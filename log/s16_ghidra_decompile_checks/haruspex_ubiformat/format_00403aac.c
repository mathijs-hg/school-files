
int format(libmtd_t libmtd,mtd_dev_info *mtd,ubigen_info *ui,ubi_scan_info *si,int start_eb,
          int novtbl)

{
  FILE *pFVar1;
  int iVar2;
  ubi_ec_hdr *hdr;
  int iVar3;
  int *piVar4;
  ubi_vtbl_record *__ptr;
  char *pcVar5;
  uint uVar6;
  ubi_vtbl_record *vtbl;
  int iVar7;
  size_t __size;
  DItype DVar8;
  int in_stack_ffffff88;
  ubi_ec_hdr *in_stack_ffffff8c;
  size_t in_stack_ffffff90;
  undefined4 in_stack_ffffff94;
  undefined4 local_58;
  ubi_vtbl_record *local_50;
  ubi_vtbl_record *local_48;
  int local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  
  iVar2 = mtd->subpage_size;
  if (iVar2 == 0) {
    trap(0x1c00);
  }
[32m  __size = iVar2 * ((iVar2 + 0x3f) / iVar2);[0m
  vtbl = (ubi_vtbl_record *)si;
[32m[32m  hdr = (ubi_ec_hdr *)malloc(__size);[0m[0m
  if (hdr == (ubi_ec_hdr *)0x0) {
    piVar4 = __errno_location();
    iVar2 = *piVar4;
    fprintf(stderr,"%s: error!: cannot allocate %d bytes of memory\n","ubiformat",__size);
    pFVar1 = stderr;
    pcVar5 = strerror(iVar2);
    fprintf(pFVar1,"%*serror %d (%s)\n",0xb,&DAT_0040e38c,iVar2,pcVar5);
    return -1;
  }
  memset(hdr,0xff,__size);
  if (start_eb < mtd->eb_cnt) {
    iVar2 = start_eb << 2;
    local_34 = 0xffffffff;
    local_3c = 0xffffffff;
    local_38 = -1;
    local_40 = -1;
    local_48 = (ubi_vtbl_record *)0xffffffff;
    local_50 = (ubi_vtbl_record *)0xffffffff;
    uVar6 = args._0_4_;
    do {
      while( true ) {
        if ((uVar6 & 6) == 0) {
          DVar8 = __divdi3(CONCAT44(in_stack_ffffff8c,in_stack_ffffff88),
                           CONCAT44(in_stack_ffffff94,in_stack_ffffff90));
          vtbl = (ubi_vtbl_record *)((ulonglong)DVar8 >> 0x20);
          printf("\rubiformat: formatting eraseblock %d -- %2lld %% complete  ",start_eb,(int)DVar8)
          ;
          fflush(stdout);
          uVar6 = args._0_4_;
        }
        iVar7 = *(int *)((int)si->ec + iVar2);
        if (iVar7 != -4) break;
LAB_00403cd8:
        start_eb = (int)(uint32_t **)start_eb + 1;
        iVar2 = iVar2 + 4;
        if (mtd->eb_cnt <= start_eb) goto LAB_00403ed8;
      }
      if ((uVar6 & 8) == 0) {
        if (iVar7 < 0) {
          local_58 = *(undefined4 *)((int)&si->mean_ec + 4);
          iVar7 = *(int *)&si->mean_ec;
        }
        else {
          local_58 = 0;
          iVar7 = iVar7 + 1;
        }
      }
      else {
        local_58 = args.ec._4_4_;
        iVar7 = (int)args.ec;
      }
      ubigen_init_ec_hdr(ui,hdr,CONCAT44(in_stack_ffffff8c,in_stack_ffffff88));
      if ((args._0_4_ & 4) != 0) {
        printf("%s: eraseblock %d: erase","ubiformat",start_eb);
        fflush(stdout);
      }
      vtbl = (ubi_vtbl_record *)start_eb;
      iVar3 = mtd_erase(libmtd,mtd,args.node_fd,start_eb);
      if (iVar3 != 0) {
        if ((args._0_4_ & 2) == 0) {
          putchar(10);
        }
        piVar4 = __errno_location();
        in_stack_ffffff88 = *piVar4;
        fprintf(stderr,"%s: error!: failed to erase eraseblock %d\n","ubiformat",start_eb);
        pFVar1 = stderr;
        in_stack_ffffff8c = (ubi_ec_hdr *)strerror(in_stack_ffffff88);
        vtbl = (ubi_vtbl_record *)&DAT_0040e38c;
        fprintf(pFVar1,"%*serror %d (%s)\n",0xb);
        if (*piVar4 == 5) {
          iVar7 = mark_bad(mtd,si,start_eb);
          uVar6 = args._0_4_;
joined_r0x00403ccc:
          args._0_4_ = uVar6;
          if (iVar7 == 0) goto LAB_00403cd8;
        }
        goto out_free;
      }
      if (((local_50 == (ubi_vtbl_record *)0xffffffff) ||
          (local_48 == (ubi_vtbl_record *)0xffffffff)) && (novtbl == 0)) {
        if (local_50 == (ubi_vtbl_record *)0xffffffff) {
          local_3c = local_58;
          local_50 = (ubi_vtbl_record *)start_eb;
          local_40 = iVar7;
        }
        else if (local_48 == (ubi_vtbl_record *)0xffffffff) {
          local_34 = local_58;
          local_48 = (ubi_vtbl_record *)start_eb;
          local_38 = iVar7;
        }
        uVar6 = args._0_4_;
        if ((args._0_4_ & 4) != 0) {
          puts(", do not write EC, leave for vtbl");
          uVar6 = args._0_4_;
        }
        goto LAB_00403cd8;
      }
      if ((args._0_4_ & 4) != 0) {
        printf(", write EC %lld\n");
        fflush(stdout);
      }
      in_stack_ffffff88 = 0;
      in_stack_ffffff94 = 0;
      vtbl = (ubi_vtbl_record *)start_eb;
      in_stack_ffffff8c = hdr;
      in_stack_ffffff90 = __size;
[32m      iVar7 = mtd_write(libmtd,mtd,args.node_fd,start_eb,0,hdr,__size,(void *)0x0,0,'\0');[0m
      if (iVar7 != 0) {
        if ((args._0_4_ & 6) == 0) {
          putchar(10);
        }
        piVar4 = __errno_location();
        in_stack_ffffff88 = *piVar4;
        fprintf(stderr,"%s: error!: cannot write EC header (%d bytes buffer) to eraseblock %d\n",
                "ubiformat",__size,start_eb);
        pFVar1 = stderr;
        in_stack_ffffff8c = (ubi_ec_hdr *)strerror(in_stack_ffffff88);
        fprintf(pFVar1,"%*serror %d (%s)\n",0xb,&DAT_0040e38c);
        if (*piVar4 != 5) {
          if (args.subpage_size != mtd->min_io_size) {
            printf("%s: may be sub-page size is incorrect?\n","ubiformat");
          }
          goto out_free;
        }
        vtbl = (ubi_vtbl_record *)start_eb;
        iVar7 = mtd_torture(libmtd,mtd,args.node_fd,start_eb);
        if (iVar7 != 0) {
          iVar7 = mark_bad(mtd,si,start_eb);
          uVar6 = args._0_4_;
          goto joined_r0x00403ccc;
        }
      }
      start_eb = (int)(uint32_t **)start_eb + 1;
      iVar2 = iVar2 + 4;
      uVar6 = args._0_4_;
    } while (start_eb < mtd->eb_cnt);
  }
  else {
    local_38 = -1;
    local_3c = 0xffffffff;
    local_34 = 0xffffffff;
    local_40 = -1;
    local_48 = (ubi_vtbl_record *)0xffffffff;
    local_50 = (ubi_vtbl_record *)0xffffffff;
  }
LAB_00403ed8:
  if ((args._0_4_ & 6) == 0) {
    putchar(10);
  }
  if (novtbl == 0) {
    if ((local_50 == (ubi_vtbl_record *)0xffffffff) || (local_48 == (ubi_vtbl_record *)0xffffffff))
    {
      fprintf(stderr,"%s: error!: no eraseblocks for volume table\n","ubiformat");
    }
    else {
      if ((args._0_4_ & 4) != 0) {
        vtbl = local_48;
        printf("%s: write volume table to eraseblocks %d and %d\n","ubiformat",local_50);
      }
      __ptr = ubigen_create_empty_vtbl(ui);
      if (__ptr != (ubi_vtbl_record *)0x0) {
        iVar2 = ubigen_write_layout_vol
                          (ui,(int)local_50,(int)local_48,CONCAT44(local_3c,local_40),
                           CONCAT44(local_34,local_38),vtbl,(int)__ptr);
        free(__ptr);
        if (iVar2 == 0) goto LAB_00403fb8;
        fprintf(stderr,"%s: error!: cannot write layout volume\n","ubiformat");
      }
    }
out_free:
    free(hdr);
    iVar2 = -1;
  }
  else {
LAB_00403fb8:
    free(hdr);
    iVar2 = 0;
  }
  return iVar2;
}

[ASK_GPT] efe148ade77a4a1f
