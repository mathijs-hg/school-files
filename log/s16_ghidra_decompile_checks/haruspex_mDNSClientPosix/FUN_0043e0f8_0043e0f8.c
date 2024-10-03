
void FUN_0043e0f8(int param_1,int param_2)

{
  int iVar1;
  
[32m[32m  memcpy((void *)(param_2 + 0x4e),&zeroEthAddr,6);[0m[0m
  *(undefined *)(param_2 + 0x88) = 0;
  mDNS_Deregister_internal(param_1,param_2,0);
  if (*(int *)(param_1 + 0x2aa4) != 0) {
    iVar1 = *(int *)(param_1 + 0x7fc4);
    if (*(int *)(param_1 + 0x2aa4) == iVar1) goto LAB_0043e170;
    mDNSPlatformUpdateProxyList(param_1);
  }
  iVar1 = *(int *)(param_1 + 0x7fc4);
LAB_0043e170:
  *(int *)(param_1 + 0x2aa4) = iVar1;
  return;
}

[ASK_GPT] 5149022547886781
