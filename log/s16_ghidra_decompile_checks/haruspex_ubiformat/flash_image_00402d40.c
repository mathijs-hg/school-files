
int flash_image(libmtd_t libmtd,mtd_dev_info *mtd,ubigen_info *ui,ubi_scan_info *si)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  uint32_t uVar13;
  uint uVar14;
  uint *ss;
  undefined4 *puVar15;
  int iVar16;
  uint *puVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  code *pcVar20;
  undefined *puVar21;
  DItype DVar22;
  undefined4 in_stack_fffffee8;
  undefined4 in_stack_fffffeec;
  undefined4 in_stack_fffffef0;
  undefined4 in_stack_fffffef4;
  int iStack_108;
  undefined4 uStack_104;
  undefined *local_100 [2];
  stat st;
  int local_48;
  int local_44;
  int local_40;
  uint32_t _x;
  undefined *local_2c;
  
  pcVar3 = args.image;
  local_100[0] = &_gp;
  iVar4 = strcmp(args.image,"-");
  if (iVar4 == 0) {
    if (((uint)args.image_sz | args.image_sz._4_4_) == 0) {
      (**(code **)(local_100[0] + -0x7e90))
                (**(undefined4 **)(local_100[0] + -0x7ee8),
                 "%s: error!: must use \'-S\' with non-zero value when reading from stdin\n",
                 "ubiformat");
      return -1;
    }
    iVar4 = (**(code **)(local_100[0] + -0x7ee0))(0);
    if (-1 < iVar4) {
LAB_00402dec:
      DVar22 = __divdi3(CONCAT44(in_stack_fffffeec,in_stack_fffffee8),
                        CONCAT44(in_stack_fffffef4,in_stack_fffffef0));
      local_40 = (int)DVar22;
      if (si->good_cnt < local_40) {
        puVar12 = *(undefined4 **)(local_100[0] + -0x7ee8);
        puVar15 = (undefined4 *)(**(code **)(local_100[0] + -0x7ef0))();
        uVar18 = *puVar15;
        (**(code **)(local_100[0] + -0x7e90))
                  (*puVar12,"%s: error!: file \"%s\" is too large (%lld bytes)\n","ubiformat",
                   args.image);
        uVar7 = *puVar12;
        (**(code **)(local_100[0] + -0x7e58))(uVar18);
        (**(code **)(local_100[0] + -0x7e90))(uVar7,"%*serror %d (%s)\n",0xb,&DAT_0040e38c);
out_close:
        (**(code **)(local_100[0] + -0x7f10))(iVar4);
        return -1;
      }
      DVar22 = __moddi3(CONCAT44(in_stack_fffffeec,in_stack_fffffee8),
                        CONCAT44(in_stack_fffffef4,in_stack_fffffef0));
      if (DVar22 == 0) {
        if ((args._0_4_ & 4) != 0) {
          (**(code **)(local_100[0] + -0x7e50))
                    ("%s: will write %d eraseblocks\n","ubiformat",local_40);
        }
        puVar21 = local_100[0];
        if (mtd->eb_cnt < 1) {
          iVar16 = 0;
LAB_00403010:
          if ((args._0_4_ & 6) == 0) {
            (**(code **)(puVar21 + -0x7e44))(10);
            puVar21 = local_100[0];
          }
          (**(code **)(puVar21 + -0x7f10))(iVar4);
          return iVar16 + 1;
        }
        local_48 = 0;
        local_44 = 0;
        iVar16 = 0;
        uVar9 = args._0_4_;
LAB_00402e94:
        iVar8 = -(mtd->eb_size + 0xeU & 0xfffffff8);
        ss = (uint *)((int)local_100 + iVar8);
        if ((uVar9 & 6) == 0) {
          DVar22 = __divdi3(*(DItype *)((int)&st + iVar8 + -0x20),
                            *(DItype *)((int)&st + iVar8 + -0x18));
          (**(code **)(local_100[0] + -0x7e50))
                    ("\rubiformat: flashing eraseblock %d -- %2lld %% complete  ",iVar16,(int)DVar22
                     ,(int)((ulonglong)DVar22 >> 0x20));
          (**(code **)(local_100[0] + -0x7e80))(**(undefined4 **)(local_100[0] + -0x7e54));
          uVar13 = si->ec[iVar16];
          uVar9 = args._0_4_;
          puVar21 = local_100[0];
        }
        else {
          uVar13 = si->ec[iVar16];
        }
        if (uVar13 != 0xfffffffc) {
          if ((uVar9 & 4) != 0) {
            (**(code **)(puVar21 + -0x7e50))("%s: eraseblock %d: erase","ubiformat",iVar16);
            (**(code **)(local_100[0] + -0x7e80))(**(undefined4 **)(local_100[0] + -0x7e54));
          }
          iVar5 = mtd_erase(libmtd,mtd,args.node_fd,iVar16);
          if (iVar5 == 0) {
            if (local_48 == 0) {
              iVar5 = mtd->eb_size;
              puVar17 = ss;
joined_r0x00403434:
              for (; iVar5 != 0; iVar5 = iVar5 - iVar11) {
                iVar11 = (**(code **)(local_100[0] + -0x7ea8))(iVar4,puVar17,iVar5);
                if (iVar11 == 0) {
                  puVar15 = *(undefined4 **)(local_100[0] + -0x7ee8);
                  (**(code **)(local_100[0] + -0x7e90))
                            (*puVar15,"%s: error!: eof reached; %zu bytes remaining\n","ubiformat",
                             iVar5);
                  goto LAB_004036a0;
                }
                if (iVar11 < 1) goto LAB_00403494;
                puVar17 = (uint *)((int)puVar17 + iVar11);
              }
            }
            uVar9 = (uint)args.ec;
            uVar2 = args.ec._4_4_;
            if ((args._0_4_ & 8) == 0) {
              if ((int)si->ec[iVar16] < 0) {
                uVar9 = *(uint *)&si->mean_ec;
                uVar2 = *(uint *)((int)&si->mean_ec + 4);
              }
              else {
                uVar9 = si->ec[iVar16] + 1;
                uVar2 = 0;
              }
            }
            if ((args._0_4_ & 4) != 0) {
              (**(code **)(local_100[0] + -0x7e50))(", change EC to %lld");
              (**(code **)(local_100[0] + -0x7e80))(**(undefined4 **)(local_100[0] + -0x7e54));
            }
            uVar10 = *ss;
            uVar14 = ui->image_seq;
            if ((uVar10 >> 0x18 | uVar10 << 0x18 | (uVar10 & 0xff00) << 8 | (uVar10 & 0xff0000) >> 8
                ) == 0x55424923) {
              uVar13 = mtd_crc32(0xffffffff,ss,0x3c);
              uVar10 = *(uint *)((int)&st + iVar8 + 0x34);
              uVar10 = uVar10 >> 0x18 | uVar10 << 0x18 | (uVar10 & 0xff00) << 8 |
                       (uVar10 & 0xff0000) >> 8;
              if (uVar13 == uVar10) {
                *(uint *)((int)&st + iVar8 + 4) =
                     uVar9 >> 0x18 | uVar9 << 0x18 | (uVar9 & 0xff00) << 8 | (uVar9 & 0xff0000) >> 8
                ;
                *(uint *)((int)&st + iVar8 + 0x10) =
                     uVar14 >> 0x18 | uVar14 << 0x18 | (uVar14 & 0xff00) << 8 |
                     (uVar14 & 0xff0000) >> 8;
                *(uint *)((int)&st + iVar8) =
                     uVar2 >> 0x18 | uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | (uVar2 & 0xff0000) >> 8
                ;
                uVar13 = mtd_crc32(0xffffffff,ss,0x3c);
                *(uint32_t *)((int)&st + iVar8 + 0x34) =
                     uVar13 >> 0x18 | uVar13 << 0x18 | (uVar13 & 0xff00) << 8 |
                     (uVar13 & 0xff0000) >> 8;
                if ((args._0_4_ & 4) != 0) {
                  (**(code **)(local_100[0] + -0x7e70))(", write data");
                  (**(code **)(local_100[0] + -0x7e80))(**(undefined4 **)(local_100[0] + -0x7e54));
                }
                iVar5 = mtd->eb_size + -1;
                if (-1 < iVar5) {
[32m                  cVar1 = *(char *)((int)ss + iVar5);[0m
                  while (cVar1 == -1) {
                    iVar5 = iVar5 + -1;
                    if (iVar5 == -1) break;
[32m                    cVar1 = *(char *)((int)ss + iVar5);[0m
                  }
                }
                iVar11 = mtd->min_io_size;
                *(undefined4 *)((int)&st + iVar8 + -0x20) = 0;
                if (iVar11 == 0) {
                  trap(0x1c00);
                }
                *(uint **)((int)&st + iVar8 + -0x1c) = ss;
                *(undefined4 *)((int)&st + iVar8 + -0x14) = 0;
                *(undefined4 *)((int)&iStack_108 + iVar8) = 0;
                *(undefined4 *)((int)&uStack_104 + iVar8) = 0;
                *(int *)((int)&st + iVar8 + -0x18) = iVar11 * ((iVar5 + iVar11) / iVar11);
                iVar5 = mtd_write(libmtd,mtd,args.node_fd,iVar16,*(int *)((int)&st + iVar8 + -0x20),
                                  *(void **)((int)&st + iVar8 + -0x1c),
                                  *(int *)((int)&st + iVar8 + -0x18),
                                  *(void **)((int)&st + iVar8 + -0x14),
                                  *(int *)((int)&iStack_108 + iVar8),
                                  *(uint8_t *)((int)&uStack_104 + iVar8));
                if (iVar5 == 0) {
                  local_44 = local_44 + 1;
                  puVar21 = local_100[0];
                  if (local_40 <= local_44) goto LAB_00403010;
                  local_48 = 0;
                  uVar9 = args._0_4_;
                }
                else {
                  local_2c = &DAT_00410000;
                  piVar6 = (int *)(**(code **)(local_100[0] + -0x7ef0))();
                  iVar5 = *piVar6;
                  (**(code **)(local_100[0] + -0x7e90))
                            (**(undefined4 **)(local_100[0] + -0x7ee8),
                             "%s: error!: cannot write eraseblock %d\n","ubiformat",iVar16);
                  _x = **(uint32_t **)(local_100[0] + -0x7ee8);
                  uVar7 = (**(code **)(local_100[0] + -0x7e58))(iVar5);
                  puVar21 = local_100[0];
                  *(undefined4 *)((int)&st + iVar8 + -0x1c) = uVar7;
                  *(int *)((int)&st + iVar8 + -0x20) = iVar5;
                  (**(code **)(puVar21 + -0x7e90))(_x,"%*serror %d (%s)\n",0xb,local_2c + -0x1c74);
                  if (*piVar6 != 5) goto out_close;
                  iVar8 = mtd_torture(libmtd,mtd,args.node_fd,iVar16);
                  if (iVar8 != 0) {
                    iVar8 = mark_bad(mtd,si,iVar16);
                    if (iVar8 == 0) {
                      local_48 = 1;
                      uVar9 = args._0_4_;
                      puVar21 = local_100[0];
                      goto LAB_00402fe4;
                    }
                    goto out_close;
                  }
                  local_48 = 1;
                  uVar9 = args._0_4_;
                  puVar21 = local_100[0];
                }
                goto LAB_00402fe4;
              }
              puVar15 = *(undefined4 **)(local_100[0] + -0x7ee8);
              pcVar20 = *(code **)(local_100[0] + -0x7e90);
              uVar7 = *puVar15;
              *(uint *)((int)&st + iVar8 + -0x20) = uVar10;
              (*pcVar20)(uVar7,"%s: error!: bad CRC %#08x, should be %#08x\n\n","ubiformat",uVar13);
            }
            else {
              puVar15 = *(undefined4 **)(local_100[0] + -0x7ee8);
              pcVar20 = *(code **)(local_100[0] + -0x7e90);
              uVar7 = *puVar15;
              *(undefined4 *)((int)&st + iVar8 + -0x20) = 0x55424923;
              (*pcVar20)(uVar7,"%s: error!: bad UBI magic %#08x, should be %#08x\n","ubiformat");
            }
            uVar7 = *puVar15;
            pcVar20 = *(code **)(local_100[0] + -0x7e90);
            *(char **)((int)&st + iVar8 + -0x20) = args.image;
            (*pcVar20)(uVar7,"%s: error!: bad EC header at eraseblock %d of \"%s\"\n","ubiformat",
                       local_44);
            goto out_close;
          }
          if ((args._0_4_ & 2) == 0) {
            (**(code **)(local_100[0] + -0x7e44))(10);
          }
          local_2c = &DAT_00410000;
          piVar6 = (int *)(**(code **)(local_100[0] + -0x7ef0))();
          iVar5 = *piVar6;
          (**(code **)(local_100[0] + -0x7e90))
                    (**(undefined4 **)(local_100[0] + -0x7ee8),
                     "%s: error!: failed to erase eraseblock %d\n","ubiformat",iVar16);
          _x = **(uint32_t **)(local_100[0] + -0x7ee8);
          uVar7 = (**(code **)(local_100[0] + -0x7e58))(iVar5);
          puVar21 = local_100[0];
          *(undefined4 *)((int)&st + iVar8 + -0x1c) = uVar7;
          *(int *)((int)&st + iVar8 + -0x20) = iVar5;
          (**(code **)(puVar21 + -0x7e90))(_x,"%*serror %d (%s)\n",0xb,local_2c + -0x1c74);
          if ((*piVar6 != 5) ||
             (iVar8 = mark_bad(mtd,si,iVar16), uVar9 = args._0_4_, puVar21 = local_100[0],
             iVar8 != 0)) goto out_close;
        }
LAB_00402fe4:
        iVar16 = iVar16 + 1;
        if (mtd->eb_cnt <= iVar16) goto LAB_00403010;
        goto LAB_00402e94;
      }
      puVar12 = *(undefined4 **)(local_100[0] + -0x7ee8);
      iVar4 = -1;
      puVar15 = (undefined4 *)(**(code **)(local_100[0] + -0x7ef0))();
      uVar7 = *puVar15;
      (**(code **)(local_100[0] + -0x7e90))
                (*puVar12,
                 "%s: error!: file \"%s\" (size %lld bytes) is not multiple of eraseblock size (%d bytes)\n"
                 ,"ubiformat",args.image);
      uVar18 = *puVar12;
      (**(code **)(local_100[0] + -0x7e58))(uVar7);
      pcVar20 = *(code **)(local_100[0] + -0x7e90);
      goto LAB_00403944;
    }
    puVar15 = *(undefined4 **)(local_100[0] + -0x7ee8);
    iVar4 = -1;
    puVar12 = (undefined4 *)(**(code **)(local_100[0] + -0x7ef0))();
    uVar7 = *puVar12;
    (**(code **)(local_100[0] + -0x7e90))(*puVar15,"%s: error!: failed to dup stdin\n","ubiformat");
  }
  else {
    iVar16 = (**(code **)(local_100[0] + -0x7e5c))(pcVar3,&st);
    iVar4 = -1;
    if (iVar16 == 0) {
      iVar4 = (**(code **)(local_100[0] + -0x7ed4))(args.image,0);
      if (iVar4 != -1) {
        if (iVar4 < 0) {
          return iVar4;
        }
        goto LAB_00402dec;
      }
      pcVar20 = *(code **)(local_100[0] + -0x7ef0);
      puVar15 = *(undefined4 **)(local_100[0] + -0x7ee8);
    }
    else {
      pcVar20 = *(code **)(local_100[0] + -0x7ef0);
      puVar15 = *(undefined4 **)(local_100[0] + -0x7ee8);
    }
    puVar12 = (undefined4 *)(*pcVar20)();
    uVar7 = *puVar12;
    (**(code **)(local_100[0] + -0x7e90))
              (*puVar15,"%s: error!: cannot open \"%s\"\n","ubiformat",args.image);
  }
  uVar18 = *puVar15;
  (**(code **)(local_100[0] + -0x7e58))(uVar7);
  pcVar20 = *(code **)(local_100[0] + -0x7e90);
LAB_00403944:
  (*pcVar20)(uVar18,"%*serror %d (%s)\n",0xb,&DAT_0040e38c);
  return iVar4;
LAB_00403494:
  piVar6 = (int *)(**(code **)(local_100[0] + -0x7ef0))();
  iVar11 = *piVar6;
  if ((iVar11 != 4) && (iVar11 != 0xb)) {
    puVar15 = *(undefined4 **)(local_100[0] + -0x7ee8);
    (**(code **)(local_100[0] + -0x7e90))
              (*puVar15,"%s: error!: reading failed; %zu bytes remaining\n","ubiformat",iVar5);
    uVar18 = *puVar15;
    uVar7 = (**(code **)(local_100[0] + -0x7e58))(iVar11);
    pcVar20 = *(code **)(local_100[0] + -0x7e90);
    *(int *)((int)&st + iVar8 + -0x20) = iVar11;
    *(undefined4 *)((int)&st + iVar8 + -0x1c) = uVar7;
    (*pcVar20)(uVar18,"%*serror %d (%s)\n",0xb,&DAT_0040e38c);
LAB_004036a0:
    puVar12 = (undefined4 *)(**(code **)(local_100[0] + -0x7ef0))();
    uVar7 = *puVar15;
    pcVar20 = *(code **)(local_100[0] + -0x7e90);
    uVar19 = *puVar12;
    *(char **)((int)&st + iVar8 + -0x20) = args.image;
    (*pcVar20)(uVar7,"%s: error!: failed to read eraseblock %d from \"%s\"\n","ubiformat",local_44);
    uVar18 = *puVar15;
    uVar7 = (**(code **)(local_100[0] + -0x7e58))(uVar19);
    puVar21 = local_100[0];
    *(undefined4 *)((int)&st + iVar8 + -0x20) = uVar19;
    *(undefined4 *)((int)&st + iVar8 + -0x1c) = uVar7;
    (**(code **)(puVar21 + -0x7e90))(uVar18,"%*serror %d (%s)\n",0xb,&DAT_0040e38c);
    goto out_close;
  }
  goto joined_r0x00403434;
}

[ASK_GPT] 39c301da203b0290
