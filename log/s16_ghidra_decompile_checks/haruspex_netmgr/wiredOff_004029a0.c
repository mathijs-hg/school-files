
/* WARNING: Heritage AFTER dead removal. Example location: r0x00415270 : 0x00402a44 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void wiredOff(void)

{
  int iVar1;
  int local_10 [2];
  
  local_10[0] = 0;
  g_State = g_State & 0xbf;
  brctlDelIf(&DAT_00404718,&DAT_00404778);
  brctlAddIf(&DAT_00404718,"wlan0");
  brctlAddIf(&DAT_00404718,"wlan0-vxd");
  iVar1 = cfgRead("WIRELESS",&DAT_00404868,local_10);
  if (-1 < iVar1) {
    if (((g_State & 0x20) == 0) && (local_10[0] != 0)) {
      g_State = g_State | 1;
    }
    if ((g_State & 1) == 0) {
      APMode(g_State >> 5 & 1);
    }
    else {
[32m      system("msger netmgr 0 wifi.adhoc 0 1 2>/dev/null 1>/dev/null");[0m
    }
  }
  return;
}

[ASK_GPT] b74d9b8b57779f59
