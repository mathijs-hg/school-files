
undefined4 ProcessCmd(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *__s;
  int iVar3;
  size_t sVar4;
  size_t sVar5;
  int local_630;
  size_t local_62c;
  char acStack_614 [1460];
  char *apcStack_60 [21];
  
[32m  local_62c = 0;[0m
  iVar1 = SplitString(param_2,apcStack_60,0x50,&DAT_0040e7ec);
  if (iVar1 == 0) {
    perror("found no string, return!\n");
    uVar2 = 0xffffffff;
  }
  else {
    for (local_630 = 0; local_630 < iVar1; local_630 = local_630 + 1) {
      __s = apcStack_60[local_630];
      if ((*__s != '\0') && (sVar5 = strlen(__s), __s[sVar5 - 1] == '\r')) {
        sVar5 = strlen(__s);
        __s[sVar5 - 1] = '\0';
      }
      if (*__s != '\0') {
        if ((l_debug != 0) && (l_debugStream != (FILE *)0x0)) {
          fprintf(l_debugStream,"recv:%s\n",__s);
        }
[32m        memset(acStack_614,0,0x5b4);[0m
        iVar3 = process_iwpriv_cmd(__s,acStack_614,0x5aa);
        if (iVar3 == 0) {
          sVar5 = strlen(acStack_614);
          sVar4 = strlen(acStack_614);
[32m          snprintf(acStack_614 + sVar5,0x5b3 - sVar4,"# ");[0m
        }
        else {
          fputs(acStack_614,stderr);
          sVar5 = strlen(acStack_614);
          sVar4 = strlen(acStack_614);
[32m          snprintf(acStack_614 + sVar5,0x5b3 - sVar4,"# error");[0m
        }
        local_62c = strlen(acStack_614);
        if ((l_debug != 0) && (l_debugStream != (FILE *)0x0)) {
          fprintf(l_debugStream,"packet length: %d, send:%s\n",local_62c,acStack_614);
        }
        if (iVar3 != 0) break;
      }
    }
    sVar5 = SendReply(param_1,acStack_614,local_62c);
    if (sVar5 == local_62c) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

[ASK_GPT] b927fed627da983f
