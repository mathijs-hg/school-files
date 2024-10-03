#!/bin/sh

/usr/sbin/userconfig -write MD_BLOCK Percentage 1
/usr/sbin/userconfig -write AUDIO_PROFILE0 SpeakerEnable 0
/usr/sbin/userconfig -write QoS VideoDSCP 63
/usr/sbin/userconfig -write QoS AudioDSCP 63
/usr/sbin/userconfig -write INFO Nipca 1.9.7

if [ -f /mnt/flash/config/NETIPCAS.ini ]; then
	hwv=`cfg -a r -p /mnt/flash/config NETIPCAS.ini NIPCAS hwv`
	/usr/sbin/userconfig -write "INFO" "HWVersion" "$hwv"
fi
