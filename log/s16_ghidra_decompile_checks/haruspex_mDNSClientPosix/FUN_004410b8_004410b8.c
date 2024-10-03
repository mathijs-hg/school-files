
void FUN_004410b8(int param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined2 uVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  char *pcVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  int iVar15;
  uint local_260 [4];
  int local_250 [132];
  undefined4 *local_40;
  uint *local_3c;
  uint *local_38;
  undefined4 *local_34;
  uint local_30;
  
  local_260[1] = 0;
  local_260[0] = 0;
  *(undefined4 *)(param_1 + 0x2a4) = *(undefined4 *)(param_1 + 0x234);
  local_250[0] = 0;
  local_250[1] = 0;
  local_250[2] = 0;
  if (*(char *)(param_1 + 0x277) == '\0') {
    if (mDNS_LoggingEnabled != 0) {
      pcVar10 = "BeginSleepProcessing: m->SystemWakeOnLANEnabled is false";
LAB_0044116c:
      LogMsgWithLevel(2,pcVar10);
    }
  }
  else {
    iVar3 = FUN_0042a73c();
    if (iVar3 != 0) {
      iVar3 = 0;
      local_3c = (uint *)(param_1 + 0x2f);
      mDNSPlatformClearSPSMACAddr();
      uVar7 = 0;
      uVar11 = *(undefined4 *)(param_1 + 0x2174);
      bVar1 = true;
      while (puVar14 = (undefined4 *)GetFirstActiveInterface(uVar11), puVar14 != (undefined4 *)0x0)
      {
        *(undefined *)((int)puVar14 + 0x1597) = 0;
        if ((*(char *)((int)puVar14 + 0x1593) == '\0') ||
           (iVar15 = mDNSPlatformInterfaceIsD2D(puVar14[0x548]), iVar15 != 0)) {
          if (mDNS_LoggingEnabled != 0) {
            LogMsgWithLevel(2,"BeginSleepProcessing: %-6s Ignoring for registrations",
                            (int)puVar14 + 0x1552);
          }
        }
        else {
          if (*(char *)(puVar14 + 0x565) != '\0') {
            puVar5 = *(undefined4 **)(param_1 + 0x2174);
LAB_00441254:
            if (puVar5 != (undefined4 *)0x0) {
              if (puVar5[0x548] != puVar14[0x548]) goto LAB_00441250;
              for (; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {
                if ((puVar5[0x548] == puVar14[0x548]) &&
                   (uVar9 = 0, piVar8 = local_250 + 3, puVar5[0x549] == 4)) {
                  for (; uVar9 < uVar7; uVar9 = uVar9 + 1) {
                    for (puVar13 = *(undefined4 **)(param_1 + 0x2174); puVar13 != (undefined4 *)0x0;
                        puVar13 = (undefined4 *)*puVar13) {
                      if (puVar13[0x548] == *piVar8) goto LAB_0044132c;
                    }
LAB_00441334:
                    piVar8 = piVar8 + 1;
                  }
                }
              }
            }
            FUN_0042db60(param_1,puVar14 + 2,local_250);
            if (local_250[0] == 0) {
              if (mDNS_LoggingEnabled != 0) {
                LogMsgWithLevel(2,
                                "BeginSleepProcessing: %-6s %#a No Sleep Proxy Server found (Next Browse Q in %d, interval %d)"
                                ,(int)puVar14 + 0x1552,puVar14 + 0x549,
                                (puVar14[6] + puVar14[5]) - *(int *)(param_1 + 0x234),puVar14[6]);
              }
            }
            else {
              puVar14[0x2a3] = 0;
              puVar14[0x2a4] = mDNSPlatformOneSecond + *(int *)(param_1 + 0x234);
              uVar9 = mDNSPlatformInterfaceIndexfromInterfaceID(param_1,puVar14[0x548],1);
              if (uVar9 < 0x40) {
                local_260[uVar9 >> 5] = 1 << (uVar9 & 0x1f) | local_260[uVar9 >> 5];
              }
              local_40 = (undefined4 *)((int)puVar14 + 0x1552);
              piVar8 = local_250;
              iVar15 = 0;
              local_38 = local_260;
              puVar5 = puVar14;
              uVar9 = uVar7;
              puVar13 = puVar14;
              do {
                puVar13[0x292] = 0;
                puVar13 = puVar13 + 5;
                if (-1 < (int)puVar5[0xaa]) {
                  mDNS_StopQuery(param_1,puVar14 + iVar15 * 0xa4 + 0xa6);
                }
                puVar5[0xaa] = 0xffffffff;
                iVar4 = *piVar8;
                uVar7 = uVar9;
                if (iVar4 != 0) {
                  if (mDNS_LoggingEnabled != 0) {
                    local_34 = *(undefined4 **)(iVar4 + 0xc);
                    uVar11 = GetRRDisplayString_rdb(iVar4 + 4,*(int *)(iVar4 + 0x24) + 4,local_3c);
                    LogMsgWithLevel(2,
                                    "BeginSleepProcessing: %-6s Found Sleep Proxy Server %d TTL %d %s"
                                    ,local_40,iVar15,local_34,uVar11);
                  }
                  local_34 = puVar14 + iVar15 * 0xa4 + 0xa6;
                  mDNS_SetupQuestion(local_34,puVar14[0x548],*(int *)(*piVar8 + 0x24) + 4,0x21,
                                     FUN_004350d4,puVar14);
                  *(undefined *)((int)puVar5 + 0x4f3) = 1;
                  mDNS_StartQuery_internal(param_1,local_34);
                  uVar7 = uVar9 + 1;
                  local_38[uVar9 + 7] = puVar14[0x548];
                }
                iVar15 = iVar15 + 1;
                puVar5 = puVar5 + 0xa4;
                piVar8 = piVar8 + 1;
                uVar9 = uVar7;
              } while (iVar15 != 3);
              bVar1 = false;
            }
            goto LAB_00441588;
          }
          if (mDNS_LoggingEnabled != 0) {
            LogMsgWithLevel(2,"BeginSleepProcessing: %-6s not capable of magic packet wakeup",
                            (int)puVar14 + 0x1552);
          }
          iVar3 = iVar3 + 1;
          *(undefined *)((int)puVar14 + 0x1597) = 1;
        }
LAB_00441588:
        uVar11 = *puVar14;
      }
      goto LAB_004415b4;
    }
    if (mDNS_LoggingEnabled != 0) {
      pcVar10 = "BeginSleepProcessing: No advertised services";
      goto LAB_0044116c;
    }
  }
  iVar3 = 0;
  bVar1 = true;
LAB_004415b4:
  if ((local_260[1] != 0) || (bVar2 = false, local_260[0] != 0)) {
    local_260[2] = local_260[0];
    local_260[3] = local_260[1];
    if (mDNS_LoggingEnabled != 0) {
      LogMsgWithLevel(2,"SPSInitRecordsBeforeUpdate: UpdateIntID 0x%x 0x%x");
    }
    puVar14 = *(undefined4 **)(param_1 + 0x2a98);
    if (mDNS_LoggingEnabled != 0) {
      LogMsgWithLevel(2,"%s : Freeing stored sleep proxy A/AAAA records","mDNSCoreFreeProxyRR");
    }
    while (puVar14 != (undefined4 *)0x0) {
      puVar5 = (undefined4 *)*puVar14;
      mDNSPlatformMemFree(puVar14);
      puVar14 = puVar5;
    }
    local_3c = local_260;
    iVar15 = param_1 + 0x2f;
    *(undefined4 *)(param_1 + 0x2a98) = 0;
    bVar2 = false;
    for (puVar14 = *(undefined4 **)(param_1 + 0x2160); puVar14 != (undefined4 *)0x0;
        puVar14 = (undefined4 *)*puVar14) {
      puVar14[0x3d] = 0;
      puVar14[0x3e] = 0;
      *(undefined2 *)((int)puVar14 + 0xf2) = 0;
      if (((puVar14[7] != 0) || (*(char *)((int)puVar14 + 0x4a) != '\0')) ||
         (iVar4 = IsLocalDomain(puVar14[8]), iVar4 != 0)) {
        iVar4 = local_260[3];
        if ((((*(byte *)((int)puVar14 + 0x4b) & 1) == 0) || (*(char *)(puVar14 + 1) != '\b')) ||
           (*(char *)(puVar14 + 0x22) == '\0')) {
          if (puVar14[7] == 0) {
            if (mDNS_LoggingEnabled != 0) {
              local_30 = local_260[2];
              uVar11 = GetRRDisplayString_rdb(puVar14 + 1,puVar14[9] + 4,iVar15);
              LogMsgWithLevel(2,"Setting scopeid (ALL) 0x%x 0x%x for %s",iVar4,local_30,uVar11);
            }
            puVar14[0x3d] = local_260[2];
            puVar14[0x3e] = local_260[3];
          }
          else {
            puVar5 = (undefined4 *)mDNSPlatformInterfaceIndexfromInterfaceID(param_1,puVar14[7],1);
            uVar7 = (uint)puVar5 >> 5;
            if ((puVar5 < (undefined4 *)0x40) &&
               (uVar9 = 1 << ((uint)puVar5 & 0x1f), (uVar9 & local_3c[uVar7 + 2]) != 0)) {
              puVar14[uVar7 + 0x3d] = uVar9 | puVar14[uVar7 + 0x3d];
              if (mDNS_LoggingEnabled != 0) {
                local_30 = puVar14[0x3e];
                uVar12 = puVar14[0x3d];
                local_34 = puVar5;
                uVar11 = GetRRDisplayString_rdb(puVar14 + 1,puVar14[9] + 4,iVar15);
                LogMsgWithLevel(2,"SPSInitRecordsBeforeUpdate: Setting scopeid(%d) 0x%x 0x%x for %s"
                                ,local_34,local_30,uVar12,uVar11);
              }
            }
            else if (mDNS_LoggingEnabled != 0) {
              LogMsgWithLevel(2,
                              "SPSInitRecordsBeforeUpdate: scopeid %d beyond range or not valid for SPS registration"
                              ,puVar5);
            }
          }
          if ((*(short *)((int)puVar14 + 6) == 1) || (*(short *)((int)puVar14 + 6) == 0x1c)) {
            local_34 = (undefined4 *)puVar14[7];
            puVar5 = (undefined4 *)mDNSPlatformMemAllocate(900);
            if (puVar5 == (undefined4 *)0x0) {
              if (mDNS_LoggingEnabled != 0) {
                LogMsgWithLevel(2,"%s : could not allocate memory for new resource record",
                                "mDNSCoreStoreProxyRR");
              }
            }
            else {
              local_40 = puVar14 + 0x5e;
              mDNSPlatformMemZero(puVar5,900);
              mDNS_SetupResourceRecord
                        (puVar5,0,local_34,*(undefined2 *)((int)puVar14 + 6),puVar14[3],
                         *(undefined *)(puVar14 + 1),puVar14[0x1f],0,0);
              uVar7 = DomainNameLengthLimit(local_40,puVar14 + 0x9e);
              if (uVar7 < 0x101) {
                mDNSPlatformMemCopy(puVar5 + 0x5e,local_40,uVar7);
              }
              else {
                *(undefined *)(puVar5 + 0x5e) = 0;
              }
              uVar6 = DomainNameLengthLimit(puVar14[8],puVar14[8] + 0x100);
              *(undefined2 *)(puVar5 + 4) = uVar6;
              uVar11 = DomainNameHashValue(puVar5[8]);
              puVar5[5] = uVar11;
              *(undefined2 *)(puVar5 + 2) = *(undefined2 *)(puVar14 + 2);
              if (*(short *)((int)puVar14 + 6) == 1) {
                *(undefined4 *)(puVar5[9] + 4) = *(undefined4 *)(puVar14[9] + 4);
              }
              else if (*(short *)((int)puVar14 + 6) == 0x1c) {
[32m[32m                memcpy((void *)(puVar5[9] + 4),(void *)(puVar14[9] + 4),0x10);[0m[0m
              }
              SetNewRData(puVar5 + 1,0,0);
              *puVar5 = *(undefined4 *)(param_1 + 0x2a98);
              *(undefined4 **)(param_1 + 0x2a98) = puVar5;
              if (mDNS_LoggingEnabled != 0) {
                uVar11 = GetRRDisplayString_rdb(puVar14 + 1,puVar14[9] + 4,iVar15);
                LogMsgWithLevel(2,"%s : Storing proxy record : %s ","mDNSCoreStoreProxyRR",uVar11);
              }
            }
          }
        }
        else {
          bVar2 = true;
          puVar14[0x24] = 0xffffffff;
        }
      }
    }
  }
  if (mDNS_LoggingEnabled != 0) {
    LogMsgWithLevel(2,
                    "BeginSleepProcessing: Did not register with an in-NIC proxy - invoking the callbacks for KA records"
                   );
  }
  *(undefined4 *)(param_1 + 0x216c) = *(undefined4 *)(param_1 + 0x2160);
  while (puVar14 = *(undefined4 **)(param_1 + 0x216c), puVar14 != (undefined4 *)0x0) {
    if (*(short *)((int)puVar14 + 6) == 10) {
      uVar7 = (uint)*(byte *)puVar14[8];
      iVar15 = uVar7 + 1;
      if (uVar7 == 0) {
        iVar15 = 0;
      }
      iVar15 = SameDomainLabel((byte *)puVar14[8] + iVar15,"\n_keepalive");
      if ((iVar15 != 0) && (*(char *)(puVar14 + 1) != '\x01')) {
        if (mDNS_LoggingEnabled != 0) {
          uVar11 = GetRRDisplayString_rdb(puVar14 + 1,puVar14[9] + 4,param_1 + 0x2f);
          LogMsgWithLevel(2,"DoKeepaliveCallbacks: Invoking the callback for %s",uVar11);
        }
        if ((code *)puVar14[0x10] != (code *)0x0) {
          (*(code *)puVar14[0x10])(param_1,puVar14,0xfffefffa);
        }
      }
    }
    if (*(undefined4 **)(param_1 + 0x216c) == puVar14) {
      *(undefined4 *)(param_1 + 0x216c) = *puVar14;
    }
  }
  if (bVar1) {
    if (mDNS_LoggingEnabled != 0) {
      LogMsgWithLevel(2,"BeginSleepProcessing: Not registering with Sleep Proxy Server");
    }
    uVar11 = 1;
    uVar12 = 1;
  }
  else {
    if (iVar3 == 0) {
      if (!bVar2) {
        return;
      }
      if (mDNS_LoggingEnabled != 0) {
        LogMsgWithLevel(2,"BeginSleepProcessing: Sending goodbyes for %s","WakeOnlyService");
      }
      FUN_0043e94c(param_1);
      return;
    }
    if (mDNS_LoggingEnabled != 0) {
      LogMsgWithLevel(2,
                      "BeginSleepProcessing: Not registering with Sleep Proxy Server on all interfaces"
                     );
    }
    uVar11 = 0;
    uVar12 = 0;
  }
  FUN_00440968(param_1,uVar11,uVar12);
  return;
LAB_00441250:
  puVar5 = (undefined4 *)*puVar5;
  goto LAB_00441254;
LAB_0044132c:
  if (puVar13 == (undefined4 *)0x0) goto LAB_00441334;
  if (((puVar13[0x548] == *piVar8) && (puVar13[0x549] == 4)) &&
     ((puVar13[0x54f] & puVar13[0x54a]) == (puVar5[0x54f] & puVar5[0x54a]))) {
    if (mDNS_LoggingEnabled != 0) {
      LogMsgWithLevel(2,"%s : Already registered for the same subnet (IPv4) for interface %s",
                      "skipSameSubnetRegistration",(int)puVar13 + 0x1552);
    }
    if (mDNS_LoggingEnabled != 0) {
      LogMsgWithLevel(2,"%s : Skipping sleep proxy registration on %s","BeginSleepProcessing",
                      (int)puVar14 + 0x1552);
    }
    goto LAB_00441588;
  }
  puVar13 = (undefined4 *)*puVar13;
  goto LAB_0044132c;
}

[ASK_GPT] 88e4162bdc38fc67
