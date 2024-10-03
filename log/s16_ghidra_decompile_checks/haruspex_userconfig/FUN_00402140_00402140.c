
undefined4 FUN_00402140(char *param_1)

{
  char **ppcVar1;
  undefined4 uVar2;
  FILE *__stream;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  char *__s1;
  int iVar8;
  undefined auStack_238 [512];
  char *local_38;
  int local_34;
  char *local_30;
  
  uVar2 = 0xffffffff;
  if (param_1 != (char *)0x0) {
    local_34 = 0;
    local_38 = (char *)0x0;
[32m    __stream = fopen(param_1,"w");[0m
    if (__stream == (FILE *)0x0) {
      uVar2 = 0xffffffff;
    }
    else {
      CfgEnumSec("/etc/userconfig.ini",&local_38,0);
      __s1 = local_38;
      if (local_38 != (char *)0x0) {
LAB_004021d0:
        iVar3 = strcmp(__s1,"Backup");
        if (iVar3 != 0) goto LAB_00402314;
        CfgEnumField("/etc/userconfig.ini",__s1,&local_34);
        if (local_34 != 0) {
          local_30 = "[%s]\n";
          iVar3 = local_34;
          do {
            iVar4 = cfgGetGroupIndex(iVar3);
            if (-1 < iVar4) {
              fprintf(__stream,local_30,iVar3);
              iVar8 = 0;
              while (iVar5 = cfgGetItemName(iVar4,iVar8), iVar5 != 0) {
                uVar2 = cfgGetItemIndex(iVar4,iVar8);
                uVar6 = cfgGetType(uVar2);
                iVar7 = cfgReadItem(uVar2,auStack_238);
                if (iVar7 < 0) break;
                fprintf(__stream,"%s=",iVar5);
                FUN_00401fac(__stream,iVar5,uVar6,auStack_238);
                iVar8 = iVar8 + 1;
              }
            }
            iVar3 = *(int *)(iVar3 + 0x100);
          } while (iVar3 != 0);
        }
        ListFree(local_34);
        local_34 = 0;
      }
LAB_00402338:
      ListFree(local_38);
      ListFree(0);
      fclose(__stream);
      uVar2 = 0;
    }
  }
  return uVar2;
LAB_00402314:
  ListFree(local_34);
  local_34 = 0;
  ppcVar1 = (char **)(__s1 + 0x100);
  __s1 = *ppcVar1;
  if (*ppcVar1 == (char *)0x0) goto LAB_00402338;
  goto LAB_004021d0;
}

[ASK_GPT] ce8a954bcd393483
