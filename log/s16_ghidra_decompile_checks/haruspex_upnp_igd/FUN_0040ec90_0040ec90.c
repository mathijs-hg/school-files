
void FUN_0040ec90(int *param_1)

{
  ssize_t sVar1;
  int iVar2;
  char *__nptr;
  void *pvVar3;
  int *piVar4;
  size_t __size;
  int iVar5;
  int iVar6;
  char **ppcVar7;
  int iVar8;
  code *pcVar9;
  
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
    iVar8 = param_1[0x20c];
    iVar2 = (sVar1 + param_1[0x206]) - param_1[0x205];
    iVar5 = *param_1;
    iVar6 = param_1[0x201] + param_1[0x205];
    pcVar9 = (code *)param_1[0x20d];
    param_1[0x208] = param_1[0x208] + sVar1;
    param_1[0x206] = sVar1 + param_1[0x206];
    do {
      (*pcVar9)(param_1,iVar5,iVar6,param_1 + 0x205,iVar2,0,iVar8);
      iVar5 = param_1[0x205];
      iVar8 = param_1[0x206];
      iVar2 = iVar5;
      if (iVar5 == iVar8) {
LAB_0040f258:
        if (((param_1[0x202] != -1) && (param_1[0x202] <= param_1[0x208])) || (sVar1 == 0)) {
          if (iVar5 == iVar2) {
            param_1[0x205] = 0;
            param_1[0x206] = 0;
          }
          (*(code *)param_1[0x20d])
                    (param_1,*param_1,param_1[0x201],param_1 + 0x205,param_1[0x206],0xffffffff,
                     param_1[0x20c]);
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
        iVar2 = iVar8;
        goto LAB_0040f258;
      }
[32m[32m      memcpy((void *)param_1[0x201],(void *)((int)(void *)param_1[0x201] + iVar5),iVar8 - iVar5);[0m[0m
      iVar5 = *param_1;
      iVar2 = param_1[0x206] - param_1[0x205];
      iVar8 = param_1[0x20c];
      iVar6 = param_1[0x201];
      pcVar9 = (code *)param_1[0x20d];
      param_1[0x206] = iVar2;
      param_1[0x205] = 0;
    } while( true );
  }
[32m  sVar1 = recv(param_1[0x209],(void *)((int)param_1 + param_1[0x203] + 4),0x800 - param_1[0x203],0);[0m
  if (sVar1 != 0) {
    iVar2 = sVar1 + param_1[0x203];
    param_1[0x203] = iVar2;
    if (iVar2 < 5) {
      return;
    }
    iVar8 = 0;
    piVar4 = param_1;
    while( true ) {
      if (iVar2 + -3 <= iVar8) {
        return;
      }
      if (((*(char *)(piVar4 + 1) == '\r') && (*(char *)((int)piVar4 + 5) == '\n')) &&
         ((*(char *)((int)piVar4 + 6) == '\r' && (*(char *)((int)piVar4 + 7) == '\n')))) break;
      iVar8 = iVar8 + 1;
      piVar4 = (int *)((int)piVar4 + 1);
    }
    iVar2 = ILibParsePacketHeader(param_1 + 1,0,iVar8 + 4);
    *param_1 = iVar2;
    *(int *)(iVar2 + 0x40) = param_1[0x204];
    param_1[0x202] = -1;
    param_1[0x208] = 0;
    for (ppcVar7 = *(char ***)(*param_1 + 0x34); ppcVar7 != (char **)0x0;
        ppcVar7 = (char **)ppcVar7[5]) {
      iVar2 = strncasecmp(*ppcVar7,"CONTENT-LENGTH",0xe);
      if (iVar2 == 0) {
[32m[32m[32m        __nptr = (char *)malloc((size_t)(ppcVar7[3] + 1));[0m[0m[0m
[32m        memcpy(__nptr,ppcVar7[2],(size_t)ppcVar7[3]);[0m
        __nptr[(int)ppcVar7[3]] = '\0';
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
    if ((iVar8 + 4 < param_1[0x203]) && (param_1[0x202] != 0)) {
      memcpy((void *)param_1[0x201],(void *)((int)param_1 + iVar8 + 8),(-4 - iVar8) + param_1[0x203]
[32m            );[0m
      iVar2 = (-4 - iVar8) + param_1[0x203];
      param_1[0x205] = 0;
      param_1[0x206] = iVar2;
      param_1[0x208] = iVar2;
      if ((param_1[0x202] != -1) && (iVar2 < param_1[0x202])) {
        iVar8 = param_1[0x20c];
        iVar5 = *param_1;
        iVar6 = param_1[0x201];
        pcVar9 = (code *)param_1[0x20d];
        while( true ) {
          (*pcVar9)(param_1,iVar5,iVar6,param_1 + 0x205,iVar2,0,iVar8);
          iVar2 = param_1[0x205];
          if (iVar2 == param_1[0x206]) {
            return;
          }
          if (iVar2 == 0) break;
          memcpy((void *)param_1[0x201],(void *)((int)(void *)param_1[0x201] + iVar2),
[32m                 param_1[0x206] - iVar2);[0m
          iVar5 = *param_1;
          iVar2 = param_1[0x206] - param_1[0x205];
          iVar8 = param_1[0x20c];
          iVar6 = param_1[0x201];
          pcVar9 = (code *)param_1[0x20d];
          param_1[0x206] = iVar2;
          param_1[0x205] = 0;
        }
        return;
      }
      iVar8 = param_1[0x20c];
      iVar5 = *param_1;
      iVar6 = param_1[0x201];
      pcVar9 = (code *)param_1[0x20d];
      while( true ) {
        (*pcVar9)(param_1,iVar5,iVar6,param_1 + 0x205,iVar2,0xffffffff,iVar8);
        iVar2 = param_1[0x205];
        if ((iVar2 == param_1[0x206]) || (iVar2 == 0)) break;
        memcpy((void *)param_1[0x201],(void *)((int)(void *)param_1[0x201] + iVar2),
[32m               param_1[0x206] - iVar2);[0m
        iVar5 = *param_1;
        iVar2 = param_1[0x206] - param_1[0x205];
        iVar8 = param_1[0x20c];
        iVar6 = param_1[0x201];
        pcVar9 = (code *)param_1[0x20d];
        param_1[0x206] = iVar2;
        param_1[0x205] = 0;
      }
    }
    else {
      param_1[0x205] = 0;
      param_1[0x206] = 0;
      if (0 < param_1[0x202]) {
        (*(code *)param_1[0x20d])(param_1,*param_1,0,param_1 + 0x205,0,0,param_1[0x20c]);
        return;
      }
      (*(code *)param_1[0x20d])(param_1,*param_1,0,param_1 + 0x205,0,0xffffffff,param_1[0x20c]);
    }
  }
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
  return;
}

[ASK_GPT] afc668108277380d
