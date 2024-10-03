
/* WARNING: Removing unreachable block (ram,0x0041c0c4) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Could not reconcile some variable overlaps */

byte * mDNS_vsnprintf(byte *param_1,int param_2,byte *param_3,int **param_4)

{
  byte *pbVar1;
  bool bVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  byte bVar8;
  char *pcVar7;
  int iVar9;
  int iVar10;
  uint uVar11;
  int ***pppiVar12;
  int iVar13;
  undefined *puVar14;
  byte *pbVar15;
  byte *pbVar16;
  int *piVar17;
  int *piVar18;
  byte *pbVar19;
  int **ppiVar20;
  undefined4 local_270;
  int *apiStack_264 [64];
  undefined4 local_164;
  undefined auStack_66 [45];
  undefined local_39;
  int **local_38 [3];
  int local_2c;
  
  pbVar16 = (byte *)0x0;
  if (param_2 != 0) {
    pbVar19 = (byte *)(param_2 + -1);
    if (pbVar19 != (byte *)0x0) {
LAB_0041c9a4:
      bVar8 = *param_3;
      if (bVar8 != 0) {
        pppiVar12 = local_38;
        if (bVar8 == 0x25) {
          iVar10 = 0;
          iVar9 = 0;
          bVar8 = 0;
          uVar3 = 0;
          iVar5 = 0;
          while( true ) {
            while( true ) {
              while( true ) {
                while( true ) {
                  while( true ) {
                    pbVar15 = param_3 + 1;
                    iVar13 = (int)(char)*pbVar15;
                    if (iVar13 != 0x2d) break;
                    iVar10 = 1;
                    param_3 = pbVar15;
                  }
                  if (iVar13 != 0x2b) break;
                  iVar9 = 1;
                  param_3 = pbVar15;
                }
                if (iVar13 != 0x20) break;
                bVar8 = 0x20;
                param_3 = pbVar15;
              }
              if (iVar13 != 0x23) break;
              uVar3 = (int)((uVar3 + 1) * 0x1000000) >> 0x18;
              param_3 = pbVar15;
            }
            if (iVar13 != 0x30) break;
            iVar5 = 1;
            param_3 = pbVar15;
          }
          local_270 = iVar10 << 0x1f | iVar9 << 0x1e | (uVar3 & 0xff) << 0x10;
          local_270 = local_270 | (uint)bVar8 << 8;
          local_270 = local_270 | iVar5 << 0x1d;
          if (iVar13 == 0x2a) {
            piVar18 = *param_4;
            if ((int)piVar18 < 0) {
              piVar18 = (int *)-(int)piVar18;
              local_270 = local_270 | 0x80000000;
            }
            pbVar15 = param_3 + 2;
            iVar13 = (int)(char)*pbVar15;
            ppiVar20 = param_4 + 1;
          }
          else {
            piVar18 = (int *)0x0;
            while (ppiVar20 = param_4, iVar13 - 0x30U < 10) {
              pbVar15 = pbVar15 + 1;
              piVar18 = (int *)((int)piVar18 * 10 + iVar13 + -0x30);
              iVar13 = (int)(char)*pbVar15;
            }
          }
          piVar17 = (int *)0x0;
          param_3 = pbVar15;
          if (iVar13 == 0x2e) {
            param_3 = pbVar15 + 1;
            iVar13 = (int)(char)*param_3;
            if (iVar13 == 0x2a) {
              param_3 = pbVar15 + 2;
              piVar17 = *ppiVar20;
              iVar13 = (int)(char)*param_3;
              ppiVar20 = ppiVar20 + 1;
            }
            else {
              while (iVar13 - 0x30U < 10) {
                param_3 = param_3 + 1;
                piVar17 = (int *)((int)piVar17 * 10 + iVar13 + -0x30);
                iVar13 = (int)(char)*param_3;
              }
            }
            local_270 = local_270 | 0x10000000;
          }
          if ((int)local_270 < 0) {
            local_270 = local_270 & 0xdfffffff;
          }
          iVar5 = 0;
          iVar9 = 0;
          while (pbVar15 = param_3 + 1, iVar13 != 0x69) {
            if (0x69 < iVar13) {
              if (iVar13 == 0x70) {
                piVar17 = (int *)0x8;
                local_270 = local_270 | iVar5 << 0x1b | 0x14000000;
LAB_0041c470:
                pcVar7 = "0123456789ABCDEF";
LAB_0041c478:
                piVar6 = *ppiVar20;
                if ((local_270 & 0x8000000) != 0) {
                  piVar6 = (int *)((uint)*ppiVar20 & 0xffff);
                }
                if ((local_270 & 0x10000000) == 0) {
                  if (((local_270 & 0x20000000) != 0) &&
                     (piVar17 = (int *)((int)piVar18 + -2), local_270._1_1_ == '\0')) {
                    piVar17 = piVar18;
                  }
                  if (piVar17 != (int *)0x0) goto LAB_0041c4cc;
                  piVar17 = (int *)0x1;
                }
                else {
LAB_0041c4cc:
                  if ((int *)0x12b < piVar17) {
                    piVar17 = (int *)0x12b;
                  }
                }
                piVar4 = (int *)0x0;
                for (; piVar6 != (int *)0x0; piVar6 = (int *)((uint)piVar6 >> 4)) {
                  pppiVar12 = (int ***)((int)pppiVar12 + -1);
                  piVar4 = (int *)((int)piVar4 + 1);
                  *(char *)pppiVar12 = pcVar7[(uint)piVar6 & 0xf];
                }
                for (; piVar4 < piVar17; piVar4 = (int *)((int)piVar4 + 1)) {
                  *(byte *)(int ***)((int)pppiVar12 + -1) = 0x30;
                  pppiVar12 = (int ***)((int)pppiVar12 + -1);
                }
                local_270._2_1_ = 0x30;
                param_4 = ppiVar20 + 1;
                if (local_270._1_1_ != '\0') {
                  *(byte *)((int)pppiVar12 + -1) = (byte)iVar13;
                  piVar4 = (int *)((int)piVar4 + 2);
                  pppiVar12 = (int ***)((int)pppiVar12 + -2);
                  goto LAB_0041c574;
                }
                goto LAB_0041c8b8;
              }
              if (iVar13 < 0x71) {
                if (iVar13 != 0x6e) {
                  if (iVar13 < 0x6f) {
                    if (iVar13 == 0x6c) goto LAB_0041bf94;
                    goto LAB_0041c84c;
                  }
                  param_4 = ppiVar20 + 1;
                  piVar6 = *ppiVar20;
                  if (iVar5 != 0) {
                    piVar6 = (int *)((uint)*ppiVar20 & 0xffff);
                  }
                  if ((local_270 & 0x10000000) == 0) {
                    if ((local_270 & 0x20000000) != 0) {
                      piVar17 = piVar18;
                    }
                    if (piVar17 != (int *)0x0) goto LAB_0041c18c;
                    piVar17 = (int *)0x1;
                  }
                  else {
LAB_0041c18c:
                    if ((int *)0x12b < piVar17) {
                      piVar17 = (int *)0x12b;
                    }
                  }
                  piVar4 = (int *)0x0;
                  for (; piVar6 != (int *)0x0; piVar6 = (int *)((uint)piVar6 >> 3)) {
                    pppiVar12 = (int ***)((int)pppiVar12 + -1);
                    *(byte *)pppiVar12 = ((byte)piVar6 & 7) + 0x30;
                    piVar4 = (int *)((int)piVar4 + 1);
                  }
                  if (((local_270._1_1_ != '\0') && (piVar4 != (int *)0x0)) &&
                     (*(byte *)pppiVar12 != 0x30)) {
                    pppiVar12 = (int ***)((int)pppiVar12 + -1);
                    piVar4 = (int *)((int)piVar4 + 1);
                    *(byte *)pppiVar12 = 0x30;
                  }
                  for (; piVar4 < piVar17; piVar4 = (int *)((int)piVar4 + 1)) {
                    *(byte *)(int ***)((int)pppiVar12 + -1) = 0x30;
                    pppiVar12 = (int ***)((int)pppiVar12 + -1);
                  }
                  bVar2 = piVar4 < piVar18;
                  local_270 = local_270 | iVar5 << 0x1b | iVar9 << 0x1a;
                  goto LAB_0041c8bc;
                }
                param_4 = ppiVar20 + 1;
                if (iVar5 == 0) {
                  **ppiVar20 = (int)pbVar16;
                }
                else {
                  *(short *)*ppiVar20 = (short)pbVar16;
                }
                goto LAB_0041c9a0;
              }
              if (iVar13 == 0x75) {
                uVar3 = local_270 & 0xffff0000 | iVar5 << 0x1b | iVar9 << 0x1a;
                piVar6 = *ppiVar20;
                if (iVar5 != 0) {
                  piVar6 = (int *)((uint)*ppiVar20 & 0xffff);
                }
                goto LAB_0041c060;
              }
              if (iVar13 == 0x78) {
                local_270 = local_270 | iVar5 << 0x1b | iVar9 << 0x1a;
                pcVar7 = "0123456789abcdef";
                goto LAB_0041c478;
              }
              if (iVar13 != 0x73) goto LAB_0041c84c;
              local_38[1] = ppiVar20 + 1;
              uVar3 = local_270 | iVar5 << 0x1b | iVar9 << 0x1a;
              pcVar7 = (char *)*ppiVar20;
              if ((int ***)pcVar7 == (int ***)0x0) {
                piVar4 = (int *)0x8;
                pcVar7 = s___NULL___0046e0b0;
                goto LAB_0041c7a8;
              }
              if (local_270._1_1_ == '\x01') {
                piVar4 = (int *)(uint)(byte)*pcVar7;
                pcVar7 = (char *)((int)pcVar7 + 1);
                goto LAB_0041c7a8;
              }
              if (local_270._1_1_ != '\x02') {
                if (local_270._1_1_ == '\0') {
                  piVar6 = (int *)0x0;
                  if ((local_270 & 0x10000000) == 0) {
                    do {
                      piVar4 = piVar6;
                      piVar6 = (int *)((int)piVar4 + 1);
                    } while (*(byte *)((int)pcVar7 + (int)piVar4) != 0);
                  }
                  else {
                    bVar2 = piVar17 != (int *)0x0;
                    piVar4 = (int *)0x0;
                    while ((bVar2 && (*(byte *)((int)pcVar7 + (int)piVar4) != 0))) {
                      bVar2 = (int *)((int)piVar4 + 1) < piVar17;
                      piVar4 = (int *)((int)piVar4 + 1);
                    }
                    pbVar15 = (byte *)((int)pcVar7 + (int)piVar4);
                    for (piVar6 = piVar4; piVar6 != (int *)0x0; piVar6 = (int *)((int)piVar6 + -1))
                    {
                      pbVar1 = pbVar15 + -1;
                      pbVar15 = pbVar15 + -1;
                      if (((int)(char)*pbVar1 & 0xc0U) != 0x80) {
                        if (((((int)(char)((byte *)((int)pcVar7 + (int)piVar6))[-1] & 0xc0U) != 0xc0
                             ) || (piVar6 = (int *)((int)piVar6 + -1),
[32m                                  6 < (uint)((int)piVar4 - (int)piVar6))) ||[0m
                           (((int)(char)*(byte *)((int)pcVar7 + (int)piVar6) >>
                             ((uint)((int)piVar6 + (7 - (int)piVar4)) & 0x1f) & 0xffU) != 0xfe))
                        break;
                        goto LAB_0041c7a8;
                      }
                    }
                    piVar4 = piVar6;
                  }
                }
                else {
                  piVar4 = (int *)0x0;
                }
                goto LAB_0041c7a8;
              }
              puVar14 = (undefined *)&local_164;
              if (*pcVar7 == 0) {
                puVar14 = (undefined *)((int)&local_164 + 1);
                local_164._0_1_ = 0x2e;
              }
              local_38[2] = (int **)auStack_66;
              local_38[0] = apiStack_264;
              goto LAB_0041c770;
            }
            if (iVar13 == 0x61) {
              local_270 = local_270 | iVar5 << 0x1b | iVar9 << 0x1a;
              piVar6 = *ppiVar20;
              param_4 = ppiVar20 + 1;
              if (piVar6 == (int *)0x0) {
                piVar4 = (int *)0x8;
                pppiVar12 = (int ***)0x46e0bc;
                goto LAB_0041c8b8;
              }
              if (local_270._1_1_ == '\0') {
LAB_0041c2d4:
                if (piVar17 == (int *)0x6) {
                  piVar4 = (int *)mDNS_snprintf(&local_164,300,"%02X:%02X:%02X:%02X:%02X:%02X",
                                                *(byte *)piVar6,*(byte *)((int)piVar6 + 1),
                                                *(byte *)((int)piVar6 + 2),
                                                *(byte *)((int)piVar6 + 3),*(byte *)(piVar6 + 1),
[32m                                                *(byte *)((int)piVar6 + 5));[0m
                }
                else if (piVar17 == (int *)0x10) {
                  piVar4 = (int *)mDNS_snprintf(&local_164,300,
                                                "%02X%02X:%02X%02X:%02X%02X:%02X%02X:%02X%02X:%02X%02X:%02X%02X:%02X%02X"
                                                ,*(byte *)piVar6,*(byte *)((int)piVar6 + 1),
                                                *(byte *)((int)piVar6 + 2),
                                                *(byte *)((int)piVar6 + 3),*(byte *)(piVar6 + 1),
                                                *(byte *)((int)piVar6 + 5),
                                                *(byte *)((int)piVar6 + 6),
                                                *(byte *)((int)piVar6 + 7),*(byte *)(piVar6 + 2),
                                                *(byte *)((int)piVar6 + 9),
                                                *(byte *)((int)piVar6 + 10),
                                                *(byte *)((int)piVar6 + 0xb),*(byte *)(piVar6 + 3),
                                                *(byte *)((int)piVar6 + 0xd),
                                                *(byte *)((int)piVar6 + 0xe),
[32m                                                *(byte *)((int)piVar6 + 0xf));[0m
                }
                else if (piVar17 == (int *)0x4) {
                  piVar4 = (int *)mDNS_snprintf(&local_164,300,"%d.%d.%d.%d",*(byte *)piVar6,
                                                *(byte *)((int)piVar6 + 1),
                                                *(byte *)((int)piVar6 + 2),
[32m                                                *(byte *)((int)piVar6 + 3));[0m
                }
                else {
                  piVar4 = (int *)mDNS_snprintf(&local_164,300,"%s",
                                                "<< ERROR: Must specify address size (i.e. %.4a=IPv4, %.6a=Ethernet, %.16a=IPv6) >>"
[32m                                               );[0m
                }
              }
              else {
                if (*piVar6 == 4) {
                  piVar17 = (int *)0x4;
LAB_0041c2d0:
                  piVar6 = piVar6 + 1;
                  goto LAB_0041c2d4;
                }
                if (*piVar6 == 6) {
                  piVar17 = (int *)0x10;
                  goto LAB_0041c2d0;
                }
[32m                piVar4 = (int *)mDNS_snprintf(&local_164,300,&DAT_00452658);[0m
              }
              pppiVar12 = (int ***)&local_164;
              bVar2 = piVar4 < piVar18;
              goto LAB_0041c8bc;
            }
            if (iVar13 < 0x62) {
              if (iVar13 != 0x4c) {
                if (iVar13 == 0x58) {
                  local_270 = local_270 | iVar5 << 0x1b | iVar9 << 0x1a;
                  goto LAB_0041c470;
                }
                if (iVar13 != 0x25) goto LAB_0041c84c;
                piVar4 = (int *)0x0;
                local_270 = local_270 | iVar5 << 0x1b | iVar9 << 0x1a;
                goto LAB_0041c898;
              }
LAB_0041bf94:
              bVar8 = *pbVar15;
              iVar9 = 1;
            }
            else {
              if (iVar13 == 100) break;
              if (iVar13 != 0x68) {
                if (iVar13 == 99) {
                  pppiVar12 = (int ***)&local_39;
                  piVar4 = (int *)0x1;
                  local_270 = local_270 | iVar5 << 0x1b | iVar9 << 0x1a;
                  local_270._2_1_ = (byte)*ppiVar20;
                  goto LAB_0041c574;
                }
LAB_0041c84c:
                pppiVar12 = (int ***)&local_164;
                local_270 = local_270 | iVar5 << 0x1b | iVar9 << 0x1a;
                piVar4 = (int *)mDNS_snprintf(pppiVar12,300,
[32m                                              "<<UNKNOWN FORMAT CONVERSION CODE %%%c>>",iVar13);[0m
LAB_0041c898:
                pbVar16 = pbVar16 + 1;
                *param_1 = (byte)iVar13;
                param_1 = param_1 + 1;
                param_4 = ppiVar20;
                if (pbVar19 <= pbVar16) {
                  *param_1 = 0;
                  return pbVar16;
                }
                goto LAB_0041c8b8;
              }
              bVar8 = *pbVar15;
              iVar5 = 1;
            }
            param_3 = pbVar15;
            iVar13 = (int)(char)bVar8;
          }
          piVar6 = *ppiVar20;
          if (iVar5 != 0) {
            piVar6 = (int *)(int)(short)*ppiVar20;
          }
          if ((int)piVar6 < 0) {
            piVar6 = (int *)-(int)piVar6;
            bVar8 = 0x2d;
LAB_0041c00c:
            local_270 = local_270 & 0xffff0000 | iVar5 << 0x1b | iVar9 << 0x1a | (uint)bVar8 << 8;
            uVar3 = local_270;
          }
          else {
            bVar8 = 0x2b;
            uVar3 = local_270 | iVar5 << 0x1b | iVar9 << 0x1a;
            if ((local_270 & 0x40000000) != 0) goto LAB_0041c00c;
          }
LAB_0041c060:
          local_270 = uVar3;
          if ((local_270 & 0x10000000) == 0) {
            if (((local_270 & 0x20000000) != 0) &&
               (piVar17 = (int *)((int)piVar18 + -1), local_270._2_1_ == 0)) {
              piVar17 = piVar18;
            }
            if (piVar17 != (int *)0x0) goto LAB_0041c0a4;
            piVar17 = (int *)0x1;
          }
          else {
LAB_0041c0a4:
            if ((int *)0x12b < piVar17) {
              piVar17 = (int *)0x12b;
            }
          }
          piVar4 = (int *)0x0;
          for (; piVar6 != (int *)0x0; piVar6 = (int *)((uint)piVar6 / 10)) {
            pppiVar12 = (int ***)((int)pppiVar12 + -1);
            piVar4 = (int *)((int)piVar4 + 1);
            *(byte *)pppiVar12 = (char)((uint)piVar6 % 10) + 0x30;
          }
          for (; piVar4 < piVar17; piVar4 = (int *)((int)piVar4 + 1)) {
            *(byte *)(int ***)((int)pppiVar12 + -1) = 0x30;
            pppiVar12 = (int ***)((int)pppiVar12 + -1);
          }
          param_4 = ppiVar20 + 1;
          if (local_270._2_1_ != 0) {
            pppiVar12 = (int ***)((int)pppiVar12 + -1);
            piVar4 = (int *)((int)piVar4 + 1);
LAB_0041c574:
            *(byte *)pppiVar12 = local_270._2_1_;
            param_4 = ppiVar20 + 1;
          }
          goto LAB_0041c8b8;
        }
        pbVar16 = pbVar16 + 1;
        *param_1 = bVar8;
        param_1 = param_1 + 1;
        if (pbVar19 <= pbVar16) {
          *param_1 = 0;
          return pbVar16;
        }
        goto LAB_0041c9a0;
      }
    }
LAB_0041c9b0:
    *param_1 = 0;
  }
  return pbVar16;
LAB_0041c770:
  uVar11 = (uint)(byte)*pcVar7;
  if (uVar11 == 0) goto LAB_0041c798;
  if (0x3f < uVar11) {
[32m    iVar5 = mDNS_snprintf(puVar14,(int)pppiVar12 - (int)puVar14,"<<INVALID LABEL LENGTH %u>>");[0m
LAB_0041c720:
    puVar14 = puVar14 + iVar5;
    goto LAB_0041c798;
  }
  if (local_38[2] <= puVar14 + uVar11) {
[32m    iVar5 = mDNS_snprintf(puVar14,(int)pppiVar12 - (int)puVar14,"<<NAME TOO LONG>>");[0m
    goto LAB_0041c720;
  }
  local_2c = (int)pppiVar12 - (int)puVar14;
  ConvertDomainLabelToCString_withescape(pcVar7,local_38[0],0x5c);
[32m  iVar5 = mDNS_snprintf(puVar14,local_2c,&DAT_00452764,local_38[0]);[0m
  puVar14 = puVar14 + iVar5;
  pcVar7 = (char *)((int)pcVar7 + (byte)*pcVar7 + 1);
  goto LAB_0041c770;
LAB_0041c798:
  pcVar7 = (char *)&local_164;
  piVar4 = (int *)(puVar14 + -(int)pcVar7);
LAB_0041c7a8:
  uVar11 = local_270 & 0x10000000;
  pppiVar12 = (int ***)pcVar7;
  param_4 = local_38[1];
  local_270 = uVar3;
  if ((uVar11 != 0) && (piVar17 < piVar4)) {
    pbVar15 = (byte *)((int)pcVar7 + (int)piVar17);
    while ((piVar4 = piVar17, piVar17 != (int *)0x0 &&
           (bVar8 = *pbVar15, pbVar15 = pbVar15 + -1, ((int)(char)bVar8 & 0xc0U) == 0x80))) {
      piVar17 = (int *)((int)piVar17 + -1);
    }
  }
LAB_0041c8b8:
  bVar2 = piVar4 < piVar18;
LAB_0041c8bc:
  piVar17 = (int *)(pbVar19 + -(int)pbVar16);
  if ((bVar2) && (piVar17 = (int *)(pbVar19 + -(int)pbVar16), -1 < (int)local_270)) {
    do {
      pbVar16 = pbVar16 + 1;
      piVar18 = (int *)((int)piVar18 + -1);
      *param_1 = 0x20;
      param_1 = param_1 + 1;
      if (pbVar19 <= pbVar16) goto LAB_0041c9b0;
    } while (piVar4 < piVar18);
    piVar17 = (int *)(pbVar19 + -(int)pbVar16);
  }
  if (piVar17 < piVar4) {
    pbVar15 = (byte *)((int)pppiVar12 + (int)piVar17);
    piVar4 = piVar17;
    while ((piVar4 != (int *)0x0 &&
           (bVar8 = *pbVar15, pbVar15 = pbVar15 + -1, ((int)(char)bVar8 & 0xc0U) == 0x80))) {
      piVar4 = (int *)((int)piVar4 + -1);
    }
  }
  piVar17 = (int *)0x0;
  pbVar15 = param_1;
  while (bVar2 = piVar17 < piVar4, piVar17 = (int *)((int)piVar17 + 1), bVar2) {
    bVar8 = *(byte *)pppiVar12;
    pppiVar12 = (int ***)((int)pppiVar12 + 1);
    *pbVar15 = bVar8;
    pbVar15 = pbVar15 + 1;
  }
  pbVar16 = pbVar16 + (int)piVar4;
  param_1 = param_1 + (int)piVar4;
  if (pbVar19 <= pbVar16) {
    *param_1 = 0;
    return pbVar16;
  }
  while (bVar2 = piVar4 < piVar18, piVar4 = (int *)((int)piVar4 + 1), bVar2) {
    pbVar16 = pbVar16 + 1;
    *param_1 = 0x20;
    param_1 = param_1 + 1;
    if (pbVar19 <= pbVar16) {
      *param_1 = 0;
      return pbVar16;
    }
  }
LAB_0041c9a0:
  param_3 = param_3 + 1;
  goto LAB_0041c9a4;
}

[ASK_GPT] 30181686080fcd04
