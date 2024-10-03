
void ** ILibParsePacketHeader(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void **__s;
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  char *__nptr;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  void *pvVar11;
  void **ppvVar12;
  
[32m[32m[32m  __s = (void **)malloc(0x44);[0m[0m[0m
[32m  memset(__s,0,0x44);[0m
  puVar1 = (undefined4 *)ILibParseString(param_1,param_2,param_3,"\r\n",2);
  puVar9 = (undefined4 *)*puVar1;
  piVar2 = (int *)ILibParseString(*puVar9,0,puVar9[1],&DAT_00416f8c,1);
  ppvVar12 = (void **)*piVar2;
  pvVar11 = *ppvVar12;
  piVar10 = (int *)puVar9[2];
  iVar3 = memcmp(pvVar11,&DAT_00416d4c,5);
  if (iVar3 == 0) {
    iVar3 = ILibParseString(pvVar11,0,ppvVar12[1],&DAT_00416d50,1);
    __s[7] = **(void ***)(iVar3 + 4);
    __s[8] = *(void **)(*(int *)(iVar3 + 4) + 4);
    ILibDestructParserResults(iVar3);
[32m[32m[32m    __nptr = (char *)malloc(*(int *)(*(int *)(*piVar2 + 8) + 4) + 1);[0m[0m[0m
[32m    memcpy(__nptr,**(void ***)(*piVar2 + 8),(size_t)(*(void ***)(*piVar2 + 8))[1]);[0m
    __nptr[*(int *)(*(int *)(*piVar2 + 8) + 4)] = '\0';
    pvVar11 = (void *)atoi(__nptr);
    __s[4] = pvVar11;
    free(__nptr);
    __s[5] = **(void ***)(*(int *)(*piVar2 + 8) + 8);
    __s[6] = *(void **)(*(int *)(*(int *)(*piVar2 + 8) + 8) + 4);
  }
  else {
    *__s = pvVar11;
    __s[1] = *(void **)(*piVar2 + 4);
    __s[2] = **(void ***)(*piVar2 + 8);
    pvVar11 = *(void **)(*(int *)(*piVar2 + 8) + 4);
    __s[4] = (void *)0xffffffff;
    __s[3] = pvVar11;
    iVar3 = ILibParseString(*(undefined4 *)piVar2[1],0,((undefined4 *)piVar2[1])[1],&DAT_00416d50,1)
    ;
    __s[7] = **(void ***)(iVar3 + 4);
    __s[8] = *(void **)(*(int *)(iVar3 + 4) + 4);
    ILibDestructParserResults(iVar3);
    *(undefined *)((int)*__s + (int)__s[1]) = 0;
    *(undefined *)((int)__s[2] + (int)__s[3]) = 0;
  }
  do {
    ppvVar12 = __s;
    if ((piVar10 == (int *)0x0) || (piVar10[1] == 0)) goto LAB_004136d4;
[32m[32m    piVar4 = (int *)malloc(0x18);[0m[0m
    *piVar4 = 0;
    piVar4[1] = 0;
    piVar4[2] = 0;
    piVar4[3] = 0;
    piVar4[4] = 0;
    piVar4[5] = 0;
    iVar3 = 0;
    do {
      iVar8 = iVar3;
      if (piVar10[1] <= iVar8) goto LAB_004135c4;
      iVar7 = *piVar10;
      iVar3 = iVar8 + 1;
    } while (*(char *)(iVar7 + iVar8) != ':');
    piVar4[1] = iVar8;
    *piVar4 = iVar7;
    piVar4[2] = *piVar10 + iVar8 + 1;
    piVar4[3] = (piVar10[1] + -1) - iVar8;
LAB_004135c4:
    if (*piVar4 == 0) {
      ppvVar12 = (void **)0x0;
      free(__s);
LAB_004136d4:
      ILibDestructParserResults(puVar1);
      ILibDestructParserResults(piVar2);
      return ppvVar12;
    }
    iVar8 = piVar4[3] + -1;
    iVar3 = 0;
    do {
      iVar6 = iVar3;
      iVar7 = iVar8;
      if (piVar4[3] <= iVar6) {
        iVar6 = 0;
        break;
      }
      iVar3 = iVar6 + 1;
    } while (*(char *)(piVar4[2] + iVar6) == ' ');
    do {
      iVar5 = iVar7;
      iVar3 = iVar8;
      if (iVar5 < 0) break;
      iVar7 = iVar5 + -1;
      iVar3 = iVar5;
    } while (*(char *)(piVar4[2] + iVar5) == ' ');
    piVar4[2] = piVar4[2] + iVar6;
    piVar4[3] = (1 - iVar6) + iVar3;
    *(undefined *)(*piVar4 + piVar4[1]) = 0;
    *(undefined *)(piVar4[2] + piVar4[3]) = 0;
    pvVar11 = __s[0xd];
    piVar4[4] = 0;
    piVar4[5] = 0;
    if (pvVar11 == (void *)0x0) {
      __s[0xd] = piVar4;
      __s[0xe] = piVar4;
    }
    else {
      *(int **)((int)__s[0xe] + 0x14) = piVar4;
    }
    __s[0xe] = piVar4;
    piVar10 = (int *)piVar10[2];
  } while( true );
}

[ASK_GPT] 1f93006fcd3e66bb
