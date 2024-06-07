
int read_major(char *file,int *major,int *minor)

{
  FILE *__stream;
  int iVar1;
  int *piVar2;
  char buf [50];
  
  iVar1 = read_data(file,buf,0x32);
  if (-1 < iVar1) {
[32m    iVar1 = sscanf(buf,"%d:%d\n",major,minor);[0m
    if (iVar1 == 2) {
      if ((*major < 0) || (iVar1 = 0, *minor < 0)) {
        piVar2 = __errno_location();
        *piVar2 = 0x16;
        fprintf(stderr,"%s: error!: bad major:minor %d:%d in \"%s\"\n","libubi",*major,*minor,file);
        iVar1 = -1;
      }
    }
    else {
      piVar2 = __errno_location();
      __stream = stderr;
      *piVar2 = 0x16;
      fprintf(__stream,"%s: error!: \"%s\" does not have major:minor format\n","libubi",file);
      iVar1 = -1;
    }
  }
  return iVar1;
}

[ASK_GPT] 54b65c3c3ad22827
