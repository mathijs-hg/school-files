#!/bin/ash

DEBUG_OUTOUT=1

local WIFI_TYPE_BCM='/tmp/g_wifi_type_bcm'

. /usr/lib/eth-encap/eth_encap.sh

is_vlan_support=$(get_switch_vlan_enable)
if [ "$is_vlan_support" == "yes" ]; then
    . /lib/network/switch.sh
fi

. /lib/functions.sh
. /usr/lib/disconnect_lan.sh

SWITCH_CPU_PORT=$(get_cpu_port_id)

eth_num=$(get_eth_port_num)
eth_num_seq=$((eth_num-1))

all_eth_ifname=""
all_eth_ifname=$(get_all_eth_names)

iptv_echo() {
    if [ "$DEBUG_OUTOUT" -gt 0 ]; then
            echo "${1}: ""$2"> /dev/console
        fi
}

__set_brwan_unisolate()
{
    for if_name in ${all_eth_ifname};do
        if [ -d "/sys/class/net/br-wan/brif/$if_name" ]; then
            echo 0 > /sys/class/net/br-wan/brif/$if_name/isolate_mode
        fi
    done

    ethtool -K "$iface" gro off

}


mv_iface_bridge() {
    local iface="$1"
    local mode="$2"
    if [ "$mode" = "lan2iptv" ]; then

        is_iface_at_lan=$(brctl show br-lan | grep $iface | grep -v $iface.)

        [ -n "$is_iface_at_lan" ] && {
            iptv_echo iptv_shell "move $iface from lan to iptv bridge"
            brctl delif br-lan $iface
            brctl addif br-iptv $iface
            replug_lan_eth_by_name $iface;
        }

    elif [ "$mode" = "iptv2lan" ]; then

        is_iface_at_iptv=$(brctl show br-iptv | grep $iface | grep -v $iface.)
        [ -n "$is_iface_at_iptv" ] && {
            iptv_echo iptv_shell "move $iface from iptv to lan bridge"
            brctl delif br-iptv $iface
            brctl addif br-lan $iface
            replug_lan_eth_by_name $iface;
        }
    elif [ "$mode" = "wan2lan" ]; then

        is_iface_at_wan=$(brctl show br-wan | grep $iface | grep -v $iface.)
        [ -n "$is_iface_at_wan" ] && {
            iptv_echo iptv_shell "move $iface from wan to lan bridge"
            brctl delif br-wan $iface
            brctl addif br-lan $iface
            replug_lan_eth_by_name $iface;
        }
    elif [ "$mode" = "wan2iptv" ]; then

        is_iface_at_wan=$(brctl show br-wan | grep $iface | grep -v $iface.)
        [ -n "$is_iface_at_wan" ] && {
            iptv_echo iptv_shell "move $iface from wan to iptv bridge"
            brctl delif br-wan $iface
            brctl addif br-iptv $iface
            replug_lan_eth_by_name $iface;
        }
    elif [ "$mode" = "lan2wan" ]; then

        is_iface_at_lan=$(brctl show br-lan | grep $iface | grep -v $iface.)
        [ -n "$is_iface_at_lan" ] && {
            iptv_echo iptv_shell "move $iface from lan to wan bridge"
            brctl delif br-lan $iface
            brctl addif br-wan $iface
            replug_lan_eth_by_name $iface;
        }
    elif [ "$mode" = "iptv2wan" ]; then

        is_iface_at_iptv=$(brctl show br-iptv | grep $iface | grep -v $iface.)
        [ -n "$is_iface_at_iptv" ] && {
            iptv_echo iptv_shell "move $iface from iptv to wan bridge"
            brctl delif br-iptv $iface
            brctl addif br-wan $iface
            replug_lan_eth_by_name $iface;
        }
    fi

}

add_iptv_wan_iface() {
    local iface="$1"
    local iptv_vid="$2"
    local iptv_prio="$3"

    echo "we get iface:$iface here" > /dev/console

    local is_port_exist=$(ifconfig -a | grep "$iface\.$iptv_vid")

    if [ -z "$is_port_exist" ]; then
        __add_iptv_wan_iface $iface $iptv_vid $iptv_prio
    else
        iptv_echo iptv_shell "$iface.$iptv_vid exist, do not add iptv wan iface"
        vlan_set_prio $iface $iptv_vid $iptv_prio
    fi
}

__add_iptv_wan_iface() {
    local iface="$1"
    local iptv_vid="$2"
    local iptv_prio="$3"

    if [ -n "$iptv_vid" -a "$iptv_vid" != "0" ]; then
        iptv_echo iptv_shell "add eth if $iface.$iptv_vid, prio: $iptv_prio"
        vlan_add $iface $iptv_vid
        vlan_set_prio $iface $iptv_vid $iptv_prio

        if [ -f $WIFI_TYPE_BCM ]; then
            echo 2 > /sys/devices/virtual/net/$ifname.$tag/brport/multicast_router
        fi
        brctl addif "br-iptv" "$iface.$iptv_vid"
        ifconfig $iface.$iptv_vid mtu 1500
        ifconfig $iface.$iptv_vid up
    fi
}


delete_invalid_iptv_wan_iface() {
    local valid_iface="$1"
    local iptv_vid="$2"
    local bridges="iptv wan"

    local eth_iface

    for iface in $all_eth_ifname; do

        local eth_vlan_ifaces=$(ifconfig -a| grep "$iface\." | cut -d ' ' -f1)

        for eth_iface in $eth_vlan_ifaces; do
            #check whether ethiface valid
            # ethiface not valid, delete
            for bridge in $bridges; do
            [ -d "/sys/class/net/br-$bridge/brif/$eth_iface" ] && {

                [ "$valid_iface.$iptv_vid" = "$eth_iface" ] || {

                    iptv_echo iptv_shell "del eth if $eth_iface"
                    ifconfig $eth_iface down
                    brctl delif "br-$bridge" $eth_iface
                    tag=$(echo $eth_iface | awk -F . '{print $NF}')
                    vlan_del $iface $tag
                } 

            }
            done
        done

    done

}

delete_invalid_lan_vlan_ifaces() {
    local valid_iface="$1"
    local iptv_vid="$2"
    local bridge="lan"

    local eth_iface

    for iface in $all_eth_ifname; do

        local eth_vlan_ifaces=$(ifconfig -a| grep "$iface\." | cut -d ' ' -f1)

        for eth_iface in $eth_vlan_ifaces; do
            #check whether ethiface valid
            # ethiface not valid, delete
            [ -d "/sys/class/net/br-$bridge/brif/$eth_iface" ] && {

                [ "$valid_iface.$iptv_vid" = "$eth_iface" ] || {

                    iptv_echo iptv_shell "del eth if $eth_iface"
                    ifconfig $eth_iface down
                    brctl delif "br-$bridge" $eth_iface
                    tag=$(echo $eth_iface | awk -F . '{print $NF}')
                    vlan_del $iface $tag
                } 

            }
        done

    done

}

# iptv enable change 0->1 or 1->1
set_iptv_interface() {
    local enable=$1
    local vlan_id=$2
    local vlan_prio=$3
    local mode=$4
    local port=$5
    local vlan_support=$(get_switch_vlan_enable)

    config_load iptv_v2
    config_get iptv_enable info enable "0"
    config_get port_mode info port_mode "WAN"
    config_get uplink_port info uplink_port "0"
    config_clear

    local wanstatus=$(cat /tmp/wanDetection)

    local eth_arr
    if_idx=0
    eth_arr=$(get_all_eth_names)

    echo "get eth_arr:$eth_arr" > /dev/console
    
    local eth_at_wan_count=0

    for if_name in $eth_arr
    do
        is_ethX_at_wan=$(brctl show br-wan | grep $if_name | grep -v "$if_name".)
        if [ -n "$is_ethX_at_wan" ];then
            eth_at_wan_count=$((eth_at_wan_count+1))
        fi
    done

    if [ $eth_at_wan_count -eq 0 ]; then
        iptv_echo iptv_shell "no interface at br-wan"
    elif [ $eth_at_wan_count -eq $eth_num ] || [ "$wanstatus" = "1" ]; then
        iptv_echo iptv_shell "all eth are at br-wan"
        delete_invalid_iptv_wan_iface "none" "$vlan_id"
        local wanstatus=$(cat /tmp/wanDetection) 
        if [ "$mode" = "normal" ]; then
            if [ "$wanstatus" = "0" ]; then
                for i in $(seq 0 1 $eth_num_seq)
                do
                    is_ethX_wan=$(isWan eth$i)
                    iptv_echo iptv_shell "mode is $mode , is_ethX_wan : $is_ethX_wan"
                    if [ "$is_ethX_wan" = "true" ]; then
                        iptv_echo iptv_shell "mode is $mode , eth$i is wan"
                        echo "we start to add iptv wan iface:$iface" > /dev/console 
                        add_iptv_wan_iface "eth$i" "$vlan_id" "$vlan_prio"

                        for j in $(seq 0 1 $eth_num_seq)
                        do 
                            port_mask=$((1<<j))
                            port_seq=$((j+1))
                            phy_port=$(get_eth_port_by_seq $port_seq)
                            logic_port=$(get_eth_by_port $phy_port)

                            if [ $((port_mask&port)) -gt 0 ] && [ "$logic_port" != "eth$i" ]; then
                                append iptv_port "${phy_port}t"
                                mv_iface_bridge "$logic_port" "wan2iptv"
                            else
                                mv_iface_bridge "$logic_port" "wan2lan"
                            fi   
                        done
                    fi
                done
                if [ "$vlan_support" == "yes" ]; then
                    local switch_device=$(uci -c /etc/vlan.d get vlan.@switch[0].name)
                    uci -c /etc/vlan.d set vlan.iptv="switch_vlan"
                    uci -c /etc/vlan.d set vlan.iptv.ports="$iptv_port"
                    uci -c /etc/vlan.d set vlan.iptv.device="$switch_device"
                    uci -c /etc/vlan.d set vlan.iptv.vlan="10"
                    uci -c /etc/vlan.d set vlan.iptv.vid=$vlan_id
                    uci commit -c /etc/vlan.d
                    swconfig dev $switch_device load /etc/vlan.d/vlan
                fi
            fi
        elif [ "$mode" = "bridge" ]; then
            if [ "$wanstatus" = "0" ]; then
                for i in $(seq 0 1 $eth_num_seq)
                do
                    is_ethX_wan=$(isWan eth$i)
                    if [ "$is_ethX_wan" = "true" ]; then
                        iptv_echo iptv_shell "mode is $mode , eth$i is wan"

                        for j in $(seq 0 1 $eth_num_seq)
                        do 
                            port_mask=$((1<<j))
                            port_seq=$((j+1))
                            phy_port=$(get_eth_port_by_seq $port_seq)
                            logic_port=$(get_eth_by_port $phy_port)
                            if [ $((port_mask&port)) -eq 0 ] && [ "$logic_port" != "eth$i" ]; then
                                mv_iface_bridge "$logic_port" "wan2lan"
                            fi   
                        done
                    fi
                done
            fi
        fi
    else
        br_show_wan=$(brctl show br-wan)

        for if_name in $eth_arr
        do
            is_ethX_at_wan=$(echo $br_show_wan | grep $if_name)
            echo "get is at wan:$is_ethX_at_wan" > /dev/console
            if [ -n "$is_ethX_at_wan" ];then
                iptv_echo iptv_shell "$if_name at br-wan"
                delete_invalid_iptv_wan_iface "$if_name" "$vlan_id"

                is_ethX_wan=$(isWan $if_name)

                if [ "$mode" = "normal" ]; then
                    echo "we start to add iptv wan iface:$if_name here" > /dev/console
                    add_iptv_wan_iface "$if_name" "$vlan_id" "$vlan_prio"
                    if [ "$port_mode" = "WAN_IPTV" ]; then 
                        if [ "$uplink_port" = "0" ]; then
                            # TODO
                            mv_iface_bridge "eth0" "lan2iptv"
                        fi
                    else
                        for j in $(seq 0 1 $eth_num_seq)
                        do 
                            port_mask=$((1<<j))
                            port_seq=$((j+1))

                            phy_port=$(get_eth_port_by_seq $port_seq)
                            logic_port=$(get_eth_by_port $phy_port)
                            is_ethX_wan=$(isWan $logic_port)
                            if [ $((port_mask&port)) -gt 0 ]; then
                                append iptv_port "${phy_port}t"
                                mv_iface_bridge "$logic_port" "lan2iptv"
                                
                                [ "$is_ethX_wan" = "false" ] && { 
                                    mv_iface_bridge "$logic_port" "wan2iptv"
                                }
                            else
                                mv_iface_bridge "$logic_port" "iptv2lan"
                                [ "$is_ethX_wan" = "false" ] && { 
                                    mv_iface_bridge "$logic_port" "wan2lan"
                                }
                            fi   
                        done

                        if [ "$vlan_support" == "yes" ]; then
                            local switch_device=$(uci -c /etc/vlan.d get vlan.@switch[0].name)
                            uci -c /etc/vlan.d set vlan.iptv="switch_vlan"
                            uci -c /etc/vlan.d set vlan.iptv.ports="$iptv_port"
                            uci -c /etc/vlan.d set vlan.iptv.device="$switch_device"
                            uci -c /etc/vlan.d set vlan.iptv.vlan="10"
                            uci -c /etc/vlan.d set vlan.iptv.vid=$vlan_id
                            uci commit -c /etc/vlan.d
                            swconfig dev $switch_device load /etc/vlan.d/vlan
                        fi
                    fi
                elif [ "$mode" = "bridge" ]; then
                    for j in $(seq 0 1 $eth_num_seq)
                    do 
                        port_mask=$((1<<j))
                        port_seq=$((j+1))

                        phy_port=$(get_eth_port_by_seq $port_seq)
                        logic_port=$(get_eth_by_port $phy_port)
                        is_ethX_wan=$(isWan $logic_port)
                        if [ $((port_mask&port)) -gt 0 ]; then
                            mv_iface_bridge "$logic_port" "lan2wan"
                            mv_iface_bridge "$logic_port" "iptv2wan"
                        else
                            mv_iface_bridge "$logic_port" "iptv2lan"
                            [ "$is_ethX_wan" = "false" ] && { 
                                mv_iface_bridge "$logic_port" "wan2lan"
                            }
                        fi
                    done

                    __set_brwan_unisolate

                    if [ "$vlan_support" == "yes" ]; then
                        local iptv_vlan_info=$(uci -c /etc/vlan.d get vlan.iptv 2>/dev/null)
                        local switch_device=$(uci -c /etc/vlan.d get vlan.@switch[0].name)
                        if [ -n "$iptv_vlan_info" ]; then
                            uci -c /etc/vlan.d delete vlan.iptv
                            uci commit -c /etc/vlan.d
                            swconfig dev $switch_device load /etc/vlan.d/vlan
                        fi
                    fi
   
                fi
            fi
        done
    fi

}

set_iptv_wds_interface(){
    local enable=$1
    local mode=$2
    local iptv_backhaul_vid="3"
    local br_name
    local other_br_name

    if [ "$mode" = "bridge" ]; then
        br_name="br-wan"
        other_br_name="br-iptv"
    else
        br_name="br-iptv"
        other_br_name="br-wan"
    fi

    local all_wds_ifname=$(ifconfig | grep 'wds..... ' | cut -d ' ' -f 1)

    for wds_ifname in $all_wds_ifname; do
        local wds_iface_up=$(ifconfig $wds_ifname | grep UP)

        # del iptv wds interface on other bridge
        local iptv_wds_iface_exist_other=$(brctl show $other_br_name | grep $wds_ifname.$iptv_backhaul_vid)
        if [ -n "$iptv_wds_iface_exist_other" ]; then
            ifconfig $wds_ifname.$iptv_backhaul_vid down
            brctl delif "$other_br_name" "$wds_ifname.$iptv_backhaul_vid"
        fi

        # add iptv wds interface on mode bridge
        local iptv_wds_iface_exist=$(brctl show $br_name | grep $wds_ifname.$iptv_backhaul_vid)
        if [ -n "$iptv_wds_iface_exist" ]; then
            if [ "$enable" == "0" ] || [ -z "$wds_iface_up" ]; then
                ifconfig $wds_ifname.$iptv_backhaul_vid down
                brctl delif "$br_name" "$wds_ifname.$iptv_backhaul_vid"
            fi
        else
            if [ "$enable" == "1" ] && [ -n "$wds_iface_up" ]; then
                if [ ! -d /sys/devices/virtual/net/$wds_ifname.$iptv_backhaul_vid ]; then
                    vlan_add $wds_ifname $iptv_backhaul_vid
                fi
                brctl addif "$br_name" "$wds_ifname.$iptv_backhaul_vid"
                ifconfig $wds_ifname.$iptv_backhaul_vid up
            fi
        fi
    done
}

__clear_iptv() {
    local mode="$1"
    local iface

    delete_invalid_iptv_wan_iface "none" "0"

    local wanstatus=$(cat /tmp/wanDetection) 
    local is_iface_at_wan
    local wan_detect_success="false"
    local wan_iface=""
    
    for iface in $all_eth_ifname; do
        mv_iface_bridge $iface "iptv2lan"
        is_iface_at_wan=$(brctl show br-wan | grep $iface | grep -v $iface.)
        if [ "$wanstatus" = "0" ]; then
            if [ -n "$is_iface_at_wan" ]; then
                local has_wan_flag=$(isWan $iface)
                if [ "$has_wan_flag" = "true" ]; then
                    if [ "$wan_detect_success" = "false" ]; then
                        iptv_echo iptv_shell "$iface is wan"
                        wan_detect_success="true"
                        wan_iface="$iface"
                    else
                        iptv_echo iptv_shell "Error: $iface is wan again"
                    fi
                fi
            fi
        fi
    done

    if [ "$wan_detect_success" = "true" ] && [ -n "$wan_iface" ]; then
        for iface in $all_eth_ifname; do        
            if  [ "$wan_iface" != "$iface" ]; then
                mv_iface_bridge "$iface" "wan2lan"
            fi
        done
    fi

    # TODO
    # 关闭iptv且有线组网时，将hw-switching开启，对于6755方案机型，不支持hw-switching，因此执行该执行之后并不影响
    # added by liujianan 29219428
    # local device_id=$(getfirm DEV_ID)
    # local role=$(uci get bind_device_list."$device_id".role 2>/dev/null)
    # if [ "$role" = "RE" ]; then
    #     [ -f /sbin/ethswctl ] && {
    #         ethswctl -c hw-switching -o enable
    #     }
    # fi

    if [ -f $WIFI_TYPE_BCM ]; then
        # disable iptv wds interface eg:wds1.1.1.3
        set_iptv_wds_interface "0" "$mode"
    fi
}

__setup_iptv() {
    local id=$1
    local prio=$2
    local mode=$3
    local port=$4

    iptv_echo iptv_shell "__setup_iptv"
    if [ -n "$id" ]; then
        set_iptv_interface "1" "$id" "$prio" "$mode" "$port"
    else
        iptv_echo iptv_shell "id is null, invaild input in setup_iptv function"
    fi
}


touch_section() {
## TODO: Do not use static index number, name it.
    local section_name
    section_name=$(uci -c /etc/vlan.d get vlan.iptv_eth_backhaul 2>/dev/null)
    switch_name=$(uci -c /etc/vlan.d get vlan.@switch[0].name)
    if [ "$section_name" != "switch_vlan" ]; then
        uci -c /etc/vlan.d set vlan.iptv_eth_backhaul="switch_vlan"
        uci -c /etc/vlan.d set vlan.iptv_eth_backhaul.device="$switch_name"
        uci -c /etc/vlan.d set vlan.iptv_eth_backhaul.vlan="5"
   fi
}

set_iptv_backhaul_vlan() {
    local enable=$1
    local vlan_id=$2
    local vlan_prio=$3
    local mode=$4
    local port=$5
    local vlan_support=$(get_switch_vlan_enable)
    
    local backhaul_port="${SWITCH_CPU_PORT}t"

    local device_id=$(getfirm DEV_ID)
    local role=$(uci get bind_device_list."$device_id".role 2>/dev/null)

    for i in $(seq 0 1 $eth_num_seq)
    do
        port_mask=$((1<<i))
        port_seq=$((i+1))
        phy_port=$(get_eth_port_by_seq $port_seq)
        logic_port=$(get_eth_by_port $phy_port)
        if [ $((port_mask&port)) -eq 0 ]; then
            if [ "$role" = "AP" ] && [ "$(isWan $logic_port)" = "false" ] || [ "$role" = "RE" ]; then
                append backhaul_port "${phy_port}t"
            fi
        fi
    done

    if [ "$backhaul_port" = "${SWITCH_CPU_PORT}t" ]; then
        iptv_echo iptv_shell "all eth are on br-iptv, no iptv_eth_backhaul"
        uci -c /etc/vlan.d delete vlan.iptv_eth_backhaul
        swconfig dev $switch_name load /etc/vlan.d/vlan
    elif [ "$vlan_support" == "yes" ]; then
        touch_section
        uci -c /etc/vlan.d set vlan.iptv_eth_backhaul.vid="$vlan_id"
        uci -c /etc/vlan.d set vlan.iptv_eth_backhaul.ports="$backhaul_port"
        uci commit -c /etc/vlan.d
        swconfig dev $switch_name load /etc/vlan.d/vlan
    fi

}

add_backhaul_eth_iptv() {
    local ethiface=$1
    local id=$2
    local mode=$3
    local interface
    local ifname
    local vlan_support
    local br_name

    if [ "$mode" = "bridge" ]; then
	br_name="br-wan"
    else
	br_name="br-iptv"
    fi

    vlan_support=$(get_switch_vlan_enable)
    if [ "$id" != "0" ]; then 
        if [ -n "$ethiface" ]; then
            for interface in $ethiface; do
                ifname=`ifconfig 2>&1 | grep "$interface.$id" | cut -d ' ' -f1`
                if [ -z "$ifname" ]; then
                    iptv_echo iptv_shell  "add eth if $interface.$id"
                    vlan_add $interface $id
                    brctl addif "$br_name" "$interface.$id"
                    ifconfig $interface.$id mtu 1500
                    ifconfig $interface.$id allmulti
                    ifconfig $interface.$id up

                else
                    local is_port_exist=$(ifconfig -a | grep "$interface\.$id")
                    if [ -z "$is_port_exist" ]; then
                        vlan_add $interface $id
                        brctl addif "$br_name" "$interface.$id"
                        ifconfig $interface.$id mtu 1500
                        ifconfig $interface.$id allmulti
                        ifconfig $interface.$id up
                    else
                        local is_port_exist_iptv=$(brctl show $br_name | grep "$interface\.$id")
                        if [ -z "$is_port_exist_iptv" ]; then
                            brctl addif "$br_name" "$interface.$id"
                        fi
                        iptv_echo iptv_shell "$interface.$id exist, do not add iptv backhaul iface" 
                    fi
                fi
                vlan_set_prio $interface $id $iptv_prio
            done
        fi
    fi
}

count_self_iptv_ports() {
	local device_id="$1"
	local self_iptv_portmap=0
	uci_load iptv_v2

        [ -z "$CONFIG_SECTIONS" ] && {
		eval "$2='other'"
		return 
	}

        for section in ${CONFIG_SECTIONS}; do
                config_get cfgtype "$section" TYPE
                [ "$cfgtype" != "ports" ] && continue
                
		config_get entry_devid "$section" "device_id"
		config_get entry_enable "$section" "enable" "0"
		config_get entry_port "$section" "port" "-1"
		if [ "$entry_enable" = "1" ] && [ "$device_id" = "$entry_devid" ] && [ "$entry_port" -ge 0 ]; then
			local port_mask=$((1<<entry_port))
			self_iptv_portmap=$((self_iptv_portmap|port_mask))
		fi
        done

	if [ "$self_iptv_portmap" -eq "0" ]; then
		eval "$2='other'"
		return 
	fi

	# self_iptv_portmap=$((self_iptv_portmap-1))
	eval "$2='$self_iptv_portmap'"
	return 
}

__iptv_check_device_mode() {
    local config="$1"
    local enabled devid
    local role

   config_get enabled "$config" enable
   if [ "$enabled" != "0" ]; then
	config_get devid "$config" device_id
	config_load bind_device_list
	config_get role $devid role
	if [ "$role" = "RE" ]; then
		eval "$2='0'"
	fi

   fi
}

check_iptv_only_on_ap() {
    local is_iptv_ap_only="1"

    config_load iptv_v2
    config_foreach __iptv_check_device_mode ports is_iptv_ap_only

    if [ "$is_iptv_ap_only" = "1" ];then
	return 0
    else
	return 1
    fi
}

add_fap_backhaul_eth() {
    local id=$1
    local prio=$2
    local mode=$3
    local port=$4

    echo "we are in add fap backhaul eth here" > /dev/console

    if [ "$(cat /tmp/wanDetection)" -ne 0 ]; then
        iptv_echo iptv_shell "Wandetection is not done yet, do not setup iptv backhaul"
        return
    fi

    if check_iptv_only_on_ap ; then
        iptv_echo iptv_shell "ALL iptv port are on FAP, on nedd to add eth iptv backhaul. "
        return
    fi
 
    if [ $eth_num -eq 2 ] && [ "$port" != "other" ]; then
        iptv_echo iptv_shell "one eth in br-wan and another in br-iptv, no eth iptv backhaul"
    else
        for i in $(seq 0 1 $eth_num_seq)
        do
            port_mask=$((1<<i))
            port_seq=$((i+1))

            phy_port=$(get_eth_port_by_seq $port_seq)
            logic_port=$(get_eth_by_port $phy_port)
            if [ $((port_mask&port)) -eq 0 ] && [ "$(isWan $logic_port)" = "false" ]; then
                add_backhaul_eth_iptv "$logic_port" "$id" "$mode"
            fi
        done
        set_iptv_backhaul_vlan "1" "$id" "$prio" "$mode" "$port"
    fi
}

set_re_iptv_interface() {
    local enable=$1
    local vlan_id=$2
    local prio=$3
    local mode=$4
    local port=$5

    local backhaul_eth=""
    for i in $(seq 0 1 $eth_num_seq)
    do
        port_mask=$((1<<i))
        port_seq=$((i+1))
        phy_port=$(get_eth_port_by_seq $port_seq)
        logic_port=$(get_eth_by_port $phy_port)
        if [ $((port_mask&port)) -gt 0 ]; then
            mv_iface_bridge "$logic_port" "lan2iptv"
        else
            append backhaul_eth "$logic_port"
        fi
    done
    add_backhaul_eth_iptv "$backhaul_eth" "$vlan_id" "$mode"

    # TODO
    # 6756方案，内置了一个switch，有线组网时，若enable hw-switching，RE上的ethX无法成功把数据转发到iptv有线backhaul接口ethY.491，
    # 此处的一个暂时的解决方案是当打开iptv时，将RE的hw-switching给disable。
    # added by liujianan 20210428
    if [ -f /sbin/ethswctl ] && [ -f $WIFI_TYPE_BCM ]; then
        ethswctl -c hw-switching -o disable
    fi
}

clear_re_bridge() {
    local iface=$1
    is_iface_at_lan=`brctl show br-lan | grep $iface | grep -v $iface.`
    is_iface_at_iptv=`brctl show br-iptv | grep $iface | grep -v $iface.`
    
}

__setup_re_iptv() {
    local id=$1
    local prio=$2
    local mode=$3
    local port=$4
    if [ -n "$id" ]; then
        set_re_iptv_interface "1" "$id" "$prio" "$mode" "$port"
        set_iptv_backhaul_vlan "1" "$id" "$prio" "$mode" "$port"
    else
        iptv_echo iptv_shell "id is null, invaild input in setup_iptv function"
    fi
}

__setup_internet_vlan() {
    local vlan_enable
    local vlan_support

    vlan_support=$(get_switch_vlan_enable)
	vlan_enable=$(uci get network.vlan.enable)

    if [ "$vlan_support" == "yes" ]; then
        if [ "$vlan_enable" == "1" ]; then 
            __set_wan_vlan
        elif [ "$vlan_enable" == "0" ]; then 
            __reset_wan_vlan
        fi
    fi

}

clear_iptv() {

    local vlan_support=$(get_switch_vlan_enable)


    local mode="$1"
    local br=$(brctl show | grep br-iptv)
    if [ -n "$br" ]; then
        __clear_iptv "$mode"
    fi

    lock /var/run/vlan.lock
    trap "" INT TERM ABRT QUIT ALRM 

    if [ "$vlan_support" == "yes" ]; then
        __setup_internet_vlan
        local iptv_vlan_info=$(uci -c /etc/vlan.d get vlan.iptv 2>/dev/null)
	local iptv_vlan_backhaul_info=$(uci -c /etc/vlan.d get vlan.iptv_eth_backhaul 2>/dev/null)
        local switch_device=$(uci -c /etc/vlan.d get vlan.@switch[0].name)
        if [ -n "$iptv_vlan_info" ] || [ -n "$iptv_vlan_backhaul_info" ]; then
            uci -c /etc/vlan.d delete vlan.iptv
            uci -c /etc/vlan.d delete vlan.iptv_eth_backhaul
            uci commit -c /etc/vlan.d
            swconfig dev $switch_device load /etc/vlan.d/vlan
        fi
    fi

    trap - INT TERM ABRT QUIT ALRM 
    lock -u /var/run/vlan.lock
}


setup_iptv() {
    local id="$1"
    local prio="$2"
    local mode="$3"
    local role="$4"
    local port="$5"
    local backhaul_id=$(uci get iptv_v2.info.iptv_backhaul_vid 2>/dev/null)
    if [ -z "$backhaul_id" ]; then 
        backhaul_id="491"
    fi

    lock /var/run/vlan.lock
    trap "" INT TERM ABRT QUIT ALRM 
    if [ "$role" != "re_mode" ]; then
        __setup_internet_vlan
        if [ "$mode" = "bridge" ]; then
            __setup_iptv "$id" "$prio" "bridge" "$port" 
            add_fap_backhaul_eth "$backhaul_id" "$prio" "bridge" "$port" 
        else
            __setup_iptv "$id" "$prio" "normal" "$port"
            add_fap_backhaul_eth "$backhaul_id" "$prio" "normal" "$port" 
        fi
    else
        __reset_wan_vlan
        __setup_re_iptv "$backhaul_id" "$prio" "normal" "$port"
    fi

    if [ -f $WIFI_TYPE_BCM ]; then
        # enable iptv wds interface eg:wds1.1.1.3
        set_iptv_wds_interface "1" "$mode"
    fi

    trap - INT TERM ABRT QUIT ALRM 
    lock -u /var/run/vlan.lock
    
}
