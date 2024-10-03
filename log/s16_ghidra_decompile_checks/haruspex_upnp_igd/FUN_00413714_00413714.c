
int ** FUN_00413714(int **param_1,void *param_2,int *param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  int **ppiVar5;
  
  param_1 = (int **)*param_1;
  piVar1 = (int *)FUN_00412208(param_2,param_3);
  if (param_3 != (int *)0x0) {
    do {
      ppiVar5 = param_1;
      if (((ppiVar5[2] == piVar1) && (ppiVar5[4] == param_3)) &&
[32m         (iVar2 = memcmp(ppiVar5[3],param_2,(size_t)param_3), iVar2 == 0)) {[0m
        return ppiVar5;
      }
      param_1 = (int **)*ppiVar5;
    } while ((int **)*ppiVar5 != (int **)0x0);
    if (param_4 != 0) {
[32m[32m[32m      piVar3 = (int *)malloc(0x18);[0m[0m[0m
      *ppiVar5 = piVar3;
      piVar3[1] = 0;
      piVar3[2] = 0;
      piVar3[5] = 0;
      *piVar3 = 0;
      piVar3[3] = 0;
      piVar3[4] = 0;
      (*ppiVar5)[1] = (int)ppiVar5;
      (*ppiVar5)[2] = (int)piVar1;
      piVar1 = *ppiVar5;
[32m[32m      pvVar4 = malloc((size_t)param_3);[0m[0m
      piVar1[3] = (int)pvVar4;
[32m      memcpy((void *)(*ppiVar5)[3],param_2,(size_t)param_3);[0m
      (*ppiVar5)[4] = (int)param_3;
      return (int **)*ppiVar5;
    }
  }
  return (int **)0x0;
}

[ASK_GPT] 82c4107b41eb5cf9
