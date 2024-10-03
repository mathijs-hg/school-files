
undefined4 FUN_0040ddc8(int *param_1)

{
  size_t sVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)param_1[6];
[32m[32m[32m  sVar1 = fread((void *)puVar2[8],1,0x1000,(FILE *)puVar2[7]);[0m[0m[0m
  if (sVar1 == 0) {
    if (puVar2[9] != 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x2a;
      (**(code **)*param_1)(param_1);
    }
    *(undefined4 *)(*param_1 + 0x14) = 0x78;
    (**(code **)(*param_1 + 4))(param_1,0xffffffff);
[32m    sVar1 = 2;[0m
    *(undefined *)puVar2[8] = 0xff;
    *(undefined *)(puVar2[8] + 1) = 0xd9;
  }
  puVar2[1] = sVar1;
  *puVar2 = puVar2[8];
  puVar2[9] = 0;
  return 1;
}

[ASK_GPT] 8e1ee62b7ebab0a5
