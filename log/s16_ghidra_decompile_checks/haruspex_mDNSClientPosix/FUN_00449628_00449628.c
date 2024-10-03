
/* WARNING: Removing unreachable block (ram,0x00449a2c) */

void FUN_00449628(int param_1,char param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  uint uVar11;
  
  if (mDNS_LoggingEnabled != 0) {
    if (param_2 == '\0') {
      pcVar6 = "Waking";
    }
    else {
      pcVar6 = "Sleeping";
    }
    LogMsgWithLevel(2,"%s (old state %d) at %ld",pcVar6,*(undefined *)(param_1 + 0x275),
                    *(undefined4 *)(param_1 + 0x234));
  }
  if (param_2 == '\0') {
    mDNS_Lock_(param_1,"mDNSCoreMachineSleep");
    *(undefined4 *)(param_1 + 0x284) = 0;
    if (*(char *)(param_1 + 0x275) != '\0') {
      *(undefined *)(param_1 + 0x275) = 0;
      *(char *)(param_1 + 0x276) = *(char *)(param_1 + 0x276) + '\x01';
      *(undefined4 *)(param_1 + 0x280) = 0;
    }
    if (*(char *)(param_1 + 0x2aa1) == '\x03') {
      *(undefined *)(param_1 + 0x2aa1) = 0;
      FUN_004490c4(param_1,*(undefined *)(param_1 + 0x2a9c),*(undefined *)(param_1 + 0x2a9d),
                   *(undefined *)(param_1 + 0x2a9e),*(undefined *)(param_1 + 0x2a9f),
                   *(undefined *)(param_1 + 0x2aa0));
    }
    uVar5 = *(undefined4 *)(param_1 + 0x2174);
    *(int *)(param_1 + 0x3998) = *(int *)(param_1 + 0x3998) + 1;
    while (puVar3 = (undefined4 *)GetFirstActiveInterface(uVar5), puVar3 != (undefined4 *)0x0) {
      uVar5 = *puVar3;
      puVar3[0x2a3] = 0xffffffff;
    }
    FUN_0042c628(param_1);
    iVar7 = *(int *)(param_1 + 0x234);
    iVar2 = mDNSPlatformOneSecond + iVar7;
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    *(int *)(param_1 + 0x218c) = iVar2;
    if (mDNS_LoggingEnabled != 0) {
      LogMsgWithLevel(3,"mDNSCoreMachineSleep waking: NextSRVUpdate in %d %d",iVar2 - iVar7,iVar7);
    }
    iVar10 = param_1 + 0x2f;
    iVar7 = mDNSPlatformUTC();
    iVar7 = iVar7 - *(int *)(param_1 + 0x288);
    iVar2 = param_1;
    do {
      for (puVar3 = *(undefined4 **)(iVar2 + 0x2e0); puVar3 != (undefined4 *)0x0;
          puVar3 = (undefined4 *)*puVar3) {
        for (puVar9 = (undefined4 *)puVar3[2]; puVar9 != (undefined4 *)0x0;
            puVar9 = (undefined4 *)*puVar9) {
          if (puVar9[7] == 0) {
            if (0 < iVar7) {
              uVar11 = (puVar9[3] * 4 - 8U) / 5;
              if (mDNSPlatformOneSecond == 0) {
                trap(0x1c00);
              }
              iVar8 = uVar11 - (*(int *)(param_1 + 0x234) - puVar9[0xd]) / mDNSPlatformOneSecond;
              if ((iVar7 < iVar8) && (iVar7 < 0x2a301)) {
                iVar4 = puVar9[0xd] - iVar7 * mDNSPlatformOneSecond;
                puVar9[0xd] = iVar4;
                if ((int)((*(int *)(param_1 + 0x234) - uVar11 * mDNSPlatformOneSecond) - iVar4) < 0)
                {
                  if (mDNS_LoggingEnabled != 0) {
                    uVar5 = GetRRDisplayString_rdb(puVar9 + 1,puVar9[9] + 4,iVar10);
                    LogMsgWithLevel(3,
                                    "mDNSCoreMachineSleep: %s: Adjusted the remain ttl %u by %d seconds"
                                    ,uVar5,iVar8,iVar7);
                  }
                  goto LAB_00449bb0;
                }
                if (mDNS_LoggingEnabled != 0) {
                  uVar5 = GetRRDisplayString_rdb(puVar9 + 1,puVar9[9] + 4,iVar10);
                  pcVar6 = 
                  "mDNSCoreMachineSleep: %s: Purging after adjusting the remaining TTL %d by %d seconds"
                  ;
                  iVar4 = iVar8;
                  iVar8 = iVar7;
                  goto LAB_00449b2c;
                }
              }
              else if (mDNS_LoggingEnabled != 0) {
                uVar5 = GetRRDisplayString_rdb(puVar9 + 1,puVar9[9] + 4,iVar10);
                pcVar6 = 
                "mDNSCoreMachineSleep: %s: Purging cache entry SleptTime %d, Remaining TTL %d";
                iVar4 = iVar7;
LAB_00449b2c:
                LogMsgWithLevel(3,pcVar6,uVar5,iVar4,iVar8);
              }
              mDNS_PurgeCacheResourceRecord(param_1,puVar9);
            }
          }
          else {
            FUN_00429190(param_1,puVar9,mDNSPlatformOneSecond * 5);
          }
LAB_00449bb0:
        }
      }
      iVar2 = iVar2 + 4;
    } while (iVar2 != param_1 + 0x7cc);
    for (puVar3 = *(undefined4 **)(param_1 + 0x2160); puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)*puVar3) {
      if (((puVar3[7] == 0) && (*(char *)((int)puVar3 + 0x4a) == '\0')) &&
         (iVar2 = IsLocalDomain(puVar3[8],puVar3,0xffffffff), iVar2 == 0)) {
        ActivateUnicastRegistration(param_1,puVar3);
      }
      else {
        FUN_0042a844(param_1,puVar3,0xffffffff);
      }
    }
    if (mDNS_LoggingEnabled != 0) {
      LogMsgWithLevel(3,"mDNSCoreMachineSleep: recreating NAT mappings in 5 seconds");
    }
    RecreateNATMappings(param_1,mDNSPlatformOneSecond * 5);
  }
  else {
    if (*(char *)(param_1 + 0x275) != '\0') {
      return;
    }
    mDNS_Lock_(param_1,"mDNSCoreMachineSleep");
    if (*(int *)(param_1 + 0x2aa8) != 0) {
      iVar2 = *(int *)(param_1 + 0x28) + 1;
      *(int *)(param_1 + 0x28) = iVar2;
[32m      cVar1 = *(char *)(param_1 + 0x2aa1);[0m
      if (*(int *)(param_1 + 0x24) != iVar2) {
        LogMsgWithLevel(0,"%s: Locking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                        "mDNSCoreMachineSleep",*(int *)(param_1 + 0x24),iVar2);
      }
      *(undefined *)(param_1 + 0x2aa1) = 2;
      if (cVar1 == '\x01') {
        FUN_0043c5a8(param_1,param_1 + 0x2aac,0);
      }
      iVar2 = *(int *)(param_1 + 0x28);
      if (*(int *)(param_1 + 0x24) != iVar2) {
        LogMsgWithLevel(0,"%s: Unlocking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                        "mDNSCoreMachineSleep",*(int *)(param_1 + 0x24),iVar2);
        iVar2 = *(int *)(param_1 + 0x28);
      }
      *(int *)(param_1 + 0x28) = iVar2 + -1;
    }
    *(undefined *)(param_1 + 0x275) = 1;
    if ((*(char *)(param_1 + 0x277) == '\0') || (*(int *)(param_1 + 0x280) == 0)) {
      *(undefined4 *)(param_1 + 0x280) = 0;
      iVar2 = mDNSPlatformOneSecond * 10;
      *(int *)(param_1 + 0x3994) = *(int *)(param_1 + 0x3994) + 1;
      iVar2 = iVar2 + *(int *)(param_1 + 0x234);
      if (iVar2 == 0) {
        iVar2 = 1;
      }
      *(int *)(param_1 + 0x284) = iVar2;
      FUN_004410b8(param_1);
    }
    else {
      if (mDNS_LoggingEnabled != 0) {
        LogMsgWithLevel(2,
                        "mDNSCoreMachineSleep: Re-sleeping immediately after waking; will delay for %d ticks"
                        ,*(int *)(param_1 + 0x280) - *(int *)(param_1 + 0x234));
      }
      iVar2 = mDNSPlatformOneSecond * 10 + *(int *)(param_1 + 0x280);
      if (iVar2 == 0) {
        iVar2 = 1;
      }
      *(int *)(param_1 + 0x284) = iVar2;
    }
    FUN_00427638(param_1);
    if (mDNS_LoggingEnabled != 0) {
[32m      cVar1 = *(char *)(param_1 + 0x275);[0m
      if (cVar1 == '\x01') {
        pcVar6 = "Transferring";
      }
      else if (cVar1 == '\x02') {
        pcVar6 = "Sleeping";
      }
      else {
        pcVar6 = "?";
      }
      LogMsgWithLevel(2,"mDNSCoreMachineSleep: m->SleepState %d (%s) seq %d",cVar1,pcVar6,
                      *(undefined *)(param_1 + 0x276));
    }
  }
                    /* WARNING: Treating indirect jump as call */
  mDNS_Unlock_(param_1,"mDNSCoreMachineSleep");
  return;
}

[ASK_GPT] 573024567209ffa2
