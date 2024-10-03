#!/bin/sh

time_protocol=`/usr/sbin/userconfig -read DATETIME Protocol`
successSleepSecs=604800
failedSleepSecs=3600
firstFailRetrytimes=6
firstFailRetrySleepSecs=1
stopflag=0
firstTry=1
syncstate=0

do_ntp_sync()
{
	/usr/sbin/ntpclient -s -i 15 -h "$1"
	if [ $? != 0 ]; then
		/usr/sbin/ntpclient -s -i 15 -6 -h "$1"
	fi
	return $?
}

case "$time_protocol" in
  1)
	kill `pidof ntpclient`
	hostname=`/usr/sbin/userconfig -read DATETIME NTPServerIP`
	if [ $? = 0 ] ; then
		kill `pidof ntpclient` 
		# some delay to avoid wireless connection not finished
		if [ -n "$1" ]; then
			sleep $1 
		fi
		while [ "$stopflag" -eq 0 ]; do
			#debug
			#echo "[$(date)] - Start doing ntp sync"
			#debug
			#start doing ntp sync
			do_ntp_sync "$hostname"
			syncstate=$?
			#end doing ntp sync
			#ntp sync success
			if [ $syncstate = 0 ]; then
				#debug
				#echo "[$(date)] - Doing ntp sync success"
				#debug
				/usr/bin/logger -t ipcam "Synchronizing the time with NTP server success."
				/usr/sbin/msger camsvr 0 ctimeupdate 0 1
				##/usr/sbin/rtcfg -w
				sleep $successSleepSecs
			#ntp sync failed
			else
				#debug
				#echo "[$(date)] - Doing ntp sync failed"
				#debug
				if [ "$firstTry" -eq 1 ]; then
					/usr/bin/logger -t ipcam "Failed to synchronize the time with NTP server."
					while [ "$firstFailRetrytimes" -gt 0 ]; do
						#debug
						#echo "[$(date)] - first time failed retryindex $firstFailRetrytimes"
						#debug
						#start doing ntp sync
						do_ntp_sync "$hostname"
						syncstate=$?
						#end doing ntp sync
						#ntp sync success
						if [ $syncstate = 0 ]; then
							#debug
							#echo "[$(date)] - retry Doing ntp sync success"
							#debug
							/usr/bin/logger -t ipcam "Synchronizing the time with NTP server success."
							/usr/sbin/msger camsvr 0 ctimeupdate 0 1
							firstFailRetrytimes=0
							sleep $successSleepSecs
							##/usr/sbin/rtcfg -w
						#ntp sync failed
						else
							#debug
							#echo "[$(date)] - retry Doing ntp sync failed retryindex $firstFailRetrytimes"
							#debug
							firstFailRetrytimes=$(($firstFailRetrytimes - 1))
							sleep $firstFailRetrySleepSecs
						fi
					done
				else
					#debug
					#echo "[$(date)] - not first time failed"
					#debug
					sleep $failedSleepSecs
				fi
			fi
			firstTry=0
		done
	fi
	;;

   *)
	echo "No protocol find"
	exit 1
esac
