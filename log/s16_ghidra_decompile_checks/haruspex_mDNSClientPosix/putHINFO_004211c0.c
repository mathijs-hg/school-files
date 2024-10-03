
undefined4 putHINFO(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  undefined auStack_3a8 [4];
  undefined auStack_3a4 [8];
  undefined4 local_39c;
  short local_398;
  short local_396;
  undefined auStack_230 [260];
  byte local_12c [268];
  
  if ((param_4 != 0) && (*(char *)(param_4 + 8) != '\0')) {
[32m    local_398 = (ushort)*(byte *)(param_1 + 0x1cd9) + (ushort)*(byte *)(param_1 + 0x1bd9) + 2;[0m
    mDNS_SetupResourceRecord(auStack_3a8,0,0,0xd,0,2,0,0,0);
    AppendDomainLabel(auStack_230,param_1 + 0x1a98);
    AppendDomainName(auStack_230,param_4 + 0x11b4);
    local_39c = 0;
    mDNSPlatformMemCopy(local_12c,(void *)(param_1 + 0x1bd9),*(byte *)(param_1 + 0x1bd9) + 1);
    mDNSPlatformMemCopy(local_12c + local_12c[0] + 1,(void *)(param_1 + 0x1cd9),
                        *(byte *)(param_1 + 0x1cd9) + 1);
    local_396 = local_398;
    param_3 = PutResourceRecordTTLWithLimit(param_2,param_3,param_2 + 10,auStack_3a4,0,param_5);
  }
  return param_3;
}

[ASK_GPT] 879bdda02ca51d23
