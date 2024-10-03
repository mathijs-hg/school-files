
/* WARNING: Type propagation algorithm not settling */

bool FUN_0041e5b0(int param_1,ushort *param_2,ushort *param_3,int param_4,ushort param_5)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  undefined *puVar4;
  byte *pbVar5;
  bool bVar6;
  uint uVar7;
  undefined *puVar8;
  char *pcVar9;
  ushort *puVar10;
  ushort *puVar11;
  int iVar12;
  byte *pbVar13;
  undefined *puVar14;
  byte *pbVar15;
  size_t __n;
  ushort local_134 [128];
  ushort auStack_34 [2];
  undefined *local_30;
  ushort *local_2c;
  
  uVar3 = (uint)*(ushort *)(param_4 + 6);
  pbVar13 = (byte *)(param_4 + 0x74);
  pbVar15 = (byte *)(uint)param_5;
  if (uVar3 == 0x15) goto LAB_0041eb70;
  if (0x15 < uVar3) {
    if (uVar3 == 0x29) {
      *(undefined2 *)(param_4 + 0x10) = 0;
      local_30 = (undefined *)(*(int *)(param_4 + 0x24) + 0x2004);
      puVar14 = (undefined *)(*(int *)(param_4 + 0x24) + 4);
      while (param_2 < param_3) {
        puVar8 = puVar14 + 0x18;
        puVar10 = param_2 + 2;
        if (local_30 <= puVar8) break;
        if (param_3 < puVar10) {
          if (mDNS_LoggingEnabled == 0) goto LAB_004200c8;
          pcVar9 = "SetRData: OPT RDATA ptr + 4 > end";
          goto LAB_0041f4f4;
        }
        uVar1 = *param_2;
        puVar14[1] = (char)uVar1;
        *puVar14 = (char)(uVar1 >> 8);
        uVar2 = param_2[1];
        uVar3 = (uint)uVar2;
        puVar14[2] = (char)(uVar2 >> 8);
        puVar14[3] = (char)uVar2;
        if (param_3 < (ushort *)((int)puVar10 + uVar3)) {
          if (mDNS_LoggingEnabled == 0) goto LAB_004200c8;
          pcVar9 = "SetRData: ptr + opt->optlen > end";
          goto LAB_0041f4f4;
        }
        puVar4 = puVar14;
        if (uVar1 == 2) {
          if (uVar3 == 4) {
            uVar3 = (uint)*(byte *)((int)param_2 + 7) | (uint)*(byte *)puVar10 << 0x18 |
                    (uint)*(byte *)((int)param_2 + 5) << 0x10 | (uint)*(byte *)(param_2 + 3) << 8;
            *(uint *)(puVar14 + 4) = uVar3;
            if (mDNSPlatformOneSecond == 0) {
              trap(0x1c00);
            }
            if (0x70000000 / mDNSPlatformOneSecond < uVar3) {
              *(uint *)(puVar14 + 4) = 0x70000000 / mDNSPlatformOneSecond;
            }
LAB_0041f778:
            puVar4 = puVar14 + 0x18;
          }
        }
        else if (uVar1 < 3) {
          if ((uVar1 == 1) && (uVar3 == 0x12)) {
            uVar1 = *puVar10;
            puVar14[5] = (char)uVar1;
            puVar14[4] = (char)(uVar1 >> 8);
            uVar1 = param_2[3];
            puVar14[7] = (char)uVar1;
            puVar14[6] = (char)(uVar1 >> 8);
            uVar1 = param_2[4];
            puVar14[9] = (char)uVar1;
            puVar14[8] = (char)(uVar1 >> 8);
            mDNSPlatformMemCopy(puVar14 + 0xc,param_2 + 5,8);
            uVar3 = (uint)*(byte *)(param_2 + 9) << 0x18 |
                    (uint)*(byte *)((int)param_2 + 0x13) << 0x10 |
                    (uint)*(byte *)((int)param_2 + 0x15) | (uint)*(byte *)(param_2 + 10) << 8;
            *(uint *)(puVar14 + 0x14) = uVar3;
            if (mDNSPlatformOneSecond == 0) {
              trap(0x1c00);
            }
            if (0x70000000 / mDNSPlatformOneSecond < uVar3) {
              *(uint *)(puVar14 + 0x14) = 0x70000000 / mDNSPlatformOneSecond;
            }
            goto LAB_0041f778;
          }
        }
        else if (uVar1 == 4) {
          if ((((uVar3 == 8) || (uVar3 == 0xe)) || (uVar3 == 0x12)) || (uVar3 == 0x14)) {
            local_2c = param_2 + 3;
            puVar14[4] = *(byte *)puVar10;
            puVar14[5] = *(byte *)((int)param_2 + 5);
            mDNSPlatformMemCopy(puVar14 + 6,local_2c,6);
            mDNSPlatformMemCopy(puVar14 + 0xc,local_2c,6);
            puVar14[0x12] = 0;
            puVar14[0x13] = 0;
            puVar14[0x14] = 0;
            puVar14[0x15] = 0;
            puVar14[0x16] = 0;
            puVar14[0x17] = 0;
            if (0xd < *(ushort *)(puVar14 + 2)) {
              mDNSPlatformMemCopy(puVar14 + 0xc,param_2 + 6,6);
              if (0xe < *(ushort *)(puVar14 + 2)) {
                mDNSPlatformMemCopy(puVar14 + 0x12,param_2 + 9,*(ushort *)(puVar14 + 2) - 0xe);
              }
            }
            goto LAB_0041f778;
          }
        }
        else if (uVar1 == 0xfde9) {
          puVar4 = puVar8;
          if (uVar3 == 5) {
            puVar14[4] = *(byte *)puVar10;
            *(uint *)(puVar14 + 8) =
                 (uint)*(byte *)((int)param_2 + 5) << 0x18 | (uint)*(byte *)(param_2 + 3) << 0x10 |
                 (uint)*(byte *)(param_2 + 4) | (uint)*(byte *)((int)param_2 + 7) << 8;
          }
          else {
            puVar14[4] = 0xff;
            *(undefined4 *)(puVar14 + 8) = 0xffffffff;
          }
        }
        param_2 = (ushort *)((int)puVar10 + (uint)*(ushort *)(puVar14 + 2));
        puVar14 = puVar4;
      }
      *(short *)(param_4 + 0x10) = (short)puVar14 - ((short)*(undefined4 *)(param_4 + 0x24) + 4);
      if (param_2 == param_3) {
        return true;
      }
      if (mDNS_LoggingEnabled != 0) {
        pcVar9 = "SetRData: Malformed OptRdata";
        goto LAB_0041f4f4;
      }
    }
    else {
      pbVar5 = pbVar15;
      if (uVar3 < 0x2a) {
        if (uVar3 == 0x1d) goto LAB_004200a4;
        if (uVar3 < 0x1e) {
          if (uVar3 != 0x1a) {
            uVar7 = 0x17;
            if (uVar3 == 0x1c) {
              if (pbVar15 != (byte *)0x10) {
                return false;
              }
              pbVar15 = (byte *)0x10;
              goto LAB_004200b8;
            }
LAB_0041e71c:
            if (uVar3 == uVar7) goto LAB_0041e7b8;
            goto LAB_004200a4;
          }
          if (pbVar15 < (byte *)0x4) {
            return false;
          }
          local_2c = param_2 + 1;
          *(ushort *)(param_4 + 0x74) = *param_2;
          if (param_1 == 0) {
            puVar10 = local_2c;
            do {
              if (param_2 + 0x81 <= puVar10) {
                *(undefined *)(param_4 + 0x76) = 0;
                goto LAB_0041eedc;
              }
              uVar3 = (uint)*(byte *)puVar10;
              if (0x3f < uVar3) {
                *(undefined *)(param_4 + 0x76) = 0;
                goto LAB_0041eedc;
              }
              puVar10 = (ushort *)((int)puVar10 + uVar3 + 1);
            } while (uVar3 != 0);
            uVar3 = (uint)((int)puVar10 + (-(int)local_2c - (uVar3 + 1)) + 1) & 0xffff;
            if (uVar3 < 0x101) {
              mDNSPlatformMemCopy((void *)(param_4 + 0x76),local_2c,uVar3);
            }
            else {
              *(undefined *)(param_4 + 0x76) = 0;
            }
LAB_0041eedc:
            pbVar15 = (byte *)(param_4 + 0x76);
            do {
              if ((byte *)(param_4 + 0x176) <= pbVar15) {
LAB_0041ef20:
                uVar3 = 0x101;
                goto LAB_0041ef24;
              }
              uVar3 = (uint)*pbVar15;
              if (0x3f < uVar3) goto LAB_0041ef20;
              pbVar15 = pbVar15 + uVar3 + 1;
            } while (uVar3 != 0);
            uVar3 = (uint)(pbVar15 + (-(int)(byte *)(param_4 + 0x76) - (uVar3 + 1)) + 1) & 0xffff;
LAB_0041ef24:
            local_2c = (ushort *)((int)local_2c + uVar3);
          }
          else {
            local_2c = (ushort *)FUN_0041b774(param_1,local_2c,param_3,param_4 + 0x76);
          }
          if (local_2c == (ushort *)0x0) {
            return false;
          }
          iVar12 = param_4 + 0x176;
          if (param_1 != 0) goto LAB_0041ef3c;
          pbVar15 = (byte *)local_2c;
          do {
            if ((byte *)((int)local_2c + 0x100) <= pbVar15) {
              *(undefined *)(param_4 + 0x176) = 0;
              goto LAB_0041efd0;
            }
            uVar3 = (uint)*pbVar15;
            if (0x3f < uVar3) {
              *(undefined *)(param_4 + 0x176) = 0;
              goto LAB_0041efd0;
            }
            pbVar15 = pbVar15 + uVar3 + 1;
          } while (uVar3 != 0);
          if (((uint)(pbVar15 + (-(int)local_2c - (uVar3 + 1)) + 1) & 0xffff) < 0x101) {
            mDNSPlatformMemCopy((void *)(param_4 + 0x176),local_2c,
                                (uint)(pbVar15 + (-(int)local_2c - (uVar3 + 1)) + 1) & 0xffff);
          }
          else {
            *(undefined *)(param_4 + 0x176) = 0;
          }
LAB_0041efd0:
          pbVar13 = (byte *)(param_4 + 0x176);
          pbVar15 = pbVar13;
          do {
            if ((byte *)(param_4 + 0x276) <= pbVar15) goto LAB_0041f014;
            uVar3 = (uint)*pbVar15;
            if (0x3f < uVar3) goto LAB_0041f014;
            pbVar15 = pbVar15 + uVar3 + 1;
          } while (uVar3 != 0);
          pbVar15 = pbVar15 + -(uVar3 + 1);
LAB_0041efe8:
          uVar3 = (uint)(pbVar15 + (1 - (int)pbVar13)) & 0xffff;
LAB_0041f018:
          local_2c = (ushort *)((int)local_2c + uVar3);
LAB_0041f020:
          return local_2c == param_3;
        }
        if (uVar3 != 0x23) {
          if (0x23 < uVar3) {
            uVar7 = 0x27;
            if (uVar3 == 0x24) goto LAB_0041eb70;
            goto LAB_0041e71c;
          }
          if (uVar3 != 0x21) goto LAB_004200a4;
          if (pbVar15 < (byte *)0x7) {
            return false;
          }
          puVar10 = param_2 + 3;
          *(ushort *)(param_4 + 0x74) = *param_2;
          *(ushort *)(param_4 + 0x76) = param_2[1];
          *(byte *)(param_4 + 0x78) = *(byte *)(param_2 + 2);
          *(byte *)(param_4 + 0x79) = *(byte *)((int)param_2 + 5);
          if (param_1 == 0) {
            puVar11 = puVar10;
            do {
              if (param_2 + 0x83 <= puVar11) {
                *(undefined *)(param_4 + 0x7a) = 0;
                goto LAB_0041f120;
              }
              uVar3 = (uint)*(byte *)puVar11;
              if (0x3f < uVar3) {
                *(undefined *)(param_4 + 0x7a) = 0;
                goto LAB_0041f120;
              }
              puVar11 = (ushort *)((int)puVar11 + uVar3 + 1);
            } while (uVar3 != 0);
            uVar3 = (uint)((int)puVar11 + (-(int)puVar10 - (uVar3 + 1)) + 1) & 0xffff;
            if (uVar3 < 0x101) {
              mDNSPlatformMemCopy((void *)(param_4 + 0x7a),puVar10,uVar3);
            }
            else {
              *(undefined *)(param_4 + 0x7a) = 0;
            }
LAB_0041f120:
            pbVar13 = (byte *)(param_4 + 0x7a);
            pbVar15 = pbVar13;
            do {
              if ((byte *)(param_4 + 0x17a) <= pbVar15) goto LAB_0041f164;
              uVar3 = (uint)*pbVar15;
              if (0x3f < uVar3) goto LAB_0041f164;
              pbVar15 = pbVar15 + uVar3 + 1;
            } while (uVar3 != 0);
            pbVar15 = pbVar15 + -(uVar3 + 1);
LAB_0041f138:
            uVar3 = (uint)(pbVar15 + (1 - (int)pbVar13)) & 0xffff;
            goto LAB_0041f168;
          }
          param_4 = param_4 + 0x7a;
          goto LAB_0041f090;
        }
        if ((byte *)0x7 < pbVar15) {
          puVar10 = (ushort *)((int)param_2 + *(byte *)(param_2 + 2) + 5);
          if (puVar10 < param_3) {
            puVar10 = (ushort *)((int)puVar10 + *(byte *)puVar10 + 1);
            if (puVar10 < param_3) {
              puVar10 = (ushort *)((int)puVar10 + *(byte *)puVar10 + 1);
              if (puVar10 < param_3) {
                if (param_1 == 0) {
                  puVar11 = puVar10;
                  do {
                    if (puVar10 + 0x80 <= puVar11) {
                      local_134[0]._0_1_ = 0;
                      goto LAB_0041f2ac;
                    }
                    uVar3 = (uint)*(byte *)puVar11;
                    if (0x3f < uVar3) {
                      local_134[0]._0_1_ = 0;
                      goto LAB_0041f2ac;
                    }
                    puVar11 = (ushort *)((int)puVar11 + uVar3 + 1);
                  } while (uVar3 != 0);
                  uVar3 = (uint)((int)puVar11 + (-(int)puVar10 - (uVar3 + 1)) + 1) & 0xffff;
                  if (uVar3 < 0x101) {
                    mDNSPlatformMemCopy(local_134,puVar10,uVar3);
                  }
                  else {
                    local_134[0]._0_1_ = 0;
                  }
LAB_0041f2ac:
                  puVar11 = local_134;
                  do {
                    if (auStack_34 <= puVar11) {
LAB_0041f2fc:
                      uVar3 = 0x101;
                      goto LAB_0041f300;
                    }
                    uVar3 = (uint)*(byte *)puVar11;
                    if (0x3f < uVar3) goto LAB_0041f2fc;
                    puVar11 = (ushort *)((int)puVar11 + uVar3 + 1);
                  } while (uVar3 != 0);
                  uVar3 = (uint)((int)puVar11 + (-(int)local_134 - (uVar3 + 1)) + 1) & 0xffff;
LAB_0041f300:
                  puVar11 = (ushort *)((int)puVar10 + uVar3);
                }
                else {
                  puVar11 = (ushort *)FUN_0041b774(param_1,puVar10,param_3,local_134);
                }
                if (puVar11 == param_3) {
                  puVar11 = local_134;
                  do {
                    if (auStack_34 <= puVar11) {
LAB_0041f36c:
                      uVar3 = 0x101;
                      goto LAB_0041f370;
                    }
                    uVar3 = (uint)*(byte *)puVar11;
                    if (0x3f < uVar3) goto LAB_0041f36c;
                    puVar11 = (ushort *)((int)puVar11 + uVar3 + 1);
                  } while (uVar3 != 0);
                  uVar3 = (uint)((int)puVar11 + (-(int)local_134 - (uVar3 + 1)) + 1) & 0xffff;
LAB_0041f370:
[32m                  __n = (int)puVar10 - (int)param_2;[0m
                  puVar10 = (ushort *)(uVar3 + __n & 0xffff);
                  *(short *)(param_4 + 0x10) = (short)puVar10;
                  if (puVar10 < (ushort *)0x2001) {
                    mDNSPlatformMemCopy(pbVar13,param_2,__n);
                    puVar10 = local_134;
                    do {
                      if (auStack_34 <= puVar10) goto LAB_0041f43c;
                      uVar3 = (uint)*(byte *)puVar10;
                      if (0x3f < uVar3) goto LAB_0041f43c;
                      puVar10 = (ushort *)((int)puVar10 + uVar3 + 1);
                    } while (uVar3 != 0);
                    pbVar15 = (byte *)((uint)((int)puVar10 + (-(int)local_134 - (uVar3 + 1)) + 1) &
                                      0xffff);
                    if ((byte *)0x100 < pbVar15) {
LAB_0041f43c:
                      pbVar13[__n] = 0;
                      return true;
                    }
                    pbVar13 = pbVar13 + __n;
                    param_2 = local_134;
                    goto LAB_004200b8;
                  }
                  param_3 = local_134;
                  if (mDNS_LoggingEnabled != 0) {
                    pcVar9 = 
                    "SetRData: Malformed NAPTR rdlength %d, rr->resrec.rdlength %d, bmaplen %d, name %##s"
                    ;
                    goto LAB_0041fbd8;
                  }
                }
                else if (mDNS_LoggingEnabled != 0) {
                  pcVar9 = "SetRData: Malformed NAPTR RDATA name";
                  goto LAB_0041f4f4;
                }
              }
              else if (mDNS_LoggingEnabled != 0) {
                pcVar9 = "SetRData: Malformed NAPTR regexp";
                goto LAB_0041f4f4;
              }
            }
            else if (mDNS_LoggingEnabled != 0) {
              pcVar9 = "SetRData: Malformed NAPTR service";
              goto LAB_0041f4f4;
            }
          }
          else if (mDNS_LoggingEnabled != 0) {
            pcVar9 = "SetRData: Malformed NAPTR flags";
            goto LAB_0041f4f4;
          }
        }
      }
      else if (uVar3 == 0x30) {
        if ((byte *)0x4 < pbVar15) {
          *(ushort *)(param_4 + 0x10) = param_5;
          goto LAB_004200b8;
        }
        if (mDNS_LoggingEnabled != 0) {
          pcVar9 = "SetRData: DNSKEY too small length %d";
          goto LAB_00420060;
        }
      }
      else if (uVar3 < 0x31) {
        if (uVar3 == 0x2e) {
          if (pbVar15 < (byte *)0x13) {
            if (mDNS_LoggingEnabled != 0) {
              pcVar9 = "SetRData: RRSIG too small length %d";
              goto LAB_00420060;
            }
          }
          else {
            puVar10 = param_2 + 9;
            if (param_1 == 0) {
              puVar11 = puVar10;
              do {
                if (param_2 + 0x89 <= puVar11) {
                  local_134[0]._0_1_ = 0;
                  goto LAB_0041ff1c;
                }
                uVar3 = (uint)*(byte *)puVar11;
                if (0x3f < uVar3) {
                  local_134[0]._0_1_ = 0;
                  goto LAB_0041ff1c;
                }
                puVar11 = (ushort *)((int)puVar11 + uVar3 + 1);
              } while (uVar3 != 0);
              uVar3 = (uint)((int)puVar11 + (-(int)puVar10 - (uVar3 + 1)) + 1) & 0xffff;
              if (uVar3 < 0x101) {
                mDNSPlatformMemCopy(local_134,puVar10,uVar3);
              }
              else {
                local_134[0]._0_1_ = 0;
              }
LAB_0041ff1c:
              puVar11 = local_134;
              do {
                if (auStack_34 <= puVar11) {
LAB_0041ff6c:
                  uVar3 = 0x101;
                  goto LAB_0041ff70;
                }
                uVar3 = (uint)*(byte *)puVar11;
                if (0x3f < uVar3) goto LAB_0041ff6c;
                puVar11 = (ushort *)((int)puVar11 + uVar3 + 1);
              } while (uVar3 != 0);
              uVar3 = (uint)((int)puVar11 + (-(int)local_134 - (uVar3 + 1)) + 1) & 0xffff;
LAB_0041ff70:
              pbVar5 = (byte *)((int)puVar10 + uVar3);
            }
            else {
              pbVar5 = (byte *)FUN_0041b774(param_1,puVar10,param_3,local_134);
            }
            if (pbVar5 == (byte *)0x0) {
              if (mDNS_LoggingEnabled != 0) {
                pcVar9 = "SetRData: Malformed RRSIG record";
LAB_0041f4f4:
                LogMsgWithLevel(3,pcVar9);
                return false;
              }
            }
            else {
              puVar11 = local_134;
              do {
                if (auStack_34 <= puVar11) {
LAB_0041ffdc:
                  uVar3 = 0x101;
                  goto LAB_0041ffe0;
                }
                uVar3 = (uint)*(byte *)puVar11;
                if (0x3f < uVar3) goto LAB_0041ffdc;
                puVar11 = (ushort *)((int)puVar11 + uVar3 + 1);
              } while (uVar3 != 0);
              uVar3 = (uint)((int)puVar11 + (-(int)local_134 - (uVar3 + 1)) + 1) & 0xffff;
LAB_0041ffe0:
              if ((int)pbVar5 - (int)puVar10 == uVar3) {
                if (pbVar5 + 1 < param_3) goto LAB_004200a4;
                if (mDNS_LoggingEnabled != 0) {
                  pcVar9 = "SetRData: Not enough bytes for signature type %d";
                  pbVar15 = (byte *)(uint)*(ushort *)(param_4 + 6);
                  goto LAB_00420060;
                }
              }
              else if (mDNS_LoggingEnabled != 0) {
                pcVar9 = "SetRData: Malformed RRSIG record, signer name compression";
                goto LAB_0041f4f4;
              }
            }
          }
        }
        else if (uVar3 < 0x2f) {
          if ((uVar3 != 0x2b) || ((byte *)0x4 < pbVar15)) goto LAB_004200a4;
          if (mDNS_LoggingEnabled != 0) {
            pcVar9 = "SetRData: DS too small length %d";
            goto LAB_00420060;
          }
        }
        else {
          if (param_1 == 0) {
            puVar10 = param_2;
            do {
              if (param_2 + 0x80 <= puVar10) {
                local_134[0]._0_1_ = 0;
                goto LAB_0041f8d8;
              }
              uVar3 = (uint)*(byte *)puVar10;
              if (0x3f < uVar3) {
                local_134[0]._0_1_ = 0;
                goto LAB_0041f8d8;
              }
              puVar10 = (ushort *)((int)puVar10 + uVar3 + 1);
            } while (uVar3 != 0);
            uVar3 = (uint)((int)puVar10 + (-(int)param_2 - (uVar3 + 1)) + 1) & 0xffff;
            if (uVar3 < 0x101) {
              mDNSPlatformMemCopy(local_134,param_2,uVar3);
            }
            else {
              local_134[0]._0_1_ = 0;
            }
LAB_0041f8d8:
            puVar10 = local_134;
            do {
              if (auStack_34 <= puVar10) {
LAB_0041f928:
                uVar3 = 0x101;
                goto LAB_0041f92c;
              }
              uVar3 = (uint)*(byte *)puVar10;
              if (0x3f < uVar3) goto LAB_0041f928;
              puVar10 = (ushort *)((int)puVar10 + uVar3 + 1);
            } while (uVar3 != 0);
            uVar3 = (uint)((int)puVar10 + (-(int)local_134 - (uVar3 + 1)) + 1) & 0xffff;
LAB_0041f92c:
            puVar11 = (ushort *)((int)param_2 + uVar3);
          }
          else {
            puVar11 = (ushort *)FUN_0041b774();
          }
          if (puVar11 == (ushort *)0x0) {
            if (mDNS_LoggingEnabled != 0) {
              pcVar9 = "SetRData: Malformed NSEC nextname";
              goto LAB_0041f4f4;
            }
          }
          else {
            puVar10 = local_134;
            do {
              if (auStack_34 <= puVar10) {
LAB_0041f998:
                uVar3 = 0x101;
                goto LAB_0041f99c;
              }
              uVar3 = (uint)*(byte *)puVar10;
              if (0x3f < uVar3) goto LAB_0041f998;
              puVar10 = (ushort *)((int)puVar10 + uVar3 + 1);
            } while (uVar3 != 0);
            uVar3 = (uint)((int)puVar10 + (-(int)local_134 - (uVar3 + 1)) + 1) & 0xffff;
LAB_0041f99c:
            pbVar15 = (byte *)((int)param_2 + ((int)pbVar15 - (int)puVar11));
            puVar10 = (ushort *)FUN_0041ccd4(puVar11,param_3,pbVar15);
            if (puVar10 != (ushort *)0x0) {
              if (puVar10 == param_3) {
                puVar10 = local_134;
                do {
                  if (auStack_34 <= puVar10) {
LAB_0041fa28:
                    uVar7 = 0x101;
                    goto LAB_0041fa2c;
                  }
                  uVar7 = (uint)*(byte *)puVar10;
                  if (0x3f < uVar7) goto LAB_0041fa28;
                  puVar10 = (ushort *)((int)puVar10 + uVar7 + 1);
                } while (uVar7 != 0);
                uVar7 = (uint)((int)puVar10 + (-(int)local_134 - (uVar7 + 1)) + 1) & 0xffff;
LAB_0041fa2c:
                puVar10 = (ushort *)((uint)(pbVar15 + uVar7) & 0xffff);
                *(short *)(param_4 + 0x10) = (short)puVar10;
                if (puVar10 < (ushort *)0x2001) {
                  puVar10 = local_134;
                  do {
                    if (auStack_34 <= puVar10) {
                      *(undefined *)(param_4 + 0x74) = 0;
                      goto LAB_0041fae8;
                    }
                    uVar7 = (uint)*(byte *)puVar10;
                    if (0x3f < uVar7) {
                      *(undefined *)(param_4 + 0x74) = 0;
                      goto LAB_0041fae8;
                    }
                    puVar10 = (ushort *)((int)puVar10 + uVar7 + 1);
                  } while (uVar7 != 0);
                  uVar7 = (uint)((int)puVar10 + (-(int)local_134 - (uVar7 + 1)) + 1) & 0xffff;
                  if (uVar7 < 0x101) {
                    mDNSPlatformMemCopy(pbVar13,local_134,uVar7);
                  }
                  else {
                    *(undefined *)(param_4 + 0x74) = 0;
                  }
LAB_0041fae8:
                  pbVar13 = pbVar13 + uVar3;
                  param_2 = puVar11;
                  goto LAB_004200b8;
                }
                param_3 = local_134;
                if (mDNS_LoggingEnabled != 0) {
                  pcVar9 = 
                  "SetRData: Malformed NSEC rdlength %d, rr->resrec.rdlength %d, bmaplen %d, name %##s"
                  ;
                  goto LAB_0041fbd8;
                }
              }
              else if (mDNS_LoggingEnabled != 0) {
                pcVar9 = "SetRData: Malformed NSEC length not right";
                goto LAB_0041f4f4;
              }
            }
          }
        }
      }
      else if (uVar3 == 0x32) {
        if (pbVar15 < (byte *)0x6) {
          if (mDNS_LoggingEnabled != 0) {
            pcVar9 = "SetRData: NSEC3 too small length %d";
LAB_00420060:
            LogMsgWithLevel(3,pcVar9,pbVar15);
            return false;
          }
        }
        else if ((byte *)(uint)*(byte *)param_2 == (byte *)0x1) {
          if (param_2[1] < 0x9c5) {
            pbVar5 = (byte *)(uint)*(byte *)(param_2 + 2);
            puVar10 = (ushort *)((int)param_2 + (int)(pbVar5 + 5));
            if (puVar10 < param_3) {
              pbVar5 = (byte *)(uint)*(byte *)puVar10;
              if (pbVar5 == (byte *)0x0) {
                if (mDNS_LoggingEnabled != 0) {
                  pcVar9 = "SetRData: hashLength zero";
                  goto LAB_0041f4f4;
                }
              }
              else {
                puVar10 = (ushort *)((int)puVar10 + (int)(pbVar5 + 1));
                if (puVar10 <= param_3) {
                  iVar12 = FUN_0041ccd4(puVar10,param_3,
                                        (byte *)((int)param_2 + ((int)pbVar15 - (int)puVar10)));
                  if (iVar12 == 0) {
                    return false;
                  }
                  goto LAB_004200a4;
                }
                if (mDNS_LoggingEnabled != 0) {
                  pcVar9 = "SetRData: nsec3 too small, at hashLength %d, p %p, end %p";
                  goto LAB_0041fbd8;
                }
              }
            }
            else if (mDNS_LoggingEnabled != 0) {
              pcVar9 = "SetRData: nsec3 too small, at saltlength %d, p %p, end %p";
LAB_0041fbd8:
              LogMsgWithLevel(3,pcVar9,pbVar5,puVar10,param_3);
              return false;
            }
          }
          else if (mDNS_LoggingEnabled != 0) {
            pcVar9 = "SetRData: nsec3 iteration count %d too big";
            pbVar15 = (byte *)(uint)param_2[1];
            goto LAB_00420060;
          }
        }
        else if (mDNS_LoggingEnabled != 0) {
          pcVar9 = "SetRData: nsec3 alg %d not supported";
          pbVar15 = (byte *)(uint)*(byte *)param_2;
          goto LAB_00420060;
        }
      }
      else {
        if ((uVar3 < 0x32) || (1 < uVar3 - 0xf9)) goto LAB_004200a4;
        if (param_1 == 0) {
          puVar10 = param_2;
          do {
            if (param_2 + 0x80 <= puVar10) {
              local_134[0]._0_1_ = 0;
              goto LAB_0041fcf4;
            }
            uVar3 = (uint)*(byte *)puVar10;
            if (0x3f < uVar3) {
              local_134[0]._0_1_ = 0;
              goto LAB_0041fcf4;
            }
            puVar10 = (ushort *)((int)puVar10 + uVar3 + 1);
          } while (uVar3 != 0);
          uVar3 = (uint)((int)puVar10 + (-(int)param_2 - (uVar3 + 1)) + 1) & 0xffff;
          if (uVar3 < 0x101) {
            mDNSPlatformMemCopy(local_134,param_2,uVar3);
          }
          else {
            local_134[0]._0_1_ = 0;
          }
LAB_0041fcf4:
          puVar10 = local_134;
          do {
            if (auStack_34 <= puVar10) {
LAB_0041fd44:
              uVar3 = 0x101;
              goto LAB_0041fd48;
            }
            uVar3 = (uint)*(byte *)puVar10;
            if (0x3f < uVar3) goto LAB_0041fd44;
            puVar10 = (ushort *)((int)puVar10 + uVar3 + 1);
          } while (uVar3 != 0);
          uVar3 = (uint)((int)puVar10 + (-(int)local_134 - (uVar3 + 1)) + 1) & 0xffff;
LAB_0041fd48:
          param_2 = (ushort *)((int)param_2 + uVar3);
        }
        else {
          param_2 = (ushort *)FUN_0041b774();
        }
        if (param_2 != (ushort *)0x0) {
          puVar10 = local_134;
          do {
            if (auStack_34 <= puVar10) {
LAB_0041fdb8:
              uVar3 = 0x101;
              goto LAB_0041fdbc;
            }
            uVar3 = (uint)*(byte *)puVar10;
            if (0x3f < uVar3) goto LAB_0041fdb8;
            puVar10 = (ushort *)((int)puVar10 + uVar3 + 1);
          } while (uVar3 != 0);
          uVar3 = (uint)((int)puVar10 + (-(int)local_134 - (uVar3 + 1)) + 1) & 0xffff;
LAB_0041fdbc:
          pbVar15 = (byte *)((int)param_3 - (int)param_2);
          *(short *)(param_4 + 0x10) = (short)uVar3 + (short)pbVar15;
          puVar10 = local_134;
          do {
            if (auStack_34 <= puVar10) {
              *(undefined *)(param_4 + 0x74) = 0;
              goto LAB_0041fe4c;
            }
            uVar7 = (uint)*(byte *)puVar10;
            if (0x3f < uVar7) {
              *(undefined *)(param_4 + 0x74) = 0;
              goto LAB_0041fe4c;
            }
            puVar10 = (ushort *)((int)puVar10 + uVar7 + 1);
          } while (uVar7 != 0);
          uVar7 = (uint)((int)puVar10 + (-(int)local_134 - (uVar7 + 1)) + 1) & 0xffff;
          if (uVar7 < 0x101) {
            local_2c = param_2;
            mDNSPlatformMemCopy(pbVar13,local_134,uVar7);
            param_2 = local_2c;
          }
          else {
            *(undefined *)(param_4 + 0x74) = 0;
          }
LAB_0041fe4c:
          pbVar13 = pbVar13 + uVar3;
          goto LAB_004200b8;
        }
        if (mDNS_LoggingEnabled != 0) {
          pcVar9 = "SetRData: Malformed name for TSIG/TKEY type %d";
          pbVar15 = (byte *)(uint)*(ushort *)(param_4 + 6);
          goto LAB_00420060;
        }
      }
    }
    goto LAB_004200c8;
  }
  if (uVar3 == 0xc) goto LAB_0041e7b8;
  if (0xc < uVar3) {
    if (uVar3 != 0x10) {
      if (uVar3 < 0x11) {
        if (uVar3 == 0xe) {
LAB_0041ec5c:
          if (param_1 == 0) {
            puVar10 = param_2;
            do {
              if (param_2 + 0x80 <= puVar10) {
                *(undefined *)(param_4 + 0x74) = 0;
                goto LAB_0041ed00;
              }
              uVar3 = (uint)*(byte *)puVar10;
              if (0x3f < uVar3) {
                *(undefined *)(param_4 + 0x74) = 0;
                goto LAB_0041ed00;
              }
              puVar10 = (ushort *)((int)puVar10 + uVar3 + 1);
            } while (uVar3 != 0);
            uVar3 = (uint)((int)puVar10 + (-(int)param_2 - (uVar3 + 1)) + 1) & 0xffff;
            if (uVar3 < 0x101) {
              mDNSPlatformMemCopy(pbVar13,param_2,uVar3);
            }
            else {
              *(undefined *)(param_4 + 0x74) = 0;
            }
LAB_0041ed00:
            pbVar15 = pbVar13;
            do {
              if ((byte *)(param_4 + 0x174) <= pbVar15) {
LAB_0041ed40:
                uVar3 = 0x101;
                goto LAB_0041ed44;
              }
              uVar3 = (uint)*pbVar15;
              if (0x3f < uVar3) goto LAB_0041ed40;
              pbVar15 = pbVar15 + uVar3 + 1;
            } while (uVar3 != 0);
            uVar3 = (uint)(pbVar15 + (-(int)pbVar13 - (uVar3 + 1)) + 1) & 0xffff;
LAB_0041ed44:
            local_2c = (ushort *)((int)param_2 + uVar3);
          }
          else {
            local_2c = (ushort *)FUN_0041b774(param_1,param_2,param_3,pbVar13);
          }
          if (local_2c == (ushort *)0x0) {
            return false;
          }
          iVar12 = param_4 + 0x174;
          if (param_1 != 0) {
LAB_0041ef3c:
            local_2c = (ushort *)FUN_0041b774(param_1,local_2c,param_3,iVar12);
            goto LAB_0041f020;
          }
          pbVar15 = (byte *)local_2c;
          do {
            if ((byte *)((int)local_2c + 0x100) <= pbVar15) {
              *(undefined *)(param_4 + 0x174) = 0;
              goto LAB_0041ede0;
            }
            uVar3 = (uint)*pbVar15;
            if (0x3f < uVar3) {
              *(undefined *)(param_4 + 0x174) = 0;
              goto LAB_0041ede0;
            }
            pbVar15 = pbVar15 + uVar3 + 1;
          } while (uVar3 != 0);
          if (((uint)(pbVar15 + (-(int)local_2c - (uVar3 + 1)) + 1) & 0xffff) < 0x101) {
            mDNSPlatformMemCopy((void *)(param_4 + 0x174),local_2c,
                                (uint)(pbVar15 + (-(int)local_2c - (uVar3 + 1)) + 1) & 0xffff);
          }
          else {
            *(undefined *)(param_4 + 0x174) = 0;
          }
LAB_0041ede0:
          pbVar13 = (byte *)(param_4 + 0x174);
          for (pbVar15 = pbVar13; pbVar15 < (byte *)(param_4 + 0x274); pbVar15 = pbVar15 + uVar3 + 1
              ) {
            uVar3 = (uint)*pbVar15;
            if (0x3f < uVar3) {
              uVar3 = 0x101;
              goto LAB_0041f018;
            }
            if (uVar3 == 0) goto LAB_0041efe8;
          }
LAB_0041f014:
          uVar3 = 0x101;
          goto LAB_0041f018;
        }
        if (0xe < uVar3) goto LAB_0041eb70;
      }
      else {
        if (uVar3 == 0x12) {
LAB_0041eb70:
          if (pbVar15 < (byte *)0x3) {
            return false;
          }
          puVar10 = param_2 + 1;
          *(ushort *)(param_4 + 0x74) = *param_2;
          if (param_1 == 0) {
            puVar11 = puVar10;
            do {
              if (param_2 + 0x81 <= puVar11) {
                *(undefined *)(param_4 + 0x76) = 0;
                goto LAB_0041ec20;
              }
              uVar3 = (uint)*(byte *)puVar11;
              if (0x3f < uVar3) {
                *(undefined *)(param_4 + 0x76) = 0;
                goto LAB_0041ec20;
              }
              puVar11 = (ushort *)((int)puVar11 + uVar3 + 1);
            } while (uVar3 != 0);
            uVar3 = (uint)((int)puVar11 + (-(int)puVar10 - (uVar3 + 1)) + 1) & 0xffff;
            if (uVar3 < 0x101) {
              mDNSPlatformMemCopy((void *)(param_4 + 0x76),puVar10,uVar3);
            }
            else {
              *(undefined *)(param_4 + 0x76) = 0;
            }
LAB_0041ec20:
            pbVar13 = (byte *)(param_4 + 0x76);
            for (pbVar15 = pbVar13; pbVar15 < (byte *)(param_4 + 0x176);
                pbVar15 = pbVar15 + uVar3 + 1) {
              uVar3 = (uint)*pbVar15;
              if (0x3f < uVar3) {
                uVar3 = 0x101;
                goto LAB_0041f168;
              }
              if (uVar3 == 0) goto LAB_0041f138;
            }
LAB_0041f164:
            uVar3 = 0x101;
LAB_0041f168:
            puVar10 = (ushort *)((int)puVar10 + uVar3);
            goto LAB_0041f170;
          }
          param_4 = param_4 + 0x76;
LAB_0041f090:
          puVar10 = (ushort *)FUN_0041b774(param_1,puVar10,param_3,param_4);
LAB_0041f170:
          return puVar10 == param_3;
        }
        if (uVar3 < 0x13) goto LAB_0041ec5c;
      }
    }
LAB_004200a4:
    *(ushort *)(param_4 + 0x10) = param_5;
LAB_004200b8:
    mDNSPlatformMemCopy(pbVar13,param_2,(size_t)pbVar15);
    return true;
  }
  if (uVar3 == 6) {
    if (param_1 == 0) {
      puVar10 = param_2;
      do {
        if (param_2 + 0x80 <= puVar10) {
          *(undefined *)(param_4 + 0x74) = 0;
          goto LAB_0041e944;
        }
        uVar3 = (uint)*(byte *)puVar10;
        if (0x3f < uVar3) {
          *(undefined *)(param_4 + 0x74) = 0;
          goto LAB_0041e944;
        }
        puVar10 = (ushort *)((int)puVar10 + uVar3 + 1);
      } while (uVar3 != 0);
      uVar3 = (uint)((int)puVar10 + (-(int)param_2 - (uVar3 + 1)) + 1) & 0xffff;
      if (uVar3 < 0x101) {
        mDNSPlatformMemCopy(pbVar13,param_2,uVar3);
      }
      else {
        *(undefined *)(param_4 + 0x74) = 0;
      }
LAB_0041e944:
      pbVar15 = pbVar13;
      do {
        if ((byte *)(param_4 + 0x174) <= pbVar15) {
LAB_0041e984:
          uVar3 = 0x101;
          goto LAB_0041e988;
        }
        uVar3 = (uint)*pbVar15;
        if (0x3f < uVar3) goto LAB_0041e984;
        pbVar15 = pbVar15 + uVar3 + 1;
      } while (uVar3 != 0);
      uVar3 = (uint)(pbVar15 + (-(int)pbVar13 - (uVar3 + 1)) + 1) & 0xffff;
LAB_0041e988:
      local_2c = (ushort *)((int)param_2 + uVar3);
    }
    else {
      local_2c = (ushort *)FUN_0041b774();
    }
    if (local_2c == (ushort *)0x0) {
      return false;
    }
    if (param_1 == 0) {
      pbVar15 = (byte *)local_2c;
      do {
        if ((byte *)((int)local_2c + 0x100) <= pbVar15) {
          *(undefined *)(param_4 + 0x174) = 0;
          goto LAB_0041ea34;
        }
        uVar3 = (uint)*pbVar15;
        if (0x3f < uVar3) {
          *(undefined *)(param_4 + 0x174) = 0;
          goto LAB_0041ea34;
        }
        pbVar15 = pbVar15 + uVar3 + 1;
      } while (uVar3 != 0);
      if (((uint)(pbVar15 + (-(int)local_2c - (uVar3 + 1)) + 1) & 0xffff) < 0x101) {
        mDNSPlatformMemCopy((void *)(param_4 + 0x174),local_2c,
                            (uint)(pbVar15 + (-(int)local_2c - (uVar3 + 1)) + 1) & 0xffff);
      }
      else {
        *(undefined *)(param_4 + 0x174) = 0;
      }
LAB_0041ea34:
      pbVar15 = (byte *)(param_4 + 0x174);
      do {
        if ((byte *)(param_4 + 0x274) <= pbVar15) {
LAB_0041ea78:
          uVar3 = 0x101;
          goto LAB_0041ea7c;
        }
        uVar3 = (uint)*pbVar15;
        if (0x3f < uVar3) goto LAB_0041ea78;
        pbVar15 = pbVar15 + uVar3 + 1;
      } while (uVar3 != 0);
      uVar3 = (uint)(pbVar15 + (-(int)(byte *)(param_4 + 0x174) - (uVar3 + 1)) + 1) & 0xffff;
LAB_0041ea7c:
      pbVar15 = (byte *)((int)local_2c + uVar3);
    }
    else {
      pbVar15 = (byte *)FUN_0041b774(param_1,local_2c,param_3,param_4 + 0x174);
    }
    if ((pbVar15 != (byte *)0x0) && (param_3 == (ushort *)(pbVar15 + 0x14))) {
      *(uint *)(param_4 + 0x274) =
           (uint)pbVar15[3] | (uint)*pbVar15 << 0x18 | (uint)pbVar15[1] << 0x10 |
           (uint)pbVar15[2] << 8;
      *(uint *)(param_4 + 0x278) =
           (uint)pbVar15[4] << 0x18 | (uint)pbVar15[5] << 0x10 | (uint)pbVar15[7] |
           (uint)pbVar15[6] << 8;
      *(uint *)(param_4 + 0x27c) =
           (uint)pbVar15[8] << 0x18 | (uint)pbVar15[9] << 0x10 | (uint)pbVar15[0xb] |
           (uint)pbVar15[10] << 8;
      *(uint *)(param_4 + 0x280) =
           (uint)pbVar15[0xc] << 0x18 | (uint)pbVar15[0xd] << 0x10 | (uint)pbVar15[0xf] |
           (uint)pbVar15[0xe] << 8;
      *(uint *)(param_4 + 0x284) =
           (uint)pbVar15[0x10] << 0x18 | (uint)pbVar15[0x11] << 0x10 | (uint)pbVar15[0x13] |
           (uint)pbVar15[0x12] << 8;
      return true;
    }
LAB_004200c8:
    bVar6 = false;
  }
  else {
    if (uVar3 < 7) {
      if (uVar3 == 1) {
        if (pbVar15 == (byte *)0x4) {
          *(byte *)(param_4 + 0x74) = *(byte *)param_2;
          *(byte *)(param_4 + 0x75) = *(byte *)((int)param_2 + 1);
          *(byte *)(param_4 + 0x76) = *(byte *)(param_2 + 1);
          *(byte *)(param_4 + 0x77) = *(byte *)((int)param_2 + 3);
          return true;
        }
        goto LAB_004200c8;
      }
      if (uVar3 == 0) goto LAB_004200a4;
    }
    else if (9 < uVar3) goto LAB_004200a4;
LAB_0041e7b8:
    if (param_1 == 0) {
      puVar10 = param_2;
      do {
        if (param_2 + 0x80 <= puVar10) {
          *(undefined *)(param_4 + 0x74) = 0;
          goto LAB_0041e854;
        }
        uVar3 = (uint)*(byte *)puVar10;
        if (0x3f < uVar3) {
          *(undefined *)(param_4 + 0x74) = 0;
          goto LAB_0041e854;
        }
        puVar10 = (ushort *)((int)puVar10 + uVar3 + 1);
      } while (uVar3 != 0);
      uVar3 = (uint)((int)puVar10 + (-(int)param_2 - (uVar3 + 1)) + 1) & 0xffff;
      if (uVar3 < 0x101) {
        mDNSPlatformMemCopy(pbVar13,param_2,uVar3);
      }
      else {
        *(undefined *)(param_4 + 0x74) = 0;
      }
LAB_0041e854:
      pbVar15 = pbVar13;
      do {
        if ((byte *)(param_4 + 0x174) <= pbVar15) {
LAB_0041e894:
          uVar3 = 0x101;
          goto LAB_0041e898;
        }
        uVar3 = (uint)*pbVar15;
        if (0x3f < uVar3) goto LAB_0041e894;
        pbVar15 = pbVar15 + uVar3 + 1;
      } while (uVar3 != 0);
      uVar3 = (uint)(pbVar15 + (-(int)pbVar13 - (uVar3 + 1)) + 1) & 0xffff;
LAB_0041e898:
      param_2 = (ushort *)((int)param_2 + uVar3);
    }
    else {
      param_2 = (ushort *)FUN_0041b774(param_1,param_2,param_3,pbVar13);
    }
    bVar6 = param_2 == param_3;
  }
  return bVar6;
}

[ASK_GPT] fc95ae571d254e74
