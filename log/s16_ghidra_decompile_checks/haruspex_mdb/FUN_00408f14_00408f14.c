
bool FUN_00408f14(char *param_1,char *param_2,char *param_3)

{
  char *__dest;
  size_t sVar1;
  char *__src;
  
  __dest = strstr(param_1,param_2);
  if (__dest != (char *)0x0) {
    sVar1 = strlen(param_2);
[32m    __src = strdup(__dest + sVar1);[0m
[32m[32m    strcpy(__dest,param_3);[0m[0m
[32m[32m    strcat(__dest,__src);[0m[0m
    free(__src);
  }
  return __dest != (char *)0x0;
}

[ASK_GPT] ecfa547e294fde95
