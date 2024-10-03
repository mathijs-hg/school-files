
/* WARNING: Removing unreachable block (ram,0x0042e220) */

void InitializeAnonInfoForQuestion(int param_1,undefined4 *param_2,int param_3)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  void *__ptr;
  undefined4 uVar6;
  undefined4 *puVar7;
  
  if (*(short *)(param_3 + 0x254) == 0xc) {
    puVar5 = (undefined4 *)*param_2;
    while (puVar7 = param_2, param_2 = puVar5, param_2 != (undefined4 *)0x0) {
      iVar2 = SameDomainName(param_2[8],param_3 + 0x154);
      puVar5 = (undefined4 *)*param_2;
      if (iVar2 != 0) {
        *puVar7 = (undefined4 *)*param_2;
        *param_2 = 0;
        uVar3 = AllocateAnonInfo(0,0,0);
        *(undefined4 *)(param_3 + 0x44) = uVar3;
        uVar4 = DomainNameHashValue(param_2[8]);
        puVar5 = (undefined4 *)param_2[9];
        if ((puVar5 != (undefined4 *)0x0) && (puVar5 != param_2 + 0x1c)) {
          mDNSPlatformMemFree(puVar5);
        }
        param_2[9] = 0;
        iVar2 = CacheGroupForName(param_1,uVar4 % 499,param_2[5],param_2[8]);
        if ((iVar2 == 0) && (mDNS_LoggingEnabled != 0)) {
          uVar6 = param_2[8];
          uVar3 = DNSTypeName(*(undefined2 *)((int)param_2 + 6));
          LogMsgWithLevel(3,"ReleaseCacheRecord: ERROR!! cg NULL for %##s (%s)",uVar6,uVar3);
        }
        __ptr = (void *)param_2[8];
        if (((__ptr != (void *)0x0) && (iVar2 != 0)) && (__ptr != *(void **)(iVar2 + 0x10))) {
          mDNSPlatformMemFree(__ptr);
        }
        param_2[8] = 0;
        if (param_2[0xb] != 0) {
          FreeAnonInfo();
        }
        param_2[0xb] = 0;
        if (param_2[7] == 0) {
          *(uint *)(param_1 + 0x2d0) = *(int *)(param_1 + 0x2d0) - (uint)*(ushort *)(param_2 + 4);
[32m          sVar1 = *(short *)((int)param_2 + 6);[0m
          if ((((ushort)(sVar1 - 0x2eU) < 3) || (sVar1 == 0x2b)) || (sVar1 == 0x32)) {
            BumpDNSSECStats(param_1,1,0,*(undefined2 *)(param_2 + 4));
          }
        }
        FUN_0042e080(param_1,param_2 + 0x15);
        FUN_0042e080(param_1,param_2 + 0x16);
        *param_2 = *(undefined4 *)(param_1 + 0x2dc);
        *(undefined4 **)(param_1 + 0x2dc) = param_2;
        *(int *)(param_1 + 0x2cc) = *(int *)(param_1 + 0x2cc) + -1;
        return;
      }
    }
  }
  return;
}

[ASK_GPT] f847024f224b83e6
