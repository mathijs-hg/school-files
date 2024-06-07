
char * mkpath(char *path,char *name)

{
  size_t __n;
  size_t sVar1;
  char *__dest;
  char *__dest_00;
  
  __n = strlen(path);
  sVar1 = strlen(name);
[32m  __dest = (char *)xmalloc(__n + sVar1 + 2);[0m
[32m  memcpy(__dest,path,__n);[0m
  __dest_00 = __dest + __n;
  if (__dest_00[-1] != '/') {
    *__dest_00 = '/';
    __dest_00 = __dest + __n + 1;
  }
[32m  memcpy(__dest_00,name,sVar1 + 1);[0m
  return __dest;
}

[ASK_GPT] 90d73d8b9157e864
