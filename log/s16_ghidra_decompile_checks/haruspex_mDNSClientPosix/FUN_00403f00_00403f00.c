
void FUN_00403f00(short *param_1,undefined4 *param_2,short *param_3)

{
  if (*param_1 == 2) {
    *param_2 = 4;
    param_2[1] = *(undefined4 *)(param_1 + 2);
  }
  else {
    if (*param_1 != 10) {
      *param_2 = 0;
      if (param_3 == (short *)0x0) {
        return;
      }
      *param_3 = 0;
      return;
    }
    *param_2 = 6;
[32m[32m    memcpy(param_2 + 1,param_1 + 4,0x10);[0m[0m
  }
  if (param_3 != (short *)0x0) {
    *param_3 = param_1[1];
  }
  return;
}

[ASK_GPT] d5b11af27c02fcd7
