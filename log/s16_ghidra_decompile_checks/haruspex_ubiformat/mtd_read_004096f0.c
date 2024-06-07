
int mtd_read(mtd_dev_info *mtd,int fd,int eb,int offs,void *buf,int len)

{
  longlong lVar1;
  int iVar2;
  ssize_t sVar3;
  int *piVar4;
  char *pcVar5;
  FILE *__stream;
  uint uVar6;
  int iVar7;
  __off64_t _Var8;
  uint in_stack_ffffffc4;
  
  iVar7 = eb;
  iVar2 = mtd_valid_erase_block(mtd,eb);
  if (iVar2 == 0) {
    iVar2 = mtd->eb_size;
    if (-1 < offs) {
      lVar1 = (longlong)eb * (longlong)iVar2;
      if (offs + len <= iVar2) {
        uVar6 = (uint)lVar1 + offs;
        _Var8 = lseek64(fd,(ulonglong)in_stack_ffffffc4 << 0x20,iVar7);
        if (_Var8 == lVar1 + offs) {
          iVar7 = 0;
          if (len < 1) {
            return 0;
          }
          while( true ) {
[32m[32m            sVar3 = read(fd,buf,len);[0m[0m
            iVar7 = iVar7 + sVar3;
            if (sVar3 < 0) break;
            if (len <= iVar7) {
              return 0;
            }
          }
          piVar4 = __errno_location();
          iVar7 = *piVar4;
          fprintf(stderr,"%s: error!: cannot read %d bytes from mtd%d (eraseblock %d, offset %d)\n",
                  "libmtd",len,mtd->mtd_num,eb,offs);
          __stream = stderr;
          pcVar5 = strerror(iVar7);
        }
        else {
          piVar4 = __errno_location();
          iVar7 = *piVar4;
          fprintf(stderr,"%s: error!: cannot seek mtd%d to offset %lld\n","libmtd",mtd->mtd_num,
                  uVar6,(uint)(uVar6 < (uint)lVar1) +
                        (int)((ulonglong)lVar1 >> 0x20) + (offs >> 0x1f));
          __stream = stderr;
          pcVar5 = strerror(iVar7);
        }
        fprintf(__stream,"%*serror %d (%s)\n",8,&DAT_0040e38c,iVar7,pcVar5);
        return -1;
      }
    }
    fprintf(stderr,"%s: error!: bad offset %d or length %d, mtd%d eraseblock size is %d\n","libmtd",
            offs,len,mtd->mtd_num,iVar2);
    iVar2 = -1;
    piVar4 = __errno_location();
    *piVar4 = 0x16;
  }
  return iVar2;
}

[ASK_GPT] 0969aa58cc4ab7ac
