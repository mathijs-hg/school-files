
/* WARNING: Could not reconcile some variable overlaps */

int mtd_write(libmtd_t desc,mtd_dev_info *mtd,int fd,int eb,int offs,void *data,int len,void *oob,
             int ooblen,uint8_t mode)

{
  uint64_t start;
  int iVar1;
  int *piVar2;
  ssize_t sVar3;
  char *pcVar4;
  void *__dest;
  int iVar5;
  FILE *pFVar6;
  __u32 (*data_00) [2];
  __u32 (*pa_Var7) [2];
  __off64_t _Var8;
  uint64_t in_stack_fffffea8;
  undefined8 uVar9;
  mtd_write_req ops;
  nand_oobinfo old_oobinfo;
  int *_err;
  
  data_00 = (__u32 (*) [2])eb;
  iVar1 = mtd_valid_erase_block(mtd,eb);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = mtd->eb_size;
  if ((offs < 0) || (iVar1 < offs + len)) {
    fprintf(stderr,"%s: error!: bad offset %d or length %d, mtd%d eraseblock size is %d\n","libmtd",
            offs,len,mtd->mtd_num,iVar1);
code_r0x0040a31c:
    piVar2 = __errno_location();
    *piVar2 = 0x16;
    return -1;
  }
  iVar5 = mtd->subpage_size;
  if (iVar5 == 0) {
    trap(0x1c00);
  }
  if (offs % iVar5 != 0) {
    fprintf(stderr,"%s: error!: write offset %d is not aligned to mtd%d min. I/O size %d\n","libmtd"
            ,offs,mtd->mtd_num,iVar5);
    goto code_r0x0040a31c;
  }
  if (iVar5 == 0) {
    trap(0x1c00);
  }
  if (len % iVar5 != 0) {
    fprintf(stderr,"%s: error!: write length %d is not aligned to mtd%d min. I/O size %d\n","libmtd"
            ,len,mtd->mtd_num,iVar5);
    goto code_r0x0040a31c;
  }
  start = (longlong)eb * (longlong)iVar1 + (longlong)offs;
  if (oob == (void *)0x0) goto LAB_0040a018;
  ops.len._4_4_ = len >> 0x1f;
  ops.ooblen._4_4_ = ooblen >> 0x1f;
  ops.ooblen._0_4_ = ooblen;
  ops.len._0_4_ = len;
  ops.usr_data._0_4_ = data;
  ops.usr_data._4_4_ = 0;
  ops.usr_oob._0_4_ = oob;
  ops.usr_oob._4_4_ = 0;
  ops.mode = mode;
  ops.start = start;
  iVar5 = ioctl(fd,0xc0304d18,&ops);
  if (iVar5 == 0) {
    return 0;
  }
  piVar2 = __errno_location();
  iVar5 = *piVar2;
  if ((iVar5 != 0x19) && (iVar5 != 0x7a)) {
    fprintf(stderr,"%s: error!: %s ioctl failed for eraseblock %d (mtd%d)\n","libmtd","MEMWRITE",eb,
            mtd->mtd_num);
    pFVar6 = stderr;
    pcVar4 = strerror(iVar5);
    uVar9 = CONCAT44(pcVar4,iVar5);
    goto LAB_0040a10c;
  }
  if (mode == '\x01') {
    iVar5 = ioctl(fd,0x40c84d0a,&old_oobinfo);
    if (iVar5 == 0) {
[32m[32m[32m      __dest = malloc(ooblen);[0m[0m[0m
[32m[32m      memcpy(__dest,oob,ooblen);[0m[0m
      if (old_oobinfo.useecc == 2) {
        data_00 = old_oobinfo.oobfree;
        if (old_oobinfo.oobfree[0][1] != 0) {
          iVar5 = 0;
          pa_Var7 = data_00;
          do {
            data_00 = pa_Var7[1];
            memcpy((void *)((int)oob + (*pa_Var7)[0]),(void *)((int)__dest + iVar5),
[32m                   old_oobinfo.oobfree[0][1]);[0m
            iVar5 = iVar5 + old_oobinfo.oobfree[0][1];
            old_oobinfo.oobfree[0][1] = pa_Var7[1][1];
            pa_Var7 = data_00;
          } while (old_oobinfo.oobfree[0][1] != 0);
        }
      }
      else {
        memcpy((void *)((int)oob + old_oobinfo.eccbytes),
[32m               (void *)((int)__dest + old_oobinfo.eccbytes),mtd->oob_size - old_oobinfo.eccbytes);[0m
      }
      goto LAB_00409fe0;
    }
    iVar1 = *piVar2;
    pcVar4 = "%s: error!: MEMGETOOBSEL failed\n";
  }
  else {
LAB_00409fe0:
    in_stack_fffffea8 = start;
    iVar5 = mtd_write_oob(desc,mtd,fd,start,(longlong)ooblen,data_00);
    if (-1 < iVar5) {
LAB_0040a018:
      if (data == (void *)0x0) {
        return 0;
      }
      _Var8 = lseek64(fd,in_stack_fffffea8 & 0xffffffff00000000,(int)&DAT_00410000);
      if (_Var8 == (longlong)eb * (longlong)iVar1 + (longlong)offs) {
        sVar3 = write(fd,data,len);
        if (sVar3 == len) {
          return 0;
        }
        piVar2 = __errno_location();
        iVar1 = *piVar2;
        fprintf(stderr,"%s: error!: cannot write %d bytes to mtd%d (eraseblock %d, offset %d)\n",
                "libmtd",len,mtd->mtd_num,eb,offs);
        pFVar6 = stderr;
        pcVar4 = strerror(iVar1);
        uVar9 = CONCAT44(pcVar4,iVar1);
      }
      else {
        piVar2 = __errno_location();
        iVar1 = *piVar2;
        fprintf(stderr,"%s: error!: cannot seek mtd%d to offset %lld\n","libmtd",mtd->mtd_num,start)
        ;
        pFVar6 = stderr;
        pcVar4 = strerror(iVar1);
        uVar9 = CONCAT44(pcVar4,iVar1);
      }
      fprintf(pFVar6,"%*serror %d (%s)\n",8,&DAT_0040e38c,uVar9);
      return -1;
    }
    iVar1 = *piVar2;
    pcVar4 = "%s: error!: cannot write to OOB\n";
  }
  fprintf(stderr,pcVar4,"libmtd");
  pFVar6 = stderr;
  pcVar4 = strerror(iVar1);
  uVar9 = CONCAT44(pcVar4,iVar1);
LAB_0040a10c:
  fprintf(pFVar6,"%*serror %d (%s)\n",8,&DAT_0040e38c,uVar9);
  return -1;
}

[ASK_GPT] 11b4d17ac5b7ca0d
