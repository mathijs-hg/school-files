#!/bin/sh
#
#
#

factoryLanMac_prefix="00:0A:EB:"
mainssid=""
guestssid=""
bkssid=""
mainkey=""
guestkey=""
bkkey=""
cfgssid=""
cfgkey=""
dftssid=""
dftkey=""
stassid=""
stakey=""

STDOUT=/dev/null
# DEBUG=1
[ -n "${DEBUG}" ] && STDOUT="/dev/console"

WIFICOMMON_DEBUG=1
WIFICOMMON_DEBUG_LEVEL=6

wificommon_echo() {
    echo "wificommon $*" >$STDOUT
    if [ "$WIFICOMMON_DEBUG" -gt 0 ]; then
        logger -p $WIFICOMMON_DEBUG_LEVEL "wificommon(repacd): $1"
    fi
}

__wifi_get_defaultmac() {
	rm -f /tmp/default-mac >/dev/null 2>&1
    local MAC_TMP_FILE=/tmp/getfirm-tmp-mac
    nvrammanager -r /tmp/default-mac -p default-mac >/dev/null 2>&1
    if [ -s "/tmp/default-mac" ];then
        echo $(grep 'MAC'  /tmp/default-mac | cut -d : -f 2-)
        return
    fi

    touch /tmp/dft-mac-none
    if [ -f "$MAC_TMP_FILE" ]; then
        # the init script boot will write this file MAC_TMP_FILE
        local factoryLanMac=`cat "$MAC_TMP_FILE"`
        factoryLanMac=${factoryLanMac//-/:}
        echo  $factoryLanMac
    else
        # just in case
        local rand_num="$(head /dev/urandom | tr -dc A-F0-9 | head -c 6)"
        local format_rand_num=$(echo "${rand_num:0:2}:${rand_num:2:2}:${rand_num:4:2}")
        local factoryLanMac=${factoryLanMac_prefix}${format_rand_num}
        echo  $factoryLanMac
    fi
}

wifi_get_default_suffix(){
    local mac=""
	mac="$(__wifi_get_defaultmac)"
    echo $(echo $mac | tail -c 6 | sed 's/[- ]//g')
}

wifi_get_factory_suffix(){
    local mac=""
    mac="$(__wifi_get_defaultmac)"
    echo $(echo $mac | tail -c 9 | sed 's/[- ]//g' | sed 's/[: ]//g')
}

wifi_init_wifi_mac() {
	local mac=""

	config_load wifi
	mac="$(__wifi_get_defaultmac)"
	mac=${mac//-/:}
	uci_set_state wifi ap bridge_lan_mac $mac

    #generate 24G mac
	mac=$(lua /usr/sbin/wifimac $mac)
	mac=$(lua /usr/sbin/wifimac $mac)
	mac="$(echo $mac | tr 'a-f' 'A-F')"
	uci_toggle_state wifi radio_2g bssid $mac

	#generate 5G mac
	mac=$(lua /usr/sbin/wifimac $mac)
	mac="$(echo $mac | tr 'a-f' 'A-F')"
	uci_toggle_state wifi radio_5g bssid $mac

	uci_commit wifi
}

__wifi_config_wireless_vap() {
	local section=$1
	local apenable=$2
	local staenable_2g=$3
    local staenable_5g=$4	
	local aphidessid=$5
	local apencry=$6
	local guestenable=$7
	local guestencry=$8
	local rootapbssid_2g=$9
	local rootapbssid_5g=$10
	local bkhaulenable=$11
	local bkhaulencry=$12
	local bkhaulhidessid=$13
    local cfgenable=$14
    local cfgencry=$15
    local cfghidessid=$16
    local dftenable=$17
    local dftencry=$18
    local dfthidessid=$19
    local staencry=$20
    local factory_mode=$21
    local support11r=$22
    local enable11r_host=$23
    local apenable_2g=$24
    local apenable_5g=$25
    local guestenable_2g=$26
    local guestenable_5g=$27
    local supportwpa3=$28
    local enablewpa3_host=$29
    local enablewpa3_guest=$30
    local enablewpa3_backhaul=$31
    local enablewpa3_config=$32
    local host_enc_type=$33
    local guest_enc_type=$34
    local host_isolate=$35
    local enable11r_guest=$36
	local mode vaptype network suffix tmpssid facsuffix

    config_get mode "$section" mode
    config_get vaptype "$section" type
    
    if [ "$vaptype" = "backhaul" -a "$mode" = "ap" ]; then
        if [ "$bkhaulenable" = 1 ] ; then
            uci_set wireless $section disabled 0
        else
            uci_set wireless $section disabled 1
        fi
        
        if [ "$bkssid" = "none" ]; then
            uci_set wireless $section ssid ""        
        else
            if [ "$factorymode" = 1 ]; then
                config_get device $section device
                if [ "$device" = "wifi0" ]; then
                    suffix="_2G_"
                elif [ "$device" = "wifi1" ]; then
                    suffix="_5G_"
                fi
                # set bssid M3W_2G_AB2500
                facsuffix="$(wifi_get_factory_suffix)"
                tmpssid="$bkssid""$suffix""$facsuffix"
                uci_set wireless $section ssid "$tmpssid"
            else
                uci_set wireless $section ssid "$bkssid"
            fi
        fi

        uci_set wireless $section hidden $bkhaulhidessid
        if [ "$bkhaulencry" = "0" ]; then
            uci_set wireless $section encryption "none"
            if [ "$supportwpa3" = "yes" ]; then
                uci_set wireless $section sae
            fi
        else
            uci_set wireless $section encryption "psk2+ccmp"
            uci_set wireless $section key "$bkkey"
            if [ "$supportwpa3" = "yes" ]; then
                if [ "$enablewpa3_backhaul" = "1" ]; then
                    uci_set wireless $section sae $enablewpa3_backhaul
                else
                    uci_set wireless $section sae
                fi
            fi
        fi
        uci_set wireless $section sko_max_xretries "0"
    elif [ "$vaptype" = "backhaul" -a "$mode" = "sta" ]; then
        config_get device $section device
        if [ "$device" = "wifi0" ]; then
            if [ "$staenable_2g" = 1 ]; then
                uci_set wireless $section disabled 0              
            else
                uci_set wireless $section disabled 1
            fi                
            if [ "$rootapbssid_2g" = "none" ]; then
                uci_set wireless $section bssid ""              
            else
                uci_set wireless $section bssid "$rootapbssid_2g"
            fi
        else
            if [ "$staenable_5g" = 1 ]; then
                uci_set wireless $section disabled 0              
            else
                uci_set wireless $section disabled 1
            fi             
            if [ "$rootapbssid_5g" = "none" ]; then
                uci_set wireless $section bssid ""              
            else
                uci_set wireless $section bssid "$rootapbssid_5g"
            fi          
        fi    
        
        if [ "$stassid" = "none" ]; then
            uci_set wireless $section ssid ""        
        else
            uci_set wireless $section ssid "$stassid"
        fi
        if [ "$staencry" = "0" ]; then
            uci_set wireless $section encryption "none"
            if [ "$supportwpa3" = "yes" ]; then
                uci_set wireless $section sae
            fi
        else
            uci_set wireless $section encryption "psk2+ccmp"
            uci_set wireless $section key "$stakey"
            if [ "$supportwpa3" = "yes" ]; then
                if [ "$enablewpa3_backhaul" = "1" ]; then
                    uci_set wireless $section sae $enablewpa3_backhaul
                else
                    uci_set wireless $section sae
                fi
            fi
        fi        
    elif [ "$mode" = "ap" -a "$vaptype" = "lan" ]; then
        config_get device $section device
		if [ "$apenable" = 1 -a "$mode" = "ap" ] ; then
            if [ "$device" = "wifi0" ]; then
                if [ "$apenable_2g" = 0 ]; then
                    wificommon_echo "ap disabled 2g" 
                    uci_set wireless $section disabled 1
                else 
                    wificommon_echo "ap enabled 2g" 
                    uci_set wireless $section disabled 0
                fi
            elif [ "$device" = "wifi1" ]; then
                if [ "$apenable_5g" = 0 ]; then
                    wificommon_echo "ap disabled 5g" 
                    uci_set wireless $section disabled 1
                else 
                    wificommon_echo "ap enabled 5g" 
                    uci_set wireless $section disabled 0
                fi
            fi
		else
            wificommon_echo "ap disabled " 
			uci_set wireless $section disabled 1
		fi
		
		if [ "$factorymode" = 1 ]; then
			config_get device $section device
			if [ "$device" = "wifi0" ]; then 
				suffix="_2G"
			elif [ "$device" = "wifi1" ]; then
				suffix="_5G"
			fi
			tmpssid="$mainssid""$suffix"
			uci_set wireless $section ssid "$tmpssid"
		else
			uci_set wireless $section ssid "$mainssid"
		fi
		uci_set wireless $section hidden $aphidessid
		if [ "$apencry" = "0" ]; then
			uci_set wireless $section encryption "none"
            if [ "$supportwpa3" = "yes" ]; then
                uci_set wireless $section sae
            fi
		else
            uci_set wireless $section key "$mainkey"
            if [ "$supportwpa3" = "yes" ]; then
                uci_set wireless $section sae "$enablewpa3_host"
                if [ "$enablewpa3_host" = "1" ]; then
                    if [ "$host_enc_type" = "wpa3" ]; then
                        uci_set wireless $section encryption "ccmp"
                    else
                        uci_set wireless $section encryption "ccmp+psk2"
                    fi
                else
                    case $host_enc_type in
                    "wpa2")
                        uci_set wireless $section encryption "psk2+ccmp";;
                    "wpa2+wpa")
                        uci_set wireless $section encryption "psk-mixed/ccmp+tkip";;
                    "none")
                        uci_set wireless $section encryption "none";;
                    *)
                        wificommon_echo "unsupported enc type $host_enc_type, set to default"
                        uci_set wireless $section encryption "psk2+ccmp"
                    esac
                fi
            else
                case $host_enc_type in
                "wpa2")
                    uci_set wireless $section encryption "psk2+ccmp";;
                "wpa2+wpa")
                    uci_set wireless $section encryption "psk-mixed/ccmp+tkip";;
                "none")
                    uci_set wireless $section encryption "none";;
                *)
                    wificommon_echo "unsupported enc type $host_enc_type, set to default"
                    uci_set wireless $section encryption "psk2+ccmp"
                esac
            fi
		fi
		# if wireless.ap.ieee80211r does not exist, it means that :
        # there is no wireless.ap.ieee80211r in the old version,but it is available in the new version.
        # So, if device supports ieee80211r, we need to configure these below.
        config_get wireless_11r "$section" ieee80211r 
        if [ -z "$wireless_11r" ]; then
            if [ "$support11r" = "yes" ]; then
                uci_set wireless $section mobility_domain "5348"
                uci_set wireless $section nasid "r0kh.tp-link.com"
                uci_set wireless $section r0_key_lifetime "10000"
                uci_set wireless $section reassociation_deadline "1000"
                uci_set wireless $section pmk_r1_push "0"
                uci_set wireless $section ft_over_ds "0"
                uci_set wireless $section ft_resource_req_supp "1"
                uci_set wireless $section ft_psk_generate_local "1"            			
            fi
        fi
        if [ "$support11r" = "yes" ]; then
            uci_set wireless $section ieee80211r $enable11r_host
        else
            uci_set wifi ap ieee80211r 0
            uci_set wifi guest ieee80211r 0 
            uci_set wireless $section ieee80211r '0'
            uci_commit wifi
        fi
    
	elif [ "$mode" = "ap" -a "$vaptype" = "guest" ]; then
		uci_set wireless $section isolate 1
		uci_set wireless $section ssid "$guestssid"
        config_get device $section device
		if [ "$guestenable" = 1 -a "$apenable" = 1 ]; then
            if [ "$device" = "wifi0" ]; then
                if [ "$guestenable_2g" = 0 ]; then
                    wificommon_echo "guest disabled 2g" 
                    uci_set wireless $section disabled 1
                else 
                    wificommon_echo "guest enabled 2g"
                    uci_set wireless $section disabled 0
                fi
            elif [ "$device" = "wifi1" ]; then
                if [ "$guestenable_5g" = 0 ]; then
                    wificommon_echo "guest disabled 5g"
                    uci_set wireless $section disabled 1
                else 
                    wificommon_echo "guest enabled 5g"
                    uci_set wireless $section disabled 0
                fi
            fi
		else
            wificommon_echo "guest disabled " 
			uci_set wireless $section disabled 1		
		fi
		if [ "$guestencry" = "0" ]; then
			uci_set wireless $section encryption "none"
            if [ "$supportwpa3" = "yes" ]; then
                uci_set wireless $section sae
            fi
		else
            uci_set wireless $section key "$guestkey"
            if [ "$supportwpa3" = "yes" ]; then
                uci_set wireless $section sae "$enablewpa3_guest"
                if [ "$enablewpa3_guest" = "1" ]; then
                    if [ "$guest_enc_type" = "wpa3" ]; then
                        uci_set wireless $section encryption "ccmp"
                    else
                        uci_set wireless $section encryption "ccmp+psk2"
                    fi
                else
                    case $guest_enc_type in
                    "wpa2")
                        uci_set wireless $section encryption "psk2+ccmp";;
                    "wpa2+wpa")
                        uci_set wireless $section encryption "psk-mixed/ccmp+tkip";;
                    "none")
                        uci_set wireless $section encryption "none";;
                    *)
                        wificommon_echo "unsupported enc type $guest_enc_type, set to default"
                        uci_set wireless $section encryption "psk2+ccmp"
                    esac
                fi
            else
                case $guest_enc_type in
                "wpa2")
                    uci_set wireless $section encryption "psk2+ccmp";;
                "wpa2+wpa")
                    uci_set wireless $section encryption "psk-mixed/ccmp+tkip";;
                "none")
                    uci_set wireless $section encryption "none";;
                *)
                    wificommon_echo "unsupported enc type $guest_enc_type, set to default"
                    uci_set wireless $section encryption "psk2+ccmp"
                esac
            fi
		fi
        # if wireless.ap.ieee80211r does not exist, it means that :
        # there is no wireless.ap.ieee80211r in the old version,but it is available in the new version.
        # So, if device supports ieee80211r, we need to configure these below.
        config_get wireless_11r "$section" ieee80211r
        if [ -z "$wireless_11r" ]; then
            if [ "$support11r" = "yes" ]; then
                uci_set wireless $section mobility_domain "5348"
                uci_set wireless $section nasid "r0kh.tp-link.com"
                uci_set wireless $section r0_key_lifetime "10000"
                uci_set wireless $section reassociation_deadline "1000"
                uci_set wireless $section pmk_r1_push "0"
                uci_set wireless $section ft_over_ds "0"
                uci_set wireless $section ft_resource_req_supp "1"
                uci_set wireless $section ft_psk_generate_local "1"
            fi
        fi
        if [ "$support11r" = "yes" ]; then
            uci_set wireless $section ieee80211r $enable11r_guest
        else
            uci_set wifi ap ieee80211r 0
            uci_set wifi guest ieee80211r 0
            uci_set wireless $section ieee80211r '0'
            uci_commit wifi
        fi

        if [ "$host_isolate" = "1" ]; then
            uci_set wireless $section isolate "1"
        else
            uci_set wireless $section isolate "0"
        fi
    elif [ "$mode" = "ap" -a "$vaptype" = "config" ]; then
        if [ "$cfgenable" = 1 ] ; then
            uci_set wireless $section disabled 0
        else
            uci_set wireless $section disabled 1
        fi
        
        if [ "$cfgssid" = "none" ]; then
            uci_set wireless $section ssid ""        
        else
            uci_set wireless $section ssid "$cfgssid"
        fi
        uci_set wireless $section hidden $cfghidessid
        if [ "$cfgencry" = "0" ]; then
            uci_set wireless $section encryption "none"
        else
            uci_set wireless $section encryption "psk2+ccmp"
            uci_set wireless $section key "$cfgkey"
        fi
    elif [ "$mode" = "ap" -a "$vaptype" = "default" ]; then
        if [ "$dftenable" = 1 ] ; then
            uci_set wireless $section disabled 0
        else
            uci_set wireless $section disabled 1
        fi
        
        if [ "$dftssid" = "none" ]; then
            uci_set wireless $section ssid ""        
        else
            suffix="$(wifi_get_default_suffix)"
			tmpssid="$dftssid""_""$suffix"
            uci_set wireless $section ssid "$tmpssid"
        fi
        uci_set wireless $section hidden $dfthidessid
        if [ "$dftencry" = "0" ]; then
            uci_set wireless $section encryption "none"
        else
            uci_set wireless $section encryption "psk2+ccmp"
            uci_set wireless $section key "$dftkey"
        fi       
    fi
}

__wifi_config_wireless_radio() {                                                        
        local section=$1                                                
        local channel=$2                                                                                                         
        local bssid=$3
	local ax_hwmode=$4
	local hwmode=$5
	local htmode=$6                                                
	local country=$7 
	local enable=$8                                             

    local ifname=`uci get profile.ifname.style -c /etc/profile.d/`
    [ "$ifname" == "ac" ] && ax_hwmode="none"

	[ "$ax_hwmode" != "none" ] && hwmode="$ax_hwmode"    
                                                                                                                 
        uci_set wireless $section channel $channel                      
        uci_set wireless $section macaddr $bssid
	uci_set wireless $section hwmode $hwmode
	uci_set wireless $section htmode $htmode                        
	uci_set wireless $section country $country
	if [ "$enable" = 1 ]; then
		uci_set wireless $section disabled 0
	else 
		uci_set wireless $section disabled 1
	fi                    
}

wifi_config_wireless() {
	local aphidessid apencry apenable
	local guestenable guestencry
	local channel_2g channel_5g bssid_2g bssid_5g country_2g country_5g
	local htmode_2g htmode_5g hwmode_2g hwmode_5g radio_2g_enable radio_5g_enable
	local rootapbssid_2g rootapbssid_5g
	local bkhaulenable bkhaulencry bkhaulhidessid
    local cfgenable cfgencry cfghidessid	
    local dftenable dftencry dfthidessid
    local staencry         
	local factorymode
	local support11r
    local supportwpa3
    local host_enc_type guest_enc_type
	


	config_get mainssid ap ssid
	config_get aphidessid ap hidessid
	config_get apencry ap encryption
	config_get mainkey ap password
	config_get apenable ap enable
	config_get apenable_2g ap enable_2g '1'
	config_get apenable_5g ap enable_5g '1'
	config_get guestenable guest enable
	config_get guestenable_2g guest enable_2g '1'
	config_get guestenable_5g guest enable_5g '1'
	config_get guestssid guest ssid
	config_get guestencry guest encryption
	config_get guestkey guest password
	config_get channel_2g radio_2g channel '0'     
	config_get bssid_2g radio_2g bssid 'none'
	config_get hwmode_2g radio_2g hwmode
	config_get ax_hwmode_2g radio_2g ax_hwmode 'none'
	config_get htmode_2g radio_2g htmode                   
	config_get country_2g radio_2g country
	config_get radio_2g_enable radio_2g enable '1'
	config_get channel_5g radio_5g channel '0'                                                 
	config_get bssid_5g radio_5g bssid 'none'
	config_get hwmode_5g radio_5g hwmode
	config_get ax_hwmode_5g radio_5g ax_hwmode 'none'
	config_get htmode_5g radio_5g htmode  
	config_get country_5g radio_5g country
	config_get radio_5g_enable radio_5g enable '1'
	config_get rootapbssid_2g sta_2g bssid 'none'
	config_get rootapbssid_5g sta_5g bssid 'none'
	config_get bkhaulenable backhaul enable '1'
	config_get bkssid backhaul ssid 'none'
	config_get bkhaulencry backhaul encryption
	config_get bkkey backhaul password
	config_get bkhaulhidessid backhaul hidessid
    config_get cfgenable config enable '1'
    config_get cfgssid config ssid 'none'
    config_get cfgencry config encryption
    config_get cfgkey config password
    config_get cfghidessid config hidessid
    config_get dftenable default enable '1'
    config_get dftssid default ssid 'none'
    config_get dftencry default encryption
    config_get dftkey default password
    config_get dfthidessid default hidessid
    config_get stassid sta ssid 'none'
    config_get staencry sta encryption
    config_get stakey sta password    
	config_get factorymode ap factorymode '0'
    config_get staenable_2g sta_2g enable '0'
    config_get staenable_5g sta_5g enable '0'
    config_get enable11r_host ap ieee80211r
    config_get enable11r_guest ap ieee80211r
    config_get host_isolate guest host_isolation '1'
    config_get enablewpa3_host ap wpa3 '0'
    config_get enablewpa3_guest guest wpa3 '0'
    config_get enablewpa3_backhaul backhaul wpa3 '0'
    config_get enablewpa3_config config wpa3 '0'
    config_get host_enc_type ap enc_type 'wpa2'
    config_get guest_enc_type guest enc_type 'wpa2'
    support11r=$(uci get profile.@wireless[0].11r_support -c /etc/profile.d)
    [ -z "$support11r" ] && support11r="no"
    supportwpa3=$(uci get profile.@wireless[0].wpa3_support -c /etc/profile.d)
    [ -z "$supportwpa3" ] && supportwpa3="no"

    wificommon_echo "enablewpa3_host: $enablewpa3_host enablewpa3_guest: $enablewpa3_guest"
    [ "$enablewpa3_host" = "1" ] && enable11r_host='0'
    [ "$enablewpa3_guest" = "1" ] && enable11r_guest='0'

	config_load wireless
	
	__wifi_config_wireless_radio wifi0 "$channel_2g" "$bssid_2g" "$ax_hwmode_2g" "$hwmode_2g" "$htmode_2g" "$country_2g" "$radio_2g_enable"
	__wifi_config_wireless_radio wifi1 "$channel_5g" "$bssid_5g" "$ax_hwmode_5g" "$hwmode_5g" "$htmode_5g" "$country_5g" "$radio_5g_enable"
	config_foreach __wifi_config_wireless_vap wifi-iface "$apenable" "$staenable_2g" "$staenable_5g" "$aphidessid" "$apencry" \
			"$guestenable"  "$guestencry" "$rootapbssid_2g" "$rootapbssid_5g" "$bkhaulenable" \
			"$bkhaulencry" "$bkhaulhidessid" "$cfgenable" "$cfgencry" "$cfghidessid" "$dftenable" "$dftencry" \
			"$dfthidessid" "$staencry" "$factorymode" "$support11r" "$enable11r_host" "$apenable_2g" "$apenable_5g" "$guestenable_2g" "$guestenable_5g" \
            "$supportwpa3" "$enablewpa3_host" "$enablewpa3_guest" "$enablewpa3_backhaul" "$enablewpa3_config" \
            "$host_enc_type" "$guest_enc_type" "$host_isolate" "$enable11r_guest"
						

	uci_commit wireless
}


ACT_RE_LOAD=1
ACT_COUNTRY=2
ACT_DEV_CFG=4
ACT_DEVMODE=8
ACT_VAP_CFG=16

CFG_HST_2G=1
CFG_HST_5G=2
CFG_GST_2G=4
CFG_GST_5G=8
CFG_BHL_2G=16
CFG_BHL_5G=32
CFG_STA_2G=64
CFG_STA_5G=128
CFG_CFG_2G=256
CFG_CFG_5G=512
CFG_DFT_2G=1024
CFG_DFT_5G=2048
CFG_DEV_2G=4096
CFG_DEV_5G=8192


CFG_VAP_2G=$((CFG_STA_2G | CFG_GST_2G | CFG_HST_2G | CFG_CFG_2G | CFG_DFT_2G))
CFG_VAP_5G=$((CFG_HST_5G | CFG_GST_5G | CFG_STA_5G | CFG_CFG_5G | CFG_DFT_5G))
CFG_VAP_AL=$((CFG_VAP_2G | CFG_VAP_5G))
CFG_DEV_AL=$((CFG_DEV_2G | CFG_DEV_5G))
CFG_HST_AL=$((CFG_HST_2G | CFG_HST_5G))
CFG_BHL_AL=$((CFG_BHL_2G | CFG_BHL_5G))
CFG_GST_AL=$((CFG_GST_2G | CFG_GST_5G))
CFG_STA_AL=$((CFG_STA_2G | CFG_STA_5G))
CFG_CFG_AL=$((CFG_CFG_2G | CFG_CFG_5G))
CFG_DFT_AL=$((CFG_DFT_2G | CFG_DFT_5G))


wifi_config_list="ap.ssid:$CFG_HST_AL,$ACT_VAP_CFG \
             ap.ieee80211r:$CFG_HST_AL,$ACT_VAP_CFG\
             ap.encryption:$CFG_HST_AL,$ACT_VAP_CFG \
             ap.password:$CFG_HST_AL,$ACT_VAP_CFG \
             ap.hidessid:$CFG_HST_AL,$ACT_VAP_CFG \
             ap.enable:$CFG_HST_AL,$ACT_VAP_CFG \
             ap.enable_2g:$CFG_HST_2G,$ACT_VAP_CFG \
             ap.enable_5g:$CFG_HST_5G,$ACT_VAP_CFG \
             ap.enc_type:$CFG_HST_AL,$ACT_VAP_CFG \
             guest.ssid:$CFG_GST_AL,$ACT_VAP_CFG \
             guest.encryption:$CFG_GST_AL,$ACT_VAP_CFG \
             guest.password:$CFG_GST_AL,$ACT_VAP_CFG \
             guest.enable:$CFG_GST_AL,$ACT_VAP_CFG \
             guest.enable_2g:$CFG_GST_2G,$ACT_VAP_CFG \
             guest.enable_5g:$CFG_GST_5G,$ACT_VAP_CFG \
             guest.enc_type:$CFG_GST_AL,$ACT_VAP_CFG \
             guest.host_isolation:$CFG_GST_AL,$ACT_VAP_CFG \
             backhaul.ssid:$CFG_BHL_AL,$ACT_VAP_CFG \
             backhaul.encryption:$CFG_BHL_AL,$ACT_VAP_CFG \
             backhaul.password:$CFG_BHL_AL,$ACT_VAP_CFG \
             backhaul.hidessid:$CFG_BHL_AL,$ACT_VAP_CFG \
             backhaul.enable:$CFG_BHL_AL,$ACT_VAP_CFG \
             config.ssid:$CFG_CFG_AL,$ACT_VAP_CFG \
             config.encryption:$CFG_CFG_AL,$ACT_VAP_CFG \
             config.password:$CFG_CFG_AL,$ACT_VAP_CFG \
             config.hidessid:$CFG_CFG_AL,$ACT_VAP_CFG \
             config.enable:$CFG_CFG_AL,$ACT_VAP_CFG \
             default.ssid:$CFG_DFT_AL,$ACT_VAP_CFG \
             default.encryption:$CFG_DFT_AL,$ACT_VAP_CFG \
             default.password:$CFG_DFT_AL,$ACT_VAP_CFG \
             default.hidessid:$CFG_DFT_AL,$ACT_VAP_CFG \
             default.enable:$CFG_DFT_AL,$ACT_VAP_CFG \
             sta.ssid:$CFG_STA_AL,$ACT_VAP_CFG \
             sta.encryption:$CFG_STA_AL,$ACT_VAP_CFG \
             sta.password:$CFG_STA_AL,$ACT_VAP_CFG \
             sta_2g.enable:$CFG_STA_2G,$ACT_VAP_CFG \
             sta_2g.bssid:$CFG_STA_2G,$ACT_VAP_CFG \
             sta_5g.enable:$CFG_STA_5G,$ACT_VAP_CFG \
             sta_5g.bssid:$CFG_STA_5G,$ACT_VAP_CFG \
             radio_2g.enable:$CFG_DEV_2G,$ACT_RE_LOAD \
             radio_2g.ax_hwmode:$CFG_DEV_2G,$ACT_DEVMODE \
             radio_2g.hwmode:$CFG_DEV_2G,$ACT_DEVMODE \
             radio_2g.htmode:$CFG_DEV_2G,$ACT_DEVMODE \
             radio_2g.channel:$CFG_DEV_2G,$ACT_DEVMODE \
             radio_2g.bssid:$CFG_DEV_2G,$ACT_RE_LOAD \
             radio_2g.country:$CFG_DEV_AL,$ACT_RE_LOAD \
             radio_5g.enable:$CFG_DEV_5G,$ACT_RE_LOAD \
             radio_5g.ax_hwmode:$CFG_DEV_5G,$ACT_DEVMODE \
             radio_5g.hwmode:$CFG_DEV_5G,$ACT_DEVMODE \
             radio_5g.htmode:$CFG_DEV_5G,$ACT_DEVMODE \
             radio_5g.channel:$CFG_DEV_5G,$ACT_DEVMODE \
             radio_5g.bssid:$CFG_DEV_5G,$ACT_RE_LOAD \
             radio_5g.country:$CFG_DEV_AL,$ACT_RE_LOAD"

wifi_act_list="reload country dev mode vap"
wifi_device_list="wifi0 wifi1"
local wifi_vap_list=""

WIFI_CFG='/etc/config/wifi'             
WIFI_BACK_CFG='/tmp/etc/config/wifi'
TMP_CFG_DIR='/tmp/etc/config' 

get_wifi_dev() {
    local device="$1"
    local band_2g="$2"
    local band_5g="$3"
    local band
    config_get band "$device" band
    if [ "$band" = "$band_2g" ]; then
         eval "$4='$device'"
    fi
    if [ "$band" = "$band_5g" ]; then
         eval "$5='$device'"
    fi
}

get_all_iface() {
    local iface="$1"
    local _type="$2"
    local _mode="$3"
    local _device="$4"
    local type
    local mode
    local device
    config_get type "$iface" type
    [ "$type" != "$_type" ] && return
    config_get device "$iface" device
    [ "$device" != "$_device" ] && return
    config_get mode "$iface" mode
    # echo "checking $iface with mode:$mode"
    [ "$mode" != "$_mode" ] && return

    wifi_vap_list="$wifi_vap_list"" $iface"
}

generate_wifi_vap_list() {
    local dev_2g
    local dev_5g

    config_load wireless
    config_foreach get_wifi_dev wifi-device 2g 5g dev_2g dev_5g
    [ "$device_2g" = "" ] && dev_2g="wifi0"
    [ "$device_5g" = "" ] && dev_5g="wifi1"
    config_foreach get_all_iface wifi-iface lan ap $dev_2g
    config_foreach get_all_iface wifi-iface lan ap $dev_5g
    config_foreach get_all_iface wifi-iface guest ap $dev_2g
    config_foreach get_all_iface wifi-iface guest ap $dev_5g
    config_foreach get_all_iface wifi-iface backhaul ap $dev_2g
    config_foreach get_all_iface wifi-iface backhaul ap $dev_5g
    config_foreach get_all_iface wifi-iface backhaul sta $dev_2g
    config_foreach get_all_iface wifi-iface backhaul sta $dev_5g
    config_foreach get_all_iface wifi-iface config ap $dev_2g
    config_foreach get_all_iface wifi-iface config ap $dev_5g
    config_foreach get_all_iface wifi-iface default ap $dev_2g
    config_foreach get_all_iface wifi-iface default ap $dev_5g
    echo "generate_wifi_vap_list result:$wifi_vap_list" > /dev/console
}

wifi_config_inspect() { 
    local key val cfg act
    local section option new_value old_value 
    local vapcfg devcfg vaplist devlist
    local wificfg= 
    local wifiact=
    local cmd=
    
    config_load wifi
    if [ ! -f $WIFI_BACK_CFG ]; then
        mkdir -p $TMP_CFG_DIR
        uci -P /var/state export wifi > $WIFI_BACK_CFG
        wificfg=$CFG_DEV_AL
        wifiact=$ACT_RE_LOAD

    else
        for param in $wifi_config_list; do
            key=${param%%:*}
            val=${param#*:}
            section=${key%%.*}
            option=${key#*.}
            cfg=${val%%,*}
            act=${val#*,}
            # echo "section:$section, option:$option, cfg:$cfg, act:$act" >/dev/console
            
            config_get new_value $section "$option"           
            old_value=$(uci get wifi.$section.$option -c $TMP_CFG_DIR)
            if [ ! "$new_value" = "$old_value" ]; then
                uci set wifi.$section.$option="$new_value" -c $TMP_CFG_DIR
                if [ -z $wificfg ]; then
                    wificfg=$cfg
                else
                    wificfg=$((wificfg | cfg))
                fi
                
                if [ -z $wifiact ]; then
                    wifiact=$act
                else
                    wifiact=$((wifiact | act))                
                fi
                echo "new_value:$new_value, old_value:$old_value" >/dev/console
                echo "change:$wificfg, action:$wifiact" >/dev/console
            fi
        done

        uci commit -c $TMP_CFG_DIR

    fi
    
    vapcfg=$((wificfg % CFG_DEV_2G))
    devcfg=$((wificfg / CFG_DEV_2G))
    index=1
    generate_wifi_vap_list
    for vap in $wifi_vap_list; do
        tmp1=$((vapcfg & index))
        if [ "$tmp1" != "0" ]; then
             vaplist="$vaplist$vap,"
        fi
        index=$((index * 2))
        
    done
    vaplist=${vaplist%,*}
    echo "vaplist:$vaplist" >/dev/console

    index=1
    for dev in $wifi_device_list; do
        tmp1=$((devcfg & index))
        if [ "$tmp1" != "0" ]; then
             devlist="$devlist$dev,"
        fi
        index=$((index * 2))
    done
    devlist=${devlist%,*}
    echo "devlist:$devlist" >/dev/console
    
    index=1
    for item in $wifi_act_list; do
        tmp1=$((wifiact & index))
        if [ "$tmp1" != "0" ]; then
             cmd="$cmd$item,"
        fi
        index=$((index * 2))
    done
    cmd=${cmd%,*}  
    cmd="$cmd $devlist"
    cmd="$cmd $vaplist"
    [ -n "$(echo $cmd | sed s/[[:space:]]//g)" ] && wifi_config_wireless
    echo $cmd
    
}




