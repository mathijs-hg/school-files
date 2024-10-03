
void mDNS_SetPrimaryInterfaceInfo(int param_1,int *param_2,int *param_3,int *param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  void *__dest;
  int iVar8;
  char *pcVar9;
  undefined1 *puVar10;
  size_t __n;
  char *pcVar11;
  undefined4 *puVar12;
  int iVar13;
  int *piStackX_8;
  int *piStackX_c;
  int local_68 [4];
  undefined auStack_58 [4];
  int local_54;
  undefined auStack_48 [8];
  int local_40;
  undefined auStack_38 [12];
  int local_2c;
  
  piVar4 = *(int **)(param_1 + 0x28);
  piStackX_c = param_4;
  if (*(int **)(param_1 + 0x24) != piVar4) {
    LogMsgWithLevel(0,"mDNS_SetPrimaryInterfaceInfo: mDNS_busy (%ld) != mDNS_reentrancy (%ld)",
                    *(int **)(param_1 + 0x24));
    piStackX_c = piVar4;
  }
  if ((param_2 == (int *)0x0) || (*param_2 == 4)) {
    if ((param_3 == (int *)0x0) || (*param_3 == 6)) {
      if ((param_4 == (int *)0x0) || (*param_4 == 4)) {
        mDNS_Lock_(param_1,"mDNS_SetPrimaryInterfaceInfo");
        if (param_2 == (int *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = param_2[1];
        }
        iVar13 = *(int *)(param_1 + 0x21c4);
        bVar1 = *(int *)(param_1 + 0x21b0) != iVar5;
        puVar10 = (undefined1 *)(param_3 + 1);
        if (param_3 == (int *)0x0) {
          puVar10 = zerov6Addr;
        }
[32m[32m        memcpy(local_68,puVar10,0x10);[0m[0m
        bVar2 = true;
        if (iVar13 == local_68[0]) {
          iVar5 = *(int *)(param_1 + 0x21c8);
          puVar10 = (undefined1 *)(param_3 + 1);
          if (param_3 == (int *)0x0) {
            puVar10 = zerov6Addr;
          }
[32m[32m          memcpy(auStack_58,puVar10,0x10);[0m[0m
          bVar2 = true;
          if (iVar5 == local_54) {
            iVar5 = *(int *)(param_1 + 0x21cc);
            puVar10 = (undefined1 *)(param_3 + 1);
            if (param_3 == (int *)0x0) {
              puVar10 = zerov6Addr;
            }
[32m[32m            memcpy(auStack_48,puVar10,0x10);[0m[0m
            bVar2 = true;
            if (iVar5 == local_40) {
              iVar5 = *(int *)(param_1 + 0x21d0);
              puVar10 = (undefined1 *)(param_3 + 1);
              if (param_3 == (int *)0x0) {
                puVar10 = zerov6Addr;
              }
[32m[32m              memcpy(auStack_38,puVar10,0x10);[0m[0m
              bVar2 = iVar5 != local_2c;
            }
          }
        }
        if (param_4 == (int *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = param_4[1];
        }
        bVar3 = *(int *)(param_1 + 0x219c) != iVar5;
        if (param_2 == (int *)0x0) {
          *(undefined4 *)(param_1 + 0x21b0) = 0;
        }
        else {
[32m[32m          memcpy((void *)(param_1 + 0x21ac),param_2,0x14);[0m[0m
        }
        __dest = (void *)(param_1 + 0x21c0);
        if (param_3 == (int *)0x0) {
          puVar10 = zerov6Addr;
          __dest = (void *)(param_1 + 0x21c4);
[32m          __n = 0x10;[0m
        }
        else {
[32m          __n = 0x14;[0m
          puVar10 = (undefined1 *)param_3;
        }
[32m[32m        memcpy(__dest,puVar10,__n);[0m[0m
        if (param_4 == (int *)0x0) {
          *(undefined4 *)(param_1 + 0x219c) = 0;
        }
        else {
[32m[32m          memcpy((void *)(param_1 + 0x2198),param_4,0x14);[0m[0m
        }
        if ((bVar2) || (bVar3 || bVar1)) {
          if (mDNS_LoggingEnabled != 0) {
            if (bVar1) {
              pcVar9 = "v4Changed ";
            }
            else {
              pcVar9 = "";
            }
            if (bVar3) {
              pcVar11 = "RouterChanged ";
            }
            else {
              pcVar11 = "";
            }
            if (bVar2) {
              pcVar6 = "v6Changed ";
            }
            else {
              pcVar6 = "";
            }
            LogMsgWithLevel(3,"mDNS_SetPrimaryInterfaceInfo: %s%s%s%#a %#a %#a",pcVar9,pcVar11,
                            pcVar6,param_2,param_3,param_4);
          }
          for (puVar12 = *(undefined4 **)(param_1 + 0x28f8); puVar12 != (undefined4 *)0x0;
              puVar12 = (undefined4 *)*puVar12) {
            if (mDNS_LoggingEnabled != 0) {
              LogMsgWithLevel(3,
                              "mDNS_SetPrimaryInterfaceInfo updating host name registrations for %##s"
                              ,puVar12 + 0x13);
            }
            if ((1 < *(byte *)(puVar12 + 0x54)) &&
               (*(int *)(puVar12[0x5c] + 4) != *(int *)(param_1 + 0x21b0))) {
              if (mDNS_LoggingEnabled != 0) {
                uVar7 = GetRRDisplayString_rdb(puVar12 + 0x54,puVar12[0x5c] + 4,param_1 + 0x2f);
                LogMsgWithLevel(3,"mDNS_SetPrimaryInterfaceInfo deregistering %s",uVar7);
              }
              mDNS_Deregister_internal(param_1,puVar12 + 0x53,0);
            }
            if ((1 < *(byte *)(puVar12 + 0x135)) &&
               ((((iVar5 = puVar12[0x13d], *(int *)(iVar5 + 4) != *(int *)(param_1 + 0x21c4) ||
                  (*(int *)(iVar5 + 8) != *(int *)(param_1 + 0x21c8))) ||
                 (*(int *)(iVar5 + 0xc) != *(int *)(param_1 + 0x21cc))) ||
                (*(int *)(iVar5 + 0x10) != *(int *)(param_1 + 0x21d0))))) {
              if (mDNS_LoggingEnabled != 0) {
                uVar7 = GetRRDisplayString_rdb(puVar12 + 0x135,iVar5 + 4,param_1 + 0x2f);
                LogMsgWithLevel(3,"mDNS_SetPrimaryInterfaceInfo deregistering %s",uVar7);
              }
              mDNS_Deregister_internal(param_1,puVar12 + 0x134,0);
            }
            FUN_00410980(param_1,puVar12);
          }
          iVar5 = 5;
          if (bVar3 || bVar1) {
            *(undefined2 *)(param_1 + 0x29e4) = 0;
            if (param_2 != (int *)0x0) {
              iVar5 = 0;
            }
            *(undefined4 *)(param_1 + 0x29c8) = 0;
            RecreateNATMappings(param_1,iVar5 * mDNSPlatformOneSecond);
            for (puVar12 = *(undefined4 **)(param_1 + 0x29b8); puVar12 != (undefined4 *)0x0;
                puVar12 = (undefined4 *)*puVar12) {
              puVar12[9] = 0;
            }
            if (mDNS_LoggingEnabled != 0) {
              if (bVar1) {
                pcVar9 = " v4Changed";
              }
              else {
                pcVar9 = "";
              }
              if (bVar3) {
                pcVar11 = " RouterChanged";
              }
              else {
                pcVar11 = "";
              }
              LogMsgWithLevel(3,
                              "mDNS_SetPrimaryInterfaceInfo:%s%s: recreating NAT mappings in %d seconds"
                              ,pcVar9,pcVar11,iVar5);
            }
          }
          if (*(int *)(param_1 + 0x21e8) != -1) {
            mDNS_StopQuery_internal(param_1,param_1 + 0x21d8);
          }
          iVar5 = *(int *)(param_1 + 0x234);
          *(undefined *)(param_1 + 0x26f8) = 0;
          if (iVar5 == 0) {
            iVar5 = 1;
          }
          *(int *)(param_1 + 0x218c) = iVar5;
        }
        iVar5 = *(int *)(param_1 + 0x24) + -1;
        *(int *)(param_1 + 0x24) = iVar5;
        if (iVar5 != *(int *)(param_1 + 0x28)) {
          LogMsgWithLevel(0,
                          "%s: mDNS_Unlock: Locking failure! mDNS_busy (%ld) != mDNS_reentrancy (%ld)"
                          ,"mDNS_SetPrimaryInterfaceInfo");
        }
        if (*(int *)(param_1 + 0x24) == 0) {
          iVar8 = *(int *)(param_1 + 0x234);
          iVar13 = iVar8 + 0x78000000;
          iVar5 = iVar13;
          if (((*(int *)(param_1 + 0xc) == 0) &&
              ((iVar5 = iVar8, *(int *)(param_1 + 0x2b0) == 0 ||
               (iVar13 = *(int *)(*(int *)(param_1 + 0x2b0) + 8), iVar13 != 0)))) &&
             (*(int *)(param_1 + 700) == 0)) {
            for (piVar4 = *(int **)(param_1 + 0x2168); piVar4 != (int *)0x0; piVar4 = (int *)*piVar4
                ) {
              if (*(char *)(piVar4 + 1) != '\x02') goto LAB_0041e3f0;
            }
            if (((*(char *)(param_1 + 0x2170) == '\0') && (*(int *)(param_1 + 0x2aa4) == 0)) &&
               (*(char *)(param_1 + 0x274) == '\0')) {
              iVar5 = *(int *)(param_1 + 0x218c);
              if (0 < iVar13 - *(int *)(param_1 + 0x2188)) {
                iVar13 = *(int *)(param_1 + 0x2188);
              }
              if (0 < iVar13 - *(int *)(param_1 + 600)) {
                iVar13 = *(int *)(param_1 + 600);
              }
              if ((iVar5 != 0) && (0 < iVar13 - iVar5)) {
                iVar13 = iVar5;
              }
              if (0 < iVar13 - *(int *)(param_1 + 0x248)) {
                iVar13 = *(int *)(param_1 + 0x248);
              }
              iVar8 = *(int *)(param_1 + 0x280);
              if (0 < iVar13 - *(int *)(param_1 + 0x25c)) {
                iVar13 = *(int *)(param_1 + 0x25c);
              }
              if (0 < iVar13 - *(int *)(param_1 + 0x260)) {
                iVar13 = *(int *)(param_1 + 0x260);
              }
              iVar5 = iVar13;
              if (iVar8 == 0) {
                if ((*(int *)(param_1 + 0x284) != 0) &&
                   (iVar5 = *(int *)(param_1 + 0x2a4), iVar13 - *(int *)(param_1 + 0x2a4) < 1)) {
                  iVar5 = iVar13;
                }
              }
              else if (0 < iVar13 - iVar8) {
                iVar5 = iVar8;
              }
              iVar13 = *(int *)(param_1 + 0x244);
              iVar8 = iVar5 - iVar13;
              if (iVar13 == 0) {
                iVar13 = *(int *)(param_1 + 0x254);
                if (0 < iVar5 - *(int *)(param_1 + 0x24c)) {
                  iVar5 = *(int *)(param_1 + 0x24c);
                }
                if (0 < iVar5 - *(int *)(param_1 + 0x250)) {
                  iVar5 = *(int *)(param_1 + 0x250);
                }
                iVar8 = iVar5 - iVar13;
              }
              if (0 < iVar8) {
                iVar5 = iVar13;
              }
              if (0 < iVar5 - *(int *)(param_1 + 0x2a8)) {
                iVar5 = *(int *)(param_1 + 0x2a8);
              }
            }
          }
LAB_0041e3f0:
          *(int *)(param_1 + 0x23c) = iVar5;
          if (*(int *)(param_1 + 0x234) == 0) {
            LogMsgWithLevel(0,"%s: mDNS_Unlock: ERROR! m->timenow aready zero",
                            "mDNS_SetPrimaryInterfaceInfo");
          }
          *(undefined4 *)(param_1 + 0x234) = 0;
        }
                    /* WARNING: Could not recover jumptable at 0x0041e430. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        mDNSPlatformUnlock(param_1);
        return;
      }
      pcVar9 = "mDNS_SetPrimaryInterfaceInfo passed non-v4 router.  Discarding. %#a";
    }
    else {
      pcVar9 = "mDNS_SetPrimaryInterfaceInfo v6 address - incorrect type.  Discarding. %#a";
      param_4 = param_3;
    }
  }
  else {
    pcVar9 = "mDNS_SetPrimaryInterfaceInfo v4 address - incorrect type.  Discarding. %#a";
    param_4 = param_2;
  }
  piStackX_8 = param_4;
  FUN_00407c70(0,pcVar9,&piStackX_8);
  return;
}

[ASK_GPT] 1347a32ad020ce40
