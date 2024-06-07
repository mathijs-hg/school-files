
int main(int argc,char **argv)

{
  bool bVar1;
  ulonglong uVar2;
  bool bVar3;
  FILE *pFVar4;
  int iVar5;
  libmtd_t desc;
  int iVar6;
  void *pvVar7;
  ssize_t sVar8;
  int *piVar9;
  char *pcVar10;
  void *data;
  uint uVar11;
  uint uVar12;
  int *__nptr;
  void *eb;
  UDItype UVar13;
  DItype DVar14;
  undefined4 in_stack_fffffdcc;
  undefined4 in_stack_fffffdd0;
  undefined4 in_stack_fffffdd4;
  char *local_218;
  int option_index;
  nand_oobinfo oobinfo;
  mtd_dev_info mtd;
  ulong local_40;
  __u32 local_34;
  __u32 local_30;
  
  bVar1 = false;
  while( true ) {
    piVar9 = &option_index;
    option_index = 0;
[32m    iVar5 = getopt_long(argc,argv,&DAT_00406170,main::lexical_block_0::long_options);[0m
    if (iVar5 == -1) break;
    if (iVar5 == 0x6a) {
      jffs2 = 1;
    }
    else if (iVar5 < 0x6b) {
      if (iVar5 == 0x4e) {
        noskipbad = 1;
      }
      else if (iVar5 < 0x4f) {
        if (iVar5 == 0) {
          if (option_index == 0) {
            pcVar10 = 
            "Usage: %s [options] MTD_DEVICE <start offset> <block count>\nErase blocks of the specified MTD device.\nSpecify a count of 0 to erase to end of device.\n\n  -j, --jffs2       format the device for jffs2\n  -N, --noskipbad   don\'t skip bad blocks\n  -u, --unlock      unlock sectors before erasing\n  -q, --quiet       do not display progress messages\n      --silent      same as --quiet\n      --help        display this help and exit\n      --version     output version information and exit\n"
            ;
            goto LAB_00400cac;
          }
          if (option_index == 1) {
            pcVar10 = 
            "%1$s version 1.5.2\n\nCopyright (C) 2000 Arcom Control Systems Ltd\n\n%1$s comes with NO WARRANTY\nto the extent permitted by law.\n\nYou may redistribute copies of %1$s\nunder the terms of the GNU General Public Licence.\nSee the file `COPYING\' for more information.\n"
            ;
LAB_00400cac:
            printf(pcVar10,"flash_erase");
            return 0;
          }
        }
        else if (iVar5 == 0x3f) {
          bVar1 = true;
        }
      }
    }
    else if (iVar5 == 0x71) {
      quiet = 1;
    }
    else if (iVar5 == 0x75) {
      unlock = 1;
    }
  }
  iVar5 = argc - optind;
  if (iVar5 != 2) {
    if (iVar5 == 3) {
      __nptr = (int *)argv[optind + 1];
      mtd_device = argv[optind];
      strtoull((char *)__nptr,&local_218,0);
      if ((*(char *)__nptr == '\0') || (*local_218 != '\0')) {
        fprintf(stderr,"%s: error!: %s: unable to parse the number \'%s\'\n","flash_erase",
                "strtoull");
        bVar1 = true;
        piVar9 = __nptr;
      }
      pcVar10 = argv[optind + 2];
      local_40 = strtoul(pcVar10,&local_218,0);
      if ((*pcVar10 != '\0') && (*local_218 == '\0')) {
        if (bVar1) goto LAB_00400da0;
[32m        desc = libmtd_open();[0m
        if (desc == (libmtd_t)0x0) {
          pcVar10 = "%s: error!: can\'t initialize libmtd\n";
        }
        else {
[32m          iVar5 = open64(mtd_device,2);[0m
          if (iVar5 < 0) {
            piVar9 = __errno_location();
            iVar5 = *piVar9;
            pcVar10 = "%s: error!: %s\n";
LAB_00401718:
            fprintf(stderr,pcVar10,"flash_erase",mtd_device);
            pFVar4 = stderr;
            pcVar10 = strerror(iVar5);
            fprintf(pFVar4,"%*serror %d (%s)\n",0xd,"",iVar5,pcVar10);
            return -1;
          }
          iVar6 = mtd_get_dev_info(desc,mtd_device,&mtd);
          if (iVar6 < 0) {
            pcVar10 = "%s: error!: mtd_get_dev_info failed\n";
          }
          else {
            if ((jffs2 == 0) || (mtd.type != 8)) {
              bVar1 = mtd.type == 4;
              bVar3 = mtd.type == 8;
              if (jffs2 == 0) {
                local_34 = 8;
                local_30 = 0;
              }
              else {
                if (target_endian == 0x4d2) {
                  cleanmarker.magic.v16 = 0x1985;
                  cleanmarker.nodetype.v16 = 0x2003;
                }
                else {
                  cleanmarker.magic.v16 = 0x8519;
                  cleanmarker.nodetype.v16 = 800;
                }
                if (bVar1 || bVar3) {
                  iVar6 = ioctl(iVar5,0x40c84d0a,&oobinfo);
                  if (iVar6 != 0) {
                    piVar9 = __errno_location();
                    iVar5 = *piVar9;
                    pcVar10 = "%s: error!: %s: unable to get NAND oobinfo\n";
                    goto LAB_00401718;
                  }
                  if (oobinfo.useecc == 2) {
                    local_34 = oobinfo.oobfree[0][1];
                    if (oobinfo.oobfree[0][1] == 0) {
                      pcVar10 = 
                      "%s: error!:  Eeep. Autoplacement selected and no empty space in oob\n";
                      goto LAB_00401784;
                    }
                    local_30 = oobinfo.oobfree[0][0];
                    if (8 < (int)oobinfo.oobfree[0][1]) {
                      local_34 = 8;
                    }
                  }
                  else if (mtd.oob_size == 0x10) {
                    local_34 = 8;
                    local_30 = 8;
                  }
                  else if (mtd.oob_size == 0x40) {
                    local_34 = 8;
                    local_30 = 0x10;
                  }
                  else if (mtd.oob_size == 8) {
                    local_34 = 2;
                    local_30 = 6;
                  }
                  else {
                    local_34 = 8;
                    local_30 = 0;
                  }
                  cleanmarker.totlen.v32 = 8;
                  if (target_endian != 0x4d2) {
                    cleanmarker.totlen.v32 = 0x8000000;
                  }
                }
                else {
                  cleanmarker.totlen.v32 = 0xc;
                  if (target_endian != 0x4d2) {
                    cleanmarker.totlen.v32 = 0xc000000;
                  }
                  local_34 = 8;
                  local_30 = 0;
                }
                cleanmarker.hdr_crc.v32 = mtd_crc32(0,&cleanmarker,8);
                if (target_endian != 0x4d2) {
                  cleanmarker.hdr_crc.v32 =
                       cleanmarker.hdr_crc.v32 << 0x18 | cleanmarker.hdr_crc.v32 >> 0x18 |
                       cleanmarker.hdr_crc.v32 >> 8 & 0xff00 |
                       (cleanmarker.hdr_crc.v32 & 0xff00) << 8;
                }
              }
              UVar13 = __udivdi3(CONCAT44(in_stack_fffffdcc,piVar9),
                                 CONCAT44(in_stack_fffffdd4,in_stack_fffffdd0));
              pvVar7 = (void *)UVar13;
              if (local_40 == 0) {
                DVar14 = __divdi3(CONCAT44(in_stack_fffffdcc,piVar9),
                                  CONCAT44(in_stack_fffffdd4,in_stack_fffffdd0));
                local_40 = (int)DVar14 - (int)pvVar7;
              }
              uVar11 = 0;
              eb = pvVar7;
              if (pvVar7 < (void *)(local_40 + (int)pvVar7)) {
                do {
                  uVar2 = ZEXT48(eb) * (ulonglong)(uint)mtd.eb_size;
                  uVar11 = (uint)uVar2;
                  uVar12 = (mtd.eb_size >> 0x1f) * (int)eb + (int)(uVar2 >> 0x20);
                  if (noskipbad == 0) {
                    iVar6 = mtd_is_bad(&mtd,iVar5,(int)eb);
                    if (iVar6 < 1) {
                      if (iVar6 != 0) {
                        piVar9 = __errno_location();
                        iVar6 = *piVar9;
                        if (iVar6 != 0x7a) {
                          fprintf(stderr,"%s: error!: %s: MTD get bad block failed\n","flash_erase",
                                  mtd_device);
                          pFVar4 = stderr;
                          pcVar10 = strerror(iVar6);
                          fprintf(pFVar4,"%*serror %d (%s)\n",0xd,"",iVar6,pcVar10);
                          return -1;
                        }
                        noskipbad = 1;
                        if (bVar1 || bVar3) {
                          fprintf(stderr,"%s: error!: %s: Bad block check not available\n",
                                  "flash_erase",mtd_device);
                          return -1;
                        }
                      }
                      goto LAB_00401064;
                    }
                    if (quiet == 0) {
                      pcVar10 = "%s: Skipping bad block at %08llx\n";
LAB_004011e8:
                      printf(pcVar10,"flash_erase",uVar11,uVar12);
                    }
                  }
                  else {
LAB_00401064:
                    if (quiet == 0) {
                      if (local_40 == 0) {
                        trap(0x1c00);
                      }
                      printf("\rErasing %d Kibyte @ %llx -- %2i %% complete ",
                             (int)(((uint)(mtd.eb_size >> 0x1f) >> 0x16) + mtd.eb_size) >> 10,uVar11
                             ,uVar12,(((int)eb - (int)pvVar7) * 100) / (int)local_40);
                    }
                    fflush(stdout);
                    if ((unlock == 0) || (iVar6 = mtd_unlock(&mtd,iVar5,(int)eb), iVar6 == 0)) {
                      data = eb;
                      iVar6 = mtd_erase(desc,&mtd,iVar5,(int)eb);
                      if (iVar6 == 0) {
                        if (jffs2 == 0) goto joined_r0x00401170;
                        if (bVar1 || bVar3) {
                          iVar6 = mtd_write_oob(desc,&mtd,iVar5,
                                                CONCAT44((uint)(uVar11 + local_30 < uVar11) +
                                                         uVar12 + ((int)local_30 >> 0x1f),
                                                         uVar11 + local_30),(longlong)(int)local_34,
                                                data);
                          if (iVar6 == 0) {
LAB_00401158:
                            if (quiet == 0) {
                              pcVar10 = "%s:  Cleanmarker written at %llx\n";
                              goto LAB_004011e8;
                            }
                            goto joined_r0x00401170;
                          }
                          piVar9 = __errno_location();
                          iVar6 = *piVar9;
                          pcVar10 = "%s: error!: %s: MTD writeoob failure\n";
                        }
                        else {
                          sVar8 = pwrite64(iVar5,&cleanmarker,0xc,
                                           uVar2 & 0xffffffff | (ulonglong)uVar12 << 0x20);
                          if (sVar8 == 0xc) goto LAB_00401158;
                          piVar9 = __errno_location();
                          iVar6 = *piVar9;
                          pcVar10 = "%s: error!: %s: MTD write failure\n";
                        }
                      }
                      else {
                        piVar9 = __errno_location();
                        iVar6 = *piVar9;
                        pcVar10 = "%s: error!: %s: MTD Erase failure\n";
                      }
                    }
                    else {
                      piVar9 = __errno_location();
                      iVar6 = *piVar9;
                      pcVar10 = "%s: error!: %s: MTD unlock failure\n";
                    }
                    fprintf(stderr,pcVar10,"flash_erase",mtd_device);
                    pFVar4 = stderr;
                    pcVar10 = strerror(iVar6);
                    fprintf(pFVar4,"%*serror %d (%s)\n",0xd,"",iVar6,pcVar10);
                  }
joined_r0x00401170:
                  eb = (void *)((int)eb + 1);
                } while (eb < (void *)(local_40 + (int)pvVar7));
              }
              else {
                uVar12 = 0;
              }
              if (quiet == 0) {
                if (local_40 == 0) {
                  trap(0x1c00);
                }
                printf("\rErasing %d Kibyte @ %llx -- %2i %% complete ",
                       (int)(((uint)(mtd.eb_size >> 0x1f) >> 0x16) + mtd.eb_size) >> 10,uVar11,
                       uVar12,(((int)eb - (int)pvVar7) * 100) / (int)local_40);
              }
              fflush(stdout);
              if (quiet != 0) {
                return 0;
              }
              putchar(10);
              return 0;
            }
            pcVar10 = "%s: error!: JFFS2 cannot support MLC NAND.\n";
          }
        }
LAB_00401784:
        fprintf(stderr,pcVar10,"flash_erase");
        return -1;
      }
      fprintf(stderr,"%s: error!: %s: unable to parse the number \'%s\'\n","flash_erase","strtoul",
              pcVar10);
      goto LAB_00400da0;
    }
    if (iVar5 != 1) {
      fprintf(stderr,"%s: error!: no MTD device specified\n","flash_erase");
    }
    fprintf(stderr,"%s: error!: no start erase block specified\n","flash_erase");
  }
  fprintf(stderr,"%s: error!: no erase block count specified\n","flash_erase");
LAB_00400da0:
  fprintf(stderr,"%s: error!: Try `--help\' for more information\n","flash_erase");
  return -1;
}

[ASK_GPT] 9dc05953a72269d2
