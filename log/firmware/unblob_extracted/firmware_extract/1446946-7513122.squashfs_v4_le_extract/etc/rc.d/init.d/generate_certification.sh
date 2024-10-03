#!/bin/sh

#generate HTTPS certification
if [ -f /mnt/flash/config/stunnel.pem ]; then
	echo "don't need to generate ssl certification"
else
	echo "generate ssl certification"
	mkdir -p /var/https
	export OPENSSL_CONF=/etc/openssl.cnf
	export RANDFILE=/tmp/random.rnd
	randnumber=`openssl rand -hex 1024`
	mac=`rtkmib mac`
	mac2=`echo $mac | awk -F: '{printf $1$2$3$4$5$6}'`
	echo "$mac2"
	echo $randnumber$mac2 > /tmp/random.rnd
	openssl req -x509 -nodes -sha256 -days 7300 -newkey rsa:2048 -keyout /var/https/www.dlink.com.key -out /var/https/www.dlink.com.crt -subj "/C=TW/ST=Asia/L=Asia/O=D-Link Corporation/OU=D-Link Corporation/CN=www.dlink.com"
	cat /var/https/www.dlink.com.key /var/https/www.dlink.com.crt > /mnt/flash/config/stunnel.pem
	rm -rf /var/https/www.dlink.com.key /var/https/www.dlink.com.csr /var/https/www.dlink.com.crt
	rm -rf /tmp/random.rnd
fi
