
/* WARNING: Removing unreachable block (ram,0x00446bf0) */
/* WARNING: Removing unreachable block (ram,0x00446684) */
/* WARNING: Removing unreachable block (ram,0x00446df0) */

undefined4 mDNS_Register_internal(int param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined *puVar7;
  undefined2 uVar9;
  int *piVar8;
  undefined uVar11;
  int *piVar10;
  char *pcVar12;
  int **ppiVar13;
  int *piVar14;
  int iVar15;
  int **ppiVar16;
  int **ppiVar17;
  int **ppiVar18;
  code *pcVar19;
  undefined auStack_48 [24];
  int **local_30;
  int local_2c;
  
[32m  sVar3 = *(short *)((int)param_2 + 6);[0m
  if ((((sVar3 == 2) || (sVar3 == 5)) || (sVar3 == 0xc)) || (sVar3 == 0x27)) {
    piVar14 = (int *)(param_2[9] + 4);
  }
  else if (((sVar3 == 0xf) || (sVar3 == 0x12)) || ((sVar3 == 0x15 || (sVar3 == 0x24)))) {
    piVar14 = (int *)(param_2[9] + 6);
  }
  else {
    piVar14 = (int *)0x0;
    if (sVar3 == 0x21) {
      piVar14 = (int *)(param_2[9] + 10);
    }
  }
  iVar15 = param_2[3];
  if (iVar15 < 1) {
    uVar4 = GetRRDisplayString_rdb(param_2 + 1,param_2[9] + 4,param_1 + 0x2f);
    LogMsgWithLevel(0,"mDNS_Register_internal: TTL %X should be 1 - 0x7FFFFFFF %s",iVar15,uVar4);
  }
  else {
    if (*(char *)(param_2 + 1) != '\0') {
      if (*(int *)(param_1 + 0x240) != 0) {
        uVar4 = GetRRDisplayString_rdb(param_2 + 1,param_2[9] + 4,param_1 + 0x2f);
        LogMsgWithLevel(0,"mDNS_Register_internal: Shutting down, can\'t register %s",uVar4);
        return 0xfffeffe5;
      }
      if ((*(char *)(param_1 + 10) != '\0') &&
         (((param_2[7] != 0 || (*(char *)((int)param_2 + 0x4a) != '\0')) ||
          (iVar15 = IsLocalDomain(param_2[8],param_2,param_1 + 0x2f), iVar15 != 0)))) {
        iVar15 = param_2[7];
        if ((iVar15 == 0) || (iVar15 == -4)) {
          param_2[0x1f] = 4;
          param_2[7] = -2;
        }
        if (param_2[7] != -2) {
          for (puVar5 = *(undefined4 **)(param_1 + 0x2174); puVar5 != (undefined4 *)0x0;
              puVar5 = (undefined4 *)*puVar5) {
            if (puVar5[0x548] == param_2[7]) {
              if (*(char *)((int)puVar5 + 0x1592) == '\0') {
                param_2[7] = -2;
                param_2[0x1f] = 4;
              }
              break;
            }
          }
        }
        if ((param_2[7] != iVar15) && (mDNS_LoggingEnabled != 0)) {
          uVar4 = GetRRDisplayString_rdb(param_2 + 1,param_2[9] + 4,param_1 + 0x2f);
          LogMsgWithLevel(3,"mDNS_Register_internal: Diverting record to local-only %s",uVar4);
        }
      }
      ppiVar17 = (int **)(param_1 + 0x2160);
      if (param_2[0x1f] - 4U < 2) {
        uVar6 = DomainNameHashValue(param_2[8]);
        iVar15 = FUN_00427c58(param_1 + 0x1278,uVar6 % 499,param_2 + 1);
        ppiVar18 = (int **)(param_1 + 0x2164);
        if (iVar15 != 0) {
          for (ppiVar13 = *(int ***)(iVar15 + 8); ppiVar18 = (int **)(param_1 + 0x2164),
              ppiVar13 != (int **)0x0; ppiVar13 = (int **)*ppiVar13) {
            if (ppiVar13 == (int **)param_2) {
              local_2c = (int)ppiVar13[8];
              local_30 = ppiVar13;
              uVar4 = DNSTypeName(*(undefined2 *)((int)ppiVar13 + 6));
              pcVar12 = 
              "mDNS_Register_internal: ERROR!! Tried to register LocalOnly AuthRecord %p %##s (%s) that\'s already in the list"
              ;
              param_2 = (int *)local_30;
              goto LAB_00446780;
            }
          }
        }
LAB_00446744:
        do {
          ppiVar13 = (int **)*ppiVar18;
          if (ppiVar13 == (int **)0x0) {
            if (param_2[0xe] != 0) {
              if (*(char *)(param_2 + 1) != '\x02') {
                local_30 = (int **)param_2[8];
                uVar4 = DNSTypeName(*(undefined2 *)((int)param_2 + 6));
                LogMsgWithLevel(0,
                                "mDNS_Register_internal: ERROR! %##s (%s): rr->DependentOn && RecordType != kDNSRecordTypeUnique"
                                ,local_30,uVar4);
                return 0xfffefff3;
              }
              *(undefined *)(param_2 + 1) = 0x10;
              if ((*(byte *)(param_2[0xe] + 4) & 0x32) == 0) {
                local_30 = (int **)param_2[8];
                uVar4 = DNSTypeName(*(undefined2 *)((int)param_2 + 6));
                LogMsgWithLevel(0,
                                "mDNS_Register_internal: ERROR! %##s (%s): rr->DependentOn->RecordType bad type %X"
                                ,local_30,uVar4,*(undefined *)(param_2[0xe] + 4));
                return 0xfffefff3;
              }
            }
            *param_2 = 0;
            if ((*(char *)(param_2 + 0x12) != '\0') && (piVar14 != (int *)0x0)) {
              *(undefined *)piVar14 = 0;
            }
            uVar11 = 3;
            if (*(char *)(param_2 + 1) != '\x02') {
              uVar11 = 0;
            }
            *(undefined *)((int)param_2 + 0x87) = 4;
            *(undefined *)((int)param_2 + 0x86) = uVar11;
            *(undefined *)(param_2 + 0x21) = 0;
            param_2[0x27] = 0;
            *(undefined *)((int)param_2 + 0x85) = 0;
            *(undefined *)(param_2 + 0x22) = 0;
            *(undefined *)((int)param_2 + 0x89) = 0;
            *(undefined *)((int)param_2 + 0x8a) = 0;
            *(undefined *)((int)param_2 + 0x8b) = 0;
            param_2[0x23] = 0;
            param_2[0x24] = 0;
            param_2[0x25] = 0;
            param_2[0x26] = 0;
[32m[32m            memcpy(param_2 + 0x28,zerov6Addr,0x10);[0m[0m
            param_2[0x2c] = 0;
            param_2[0x2d] = 0;
            param_2[0x2e] = 0;
            if (*(char *)(param_2 + 0x12) == '\0') {
              FUN_00428828(param_1,param_2);
            }
            param_2[0x36] = 10;
            param_2[0x33] = 0;
            *(undefined2 *)(param_2 + 0x34) = 0;
            param_2[0x35] = 0;
            param_2[0x37] = 0;
            param_2[0x38] = 0;
            if ((*(int *)((int)param_2 + 0x4e) != 0) && (param_2[0x18] == 0)) {
              *(undefined *)((int)param_2 + 0x87) = 2;
            }
            param_2[0x3f] = param_2[8];
            *(undefined2 *)((int)param_2 + 0xf2) = 0;
            param_2[0x3d] = 0;
            param_2[0x3e] = 0;
            param_2[0x39] = 0;
            *(undefined *)(param_2 + 0x3a) = 0;
            param_2[0x3b] = 0;
            *(undefined *)(param_2 + 0x3c) = 0;
            param_2[0x40] = 0;
            param_2[0x41] = 0;
            param_2[0x5b] = 0;
            *(undefined2 *)(param_2 + 0x59) = 0;
            param_2[0x5c] = 0;
            *(undefined2 *)((int)param_2 + 0x166) = 0;
            param_2[0x5d] = 0;
            *(undefined2 *)(param_2 + 0x5a) = 0;
            if ((*(short *)((int)param_2 + 6) == 0x10) && (*(short *)(param_2 + 4) == 0)) {
              *(undefined2 *)(param_2 + 4) = 1;
              *(undefined *)(param_2[9] + 4) = 0;
            }
            if (*(char *)(param_2 + 0x12) == '\0') {
              uVar9 = GetRDLength(param_2 + 1,0);
              *(undefined2 *)(param_2 + 4) = uVar9;
              uVar9 = GetRDLength(param_2 + 1,1);
              *(undefined2 *)((int)param_2 + 0x12) = uVar9;
            }
            else {
              FUN_0042cc08(param_1,param_2);
              if (param_2[0x39] == 8) {
[32m                sVar3 = *(short *)((int)param_2 + 6);[0m
                if ((((sVar3 == 2) || (sVar3 == 5)) || (sVar3 == 0xc)) || (sVar3 == 0x27)) {
                  puVar7 = (undefined *)(param_2[9] + 4);
LAB_00446a3c:
                  if (puVar7 != (undefined *)0x0) {
                    *puVar7 = 0;
                  }
                }
                else {
                  if (((sVar3 == 0xf) || (sVar3 == 0x12)) || ((sVar3 == 0x15 || (sVar3 == 0x24)))) {
                    puVar7 = (undefined *)(param_2[9] + 6);
                    goto LAB_00446a3c;
                  }
                  if (sVar3 == 0x21) {
                    puVar7 = (undefined *)(param_2[9] + 10);
                    goto LAB_00446a3c;
                  }
                }
                if (mDNS_LoggingEnabled != 0) {
                  uVar4 = GetRRDisplayString_rdb(param_2 + 1,param_2[9] + 4,param_1 + 0x2f);
                  LogMsgWithLevel(3,"mDNS_Register_internal: record %s in NoTarget state",uVar4);
                }
              }
            }
            uVar6 = DomainNameLengthLimit(param_2[8],param_2[8] + 0x100);
            if (0x100 < uVar6) {
              uVar4 = GetRRDisplayString_rdb(param_2 + 1,param_2[9] + 4,param_1 + 0x2f);
              pcVar12 = "Attempt to register record with invalid name: %s";
LAB_00446b50:
              LogMsgWithLevel(0,pcVar12,uVar4);
              return 0xfffefff3;
            }
            iVar15 = ValidateRData(*(undefined2 *)((int)param_2 + 6),*(undefined2 *)(param_2 + 4));
            if (iVar15 == 0) {
              uVar4 = GetRRDisplayString_rdb(param_2 + 1,param_2[9] + 4,param_1 + 0x2f);
              pcVar12 = "Attempt to register record with invalid rdata: %s";
              goto LAB_00446b50;
            }
            iVar15 = DomainNameHashValue(param_2[8]);
            param_2[5] = iVar15;
            if (piVar14 == (int *)0x0) {
              pcVar19 = RDataHashValue;
              piVar14 = param_2 + 1;
            }
            else {
              pcVar19 = DomainNameHashValue;
            }
            iVar15 = (*pcVar19)(piVar14);
            param_2[6] = iVar15;
            if ((param_2[0x1f] - 4U < 2) && ((*(byte *)(param_2 + 1) & 0x32) != 0)) {
              uVar6 = DomainNameHashValue(param_2[8]);
              iVar15 = FUN_00427c58(param_1 + 0x1278,uVar6 % 499,param_2 + 1);
              ppiVar13 = (int **)(iVar15 + 8);
              if (iVar15 != 0) {
                for (; piVar14 = *ppiVar13, piVar14 != (int *)0x0; ppiVar13 = (int **)*ppiVar13) {
                  piVar10 = (int *)param_2[0xf];
                  if ((int *)param_2[0xf] == (int *)0x0) {
                    piVar10 = param_2;
                  }
                  piVar8 = (int *)piVar14[0xf];
                  if ((int *)piVar14[0xf] == (int *)0x0) {
                    piVar8 = piVar14;
                  }
                  if (((piVar10 != piVar8) &&
                      (*(short *)((int)piVar14 + 6) == *(short *)((int)param_2 + 6))) &&
                     (iVar15 = FUN_00427870(piVar14,param_2), iVar15 != 0)) {
                    piVar14 = *ppiVar13;
                    if (((*(short *)((int)piVar14 + 6) != *(short *)((int)param_2 + 6)) ||
                        (*(short *)(piVar14 + 2) != *(short *)(param_2 + 2))) ||
                       ((*(short *)(piVar14 + 4) != *(short *)(param_2 + 4) ||
                        ((piVar14[6] != param_2[6] ||
                         (iVar15 = SameRDataBody(piVar14 + 1,param_2[9] + 4,SameDomainName),
                         iVar15 == 0)))))) {
                      if (mDNS_LoggingEnabled != 0) {
                        uVar4 = GetRRDisplayString_rdb(param_2 + 1,param_2[9] + 4,param_1 + 0x2f);
                        LogMsgWithLevel(3,
                                        "mDNS_Register_internal: Name conflict %s (%p), InterfaceID %p"
                                        ,uVar4,param_2,param_2[7]);
                      }
                      return 0xfffefff4;
                    }
                  }
                }
              }
            }
            if (((param_2[7] == 0) && (*(char *)((int)param_2 + 0x4a) == '\0')) &&
               (iVar15 = IsLocalDomain(param_2[8]), iVar15 == 0)) {
              if (*(int *)(param_1 + 0x2168) == 0) {
                *(int **)(param_1 + 0x2168) = param_2;
              }
              do {
                ppiVar18 = ppiVar17;
                ppiVar17 = (int **)*ppiVar18;
              } while (ppiVar17 != (int **)0x0);
              *ppiVar18 = param_2;
              if (*(char *)(param_2 + 1) == '\x02') {
                *(undefined *)(param_2 + 1) = 0x10;
              }
              *(undefined *)((int)param_2 + 0x86) = 0;
              *(undefined *)((int)param_2 + 0x85) = 0;
              *(undefined *)((int)param_2 + 0x87) = 0;
              if (param_2[0x39] == 8) {
                return 0;
              }
              ActivateUnicastRegistration(param_1,param_2);
              return 0;
            }
            if (param_2[0x1f] - 4U < 2) {
              *(undefined *)((int)param_2 + 0x86) = 0;
              *(undefined *)((int)param_2 + 0x85) = 0;
              *(undefined *)((int)param_2 + 0x87) = 0;
              uVar6 = DomainNameHashValue(param_2[8]);
              iVar15 = FUN_00427c58(param_1 + 0x1278,uVar6 % 499,param_2 + 1);
              ppiVar16 = (int **)(iVar15 + 8);
              if (iVar15 != 0) {
                for (; piVar14 = *ppiVar16, piVar14 != (int *)0x0; ppiVar16 = (int **)*ppiVar16) {
                  if (piVar14[7] == param_2[7]) {
                    bVar1 = *(byte *)(piVar14 + 1);
                    bVar2 = *(byte *)(param_2 + 1);
                    if ((((bVar1 == bVar2) || ((bVar2 | bVar1) == 0x12)) ||
                        ((bVar1 == 1 || (bVar2 == 1)))) &&
                       (((*(short *)((int)piVar14 + 6) == *(short *)((int)param_2 + 6) &&
                         (*(short *)(piVar14 + 2) == *(short *)(param_2 + 2))) &&
                        ((piVar14[5] == param_2[5] &&
                         ((((*(short *)(piVar14 + 4) == *(short *)(param_2 + 4) &&
                            (piVar14[6] == param_2[6])) &&
                           (iVar15 = SameRDataBody(piVar14 + 1,param_2[9] + 4,SameDomainName),
                           iVar15 != 0)) &&
                          (iVar15 = SameDomainName((*ppiVar16)[8],param_2[8]), iVar15 != 0)))))))) {
                      ppiVar13 = (int **)*ppiVar16;
                      if (*(char *)((int *)ppiVar13 + 1) != '\x01') {
                        if (ppiVar13 != (int **)0x0) goto LAB_0044701c;
                        break;
                      }
                      *(undefined *)((int)ppiVar13 + 0x87) = 0;
                    }
                  }
                }
              }
            }
            else {
              for (ppiVar13 = *(int ***)(param_1 + 0x2160); ppiVar13 != (int **)0x0;
                  ppiVar13 = (int **)*ppiVar13) {
                if (ppiVar13[7] == (int *)param_2[7]) {
                  bVar1 = *(byte *)(ppiVar13 + 1);
                  bVar2 = *(byte *)(param_2 + 1);
                  if ((((bVar1 == bVar2) || ((bVar2 | bVar1) == 0x12)) ||
                      ((bVar1 == 1 || (bVar2 == 1)))) &&
                     ((((*(short *)((int)ppiVar13 + 6) == *(short *)((int)param_2 + 6) &&
                        (*(short *)(ppiVar13 + 2) == *(short *)(param_2 + 2))) &&
                       (ppiVar13[5] == (int *)param_2[5])) &&
                      ((((*(short *)(ppiVar13 + 4) == *(short *)(param_2 + 4) &&
                         (ppiVar13[6] == (int *)param_2[6])) &&
                        (iVar15 = SameRDataBody(ppiVar13 + 1,param_2[9] + 4,SameDomainName),
                        iVar15 != 0)) &&
                       (iVar15 = SameDomainName(ppiVar13[8],param_2[8]), iVar15 != 0)))))) {
                    if (*(char *)(ppiVar13 + 1) != '\x01') {
LAB_0044701c:
                      *ppiVar18 = param_2;
                      if ((*(char *)(param_2 + 1) == '\x02') &&
                         (*(char *)((int *)ppiVar13 + 1) == '\x10')) {
                        *(undefined *)((int)param_2 + 0x86) = 0;
                      }
                      goto LAB_004470bc;
                    }
                    *(undefined *)((int)ppiVar13 + 0x87) = 0;
                  }
                }
              }
            }
            if (param_2[0x1f] - 4U < 2) {
              iVar15 = FUN_004389bc(param_1,param_1 + 0x1278,param_2);
              if ((iVar15 != 0) && (*(int *)(iVar15 + 0x14) == 0)) {
                *(undefined *)(param_1 + 0x2170) = 1;
                *(int **)(iVar15 + 0x14) = param_2;
              }
              if (*(char *)(param_2 + 1) == '\x02') {
                *(undefined *)(param_2 + 1) = 0x10;
              }
              FUN_00426c2c(param_1,param_2);
              return 0;
            }
            if (*(int *)(param_1 + 0x2168) == 0) {
              *(int **)(param_1 + 0x2168) = param_2;
            }
            *ppiVar17 = param_2;
LAB_004470bc:
            if ((*(int *)((int)param_2 + 0x4e) == 0) && (*(short *)((int)param_2 + 6) == 10)) {
              uVar6 = (uint)*(byte *)param_2[8];
              iVar15 = uVar6 + 1;
              if (uVar6 == 0) {
                iVar15 = 0;
              }
              iVar15 = SameDomainLabel((byte *)param_2[8] + iVar15,"\n_keepalive");
              if (iVar15 != 0) {
                *(undefined *)(param_2 + 1) = 0x20;
                *(undefined *)((int)param_2 + 0x87) = 0;
                FUN_0042b250(param_1,param_2,auStack_48);
                mDNSPlatformGetRemoteMacAddr(param_1,auStack_48);
              }
            }
            if (((param_2[7] == 0) && (*(char *)((int)param_2 + 0x4a) == '\0')) &&
               (iVar15 = IsLocalDomain(param_2[8]), iVar15 == 0)) {
              return 0;
            }
            if (param_2[0x1f] - 4U < 2) {
              if (mDNS_LoggingEnabled != 0) {
                uVar4 = GetRRDisplayString_rdb(param_2 + 1,param_2[9] + 4,param_1 + 0x2f);
                LogMsgWithLevel(3,"IncrementAutoTargetServices: called for RRLocalOnly() record: %s"
                                ,uVar4);
              }
            }
            else if ((((param_2[7] != 0) || (*(char *)((int)param_2 + 0x4a) != '\0')) ||
                     (iVar15 = IsLocalDomain(param_2[8]), iVar15 != 0)) &&
                    ((*(short *)((int)param_2 + 6) == 0x21 && (*(char *)(param_2 + 0x12) == '\x01'))
                    )) {
              iVar15 = *(int *)(param_1 + 0x3908) + 1;
              *(int *)(param_1 + 0x3908) = iVar15;
              if (mDNS_LoggingEnabled != 0) {
                uVar4 = GetRRDisplayString_rdb(param_2 + 1,param_2[9] + 4,param_1 + 0x2f);
                LogMsgWithLevel(3,"IncrementAutoTargetServices: AutoTargetServices %d Record %s",
                                iVar15,uVar4);
              }
              if (*(int *)(param_1 + 0x3908) == 1) {
                FUN_004477f0(param_1);
              }
            }
            if (1 < (byte)(*(char *)(param_2 + 1) - 1U)) {
              FUN_00426c2c(param_1,param_2);
            }
            FUN_0042f54c(param_1);
            return 0;
          }
          ppiVar18 = ppiVar13;
        } while (ppiVar13 != (int **)param_2);
        local_2c = param_2[8];
        uVar4 = DNSTypeName(*(undefined2 *)((int)param_2 + 6));
        pcVar12 = 
        "mDNS_Register_internal: ERROR!! Tried to register AuthRecord %p %##s (%s) that\'s already in the Duplicate list"
        ;
      }
      else {
        do {
          ppiVar13 = (int **)*ppiVar17;
          ppiVar18 = (int **)(param_1 + 0x2164);
          if (ppiVar13 == (int **)0x0) goto LAB_00446744;
          ppiVar17 = ppiVar13;
        } while (ppiVar13 != (int **)param_2);
        local_2c = param_2[8];
        uVar4 = DNSTypeName(*(undefined2 *)((int)param_2 + 6));
        pcVar12 = 
        "mDNS_Register_internal: ERROR!! Tried to register AuthRecord %p %##s (%s) that\'s already in the list"
        ;
      }
LAB_00446780:
      LogMsgWithLevel(0,pcVar12,param_2,local_2c,uVar4);
      return 0xfffefff5;
    }
    uVar4 = GetRRDisplayString_rdb(param_2 + 1,param_2[9] + 4);
    LogMsgWithLevel(0,"mDNS_Register_internal: RecordType must be non-zero %s",uVar4);
  }
  return 0xfffefffc;
}

[ASK_GPT] 3a2134c6dcba21c4
