
int FUN_0040e3f4(int param_1,undefined4 param_2,int param_3,void *param_4)

{
  int iVar1;
  char *pcVar2;
  undefined auStack_3a0 [4];
  undefined auStack_39c [4];
  undefined2 local_398;
  undefined2 local_390;
  undefined2 local_38e;
  int local_37c;
  
  iVar1 = putQuestion(param_1,param_2,param_1 + 0x22f8,param_3 + 0x154,
                      *(undefined2 *)(param_3 + 0x254),*(undefined2 *)(param_3 + 0x256));
  if (iVar1 == 0) {
    pcVar2 = "ERROR: putLLQ - putQuestion";
  }
  else {
    mDNS_SetupResourceRecord(auStack_3a0,0,0,0x29,0x1194,0x20,0,0,0);
    local_38e = 0x18;
    local_390 = 0x18;
    local_398 = 0x5a0;
    *(undefined2 *)(local_37c + 4) = 1;
[32m[32m    memcpy((void *)(local_37c + 8),param_4,0x14);[0m[0m
    iVar1 = PutResourceRecordTTLWithLimit(param_1,iVar1,param_1 + 10,auStack_39c,0,param_1 + 0x22f8)
    ;
    if (iVar1 != 0) {
      return iVar1;
    }
    pcVar2 = "ERROR: putLLQ - PutResourceRecordTTLJumbo";
  }
  LogMsgWithLevel(0,pcVar2);
  return iVar1;
}

[ASK_GPT] 4439e12802987d5c
