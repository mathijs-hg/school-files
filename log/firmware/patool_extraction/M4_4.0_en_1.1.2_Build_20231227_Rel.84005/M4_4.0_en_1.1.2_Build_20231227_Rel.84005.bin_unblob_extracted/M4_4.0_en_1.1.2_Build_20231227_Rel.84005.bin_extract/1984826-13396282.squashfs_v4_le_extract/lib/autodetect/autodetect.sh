#!/bin/sh
# Copyright(c) 2008-2014 Shenzhen TP-LINK Technologies Co.Ltd.
#
# Details : The real auto detection script.
# Author  : Ye Qianchuan <yeqianchuan@tp-link.net>
# Version : 1.0
# Date    : 25 Mar, 2014
# History : 
#   The script will not do dhcp detection at Router Mode.
#   If wan connetction type isn't Dynamic IP, the dhcp detection will consume an IP of front-end network. 
#   The netifd will do dhcp detection when wan connection is Dynamic IP
#   By humin, 24Sep2017

. /lib/functions/network.sh

# Get wan interface.
network_get_physdev IFC wan
network_get_physdev IFC_LAN lan

DNS1_V6_FILE=/tmp/dns1
DNS2_V6_FILE=/tmp/dns2
DEFAULT_DNS_FILE=/tmp/resolv.conf.auto
DEFAULT_DNS_FILE_BACK=/tmp/resolv.conf.auto.back

DNS_FILE=/tmp/autodetect-dns
DHCP_SCRIPT="/lib/autodetect/dhcp.script"
DHCP_PIDFILE="/var/run/udhcpc-${IFC}:${DHCP_ALIAS}.pid"
SYS_MODE_DB=/tmp/sys_mode
DHCP6CDIR="/lib/autodetect"
DHCP6C_CONF="/tmp/dhcp6c_autodet.conf"
DHCP6C_SCRIPT="$DHCP6CDIR/dhcp6c_autodet.script"
DHCP6C_PIDFILE="/tmp/dhcp6c.pid"
AUTODETECT_LOCK_FILE="/tmp/ad.lock"

DHCP_IFC=${IFC}:${DHCP_ALIAS}
PPPOE_IFC=${IFC}:${PPPOE_ALIAS}

flag=0
wanv6_connectable=0
wanv6_up=0
mode=$1
internet_ok=1
dhcp_ok=1
pppoe_ok=1

dslite_version=`uci get component-router-owner.list.dslite -c /etc/profile.d/`
v6plus_version=`uci get component-router-owner.list.v6_plus -c /etc/profile.d/`

[ -f "$AUTODETECT_LOCK_FILE" ] && exit

echo $$ > "$AUTODETECT_LOCK_FILE"

[ $dslite_version -gt 0 ] && {
    dslite_support="yes"
}

[ $v6plus_version -gt 0 ] && {
    v6plus_support="yes"
}

if [ "$dslite_support" == "yes" -o "$v6plus_support" == "yes" ]; then
	config_load /etc/config/network
	config_get wan_proto wan proto

	dad_transmits=`cat /proc/sys/net/ipv6/conf/$IFC/dad_transmits`
	v6_disable=`cat /proc/sys/net/ipv6/conf/$IFC/disable_ipv6`

	ubus list |grep network.interface.wanv6 && {
		local wanv6_status=`ubus call network.interface.wanv6 status`
		json_load "$wanv6_status"
		json_get_var wanv6_connectable connectable
		json_get_var wanv6_up up
	}
fi

record() {
    echo $@ >$RESULT_FILE
}

clean_result() {
    rm -f $DNS_FILE
    [ -f "$DHCP_PIDFILE" ] && kill $(cat "$DHCP_PIDFILE")
	if [ "$dslite_support" == "yes" -o "$v6plus_support" == "yes" ]; then
        rm -f /tmp/dslite_ret*
        rm -f /tmp/v6plus_ret*
		[ -f "$DNS1_V6_FILE" ] &&  rm -f $DNS1_V6_FILE
		[ -f "$DNS2_V6_FILE" ] &&  rm -f $DNS2_V6_FILE
		[ -f "$DHCP6C_PIDFILE" ] && kill $(cat "$DHCP6C_PIDFILE")
		[ -f "$DEFAULT_DNS_FILE_BACK"] && mv DEFAULT_DNS_FILE_BACK DEFAULT_DNS_FILE
		[ $flag -eq 1 ] && ubus call network.interface.wanv6 connect
		echo $dad_transmits > /proc/sys/net/ipv6/conf/$IFC/dad_transmits
		[ `cat /proc/sys/net/ipv6/conf/$IFC/disable_ipv6` -ne "$v6_disable" ] && \
			echo $v6_disable > /proc/sys/net/ipv6/conf/all/disable_ipv6
	fi
    rm -f $AUTODETECT_LOCK_FILE
}

record_clean_and_exit() {
    record $@
    cat $RESULT_FILE > $RESULT_FILE_SAVE
    clean_result
    exit 0
}

sysmode_get_db() {
    local sys_mode="Router"
    if [ -f $SYS_MODE_DB ]; then
        sys_mode="$(cat $SYS_MODE_DB)"
    fi
    echo $sys_mode
}

wan_get_proto() {
    local ifc=wan
    ubus list | grep -q network.interface.internet && ifc=internet

    local proto
    network_get_proto proto $ifc && echo $proto || echo none
}

dhcp6c_create_slaac_conffile() {
	[ -z "$DHCP6CDIR" ] && mkdir -p $DHCP6CDIR
	echo -e "interface $IFC {" > "$DHCP6C_CONF"
	echo -e "\tinformation-only;" >> "$DHCP6C_CONF"
	echo -e "\trequest domain-name-servers;" >> "$DHCP6C_CONF"
	echo -e "\tscript \"$DHCP6C_SCRIPT\";"  >> "$DHCP6C_CONF"
	echo -e "};\n" >> "$DHCP6C_CONF"
	echo -e "id-assoc na 1 {};\n" >> "$DHCP6C_CONF"
}

dhcp6c_create_dhcpv6_conffile() {
	[ -z "$DHCP6CDIR" ] && mkdir -p $DHCP6CDIR
	echo -e "interface $IFC {" > "$DHCP6C_CONF"
	echo -e "\tsend ia-na 1;" >> "$DHCP6C_CONF"
	echo -e "\tsend ia-pd 1;" >> "$DHCP6C_CONF"
	echo -e "\trequest domain-name-servers;" >> "$DHCP6C_CONF"
	echo -e "\tscript \"$DHCP6C_SCRIPT\";"  >> "$DHCP6C_CONF"
	echo -e "};\n" >> "$DHCP6C_CONF"
	echo -e "id-assoc na 1 {};\n" >> "$DHCP6C_CONF"
	echo "id-assoc pd 1 {" >> "$DHCP6C_CONF"
	echo -e "\tprefix-interface $IFC_LAN {" >> "$DHCP6C_CONF"
	echo -e "\t\tsla-id 1;" >> "$DHCP6C_CONF"
	echo -e "\t};" >>  "$DHCP6C_CONF"
	echo "};" >>  "$DHCP6C_CONF"
}

check_both_dslite_v6plus(){
	dns1=$1
	dns2=$2

    local ds_1
    local ds_2
    local ds_3
    local ds_4
    local ip_1
    local ip_2

    config_load /etc/config/network
	config_get AFTR_name wan AFTR_name

    [ -n "$AFTR_name" ] && [ "$AFTR_name" != "$DSLITE_DOMAIN" ] && [ -n "$dns1" ] && {
        [ -n "$dns1" ] && {
            dnslookup -6 -t $DNS_V6_TIMEOUT "$AFTR_name" $dns1 > /tmp/dslite_ret1 &
        }
        [ -n "$dns2" ] && {
		    dnslookup -6 -t $DNS_V6_TIMEOUT "$AFTR_name" $dns2 > /tmp/dslite_ret2 &
        }

        sleep $DNS_V6_TIMEOUT

        ds_1=`cat /tmp/dslite_ret1`
        ds_2=`cat /tmp/dslite_ret2`
        [ -n "$dns1" ] && {
            [ -n "$ds_1" ] && record_clean_and_exit "dslite"
        }
        [ -n "$dns2" ] && {
            [ -n "$ds_2" ] && record_clean_and_exit "dslite"
        }
    }

	[ -n "$dns1" ] && {
		dnslookup -6 -t $DNS_V6_TIMEOUT "$DSLITE_DOMAIN" $dns1 > /tmp/dslite_ret1 &
        dnslookup -6 -t $DNS_V6_TIMEOUT "$DSLITE_DOMAIN2" $dns1 > /tmp/dslite_ret2 &
        dnslookup -6 -t $DNS_V6_TIMEOUT "$DSLITE_DOMAIN3" $dns1 > /tmp/dslite_ret3 &
	}

    [ -n "$dns2" ] && {
		dnslookup -6 -t $DNS_V6_TIMEOUT "$DSLITE_DOMAIN" $dns2 > /tmp/dslite_ret4 &
        dnslookup -6 -t $DNS_V6_TIMEOUT "$DSLITE_DOMAIN2" $dns2 > /tmp/dslite_ret5 &
    #    dnslookup -6 -t $DNS_V6_TIMEOUT "$DSLITE_DOMAIN3" $dns2 > /tmp/dslite_ret6 &
    }

    sleep $DNS_V6_TIMEOUT

    ds_1=`cat /tmp/dslite_ret1`
    ds_2=`cat /tmp/dslite_ret2`
    ds_3=`cat /tmp/dslite_ret4`
    ds_4=`cat /tmp/dslite_ret5`

    check_v6plus $dns1 $dns2
    [ -n "$ds_1" ] || [ -n "$ds_2" ] || [ -n "$ds_3" ] || [ -n "$ds_4" ] &&	record_clean_and_exit "dslite"

    ip_1=`cat /tmp/dslite_ret3`
    [ -n "$ip_1" ] && {
        # TODO: may dns return multiple ip, we use the 1st ip now
        local has_default_route
        local sleep_count
        sleep_count=0
        ip_1=`echo $ip_1|awk '{print $1}'`
        while [ $sleep_count -lt 5 ]
        do
            has_default_route=`route -A inet6 -n | grep "::/0"`
            if [ "$has_default_route" != "" ]; then
                ping6 -w 2 -c 2 "$ip_1" | grep "time=" && record_clean_and_exit "dslite"
                break
            else
                echo "1" > /proc/sys/net/ipv6/conf/$IFC/sendrs  #send RS for RA
            fi
            sleep 1
            sleep_count=$(($sleep_count+1))
        done
    }

    #ip_2=`cat /tmp/dslite_ret6`
    #[ -n "$ip_2" ] && [ "$ip_1" -ne "$ip_2" ] && {
        # TODO: may dns return multiple ip, we use the 1st ip now
    #    ip_2=`echo $ip_2|awk '{print $1}'`
    #    ping6 -c 3 "$ip_2" | grep "time=" && record_clean_and_exit "dslite"
    #}
}

check_v6plus(){
	dns1=$1
	dns2=$2
	urls_status_code=0
	timeout=10

	[ -n "$dns1" ] || [ -n "$dns2" ] && {
		cp DEFAULT_DNS_FILE DEFAULT_DNS_FILE_BACK
		echo nameserver $dns1 > DEFAULT_DNS_FILE
		[ -n "$dns2" ] && echo nameserver $dns2 >> DEFAULT_DNS_FILE

		#check JPNE or BIGLOBE
		V6PLUS_URL_JPNE="https://api.enabler.ne.jp/e4fe129ed441b61b3e72f835cd0cb61a/get_rules?callback=daewfw"
		urls_status_code=`curl -o /dev/null -s -6 -k -m $timeout -w %{http_code} "$V6PLUS_URL_JPNE"`
		[ "$urls_status_code" = "200" ] && record_clean_and_exit "v6_plus"

		#check OCN
		while read line
		do
			[ $IFC != ${line##* } ] && continue
			[ "fe80" = ${line:0:4} ] && continue
			element=${line:0:32}
			prefix=${element:0:4}:${element:4:4}:${element:8:4}:${element:12:4}::
		done </proc/net/if_inet6
		V6PLUS_URL_OCN="https://rule.map.ocn.ad.jp/?ipv6Prefix="$prefix"&ipv6PrefixLength=64&code=e8mMWklYwaGoHmT05ynqVM4kPqF9rAUnhrWCp1vWvBeOO0pfpMokg=="
		urls_status_code=`curl -o /dev/null -s -6 -k -m $timeout -w %{http_code} "$V6PLUS_URL_OCN"`
		[ "$urls_status_code" = "200" ] && record_clean_and_exit "ocn"
	}
}

check_dslite() {
	dns1=$1
	dns2=$2
    local ret1
    local ret2
    local ret3
    local ret4
    local ip_1
    local ip_2


	config_load /etc/config/network
	config_get AFTR_name wan AFTR_name

    ifconfig br-wan
	[ -n "$dns1" ] || [ -n "$dns2" ] && {
		[ -n "$AFTR_name" ] && [ "$AFTR_name" != "$DSLITE_DOMAIN" ] && {
			dnslookup -6 -t $DNS_V6_TIMEOUT "$AFTR_name" $dns1 > /tmp/dslite_ret1 &
			dnslookup -6 -t $DNS_V6_TIMEOUT "$AFTR_name" $dns2 > /tmp/dslite_ret2 &

            sleep $DNS_V6_TIMEOUT
            ret1=`cat /tmp/dslite_ret1`
            ret2=`cat /tmp/dslite_ret2`
			[ -n "$ret1" ] || [ -n "$ret2" ] && record_clean_and_exit "dslite"
		}

		dnslookup -6 -t $DNS_V6_TIMEOUT "$DSLITE_DOMAIN" $dns1 > /tmp/dslite_ret1 &
		dnslookup -6 -t $DNS_V6_TIMEOUT "$DSLITE_DOMAIN" $dns2 > /tmp/dslite_ret2 &
        dnslookup -6 -t $DNS_V6_TIMEOUT "$DSLITE_DOMAIN2" $dns1 > /tmp/dslite_ret3 &
        dnslookup -6 -t $DNS_V6_TIMEOUT "$DSLITE_DOMAIN2" $dns2 > /tmp/dslite_ret4 &
        dnslookup -6 -t $DNS_V6_TIMEOUT "$DSLITE_DOMAIN3" $dns1 > /tmp/dslite_ret5 &
        #dnslookup -6 -t $DNS_V6_TIMEOUT "$DSLITE_DOMAIN3" $dns2 > /tmp/dslite_ret6 &

        sleep $DNS_V6_TIMEOUT

        ret1=`cat /tmp/dslite_ret1`
        ret2=`cat /tmp/dslite_ret2`
        ret3=`cat /tmp/dslite_ret3`
        ret4=`cat /tmp/dslite_ret4`
        ip_1=`cat /tmp/dslite_ret5`
        #ip_2=`cat /tmp/dslite_ret6`

        [ -n "$ret1" ] || [ -n "$ret2" ] || [ -n "$ret3" ] || [ -n "$ret4" ] &&	record_clean_and_exit "dslite"

        [ -n "$ip_1" ] && {
            # TODO: may dns return multiple ip, we use the 1st ip now
            local has_default_route
            local sleep_count
            sleep_count=0
            ip_1=`echo $ip_1|awk '{print $1}'`
            while [ $sleep_count -lt 5 ]
            do
                has_default_route=`route -A inet6 -n | grep "::/0"`
                if [ "$has_default_route" != "" ]; then
                    ping6 -w 2 -c 2 "$ip_1" | grep "time=" && record_clean_and_exit "dslite"
                    break
                else
                    echo "1" > /proc/sys/net/ipv6/conf/$IFC/sendrs  #send RS for RA
                fi
                sleep 1
                sleep_count=$(($sleep_count+1))
            done
        }

        #[ -n "$ip_2" ] && [ "$ip_1" -ne "$ip_2" ] && {
        #    ip_2=`echo $ip_2|awk '{print $1}'`
        #    ping6 -c 3 "$ip_2" | grep "time=" && record_clean_and_exit "dslite"
        #}
	}
}

# Check the dslite & v6plus status
# Get ipv6 addr & dns,and check the specific domain name
get_dns_and_check_doamin() {
	wait_dns=10
	while [ $wait_dns -ne 0 ]; do
		sleep 1

		if [ -e "$DNS1_V6_FILE" ]; then
			wait_dns=0
			DNS1=$(cat $DNS1_V6_FILE)
			DNS2=$(cat $DNS2_V6_FILE)
			[ -n "$DNS1" ] && [ -z "$(cat $DEFAULT_DNS_FILE |grep $DNS1)" ] && \
				echo nameserver $DNS1 >> $DEFAULT_DNS_FILE
			[ -n "$DNS2" ] && [ -z "$(cat $DEFAULT_DNS_FILE |grep $DNS2)" ] && \
				echo nameserver $DNS2 >> $DEFAULT_DNS_FILE

            [ "$dslite_support" == "yes" ] && [ "$v6plus_support" == "yes" ] && check_both_dslite_v6plus $DNS1 $DNS2
		    [ "$dslite_support" == "yes" ] && [ "$v6plus_support" != "yes" ] && check_dslite $DNS1 $DNS2
		    [ "$v6plus_support" == "yes" ] && [ "$dslite_support" != "yes" ] && check_v6plus $DNS1 $DNS2
		else
			let "wait_dns=wait_dns - 1"
            echo "can't read dns" > /dev/console
		fi
	done
}

# Check physical connection.
network_get_link physlink $IFC
[ -z "$physlink" ] && record_clean_and_exit "none"
[ "$physlink" = 0 ] && record_clean_and_exit "unplugged"

# Check the internet status. 
#deleted by wanghao
#online-test "$CHECK_URL" "$DNS_FIRST_TIMEOUT" && \
#    record_clean_and_exit "$(wan_get_proto)"

# Update estimated time
record time $(((EST_TIME-INTERNET_TIMEOUT)*1000))

# Check dslite & v6plus
if [ "$dslite_support" == "yes" -o "$v6plus_support" == "yes" ]; then
	local count=6
	local mbit=1
	local dns1=`grep ^nameserver.*[:] $DEFAULT_DNS_FILE | awk '{print $2}' | sed -n '1p'`
	local dns2=`grep ^nameserver.*[:] $DEFAULT_DNS_FILE | awk '{print $2}' | sed -n '2p'`

	if [ $wanv6_connectable -eq 1 -a $wanv6_up -eq 1 ] && [ -n "$dns1" -o -n "$dns2" ]; then
        [ "$dslite_support" == "yes" ] && [ "$v6plus_support" == "yes" ] && check_both_dslite_v6plus $dns1 $dns2
		[ "$dslite_support" == "yes" ] && [ "$v6plus_support" != "yes" ] && check_dslite $dns1 $dns2
		[ "$v6plus_support" == "yes" ] && [ "$dslite_support" != "yes" ] && check_v6plus $dns1 $dns2
	else
		if [ $wanv6_connectable -eq 1 ]; then
			ubus call network.interface.wanv6 disconnect
			flag=1
			sleep 2
		fi
		echo 0 > /proc/sys/net/ipv6/conf/$IFC/dad_transmits
		if [ $v6_disable -ne 0 ]; then
			echo 0 > /proc/sys/net/ipv6/conf/all/disable_ipv6 #open ipv6 stack
		fi
		echo "-1" > /proc/sys/net/ipv6/conf/$IFC/ndisc_mbit #reset the mbit value to -1
		echo "2"  > /proc/sys/net/ipv6/conf/$IFC/accept_ra
		echo "1" > /proc/sys/net/ipv6/conf/$IFC/sendrs  #send RS for RA

		# Wait for RA
		mbit=`cat /proc/sys/net/ipv6/conf/$IFC/ndisc_mbit`
		while [ $count -ne 0 -a $mbit -eq -1 ]; do
			sleep 1
			mbit=`cat /proc/sys/net/ipv6/conf/$IFC/ndisc_mbit`
			let "count=count - 1"
		done

		if [ $mbit -eq 0 ]; then
			dhcp6c_create_slaac_conffile
			/usr/sbin/dhcp6c -f -p $DHCP6C_PIDFILE -c $DHCP6C_CONF -t wanv6 $IFC &
			get_dns_and_check_doamin
		elif [ $mbit -eq 1 ]; then
			dhcp6c_create_dhcpv6_conffile
			/usr/sbin/dhcp6c -f -p $DHCP6C_PIDFILE -c $DHCP6C_CONF -t wanv6 $IFC &
			get_dns_and_check_doamin
		else
			echo "RA recieve fail" > /dev/console
		fi
	fi
fi

if [[ $mode == "only_v6plus_or_dslite" ]]; then
    record_clean_and_exit "unknown"
fi


# Check DHCP.
#add by wanghao
#if [ "$(wan_get_proto)" != "dhcp" -o "$(sysmode_get_db)" = "AP" ]; then
#For Router mode, if wan protol isn't dhcp, we don't need to do dhcp detection that consume an IP of front-end network
if [ "$(sysmode_get_db)" = "AP" ]; then
host_name=decoMesh$(getfirm MODEL)
#broadcast=""
#if [ "$(sysmode_get_db)" = "AP" ];then
broadcast="-B"
#fi
udhcpc \
    -p "$DHCP_PIDFILE" \
    -s "$DHCP_SCRIPT" \
    -i $DHCP_IFC \
    -t $DHCP_TIMEOUT -T $DHCP_RETRIES \
    -n -R -h "$host_name" "$broadcast" >/dev/null &
# This is the foreground udhcpc pid.
DHCP_PID=$!
else 
    if [ "$(wan_get_proto)" = "dhcp" ]; then
    	#add by wanghao for wanDetection
    	ifconfig br-wan down
    	sleep 1
    	ifconfig br-wan up
    fi
fi

if [ "$(sysmode_get_db)" != "AP" ]; then
# Check PPPOE.
pppoe-discovery \
    -U \
    -I $PPPOE_IFC \
    -t $PPPOE_TIMEOUT -T $PPPOE_RETRIES >/dev/null &
PPPOE_PID=$!
fi

# Check the DHCP status and
# check the internet status with DNS server set.
#add by wanghao
if [ -n "$DHCP_PID" ]; then
    if wait $DHCP_PID; then
        # Update estimated time
        record time $((DNS_TIMEOUT*1000))

        dnslookup -t $DNS_TIMEOUT "$CHECK_URL" $(cat "$DNS_FILE") >/dev/null && \
        record_clean_and_exit "dhcp"
    fi
fi

# Check the PPPOE status.
[ -n "$PPPOE_PID" ] && wait $PPPOE_PID && \
    record_clean_and_exit "pppoe" || record_clean_and_exit "dhcp"
