
void FUN_00407c70(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined auStack_210 [516];
  
[32m  iVar1 = mDNS_vsnprintf(auStack_210,0x200,param_2,param_3);[0m
  auStack_210[iVar1] = 0;
  mDNSPlatformWriteLogMsg("mDNSClientPosix",auStack_210,param_1);
  return;
}

[ASK_GPT] 762ac3564eb8f047
