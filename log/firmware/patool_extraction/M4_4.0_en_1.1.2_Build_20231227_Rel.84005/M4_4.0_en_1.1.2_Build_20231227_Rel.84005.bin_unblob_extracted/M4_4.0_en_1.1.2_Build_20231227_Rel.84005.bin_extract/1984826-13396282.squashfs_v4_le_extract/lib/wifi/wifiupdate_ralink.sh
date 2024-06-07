#!/bin/sh
#
# Copyright (c) 2014 TP-LINK Technologies Co., Ltd.
#
# All Rights Reserved.
#

brchanged=0

maclist_sec=""

FACTORYMODE_FILE="/tmp/factorymode"

DBG=1
STDOUT="/dev/null"

if [ "$DBG" = "1" ];then
    DEBUG=echo
    STDOUT="/dev/console"
fi

tpdbg () {
    ${DEBUG:-:} "$*" >$STDOUT
}

kill_process() {
    [ -f "/var/run/hostapd-$1.lock" ] && { \
        wpa_cli -g /var/run/hostapd/global raw REMOVE $1
        rm /var/run/hostapd-$1.lock
    }
    [ -f "/var/run/wpa_supplicant-$1.lock" ] && { \
        wpa_cli -g /var/run/wpa_supplicantglobal  interface_remove  $1
        rm /var/run/wpa_supplicant-$1.lock
    }
    [ -f "/var/run/wapid-$1.conf" ] && { \
        kill "$(cat "/var/run/wifi-$1.pid")"
    }        
}

down_vap() {
    tpdbg "down_vap $1" 
    [ ! -d /sys/class/net/$1 ] && return

    # [ "$(cat /sys/class/net/$1/carrier)" == "1" ] && ifconfig "$1" down
    ifconfig "$1" down
    
    uci_revert_state wireless $1 up 

}

config_iwpriv_set() {
	[ -n "$3" ] && iwpriv "$1" set "$2"="$3"
}

check_wps_iface() {
    local _vif="$1"
    local vif="$2"
    if [ "$vif" == "$_vif" ]; then
        eval "$3='1'"
    fi
}

config_wps() {
    local vif="$1"
    local is_wps="0"

    if [ "$(uci get wps.wpsd.enabled)" != "1" ]; then
        return
    fi

    config_load wps
    config_foreach check_wps_iface wifi-iface "$vif" is_wps
    if [ "$is_wps" == "1" ]; then
        config_iwpriv_set $vif WscConfMode 7
        config_iwpriv_set $vif WscConfStatus 2
    fi
}

setup_vif_ap() {
    local vif="$1"

    tpdbg "setup_vif_ap vif:$vif "
    local enc key mode ifname wds channel=""

    local country txpower country
    
    config_get channel "$device" channel
    config_get txpower "$device" txpower
    config_get country "$device" country

    [ auto = "$channel" ] && channel=0    

    config_get mode "$vif" mode
    config_get ifname "$vif" vapname
    config_get_bool wds "$vif" wds 0
    config_get device "$vif" device
    config_get channel "$device" channel 0

    config_get enc "$vif" encryption
    config_get key "$vif" key
    config_get vaptype "$vif" type

    config_get hwmode "$device" hwmode auto
    config_get htmode "$device" htmode auto

    local band
    case "$hwmode" in
            *ac) band="5g";;
            *) band="2g";;
    esac

    [ "$vaptype" = "backhaul" -a "ap" = "$mode" ] &&  {
    wifiextend set_channel "$vif" "$channel"
    }

    config_get_bool hidden "$vif" hidden 0
    iwpriv "$vif" set "HideSSID=$hidden"

    config_get chwidth "$vif" chwidth
    #[ -n "$chwidth" ] && iwpriv "$vif" set "HtBw=${chwidth}"

    config_get wds "$vif" wds
    case "$wds" in
            1|on|enabled) wds=1;;
            *) wds=0;;
    esac

    # iwpriv "$vif" set "ApMWDS=$wds"

    case "$enc" in
            none)
                # 
                iwpriv "$vif" set AuthMode=OPEN
                iwpriv "$vif" set EncrypType=NONE
            ;;
            wep*)
                # AuthMode=WEPAUTO/SHARED/OPEN
                case "$enc" in
                    *mixed*)  iwpriv "$vif" set AuthMode=WEPAUTO;;
                    *shared*) iwpriv "$vif" set AuthMode=SHARED;;
                    *)        iwpriv "$vif" set AuthMode=OPEN;;
                esac

                iwpriv "$vif" set EncrypType=WEP
                iwpriv "$vif" set IEEE8021X=0
                for idx in 1 2 3 4; do
                    config_get key "$vif" "key${idx}"
                    #iwconfig "$vif" enc "[$idx]" "${key:-off}"
                    iwpriv "$vif" set "Key${idx}=[$key]"
                done
                config_get key "$vif" key
                key="${key:-1}"
                case "$key" in
                    #[1234]) iwpriv "$vif" enc "[$key]";;
                    [1234]) iwpriv "$vif" set "Key${idx}=[$key]";;
                    *) iwpriv "$vif" set "DefaultKeyID=$key";;
                esac
            ;;
            mixed*|psk*|wpa*|8021x)
                # AuthMode=WPAPSK/WPA2PSK/WPAPSKWPA2PSK
                # EncrypType=TKIP/AES/TKIPAES
                config_get key "$vif" key

                #backhaul:WPA2PSK+AES  mainAP:WPAPSKWPA2PSK+TKIPAES, config: set by .dat
                if [ "$vaptype" = "backhaul" ]; then
                    iwpriv "$vif" set "AuthMode=WPA2PSK"
                    iwpriv "$vif" set "EncrypType=AES"
                elif [ "$vaptype" != "config" ]; then
                    iwpriv "$vif" set "AuthMode=WPAPSKWPA2PSK"
                    iwpriv "$vif" set "EncrypType=TKIPAES"
                    case "$enc" in
                    *tkip)
                        iwpriv "$vif" set "AuthMode=WPAPSKWPA2PSK"
                        iwpriv "$vif" set "EncrypType=TKIPAES" ;;
                    *ccmp)
                        iwpriv "$vif" set "AuthMode=WPA2PSK"
                        iwpriv "$vif" set "EncrypType=AES" ;;
                    *)
                        iwpriv "$vif" set "AuthMode=WPA2PSK"
                        iwpriv "$vif" set "EncrypType=AES" ;;
                    esac
                fi

                iwpriv "$vif" set "IEEE8021X=0"
                iwpriv "$vif" set "WPAPSK=$key"
                iwpriv "$vif" set "DefaultKeyID=2"
                iwpriv "$vif" set "RekeyInterval=0"
            ;;
            ccmp*|gcmp*)
                config_get key "$vif" key
                case "$enc" in
                ccmp)
                    iwpriv "$vif" set "AuthMode=WPA3PSK"
                    iwpriv "$vif" set "EncrypType=AES"
                    iwpriv "$vif" set "WPAPSK=$key"
                    iwpriv "$vif" set "RekeyInterval=0";;
                *)
                    iwpriv "$vif" set "AuthMode=WPA2PSKWPA3PSK"
                    iwpriv "$vif" set "EncrypType=AES"
                    iwpriv "$vif" set "WPAPSK=$key"
                    iwpriv "$vif" set "RekeyInterval=0";;
                esac
            ;;
            wapi*)
                config_get key "$vif" key
            ;;
    esac


    # flush MAC list
    iwpriv "$ifname" set ACLClearAll=1:1
    # set ACL rule 
    # AccessPolicy  0:disable 1:positive(white list) 2:negative(black list)
    #add to support macfilter_sec
    config_get macfilter_sec "$vif" macfilter_sec
    case "$macfilter_sec" in
        allow)
            [ -n "$maclist_sec" ] && {
                # white list
                iwpriv "$vif" set AccessPolicy=1
                for mac in $maclist_sec; do
                    iwpriv "$vif" set "ACLAddEntry=$mac-1"
                done
            }
        ;;
        deny)
            [ -n "$maclist_sec" ] && {
                # black list
                iwpriv "$vif" set AccessPolicy=2
                for mac in $maclist_sec; do
                    iwpriv "$vif" set "ACLAddEntry=$mac-1"
                done
            }
        ;;
    esac

    config_get_bool wmm "$vif" wmm
    [ -n "$wmm" ] && iwpriv "$vif" set "WmmCapable=$wmm"

    config_get dtim_period "$vif" dtim_period
    [ -n "$dtim_period" ] && iwpriv "$vif" set "DtimPeriod=$dtim_period"

    #config_get wnm "$vif" wnm
    #[ -n "$wnm" ] && iwpriv "$vif" wnm "$wnm"

    #config_get ampdu "$vif" ampdu
    #[ -n "$ampdu" ] && iwpriv "$vif" set "HtMpduDensity=$ampdu"

    config_get amsdu "$vif" amsdu
    [ -n "$amsdu" ] && iwpriv "$vif" set "HtAmsdu=$amsdu"

    config_get ieee80211r "$vif" ieee80211r 0
    [ -n "$ieee80211r" ] && iwpriv "$vif" set "ftenable=$ieee80211r"

    #config_get maxampdu "$vif" maxampdu
    #[ -n "$maxampdu" ] && iwpriv "$vif" set "HtMpduDensity=$maxampdu"

    #config_get maclist "$vif" maclist
    #[ -n "$maclist" ] && {
            # flush MAC list
    #        iwpriv "$vif" maccmd 3
    #        for mac in $maclist; do
    #        iwpriv "$vif" addmac "$mac"
    #        done
    #}

    local maxsta
    #config_get maxsta "$vif" maxsta
    [ "$band" = "5g" -o "$band" = "2g" ] && {
            maxsta=$(uci get profile.@wireless[0].max_sta_number_$band -c /etc/profile.d)
    }
    [ -n "$maxsta" ] && iwpriv "$vif" set "MaxStaNum=$maxsta"  
    
    #the ssid of config vap is already set by .dat, 
    #so we won't set it again to avoid vap restart
    [ "$vaptype" = "config" ] && {
        return
    }

    config_get ssid "$vif" ssid
    [ -n "$ssid" ] && {
        iwpriv "$vif" set "SSID=$ssid"
    }
    
    config_get_bool isolate "$vif" isolate 0
    [ -n "$isolate" ] && {
        iwpriv "$vif" set "NoForwarding=$isolate"
    }

    config_wps $vif

    wifiextend set_edcca $vif

    #if [ "$device" = "wifi1" -a "$country" = "US" -a "$mode" = "ap" ]; then
    #        wifitool "$vif" block_acs_channel "149,153,157,161,165"
    #fi

    return 0
}


setup_vif_sta() {
    local vif="$1"

    # make sure we have the encryption type and the psk
    local enc key mode ifname wds channel=""
    config_get mode "$vif" mode
    config_get ifname "$vif" vapname
    config_get_bool wds "$vif" wds 0
    config_get device "$vif" device
    config_get channel "$device" channel 0

    config_get enc "$vif" encryption "psk2+ccmp"
    config_get key "$vif" key "12345678"

    config_get ssid "$vif" ssid
    config_get bssid "$vif" bssid

    tpdbg "setup_vif_sta ifname($ifname) ssid($ssid) bssid($bssid) encrytion($enc) password($key)"

    ifconfig "$vif" down
    ifconfig "$vif" up

    iwpriv "$vif" set ApCliEnable=0
    # iwpriv "$vif" set MACRepeaterEn=0
    # iwpriv "$vif" set ApCliMWDS=1

    if [ "none" = "$enc" ]; then
        iwpriv "$vif" set ApCliAuthMode=OPEN
        iwpriv "$vif" set ApCliEncrypType=NONE
    else
        # psk2+ccmp(AES)
        iwpriv "$vif" set ApCliAuthMode=WPA2PSK
        iwpriv "$vif" set ApCliEncrypType=AES
        iwpriv "$vif" set IEEE8021X=0 
        iwpriv "$vif" set "ApCliWPAPSK=$key"
    fi
    iwpriv "$vif" set "ApCliSsid=$ssid"
    iwpriv "$vif" set "ApCliBssid=$bssid"
    iwpriv "$vif" set ApCliEnable=1

    rm -f /var/run/wpa_supplicant-$vif.conf
    cat > /var/run/wpa_supplicant-$vif.conf <<EOF
network={
    scan_ssid=1
    ssid="$ssid"
    bssid="$bssid"
    encryption="$enc"
    psk="$key"
}
EOF
}

create_process(){
    local vif="$1" mode="$2" brname="$3" start_hostapd="$4" start_wapid="$5"
    
    tpdbg "[create_process]vif:$vif mode:$mode brname:$brname start_hostapd:$start_hostapd start_wapid:$start_wapid"
    uci_set_state wireless "$vif" up 1    

    case "$mode" in
        ap|ap_guest)
            setup_vif_ap "$vif" || {
                echo "create_process($device): Failed to set up hostapd for interface $vif" > /dev/console
                # make sure this wifi interface won't accidentally stay open without encryption
                uci_revert_state wireless $vif up 
                ifconfig "$vif" down
                #wlanconfig "$vif" destroy
                return
            }
         ;;
        sta)
            if [ ! -f "/var/run/wpa_supplicant-$vif.lock" ] 2>/dev/null >/dev/null; then
                if [ ! -f "/var/run/wpa_supplicant-update-$vif.lock" ]; then
                    touch /var/run/wpa_supplicant-update-$vif.lock
                    setup_vif_sta "$vif" || {
                        echo "enable_qcawifi($device): Failed to set up wpa_supplicant for interface $vif" > /dev/console
                        uci_revert_state wireless $vif up 
                        ifconfig "$vif" down
                        # wlanconfig "$vif" destroy
                        rm /var/run/wpa_supplicant-update-$vif.lock
                        return
                    }
                    rm /var/run/wpa_supplicant-update-$vif.lock
                fi
            fi
        ;;
        *)
            echo "enable_ralinkwifi ; unknow mode:$mode" > /dev/console 
        ;;
    esac
     
}

getmaclist_sec() {
	local section="$1"
	config_get mac "$section" mac
	mac=${mac//-/:}
	append maclist_sec "$mac "
}

create_vap() {
    tpdbg "create vap :vif($1) device($2)"
    local vif="$1" device="$2"    
    local start_hostapd= vif_txpower= nosbeacon= wlanaddr=""
    local wlanmode disabled vaptype
    
    config_get enc "$vif" encryption "none"
    config_get eap_type "$vif" eap_type
    config_get mode "$vif" mode
    config_get ifname "$vif" vapname
    config_get disabled "$vif" disabled
    config_get vaptype "$vif" type

    if [ ! -d /sys/class/net/${ifname} ]; then
        ifconfig  ${ifname} up
        #tpdbg "ifconfig ${ifname} up"
    else
        tpdbg "${ifname} is up"
    fi

    [ $? -ne 0 ] && {
            echo "Failed to set up $mode vif $ifname" >&2
            return 
    }

    [ "$disabled" = 1 ] && return
    config_set "$vif" ifname "$ifname"

    local net_cfg 
    local bridge=
    net_cfg="$(find_net_config "$vif")"
    [ "$net_cfg" != "backhaul" ] && { \
        bridge="$(bridge_interface "$net_cfg")"
        config_set "$vif" bridge "$bridge"
    }

    create_process "$vif" "$mode" "$bridge" "$start_hostapd" "$start_wapid" &

    #share wifi1 process to cpu0,1,3
    #if [ "wifi1" = "$device" ]; then
    #        echo 3 > /sys/devices/virtual/net/${ifname}/queues/rx-0/rps_cpus
    #fi 
}



up_all_vap() {
    local vlanid=3 gvlan=2
    local start_hostapd= start_wapid=
    #local brchanged=0
    tpdbg "up_all_vap DEVICES($DEVICES)"
    for dev in $DEVICES; do
        config_get dev_disabled "$dev" disabled   
        #[ "$dev_disabled" = "1" ] && continue
        for vif in $(config_get "$dev" vifs); do 
            if [ -d /sys/class/net/$vif ]; then
                local brname=
                config_get disabled "$vif" disabled
                net_cfg="$(find_net_config "$vif")"
                [ -n "$net_cfg" ] && [ "$net_cfg" != "backhaul" ] && brname="$(bridge_interface "$net_cfg")" 
                [ "$disabled" = "1" -o "$dev_disabled" = "1" ] && {
                    [ -n "$brname" ] && [ -e /sys/class/net/$brname/brif/$vif ] && {
                        brctl delif $brname $vif
                        tpdbg "up_all_vap brctl delif $brname $vif"
                        [ "$?" = "0" ] && brchanged=1
                    }
                    continue
                }
                
                local up=$(uci_get_state wireless.$vif.up)
                [ "$up" = "1" ] || {                          
                    config_get mode "$vif" mode
                    config_get enc "$vif" encryption "none" 
                    case "$enc" in
                        none)
                            # We start hostapd in open mode also
                            start_hostapd=1
                            ;;
                        mixed*|psk*|wpa*|8021x)
                            start_hostapd=1
                            ;;
                        ccmp*|gcmp*)
            				start_hostapd=1
                            ;;
                        wapi*)
                            start_wapid=1
                            ;;
                    esac 
                 
                    create_process "$vif" "$mode" "$brname" "$start_hostapd" "$start_wapid" 
                 }
                 config_get vif_type "$vif" type
                 [ "backhaul" == "$vif_type" ] && wifiextend set_backhaul_down "$vif"
                 ifconfig "$vif" up
                 [ -n "$brname" ] && [ ! -e /sys/class/net/$brname/brif/$vif ] && {
                    tpdbg "up_all_vap brctl addif brname:$brname vif($vif)"
                    brctl addif "$brname" "$vif"
                    [ "$?" = "0" ] && brchanged=1
                    #ubus call network.interface.lan add_device "{\"name\":\"$vif\"}"
                 }
                 set_wifi_up "$vif" "$vif"
             fi
        done
    done
}


config_vap() {
    local vif="$1" action="$2" start_hostapd= start_wapid= hasvif=
    local net_cfg= brname=
    local mode phy disabled
    local is_main_vif=

    [ -z "$vif" ] && return
    config_get mode "$vif" mode
    config_get phy "$vif" device
    config_get disabled "$vif" disabled 0
    
    tpdbg "config_vap  vif($vif) action($action) phy($phy) mode($mode) disabled($disabled)"

    [ -z "$mode" -o -z "phy" ] && return
    config_get dev_disabled "$phy" disabled 
 
    tpdbg "config_vap vif:$vif disabled:$disabled"
    [ -d /sys/class/net/$vif ] && hasvif="1"

    [ "$disabled" = "1" ] && {
        [ -n "$hasvif" ] && down_vap $vif
        return
    }

    # no need to down vap in factorymode
    if [ ! -f $FACTORYMODE_FILE ]; then
        is_main_vif=$(wifiextend check_main_vif "$vif")
        [ -n "$hasvif" -a "$is_main_vif" = "false" ] && down_vap $vif
    fi

    [ -z "$hasvif" -o "$action" = "reload" ] && create_vap "$vif" "$phy" "$mode" &>$STDOUT && return 0   
    
    # config_get ssid "$vif" ssid
    # if [ -n "$ssid" ]; then
    #     iwpriv "$vif" set "SSID=$ssid"
    # fi

    # config_get_bool hidden "$vif" hidden 0
    # iwpriv "$vif" set "HideSSID=$hidden"

    # config_get enc "$vif" encryption "none"
    # case "$enc" in
    #         none)
    #             # 
    #             iwpriv "$vif" set AuthMode=OPEN
    #             iwpriv "$vif" set EncrypType=NONE
    #         ;;
    #         wep*)
    #             # AuthMode=WEPAUTO/SHARED/OPEN
    #             case "$enc" in
    #                 *mixed*)  iwpriv "$vif" set AuthMode=WEPAUTO;;
    #                 *shared*) iwpriv "$vif" set AuthMode=SHARED;;
    #                 *)        iwpriv "$vif" set AuthMode=OPEN;;
    #             esac

    #             iwpriv "$vif" set EncrypType=WEP
    #             iwpriv "$vif" set IEEE8021X=0
    #             for idx in 1 2 3 4; do
    #                 config_get key "$vif" "key${idx}"
    #                 #iwconfig "$ifname" enc "[$idx]" "${key:-off}"
    #                 iwpriv "$vif" set "Key${idx}=[$key]"
    #             done
    #             config_get key "$vif" key
    #             key="${key:-1}"
    #             case "$key" in
    #                 #[1234]) iwpriv "$ifname" enc "[$key]";;
    #                 [1234]) iwpriv "$vif" set "Key${idx}=[$key]";;
    #                 *) iwpriv "$vif" set "DefaultKeyID=$key";;
    #             esac
    #         ;;
    #         mixed*|psk*|wpa*|8021x)
    #             # AuthMode=WPAPSK/WPA2PSK/WPAPSKWPA2PSK
    #             # EncrypType=TKIP/AES/TKIPAES
    #             config_get key "$vif" key
    #             iwpriv "$vif" set "AuthMode=WPAPSKWPA2PSK"
    #             iwpriv "$vif" set "EncrypType=TKIPAES"
    #             iwpriv "$vif" set "IEEE8021X=0"
    #             iwpriv "$vif" set "WPAPSK=$key"
    #             iwpriv "$vif" set "DefaultKeyID=2"
    #             iwpriv "$vif" set "RekeyInterval=0"
    #         ;;
    #         wapi*)
    #             config_get key "$vif" key
    #         ;;
    # esac
    
    [ "$dev_disabled" = "1" ] && {
        return
    }
       
    net_cfg="$(find_net_config "$vif")"
    [ -z "$net_cfg" ] || brname="$(bridge_interface "$net_cfg")"
    #[ -z "$brname" ] && brname="br-$net_cfg"   
    create_process "$vif" "$mode" "$brname" "$start_hostapd" "$start_wapid" &
}

config_country() {
    config_get blockdfslist "$1" blockdfslist
    [ -n "$blockdfslist" ] && iwpriv "$phy" blockdfslist "$blockdfslist"

    config_get country "$1" country US
    case "$country" in
        [0-9]*)
            iwpriv "$phy" setCountryID "$country"
        ;;
        *)
            [ -n "$country" ] && iwpriv "$phy" setCountry "$country"
        ;;
    esac   
}

config_vap_mode() {
    local device="$1" vif="$2" mode="$3" chan="$4" txpower="$5"
    local hwmode htbw vhtbw

    tpdbg "config_vap_mode  device=$1 vif=$2 mode=$3 channel=$4 txpower=$5"

    # static int mtk_wireless_mode[]=
    # {
    #    -1,     //0 NONE
    #    1,      //1 WIRELESS_MODE_11B_ONLY
    #    4,      //2 WIRELESS_MODE_11G_ONLY
    #    6,      //3 WIRELESS_MODE_11N_ONLY
    #    0,      //4 WIRELESS_MODE_11BG_MIX
    #    9,      //5 WIRELESS_MODE_11BGN_MIX
    #    7,      //6 WIRELESS_MODE_11NG_MIX
    #    2,      //7 WIRELESS_MODE_11A_ONLY
    #    15,     //8 WIRELESS_MODE_11AC_ONLY     we do not have this mode!!!
    #    8,      //9 WIRELESS_MODE_11NA_MIX
    #    14,     //10 WIRELESS_MODE_11NAAC_MIX
    #    15,     //11 WIRELESS_MODE_11NAC_MIX
    # };

    #  WirelessMode= 9 / 14
    # 2.4G HtBw=0(HT20)/1(HT40)
    # 5G  HtBw/VhtBw: HT20/VHT20(0/0) HT40/VHT40(1/0)  HT40/VHT80(1/1)
    # default: 11ng:HT40 11ac:HT80

    case "$mode" in
    # The parsing stops at the first match so we need to make sure
    # these are in the right orders (most generic at the end)
            *axg:HT20)
                hwmode=16
                htbw=0
            ;;
            *axg:HT40*)
                hwmode=16
                htbw=1
            ;;
            *ng:HT20) 
                hwmode=9
                htbw=0
            ;;
            *ng:HT40*)
                hwmode=9
                htbw=1
            ;;
            *b:*) 
                hwmode=1
                htbw=0
            ;;
            *bg:*) 
                hwmode=0
                htbw=0
            ;;
            *g:*) 
                hwmode=4
                htbw=0
            ;;
            *na:HT20)
                hwmode=8
                htbw=0
                vhtbw=0
            ;;
            *na:HT40*)
                hwmode=8
                htbw=1
                vhtbw=0
            ;;
            *na:*)
                hwmode=8
                htbw=1
                vhtbw=0
            ;;
            *axa:HT20)
                hwmode=17
                htbw=0
                vhtbw=0
            ;;
            *axa:HT40*)
                hwmode=17
                htbw=1
                vhtbw=0
            ;;
            *axa:HT80)
                hwmode=17
                htbw=1
                vhtbw=1
            ;;
            *axa:HT160)
                hwmode=17
                htbw=1
                vhtbw=1
            ;;
            *axa:HT80_80)
                hwmode=17
                htbw=1
                vhtbw=1
            ;;
            *axa:*)
                hwmode=17
                htbw=1
                vhtbw=1
            ;;
            *ac:HT20)
                hwmode=14
                htbw=0
                vhtbw=0
            ;;
            *ac:HT40*)
                hwmode=14
                htbw=1
                vhtbw=0
            ;;
            *ac:HT80)
                hwmode=14
                htbw=1
                vhtbw=1
            ;;
            *ac:HT160)
                hwmode=14
                htbw=1
                vhtbw=1
            ;;
            *ac:HT80_80)
                hwmode=14
                htbw=1
                vhtbw=1
            ;;
            *ac:*)
                hwmode=14
                htbw=1
                vhtbw=1
            ;;
            *a:*)
                hwmode=2
                htbw=1
                vhtbw=0
            ;;
            *) 
                [ "wifi0" = "$device" ] && hwmode=9
                [ "wifi1" = "$device" ] && hwmode=14
                htbw=1
                vhtbw=0
            ;;
    esac

    iwpriv "$vif" set "WirelessMode=$hwmode"
    iwpriv "$vif" set "HtBw=$htbw"

    [ "wifi1" = "$device" ] && iwpriv "$vif" set "VhtBw=$vhtbw"

    [ -n "$chan" ] && {
    wifiextend set_channel "$vif" "$chan"
    }
    wifiextend set_edcca $vif
}

wifi_mode() {
    tpdbg "wifi_mode:$1" 
    local dev vif
    local mode hwmode htmode channel txpower

    local wifi_mode_vap="backhaul"
    [ -f $FACTORYMODE_FILE -a "$(/sbin/is_cal)" = "true" ] && wifi_mode_vap="lan"

    for dev in $1; do
        config_get disabled "$dev" disabled 0
        if [ "$disabled" = "1" ]; then
            for vif in $(config_get "$dev" vifs); do 
                [ -d /sys/class/net/$vif ]  && down_vap "$vif" &>$STDOUT
            done;
            continue
        fi

        # no need to down vap when mode(hwmode/htmode/channel) changed
        # just to set backhaul vap(ra0/rax0) for MTK

        config_get hwmode "$dev" hwmode auto
        config_get htmode "$dev" htmode auto
        config_get channel "$dev" channel 0
        config_get txpower "$dev" txpower

        local vifs=""
        for vif in $(config_get "$dev" vifs); do 
            [ -d /sys/class/net/$vif ] && append vifs "$vif"
            config_get vap_mode "$vif" mode
            config_get vap_type "$vif" type

            if [ "$vap_mode" == "ap" -a "$vap_type" == "$wifi_mode_vap" ]; then
                config_vap_mode "$dev" "$vif" "$hwmode:$htmode" "$channel" "$txpower" &>$STDOUT
            fi
        done;

        # wifi reload when country changed
        #[ -n "$2" -o "$1" = "country" ] && config_country "$dev" &>$STDOUT
    done;
}


wifi_vap() {
    tpdbg "wifi_vap:$1" 
    local device vifs disabled dev_disabled dev_disabled_all
	#get maclist_sec from blacklist.
	config_load blacklist
	maclist_sec=""
	config_foreach getmaclist_sec client 
	
    for vap in $1; do
        config_get device "$vap" device
        config_get vifs "$device" vifs
        config_get disabled "$vap" disabled
        #tpdbg "wifi_vap:device($device) vifs($vifs) disabled($disabled)"

        [ "$disabled" = "1" ] && down_vap "$vap" && continue
        #for vif in $vifs; do ifconfig "$vif" down &>$STDOUT; done

        tpdbg "wifi_vap to config_vap($vap)"

        config_vap "$vap" &>$STDOUT
    done
}




wifi_update() {
    local action="${1//,/ }"
    local device="${2//,/ }"
    local vap="${3//,/ }"


    tpdbg "wifi_update action($action) device($device) vap($vap)"

    #action=${1%% *} && action=${action//,/ }
    #device=${1#* } && device=${device%% *} && device=${device//,/ } 
    #vap=${1##* } && vap=${vap//,/ }
    
    brchanged=0
    
    for cmd in $action; do
        if [ "$cmd" == "vap" ]; then
            [ -z "$vap" ] && vap=$device
            wifi_$cmd "$vap"
        else
            wifi_$cmd "$device"       
        fi
    done
    
    up_all_vap &>$STDOUT
     
}
