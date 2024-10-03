
void UpdateWPSStatus(void)

{
  byte bVar1;
  byte bVar2;
  undefined local_10 [4];
  undefined4 local_c [2];
  
  DAT_00415060 = WSCStatus();
  if (DAT_00415060 == 1) {
    fwrite("\n=== WPS SUCCESS ===\n",1,0x15,stderr);
    local_10[0] = 0;
    cfgWrite("WIRELESS_AP","Enable",local_10,1);
    local_c[0] = GetChannel("wlan0-vxd");
    cfgWrite("WIRELESS","Channel",local_c,1);
    WSCConnect();
    g_iApWps = 0;
    APMode(0);
    if ((g_State & 0x40) != 0) {
      LEDcontrol("wpsok");
[32m      system("msger camsvr 0 csmodlazy 0 0");[0m
    }
    g_State = g_State & 0xea;
  }
  else if (DAT_00415060 == 2) {
    fwrite("\n=== WPS FAIL ===\n",1,0x12,stderr);
    bVar1 = g_State & 0xfb;
    bVar2 = g_State & 0x40;
    g_State = bVar1;
    if (bVar2 != 0) {
      LEDcontrol("wpsinit");
[32m      system("msger camsvr 0 csmodlazy 0 0");[0m
    }
    if ((g_State & 0x10) == 0) {
      if ((g_State & 1) == 0) {
        if (g_iApWps == 0) {
          APMode(g_State >> 5 & 1);
        }
        else {
          LEDcontrol("wpsinit");
          g_iApWps = 0;
          APMode(1);
        }
      }
      else {
[32m        system("/usr/sbin/userconfig -write WIRELESS Mode 1");[0m
        LEDcontrol("wpsinit");
        APMode(3);
      }
    }
    else {
      LEDcontrol("wpsinit");
      APMode(1);
    }
  }
  return;
}

[ASK_GPT] a456da60f368c456
