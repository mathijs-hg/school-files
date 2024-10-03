
int FUN_00411aa0(char *param_1,char *param_2)

{
  char cVar1;
  size_t sVar2;
  char *__src;
  size_t __n;
  char *pcVar3;
  char *__dest;
  int iVar4;
  
  iVar4 = 0;
  sVar2 = strlen(param_2);
  __dest = param_1;
  do {
    while( true ) {
      if ((int)sVar2 <= iVar4) {
        *__dest = '\0';
[32m        return (int)__dest - (int)param_1;[0m
      }
[32m      cVar1 = param_2[iVar4];[0m
      __src = "&quot;";
      if (cVar1 != '\"') break;
LAB_00411b64:
[32m      __n = 6;[0m
      pcVar3 = __dest + 6;
LAB_00411b68:
      iVar4 = iVar4 + 1;
[32m[32m      memcpy(__dest,__src,__n);[0m[0m
      __dest = pcVar3;
    }
    if (cVar1 == '\'') {
      __src = "&apos;";
      goto LAB_00411b64;
    }
    __src = "&lt;";
    if (cVar1 == '<') {
LAB_00411bb0:
[32m      __n = 4;[0m
      pcVar3 = __dest + 4;
      goto LAB_00411b68;
    }
    if (cVar1 == '>') {
      __src = "&gt;";
      goto LAB_00411bb0;
    }
    if (cVar1 == '&') {
[32m      __n = 5;[0m
      pcVar3 = __dest + 5;
      __src = "&amp;";
      goto LAB_00411b68;
    }
    *__dest = cVar1;
    __dest = __dest + 1;
    iVar4 = iVar4 + 1;
  } while( true );
}

[ASK_GPT] 4218702f07f344de
