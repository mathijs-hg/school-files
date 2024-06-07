
/* WARNING: Could not reconcile some variable overlaps */

int legacy_get_dev_info(char *node,mtd_dev_info *mtd)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  FILE *pFVar7;
  DItype DVar8;
  int in_stack_fffffe60;
  char *in_stack_fffffe64;
  undefined4 in_stack_fffffe68;
  undefined4 in_stack_fffffe6c;
  loff_t offs;
  mtd_info_user ui;
  proc_parse_info pi;
  stat st;
  
  offs._0_4_ = 0;
  offs._4_4_ = 0;
  iVar1 = stat64(node,(stat64 *)&st);
  if (iVar1 != 0) {
    piVar3 = __errno_location();
    in_stack_fffffe60 = *piVar3;
    fprintf(stderr,"%s: error!: cannot open \"%s\"\n","libmtd",node);
    pFVar7 = stderr;
    in_stack_fffffe64 = strerror(in_stack_fffffe60);
    fprintf(pFVar7,"%*serror %d (%s)\n",8,"");
    if (*piVar3 == 2) {
      printf("%s: MTD subsystem is old and does not support sysfs, so MTD character device nodes have to exist\n"
             ,"libmtd");
    }
  }
  if ((st.st_mode & 0xf000) != 0x2000) {
    piVar3 = __errno_location();
    pFVar7 = stderr;
    *piVar3 = 0x16;
    fprintf(pFVar7,"%s: error!: \"%s\" is not a character device\n","libmtd",node);
    return -1;
  }
[32m  memset(mtd,0,0x100);[0m
  uVar6 = st.st_rdev._4_4_ & 0xfffff000 | (uint)st.st_rdev >> 8 & 0xfff;
  uVar5 = st.st_rdev._4_4_ << 0x14 | (uint)st.st_rdev >> 0xc & 0xffffff00 | (uint)st.st_rdev & 0xff;
  mtd->major = uVar6;
  mtd->minor = uVar5;
  if (uVar6 != 0x5a) {
    piVar3 = __errno_location();
    *piVar3 = 0x16;
    fprintf(stderr,"%s: error!: \"%s\" has major number %d, MTD devices have major %d\n","libmtd",
            node,mtd->major,0x5a);
    return -1;
  }
  mtd->mtd_num = (int)uVar5 / 2;
[32m  iVar1 = open64(node,0);[0m
  if (iVar1 == -1) {
    piVar3 = __errno_location();
    iVar1 = *piVar3;
    fprintf(stderr,"%s: error!: cannot open \"%s\"\n","libmtd",node);
    pFVar7 = stderr;
    pcVar4 = strerror(iVar1);
    fprintf(pFVar7,"%*serror %d (%s)\n",8,"",iVar1,pcVar4);
    return -1;
  }
  iVar2 = ioctl(iVar1,0x40204d01,&ui);
  if (iVar2 == 0) {
    iVar2 = ioctl(iVar1,0x80084d0b,&offs);
    if (iVar2 == -1) {
      piVar3 = __errno_location();
      iVar2 = *piVar3;
      if (iVar2 != 0x7a) {
        fprintf(stderr,"%s: error!: MEMGETBADBLOCK ioctl failed\n","libmtd");
        pFVar7 = stderr;
        pcVar4 = strerror(iVar2);
        goto LAB_0040512c;
      }
      *piVar3 = 0;
      *(uint *)&mtd->field_0xf8 = *(uint *)&mtd->field_0xf8 & 0xfffffffd;
    }
    else {
      *(uint *)&mtd->field_0xf8 = *(uint *)&mtd->field_0xf8 | 2;
    }
    mtd->type = (uint)ui.type;
    *(__u32 *)&mtd->size = ui.size;
    *(undefined4 *)((int)&mtd->size + 4) = 0;
    mtd->eb_size = ui.erasesize;
    mtd->min_io_size = ui.writesize;
    mtd->oob_size = ui.oobsize;
    if ((int)ui.writesize < 1) {
      fprintf(stderr,"%s: error!: mtd%d (%s) has insane min. I/O unit size %d\n","libmtd",
              mtd->mtd_num,node,ui.writesize);
      goto out_close;
    }
    if (((int)ui.erasesize < 1) || ((int)ui.erasesize < (int)ui.writesize)) {
      fprintf(stderr,"%s: error!: mtd%d (%s) has insane eraseblock size %d\n","libmtd",mtd->mtd_num,
              node,ui.erasesize);
      goto out_close;
    }
    if ((ui.size == 0) || ((-1 < (int)ui.erasesize && (ui.size < ui.erasesize)))) {
      fprintf(stderr,"%s: error!: mtd%d (%s) has insane size %lld\n","libmtd",mtd->mtd_num,node);
      goto out_close;
    }
    DVar8 = __divdi3(CONCAT44(in_stack_fffffe64,in_stack_fffffe60),
                     CONCAT44(in_stack_fffffe6c,in_stack_fffffe68));
    mtd->eb_cnt = (int)DVar8;
    switch((uint)ui.type) {
    case 0:
      fprintf(stderr,"%s: error!: mtd%d (%s) is removable and is not present\n","libmtd",
              mtd->mtd_num,node);
    default:
out_close:
      close(iVar1);
      return -1;
    case 1:
      pcVar4 = mtd->type_str + 3;
      uVar5 = (uint)pcVar4 & 3;
      *(uint *)(pcVar4 + -uVar5) =
           *(uint *)(pcVar4 + -uVar5) & -1 << (uVar5 + 1) * 8 | 0x6d6172U >> (3 - uVar5) * 8;
      uVar5 = (uint)mtd->type_str & 3;
      pcVar4 = mtd->type_str + -uVar5;
      *(uint *)pcVar4 = *(uint *)pcVar4 & 0xffffffffU >> (4 - uVar5) * 8 | 0x6d6172 << uVar5 * 8;
      break;
    case 2:
      pcVar4 = mtd->type_str + 3;
      uVar5 = (uint)pcVar4 & 3;
      *(uint *)(pcVar4 + -uVar5) =
           *(uint *)(pcVar4 + -uVar5) & -1 << (uVar5 + 1) * 8 | 0x6d6f72U >> (3 - uVar5) * 8;
      uVar5 = (uint)mtd->type_str & 3;
      pcVar4 = mtd->type_str + -uVar5;
      *(uint *)pcVar4 = *(uint *)pcVar4 & 0xffffffffU >> (4 - uVar5) * 8 | 0x6d6f72 << uVar5 * 8;
      break;
    case 3:
      pcVar4 = mtd->type_str + 3;
      uVar5 = (uint)pcVar4 & 3;
      *(uint *)(pcVar4 + -uVar5) =
           *(uint *)(pcVar4 + -uVar5) & -1 << (uVar5 + 1) * 8 | 0x726f6eU >> (3 - uVar5) * 8;
      uVar5 = (uint)mtd->type_str & 3;
      pcVar4 = mtd->type_str + -uVar5;
      *(uint *)pcVar4 = *(uint *)pcVar4 & 0xffffffffU >> (4 - uVar5) * 8 | 0x726f6e << uVar5 * 8;
      break;
    case 4:
      pcVar4 = mtd->type_str + 3;
      uVar5 = (uint)pcVar4 & 3;
      *(uint *)(pcVar4 + -uVar5) =
           *(uint *)(pcVar4 + -uVar5) & -1 << (uVar5 + 1) * 8 | 0x646e616eU >> (3 - uVar5) * 8;
      uVar5 = (uint)mtd->type_str & 3;
      pcVar4 = mtd->type_str + -uVar5;
      *(uint *)pcVar4 = *(uint *)pcVar4 & 0xffffffffU >> (4 - uVar5) * 8 | 0x646e616e << uVar5 * 8;
      mtd->type_str[4] = '\0';
      break;
    case 6:
      pcVar4 = mtd->type_str + 3;
      uVar5 = (uint)pcVar4 & 3;
      *(uint *)(pcVar4 + -uVar5) =
           *(uint *)(pcVar4 + -uVar5) & -1 << (uVar5 + 1) * 8 | 0x61746164U >> (3 - uVar5) * 8;
      uVar5 = (uint)mtd->type_str & 3;
      pcVar4 = mtd->type_str + -uVar5;
      *(uint *)pcVar4 = *(uint *)pcVar4 & 0xffffffffU >> (4 - uVar5) * 8 | 0x61746164 << uVar5 * 8;
      *(undefined4 *)(mtd->type_str + 4) = 0x73616c66;
      mtd->type_str[8] = 'h';
      mtd->type_str[9] = '\0';
      break;
    case 7:
      pcVar4 = mtd->type_str + 3;
      uVar5 = (uint)pcVar4 & 3;
      *(uint *)(pcVar4 + -uVar5) =
           *(uint *)(pcVar4 + -uVar5) & -1 << (uVar5 + 1) * 8 | 0x696275U >> (3 - uVar5) * 8;
      uVar5 = (uint)mtd->type_str & 3;
      pcVar4 = mtd->type_str + -uVar5;
      *(uint *)pcVar4 = *(uint *)pcVar4 & 0xffffffffU >> (4 - uVar5) * 8 | 0x696275 << uVar5 * 8;
      break;
    case 8:
      pcVar4 = mtd->type_str + 3;
      uVar5 = (uint)pcVar4 & 3;
      *(uint *)(pcVar4 + -uVar5) =
           *(uint *)(pcVar4 + -uVar5) & -1 << (uVar5 + 1) * 8 | 0x2d636c6dU >> (3 - uVar5) * 8;
      uVar5 = (uint)mtd->type_str & 3;
      pcVar4 = mtd->type_str + -uVar5;
      *(uint *)pcVar4 = *(uint *)pcVar4 & 0xffffffffU >> (4 - uVar5) * 8 | 0x2d636c6d << uVar5 * 8;
      *(undefined4 *)(mtd->type_str + 4) = 0x646e616e;
      mtd->type_str[8] = '\0';
    }
    if ((ui.flags & 0x400) != 0) {
      *(uint *)&mtd->field_0xf8 = *(uint *)&mtd->field_0xf8 | 1;
    }
    mtd->subpage_size = mtd->min_io_size;
    close(iVar1);
    iVar1 = proc_parse_start(&pi);
    iVar2 = -1;
    if (iVar1 == 0) {
      do {
        iVar1 = proc_parse_next(&pi);
        if (iVar1 == 0) {
          fprintf(stderr,"%s: error!: mtd%d not found in \"%s\"\n","libmtd",mtd->mtd_num,"/proc/mtd"
                 );
          piVar3 = __errno_location();
          *piVar3 = 2;
          return -1;
        }
      } while (pi.mtd_num != mtd->mtd_num);
[32m[32m      strcpy(mtd->name,pi.name);[0m[0m
      iVar2 = 0;
    }
    return iVar2;
  }
  piVar3 = __errno_location();
  iVar2 = *piVar3;
  fprintf(stderr,"%s: error!: MEMGETINFO ioctl request failed\n","libmtd");
  pFVar7 = stderr;
  pcVar4 = strerror(iVar2);
LAB_0040512c:
  fprintf(pFVar7,"%*serror %d (%s)\n",8,"",iVar2,pcVar4);
  goto out_close;
}

[ASK_GPT] ee565e8ba07789ba
