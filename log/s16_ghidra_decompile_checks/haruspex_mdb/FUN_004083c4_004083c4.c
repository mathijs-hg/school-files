
int FUN_004083c4(int *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  char *__ptr;
  char *pcVar1;
  char **ppcVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  int local_818;
  undefined local_814;
  char *local_810 [510];
  
  puVar5 = &_gp;
[32m  memset(&local_818,0,0x800);[0m
  local_818 = 0x80;
  local_814 = 0x3d;
[32m  __ptr = strdup(param_2);[0m
  *param_1 = 0;
  kvparse(&local_818,__ptr,0x26,param_4,puVar5);
  ppcVar2 = local_810;
  if (0 < local_818) {
    iVar3 = 0;
    do {
      if (**ppcVar2 != '\0') {
        iVar4 = *param_1;
[32m        pcVar1 = strdup(*ppcVar2);[0m
        param_1[iVar4 + 1] = (int)pcVar1;
        iVar4 = *param_1;
[32m        pcVar1 = strdup(ppcVar2[1]);[0m
        param_1[iVar4 + 0x81] = (int)pcVar1;
        *param_1 = *param_1 + 1;
      }
      iVar3 = iVar3 + 1;
      ppcVar2 = ppcVar2 + 4;
    } while (iVar3 < local_818);
  }
  free(__ptr);
  return *param_1;
}

[ASK_GPT] c6dbed373c8c2ebb
