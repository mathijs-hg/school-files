
undefined4 main(int param_1,int param_2)

{
  char **ppcVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  uint local_20 [3];
  
  ppcVar1 = (char **)FUN_00404b88();
  if (param_1 - 2U < 3) {
    if (param_1 == 3) {
      pcVar4 = *(char **)(param_2 + 4);
      iVar2 = strncmp(pcVar4,"get",3);
      if ((iVar2 != 0) && (iVar2 = strncmp(pcVar4,"set",3), iVar2 != 0)) {
        FUN_00401748(&DAT_0040be54);
        FUN_00404ad4(ppcVar1);
        return 1;
      }
[32m      pcVar4 = strdup(pcVar4);[0m
      *ppcVar1 = pcVar4;
[32m      pcVar4 = strdup(*(char **)(param_2 + 8));[0m
      ppcVar1[1] = pcVar4;
      iVar2 = strncmp(*(char **)(param_2 + 4),"set",3);
      if (iVar2 == 0) {
[32m        pcVar4 = strdup("");[0m
        ppcVar1[2] = pcVar4;
      }
    }
    else if (param_1 == 4) {
      pcVar4 = *(char **)(param_2 + 4);
      iVar2 = strncmp(pcVar4,"set",3);
      if (iVar2 != 0) {
        FUN_00401748(&DAT_0040be54);
        FUN_00404ad4(ppcVar1);
        return 1;
      }
[32m      pcVar4 = strdup(pcVar4);[0m
      *ppcVar1 = pcVar4;
[32m      pcVar4 = strdup(*(char **)(param_2 + 8));[0m
      ppcVar1[1] = pcVar4;
[32m      pcVar4 = strdup(*(char **)(param_2 + 0xc));[0m
      ppcVar1[2] = pcVar4;
    }
    else if (param_1 == 2) {
      pcVar4 = *(char **)(param_2 + 4);
      iVar2 = strncmp(pcVar4,"apply",5);
      if (iVar2 != 0) {
        FUN_00401748(&DAT_0040be54);
        FUN_00404ad4(ppcVar1);
        return 1;
      }
[32m      pcVar4 = strdup(pcVar4);[0m
      *ppcVar1 = pcVar4;
    }
    pcVar4 = *ppcVar1;
    iVar2 = strcasecmp(pcVar4,"get");
    if (iVar2 == 0) {
      uVar3 = FUN_00401920(ppcVar1);
    }
    else {
      iVar2 = strcasecmp(pcVar4,"set");
      if (iVar2 == 0) {
        local_20[0] = 0;
        iVar2 = FUN_00401710();
        local_20[0] = FUN_004016d0();
        if ((iVar2 == 1) || (local_20[0] == 0x80000000)) {
          uVar3 = 1;
        }
        else {
          SIReadInt(0x14,local_20);
          local_20[0] = local_20[0] | 0x80000000;
          SIWriteInt(0x14);
          uVar3 = FUN_004057f4(ppcVar1);
          SIReadInt(0x14,local_20);
          local_20[0] = local_20[0] + 0x80000000;
          SIWriteInt(0x14);
        }
      }
      else {
        iVar2 = strcasecmp(pcVar4,"apply");
        if (iVar2 == 0) {
          uVar3 = FUN_00404e88();
        }
        else {
          uVar3 = 0;
        }
      }
    }
    FUN_00404ad4(ppcVar1);
  }
  else {
    FUN_00401748(&DAT_0040be54);
    FUN_00404ad4(ppcVar1);
    uVar3 = 1;
  }
  return uVar3;
}

[ASK_GPT] 3278dd5a126cf203
