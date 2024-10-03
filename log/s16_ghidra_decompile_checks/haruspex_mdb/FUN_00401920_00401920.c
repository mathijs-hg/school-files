
/* WARNING: Could not reconcile some variable overlaps */

undefined4 FUN_00401920(int param_1)

{
  int iVar1;
  FILE *pFVar2;
  size_t sVar3;
  int iVar4;
  tm *ptVar5;
  size_t sVar6;
  uint uVar7;
  undefined4 uVar8;
  char *pcVar9;
  in_addr local_1f28;
  uint local_1f24;
  int local_1f20;
  undefined4 local_1f1c;
  int local_1f18;
  undefined4 local_1f14;
  char local_1f10;
  undefined auStack_1f0f [15];
  char local_1f00;
  undefined auStack_1eff [15];
  undefined4 local_1ef0;
  undefined4 local_1eec;
  undefined4 local_1ee8;
  undefined4 local_1ee4;
  undefined4 local_1ee0;
  undefined4 local_1edc;
  undefined4 local_1ed0;
  undefined local_1ecc;
  undefined local_1ecb;
  undefined local_1eca;
  undefined local_1ec9;
  undefined2 local_1eb0;
  undefined local_1eae;
  undefined local_1ead;
  undefined local_1eac;
  undefined local_1eab;
  undefined local_1eaa;
  undefined local_1ea9;
  char local_1e80;
  undefined auStack_1e7f [255];
  byte local_1d80;
  byte local_1d7f;
  byte local_1d7e;
  byte local_1d7d;
  byte local_1d7c;
  byte local_1d7b;
  char local_1c80;
  undefined auStack_1c7f [3];
  char acStack_1c7c [33];
  char acStack_1c5b [20];
  char acStack_1c47 [23];
  char acStack_1c30 [10];
  char acStack_1c26 [8];
  char acStack_1c1e [926];
  char local_1880;
  undefined auStack_187f [4];
  char acStack_187b [34];
  char acStack_1859 [21];
  char acStack_1844 [24];
  char acStack_182c [11];
  char acStack_1821 [9];
  char acStack_1818 [2992];
  char local_c68;
  undefined auStack_c67 [3095];
  byte *local_50;
  char *local_4c;
  char *local_48;
  char *local_44;
  char *local_40;
  char *local_3c;
  char *local_38;
  char *local_34;
  char *local_30;
  char *local_2c;
  
  pcVar9 = *(char **)(param_1 + 4);
  iVar1 = strcasecmp(pcVar9,"fw_version");
  if (iVar1 == 0) {
    local_1f24 = local_1f24 & 0xffff;
    local_1f28.s_addr = local_1f28.s_addr & 0xffff;
    local_1ed0 = local_1ed0 & 0xffffff;
[32m    memset((void *)((int)&local_1ed0 + 1),0,0xf);[0m
    local_1eb0 = (ushort)(byte)local_1eb0;
[32m    memset((void *)((int)&local_1eb0 + 1),0,0x2f);[0m
    cfgRead("System","MainVersion",&local_1f24);
    cfgRead("System","FirmwareVersion",&local_1f28);
[32m    sprintf((char *)&local_1ed0,"%u.%02d",local_1f24 >> 0x10,local_1f28.s_addr >> 0x10);[0m
    qryStringEncode(&local_1ed0,&local_1eb0);
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fputs((char *)&local_1eb0,stdout);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"hw_version");
  if (iVar1 == 0) {
    local_1880 = '\0';
[32m    memset(auStack_187f,0,0x3f);[0m
    local_1c80 = '\0';
[32m    memset(auStack_1c7f,0,0xbf);[0m
    cfgRead(&DAT_0040b128,"HWVersion",&local_1880);
    qryStringEncode(&local_1880,&local_1c80);
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fputs(&local_1c80,stdout);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"dev_model");
  if (iVar1 == 0) {
    local_1880 = '\0';
[32m    memset(auStack_187f,0,0x3f);[0m
    local_1c80 = '\0';
[32m    memset(auStack_1c7f,0,0xbf);[0m
    cfgRead("System","ModelName",&local_1880);
    qryStringEncode(&local_1880,&local_1c80);
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fputs(&local_1c80,stdout);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"dev_name");
  if (iVar1 == 0) {
    local_1880 = '\0';
[32m    memset(auStack_187f,0,0x3f);[0m
    local_1c80 = '\0';
[32m    memset(auStack_1c7f,0,0xbf);[0m
    cfgRead("CAMSYSTEM","CameraName",&local_1880);
    qryStringEncode(&local_1880,&local_1c80);
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fputs(&local_1c80,stdout);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"admin_passwd");
  if (iVar1 == 0) {
    local_1880 = '\0';
[32m    memset(auStack_187f,0,0x3f);[0m
    local_1c80 = '\0';
[32m    memset(auStack_1c7f,0,0xbf);[0m
    cfgRead("USER_ADMIN","Password1",&local_1880);
    qryStringEncode(&local_1880,&local_1c80);
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fputs(&local_1c80,stdout);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"http_port");
  if (iVar1 == 0) {
    local_1f28.s_addr = 0;
    local_1eb0 = 0;
    local_1eae = 0;
    local_1ead = 0;
    local_1eac = 0;
    local_1eab = 0;
    local_1eaa = 0;
    local_1ea9 = 0;
    cfgRead(&DAT_0040b1ac,&DAT_0040b1b4,&local_1f28);
[32m    sprintf((char *)&local_1eb0,"%d",local_1f28.s_addr);[0m
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fputs((char *)&local_1eb0,stdout);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"https_port");
  if (iVar1 == 0) {
    local_1f28.s_addr = 0;
    local_1eb0 = 0;
    local_1eae = 0;
    local_1ead = 0;
    local_1eac = 0;
    local_1eab = 0;
    local_1eaa = 0;
    local_1ea9 = 0;
    cfgRead(&DAT_0040b1c8,&DAT_0040b1b4,&local_1f28);
[32m    sprintf((char *)&local_1eb0,"%d",local_1f28.s_addr);[0m
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fputs((char *)&local_1eb0,stdout);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"register_st");
  if (iVar1 == 0) {
    local_1f28.s_addr = local_1f28.s_addr & 0xffffff;
    cfgRead("MYDLINK","RegisterStatus",&local_1f28);
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fprintf(stdout,"%u",local_1f28.s_addr >> 0x18);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"mac_addr");
  if (iVar1 == 0) {
    local_1ed0 = local_1ed0 & 0xffffff;
[32m    memset((void *)((int)&local_1ed0 + 1),0,0xf);[0m
    local_1d80 = 0;
[32m    memset(&local_1d7f,0,0xff);[0m
    net_get_hwaddr(&DAT_0040b200,&local_1d80);
    sprintf((char *)&local_1ed0,"%02X%02X%02X%02X%02X%02X",(uint)local_1d80,(uint)local_1d7f,
[32m            (uint)local_1d7e,(uint)local_1d7d,(uint)local_1d7c,(uint)local_1d7b);[0m
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fputs((char *)&local_1ed0,stdout);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"attr_0");
  if (iVar1 == 0) {
    local_1880 = '\0';
[32m    memset(auStack_187f,0,0xc17);[0m
[32m    memset(&local_1880,0,0xc18);[0m
    CfgGetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,&DAT_0040b248,1,&local_1880,0xc18);
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fputs(&local_1880,stdout);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"attr_1");
  if (iVar1 == 0) {
    local_1880 = '\0';
[32m    memset(auStack_187f,0,0xc17);[0m
[32m    memset(&local_1880,0,0xc18);[0m
    CfgGetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr1",1,&local_1880,0xc18);
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fputs(&local_1880,stdout);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"attr_2");
  if (iVar1 == 0) {
    local_1880 = '\0';
[32m    memset(auStack_187f,0,0xc17);[0m
[32m    memset(&local_1880,0,0xc18);[0m
    CfgGetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr2",1,&local_1880,0xc18);
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fputs(&local_1880,stdout);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"attr_3");
  if (iVar1 == 0) {
    local_1880 = '\0';
[32m    memset(auStack_187f,0,0xc17);[0m
[32m    memset(&local_1880,0,0xc18);[0m
    CfgGetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr3",1,&local_1880,0xc18);
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fputs(&local_1880,stdout);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"attr_4");
  if (iVar1 == 0) {
    local_1880 = '\0';
[32m    memset(auStack_187f,0,0xc17);[0m
[32m    memset(&local_1880,0,0xc18);[0m
    CfgGetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr4",1,&local_1880,0xc18);
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fputs(&local_1880,stdout);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"attr_5");
  if (iVar1 == 0) {
    local_1880 = '\0';
[32m    memset(auStack_187f,0,0xc17);[0m
[32m    memset(&local_1880,0,0xc18);[0m
    CfgGetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr5",1,&local_1880,0xc18);
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fputs(&local_1880,stdout);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"attr_6");
  if (iVar1 == 0) {
    local_1880 = '\0';
[32m    memset(auStack_187f,0,0xc17);[0m
[32m    memset(&local_1880,0,0xc18);[0m
    CfgGetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr6",1,&local_1880,0xc18);
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fputs(&local_1880,stdout);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"attr_7");
  if (iVar1 == 0) {
    local_1880 = '\0';
[32m    memset(auStack_187f,0,0xc17);[0m
[32m    memset(&local_1880,0,0xc18);[0m
    CfgGetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr7",1,&local_1880,0xc18);
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fputs(&local_1880,stdout);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"attr_8");
  if (iVar1 == 0) {
    local_1880 = '\0';
[32m    memset(auStack_187f,0,0xc17);[0m
[32m    memset(&local_1880,0,0xc18);[0m
    CfgGetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr8",1,&local_1880,0xc18);
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fputs(&local_1880,stdout);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"attr_9");
  if (iVar1 == 0) {
    local_1880 = '\0';
[32m    memset(auStack_187f,0,0xc17);[0m
[32m    memset(&local_1880,0,0xc18);[0m
    CfgGetField("/mnt/flash/config/mdbcfg.ini",&DAT_0040bf30,"attr9",1,&local_1880,0xc18);
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fputs(&local_1880,stdout);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"wan_mode");
  if (iVar1 == 0) {
    local_1f28.s_addr = 0;
    cfgRead("NETWORK_V4","BootProto",&local_1f28);
    if (local_1f28.s_addr == 0) {
      if (stdout == (FILE *)0x0) {
        return 0;
      }
      fputc(0x31,stdout);
      return 0;
    }
    if (local_1f28.s_addr == 1) {
      if (stdout == (FILE *)0x0) {
        return 0;
      }
      fputc(0x30,stdout);
      return 0;
    }
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"static_ip_info");
  if (iVar1 == 0) {
    local_1ed0 = local_1ed0 & 0xffffff;
[32m    memset((void *)((int)&local_1ed0 + 1),0,0xf);[0m
    local_1eb0 = (ushort)(byte)local_1eb0;
[32m    memset((void *)((int)&local_1eb0 + 1),0,0xf);[0m
    local_1ef0 = local_1ef0 & 0xffffff;
[32m    memset((void *)((int)&local_1ef0 + 1),0,0xf);[0m
    local_1f00 = '\0';
[32m    memset(auStack_1eff,0,0xf);[0m
    local_1f10 = '\0';
[32m    memset(auStack_1f0f,0,0xf);[0m
    local_1880 = '\0';
[32m    memset(auStack_187f,0,0x2f);[0m
    local_c68 = '\0';
[32m    memset(auStack_c67,0,0x2f);[0m
    local_1c80 = '\0';
[32m    memset(auStack_1c7f,0,0x2f);[0m
    local_1d80 = 0;
[32m    memset(&local_1d7f,0,0x2f);[0m
    local_1e80 = '\0';
[32m    memset(auStack_1e7f,0,0x2f);[0m
    cfgRead("NETWORK_V4",&DAT_0040b314,&local_1ed0);
    cfgRead("NETWORK_V4","SubnetMask",&local_1eb0);
    cfgRead("NETWORK_V4","Gateway",&local_1ef0);
    cfgRead("NETWORK_V4",&DAT_0040b32c,&local_1f00);
    cfgRead("NETWORK_V4",&DAT_0040b334,&local_1f10);
    qryStringEncode(&local_1ed0,&local_1880);
    qryStringEncode(&local_1eb0,&local_c68);
    qryStringEncode(&local_1ef0,&local_1c80);
    qryStringEncode(&local_1f00,&local_1d80);
    qryStringEncode(&local_1f10,&local_1e80);
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fprintf(stdout,"I=%s&N=%s&G=%s&D1=%s&D2=%s",&local_1880,&local_c68,&local_1c80,&local_1d80,
            &local_1e80);
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"eth_cable_st");
  if (iVar1 == 0) {
    iVar1 = net_get_carrier(&DAT_0040b368,0);
    if (stdout == (FILE *)0x0) {
      return 0;
    }
    fprintf(stdout,"%d",(uint)(0 < iVar1));
    return 0;
  }
  iVar1 = strcasecmp(pcVar9,"wlan_conn_st");
  if (iVar1 != 0) {
    iVar1 = strcasecmp(pcVar9,"cur_ip_info");
    if (iVar1 == 0) {
      local_1f10 = '\0';
[32m      memset(auStack_1f0f,0,0xf);[0m
      local_1f00 = '\0';
[32m      memset(auStack_1eff,0,0xf);[0m
      local_1ef0 = local_1ef0 & 0xffffff;
[32m      memset((void *)((int)&local_1ef0 + 1),0,0xf);[0m
      local_1eb0 = (ushort)(byte)local_1eb0;
[32m      memset((void *)((int)&local_1eb0 + 1),0,0xf);[0m
      local_1ed0 = local_1ed0 & 0xffffff;
[32m      memset((void *)((int)&local_1ed0 + 1),0,0xf);[0m
      local_1e80 = '\0';
[32m      memset(auStack_1e7f,0,0x2f);[0m
      local_1d80 = 0;
[32m      memset(&local_1d7f,0,0x2f);[0m
      local_1c80 = '\0';
[32m      memset(auStack_1c7f,0,0x2f);[0m
      local_c68 = '\0';
[32m      memset(auStack_c67,0,0x2f);[0m
      local_1880 = '\0';
[32m      memset(auStack_187f,0,0x2f);[0m
      local_1f28.s_addr = 0;
      net_get_ifaddr(&DAT_0040b200,&local_1f28);
      pcVar9 = inet_ntoa(local_1f28);
[32m[32m      strcpy(&local_1f10,pcVar9);[0m[0m
      local_1f28.s_addr = 0;
      net_get_netmask(&DAT_0040b200,&local_1f28);
      pcVar9 = inet_ntoa(local_1f28);
[32m[32m      strcpy(&local_1f00,pcVar9);[0m[0m
      local_1f28.s_addr = 0;
      net_get_gateway(&local_1f28);
      pcVar9 = inet_ntoa(local_1f28);
[32m[32m      strcpy((char *)&local_1ef0,pcVar9);[0m[0m
      local_1f28.s_addr = 0;
      net_get_dns(&local_1f28);
      pcVar9 = inet_ntoa(local_1f28);
[32m[32m      strcpy((char *)&local_1eb0,pcVar9);[0m[0m
      local_1f28.s_addr = 0;
      net_get_dns2(&local_1f28);
      pcVar9 = inet_ntoa(local_1f28);
[32m[32m      strcpy((char *)&local_1ed0,pcVar9);[0m[0m
      qryStringEncode(&local_1f10,&local_1e80);
      qryStringEncode(&local_1f00,&local_1d80);
      qryStringEncode(&local_1ef0,&local_1c80);
      qryStringEncode(&local_1eb0,&local_c68);
      qryStringEncode(&local_1ed0,&local_1880);
      if (stdout == (FILE *)0x0) {
        return 0;
      }
      fprintf(stdout,"I=%s&N=%s&G=%s&D1=%s&D2=%s",&local_1e80,&local_1d80,&local_1c80,&local_c68,
              &local_1880);
      return 0;
    }
    iVar1 = strcasecmp(pcVar9,"pppoe_info");
    if (iVar1 == 0) {
      local_1f28.s_addr = local_1f28.s_addr & 0xffffff;
      local_1880 = '\0';
[32m      memset(auStack_187f,0,0x3f);[0m
      local_c68 = '\0';
[32m      memset(auStack_c67,0,0x3f);[0m
      local_1c80 = '\0';
[32m      memset(auStack_1c7f,0,0xbf);[0m
      local_1d80 = 0;
[32m      memset(&local_1d7f,0,0xbf);[0m
      cfgRead("NETWORK_V4","PPPoEEnable",&local_1f28);
      cfgRead("NETWORK_V4","PPPoEUID",&local_1880);
      cfgRead("NETWORK_V4","PPPoEPWD",&local_c68);
      qryStringEncode(&local_1880,&local_1c80);
      qryStringEncode(&local_c68,&local_1d80);
      if (stdout == (FILE *)0x0) {
        return 0;
      }
      fprintf(stdout,"E=%u&U=%s&P=%s",local_1f28.s_addr >> 0x18,&local_1c80,&local_1d80);
      return 0;
    }
    iVar1 = strcasecmp(pcVar9,"wlan_st_info");
    if (iVar1 == 0) {
      if (stdout == (FILE *)0x0) {
        return 0;
      }
      fprintf(stdout,"E=%u",1);
      return 0;
    }
    iVar1 = strcasecmp(pcVar9,"wlan_info");
    if (iVar1 == 0) {
      local_1f28.s_addr = 0;
      local_1f24 = 0;
      local_1f20 = 0;
      local_1f1c = 0;
      local_1f18 = 0;
      local_1f14 = 0;
      local_c68 = '\0';
[32m      memset(auStack_c67,0,0x3f);[0m
      local_1ef0 = local_1ef0 & 0xffffff;
[32m      memset((void *)((int)&local_1ef0 + 1),0,0x1f);[0m
      local_1c80 = '\0';
[32m      memset(auStack_1c7f,0,0x7f);[0m
      local_1eb0 = 0;
      local_1eae = 0;
      local_1ead = 0;
      local_1eac = 0;
      local_1eab = 0;
      local_1eaa = 0;
      local_1ea9 = 0;
      local_1d80 = 0;
[32m      memset(&local_1d7f,0,0xbf);[0m
      local_1880 = '\0';
[32m      memset(auStack_187f,0,0x5f);[0m
      local_1e80 = '\0';
[32m      memset(auStack_1e7f,0,0xff);[0m
      cfgRead("WIRELESS",&DAT_0040b408,&local_1f28);
      cfgRead("WIRELESS",&DAT_0040b410,&local_c68);
      cfgRead("WIRELESS","Authentication",&local_1f24);
      cfgRead("WIRELESS","Encryption",&local_1f20);
      cfgRead("WIRELESS","WEPKeyFormat",&local_1f1c);
      cfgRead("WIRELESS","WEPKeyLength",&local_1f18);
      cfgRead("WIRELESS","WEPActiveKey",&local_1f14);
[32m      sprintf((char *)&local_1eb0,"WEPKey%d",local_1f14);[0m
      cfgRead("WIRELESS",&local_1eb0,&local_1ef0);
      cfgRead("WIRELESS","PreSharedKey",&local_1c80);
      qryStringEncode(&local_c68,&local_1d80);
      qryStringEncode(&local_1ef0,&local_1880);
      qryStringEncode(&local_1c80,&local_1e80);
      if (local_1f20 != 0) {
        if (local_1f20 == 1) {
          if (local_1f24 == 0) {
            iVar1 = 1;
          }
          else {
            iVar1 = 2;
            if (local_1f24 != 1) {
              iVar1 = -1;
            }
          }
          uVar7 = (uint)(local_1f18 != 0);
        }
        else {
          if (local_1f24 == 2) {
            iVar1 = 3;
          }
          else {
            iVar1 = 5;
            if (local_1f24 == 3) {
              iVar1 = 4;
            }
            else if (local_1f24 != 4) {
              iVar1 = -1;
            }
          }
          if (local_1f20 == 2) {
            uVar7 = 3;
          }
          else {
            uVar7 = 4;
            if (local_1f20 == 3) {
              uVar7 = 2;
            }
            else if (local_1f20 != 4) {
              uVar7 = 0xffffffff;
            }
          }
        }
        if (iVar1 != 0) {
          if (iVar1 - 1U < 2) {
            if (stdout == (FILE *)0x0) {
              return 0;
            }
            fprintf(stdout,"M=%d&I=%s&S=%d&E=%d&K=%s",local_1f28.s_addr,&local_1d80,iVar1,uVar7,
                    &local_1880);
            return 0;
          }
          if (2 < iVar1 - 3U) {
            return 0;
          }
          if (stdout == (FILE *)0x0) {
            return 0;
          }
          fprintf(stdout,"M=%d&I=%s&S=%d&E=%d&K=%s",local_1f28.s_addr,&local_1d80,iVar1,uVar7,
                  &local_1e80);
          return 0;
        }
      }
      if (stdout == (FILE *)0x0) {
        return 0;
      }
      fprintf(stdout,"M=%d&I=%s&S=%d",local_1f28.s_addr,&local_1d80,0);
      return 0;
    }
    iVar1 = strcasecmp(pcVar9,"wlan_ap_list");
    if (iVar1 != 0) {
      iVar1 = strcasecmp(pcVar9,"mdb_st");
      if (iVar1 == 0) {
        iVar1 = FUN_00401710();
        iVar4 = FUN_004016d0();
        if (iVar1 == 1) {
          uVar7 = 1;
        }
        else {
          uVar7 = (uint)(iVar4 == -0x80000000);
        }
        if (stdout == (FILE *)0x0) {
          return 0;
        }
        fprintf(stdout,"%d",uVar7);
        return 0;
      }
      iVar1 = strcasecmp(pcVar9,"time");
      if (iVar1 == 0) {
        local_1f14 = 0;
        local_1f18 = 0;
        local_1f1c = 0;
        local_1eb0 = 0;
        local_1eae = 0;
        local_1ead = 0;
        local_1eac = 0;
        local_1eab = 0;
        local_1eaa = 0;
        local_1ea9 = 0;
        cfgRead("DATETIME","TimeZone",&local_1f14);
        uVar8 = get_oem_timezone_id(3,local_1f14);
        get_timezone_info(3,uVar8,&local_1ed0);
[32m        iVar1 = sscanf((char *)(local_1ed0 + 4),"%d:%d",&local_1f18,&local_1f1c);[0m
        if (iVar1 != 2) {
          return 1;
        }
        if (*(char *)(local_1ed0 + 3) == '+') {
          if (local_1f18 == 0) {
[32m            sprintf((char *)&local_1eb0,"%d");[0m
          }
          else {
[32m            sprintf((char *)&local_1eb0,"-%d");[0m
          }
        }
        else {
[32m          sprintf((char *)&local_1eb0,"%d",local_1f18);[0m
        }
        tzset();
        time(&local_1f20);
        ptVar5 = localtime(&local_1f20);
        if (stdout == (FILE *)0x0) {
          return 0;
        }
        fprintf(stdout,"%s:%d:%.4d:%.2d:%.2d:%.2d:%.2d:%.2d",&local_1eb0,uVar8,
                ptVar5->tm_year + 0x76c,ptVar5->tm_mon + 1,ptVar5->tm_mday,ptVar5->tm_hour,
                ptVar5->tm_min,ptVar5->tm_sec);
        return 0;
      }
      iVar1 = strcasecmp(pcVar9,"ntpsetting");
      if (iVar1 == 0) {
        local_1f20 = 0;
        local_1f1c = 0;
        local_1f18 = 0;
        local_1f14 = 0;
        local_1ed0 = 0;
        local_1ecc = 0;
        local_1ecb = 0;
        local_1eca = 0;
        local_1ec9 = 0;
        local_1eb0 = 0;
        local_1eae = 0;
        local_1ead = 0;
        local_1e80 = '\0';
[32m        memset(auStack_1e7f,0,0xff);[0m
        local_1f28.s_addr = local_1f28.s_addr & 0xffffff;
        cfgRead("DATETIME","Protocol",&local_1f20);
        if (local_1f20 == 1) {
          local_1eb0 = 0x3100;
        }
        else {
          local_1eb0 = 0x3000;
        }
        cfgRead("DATETIME","TimeZone",&local_1f1c);
        uVar8 = get_oem_timezone_id(2,local_1f1c);
        get_timezone_info(2,uVar8,&local_1ef0);
[32m        iVar1 = sscanf((char *)(local_1ef0 + 4),"%d:%d",&local_1f18,&local_1f14);[0m
        if (iVar1 == 2) {
          if (*(char *)(local_1ef0 + 3) == '+') {
            if (local_1f18 == 0) {
[32m              sprintf((char *)&local_1ed0,"%d");[0m
            }
            else {
[32m              sprintf((char *)&local_1ed0,"-%d");[0m
            }
          }
          else {
[32m            sprintf((char *)&local_1ed0,"%d",local_1f18);[0m
          }
          cfgRead("DATETIME","NTPServerIP",&local_1e80);
          cfgRead("MYDLINK","LRCLockDateTime",&local_1f28);
          if (stdout == (FILE *)0x0) {
            return 0;
          }
          fprintf(stdout,"%s:%s:%s:%u",&local_1eb0,&local_1ed0,&local_1e80,local_1f28.s_addr >> 0x18
                 );
          return 0;
        }
        return 1;
      }
      iVar1 = strcasecmp(pcVar9,"lrmapping");
      if (iVar1 == 0) {
[32m        pFVar2 = fopen("/mnt/flash/config/lrmapping.dat","rb");[0m
        if (pFVar2 == (FILE *)0x0) {
          return 0;
        }
        fseek(pFVar2,0,2);
        sVar3 = ftell(pFVar2);
        rewind(pFVar2);
[32m[32m        pcVar9 = (char *)malloc(sVar3 + 1);[0m[0m
        if (pcVar9 != (char *)0x0) {
          memset(pcVar9,0,sVar3 + 1);
[32m          sVar6 = 0;[0m
          do {
            if ((int)sVar3 < 1) {
              if (stdout != (FILE *)0x0) {
                fputs(pcVar9,stdout);
              }
              fclose(pFVar2);
              free(pcVar9);
              return 0;
            }
            pcVar9 = pcVar9 + sVar6;
[32m[32m[32m            sVar6 = fread(pcVar9,1,sVar3,pFVar2);[0m[0m[0m
            sVar3 = sVar3 - sVar6;
          } while (0 < (int)sVar6);
          if (pcVar9 != (char *)0x0) {
            free(pcVar9);
          }
          fclose(pFVar2);
          return 1;
        }
        fclose(pFVar2);
        return 1;
      }
      iVar1 = strcasecmp(pcVar9,"lrunmapping");
      if (iVar1 != 0) {
        iVar1 = strcasecmp(pcVar9,"lrthreshold");
        if (iVar1 == 0) {
          local_1f14 = 0;
          cfgRead("MYDLINK","LRCThreshold",&local_1f14);
          if (stdout == (FILE *)0x0) {
            return 0;
          }
          fprintf(stdout,"%d",local_1f14);
          return 0;
        }
        iVar1 = strcasecmp(pcVar9,"ctrl_stats");
        if (iVar1 == 0) {
          local_1880 = '\0';
[32m          memset(auStack_187f,0,0x3ff);[0m
          local_c68 = '\0';
[32m          memset(auStack_c67,0,0xc17);[0m
          local_1ef0 = local_1ef0 & 0xffffff;
[32m          memset((void *)((int)&local_1ef0 + 1),0,0x1f);[0m
          local_1ed0 = local_1ed0 & 0xffffff;
[32m          memset((void *)((int)&local_1ed0 + 1),0,0x1f);[0m
          local_1eb0 = (ushort)(byte)local_1eb0;
[32m          memset((void *)((int)&local_1eb0 + 1),0,0x1f);[0m
          local_1e80 = '\0';
[32m          memset(auStack_1e7f,0,0xff);[0m
          local_1d80 = 0;
[32m          memset(&local_1d7f,0,0xff);[0m
          local_1c80 = '\0';
[32m          memset(auStack_1c7f,0,0xff);[0m
[32m          memset(&local_1880,0,0x400);[0m
          local_4c = &local_c68;
[32m          memset(local_4c,0,0xc18);[0m
[32m          memset(&local_1ef0,0,0x20);[0m
[32m          memset(&local_1ed0,0,0x20);[0m
[32m          memset(&local_1eb0,0,0x20);[0m
[32m          memset(&local_1e80,0,0x100);[0m
          local_50 = &local_1d80;
[32m          memset(local_50,0,0x100);[0m
[32m          memset(&local_1c80,0,0x100);[0m
          CfgGetField("/mnt/flash/config/hnap_module_profile.ini","Module1","NickName",1,&local_1ef0
                      ,0x20);
          CfgGetField("/mnt/flash/config/hnap_module_profile.ini","Module2","NickName",1,&local_1ed0
                      ,0x20);
          CfgGetField("/mnt/flash/config/hnap_module_profile.ini","Module3","NickName",1,&local_1eb0
                      ,0x20);
          sprintf(&local_1e80,
                  "{\"ModuleID\":\"1\",\"NickName\":\"%s\",\"OPStatus\":\"1\",\"Cat\":\"Reactor\",\"Type\":\"Camera\",\"SubType\":\"Camera Module\",\"IsBuiltIn\":\"1\"}"
[32m[32m                  ,&local_1ef0);[0m[0m
          sprintf((char *)local_50,
                  "{\"ModuleID\":\"2\",\"NickName\":\"%s\",\"OPStatus\":\"1\",\"Cat\":\"Notifier\",\"Type\":\"Optical Recognition\",\"SubType\":\"Motion Sensor\",\"IsBuiltIn\":\"1\"}"
[32m[32m                  ,&local_1ed0);[0m[0m
          sprintf(&local_1c80,
                  "{\"ModuleID\":\"3\",\"NickName\":\"%s\",\"OPStatus\":\"1\",\"Cat\":\"Notifier\",\"Type\":\"Environmental Sensor\",\"SubType\":\"Sound Detector\",\"IsBuiltIn\":\"1\"}"
[32m[32m                  ,&local_1eb0);[0m[0m
[32m[32m          sprintf(&local_1880,"{\"ModuleInfo\":[%s,%s,%s]}",&local_1e80,local_50,&local_1c80);[0m[0m
          qryStringEncode(&local_1880,local_4c);
          if (stdout == (FILE *)0x0) {
            return 0;
          }
          fputs(&local_c68,stdout);
          return 0;
        }
        iVar1 = strcasecmp(pcVar9,"mydlink_server_availability");
        if (iVar1 == 0) {
          local_1f28.s_addr = local_1f28.s_addr & 0xffffff;
          cfgRead("MYDLINK","ServerAvailability",&local_1f28);
          if (stdout == (FILE *)0x0) {
            return 0;
          }
          fprintf(stdout,"%u",local_1f28.s_addr >> 0x18);
          return 0;
        }
        iVar1 = strcasecmp(pcVar9,"device_recording");
        if (iVar1 == 0) {
          local_1f28.s_addr = local_1f28.s_addr & 0xffffff;
          cfgRead("MYDLINK","LRCEnable",&local_1f28);
          if (stdout == (FILE *)0x0) {
            return 0;
          }
          fprintf(stdout,"%u",local_1f28.s_addr >> 0x18);
          return 0;
        }
        iVar1 = strcasecmp(pcVar9,"privmode");
        if (iVar1 == 0) {
          local_1f28.s_addr = local_1f28.s_addr & 0xffffff;
          local_1f24 = local_1f24 & 0xffffff;
          cfgRead("PRIVACY_MODE","Enable",&local_1f28);
          cfgRead("PRIVACY_MODE","Manual",&local_1f24);
          if ((local_1f28.s_addr._0_1_ != '\0') && (local_1f24._0_1_ != '\0')) {
            if (stdout == (FILE *)0x0) {
              return 0;
            }
            fprintf(stdout,"%u",1);
            return 0;
          }
          if (stdout == (FILE *)0x0) {
            return 0;
          }
          fprintf(stdout,"%u",0);
          return 0;
        }
        iVar1 = strcasecmp(pcVar9,"dev_uid");
        if (iVar1 != 0) {
          return 1;
        }
        local_1ef0 = local_1ef0 & 0xffffff;
[32m        memset((void *)((int)&local_1ef0 + 1),0,0x17);[0m
[32m        system("/usr/sbin/makeDevUid 2>/dev/null 1>/dev/null");[0m
        local_1ef0 = 0;
        local_1eec = 0;
        local_1ee8 = 0;
        local_1ee4 = 0;
        local_1ee0 = 0;
        local_1edc = 0;
        CfgGetField("/mnt/flash/device/dev_unique.ini",&DAT_0040b988,"unique_id",1,&local_1ef0,0x18)
        ;
        if (stdout == (FILE *)0x0) {
          return 0;
        }
        fputs((char *)&local_1ef0,stdout);
        return 0;
      }
[32m      pFVar2 = fopen("/mnt/flash/config/lrunmapping.dat","rb");[0m
      if (pFVar2 == (FILE *)0x0) {
        return 0;
      }
      fseek(pFVar2,0,2);
      sVar3 = ftell(pFVar2);
      rewind(pFVar2);
[32m[32m      pcVar9 = (char *)malloc(sVar3 + 1);[0m[0m
      if (pcVar9 != (char *)0x0) {
        memset(pcVar9,0,sVar3 + 1);
[32m        sVar6 = 0;[0m
        do {
          if ((int)sVar3 < 1) {
            if (stdout != (FILE *)0x0) {
              fputs(pcVar9,stdout);
            }
            fclose(pFVar2);
            free(pcVar9);
            return 0;
          }
          pcVar9 = pcVar9 + sVar6;
[32m[32m[32m          sVar6 = fread(pcVar9,1,sVar3,pFVar2);[0m[0m[0m
          sVar3 = sVar3 - sVar6;
        } while (0 < (int)sVar6);
        if (pcVar9 != (char *)0x0) {
          free(pcVar9);
        }
        fclose(pFVar2);
        return 1;
      }
      fclose(pFVar2);
      return 1;
    }
    local_1c80 = '\0';
[32m    memset(auStack_1c7f,0,0x3ff);[0m
    local_1d80 = 0;
[32m    memset(&local_1d7f,0,0xbf);[0m
[32m[32m    pcVar9 = (char *)malloc(0x5554);[0m[0m
    if (pcVar9 == (char *)0x0) {
      return 1;
    }
    getSiteList(pcVar9,0x5554);
[32m    pFVar2 = tmpfile();[0m
    sVar3 = strlen(pcVar9);
    fwrite(pcVar9,sVar3,1,pFVar2);
    fseek(pFVar2,0,0);
    free(pcVar9);
    iVar1 = 0;
    local_50 = (byte *)0x40b4bc;
    local_4c = "NONE";
    local_48 = "WEP";
    local_44 = "WPAPSK/AES";
    local_40 = "WPAPSK/TKIP";
    local_3c = "WPAPSK/TKIPAES";
    local_38 = "WPA2PSK/AES";
    local_34 = "WPA2PSK/TKIP";
    local_30 = "WPA2PSK/TKIPAES";
    local_2c = "WPA1PSKWPA2PSK/AES";
    do {
      while( true ) {
        while( true ) {
[32m          pcVar9 = fgets(&local_1c80,0x400,pFVar2);[0m
          if (pcVar9 == (char *)0x0) {
            return 0;
          }
[32m          memset(&local_1880,0,0x6b);[0m
[32m[32m[32m          strncpy(&local_1880,&local_1c80,4);[0m[0m[0m
[32m[32m[32m[32m          strncpy(acStack_187b,acStack_1c7c,0x21);[0m[0m[0m[0m
[32m[32m[32m[32m          strncpy(acStack_1859,acStack_1c5b,0x14);[0m[0m[0m[0m
[32m[32m[32m[32m          strncpy(acStack_1844,acStack_1c47,0x17);[0m[0m[0m[0m
[32m[32m[32m[32m          strncpy(acStack_182c,acStack_1c30,10);[0m[0m[0m[0m
[32m[32m[32m[32m          strncpy(acStack_1821,acStack_1c26,8);[0m[0m[0m[0m
[32m[32m[32m          strncpy(acStack_1818,acStack_1c1e,2);[0m[0m[0m
          FUN_00401680(&local_1880,5);
          FUN_00401680(acStack_187b,0x22);
          FUN_00401680(acStack_1859,0x15);
          FUN_00401680(acStack_1844,0x18);
          FUN_00401680(acStack_182c,0xb);
          FUN_00401680(acStack_1821,9);
          FUN_00401680(acStack_1818,3);
          if (iVar1 != 0) break;
          iVar1 = 1;
        }
[32m        memset(&local_1d80,0,0xc0);[0m
        qryStringEncode(acStack_187b,&local_1d80);
        iVar4 = strcasecmp(acStack_1818,(char *)local_50);
        uVar7 = (uint)(iVar4 != 0);
        iVar4 = strcasecmp(acStack_1844,local_4c);
        if (iVar4 == 0) break;
        iVar4 = strcasecmp(acStack_1844,local_48);
        if (iVar4 == 0) {
          if (iVar1 < 2) {
LAB_004037a4:
            if (stdout != (FILE *)0x0) {
              fprintf(stdout,"I=%s&M=%d&C=%s&S=%d&E=%d&P=%s",&local_1d80,uVar7,&local_1880,1,0,
                      acStack_182c);
            }
          }
          else if (stdout != (FILE *)0x0) {
            fputc(0x3b,stdout);
            goto LAB_004037a4;
          }
          iVar1 = iVar1 + 1;
        }
        else {
          iVar4 = strcasecmp(acStack_1844,local_44);
          if (iVar4 == 0) {
            if (iVar1 < 2) {
LAB_00403834:
              if (stdout != (FILE *)0x0) {
                fprintf(stdout,"I=%s&M=%d&C=%s&S=%d&E=%d&P=%s",&local_1d80,uVar7,&local_1880,3,2,
                        acStack_182c);
              }
            }
            else if (stdout != (FILE *)0x0) {
              fputc(0x3b,stdout);
              goto LAB_00403834;
            }
            iVar1 = iVar1 + 1;
          }
          else {
            iVar4 = strcasecmp(acStack_1844,local_40);
            if (iVar4 == 0) {
              if (iVar1 < 2) {
LAB_004038c8:
                if (stdout != (FILE *)0x0) {
                  fprintf(stdout,"I=%s&M=%d&C=%s&S=%d&E=%d&P=%s",&local_1d80,uVar7,&local_1880,3,3,
                          acStack_182c);
                }
              }
              else if (stdout != (FILE *)0x0) {
                fputc(0x3b,stdout);
                goto LAB_004038c8;
              }
              iVar1 = iVar1 + 1;
            }
            else {
              iVar4 = strcasecmp(acStack_1844,local_3c);
              if (iVar4 == 0) {
                if (iVar1 < 2) {
LAB_00403958:
                  if (stdout != (FILE *)0x0) {
                    fprintf(stdout,"I=%s&M=%d&C=%s&S=%d&E=%d&P=%s",&local_1d80,uVar7,&local_1880,3,4
                            ,acStack_182c);
                  }
                }
                else if (stdout != (FILE *)0x0) {
                  fputc(0x3b,stdout);
                  goto LAB_00403958;
                }
                iVar1 = iVar1 + 1;
              }
              else {
                iVar4 = strcasecmp(acStack_1844,local_38);
                if (iVar4 == 0) {
                  if (iVar1 < 2) {
LAB_004039ec:
                    if (stdout != (FILE *)0x0) {
                      fprintf(stdout,"I=%s&M=%d&C=%s&S=%d&E=%d&P=%s",&local_1d80,uVar7,&local_1880,4
                              ,2,acStack_182c);
                    }
                  }
                  else if (stdout != (FILE *)0x0) {
                    fputc(0x3b,stdout);
                    goto LAB_004039ec;
                  }
                  iVar1 = iVar1 + 1;
                }
                else {
                  iVar4 = strcasecmp(acStack_1844,local_34);
                  if (iVar4 == 0) {
                    if (iVar1 < 2) {
LAB_00403a80:
                      if (stdout != (FILE *)0x0) {
                        fprintf(stdout,"I=%s&M=%d&C=%s&S=%d&E=%d&P=%s",&local_1d80,uVar7,&local_1880
                                ,4,3,acStack_182c);
                      }
                    }
                    else if (stdout != (FILE *)0x0) {
                      fputc(0x3b,stdout);
                      goto LAB_00403a80;
                    }
                    iVar1 = iVar1 + 1;
                  }
                  else {
                    iVar4 = strcasecmp(acStack_1844,local_30);
                    if (iVar4 == 0) {
                      if (iVar1 < 2) {
LAB_00403b14:
                        if (stdout != (FILE *)0x0) {
                          fprintf(stdout,"I=%s&M=%d&C=%s&S=%d&E=%d&P=%s",&local_1d80,uVar7,
                                  &local_1880,4,4,acStack_182c);
                        }
                      }
                      else if (stdout != (FILE *)0x0) {
                        fputc(0x3b,stdout);
                        goto LAB_00403b14;
                      }
                      iVar1 = iVar1 + 1;
                    }
                    else {
                      iVar4 = strcasecmp(acStack_1844,local_2c);
                      if (iVar4 == 0) {
                        if (iVar1 < 2) {
LAB_00403ba8:
                          if (stdout != (FILE *)0x0) {
                            fprintf(stdout,"I=%s&M=%d&C=%s&S=%d&E=%d&P=%s",&local_1d80,uVar7,
                                    &local_1880,5,2,acStack_182c);
                          }
                        }
                        else if (stdout != (FILE *)0x0) {
                          fputc(0x3b,stdout);
                          goto LAB_00403ba8;
                        }
                        iVar1 = iVar1 + 1;
                      }
                      else {
                        iVar4 = strcasecmp(acStack_1844,"WPA1PSKWPA2PSK/TKIP");
                        if (iVar4 == 0) {
                          if (iVar1 < 2) {
LAB_00403c40:
                            if (stdout != (FILE *)0x0) {
                              fprintf(stdout,"I=%s&M=%d&C=%s&S=%d&E=%d&P=%s",&local_1d80,uVar7,
                                      &local_1880,5,3,acStack_182c);
                            }
                          }
                          else if (stdout != (FILE *)0x0) {
                            fputc(0x3b,stdout);
                            goto LAB_00403c40;
                          }
                          iVar1 = iVar1 + 1;
                        }
                        else {
                          iVar4 = strcasecmp(acStack_1844,"WPA1PSKWPA2PSK/TKIPAES");
                          if (iVar4 == 0) {
                            if (iVar1 < 2) {
LAB_00403cd8:
                              if (stdout != (FILE *)0x0) {
                                fprintf(stdout,"I=%s&M=%d&C=%s&S=%d&E=%d&P=%s",&local_1d80,uVar7,
                                        &local_1880,5,4,acStack_182c);
                              }
                            }
                            else if (stdout != (FILE *)0x0) {
                              fputc(0x3b,stdout);
                              goto LAB_00403cd8;
                            }
                            iVar1 = iVar1 + 1;
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
      }
      if (iVar1 < 2) {
LAB_0040371c:
        if (stdout != (FILE *)0x0) {
          fprintf(stdout,"I=%s&M=%d&C=%s&S=%d&P=%s",&local_1d80,uVar7,&local_1880,0,acStack_182c);
        }
      }
      else if (stdout != (FILE *)0x0) {
        fputc(0x3b,stdout);
        goto LAB_0040371c;
      }
      iVar1 = iVar1 + 1;
    } while( true );
  }
  iVar1 = WExist();
  if (0 < iVar1) {
    iVar1 = WStatus("wlan0-vxd");
    uVar8 = 1;
    if (0 < iVar1) goto LAB_00402ae8;
  }
  uVar8 = 0;
LAB_00402ae8:
  if (stdout == (FILE *)0x0) {
    return 0;
  }
  fprintf(stdout,"%d",uVar8);
  return 0;
}

[ASK_GPT] 7283d029f54ea3f3
