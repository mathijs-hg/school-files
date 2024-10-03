
undefined4 FUN_00436018(int param_1)

{
  undefined4 *puVar1;
  ushort uVar2;
  bool bVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined *puVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  void *__ptr;
  void **ppvVar14;
  int iVar15;
  int iVar16;
  code *pcVar17;
  undefined *puVar18;
  undefined4 *local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  uint local_190;
  undefined auStack_180 [4];
  int local_17c;
  int local_178;
  int local_174;
  int local_170;
  undefined4 local_16c;
  int local_168;
  undefined auStack_158 [256];
  undefined2 local_58 [2];
  undefined4 *local_54;
  int local_50;
  int local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  char *local_38;
  uint local_34;
  char *local_30;
  int local_2c;
  
  local_4c = *(int *)(param_1 + 0x2190);
  uDNS_SetupWABQueries();
  mDNS_Lock_(param_1,"uDNS_SetupDNSConfig");
  for (puVar4 = *(undefined4 **)(param_1 + 0x2190); puVar4 != (undefined4 *)0x0;
      puVar4 = (undefined4 *)*puVar4) {
    puVar4[0x4c] = 0;
    NumUnicastDNSServers = NumUnicastDNSServers + -1;
    puVar4[9] = puVar4[9] | 1;
  }
  for (puVar4 = *(undefined4 **)(param_1 + 0x2194); puVar4 != (undefined4 *)0x0;
      puVar4 = (undefined4 *)*puVar4) {
    puVar4[2] = puVar4[2] | 1;
  }
  iVar5 = mDNSPlatformSetDNSConfig(param_1,1,0,auStack_158,0,0,1);
  puVar4 = (undefined4 *)(param_1 + 0x2194);
  if (iVar5 == 0) {
    for (puVar4 = *(undefined4 **)(param_1 + 0x2190); puVar4 != (undefined4 *)0x0;
        puVar4 = (undefined4 *)*puVar4) {
      puVar4[0x4c] = 0;
      NumUnicastDNSServers = NumUnicastDNSServers + '\x01';
      puVar4[9] = puVar4[9] & 0xfffffffe;
    }
    for (puVar4 = *(undefined4 **)(param_1 + 0x2194); puVar4 != (undefined4 *)0x0;
        puVar4 = (undefined4 *)*puVar4) {
      puVar4[2] = puVar4[2] & 0xfffffffe;
    }
    mDNS_Unlock_(param_1,"uDNS_SetupDNSConfig");
    if (mDNS_LoggingEnabled == 0) {
      return 0;
    }
    iVar5 = 3;
    pcVar17 = LogMsgWithLevel;
    pcVar9 = "uDNS_SetupDNSConfig: No configuration change";
  }
  else {
    while (puVar8 = (undefined4 *)*puVar4, puVar8 != (undefined4 *)0x0) {
      if ((puVar8[2] & 1) == 0) {
        puVar8[2] = puVar8[2] & 0xfffffffd;
        puVar4 = (undefined4 *)*puVar4;
      }
      else {
        *puVar4 = *puVar8;
        mDNSPlatformMemFree(puVar8);
      }
    }
    bVar3 = false;
    for (puVar4 = *(undefined4 **)(param_1 + 0x2ac); puVar4 != (undefined4 *)0x0;
        puVar4 = (undefined4 *)*puVar4) {
      if ((*(short *)((int)puVar4 + 0x152) != 0) && (puVar4[0xf] == 0)) {
        SetValidDNSServers(param_1,puVar4);
        *(undefined2 *)((int)puVar4 + 0xea) = 0;
        iVar5 = GetServerForQuestion(param_1,puVar4);
        iVar15 = puVar4[0x37];
        if (iVar15 == iVar5) {
          for (puVar8 = (undefined4 *)*puVar4; puVar8 != (undefined4 *)0x0;
              puVar8 = (undefined4 *)*puVar8) {
            if ((undefined4 *)puVar8[0xf] == puVar4) {
              puVar8[0x38] = puVar4[0x38];
              puVar8[0x39] = puVar4[0x39];
              puVar8[0x37] = puVar4[0x37];
            }
          }
        }
        else {
          if (mDNS_LoggingEnabled != 0) {
            if (iVar15 == 0) {
              uVar2 = 0;
              local_2c = 0;
            }
            else {
              uVar2 = *(ushort *)(iVar15 + 0x20);
              local_2c = iVar15 + 0xc;
            }
            local_38 = (char *)(iVar15 + 0x30);
            if (iVar15 == 0) {
              local_38 = "";
            }
            local_40 = (uint)(uVar2 >> 8);
            local_34 = uVar2 & 0xff;
            if (iVar5 == 0) {
              uVar2 = 0;
              local_3c = 0;
            }
            else {
              uVar2 = *(ushort *)(iVar5 + 0x20);
              local_3c = iVar5 + 0xc;
            }
            local_48 = (uint)(uVar2 >> 8);
            local_30 = (char *)(iVar5 + 0x30);
            if (iVar5 == 0) {
              local_30 = "";
            }
            local_44 = uVar2 & 0xff;
            uVar6 = DNSTypeName(*(undefined2 *)(puVar4 + 0x95));
            LogMsgWithLevel(3,
                            "uDNS_SetupDNSConfig: Updating DNS Server from %#a:%d (%##s) to %#a:%d (%##s) for question %##s (%s) (scope:%p)"
                            ,local_2c,local_40 << 8 | local_34,local_38,local_3c,
                            local_48 << 8 | local_44,local_30,puVar4 + 0x55,uVar6,puVar4[0x4d]);
          }
          local_30 = (char *)(uint)*(byte *)(puVar4 + 0x2f);
          uVar11 = FUN_00427d54(param_1,puVar4,iVar5);
          if (local_30 == (char *)uVar11) {
            DNSServerChangeForQuestion(param_1,puVar4,iVar5);
            *(undefined *)(puVar4 + 0x3b) = 0;
            mDNS_NewMessageID(local_58,param_1);
            *(undefined2 *)((int)puVar4 + 0x152) = local_58[0];
            if (((*(char *)(puVar4 + 0x97) == '\0') || (*(char *)(puVar4 + 0x2f) == '\0')) &&
               (*(char *)((int)puVar4 + 0x12e) == '\0')) {
              FUN_0042c3ac(param_1,puVar4,1);
              for (puVar8 = (undefined4 *)*puVar4; puVar8 != (undefined4 *)0x0;
                  puVar8 = (undefined4 *)*puVar8) {
                if ((undefined4 *)puVar8[0xf] == puVar4) {
                  FUN_0042c3ac(param_1,puVar8,1);
                }
              }
            }
          }
          else {
            *(char *)(puVar4 + 0x2f) = (char)uVar11;
            *(undefined *)((int)puVar4 + 0x113) = 1;
            for (puVar8 = (undefined4 *)*puVar4; bVar3 = true, puVar8 != (undefined4 *)0x0;
                puVar8 = (undefined4 *)*puVar8) {
              if ((undefined4 *)puVar8[0xf] == puVar4) {
                *(undefined *)((int)puVar8 + 0x113) = 1;
              }
            }
          }
        }
      }
    }
    if (bVar3) {
      iVar5 = *(int *)(param_1 + 0x2c0);
      local_1a0 = (undefined4 *)0x0;
      if (iVar5 != 0) {
        uVar6 = DNSTypeName(*(undefined2 *)(iVar5 + 0x254));
        LogMsgWithLevel(0,
                        "RestartUnicastQuestions: ERROR!! m->RestartQuestion already set: %##s (%s)"
                        ,iVar5 + 0x154,uVar6);
      }
      *(undefined4 *)(param_1 + 0x2c0) = *(undefined4 *)(param_1 + 0x2ac);
      while (puVar4 = *(undefined4 **)(param_1 + 0x2c0), puVar4 != (undefined4 *)0x0) {
        *(undefined4 *)(param_1 + 0x2c0) = *puVar4;
        if (*(char *)((int)puVar4 + 0x113) != '\0') {
          if (*(short *)((int)puVar4 + 0x152) == 0) {
            uVar6 = DNSTypeName(*(undefined2 *)(puVar4 + 0x95));
            LogMsgWithLevel(0,
                            "RestartUnicastQuestions: ERROR!! Restart set for multicast question %##s (%s)"
                            ,puVar4 + 0x55,uVar6);
          }
          *(undefined *)((int)puVar4 + 0x113) = 0;
          FUN_00435ef0(param_1,puVar4,&local_1a0);
        }
      }
      while (puVar4 = local_1a0, local_1a0 != (undefined4 *)0x0) {
        puVar8 = (undefined4 *)*local_1a0;
        *local_1a0 = 0;
        if (mDNS_LoggingEnabled != 0) {
          puVar1 = local_1a0 + 0x95;
          local_1a0 = puVar8;
          uVar6 = DNSTypeName(*(undefined2 *)puVar1,puVar4);
          LogMsgWithLevel(3,"RestartUnicastQuestions: Start question %p %##s (%s)",puVar4,
                          puVar4 + 0x55,uVar6);
          puVar8 = local_1a0;
        }
        local_1a0 = puVar8;
        mDNS_StartQuery_internal(param_1,puVar4);
      }
    }
    local_50 = param_1 + 0x7cc;
    iVar15 = param_1 + 0x2f;
    iVar5 = param_1;
    do {
      for (local_54 = *(undefined4 **)(iVar5 + 0x2e0); local_54 != (undefined4 *)0x0;
          local_54 = (undefined4 *)*local_54) {
        for (puVar4 = (undefined4 *)local_54[2]; puVar4 != (undefined4 *)0x0;
            puVar4 = (undefined4 *)*puVar4) {
          if (puVar4[7] == 0) {
            iVar16 = puVar4[0x11];
            local_30 = (char *)puVar4[8];
            iVar13 = 0;
            if (iVar16 == 0) {
              uVar6 = 0xffffffff;
            }
            else {
              uVar6 = *(undefined4 *)(iVar16 + 0x130);
              iVar13 = *(int *)(iVar16 + 0x134);
            }
            if ((iVar13 == -3) || (iVar13 == -2)) {
              iVar13 = 0;
            }
            else if (iVar13 != 0) {
              for (puVar8 = *(undefined4 **)(param_1 + 0x2174); puVar8 != (undefined4 *)0x0;
                  puVar8 = (undefined4 *)*puVar8) {
                if (puVar8[0x548] == iVar13) {
                  puVar10 = (undefined *)((int)puVar8 + 0x1552);
                  goto LAB_00436674;
                }
              }
            }
            puVar10 = (undefined *)0x0;
LAB_00436674:
            local_198 = 0xffffffff;
            local_19c = 0xffffffff;
            puVar18 = (undefined *)0xffffffff;
            iVar16 = 0;
            uVar11 = 1;
            iVar12 = FUN_0042820c(param_1,local_30,iVar13,uVar6,0xffffffff,0xffffffff,0,1);
            if (iVar12 == 0) {
              if (mDNS_LoggingEnabled != 0) {
                if (puVar10 == (undefined *)0x0) {
                  puVar10 = &DAT_00455450;
                }
                LogMsgWithLevel(3,
                                "GetServerForName: no DNS server (Scope %s:%p) found for name %##s",
                                puVar10,iVar13,local_30);
              }
            }
            else {
              iVar7 = 0;
              if (mDNS_LoggingEnabled != 0) {
                if (*(int *)(iVar12 + 0x130) != 0) {
                  iVar7 = *(int *)(iVar12 + 0x130) - *(int *)(param_1 + 0x234);
                }
                puVar18 = puVar10;
                if (puVar10 == (undefined *)0x0) {
                  puVar18 = &DAT_00455450;
                }
                uVar11 = (uint)local_30;
                LogMsgWithLevel(3,
                                "GetServerForName: DNS server %#a:%d (Penalty Time Left %d) (Scope %s:%p) found for name %##s"
                                ,iVar12 + 0xc,
                                (uint)(*(ushort *)(iVar12 + 0x20) >> 8) << 8 |
                                *(ushort *)(iVar12 + 0x20) & 0xff,iVar7,puVar18,iVar13,local_30);
                iVar16 = iVar13;
              }
              if (iVar12 != puVar4[10]) {
                iVar13 = puVar4[0x11];
                if (((iVar13 == 0) || (*(char *)(iVar13 + 0x266) != '\0')) ||
                   ((*(char *)(iVar13 + 0xcc) != '\0' ||
                    ((*(char *)(iVar13 + 0x267) != '\0' && (*(char *)(iVar13 + 0x268) != '\0'))))))
                {
                  if (mDNS_LoggingEnabled != 0) {
                    uVar6 = GetRRDisplayString_rdb(puVar4 + 1,puVar4[9] + 4,iVar15);
                    iVar13 = puVar4[10] + 0xc;
                    if (puVar4[10] == 0) {
                      iVar13 = 0;
                    }
                    LogMsgWithLevel(3,
                                    "uDNS_SetupDNSConfig: Purging Resourcerecord %s, New DNS server %#a , Old DNS server %#a"
                                    ,uVar6,iVar12 + 0xc,iVar13,puVar18,iVar16,uVar11);
                  }
                  mDNS_PurgeCacheResourceRecord(param_1,puVar4);
                }
                else {
                  if (mDNS_LoggingEnabled != 0) {
                    uVar6 = GetRRDisplayString_rdb(puVar4 + 1,puVar4[9] + 4,iVar15);
                    iVar13 = puVar4[10] + 0xc;
                    if (puVar4[10] == 0) {
                      iVar13 = 0;
                    }
                    LogMsgWithLevel(3,
                                    "uDNS_SetupDNSConfig: Purging/Reconfirming Resourcerecord %s, New DNS server %#a, Old DNS server %#a"
                                    ,uVar6,iVar12 + 0xc,iVar13,puVar18,iVar16,uVar11);
                  }
                  FUN_004292f4(param_1,puVar4,iVar12,0);
                }
              }
            }
          }
        }
      }
      iVar5 = iVar5 + 4;
      ppvVar14 = (void **)(param_1 + 0x2190);
    } while (iVar5 != local_50);
    while (__ptr = *ppvVar14, __ptr != (void *)0x0) {
      if ((*(uint *)((int)__ptr + 0x24) & 1) == 0) {
        *(uint *)((int)__ptr + 0x24) = *(uint *)((int)__ptr + 0x24) & 0xfffffffd;
        ppvVar14 = (void **)*ppvVar14;
      }
      else {
        iVar16 = (int)__ptr + 0xc;
        iVar5 = param_1;
        do {
          for (local_54 = *(undefined4 **)(iVar5 + 0x2e0); local_54 != (undefined4 *)0x0;
              local_54 = (undefined4 *)*local_54) {
            for (puVar4 = (undefined4 *)local_54[2]; puVar4 != (undefined4 *)0x0;
                puVar4 = (undefined4 *)*puVar4) {
              if ((puVar4[7] == 0) && ((void *)puVar4[10] == __ptr)) {
                iVar13 = puVar4[0x11];
                if (iVar13 == 0) {
                  if (mDNS_LoggingEnabled != 0) {
                    LogMsgWithLevel(3,
                                    "uDNS_SetupDNSConfig: Cache Record %##s has no Active question, Record\'s DNSServer Address %#a, Server to be deleted %#a"
                                    ,puVar4[8],iVar16,iVar16);
                  }
LAB_00436a44:
                  puVar4[10] = 0;
                }
                else {
                  if (*(void **)(iVar13 + 0xdc) == __ptr) {
                    local_2c = GetRRDisplayString_rdb(puVar4 + 1,puVar4[9] + 4,iVar15);
                    uVar6 = DNSTypeName(*(undefined2 *)(iVar13 + 0x254));
                    LogMsgWithLevel(0,
                                    "uDNS_SetupDNSConfig: ERROR!! Cache Record %s  Active question %##s (%s) (scope:%p) poining to DNSServer Address %#a to be freed"
                                    ,local_2c,iVar13 + 0x154,uVar6,*(undefined4 *)(iVar13 + 0x134),
                                    iVar16);
                    *(undefined4 *)(iVar13 + 0xdc) = 0;
                    *(undefined4 *)(iVar13 + 0xe0) = 0;
                    *(undefined4 *)(iVar13 + 0xe4) = 0;
                    goto LAB_00436a44;
                  }
                  if (mDNS_LoggingEnabled != 0) {
                    local_2c = GetRRDisplayString_rdb(puVar4 + 1,puVar4[9] + 4,iVar15);
                    uVar6 = DNSTypeName(*(undefined2 *)(iVar13 + 0x254));
                    iVar12 = *(int *)(iVar13 + 0xdc) + 0xc;
                    if (*(int *)(iVar13 + 0xdc) == 0) {
                      iVar12 = 0;
                    }
                    LogMsgWithLevel(3,
                                    "uDNS_SetupDNSConfig: Cache Record %s,  Active question %##s (%s) (scope:%p), pointing to DNSServer %#a (to be deleted), resetting to  question\'s DNSServer Address %#a"
                                    ,local_2c,iVar13 + 0x154,uVar6,*(undefined4 *)(iVar13 + 0x134),
                                    iVar16,iVar12);
                  }
                  puVar4[10] = *(undefined4 *)(iVar13 + 0xdc);
                }
                FUN_004292f4(param_1,puVar4,__ptr,1);
              }
            }
          }
          iVar5 = iVar5 + 4;
        } while (iVar5 != local_50);
                    /* WARNING: Load size is inaccurate */
        *ppvVar14 = **ppvVar14;
        if (mDNS_LoggingEnabled != 0) {
          LogMsgWithLevel(3,"uDNS_SetupDNSConfig: Deleting server %p %#a:%d (%##s) %d",__ptr,iVar16,
                          *(undefined2 *)((int)__ptr + 0x20),(int)__ptr + 0x30,NumUnicastDNSServers)
          ;
        }
        mDNSPlatformMemFree(__ptr);
      }
    }
    uVar11 = 0;
    iVar5 = param_1;
    if ((local_4c != 0) != (*(int *)(param_1 + 0x2190) != 0)) {
      do {
        for (puVar4 = *(undefined4 **)(iVar5 + 0x2e0); puVar4 != (undefined4 *)0x0;
            puVar4 = (undefined4 *)*puVar4) {
          for (puVar8 = (undefined4 *)puVar4[2]; puVar8 != (undefined4 *)0x0;
              puVar8 = (undefined4 *)*puVar8) {
            if (puVar8[7] == 0) {
              local_34 = uVar11 + 1;
              mDNS_PurgeCacheResourceRecord(param_1,puVar8);
              uVar11 = local_34;
            }
          }
        }
        iVar5 = iVar5 + 4;
      } while (iVar5 != local_50);
      if (mDNS_LoggingEnabled != 0) {
        if (*(int *)(param_1 + 0x2190) == 0) {
          pcVar9 = "No DNS servers";
        }
        else {
          pcVar9 = "DNS server became";
        }
        LogMsgWithLevel(3,
                        "uDNS_SetupDNSConfig: %s available; purged %d unicast DNS records from cache"
                        ,pcVar9);
      }
      FUN_0042c704(param_1);
    }
    iVar5 = param_1 + 0x27f8;
    iVar15 = SameDomainName(auStack_158,iVar5);
    if (iVar15 == 0) {
      if (*(char *)(param_1 + 0x27f8) != '\0') {
        mDNS_RemoveDynDNSHostName(param_1,iVar5);
      }
      uVar11 = DomainNameLengthLimit(auStack_158,local_58);
      if (uVar11 < 0x101) {
        mDNSPlatformMemCopy((void *)(param_1 + 0x27f8),auStack_158,uVar11);
      }
      else {
        *(undefined *)(param_1 + 0x27f8) = 0;
      }
      if (*(char *)(param_1 + 0x27f8) != '\0') {
        mDNSPlatformDynDNSHostNameStatusChanged(iVar5,1);
        mDNS_AddDynDNSHostName(param_1,iVar5,FUN_00427d38,0);
      }
    }
    mDNS_Unlock_(param_1,"uDNS_SetupDNSConfig");
    puVar4 = &local_194;
[32m[32m    memcpy(&local_16c,zeroAddr,0x14);[0m[0m
[32m[32m    memcpy(auStack_180,&local_16c,0x14);[0m[0m
[32m[32m    memcpy(puVar4,auStack_180,0x14);[0m[0m
    local_194 = 4;
    local_16c = 4;
    iVar15 = mDNSPlatformGetPrimaryInterface(param_1,puVar4,auStack_180,&local_16c);
    if (iVar15 == 0) {
      if (local_190 == 0) {
        puVar4 = (undefined4 *)0x0;
      }
      if ((local_190 & 0xffff0000) != 0xa9fe0000) {
        if ((local_178 != 0) ||
           (((puVar10 = auStack_180, local_17c == 0 && (local_174 == 0)) &&
            (puVar10 = (undefined *)0x0, local_170 != 0)))) {
          puVar10 = auStack_180;
        }
        puVar8 = &local_16c;
        if (local_168 == 0) {
          puVar8 = (undefined4 *)0x0;
        }
        mDNS_SetPrimaryInterfaceInfo(param_1,puVar4,puVar10,puVar8);
        return 0;
      }
    }
    mDNS_SetPrimaryInterfaceInfo(param_1,0,0,0);
    if (*(char *)(param_1 + 0x27f8) == '\0') {
      return 0;
    }
    pcVar17 = mDNSPlatformDynDNSHostNameStatusChanged;
    pcVar9 = (char *)0x1;
  }
  (*pcVar17)(iVar5,pcVar9);
  return 0;
}

[ASK_GPT] fadfed6680b0fe1d
