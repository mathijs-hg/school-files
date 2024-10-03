
void ILibGetRawPacket(void **param_1,void **param_2)

{
  void *pvVar1;
  undefined *puVar2;
  char *__dest;
  int iVar3;
  void *pvVar4;
  void **ppvVar5;
  void *pvVar6;
  int iVar7;
  
  if (param_1[4] == (void *)0xffffffff) {
    iVar3 = (int)param_1[1] + (int)param_1[3];
  }
  else {
    iVar3 = (int)param_1[8] + (int)param_1[6];
  }
  iVar3 = iVar3 + 0xc;
  for (pvVar1 = param_1[0xd]; pvVar1 != (void *)0x0; pvVar1 = *(void **)((int)pvVar1 + 0x14)) {
    iVar3 = iVar3 + *(int *)((int)pvVar1 + 4) + *(int *)((int)pvVar1 + 0xc) + 4;
  }
[32m[32m[32m[32m  pvVar1 = malloc((int)param_1[10] + iVar3 + 3);[0m[0m[0m[0m
  *param_2 = pvVar1;
  if (param_1[4] == (void *)0xffffffff) {
[32m    memcpy(pvVar1,*param_1,(size_t)param_1[1]);[0m
    iVar7 = (int)param_1[1] + 1;
    pvVar6 = param_1[2];
    pvVar4 = param_1[3];
    *(undefined *)((int)pvVar1 + (int)param_1[1]) = 0x20;
[32m    memcpy((void *)((int)pvVar1 + iVar7),pvVar6,(size_t)pvVar4);[0m
    iVar7 = iVar7 + (int)param_1[3];
    iVar3 = iVar7 + 6;
[32m[32m    memcpy((void *)((int)pvVar1 + iVar7)," HTTP/",6);[0m[0m
[32m    memcpy((void *)((int)pvVar1 + iVar3),param_1[7],(size_t)param_1[8]);[0m
    pvVar6 = param_1[8];
  }
  else {
[32m[32m    memcpy(pvVar1,&DAT_00416d4c,5);[0m[0m
[32m    memcpy((void *)((int)pvVar1 + 5),param_1[7],(size_t)param_1[8]);[0m
    pvVar6 = param_1[8];
[32m    iVar3 = sprintf((char *)((int)pvVar1 + (int)pvVar6 + 5)," %d ",param_1[4]);[0m
    iVar3 = iVar3 + (int)pvVar6 + 5;
[32m    memcpy((void *)((int)pvVar1 + iVar3),param_1[5],(size_t)param_1[6]);[0m
    pvVar6 = param_1[6];
  }
  iVar3 = iVar3 + (int)pvVar6;
  ((char *)((int)pvVar1 + iVar3))[1] = '\n';
  *(char *)((int)pvVar1 + iVar3) = '\r';
  ppvVar5 = (void **)param_1[0xd];
  while( true ) {
    __dest = (char *)((int)pvVar1 + iVar3 + 2);
    if (ppvVar5 == (void **)0x0) break;
[32m    memcpy(__dest,*ppvVar5,(size_t)ppvVar5[1]);[0m
    iVar3 = iVar3 + 2 + (int)ppvVar5[1];
    puVar2 = (undefined *)((int)pvVar1 + iVar3);
    *puVar2 = 0x3a;
    iVar3 = iVar3 + 2;
    puVar2[1] = 0x20;
[32m    memcpy((void *)((int)pvVar1 + iVar3),ppvVar5[2],(size_t)ppvVar5[3]);[0m
    iVar3 = iVar3 + (int)ppvVar5[3];
    *(char *)((int)pvVar1 + iVar3) = '\r';
    ((char *)((int)pvVar1 + iVar3))[1] = '\n';
    ppvVar5 = (void **)ppvVar5[5];
  }
  pvVar6 = param_1[9];
  pvVar4 = param_1[10];
  __dest[1] = '\n';
  *__dest = '\r';
[32m  memcpy((void *)((int)pvVar1 + iVar3 + 4),pvVar6,(size_t)pvVar4);[0m
  *(undefined *)((int)pvVar1 + iVar3 + 4 + (int)param_1[10]) = 0;
  return;
}

[ASK_GPT] 87a1e6ec734f159d
