
int FUN_00413d30(char *param_1)

{
  bool bVar1;
  int iVar2;
  size_t sVar3;
  long lVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char local_28;
  char local_27;
  undefined local_26;
  char *pcStack_24;
  
  sVar3 = strlen(param_1);
  local_26 = 0;
  iVar2 = 0;
  iVar8 = 0;
LAB_00413dec:
  iVar7 = iVar2;
  pcVar5 = param_1 + iVar8;
  if ((int)sVar3 <= iVar8) {
    return iVar7;
  }
  iVar6 = iVar8 + 1;
  if (*pcVar5 != '%') goto LAB_00413dd4;
[32m  local_27 = pcVar5[2];[0m
[32m  local_28 = pcVar5[1];[0m
  iVar6 = iVar8 + 3;
  lVar4 = strtol(&local_28,&pcStack_24,0x10);
  param_1[iVar7] = (char)lVar4;
  goto LAB_00413de0;
LAB_00413dd4:
  bVar1 = iVar8 != iVar7;
  iVar2 = iVar6;
  iVar8 = iVar6;
  if (bVar1) {
    param_1[iVar7] = *pcVar5;
LAB_00413de0:
    iVar2 = iVar7 + 1;
    iVar8 = iVar6;
  }
  goto LAB_00413dec;
}

[ASK_GPT] 687e83048abe62f3
