
void * mDNS_AddDNSServer(int param_1,char *param_2,int param_3,int param_4,void *param_5,
                        undefined4 param_6,int param_7,undefined4 param_8,char param_9,
                        undefined2 param_10,char param_11,char param_12,char param_13)

{
  char *pcVar1;
  int iVar2;
  void **ppvVar3;
  uint __n;
  char *pcVar4;
  void **ppvVar5;
  void *pvVar6;
  char *pcVar7;
  void **ppvVar8;
  char *pcVar9;
  
  if (0x40 < NumUnicastDNSServers + 1) {
    LogMsgWithLevel(0,"mDNS_AddDNSServer: DNS server limit of %d reached, not adding this server",
                    0x40);
    return (void *)0x0;
  }
  if (param_2 == (char *)0x0) {
    param_2 = "";
  }
  if (mDNS_LoggingEnabled != 0) {
    if (param_11 == '\0') {
      pcVar7 = "False";
    }
    else {
      pcVar7 = "True";
    }
    if (param_12 == '\0') {
      pcVar9 = "False";
    }
    else {
      pcVar9 = "True";
    }
    if (param_9 == '\0') {
      pcVar4 = "False";
    }
    else {
      pcVar4 = "True";
    }
    if (param_13 == '\0') {
      pcVar1 = "False";
    }
    else {
      pcVar1 = "True";
    }
    LogMsgWithLevel(3,
                    "mDNS_AddDNSServer(%d): Adding %#a for %##s, InterfaceID %p, serviceID %u, scoped %d, resGroupID %d req_A is %s req_AAAA is %s cell %s req_DO is %s"
                    ,(uint)NumUnicastDNSServers,param_5,param_2,param_3,param_4,param_7,param_10,
                    pcVar7,pcVar9,pcVar4,pcVar1);
  }
  if (*(int *)(param_1 + 0x24) != *(int *)(param_1 + 0x28) + 1) {
    LogMsgWithLevel(0,"%s: Lock not held! mDNS_busy (%ld) mDNS_reentrancy (%ld)","mDNS_AddDNSServer"
                    ,*(int *)(param_1 + 0x24),*(int *)(param_1 + 0x28));
  }
  ppvVar5 = (void **)(param_1 + 0x2190);
  ppvVar8 = (void **)0x0;
  while (pvVar6 = *ppvVar5, pvVar6 != (void *)0x0) {
    if ((((((*(int *)((int)pvVar6 + 0x134) == param_7) && (*(int *)((int)pvVar6 + 4) == param_3)) &&
          (*(int *)((int)pvVar6 + 8) == param_4)) &&
         ((*(int *)((int)pvVar6 + 0x28) != 3 &&
          (iVar2 = mDNSSameAddress((int)pvVar6 + 0xc,param_5), iVar2 != 0)))) &&
        ((*(short *)((int)*ppvVar5 + 0x20) == param_6._0_2_ &&
         ((iVar2 = SameDomainName((int)*ppvVar5 + 0x30,param_2), iVar2 != 0 &&
          (ppvVar3 = (void **)*ppvVar5, *(char *)(ppvVar3 + 0x50) == param_11)))))) &&
       (*(char *)((int)ppvVar3 + 0x141) == param_12)) {
      *ppvVar5 = *ppvVar3;
      *ppvVar3 = (void *)0x0;
      ppvVar8 = ppvVar3;
    }
    else {
      ppvVar5 = (void **)*ppvVar5;
    }
  }
  if ((ppvVar8 == (void **)0x0) || (((uint)ppvVar8[9] & 1) != 0)) {
    NumUnicastDNSServers = NumUnicastDNSServers + 1;
  }
  if (ppvVar8 == (void **)0x0) {
    pvVar6 = mDNSPlatformMemAllocate(0x148);
    *ppvVar5 = pvVar6;
    if (pvVar6 == (void *)0x0) {
      LogMsgWithLevel(0,"Error: mDNS_AddDNSServer - malloc");
    }
    else {
      *(int *)((int)pvVar6 + 0x134) = param_7;
      *(int *)((int)*ppvVar5 + 4) = param_3;
      *(int *)((int)*ppvVar5 + 8) = param_4;
[32m[32m      memcpy((void *)((int)*ppvVar5 + 0xc),param_5,0x14);[0m[0m
      *(short *)((int)*ppvVar5 + 0x20) = param_6._0_2_;
      *(undefined4 *)((int)*ppvVar5 + 0x24) = 2;
      *(undefined4 *)((int)*ppvVar5 + 0x28) = 1;
      *(int *)((int)*ppvVar5 + 0x2c) = mDNSPlatformOneSecond * -3 + *(int *)(param_1 + 0x234);
      *(undefined4 *)((int)*ppvVar5 + 0x138) = param_8;
      *(char *)((int)*ppvVar5 + 0x13c) = param_9;
      *(char *)((int)*ppvVar5 + 0x140) = param_11;
      *(char *)((int)*ppvVar5 + 0x141) = param_12;
      *(char *)((int)*ppvVar5 + 0x142) = param_13;
      *(undefined *)((int)*ppvVar5 + 0x144) = 0;
      *(undefined *)((int)*ppvVar5 + 0x143) = 0;
      __n = DomainNameLengthLimit(param_2,param_2 + 0x100);
      if (__n < 0x101) {
        mDNSPlatformMemCopy((void *)((int)*ppvVar5 + 0x30),param_2,__n);
      }
      else {
        *(undefined *)((int)*ppvVar5 + 0x30) = 0;
      }
      *(undefined4 *)*ppvVar5 = 0;
    }
  }
  else {
    ppvVar8[9] = (void *)((uint)ppvVar8[9] & 0xfffffffe);
    *ppvVar5 = ppvVar8;
  }
  *(undefined4 *)((int)*ppvVar5 + 0x130) = 0;
  *(undefined2 *)((int)*ppvVar5 + 0x13e) = param_10;
  return *ppvVar5;
}

[ASK_GPT] 0914cce18cf39a9f
