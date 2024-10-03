
undefined4 FUN_004042b0(int *param_1)

{
  size_t sVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)param_1[6];
[32m  sVar1 = fwrite((void *)puVar2[6],1,0x1000,(FILE *)puVar2[5]);[0m
  if (sVar1 != 0x1000) {
    *(undefined4 *)(*param_1 + 0x14) = 0x25;
    (**(code **)*param_1)(param_1);
  }
  puVar2[1] = 0x1000;
  *puVar2 = puVar2[6];
  return 1;
}

[ASK_GPT] 9aa86d5e7fefc049
