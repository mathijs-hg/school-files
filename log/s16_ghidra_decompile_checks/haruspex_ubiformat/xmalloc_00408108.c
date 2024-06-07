
void * xmalloc(size_t size)

{
  FILE *__stream;
  void *pvVar1;
  int *piVar2;
  char *pcVar3;
  int __errnum;
  
[32m  pvVar1 = malloc(size);[0m
  if ((pvVar1 == (void *)0x0) && (size != 0)) {
    piVar2 = __errno_location();
    __errnum = *piVar2;
    fprintf(stderr,"%s: error!: out of memory\n","libmtd");
    __stream = stderr;
    pcVar3 = strerror(__errnum);
    fprintf(__stream,"%*serror %d (%s)\n",8,&DAT_0040e38c,__errnum,pcVar3);
                    /* WARNING: Subroutine does not return */
    exit(-1);
  }
  return pvVar1;
}

[ASK_GPT] 977d58e96da97bc1
