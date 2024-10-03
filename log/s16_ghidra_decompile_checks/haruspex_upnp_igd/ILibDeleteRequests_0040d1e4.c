
void ILibDeleteRequests(int param_1,void *param_2)

{
  int iVar1;
  void **ppvVar2;
  void **ppvVar3;
  void *pvVar4;
  void **ppvVar5;
  void *pvVar6;
  void **ppvVar7;
  void **__ptr;
  int iVar8;
  int iVar9;
  
  sem_wait((sem_t *)(param_1 + 0x10));
  __ptr = (void **)0x0;
  ppvVar3 = (void **)0x0;
  iVar9 = 0;
LAB_0040d2e8:
  iVar8 = iVar9;
  if (iVar8 < *(int *)(param_1 + 0x38)) {
    iVar1 = *(int *)(param_1 + 0x3c) + iVar8 * 0x850;
    ppvVar5 = __ptr;
    ppvVar2 = ppvVar3;
    if (*(int *)(iVar1 + 0x824) != -1) goto code_r0x0040d264;
    goto LAB_0040d2e4;
  }
  ppvVar5 = *(void ***)(param_1 + 0x34);
  do {
    while( true ) {
      ppvVar2 = ppvVar5;
      if (ppvVar2 == (void **)0x0) {
        sem_post((sem_t *)(param_1 + 0x10));
        while (__ptr != (void **)0x0) {
          if ((code *)__ptr[10] != (code *)0x0) {
            (*(code *)__ptr[10])(param_1,0,4,0,0,0,0xffffffff,__ptr[8],__ptr[9]);
          }
          if (*__ptr != (void *)0x0) {
            free(*__ptr);
          }
          if (__ptr[1] != (void *)0x0) {
            free(__ptr[1]);
          }
          ppvVar3 = (void **)__ptr[0xb];
          free(__ptr);
          __ptr = ppvVar3;
        }
        return;
      }
      if (ppvVar2[8] == param_2) break;
      ppvVar5 = (void **)ppvVar2[0xb];
    }
    ppvVar7 = ppvVar2;
    if (__ptr != (void **)0x0) {
      ppvVar3[0xb] = ppvVar2;
      ppvVar7 = __ptr;
    }
    pvVar4 = ppvVar2[0xb];
    if (ppvVar2[0xc] == (void *)0x0) {
      *(void **)(param_1 + 0x34) = pvVar4;
      if (pvVar4 != (void *)0x0) {
        *(undefined4 *)((int)pvVar4 + 0x30) = 0;
        pvVar6 = *(void **)(param_1 + 0x34);
        pvVar4 = *(void **)((int)pvVar6 + 0x2c);
        if (pvVar4 != (void *)0x0) goto LAB_0040d374;
      }
    }
    else {
      *(void **)((int)ppvVar2[0xc] + 0x2c) = pvVar4;
      pvVar4 = ppvVar2[0xb];
      if (pvVar4 != (void *)0x0) {
        pvVar6 = ppvVar2[0xc];
LAB_0040d374:
        *(void **)((int)pvVar4 + 0x30) = pvVar6;
      }
    }
    ppvVar5 = (void **)ppvVar2[0xb];
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
    ppvVar2[0xc] = ppvVar3;
    ppvVar2[0xb] = (void *)0x0;
    __ptr = ppvVar7;
    ppvVar3 = ppvVar2;
  } while( true );
code_r0x0040d264:
  iVar9 = iVar8 + 1;
  if (*(void **)(iVar1 + 0x834) == param_2) {
    *(undefined4 *)(iVar1 + 0x828) = 1;
[32m[32m[32m    ppvVar2 = (void **)malloc(0x34);[0m[0m[0m
[32m    memset(ppvVar2,0,0x34);[0m
    iVar9 = *(int *)(param_1 + 0x3c) + iVar8 * 0x850;
    ppvVar2[10] = *(void **)(iVar9 + 0x83c);
    ppvVar2[8] = *(void **)(iVar9 + 0x834);
    ppvVar2[9] = *(void **)(iVar9 + 0x838);
    ppvVar5 = ppvVar2;
    if (__ptr != (void **)0x0) {
      ppvVar3[0xb] = ppvVar2;
      ppvVar5 = __ptr;
    }
LAB_0040d2e4:
    __ptr = ppvVar5;
    ppvVar3 = ppvVar2;
    iVar9 = iVar8 + 1;
  }
  goto LAB_0040d2e8;
}

[ASK_GPT] 1ce71364ada531bf
