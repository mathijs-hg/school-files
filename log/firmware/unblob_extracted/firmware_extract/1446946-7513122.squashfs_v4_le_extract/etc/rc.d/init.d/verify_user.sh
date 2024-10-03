#!/bin/sh

username="$1"
password="$2"
username_check=`/usr/sbin/userconfig -read USER_ADMIN Username1`
password_check=`/usr/sbin/userconfig -read USER_ADMIN Password1`
check_value=1
i=1

if [ "$username" == "$username_check" ] && [ "$password" == "$password_check" ]; then
	exit 0
fi


while [ $i -le 10 ]; do
	username_check=`/usr/sbin/userconfig -read USER_GENERAL Username$i`
	password_check=`/usr/sbin/userconfig -read USER_GENERAL Password$i`
	if [ "$username" == "$username_check" ] && [ "$password" == "$password_check" ]; then
		exit 0
	fi
	i=$(($i + 1))
done

i=1
while [ $i -le 10 ]; do
	username_check=`/usr/sbin/userconfig -read USER_GUEST Username$i`
	password_check=`/usr/sbin/userconfig -read USER_GUEST Password$i`
	if [ "$username" == "$username_check" ] && [ "$password" == "$password_check" ]; then
		exit 0
	fi
	i=$(($i + 1))
done

exit 1
