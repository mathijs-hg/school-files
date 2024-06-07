
longlong ubiutils_get_bytes(char *str)

{
  ulonglong uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  char *__s1;
  ulonglong uVar5;
  char *endp;
  
  uVar5 = strtoull(str,&endp,0);
  if ((endp == str) || ((longlong)uVar5 < 0)) {
    fprintf(stderr,"incorrect amount of bytes: \"%s\"\n",str);
    uVar5 = 0xffffffffffffffff;
  }
  else {
    cVar2 = *endp;
    __s1 = endp;
    if (cVar2 != '\0') {
      while ((cVar2 == ' ' || (cVar2 == '\t'))) {
[32m        cVar2 = __s1[1];[0m
        __s1 = __s1 + 1;
      }
      iVar3 = strcmp(__s1,"KiB");
      uVar4 = 0x400;
      if (iVar3 != 0) {
        iVar3 = strcmp(__s1,"MiB");
        uVar4 = 0x100000;
        if (iVar3 != 0) {
          iVar3 = strcmp(__s1,"GiB");
          uVar4 = 0x40000000;
          if (iVar3 != 0) {
            fprintf(stderr,"bad size specifier: \"%s\" - should be \'KiB\', \'MiB\' or \'GiB\'\n",
                    endp);
            return -1;
          }
        }
      }
      uVar1 = (uVar5 & 0xffffffff) * (ulonglong)uVar4;
      uVar5 = uVar1 & 0xffffffff |
              (ulonglong)((int)(uVar5 >> 0x20) * uVar4 + (int)(uVar1 >> 0x20)) << 0x20;
    }
  }
  return uVar5;
}

[ASK_GPT] 4e65449fee5017c7
