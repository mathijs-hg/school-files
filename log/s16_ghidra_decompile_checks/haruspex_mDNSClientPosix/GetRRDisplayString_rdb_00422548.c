
char * GetRRDisplayString_rdb(char *param_1,ushort *param_2,char *param_3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  char *pcVar9;
  int iVar10;
  byte *pbVar11;
  char *pcVar12;
  uint uVar13;
  uint uVar14;
  undefined4 uVar15;
  uint uVar16;
  ushort *puVar17;
  int iVar18;
  ushort *puVar19;
  byte *pbVar20;
  undefined auStack_b4 [64];
  undefined auStack_74 [68];
  ushort *local_30;
  uint local_2c;
  
  local_2c = (uint)*(ushort *)(param_1 + 0xc);
  uVar15 = *(undefined4 *)(param_1 + 0x1c);
  uVar5 = DNSTypeName(*(undefined2 *)(param_1 + 2));
[32m  iVar6 = mDNS_snprintf(param_3,0x1ff,"%4d %##s %s ",local_2c,uVar15,uVar5);[0m
  if (*param_1 == -0x10) {
    return param_3;
  }
  uVar16 = (uint)*(ushort *)(param_1 + 0xc);
  if ((uVar16 == 0) && (*(short *)(param_1 + 2) != 0x29)) {
[32m    mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6,"<< ZERO RDATA LENGTH >>");[0m
    return param_3;
  }
  uVar3 = *(ushort *)(param_1 + 2);
  if (uVar3 == 0x1c) {
    iVar10 = 0x1ff - iVar6;
    pcVar12 = "%.16a";
LAB_00422704:
[32m    mDNS_snprintf(param_3 + iVar6,iVar10,pcVar12,param_2,uVar15,uVar5);[0m
  }
  else {
    if (uVar3 < 0x1d) {
      if (uVar3 == 6) {
        mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6,"%##s %##s %d %d %d %d %d",param_2,
                      param_2 + 0x80,*(undefined4 *)(param_2 + 0x100),
                      *(undefined4 *)(param_2 + 0x102),*(undefined4 *)(param_2 + 0x104),
[32m                      *(undefined4 *)(param_2 + 0x106),*(undefined4 *)(param_2 + 0x108));[0m
        return param_3;
      }
      if (uVar3 < 7) {
        if ((uVar3 == 2) || (uVar3 == 5)) {
LAB_004226f4:
          iVar10 = 0x1ff - iVar6;
          pcVar12 = "%##s";
          goto LAB_00422704;
        }
        if (uVar3 == 1) {
          iVar10 = 0x1ff - iVar6;
          pcVar12 = "%.4a";
          goto LAB_00422704;
        }
      }
      else {
        if ((uVar3 == 0xd) || (uVar3 == 0x10)) {
          puVar17 = param_2;
          while( true ) {
            pcVar12 = "";
            if (param_2 < puVar17) {
              pcVar12 = &UNK_0045393c;
            }
            if ((ushort *)((int)param_2 + (uint)*(ushort *)(param_1 + 0xc)) <= puVar17) break;
[32m            iVar10 = mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6,"%s%#s",pcVar12,puVar17,uVar5);[0m
            iVar6 = iVar6 + iVar10;
            puVar17 = (ushort *)((int)puVar17 + *(byte *)puVar17 + 1);
          }
          return param_3;
        }
        if (uVar3 == 0xc) goto LAB_004226f4;
      }
    }
    else {
      if (uVar3 == 0x2e) {
        puVar19 = param_2 + 9;
        mDNSPlatformFormatTime(*(undefined4 *)(param_2 + 4),auStack_b4,0x40);
        mDNSPlatformFormatTime(*(undefined4 *)(param_2 + 6),auStack_74,0x40);
        local_2c = DNSTypeName(*param_2);
        uVar5 = FUN_0041ca04(*(byte *)(param_2 + 1));
        iVar10 = mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6,"\t%s  %s  %d  %d  %s  %s  %d  %##s ",
                               local_2c,uVar5,*(byte *)((int)param_2 + 3),
                               *(undefined4 *)(param_2 + 2),auStack_b4,auStack_74,param_2[8],puVar19
[32m                              );[0m
        puVar17 = puVar19;
        do {
          if (param_2 + 0x89 <= puVar17) {
LAB_00422e7c:
            uVar16 = 0x101;
            goto LAB_00422e80;
          }
          uVar16 = (uint)*(byte *)puVar17;
          if (0x3f < uVar16) goto LAB_00422e7c;
          puVar17 = (ushort *)((int)puVar17 + uVar16 + 1);
        } while (uVar16 != 0);
        uVar16 = (uint)((int)puVar17 + (-(int)puVar19 - (uVar16 + 1)) + 1) & 0xffff;
LAB_00422e80:
        param_2 = (ushort *)((int)param_2 + uVar16 + 0x12);
        iVar18 = (*(ushort *)(param_1 + 0xc) - 0x12) - uVar16;
LAB_00422f4c:
        FUN_00422460(param_3 + iVar10 + iVar6,0x1ff - (iVar10 + iVar6),param_2,iVar18,2);
        return param_3;
      }
      if (uVar3 < 0x2f) {
        if (uVar3 == 0x29) {
          iVar10 = mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6,"Max %d",*(undefined2 *)(param_1 + 4)
[32m                                 ,uVar15,uVar5);[0m
          local_30 = (ushort *)((int)param_2 + uVar16);
          iVar10 = iVar10 + iVar6;
          do {
            if (local_30 <= param_2) {
              return param_3;
            }
            puVar17 = (ushort *)(uint)*param_2;
            if (puVar17 == (ushort *)0x2) {
              puVar17 = *(ushort **)(param_2 + 2);
              pcVar12 = " Lease %d";
              iVar6 = 0x1ff - iVar10;
              pcVar9 = param_3 + iVar10;
LAB_00422adc:
[32m              iVar6 = mDNS_snprintf(pcVar9,iVar6,pcVar12,puVar17,uVar15,uVar5);[0m
              iVar10 = iVar10 + iVar6;
            }
            else {
              if (puVar17 < (ushort *)0x3) {
                if (puVar17 == (ushort *)0x1) {
                  iVar6 = mDNS_snprintf(param_3 + iVar10,0x1ff - iVar10,&DAT_00453960,1,uVar15,uVar5
[32m                                       );[0m
                  iVar6 = iVar6 + iVar10;
[32m                  iVar10 = mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6," Vers %d",param_2[2]);[0m
                  iVar6 = iVar6 + iVar10;
[32m                  iVar10 = mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6," Op %d",param_2[3]);[0m
                  iVar6 = iVar6 + iVar10;
[32m                  iVar10 = mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6," Err/Port %d",param_2[4]);[0m
                  iVar6 = iVar6 + iVar10;
                  uVar15 = *(undefined4 *)(param_2 + 8);
                  iVar10 = mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6," ID %08X%08X",
[32m                                         *(undefined4 *)(param_2 + 6));[0m
                  puVar17 = *(ushort **)(param_2 + 10);
                  iVar10 = iVar6 + iVar10;
                  iVar6 = 0x1ff - iVar10;
                  pcVar9 = param_3 + iVar10;
                  pcVar12 = " Lease %d";
                }
                else {
LAB_00422ac8:
                  pcVar9 = param_3 + iVar10;
                  iVar6 = 0x1ff - iVar10;
                  pcVar12 = " Unknown %d";
                }
                goto LAB_00422adc;
              }
              if (puVar17 != (ushort *)0x4) {
                if (puVar17 != (ushort *)0xfde9) goto LAB_00422ac8;
[32m                iVar6 = mDNS_snprintf(param_3 + iVar10,0x1ff - iVar10," Trace",0xfde9,uVar15,uVar5);[0m
                iVar6 = iVar6 + iVar10;
                iVar10 = mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6," Platform %d",
[32m                                       *(byte *)(param_2 + 2));[0m
                puVar17 = *(ushort **)(param_2 + 4);
                iVar10 = iVar6 + iVar10;
                pcVar12 = " mDNSVers %d";
                iVar6 = 0x1ff - iVar10;
                pcVar9 = param_3 + iVar10;
                goto LAB_00422adc;
              }
[32m              iVar6 = mDNS_snprintf(param_3 + iVar10,0x1ff - iVar10," Owner",4,uVar15,uVar5);[0m
              iVar6 = iVar6 + iVar10;
              iVar10 = mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6," Vers %d",*(byte *)(param_2 + 2)
[32m                                    );[0m
              iVar6 = iVar6 + iVar10;
              iVar10 = mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6," Seq %3d",
[32m                                     *(byte *)((int)param_2 + 5));[0m
              iVar6 = iVar6 + iVar10;
[32m              iVar10 = mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6," MAC %.6a",param_2 + 3);[0m
              iVar10 = iVar6 + iVar10;
              if (0xd < param_2[1]) {
[32m                iVar6 = mDNS_snprintf(param_3 + iVar10,0x1ff - iVar10," I-MAC %.6a",param_2 + 6);[0m
                iVar10 = iVar10 + iVar6;
                if (0xe < param_2[1]) {
                  iVar6 = 0x1ff - iVar10;
                  pcVar9 = param_3 + iVar10;
                  pcVar12 = " Password %.6a";
                  puVar17 = param_2 + 9;
                  goto LAB_00422adc;
                }
              }
            }
            param_2 = param_2 + 0xc;
          } while( true );
        }
        if (uVar3 == 0x2b) {
          uVar7 = FUN_0041ca04(*(byte *)(param_2 + 1));
          uVar3 = *param_2;
          bVar2 = *(byte *)((int)param_2 + 3);
          if (bVar2 == 1) {
            pcVar12 = "SHA1";
          }
          else if (bVar2 == 2) {
            pcVar12 = "SHA256";
          }
          else {
[32m            mDNS_snprintf(&DAT_0046e7d8,0x10,"DIG%d",bVar2,uVar15,uVar5);[0m
            pcVar12 = &DAT_0046e7d8;
          }
          uVar16 = (uint)(uVar3 >> 8) << 8 | uVar3 & 0xff;
          iVar18 = 0;
[32m          iVar10 = mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6,"\t%s\t%d\t%s ",uVar7,uVar16,pcVar12)[0m
          ;
          iVar10 = iVar10 + iVar6;
          while( true ) {
            iVar6 = iVar18 + 4;
            bVar4 = (int)(*(ushort *)(param_1 + 0xc) - 4) <= iVar18;
            iVar18 = iVar18 + 1;
            if (bVar4) break;
            iVar6 = mDNS_snprintf(param_3 + iVar10,0x1ff - iVar10,"%x",
[32m                                  *(byte *)((int)param_2 + iVar6),uVar16,pcVar12);[0m
            iVar10 = iVar10 + iVar6;
          }
          return param_3;
        }
        if (uVar3 == 0x21) {
          mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6,"%u %u %u %##s",*param_2,param_2[1],param_2[2]
[32m                        ,param_2 + 3);[0m
          return param_3;
        }
      }
      else {
        if (uVar3 == 0x30) {
          uVar3 = *param_2;
          bVar2 = *(byte *)(param_2 + 1);
          uVar5 = FUN_0041ca04(*(byte *)((int)param_2 + 3));
          uVar8 = 0;
          uVar16 = 0;
          puVar17 = param_2;
          while( true ) {
            bVar4 = *(ushort *)(param_1 + 0xc) <= uVar8;
            uVar14 = uVar8 & 1;
            uVar8 = uVar8 + 1;
            if (bVar4) break;
            bVar1 = *(byte *)puVar17;
            puVar17 = (ushort *)((int)puVar17 + 1);
            uVar13 = (uint)bVar1;
            if (uVar14 == 0) {
              uVar13 = (uint)bVar1 << 8;
            }
            uVar16 = uVar16 + uVar13;
          }
          iVar10 = mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6,"\t%d  %d  %s  %u ",
                                 (uint)(uVar3 >> 8) << 8 | uVar3 & 0xff,bVar2,uVar5,
[32m                                 (uVar16 >> 0x10) + uVar16 & 0xffff);[0m
          param_2 = param_2 + 2;
          iVar18 = *(ushort *)(param_1 + 0xc) - 4;
          goto LAB_00422f4c;
        }
        puVar17 = param_2;
        if (uVar3 < 0x30) {
          do {
            if (param_2 + 0x80 <= puVar17) {
LAB_00422b44:
              uVar8 = 0x101;
              goto LAB_00422b48;
            }
            uVar8 = (uint)*(byte *)puVar17;
            if (0x3f < uVar8) goto LAB_00422b44;
            puVar17 = (ushort *)((int)puVar17 + uVar8 + 1);
          } while (uVar8 != 0);
          uVar8 = (uint)((int)puVar17 + (-(int)param_2 - (uVar8 + 1)) + 1) & 0xffff;
LAB_00422b48:
          iVar10 = RRAssertsExistence(param_1,0x2f);
          if (iVar10 != 0) {
[32m            iVar10 = mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6,"%##s ",param_2,uVar15,uVar5);[0m
            iVar6 = iVar6 + iVar10;
          }
          pbVar11 = (byte *)(uVar16 - uVar8);
          pbVar20 = (byte *)((int)param_2 + uVar8);
LAB_00422cf0:
          FUN_0041e054(pbVar20,pbVar11,param_3,iVar6);
          return param_3;
        }
        if (uVar3 == 0x32) {
          bVar2 = *(byte *)param_2;
          if (bVar2 == 1) {
            pcVar12 = "SHA1";
          }
          else if (bVar2 == 2) {
            pcVar12 = "SHA256";
          }
          else {
[32m            mDNS_snprintf(&DAT_0046e7d8,0x10,"DIG%d",bVar2,uVar15,uVar5);[0m
            pcVar12 = &DAT_0046e7d8;
          }
          uVar8 = (uint)*(byte *)((int)param_2 + 1);
          uVar16 = (uint)param_2[1];
[32m          iVar10 = mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6,"\t%s  %d  %d ",pcVar12,uVar8,uVar16)[0m
          ;
          iVar10 = iVar10 + iVar6;
          if (*(byte *)(param_2 + 2) == 0) {
[32m            iVar6 = mDNS_snprintf(param_3 + iVar10,0x1ff - iVar10,&DAT_00453a38);[0m
            iVar10 = iVar10 + iVar6;
          }
          else {
            iVar6 = 0;
            while( true ) {
              iVar18 = iVar6 + 5;
              bVar4 = (int)(uint)*(byte *)(param_2 + 2) <= iVar6;
              iVar6 = iVar6 + 1;
              if (bVar4) break;
              iVar18 = mDNS_snprintf(param_3 + iVar10,0x1ff - iVar10,"%x",
[32m                                     *(byte *)((int)param_2 + iVar18),uVar8,uVar16);[0m
              iVar10 = iVar10 + iVar18;
            }
          }
[32m          iVar18 = mDNS_snprintf(param_3 + iVar10,0x1ff - iVar10," ");[0m
          iVar18 = iVar18 + iVar10;
          pbVar20 = (byte *)((int)param_2 + *(byte *)(param_2 + 2) + 5);
          uVar16 = (uint)*pbVar20;
          pbVar20 = pbVar20 + 1;
          iVar6 = FUN_00422460(param_3 + iVar18,0x1ff - iVar18,pbVar20,uVar16,1);
          iVar6 = iVar6 + iVar18;
[32m          iVar10 = mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6," ");[0m
          pbVar20 = pbVar20 + uVar16;
          iVar6 = iVar6 + iVar10;
          pbVar11 = (byte *)((int)param_2 + ((uint)*(ushort *)(param_1 + 0xc) - (int)pbVar20));
          goto LAB_00422cf0;
        }
      }
    }
[32m    mDNS_snprintf(param_3 + iVar6,0x1ff - iVar6,"RDLen %d: %s",uVar16,param_2,uVar5);[0m
    for (pcVar12 = param_3; *pcVar12 != '\0'; pcVar12 = pcVar12 + 1) {
      if (*pcVar12 < ' ') {
        *pcVar12 = '.';
      }
    }
  }
  return param_3;
}

[ASK_GPT] b75a671d2bb2ca32
