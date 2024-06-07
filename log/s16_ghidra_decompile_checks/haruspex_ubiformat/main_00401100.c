
/* WARNING: Removing unreachable block (ram,0x004023e8) */
/* WARNING: Removing unreachable block (ram,0x0040146c) */

int main(int argc,char **argv)

{
  bool bVar1;
  FILE *__stream;
  ubi_scan_info *puVar2;
  _Bool _Var3;
  libmtd_t desc;
  uint32_t uVar4;
  int iVar5;
  uint uVar6;
  libubi_t desc_00;
  SItype SVar7;
  undefined3 extraout_var;
  int *piVar8;
  undefined def;
  char *pcVar9;
  int iVar10;
  SItype arg_a;
  FLO_type in_f12_13;
  FLO_type in_f14_15;
  longlong lVar11;
  ulonglong uVar12;
  ulonglong in_stack_fffffe70;
  char *local_178;
  int local_174;
  ubi_scan_info *local_170;
  mtd_info mtd_info;
  ubigen_info ui;
  mtd_dev_info mtd;
  
[32m  desc = libmtd_open();[0m
  if (desc != (libmtd_t)0x0) {
[32m    ubiutils_srand();[0m
[32m[32m    uVar4 = rand();[0m[0m
    args.ec = CONCAT44(args.ec._4_4_,(undefined4)args.ec);
    args.image_sz = CONCAT44(args.image_sz._4_4_,(undefined4)args.image_sz);
LAB_0040118c:
    while( true ) {
      args.image_seq = uVar4;
      local_174 = 0;
      in_stack_fffffe70 = in_stack_fffffe70 & 0xffffffff00000000;
[32m      iVar5 = getopt_long(argc,argv,"nh?Vyqve:x:s:O:f:S:",long_options);[0m
      pcVar9 = optarg;
      if (iVar5 == -1) break;
      uVar4 = args.image_seq;
      switch(iVar5) {
      case 0x3a:
        fprintf(stderr,"%s: error!: parameter is missing\n","ubiformat");
        goto out_close_mtd;
      default:
        fwrite("Use -h for help\n",1,0x10,stderr);
        goto out_close_mtd;
      case 0x3f:
      case 0x68:
        printf("%s\n\n",
               "ubiformat version 1.5.2 - a tool to format MTD devices and flash UBI images");
        printf("%s\n\n",
               "Usage: ubiformat <MTD device node file name> [-s <bytes>] [-O <offs>] [-n]\n\t\t\t[-Q <num>] [-f <file>] [-S <bytes>] [-e <value>] [-x <num>] [-y] [-q] [-v] [-h]\n\t\t\t[--sub-page-size=<bytes>] [--vid-hdr-offset=<offs>] [--no-volume-table]\n\t\t\t[--flash-image=<file>] [--image-size=<bytes>] [--erase-counter=<value>]\n\t\t\t[--image-seq=<num>] [--ubi-ver=<num>] [--yes] [--quiet] [--verbose]\n\t\t\t[--help] [--version]\n\nExample 1: ubiformat /dev/mtd0 -y - format MTD device number 0 and do\n           not ask questions.\nExample 2: ubiformat /dev/mtd0 -q -e 0 - format MTD device number 0,\n           be quiet and force erase counter value 0."
              );
        puts(
            "-s, --sub-page-size=<bytes>  minimum input/output unit used for UBI\n                             headers, e.g. sub-page size in case of NAND\n                             flash (equivalent to the minimum input/output\n                             unit size by default)\n-O, --vid-hdr-offset=<offs>  offset if the VID header from start of the\n                             physical eraseblock (default is the next\n                             minimum I/O unit or sub-page after the EC\n                             header)\n-n, --no-volume-table        only erase all eraseblock and preserve erase\n                             counters, do not write empty volume table\n-f, --flash-image=<file>     flash image file, or \'-\' for stdin\n-S, --image-size=<bytes>     bytes in input, if not reading from file\n-e, --erase-counter=<value>  use <value> as the erase counter value for all\n                             eraseblocks\n-x, --ubi-ver=<num>          UBI version number to put to EC headers\n                             (default is 1)\n-Q, --image-seq=<num>        32-bit UBI image sequence number to use\n                             (by default a random number is picked)\n-y, --yes                    assume the answer is \"yes\" for all question\n                             this program would otherwise ask\n-q, --quiet                  suppress progress percentage information\n-v, --verbose                be verbose\n-h, -?, --help               print help message\n-V, --version                print program version\n"
            );
                    /* WARNING: Subroutine does not return */
        exit(0);
      case 0x4f:
        args.vid_hdr_offs = simple_strtoul(optarg,&local_174);
        if ((local_174 != 0) || (uVar4 = args.image_seq, args.vid_hdr_offs < 1)) {
          fprintf(stderr,"%s: error!: bad VID header offset: \"%s\"\n","ubiformat",optarg);
          goto out_close_mtd;
        }
        break;
      case 0x51:
        uVar4 = simple_strtoul(optarg,&local_174);
        if (local_174 != 0) {
          fprintf(stderr,"%s: error!: bad UBI image sequence number: \"%s\"\n","ubiformat",optarg);
          goto out_close_mtd;
        }
        break;
      case 0x53:
        lVar11 = ubiutils_get_bytes(optarg);
        uVar4 = args.image_seq;
        args.image_sz = lVar11;
        if (lVar11 < 1) {
          fprintf(stderr,"%s: error!: bad image-size: \"%s\"\n","ubiformat",optarg);
          goto out_close_mtd;
        }
        break;
      case 0x56:
        printf("%s %s\n","ubiformat","1.5.2");
                    /* WARNING: Subroutine does not return */
        exit(0);
      case 0x65:
        uVar12 = strtoull(optarg,&local_178,0);
        if ((*pcVar9 == '\0') || (*local_178 != '\0')) {
          in_stack_fffffe70 = in_stack_fffffe70 & 0xffffffff00000000 | ZEXT48(pcVar9);
          fprintf(stderr,"%s: error!: %s: unable to parse the number \'%s\'\n","ubiformat",
                  "strtoull",pcVar9);
          local_174 = 1;
        }
        args.ec = uVar12;
        if ((local_174 != 0) || ((longlong)uVar12 < 0)) {
          fprintf(stderr,"%s: error!: bad erase counter value: \"%s\"\n","ubiformat",optarg,
                  in_stack_fffffe70);
          goto out_close_mtd;
        }
        if (0x7ffffffe < (longlong)uVar12) {
          fprintf(stderr,"%s: error!: too high erase %llu, counter, max is %u\n","ubiformat");
          goto out_close_mtd;
        }
        args._0_4_ = args._0_4_ | 8;
        uVar4 = args.image_seq;
        break;
      case 0x66:
        args.image = optarg;
        break;
      case 0x6e:
        args._0_4_ = args._0_4_ | 0x10;
        break;
      case 0x71:
        args._0_4_ = args._0_4_ | 2;
        break;
      case 0x73:
        lVar11 = ubiutils_get_bytes(optarg);
        args.subpage_size = (int)lVar11;
        if (args.subpage_size < 1) {
          fprintf(stderr,"%s: error!: bad sub-page size: \"%s\"\n","ubiformat",optarg);
          goto out_close_mtd;
        }
        uVar4 = args.image_seq;
        if ((args.subpage_size - 1U & args.subpage_size |
            (uint)(args.subpage_size - 1U < (uint)args.subpage_size) +
            ((args.subpage_size >> 0x1f) - 1U) & args.subpage_size >> 0x1f) != 0) {
          fprintf(stderr,"%s: error!: sub-page size should be power of 2\n","ubiformat");
          goto out_close_mtd;
        }
        break;
      case 0x76:
        args._0_4_ = args._0_4_ | 4;
        break;
      case 0x78:
        goto switchD_00401200_caseD_78;
      case 0x79:
        args._0_4_ = args._0_4_ | 1;
      }
    }
    if ((args._0_4_ & 6) == 6) {
      fprintf(stderr,"%s: error!: using \"-q\" and \"-v\" at the same time does not make sense\n",
              "ubiformat");
      goto out_close_mtd;
    }
    if (argc == optind) {
      fprintf(stderr,"%s: error!: MTD device name was not specified (use -h for help)\n","ubiformat"
             );
      goto out_close_mtd;
    }
    if (optind != argc + -1) {
      fprintf(stderr,"%s: error!: more then one MTD device specified (use -h for help)\n",
              "ubiformat");
      goto out_close_mtd;
    }
    if ((args.image != (char *)0x0) && ((args._0_4_ & 0x10) != 0)) {
      fprintf(stderr,"%s: error!: -n cannot be used together with -f\n","ubiformat");
      goto out_close_mtd;
    }
    args.node = argv[optind];
    iVar5 = mtd_get_info(desc,&mtd_info);
    if (iVar5 != 0) {
      piVar8 = __errno_location();
      iVar5 = *piVar8;
      if (iVar5 == 0x13) {
        fprintf(stderr,"%s: error!: MTD is not present\n","ubiformat");
        iVar5 = *piVar8;
      }
      fprintf(stderr,"%s: error!: cannot get MTD information\n","ubiformat");
LAB_00402154:
      __stream = stderr;
      pcVar9 = strerror(iVar5);
      fprintf(__stream,"%*serror %d (%s)\n",0xb,&DAT_0040e38c,iVar5,pcVar9);
      goto out_close_mtd;
    }
    iVar5 = mtd_get_dev_info(desc,args.node,&mtd);
    if (iVar5 != 0) {
      piVar8 = __errno_location();
      iVar5 = *piVar8;
      pcVar9 = "%s: error!: cannot get information about \"%s\"\n";
LAB_00402260:
      fprintf(stderr,pcVar9,"ubiformat",args.node);
      goto LAB_00402154;
    }
    uVar6 = mtd.min_io_size >> 0x1f;
    if (((mtd.min_io_size | uVar6) == 0) ||
       ((mtd.min_io_size - 1U & mtd.min_io_size |
        (uint)(mtd.min_io_size - 1U < (uint)mtd.min_io_size) + (uVar6 - 1) & uVar6) != 0)) {
      fprintf(stderr,"%s: error!: min. I/O size is %d, but should be power of 2\n","ubiformat");
      goto out_close_mtd;
    }
    if ((mtd_info._12_4_ & 1) == 0) {
      if (args.subpage_size == 0) {
        fprintf(stderr,
                "%s: warning!: your MTD system is old and it is impossible to detect sub-page size. Use -s to get rid of this warning\n"
                ,"ubiformat");
        printf("%s: assume sub-page to be %d\n","ubiformat",mtd.subpage_size);
        goto LAB_00401bf8;
      }
LAB_004016ec:
      mtd.subpage_size = args.subpage_size;
      args.manual_subpage = 1;
LAB_004016f8:
      if (mtd.min_io_size < args.subpage_size) {
        fprintf(stderr,"%s: error!: sub-page cannot be larger than min. I/O unit\n","ubiformat");
        goto out_close_mtd;
      }
      if (args.subpage_size == 0) {
        trap(0x1c00);
      }
      if (mtd.min_io_size % args.subpage_size != 0) {
        fprintf(stderr,"%s: error!: min. I/O unit size should be multiple of sub-page size\n",
                "ubiformat");
        goto out_close_mtd;
      }
    }
    else {
      if ((args.subpage_size != 0) && (args.subpage_size != mtd.subpage_size)) goto LAB_004016ec;
LAB_00401bf8:
      if (args.manual_subpage != 0) goto LAB_004016f8;
    }
[32m    args.node_fd = open64(args.node,2);[0m
    if (args.node_fd == -1) {
      piVar8 = __errno_location();
      iVar5 = *piVar8;
      pcVar9 = "%s: error!: cannot open \"%s\"\n";
      goto LAB_00402260;
    }
    if (args.vid_hdr_offs != 0) {
      if ((args.vid_hdr_offs & 7U) != 0) {
        fprintf(stderr,"%s: error!: VID header offset has to be multiple of min. I/O unit size\n",
                "ubiformat");
        goto out_close;
      }
      if (mtd.eb_size <= args.vid_hdr_offs + 0x3f) {
        fprintf(stderr,"%s: error!: bad VID header offset\n","ubiformat");
        goto out_close;
      }
    }
    if ((mtd._248_4_ & 1) == 0) {
      pcVar9 = "%s: error!: mtd%d (%s) is a read-only device\n";
      uVar12 = in_stack_fffffe70 & 0xffffffff00000000 | ZEXT48(args.node);
LAB_004021c8:
      fprintf(stderr,pcVar9,"ubiformat",mtd.mtd_num,uVar12);
    }
    else {
[32m      desc_00 = libubi_open();[0m
      if (desc_00 != (libubi_t)0x0) {
        iVar5 = mtd_num2ubi_dev(desc_00,mtd.mtd_num,&local_174);
        libubi_close(desc_00);
        if (iVar5 == 0) {
          pcVar9 = "%s: error!: please, first detach mtd%d (%s) from ubi%d\n";
          uVar12 = CONCAT44(local_174,args.node);
          goto LAB_004021c8;
        }
      }
      iVar5 = 0;
      if ((args._0_4_ & 2) == 0) {
        printf("%s: mtd%d (%s), size ","ubiformat",mtd.mtd_num,mtd.type_str);
        ubiutils_print_bytes(in_stack_fffffe70,(int)mtd.size);
        printf(", %d eraseblocks of ",mtd.eb_cnt);
        ubiutils_print_bytes(in_stack_fffffe70,mtd.eb_size);
        printf(", min. I/O size %d bytes\n",mtd.min_io_size);
        if ((args._0_4_ & 2) == 0) {
          iVar5 = 2 - (uint)((args._0_4_ & 4) == 0);
        }
      }
      iVar5 = ubi_scan(&mtd,args.node_fd,&local_170,iVar5);
      if (iVar5 != 0) {
        pcVar9 = "%s: error!: failed to scan mtd%d (%s)\n";
        uVar12 = in_stack_fffffe70 & 0xffffffff00000000 | ZEXT48(args.node);
        goto LAB_004021c8;
      }
      iVar5 = local_170->good_cnt;
      if (iVar5 == 0) {
        fprintf(stderr,"%s: error!: all %d eraseblocks are bad\n","ubiformat",local_170->bad_cnt);
      }
      else if ((iVar5 < 2) && (((args._0_4_ & 0x10) == 0 || (args.image != (char *)0x0)))) {
        fprintf(stderr,"%s: error!: too few non-bad eraseblocks (%d) on mtd%d\n","ubiformat",iVar5,
                mtd.mtd_num);
      }
      else {
        if ((args._0_4_ & 2) == 0) {
          if (local_170->ok_cnt != 0) {
            printf("%s: %d eraseblocks have valid erase counter, mean value is %lld\n","ubiformat",
                   local_170->ok_cnt,local_170,*(undefined4 *)&local_170->mean_ec);
          }
          if (local_170->empty_cnt != 0) {
            printf("%s: %d eraseblocks are supposedly empty\n","ubiformat");
          }
          if (local_170->corrupted_cnt != 0) {
            printf("%s: %d corrupted erase counters\n","ubiformat");
          }
          puVar2 = local_170;
          if (local_170->bad_cnt != 0) {
            printf("%s: %d bad eraseblocks found, numbers: ","ubiformat");
            iVar10 = 0;
            bVar1 = true;
            iVar5 = mtd.eb_cnt;
            while (iVar10 < iVar5) {
              if (puVar2->ec[iVar10] == 0xfffffffc) {
                if (bVar1) {
                  printf("%d",iVar10);
                  bVar1 = false;
                  iVar10 = iVar10 + 1;
                  iVar5 = mtd.eb_cnt;
                }
                else {
                  printf(", %d",iVar10);
                  iVar10 = iVar10 + 1;
                  iVar5 = mtd.eb_cnt;
                }
              }
              else {
                iVar10 = iVar10 + 1;
              }
            }
            putchar(10);
          }
        }
        if (local_170->alien_cnt == 0) {
LAB_004018ec:
          uVar6 = args._0_4_;
          if (((args._0_4_ & 8) == 0) && (iVar5 = local_170->good_cnt, local_170->empty_cnt < iVar5)
             ) {
            arg_a = local_170->ok_cnt;
            __floatsidf(arg_a);
            __floatsidf(iVar5);
            __divdf3(in_f12_13,in_f14_15);
            __muldf3(in_f12_13,in_f14_15);
            SVar7 = __fixdfsi(in_f12_13);
            if (SVar7 < 0x32) {
              if ((uVar6 & 3) != 3) {
                fprintf(stderr,"%s: warning!: only %d of %d eraseblocks have valid erase counter\n",
                        "ubiformat",arg_a,iVar5);
                printf("%s: erase counter 0 will be used for all eraseblocks\n","ubiformat");
                printf("%s: note, arbitrary erase counter value may be specified using -e option\n",
                       "ubiformat");
              }
              if ((args._0_4_ & 1) == 0) {
                iVar5 = want_exit();
                if (iVar5 != 0) goto LAB_00401ea0;
              }
              args._0_4_ = args._0_4_ | 8;
              args.ec = 0;
            }
            else if (SVar7 < 0x5f) {
              if ((uVar6 & 3) != 3) {
                fprintf(stderr,"%s: warning!: only %d of %d eraseblocks have valid erase counter\n",
                        "ubiformat",arg_a,iVar5);
                printf("%s: mean erase counter %lld will be used for the rest of eraseblock\n",
                       "ubiformat",*(undefined4 *)&local_170->mean_ec,
                       *(undefined4 *)((int)&local_170->mean_ec + 4));
              }
              if ((args._0_4_ & 1) == 0) {
                iVar5 = want_exit();
                if (iVar5 != 0) goto LAB_00401ea0;
              }
              args.ec = local_170->mean_ec;
              args._0_4_ = args._0_4_ | 8;
            }
          }
          args.ec._4_4_ = (undefined4)((ulonglong)args.ec >> 0x20);
          if ((args._0_4_ & 10) == 8) {
            printf("%s: use erase counter %lld for all eraseblocks\n","ubiformat",
                   (undefined4)args.ec,args.ec._4_4_);
          }
          iVar5 = mtd.eb_size;
          ubigen_info_init(&ui,mtd.eb_size,mtd.min_io_size,mtd.subpage_size,args.vid_hdr_offs,
                           args.ubi_ver,args.image_seq);
          def = (undefined)iVar5;
          iVar5 = local_170->vid_hdr_offs;
          if ((iVar5 != -1) && (iVar5 != ui.vid_hdr_offs)) {
            if ((args._0_4_ & 3) != 3) {
              fprintf(stderr,
                      "%s: warning!: VID header and data offsets on flash are %d and %d, which is different to requested offsets %d and %d\n"
                      ,"ubiformat",iVar5,local_170->data_offs,ui.vid_hdr_offs,ui.data_offs);
              def = 0xe4;
              printf("%s: use new offsets %d and %d? ","ubiformat",ui.vid_hdr_offs,ui.data_offs);
            }
            if ((args._0_4_ & 1) == 0) {
              _Var3 = prompt("continue?",(_Bool)def);
              if (CONCAT31(extraout_var,_Var3) != 0) goto LAB_00401ae0;
              ubigen_info_init(&ui,mtd.eb_size,mtd.min_io_size,0,local_170->vid_hdr_offs,
                               args.ubi_ver,args.image_seq);
            }
            else {
LAB_00401ae0:
              if ((args._0_4_ & 3) == 1) {
                puts("yes");
              }
            }
            printf("%s: use offsets %d and %d\n","ubiformat",ui.vid_hdr_offs,ui.data_offs);
          }
          if (args.image == (char *)0x0) {
            iVar5 = format(desc,&mtd,&ui,local_170,0,args._0_4_ >> 4 & 1);
          }
          else {
            iVar5 = flash_image(desc,&mtd,&ui,local_170);
            if (iVar5 < 0) goto out_free;
            iVar5 = format(desc,&mtd,&ui,local_170,iVar5,1);
          }
          if (iVar5 == 0) {
            ubi_scan_free(local_170);
            close(args.node_fd);
            libmtd_close(desc);
            iVar5 = 0;
            goto LAB_004015cc;
          }
        }
        else {
          if ((args._0_4_ & 3) != 3) {
            fprintf(stderr,"%s: warning!: %d of %d eraseblocks contain non-UBI data\n","ubiformat",
                    local_170->alien_cnt,local_170->good_cnt);
          }
          if ((args._0_4_ & 1) != 0) goto LAB_004018ec;
          iVar5 = want_exit();
          if (iVar5 == 0) goto LAB_004018ec;
LAB_00401ea0:
          if ((args._0_4_ & 3) == 1) {
            puts("yes");
          }
        }
      }
out_free:
      ubi_scan_free(local_170);
    }
out_close:
    close(args.node_fd);
    goto out_close_mtd;
  }
  fprintf(stderr,"%s: error!: MTD subsystem is not present\n","ubiformat");
  iVar5 = -1;
LAB_004015cc:
  args.ec._4_4_ = (undefined4)((ulonglong)args.ec >> 0x20);
  args.image_sz._4_4_ = (undefined4)((ulonglong)args.image_sz >> 0x20);
  return iVar5;
switchD_00401200_caseD_78:
  args.ubi_ver = simple_strtoul(optarg,&local_174);
  if ((local_174 != 0) || (uVar4 = args.image_seq, args.ubi_ver < 0)) goto LAB_00401248;
  goto LAB_0040118c;
LAB_00401248:
  fprintf(stderr,"%s: error!: bad UBI version: \"%s\"\n","ubiformat",optarg);
out_close_mtd:
  libmtd_close(desc);
  iVar5 = -1;
  goto LAB_004015cc;
}

[ASK_GPT] f86971734fbbfadd
