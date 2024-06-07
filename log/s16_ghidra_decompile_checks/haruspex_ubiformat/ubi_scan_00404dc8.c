
int ubi_scan(mtd_dev_info *mtd,int fd,ubi_scan_info **info,int verbose)

{
  bool bVar1;
  __be32 *p_Var2;
  FILE *pFVar3;
  ubi_scan_info *__ptr;
  uint32_t *puVar4;
  int iVar5;
  ubi_ec_hdr *puVar6;
  uint32_t uVar7;
  int *piVar8;
  uint uVar9;
  char *pcVar10;
  uint uVar11;
  size_t __nmemb;
  ubi_ec_hdr *eb;
  int iVar12;
  int iVar13;
  UDItype UVar14;
  DItype DVar15;
  ubi_ec_hdr *in_stack_ffffff68;
  ubi_ec_hdr *in_stack_ffffff6c;
  undefined4 in_stack_ffffff70;
  undefined4 in_stack_ffffff74;
  ubi_ec_hdr ech;
  uint local_38;
  uint local_34;
  uint local_30;
  
[32m[32m  __ptr = (ubi_scan_info *)calloc(1,0x30);[0m[0m
  if (__ptr == (ubi_scan_info *)0x0) {
    iVar12 = -1;
    piVar8 = __errno_location();
    iVar13 = *piVar8;
    fprintf(stderr,"%s: error!: cannot allocate %zd bytes of memory\n","libscan",0x30);
    pFVar3 = stderr;
    pcVar10 = strerror(iVar13);
    fprintf(pFVar3,"%*serror %d (%s)\n",9,&DAT_0040e38c,iVar13,pcVar10);
  }
  else {
    __nmemb = mtd->eb_cnt;
[32m[32m    puVar4 = (uint32_t *)calloc(__nmemb,4);[0m[0m
    __ptr->ec = puVar4;
    if (puVar4 == (uint32_t *)0x0) {
      piVar8 = __errno_location();
      iVar12 = *piVar8;
      fprintf(stderr,"%s: error!: cannot allocate %zd bytes of memory\n","libscan",0x30);
      pFVar3 = stderr;
      pcVar10 = strerror(iVar12);
      fprintf(pFVar3,"%*serror %d (%s)\n",9,&DAT_0040e38c,iVar12,pcVar10);
out_si:
      iVar12 = -1;
      free(__ptr);
      *info = (ubi_scan_info *)0x0;
    }
    else {
      bVar1 = verbose == 2;
      __ptr->data_offs = -1;
      __ptr->vid_hdr_offs = -1;
      if (bVar1) {
        printf("%s: start scanning eraseblocks 0-%d\n","libscan",__nmemb);
      }
      iVar12 = mtd->eb_cnt;
      local_38 = (uint)(verbose == 1);
      if (0 < iVar12) {
        iVar13 = 0;
        eb = (ubi_ec_hdr *)0x0;
        do {
          puVar6 = in_stack_ffffff68;
          if (bVar1) {
            printf("%s: scanning eraseblock %d","libscan",eb);
            fflush(stdout);
            puVar6 = in_stack_ffffff68;
          }
          if (local_38 != 0) {
            DVar15 = __divdi3(CONCAT44(in_stack_ffffff6c,puVar6),
                              CONCAT44(in_stack_ffffff74,in_stack_ffffff70));
            printf("\rlibscan: scanning eraseblock %d -- %2lld %% complete  ",eb,(int)DVar15,
                   (int)((ulonglong)DVar15 >> 0x20));
            fflush(stdout);
          }
          iVar12 = mtd_is_bad(mtd,fd,(int)eb);
          if (iVar12 == -1) {
out_ec:
            free(__ptr->ec);
            goto out_si;
          }
          in_stack_ffffff68 = &ech;
          if (iVar12 == 0) {
            in_stack_ffffff6c = (ubi_ec_hdr *)0x40;
[32m            iVar12 = mtd_read(mtd,fd,(int)eb,0,in_stack_ffffff68,0x40);[0m
            if (iVar12 < 0) goto out_ec;
            puVar6 = &ech;
            if ((ech.magic >> 0x18 | ech.magic << 0x18 | (ech.magic & 0xff00) << 8 |
                (ech.magic & 0xff0000) >> 8) == 0x55424923) {
              local_34 = 0xff0000;
              uVar7 = mtd_crc32(0xffffffff,&ech,0x3c);
              if ((ech.hdr_crc >> 0x18 | ech.hdr_crc << 0x18 | (ech.hdr_crc & 0xff00) << 8 |
                  (ech.hdr_crc & local_34) >> 8) == uVar7) {
                uVar11 = (uint)ech.ec >> 0x18 |
                         (uint)ech.ec << 0x18 | ((uint)ech.ec & 0xff00) << 8 |
                         ((uint)ech.ec & local_34) >> 8;
                uVar9 = ech.ec._4_4_ >> 0x18 | ech.ec._4_4_ << 0x18 | (ech.ec._4_4_ & 0xff00) << 8 |
                        (ech.ec._4_4_ & local_34) >> 8;
                if ((uVar11 != 0) || (0x7fffffff < uVar9)) {
                  if (local_38 != 0) {
                    local_34 = uVar9;
                    local_30 = uVar11;
                    putchar(10);
                    uVar9 = local_34;
                    uVar11 = local_30;
                  }
                  fprintf(stderr,
                          "%s: error!: erase counter in EB %d is %llu, while this program expects them to be less than %u\n"
                          ,"libscan",eb,uVar9,uVar11,0x7fffffff);
                  goto out_ec;
                }
                if (__ptr->vid_hdr_offs == 0xffffffff) {
                  iVar12 = mtd->min_io_size;
                  uVar11 = ech.data_offset >> 0x18 | ech.data_offset << 0x18 |
                           (ech.data_offset & 0xff00) << 8 | (ech.data_offset & local_34) >> 8;
                  if (iVar12 == 0) {
                    trap(0x1c00);
                  }
                  __ptr->vid_hdr_offs =
                       ech.vid_hdr_offset >> 0x18 | ech.vid_hdr_offset << 0x18 |
                       (ech.vid_hdr_offset & 0xff00) << 8 | (ech.vid_hdr_offset & local_34) >> 8;
                  __ptr->data_offs = uVar11;
                  if ((int)uVar11 % iVar12 == 0) {
LAB_004054f0:
                    __ptr->ok_cnt = __ptr->ok_cnt + 1;
                    *(uint *)((int)__ptr->ec + iVar13) = uVar9;
                    if (bVar1) {
                      printf(": OK, erase counter %u\n");
                    }
                    goto LAB_00404eec;
                  }
                  if (local_38 != 0) {
                    putchar(10);
                  }
                  if (bVar1) {
                    puts(": corrupted because of the below");
                  }
                  in_stack_ffffff6c = (ubi_ec_hdr *)mtd->min_io_size;
                  iVar12 = __ptr->data_offs;
                  pcVar10 = 
                  "%s: warning!: bad data offset %d at eraseblock %d (nof multiple of min. I/O unit size %d)\n"
                  ;
                  in_stack_ffffff68 = eb;
                }
                else if (__ptr->vid_hdr_offs ==
                         (ech.vid_hdr_offset >> 0x18 | ech.vid_hdr_offset << 0x18 |
                          (ech.vid_hdr_offset & 0xff00) << 8 | (ech.vid_hdr_offset & local_34) >> 8)
                        ) {
                  if ((ech.data_offset >> 0x18 | ech.data_offset << 0x18 |
                       (ech.data_offset & 0xff00) << 8 | (ech.data_offset & local_34) >> 8) ==
                      __ptr->data_offs) goto LAB_004054f0;
                  if (local_38 != 0) {
                    putchar(10);
                  }
                  if (bVar1) {
                    puts(": corrupted because of the below");
                  }
                  iVar12 = __ptr->data_offs;
                  pcVar10 = 
                  "%s: warning!: inconsistent data offset: was %d, but is %d in eraseblock %d\n";
                  in_stack_ffffff68 =
                       (ubi_ec_hdr *)
                       (ech.data_offset >> 0x18 | ech.data_offset << 0x18 |
                        (ech.data_offset & 0xff00) << 8 | ech.data_offset >> 8 & 0xff00);
                  in_stack_ffffff6c = eb;
                }
                else {
                  if (local_38 != 0) {
                    putchar(10);
                  }
                  if (bVar1) {
                    puts(": corrupted because of the below");
                  }
                  iVar12 = __ptr->vid_hdr_offs;
                  pcVar10 = 
                  "%s: warning!: inconsistent VID header offset: was %d, but is %d in eraseblock %d\n"
                  ;
                  in_stack_ffffff68 =
                       (ubi_ec_hdr *)
                       (ech.vid_hdr_offset >> 0x18 | ech.vid_hdr_offset << 0x18 |
                        (ech.vid_hdr_offset & 0xff00) << 8 | ech.vid_hdr_offset >> 8 & 0xff00);
                  in_stack_ffffff6c = eb;
                }
                fprintf(stderr,pcVar10,"libscan",iVar12);
                fprintf(stderr,"%s: warning!: treat eraseblock %d as corrupted\n","libscan",eb);
                __ptr->corrupted_cnt = __ptr->corrupted_cnt + 1;
                *(undefined4 *)((int)__ptr->ec + iVar13) = 0xfffffffe;
              }
              else {
                __ptr->corrupted_cnt = __ptr->corrupted_cnt + 1;
                *(undefined4 *)((int)__ptr->ec + iVar13) = 0xfffffffe;
                if (bVar1) {
                  printf(": bad CRC %#08x, should be %#08x\n",uVar7,
                         ech.hdr_crc >> 0x18 | ech.hdr_crc << 0x18 | (ech.hdr_crc & 0xff00) << 8 |
                         (ech.hdr_crc & local_34) >> 8);
                }
              }
            }
            else {
              do {
                p_Var2 = &puVar6->magic;
                puVar6 = (ubi_ec_hdr *)((int)&puVar6->magic + 1);
                if (*(char *)p_Var2 != -1) {
                  __ptr->alien_cnt = __ptr->alien_cnt + 1;
                  *(undefined4 *)((int)__ptr->ec + iVar13) = 0xfffffffd;
                  if (bVar1) {
                    puts(": alien");
                  }
                  goto LAB_00404eec;
                }
              } while (puVar6 != (ubi_ec_hdr *)&local_38);
              __ptr->empty_cnt = __ptr->empty_cnt + 1;
              *(undefined4 *)((int)__ptr->ec + iVar13) = 0xffffffff;
              if (bVar1) {
                puts(": empty");
              }
            }
          }
          else {
            __ptr->bad_cnt = __ptr->bad_cnt + 1;
            *(undefined4 *)((int)__ptr->ec + iVar13) = 0xfffffffc;
            in_stack_ffffff68 = puVar6;
            if (bVar1) {
              puts(": bad");
              in_stack_ffffff68 = puVar6;
            }
          }
LAB_00404eec:
          iVar12 = mtd->eb_cnt;
          eb = (ubi_ec_hdr *)((int)&eb->magic + 1);
          iVar13 = iVar13 + 4;
        } while ((int)eb < iVar12);
      }
      iVar13 = __ptr->ok_cnt;
      if (iVar13 != 0) {
        if (0 < iVar12) {
          iVar5 = 0;
          do {
            iVar5 = iVar5 + 1;
          } while (iVar5 != iVar12);
        }
        UVar14 = __udivdi3(CONCAT44(in_stack_ffffff6c,in_stack_ffffff68),
                           CONCAT44(in_stack_ffffff74,in_stack_ffffff70));
        __ptr->mean_ec = UVar14;
      }
      __ptr->good_cnt = iVar12 - __ptr->bad_cnt;
      if (bVar1) {
        printf("%s: finished, mean EC %lld, %d OK, %d corrupted, %d empty, %d alien, bad %d\n",
               "libscan",*(undefined4 *)&__ptr->mean_ec,*(undefined4 *)((int)&__ptr->mean_ec + 4),
               iVar13,__ptr->corrupted_cnt,__ptr->empty_cnt,__ptr->alien_cnt,__ptr->bad_cnt);
      }
      iVar12 = 0;
      *info = __ptr;
      if (local_38 != 0) {
        putchar(10);
      }
    }
  }
  return iVar12;
}

[ASK_GPT] cc64609d966bba8d
