
int FUN_0040423c(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  if (DAT_0046e750 == 0) {
    InitLinkedList(&DAT_0046e748,0xc);
  }
  if (param_1 < 0x400) {
    iVar1 = -0x10004;
    if (param_2 != 0) {
[32m[32m      piVar2 = (int *)malloc(0x10);[0m[0m
      if (piVar2 == (int *)0x0) {
        iVar1 = -0x10003;
      }
      else {
        piVar2[2] = param_1;
        *piVar2 = param_2;
        piVar2[1] = param_3;
        AddToTail(&DAT_0046e748,piVar2);
        iVar1 = DAT_0046e748;
        *(uint *)(&DAT_0046e6c4 + (param_1 >> 5) * 4) =
             *(uint *)(&DAT_0046e6c4 + (param_1 >> 5) * 4) | 1 << (param_1 & 0x1f);
        DAT_0046e744 = 0;
        while (iVar1 != 0) {
          piVar2 = (int *)(iVar1 + 8);
          iVar1 = *(int *)(iVar1 + 0xc);
          if (DAT_0046e744 < *piVar2) {
            DAT_0046e744 = *piVar2;
          }
        }
      }
    }
  }
  else {
    iVar1 = -0x10008;
  }
  return iVar1;
}

[ASK_GPT] 6d036c5c5537a36c
