
int read_data(char *file,void *buf,int buf_len)

{
  FILE *pFVar1;
  int iVar2;
  ssize_t sVar3;
  ssize_t sVar4;
  int *piVar5;
  char *pcVar6;
  int __errnum;
  int tmp;
  
[32m  iVar2 = open64(file,0);[0m
  if (iVar2 == -1) {
    return -1;
  }
[32m[32m  sVar3 = read(iVar2,buf,buf_len);[0m[0m
  if (sVar3 == -1) {
LAB_00405a8c:
    piVar5 = __errno_location();
    __errnum = *piVar5;
    fprintf(stderr,"%s: error!: cannot read \"%s\"\n","libubi",file);
    pFVar1 = stderr;
    pcVar6 = strerror(__errnum);
    fprintf(pFVar1,"%*serror %d (%s)\n",8,&DAT_0040e38c,__errnum,pcVar6);
  }
  else {
    if (sVar3 == buf_len) {
      fprintf(stderr,"%s: error!: contents of \"%s\" is too long\n","libubi",file);
    }
    else {
      *(undefined *)((int)buf + sVar3) = 0;
[32m[32m      sVar4 = read(iVar2,&tmp,1);[0m[0m
      if (sVar4 == 1) goto LAB_00405a8c;
      if (sVar4 == 0) {
        iVar2 = close(iVar2);
        if (iVar2 == 0) {
          return sVar3;
        }
        piVar5 = __errno_location();
        iVar2 = *piVar5;
        fprintf(stderr,"%s: error!: close failed on \"%s\"\n","libubi",file);
        pFVar1 = stderr;
        pcVar6 = strerror(iVar2);
        fprintf(pFVar1,"%*serror %d (%s)\n",8,&DAT_0040e38c,iVar2,pcVar6);
        return -1;
      }
      fprintf(stderr,"%s: error!: file \"%s\" contains too much data (> %d bytes)\n","libubi",file,
              buf_len);
    }
    piVar5 = __errno_location();
    *piVar5 = 0x16;
  }
  close(iVar2);
  return -1;
}

[ASK_GPT] 2092755de915bea6
