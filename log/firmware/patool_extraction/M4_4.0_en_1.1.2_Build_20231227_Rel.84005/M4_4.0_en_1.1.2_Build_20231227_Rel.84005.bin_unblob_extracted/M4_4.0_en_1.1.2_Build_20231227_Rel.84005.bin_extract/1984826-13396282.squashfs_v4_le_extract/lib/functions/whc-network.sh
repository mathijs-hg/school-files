#!/bin/sh /etc/rc.common
# Copyright (c) 2015 Qualcomm Atheros, Inc.
#
# All Rights Reserved.
# Qualcomm Atheros Confidential and Proprietary.

whc_network_restart() {
    # This already grabs a lock when reconfiguring the Wi-Fi interfaces.
    # If WHC ever grows to configure more than just Wi-Fi, then we may
    # need to grab an additional lock.
    if [ -n "$1" -a "$1" = "${1/reload}" ]; then
        echo "whc update:$1" >/dev/console
        logger -p $LEVEL "whc (repacd) update: cmd: /sbin/wifi update $1"
        /sbin/wifi update "$@"
    else
        echo "wifi reload" >/dev/console
        logger -p $LEVEL "whc (repacd) : wifi reload, cmd:/sbin/wifi"
		local isMobile=$(isMobile 2>/dev/null)
		if [ "$isMobile" = "yes" ]; then
	        if [ -n "$1" -a "$1" = "reload" ] && ( [ -n "$1" -a "$2" = "wifi0" ] || [ -n "$1" -a "$2" = "wifi1" ] ); then
    	        /sbin/wifi reload "$2"
    	    else
        	    /sbin/wifi
        	fi
		else
			/sbin/wifi
		fi
    fi
}

# Determine  if the device provided is for 5 GHz or not
# Currently this relies on the hwmode config parameter and is meant for
# a radio tied to a specific band.
#
# The wireless configuration needs to have been loaded prior to this function
# being invoked.
#
# input: $1 device - name of the device
# return: 0 if the device operates on 5 GHz; otherwise 1
whc_is_5g_radio() {
	if [ -f /sbin/ethswctl ]; then
		local band
		config_get band $1 band '2g'

		case "$band" in
		    5g)
		        return 0
		    ;;

		    2g)
		        return 1
		    ;;
		esac
	else
		local hwmode
		config_get hwmode $1 hwmode '11ng'

		case "$hwmode" in
		    11ac|11na|11a|11axa)
		        return 0
		    ;;

		    *)
		        return 1
		    ;;
		esac
	fi
}

# Determine if the VAP provided (identified by its section name) operates
# on 5 GHz or not.
#
# See the caveat about this being intended for platforms where each radio is
# dedicated to a band as mentioned in the __repacd_is_5g_radio documentation
# above.
#
# The wireless configuration needs to have been loaded prior to this function
# being invoked.
#
# input: $1 vap - name of the wifi-iface section
# return: 0 if the VAP operates on 5 GHz; otherwise 1
whc_is_5g_vap() {
    local device
    config_get device $1 device

    whc_is_5g_radio $device
    return $?
}
