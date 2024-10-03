
undefined4 NotifierSettingsCheck(int param_1)

{
  int iVar1;
  char *__nptr;
  int iVar2;
  int iVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint local_5b0;
  uint local_5ac;
  undefined4 local_5a8;
  undefined4 local_5a4;
  undefined4 local_5a0;
  undefined4 local_59c;
  undefined4 local_598;
  undefined4 local_594;
  undefined4 local_590;
  undefined4 local_58c;
  char local_588;
  undefined auStack_587 [31];
  char local_568;
  undefined auStack_567 [255];
  char local_468;
  undefined auStack_467 [255];
  char local_368;
  undefined auStack_367 [255];
  char local_268;
  undefined auStack_267 [511];
  int local_68;
  undefined4 *local_64;
  int local_60;
  char *local_5c;
  char *local_58;
  time_t local_54;
  char *local_50;
  char *local_4c;
  undefined *local_48;
  char *local_44;
  char *local_40;
  undefined1 *local_3c;
  char *local_38;
  char *local_34;
  char *local_30;
  char *local_2c;
  
  local_60 = ixmlLoadDocument("/mnt/flash/config/hnap_notifier.xml");
  if (local_60 == 0) {
    iVar8 = 0;
  }
  else {
    iVar8 = ixmlDocument_getElementById(local_60,"NotifierSettingsList");
    if (iVar8 == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = ixmlElement_getElementsByTagName(iVar8,"NotifierSettings");
      if (iVar8 != 0) {
        local_68 = ixmlNodeList_length(iVar8);
        if (0 < local_68) {
          iVar6 = 0;
          iVar7 = 0;
          local_48 = &DAT_00414bc0;
          local_44 = "%02X%02X%02X%02X%02X%02X";
          local_40 = "/tmp/provision.conf";
          local_3c = &DAT_0041631c;
          local_38 = "username";
          local_34 = "%s%s%lu";
          local_30 = "\x1b[1;31mszEncryption [%s]\n\x1b[m";
          local_2c = "gw.dch.dlink.com";
          do {
            iVar1 = ixmlNodeList_item(iVar8,iVar6);
            if (((iVar1 != 0) &&
                (__nptr = (char *)ixmlGetElementValueByTag(iVar1,"ModuleID"), __nptr != (char *)0x0)
                ) && (iVar2 = atoi(__nptr), iVar2 - 2U < 2)) {
              iVar1 = ixmlDocument_getElementById(iVar1,"EnabledEventIDs");
              if (iVar1 != 0) {
                iVar7 = ixmlElement_getElementsByTagName(iVar1,&DAT_0041531c);
              }
              if ((iVar7 != 0) && (iVar1 = ixmlNodeList_length(iVar7), 0 < iVar1)) {
                iVar5 = 0;
                local_58 = "b91d2df5c5ad4b688c1b9be2a2ef791d";
                do {
                  local_568 = '\0';
[32m                  memset(auStack_567,0,0xff);[0m
                  iVar3 = ixmlNodeList_item(iVar7,iVar5);
                  if (iVar3 != 0) {
                    ixmlGetElementValueByTag_s(iVar3,&DAT_0041531c,&local_568,0x100);
                  }
                  fprintf(stderr,
                          "\x1b[1;31mevent [%d] Notifier Settings: moduleID: [%d] eventID: [%s]\n\x1b[m"
                          ,param_1,iVar2,&local_568);
                  if ((iVar2 == 2) && (iVar3 = strcmp(&local_568,"230010"), iVar3 == 0)) {
                    iVar3 = atoi(&local_568);
                    if (iVar3 == param_1) {
                      fwrite(&DAT_00415368,1,0x25,stderr);
LAB_00406db0:
                      local_268 = '\0';
[32m                      memset(auStack_267,0,0x1ff);[0m
                      local_5b0 = 0;
                      local_5ac = 0;
                      local_588 = '\0';
[32m                      memset(auStack_587,0,0x1f);[0m
                      local_5a8 = local_5a8 & 0xffffff;
[32m                      memset((void *)((int)&local_5a8 + 1),0,0xf);[0m
                      local_468 = '\0';
[32m                      memset(auStack_467,0,0xff);[0m
                      local_368 = '\0';
[32m                      memset(auStack_367,0,0xff);[0m
                      local_54 = time((time_t *)0x0);
                      local_5b0 = 0;
                      local_5ac = 0;
                      net_get_hwaddr(local_48,&local_5b0);
                      local_50 = &local_588;
                      sprintf(local_50,local_44,local_5b0 >> 0x18,local_5b0 >> 0x10 & 0xff,
                              local_5b0 >> 8 & 0xff,local_5b0 & 0xff,local_5ac >> 0x18,
[32m[32m                              local_5ac >> 0x10 & 0xff);[0m[0m
                      local_64 = &local_5a8;
                      local_5a8 = 0;
                      local_5a4 = 0;
                      local_5a0 = 0;
                      local_59c = 0;
                      CfgGetField(local_40,local_3c,local_38,1,local_64,0x10);
                      local_5c = &local_468;
                      local_4c = &local_568;
[32m[32m                      snprintf(local_5c,0x100,local_34,local_64,local_4c,local_54);[0m[0m
                      fprintf(stderr,local_30,local_5c);
                      sVar4 = strlen(local_5c);
                      hmac_md5(local_5c,sVar4,local_58,0x20,&local_598);
                      local_5c = &local_368;
[32m                      sprintf(local_5c,"%08x%08x%08x%08x",local_598,local_594,local_590,local_58c);[0m
                      local_64 = (undefined4 *)&local_268;
                      snprintf((char *)local_64,0x1ff,
                               "curl -H \"Content-Type: application/json\" -X POST -d \'{\"mac\":\"%s\",\"eid\":\"%s\",\"ts\":\"%lu\",\"hash\":\"%s\"}\' https://%s/ipcam_event -kv &"
[32m[32m                               ,local_50,local_4c,local_54,local_5c,local_2c);[0m[0m
                      fprintf(stderr,"\x1b[1;32m[%s]\n\x1b[m",local_64);
[32m[32m                      system((char *)local_64);[0m[0m
                    }
                  }
                  else if ((iVar2 == 3) && (iVar3 = strcmp(&local_568,"225810"), iVar3 == 0)) {
                    iVar3 = atoi(&local_568);
                    if (iVar3 == param_1) {
                      fwrite(&DAT_00415390,1,0x24,stderr);
                      goto LAB_00406db0;
                    }
                  }
                  iVar5 = iVar5 + 1;
                } while (iVar5 < iVar1);
              }
              ixmlNodeList_free(iVar7);
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < local_68);
        }
      }
    }
  }
  ixmlNodeList_free(iVar8);
  ixmlDocument_free(local_60);
  return 0;
}

[ASK_GPT] 29b57f26cfc552c3
