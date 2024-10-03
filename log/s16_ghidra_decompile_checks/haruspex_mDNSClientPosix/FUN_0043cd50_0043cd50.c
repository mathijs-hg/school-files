
/* WARNING: Removing unreachable block (ram,0x0043dc64) */
/* WARNING: Removing unreachable block (ram,0x0043dcb8) */
/* WARNING: Could not reconcile some variable overlaps */

int FUN_0043cd50(int param_1,ushort *param_2,undefined4 param_3,int *param_4,int *param_5,
                byte param_6,byte param_7,byte param_8,int param_9)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 *puVar4;
  int iVar5;
  int **ppiVar6;
  undefined4 uVar7;
  int **ppiVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  ushort *puVar12;
  undefined4 *puVar13;
  int iVar14;
  int iVar15;
  undefined4 *puVar16;
  int **ppiVar17;
  int *piVar18;
  undefined4 *puVar19;
  ushort *puVar20;
  int *piVar21;
  int **local_5b8;
  int ***local_5b4;
  int *local_5b0;
  int *local_5ac;
  int *piStack_5a8;
  int local_5a4;
  int local_564;
  undefined4 local_474;
  undefined auStack_454 [256];
  undefined4 local_354;
  undefined auStack_318 [340];
  int *apiStack_1c4 [64];
  undefined2 local_c4;
  undefined2 local_c2;
  int **local_88;
  int **local_84;
  undefined *local_80;
  int local_7c;
  uint local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  uint local_60;
  int **local_5c;
  int **local_58;
  int **local_54;
  uint local_50;
  int *local_4c;
  int local_48;
  uint local_44;
  int local_40;
  int **local_3c;
  char *local_38;
  int *local_34;
  int **local_30;
  
  local_78 = (uint)param_6;
  local_60 = (uint)param_7;
  local_44 = (uint)param_8;
  if (param_4 == (int *)0x0) {
LAB_0043cdd4:
    local_48 = 0;
  }
  else {
    iVar5 = FUN_00426100(param_1,param_5,param_4);
    local_48 = 1;
    if (iVar5 == 0) goto LAB_0043cdd4;
  }
  local_5b4 = &local_5b8;
  local_5b8 = (int **)0x0;
  local_5b0 = (int *)0x0;
  local_5ac = (int *)0x0;
  iVar5 = LocateOptRR(param_2,param_3,0xc);
  if (iVar5 != 0) {
    iVar5 = GetLargeResourceRecord(param_1,param_2,iVar5,param_3,param_5,0x80,param_1 + 0x7fa8);
    if (((iVar5 != 0) && (*(char *)(param_1 + 0x7fac) != -0x10)) &&
       (ppiVar6 = (int **)0x4, *(short *)(param_1 + 0x7fae) == 0x29)) {
      puVar12 = (ushort *)(*(int *)(param_1 + 0x7fcc) + 4);
      puVar20 = (ushort *)((int)puVar12 + (uint)*(ushort *)(param_1 + 0x7fb8));
      for (; puVar12 < puVar20; puVar12 = puVar12 + 0xc) {
        if ((((int **)(uint)*puVar12 == ppiVar6) && (*(char *)(puVar12 + 2) == '\0')) &&
           (*(int *)(puVar12 + 3) != 0)) {
          local_3c = ppiVar6;
          FUN_0043cad4(param_1,puVar12 + 2,*(undefined4 *)(param_1 + 0x2164));
          FUN_0043cad4(param_1,puVar12 + 2,*(undefined4 *)(param_1 + 0x2160));
          ppiVar6 = local_3c;
        }
      }
    }
    *(undefined *)(param_1 + 0x7fac) = 0;
  }
  local_58 = (int **)(param_2 + 6);
  local_7c = param_1 + 0x7fac;
  local_80 = (undefined *)(param_1 + 0x7fa8);
  local_64 = param_1 + 0x2f;
  local_68 = 0;
  FUN_004382b0(param_1,param_2,param_3,param_5,&local_5ac);
  local_54 = &local_5b0;
  local_84 = &piStack_5a8;
  local_88 = local_58;
  local_40 = param_9;
  piVar21 = (int *)0x0;
  local_4c = param_4;
LAB_0043d6b8:
  iVar5 = local_40;
  piVar18 = local_4c;
  if (local_68 < (int)(uint)param_2[2]) {
    local_88 = (int **)getQuestion(param_2,local_88,param_3,param_5,local_84);
    piVar18 = local_4c;
    if (local_88 != (int **)0x0) {
      local_564 = 0;
      if (local_5ac != (int *)0x0) {
        InitializeAnonInfoForQuestion(param_1,&local_5ac,local_84);
      }
      if ((local_60 == 0) || (local_78 != 0)) {
        local_50 = 0;
      }
      else {
        local_50 = (uint)~(int)local_354._2_2_ >> 0x1f;
      }
      if (local_354._2_2_ < 0) {
        *(int *)(param_1 + 0x397c) = *(int *)(param_1 + 0x397c) + 1;
      }
      else {
        *(int *)(param_1 + 0x3980) = *(int *)(param_1 + 0x3980) + 1;
      }
      iVar5 = *(int *)(param_1 + 0x216c);
      local_354 = local_354 & 0xffff7fff;
      if (iVar5 != 0) {
        uVar7 = GetRRDisplayString_rdb(iVar5 + 4,*(int *)(iVar5 + 0x24) + 4,local_64);
        LogMsgWithLevel(0,"ProcessQuery ERROR m->CurrentRecord already set %s",uVar7);
      }
      local_5c = (int **)&SUB_fffffffe;
      if (local_78 != 0) {
        local_5c = local_88;
      }
      *(undefined4 *)(param_1 + 0x216c) = *(undefined4 *)(param_1 + 0x2160);
      local_6c = 0;
      puVar4 = (undefined4 *)0x0;
LAB_0043d538:
      do {
        puVar16 = puVar4;
        puVar13 = *(undefined4 **)(param_1 + 0x216c);
        puVar19 = puVar13 + 1;
        if (puVar13 == (undefined4 *)0x0) goto code_r0x0043d544;
        *(undefined4 *)(param_1 + 0x216c) = *puVar13;
        iVar5 = AnyTypeRecordAnswersQuestion(puVar19,local_84);
        puVar4 = puVar16;
        if (iVar5 != 0) {
          if (((local_44 != 0) || (local_60 != 0)) || (*(char *)((int)puVar13 + 0x49) != '\0')) {
            *(int *)(param_1 + 0x3984) = *(int *)(param_1 + 0x3984) + 1;
            if (((*(short *)((int)puVar13 + 6) == 5) ||
                (*(short *)((int)puVar13 + 6) == local_354._0_2_)) ||
               ((local_354._0_2_ == 0xff || (iVar5 = RRAssertsNonexistence(puVar19), iVar5 != 0))))
            {
              if (*(byte *)(puVar13 + 1) == 2) {
                bVar1 = false;
                local_74 = 0;
                local_70 = LocateAuthorities(param_2,param_3);
                while ((local_74 < (int)(uint)param_2[4] &&
                       (local_70 = GetLargeResourceRecord
                                             (param_1,param_2,local_70,param_3,local_474,0xa0,
                                              local_80), local_70 != 0))) {
                  if ((*(char *)(param_1 + 0x7fac) != -0x10) &&
                     (iVar5 = ResourceRecordAnswersQuestion(local_7c,local_84), iVar5 != 0)) {
                    iVar5 = FUN_0042d4d0(param_1,puVar13,local_80);
                    bVar1 = true;
                    if (iVar5 != 0) {
                      iVar5 = (uint)*(ushort *)(puVar13 + 2) - (uint)*(ushort *)(param_1 + 0x7fb0);
                      if (((iVar5 == 0) &&
                          (iVar5 = (uint)*(ushort *)((int)puVar13 + 6) -
                                   (uint)*(ushort *)(param_1 + 0x7fae), iVar5 == 0)) &&
                         (iVar5 = FUN_0042df20(puVar13,local_80), iVar5 == 0)) {
                        bVar1 = true;
                      }
                      else {
                        local_38 = "lost:";
                        if (-1 < iVar5) {
                          local_38 = "won: ";
                        }
                        local_34 = *(int **)(param_1 + 0x7fc0);
                        local_30 = (int **)local_474;
                        uVar7 = GetRRDisplayString_rdb
                                          (local_7c,*(int *)(param_1 + 0x7fcc) + 4,local_64);
                        LogMsgWithLevel(0,"ResolveSimultaneousProbe: %p Pkt Record:        %08lX %s"
                                        ,local_30,local_34,uVar7);
                        local_3c = (int **)puVar13[7];
                        local_34 = (int *)(uint)*(byte *)((int)puVar13 + 0x86);
                        local_30 = (int **)puVar13[6];
                        uVar7 = GetRRDisplayString_rdb(puVar19,puVar13[9] + 4,local_64);
                        LogMsgWithLevel(0,"ResolveSimultaneousProbe: %p Our Record %d %s %08lX %s",
                                        local_3c,local_34,local_38,local_30,uVar7);
                        bVar1 = true;
                        if (iVar5 < 0) {
                          iVar5 = (int)mDNSPlatformOneSecond + *(int *)(param_1 + 0x234);
                          if (iVar5 == 0) {
                            iVar5 = 1;
                          }
                          *(int *)(param_1 + 0x2180) = iVar5;
                          *(undefined *)((int)puVar13 + 0x86) = 3;
                          *(undefined *)((int)puVar13 + 0x87) = 4;
                          FUN_00428828(param_1,puVar13);
                          goto LAB_0043d394;
                        }
                      }
                    }
                  }
                  *(undefined *)(param_1 + 0x7fac) = 0;
                  local_74 = local_74 + 1;
                }
                if ((!bVar1) && (mDNS_LoggingEnabled != 0)) {
                  local_3c = (int **)puVar13[8];
                  uVar7 = DNSTypeName(*(undefined2 *)((int)puVar13 + 6));
                  LogMsgWithLevel(3,"ResolveSimultaneousProbe: %##s (%s): No Update Record found",
                                  local_3c,uVar7);
                }
LAB_0043d394:
                *(undefined *)(param_1 + 0x7fac) = 0;
              }
              else if (((((*(byte *)(puVar13 + 1) & 0x3c) != 0) &&
                        ((puVar13[0xc] == 0 || ((*(byte *)(puVar13[0xc] + 4) & 0x3c) != 0)))) &&
                       ((puVar13[0xd] == 0 || ((*(byte *)(puVar13[0xd] + 4) & 0x3c) != 0)))) &&
                      ((puVar13[0xe] == 0 || ((*(byte *)(puVar13[0xe] + 4) & 0x3c) != 0)))) {
                local_6c = local_6c + 1;
                if ((local_564 != 0) && (puVar13[0xb] != 0)) {
                  SetAnonData(local_84,puVar19,1);
                }
                if ((local_50 == 0) && (((local_48 != 0 || (local_60 == 0)) || (local_78 != 0)))) {
                  if (puVar13[0x2d] == 0) {
                    puVar13[0x2d] = local_5c;
                  }
                }
                else if ((-1 < (-puVar13[0x31] - (int)mDNSPlatformOneSecond) +
                               *(int *)(param_1 + 0x234)) ||
                        (((int *)puVar13[0x32] != (int *)0xffffffff &&
                         ((int *)puVar13[0x32] != param_5)))) {
                  puVar13[0x2d] = 0xffffffff;
                }
              }
            }
            else if (((((((*(byte *)(puVar13 + 1) & 0x30) != 0) &&
                        ((*(byte *)(puVar13 + 1) & 0x3c) != 0)) &&
                       ((puVar13[0xc] == 0 || ((*(byte *)(puVar13[0xc] + 4) & 0x3c) != 0)))) &&
                      ((puVar13[0xd] == 0 || ((*(byte *)(puVar13[0xd] + 4) & 0x3c) != 0)))) &&
                     ((puVar13[0xe] == 0 || ((*(byte *)(puVar13[0xe] + 4) & 0x3c) != 0)))) &&
                    (puVar4 = puVar13, puVar16 == (undefined4 *)0x0)) goto LAB_0043d538;
          }
          puVar4 = puVar16;
        }
      } while( true );
    }
    goto LAB_0043dfac;
  }
  for (ppiVar6 = *(int ***)(param_1 + 0x2160); ppiVar6 != (int **)0x0; ppiVar6 = (int **)*ppiVar6) {
    if (((ppiVar6[0x2d] != (int *)0x0) && (ppiVar6[0x2c] == (int *)0x0)) &&
       (local_5b4 != (int ***)(ppiVar6 + 0x2c))) {
      *local_5b4 = ppiVar6;
      ppiVar6[0x2e] = (int *)0x0;
      local_5b4 = (int ***)(ppiVar6 + 0x2c);
    }
  }
  FUN_0042a238(param_1,local_5b8,&local_5b4,param_5);
  local_84 = &local_5b0;
  for (iVar14 = 0; ppiVar6 = local_5b8, iVar14 < (int)(uint)param_2[3]; iVar14 = iVar14 + 1) {
    local_88 = (int **)GetLargeResourceRecord
                                 (param_1,param_2,local_88,param_3,param_5,0xc0,local_80);
    if (local_88 == (int **)0x0) goto LAB_0043dfac;
    ppiVar6 = local_5b8;
    if (*(char *)(param_1 + 0x7fac) != -0x10) {
      for (; ppiVar6 != (int **)0x0; ppiVar6 = (int **)ppiVar6[0x2c]) {
        if (((ppiVar6[0x2d] != (int *)0x0) || (ppiVar6[0x2e] != (int *)0x0)) &&
           (local_30 = ppiVar6, iVar15 = FUN_0042d7b4(local_80,ppiVar6), ppiVar6 = local_30,
           iVar15 != 0)) {
          *(int *)(param_1 + 0x3970) = *(int *)(param_1 + 0x3970) + 1;
          local_30[0x2d] = (int *)0x0;
          local_30[0x2e] = (int *)0x0;
        }
      }
      for (ppiVar6 = *(int ***)(param_1 + 0x2160); ppiVar6 != (int **)0x0;
          ppiVar6 = (int **)*ppiVar6) {
        if ((ppiVar6[0x24] == param_5) &&
           (local_30 = ppiVar6, iVar15 = FUN_0042d7b4(local_80,ppiVar6), ppiVar6 = local_30,
           iVar15 != 0)) {
          if (*piVar18 == 4) {
            if (local_30[0x27] == (int *)piVar18[1]) {
              local_30[0x27] = (int *)0x0;
            }
          }
          else if ((((*piVar18 == 6) && (local_30[0x28] == (int *)piVar18[1])) &&
                   (local_30[0x29] == (int *)piVar18[2])) &&
                  ((local_30[0x2a] == (int *)piVar18[3] && (local_30[0x2b] == (int *)piVar18[4]))))
          {
[32m[32m            memcpy(local_30 + 0x28,zerov6Addr,0x10);[0m[0m
          }
          ppiVar6 = local_30;
          if (((local_30[0x27] == (int *)0x0) && (local_30[0x29] == (int *)0x0)) &&
             ((local_30[0x28] == (int *)0x0 &&
              ((local_30[0x2a] == (int *)0x0 && (local_30[0x2b] == (int *)0x0)))))) {
            *(int *)(param_1 + 0x3970) = *(int *)(param_1 + 0x3970) + 1;
            local_30[0x24] = (int *)0x0;
            *(undefined *)((int)local_30 + 0x8b) = 0;
          }
        }
      }
      iVar15 = FUN_0042d2bc(param_1,local_7c);
      ppiVar6 = local_84;
      if (iVar15 == 0) {
        while (ppiVar17 = (int **)*ppiVar6, ppiVar17 != (int **)0x0) {
          local_3c = ppiVar6;
          local_30 = ppiVar17;
          iVar15 = ResourceRecordAnswersQuestion(local_7c,ppiVar17);
          ppiVar17 = local_30;
          ppiVar6 = local_3c;
          if (iVar15 == 0) {
            ppiVar6 = local_30 + 0x10;
          }
          else {
            *local_3c = local_30[0x10];
            ppiVar17[0x10] = (int *)0x0;
          }
        }
      }
    }
    *(undefined *)(param_1 + 0x7fac) = 0;
  }
  for (; bVar1 = false, ppiVar6 != (int **)0x0; ppiVar6 = (int **)ppiVar6[0x2c]) {
    piVar11 = ppiVar6[0x2e];
    if (((piVar11 != (int *)0x0) && (piVar11[0x2d] == 0)) && (piVar11[0x2e] == 0)) {
      ppiVar6[0x2d] = (int *)0x0;
      ppiVar6[0x2e] = (int *)0x0;
    }
  }
  local_88 = (int **)(piVar18 + 1);
  piVar11 = (int *)0xffffffff;
  ppiVar6 = &mDNSPlatformOneSecond;
  for (ppiVar17 = local_5b8; ppiVar17 != (int **)0x0; ppiVar17 = (int **)ppiVar17[0x2c]) {
    piVar9 = ppiVar17[0x2d];
    if (piVar9 == (int *)0x0) {
      if ((ppiVar17[0x2e] != (int *)0x0) && ((int *)ppiVar17[0x2e][0x2d] == piVar11)) {
        ppiVar17[0x25] = param_5;
      }
    }
    else {
      iVar14 = (int)ppiVar17[3] * (int)*ppiVar6;
      if (iVar14 < 0) {
        iVar14 = iVar14 + 3;
      }
      bVar2 = false;
      if ((-1 < (*(int *)(param_1 + 0x234) - (int)ppiVar17[0x31]) - (iVar14 >> 2)) &&
         (bVar2 = true, piVar9 == (int *)&SUB_fffffffe)) {
        *(int *)(param_1 + 0x3990) = *(int *)(param_1 + 0x3990) + 1;
        ppiVar17[0x2d] = piVar11;
        piVar9 = ppiVar17[0x2d];
      }
      if (piVar9 == piVar11) {
        bVar3 = false;
        *(int *)(param_1 + 0x398c) = *(int *)(param_1 + 0x398c) + 1;
LAB_0043daa0:
        *(undefined4 *)(param_1 + 0x254) = *(undefined4 *)(param_1 + 0x234);
        if ((ppiVar17[0x24] == (int *)0x0) || (ppiVar17[0x24] == param_5)) {
          ppiVar17[0x24] = param_5;
          if (bVar3) {
            *(undefined *)((int)ppiVar17 + 0x8b) = 1;
          }
          if (*piVar18 == 4) {
            if (ppiVar17[0x27] == (int *)0x0) {
              ppiVar17[0x27] = (int *)piVar18[1];
            }
            else if (ppiVar17[0x27] != (int *)piVar18[1]) {
              ppiVar17[0x27] = (int *)0xffffffff;
            }
          }
          else if (*piVar18 == 6) {
            if ((((ppiVar17[0x29] == (int *)0x0) && (ppiVar17[0x28] == (int *)0x0)) &&
                (ppiVar17[0x2a] == (int *)0x0)) && (ppiVar17[0x2b] == (int *)0x0)) {
              local_34 = piVar11;
              local_30 = ppiVar6;
[32m[32m              memcpy(ppiVar17 + 0x28,local_88,0x10);[0m[0m
              ppiVar6 = local_30;
              piVar11 = local_34;
            }
            else if (((ppiVar17[0x28] != (int *)piVar18[1]) || (ppiVar17[0x29] != (int *)piVar18[2])
                     ) || ((ppiVar17[0x2a] != (int *)piVar18[3] ||
                           (ppiVar17[0x2b] != (int *)piVar18[4])))) {
              local_34 = piVar11;
              local_30 = ppiVar6;
[32m[32m              memcpy(ppiVar17 + 0x28,onesIPv6Addr,0x10);[0m[0m
              ppiVar6 = local_30;
              piVar11 = local_34;
            }
          }
        }
        else {
          ppiVar17[0x24] = (int *)0xffffffff;
        }
      }
      else {
        if (piVar9 == (int *)&SUB_fffffffe) {
          bVar3 = true;
          *(int *)(param_1 + 0x3988) = *(int *)(param_1 + 0x3988) + 1;
          goto LAB_0043daa0;
        }
        if (piVar9 != (int *)0x0) {
          bVar1 = true;
        }
        bVar3 = false;
        if (bVar2) goto LAB_0043daa0;
      }
      if ((*(byte *)(param_2 + 1) & 2) == 0) {
        if (*(char *)(ppiVar17 + 1) == '\b') {
          piVar21 = *ppiVar6;
        }
      }
      else {
        piVar21 = (int *)((int)*ppiVar6 * 0x14);
      }
    }
  }
  if ((piVar21 != (int *)0x0) &&
     ((*(int *)(param_1 + 0x244) == 0 ||
      (*(int *)(param_1 + 0x244) - *(int *)(param_1 + 0x234) < ((int)piVar21 + 0x31) / 0x32)))) {
    iVar15 = *(int *)(param_1 + 0x234);
    iVar14 = mDNSRandom((int)mDNSPlatformOneSecond * 5);
    iVar15 = ((int)piVar21 + iVar14 + 0x31) / 0x32 + iVar15;
    *(int *)(param_1 + 0x244) = iVar15;
    if (iVar15 == 0) {
      *(undefined4 *)(param_1 + 0x244) = 1;
    }
  }
  ppiVar6 = local_5b8;
  if (bVar1) {
    local_88 = (int **)(iVar5 + 0x22f8);
    iVar14 = iVar5 + 0xc;
    piVar21 = (int *)0x70000000;
    InitializeDNSMessage(iVar5,(uint)*param_2 << 0x10,0x84000000);
    if (local_78 != 0) {
      local_84 = apiStack_1c4;
      ppiVar17 = local_58;
      local_80 = auStack_318;
      for (iVar15 = 0; iVar15 < (int)(uint)param_2[2]; iVar15 = iVar15 + 1) {
        ppiVar17 = (int **)getQuestion(param_2,ppiVar17,param_3,param_5,local_80);
        ppiVar8 = ppiVar6;
        if (ppiVar17 == (int **)0x0) goto LAB_0043dfac;
        for (; ppiVar8 != (int **)0x0; ppiVar8 = (int **)ppiVar8[0x2c]) {
          if ((int **)ppiVar8[0x2d] == ppiVar17) {
            local_30 = ppiVar17;
            iVar14 = putQuestion(iVar5,iVar14,local_88,local_84,local_c4,local_c2);
            ppiVar17 = local_30;
            if (iVar14 == 0) {
              *(undefined *)(param_1 + 0x7fac) = 0;
              goto LAB_0043dfc8;
            }
            break;
          }
        }
      }
      piVar21 = (int *)0xa;
      if (*(short *)(iVar5 + 4) == 0) {
        LogMsgWithLevel(0,"GenerateUnicastResponse: ERROR! Why no questions?");
        goto LAB_0043dfac;
      }
    }
    for (ppiVar17 = ppiVar6; ppiVar17 != (int **)0x0; ppiVar17 = (int **)ppiVar17[0x2c]) {
      iVar15 = iVar14;
      if (ppiVar17[0x2d] != (int *)0x0) {
        if (((*(short *)(iVar5 + 6) != 0) || (*(short *)(iVar5 + 8) != 0)) ||
           (iVar15 = iVar5 + 0x22ec, *(short *)(iVar5 + 10) != 0)) {
          iVar15 = iVar5 + 0x5a0;
        }
        piVar11 = ppiVar17[3];
        if (piVar21 <= ppiVar17[3]) {
          piVar11 = piVar21;
        }
        iVar15 = PutResourceRecordTTLWithLimit
                           (iVar5,iVar14,iVar5 + 6,ppiVar17 + 1,piVar11,iVar15 + 0xc);
        if (iVar15 == 0) {
          *(byte *)(iVar5 + 2) = *(byte *)(iVar5 + 2) | 2;
          iVar15 = iVar14;
        }
      }
      iVar14 = iVar15;
    }
    for (; ppiVar6 != (int **)0x0; ppiVar6 = (int **)ppiVar6[0x2c]) {
      iVar15 = iVar14;
      if ((ppiVar6[0x2e] != (int *)0x0) && (ppiVar6[0x2d] == (int *)0x0)) {
        if ((*(short *)(iVar5 + 6) != 0) ||
           ((*(short *)(iVar5 + 8) != 0 || (iVar15 = iVar5 + 0x22ec, *(short *)(iVar5 + 10) != 0))))
        {
          iVar15 = iVar5 + 0x5a0;
        }
        piVar11 = ppiVar6[3];
        if (piVar21 <= ppiVar6[3]) {
          piVar11 = piVar21;
        }
        iVar15 = PutResourceRecordTTLWithLimit
                           (iVar5,iVar14,iVar5 + 10,ppiVar6 + 1,piVar11,iVar15 + 0xc);
        if (iVar15 == 0) {
          iVar15 = iVar14;
        }
      }
      iVar14 = iVar15;
    }
    *(undefined *)(param_1 + 0x7fac) = 0;
  }
  else {
LAB_0043dfac:
    iVar14 = 0;
    *(undefined *)(param_1 + 0x7fac) = 0;
  }
LAB_0043dfc8:
  while (local_5b8 != (int **)0x0) {
    ppiVar6 = (int **)local_5b8[0x2c];
    local_5b8[0x2e] = (int *)0x0;
    local_5b8[0x2c] = (int *)0x0;
    local_5b8[0x2d] = (int *)0x0;
    local_5b8 = ppiVar6;
  }
  do {
    piVar21 = local_5ac;
    if (local_5b0 == (int *)0x0) {
      while (piVar21 != (int *)0x0) {
        piVar21 = (int *)*piVar21;
        ReleaseCacheRecord(param_1);
      }
      return iVar14;
    }
    piVar11 = (int *)local_5b0[0x10];
    iVar5 = 0;
    local_5b0[0x10] = 0;
    iVar15 = *(int *)(param_1 + 0x234);
    piVar21 = local_5b0;
    do {
      if (((int *)piVar21[0x13] == param_5) && (piVar21[0x14] == *piVar18)) goto LAB_0043e074;
      iVar5 = iVar5 + 1;
      piVar21 = piVar21 + 3;
    } while (iVar5 != 8);
    iVar5 = 0;
    iVar10 = 1;
    piVar21 = local_5b0;
    do {
      if (local_5b0[iVar5 * 3 + 0x13] == 0) break;
      if ((piVar21[0x16] == 0) || (piVar21[0x15] - local_5b0[iVar5 * 3 + 0x12] < 0)) {
        iVar5 = iVar10;
      }
      iVar10 = iVar10 + 1;
      piVar21 = piVar21 + 3;
    } while (iVar10 != 8);
LAB_0043e074:
    local_5b0[iVar5 * 3 + 0x14] = *piVar18;
    local_5b0[iVar5 * 3 + 0x12] = iVar15;
    local_5b0[iVar5 * 3 + 0x13] = (int)param_5;
    local_5b0 = piVar11;
  } while( true );
code_r0x0043d544:
  piVar18 = piVar21;
  if ((local_6c == 0) && (piVar18 = mDNSPlatformOneSecond, puVar16 != (undefined4 *)0x0)) {
    puVar16[0x23] = param_5;
    *(undefined4 *)(param_1 + 0x254) = *(undefined4 *)(param_1 + 0x234);
    piVar18 = piVar21;
  }
  if ((*(byte *)(param_2 + 1) & 2) != 0) {
    *(int *)(param_1 + 0x3974) = *(int *)(param_1 + 0x3974) + 1;
  }
  ppiVar6 = local_54;
  if (((local_50 != 0) && ((*(byte *)(param_2 + 1) & 2) == 0)) && (local_564 == 0)) {
    for (ppiVar17 = *(int ***)(param_1 + 0x2ac); ppiVar17 != (int **)0x0;
        ppiVar17 = (int **)*ppiVar17) {
      if (((ppiVar17[0x4f] == (int *)0x0) && (0 < (int)ppiVar17[4])) &&
         (ppiVar17[0xf] == (int *)0x0)) {
        piVar21 = mDNSPlatformOneSecond;
        if ((int)mDNSPlatformOneSecond < 0) {
          piVar21 = (int *)((int)mDNSPlatformOneSecond + 3);
        }
        if (((((int)piVar21 >> 2 < *(int *)(param_1 + 0x234) - (int)ppiVar17[0x2d]) &&
             ((ppiVar17[0x4d] == (int *)0x0 || (ppiVar17[0x4d] == param_5)))) &&
            (ppiVar17[0x10] == (int *)0x0)) &&
           ((((ppiVar6 != ppiVar17 + 0x10 && (ppiVar17[0x95] == (int *)local_354)) &&
             (ppiVar17[1] == (int *)local_5a4)) &&
            (iVar5 = SameDomainName(ppiVar17 + 0x55,auStack_454), iVar5 != 0)))) {
          *ppiVar6 = (int *)ppiVar17;
          ppiVar6 = ppiVar17 + 0x10;
        }
      }
    }
  }
  local_54 = ppiVar6;
  if (local_564 != 0) {
    FreeAnonInfo();
  }
  local_68 = local_68 + 1;
  piVar21 = piVar18;
  goto LAB_0043d6b8;
}

[ASK_GPT] 2b69d7736d0b877d
