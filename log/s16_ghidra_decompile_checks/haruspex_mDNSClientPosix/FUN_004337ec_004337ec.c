
undefined4
FUN_004337ec(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,char *param_5,
            undefined4 param_6,undefined4 param_7,undefined param_8,undefined param_9,
            undefined4 param_10,undefined4 param_11)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  
  *(undefined4 *)(param_2 + 0x134) = param_6;
  *(undefined4 *)(param_2 + 0x138) = param_7;
[32m[32m  memcpy((void *)(param_2 + 0x13c),zeroAddr,0x14);[0m[0m
  *(undefined2 *)(param_2 + 0x254) = 0xc;
  *(undefined *)(param_2 + 600) = 1;
  *(undefined *)(param_2 + 0x25a) = param_8;
  *(undefined *)(param_2 + 0x262) = param_9;
  *(undefined4 *)(param_2 + 0x288) = param_10;
  *(undefined4 *)(param_2 + 0x28c) = param_11;
  *(undefined2 *)(param_2 + 0x256) = 1;
  *(undefined *)(param_2 + 0x259) = 0;
  *(undefined *)(param_2 + 0x25b) = 0;
  *(undefined *)(param_2 + 0x25c) = 0;
  *(undefined *)(param_2 + 0x25d) = 0;
  *(undefined *)(param_2 + 0x25e) = 0;
  *(undefined *)(param_2 + 0x263) = 0;
  *(undefined *)(param_2 + 0x264) = 0;
  *(undefined *)(param_2 + 0x25f) = 0;
  *(undefined *)(param_2 + 0x260) = 0;
  *(undefined *)(param_2 + 0x261) = 0;
  *(undefined *)(param_2 + 0x266) = 0;
  *(undefined *)(param_2 + 0xcc) = 0;
  *(undefined *)(param_2 + 0x267) = 0;
  *(undefined4 *)(param_2 + 0x284) = 0;
  *(undefined4 *)(param_2 + 0x44) = 0;
  iVar1 = ConstructServiceName(param_2 + 0x154,0,param_3,param_4);
  if (iVar1 == 0) {
    return 0xfffefffc;
  }
  if (param_5 != (char *)0x0) {
    sVar2 = mDNSPlatformStrLen(param_5);
[32m    iVar1 = AllocateAnonInfo(param_2 + 0x154,param_5,sVar2,0);[0m
    *(int *)(param_2 + 0x44) = iVar1;
    if (iVar1 == 0) {
      return 0xfffefffc;
    }
  }
  uVar3 = mDNS_StartQuery_internal(param_1,param_2);
  return uVar3;
}

[ASK_GPT] 70d19ae904022085
