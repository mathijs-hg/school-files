
void FUN_0040d47c(int *param_1)

{
  ssize_t sVar1;
  int iVar2;
  char *__nptr;
  void *pvVar3;
  int iVar4;
  size_t __size;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  char **ppcVar9;
  code *pcVar10;
  int *piVar11;
  undefined4 uVar12;
  
  if (param_1[0x202] != 0) {
    iVar2 = param_1[0x205];
    if (iVar2 == param_1[0x206]) {
      param_1[0x205] = 0;
      param_1[0x206] = 0;
    }
    else if (iVar2 != 0) {
      param_1[0x206] = iVar2;
    }
    iVar2 = param_1[0x206];
    if (iVar2 == param_1[0x207]) {
      param_1[0x207] = iVar2 + 0x1000U;
[32m[32m[32m[32m      pvVar3 = realloc((void *)param_1[0x201],iVar2 + 0x1000U);[0m[0m[0m[0m
      param_1[0x201] = (int)pvVar3;
      iVar2 = param_1[0x206];
    }
[32m    sVar1 = recv(param_1[0x209],(void *)(param_1[0x201] + iVar2),param_1[0x207] - iVar2,0);[0m
    iVar8 = param_1[0x20d];
    iVar2 = (sVar1 + param_1[0x206]) - param_1[0x205];
    iVar4 = param_1[0x20e];
    iVar7 = param_1[0x201] + param_1[0x205];
    iVar5 = *param_1;
    pcVar10 = (code *)param_1[0x20f];
    param_1[0x208] = param_1[0x208] + sVar1;
    param_1[0x206] = sVar1 + param_1[0x206];
    do {
      (*pcVar10)(param_1,iVar5,0,iVar7,param_1 + 0x205,iVar2,0,iVar8,iVar4);
      iVar5 = param_1[0x205];
      iVar4 = param_1[0x206];
      iVar2 = iVar5;
      if (iVar5 == iVar4) {
LAB_0040dbb8:
        if (((param_1[0x202] != -1) && (param_1[0x202] <= param_1[0x208])) || (sVar1 == 0)) {
          if (iVar5 == iVar2) {
            param_1[0x205] = 0;
            param_1[0x206] = 0;
          }
          (*(code *)param_1[0x20f])
                    (param_1,*param_1,0,param_1[0x201],param_1 + 0x205,param_1[0x206],0xffffffff,
                     param_1[0x20d],param_1[0x20e]);
          if ((void *)param_1[0x201] != (void *)0x0) {
            free((void *)param_1[0x201]);
            param_1[0x201] = 0;
            param_1[0x207] = 0;
          }
          param_1[0x20a] = 1;
          param_1[0x202] = 0;
          ILibLifeTime_AddEx(*(undefined4 *)(param_1[0x20c] + 0x48),param_1,1000,FUN_0040cef4,0);
        }
        if (param_1[0x205] != param_1[0x206]) {
          return;
        }
        param_1[0x206] = 0;
        param_1[0x205] = 0;
        return;
      }
      if (iVar5 == 0) {
        iVar5 = 0;
        iVar2 = iVar4;
        goto LAB_0040dbb8;
      }
[32m[32m      memcpy((void *)param_1[0x201],(void *)((int)(void *)param_1[0x201] + iVar5),iVar4 - iVar5);[0m[0m
      iVar8 = param_1[0x20d];
      iVar2 = param_1[0x206] - param_1[0x205];
      iVar4 = param_1[0x20e];
      iVar5 = *param_1;
      iVar7 = param_1[0x201];
      pcVar10 = (code *)param_1[0x20f];
      param_1[0x206] = iVar2;
      param_1[0x205] = 0;
    } while( true );
  }
[32m  sVar1 = recv(param_1[0x209],(void *)((int)param_1 + param_1[0x203] + 4),0x800 - param_1[0x203],0);[0m
  if (sVar1 == 0) {
    if (*param_1 != 0) {
      ILibDestructPacket();
    }
    if (param_1[0x207] != 0) {
      free((void *)param_1[0x201]);
    }
    param_1[0x201] = 0;
    param_1[0x207] = 0;
    *param_1 = 0;
    close(param_1[0x209]);
    param_1[0x209] = -1;
    ILibLifeTime_Remove(*(undefined4 *)(param_1[0x20c] + 0x48),param_1);
    if (param_1[0x20a] != 0) {
      return;
    }
    iVar4 = param_1[0x20d];
    iVar5 = 0;
    iVar2 = param_1[0x20e];
    uVar6 = 2;
    pcVar10 = (code *)param_1[0x20f];
    uVar12 = 0xffffffff;
    piVar11 = (int *)0x0;
LAB_0040da34:
    (*pcVar10)(param_1,iVar5,uVar6,0,piVar11,0,uVar12,iVar4,iVar2);
    return;
  }
  if (param_1[0x20a] != 0) {
    return;
  }
  iVar2 = sVar1 + param_1[0x203];
  param_1[0x203] = iVar2;
  if (iVar2 < 5) {
    return;
  }
  iVar4 = 0;
  piVar11 = param_1;
  while( true ) {
    if (iVar2 + -3 <= iVar4) {
      return;
    }
    if (((*(char *)(piVar11 + 1) == '\r') && (*(char *)((int)piVar11 + 5) == '\n')) &&
       ((*(char *)((int)piVar11 + 6) == '\r' && (*(char *)((int)piVar11 + 7) == '\n')))) break;
    iVar4 = iVar4 + 1;
    piVar11 = (int *)((int)piVar11 + 1);
  }
  iVar2 = ILibParsePacketHeader(param_1 + 1,0,iVar4 + 4);
  *param_1 = iVar2;
  if (iVar2 == 0) {
    (*(code *)param_1[0x20f])(param_1,0,0,0,0,0,0xffffffff,param_1[0x20d],param_1[0x20e]);
  }
  else {
    *(int *)(iVar2 + 0x40) = param_1[0x204];
    param_1[0x202] = -1;
    param_1[0x208] = 0;
    for (ppcVar9 = *(char ***)(*param_1 + 0x34); ppcVar9 != (char **)0x0;
        ppcVar9 = (char **)ppcVar9[5]) {
      iVar2 = strncasecmp(*ppcVar9,"CONTENT-LENGTH",0xe);
      if (iVar2 == 0) {
[32m[32m[32m        __nptr = (char *)malloc((size_t)(ppcVar9[3] + 1));[0m[0m[0m
[32m        memcpy(__nptr,ppcVar9[2],(size_t)ppcVar9[3]);[0m
        __nptr[(int)ppcVar9[3]] = '\0';
        iVar2 = atoi(__nptr);
        param_1[0x202] = iVar2;
        free(__nptr);
        break;
      }
    }
[32m    __size = param_1[0x202];[0m
    if (__size == 0xffffffff) {
[32m[32m[32m      pvVar3 = malloc(0x1000);[0m[0m[0m
      param_1[0x201] = (int)pvVar3;
      param_1[0x207] = 0x1000;
    }
    else if (__size == 0) {
      param_1[0x201] = 0;
      param_1[0x207] = 0;
    }
    else {
[32m[32m      pvVar3 = malloc(__size);[0m[0m
      param_1[0x201] = (int)pvVar3;
      param_1[0x207] = param_1[0x202];
    }
    if ((param_1[0x203] <= iVar4 + 4) || (param_1[0x202] == 0)) {
      param_1[0x205] = 0;
      param_1[0x206] = 0;
      iVar5 = *param_1;
      iVar4 = param_1[0x20d];
      iVar2 = param_1[0x20e];
      pcVar10 = (code *)param_1[0x20f];
      piVar11 = param_1 + 0x205;
      if (param_1[0x202] != 0) {
        uVar6 = 0;
        uVar12 = 0;
        goto LAB_0040da34;
      }
      (*pcVar10)(param_1,iVar5,0,0,piVar11,0,0xffffffff,iVar4,iVar2);
      param_1[0x20a] = 1;
      param_1[0x202] = 0;
      uVar6 = *(undefined4 *)(param_1[0x20c] + 0x48);
      goto LAB_0040d6a8;
    }
[32m    memcpy((void *)param_1[0x201],(void *)((int)param_1 + iVar4 + 8),(-4 - iVar4) + param_1[0x203]);[0m
    iVar2 = (-4 - iVar4) + param_1[0x203];
    param_1[0x205] = 0;
    param_1[0x206] = iVar2;
    param_1[0x208] = iVar2;
    if ((param_1[0x202] == -1) || (iVar2 < param_1[0x202])) {
      iVar5 = param_1[0x20d];
      iVar4 = param_1[0x20e];
      iVar7 = *param_1;
      iVar8 = param_1[0x201];
      pcVar10 = (code *)param_1[0x20f];
      while( true ) {
        (*pcVar10)(param_1,iVar7,0,iVar8,param_1 + 0x205,iVar2,0,iVar5,iVar4);
        iVar2 = param_1[0x205];
        if (iVar2 == param_1[0x206]) {
          return;
        }
        if (iVar2 == 0) break;
        memcpy((void *)param_1[0x201],(void *)((int)(void *)param_1[0x201] + iVar2),
[32m               param_1[0x206] - iVar2);[0m
        iVar5 = param_1[0x20d];
        iVar2 = param_1[0x206] - param_1[0x205];
        iVar4 = param_1[0x20e];
        iVar7 = *param_1;
        iVar8 = param_1[0x201];
        pcVar10 = (code *)param_1[0x20f];
        param_1[0x206] = iVar2;
        param_1[0x205] = 0;
      }
      return;
    }
    iVar8 = param_1[0x20d];
    iVar4 = param_1[0x20e];
    iVar5 = *param_1;
    iVar7 = param_1[0x201];
    pcVar10 = (code *)param_1[0x20f];
    while( true ) {
      (*pcVar10)(param_1,iVar5,0,iVar7,param_1 + 0x205,iVar2,0xffffffff,iVar8,iVar4);
      iVar2 = param_1[0x205];
      if ((iVar2 == param_1[0x206]) || (iVar2 == 0)) break;
      memcpy((void *)param_1[0x201],(void *)((int)(void *)param_1[0x201] + iVar2),
[32m             param_1[0x206] - iVar2);[0m
      iVar8 = param_1[0x20d];
      iVar2 = param_1[0x206] - param_1[0x205];
      iVar4 = param_1[0x20e];
      iVar5 = *param_1;
      iVar7 = param_1[0x201];
      pcVar10 = (code *)param_1[0x20f];
      param_1[0x206] = iVar2;
      param_1[0x205] = 0;
    }
  }
  param_1[0x202] = 0;
  if ((void *)param_1[0x201] != (void *)0x0) {
    free((void *)param_1[0x201]);
    param_1[0x201] = 0;
    param_1[0x207] = 0;
  }
  param_1[0x20a] = 1;
  uVar6 = *(undefined4 *)(param_1[0x20c] + 0x48);
LAB_0040d6a8:
  ILibLifeTime_AddEx(uVar6,param_1,1000,FUN_0040cef4,0);
  return;
}

[ASK_GPT] 6f0da4bf4df51134
