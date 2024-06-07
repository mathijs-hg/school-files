
int proc_parse_next(proc_parse_info *pi)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  size_t __n;
  void *__s;
  char *pcVar4;
  
  iVar3 = (int)pi->next - (int)pi->buf;
  if (pi->data_size <= iVar3) {
    free(pi->buf);
    return 0;
  }
[32m  iVar1 = sscanf(pi->next,"mtd%d: %llx %x",pi,&pi->size,&pi->eb_size);[0m
  if (iVar1 != 3) {
    fprintf(stderr,"%s: error!: \"%s\" pattern not found\n","libmtd","mtd%d: %llx %x");
    return -1;
  }
  iVar1 = pi->data_size;
  pvVar2 = memchr(pi->next,0x22,iVar1 - iVar3);
  __s = (void *)((int)pvVar2 + 1);
  if (pvVar2 != (void *)0x0) {
    pcVar4 = pi->buf;
    iVar3 = (int)__s - (int)pcVar4;
    if (iVar3 < iVar1) {
      pvVar2 = memchr(__s,0x22,iVar1 - iVar3);
      if ((pvVar2 == (void *)0x0) ||
[32m         (__n = (int)pvVar2 - (int)__s, iVar1 <= (int)pvVar2 - (int)pcVar4)) {[0m
        pcVar4 = "%s: error!: closing \" not found\n";
      }
      else {
        if (0x7f < (int)__n) {
          fprintf(stderr,"%s: error!: too long mtd%d device name\n","libmtd",pi->mtd_num);
          return -1;
        }
[32m        memcpy(pi->name,__s,__n);[0m
        *(undefined *)((int)pi + __n + 0x10) = 0;
        if (*(char *)((int)pvVar2 + 1) == '\n') {
          pi->next = (char *)((int)pvVar2 + 2);
          return 1;
        }
        pcVar4 = "%s: error!: opening \"\n\" not found\n";
      }
      goto LAB_00404944;
    }
  }
  pcVar4 = "%s: error!: opening \" not found\n";
LAB_00404944:
  fprintf(stderr,pcVar4,"libmtd");
  return -1;
}

[ASK_GPT] f0fb9d00550e4598
