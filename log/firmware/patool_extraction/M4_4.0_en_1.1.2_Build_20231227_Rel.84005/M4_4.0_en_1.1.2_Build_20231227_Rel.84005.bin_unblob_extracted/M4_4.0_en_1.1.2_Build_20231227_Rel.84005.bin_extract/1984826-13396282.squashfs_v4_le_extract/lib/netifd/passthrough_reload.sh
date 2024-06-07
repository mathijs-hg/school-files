#!/bin/sh

INCLUDE_ONLY=1

. /lib/netifd/proto/passthrough.sh
. /lib/functions.sh

reload_passthrough() {


    local rewrite_name=

    sleep 3

    config_load network
    config_get vlan_enable vlan enable "0"
    config_get vlan_id vlan id "0"
    config_clear

    echo "vlan_enable:$vlan_enable vlan_id:$vlan_id  !!!!!!!!!!!" > /dev/console

    if [ "$vlan_enable" == "1" ]; then
        
        for ck_idx in $(seq 1 1 5); do
            if_exists=$(ifconfig -a | grep br-wan."$vlan_id")
            if [ -n "$if_exists" ]; then
                rewrite_name="br-wan.$vlan_id"
                break
            else
                sleep 1
            fi
        done

    else
        echo "set br-wan" > /dev/console
        rewrite_name="br-wan"
    fi

    if [ -n "$rewrite_name" ]; then
        for ck_idx in $(seq 1 1 5); do
            if [ -f "/proc/passthrough/wan_eth_name" ]; then
                param=$(cat /proc/passthrough/wan_eth_name)
                if [ "$param" != "$rewrite_name" ]; then
                    echo "$rewrite_name" > /proc/passthrough/wan_eth_name
                    break
                fi
            else
                sleep 1
            fi
        done
    fi

}

reload_passthrough
