
int ubigen_write_layout_vol
              (ubigen_info *ui,int peb1,int peb2,longlong ec1,longlong ec2,ubi_vtbl_record *vtbl,
              int fd)

{
  ubi_ec_hdr *hdr;
  int iVar1;
  ssize_t sVar2;
  char *pcVar3;
  int *piVar4;
  FILE *pFVar5;
  int iVar6;
  ubi_ec_hdr *__whence;
  size_t __size;
  int iVar7;
  __off64_t _Var8;
  int in_stack_00000024;
  undefined4 uVar9;
  uint in_stack_ffffff94;
  uint uVar10;
  ubigen_vol_info vi;
  
  vi.usable_leb_size = ui->leb_size;
  vi.alignment = 1;
  vi.type = 1;
  __size = ui->peb_size;
  vi.bytes._0_4_ = vi.usable_leb_size << 1;
  vi.bytes._4_4_ = (int)vi.bytes >> 0x1f;
  vi.name = "layout volume";
  vi.name_len = 0xd;
  vi.id = 0x7fffefff;
  vi.data_pad = 0;
  vi.compat = 5;
[32m  hdr = (ubi_ec_hdr *)malloc(__size);[0m
  if (hdr == (ubi_ec_hdr *)0x0) {
    piVar4 = __errno_location();
    iVar1 = *piVar4;
    fprintf(stderr,"%s: error!: failed to allocate %d bytes\n","libubigen",__size);
    pFVar5 = stderr;
    pcVar3 = strerror(iVar1);
    fprintf(pFVar5,"%*serror %d (%s)\n",0xb,&DAT_0040e38c,iVar1,pcVar3);
    return -1;
  }
  memset(hdr,0xff,ui->data_offs);
  iVar7 = ui->vid_hdr_offs;
[32m  memcpy(hdr->padding1 + ui->data_offs + -5,(void *)fd,ui->vtbl_size);[0m
  iVar6 = 0xff;
  memset(hdr->padding1 + ui->vtbl_size + ui->data_offs + -5,0xff,
         (ui->peb_size - ui->data_offs) - ui->vtbl_size);
  iVar1 = ui->peb_size;
  uVar9 = 0;
  _Var8 = lseek64(in_stack_00000024,(ulonglong)in_stack_ffffff94 << 0x20,iVar6);
  if ((longlong)peb1 * (longlong)iVar1 == _Var8) {
    ubigen_init_ec_hdr(ui,hdr,CONCAT44(in_stack_ffffff94,uVar9));
    uVar10 = 0;
    ubigen_init_vid_hdr(ui,&vi,(ubi_vid_hdr *)(hdr->padding1 + iVar7 + -5),0,(void *)0x0,0);
    __whence = hdr;
    sVar2 = write(in_stack_00000024,hdr,ui->peb_size);
    iVar1 = ui->peb_size;
    if (iVar1 != sVar2) {
      piVar4 = __errno_location();
      iVar6 = *piVar4;
      fprintf(stderr,"%s: error!: cannot write %d bytes\n","libubigen",iVar1);
      pFVar5 = stderr;
      pcVar3 = strerror(iVar6);
      goto out_free;
    }
    uVar9 = 0;
    _Var8 = lseek64(in_stack_00000024,(ulonglong)uVar10 << 0x20,(int)__whence);
    if (_Var8 != (longlong)peb2 * (longlong)iVar1) goto LAB_00404c00;
    ubigen_init_ec_hdr(ui,hdr,CONCAT44(uVar10,uVar9));
    ubigen_init_vid_hdr(ui,&vi,(ubi_vid_hdr *)(hdr->padding1 + iVar7 + -5),1,(void *)0x0,0);
    sVar2 = write(in_stack_00000024,hdr,ui->peb_size);
    iVar1 = ui->peb_size;
    if (iVar1 == sVar2) {
      free(hdr);
      return 0;
    }
    piVar4 = __errno_location();
    iVar6 = *piVar4;
    fprintf(stderr,"%s: error!: cannot write %d bytes\n","libubigen",iVar1);
  }
  else {
LAB_00404c00:
    piVar4 = __errno_location();
    iVar6 = *piVar4;
    fprintf(stderr,"%s: error!: cannot seek output file\n","libubigen");
  }
  pFVar5 = stderr;
  pcVar3 = strerror(iVar6);
out_free:
  fprintf(pFVar5,"%*serror %d (%s)\n",0xb,&DAT_0040e38c,iVar6,pcVar3);
  free(hdr);
  return -1;
}

[ASK_GPT] 68198f3610dcedfb
