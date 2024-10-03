
undefined4 FUN_004053f0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  time_t local_40;
  tm local_3c;
  
  local_3c.tm_wday = 0;
  local_3c.tm_yday = 0;
  local_3c.tm_isdst = 0;
  local_3c.tm_gmtoff = 0;
  local_3c.tm_zone = (char *)0x0;
  local_3c.tm_year = param_1 + -0x76c;
  local_3c.tm_mon = param_2 + -1;
  local_3c.tm_min = param_5;
  local_3c.tm_sec = param_6;
  local_3c.tm_hour = param_4;
  local_3c.tm_mday = param_3;
  tzset();
  local_3c.tm_isdst = -1;
  local_40 = mktime(&local_3c);
  if ((local_40 != -1) && (iVar1 = stime(&local_40), iVar1 == 0)) {
[32m    system("/usr/sbin/rtcfg -w 2>/dev/null 1>/dev/null");[0m
[32m    system("/usr/sbin/msger camsvr 0 ctimeupdate 0 1 2>/dev/null 1>/dev/null");[0m
    return 0;
  }
  return 0xffffffff;
}

[ASK_GPT] c34e31dc41fb2d21
