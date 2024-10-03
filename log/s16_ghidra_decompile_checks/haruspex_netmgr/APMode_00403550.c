
void APMode(int param_1)

{
  bool bVar1;
  bool bVar2;
  FILE *__stream;
  tm *__tp;
  char *pcVar3;
  undefined4 uVar4;
  byte bVar5;
  undefined4 local_1a8 [11];
  int local_17c;
  char local_18 [4];
  time_t tStack_14;
  
  if ((g_State & 0x40) == 0) {
    g_iWait = 400;
    time(&tStack_14);
    __tp = localtime(&tStack_14);
    __stream = stderr;
    pcVar3 = asctime(__tp);
    fprintf(__stream,"\n=== Netmgr Start set IF, time is: %s\n",pcVar3);
    HWMIB_getRegion(local_18);
    bVar1 = local_18[0] == '\x03';
    bVar2 = local_18[0] == '\x1a';
    g_State = g_State & 0xfd;
[32m    system("iwpriv wlan0 set_mib antdiv_select=0");[0m
    if (param_1 == 1) {
      g_State = g_State & 0xfe | 0x20;
      LEDcontrol(&DAT_00404b1c);
      if ((g_State & 8) != 0) {
        g_State = g_State & 0xf7;
      }
      if ((g_State & 4) != 0) {
        stopWPS();
      }
      net_down("wlan0-vxd");
      net_down("wlan0");
      get_wlan2_ap(local_1a8);
      local_1a8[0] = 1;
      uVar4 = 5;
      if (local_17c < 0xe) {
        uVar4 = 0xb;
      }
      setWlanDrv(local_1a8,"wlan0",uVar4);
      if ((g_State & 0x10) == 0) {
        get_wlan2_cli(local_1a8);
        setWlanDrv(local_1a8,"wlan0-vxd",0xd);
      }
      if ((bVar1 || bVar2) && (SetAdaptivity("wlan0",1), (g_State & 0x10) == 0)) {
        SetAdaptivity("wlan0-vxd",1);
      }
      UpdateNetPhy();
[32m      system("/usr/sbin/userconfig -write DHCPD Enable 1");[0m
      IPReset();
      LEDcontrol(&DAT_00404b1c);
      puts("\nnetmgr: switch to AP mode done\n");
[32m      system("iwpriv wlan0 set_mib antdiv_select=2");[0m
      puts("WiFi: Select Antenna to 2");
    }
    else if (param_1 == 3) {
      bVar5 = g_State & 0xdf;
      if ((g_State & 8) != 0) {
        bVar5 = g_State & 0xd7;
      }
      g_State = bVar5 | 1;
      if ((bVar5 & 4) != 0) {
        stopWPS();
      }
      net_down("wlan0-vxd");
      net_down("wlan0");
      get_wlan2_adh(local_1a8);
      local_1a8[0] = 1;
[32m      system("/usr/sbin/userconfig -write DHCPD Enable 0");[0m
      setWlanDrv(local_1a8,"wlan0",0xb);
      if (bVar1 || bVar2) {
        SetAdaptivity("wlan0",1);
      }
      UpdateNetPhy();
      IPReset();
      LEDcontrol("apoff");
      puts("\nnetmgr: switch to Ad-Hoc  done\n");
    }
    else {
[32m      system("ifconfig br0 192.168.0.20 netmask 255.255.255.0 up");[0m
[32m      system("route add default gw 192.168.0.1 metric 10");[0m
      bVar5 = g_State & 0xdf;
      if ((g_State & 8) != 0) {
        bVar5 = g_State & 0xd7;
      }
      g_State = bVar5;
      LEDcontrol("apoff");
      net_down("wlan0-vxd");
      net_down("wlan0");
      get_wlan2_ap(local_1a8);
      local_1a8[0] = 1;
      uVar4 = 5;
      if (local_17c < 0xe) {
        uVar4 = 0xb;
      }
      setWlanDrv(local_1a8,"wlan0",uVar4);
[32m      system("/usr/sbin/userconfig -write DHCPD Enable 1");[0m
      get_wlan2_cli(local_1a8);
      setWlanDrv(local_1a8,"wlan0-vxd",0xd);
      if (bVar1 || bVar2) {
        SetAdaptivity("wlan0",1);
        SetAdaptivity("wlan0-vxd",1);
      }
      UpdateNetPhy();
      IPReset();
      if (param_1 == 0) {
        g_iAPWaitCnt = 0;
        g_State = g_State | 8;
      }
      else {
        ClientAntennaSelect();
      }
      puts("\nnetmgr: switch to Client mode done\n");
    }
  }
  return;
}

[ASK_GPT] 95e6dfaaa8a84e70
