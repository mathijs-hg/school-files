
undefined4 getTargetIPAndPort(char *param_1,char *param_2,int *param_3)

{
  size_t sVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  int iVar9;
  char local_b8 [32];
  char local_98;
  undefined auStack_97 [15];
  char local_88;
  undefined auStack_87 [31];
  char local_68;
  undefined auStack_67 [31];
  char *local_48;
  char *local_44;
  undefined *local_40;
  int local_3c;
  char *local_38;
  undefined *local_34;
  char *local_30;
  
  local_b8[0] = '\0';
[32m  memset(local_b8 + 1,0,0x1f);[0m
  if (((param_1 == (char *)0x0) || (param_2 == (char *)0x0)) || (param_3 == (int *)0x0)) {
    fprintf(stderr,"[hnap_push_service][%s] invalid parameters\n","getTargetIPAndPort");
    uVar8 = 0xffffffff;
  }
  else {
[32m[32m    strcpy(local_b8,param_1);[0m[0m
    sVar1 = strlen(local_b8);
    pcVar7 = local_b8;
    if (0 < (int)sVar1) {
      pcVar2 = pcVar7 + sVar1;
      do {
        *pcVar7 = (char)*(undefined2 *)(__ctype_toupper + *pcVar7 * 2);
        pcVar7 = pcVar7 + 1;
      } while (pcVar7 != pcVar2);
    }
    local_3c = ixmlLoadDocument("/tmp/.hnap_device_list.xml");
    if (local_3c == 0) {
      usleep(500000);
      local_3c = ixmlLoadDocument("/tmp/.hnap_device_list.xml");
      if (local_3c == 0) {
        fprintf(stderr,"[hnap_push_service][%s] load xml failed\n","getTargetIPAndPort");
        return 0xffffffff;
      }
    }
    iVar3 = ixmlElement_getElementsByTagName(local_3c,"device");
    if (iVar3 == 0) {
      fprintf(stderr,"[hnap_push_service][%s] no device list\n","getTargetIPAndPort");
      ixmlDocument_free(local_3c);
      uVar8 = 0xffffffff;
    }
    else {
      iVar4 = ixmlNodeList_length(iVar3);
      if (iVar4 < 1) {
        fprintf(stderr,"[hnap_push_service][%s] device list length 0\n","getTargetIPAndPort");
        ixmlNodeList_free(iVar3);
        ixmlDocument_free(local_3c);
        uVar8 = 0xffffffff;
      }
      else {
        iVar9 = 0;
        local_48 = &local_88;
        local_44 = &local_68;
        local_40 = &DAT_0041664c;
        local_38 = &local_98;
        local_34 = &DAT_00416650;
        local_30 = local_b8;
        do {
          local_88 = '\0';
[32m          memset(auStack_87,0,0x1f);[0m
          local_68 = '\0';
[32m          memset(auStack_67,0,0x1f);[0m
          local_98 = '\0';
[32m          memset(auStack_97,0,0xf);[0m
          iVar5 = ixmlNodeList_item(iVar3,iVar9);
          if (((iVar5 != 0) &&
              (iVar6 = ixmlGetElementValueByTag_s(iVar5,&DAT_00416648,local_48,0x20), iVar6 == 0))
             && ((iVar6 = ixmlGetElementValueByTag_s(iVar5,local_40,local_44,0x20), iVar6 == 0 &&
                 ((iVar5 = ixmlGetElementValueByTag_s(iVar5,local_34,local_38,0x10), iVar5 == 0 &&
                  (iVar5 = strcasecmp(local_30,local_48), iVar5 == 0)))))) {
[32m[32m            strcpy(param_2,&local_68);[0m[0m
            iVar4 = atoi(&local_98);
            *param_3 = iVar4;
            uVar8 = 0;
            goto LAB_0041251c;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < iVar4);
        uVar8 = 0xffffffff;
LAB_0041251c:
        ixmlNodeList_free(iVar3);
        ixmlDocument_free(local_3c);
      }
    }
  }
  return uVar8;
}

[ASK_GPT] 184d0ccd29b5aeab
