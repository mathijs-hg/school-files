
/* WARNING: Removing unreachable block (ram,0x0041675c) */

void uDNS_ReceiveMsg(int param_1,short *param_2,undefined4 param_3,int param_4,uint param_11)

{
  byte bVar1;
  undefined2 uVar2;
  short sVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  char *pcVar9;
  undefined *puVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  byte bVar15;
  int iVar16;
  uint in_stack_ffffffac;
  short local_38;
  
  bVar1 = *(byte *)((int)param_2 + 3);
  bVar15 = bVar1 & 0xf;
  if ((*(byte *)(param_2 + 1) & 0xf8) == 0x80) {
    iVar5 = FUN_0040ff8c();
    if (iVar5 == 0) {
      for (puVar14 = *(undefined4 **)(param_1 + 0x2ac); puVar14 != (undefined4 *)0x0;
          puVar14 = (undefined4 *)*puVar14) {
        if ((((*(byte *)(param_2 + 1) & 2) != 0) && (*(short *)((int)puVar14 + 0x152) == *param_2))
           && (*(int *)(param_1 + 0x234) - puVar14[3] < mDNSPlatformOneSecond * 0x3c)) {
          if (param_4 == 0) {
            LogMsgWithLevel(0,"uDNS_ReceiveMsg: TCP DNS response had TC bit set: ignoring");
          }
          else {
            if (puVar14[0x43] != 0) {
              DisposeTCPConn(puVar14[0x43]);
              puVar14[0x43] = 0;
            }
            in_stack_ffffffac = in_stack_ffffffac & 0xffff | param_11 & 0xffff0000;
            uVar6 = FUN_0041447c(param_1,0,0,0,param_4,in_stack_ffffffac,0,puVar14,0);
            puVar14[0x43] = uVar6;
          }
        }
      }
    }
  }
  else if ((*(byte *)(param_2 + 1) & 0xf8) == 0xa8) {
    iVar5 = GetPktLease();
    iVar16 = iVar5 * mDNSPlatformOneSecond + *(int *)(param_1 + 0x234);
    uVar6 = mDNSRandom((iVar5 * mDNSPlatformOneSecond) / 10);
    iVar12 = *(int *)(param_1 + 0x216c);
    if (iVar12 != 0) {
      uVar7 = GetRRDisplayString_rdb(iVar12 + 4,*(int *)(iVar12 + 0x24) + 4,param_1 + 0x2f);
      LogMsgWithLevel(0,"uDNS_ReceiveMsg ERROR m->CurrentRecord already set %s",uVar7);
    }
    iVar12 = param_1 + 0x2f;
    *(undefined4 *)(param_1 + 0x216c) = *(undefined4 *)(param_1 + 0x2160);
LAB_0041715c:
    puVar14 = *(undefined4 **)(param_1 + 0x216c);
    if (puVar14 != (undefined4 *)0x0) {
      *(undefined4 *)(param_1 + 0x216c) = *puVar14;
      if ((((puVar14[7] == 0) && (*(char *)((int)puVar14 + 0x4a) == '\0')) &&
          (iVar8 = IsLocalDomain(puVar14[8]), iVar8 == 0)) &&
         (*(short *)((int)puVar14 + 0xf2) == *param_2)) {
        uVar7 = puVar14[8];
        if ((bVar1 & 0xf) == 0) {
          iVar8 = 0;
          if (((*(char *)(puVar14 + 0x3a) != '\0') && (iVar5 != 0)) &&
             ((-1 < puVar14[0x3b] - iVar16 || (puVar14[0x39] != 7)))) {
            puVar14[0x3b] = iVar16;
            iVar8 = 0;
            *(undefined *)(puVar14 + 0x56) = 0;
          }
        }
        else if (bVar15 == 6) {
          iVar8 = -0x1000c;
        }
        else if (bVar15 == 5) {
          LogMsgWithLevel(0,"Update %##s refused",uVar7);
          iVar8 = -0x10011;
        }
        else if (bVar15 == 8) {
          LogMsgWithLevel(0,"Reregister refused (NXRRSET): %##s",uVar7);
          iVar8 = -0x10012;
        }
        else if (bVar15 == 9) {
          iVar8 = FUN_00410730(param_1,param_2,param_3,uVar7);
          if (iVar8 == 0) {
            pcVar9 = "Permission denied (NOAUTH): %##s";
LAB_00416920:
            LogMsgWithLevel(0,pcVar9,uVar7);
LAB_00416950:
            iVar8 = -0x10001;
          }
        }
        else {
          if (bVar15 != 1) {
            LogMsgWithLevel(0,"Update %##s failed with rcode %d",uVar7,bVar15);
            goto LAB_00416950;
          }
          iVar8 = FUN_00410730(param_1,param_2,param_3,uVar7);
          if (iVar8 == 0) {
            pcVar9 = "Format Error: %##s";
            goto LAB_00416920;
          }
        }
[32m        local_38 = 0;[0m
        if (*(int *)(param_1 + 0x24) != *(int *)(param_1 + 0x28) + 1) {
          LogMsgWithLevel(0,"%s: Lock not held! mDNS_busy (%ld) mDNS_reentrancy (%ld)",
                          "hndlRecordUpdateReply",*(int *)(param_1 + 0x24),*(int *)(param_1 + 0x28))
          ;
        }
        if (mDNS_LoggingEnabled != 0) {
          uVar2 = *(undefined2 *)((int)puVar14 + 0xf2);
          uVar11 = puVar14[0x39];
          uVar7 = GetRRDisplayString_rdb(puVar14 + 1,puVar14[9] + 4,iVar12);
          LogMsgWithLevel(3,"hndlRecordUpdateReply: err %d ID %d state %d %s(%p)",iVar8,uVar2,uVar11
                          ,uVar7,puVar14);
        }
        puVar14[0x57] = iVar8;
        FUN_0040eb84(param_1,puVar14,uVar6);
        *(undefined2 *)((int)puVar14 + 0xf2) = 0;
        if (puVar14[0x40] != 0) {
          if (*(int *)(puVar14[0x40] + 0x33c) != -1) {
            uVar7 = GetRRDisplayString_rdb(puVar14 + 1,puVar14[9] + 4,iVar12);
            iVar13 = puVar14[0x40];
            uVar11 = DNSTypeName(*(undefined2 *)(iVar13 + 0x580));
            LogMsgWithLevel(0,
                            "hndlRecordUpdateReply: ResourceRecord %s, zone info question %##s (%s) interval %d not -1"
                            ,uVar7,iVar13 + 0x480,uVar11,*(undefined4 *)(puVar14[0x40] + 0x33c));
          }
[32m          local_38 = *(short *)(puVar14[0x40] + 0x30a);[0m
          CancelGetZoneData(param_1,puVar14[0x40]);
          puVar14[0x40] = 0;
        }
        if ((*(char *)(puVar14 + 1) == '\x01') && (puVar14[0x39] == 3)) {
          if (iVar8 != 0) {
            LogMsgWithLevel(0,"ERROR: Deregistration of record %##s type %d failed with error %d",
                            puVar14[8],*(undefined2 *)((int)puVar14 + 6),iVar8);
          }
          puVar14[0x39] = 4;
          CompleteDeregistration(param_1,puVar14);
          goto LAB_0041715c;
        }
        if (*(char *)(param_1 + 0x275) == '\0') {
          if (puVar14[0x39] == 7) {
            if (iVar8 != 0) {
              LogMsgWithLevel(0,"Update record failed for %##s (err %d)",puVar14[8],iVar8);
            }
            puVar14[0x39] = 2;
            if ((code *)puVar14[0x35] != (code *)0x0) {
              (*(code *)puVar14[0x35])
                        (param_1,puVar14,puVar14[0x5b],*(undefined2 *)(puVar14 + 0x59));
            }
            SetNewRData(puVar14 + 1,puVar14[0x5c],*(undefined2 *)((int)puVar14 + 0x166));
            puVar14[0x5b] = 0;
            puVar14[0x5c] = 0;
          }
          if (*(char *)(puVar14 + 0x54) != '\0') {
            if (*(short *)((int)puVar14 + 6) == 0x21) {
              pcVar9 = (char *)GetServiceTarget(param_1,puVar14);
              if ((pcVar9 == (char *)0x0) || (*pcVar9 == '\0')) {
                if (puVar14[0x39] == 3) {
                  if (mDNS_LoggingEnabled != 0) {
                    LogMsgWithLevel(3,
                                    "hndlSRVChanged: SRVChanged, No Target, SRV Deregistered for %##s, state %d"
                                    ,puVar14[8],3);
                  }
[32m                  sVar3 = *(short *)((int)puVar14 + 6);[0m
                  *(undefined *)(puVar14 + 0x54) = 0;
                  if (((sVar3 == 2) || (sVar3 == 5)) || ((sVar3 == 0xc || (sVar3 == 0x27)))) {
                    puVar10 = (undefined *)(puVar14[9] + 4);
LAB_00416d00:
                    if (puVar10 != (undefined *)0x0) {
                      *puVar10 = 0;
                    }
                  }
                  else {
                    if ((((sVar3 == 0xf) || (sVar3 == 0x12)) || (sVar3 == 0x15)) || (sVar3 == 0x24))
                    {
                      puVar10 = (undefined *)(puVar14[9] + 6);
                      goto LAB_00416d00;
                    }
                    if (sVar3 == 0x21) {
                      puVar10 = (undefined *)(puVar14[9] + 10);
                      goto LAB_00416d00;
                    }
                  }
                  puVar14[0x39] = 8;
                  *(undefined2 *)(puVar14 + 4) = 0;
                  *(undefined2 *)((int)puVar14 + 0x12) = 0;
                }
                else if (puVar14[0x39] == 1) {
                  if (mDNS_LoggingEnabled != 0) {
                    LogMsgWithLevel(3,
                                    "hndlSRVChanged: SRVChanged, No Target, Deregistering again %##s, state %d"
                                    ,puVar14[8],1);
                  }
                  puVar14[0x2f] = mDNSPlatformOneSecond;
                  iVar8 = mDNSPlatformOneSecond;
                  iVar13 = *(int *)(param_1 + 0x234);
                  puVar14[0x39] = 3;
                  puVar14[0x30] = iVar13 - iVar8;
                }
                else if (mDNS_LoggingEnabled == 0) {
LAB_00416ec4:
                  *(undefined *)(puVar14 + 0x54) = 0;
                }
                else {
                  LogMsgWithLevel(3,
                                  "hndlSRVChanged: Not in DeregPending or RegPending state %##s, state %d"
                                  ,puVar14[8]);
                  *(undefined *)(puVar14 + 0x54) = 0;
                }
              }
              else {
                if ((puVar14[0x39] != 3) &&
                   ((puVar14[0x39] != 1 ||
                    (iVar8 = SameDomainName(pcVar9,puVar14[9] + 10), iVar8 != 0)))) {
                  if (puVar14[0x39] == 1) {
                    puVar14[0x39] = 2;
                  }
                  goto LAB_00416ec4;
                }
[32m                sVar3 = *(short *)((int)puVar14 + 6);[0m
                if ((((sVar3 == 2) || (sVar3 == 5)) || (sVar3 == 0xc)) || (sVar3 == 0x27)) {
                  puVar10 = (undefined *)(puVar14[9] + 4);
LAB_00416e50:
                  if (puVar10 != (undefined *)0x0) {
                    *puVar10 = 0;
                  }
                }
                else {
                  if (((sVar3 == 0xf) || (sVar3 == 0x12)) || ((sVar3 == 0x15 || (sVar3 == 0x24)))) {
                    puVar10 = (undefined *)(puVar14[9] + 6);
                    goto LAB_00416e50;
                  }
                  if (sVar3 == 0x21) {
                    puVar10 = (undefined *)(puVar14[9] + 10);
                    goto LAB_00416e50;
                  }
                }
                puVar14[0x39] = 8;
                *(undefined2 *)((int)puVar14 + 0x12) = 0;
                *(undefined2 *)(puVar14 + 4) = 0;
                if (mDNS_LoggingEnabled != 0) {
                  LogMsgWithLevel(3,
                                  "hndlSRVChanged: SRVChanged, Valid Target %##s, Registering all records for %##s, state %d"
                                  ,pcVar9,puVar14[8],8);
                }
                *(undefined *)(puVar14 + 0x54) = 0;
                FUN_0041347c(param_1,puVar14);
              }
            }
            else {
              if (mDNS_LoggingEnabled != 0) {
                uVar11 = puVar14[8];
                uVar7 = DNSTypeName();
                LogMsgWithLevel(3,"hndlRecordUpdateReply: Deregistered %##s (%s), state %d",uVar11,
                                uVar7,puVar14[0x39]);
              }
              *(undefined *)(puVar14 + 0x54) = 0;
              if (puVar14[0x39] != 3) {
                uVar7 = GetRRDisplayString_rdb(puVar14 + 1,puVar14[9] + 4,iVar12);
                LogMsgWithLevel(0,
                                "hndlRecordUpdateReply: ResourceRecord %s not in DeregPending state %d"
                                ,uVar7,puVar14[0x39]);
              }
              puVar14[0x39] = 8;
            }
            goto LAB_0041715c;
          }
          iVar13 = puVar14[0x39];
          if ((iVar13 == 1) || (iVar13 == 5)) {
            if (iVar8 == 0) {
              puVar14[0x39] = 2;
              bVar4 = iVar13 != 5;
              goto LAB_00417024;
            }
            LogMsgWithLevel(0,
                            "hndlRecordUpdateReply: Registration of record %##s type %d failed with error %d"
                            ,puVar14[8],*(undefined2 *)((int)puVar14 + 6),iVar8);
            bVar4 = true;
            if (((*(char *)(puVar14 + 0x3c) != '\0') ||
                (bVar4 = true, *(char *)(puVar14 + 0x3a) == '\0')) ||
               (bVar4 = true, iVar8 != -0x10001)) goto LAB_00417024;
            if (local_38 != 0x35) goto LAB_00417020;
            LogMsgWithLevel(0,
                            "hndlRecordUpdateReply: Will retry update of record %##s without lease option"
                            ,puVar14[8]);
            *(undefined *)(puVar14 + 0x3a) = 0;
          }
          else {
LAB_00417020:
            bVar4 = true;
LAB_00417024:
            if ((puVar14[0x5d] == 0) || (puVar14[0x39] != 2)) {
              if ((iVar8 == 0) && ((bVar4 && (puVar14[0x10] != 0)))) {
                if (mDNS_LoggingEnabled != 0) {
                  LogMsgWithLevel(3,"hndlRecordUpdateReply: Calling record callback on %##s",
                                  puVar14[8]);
                }
                iVar8 = *(int *)(param_1 + 0x28) + 1;
                *(int *)(param_1 + 0x28) = iVar8;
                if (*(int *)(param_1 + 0x24) != iVar8) {
                  LogMsgWithLevel(0,"%s: Locking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                                  "hndlRecordUpdateReply",*(int *)(param_1 + 0x24),iVar8);
                }
                (*(code *)puVar14[0x10])(param_1,puVar14,0);
                iVar8 = *(int *)(param_1 + 0x28);
                if (*(int *)(param_1 + 0x24) != iVar8) {
                  LogMsgWithLevel(0,
                                  "%s: Unlocking Failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                                  "hndlRecordUpdateReply",*(int *)(param_1 + 0x24),iVar8);
                  iVar8 = *(int *)(param_1 + 0x28);
                }
                *(int *)(param_1 + 0x28) = iVar8 + -1;
              }
              goto LAB_0041715c;
            }
            puVar14[0x39] = 7;
            puVar14[0x5c] = puVar14[0x5d];
            *(undefined2 *)((int)puVar14 + 0x166) = *(undefined2 *)(puVar14 + 0x5a);
            puVar14[0x5b] = puVar14[9];
            *(undefined2 *)(puVar14 + 0x59) = *(undefined2 *)(puVar14 + 4);
            puVar14[0x5d] = 0;
          }
          iVar8 = mDNSPlatformOneSecond;
          puVar14[0x2f] = mDNSPlatformOneSecond;
          iVar13 = *(int *)(param_1 + 0x234) - mDNSPlatformOneSecond;
          puVar14[0x30] = iVar13;
          iVar13 = iVar13 + iVar8;
          if (-1 < *(int *)(param_1 + 0x2188) - iVar13) {
            *(int *)(param_1 + 0x2188) = iVar13;
          }
          goto LAB_0041715c;
        }
        if ((*(short *)((int)puVar14 + 6) == 0x21) && (puVar14[0x39] == 3)) {
          puVar14[0x39] = 8;
        }
      }
      goto LAB_0041715c;
    }
  }
  return;
}

[ASK_GPT] 0b8698a1f8efb738
