
void FUN_00426808(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x28c);
  if (param_4 != 0) {
    if (*(short *)(param_3 + 2) == 1) {
      *(undefined4 *)(*(int *)(iVar1 + 0xa48) + 0x104) = 4;
      *(undefined4 *)(*(int *)(iVar1 + 0xa48) + 0x108) =
           *(undefined4 *)(*(int *)(param_3 + 0x20) + 4);
    }
    else {
      if (*(short *)(param_3 + 2) != 0x1c) {
        return;
      }
      *(undefined4 *)(*(int *)(iVar1 + 0xa48) + 0x104) = 6;
[32m[32m      memcpy((void *)(*(int *)(iVar1 + 0xa48) + 0x108),(void *)(*(int *)(param_3 + 0x20) + 4),0x10);[0m[0m
    }
    *(undefined *)(iVar1 + 0xa42) = 1;
    *(undefined4 *)(*(int *)(iVar1 + 0xa48) + 0x100) = *(undefined4 *)(param_3 + 0x18);
    if ((*(code **)(iVar1 + 0xa4c) != (code *)0x0) && (*(char *)(iVar1 + 0xa41) != '\0')) {
      *(int *)(iVar1 + 0xa44) = *(int *)(iVar1 + 0xa44) + 1;
                    /* WARNING: Could not recover jumptable at 0x004268e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar1 + 0xa4c))(param_1,iVar1);
      return;
    }
  }
  return;
}

[ASK_GPT] 422c0a8d2dba5f57
