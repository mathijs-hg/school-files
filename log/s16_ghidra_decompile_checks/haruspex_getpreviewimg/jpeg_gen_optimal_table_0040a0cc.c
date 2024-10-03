
void jpeg_gen_optimal_table(int *param_1,void *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  char acStack_850 [31];
  char local_831 [5];
  int local_82c [257];
  int local_428 [257];
  int iStack_24;
  
[32m  memset(acStack_850,0,0x21);[0m
[32m  memset(local_82c,0,0x404);[0m
  piVar2 = local_428;
  do {
    *piVar2 = -1;
    piVar2 = piVar2 + 1;
  } while (piVar2 != &iStack_24);
  param_3[0x100] = 1;
  iVar6 = -1;
  iVar3 = 0;
  iVar4 = 1000000000;
  do {
    iVar7 = iVar3 << 2;
    if (0x100 < iVar3) {
      iVar7 = 0;
      iVar4 = -1;
      iVar3 = 1000000000;
      piVar2 = param_3;
      do {
        iVar8 = *piVar2;
        if (((iVar8 != 0) && (iVar8 <= iVar3)) && (iVar7 != iVar6)) {
          iVar4 = iVar7;
          iVar3 = iVar8;
        }
        iVar7 = iVar7 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar7 != 0x101);
      if (iVar4 < 0) {
        piVar2 = local_82c;
        do {
          iVar6 = *piVar2;
          if (iVar6 != 0) {
            if (0x20 < iVar6) {
              *(undefined4 *)(*param_1 + 0x14) = 0x27;
              (**(code **)*param_1)(param_1);
              iVar6 = *piVar2;
            }
            acStack_850[iVar6] = acStack_850[iVar6] + '\x01';
          }
          piVar2 = piVar2 + 1;
          pcVar5 = local_831 + 1;
        } while (piVar2 != local_428);
        iVar6 = 0x1e;
        do {
          while (*pcVar5 != '\0') {
            pcVar9 = acStack_850 + iVar6;
            iVar4 = iVar6;
            while (cVar1 = *pcVar9, pcVar9 = pcVar9 + -1, cVar1 == '\0') {
              iVar4 = iVar4 + -1;
            }
            *pcVar5 = *pcVar5 + -2;
            pcVar5[-1] = pcVar5[-1] + '\x01';
            acStack_850[iVar4 + 1] = acStack_850[iVar4 + 1] + '\x02';
            acStack_850[iVar4] = acStack_850[iVar4] + -1;
          }
          iVar6 = iVar6 + -1;
          pcVar5 = pcVar5 + -1;
        } while (iVar6 != 0xe);
        iVar6 = 0x10;
        do {
          pcVar5 = acStack_850 + iVar6;
          cVar1 = *pcVar5;
          iVar6 = iVar6 + -1;
        } while (cVar1 == '\0');
        *pcVar5 = cVar1 + -1;
[32m[32m        memcpy(param_2,acStack_850,0x11);[0m[0m
        iVar4 = 1;
        iVar6 = 0;
        do {
          iVar7 = 0;
          iVar3 = iVar6;
          piVar2 = local_82c;
          do {
            iVar8 = *piVar2;
            piVar2 = piVar2 + 1;
            iVar6 = iVar3;
            if (iVar8 == iVar4) {
              iVar6 = iVar3 + 1;
              *(char *)((int)param_2 + iVar3 + 0x11) = (char)iVar7;
            }
            iVar7 = iVar7 + 1;
            iVar3 = iVar6;
          } while (iVar7 != 0x100);
          iVar4 = iVar4 + 1;
        } while (iVar4 != 0x21);
        *(undefined4 *)((int)param_2 + 0x114) = 0;
        return;
      }
      iVar3 = local_82c[iVar6];
      param_3[iVar6] = param_3[iVar6] + param_3[iVar4];
      local_82c[iVar6] = iVar3 + 1;
      param_3[iVar4] = 0;
      while( true ) {
        iVar3 = local_428[iVar6];
        if (iVar3 < 0) break;
        local_82c[iVar3] = local_82c[iVar3] + 1;
        iVar6 = iVar3;
      }
      local_428[iVar6] = iVar4;
      do {
        piVar2 = local_428 + iVar4;
        local_82c[iVar4] = local_82c[iVar4] + 1;
        iVar4 = *piVar2;
      } while (-1 < *piVar2);
      iVar3 = 0;
      iVar6 = -1;
      iVar7 = 0;
      iVar4 = 1000000000;
    }
    iVar7 = *(int *)((int)param_3 + iVar7);
    if ((iVar7 != 0) && (iVar7 <= iVar4)) {
      iVar6 = iVar3;
      iVar4 = iVar7;
    }
    iVar3 = iVar3 + 1;
  } while( true );
}

[ASK_GPT] 4ba535b4a4a78a48
