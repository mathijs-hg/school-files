
undefined4 main(int param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  FILE *__s;
  size_t sVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  uint uVar7;
  char local_4d0;
  undefined auStack_4cf [3];
  char acStack_4cc [33];
  char acStack_4ab [20];
  char acStack_497 [23];
  char acStack_480 [10];
  char acStack_476 [8];
  char acStack_46e [926];
  char acStack_d0 [5];
  char acStack_cb [34];
  char local_a9 [21];
  char acStack_94 [24];
  char acStack_7c [11];
  char acStack_71 [9];
  char acStack_68 [8];
  undefined4 local_60;
  FILE *local_5c;
  int local_58;
  char *local_54;
  undefined4 local_50;
  char *local_4c;
  undefined *local_48;
  char *local_44;
  char *local_40;
  char *local_3c;
  char *local_38;
  char *local_34;
  char *local_30;
  char *local_2c;
  
  local_4d0 = '\0';
[32m  memset(auStack_4cf,0,0x3ff);[0m
  if (param_1 < 3) {
    fwrite("[hnap_tool_sitesurvey] Usage\n",1,0x1d,stderr);
    fwrite(" hnap_tool_sitesurvey [Band] [output_filepath]\n",1,0x2f,stderr);
    fwrite(" [Band] 2 - 2.4Ghz / 5 - 5GHz\n",1,0x1e,stderr);
    uVar2 = 0xffffffff;
  }
  else {
    local_58 = atoi(*(char **)(param_2 + 4));
    pcVar6 = *(char **)(param_2 + 8);
[32m    local_5c = fopen(pcVar6,"w");[0m
    if (local_5c == (FILE *)0x0) {
      fprintf(stderr,"[hnap_tool_sitesurvey] open file [%s] failed\n",pcVar6);
      uVar2 = 0xffffffff;
    }
    else {
[32m      __s = tmpfile();[0m
[32m[32m      pcVar6 = (char *)malloc(0x5554);[0m[0m
      if (pcVar6 == (char *)0x0) {
        fwrite("[hnap_tool_sitesurvey] malloc sitesurvey buffer failed\n",1,0x37,stderr);
        fclose(local_5c);
        fclose(__s);
        uVar2 = 0xffffffff;
      }
      else {
        if (local_58 == 5) {
[32m          system("iwpriv wlan0 set_mib band2G5GSelected=2");[0m
        }
        else {
[32m          system("iwpriv wlan0 set_mib band2G5GSelected=1");[0m
        }
        getSiteList(pcVar6,0x5554);
[32m        system("iwpriv wlan0 set_mib band2G5GSelected=3");[0m
        sVar3 = strlen(pcVar6);
        fwrite(pcVar6,sVar3,1,__s);
        fseek(__s,0,0);
[32m        free(pcVar6);[0m
        bVar1 = true;
        local_60 = ixmlDocument_createDocument();
        local_50 = ixmlDocument_createElement(local_60,"APStatInfoLists");
        local_4c = "APStatInfo";
        local_48 = &DAT_00402a14;
        local_44 = "MacAddress";
        local_40 = "SupportedSecurity";
        local_3c = "SecurityInfo";
        local_54 = "NONE";
        local_38 = "Channel";
        local_34 = "SignalStrength";
        local_30 = "WEP";
        local_2c = "WPAPSK";
LAB_00401bd4:
[32m        pcVar6 = fgets(&local_4d0,0x400,__s);[0m
        if (pcVar6 != (char *)0x0) {
[32m          memset(acStack_d0,0,0x6b);[0m
[32m[32m[32m          strncpy(acStack_d0,&local_4d0,4);[0m[0m[0m
[32m[32m[32m[32m          strncpy(acStack_cb,acStack_4cc,0x21);[0m[0m[0m[0m
[32m[32m[32m[32m          strncpy(local_a9,acStack_4ab,0x14);[0m[0m[0m[0m
[32m[32m[32m[32m          strncpy(acStack_94,acStack_497,0x17);[0m[0m[0m[0m
[32m[32m[32m[32m          strncpy(acStack_7c,acStack_480,10);[0m[0m[0m[0m
[32m[32m[32m[32m          strncpy(acStack_71,acStack_476,8);[0m[0m[0m[0m
[32m[32m[32m          strncpy(acStack_68,acStack_46e,2);[0m[0m[0m
          FUN_00400f50(acStack_d0,5);
          FUN_00400f50(acStack_cb,0x22);
          FUN_00400f50(local_a9,0x15);
          FUN_00400f50(acStack_94,0x18);
          FUN_00400f50(acStack_7c,0xb);
          FUN_00400f50(acStack_71,9);
          FUN_00400f50(acStack_68,3);
          if ((!bVar1) && (iVar4 = FUN_00400f8c(acStack_d0), iVar4 != -1)) goto code_r0x004014dc;
          goto LAB_00401bd0;
        }
        pcVar6 = (char *)ixmlPrintNode(local_50);
        if (pcVar6 != (char *)0x0) {
          sVar3 = strlen(pcVar6);
          fwrite(pcVar6,1,sVar3,local_5c);
          fflush(local_5c);
          ixmlFreeDOMString(pcVar6);
        }
        ixmlDocument_free(local_60);
        fclose(__s);
        fclose(local_5c);
        uVar2 = 0;
      }
    }
  }
  return uVar2;
code_r0x004014dc:
  if (local_58 == 5) {
    iVar4 = atoi(acStack_d0);
  }
  else {
    iVar4 = atoi(acStack_d0);
  }
  bVar1 = false;
  if (0xe < iVar4) goto LAB_00401bd4;
  uVar2 = ixmlAppendNewElement(local_60,local_50,local_4c,0);
  ixmlAppendNewElement(local_60,uVar2,local_48,acStack_cb);
  pcVar6 = local_a9;
  for (uVar7 = 0; sVar3 = strlen(local_a9), uVar7 < sVar3; uVar7 = uVar7 + 1) {
    *pcVar6 = (char)*(undefined2 *)(__ctype_toupper + *pcVar6 * 2);
    pcVar6 = pcVar6 + 1;
  }
  ixmlAppendNewElement(local_60,uVar2,local_44,local_a9);
  uVar5 = ixmlAppendNewElement(local_60,uVar2,local_40,0);
  uVar5 = ixmlAppendNewElement(local_60,uVar5,local_3c,0);
  pcVar6 = strstr(acStack_94,local_54);
  if (pcVar6 == (char *)0x0) {
    pcVar6 = strstr(acStack_94,local_30);
    if (pcVar6 == (char *)0x0) {
      pcVar6 = strstr(acStack_94,local_2c);
      if (pcVar6 == (char *)0x0) {
        pcVar6 = strstr(acStack_94,"WPA1PSK");
        if (pcVar6 == (char *)0x0) {
          pcVar6 = strstr(acStack_94,"WPA2PSK");
          if (pcVar6 != (char *)0x0) {
            ixmlAppendNewElement(local_60,uVar5,"SecurityType","WPA2-PSK");
            uVar5 = ixmlAppendNewElement(local_60,uVar5,"Encryptions",0);
            pcVar6 = strstr(acStack_94,"TKIP");
            if (pcVar6 == (char *)0x0) {
              pcVar6 = strstr(acStack_94,"AES");
              if (pcVar6 == (char *)0x0) {
                ixmlAppendNewElement(local_60,uVar5,"string","TKIPORAES");
              }
              else {
                ixmlAppendNewElement(local_60,uVar5,"string",&DAT_00402a94);
              }
            }
            else {
              pcVar6 = strstr(acStack_94,"AES");
              if (pcVar6 == (char *)0x0) {
                ixmlAppendNewElement(local_60,uVar5,"string",&DAT_00402a8c);
              }
              else {
                ixmlAppendNewElement(local_60,uVar5,"string","TKIPORAES");
              }
            }
            goto LAB_00401b98;
          }
        }
        else {
          pcVar6 = strstr(acStack_94,"WPA2PSK");
          if (pcVar6 != (char *)0x0) {
            ixmlAppendNewElement(local_60,uVar5,"SecurityType","WPAORWPA2-PSK");
            uVar5 = ixmlAppendNewElement(local_60,uVar5,"Encryptions",0);
            pcVar6 = strstr(acStack_94,"TKIP");
            if (pcVar6 == (char *)0x0) {
              pcVar6 = strstr(acStack_94,"AES");
              if (pcVar6 == (char *)0x0) {
                ixmlAppendNewElement(local_60,uVar5,"string","TKIPORAES");
              }
              else {
                ixmlAppendNewElement(local_60,uVar5,"string",&DAT_00402a94);
              }
            }
            else {
              pcVar6 = strstr(acStack_94,"AES");
              if (pcVar6 == (char *)0x0) {
                ixmlAppendNewElement(local_60,uVar5,"string",&DAT_00402a8c);
              }
              else {
                ixmlAppendNewElement(local_60,uVar5,"string","TKIPORAES");
              }
            }
            goto LAB_00401b98;
          }
        }
        ixmlAppendNewElement(local_60,uVar5,"SecurityType",local_54);
        uVar5 = ixmlAppendNewElement(local_60,uVar5,"Encryptions",0);
        ixmlAppendNewElement(local_60,uVar5,"string",local_54);
      }
      else {
        ixmlAppendNewElement(local_60,uVar5,"SecurityType","WPA-PSK");
        uVar5 = ixmlAppendNewElement(local_60,uVar5,"Encryptions",0);
        pcVar6 = strstr(acStack_94,"TKIP");
        if (pcVar6 == (char *)0x0) {
          pcVar6 = strstr(acStack_94,"AES");
          if (pcVar6 == (char *)0x0) {
            ixmlAppendNewElement(local_60,uVar5,"string","TKIPORAES");
          }
          else {
            ixmlAppendNewElement(local_60,uVar5,"string",&DAT_00402a94);
          }
        }
        else {
          pcVar6 = strstr(acStack_94,"AES");
          if (pcVar6 == (char *)0x0) {
            ixmlAppendNewElement(local_60,uVar5,"string",&DAT_00402a8c);
          }
          else {
            ixmlAppendNewElement(local_60,uVar5,"string","TKIPORAES");
          }
        }
      }
    }
    else {
      ixmlAppendNewElement(local_60,uVar5,"SecurityType","WEP-AUTO");
      uVar5 = ixmlAppendNewElement(local_60,uVar5,"Encryptions",0);
      ixmlAppendNewElement(local_60,uVar5,"string","WEP-64");
    }
  }
  else {
    ixmlAppendNewElement(local_60,uVar5,"SecurityType",local_54);
    uVar5 = ixmlAppendNewElement(local_60,uVar5,"Encryptions",0);
    ixmlAppendNewElement(local_60,uVar5,"string",local_54);
  }
LAB_00401b98:
  ixmlAppendNewElement(local_60,uVar2,local_38,acStack_d0);
  ixmlAppendNewElement(local_60,uVar2,local_34,acStack_7c);
LAB_00401bd0:
  bVar1 = false;
  goto LAB_00401bd4;
}

[ASK_GPT] 56806eef24e1dc4d
