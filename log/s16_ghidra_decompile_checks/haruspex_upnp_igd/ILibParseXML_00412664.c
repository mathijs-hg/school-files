
int * ILibParseXML(char *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 *puVar2;
  int **ppiVar3;
  int *piVar4;
  int **ppiVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  char **ppcVar11;
  int iVar12;
  int *piVar13;
  int *piVar14;
  int *__s;
  int iVar15;
  int local_40;
  int local_3c;
  int local_38;
  
  do {
    while (((pcVar8 = param_1, cVar1 = *pcVar8, cVar1 == '\t' || (cVar1 == ' ')) || (cVar1 == '\r'))
          ) {
      param_1 = pcVar8 + 1;
    }
    param_1 = pcVar8 + 1;
  } while (cVar1 == '\n');
  __s = (int *)0x0;
  puVar2 = (undefined4 *)ILibParseString(pcVar8,param_2,param_3,&DAT_00416d44,1);
  ppcVar11 = (char **)*puVar2;
  piVar14 = (int *)0x0;
  do {
    if (ppcVar11 == (char **)0x0) {
      ILibDestructParserResults(puVar2);
      return piVar14;
    }
    pcVar8 = *ppcVar11;
    piVar13 = piVar14;
    if (*pcVar8 != '?') {
      if (*pcVar8 == '/') {
        pcVar9 = ppcVar11[1] + -1;
        *ppcVar11 = pcVar8 + 1;
        ppcVar11[1] = pcVar9;
        iVar12 = 0;
        iVar15 = 0;
        ppiVar3 = (int **)ILibParseString(pcVar8 + 1,0,pcVar9,&DAT_00416d48,1);
      }
      else {
        iVar15 = -1;
        ppiVar3 = (int **)ILibParseString(pcVar8,0,ppcVar11[1],&DAT_00416d48,1);
        iVar12 = -1;
        if (*(char *)(**ppiVar3 + (*ppiVar3)[1] + -1) != '/') {
          iVar12 = 0;
        }
      }
      piVar4 = (int *)ILibParseString(**ppiVar3,0,(*ppiVar3)[1],&DAT_00416f8c,1);
      ppiVar5 = (int **)ILibParseString(*(undefined4 *)*piVar4,0,((undefined4 *)*piVar4)[1],
                                        &DAT_00415af0,1);
      piVar7 = *ppiVar5;
      if (ppiVar5[2] == (int *)0x1) {
        iVar10 = piVar7[1];
        local_3c = 0;
        local_40 = *piVar7;
        local_38 = 0;
      }
      else {
        local_38 = *piVar7;
        local_3c = piVar7[1];
        iVar10 = ((int *)piVar7[2])[1];
        local_40 = *(int *)piVar7[2];
      }
      ILibDestructParserResults(ppiVar5);
      for (iVar6 = 0; iVar6 < iVar10; iVar6 = iVar6 + 1) {
[32m        cVar1 = *(char *)(local_40 + iVar6);[0m
        if ((((cVar1 == ' ') || (cVar1 == '/')) ||
            ((cVar1 == '>' || ((cVar1 == '\r' || (cVar1 == '\n')))))) && (iVar6 != 0)) {
          if (cVar1 == '/') {
            iVar12 = -1;
          }
          goto LAB_0041289c;
        }
      }
      iVar6 = iVar10;
      if (iVar10 != 0) {
LAB_0041289c:
[32m[32m[32m        piVar7 = (int *)malloc(0x34);[0m[0m[0m
[32m        memset(piVar7,0,0x34);[0m
        *piVar7 = local_40;
        piVar7[4] = iVar15;
        piVar7[1] = iVar6;
        piVar7[2] = local_38;
        piVar7[3] = local_3c;
        if (iVar15 == 0) {
          piVar7[6] = (int)*ppcVar11;
          do {
            iVar15 = piVar7[6];
            piVar7[6] = iVar15 + -1;
          } while (*(char *)(iVar15 + -1) == '<');
        }
        else {
          piVar7[6] = *ppiVar3[1];
        }
        piVar13 = piVar7;
        if (piVar14 != (int *)0x0) {
          __s[8] = (int)piVar7;
          piVar13 = piVar14;
        }
        __s = piVar7;
        if (iVar12 != 0) {
[32m[32m[32m          __s = (int *)malloc(0x34);[0m[0m[0m
[32m          memset(__s,0,0x34);[0m
          iVar12 = piVar7[6];
          *__s = local_40;
          __s[1] = iVar6;
          __s[2] = local_38;
          __s[6] = iVar12;
          __s[3] = local_3c;
          piVar7[8] = (int)__s;
          piVar7[5] = -1;
        }
      }
      ILibDestructParserResults(ppiVar3);
      ILibDestructParserResults(piVar4);
    }
    ppcVar11 = (char **)ppcVar11[2];
    piVar14 = piVar13;
  } while( true );
}

[ASK_GPT] 6a7a235c6636cc73
