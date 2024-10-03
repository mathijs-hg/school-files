
/* WARNING: Removing unreachable block (ram,0x0041d7cc) */

void FUN_0042cc08(int param_1,int param_2)

{
  short sVar1;
  undefined2 uVar4;
  undefined4 uVar2;
  int iVar3;
  uint __n;
  undefined uVar5;
  int iVar6;
  undefined *__dest;
  char *__src;
  
[32m  sVar1 = *(short *)(param_2 + 6);[0m
  if ((((sVar1 == 2) || (sVar1 == 5)) || (sVar1 == 0xc)) || (sVar1 == 0x27)) {
    __dest = (undefined *)(*(int *)(param_2 + 0x24) + 4);
  }
  else if (((sVar1 == 0xf) || (sVar1 == 0x12)) || ((sVar1 == 0x15 || (sVar1 == 0x24)))) {
    __dest = (undefined *)(*(int *)(param_2 + 0x24) + 6);
  }
  else {
    __dest = (undefined *)0x0;
    if (sVar1 == 0x21) {
      __dest = (undefined *)(*(int *)(param_2 + 0x24) + 10);
    }
  }
  __src = (char *)(param_1 + 0x1ad9);
  if ((__dest == (undefined *)0x0) && (mDNS_LoggingEnabled != 0)) {
    uVar2 = DNSTypeName(sVar1);
    LogMsgWithLevel(3,"SetTargetToHostName: Don\'t know how to set the target of rrtype %s",uVar2);
  }
  if ((((*(char *)(param_2 + 0x4a) == '\0') && (*(int *)(param_2 + 0x7c) != 4)) &&
      (*(int *)(param_2 + 0x7c) != 5)) && (iVar3 = IsLocalDomain(param_2 + 0x178), iVar3 == 0)) {
    if ((*(char *)(param_2 + 0x48) != '\0') &&
       ((iVar3 = GetAuthInfoForName_internal(param_1,*(undefined4 *)(param_2 + 0x20)), iVar3 == 0 ||
        (*(char *)(iVar3 + 8) == '\0')))) {
      *(undefined *)(param_2 + 0x48) = 2;
    }
    __src = (char *)GetServiceTarget(param_1,param_2);
    if ((__src == (char *)0x0) || (*__src == '\0')) {
      if (mDNS_LoggingEnabled != 0) {
        uVar2 = GetRRDisplayString_rdb(param_2 + 4,*(int *)(param_2 + 0x24) + 4,param_1 + 0x2f);
        LogMsgWithLevel(3,"SetUnicastTargetToHostName No target for %s",uVar2);
      }
      *(undefined4 *)(param_2 + 0xe4) = 8;
      if (__dest != (undefined *)0x0) {
        *__dest = 0;
      }
      iVar3 = param_2 + 4;
[32m      sVar1 = *(short *)(param_2 + 6);[0m
      if ((((sVar1 == 2) || (sVar1 == 5)) || (sVar1 == 0xc)) || (sVar1 == 0x27)) {
        iVar6 = *(int *)(param_2 + 0x24) + 4;
      }
      else if (((sVar1 == 0xf) || (sVar1 == 0x12)) || ((sVar1 == 0x15 || (sVar1 == 0x24)))) {
        iVar6 = *(int *)(param_2 + 0x24) + 6;
      }
      else {
        iVar6 = 0;
        if (sVar1 == 0x21) {
          iVar6 = *(int *)(param_2 + 0x24) + 10;
        }
      }
      uVar4 = GetRDLength(iVar3,0);
      *(undefined2 *)(param_2 + 0x10) = uVar4;
      uVar4 = GetRDLength(iVar3,1);
      *(undefined2 *)(param_2 + 0x12) = uVar4;
      if (iVar6 == 0) {
        uVar2 = RDataHashValue(iVar3);
        *(undefined4 *)(param_2 + 0x18) = uVar2;
      }
      else {
        uVar2 = DomainNameHashValue(iVar6);
        *(undefined4 *)(param_2 + 0x18) = uVar2;
      }
      return;
    }
    if (mDNS_LoggingEnabled != 0) {
      uVar2 = GetRRDisplayString_rdb(param_2 + 4,*(int *)(param_2 + 0x24) + 4,param_1 + 0x2f);
      LogMsgWithLevel(3,"SetUnicastTargetToHostName target %##s for resource record %s",__src,uVar2)
      ;
    }
  }
  if (__dest != (undefined *)0x0) {
    SameDomainName(__dest,__src);
    iVar3 = SameDomainName(__dest,__src);
    if (iVar3 == 0) {
      __n = DomainNameLengthLimit(__src,__src + 0x100);
      if (__n < 0x101) {
        mDNSPlatformMemCopy(__dest,__src,__n);
      }
      else {
        *__dest = 0;
      }
      SetNewRData(param_2 + 4,0,0);
      *(undefined *)(param_2 + 0x87) = 4;
      uVar5 = 3;
      if (*(char *)(param_2 + 4) != '\x02') {
        uVar5 = 0;
      }
      *(undefined *)(param_2 + 0x88) = 0;
      *(undefined *)(param_2 + 0x86) = uVar5;
      *(undefined *)(param_2 + 0x85) = 0;
      FUN_00428828(param_1,param_2);
      return;
    }
  }
  return;
}

[ASK_GPT] fa80f804e4c5dd83
