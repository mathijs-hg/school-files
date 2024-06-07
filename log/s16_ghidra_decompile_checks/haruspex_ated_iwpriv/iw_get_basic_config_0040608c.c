
/* WARNING: Could not reconcile some variable overlaps */

undefined4 iw_get_basic_config(int param_1,char *param_2,char *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined *puVar4;
  char acStack_28 [16];
  char *local_18;
  undefined4 local_14;
  
  puVar4 = &_gp;
[32m  memset(param_3,0,0xb8);[0m
[32m[32m[32m  strncpy(acStack_28,param_2,0x10);[0m[0m[0m
  iVar1 = ioctl(param_1,0x8b01,acStack_28,param_4,puVar4);
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
[32m[32m    strncpy(param_3,(char *)&local_18,0x10);[0m[0m
    param_3[0x10] = '\0';
[32m[32m[32m    strncpy(acStack_28,param_2,0x10);[0m[0m[0m
    iVar1 = ioctl(param_1,0x8b03,acStack_28);
    if (-1 < iVar1) {
      *(undefined4 *)(param_3 + 0x14) = 1;
      *(char **)(param_3 + 0x18) = local_18;
      *(uint *)(param_3 + 0x1c) = local_14;
    }
[32m[32m[32m    strncpy(acStack_28,param_2,0x10);[0m[0m[0m
    iVar1 = ioctl(param_1,0x8b05,acStack_28);
    if (-1 < iVar1) {
      *(undefined4 *)(param_3 + 0x20) = 1;
      uVar3 = iw_freq2float(&local_18);
      *(undefined8 *)(param_3 + 0x28) = uVar3;
      *(uint *)(param_3 + 0x30) = (uint)local_14._3_1_;
    }
    local_18 = param_3 + 0x38;
    local_14 = 0x40;
[32m[32m[32m    strncpy(acStack_28,param_2,0x10);[0m[0m[0m
    iVar1 = ioctl(param_1,0x8b2b,acStack_28);
    if (-1 < iVar1) {
      *(undefined4 *)(param_3 + 0x34) = 1;
      *(uint *)(param_3 + 0x78) = local_14 & 0xffff;
      *(uint *)(param_3 + 0x7c) = local_14 >> 0x10;
    }
    local_18 = param_3 + 0x88;
    local_14 = 0x21;
[32m[32m[32m    strncpy(acStack_28,param_2,0x10);[0m[0m[0m
    iVar1 = ioctl(param_1,0x8b1b,acStack_28);
    if (-1 < iVar1) {
      *(undefined4 *)(param_3 + 0x80) = 1;
      *(uint *)(param_3 + 0x84) = local_14 >> 0x10;
    }
[32m[32m[32m    strncpy(acStack_28,param_2,0x10);[0m[0m[0m
    iVar1 = ioctl(param_1,0x8b07,acStack_28);
    if (-1 < iVar1) {
      *(undefined4 *)(param_3 + 0xac) = 1;
      if (local_18 < (char *)0x7) {
        *(char **)(param_3 + 0xb0) = local_18;
      }
      else {
        *(undefined4 *)(param_3 + 0xb0) = 7;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}

[ASK_GPT] 496b221330509fdc
