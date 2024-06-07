# Copyright (C) 2014-2015 TP-link
. /lib/config/uci.sh
. /usr/lib/eth-encap/eth_encap.sh

local isMobile=$(isMobile 2>/dev/null)

QOS_LAN_MARK_LOW=1
QOS_LAN_MARK_HIGH=2
QOS_WAN_MARK_LOW=3
QOS_WAN_MARK_HIGH=4
QOS_MARK_MASK=0xf

HWQOS_LAN_QUEUE_LOW=1
HWQOS_LAN_QUEUE_HIGH=2
HWQOS_WAN_QUEUE_LOW=3
HWQOS_WAN_QUEUE_HIGH=4

qdma_d(){
    echo "qdma $@" > /dev/console
    qdma $@
}

tc_d(){
    echo "tc $@" > /dev/console
    tc $@
}

crontab_cmd="\* \* \* \* \* \/sbin\/qos_check"
sfe_compat_ver=$(uci -c /etc/profile.d get profile.@qos[0].sfe_compat_ver)
if [ "$sfe_compat_ver" = "2" ]; then
    QOS_PROC_PATH="/tmp/qos_enable"
else
    QOS_PROC_PATH="/proc/sfe_ipv4/qos_enable"
fi
uci_p="uci -c /etc/profile.d/"

fw_config_get_global(){

    local rUpband
    local rDownband

    rUpband="$(uci -c /etc/profile.d get profile.@qos[0].rUpband 2>&1)"
    rDownband="$(uci -c /etc/profile.d get profile.@qos[0].rDownband 2>&1)"

    if [ "$(echo $rUpband | grep [^0-9])" ]; then
        rUpband="984400"
    fi

    if [ "$(echo $rDownband | grep [^0-9])" ]; then
        rDownband="984400"
    fi
 

    fw_config_get_section "$1" global { \
        string enable           "off" \
        string up_band          "" \
        string down_band        "" \
        string high             "90" \
        string low              "10" \
        string percent          "100" \
        string up_unit          "mbps" \
        string down_unit        "mbps" \
        string rUpband          "$rUpband" \
        string rDownband        "$rDownband" \
        string qos_switch       "on" \
    } || return       


}

fw_config_get_client(){
    fw_config_get_section "$1" client { \
        string mac              "" \
        string prio             "off" \
        string prio_time        "" \
        string time_period      "" \
    } || return
}

fw_load_qos(){
    if [[ x"$(uci_get_state qos_v2 core)" != x"qos_v2" ]]; then
        uci_set_state qos_v2 core "" qos_v2
    fi
    
    fw_config_once fw_load_global global 
}

# start hnat
fw_hnat_start()
{
	
    wanDetect=`cat /tmp/wanDetection 2>/dev/null`
    if [ "$wanDetect" == "0" ]; then
        if [ -f "/usr/sbin/qca-hnat" ]; then
            /usr/sbin/qca-hnat start
            sh /usr/lib/wanDetect/cp_dir.sh /tmp/qca_switch/ /proc/qca_switch/
            sleep 2
        elif [ -f "/etc/init.d/hnat-start" ]; then
            /etc/init.d/hnat-start start
        fi
    fi

    if [ "$isMobile" = "yes" ]; then
        #enable ecm-nss L3 accelerator
        [ -e "/sys/kernel/debug/ecm/" ] && {
            echo 1 > /sys/kernel/debug/ecm/ecm_nss_ipv4/register_L3_hook
            echo 1 > /sys/kernel/debug/ecm/ecm_nss_ipv6/register_L3_hook
        }
        [ -f "/sys/sfe_cm/flushall" ] && {
            echo 1 > /sys/sfe_cm/flushall
        }
    fi
}

# stop hnat and clear qca header
fw_hnat_stop()
{

    local plc_support=$($uci_p get profile.switch.plc_support 2>/dev/null)
                        
    if [ -f "/usr/sbin/qca-hnat" ]; then
        /usr/sbin/qca-hnat stop
        if [ -n "$plc_support" ] && [ "yes" == "$plc_support" ]; then
            echo "plc support here" > /dev/console
        else
            ssdk_sh debug reg set 0x620 0x4f0 4
            ssdk_sh debug reg set 0x9c 0x0 4
        fi
    elif [ -f "/etc/init.d/hnat-start" ]; then
        /etc/init.d/hnat-start stop
    fi

    if [ "$isMobile" = "yes" ]; then
        #disable ecm-nss L3 accelerator
        [ -e "/sys/kernel/debug/ecm/" ] && {
            echo 0 > /sys/kernel/debug/ecm/ecm_nss_ipv4/register_L3_hook
            echo 0 > /sys/kernel/debug/ecm/ecm_nss_ipv6/register_L3_hook
            echo 1 > /sys/kernel/debug/ecm/ecm_db/defunct_all
        }
    fi
}

fw_acceleration_engin()
{

    local engin=$1
    [ -f "/etc/init.d/qca-nss-ecm" ] && {
        uci set ecm.global.acceleration_engine=$engin
        uci commit ecm
        /etc/init.d/qca-nss-ecm restart &
    }

}

fw_ecm_reload()
{
    /etc/init.d/qca-nss-ecm restart &
}

fw_ecm_stop()
{
    /etc/init.d/qca-nss-ecm stop
}

fw_ecm_start()
{
    /etc/init.d/qca-nss-ecm start
}

fw_rule_exit(){

    fw flush 4 m zone_lan_qos
    fw flush 4 m zone_wan_qos

    fw flush 4 m qos_lan_rule

    fw flush 4 m qos_lan_HIGH
    fw flush 4 m qos_lan_LOW

    fw flush 4 m qos_wan_HIGH
    fw flush 4 m qos_wan_LOW

    fw del 4 m qos_lan_rule

    fw del 4 m qos_lan_HIGH
    fw del 4 m qos_lan_LOW

    fw del 4 m qos_wan_HIGH
    fw del 4 m qos_wan_LOW
}

fw_rule_load() {

    
    fw add 4 m qos_lan_HIGH
    fw add 4 m qos_lan_LOW
    fw add 4 m qos_lan_rule

    fw add 4 m qos_wan_HIGH
    fw add 4 m qos_wan_LOW

    local lan_target="MARK --set-xmark ${QOS_LAN_MARK_HIGH}/${QOS_MARK_MASK}"
    local conn_target="CONNMARK --set-xmark ${QOS_LAN_MARK_HIGH}/${QOS_MARK_MASK}"
    local wan_target="MARK --set-xmark ${QOS_WAN_MARK_HIGH}/${QOS_MARK_MASK}"
    local w_conn_target="CONNMARK --set-xmark ${QOS_WAN_MARK_HIGH}/${QOS_MARK_MASK}"

    fw s_add 4 m qos_lan_HIGH "$lan_target"
    fw s_add 4 m qos_lan_HIGH "$conn_target"
    fw s_add 4 m qos_lan_HIGH ACCEPT
    fw s_add 4 m qos_wan_HIGH "$wan_target"
    if [ "$isMobile" = "yes" ]; then
        fw s_add 4 m qos_wan_HIGH "$w_conn_target"
    fi
    fw s_add 4 m qos_wan_HIGH ACCEPT

    lan_target="MARK --set-xmark ${QOS_LAN_MARK_LOW}/${QOS_MARK_MASK}"
    conn_target="CONNMARK --set-xmark ${QOS_LAN_MARK_LOW}/${QOS_MARK_MASK}"
    wan_target="MARK --set-xmark ${QOS_WAN_MARK_LOW}/${QOS_MARK_MASK}"
    w_conn_target="CONNMARK --set-xmark ${QOS_WAN_MARK_LOW}/${QOS_MARK_MASK}"

    fw s_add 4 m qos_lan_LOW "$lan_target"
    fw s_add 4 m qos_lan_LOW "$conn_target"
    fw s_add 4 m qos_lan_LOW ACCEPT
    fw s_add 4 m qos_wan_LOW "$wan_target"
    if [ "$isMobile" = "yes" ]; then
        fw s_add 4 m qos_wan_LOW "$w_conn_target"
    fi
    fw s_add 4 m qos_wan_LOW ACCEPT

    # wan rules, low is default
    fw s_add 4 m zone_wan_qos qos_wan_HIGH { "-m connmark --mark ${QOS_LAN_MARK_HIGH}/${QOS_MARK_MASK}" }
    fw s_add 4 m zone_wan_qos qos_wan_LOW { "-m connmark --mark ${QOS_LAN_MARK_LOW}/${QOS_MARK_MASK}" }

    # lan rules, to avoid second match
    fw s_add 4 m zone_lan_qos qos_lan_HIGH { "-m connmark --mark ${QOS_LAN_MARK_HIGH}/${QOS_MARK_MASK}" }
    fw s_add 4 m zone_lan_qos qos_lan_LOW { "-m connmark --mark ${QOS_LAN_MARK_LOW}/${QOS_MARK_MASK}" }
    fw s_add 4 m zone_lan_qos qos_lan_rule

    # default qos
    fw s_add 4 m zone_lan_qos qos_lan_LOW
    fw s_add 4 m zone_wan_qos qos_wan_LOW
}

fw_exit_qos(){
    if [[ x"$(uci_get_state qos_v2 core)" != x"qos_v2" ]]; then
        uci_set_state qos_v2 core "" qos_v2
    fi
    sed -i "/^${crontab_cmd}/d" /etc/crontabs/root 

    if [[ x"$(uci_get_state qos_v2 core loaded)" == x1 ]]; then
        nss_support=$(get_qos_nss_enable)
        if [ -z "$nss_support" ] || [ "$nss_support" == "no" ]; then
            fw_rule_exit
        fi
        if [ "$(uci -c /etc/profile.d get profile.@qos[0].hw_qos)" = "enable" ]; then
            fw_qdma_stop
        fi
        fw_tc_stop

        # for brcm qos support
        grep qos_kctl /proc/modules && rmmod qos_kctl

        uci_revert_state qos_v2 core loaded
		uci_revert_state qos_v2 core check_time
        uci_set_state qos_v2 core loaded 0

        # for brcm rest wlx affinity
        if [[ -f /etc/init.d/bcm_cpu_affinity ]]; then
            /etc/init.d/bcm_cpu_affinity start
        fi

    fi
}

fw_load_global() {

    fw_config_get_global "$1"

    if [[ x"$(uci_get_state qos_v2 core loaded)" != x1 ]]; then
        if [[ "$global_enable" == "on" -a "$global_qos_switch" == "on" ]]; then
            syslog $LOG_INF_FUNCTION_ENABLE

            if [[ -n "$global_up_band" -a -n "$global_down_band" ]]; then
                nss_support=$(get_qos_nss_enable)
                if [ -z "$nss_support" ] || [ "$nss_support" == "no" ]; then
                    fw_rule_load
                fi
                uci_revert_state qos_v2 core check_time
                config_foreach fw_load_client client
                
                local macs=$(uci_get_state qos_v2 core check_time)
                if [ -n "$macs" ]; then
    
                    sed -i "/^${crontab_cmd}/d" /etc/crontabs/root 
                    echo "* * * * * /sbin/qos_check" >> /etc/crontabs/root 
                    /etc/init.d/cron restart &
                    
                    macs=$(echo ${macs}|tr ":" "-")
                    echo "1 ${macs}" > $QOS_PROC_PATH
                    fw_tc_start
                    if [ "$(uci -c /etc/profile.d get profile.@qos[0].hw_qos)" = "enable" ]; then
                        fw_qdma_start
                    else
                        fw_hnat_stop
                    fi
                fi
            fi
            # fw_rule_load

            uci_revert_state qos_v2 core loaded
            uci_set_state qos_v2 core loaded 1

            # for brcm qos support
            linux_ver=$(grep -o "Linux version [0-9A-Za-z_.-]*" /proc/version | grep -o "[0-9A-Za-z_.-]*$")
            if [[ -f /lib/modules/$linux_ver/qos_kctl.ko ]]; then
                insmod /lib/modules/$linux_ver/qos_kctl.ko
            fi

            # for brcm rest wlx affinity
            if [[ -f /etc/init.d/bcm_cpu_affinity ]]; then
                /etc/init.d/bcm_cpu_affinity start
            fi

        else
            syslog $LOG_INF_FUNCTION_DISABLE
            uci_revert_state qos_v2 core loaded
			uci_revert_state qos_v2 core check_time
            uci_set_state qos_v2 core loaded 0

            # for brcm qos support
            grep qos_kctl /proc/modules && rmmod qos_kctl

            # for brcm rest wlx affinity
            if [[ -f /etc/init.d/bcm_cpu_affinity ]]; then
                /etc/init.d/bcm_cpu_affinity start
            fi

        fi
    fi    
}

fw_tc_lan_setup()
{
    lan_ifname=$1
    # downlink

    nss_support=$(get_qos_nss_enable)
    if [ -n "$nss_support" ] && [ "$nss_support" == "yes" ]; then
        tc_d qdisc add dev $lan_ifname root handle 2: nsshtb r2q 200 accel_mode 0
        tc_d class add dev $lan_ifname parent 2: classid 2:2 nsshtb rate "$downlink" crate "$downlink" burst 1281600 cburst 1281600 quantum 1518
        
        tc_d class add dev $lan_ifname parent 2:2 classid 2:2101 nsshtb rate "$down_high" crate "$downlink" burst 641600 cburst 1281600 quantum 1518 priority 0
        tc_d qdisc add dev $lan_ifname parent 2:2101 handle 2101: nsspfifo limit 1000
        
        tc_d class add dev $lan_ifname parent 2:2 classid 2:2103 nsshtb rate "$down_low" crate "$downlink" burst 641600 cburst 1281600 quantum 1518 priority 2
        tc_d qdisc add dev $lan_ifname parent 2:2103 handle 2103: nsspfifo limit 1000
        
        tc_d class add dev $lan_ifname parent 2:2 classid 2:2100 nsshtb rate 1000Mbit crate 1000Mbit burst 1281600 cburst 1281600 quantum 1518 priority 3
        tc_d qdisc add dev $lan_ifname parent 2:2100 handle 2100: nsspfifo limit 1000 set_default

    else
        tc_d qdisc add dev $lan_ifname root handle 2: htb default 2100
        tc_d class add dev $lan_ifname parent 2: classid 2:2 htb rate "$downlink" ceil "$downlink" $down_burst quantum 1500
        tc_d class add dev $lan_ifname parent 2: classid 2:2100 htb rate 1000000kbit ceil 1000000kbit $down_iface_burst quantum 1500 prio 3
        tc_d qdisc add dev $lan_ifname parent 2:2100 handle 2100: sfq perturb 10
    
        tc_d class add dev $lan_ifname parent 2:2 classid 2:2101 htb rate "$down_high" ceil "$downlink" $d_hi_burst quantum 1500 prio 0
        tc_d qdisc add dev $lan_ifname parent 2:2101 handle 2101: sfq perturb 10
    
        tc_d class add dev $lan_ifname parent 2:2 classid 2:2103 htb rate "$down_low" ceil "$downlink" $d_lo_burst quantum 1500 prio 2
        tc_d qdisc add dev $lan_ifname parent 2:2103 handle 2103: sfq perturb 10
    
        # filter
        tc_d filter add dev $lan_ifname parent 2:0 protocol all handle "$QOS_WAN_MARK_HIGH"/${QOS_MARK_MASK} fw classid 2:2101
        tc_d filter add dev $lan_ifname parent 2:0 protocol all handle "$QOS_WAN_MARK_LOW"/${QOS_MARK_MASK} fw classid 2:2103
    fi
}

fw_tc_wan_setup()
{
    nss_support=$(get_qos_nss_enable)
    if [ -n "$nss_support" ] && [ "$nss_support" == "yes" ]; then
        if [ "$isMobile" = "yes" ]; then
            wan_ifname=$1
        else
            wan_ifname="br-wan"
        fi
        tc_d qdisc add dev $wan_ifname root handle 1: nsshtb r2q 200 accel_mode 0
        tc_d class add dev $wan_ifname parent 1: classid 1:1 nsshtb rate "$uplink" crate "$uplink" burst 1281600 cburst 1281600 quantum 1518
        
        tc_d class add dev $wan_ifname parent 1:1 classid 1:1101 nsshtb rate "$up_high" crate "$uplink" burst 641600 cburst 1281600 quantum 1518 priority 0
        tc_d qdisc add dev $wan_ifname parent 1:1101 handle 1101: nsspfifo limit 1000
        
        tc_d class add dev $wan_ifname parent 1:1 classid 1:1103 nsshtb rate "$up_low" crate "$uplink" burst 641600 cburst 1281600 quantum 1518 priority 2
        tc_d qdisc add dev $wan_ifname parent 1:1103 handle 1103: nsspfifo limit 1000
        
        tc_d class add dev $wan_ifname parent 1:1 classid 1:1100 nsshtb rate 1000Mbit crate 1000Mbit burst 1281600 cburst 1281600 quantum 1518 priority 3
        tc_d qdisc add dev $wan_ifname parent 1:1100 handle 1100: nsspfifo limit 1000 set_default

    else
        wan_ifname=$1
        # uplink
        tc_d qdisc add dev $wan_ifname root handle 1: htb default 1100
        tc_d class add dev $wan_ifname parent 1: classid 1:1 htb rate "$uplink" ceil "$uplink" $up_burst quantum 1500
        tc_d class add dev $wan_ifname parent 1: classid 1:1100 htb rate 1000000kbit ceil 1000000kbit $up_iface_burst quantum 1500 prio 3
        tc_d qdisc add dev $wan_ifname parent 1:1100 handle 1100: sfq perturb 10
    
        tc_d class add dev $wan_ifname parent 1:1 classid 1:1101 htb rate "$up_high" ceil "$uplink" $u_hi_burst quantum 1500 prio 0
        tc_d qdisc add dev $wan_ifname parent 1:1101 handle 1101: sfq perturb 10
    
        tc_d class add dev $wan_ifname parent 1:1 classid 1:1103 htb rate "$up_low" ceil "$uplink" $u_lo_burst quantum 1500 prio 2
        tc_d qdisc add dev $wan_ifname parent 1:1103 handle 1103: sfq perturb 10
    
        # filter
    tc_d filter add dev $wan_ifname parent 1:0 protocol all handle "$QOS_LAN_MARK_HIGH"/${QOS_MARK_MASK} fw classid 1:1101
    tc_d filter add dev $wan_ifname parent 1:0 protocol all handle "$QOS_LAN_MARK_LOW"/${QOS_MARK_MASK} fw classid 1:1103
    fi
}

is_mobile_wan_inface()
{
    local is_wan=0
    local accessmode=$(cat /tmp/access_mode)
    local backup_stat=$(cat /tmp/backup_state)
    # echo "--> accessmode=$accessmode   backup_stat=$backup_stat" > /dev/console
    if [ "$accessmode" == "mobile" ] || ( [ "$accessmode" == "ewan" ] && [ "$backup_stat" == "2" ] ) ; then
        is_wan=1
    fi
    echo "--> is_mobile_wan=$is_mobile_wan" > /dev/console 
    echo "$is_wan"
}

fw_tc_start() {

    if [ "$isMobile" = "yes" ]; then
        local is_mobile_wan=$(is_mobile_wan_inface)
    fi

    # modules

    local all_percent=$((${global_high}+${global_low}))
    global_high=$((${global_high}*100/${all_percent}))
    global_low=$((${global_low}*100/${all_percent}))

    #get port speed
    if [ "$isMobile" = "yes" ]; then
    local portWan_speed=$(get_ewanport_speed)
    [ $is_mobile_wan -eq 1 ] && {
        local upband=$(uci get profile.mobile_rate.upband -c /etc/profile.d/)
        local downband=$(uci get profile.mobile_rate.downband -c /etc/profile.d/)
        [ -n "$upband" ] && global_rUpband="$upband"
        [ -n "$downband" ] && global_rDownband="$downband"
    } || {
        #get port speed
        local portWan_speed=$(get_ewanport_speed)
        if [ "$portWan_speed" == "100" ]
        then
            global_rUpband="92000"
            global_rDownband="92000"
        fi    
    }
    echo "--> global_rUpband=$global_rUpband global_rDownband=$global_rDownband" > /dev/console
    else
    local portWan_speed=$(get_port_speed "wan")
    echo "get wan speed:$portWan_speed" > /dev/console
    fi
    if [ "$portWan_speed" == "100" ]; then
        global_rUpband="92000"
        global_rDownband="92000"
    elif [ "$portWan_speed" == "2500" ]; then
        global_rUpband="2500000"
        global_rDownband="2500000"
    elif [ "$portWan_speed" == "10000" ]; then
        global_rUpband="9998000"
        global_rDownband="9998000"
    fi

    if [ "$isMobile" = "yes" ]; then
        echo "global_rUpband is $global_rUpband"
        echo "portspeed is $portWan_speed"
    fi
    # paras
    if test "$global_up_band" -ge "$global_rUpband" 
    then
        global_up_band=$((global_rUpband))
    fi
    if [[ "$global_up_unit" == "mbps" ]]; then
        global_up_band=$((global_up_band*1000))
    fi
    local uplink=$((${global_percent}*${global_up_band}/100))
    
    if test "$global_down_band" -ge "$global_rDownband" 
    then
        global_down_band=$((global_rDownband))
    fi
    if [[ "$global_down_unit" == "mbps" ]]; then
        global_down_band=$((global_down_band*1000))
    fi
    local downlink=$((${global_percent}*${global_down_band}/100))
    

    local up_high=$((${global_high}*${uplink}/100))
    local up_low=$((${global_low}*${uplink}/100))

    local down_high=$((${global_high}*${downlink}/100))
    local down_low=$((${global_low}*${downlink}/100))

    # Calculate the burst and cburst parameters for HTB 
    # Added by Jason Guo<guodongxian@tp-link.net>, 20140729 
    local hz=$(cat /proc/net/psched|awk -F ' ' '{print $4}')
    local up_iface_burst down_iface_burst
    local up_burst u_hi_burst u_lo_burst
    local down_burst d_hi_burst d_lo_burst 
    [ "$hz" == "3b9aca00" ] && {
        burst__calc() {
            local b=$((${1} * 1000 / 8 / 100))
            b=$((${b} + 1600))
            echo "$b"
        }
        # Uplink, unit bit
        up_burst=$(burst__calc $uplink)
        u_hi_burst=$(burst__calc $up_high)
        u_lo_burst=$(burst__calc $up_low)

        # Downlink, unit bit
        down_burst=$(burst__calc $downlink)
        d_hi_burst=$(burst__calc $down_high)
        d_lo_burst=$(burst__calc $down_low)

        nss_support=$(get_qos_nss_enable)
        if [ -n "$nss_support" ] && [ "$nss_support" == "yes" ]; then
            local u_total_burst=$((${u_hi_burst}+${u_lo_burst}))
            u_hi_burst=$((${u_total_burst} / 2))
            u_lo_burst=$u_hi_burst
    
            local d_total_burst=$((${d_hi_burst}+${d_lo_burst}))
            d_hi_burst=$((${d_total_burst} / 2))
            d_lo_burst=$d_hi_burst
        fi
        up_iface_burst=$(burst__calc 1000000)
        down_iface_burst=$(burst__calc 1000000)
        param__convert() {
            local p=
            [ -n "$1" -a -n "$2" ] && {
                p="burst $1 cburst $2"
            }
            echo "$p"        
        }
        
        u_hi_burst=$(param__convert $u_hi_burst $up_burst)
        u_lo_burst=$(param__convert $u_lo_burst $up_burst)
        up_burst=$(param__convert $up_burst $up_burst)

        d_hi_burst=$(param__convert $d_hi_burst $down_burst)
        d_lo_burst=$(param__convert $d_lo_burst $down_burst)
        down_burst=$(param__convert $down_burst $down_burst)

        up_iface_burst=$(param__convert $up_iface_burst $up_iface_burst)
        down_iface_burst=$(param__convert $down_iface_burst $down_iface_burst)
    }
    uplink="$uplink""kbit"
    downlink="$downlink""kbit"

    up_high="$up_high""kbit"
    up_low="$up_low""kbit"

    down_high="$down_high""kbit"
    down_low="$down_low""kbit"
    if [ "$isMobile" = "yes" ]; then
    if [ $is_mobile_wan -eq 1 ] ; then
        local mobie_ifname=$(mobile_cmd ifname)
        [ -n "$mobie_ifname" ] && fw_tc_wan_setup $mobie_ifname
    else
        fw_tc_wan_setup "br-wan"
    fi
    else

    if [ "$(which is fc)" ]; then

        eth_iface=$(brctl show br-wan | grep eth | awk '{print $NF}')
        if [ -n "$eth_iface" ]; then
           fw_tc_wan_setup $eth_iface
        fi

    else

        #local ifaces="mobile wan"
        local ifaces=""
        local wan_ifname=""

        ifaces="internet wan"
        for i in $ifaces; do
            if [ "$i" == "internet" ]; then
                wan_ifname=$(uci get network.$i.wan_type)
                if [ "l2tp" == "$wan_ifname" ]; then
                {
                    wan_ifname="${wan_ifname}-${i}"
                }
                else
                {
                    wan_ifname=""
                }
                fi
            else
                wan_ifname=$(uci get network.$i.ifname)
            fi
            [ -z $wan_ifname ] && {
                continue
            }
            fw_tc_wan_setup $wan_ifname
        done

    fi
    fi

    fw_tc_lan_setup "br-lan"
}

fw_tc_stop(){
    #local ifaces="mobile wan"
	local ifaces=""
    local wan_ifname=""  
    
    ifaces="internet wan"  
    for i in $ifaces; do
        if [ "$i" == "internet" ]; then
            wan_ifname=$(uci get network.$i.wan_type)
            if [ "l2tp" == "$wan_ifname" ]; then
            {
                wan_ifname="${wan_ifname}-${i}"
            }
            else
            {
                wan_ifname=""
            }
            fi
        else
            wan_ifname=$(uci get network.$i.ifname)
        fi
        [ -z $wan_ifname ] && {
            continue
        }
        nss_support=$(get_qos_nss_enable)
        if [ -n "$nss_support" ] && [ "$nss_support" == "yes" ]; then
            tc_d qdisc del dev br-wan root
        else
            tc_d qdisc del dev "$wan_ifname" root
        fi
    done

    tc_d qdisc del dev br-lan root


    if [ "$isMobile" = "yes" ]; then
    local mobie_ifname=$(mobile_cmd ifname)
    [ -n "$mobie_ifname" ] && tc_d qdisc del dev $mobie_ifname root
    else
    tc_d qdisc del dev eth0 root
    tc_d qdisc del dev eth1 root
    tc_d qdisc del dev eth2 root
    fi

}

fw_qdma_start(){
    # config each mark to a queue
    qdma_d m2q $QOS_LAN_MARK_HIGH $HWQOS_LAN_QUEUE_HIGH
    qdma_d m2q $QOS_LAN_MARK_LOW  $HWQOS_LAN_QUEUE_LOW
    qdma_d m2q $QOS_WAN_MARK_HIGH $HWQOS_WAN_QUEUE_HIGH
    qdma_d m2q $QOS_WAN_MARK_LOW  $HWQOS_WAN_QUEUE_LOW

    # config rate for high and low queues
    local all_percent=$((${global_high} + ${global_low}))
    global_high=$((${global_high} * 100 / ${all_percent}))
    global_low=$((${global_low} * 100 / ${all_percent}))

    ## maybe delete
    if test "$global_up_band" -ge "$global_rUpband"
    then
        global_up_band=$((global_rUpband))
    fi
    ##
    if [[ "$global_up_unit" == "mbps" ]]; then
        global_up_band=$((global_up_band * 1000))
    fi
    local uplink_rate=$((${global_up_band} * 1000 / 1024))

    ## maybe delete
    if test "$global_down_band" -ge "$global_rDownband"
    then
        global_down_band=$((global_rDownband))
    fi
    ##
    if [[ "$global_down_unit" == "mbps" ]]; then
        global_down_band=$((global_down_band * 1000))
    fi
    local downlink_rate=$((${global_down_band} * 1000 / 1024))

    local up_high_rate=$((${global_high} * ${uplink_rate} / 100))
    local up_low_rate=$((${global_low}*${uplink_rate}/100))

    local down_high_rate=$((${global_high} * ${downlink_rate} / 100))
    local down_low_rate=$((${global_low} * ${downlink_rate} / 100))

    local weight_high=$((${global_high} / 10))
    local weight_low=$((${global_low} / 10))

    local sch_up=0
    local sch_down=1

    # always config larger band to sch0 to workaround qdma bug
    if [ "$uplink_rate" -lt "$downlink_rate" ]; then
        sch_up=1
        sch_down=0
    fi

    # config queues to sch
    qdma_d sch $HWQOS_LAN_QUEUE_HIGH $sch_up
    qdma_d sch $HWQOS_LAN_QUEUE_LOW  $sch_up
    qdma_d sch $HWQOS_WAN_QUEUE_HIGH $sch_down
    qdma_d sch $HWQOS_WAN_QUEUE_LOW  $sch_down

    qdma_d sch_rate $sch_up 1 $uplink_rate
    qdma_d sch_rate $sch_down 1 $downlink_rate

    local queue_min_rate=1000

    qdma_d rate $HWQOS_LAN_QUEUE_HIGH 1 $queue_min_rate 0 0
    qdma_d rate $HWQOS_LAN_QUEUE_LOW  1 $queue_min_rate 0 0
    qdma_d rate $HWQOS_WAN_QUEUE_HIGH 1 $queue_min_rate 0 0
    qdma_d rate $HWQOS_WAN_QUEUE_LOW  1 $queue_min_rate 0 0

    qdma_d weight $HWQOS_LAN_QUEUE_HIGH $weight_high
    qdma_d weight $HWQOS_WAN_QUEUE_HIGH $weight_high

    qdma_d weight $HWQOS_LAN_QUEUE_LOW $weight_low
    qdma_d weight $HWQOS_WAN_QUEUE_LOW $weight_low

}

fw_qdma_stop(){
    qdma_d m2q $QOS_LAN_MARK_HIGH 0
    qdma_d m2q $QOS_LAN_MARK_LOW  0
    qdma_d m2q $QOS_WAN_MARK_HIGH 0
    qdma_d m2q $QOS_WAN_MARK_LOW  0

    qdma_d sch $HWQOS_LAN_QUEUE_HIGH 0
    qdma_d sch $HWQOS_LAN_QUEUE_LOW  0
    qdma_d sch $HWQOS_WAN_QUEUE_HIGH 0
    qdma_d sch $HWQOS_WAN_QUEUE_LOW  0

    qdma_d sch_rate 0 0 0
    qdma_d sch_rate 1 0 0

    qdma_d rate $HWQOS_LAN_QUEUE_HIGH 0 0 0 0
    qdma_d rate $HWQOS_LAN_QUEUE_LOW  0 0 0 0
    qdma_d rate $HWQOS_WAN_QUEUE_HIGH 0 0 0 0
    qdma_d rate $HWQOS_WAN_QUEUE_LOW  0 0 0 0

}

fw_rule_reload() {
    echo "do nothing">/dev/console
}

fw_load_client() {
    fw_config_get_client "$1"
	#echo "client_mac=$client_mac client_prio=$client_prio" > /dev/console
	
	local client_mac=${client_mac//-/:}
	client_mac=$(echo $client_mac | tr [a-z] [A-Z])
	
	local lan_target
	if [ "$client_prio" == "on" ]; then
		now=`date '+%s'`
		if [ "$client_prio_time" == "-1" -o "$now" -lt "$client_prio_time" ]; then
			nss_support=$(get_qos_nss_enable)
			if [ -z "$nss_support" ] || [ "$nss_support" == "no" ]; then
				fw s_add 4 m qos_lan_rule qos_lan_HIGH { "-m mac --mac-source $client_mac" }
			fi
			macs=$(uci_get_state qos_v2 core check_time)
			append macs ${client_mac}
			uci_toggle_state qos_v2 core check_time "${macs}"
		fi
	fi
}

fw_check_client_is_online() {
    local macs=$1
    local ONLINE_DEV_PATH="/tmp/online_devlist"
    local qos_enable
	local is_online=false

    [ -z "$macs" ]&&{
        return true
    } 
    for mac in $macs
	do
        mac=${mac//:/-}
        res=`cat ${ONLINE_DEV_PATH}|grep -i ${mac}`
        if [ -n "$res" ]; then
            is_online=true
        fi
    done
    
    if [ -f ${QOS_PROC_PATH} ]; then
        qos_enable=$(cat ${QOS_PROC_PATH}|head -1)
    elif [ -f /lib/modules/$linux_ver/qos_kctl.ko ]; then
        local qos_mod=$(lsmod|grep qos_kctl)
        if [ -n "$qos_mod" ]; then
            qos_enable=1
        else
            qos_enable=0
        fi
    fi

    if [ "$qos_enable" == "0" ] && [ "$is_online" == true ]; then
        fw_config_get_global "settings"
        nss_support=$(get_qos_nss_enable)
        if [ -n "$nss_support" ] && [ "$nss_support" == "yes" ]; then
            fw_ecm_stop
            fw_tc_start
            fw_hnat_stop
            fw_ecm_start
        else
            fw_tc_start
            if [ "$(uci -c /etc/profile.d get profile.@qos[0].hw_qos)" = "enable" ]; then
                fw_qdma_start
            else
                fw_hnat_stop
            fi
            fw_acceleration_engin "sfe"
        fi
        if [ -f ${QOS_PROC_PATH} ]; then
            echo "1 ${macs//:/-}">$QOS_PROC_PATH
        elif [ -f /lib/modules/$linux_ver/qos_kctl.ko ]; then
            insmod /lib/modules/$linux_ver/qos_kctl.ko
        fi
    elif [ "$qos_enable" == "1" ] && [ "$is_online" == false ]; then
        nss_support=$(get_qos_nss_enable)
        if [ -n "$nss_support" ] && [ "$nss_support" == "yes" ]; then
            fw_ecm_stop
            fw_tc_stop
            fw_ecm_start
            fw_hnat_start
        else
            fw_tc_stop
            if [ "$(uci -c /etc/profile.d get profile.@qos[0].hw_qos)" = "enable" ]; then
                fw_qdma_stop
            else
                fw_hnat_start
            fi
            fw_acceleration_engin "nss"
        fi
        if [ -f ${QOS_PROC_PATH} ]; then
            echo "0">$QOS_PROC_PATH
        elif [ -f /lib/modules/$linux_ver/qos_kctl.ko ]; then
            rmmod qos_kctl
        fi
    elif [ "$qos_enable" == "0" ] && [ "$is_online" == false ]; then
        return 0
    fi
    return 1
}

fw_check_clients() {
	local old_macs=$(uci_get_state qos_v2 core check_time)
	local new_macs

	local now=`date '+%s'`
    local is_online=$(fw_check_client_is_online "$old_macs")
    [ "$is_online" == "0" ] && return
	for mac in $old_macs
	do
		key=${mac//:/}
		fw_config_get_client $key
		
		#echo $key "$client_mac" "$now" "$client_prio_time" > /dev/console
		if [ "$client_prio_time" == "-1" ];then
            append new_macs $mac 
        else
            if [ "$now" -gt "$client_prio_time" ]; then
                nss_support=$(get_qos_nss_enable)
                if [ -z "$nss_support" ] || [ "$nss_support" == "no" ]; then
                    fw s_del 4 m qos_lan_rule qos_lan_HIGH { "-m mac --mac-source $mac" }
                fi
                echo "dev:${mac} high prio timeout">/dev/console
            else
                append new_macs $mac 
            fi
        fi
	done
	
	if [ "${new_macs}" != "${old_macs}" ];then
		
        uci_toggle_state qos_v2 core check_time "${new_macs}"
        
        # write proc file
        new_macs=$(echo ${new_macs}|tr ":" "-")
        [ -n "${new_macs}" ] && echo "1 ${new_macs}">$QOS_PROC_PATH

	fi
	
	if [ -z "${new_macs}" ];then
		uci_revert_state qos_v2 core check_time
		sed -i "/^${crontab_cmd}/d" /etc/crontabs/root 
		/etc/init.d/cron restart &
        uci set qos_v2.settings.enable="off"
        uci commit qos_v2
        /etc/init.d/qos restart    
    fi
}

get_cpu_rgmii_type()
{
    local sgmac_type=$(get_switch_sgmac_type)
    if [ -n "$sgmac_type" ] && [ "$sgmac_type" == "yes" ]; then
        echo "single"
    else
        echo "double"
    fi

    return
}

get_single_rgmii_port_speed()
{

    local port_name="$1"
    local portWan_vid=`brctl show br-wan|tail -1|awk '{print $4}'|cut -d "." -f2`
    local port_speed="1000"
    local portWan_id=""

    local vid=-1
    while true
    do
        vid=$((vid + 1))
        vid_tmp=$(uci -c /etc/vlan.d get vlan.@switch_vlan[$vid].vid)
        if [ -z "$vid_tmp" ]; then
            break
        elif [ "$vid_tmp" == "$portWan_vid" ]; then
            portWan_id=$(uci -c /etc/vlan.d get vlan.@switch_vlan[$vid].ports | awk '{print $2}' | tr -d 't')
        else
            continue
        fi

        if [ -n "$portWan_id" ]; then
            break
        fi
    done

    echo "====portWan=${portWan_id} wan_vid=${portWan_vid}">>/dev/console

    if [ -n "$portWan_id" ]
    then
        if [ "$port_name" == "wan" ]
        then
            port_speed=$(swconfig dev switch1 show | grep "link: port:$portWan_id" | cut -d ':' -f 5 | cut -d 'b' -f 1)
        fi            
    fi
    echo "${port_speed%%(*}"
}


get_port_speed_legacy_port()
{
    local port_name="$1"
    local interface_name1=$($uci_p get interfaces.@interface[0].name 2>/dev/null)
    local interface_name2=$($uci_p get interfaces.@interface[1].name 2>/dev/null)
    local interface_name3=$($uci_p get interfaces.@interface[2].name 2>/dev/null)
    local port_phy1=$($uci_p get interfaces.@interface[0].phy_port_1 2>/dev/null)
    local port_phy2=$($uci_p get interfaces.@interface[1].phy_port_2 2>/dev/null)
    local port_switch1=""
    local port_switch2=""
    local port_speed="1000"


    if [ -f "/usr/sbin/ssdk_sh" ]; then

        if [ -z "$port_phy1" ] || [ -z "$port_phy2" ]
        then
            echo $port_speed
            return
        fi
        
        let port_switch1=1+$port_phy1
        let port_switch2=1+$port_phy2
    
        port1_speed=$(ssdk_sh port speed get ${port_switch1}|grep speed|cut -d ":" -f 2)
        port2_speed=$(ssdk_sh port speed get ${port_switch2}|grep speed|cut -d ":" -f 2)

    elif [ -f "/sbin/ethctl" ]; then
        port1_speed=$(ethctl $interface_name1 media-type | grep "at Speed" | awk '{print $6}' | cut -d "," -f 1)
        port2_speed=$(ethctl $interface_name2 media-type | grep "at Speed" | awk '{print $6}' | cut -d "," -f 1)
        port3_speed=$(ethctl $interface_name3 media-type | grep "at Speed" | awk '{print $6}' | cut -d "," -f 1)

        if [ "$port1_speed" == "2.5G" ]; then
            port1_speed="2500(Mbps)"
        elif [ "$port1_speed" == "1G" ]; then
            port1_speed="1000(Mbps)"
        elif [ "$port1_speed" == "100M" ]; then
            port1_speed="100(Mbps)"
        elif [ "$port1_speed" == "10M" ]; then
            port1_speed="10(Mbps)"
        fi

        if [ "$port2_speed" == "2.5G" ]; then
            port2_speed="2500(Mbps)"
        elif [ "$port2_speed" == "1G" ]; then
            port2_speed="1000(Mbps)"
        elif [ "$port2_speed" == "100M" ]; then
            port2_speed="100(Mbps)"
        elif [ "$port2_speed" == "10M" ]; then
            port2_speed="10(Mbps)"
        fi

        if [ "$port3_speed" == "2.5G" ]; then
            port3_speed="2500(Mbps)"
        elif [ "$port3_speed" == "1G" ]; then
            port3_speed="1000(Mbps)"
        elif [ "$port3_speed" == "100M" ]; then
            port3_speed="100(Mbps)"
        elif [ "$port3_speed" == "10M" ]; then
            port3_speed="10(Mbps)"
        fi
    fi

    echo "=====port 1 speed=${port1_speed}===port 2 speed=${port2_speed}===port 3 speed=${port3_speed}">>/dev/console
    local portWan=$(brctl show br-wan|tail -1|awk '{print $4}')

    if [ "$portWan" == "$interface_name1" ] && [ "$port_name" == "wan" ]
    then
        port_speed=$port1_speed
    elif [ "$portWan" == "$interface_name1" ]&& [ "$port_name" == "lan" ]
    then
        port_speed=$port2_speed
    elif [ "$portWan" == "$interface_name2" ]&& [ "$port_name" == "wan" ]
    then
        port_speed=$port2_speed
    elif [ "$portWan" == "$interface_name2" ]&& [ "$port_name" == "lan" ]
    then
        port_speed=$port1_speed
    elif [ "$portWan" == "$interface_name3" ]&& [ "$port_name" == "wan" ]
    then
        port_speed=$port3_speed
    fi
    echo "${port_speed%%(*}"
}

get_port_speed_multi_port()
{

    local port_name="$1"
    local port_speed="100"
    local all_eths=$(get_all_eth_names)

    local portWan=`brctl show br-wan|tail -1|awk '{print $4}'`

    for if_name in $all_eths
    do 
        if [ "$portWan" == "$if_name" ]; then
            port_speed=$(ethtool ${if_name}|grep Speed|cut -d ":" -f 2)
            break
        fi
    done

    echo "${port_speed%%(*}"

}

get_double_rgmii_port_speed()
{

    local speed

    eth_num=$(get_eth_port_num)

    if [ $eth_num == 2 ]; then

        speed=$(get_port_speed_legacy_port "$1")

    else

        speed=$(get_port_speed_multi_port "$1")

    fi

    echo "${speed}" | tr -cd "[0-9]"

}

get_port_speed()
{
    local RGMII_TYPE=$(get_cpu_rgmii_type)
    local ret="1000"

    case "$RGMII_TYPE" in
    "single")
        ret=$(get_single_rgmii_port_speed "$1")
    ;;
    "double")
        ret=$(get_double_rgmii_port_speed "$1")
    ;;
    esac
    echo "$ret"
}

get_ewanport_speed()
{
    local speed
    local portWan=$(brctl show br-wan|tail -1|awk '{print $4}')
    [ -n "$portWan" ] && speed=$(cat /sys/class/net/$portWan/speed)
    [ -n "$speed" ] && echo "$speed"
}
