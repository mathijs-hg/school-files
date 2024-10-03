
undefined4
FUN_00412bd8(void *param_1,size_t param_2,void *param_3,size_t param_4,undefined4 *param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
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
[32m  memcpy(local_80 + 0x10,param_1,param_2);[0m
[32m  memcpy(puVar1,param_3,param_4);[0m
  FUN_00412a5c();
  do {
    FUN_00412a2c(puVar1,&local_30);
    FUN_00412b6c(puVar1,AES_ShiftRowTab_Inv);
    FUN_00412a00(puVar1,AES_Sbox_Inv);
    FUN_00412a2c(puVar1,local_80 + 0x10);
    puVar1 = puVar1 + 4;
  } while (puVar1 != local_80 + 0x10);
  puVar1 = local_80;
  do {
    uVar4 = puVar1[1];
    uVar3 = puVar1[2];
    uVar2 = puVar1[3];
    *param_5 = *puVar1;
    param_5[1] = uVar4;
    param_5[2] = uVar3;
    param_5[3] = uVar2;
    puVar1 = puVar1 + 4;
    param_5 = param_5 + 4;
  } while (puVar1 != local_80 + 0x10);
  return 1;
}

[ASK_GPT] 7d961aa73e41a0c5
