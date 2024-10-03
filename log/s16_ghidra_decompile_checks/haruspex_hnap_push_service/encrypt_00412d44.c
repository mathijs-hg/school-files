
void encrypt(char *__block,int __edflag)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *in_a2;
  undefined4 uVar4;
  size_t in_a3;
  undefined4 *in_stack_00000010;
  undefined4 local_80 [19];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  puVar1 = local_80;
[32m  memset(puVar1,0,0x40);[0m
  local_80[16] = 0;
  local_80[17] = 0;
  local_80[18] = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
[32m[32m  memcpy(local_80 + 0x10,__block,__edflag);[0m[0m
[32m  memcpy(puVar1,in_a2,in_a3);[0m
  FUN_00412a5c();
  do {
    FUN_00412a2c(puVar1,local_80 + 0x10);
    FUN_00412a00(puVar1,&DAT_00427090);
    FUN_00412b6c(puVar1,&DAT_00427190);
    FUN_00412a2c(puVar1,&local_30);
    puVar1 = puVar1 + 4;
  } while (puVar1 != local_80 + 0x10);
  puVar1 = local_80;
  do {
    uVar4 = puVar1[1];
    uVar3 = puVar1[2];
    uVar2 = puVar1[3];
    *in_stack_00000010 = *puVar1;
    in_stack_00000010[1] = uVar4;
    in_stack_00000010[2] = uVar3;
    in_stack_00000010[3] = uVar2;
    puVar1 = puVar1 + 4;
    in_stack_00000010 = in_stack_00000010 + 4;
  } while (puVar1 != local_80 + 0x10);
  return;
}

[ASK_GPT] b5f5629266b448be
