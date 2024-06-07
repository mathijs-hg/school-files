#!/bin/sh

_hide_ssid() {
    local vif=$1
    local disable=$2

    [ "$vif" == "" ] && return
    [ ! -d /sys/class/net/"$vif" ] && return
    [ ! -f "/tmp/factorymode" ] && return
    [ "$disable" = 0 ] && return
	[ "$(/sbin/is_cal)" != "true" ] && return

    echo "hide ifname(${vif}) at factory mode"
    iwpriv $vif set HideSSID=1
    iwpriv $vif set AuthMode=OPEN
    iwpriv $vif set EncrypType=NONE
    iwpriv $vif set ACLClearAll=1
    iwpriv $vif set ftenable=0
    iwpriv $vif set SSID=
}

_set_essid() {
    local opt_name=$1;
    local mac_str=$2;

    [ "$opt_name" == "" -o "$mac_str" == "" ] && return

    echo "set essid" > /dev/console
    local wifi_2g="_2G_";
    local wifi_5g="_5G_";

    local ssid_2g="$opt_name$wifi_2g$mac_str"
    local ssid_5g="$opt_name$wifi_5g$mac_str"
    local prefix_2g="ra"
    local prefix_5g="rai"
    local backhaul_idx="0"
    local main_idx="2"

    if [ -d "/sys/class/net/rax0/" ]; then
        prefix_5g="rax"
    fi

    local main_2g=$prefix_2g$main_idx
    local main_5g=$prefix_5g$main_idx

    local vif_2g=$main_2g
    local vif_5g=$main_5g

    # echo "vif_2g is $vif_2g and SSID will be $ssid_2g"
    # echo "vif_5g is $vif_5g and SSID will be $ssid_5g"

    iwpriv $vif_2g set HideSSID=0
    iwpriv $vif_2g set AuthMode=OPEN
    iwpriv $vif_2g set EncrypType=NONE
    iwpriv $vif_2g set ACLClearAll=1
    iwpriv $vif_2g set ftenable=1
    iwpriv $vif_2g set SSID=$ssid_2g

    iwpriv $vif_5g set HideSSID=0
    iwpriv $vif_5g set AuthMode=OPEN
    iwpriv $vif_5g set EncrypType=NONE
    iwpriv $vif_5g set ACLClearAll=1
    iwpriv $vif_5g set ftenable=1
    iwpriv $vif_5g set SSID=$ssid_5g
    iwpriv $vif_5g set NoForwarding=0
    iwpriv $vif_5g set NoForwardingBTNBSSID=0
}

main() {
    case "$1" in
        hide_ssid) shift 1; _hide_ssid "$@";;
        *) _set_essid "$@";;
    esac
}

main $@
