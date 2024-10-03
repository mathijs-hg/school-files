
void CompleteDeregistration(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (mDNS_LoggingEnabled != 0) {
    uVar1 = GetRRDisplayString_rdb(param_2 + 4,*(int *)(param_2 + 0x24) + 4,param_1 + 0x2f);
    LogMsgWithLevel(3,"CompleteDeregistration: called for Resource record %s",uVar1);
  }
  *(undefined *)(param_2 + 4) = 8;
  *(undefined *)(param_2 + 0x88) = 0;
[32m[32m  memcpy((void *)(param_2 + 0x4e),&zeroEthAddr,6);[0m[0m
  if (*(char *)(param_2 + 0x89) != '\0') {
    FUN_0043541c(param_1,param_2,0);
    *(undefined *)(param_2 + 0x89) = 0;
  }
  mDNS_Deregister_internal(param_1,param_2,0);
  return;
}

[ASK_GPT] 0849977b0cee1864
