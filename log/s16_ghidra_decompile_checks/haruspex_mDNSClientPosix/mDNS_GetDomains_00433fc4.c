
undefined4
mDNS_GetDomains(undefined4 param_1,int param_2,uint param_3,undefined *param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined4 *)(param_2 + 0x134) = param_5;
  *(undefined4 *)(param_2 + 0x138) = 0;
[32m[32m  memcpy((void *)(param_2 + 0x13c),zeroAddr,0x14);[0m[0m
  *(undefined2 *)(param_2 + 0x254) = 0xc;
  *(undefined2 *)(param_2 + 0x256) = 1;
  *(undefined *)(param_2 + 600) = 0;
  *(undefined *)(param_2 + 0x259) = 0;
  *(undefined *)(param_2 + 0x25a) = 0;
  *(undefined *)(param_2 + 0x25b) = 0;
  *(undefined *)(param_2 + 0x25c) = 0;
  *(undefined *)(param_2 + 0x25d) = 0;
  *(undefined *)(param_2 + 0x25e) = 0;
  *(undefined *)(param_2 + 0x263) = 0;
  *(undefined *)(param_2 + 0x264) = 0;
  *(undefined *)(param_2 + 0x25f) = 0;
  *(undefined *)(param_2 + 0x260) = 0;
  *(undefined *)(param_2 + 0x261) = 0;
  *(undefined *)(param_2 + 0x262) = 0;
  *(undefined *)(param_2 + 0x266) = 0;
  *(undefined *)(param_2 + 0xcc) = 0;
  *(undefined *)(param_2 + 0x267) = 0;
  *(undefined4 *)(param_2 + 0x284) = 0;
  *(undefined4 *)(param_2 + 0x44) = 0;
  uVar1 = mDNSPlatformGetPID();
  *(undefined4 *)(param_2 + 0x26c) = uVar1;
  *(undefined4 *)(param_2 + 0x288) = param_6;
  *(undefined4 *)(param_2 + 0x28c) = param_7;
  *(undefined4 *)(param_2 + 0x280) = 0;
  if (param_3 < 5) {
    iVar2 = MakeDomainNameFromDNSNameString
                      (param_2 + 0x154,*(undefined4 *)(mDNS_DomainTypeNames + param_3 * 4));
    if (iVar2 != 0) {
      if (param_4 == (undefined *)0x0) {
        param_4 = &DAT_0044d544;
      }
      iVar2 = AppendDomainName(param_2 + 0x154,param_4);
      if (iVar2 != 0) {
        uVar1 = mDNS_StartQuery(param_1,param_2);
        return uVar1;
      }
    }
  }
  return 0xfffefffc;
}

[ASK_GPT] 474245ed7b2b2d1b
