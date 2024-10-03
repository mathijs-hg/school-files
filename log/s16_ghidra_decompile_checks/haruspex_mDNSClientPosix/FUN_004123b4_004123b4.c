
void FUN_004123b4(undefined4 param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar8 = *(int *)(param_2 + 0x28c);
  if ((param_4 == 0) ||
     (((param_4 == 2 && (*(short *)(param_3 + 0xc) == 0)) ||
[32m      (sVar1 = *(short *)(param_2 + 0x254), sVar1 != *(short *)(param_3 + 2))))) {[0m
    return;
  }
  if (sVar1 != 6) {
    if (sVar1 == 0x21) {
      mDNS_StopQuery(param_1,param_2);
      if (*(int *)(param_2 + 0x10) != -1) {
        uVar2 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
        LogMsgWithLevel(0,"GetZoneData_QuestionCallback: Question %##s (%s) ThisQInterval %d not -1"
                        ,param_2 + 0x154,uVar2,*(undefined4 *)(param_2 + 0x10));
      }
      if (*(short *)(param_3 + 0xc) != 0) {
        uVar3 = DomainNameLengthLimit
                          (*(int *)(param_3 + 0x20) + 10,*(int *)(param_3 + 0x20) + 0x10a);
        if (uVar3 < 0x101) {
          mDNSPlatformMemCopy((void *)(iVar8 + 0x20a),(void *)(*(int *)(param_3 + 0x20) + 10),uVar3)
          ;
        }
        else {
          *(undefined *)(iVar8 + 0x20a) = 0;
        }
        *(undefined2 *)(iVar8 + 0x30a) = *(undefined2 *)(*(int *)(param_3 + 0x20) + 8);
        uVar3 = DomainNameLengthLimit((void *)(iVar8 + 0x20a),iVar8 + 0x30a);
        if (uVar3 < 0x101) {
          mDNSPlatformMemCopy((void *)(iVar8 + 0x480),(void *)(iVar8 + 0x20a),uVar3);
        }
        else {
          *(undefined *)(iVar8 + 0x480) = 0;
        }
        uVar2 = 1;
        goto LAB_004125d0;
      }
      *(undefined2 *)(iVar8 + 0x30a) = 0;
      *(undefined *)(iVar8 + 800) = 0;
      *(undefined *)(iVar8 + 0x20a) = 0;
[32m[32m      memcpy((void *)(iVar8 + 0x30c),zeroAddr,0x14);[0m[0m
      UNRECOVERED_JUMPTABLE = *(code **)(iVar8 + 0x324);
      uVar7 = 0;
    }
    else {
      if (sVar1 != 1) {
        return;
      }
      mDNS_StopQuery(param_1,param_2);
      if (*(int *)(param_2 + 0x10) != -1) {
        uVar2 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
        LogMsgWithLevel(0,"GetZoneData_QuestionCallback: Question %##s (%s) ThisQInterval %d not -1"
                        ,param_2 + 0x154,uVar2,*(undefined4 *)(param_2 + 0x10));
      }
      *(undefined4 *)(iVar8 + 0x30c) = 4;
      if (*(short *)(param_3 + 0xc) == 4) {
        uVar2 = *(undefined4 *)(*(int *)(param_3 + 0x20) + 4);
      }
      else {
        uVar2 = 0;
      }
      UNRECOVERED_JUMPTABLE = *(code **)(iVar8 + 0x324);
      uVar7 = 0;
      *(undefined4 *)(iVar8 + 0x310) = uVar2;
    }
    goto LAB_0041281c;
  }
  mDNS_StopQuery(param_1,param_2);
  if (*(int *)(param_2 + 0x10) != -1) {
    uVar2 = DNSTypeName(*(undefined2 *)(param_2 + 0x254));
    LogMsgWithLevel(0,"GetZoneData_QuestionCallback: Question %##s (%s) ThisQInterval %d not -1",
                    param_2 + 0x154,uVar2,*(undefined4 *)(param_2 + 0x10));
  }
  if (*(short *)(param_3 + 0xc) != 0) {
    uVar3 = DomainNameLengthLimit(*(int *)(param_3 + 0x1c),*(int *)(param_3 + 0x1c) + 0x100);
    if (uVar3 < 0x101) {
      mDNSPlatformMemCopy((void *)(iVar8 + 0x108),*(void **)(param_3 + 0x1c),uVar3);
    }
    else {
      *(undefined *)(iVar8 + 0x108) = 0;
    }
    *(undefined2 *)(iVar8 + 0x208) = *(undefined2 *)(param_3 + 4);
    uVar3 = DomainNameLengthLimit((void *)(iVar8 + 0x108),iVar8 + 0x208);
    if (uVar3 < 0x101) {
      mDNSPlatformMemCopy((void *)(iVar8 + 0x480),(void *)(iVar8 + 0x108),uVar3);
    }
    else {
      *(undefined *)(iVar8 + 0x480) = 0;
    }
    uVar2 = 0x21;
LAB_004125d0:
    FUN_0041213c(param_1,iVar8,uVar2);
    return;
  }
  if (**(char **)(iVar8 + 0x104) == '\0') {
    if (mDNS_LoggingEnabled != 0) {
      pcVar6 = "GetZoneData recursed to root label of %##s without finding SOA";
      iVar4 = iVar8;
LAB_0041260c:
      LogMsgWithLevel(3,pcVar6,iVar4);
    }
  }
  else {
    iVar4 = FUN_0040d9ac(param_1);
    if ((iVar4 == 0) || (*(char *)(iVar4 + 8) == '\0')) {
      pbVar5 = *(byte **)(iVar8 + 0x104) + **(byte **)(iVar8 + 0x104) + 1;
      *(byte **)(iVar8 + 0x104) = pbVar5;
      uVar3 = DomainNameLengthLimit(pbVar5,pbVar5 + 0x100);
      if (uVar3 < 0x101) {
        mDNSPlatformMemCopy((void *)(iVar8 + 0x480),*(void **)(iVar8 + 0x104),uVar3);
      }
      else {
        *(undefined *)(iVar8 + 0x480) = 0;
      }
      uVar2 = 6;
      goto LAB_004125d0;
    }
    if (mDNS_LoggingEnabled != 0) {
      pcVar6 = "GetZoneData_QuestionCallback: not chopping labels for %##s";
      iVar4 = *(int *)(iVar8 + 0x104);
      goto LAB_0041260c;
    }
  }
  UNRECOVERED_JUMPTABLE = *(code **)(iVar8 + 0x324);
  uVar7 = 0xfffefffe;
LAB_0041281c:
                    /* WARNING: Could not recover jumptable at 0x00412834. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,uVar7,iVar8);
  return;
}

[ASK_GPT] 52fdfbb1f4ca542c
