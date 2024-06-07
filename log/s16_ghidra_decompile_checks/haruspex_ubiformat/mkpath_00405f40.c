
char * mkpath(char *path,char *name)

{
  FILE *__stream;
  size_t __n;
  size_t sVar1;
  char *__dest;
  int *piVar2;
  char *pcVar3;
  int __errnum;
  size_t __size;
  
  __n = strlen(path);
  sVar1 = strlen(name);
[32m  __size = __n + sVar1 + 2;[0m
[32m[32m  __dest = (char *)malloc(__size);[0m[0m
  if (__dest == (char *)0x0) {
    piVar2 = __errno_location();
    __errnum = *piVar2;
    fprintf(stderr,"%s: error!: cannot allocate %d bytes\n","libubi",__size);
    __stream = stderr;
    pcVar3 = strerror(__errnum);
    fprintf(__stream,"%*serror %d (%s)\n",8,&DAT_0040e38c,__errnum,pcVar3);
  }
  else {
[32m    memcpy(__dest,path,__n);[0m
    if ((__dest + __n)[-1] != '/') {
      __dest[__n] = '/';
[32m      __n = __n + 1;[0m
    }
[32m    memcpy(__dest + __n,name,sVar1 + 1);[0m
  }
  return __dest;
}

[ASK_GPT] aeffb44ef7c4a557
