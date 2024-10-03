#!/bin/sh

AUTO_APMODE_CONFIG_KEY="/mnt/flash/config/auto_apmode_config_key"

default_wifi()
{
	mac=`rtkmib mac|tr '[a-z]' '[A-Z]'`
	modelname=`/usr/sbin/userconfig -read System ModelName`
	ssid=$modelname"-"`echo $mac|cut -d: -f 5``echo $mac|cut -d: -f 6`
	userconfig -write WIRELESS_AP SSID $ssid

	if [ -f  $AUTO_APMODE_CONFIG_KEY ]; then
		psk=`dlinkpsk`
		if [ ! -z "$psk" ]; then
			userconfig -write WIRELESS_AP PreSharedKey $psk
		fi
	fi
}

default_wifi

