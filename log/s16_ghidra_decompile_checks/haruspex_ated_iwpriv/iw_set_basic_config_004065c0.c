
/* WARNING: Could not reconcile some variable overlaps */

undefined4 iw_set_basic_config(int param_1,char *param_2,int param_3)

{
  FILE *pFVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  uint uVar6;
  size_t sVar7;
  undefined4 local_b8;
  char acStack_3c [16];
  int local_2c;
  undefined4 local_28;
  
  local_b8 = 0;
[32m[32m[32m  strncpy(acStack_3c,param_2,0x10);[0m[0m[0m
  iVar3 = ioctl(param_1,0x8b01,acStack_3c);
  if (iVar3 < 0) {
    local_b8 = 0xfffffffe;
  }
  else {
    if (*(int *)(param_3 + 0xac) != 0) {
[32m[32m[32m      strncpy(acStack_3c,param_2,0x10);[0m[0m[0m
      local_2c = *(int *)(param_3 + 0xb0);
[32m[32m[32m      strncpy(acStack_3c,param_2,0x10);[0m[0m[0m
      iVar3 = ioctl(param_1,0x8b06,acStack_3c);
      pFVar1 = stderr;
      if (iVar3 < 0) {
        piVar4 = __errno_location();
        pcVar5 = strerror(*piVar4);
        fprintf(pFVar1,"SIOCSIWMODE: %s\n",pcVar5);
        local_b8 = 0xffffffff;
      }
    }
    if (*(int *)(param_3 + 0x20) != 0) {
      iw_float2freq(*(undefined4 *)(param_3 + 0x28),*(undefined4 *)(param_3 + 0x2c),&local_2c);
[32m[32m[32m      strncpy(acStack_3c,param_2,0x10);[0m[0m[0m
      iVar3 = ioctl(param_1,0x8b04,acStack_3c);
      pFVar1 = stderr;
      if (iVar3 < 0) {
        piVar4 = __errno_location();
        pcVar5 = strerror(*piVar4);
        fprintf(pFVar1,"SIOCSIWFREQ: %s\n",pcVar5);
        local_b8 = 0xffffffff;
      }
    }
    if (*(int *)(param_3 + 0x34) != 0) {
      uVar6 = *(uint *)(param_3 + 0x7c);
      if ((uVar6 & 0xff) != 0) {
        local_2c = 0;
        local_28 = (uint)((ushort)uVar6 & 0xff | 0x800) << 0x10;
[32m[32m[32m        strncpy(acStack_3c,param_2,0x10);[0m[0m[0m
        iVar3 = ioctl(param_1,0x8b2a,acStack_3c);
        pFVar1 = stderr;
        if (iVar3 < 0) {
          piVar4 = __errno_location();
          iVar3 = *piVar4;
          piVar4 = __errno_location();
          pcVar5 = strerror(*piVar4);
          fprintf(pFVar1,"SIOCSIWENCODE(%d): %s\n",iVar3,pcVar5);
          local_b8 = 0xffffffff;
        }
      }
      local_2c = param_3 + 0x38;
      local_28 = *(uint *)(param_3 + 0x78) & 0xffff | (uVar6 & 0xff00) << 0x10;
      if ((uVar6 & 0x800) != 0) {
        local_2c = 0;
      }
[32m[32m[32m      strncpy(acStack_3c,param_2,0x10);[0m[0m[0m
      iVar3 = ioctl(param_1,0x8b2a,acStack_3c);
      pFVar1 = stderr;
      if (iVar3 < 0) {
        piVar4 = __errno_location();
        iVar3 = *piVar4;
        piVar4 = __errno_location();
        pcVar5 = strerror(*piVar4);
        fprintf(pFVar1,"SIOCSIWENCODE(%d): %s\n",iVar3,pcVar5);
        local_b8 = 0xffffffff;
      }
    }
    if (*(int *)(param_3 + 0x14) != 0) {
      local_2c = *(int *)(param_3 + 0x18);
      local_28 = CONCAT31((int3)((uint)*(undefined4 *)(param_3 + 0x1c) >> 8),1);
[32m[32m[32m      strncpy(acStack_3c,param_2,0x10);[0m[0m[0m
      iVar3 = ioctl(param_1,0x8b02,acStack_3c);
      pFVar1 = stderr;
      if (iVar3 < 0) {
        piVar4 = __errno_location();
        pcVar5 = strerror(*piVar4);
        fprintf(pFVar1,"SIOCSIWNWID: %s\n",pcVar5);
        local_b8 = 0xffffffff;
      }
    }
    if (*(int *)(param_3 + 0x80) != 0) {
      iVar3 = iw_get_kernel_we_version();
      local_2c = param_3 + 0x88;
[32m      sVar7 = strlen((char *)(param_3 + 0x88));[0m
      sVar2 = (short)sVar7;
      if (iVar3 < 0x15) {
        sVar2 = sVar2 + 1;
      }
      local_28 = CONCAT22((short)*(undefined4 *)(param_3 + 0x84),sVar2);
[32m[32m[32m      strncpy(acStack_3c,param_2,0x10);[0m[0m[0m
      iVar3 = ioctl(param_1,0x8b1a,acStack_3c);
      pFVar1 = stderr;
      if (iVar3 < 0) {
        piVar4 = __errno_location();
        pcVar5 = strerror(*piVar4);
        fprintf(pFVar1,"SIOCSIWESSID: %s\n",pcVar5);
        local_b8 = 0xffffffff;
      }
    }
  }
  return local_b8;
}

[ASK_GPT] bc431476a64c6b72
