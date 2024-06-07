#!/bin/sh /etc/rc.common
#
# Copyright (C) 2017 Tp-link.com
# Author: Weng Kaiping <wengkaiping@tp-link.net>
# Date: 30Mar17
#


WLAN_DEVICES=
WLAN_DEVICE_NUM=
ALL_DEVICES=
local maclist=""
BAND2_4_NAME="band2_4"
BAND5_NAME="band5"
local band2_4_list=""
local band5_list=""
local this_dev_list=""
local other_dev_list=""
local other_dev_devId_list=""
local this_dev_id=""


NRD_DEBUG=1
NRD_DEBUG_LEVEL=6

support_6g=$(uci -c /etc/profile.d/ get profile.band_6g.support 2>/dev/null)

dev_2g=$(uci -c /etc/profile.d/ get interfaces.radio_2g.name 2>/dev/null)
dev_5g=$(uci -c /etc/profile.d/ get interfaces.radio_5g.name 2>/dev/null)
dev_5g2=$(uci -c /etc/profile.d/ get interfaces.radio_5g2.name 2>/dev/null)
dev_6g=$(uci -c /etc/profile.d/ get interfaces.radio_6g.name 2>/dev/null)

support_6g=$(uci -c /etc/profile.d/ get profile.band_6g.support 2>/dev/null)
support_5g2=$(uci -c /etc/profile.d/ get profile.band_5g2.support 2>/dev/null)
roaming_support_5g2=$(uci -c /etc/profile.d/ get profile.band_5g2.roaming_support 2>/dev/null)
support_triband=$(uci -c /etc/profile.d get profile.tri_band.support 2>/dev/null)

[ -n "$dev_2g" ] || dev_2g="wifi0"
[ -n "$dev_5g" ] || dev_5g="wifi1"
[ -n "$dev_5g2" ] || dev_5g2="wifi2"
[ -n "$dev_6g" ] || dev_6g="wifi3"

bak_if_2g=
sta_if_2g=
hst_if_2g=
gst_if_2g=
bak_if_5g=
sta_if_5g=
hst_if_5g=
gst_if_5g=
bak_if_5g2=
sta_if_5g2=
hst_if_5g2=
gst_if_5g2=
bak_if_6g=
sta_if_6g=
hst_if_6g=
gst_if_6g=

nrd_echo() {
	if [ "$NRD_DEBUG" -gt 0 ]; then
		logger -p $NRD_DEBUG_LEVEL "nrd: config $1"
	fi
}

# Get interfaces for ai-roaming
__get_ifaces() {
	local config="$1"
	local vapname vapmode nettype device

	config_get vapname "$config" vapname
	config_get vapmode "$config" mode
	config_get nettype "$config" type
	config_get device "$config" device

	#echo "vapname:${vapname} vapmode:${vapmode} nettype:${nettype} device:${device}" > /dev/console

	#2.4G
	if [ -n "$vapname" ] && [ "$device" = "$dev_2g" ]; then
		if [ "$vapmode" = "ap" ] && [ "$nettype" = "backhaul" ]; then
			bak_if_2g="$vapname"
		elif [ "$vapmode" = "ap" ] && [ "$nettype" = "lan" ]; then
			hst_if_2g="$vapname"
		elif [ "$vapmode" = "ap" ] && [ "$nettype" = "guest" ]; then
			gst_if_2g="$vapname"
		elif [ "$vapmode" = "sta" ] && [ "$nettype" = "backhaul" ]; then
			sta_if_2g="$vapname"
		fi
	fi
	#5G
	if [ -n "$vapname" ] && [ "$device" = "$dev_5g" ]; then
		if [ "$vapmode" = "ap" ] && [ "$nettype" = "backhaul" ]; then
			bak_if_5g="$vapname"
		elif [ "$vapmode" = "ap" ] && [ "$nettype" = "lan" ]; then
			hst_if_5g="$vapname"
		elif [ "$vapmode" = "ap" ] && [ "$nettype" = "guest" ]; then
			gst_if_5g="$vapname"
		elif [ "$vapmode" = "sta" ] && [ "$nettype" = "backhaul" ]; then
			sta_if_5g="$vapname"
		fi
	fi
	#5G2
	if [ -n "$vapname" ] && [ "$device" = "$dev_5g2" ]; then
		if [ "$vapmode" = "ap" ] && [ "$nettype" = "backhaul" ]; then
			bak_if_5g2="$vapname"
		elif [ "$vapmode" = "ap" ] && [ "$nettype" = "lan" ]; then
			hst_if_5g2="$vapname"
		elif [ "$vapmode" = "ap" ] && [ "$nettype" = "guest" ]; then
			gst_if_5g2="$vapname"
		elif [ "$vapmode" = "sta" ] && [ "$nettype" = "backhaul" ]; then
			sta_if_5g2="$vapname"
		fi
	fi
	#6G
	if [ -n "$vapname" ] && [ "$device" = "$dev_6g" ]; then
		if [ "$vapmode" = "ap" ] && [ "$nettype" = "backhaul" ]; then
			bak_if_6g="$vapname"
		elif [ "$vapmode" = "ap" ] && [ "$nettype" = "lan" ]; then
			hst_if_6g="$vapname"
		elif [ "$vapmode" = "ap" ] && [ "$nettype" = "guest" ]; then
			gst_if_6g="$vapname"
		elif [ "$vapmode" = "sta" ] && [ "$nettype" = "backhaul" ]; then
			sta_if_6g="$vapname"
		fi
	fi
}

__nrd_get_ar_interfaces() {
	config_load wireless
	config_foreach __get_ifaces wifi-iface
}

__nrd_get_wlan_ifaces() {
	local config="$1"
	local ap_2g="$2"
	local ap_5g="$3"
	local guest_2g="$4"
	local guest_5g="$5"
	local owe_2g="$6"
	local owe_5g="$7"
	local guest_owe_2g="$8"
	local guest_owe_5g="$9"
	local ap_5g2="$10"
	local guest_5g2="$11"
	local ap_6g="$12"
	local guest_6g="$13"
	local ssid_to_match="$14"

	local device iface disabled mode ssid network vap_type
	local dev_2g
	local dev_5g
	local dev_5g2
	local dev_6g
	local ap_6g
	local guest_6g

	dev_2g=$(uci -c /etc/profile.d/ get interfaces.radio_2g.name 2>/dev/null)
	dev_5g=$(uci -c /etc/profile.d/ get interfaces.radio_5g.name 2>/dev/null)
	dev_5g2=$(uci -c /etc/profile.d/ get interfaces.radio_5g2.name 2>/dev/null)
	dev_6g=$(uci -c /etc/profile.d/ get interfaces.radio_6g.name 2>/dev/null)
	if [ -z "${dev_2g}" ] || [ -z "${dev_5g}" ]; then
		dev_2g="wifi0"
		dev_5g="wifi1"
	fi

	if [ -z "$dev_5g2" ]; then
		dev_5g2="wifi2"
	fi

	if [ -z "$dev_6g" ]; then
		dev_6g="wifi3"
	fi

	config_get radio "$config" radio
	config_get vaps "$config" vaps

	for iface in $vaps; do
		local vap_type=`uci get wireless.$iface.type`
		if [ "$radio" = "${dev_2g}" ]; then
			if [ "$vap_type" = "lan" -a "$ap_2g" = "1" ] || [ "$vap_type" = "guest" -a "$guest_2g" = "1" ] || [ "$vap_type" = "owe_host" -a "$owe_2g" = "1" ] || [ "$vap_type" = "owe_guest" -a "$guest_owe_2g" = "1" ]; then
				nrd_echo "nrd 2g enable $iface"
				WLAN_DEVICES="${WLAN_DEVICES}${WLAN_DEVICES:+","}${radio}:${iface}"
			fi
		elif [ "$radio" = "${dev_5g}"  ]; then
			if [ "$vap_type" = "lan" -a "$ap_5g" = "1" ] || [ "$vap_type" = "guest" -a "$guest_5g" = "1" ] || [ "$vap_type" = "owe_host" -a "$owe_5g" = "1" ] || [ "$vap_type" = "owe_guest" -a "$guest_owe_5g" = "1" ]; then
				nrd_echo "nrd 5g enable $iface"
				WLAN_DEVICES="${WLAN_DEVICES}${WLAN_DEVICES:+","}${radio}:${iface}"
			fi
		elif [ "$roaming_support_5g2" = "yes" ] && [ "$radio" = "${dev_5g2}"  ]; then
			if [ "$vap_type" = "lan" -a "$ap_5g2" = "1" ] || [ "$vap_type" = "guest" -a "$guest_5g2" = "1" ]; then
				nrd_echo "nrd 5g2 enable $iface"
				WLAN_DEVICES="${WLAN_DEVICES}${WLAN_DEVICES:+","}${radio}:${iface}"
			fi
		elif [ "$support_6g" = "yes" ] && [ "$radio" = "${dev_6g}" ]; then
			if [ "$vap_type" = "lan" -a "$ap_6g" = "1" ] || [ "$vap_type" = "guest" -a "$guest_6g" = "1" ]; then
				nrd_echo "nrd 6g enable $iface"
				WLAN_DEVICES="${WLAN_DEVICES}${WLAN_DEVICES:+","}${radio}:${iface}"
			fi
		fi
	done
}

# __nrd_get_wlan_interface()
# output: $1 List of all WLAN interfaces matching the SSID provided
# input: $2 The desired SSID. If it is null string, then get all WLAN
#        interfaces; otherwise, get all that matches this SSID
__nrd_get_wlan_interface() {
	WLAN_DEVICES=""
	local ap_2g
	local ap_5g
	local ap_5g2
	local ap_6g
	local guest_enable
	local gst_2g
	local gst_5g
	local gst_5g2
	local gst_6g
	local owe_2g
	local owe_5g
	local owe_5g2
	local guest_owe_2g
	local guest_owe_5g
	local owe_enable guest_owe_enable
	local host_wpa3 guest_wpa3 host_enc guest_enc

	config_load wifi
	config_get ap_2g ap enable_2g 1
	config_get ap_5g ap enable_5g 1

	config_get guest_enable guest enable 0
	config_get gst_2g guest enable_2g $guest_enable
	config_get gst_5g guest enable_5g $guest_enable

	config_get host_wpa3 ap wpa3 0
	config_get host_enc ap encryption 0
	if [ "$host_wpa3" = 1 -a "$host_enc" = 0 ]; then
		owe_enable=1
	else
		owe_enable=0
	fi
	owe_2g=$((owe_enable*ap_2g))
	owe_5g=$((owe_enable*ap_5g))

	config_get guest_wpa3 guest wpa3 0
	config_get guest_enc guest encryption 0
	if [ "$guest_wpa3" = 1 -a "$guest_enc" = 0 ]; then
		guest_owe_enable=1
	else
		guest_owe_enable=0
	fi
	nrd_echo "guest_owe_enable: $guest_owe_enable"
	guest_owe_2g=$((guest_owe_enable*gst_2g))
	guest_owe_5g=$((guest_owe_enable*gst_5g))
	nrd_echo "guest_wpa3: $guest_wpa3, guest_enc: $guest_enc, guest_owe_2g: $guest_owe_2g, guest_owe_5g: $guest_owe_5g"

	config_get ap_5g2 ap enable_5g2 0
	config_get gst_5g2 guest enable_5g2 0
	config_get ap_6g ap enable_6g 0
	config_get gst_6g guest enable_6g 0
	if [ "$support_6g" = "yes" ]; then
		config_get ap_6g ap enable_6g 0
		config_get gst_6g guest enable_6g 0
	fi
	config_clear

	config_load nrd
	config_foreach __nrd_get_wlan_ifaces wlanif "$ap_2g" "$ap_5g" "$gst_2g" "$gst_5g" "$owe_2g" "$owe_5g" "$guest_owe_2g" "$guest_owe_5g" "$ap_5g2" "$gst_5g2" "$ap_6g" "$gst_6g" $2

	eval "$1='${WLAN_DEVICES}'"
}


# Append a config parameter to the file
# input: $1 - parameter string to append (key and value)
# input: $2 - filename to append to
__nrd_cfg_append() {
	echo "$1" >> "$2"
}

# Append a config parameter to the file preceded by a newline
# input: $1 - parameter string to append (key and value)
# input: $2 - filename to append to
__nrd_cfg_nl_append() {
	echo "" >> "$2"
	echo "$1" >> "$2"
}

__nrd_cfg_add_key_val() {
	local key="$1"
	local val="$2"
	local filename="$3"

	__nrd_cfg_append "${key}=${val}" $filename
}

# __nrd_cfg_add_str <section> <option> <filename>
__nrd_cfg_add_str() {
	local key="$2"
	local section="$1"
	local option="$2"
	local filename="$3"

	config_get val "${section}" "${option}"
	[ -n "${val}" ] && __nrd_cfg_append "${key}=${val}" $filename
}

# Add a string to the config file where the key in the UCI config is
# different from the config in the generated config.
# input: $1 - section name in UCI
# input: $2 - parameter name in UCI
# input: $3 - parameter name in the generated configuration
# input: $4 - output filename
__nrd_cfg_add_str_new_key() {
	local section="$1"
	local option="$2"
	local newkey="$3"
	local filename="$4"

	config_get val "${section}" "${option}"
	[ -n "${val}" ] && __nrd_cfg_append "${newkey}=${val}" $filename
}

# Add AP Steering threshold. If band specific parameter is present
# use that, else use generic steering threshold.
# input: $1 - section name in UCI
# input: $2 - band specific steering parameter
# input: $2 - generic steering parameter
# input: $3 - parameter name in the generated configuration
# input: $4 - output filename
__nrd_cfg_add_ap_steering_thresh() {
	local section="$1"
	local band_option="$2"
	local gen_option="$3"
	local newkey="$4"
	local filename="$5"
	local val

	config_get val "${section}" "${band_option}"
	if [ -n "${val}" ]; then
		__nrd_cfg_add_str_new_key "${section}" "${band_option}" "${newkey}" $filename
	else
		__nrd_cfg_add_str_new_key "${section}" "${gen_option}" "${newkey}" $filename
	fi
}

# Given two (section, key) pairs, subtract the second value from the first
# to arrive at an RSSI value and use that for the key being generated.
# This is meant to convert an RSSI on one band to an RSSI on the
# other band, albeit in such a way that is the mirror image of the estimates
# performed by nrd.
# To prevent value underflow/overflow, use 0 for the key if the base value
# is smaller than the adjust value; use 255 if the base value subtracts the
# adjust value is greater than 255
#
# The last parameter is the file to output.
__nrd_cfg_add_rssi_est_str() {
	local basevalsection="$1"
	local basevalkey="$2"
	local adjvalsection="$3"
	local adjvalkey="$4"
	local newkey="$5"
	local filename="$6"

	config_get baseval "${basevalsection}" "${basevalkey}"
	config_get adjval  "${adjvalsection}" "${adjvalkey}"
	if [ -n "${baseval}" ] && [ -n "${adjval}" ]; then
		if [ "${baseval}" -gt "${adjval}" ] && \
		   [ "${baseval}" -lt "$((255 + $adjval))" ]; then
			val="$(($baseval - $adjval))"
		elif [ "${baseval}" -le "${adjval}" ]; then
			val="0"
		elif [ "${baseval}" -ge "$((255 + $adjval))" ]; then
			val="255"
		fi
	fi

	[ -n "${val}" ] && __nrd_cfg_append "${newkey}=${val}" $filename
}



# Add the list of managed interfaces to the configuration file.
# input: $1 - the name of the config file to write to
__nrd_cfg_add_interface() {
	local filename="$1"
	local section="config"
	local option="MatchingSSID"

	config_get ssid "${section}" "${option}"

	local all_wlan_ifaces

	# Get a list of wlan interfaces, seperated by comma
	__nrd_get_wlan_interface all_wlan_ifaces $ssid
	__nrd_cfg_append 'WlanInterfaces='$all_wlan_ifaces $filename
}

# Add the list of blacklist to the configuration file.
# input: $1 - the name of the config file to write to
__nrd_cfg_add_blacklist() {
	local filename="$1"
	local count=0
	local mac
	config_load nrd_blacklist
	config_foreach __nrd_cfg_append_blacklist  client

	for mac in $maclist; do
		__nrd_cfg_append "BlackMac""$count""="$mac $filename
		count=`expr $count + 1`
	done;
	__nrd_cfg_append "BlacklistCount=""$count" $filename

}

__nrd_cfg_append_blacklist() {
	local section="$1"
	local mac
	config_get mac "$section" mac
	mac=${mac//-/:}
	append maclist "$mac "

}


__nrd_cfg_add_link_priority() {
	local filename="$1"
	local this_dev_count=0
	local other_dev_count=0
	local band2_4_count=0
	local band5_count=0
	local mac
	local device_id

	this_dev_id=$(getfirm DEV_ID)
	config_load client_mgmt
	config_foreach __nrd_cfg_append_link_priority client $this_dev_id

	for mac in $this_dev_list; do
		__nrd_cfg_append "linkPriority_thisDevMAC""$this_dev_count""="$mac $filename
		this_dev_count=$((this_dev_count + 1))
	done;
	__nrd_cfg_append "linkPriority_thisDevCount=""$this_dev_count" $filename

	for mac in $other_dev_list; do
		__nrd_cfg_append "linkPriority_otherDevMAC""$other_dev_count""="$mac $filename
		other_dev_count=$((other_dev_count + 1))
	done;

	other_dev_count=0

	for device_id in $other_dev_devId_list; do
		__nrd_cfg_append "linkPriority_otherDevDevId""$other_dev_count""="$device_id $filename
		other_dev_count=$((other_dev_count + 1))
	done;
	__nrd_cfg_append "linkPriority_otherDevCount=""$other_dev_count" $filename

	for mac in $band2_4_list; do
		__nrd_cfg_append "linkPriority_band2_4MAC""$band2_4_count""="$mac $filename
		band2_4_count=$((band2_4_count + 1))
	done;
	__nrd_cfg_append "linkPriority_band2_4Count=""$band2_4_count" $filename

	for mac in $band5_list; do
		__nrd_cfg_append "linkPriority_band5MAC""$band5_count""="$mac $filename
		band5_count=$((band5_count + 1))
	done;
	__nrd_cfg_append "linkPriority_band5Count=""$band5_count" $filename
}

__nrd_cfg_append_link_priority() {
	local section="$1"
	local thisDev_id="$2"
	local mac
	config_get mac    "$section" mac
	config_get band   "$section" link_pri_band
	config_get device_id "$section" link_pri_device_id
	mac=${mac//-/:}

	echo "this dev id is $thisDev_id"> /dev/console
	echo "user set dev id is $device_id"> /dev/console
	echo "over!"> /dev/console

	if [ -n "$device_id" ]; then
		if [ "$device_id" == "$thisDev_id" ]; then
			append this_dev_list "$mac"
		else
			append other_dev_list "$mac"
			append other_dev_devId_list "$device_id"
		fi
	fi

	if [ -n "$band" ]; then
		if [ "$band" == "$BAND2_4_NAME" ]; then
			append band2_4_list "$mac"
		elif [ "$band" == "$BAND5_NAME" ]; then
			append band5_list "$mac"
		else
			echo "link_priority: bad band name:$band"> /dev/console
		fi
	fi

}

nrd_create_config() {
	local filename=$1
	local device_type=$2
	local link_pri_filename=$3

	echo "" > "$filename"
	echo "" > "$link_pri_filename"

	config_load 'nrd'

	__nrd_cfg_nl_append '[STADB]' $link_pri_filename
	__nrd_cfg_add_link_priority $link_pri_filename

	__nrd_cfg_nl_append '[WLANIF]' $filename
	__nrd_cfg_add_interface $filename
	__nrd_cfg_add_str_new_key radio_2g vaps ifname_2g $filename
	__nrd_cfg_add_str_new_key radio_5g vaps ifname_5g $filename

	__nrd_cfg_nl_append '[WLANIF2G]' $filename
	__nrd_cfg_add_str_new_key	IdleSteer	NormalInactTimeout	InactIdleThreshold $filename
	__nrd_cfg_add_str_new_key	IdleSteer	OverloadInactTimeout	InactOverloadThreshold $filename
	__nrd_cfg_add_str	IdleSteer	InactCheckInterval $filename
	__nrd_cfg_add_str   IdleSteer   AuthAllow $filename
	__nrd_cfg_add_rssi_est_str	IdleSteer	RSSISteeringPoint_UG	Estimator_Adv	RSSIDiff_EstW5FromW2	InactRSSIXingHighThreshold $filename
	__nrd_cfg_add_str	SteerExec_Adv	LowRSSIXingThreshold $filename
	__nrd_cfg_add_str	Estimator_Adv	BcnrptActiveDuration $filename
	__nrd_cfg_add_str	Estimator_Adv	BcnrptPassiveDuration $filename
	#__nrd_cfg_add_str_new_key	ActiveSteer	TxRateXingThreshold_UG	HighTxRateXingThreshold $filename
		__nrd_cfg_append 'HighTxRateXingThreshold=6000' $filename
	__nrd_cfg_add_str_new_key	ActiveSteer	RateRSSIXingThreshold_UG	HighRateRSSIXingThreshold $filename
	__nrd_cfg_add_ap_steering_thresh	APSteer	LowRSSIAPSteerThreshold_CAP_W2	LowRSSIAPSteerThreshold_CAP	LowRSSIAPSteeringThreshold	$filename
	__nrd_cfg_add_str	SteerExec_Adv	Delay24GProbeRSSIThreshold $filename
	__nrd_cfg_add_str	SteerExec_Adv	Delay24GProbeTimeWindow $filename
	__nrd_cfg_add_str	SteerExec_Adv	Delay24GProbeMinReqCount $filename

	__nrd_cfg_nl_append '[WLANIF5G]' $filename
	__nrd_cfg_add_str_new_key	IAS	Enable_W5 InterferenceDetectionEnable $filename
	__nrd_cfg_add_str_new_key	IdleSteer	NormalInactTimeout	InactIdleThreshold $filename
	__nrd_cfg_add_str_new_key	IdleSteer	OverloadInactTimeout	InactOverloadThreshold $filename
	__nrd_cfg_add_str	IdleSteer	InactCheckInterval $filename
	__nrd_cfg_add_str   IdleSteer   AuthAllow $filename
	__nrd_cfg_add_str_new_key	IdleSteer	RSSISteeringPoint_UG	InactRSSIXingHighThreshold $filename
	__nrd_cfg_add_rssi_est_str	IdleSteer	RSSISteeringPoint_DG	Estimator_Adv	RSSIDiff_EstW2FromW5	InactRSSIXingLowThreshold $filename
	__nrd_cfg_add_str	SteerExec_Adv	LowRSSIXingThreshold $filename
	__nrd_cfg_add_str	Estimator_Adv	BcnrptActiveDuration $filename
	__nrd_cfg_add_str	Estimator_Adv	BcnrptPassiveDuration $filename
	__nrd_cfg_add_str_new_key	ActiveSteer	TxRateXingThreshold_DG	LowTxRateXingThreshold $filename
	__nrd_cfg_add_str_new_key	ActiveSteer	RateRSSIXingThreshold_DG	LowRateRSSIXingThreshold $filename
	__nrd_cfg_add_ap_steering_thresh	APSteer	LowRSSIAPSteerThreshold_CAP_W5	LowRSSIAPSteerThreshold_CAP	LowRSSIAPSteeringThreshold	$filename

	if [ "$support_6g" = "yes" ]; then
		__nrd_cfg_nl_append '[WLANIF6G]' $filename
		__nrd_cfg_add_str_new_key	IAS	Enable_W6 InterferenceDetectionEnable $filename
		__nrd_cfg_add_str_new_key	IdleSteer	NormalInactTimeout	InactIdleThreshold $filename
		__nrd_cfg_add_str_new_key	IdleSteer	OverloadInactTimeout	InactOverloadThreshold $filename
		__nrd_cfg_add_str	IdleSteer	InactCheckInterval $filename
		__nrd_cfg_add_str   IdleSteer   AuthAllow $filename
		__nrd_cfg_add_str_new_key	IdleSteer	RSSISteeringPoint_UG	InactRSSIXingHighThreshold $filename
		__nrd_cfg_add_rssi_est_str	IdleSteer	RSSISteeringPoint_DG	Estimator_Adv	RSSIDiff_EstW2FromW5	InactRSSIXingLowThreshold $filename
		__nrd_cfg_add_str	SteerExec_Adv	LowRSSIXingThreshold $filename
		__nrd_cfg_add_str	Estimator_Adv	BcnrptActiveDuration $filename
		__nrd_cfg_add_str	Estimator_Adv	BcnrptPassiveDuration $filename
		__nrd_cfg_add_str_new_key	ActiveSteer	TxRateXingThreshold_DG	LowTxRateXingThreshold $filename
		__nrd_cfg_add_str_new_key	ActiveSteer	RateRSSIXingThreshold_DG	LowRateRSSIXingThreshold $filename
		__nrd_cfg_add_ap_steering_thresh	APSteer	LowRSSIAPSteerThreshold_CAP_W5	LowRSSIAPSteerThreshold_CAP	LowRSSIAPSteeringThreshold	$filename
	fi
	if [ "$support_5g2" = "yes" ] && [ "$roaming_support_5g2" = "yes" ]; then
		__nrd_cfg_nl_append '[WLANIF5G2]' $filename
		__nrd_cfg_add_str_new_key	IAS	Enable_W5_2 InterferenceDetectionEnable $filename
		__nrd_cfg_add_str_new_key	IdleSteer	NormalInactTimeout	InactIdleThreshold $filename
		__nrd_cfg_add_str_new_key	IdleSteer	OverloadInactTimeout	InactOverloadThreshold $filename
		__nrd_cfg_add_str	IdleSteer	InactCheckInterval $filename
		__nrd_cfg_add_str   IdleSteer   AuthAllow $filename
		__nrd_cfg_add_str_new_key	IdleSteer	RSSISteeringPoint_UG	InactRSSIXingHighThreshold $filename
		__nrd_cfg_add_rssi_est_str	IdleSteer	RSSISteeringPoint_DG	Estimator_Adv	RSSIDiff_EstW2FromW5	InactRSSIXingLowThreshold $filename
		__nrd_cfg_add_str	SteerExec_Adv	LowRSSIXingThreshold $filename
		__nrd_cfg_add_str	Estimator_Adv	BcnrptActiveDuration $filename
		__nrd_cfg_add_str	Estimator_Adv	BcnrptPassiveDuration $filename
		__nrd_cfg_add_str_new_key	ActiveSteer	TxRateXingThreshold_DG	LowTxRateXingThreshold $filename
		__nrd_cfg_add_str_new_key	ActiveSteer	RateRSSIXingThreshold_DG	LowRateRSSIXingThreshold $filename
		__nrd_cfg_add_ap_steering_thresh	APSteer	LowRSSIAPSteerThreshold_CAP_W5	LowRSSIAPSteerThreshold_CAP	LowRSSIAPSteeringThreshold	$filename
	fi

	__nrd_cfg_nl_append '[NETDB]' $filename
	__nrd_cfg_add_str   NetDB       DiscoverByScan $filename
	__nrd_cfg_add_str   NetDB       ScanFrequency $filename
	__nrd_cfg_add_str   NetDB       MinChannelTime $filename
	__nrd_cfg_add_str   NetDB       MaxChannelTime $filename
	__nrd_cfg_add_str   NetDB       AgeFrequency $filename
	__nrd_cfg_add_str   NetDB       RemoteBSSMaxAge $filename
	__nrd_cfg_add_str	NetDB		ApPollingPeriod $filename
	__nrd_cfg_add_str	NetDB		StaPollingPeriod $filename
	__nrd_cfg_add_str	NetDB		ArApSyncPeriod $filename
	__nrd_cfg_add_str	NetDB		ArPatSyncPeriod $filename

	__nrd_cfg_nl_append '[STADB]' $filename
	__nrd_cfg_add_str	StaDB		IncludeOutOfNetwork $filename
	__nrd_cfg_add_str	StaDB       AgingSizeThreshold $filename
	__nrd_cfg_add_str	StaDB       AgingFrequency $filename
	__nrd_cfg_add_str	StaDB       PollFrequency $filename
	__nrd_cfg_add_str	StaDB       OutOfNetworkMaxAge $filename
	__nrd_cfg_add_str	StaDB       InNetworkMaxAge $filename
	__nrd_cfg_add_str	StaDB       NumRemoteBSSes		$filename
	__nrd_cfg_add_str	StaDB		MarkAdvClientAsDualBand $filename
	__nrd_cfg_add_str	StaDB       PopulateNonServingPHYInfo $filename
	__nrd_cfg_add_str_new_key       config_Adv  AgeLimit    ProbeMaxInterval $filename
	__nrd_cfg_add_str_new_key   IdleSteer   NormalInactTimeout  InactIdleThreshold $filename
	[ -n "$max_sta_num_5g" ] && __nrd_cfg_append "max_sta_num_5g=${max_sta_num_5g}" $filename
	 __nrd_cfg_add_blacklist $filename

	__nrd_cfg_nl_append '[TRIGGERMON]' $filename
	__nrd_cfg_add_str	TriggerMonitor	RSSIMeasureSamples_W2 $filename
	__nrd_cfg_add_str	TriggerMonitor	RSSIMeasureSamples_W5 $filename
	__nrd_cfg_add_str    TriggerMonitor  ThresholdEstimator $filename
	__nrd_cfg_add_str	config_Adv	AgeLimit $filename
	#__nrd_cfg_add_str_new_key	ActiveSteer	TxRateXingThreshold_UG	HighTxRateXingThreshold $filename
		__nrd_cfg_append 'HighTxRateXingThreshold=6000' $filename
	__nrd_cfg_add_str_new_key	ActiveSteer	RateRSSIXingThreshold_UG	HighRateRSSIXingThreshold $filename
	__nrd_cfg_add_str_new_key	ActiveSteer	TxRateXingThreshold_DG	LowTxRateXingThreshold $filename
	__nrd_cfg_add_str_new_key	ActiveSteer	RateRSSIXingThreshold_DG	LowRateRSSIXingThreshold $filename
	__nrd_cfg_add_str	APSteer APSteerToPeerMinRSSIIncThresholdAr  $filename
	__nrd_cfg_add_str   APSteer CliSteerRCPIThreshold $filename
	if [ "$device_type" = 'AP' ]; then
		__nrd_cfg_add_ap_steering_thresh    APSteer LowRSSIAPSteerThresholdIni_CAP_W2  LowRSSIAPSteerThreshold_CAP LowRSSIAPSteeringThreshold_W2   $filename
		__nrd_cfg_add_ap_steering_thresh    APSteer LowRSSIAPSteerThresholdIni_CAP_W5  LowRSSIAPSteerThreshold_CAP LowRSSIAPSteeringThreshold_W5   $filename
		if [ "$support_6g" = "yes" ]; then
			__nrd_cfg_add_ap_steering_thresh    APSteer LowRSSIAPSteerThresholdIni_CAP_W5  LowRSSIAPSteerThreshold_CAP LowRSSIAPSteeringThreshold_W6   $filename
		fi
		if [ "$support_5g2" = "yes" ] && [ "$roaming_support_5g2" = "yes" ]; then
			__nrd_cfg_add_ap_steering_thresh    APSteer LowRSSIAPSteerThresholdIni_CAP_W5  LowRSSIAPSteerThreshold_CAP LowRSSIAPSteeringThreshold_W5_2   $filename
		fi
		__nrd_cfg_append 'RunOnCAP=1' $filename
	else
		__nrd_cfg_add_ap_steering_thresh    APSteer LowRSSIAPSteerThresholdIni_RE_W2   LowRSSIAPSteerThreshold_RE  LowRSSIAPSteeringThreshold_W2   $filename
		__nrd_cfg_add_ap_steering_thresh    APSteer LowRSSIAPSteerThresholdIni_RE_W5   LowRSSIAPSteerThreshold_RE  LowRSSIAPSteeringThreshold_W5   $filename
		if [ "$support_6g" = "yes" ]; then
			__nrd_cfg_add_ap_steering_thresh    APSteer LowRSSIAPSteerThresholdIni_RE_W5  LowRSSIAPSteerThreshold_RE LowRSSIAPSteeringThreshold_W6   $filename
		fi
		if [ "$support_5g2" = "yes" ] && [ "$roaming_support_5g2" = "yes" ]; then
			__nrd_cfg_add_ap_steering_thresh    APSteer LowRSSIAPSteerThresholdIni_RE_W5  LowRSSIAPSteerThreshold_RE LowRSSIAPSteeringThreshold_W5_2   $filename
		fi
		__nrd_cfg_append 'RunOnCAP=0' $filename
	fi
	__nrd_cfg_add_str   TriggerMonitor  LowAPSteerThresholdFloor_W2  $filename
	__nrd_cfg_add_str   TriggerMonitor  LowAPSteerThresholdFloor_W5  $filename
	if [ "$device_type" = 'AP' ]; then
		__nrd_cfg_add_str_new_key APSteer APSteerToPeerMinRSSIIncThresholdAr_CAP APSteerToPeerMinRSSIIncThresholdAr $filename
	else
		__nrd_cfg_add_str_new_key APSteer APSteerToPeerMinRSSIIncThresholdAr_RE APSteerToPeerMinRSSIIncThresholdAr $filename
	fi

	__nrd_cfg_nl_append '[ESTIMATOR]' $filename
	__nrd_cfg_add_str   config_Adv  AgeLimit $filename
	__nrd_cfg_add_str   Estimator_Adv   RSSIDiff_EstW5FromW2 $filename
	__nrd_cfg_add_str   Estimator_Adv   RSSIDiff_EstW2FromW5 $filename
	__nrd_cfg_add_str   Estimator_Adv   ProbeCountThreshold $filename
	__nrd_cfg_add_str   Estimator_Adv   11kProhibitTimeShort $filename
	__nrd_cfg_add_str   Estimator_Adv   11kProhibitTimeLong $filename

	__nrd_cfg_nl_append '[STEEREXEC]' $filename
	__nrd_cfg_add_str	SteerExec_Adv	SteeringProhibitTime $filename
	__nrd_cfg_add_str	SteerExec_Adv	TSteering $filename
	__nrd_cfg_add_str	SteerExec_Adv	InitialAuthRejCoalesceTime $filename
	__nrd_cfg_add_str	SteerExec_Adv	AuthRejMax $filename
	__nrd_cfg_add_str	SteerExec_Adv	SteeringUnfriendlyTime $filename
	__nrd_cfg_add_str	SteerExec_Adv	MaxSteeringUnfriendly $filename
	__nrd_cfg_add_str_new_key	SteerExec_Adv	LowRSSIXingThreshold	LowRSSIXingThreshold_W2 $filename
	__nrd_cfg_add_str_new_key	SteerExec_Adv	LowRSSIXingThreshold	LowRSSIXingThreshold_W5 $filename
	__nrd_cfg_add_str	SteerExec_Adv	TargetLowRSSIThreshold_W2 $filename
	__nrd_cfg_add_str	SteerExec_Adv	TargetLowRSSIThreshold_W5 $filename
	__nrd_cfg_add_str	SteerExec_Adv	BlacklistTime $filename
	__nrd_cfg_add_str	SteerExec_Adv	BTMResponseTime $filename
	__nrd_cfg_add_str	SteerExec_Adv	BTMAssociationTime $filename
	__nrd_cfg_add_str	SteerExec_Adv	BTMAlsoBlacklist $filename
	__nrd_cfg_add_str	SteerExec_Adv	BTMUnfriendlyTime $filename
	__nrd_cfg_add_str	SteerExec_Adv	BTMSteeringProhibitShortTime $filename
	__nrd_cfg_add_str	SteerExec_Adv	MaxBTMUnfriendly $filename
	__nrd_cfg_add_str	SteerExec_Adv	MaxBTMActiveUnfriendly $filename
	__nrd_cfg_add_str	config_Adv	AgeLimit $filename
	__nrd_cfg_add_str	SteerExec_Adv	MinRSSIBestEffort $filename
	__nrd_cfg_add_str	SteerExec_Adv	StartInBTMActiveState $filename
	__nrd_cfg_add_str	SteerExec_Adv	MaxConsecutiveBTMFailuresAsActive $filename

	__nrd_cfg_nl_append '[STEERALG]' $filename
	__nrd_cfg_add_str_new_key	IdleSteer	RSSISteeringPoint_DG	InactRSSIXingThreshold_W2 $filename
	__nrd_cfg_add_str_new_key	IdleSteer	RSSISteeringPoint_UG	InactRSSIXingThreshold_W5 $filename
	#__nrd_cfg_add_str_new_key	ActiveSteer	TxRateXingThreshold_UG	HighTxRateXingThreshold $filename
		__nrd_cfg_append 'HighTxRateXingThreshold=6000' $filename

	__nrd_cfg_add_str_new_key	ActiveSteer	RateRSSIXingThreshold_UG	HighRateRSSIXingThreshold $filename
	__nrd_cfg_add_str_new_key	ActiveSteer	TxRateXingThreshold_DG	LowTxRateXingThreshold $filename
	__nrd_cfg_add_str_new_key	ActiveSteer	RateRSSIXingThreshold_DG	LowRateRSSIXingThreshold $filename
	__nrd_cfg_add_str	SteerAlg_Adv	MinTxRateIncreaseThreshold $filename
	__nrd_cfg_add_str	config_Adv	AgeLimit $filename
	__nrd_cfg_add_str	config		PHYBasedPrioritization $filename
	__nrd_cfg_add_str	SteerAlg_Adv	MaxSteeringTargetCount $filename
	__nrd_cfg_add_str   APSteer APSteerToLeafMinRSSIIncThreshold    $filename
		# TODO: only consider star topology, so no more than one hop RE
	__nrd_cfg_add_str   APSteer APSteerToRootMinRSSIIncThreshold    $filename
	__nrd_cfg_add_str   APSteer APSteerToPeerMinRSSIIncThreshold    $filename
	# Use different delta rssi threshold for ap and re.
	if [ "$device_type" = 'AP' ]; then
		__nrd_cfg_add_str_new_key APSteer APSteerToPeerMinRSSIIncThresholdAr_CAP APSteerToPeerMinRSSIIncThresholdAr $filename
	else
		__nrd_cfg_add_str_new_key APSteer APSteerToPeerMinRSSIIncThresholdAr_RE APSteerToPeerMinRSSIIncThresholdAr $filename
	fi
	__nrd_cfg_add_str   APSteer DownlinkRSSIThreshold_W5    $filename
	__nrd_cfg_add_str   APSteer CliSteerRCPIThreshold       $filename
	__nrd_cfg_add_str   APSteer CliRCPIBtmThreshold         $filename
	__nrd_cfg_add_str	APSteer BandRcpiDeltaThreshold		$filename
	__nrd_cfg_add_str   APSteer AiRoamingEnable       		$filename
	__nrd_cfg_add_str   APSteer CliSteerRCPIThresholdAr     $filename
	__nrd_cfg_add_str   APSteer CliRCPIBtmThresholdAr       $filename
	__nrd_cfg_add_str	APSteer BandRcpiDeltaThresholdAr	$filename

	__nrd_get_ar_interfaces
	__nrd_cfg_nl_append '[AIROAMING]' $filename
	[ -n "$bak_if_2g" ] && __nrd_cfg_add_key_val backhaulIfname2g "$bak_if_2g" $filename
	[ -n "$sta_if_2g" ] && __nrd_cfg_add_key_val staIfname2g "$sta_if_2g" $filename
	[ -n "$hst_if_2g" ] && __nrd_cfg_add_key_val hostIfname2g "$hst_if_2g" $filename
	[ -n "$gst_if_2g" ] && __nrd_cfg_add_key_val guestIfname2g "$gst_if_2g" $filename
	[ -n "$bak_if_5g" ] && __nrd_cfg_add_key_val backhaulIfname5g "$bak_if_5g" $filename
	[ -n "$sta_if_5g" ] && __nrd_cfg_add_key_val staIfname5g "$sta_if_5g" $filename
	[ -n "$hst_if_5g" ] && __nrd_cfg_add_key_val hostIfname5g "$hst_if_5g" $filename
	[ -n "$gst_if_5g" ] && __nrd_cfg_add_key_val guestIfname5g "$gst_if_5g" $filename
	# Temporarily use 6g interface name to overwrite then 5g2 name. Changes may be needed
	# after the algorithm being adapted with more bands.
	if [ "$support_triband" = "yes" ]; then
		if [ "$support_6g" = "yes" ]; then
			[ -n "$bak_if_6g" ] && __nrd_cfg_add_key_val backhaulIfname5g2 "$bak_if_6g" $filename
			[ -n "$sta_if_6g" ] && __nrd_cfg_add_key_val staIfname5g2 "$sta_if_6g" $filename
			[ -n "$hst_if_6g" ] && __nrd_cfg_add_key_val hostIfname5g2 "$hst_if_6g" $filename
			[ -n "$gst_if_6g" ] && __nrd_cfg_add_key_val guestIfname5g2 "$gst_if_6g" $filename
		else
			[ -n "$bak_if_5g2" ] && __nrd_cfg_add_key_val backhaulIfname5g2 "$bak_if_5g2" $filename
			[ -n "$sta_if_5g2" ] && __nrd_cfg_add_key_val staIfname5g2 "$sta_if_5g2" $filename
			[ -n "$hst_if_5g2" ] && __nrd_cfg_add_key_val hostIfname5g2 "$hst_if_5g2" $filename
			[ -n "$gst_if_5g2" ] && __nrd_cfg_add_key_val guestIfname5g2 "$gst_if_5g2" $filename
		fi
	fi
}
