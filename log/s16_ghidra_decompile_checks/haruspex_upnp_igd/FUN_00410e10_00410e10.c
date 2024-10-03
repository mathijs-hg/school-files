
void FUN_00410e10(void **param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  void *pvVar2;
  
[32m[32m[32m  puVar1 = (undefined4 *)malloc(8);[0m[0m[0m
  pvVar2 = *param_1;
  puVar1[1] = 0;
  *puVar1 = param_2;
  if (pvVar2 == (void *)0x0) {
    param_1[1] = puVar1;
    *param_1 = puVar1;
  }
  else {
    *(undefined4 **)((int)param_1[1] + 4) = puVar1;
    param_1[1] = puVar1;
  }
  return;
}

[ASK_GPT] 3cd0608954becfa4
