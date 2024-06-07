#!/bin/sh
. /usr/lib/eth-encap/eth_encap.sh

replug_lan_eth() {

    local port
    local if_name
    local all_eth_name=$(get_all_eth_names)

    for if_name in $all_eth_name
    do
        if [ $(brctl show br-lan  2>&1 | grep -E "$if_name") == "$if_name" ]; then
            port=$(get_port_by_eth $if_name)
            echo "we get $if_name port:$port and down" > /dev/console
            ssdk_sh port poweroff set $port
            sleep 1
            ssdk_sh port poweron set $port
        fi
    done

}

replug_lan_eth_by_name() {

    local port0
    local port1
    local port2

    local eth0
    local eth1
    local eth2

    echo "replug_lan_eth_by_name $1" > dev/console

    eth0=$(uci -c /etc/profile.d get interfaces.@interface[0].name)
    eth1=$(uci -c /etc/profile.d get interfaces.@interface[1].name)
    eth2=$(uci -c /etc/profile.d get interfaces.@interface[2].name)

    port0=$(uci -c /etc/profile.d get interfaces.@interface[0].port)
    port1=$(uci -c /etc/profile.d get interfaces.@interface[1].port)
    port2=$(uci -c /etc/profile.d get interfaces.@interface[2].port)

    [ "$1" == "$eth0" ] && {
        echo "we get $eth0 port:$port0 and down" > /dev/console
        ssdk_sh port poweroff set $port0
        sleep 1
        ssdk_sh port poweron set $port0
    }

    [ "$1" == "$eth1" ] && {
        echo "we get $eth1 port:$port1 and down" > /dev/console
        ssdk_sh port poweroff set $port1
        sleep 1
        ssdk_sh port poweron set $port1
    }

    [ "$1" == "$eth2" ] && {
        echo "we get $eth2 port:$port2 and down" > /dev/console
        ssdk_sh port poweroff set $port2
        sleep 1
        ssdk_sh port poweron set $port2
    }
}
