
undefined4 FUN_00406464(undefined4 param_1,char *param_2)

{
  FILE *__stream;
  int iVar1;
  char *pcVar2;
  int iVar3;
  in_addr local_170;
  char acStack_16c [12];
  char acStack_160 [16];
  undefined4 local_150;
  in_addr_t local_14c;
  char acStack_13c [255];
  undefined local_3d;
  undefined4 local_38;
  in_addr *local_34;
  undefined4 *local_30;
  
[32m  __stream = fopen(param_2,"r");[0m
  if (__stream != (FILE *)0x0) {
    iVar3 = 0;
    local_38 = 0;
    local_34 = &local_170;
    local_30 = &local_150;
[32m    while (pcVar2 = fgets(acStack_13c,0x100,__stream), pcVar2 != (char *)0x0) {[0m
      local_3d = 0;
[32m      iVar1 = sscanf(acStack_13c,"%10s %15s",acStack_16c,acStack_160);[0m
      if (((iVar1 == 2) && (iVar1 = strncasecmp(acStack_16c,"nameserver",10), iVar1 == 0)) &&
         (iVar1 = inet_aton(acStack_160,local_34), iVar1 != 0)) {
        iVar3 = iVar3 + 1;
        local_14c = local_170.s_addr;
        local_150 = 4;
        mDNS_AddDNSServer(param_1,0,local_38,0,local_30);
      }
    }
    fclose(__stream);
    if (0 < iVar3) {
      return 0;
    }
  }
  return 0xffffffff;
}

[ASK_GPT] af2b7d113bd01ba7
