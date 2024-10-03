
undefined4 AESEncrypt(undefined4 param_1,char *param_2,int param_3,undefined4 param_4)

{
  int __edflag;
  int iVar1;
  undefined4 uVar2;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined auStack_98 [64];
  undefined auStack_58 [68];
  
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = 0;
[32m  memset(auStack_98,0,0x40);[0m
  __edflag = FUN_00412f7c(param_1,&local_b8);
  if (__edflag == 0) {
LAB_0041324c:
    uVar2 = 1;
  }
  else {
    if (param_3 == 0) {
      strlen(param_2);
      encrypt((char *)&local_b8,__edflag);
    }
    else {
[32m      memset(auStack_58,0,0x40);[0m
      iVar1 = FUN_00412f7c(param_2,auStack_58);
      if (iVar1 == 0) goto LAB_0041324c;
      encrypt((char *)&local_b8,__edflag);
    }
    FUN_00412eb4(auStack_98,param_4,0x40);
    uVar2 = 0;
  }
  return uVar2;
}

[ASK_GPT] 6d6cb3c4ec13ba69
