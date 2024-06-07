
int getnext(char *param_1,int param_2,char *param_3)

{
  int iVar1;
  char *pcVar2;
  size_t __n;
  
  if ((param_1 == (char *)0x0) || (param_3 == (char *)0x0)) {
    iVar1 = -1;
  }
  else {
    pcVar2 = strchr(param_1,param_2);
    if (pcVar2 == (char *)0x0) {
[32m[32m      strcpy(param_3,param_1);[0m[0m
      iVar1 = -1;
    }
    else {
[32m[32m      __n = (int)pcVar2 - (int)param_1;[0m[0m
[32m      strncpy(param_3,param_1,__n);[0m
      param_3[__n] = '\0';
[32m      iVar1 = __n + 1;[0m
    }
  }
  return iVar1;
}

[ASK_GPT] 98734a79f678d1bf
