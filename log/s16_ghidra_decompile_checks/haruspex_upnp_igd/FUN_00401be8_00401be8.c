
void FUN_00401be8(void **param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  void *pvVar2;
  
[32m[32m[32m  puVar1 = (undefined4 *)malloc(8);[0m[0m[0m
  pvVar2 = *param_1;
  *param_1 = puVar1;
  puVar1[1] = pvVar2;
  *puVar1 = param_2;
  return;
}

[ASK_GPT] f7400b2604eb5259
