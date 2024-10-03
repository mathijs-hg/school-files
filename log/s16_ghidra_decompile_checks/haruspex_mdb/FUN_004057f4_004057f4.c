
undefined4 FUN_004057f4(int param_1)

{
  int iVar1;
  size_t sVar2;
  FILE *pFVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  size_t sVar7;
  void *pvVar8;
  char *pcVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  uint local_d80;
  int local_d7c;
  undefined4 local_d78;
  undefined4 local_d74;
  int local_d70;
  uint local_d6c;
  int local_d68;
  int local_d64;
  uint local_d60;
  uint local_d5c;
  undefined local_d58 [256];
  char local_c58;
  undefined local_c57;
  undefined local_c56;
  undefined local_c55;
  undefined local_c54;
  undefined local_c53;
  undefined local_c52;
  undefined local_c51;
  char *local_40;
  char *local_3c;
  char *local_38;
  char *local_34;
  undefined *local_30;
  undefined *local_2c;
  
  local_d80 = 0;
  SIReadInt(0x14,&local_d80);
  pcVar9 = *(char **)(param_1 + 4);
  iVar1 = strcasecmp(pcVar9,"admin_passwd");
  if (iVar1 == 0) {
    qryStringDecode(*(undefined4 *)(param_1 + 8));
    pcVar9 = *(char **)(param_1 + 8);
    sVar2 = strlen(pcVar9);
    if (0x20 < sVar2) {
      return 1;
    }
    if (sVar2 < 6) {
      return 1;
    }
    cfgWrite("USER_ADMIN","Password1",pcVar9,1);
    local_d80 = local_d80 | 1;
    goto LAB_00407c5c;
  }
  iVar1 = strcasecmp(pcVar9,"register_st");
  if (iVar1 == 0) {
    iVar1 = atoi(*(char **)(param_1 + 8));
    local_d6c = local_d6c & 0xffffff | iVar1 << 0x18;
    cfgWrite("MYDLINK","RegisterStatus",&local_d6c,1);
    local_d80 = local_d80 | 2;
    goto LAB_00407c5c;
  }
  iVar1 = strcasecmp(pcVar9,"attr_0");
  if (iVar1 == 0) {
    local_c58 = '\0';
[32m    memset(&local_c57,0,0xc17);[0m
[32m[32m[32m    strncpy(&local_c58,*(char **)(param_1 + 8),0xc18);[0m[0m[0m
[32m[32m    iVar1 = stat("/mnt/flash/config/mdbcfg.ini",(stat *)local_d58);[0m[0m
    if (iVar1 < 0) {
[32m      pFVar3 = fopen("/mnt/flash/config/mdbcfg.ini","wb");[0m
      fflush(pFVar3);
      fclose(pFVar3);
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,&DAT_0040b248,&local_c58);
    }
    else {
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,&DAT_0040b248,&local_c58);
    }
    local_d80 = local_d80 | 4;
    goto LAB_00407c5c;
  }
  iVar1 = strcasecmp(pcVar9,"attr_1");
  if (iVar1 == 0) {
    local_c58 = '\0';
[32m    memset(&local_c57,0,0xc17);[0m
[32m[32m[32m    strncpy(&local_c58,*(char **)(param_1 + 8),0xc18);[0m[0m[0m
[32m[32m    iVar1 = stat("/mnt/flash/config/mdbcfg.ini",(stat *)local_d58);[0m[0m
    if (iVar1 < 0) {
[32m      pFVar3 = fopen("/mnt/flash/config/mdbcfg.ini","wb");[0m
      fflush(pFVar3);
      fclose(pFVar3);
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr1",&local_c58);
    }
    else {
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr1",&local_c58);
    }
    local_d80 = local_d80 | 8;
    goto LAB_00407c5c;
  }
  iVar1 = strcasecmp(pcVar9,"attr_2");
  if (iVar1 == 0) {
    local_c58 = '\0';
[32m    memset(&local_c57,0,0xc17);[0m
[32m[32m[32m    strncpy(&local_c58,*(char **)(param_1 + 8),0xc18);[0m[0m[0m
[32m[32m    iVar1 = stat("/mnt/flash/config/mdbcfg.ini",(stat *)local_d58);[0m[0m
    if (iVar1 < 0) {
[32m      pFVar3 = fopen("/mnt/flash/config/mdbcfg.ini","wb");[0m
      fflush(pFVar3);
      fclose(pFVar3);
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr2",&local_c58);
    }
    else {
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr2",&local_c58);
    }
    local_d80 = local_d80 | 0x10;
    goto LAB_00407c5c;
  }
  iVar1 = strcasecmp(pcVar9,"attr_3");
  if (iVar1 == 0) {
    local_c58 = '\0';
[32m    memset(&local_c57,0,0xc17);[0m
[32m[32m[32m    strncpy(&local_c58,*(char **)(param_1 + 8),0xc18);[0m[0m[0m
[32m[32m    iVar1 = stat("/mnt/flash/config/mdbcfg.ini",(stat *)local_d58);[0m[0m
    if (iVar1 < 0) {
[32m      pFVar3 = fopen("/mnt/flash/config/mdbcfg.ini","wb");[0m
      fflush(pFVar3);
      fclose(pFVar3);
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr3",&local_c58);
    }
    else {
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr3",&local_c58);
    }
    local_d80 = local_d80 | 0x20;
    goto LAB_00407c5c;
  }
  iVar1 = strcasecmp(pcVar9,"attr_4");
  if (iVar1 == 0) {
    local_c58 = '\0';
[32m    memset(&local_c57,0,0xc17);[0m
[32m[32m[32m    strncpy(&local_c58,*(char **)(param_1 + 8),0xc18);[0m[0m[0m
[32m[32m    iVar1 = stat("/mnt/flash/config/mdbcfg.ini",(stat *)local_d58);[0m[0m
    if (iVar1 < 0) {
[32m      pFVar3 = fopen("/mnt/flash/config/mdbcfg.ini","wb");[0m
      fflush(pFVar3);
      fclose(pFVar3);
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr4",&local_c58);
    }
    else {
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr4",&local_c58);
    }
    local_d80 = local_d80 | 0x40;
    goto LAB_00407c5c;
  }
  iVar1 = strcasecmp(pcVar9,"attr_5");
  if (iVar1 == 0) {
    local_c58 = '\0';
[32m    memset(&local_c57,0,0xc17);[0m
[32m[32m[32m    strncpy(&local_c58,*(char **)(param_1 + 8),0xc18);[0m[0m[0m
[32m[32m    iVar1 = stat("/mnt/flash/config/mdbcfg.ini",(stat *)local_d58);[0m[0m
    if (iVar1 < 0) {
[32m      pFVar3 = fopen("/mnt/flash/config/mdbcfg.ini","wb");[0m
      fflush(pFVar3);
      fclose(pFVar3);
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr5",&local_c58);
    }
    else {
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr5",&local_c58);
    }
    local_d80 = local_d80 | 0x80;
    goto LAB_00407c5c;
  }
  iVar1 = strcasecmp(pcVar9,"attr_6");
  if (iVar1 == 0) {
    local_c58 = '\0';
[32m    memset(&local_c57,0,0xc17);[0m
[32m[32m[32m    strncpy(&local_c58,*(char **)(param_1 + 8),0xc18);[0m[0m[0m
[32m[32m    iVar1 = stat("/mnt/flash/config/mdbcfg.ini",(stat *)local_d58);[0m[0m
    if (iVar1 < 0) {
[32m      pFVar3 = fopen("/mnt/flash/config/mdbcfg.ini","wb");[0m
      fflush(pFVar3);
      fclose(pFVar3);
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr6",&local_c58);
    }
    else {
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr6",&local_c58);
    }
    local_d80 = local_d80 | 0x100;
    goto LAB_00407c5c;
  }
  iVar1 = strcasecmp(pcVar9,"attr_7");
  if (iVar1 == 0) {
    local_c58 = '\0';
[32m    memset(&local_c57,0,0xc17);[0m
[32m[32m[32m    strncpy(&local_c58,*(char **)(param_1 + 8),0xc18);[0m[0m[0m
[32m[32m    iVar1 = stat("/mnt/flash/config/mdbcfg.ini",(stat *)local_d58);[0m[0m
    if (iVar1 < 0) {
[32m      pFVar3 = fopen("/mnt/flash/config/mdbcfg.ini","wb");[0m
      fflush(pFVar3);
      fclose(pFVar3);
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr7",&local_c58);
    }
    else {
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr7",&local_c58);
    }
    local_d80 = local_d80 | 0x200;
    goto LAB_00407c5c;
  }
  iVar1 = strcasecmp(pcVar9,"attr_8");
  if (iVar1 == 0) {
    local_c58 = '\0';
[32m    memset(&local_c57,0,0xc17);[0m
[32m[32m[32m    strncpy(&local_c58,*(char **)(param_1 + 8),0xc18);[0m[0m[0m
[32m[32m    iVar1 = stat("/mnt/flash/config/mdbcfg.ini",(stat *)local_d58);[0m[0m
    if (iVar1 < 0) {
[32m      pFVar3 = fopen("/mnt/flash/config/mdbcfg.ini","wb");[0m
      fflush(pFVar3);
      fclose(pFVar3);
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr8",&local_c58);
    }
    else {
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr8",&local_c58);
    }
    local_d80 = local_d80 | 0x400;
    goto LAB_00407c5c;
  }
  iVar1 = strcasecmp(pcVar9,"attr_9");
  if (iVar1 == 0) {
    local_c58 = '\0';
[32m    memset(&local_c57,0,0xc17);[0m
[32m[32m[32m    strncpy(&local_c58,*(char **)(param_1 + 8),0xc18);[0m[0m[0m
[32m[32m    iVar1 = stat("/mnt/flash/config/mdbcfg.ini",(stat *)local_d58);[0m[0m
    if (iVar1 < 0) {
[32m      pFVar3 = fopen("/mnt/flash/config/mdbcfg.ini","wb");[0m
      fflush(pFVar3);
      fclose(pFVar3);
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr9",&local_c58);
    }
    else {
      CfgSetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr9",&local_c58);
    }
    local_d80 = local_d80 | 0x800;
    goto LAB_00407c5c;
  }
  iVar1 = strcasecmp(pcVar9,"wan_mode");
  if (iVar1 == 0) {
    local_d6c = atoi(*(char **)(param_1 + 8));
    if (local_d6c == 0) {
      local_d6c = 1;
      cfgWrite("NETWORK_V4","BootProto",&local_d6c,1);
    }
    else if (local_d6c == 1) {
      local_d6c = 0;
      cfgWrite("NETWORK_V4","BootProto",&local_d6c,1);
    }
    local_d80 = local_d80 | 0x1000;
    goto LAB_00407c5c;
  }
  iVar1 = strcasecmp(pcVar9,"static_ip_info");
  if (iVar1 == 0) {
    qryStringDecode(*(undefined4 *)(param_1 + 8));
    FUN_00404bc0(param_1);
    piVar10 = *(int **)(param_1 + 0xc);
    iVar1 = 0;
    if (0 < *piVar10) {
      local_3c = "D2";
      local_2c = &DAT_0040b334;
      local_30 = &DAT_0040b32c;
      local_34 = "Gateway";
      local_38 = "SubnetMask";
      local_40 = "IP";
      iVar4 = 0;
      do {
        pcVar9 = *(char **)((int)piVar10 + iVar4 + 4);
        iVar4 = strcasecmp(pcVar9,"I");
        if (iVar4 == 0) {
          cfgWrite("NETWORK_V4",local_40,piVar10[iVar1 + 0x81],1);
        }
        else {
          iVar4 = strcasecmp(pcVar9,"N");
          if (iVar4 == 0) {
            cfgWrite("NETWORK_V4",local_38,piVar10[iVar1 + 0x81],1);
          }
          else {
            iVar4 = strcasecmp(pcVar9,"G");
            if (iVar4 == 0) {
              cfgWrite("NETWORK_V4",local_34,piVar10[iVar1 + 0x81],1);
            }
            else {
              iVar4 = strcasecmp(pcVar9,"D1");
              if (iVar4 == 0) {
                cfgWrite("NETWORK_V4",local_30,piVar10[iVar1 + 0x81],1);
              }
              else {
                iVar4 = strcasecmp(pcVar9,local_3c);
                if (iVar4 == 0) {
                  cfgWrite("NETWORK_V4",local_2c,piVar10[iVar1 + 0x81],1);
                }
              }
            }
          }
        }
        iVar1 = iVar1 + 1;
        piVar10 = *(int **)(param_1 + 0xc);
        iVar4 = iVar1 * 4;
      } while (iVar1 < *piVar10);
    }
    local_d80 = local_d80 | 0x2000;
    goto LAB_00407c5c;
  }
  iVar1 = strcasecmp(pcVar9,"pppoe_info");
  if (iVar1 == 0) {
    qryStringDecode(*(undefined4 *)(param_1 + 8));
    FUN_00404bc0(param_1);
    piVar10 = *(int **)(param_1 + 0xc);
    iVar1 = 0;
    if (0 < *piVar10) {
      local_38 = "PPPoEPWD";
      local_3c = "PPPoEUID";
      local_40 = "PPPoEEnable";
      iVar4 = 0;
      do {
        pcVar9 = *(char **)((int)piVar10 + iVar4 + 4);
        iVar4 = strcasecmp(pcVar9,"E");
        if (iVar4 == 0) {
          iVar4 = atoi((char *)piVar10[iVar1 + 0x81]);
          local_d6c = local_d6c & 0xffffff | iVar4 << 0x18;
          cfgWrite("NETWORK_V4",local_40,&local_d6c,1);
        }
        else {
          iVar4 = strcasecmp(pcVar9,"U");
          if (iVar4 == 0) {
            cfgWrite("NETWORK_V4",local_3c,piVar10[iVar1 + 0x81],1);
          }
          else {
            iVar4 = strcasecmp(pcVar9,"P");
            if (iVar4 == 0) {
              cfgWrite("NETWORK_V4",local_38,piVar10[iVar1 + 0x81],1);
            }
          }
        }
        iVar1 = iVar1 + 1;
        piVar10 = *(int **)(param_1 + 0xc);
        iVar4 = iVar1 * 4;
      } while (iVar1 < *piVar10);
    }
    local_d80 = local_d80 | 0x4000;
    goto LAB_00407c5c;
  }
  iVar1 = strcasecmp(pcVar9,"wlan_st_info");
  if (iVar1 == 0) {
    return 1;
  }
  iVar1 = strcasecmp(pcVar9,"wlan_info");
  if (iVar1 != 0) {
    iVar1 = strcasecmp(pcVar9,"time");
    if (iVar1 == 0) {
      local_d7c = 0;
      local_d78 = 0;
      local_d74 = 0;
      local_d70 = 0;
      local_d6c = 0;
      local_d5c = 0;
      local_d60 = 0;
      local_d64 = 0;
      local_d68 = 0;
      iVar1 = sscanf(*(char **)(param_1 + 8),"%d:%d:%d:%d:%d:%d:%d:%d",&local_d78,&local_d7c,
[32m                     &local_d70,&local_d6c,&local_d5c,&local_d60,&local_d64,&local_d68);[0m
      if (iVar1 != 8) {
        return 1;
      }
      if (0x99 < local_d7c - 1U) {
        return 1;
      }
      if (0x81 < local_d70 - 0x7b3U) {
        return 1;
      }
      if (10 < local_d6c - 2) {
        return 1;
      }
      if (0x1d < local_d5c - 2) {
        return 1;
      }
      if (0x16 < local_d60 - 1) {
        return 1;
      }
      if (0x3a < local_d64 - 1U) {
        return 1;
      }
      if (0x3a < local_d68 - 1U) {
        return 1;
      }
      local_d74 = get_real_timezone_id(3);
      cfgWrite("DATETIME","TimeZone",&local_d74,1);
      FUN_004054d4();
      FUN_004053f0(local_d70,local_d6c,local_d5c,local_d60,local_d64,local_d68);
      local_d80 = local_d80 | 0x20000;
    }
    else {
      iVar1 = strcasecmp(pcVar9,"ntpsetting");
      if (iVar1 == 0) {
        local_d6c = local_d6c & 0xffffff;
        local_d58[0] = '\0';
[32m        memset(local_d58 + 1,0,0xff);[0m
        local_d68 = 0;
        local_d64 = 0;
        local_d60 = 0;
        local_d5c = 0;
        iVar1 = sscanf(*(char **)(param_1 + 8),"%d:%d:%[^:]:%u",&local_d60,&local_d68,local_d58,
[32m                       &local_d5c);[0m
        if (iVar1 != 4) {
          return 1;
        }
        if (1 < local_d60) {
          return 1;
        }
        if (0x19 < local_d68 + 0xcU) {
          return 1;
        }
        if (1 < local_d5c) {
          return 1;
        }
        uVar6 = __floatsisf();
        local_d64 = get_real_timezone_id_by_offset(uVar6);
        if (local_d64 == -1) {
          return 1;
        }
        cfgWrite("DATETIME","TimeZone",&local_d64,1);
        cfgWrite("DATETIME","Protocol",&local_d60,1);
        cfgWrite("DATETIME","NTPServerIP",local_d58,1);
        local_d6c = local_d6c & 0xffffff | local_d5c << 0x18;
        cfgWrite("MYDLINK","LRCLockDateTime",&local_d6c,1);
        FUN_004054d4();
        if (local_d60 == 1) {
[32m          system("/etc/init.d/ntpc.sh stop 2>/dev/null 1>/dev/null");[0m
[32m          system("/usr/sbin/msger sinfo 0 sntpstate 0 0 2>/dev/null 1>/dev/null");[0m
[32m          system("/etc/init.d/ntpc.sh start 2>/dev/null 1>/dev/null");[0m
        }
        else {
[32m          system("/etc/init.d/ntpc.sh stop 2>/dev/null 1>/dev/null");[0m
        }
        local_d80 = local_d80 | 0x100000;
      }
      else {
        iVar1 = strcasecmp(pcVar9,"lrmapping");
        if (iVar1 == 0) {
[32m          sVar2 = strlen(*(char **)(param_1 + 8));[0m
[32m          pFVar3 = fopen("/mnt/flash/config/lrmapping.dat","wb");[0m
          if (pFVar3 == (FILE *)0x0) {
            return 1;
          }
[32m          sVar7 = 0;[0m
          while (0 < (int)sVar2) {
            pvVar8 = (void *)(*(int *)(param_1 + 8) + sVar7);
            *(void **)(param_1 + 8) = pvVar8;
[32m            sVar7 = fwrite(pvVar8,1,sVar2,pFVar3);[0m
            sVar2 = sVar2 - sVar7;
            if ((int)sVar7 < 1) {
              fclose(pFVar3);
              return 1;
            }
          }
          fclose(pFVar3);
          local_d80 = local_d80 | 0x200000;
        }
        else {
          iVar1 = strcasecmp(pcVar9,"lrunmapping");
          if (iVar1 == 0) {
[32m            sVar2 = strlen(*(char **)(param_1 + 8));[0m
[32m            pFVar3 = fopen("/mnt/flash/config/lrunmapping.dat","wb");[0m
            if (pFVar3 == (FILE *)0x0) {
              return 1;
            }
[32m            sVar7 = 0;[0m
            while (0 < (int)sVar2) {
              pvVar8 = (void *)(*(int *)(param_1 + 8) + sVar7);
              *(void **)(param_1 + 8) = pvVar8;
[32m              sVar7 = fwrite(pvVar8,1,sVar2,pFVar3);[0m
              sVar2 = sVar2 - sVar7;
              if ((int)sVar7 < 1) {
                fclose(pFVar3);
                return 1;
              }
            }
            fclose(pFVar3);
            local_d80 = local_d80 | 0x2000000;
          }
          else {
            iVar1 = strcasecmp(pcVar9,"lrthreshold");
            if (iVar1 == 0) {
              local_d5c = atoi(*(char **)(param_1 + 8));
              cfgWrite("MYDLINK","LRCThreshold",&local_d5c,1);
              local_d80 = local_d80 | 0x400000;
            }
            else {
              iVar1 = strcasecmp(pcVar9,"mydlink_server_availability");
              if (iVar1 == 0) {
                iVar1 = atoi(*(char **)(param_1 + 8));
                local_d6c = local_d6c & 0xffffff | iVar1 << 0x18;
                cfgWrite("MYDLINK","ServerAvailability",&local_d6c,1);
                local_d80 = local_d80 | 0x40000;
              }
              else {
                iVar1 = strcasecmp(pcVar9,"device_recording");
                if (iVar1 == 0) {
                  local_d6c = local_d6c & 0xffffff;
                  pcVar9 = *(char **)(param_1 + 8);
                  iVar1 = strcmp(pcVar9,(char *)&DAT_0040b24c);
                  if ((iVar1 != 0) && (iVar1 = strcmp(pcVar9,(char *)&DAT_0040c078), iVar1 != 0)) {
                    return 1;
                  }
                  iVar1 = atoi(pcVar9);
                  local_d6c = local_d6c & 0xffffff | iVar1 << 0x18;
                  cfgWrite("MYDLINK","LRCEnable",&local_d6c,1);
                  local_d80 = local_d80 | 0x80000;
                }
                else {
                  iVar1 = strcasecmp(pcVar9,"policy");
                  if (iVar1 == 0) {
                    if (stderr != 0) {
                      fwrite("mdbSet: Got SetDCHPolicy Request\n",1,0x21,(FILE *)stderr);
                    }
                    qryStringDecode(*(undefined4 *)(param_1 + 8));
                    iVar1 = checkSetPolicyType(*(undefined4 *)(param_1 + 8));
                    if (iVar1 == 0) {
                      SetNotifierSettingsHandle(*(undefined4 *)(param_1 + 8));
                    }
                    else if (iVar1 == 1) {
                      DoActionHandle(*(undefined4 *)(param_1 + 8));
                    }
                    else if (iVar1 == 2) {
                      SetDCHPolicyHandle(*(undefined4 *)(param_1 + 8));
[32m                      system("msger hnap_push_service 0 hreview_policy 0 0&");[0m
                    }
                    local_d80 = local_d80 | 0x800000;
                  }
                  else {
                    iVar1 = strcasecmp(pcVar9,"event");
                    if (iVar1 == 0) {
                      if (stderr != 0) {
                        fwrite("mdbSet: Got PushDCHEvent Request\n",1,0x21,(FILE *)stderr);
                      }
                      qryStringDecode(*(undefined4 *)(param_1 + 8));
                      PushDCHEventHandle(*(undefined4 *)(param_1 + 8));
                      local_d80 = local_d80 | 0x1000000;
                    }
                    else {
                      iVar1 = strcasecmp(pcVar9,"reload_http_service");
                      if (iVar1 != 0) {
                        return 1;
                      }
                      if (stderr != 0) {
                        fwrite("mdbSet: Got reload_http_service\n",1,0x20,(FILE *)stderr);
                      }
                      qryStringDecode(*(undefined4 *)(param_1 + 8));
                      iVar1 = atoi(*(char **)(param_1 + 8));
                      if (iVar1 == 1) {
                        local_d80 = local_d80 | 0x4000000;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    goto LAB_00407c5c;
  }
  qryStringDecode(*(undefined4 *)(param_1 + 8));
  FUN_00404bc0(param_1);
  local_d6c = 0xffffffff;
  local_d58[0] = '\0';
[32m  memset(local_d58 + 1,0,0x7f);[0m
  piVar10 = *(int **)(param_1 + 0xc);
  iVar1 = 0;
  if (*piVar10 < 1) {
    iVar12 = -1;
    local_40 = (char *)0xffffffff;
    iVar4 = -1;
LAB_00406f6c:
    if (iVar12 - 3U < 3) {
      if (iVar12 == 3) {
        if (local_40 == (char *)0x2) {
          local_d78 = 2;
          local_d7c = 3;
          cfgWrite("WIRELESS","Authentication",&local_d78,1);
          cfgWrite("WIRELESS","Encryption",&local_d7c,1);
          cfgWrite("WIRELESS","PreSharedKey",local_d58,1);
        }
        else if (local_40 == (char *)0x3) {
          local_d7c = 2;
          local_d78 = 2;
          cfgWrite("WIRELESS","Authentication",&local_d7c,1);
          cfgWrite("WIRELESS","Encryption",&local_d78,1);
          cfgWrite("WIRELESS","PreSharedKey",local_d58,1);
        }
        else if (local_40 == (char *)0x4) {
          local_d78 = 2;
          local_d7c = 4;
          cfgWrite("WIRELESS","Authentication",&local_d78,1);
          cfgWrite("WIRELESS","Encryption",&local_d7c,1);
          cfgWrite("WIRELESS","PreSharedKey",local_d58,1);
        }
      }
      else if (iVar12 == 4) {
        if (local_40 == (char *)0x2) {
          local_d7c = 3;
          local_d78 = 3;
          cfgWrite("WIRELESS","Authentication",&local_d7c,1);
          cfgWrite("WIRELESS","Encryption",&local_d78,1);
          cfgWrite("WIRELESS","PreSharedKey",local_d58,1);
        }
        else if (local_40 == (char *)0x3) {
          local_d78 = 3;
          local_d7c = 2;
          cfgWrite("WIRELESS","Authentication",&local_d78,1);
          cfgWrite("WIRELESS","Encryption",&local_d7c,1);
          cfgWrite("WIRELESS","PreSharedKey",local_d58,1);
        }
        else if (local_40 == (char *)0x4) {
          local_d7c = 3;
          local_d78 = 4;
          cfgWrite("WIRELESS","Authentication",&local_d7c,1);
          cfgWrite("WIRELESS","Encryption",&local_d78,1);
          cfgWrite("WIRELESS","PreSharedKey",local_d58,1);
        }
      }
      else if (iVar12 == 5) {
        local_d78 = 4;
        local_d7c = 4;
        cfgWrite("WIRELESS","Authentication",&local_d78,1);
        cfgWrite("WIRELESS","Encryption",&local_d7c,1);
        cfgWrite("WIRELESS","PreSharedKey",local_d58,1);
      }
    }
  }
  else {
    local_40 = (char *)0xffffffff;
    iVar12 = -1;
    local_3c = "E";
    local_38 = "K";
    local_34 = local_d58;
    iVar11 = -1;
    do {
      pcVar9 = (char *)piVar10[iVar1 + 1];
      iVar4 = strcasecmp(pcVar9,"M");
      if (iVar4 == 0) {
        local_d6c = atoi((char *)piVar10[iVar1 + 0x81]);
        iVar4 = iVar11;
      }
      else {
        iVar5 = strcasecmp(pcVar9,"I");
        iVar4 = iVar1;
        if (iVar5 != 0) {
          iVar4 = strcasecmp(pcVar9,"S");
          if (iVar4 == 0) {
            iVar12 = atoi((char *)piVar10[iVar1 + 0x81]);
            iVar4 = iVar11;
          }
          else {
            iVar4 = strcasecmp(pcVar9,local_3c);
            if (iVar4 == 0) {
              local_40 = (char *)atoi((char *)piVar10[iVar1 + 0x81]);
              iVar4 = iVar11;
            }
            else {
              iVar5 = strcasecmp(pcVar9,local_38);
              iVar4 = iVar11;
              if (iVar5 == 0) {
[32m[32m                strcpy(local_34,(char *)piVar10[iVar1 + 0x81]);[0m[0m
              }
            }
          }
        }
      }
      iVar1 = iVar1 + 1;
      piVar10 = *(int **)(param_1 + 0xc);
      iVar11 = iVar4;
    } while (iVar1 < *piVar10);
    if (iVar12 == 0) {
      local_d78 = 0;
      cfgWrite("WIRELESS","Encryption",&local_d78,1);
    }
    else {
      if (1 < iVar12 - 1U) goto LAB_00406f6c;
      if (iVar12 == 1) {
        if (local_40 == (char *)0x0) {
          local_d78 = 0;
          local_d7c = 1;
          local_d74 = 0;
          local_d70 = 0;
          local_c58 = '\0';
          local_c57 = 0;
          local_c56 = 0;
          local_c55 = 0;
          local_c54 = 0;
          local_c53 = 0;
          local_c52 = 0;
          local_c51 = 0;
          cfgWrite("WIRELESS","Authentication",&local_d78,1);
          cfgWrite("WIRELESS","Encryption",&local_d7c,1);
          cfgWrite("WIRELESS","WEPKeyLength",&local_d74,1);
          cfgRead("WIRELESS","WEPActiveKey",&local_d70);
[32m          sprintf(&local_c58,"WEPKey%d",local_d70);[0m
          cfgWrite("WIRELESS",&local_c58,local_d58,1);
        }
        else if (local_40 == (char *)0x1) {
          local_d70 = 0;
          local_d74 = 1;
          local_d7c = 1;
          local_d78 = 0;
          local_c58 = '\0';
          local_c57 = 0;
          local_c56 = 0;
          local_c55 = 0;
          local_c54 = 0;
          local_c53 = 0;
          local_c52 = 0;
          local_c51 = 0;
          cfgWrite("WIRELESS","Authentication",&local_d70,1);
          cfgWrite("WIRELESS","Encryption",&local_d74,1);
          cfgWrite("WIRELESS","WEPKeyLength",&local_d7c,1);
          cfgRead("WIRELESS","WEPActiveKey",&local_d78);
[32m          sprintf(&local_c58,"WEPKey%d",local_d78);[0m
          cfgWrite("WIRELESS",&local_c58,local_d58,1);
        }
      }
      else if (iVar12 == 2) {
        if (local_40 == (char *)0x0) {
          local_d78 = 1;
          local_d7c = 1;
          local_d74 = 0;
          local_d70 = 0;
          local_c58 = '\0';
          local_c57 = 0;
          local_c56 = 0;
          local_c55 = 0;
          local_c54 = 0;
          local_c53 = 0;
          local_c52 = 0;
          local_c51 = 0;
          cfgWrite("WIRELESS","Authentication",&local_d78,1);
          cfgWrite("WIRELESS","Encryption",&local_d7c,1);
          cfgWrite("WIRELESS","WEPKeyLength",&local_d74,1);
          cfgRead("WIRELESS","WEPActiveKey",&local_d70);
[32m          sprintf(&local_c58,"WEPKey%d",local_d70);[0m
          cfgWrite("WIRELESS",&local_c58,local_d58,1);
        }
        else if (local_40 == (char *)0x1) {
          local_d70 = 1;
          local_d74 = 1;
          local_d7c = 1;
          local_d78 = 0;
          local_c58 = '\0';
          local_c57 = 0;
          local_c56 = 0;
          local_c55 = 0;
          local_c54 = 0;
          local_c53 = 0;
          local_c52 = 0;
          local_c51 = 0;
          cfgWrite("WIRELESS","Authentication",&local_d70,1);
          cfgWrite("WIRELESS","Encryption",&local_d74,1);
          cfgWrite("WIRELESS","WEPKeyLength",&local_d7c,1);
          cfgRead("WIRELESS","WEPActiveKey",&local_d78);
[32m          sprintf(&local_c58,"WEPKey%d",local_d78);[0m
          cfgWrite("WIRELESS",&local_c58,local_d58,1);
        }
      }
    }
  }
  if (local_d6c != 0xffffffff) {
    cfgWrite("WIRELESS",&DAT_0040b408,&local_d6c,1);
  }
  if (iVar4 != -1) {
    cfgWrite("WIRELESS",&DAT_0040b410,
             *(undefined4 *)(*(int *)(param_1 + 0xc) + (iVar4 + 0x80) * 4 + 4),1);
  }
  local_d80 = local_d80 | 0x10000;
LAB_00407c5c:
  SIWriteInt(0x14,local_d80);
  if (stdout != (FILE *)0x0) {
    fprintf(stdout,"%d\n",1);
  }
  return 0;
}

[ASK_GPT] 588cac3f3f5e6c90
