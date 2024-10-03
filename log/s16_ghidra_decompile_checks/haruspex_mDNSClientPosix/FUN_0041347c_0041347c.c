
void FUN_0041347c(int param_1,undefined4 *param_2)

{
  short sVar1;
  bool bVar2;
  undefined4 *puVar3;
  char *pcVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  undefined4 uStackX_8;
  uint uStackX_c;
  
  iVar10 = param_2[9];
  pcVar4 = (char *)GetServiceTarget();
  pcVar9 = pcVar4;
  if (pcVar4 == (char *)0x0) {
    pcVar9 = "";
  }
  if ((*pcVar9 == '\0') || (param_2[0x39] != 8)) {
    iVar11 = 0;
    iVar10 = SameDomainName(iVar10 + 10,pcVar9);
    if (iVar10 == 0) goto LAB_00413508;
  }
  else {
LAB_00413508:
    iVar11 = 1;
  }
[32m  sVar1 = *(short *)(param_2[9] + 8);[0m
  if (*(char *)(param_2 + 0x12) == '\x02') {
    bVar2 = false;
    if (sVar1 != 0) {
      iVar10 = mDNSv4AddrIsRFC1918(param_1 + 0x21b0);
      bVar2 = false;
      if (((iVar10 != 0) && (iVar10 = param_2[0x40], iVar10 != 0)) &&
         (bVar2 = true, *(int *)(iVar10 + 0x30c) == 4)) {
        iVar10 = mDNSv4AddrIsRFC1918(iVar10 + 0x310);
        if (iVar10 != 0) goto LAB_0041357c;
        bVar2 = true;
      }
    }
  }
  else {
LAB_0041357c:
    bVar2 = false;
  }
  if (param_2[0x53] == 0) {
    uVar12 = 0;
  }
  else {
    uVar12 = (uint)(*(short *)(param_2 + 0x50) != sVar1);
  }
  uVar5 = (uint)(param_2[0x53] == 0);
  if (!bVar2) {
    uVar5 = uVar12;
  }
  if (mDNS_LoggingEnabled != 0) {
    uVar6 = GetRRDisplayString_rdb(param_2 + 1,param_2[9] + 4,param_1 + 0x2f);
    LogMsgWithLevel(3,"UpdateOneSRVRecord: Resource Record %s TargetChanged %d, NewTarget %##s",
                    uVar6,iVar11,pcVar4);
  }
  uStackX_c = *(uint *)(param_1 + 0x24);
  if (uStackX_c != *(int *)(param_1 + 0x28) + 1U) {
    LogMsgWithLevel(0,"%s: Lock not held! mDNS_busy (%ld) mDNS_reentrancy (%ld)",
                    "UpdateOneSRVRecord",uStackX_c,*(int *)(param_1 + 0x28));
  }
  if ((uVar5 == 0) && (iVar11 == 0)) {
    return;
  }
  if (*(char *)(param_2 + 1) == '\x01') {
    if (mDNS_LoggingEnabled == 0) {
      return;
    }
    LogMsgWithLevel(3,
                    "UpdateOneSRVRecord: Deregistering record, Ignoring TargetChanged %d, NATChanged %d for %##s, state %d"
                    ,iVar11,uVar5,param_2[8],param_2[0x39]);
    return;
  }
  if (mDNS_LoggingEnabled != 0) {
    uStackX_c = uVar5;
    LogMsgWithLevel(3,
                    "UpdateOneSRVRecord: TargetChanged %d, NATChanged %d for %##s, state %d, newtarget %##s"
                    ,iVar11,uVar5,param_2[8],param_2[0x39],pcVar9);
  }
  uStackX_8 = param_2[0x39];
  switch(uStackX_8) {
  case 1:
  case 2:
  case 3:
  case 5:
    *(undefined *)(param_2 + 0x54) = 1;
    param_2[0x2f] = mDNSPlatformOneSecond;
    param_2[0x30] = *(int *)(param_1 + 0x234) - mDNSPlatformOneSecond;
    if (*pcVar9 != '\0') {
      if (mDNS_LoggingEnabled != 0) {
        LogMsgWithLevel(3,
                        "UpdateOneSRVRecord: SRV record changed for service %##s, registering with new target %##s"
                        ,param_2[8],pcVar9);
      }
      param_2[0x39] = 1;
      return;
    }
    if (mDNS_LoggingEnabled != 0) {
      LogMsgWithLevel(3,"UpdateOneSRVRecord: SRV record changed for service %##s de-registering",
                      param_2[8]);
    }
    uVar6 = 0;
    param_2[0x39] = 3;
    break;
  default:
    uStackX_c = param_2[8];
    pcVar9 = "UpdateOneSRVRecord: Unknown state %d for %##s";
    uVar6 = 0;
    goto code_r0x00407ce4;
  case 6:
  case 7:
    return;
  case 9:
    if (uVar5 == 0) {
      return;
    }
  case 8:
    if (*pcVar9 == '\0') {
      if (mDNS_LoggingEnabled == 0) {
        return;
      }
      uStackX_8 = GetRRDisplayString_rdb(param_2 + 1,param_2[9] + 4,param_1 + 0x2f);
      pcVar9 = "UpdateOneSRVRecord: No target yet for Resource Record %s";
      uVar6 = 3;
code_r0x00407ce4:
      FUN_00407c70(uVar6,pcVar9,&uStackX_8);
      return;
    }
    if (mDNS_LoggingEnabled != 0) {
      LogMsgWithLevel(3,"RegisterAllServiceRecords: Service Record %##s",param_2[8]);
    }
    *(undefined *)(param_2 + 0x54) = 0;
    puVar3 = *(undefined4 **)(param_1 + 0x2160);
    puVar8 = (undefined4 *)(param_1 + 0x2160);
    while (puVar7 = puVar3, puVar7 != (undefined4 *)0x0) {
      if (puVar7 == param_2) {
        *puVar8 = *param_2;
        *param_2 = 0;
        if (param_2[0x53] != 0) {
          mDNS_StopNATOperation_internal(param_1,param_2 + 0x42);
          param_2[0x53] = 0;
          if (*(short *)((int)param_2 + 6) == 0x21) {
            *(undefined2 *)(param_2[9] + 8) = *(undefined2 *)((int)param_2 + 0x13e);
          }
        }
        goto LAB_00413818;
      }
      puVar8 = puVar7;
      puVar3 = (undefined4 *)*puVar7;
    }
    LogMsgWithLevel(0,"UnlinkResourceRecord:ERROR!! - no such active record %##s",param_2[8]);
LAB_00413818:
    mDNS_Register_internal(param_1,param_2);
    uVar6 = 1;
  }
  FUN_0040e070(param_1,param_2,uVar6);
  return;
}

[ASK_GPT] e01e4fbeab7a420f
