#!/bin/sh /etc/rc.common
# Copyright (c) 2020 Shenzhen TP-LINK Technologies Co.Ltd.
# Author		Song Tianhao<songtianhao@tp-link.com.cn>
# Run this shell to get the current WAN port speed and compare it with the max speed
# that was stored in the configuration.
# After that, store the result in /etc/profie.d/interfaces

uci_p="uci -c /etc/profile.d/"

#exit 0 :确定不需要速率诊断
#exit 1 :确定需要速率诊断
#exit 2 :获取速率失败，无法判断速率是否达到最大
#exit 3 :程序内变量出现异常（不太可能出现）

#获取wan口与最大速度
eth0_name=$($uci_p get interfaces.@interface[0].name 2>/dev/null)
eth1_name=$($uci_p get interfaces.@interface[1].name 2>/dev/null)
eth0_is_wan=$(isWan $eth0_name)
eth1_is_wan=$(isWan $eth1_name)

if [ "$eth0_is_wan" == "true" ]; then
    wan_port=$eth0_name
    max_speed=$($uci_p get interfaces.@interface[0].max_speed 2>/dev/null)
    port_phy_num=$($uci_p get interfaces.@interface[0].port 2>/dev/null)
elif [ "$eth1_is_wan" == "true" ]; then
    wan_port=$eth1_name
    max_speed=$($uci_p get interfaces.@interface[1].max_speed 2>/dev/null)
    port_phy_num=$($uci_p get interfaces.@interface[1].port 2>/dev/null)
else
    echo "no wan port!">>/dev/console
    echo -n "0"
fi

[ -z "$max_speed" ] && max_speed=1000
echo "max speed is $max_speed , wan_port is $wan_port">>/dev/console

#通过不同工具，获取wan口速度与最大速度字符串
if [ -f /usr/sbin/ssdk_sh ]; then
    port_speed=$(ssdk_sh port speed get ${port_phy_num} | grep speed | cut -d ":" -f 2)
    MAX_SPEED="${max_speed}(Mbps)"    

elif [ -f /sbin/ethctl ]; then
    port_speed=$(ethctl ${wan_port} media-type | grep Speed: | cut -d ":" -f 2 | cut -d "," -f 1)
    if [ "$max_speed" == "1000" ]; then
        MAX_SPEED=" 1G"
    else
        MAX_SPEED=" ${max_speed}M"
    fi
elif [ -f /usr/bin/switch ]; then
    # MTK机型支持
    port_speed=$(switch phy_link_status | grep "port ${port_phy_num}" | cut -d " " -f 5 | tr -cd "[0-9]")
    MAX_SPEED="${max_speed}"

else
    echo "tools do not exist!">>/dev/console
    echo -n "2"
fi

#对比
echo ${port_speed},and ${MAX_SPEED} >>/dev/console
if [ "${port_speed}" != "${MAX_SPEED}" ]; then
    echo "wan speed is ${port_speed}">>/dev/console
    echo -n "1"
else
    echo "no need to speed diagnose">>/dev/console
    echo -n "0"
fi
