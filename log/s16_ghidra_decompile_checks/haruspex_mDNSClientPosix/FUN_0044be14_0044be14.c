
void FUN_0044be14(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  char *pcVar1;
  undefined auStack_1df8 [64];
  undefined auStack_1db8 [64];
  undefined auStack_1d78 [256];
  undefined auStack_1c78 [256];
  undefined auStack_1b78 [1012];
  undefined auStack_1784 [1012];
  undefined auStack_1390 [256];
  undefined4 local_1290;
  undefined auStack_a74 [2648];
  
[32m  memset(auStack_1390,0,0x91c);[0m
[32m  memset(auStack_a74,0,0xa54);[0m
  if (*(short *)(param_3 + 2) != 0xc) {
    __assert("answer->rrtype == kDNSType_PTR","Client.c",0x84);
  }
  DeconstructServiceName(*(int *)(param_3 + 0x20) + 4,auStack_1df8,auStack_1d78,auStack_1c78);
  ConvertDomainLabelToCString_withescape(auStack_1df8,auStack_1db8,0);
  ConvertDomainNameToCString_withescape(auStack_1d78,auStack_1b78,0x5c);
  ConvertDomainNameToCString_withescape(auStack_1c78,auStack_1784,0x5c);
  if (param_4 == 0) {
    pcVar1 = "Lost ";
  }
  else {
[32m[32m    memcpy(auStack_1390,(void *)(*(int *)(param_3 + 0x20) + 4),0x100);[0m[0m
    local_1290 = *(undefined4 *)(param_3 + 0x18);
    mDNS_StartResolveService(param_1,auStack_a74,auStack_1390,FUN_0044bfd8,0);
    pcVar1 = "Found";
  }
  fprintf(stderr,"*** %s name = \'%s\', type = \'%s\', domain = \'%s\'\n",pcVar1,auStack_1db8,
          auStack_1b78,auStack_1784);
  return;
}

[ASK_GPT] 3dbb39c6fcb41791
