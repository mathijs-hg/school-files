
void FUN_00404ee4(int param_1,char *param_2,char *param_3)

{
  int iVar1;
  size_t sVar2;
  char *__dest;
  char **ppcVar3;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    return;
  }
  sem_wait((sem_t *)(param_1 + 0x38));
  ppcVar3 = *(char ***)(param_1 + 0x24);
  do {
    if (ppcVar3 == (char **)0x0) {
LAB_00404fc4:
                    /* WARNING: Treating indirect jump as call */
      sem_post((sem_t *)(param_1 + 0x38));
      return;
    }
    iVar1 = strcmp(*ppcVar3,param_2);
    if (iVar1 == 0) {
      if (ppcVar3[1] != (char *)0x0) {
        free(ppcVar3[1]);
      }
      sVar2 = strlen(param_3);
[32m[32m[32m      __dest = (char *)malloc(sVar2 + 1);[0m[0m[0m
      ppcVar3[1] = __dest;
[32m[32m      strcpy(__dest,param_3);[0m[0m
      goto LAB_00404fc4;
    }
    ppcVar3 = (char **)ppcVar3[5];
  } while( true );
}

[ASK_GPT] 3f259f5e8639dded
