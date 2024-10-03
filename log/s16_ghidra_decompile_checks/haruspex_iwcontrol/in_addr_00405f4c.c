
undefined4 in_addr(int param_1,char *param_2,char *param_3,void *param_4)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined auStack_78 [16];
  undefined auStack_68 [16];
  undefined2 local_58 [8];
  uint local_48;
  char acStack_34 [24];
  
  pcVar1 = index(param_3,0x3a);
  if (pcVar1 == (char *)0x0) {
    iVar2 = FUN_00405e2c(param_3,auStack_78);
    if (iVar2 < 0) {
      fprintf(stderr,"Invalid interface address %s\n",param_3);
    }
    else {
[32m[32m      memcpy(auStack_68,auStack_78,0x10);[0m[0m
      local_58[0] = 0;
      local_48 = 0;
[32m[32m[32m      strncpy(acStack_34,param_2,0x10);[0m[0m[0m
      iVar2 = ioctl(param_1,0x8954,auStack_68);
      if ((-1 < iVar2) && ((local_48 & 2) != 0)) {
[32m[32m        memcpy(param_4,local_58,0x10);[0m[0m
        return 0;
      }
      piVar3 = __errno_location();
      fprintf(stderr,"Arp failed for %s on %s... (%d)\nTry to ping the address before setting it.\n"
              ,param_3,param_2,*piVar3);
    }
    uVar4 = 0xffffffff;
  }
  else {
    iVar2 = FUN_00405cf8(param_3,param_4);
    uVar4 = 0;
    if (iVar2 < 0) {
      fprintf(stderr,"Invalid hardware address %s\n",param_3);
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}

[ASK_GPT] 6cd49229eaf9f197
