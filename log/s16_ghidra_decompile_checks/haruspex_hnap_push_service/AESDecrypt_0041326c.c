
undefined4 AESDecrypt(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined auStack_70 [64];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
[32m  memset(auStack_70,0,0x40);[0m
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  iVar1 = FUN_00412f7c(param_1,&local_30);
  if (iVar1 != 0) {
    iVar2 = FUN_00412f7c(param_2,auStack_70);
    if (iVar2 != 0) {
      FUN_00412bd8(&local_30,iVar1,auStack_70,iVar2,param_3);
      return 0;
    }
  }
  return 1;
}

[ASK_GPT] db04af27f997080e
