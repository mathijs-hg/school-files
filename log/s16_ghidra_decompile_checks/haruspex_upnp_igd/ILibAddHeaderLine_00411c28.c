
void ILibAddHeaderLine(int param_1,void *param_2,void *param_3,void *param_4,void *param_5)

{
  void **ppvVar1;
  void *pvVar2;
  int iVar3;
  
[32m[32m[32m  ppvVar1 = (void **)malloc(0x18);[0m[0m[0m
  ppvVar1[4] = (void *)0xffffffff;
[32m[32m[32m[32m  pvVar2 = malloc((int)param_3 + 1);[0m[0m[0m[0m
  *ppvVar1 = pvVar2;
[32m  memcpy(pvVar2,param_2,(size_t)param_3);[0m
  *(undefined *)((int)*ppvVar1 + (int)param_3) = 0;
  ppvVar1[1] = param_3;
[32m[32m[32m[32m  pvVar2 = malloc((int)param_5 + 1);[0m[0m[0m[0m
  ppvVar1[2] = pvVar2;
[32m  memcpy(pvVar2,param_4,(size_t)param_5);[0m
  *(undefined *)((int)ppvVar1[2] + (int)param_5) = 0;
  iVar3 = *(int *)(param_1 + 0x38);
  ppvVar1[3] = param_5;
  ppvVar1[5] = (void *)0x0;
  if (iVar3 == 0) {
    *(void ***)(param_1 + 0x34) = ppvVar1;
  }
  else {
    *(void ***)(iVar3 + 0x14) = ppvVar1;
  }
  *(void ***)(param_1 + 0x38) = ppvVar1;
  return;
}

[ASK_GPT] 87ce367f42fe4ff3
