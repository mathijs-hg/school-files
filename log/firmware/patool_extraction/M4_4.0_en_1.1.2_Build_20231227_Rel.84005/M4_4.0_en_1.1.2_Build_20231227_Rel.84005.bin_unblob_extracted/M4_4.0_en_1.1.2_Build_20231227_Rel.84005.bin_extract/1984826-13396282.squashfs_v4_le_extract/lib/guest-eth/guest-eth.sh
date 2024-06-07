#!/bin/sh

. /lib/functions.sh
. /usr/lib/eth-encap/eth_encap.sh

DEBUG_OUTOUT=1
LEVEL=6

local section_name
section_name=$(uci -c /etc/vlan.d get vlan.guest_eth 2>/dev/null)
switch_name=$(uci -c /etc/vlan.d get vlan.@switch[0].name)

SWITCH_CPU_PORT=$(get_cpu_port_id)

eth_num=$(get_eth_port_num)

eth_num_seq=$((eth_num-1))

config_load sysmode
config_get system_mode sysmode mode "Router"
config_clear

swconfig() {
    if [ -f "/sbin/swconfig" ]; then
       /sbin/swconfig "$@"
    fi
}

guest_echo() {
    if [ "$DEBUG_OUTOUT" -gt 0 ]; then
            echo "${1}: ""$2"> /dev/console
            logger -p $LEVEL "${1} $2"
        fi
}

touch_section() {
## TODO: Do not use static index number, name it.
    if [ "$section_name" != "switch_vlan" ]; then
        uci -c /etc/vlan.d set vlan.guest_eth="switch_vlan"                              
        uci -c /etc/vlan.d set vlan.guest_eth.device="$switch_device"                           
        uci -c /etc/vlan.d set vlan.guest_eth.vlan="3"                                        

    fi
}

switch_guest_config() {

    local device_type=$1
    local vlan_enable=$2
    local vlan_id=$3
    local iptv_port="other"
    local vlan_support
    vlan_support=$(get_switch_vlan_enable)
    #guest_echo guest-eth "guest-eth start"
    if [ "$vlan_enable" == '0' ]; then
        guest_echo guest-eth "guest vlan not enable, exist"
        return 0;
    fi
    [ -n "$5" ] && iptv_port=$5
    guest_echo guest-eth "Start to set guest vlan"
    #if [ "$sysmode" == "AP" ]; then
    #    return 0;
    #fi
    guest_echo guest-eth "Ignore system signal"
    guest_echo guest-eth "Lock vlan.lock"
    lock /var/run/vlan.lock
    trap "" INT TERM ABRT QUIT ALRM 
    if [ "$device_type" == 'RE' -a -n "$vlan_id" -a -s /tmp/group-info ]; then
        local port_num=$(get_eth_port_num)
        local switch_ports
        local eth_ifaces

        for i in $(seq 0 $((port_num - 1))); do
            local port_mask=$((1 << i))

            if [ $((iptv_port & port_mask)) = 0 ]; then
                local switch_port=$(uci -c /etc/profile.d/ get interfaces.@interface[$i].port)
                local eth_iface=$(uci -c /etc/profile.d/ get interfaces.@interface[$i].name)
                append switch_ports ${switch_port}t
                append eth_ifaces $eth_iface
            fi
        done

        if [ -n "$switch_ports" ]; then
            switch_ports="0t $switch_ports"
            guest_echo guest-eth "set guest vlan: vlan_id=$vlan_id, switch_ports=$switch_ports, eth_ifaces=$eth_ifaces"

            if [ "$vlan_support" == "yes" ]; then
                touch_section
                uci -c /etc/vlan.d set vlan.guest_eth.vid="$vlan_id"
                uci -c /etc/vlan.d set vlan.guest_eth.ports="$switch_ports"
                uci commit -c /etc/vlan.d
                swconfig dev $switch_name load /etc/vlan.d/vlan
            fi

            del_invalid_guest_eth "lan" "$eth_ifaces"
            
            if [[ "$system_mode" != "AP" ]]; then
                add_eth_guest "$eth_ifaces"
            fi
        else
            guest_echo guest-eth "no switch port avaliable for guest network, clear guest vlan"

            if [ "$vlan_support" == "yes" ]; then
                if [ "$section_name" == "switch_vlan" ]; then
                    uci -c /etc/vlan.d delete vlan.guest_eth
                    uci commit -c /etc/vlan.d
                    swconfig dev $switch_name load /etc/vlan.d/vlan
                fi
            fi

            del_invalid_guest_eth "lan" "none"
        fi
    elif [ "$device_type" == 'AP' ] && [ -n "$vlan_id" ]; then
        guest_eth=""
        for i in $(seq 0 1 $eth_num_seq)
        do
            port_seq=$((i+1))
            phy_port=$(uci get profile.switch.phy_port_$port_seq -c /etc/profile.d)
            logic_port=$(uci get profile.switch.logic_port_$port_seq -c /etc/profile.d)
            [ -z "$logic_port" ] && { logic_port=$i; }

            is_eth_at_wan=$(brctl show br-wan | grep eth$logic_port | grep -v eth$logic_port.)

            if [ -z "$is_eth_at_wan" ]; then
                guest_echo guest-eth "AP role, eth$logic_port set tag port, vlan id is $vlan_id"
                append guest_port "${phy_port}t"
                append guest_eth "eth$logic_port"
            fi
        done

        if [ "$vlan_support" == "yes" ]; then
            touch_section
            uci -c /etc/vlan.d set vlan.guest_eth.vid="$vlan_id"
            uci -c /etc/vlan.d set vlan.guest_eth.ports="$guest_eth"
            uci commit -c /etc/vlan.d
            swconfig dev $switch_name load /etc/vlan.d/vlan
        fi
        del_invalid_guest_eth "lan" "$guest_eth"
        if [[ "$system_mode" != "AP" ]]; then
            add_eth_guest "$guest_eth"
        fi

        if [ "$guest_port" = "${SWITCH_CPU_PORT}t" ]; then
            guest_echo guest-eth "AP role, all eth are on br-wan, clear guest network vlan config"
            if [ "$vlan_support" == "yes" ]; then
                if [ "$section_name" == "switch_vlan" ]; then
                    uci -c /etc/vlan.d delete vlan.guest_eth
                    uci commit -c /etc/vlan.d
                    swconfig dev $switch_name load /etc/vlan.d/vlan
                fi
            fi

            del_invalid_guest_eth "lan" "none"
        fi
    fi
    trap - INT TERM ABRT QUIT ALRM 
    lock -u /var/run/vlan.lock
    
}

switch_guest_clear() {
    
    local vlan_support=$(get_switch_vlan_enable)

    lock /var/run/vlan.lock
    trap "" INT TERM ABRT QUIT ALRM 

    if [ "$vlan_support" == "yes" ]; then
        if [ "$section_name" == "switch_vlan" ]; then
            uci -c /etc/vlan.d delete vlan.guest_eth
        fi

        uci commit -c /etc/vlan.d
        swconfig dev $switch_name load /etc/vlan.d/vlan
    fi
    del_invalid_guest_eth "lan" "none"

    trap - INT TERM ABRT QUIT ALRM 
    lock -u /var/run/vlan.lock
}

del_invalid_guest_eth() {
    local network=$1
    local valid_iface=$2
    local wifi_iface
    local vlan_id
    local eth_vlan_ifaces
    local eth_iface
    local iface
    local tmp_id
    
    vlan_id=$(uci get wifi.guest.vlan_id -c /etc/config)

    local all_eth_ifname=""
    all_eth_ifname=$(get_all_eth_names)
    all_eth_ifname=$(echo $all_eth_ifname|sed 's/^[ \t]*$//g')

    for iface in $all_eth_ifname; do
        #valid_iface: eth0.x or eth1.x
        #eth_vlan_ifaces: eth0.x or eth1.x /  eth0.y or eth0.y

        eth_vlan_ifaces=`ifconfig -a| grep "$iface\." | cut -d ' ' -f1`

        for eth_iface in $eth_vlan_ifaces; do
            #check whether ethiface valid
            [ -d "/sys/class/net/br-$network/brif/$eth_iface" ] && {

                if __is_valid_eth_vlan_interfaces "$valid_iface" "$vlan_id" "$eth_iface"; then  
                    continue;
                else
                    # ethiface not valid, delete

                    tmp_id=$(echo $eth_iface | cut -d '.' -f2)
                    guest_echo guest-eth "del eth if id is $tmp_id"

                    if [ "$tmp_id" -ge 3 ] && [ "$tmp_id" -le 1024 ]; then
                        guest_echo guest-eth "del eth if $eth_iface"
                        ifconfig $eth_iface down
                        brctl delif "br-$network" $eth_iface
                        vlan_del $iface $tmp_id
                    fi

                fi

            }
        done

    done
}

__is_valid_eth_vlan_interfaces() {
    local valid_ifaces=$1
    local id=$2
    local iface=$3
    local l_iface

    for l_iface in $valid_ifaces; do
        if [ "$l_iface.$id" = "$iface" ]; then
            return 0
        fi
    done

    return 1
}


add_eth_guest () {
    local ethiface=$1
    local network
    local id
    local interface
    local ifname
    local vlan_support

    config_load repacd
    config_get network repacd ManagedNetwork 'lan'
    config_clear
    vlan_support=$(get_switch_vlan_enable)

    id=$(uci get wifi.guest.vlan_id -c /etc/config)

    if [ -n "$ethiface" ]; then
        for interface in $ethiface; do
            ifname=$(ifconfig 2>&1 | grep "$interface.$id" | cut -d ' ' -f1)
            if [ -z "$ifname" ]; then
                guest_echo guest-eth "add eth if $interface.$id"

                brctl addif "br-$network" "$interface.$id"

                vlan_add $interface $id
                brctl addif "br-$network" "$interface.$id"
                ifconfig $interface.$id mtu 1500
                ifconfig $interface.$id allmulti
                ifconfig $interface.$id up
            fi
        done
    fi    

}
