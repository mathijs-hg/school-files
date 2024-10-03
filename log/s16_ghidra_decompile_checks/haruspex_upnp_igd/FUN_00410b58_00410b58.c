
int ** FUN_00410b58(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  int **ppiVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  char cVar13;
  char cVar14;
  
  bVar3 = false;
  iVar12 = param_1 + param_2;
  iVar11 = 0;
[32m[32m[32m  ppiVar4 = (int **)malloc(0xc);[0m[0m[0m
  cVar13 = '\0';
  *ppiVar4 = (int *)0x0;
  ppiVar4[2] = (int *)0x0;
  iVar7 = param_3 + param_2;
  do {
    if (iVar7 <= param_2) {
[32m[32m[32m      piVar6 = (int *)malloc(0xc);[0m[0m[0m
      piVar8 = *ppiVar4;
      *piVar6 = iVar12;
      piVar6[1] = iVar11;
      piVar6[2] = 0;
      if (piVar8 == (int *)0x0) {
        ppiVar4[1] = piVar6;
        *ppiVar4 = piVar6;
      }
      else {
        ppiVar4[1][2] = (int)piVar6;
        ppiVar4[1] = piVar6;
      }
      ppiVar4[2] = (int *)((int)ppiVar4[2] + 1);
      return ppiVar4;
    }
    if (cVar13 == '\0') {
[32m      cVar1 = *(char *)(param_1 + param_2);[0m
      cVar14 = '\"';
      if (cVar1 == '\"') {
        bVar3 = true;
      }
      else {
        if (cVar1 != '\'') goto LAB_00410c24;
        bVar3 = true;
        cVar14 = '\'';
      }
    }
    else {
[32m      cVar1 = *(char *)(param_1 + param_2);[0m
      if (cVar1 == cVar13) {
        bVar3 = (bool)(bVar3 ^ 1);
        cVar13 = cVar1;
      }
LAB_00410c24:
      cVar14 = cVar13;
      if ((!bVar3) && (pcVar9 = (char *)(param_1 + param_2), param_2 + param_5 <= param_3)) {
        iVar5 = 0;
        do {
          bVar2 = param_5 <= iVar5;
          pcVar10 = (char *)(param_4 + iVar5);
          iVar5 = iVar5 + 1;
          if (bVar2) {
[32m[32m[32m            piVar6 = (int *)malloc(0xc);[0m[0m[0m
            piVar8 = *ppiVar4;
            *piVar6 = iVar12;
            piVar6[1] = iVar11;
            piVar6[2] = 0;
            if (piVar8 == (int *)0x0) {
              ppiVar4[1] = piVar6;
              *ppiVar4 = piVar6;
            }
            else {
              ppiVar4[1][2] = (int)piVar6;
              ppiVar4[1] = piVar6;
            }
            iVar12 = iVar12 + iVar11 + param_5;
            param_2 = param_2 + param_5 + -1;
            iVar11 = 0;
            ppiVar4[2] = (int *)((int)ppiVar4[2] + 1);
            goto LAB_00410ca0;
          }
          cVar1 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (*pcVar10 == cVar1);
      }
    }
    iVar11 = iVar11 + 1;
    cVar13 = cVar14;
LAB_00410ca0:
    param_2 = param_2 + 1;
  } while( true );
}

[ASK_GPT] 79b7363cf9a2973e
