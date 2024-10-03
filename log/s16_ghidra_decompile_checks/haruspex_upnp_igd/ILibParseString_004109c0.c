
int ** ILibParseString(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  char cVar1;
  bool bVar2;
  int **ppiVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  int *piVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  
  iVar9 = 0;
  iVar10 = param_1 + param_2;
[32m[32m[32m  ppiVar3 = (int **)malloc(0xc);[0m[0m[0m
  *ppiVar3 = (int *)0x0;
  ppiVar3[2] = (int *)0x0;
  do {
    if (param_3 <= param_2) {
[32m[32m[32m      piVar5 = (int *)malloc(0xc);[0m[0m[0m
      piVar7 = *ppiVar3;
      *piVar5 = iVar10;
      piVar5[1] = iVar9;
      piVar5[2] = 0;
      if (piVar7 == (int *)0x0) {
        ppiVar3[1] = piVar5;
        *ppiVar3 = piVar5;
      }
      else {
        ppiVar3[1][2] = (int)piVar5;
        ppiVar3[1] = piVar5;
      }
      ppiVar3[2] = (int *)((int)ppiVar3[2] + 1);
      return ppiVar3;
    }
    pcVar6 = (char *)(param_1 + param_2);
    if (param_2 + param_5 <= param_3) {
      iVar4 = 0;
      do {
        bVar2 = param_5 <= iVar4;
        pcVar8 = (char *)(param_4 + iVar4);
        iVar4 = iVar4 + 1;
        if (bVar2) {
[32m[32m[32m          piVar5 = (int *)malloc(0xc);[0m[0m[0m
          piVar7 = *ppiVar3;
          *piVar5 = iVar10;
          piVar5[1] = iVar9;
          piVar5[2] = 0;
          if (piVar7 == (int *)0x0) {
            ppiVar3[1] = piVar5;
            *ppiVar3 = piVar5;
          }
          else {
            ppiVar3[1][2] = (int)piVar5;
            ppiVar3[1] = piVar5;
          }
          iVar10 = iVar10 + iVar9 + param_5;
          param_2 = param_2 + param_5 + -1;
          iVar9 = 0;
          ppiVar3[2] = (int *)((int)ppiVar3[2] + 1);
          goto LAB_00410aa8;
        }
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (*pcVar8 == cVar1);
    }
    iVar9 = iVar9 + 1;
LAB_00410aa8:
    param_2 = param_2 + 1;
  } while( true );
}

[ASK_GPT] f9b2093ff547a727
