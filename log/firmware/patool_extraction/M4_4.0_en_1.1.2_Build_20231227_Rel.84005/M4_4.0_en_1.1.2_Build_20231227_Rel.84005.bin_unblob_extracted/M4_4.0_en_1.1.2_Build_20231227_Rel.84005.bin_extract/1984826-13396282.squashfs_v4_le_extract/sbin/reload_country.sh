#!/bin/sh
#
#

sid=$(getfirm SPECIAL_ID)

country='US'

case $sid in
	55530000)
		uci set wifi.radio_2g.country='US'
		uci set wifi.radio_5g.country='US'
		country='US'
		;;
	45550000|5A470000|45470000)
		uci set wifi.radio_2g.country='DE'
		uci set wifi.radio_5g.country='DE'
		country='DE'
		;;
	4A500000)
		uci set wifi.radio_2g.country='JP'
		uci set wifi.radio_5g.country='JP'
		country='JP'
		;;
	43410000)
		uci set wifi.radio_2g.country='CA'
		uci set wifi.radio_5g.country='CA'
		country='CA'
		;;
	41550000)
		uci set wifi.radio_2g.country='AU'
		uci set wifi.radio_5g.country='AU'
		country='AU'
		;;
	4B520000)
		uci set wifi.radio_2g.country='KR'
		uci set wifi.radio_5g.country='KR'
		country='KR'
		;;
	52550000)
		uci set wifi.radio_2g.country='RU'
		uci set wifi.radio_5g.country='RU'
		country='RU'
		;;
esac

uci commit

echo $country > /tmp/country
