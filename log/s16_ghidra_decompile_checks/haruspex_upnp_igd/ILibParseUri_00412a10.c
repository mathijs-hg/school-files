
void ILibParseUri(char *param_1,void **param_2,undefined2 *param_3,void **param_4)

{
  size_t sVar1;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  int *piVar5;
  char *__nptr;
  int iVar6;
  int iVar7;
  
  sVar1 = strlen(param_1);
[32m  iVar2 = ILibParseString(param_1,0,sVar1,&DAT_00415bb4,3);[0m
  iVar6 = (*(int **)(iVar2 + 4))[1];
  iVar7 = **(int **)(iVar2 + 4);
  piVar3 = (int *)ILibParseString(iVar7,0,iVar6,&DAT_00416d50,1);
[32m  sVar1 = iVar6 - *(int *)(*piVar3 + 4);[0m
[32m[32m[32m  pvVar4 = malloc(sVar1 + 1);[0m[0m[0m
  *param_4 = pvVar4;
[32m  memcpy(pvVar4,(void *)(iVar7 + *(int *)(*piVar3 + 4)),sVar1);[0m
  *(undefined *)((int)*param_4 + sVar1) = 0;
  piVar5 = (int *)ILibParseString(*(undefined4 *)*piVar3,0,((undefined4 *)*piVar3)[1],&DAT_00415af0,
                                  1);
  if (piVar5[2] == 1) {
    *param_3 = 0x50;
  }
  else {
[32m[32m[32m    __nptr = (char *)malloc(*(int *)(piVar5[1] + 4) + 1);[0m[0m[0m
[32m    memcpy(__nptr,*(void **)piVar5[1],(size_t)((void **)piVar5[1])[1]);[0m
    __nptr[*(int *)(piVar5[1] + 4)] = '\0';
    iVar6 = atoi(__nptr);
    *param_3 = (short)iVar6;
    free(__nptr);
  }
[32m  sVar1 = *(size_t *)(*piVar5 + 4);[0m
[32m[32m[32m  pvVar4 = malloc(sVar1 + 1);[0m[0m[0m
  *param_2 = pvVar4;
[32m  memcpy(pvVar4,*(void **)*piVar5,sVar1);[0m
  *(undefined *)((int)*param_2 + sVar1) = 0;
  ILibDestructParserResults(piVar5);
  ILibDestructParserResults(piVar3);
  ILibDestructParserResults(iVar2);
  return;
}

[ASK_GPT] 0de158477223fa0e
