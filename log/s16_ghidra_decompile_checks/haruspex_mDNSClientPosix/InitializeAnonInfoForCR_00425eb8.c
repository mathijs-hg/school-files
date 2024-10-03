
/* WARNING: Removing unreachable block (ram,0x0042e220) */

void InitializeAnonInfoForCR(int param_1,undefined4 *param_2,int param_3)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  void *__ptr;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  
  if ((((undefined4 *)*param_2 != (undefined4 *)0x0) && (*(int *)(param_3 + 0x2c) == 0)) &&
     (*(short *)(param_3 + 6) == 0xc)) {
    uVar7 = *(undefined4 *)(param_3 + 0x20);
    puVar4 = (undefined4 *)*param_2;
    do {
      puVar6 = puVar4;
      iVar2 = SameDomainName(puVar6[8],uVar7);
      puVar4 = (undefined4 *)*puVar6;
      if (iVar2 != 0) {
        *param_2 = puVar4;
        *puVar6 = 0;
        uVar7 = AllocateAnonInfo(0,0,0);
        *(undefined4 *)(param_3 + 0x2c) = uVar7;
        uVar3 = DomainNameHashValue(puVar6[8]);
        puVar4 = (undefined4 *)puVar6[9];
        if ((puVar4 != (undefined4 *)0x0) && (puVar4 != puVar6 + 0x1c)) {
          mDNSPlatformMemFree(puVar4);
        }
        puVar6[9] = 0;
        iVar2 = CacheGroupForName(param_1,uVar3 % 499,puVar6[5],puVar6[8]);
        if ((iVar2 == 0) && (mDNS_LoggingEnabled != 0)) {
          uVar5 = puVar6[8];
          uVar7 = DNSTypeName(*(undefined2 *)((int)puVar6 + 6));
          LogMsgWithLevel(3,"ReleaseCacheRecord: ERROR!! cg NULL for %##s (%s)",uVar5,uVar7);
        }
        __ptr = (void *)puVar6[8];
        if (((__ptr != (void *)0x0) && (iVar2 != 0)) && (__ptr != *(void **)(iVar2 + 0x10))) {
          mDNSPlatformMemFree(__ptr);
        }
        puVar6[8] = 0;
        if (puVar6[0xb] != 0) {
          FreeAnonInfo();
        }
        puVar6[0xb] = 0;
        if (puVar6[7] == 0) {
          *(uint *)(param_1 + 0x2d0) = *(int *)(param_1 + 0x2d0) - (uint)*(ushort *)(puVar6 + 4);
[32m          sVar1 = *(short *)((int)puVar6 + 6);[0m
          if ((((ushort)(sVar1 - 0x2eU) < 3) || (sVar1 == 0x2b)) || (sVar1 == 0x32)) {
            BumpDNSSECStats(param_1,1,0,*(undefined2 *)(puVar6 + 4));
          }
        }
        FUN_0042e080(param_1,puVar6 + 0x15);
        FUN_0042e080(param_1,puVar6 + 0x16);
        *puVar6 = *(undefined4 *)(param_1 + 0x2dc);
        *(undefined4 **)(param_1 + 0x2dc) = puVar6;
        *(int *)(param_1 + 0x2cc) = *(int *)(param_1 + 0x2cc) + -1;
        return;
      }
      param_2 = puVar6;
    } while (puVar4 != (undefined4 *)0x0);
  }
  return;
}

[ASK_GPT] 419bb3c0a3dcf07a
