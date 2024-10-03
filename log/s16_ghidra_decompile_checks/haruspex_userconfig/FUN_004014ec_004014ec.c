
undefined4 FUN_004014ec(undefined4 param_1,int param_2)

{
  char **ppcVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  size_t sVar5;
  char *__s1;
  uint uVar6;
  char *local_ad8;
  int local_ad4;
  int local_ad0;
  char local_acc [512];
  char local_8cc [1024];
  char local_4cc;
  undefined auStack_4cb [1155];
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  char *local_38;
  char *local_34;
  char *local_30;
  char *local_2c;
  
  local_ad8 = (char *)0x0;
  local_ad4 = 0;
  local_ad0 = 0;
  local_acc[0] = '\0';
[32m  memset(local_acc + 1,0,0x1ff);[0m
  local_4cc = '\0';
[32m  memset(auStack_4cb,0,0x47f);[0m
  if (param_2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    local_8cc[0] = '\0';
[32m    memset(local_8cc + 1,0,0x3ff);[0m
    CfgEnumSec("/etc/userconfig.ini",&local_ad8,0);
    __s1 = local_ad8;
    if (local_ad8 != (char *)0x0) {
LAB_004015dc:
      iVar4 = strcmp(__s1,"Restore");
      if (iVar4 != 0) goto LAB_00401814;
      CfgEnumField("/etc/userconfig.ini",__s1,&local_ad4);
      local_3c = local_ad4;
      if (local_ad4 != 0) {
        local_30 = "Restore config: [%s] [%s] = [%s]\n";
        local_2c = "%s -write \"%s\" \"%s\" \"%s\" 2>/dev/null 1>/dev/null";
        local_38 = local_8cc;
        local_34 = &local_4cc;
        do {
          local_44 = local_3c;
          CfgEnumField(param_2,local_3c,&local_ad0);
          for (local_48 = local_ad0; local_48 != 0; local_48 = *(int *)(local_48 + 0x100)) {
[32m            memset(local_acc,0,0x200);[0m
            local_40 = local_48;
            iVar4 = CfgGetField(param_2,local_44,local_48,1,local_acc,0x200);
            if (iVar4 == 0) {
[32m              memset(local_38,0,0x400);[0m
              iVar4 = 0;
              for (uVar6 = 0; sVar5 = strlen(local_acc), uVar6 < sVar5; uVar6 = uVar6 + 1) {
                cVar2 = local_acc[uVar6];
                if (((cVar2 == '\"') || (cVar2 == '`')) || (cVar2 == '\\')) {
                  local_8cc[iVar4] = '\\';
                  iVar4 = iVar4 + 1;
                }
                local_8cc[iVar4] = cVar2;
                iVar4 = iVar4 + 1;
              }
[32m              fprintf(stderr,local_30,local_44,local_40,local_acc);[0m
[32m[32m[32m              sprintf(local_34,local_2c,param_1,local_44,local_40,local_38);[0m[0m[0m
[32m[32m              system(local_34);[0m[0m
            }
          }
          ListFree(local_ad0);
          local_ad0 = 0;
          local_3c = *(int *)(local_3c + 0x100);
        } while (local_3c != 0);
      }
      ListFree(local_ad4);
      local_ad4 = 0;
    }
LAB_00401850:
    ListFree(local_ad8);
    ListFree(0);
    uVar3 = 0;
  }
  return uVar3;
LAB_00401814:
  ListFree(local_ad4);
  local_ad4 = 0;
  ListFree(local_ad0);
  local_ad0 = 0;
  ppcVar1 = (char **)(__s1 + 0x100);
  __s1 = *ppcVar1;
  if (*ppcVar1 == (char *)0x0) goto LAB_00401850;
  goto LAB_004015dc;
}

[ASK_GPT] 10f01266f5c12710
