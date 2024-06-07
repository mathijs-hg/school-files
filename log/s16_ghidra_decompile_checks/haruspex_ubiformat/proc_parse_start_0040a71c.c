
int proc_parse_start(proc_parse_info *pi)

{
  FILE *pFVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  
[32m  iVar2 = open64("/proc/mtd",0);[0m
  if (iVar2 != -1) {
[32m[32m    pcVar3 = (char *)malloc(0x1000);[0m[0m
    if (pcVar3 == (char *)0x0) {
      piVar6 = __errno_location();
      iVar2 = *piVar6;
      fprintf(stderr,"%s: error!: out of memory\n","libmtd");
      pFVar1 = stderr;
      pcVar3 = strerror(iVar2);
      fprintf(pFVar1,"%*serror %d (%s)\n",8,&DAT_0040e38c,iVar2,pcVar3);
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    pi->buf = pcVar3;
[32m[32m    uVar4 = read(iVar2,pcVar3,0x1000);[0m[0m
    if (uVar4 == 0xffffffff) {
      piVar6 = __errno_location();
      iVar5 = *piVar6;
      fprintf(stderr,"%s: error!: cannot read \"%s\"\n","libmtd","/proc/mtd");
      pFVar1 = stderr;
      pcVar3 = strerror(iVar5);
      fprintf(pFVar1,"%*serror %d (%s)\n",8,&DAT_0040e38c,iVar5,pcVar3);
    }
    else {
      if (0x1e < uVar4) {
        pcVar3 = pi->buf;
        iVar5 = memcmp(pcVar3,"dev:    size   erasesize  name\n",0x1f);
        if (iVar5 == 0) {
          pi->data_size = uVar4;
          pi->next = pcVar3 + 0x1f;
          close(iVar2);
          return 0;
        }
      }
      fprintf(stderr,"%s: error!: \"%s\" does not start with \"%s\"\n","libmtd","/proc/mtd",
              "dev:    size   erasesize  name\n");
    }
    free(pi->buf);
    close(iVar2);
  }
  return -1;
}

[ASK_GPT] 76c072055357682a
