
undefined4 getCmdResults(char *param_1,char *param_2,char *param_3,size_t param_4)

{
  FILE *__stream;
  size_t sVar1;
  size_t sVar2;
  char *pcVar3;
  undefined4 local_418;
  char acStack_410 [1024];
  
[32m  memset(acStack_410,0,0x400);[0m
  local_418 = 0;
  memset(param_3,0,param_4);
[32m[32m  __stream = popen(param_1,"r");[0m[0m
  if (__stream == (FILE *)0x0) {
    local_418 = 0xffffffff;
  }
  else {
    do {
      while( true ) {
[32m        pcVar3 = fgets(acStack_410,0x400,__stream);[0m
        if (pcVar3 == (char *)0x0) goto LAB_00404b30;
        if (param_2 != (char *)0x0) break;
        sVar1 = strlen(param_3);
        sVar2 = strlen(param_3);
[32m        strlcpy(param_3 + sVar1,acStack_410,param_4 - sVar2);[0m
      }
      pcVar3 = strstr(acStack_410,param_2);
    } while (pcVar3 == (char *)0x0);
[32m    strlcpy(param_3,acStack_410,param_4);[0m
LAB_00404b30:
    pclose(__stream);
  }
  return local_418;
}

[ASK_GPT] ff4109c76d95ee56
