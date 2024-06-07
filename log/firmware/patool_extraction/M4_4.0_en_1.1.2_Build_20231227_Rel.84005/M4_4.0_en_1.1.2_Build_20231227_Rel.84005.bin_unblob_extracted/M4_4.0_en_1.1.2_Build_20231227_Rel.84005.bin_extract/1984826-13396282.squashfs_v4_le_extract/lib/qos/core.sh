# Copyright (C) 2009-2010 OpenWrt.org

PC_LIBDIR=${PC_LIBDIR:-/lib/qos}
sfe_compat_ver=$(uci -c /etc/profile.d get profile.@qos[0].sfe_compat_ver)
if [ "$sfe_compat_ver" = "2" ]; then
    QOS_PROC_PATH="/tmp/qos_enable"
else
    QOS_PROC_PATH="/proc/sfe_ipv4/qos_enable"
fi

include /lib/network

. /usr/lib/eth-encap/eth_encap.sh

# check firewall
fw_is_loaded() {
    local bool=$(uci_get_state firewall.core.loaded)
    return $((! ${bool:-0}))
}


fw_init() {
    [ -z "$PC_INITIALIZED" ] || return 0

    . $PC_LIBDIR/config.sh

    # export the qos config
    fw_config_append qos_v2
	fw_config_append client_mgmt

    for file in $PC_LIBDIR/core_*.sh; do
        . $file
    done
    
    PC_INITIALIZED=1
    return 0
}

fw_start() {
    # make sure firewall is loaded
    fw_is_loaded || {
        echo "firewall is not loaded" > /dev/console
        exit 1
    }
    
    # check the hook and chains

    # init
    fw_init

    # ready to load rules from uci config
    echo "loading qos" > /dev/console
    fw_load_qos
	
    syslog $LOG_INF_SERVICE_START
}

fw_stop() {

    # make sure firewall is loaded
    fw_is_loaded || {
        echo "firewall is not loaded" >&2
        exit 1
    }
    # check the hook and chains

    # init
    fw_init

    fw_hnat_start
    nss_support=$(get_qos_nss_enable)
    if [ -n "$nss_support" ] && [ "$nss_support" == "yes" ]; then
        /etc/init.d/qca-nss-ecm stop
    fi
    fw_exit_qos
    echo '0' > $QOS_PROC_PATH
    if [ -n "$nss_support" ] && [ "$nss_support" == "yes" ]; then
        /etc/init.d/qca-nss-ecm start
    fi
    syslog $LOG_INF_SERVICE_STOP
    echo "--------->exiting qos">/dev/console
}

fw_stop_without_hwnat() {

    # make sure firewall is loaded
    fw_is_loaded || {
        echo "firewall is not loaded" >&2
        exit 1
    }
    # check the hook and chains

    # init
    fw_init

    fw_hnat_start
    fw_exit_qos
    echo '0' > $QOS_PROC_PATH
    syslog $LOG_INF_SERVICE_STOP
    echo "--------->exiting qos">/dev/console
}

fw_restart() {

    local qos_status_file="/tmp/qos_running_status"
    if [ -f $qos_status_file ];then
        while [ 1 ]; do
            if [ ! -f $qos_status_file ];then
                echo $$>$qos_status_file
                break
            fi
            sleep 1
        done
    else
        echo $$>$qos_status_file
    fi
	
    [ "$(cat $qos_status_file)" == "$$" ] || exit

    nss_support=$(get_qos_nss_enable)
    if [ -n "$nss_support" ] && [ "$nss_support" == "yes" ]; then
        /etc/init.d/qca-nss-ecm stop
        fw_stop_without_hwnat
        #fw_start
        /etc/init.d/qos start
        /etc/init.d/qca-nss-ecm start
    else
        fw_stop
        fw_start
    fi
    rm -f $qos_status_file
}

fw_reload() {
    # make sure firewall is loaded
    fw_is_loaded || {
        echo "firewall is not loaded" >&2
        exit 1
    }
    # reload
    fw_init

    fw_config_once fw_rule_reload global
}

fw_check() {
	fw_is_loaded || {
        echo "firewall is not loaded" >&2
        exit 1
    }
	
	# init
    fw_init
	
	fw_check_clients
}
