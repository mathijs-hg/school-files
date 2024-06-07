
int read_pos_ll(char *file,longlong *value)

{
  FILE *pFVar1;
  int iVar2;
  ssize_t sVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  char buf [50];
  
[32m  iVar2 = open64(file,0x80000);[0m
  if (iVar2 != -1) {
[32m[32m    sVar3 = read(iVar2,buf,0x32);[0m[0m
    if (sVar3 == -1) {
      piVar5 = __errno_location();
      iVar4 = *piVar5;
      fprintf(stderr,"%s: error!: cannot read \"%s\"\n","libmtd",file);
      pFVar1 = stderr;
      pcVar6 = strerror(iVar4);
      fprintf(pFVar1,"%*serror %d (%s)\n",8,&DAT_0040e38c,iVar4,pcVar6);
    }
    else {
      if (sVar3 == 0x32) {
        fprintf(stderr,"%s: error!: contents of \"%s\" is too long\n","libmtd",file);
      }
      else {
[32m        iVar4 = sscanf(buf,"%lld\n",value);[0m
        if (iVar4 == 1) {
          if (-1 < *(int *)((int)value + 4)) {
            iVar2 = close(iVar2);
            if (iVar2 == 0) {
              return 0;
            }
            piVar5 = __errno_location();
            iVar2 = *piVar5;
            fprintf(stderr,"%s: error!: close failed on \"%s\"\n","libmtd",file);
            pFVar1 = stderr;
            pcVar6 = strerror(iVar2);
            fprintf(pFVar1,"%*serror %d (%s)\n",8,&DAT_0040e38c,iVar2,pcVar6);
            return -1;
          }
          fprintf(stderr,"%s: error!: negative value %lld in \"%s\"\n","libmtd");
        }
        else {
          fprintf(stderr,"%s: error!: cannot read integer from \"%s\"\n\n","libmtd",file);
        }
      }
      piVar5 = __errno_location();
      *piVar5 = 0x16;
    }
    close(iVar2);
  }
  return -1;
}

[ASK_GPT] 2e8a8409bc9c1481
