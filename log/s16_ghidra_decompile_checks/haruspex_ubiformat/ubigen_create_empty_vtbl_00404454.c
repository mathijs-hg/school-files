
ubi_vtbl_record * ubigen_create_empty_vtbl(ubigen_info *ui)

{
  FILE *__stream;
  ubi_vtbl_record *puVar1;
  uint32_t uVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  ubi_vtbl_record *ss;
  int iVar6;
  size_t __size;
  
  __size = ui->vtbl_size;
[32m[32m  puVar1 = (ubi_vtbl_record *)calloc(1,__size);[0m[0m
  if (puVar1 == (ubi_vtbl_record *)0x0) {
    piVar3 = __errno_location();
    iVar6 = *piVar3;
    fprintf(stderr,"%s: error!: cannot allocate %d bytes of memory\n","libubigen",__size);
    __stream = stderr;
    pcVar4 = strerror(iVar6);
    fprintf(__stream,"%*serror %d (%s)\n",0xb,&DAT_0040e38c,iVar6,pcVar4);
  }
  else if (0 < ui->max_volumes) {
    iVar6 = 0;
    ss = puVar1;
    do {
      uVar2 = mtd_crc32(0xffffffff,ss,0xa8);
      iVar5 = ui->max_volumes;
      iVar6 = iVar6 + 1;
      ss->crc = uVar2 >> 0x18 | uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | (uVar2 & 0xff0000) >> 8;
      ss = ss + 1;
    } while (iVar6 < iVar5);
  }
  return puVar1;
}

[ASK_GPT] d90ed97a6dec86e5
