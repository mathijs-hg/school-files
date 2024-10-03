
void MsgManager(int param_1)

{
  int iVar1;
  byte bVar2;
  undefined local_40 [4];
  int local_3c;
  char *local_38;
  char *local_34;
  uint local_30;
  
  local_38 = "msg.c";
  local_34 = "WIRELESS_AP";
  do {
    if ((g_State & 0x80) == 0) {
LAB_004028a0:
      msgClean(param_1,0);
      msgDetach(g_pTMsg);
      msgRelease(param_1);
      fwrite("\n=== Netmgr Exit! ===\n",1,0x16,stderr);
      return;
    }
    iVar1 = msgWaitUser(param_1,1);
    if (-1 < iVar1) {
      if ((g_State & 0x80) == 0) goto LAB_004028a0;
      if (*(int *)(param_1 + 0xc) == 300) {
        if (*(int *)(param_1 + 0x10) == 2000) {
          local_3c = 0;
          switch(*(undefined4 *)(param_1 + 0x14)) {
          case 200:
            iVar1 = WExist();
            if (iVar1 != 0) {
              local_30 = (uint)*(byte *)(param_1 + 0x23);
              if (local_30 == 2) {
                local_30 = (g_State ^ 0x20) >> 5 & 1;
              }
              if (local_30 == 0) {
                g_State = g_State & 0xef;
              }
              else {
                g_State = g_State | 0x10;
              }
              if ((g_State & 0x40) == 0) {
                if ((g_State & 4) != 0) {
                  stopWPS();
                }
                iVar1 = cfgRead("WIRELESS",&DAT_00404868,&local_3c);
                if (-1 < iVar1) {
                  if ((local_30 == 0) && (local_3c != 0)) {
[32m                    system("msger netmgr 0 wifi.adhoc 0 1 2>/dev/null 1>/dev/null");[0m
                  }
                  else {
                    APMode(local_30);
                  }
                }
              }
              else {
                g_State = g_State & 0xdf | (byte)((g_State & 0x10) << 1);
              }
            }
            break;
          case 0xc9:
            iVar1 = WExist();
            if (iVar1 != 0) {
              DaulBandSiteScan();
            }
            break;
          case 0xca:
[32m            system("/usr/sbin/userconfig -write WIRELESS Mode 0");[0m
            iVar1 = WExist();
            if ((iVar1 == 0) || ((g_State & 0x44) != 0)) {
              iVar1 = WExist();
              if ((iVar1 != 0) && ((g_State & 0x44) == 0x40)) {
                brctlAddIf(&DAT_00404718,"wlan0");
                brctlAddIf(&DAT_00404718,"wlan0-vxd");
                ClientAntennaSelect();
                startWPS(1);
                brctlDelIf(&DAT_00404718,"wlan0");
                brctlDelIf(&DAT_00404718,"wlan0-vxd");
              }
            }
            else {
              if ((g_State & 0x21) != 0) {
                if ((g_State & 0x20) != 0) {
                  g_iApWps = 1;
                }
                APMode(0xffffffff);
              }
              startWPS(0);
            }
            break;
          case 0xcb:
            if ((g_State & 4) == 0) {
[32m              system("/usr/sbin/userconfig -write WIRELESS Mode 0");[0m
              iVar1 = WExist();
              if ((iVar1 == 0) || ((g_State & 0x44) != 0)) {
                iVar1 = WExist();
                if ((iVar1 != 0) && ((g_State & 0x44) == 0x40)) {
                  brctlAddIf(&DAT_00404718,"wlan0");
                  brctlAddIf(&DAT_00404718,"wlan0-vxd");
                  ClientAntennaSelect();
                  startWPS(1);
                  brctlDelIf(&DAT_00404718,"wlan0");
                  brctlDelIf(&DAT_00404718,"wlan0-vxd");
                }
              }
              else {
                if ((g_State & 0x21) != 0) {
                  if ((g_State & 0x20) != 0) {
                    g_iApWps = 1;
                  }
                  LEDcontrol("apoff");
                  LEDcontrol("wpsproc");
                  APMode(0xffffffff);
                }
                startWPS(1);
              }
            }
            else {
              startWPS(1);
            }
            break;
          case 0xcc:
            iVar1 = WExist();
            if ((iVar1 == 0) || ((g_State & 0x44) != 4)) {
              if ((g_State & 0x44) == 0x44) {
                stopWPS();
                LEDcontrol("netup");
                brctlDelIf(&DAT_00404718,"wlan0");
                brctlDelIf(&DAT_00404718,"wlan0-vxd");
              }
            }
            else {
              stopWPS();
              if ((g_State & 0x10) == 0) {
                if ((g_State & 1) == 0) {
                  LEDcontrol("netup");
                }
                else {
[32m                  system("/usr/sbin/userconfig -write WIRELESS Mode 1");[0m
                  APMode(3);
                }
              }
              else {
                APMode(1);
              }
            }
            break;
          case 0xcd:
            if ((g_State & 4) != 0) {
              UpdateWPSStatus();
            }
            break;
          case 0xce:
            UpdateNetPhy();
            break;
          case 0xcf:
            if (*(int *)(param_1 + 0x20) == 0) {
              iVar1 = WExist();
              if (iVar1 != 0) {
                wiredOff();
              }
            }
            else {
              if ((g_State & 4) != 0) {
                stopWPS();
              }
              if ((g_State & 0x40) == 0) {
                wiredOn();
              }
            }
            break;
          case 0xd0:
            iVar1 = WExist();
            if ((iVar1 != 0) && ((g_State & 0x40) == 0)) {
              g_State = g_State & 0xee;
              local_40[0] = 0;
              cfgWrite(local_34,"Enable",local_40,1);
              APMode(0);
            }
            break;
          case 0xd1:
          case 0xd5:
          case 0xd6:
            break;
          case 0xd2:
            iVar1 = WExist();
            if ((iVar1 != 0) && ((g_State & 0x40) == 0)) {
              APMode(1);
            }
            break;
          case 0xd3:
            APWaitUpdate();
            break;
          case 0xd4:
            APMode(3);
            break;
          case 0xd7:
            FUN_00401ed0();
            break;
          default:
            printf("%s: Unknown Inform Cmd: %d\n",local_38);
          }
        }
        else if (*(int *)(param_1 + 0x10) == 4000) {
          bVar2 = g_State;
          if (*(int *)(param_1 + 0x14) != 300) {
            printf("[%s] Unknown Query Cmd: %d\n","netmgr");
            bVar2 = 0;
          }
          msgAnswerVal(param_1,*(undefined4 *)(param_1 + 0x14),bVar2);
        }
        else {
          printf("[%s] Unkonw command grop: %d\n","netmgr");
        }
      }
      else {
        printf("[%s] Get Unknown msg type: %ld\n","netmgr");
        printf("\tgroup: %d\n",*(undefined4 *)(param_1 + 0x10));
        printf("\tCmd: %d\n",*(undefined4 *)(param_1 + 0x14));
      }
    }
  } while( true );
}

[ASK_GPT] cf15e2d16a9fd53f
