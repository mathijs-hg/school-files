#!/bin/sh
/etc/init.d/ntpc.sh stop &
sleep 1
kill `pidof sleep`
# stop daemon
/etc/init.d/upnp_igd-http.sh stop&
/etc/init.d/upnp_igd-https.sh stop&
/etc/init.d/upnp_igd-rtsp.sh stop&
sleep 1
# kill udhcpc
kill `cat /var/run/udhcpc.pid`
