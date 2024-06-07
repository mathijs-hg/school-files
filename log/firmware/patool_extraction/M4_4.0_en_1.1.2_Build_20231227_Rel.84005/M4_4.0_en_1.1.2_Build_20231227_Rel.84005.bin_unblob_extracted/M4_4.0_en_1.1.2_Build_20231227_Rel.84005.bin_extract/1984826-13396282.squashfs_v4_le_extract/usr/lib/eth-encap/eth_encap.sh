#!/bin/sh

. /lib/functions.sh
switch_mtk=$(lsmod|grep -o "raeth")

get_cpu_port_id()
{

    local cpu_port=

    cpu_port=$(uci get profile.switch.cpu_port -c /etc/profile.d)
    [ -z "$cpu_port" ] && {
        cpu_port=0
    }

    echo $cpu_port

}

get_eth_port_num()
{

    local eth_num=

    eth_num=$(uci -c /etc/profile.d/ get profile.@DEVINFO[0].eth_port_num)
    [ -z "$eth_num" ] && { eth_num=2; }

    echo $eth_num

}

get_switch_vlan_enable()
{

    local vlan_support=$(uci get profile.switch.switch_vlan -c /etc/profile.d)

    echo $vlan_support
}

get_switch_sgmac_type()
{
    local sgmac_type=$(uci get profile.switch.sgmac -c /etc/profile.d)

    echo $sgmac_type
}

get_qos_nss_enable()
{
    local nss_support=$(uci get profile.@qos[0].nss_support -c /etc/profile.d)

    echo $nss_support
}

get_port_positive_seq()
{

    local left_up_port_num=
    local phy_port_first=
    local positive_seq=

    left_up_port_num=$(uci -c /etc/profile.d/ get profile.interface.left_up_port 2>/dev/null)
    phy_port_first=$(uci get profile.switch.phy_port_1 -c /etc/profile.d 2>/dev/null)
    if [ $left_up_port_num -eq $phy_port_first ];then
        positive_seq=1
    else
        positive_seq=0
    fi

    echo $positive_seq
}

get_all_eth_port()
{

    eth_num=$(get_eth_port_num)

    all_eth_port=""
    for i in $(seq 1 1 $eth_num)
    do
        eth_port=$(uci get profile.switch.phy_port_$i -c /etc/profile.d)
        append all_eth_port "$eth_port"
    done

    echo $all_eth_port

}

get_eth_port_by_seq()
{
    local port_seq=$1
    local eth_port=

    eth_port=$(uci get profile.switch.phy_port_$port_seq -c /etc/profile.d)

    echo $eth_port
}

get_all_vlan_ids()
{
    
    local eth_num=$(get_eth_port_num)
    local all_vlan_ids=""

    for i in $(seq 1 1 $eth_num)
    do
        vlan_id=$(uci get profile.switch.vlan_id_$i -c /etc/profile.d)
        append all_vlan_ids "$vlan_id"
    done

    echo $all_vlan_ids

}

get_all_eth_port_with_tag()
{

    eth_num=$(get_eth_port_num)

    all_eth_port=""
    for i in $(seq 1 1 $eth_num)
    do
        eth_port=$(uci get profile.switch.phy_port_$i -c /etc/profile.d)
        append all_eth_port "${eth_port}t"
    done

    echo $all_eth_port

}

get_sgmac_eth_name()
{
    local eth_id=-1
    local eth_type=
    local if_name=
    local real_dev_name=

    while true
    do
        eth_id=$(($eth_id + 1))
        eth_type=$(uci -c /etc/profile.d get interfaces.@interface[$eth_id].type)

        if [ -z "$eth_type" ]; then
            break
        elif [ "$eth_type" == "eth" ]; then
            if_name=$(uci -c /etc/profile.d get interfaces.@interface[$eth_id].name 2>/dev/null)
            real_dev_name=$(echo "$if_name" | cut -f 1 -d '.')
            break
        else
            continue
        fi
    done

    echo $real_dev_name

}

get_all_eth_names()
{

    local eth_id=-1
    local eth_type=
    local if_name=
    local all_eth_ifname=

    while true
    do
        eth_id=$(($eth_id + 1))
        eth_type=$(uci -c /etc/profile.d get interfaces.@interface[$eth_id].type)

        if [ -z "$eth_type" ]; then
            break
        elif [ "$eth_type" == "eth" ]; then
            if_name=$(uci -c /etc/profile.d get interfaces.@interface[$eth_id].name 2>/dev/null)
            append all_eth_ifname "$if_name"
        else
            continue
        fi
    done

    echo $all_eth_ifname
	
}

get_sgmac_eth_vids()
{
    local all_ifnames=$(get_all_eth_names)
    local all_vids=

    for eth_name in $all_ifnames
    do
        eth_vid="${eth_name#*.}"
        append all_vids "$eth_vid"
    done

    echo $all_vids

}

get_port_by_eth()
{
    local port=
    local eth_id=-1
    local eth_type=
    local eth_param="$1"

    while true
    do
        eth_id=$(($eth_id + 1))
        eth_type=$(uci -c /etc/profile.d get interfaces.@interface[$eth_id].type)

        if [ -z "$eth_type" ]; then
            break
        elif [ "$eth_type" == "eth" ]; then
            if_name=$(uci -c /etc/profile.d get interfaces.@interface[$eth_id].name 2>/dev/null)
            if [ "$if_name" == "$eth_param" ]; then
                port=$(uci -c /etc/profile.d get interfaces.@interface[$eth_id].port 2>/dev/null)
                break
            fi
        else
            continue
        fi
    done

    echo $port

}

get_eth_by_port()
{

    local if_name=
    local port=
    local eth_id=-1
    local eth_type=
    local port_param="$1"

    while true
    do
        eth_id=$(($eth_id + 1))
        eth_type=$(uci -c /etc/profile.d get interfaces.@interface[$eth_id].type)

        if [ -z "$eth_type" ]; then
            break
        elif [ "$eth_type" == "eth" ]; then
            port=$(uci -c /etc/profile.d/ get interfaces.@interface[$eth_id].port 2>/dev/null)
            if [ "$port" == "$port_param" ]; then
                if_name=$(uci -c /etc/profile.d get interfaces.@interface[$eth_id].name 2>/dev/null)
                break
            fi
        else
            continue
        fi
    done

    echo $if_name

}

get_eth_by_seq()
{

    port=$(uci get profile.switch.phy_port_$1 -c /etc/profile.d)
    eth_name=$(get_eth_by_port $port)
    echo $eth_name

}

down_lan_eth_ports() 
{

    local if_port=
    local all_eth_ifname=

    all_eth_ifname=$(get_all_eth_names)

    for if_name in $all_eth_ifname; do
        if [ "$(brctl show br-lan  2>&1 | grep -E "$if_name")" == "$if_name" ]; then
            if_port=$(get_port_by_eth $if_name)
            echo "we get $if_name port:$if_port and down" > /dev/console
            ssdk_sh port poweroff set $if_port
        fi
    done

}

up_lan_eth_ports() 
{

    local if_port=
    local all_eth_ifname=

    all_eth_ifname=$(get_all_eth_names)

    for if_name in $all_eth_ifname; do
        if [ "$(brctl show br-lan  2>&1 | grep -E "$if_name")" == "$if_name" ]; then
            if_port=$(get_port_by_eth $if_name)
            echo "we get $if_name port:$if_port and up" > /dev/console
            ssdk_sh port poweron set $if_port
        fi
    done

}

replug_lan_eth_ports() 
{

    local if_port=
    local all_eth_ifname=

    all_eth_ifname=$(get_all_eth_names)

    for if_name in $all_eth_ifname; do
        if [ "$(brctl show br-lan  2>&1 | grep -E "$if_name")" == "$if_name" ]; then
            if_port=$(get_port_by_eth $if_name)
            echo "we get $if_name port:$if_port and replug" > /dev/console
            ssdk_sh port poweroff set $if_port
            sleep 1
            ssdk_sh port poweron set $if_port
        fi
    done

}

replug_port_by_eth()
{

    local vlan_port
    local vlan_id
    local eth_vid
    
    vlan_id=${1#*.}
    
    local vlan_match="0"
    local eth_vids=$(get_sgmac_eth_vids)
    
    for eth_vid in $eth_vids
    do
        if [ "$vlan_id" == "$eth_vid" ]; then
            vlan_match="1"
            break
        fi
    done
    
    if [ "$vlan_match" == "0" ]; then
        exit 0
    fi
    
    local vid=-1
    while true
    do
        vid=$(($vid + 1))
        vid_tmp=$(uci -c /etc/vlan.d get vlan.@switch_vlan[$vid].vid)
        if [ -z "$vid_tmp" ]; then
            break
        elif [ "$vid_tmp" == "$vlan_id" ]; then
            vlan_port=$(uci -c /etc/vlan.d get vlan.@switch_vlan[$vid].ports | awk '{print $2}')
        else
            continue
        fi
    done
    
    local switch_rtl8367s
    switch_rtl8367s=$(lsmod|grep -o "rtl8367s_gsw")

    if [ -n "$switch_rtl8367s" ]; then
        vlan_phy="$vlan_port"
        echo "$vlan_phy 0" >/proc/rtk_gsw/phylink
        sleep 1
        echo "$vlan_phy 1" >/proc/rtk_gsw/phylink
    elif [ -n "$switch_mtk" ]; then
        switch phy_power $vlan_port off
        sleep 1
        switch phy_power $vlan_port on
    fi

}

down_all_rtl_ports()
{

    local all_ports=$(get_all_eth_port)

    for port in $all_ports
    do
        echo "$port 0" >/proc/rtk_gsw/phylink
    done

}

down_all_qca_ports()
{
    local all_ports=$(get_all_eth_port)

    for port in $all_ports
    do
        ssdk_sh port poweroff set $port
    done
}

up_all_qca_ports()
{
    local all_ports=$(get_all_eth_port)

    for port in $all_ports
    do
        ssdk_sh port poweron set $port
    done
}


disable_all_qca_ports_Ieee8023az()
{
    local all_ports=$(get_all_eth_port)

    for port in $all_ports
    do
        ssdk_sh port Ieee8023az set $port disable
    done
}

set_qca_flowctrl()
{
    local all_ports=$(get_all_eth_port)

    for port in $all_ports
    do
        ssdk_sh port flowCtrlforcemode set $port enable 2>&1 1>/dev/null
	    ssdk_sh port txfcstatus set $port disable 2>&1 1>/dev/null
        ssdk_sh port rxfcstatus set $port enable 2>&1 1>/dev/null
    done
}

get_product_plc_support()
{
    local plc_support=
    plc_support=$(uci -c /etc/profile.d get profile.switch.plc_support)

    echo $plc_support
}

vlan_add()
{
    local ifname="$1"
    local tag="$2"

    if [ -f /sbin/vlanctl ]; then
        vlanctl --if-suffix . --if-create "$ifname" "$tag"  --mcast --if "$ifname" --set-if-mode-rg
        vlanctl --if "$ifname" --rx --tags 1 --filter-vid "$tag" 0 --pop-tag --set-rxif "$ifname"."$tag" --rule-append
        vlanctl --if "$ifname" --tx --tags 0 --filter-txif "$ifname"."$tag" --push-tag --set-vid "$tag" 0 --rule-append
    else
        vconfig add "$ifname" "$tag"
    fi
}

vlan_del()
{
    local ifname="$1"
    local tag="$2"

    if [ -f /sbin/vlanctl ]; then
        vlanctl --if $ifname --tx --tags 0 --filter-txif "$ifname"."$tag" --rule-remove-by-filter
        vlanctl --if $ifname --rx --tags 1 --filter-vid "$tag" 0 --rule-remove-by-filter
        vlanctl --if-delete "$ifname"."$tag"
    else
        vconfig rem "$ifname"."$tag"
    fi
}

vlan_set_prio()
{
    local ifname="$1"
    local tag="$2"
    local prio="$3"

    if [ -f /sbin/vlanctl ]; then
        for i in $(seq 0 1 7); do
            vlanctl --if $ifname --tx --tags 0 --filter-txif $ifname.$tag --rule-remove-by-filter
        done
        vlanctl --if $ifname --tx --tags 0 --filter-txif $ifname.$tag --push-tag --set-vid $tag 0 --set-pbits $prio 0 --rule-append
    else
        for i in $(seq 0 1 7); do
            vconfig set_egress_map "$ifname.$tag" "$i" "$prio"
        done
    fi
}
