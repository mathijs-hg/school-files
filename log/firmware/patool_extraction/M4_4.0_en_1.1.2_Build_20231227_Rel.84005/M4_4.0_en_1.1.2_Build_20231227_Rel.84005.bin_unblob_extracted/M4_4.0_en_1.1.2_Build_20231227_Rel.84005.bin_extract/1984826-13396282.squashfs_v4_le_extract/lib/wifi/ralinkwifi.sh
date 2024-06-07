#!/bin/sh
#
# Copyright (c) 2014, 2016, The Linux Foundation. All rights reserved.
#
#  Permission to use, copy, modify, and/or distribute this software for any
#  purpose with or without fee is hereby granted, provided that the above
#  copyright notice and this permission notice appear in all copies.
#
#  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
#  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
#  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
#  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
#  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
#  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
#  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#
append DRIVERS "ralinkwifi"

DEBUG=1

wlanconfig() {
	[ -n "${DEBUG}" ] && echo wlanconfig "$@" > /dev/console
	/usr/sbin/wlanconfig "$@"
}

iwconfig() {
	[ -n "${DEBUG}" ] && echo iwconfig "$@" > /dev/console
	/usr/sbin/iwconfig "$@"
}

iwpriv() {
	[ -n "${DEBUG}" ] && echo iwpriv "$@" > /dev/console
	/usr/sbin/iwpriv "$@"
}

COMMON_DEBUG=1
STDOUT="/dev/null"

if [ "$COMMON_DEBUG" = "1" ];then
    DEBUG_ECHO=echo
    STDOUT="/dev/console"
fi

dbg_print() {
    ${DEBUG_ECHO:-:} "$*" >$STDOUT
}

find_ralinkwifi_phy() {
	local device="$1"

	local macaddr="$(config_get "$device" macaddr | tr 'A-Z' 'a-z')"
	config_get phy "$device" phy
	[ -z "$phy" -a -n "$macaddr" ] && {
		cd /sys/class/net
		for phy in $(ls -d wifi* 2>&-); do
			[ "$macaddr" = "$(cat /sys/class/net/${phy}/address)" ] || continue
			config_set "$device" phy "$phy"
			break
		done
		config_get phy "$device" phy
	}
	[ -n "$phy" -a -d "/sys/class/net/$phy" ] || {
		dbg_print "phy for wifi device $1 not found"
		return 1
	}
	[ -z "$macaddr" ] && {
		config_set "$device" macaddr "$(cat /sys/class/net/${phy}/address)"
	}
	return 0
}

scan_ralinkwifi() {
	local device="$1"
	local wds
	local adhoc sta ap monitor ap_monitor ap_smart_monitor mesh ap_lp_iot ap_guest disabled

	[ ${device%[0-9]} = "wifi" ] && config_set "$device" phy "$device"

	local ifidx=0
	local radioidx=${device#wifi}

	config_get vifs "$device" vifs
	for vif in $vifs; do
		config_get_bool disabled "$vif" disabled 0
		config_get mode "$vif" mode
		[ $disabled = 0 ] || continue
#		[ $disabled = 1 -a "$mode" != "sta" ] && continue

		config_set "$vif" ifname $vifname
	
		dbg_print "scan_ralinkwifi config_set vif($vif) vifname($vifname) mode($mode)"

		case "$mode" in
			adhoc|sta|ap|monitor|wrap|ap_monitor|ap_smart_monitor|mesh|ap_lp_iot|ap_guest)
				append "$mode" "$vif"
				dbg_print "scan_ralinkwifi append mode($mode) vif($vif) "
			;;
			wds)
				config_get ssid "$vif" ssid
				[ -z "$ssid" ] && continue

				config_set "$vif" wds 1
				config_set "$vif" mode sta
				mode="sta"
				addr="$ssid"
				${addr:+append "$mode" "$vif"}

			;;
			*) echo "$device($vif): Invalid mode, ignored."; continue;;
		esac

		ifidx=$(($ifidx + 1))
	done

	case "${adhoc:+1}:${sta:+1}:${ap:+1}" in
		# valid mode combinations
		1::) wds="";;
		1::1);;
		:1:1)config_set "$device" nosbeacon 1;; # AP+STA, can not use beacon timers for STA
		:1:);;
		::1);;
		::);;
		*) echo "$device: Invalid mode combination in config"; return 1;;
	esac

	config_set "$device" vifs "${ap:+$ap }${ap_guest:+$ap_guest }${ap_monitor:+$ap_monitor }${mesh:+$mesh }${ap_smart_monitor:+$ap_smart_monitor }${wrap:+$wrap }${sta:+$sta }${adhoc:+$adhoc }${wds:+$wds }${monitor:+$monitor}${ap_lp_iot:+$ap_lp_iot}"
}

# The country ID is set at the radio level. When the driver attaches the radio,
# it sets the default country ID to 840 (US STA). This is because the desired
# VAP modes are not known at radio attach time, and STA functionality is the
# common unit of 802.11 operation.
# If the user desires any of the VAPs to be in AP mode, then we set a new
# default of 843 (US AP with TDWR) from this script. Even if any of the other
# VAPs are in non-AP modes like STA or Monitor, the stricter default of 843
# will apply.
# No action is required here if none of the VAPs are in AP mode.
set_default_country() {
	local device="$1"
	local mode

	find_ralinkwifi_phy "$device" || return 1
	config_get phy "$device" phy

	config_get vifs "$device" vifs
	for vif in $vifs; do
		config_get_bool disabled "$vif" disabled 0
		[ $disabled = 0 ] || continue

		config_get mode "$vif" mode
		case "$mode" in
			ap|wrap|ap_monitor|ap_smart_monitor|ap_lp_iot)
				echo "iwpriv phy($phy) setCountryID 843" > /dev/console
				iwpriv "$phy" setCountryID 843
				return 0;
			;;
		*) ;;
		esac
	done

	return 0
}

is_low_mem_system() {
	local board_name
	[ -f /tmp/sysinfo/board_name ] && {
		board_name=$(cat /tmp/sysinfo/board_name)
	}
	memtotal=$(grep MemTotal /proc/meminfo | awk '{print $2}')

	case "$board_name" in
		ap-dk01.1-c1 | ap-dk01.1-c2 | ap-dk04.1-c1 | ap-dk04.1-c2 | ap-dk04.1-c3)
			if [ $memtotal -le 131072 ]; then
				echo "true"
			else
				echo "false"
			fi
		;;

		*) echo "false"
		;;
	esac
}

config_low_targ_clkspeed() {
        local board_name
        [ -f /tmp/sysinfo/board_name ] && {
                board_name=$(cat /tmp/sysinfo/board_name)
        }

        case "$board_name" in
                ap147 | ap151)
                   echo "true"
                ;;
                *) echo "false"
                ;;
        esac
}

# configure tx queue fc_buf_max
config_tx_fc_buf() {
	local phy="$1"
	local board_name
	[ -f /tmp/sysinfo/board_name ] && {
		board_name=$(cat /tmp/sysinfo/board_name)
	}
	memtotal=$(grep MemTotal /proc/meminfo | awk '{print $2}')

	case "$board_name" in
		MT7628*)
			if [ $memtotal -le 131072 ]; then
				# 4MB tx queue max buffer size
				echo "config_tx_fc_buf" > /dev/console
			elif [ $memtotal -le 256000 ]; then
				# 8MB tx queue max buffer size
				echo "config_tx_fc_buf" > /dev/console
			fi
				# default value from code memsize > 256MB
		;;

		*)
		;;
	esac
}

disable_ralinkwifi() {
	local device="$1"
	local parent
	local retval=0

	config_get phy "$device" phy
	set_wifi_down "$device"

	dbg_print "disable_ralinkwifi DRIVERS($DRIVERS) device($device) vifs($vifs)"

	for vif in $vifs; do
		if [ -d /sys/class/net/${vif} ]; then
			config_get vif_mode "$vif" mode
			config_get vif_type "$vif" type

			# no need to down ra0/rax0 here
			if [ "backhaul" != "$vif_type" -o "ap" != "$vif_mode" ]; then
				ifconfig "$vif" down
				dbg_print "disable_ralinkwifi DRIVERS($DRIVERS) device($device) vifs($vifs) vif($vif)"
			fi
		fi
	done

	return 0
}

getmaclist_sec() {
	local section="$1"
	config_get mac "$section" mac
	mac=${mac//-/:}
	append maclist_sec "$mac "
}

enable_ralinkwifi() {
	local device="$1"
	local count=0
	local backhaul_ifname=""
    local essid_file="/lib/essid/essid.sh"

	#get maclist_sec from blacklist.
	config_load blacklist
	maclist_sec=""
	config_foreach getmaclist_sec client 

	config_get phy "$device" phy
    config_get channel "$device" channel
    config_get txpower "$device" txpower

    [ auto = "$channel" ] && channel=0

	for vif in $vifs; do
		local vif_txpower= nosbeacon= wlanaddr=""
		local disabled
		local realup="1"
		config_get ifname "$vif" ifname
		config_get enc "$vif" encryption "none"
		config_get eap_type "$vif" eap_type
		config_get mode "$vif" mode
		config_get ifname "$vif" vapname
		config_get vif_type "$vif" type
		config_get disabled "$vif" disabled

		dbg_print "enable_ralinkwifi: DRIVERS($DRIVERS): device($device) vifs($vifs) vif($vif) disabled($disabled)" >/dev/console

		# for MTK drivers: up ra0, rai0/rax0 at the first
		if [ "backhaul" = "$vif_type" -a "ap" = "$mode" ]; then
			ifconfig "$vif" up
			backhaul_ifname="$ifname"
			dbg_print "enable_ralinkwifi: ifconfig ifname(${ifname}) up"
            if [ -f "$essid_file" ]; then
                sh $essid_file hide_ssid "$vif" "$disable"
            fi
		fi

		[ "$disabled" = 1 -a "$vif_type" != "backhaul" ] && continue

 		if [ ! -d /sys/class/net/${ifname} ]; then
			ifconfig "${vif}" up
			dbg_print "enable_ralinkwifi: ifconfig ifname(${ifname}) up "
		fi

		[ $? -ne 0 ] && {
			echo "enable_ralinkwifi($device): Failed to set up $mode vif $ifname" > /dev/console
			continue
		}
        
		[ "$disabled" = 1 -a "$mode" != "sta" -a "$vif_type" != "backhaul" ] && continue    
		[ "$disabled" = 1 -a "$mode" = "sta" ] && realup="0"    
        
		config_set "$vif" ifname "$ifname"

		config_get hwmode "$device" hwmode auto
		config_get htmode "$device" htmode auto

		if [ "backhaul" = "$vif_type" -a "ap" = "$mode" ]; then
			dbg_print "enable_ralinkwifi to config vap wirless mode"

			iw_info=$(iwconfig "$vif")
			res=$(echo "$iw_info" | grep -o Channel)
			[ "$res" = "" ] && {
				echo "--------Failed to up $vif and retry--------" > /dev/console
				ifconfig "$vif" up
			}

			config_vap_mode "$device" "$vif" "$hwmode:$htmode" "$channel" "$txpower" &>$STDOUT
		fi

		local net_cfg bridge
		net_cfg="$(find_net_config "$vif")"

		[ -n "$net_cfg" -a "backhaul" != "$net_cfg" ] && { \
			bridge="$(bridge_interface "$net_cfg")"
			config_set "$vif" bridge "$bridge"
        }

		case "$mode" in
			ap|wrap|ap_monitor|ap_smart_monitor|mesh|ap_lp_iot|ap_guest)
				setup_vif_ap "$vif" || {
					echo "enable_wifi($device): Failed to set up wapid for interface $ifname" >&2
					ifconfig "$ifname" down
					#wlanconfig "$ifname" destroy
					continue
				}
			;;
			wds|sta)
					if [ "$realup" = "1" ]; then
					 setup_vif_sta "$vif" || {
						echo "enable_qcawifi($device): Failed to set up wpa_supplicant for interface $ifname" >&2
						ifconfig "$ifname" down
						#wlanconfig "$ifname" destroy
						continue
					}
					fi
			;;
			*)
				echo "enable_ralinkwifi ; unknow mode:$mode" > /dev/console	
			;;
		esac

		# [ -z "$bridge" -o "$isolate" = 1 -a "$mode" = "wrap" ] || {
		#       [ -f /sys/class/net/${ifname}/parent ] && { \
		# 		start_net "$ifname" "$net_cfg"
  #                       }
		# }

		if [ "$realup" = "1" ]; then
			ifconfig "$ifname" up
			set_wifi_up "$vif" "$ifname"
		elif [ "$mode" = "sta" ]; then
			uci_set_state wireless "$vif" ifname "$ifname"
		fi

		#config_get vif_txpower "$vif" txpower
		# use vif_txpower (from wifi-iface) instead of txpower (from wifi-device) if
		# the latter doesn't exist
		#txpower="${txpower:-$vif_txpower}"
		#[ -z "$txpower" ] || iwconfig "$ifname" txpower "${txpower%%.*}"


		#share wifi1 process to cpu0,1,3
		#if [ "wifi1" = "$device" ]; then
		#	echo 3 > /sys/devices/virtual/net/${ifname}/queues/rx-0/rps_cpus
		#fi

		[ -n "$bridge" -a "backhaul" != "$net_cfg" ] && [ ! -e /sys/class/net/$bridge/brif/$vif ] && {
	        dbg_print "enable_ralinkwifi brctl addif brname:$bridge vif($vif)"
	        brctl addif "$bridge" "$vif"
	        [ "$?" = "0" ] && brchanged=1
	        #ubus call network.interface.lan add_device "{\"name\":\"$vif\"}"
	    }

	done

	config_get disabled "$backhaul_ifname" disabled
    wifiextend set_backhaul  "$backhaul_ifname" "$disabled"
    wifiextend set_edcca  "$backhaul_ifname"
}

setup_wps_enhc_device() {
	local device=$1
	local wps_enhc_cfg=

	append wps_enhc_cfg "RADIO" "$N"
	config_get_bool wps_pbc_try_sta_always "$device" wps_pbc_try_sta_always 0
	config_get_bool wps_pbc_skip_ap_if_sta_disconnected "$device" wps_pbc_skip_ap_if_sta_disconnected 0
	config_get_bool wps_pbc_overwrite_ap_settings "$device" wps_pbc_overwrite_ap_settings 0
	config_get wps_pbc_overwrite_ssid_band_suffix "$device" wps_pbc_overwrite_ssid_band_suffix
	[ $wps_pbc_try_sta_always -ne 0 ] && \
			append wps_enhc_cfg "$device:try_sta_always" "$N"
	[ $wps_pbc_skip_ap_if_sta_disconnected -ne 0 ] && \
			append wps_enhc_cfg "$device:skip_ap_if_sta_disconnected" "$N"
	[ $wps_pbc_overwrite_ap_settings -ne 0 ] && \
			append wps_enhc_cfg "$device:overwrite_ap_settings" "$N"
	[ -n "$wps_pbc_overwrite_ssid_band_suffix" ] && \
			append wps_enhc_cfg "$device:overwrite_ssid_band_suffix:$wps_pbc_overwrite_ssid_band_suffix" "$N"

	config_get vifs $device vifs

	for vif in $vifs; do
		config_get ifname "$vif" ifname

		append wps_enhc_cfg "VAP" "$N"
		config_get_bool wps_pbc_enable "$vif" wps_pbc_enable 0
		config_get wps_pbc_start_time "$vif" wps_pbc_start_time
		config_get wps_pbc_duration "$vif" wps_pbc_duration
		if [ $wps_pbc_enable -ne 0 ]; then
			[ -n "$wps_pbc_start_time" -a -n "$wps_pbc_duration" ] && \
					append wps_enhc_cfg "$ifname:$wps_pbc_start_time:$wps_pbc_duration:$device" "$N"
			[ -n "$wps_pbc_start_time" -a -n "$wps_pbc_duration" ] || \
					append wps_enhc_cfg "$ifname:-:-:$device" "$N"
		fi
	done

	cat >> /var/run/wifi-wps-enhc-extn.conf <<EOF
$wps_enhc_cfg
EOF
}

setup_wps_enhc() {
	local wps_enhc_cfg=

	append wps_enhc_cfg "GLOBAL" "$N"
	config_get_bool wps_pbc_overwrite_ap_settings_all ralinkwifi wps_pbc_overwrite_ap_settings_all 0
	[ $wps_pbc_overwrite_ap_settings_all -ne 0 ] && \
			append wps_enhc_cfg "-:overwrite_ap_settings_all" "$N"
	config_get wps_pbc_overwrite_ssid_suffix ralinkwifi wps_pbc_overwrite_ssid_suffix
	[ -n "$wps_pbc_overwrite_ssid_suffix" ] && \
			append wps_enhc_cfg "-:overwrite_ssid_suffix:$wps_pbc_overwrite_ssid_suffix" "$N"

	cat >> /var/run/wifi-wps-enhc-extn.conf <<EOF
$wps_enhc_cfg
EOF

	config_load wireless
	config_foreach setup_wps_enhc_device wifi-device
}

ralinkwifi_start_hostapd_cli() {
	local device=$1
	local ifidx=0
	local radioidx=${device#wifi}

	config_get vifs $device vifs

	for vif in $vifs; do
		local config_methods vifname

		config_get vifname "$vif" ifname

		if [ -n $vifname ]; then
			[ $ifidx -gt 0 ] && vifname="ath${radioidx}$ifidx" || vifname="ath${radioidx}"
		fi

		config_get_bool wps_pbc "$vif" wps_pbc 0
		config_get config_methods "$vif" wps_config
		[ "$wps_pbc" -gt 0 ] && append config_methods push_button

		if [ -n "$config_methods" ]; then
			pid=/var/run/hostapd_cli-$vifname.pid
			hostapd_cli -i $vifname -P $pid -a /lib/wifi/wps-hostapd-update-uci -p /var/run/hostapd-$device -B
		fi

		ifidx=$(($ifidx + 1))
	done
}

pre_ralinkwifi() {
	local action=${1}

	#config_load wireless

	case "${action}" in
		disable)
			echo "nothing to be done for pre_ralinkwifi disable " > /dev/console
		;;
	esac
}

post_ralinkwifi() {
	local action=${1}

	case "${action}" in
		enable)
			echo "nothing to be done for post_ralinkwifi enable " > /dev/console
		;;
	esac
}

check_ralinkwifi_device() {

	echo "check_ralinkwifi_device config_set $1 phy $1" >/dev/console

	[ ${1%[0-9]} = "wifi" ] && config_set "$1" phy "$1"
	config_get phy "$1" phy
	[ -z "$phy" ] && {
		find_ralinkwifi_phy "$1" >/dev/null || return 1
		config_get phy "$1" phy
	}
	[ "$phy" = "$dev" ] && found=1
}


detect_ralinkwifi() {
	devidx=0
	olcfg_ng=0
	olcfg_ac=0
	nss_olcfg=0
	nss_ol_num=0
	reload=0
	sleep 3
	config_load wireless
	while :; do
		config_get type "wifi$devidx" type
		[ -n "$type" ] || break
		devidx=$(($devidx + 1))
	done
	cd /sys/class/net
	[ -d wifi0 ] || return
	for dev in $(ls -d wifi* 2>&-); do
		found=0
		config_foreach check_ralinkwifi_device wifi-device
		[ "$found" -gt 0 ] && continue

		hwcaps=$(cat ${dev}/hwcaps)
		case "${hwcaps}" in
			*11bgn) mode_11=ng;;
			*11abgn) mode_11=ng;;
			*11an) mode_11=na;;
			*11an/ac) mode_11=ac;;
			*11abgn/ac) mode_11=ac;;
		esac
		if [ -f /sys/class/net/${dev}/nssoffload ] && [ $(cat /sys/class/net/${dev}/nssoffload) == "capable" ]; then
			case "${mode_11}" in
				ng)
					if [ $olcfg_ng == 0 ]; then
						olcfg_ng=1
						nss_olcfg=$(($nss_olcfg|$((1<<$devidx))))
						nss_ol_num=$(($nss_ol_num + 1))
					fi
				;;
				na|ac)
					if [ $olcfg_ac == 0 ]; then
						olcfg_ac=1
						nss_olcfg=$(($nss_olcfg|$((1<<$devidx))))
						nss_ol_num=$(($nss_ol_num + 1))
					fi
				;;
			esac
		fi
		echo $nss_olcfg >/lib/wifi/wifi_nss_olcfg
		echo $nss_ol_num >/lib/wifi/wifi_nss_olnum
		reload=1
		cat <<EOF
config wifi-device  wifi$devidx
	option type	ralinkwifi
	option channel	auto
	option macaddr	$(cat /sys/class/net/${dev}/address)
	option hwmode	11${mode_11}
	# REMOVE THIS LINE TO ENABLE WIFI:
	option disabled 1

config wifi-iface
	option device	wifi$devidx
	option network	lan
	option mode	ap
	option ssid	OpenWrt
	option encryption none

EOF
	devidx=$(($devidx + 1))
	done

}

# Handle traps here
trap_ralinkwifi() {
	# Release any locks taken
	lock -u /var/run/wifilock
}
