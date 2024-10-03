
void FUN_00404c30(int param_1,char *param_2)

{
  int iVar1;
  void **ppvVar2;
  size_t sVar3;
  void *pvVar4;
  char **ppcVar5;
  
  sem_wait((sem_t *)(param_1 + 0x38));
  for (ppcVar5 = *(char ***)(param_1 + 0x24); ppcVar5 != (char **)0x0; ppcVar5 = (char **)ppcVar5[5]
      ) {
    iVar1 = strcmp(*ppcVar5,param_2);
    if (iVar1 == 0) goto LAB_00404cb8;
  }
[32m[32m[32m  ppvVar2 = (void **)malloc(0x1c);[0m[0m[0m
  ppvVar2[3] = (void *)0x0;
  sVar3 = strlen(param_2);
[32m[32m  pvVar4 = malloc(sVar3 + 1);[0m[0m
  *ppvVar2 = pvVar4;
  sVar3 = strlen(param_2);
[32m  memcpy(pvVar4,param_2,sVar3);[0m
  sVar3 = strlen(param_2);
  *(undefined *)((int)*ppvVar2 + sVar3) = 0;
  pvVar4 = *(void **)(param_1 + 0x24);
  *(void ***)(param_1 + 0x24) = ppvVar2;
  ppvVar2[4] = (void *)0x0;
  ppvVar2[1] = (void *)0x0;
  ppvVar2[5] = pvVar4;
  ppvVar2[6] = (void *)0x0;
  if (pvVar4 != (void *)0x0) {
    *(void ***)((int)pvVar4 + 0x18) = ppvVar2;
  }
LAB_00404cb8:
                    /* WARNING: Treating indirect jump as call */
  sem_post((sem_t *)(param_1 + 0x38));
  return;
}

[ASK_GPT] 62a1b7cd9ceaa64b
