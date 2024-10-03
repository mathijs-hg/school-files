
/* WARNING: Removing unreachable block (ram,0x00438ef0) */
/* WARNING: Removing unreachable block (ram,0x00439534) */

undefined4 mDNS_Deregister_internal(int param_1,int **param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  int **ppiVar7;
  undefined4 uVar8;
  undefined uVar9;
  int *piVar10;
  undefined4 *puVar11;
  int **ppiVar12;
  int **ppiVar13;
  
[32m  cVar1 = *(char *)(param_2 + 1);[0m
  ppiVar7 = (int **)(param_1 + 0x2160);
  if (param_2[0x1f] + -1 < (int *)0x2) {
    uVar5 = DomainNameHashValue(param_2[8]);
    iVar6 = FUN_00427c58(param_1 + 0x1278,uVar5 % 499,param_2 + 1);
    if (iVar6 == 0) {
      return 0;
    }
    ppiVar7 = *(int ***)(iVar6 + 8);
    ppiVar13 = (int **)(iVar6 + 8);
    while ((ppiVar12 = ppiVar7, ppiVar12 != (int **)0x0 && (ppiVar12 != param_2))) {
      ppiVar13 = ppiVar12;
      ppiVar7 = (int **)*ppiVar12;
    }
  }
  else {
    do {
      ppiVar13 = ppiVar7;
      ppiVar7 = (int **)*ppiVar13;
      if (ppiVar7 == (int **)0x0) goto LAB_00438f58;
    } while (ppiVar7 != param_2);
  }
  ppiVar7 = (int **)*ppiVar13;
LAB_00438f58:
  if (ppiVar7 == (int **)0x0) {
    ppiVar7 = *(int ***)(param_1 + 0x2164);
    ppiVar13 = (int **)(param_1 + 0x2164);
    while (ppiVar12 = ppiVar7, bVar4 = false, ppiVar12 != (int **)0x0) {
      if (ppiVar12 == param_2) {
        bVar4 = true;
[32m[32m        memcpy((void *)((int)param_2 + 0x4e),&zeroEthAddr,6);[0m[0m
        *(undefined *)(param_2 + 1) = 1;
        *(undefined *)(param_2 + 0x22) = 0;
        break;
      }
      ppiVar13 = ppiVar12;
      ppiVar7 = (int **)*ppiVar12;
    }
  }
  else {
    ppiVar7 = (int **)(param_1 + 0x2164);
    if (param_3 == 2) {
      for (puVar11 = *(undefined4 **)(param_1 + 0x2164); puVar11 != (undefined4 *)0x0;
          puVar11 = (undefined4 *)*puVar11) {
        if ((int *)puVar11[7] == param_2[7]) {
          bVar2 = *(byte *)(puVar11 + 1);
          bVar3 = *(byte *)(param_2 + 1);
          if (((((((bVar2 == bVar3) || ((bVar3 | bVar2) == 0x12)) || (bVar2 == 1)) || (bVar3 == 1))
               && ((*(short *)((int)puVar11 + 6) == *(short *)((int)param_2 + 6) &&
                   (*(short *)(puVar11 + 2) == *(short *)(param_2 + 2))))) &&
              (((int *)puVar11[5] == param_2[5] &&
               ((*(short *)(puVar11 + 4) == *(short *)(param_2 + 4) &&
                ((int *)puVar11[6] == param_2[6])))))) &&
             ((iVar6 = SameRDataBody(puVar11 + 1,param_2[9] + 1,SameDomainName), iVar6 != 0 &&
              (iVar6 = SameDomainName(puVar11[8],param_2[8]), iVar6 != 0)))) {
            *(undefined *)((int)puVar11 + 0x86) = 0xff;
          }
        }
      }
      bVar4 = false;
    }
    else {
      for (; piVar10 = *ppiVar7, piVar10 != (int *)0x0; ppiVar7 = (int **)*ppiVar7) {
        if ((int *)piVar10[7] == param_2[7]) {
          bVar2 = *(byte *)(piVar10 + 1);
          bVar3 = *(byte *)(param_2 + 1);
          if (((((bVar2 == bVar3) || ((bVar3 | bVar2) == 0x12)) || (bVar2 == 1)) || (bVar3 == 1)) &&
             (((((*(short *)((int)piVar10 + 6) == *(short *)((int)param_2 + 6) &&
                 (*(short *)(piVar10 + 2) == *(short *)(param_2 + 2))) &&
                (((int *)piVar10[5] == param_2[5] &&
                 ((*(short *)(piVar10 + 4) == *(short *)(param_2 + 4) &&
                  ((int *)piVar10[6] == param_2[6])))))) &&
               (iVar6 = SameRDataBody(piVar10 + 1,param_2[9] + 1,SameDomainName), iVar6 != 0)) &&
              (iVar6 = SameDomainName((*ppiVar7)[8],param_2[8]), iVar6 != 0)))) break;
        }
      }
      ppiVar12 = (int **)*ppiVar7;
      if (ppiVar12 == (int **)0x0) {
        bVar4 = false;
      }
      else {
        *ppiVar7 = *ppiVar12;
        if (param_2[0x1f] + -1 < (int *)0x2) {
          *ppiVar12 = (int *)0x0;
          iVar6 = FUN_004389bc(param_1,param_1 + 0x1278,ppiVar12);
          if (iVar6 == 0) {
            uVar8 = GetRRDisplayString_rdb(ppiVar12 + 1,ppiVar12[9] + 1,param_1 + 0x2f);
            LogMsgWithLevel(0,"mDNS_Deregister_internal: ERROR!! cannot insert %s",uVar8);
          }
        }
        else {
          *ppiVar12 = *param_2;
          *param_2 = (int *)ppiVar12;
        }
        *(undefined *)(ppiVar12 + 1) = *(undefined *)(param_2 + 1);
        bVar4 = false;
        *(undefined *)((int)ppiVar12 + 0x86) = *(undefined *)((int)param_2 + 0x86);
        *(undefined *)((int)ppiVar12 + 0x85) = *(undefined *)((int)param_2 + 0x85);
        *(undefined *)((int)ppiVar12 + 0x87) = *(undefined *)((int)param_2 + 0x87);
        *(undefined *)(ppiVar12 + 0x22) = *(undefined *)(param_2 + 0x22);
        *(undefined *)((int)ppiVar12 + 0x89) = *(undefined *)((int)param_2 + 0x89);
        ppiVar12[0x24] = param_2[0x24];
        *(undefined *)((int)ppiVar12 + 0x8b) = *(undefined *)((int)param_2 + 0x8b);
        ppiVar12[0x25] = param_2[0x25];
        ppiVar12[0x27] = param_2[0x27];
[32m[32m        memcpy(ppiVar12 + 0x28,param_2 + 0x28,0x10);[0m[0m
        ppiVar12[0x2f] = param_2[0x2f];
        ppiVar12[0x30] = param_2[0x30];
        ppiVar12[0x31] = param_2[0x31];
        ppiVar12[0x32] = param_2[0x32];
        *(undefined *)(ppiVar12 + 0x3c) = *(undefined *)(param_2 + 0x3c);
        ppiVar12[0x39] = param_2[0x39];
        *(undefined *)(param_2 + 0x22) = 0;
        *(undefined *)((int)param_2 + 0x89) = 0;
      }
    }
  }
  if (*ppiVar13 == (int *)0x0) {
    if (param_3 != 3) {
      uVar8 = GetRRDisplayString_rdb(param_2 + 1,param_2[9] + 1,param_1 + 0x2f);
      LogMsgWithLevel(0,"mDNS_Deregister_internal: Record %p not found in list %s",param_2,uVar8);
    }
LAB_00439318:
    uVar8 = 0xfffefffb;
  }
  else {
    if (((param_2[7] == (int *)0x0) && (*(char *)((int)param_2 + 0x4a) == '\0')) &&
       (iVar6 = IsLocalDomain(param_2[8]), iVar6 == 0)) {
      if (*(char *)(param_2 + 0x22) != '\0') {
        if (param_2[0x41] != (int *)0x0) {
          DisposeTCPConn();
          param_2[0x41] = (int *)0x0;
        }
        *(undefined *)(param_2 + 1) = 1;
        *(undefined *)(param_1 + 0x274) = 1;
        uDNS_DeregisterRecord(param_1,param_2);
        return 0;
      }
      *(undefined2 *)((int)param_2 + 0xf2) = 0;
      if (param_2[0x53] != (int *)0x0) {
        mDNS_StopNATOperation_internal(param_1,param_2 + 0x42);
        param_2[0x53] = (int *)0x0;
      }
      if (param_2[0x40] != (int *)0x0) {
        CancelGetZoneData(param_1);
        param_2[0x40] = (int *)0x0;
      }
      if (param_2[0x41] != (int *)0x0) {
        DisposeTCPConn();
        param_2[0x41] = (int *)0x0;
      }
    }
    if (cVar1 == '\0') {
      uVar8 = GetRRDisplayString_rdb(param_2 + 1,param_2[9] + 1,param_1 + 0x2f);
      LogMsgWithLevel(0,"mDNS_Deregister_internal: %s already marked kDNSRecordTypeUnregistered",
                      uVar8);
    }
    else if (cVar1 == '\x01') {
      uVar8 = GetRRDisplayString_rdb(param_2 + 1,param_2[9] + 1,param_1 + 0x2f);
      LogMsgWithLevel(0,"mDNS_Deregister_internal: %s already marked kDNSRecordTypeDeregistering",
                      uVar8);
      goto LAB_00439318;
    }
    if ((*(int *)((int)param_2 + 0x4e) == 0) &&
       ((cVar1 != '\b' || (((uint)param_2[0x22] & 0xffff0000) == 0)))) {
      if ((bVar4) || ((int *)0x1 < param_2[0x1f] + -1)) {
        *ppiVar13 = *param_2;
        if (*(int ***)(param_1 + 0x2168) == param_2) {
          *(int **)(param_1 + 0x2168) = *param_2;
        }
        if (param_2[0x1f] + -1 < (int *)0x2) {
          if (mDNS_LoggingEnabled != 0) {
            uVar8 = GetRRDisplayString_rdb(param_2 + 1,param_2[9] + 1,param_1 + 0x2f);
            LogMsgWithLevel(3,"DecrementAutoTargetServices: called for RRLocalOnly() record: %s",
                            uVar8);
          }
        }
        else if ((((param_2[7] != (int *)0x0) || (*(char *)((int)param_2 + 0x4a) != '\0')) ||
                 (iVar6 = IsLocalDomain(param_2[8]), iVar6 != 0)) &&
                ((*(short *)((int)param_2 + 6) == 0x21 && (*(char *)(param_2 + 0x12) == '\x01')))) {
          if (*(int *)(param_1 + 0x3908) == 1) {
            FUN_004399d4(param_1);
          }
          iVar6 = *(int *)(param_1 + 0x3908) + -1;
          *(int *)(param_1 + 0x3908) = iVar6;
          if (mDNS_LoggingEnabled != 0) {
            uVar8 = GetRRDisplayString_rdb(param_2 + 1,param_2[9] + 1,param_1 + 0x2f);
            LogMsgWithLevel(3,"DecrementAutoTargetServices: AutoTargetServices %d Record %s",iVar6,
                            uVar8);
          }
        }
      }
      else {
        iVar6 = FUN_0042801c(param_1,param_1 + 0x1278,param_2);
        if (*(int ***)(iVar6 + 0x14) == param_2) {
          *(int **)(iVar6 + 0x14) = *param_2;
        }
      }
      if (*(int ***)(param_1 + 0x216c) == param_2) {
        *(int **)(param_1 + 0x216c) = *param_2;
      }
      *param_2 = (int *)0x0;
      *(undefined *)(param_2 + 1) = 0;
      if (param_2[0x33] != (int *)0x0) {
        FUN_0042cb70(param_1,param_2);
      }
      if (param_3 == 2) {
        FUN_004276dc(param_1,param_2);
        iVar6 = *(int *)(param_1 + 0x28) + 1;
        *(int *)(param_1 + 0x28) = iVar6;
        if (*(int *)(param_1 + 0x24) != iVar6) {
          LogMsgWithLevel(0,"%s: Locking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                          "mDNS_Deregister_internal",*(int *)(param_1 + 0x24),iVar6);
        }
        if (param_2[0x10] != (int *)0x0) {
          (*(code *)param_2[0x10])(param_1,param_2,0xfffefff4);
        }
        iVar6 = *(int *)(param_1 + 0x28);
        if (*(int *)(param_1 + 0x24) != iVar6) {
          LogMsgWithLevel(0,"%s: Unlocking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                          "mDNS_Deregister_internal",*(int *)(param_1 + 0x24),iVar6);
          iVar6 = *(int *)(param_1 + 0x28);
        }
        puVar11 = *(undefined4 **)(param_1 + 0x2164);
        *(int *)(param_1 + 0x28) = iVar6 + -1;
        while (puVar11 != (undefined4 *)0x0) {
          if (*(char *)((int)puVar11 + 0x86) == -1) {
            mDNS_Deregister_internal(param_1,puVar11,2);
            puVar11 = *(undefined4 **)(param_1 + 0x2164);
          }
          else {
            puVar11 = (undefined4 *)*puVar11;
          }
        }
      }
      else {
        iVar6 = *(int *)(param_1 + 0x28) + 1;
        *(int *)(param_1 + 0x28) = iVar6;
        if (*(int *)(param_1 + 0x24) != iVar6) {
          LogMsgWithLevel(0,"%s: Locking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                          "mDNS_Deregister_internal",*(int *)(param_1 + 0x24),iVar6);
        }
        if (mDNS_LoggingEnabled != 0) {
          uVar8 = GetRRDisplayString_rdb(param_2 + 1,param_2[9] + 1,param_1 + 0x2f);
          LogMsgWithLevel(3,"mDNS_Deregister_internal: mStatus_MemFree for %s",uVar8);
        }
        if (param_2[0x10] != (int *)0x0) {
          (*(code *)param_2[0x10])(param_1,param_2,0xfffeff00);
        }
        iVar6 = *(int *)(param_1 + 0x28);
        if (*(int *)(param_1 + 0x24) != iVar6) {
          LogMsgWithLevel(0,"%s: Unlocking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                          "mDNS_Deregister_internal",*(int *)(param_1 + 0x24),iVar6);
          iVar6 = *(int *)(param_1 + 0x28);
        }
        *(int *)(param_1 + 0x28) = iVar6 + -1;
      }
    }
    else {
      *(undefined *)(param_2 + 1) = 1;
      param_2[3] = (int *)0x0;
      uVar9 = 0x12;
      if ((*(int *)((int)param_2 + 0x4e) == 0) && (uVar9 = 3, param_3 == 1)) {
        uVar9 = 1;
      }
      *(undefined *)((int)param_2 + 0x87) = uVar9;
      iVar6 = mDNSPlatformOneSecond;
      param_2[0x2f] = (int *)(mDNSPlatformOneSecond * 2);
      param_2[0x30] = (int *)(*(int *)(param_1 + 0x234) + iVar6 * -2);
      *(undefined *)(param_1 + 0x274) = 1;
      iVar6 = mDNSPlatformOneSecond / 10 + *(int *)(param_1 + 0x234);
      if (-1 < *(int *)(param_1 + 0x254) - iVar6) {
        *(int *)(param_1 + 0x254) = iVar6;
      }
    }
    FUN_0042f54c(param_1);
    uVar8 = 0;
  }
  return uVar8;
}

[ASK_GPT] 80d2e148afa6c652
