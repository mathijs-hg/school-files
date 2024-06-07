
int mtd_torture(libmtd_t desc,mtd_dev_info *mtd,int fd,int eb)

{
  byte *buf;
  int iVar1;
  size_t sVar2;
  int *piVar3;
  byte *pbVar4;
  size_t __n;
  uint __c;
  uint8_t *puVar5;
  
  printf("%s: run torture test for PEB %d\n","libmtd",eb);
[32m  buf = (byte *)xmalloc(mtd->eb_size);[0m
  puVar5 = patterns;
  while( true ) {
    iVar1 = mtd_erase(desc,mtd,fd,eb);
[32m    if ((iVar1 != 0) || (iVar1 = mtd_read(mtd,fd,eb,0,buf,mtd->eb_size), iVar1 != 0)) goto out;[0m
    __n = mtd->eb_size;
    if (0 < (int)__n) break;
LAB_0040a564:
    __c = (uint)*puVar5;
    memset(buf,__c,__n);
    iVar1 = mtd_write(desc,mtd,fd,eb,0,buf,mtd->eb_size,(void *)0x0,0,'\0');
    if (iVar1 != 0) goto out;
    memset(buf,~__c,mtd->eb_size);
[32m    iVar1 = mtd_read(mtd,fd,eb,0,buf,mtd->eb_size);[0m
    if (iVar1 != 0) goto out;
    if (0 < mtd->eb_size) {
      if (*buf != __c) {
LAB_0040a6ec:
        fprintf(stderr,"%s: error!: pattern %x checking failed for PEB %d\n","libmtd",__c,eb);
        goto code_r0x0040a6cc;
      }
      iVar1 = 1;
      while (pbVar4 = buf + iVar1, iVar1 != mtd->eb_size) {
        iVar1 = iVar1 + 1;
        if (*pbVar4 != __c) goto LAB_0040a6ec;
      }
    }
    puVar5 = puVar5 + 1;
    if (puVar5 == &UNK_00410817) {
      printf("%s: PEB %d passed torture test, do not mark it a bad\n","libmtd",eb);
out:
      free(buf);
      return -1;
    }
  }
  if (*buf == 0xff) {
[32m    sVar2 = 1;[0m
    while (pbVar4 = buf + sVar2, sVar2 != __n) {
[32m      sVar2 = sVar2 + 1;[0m
      if (*pbVar4 != 0xff) goto LAB_0040a6a4;
    }
    goto LAB_0040a564;
  }
LAB_0040a6a4:
  fprintf(stderr,"%s: error!: erased PEB %d, but a non-0xFF byte found\n","libmtd",eb);
code_r0x0040a6cc:
  piVar3 = __errno_location();
  *piVar3 = 5;
  goto out;
}

[ASK_GPT] be8e9b1b9103e749
