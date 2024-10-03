
undefined4 FUN_004126e4(void)

{
  system(
        "/usr/sbin/mDNSClientPosix -t _dhnap._tcp -s 5 -f 0 -p /tmp/.hnap_device_list_tmp.xml 2>/dev/null 1>/dev/null"
[32m        );[0m
[32m  system("cp -f /tmp/.hnap_device_list_tmp.xml /tmp/.hnap_device_list.xml");[0m
  return 0;
}

[ASK_GPT] aedefdc0d2283317
