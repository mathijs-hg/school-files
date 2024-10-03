
void ExampleClientEventLoop(undefined4 param_1)

{
  __fd_mask *p_Var1;
  int iVar2;
  int *piVar3;
  int local_b8;
  timeval local_b4;
  __fd_mask local_ac [32];
  undefined4 uStack_2c;
  
[32m  signal(2,(__sighandler_t)&LAB_0044b5f0);[0m
[32m  signal(0xf,(__sighandler_t)&LAB_0044b5f0);[0m
[32m  signal(0xe,(__sighandler_t)&LAB_0044b5f0);[0m
  while (p_Var1 = local_ac, DAT_0046e820 == '\0') {
    do {
      *p_Var1 = 0;
      p_Var1 = p_Var1 + 1;
    } while (p_Var1 != &uStack_2c);
    local_b4.tv_sec = 0x3fffffff;
    local_b4.tv_usec = 0;
    local_b8 = 0;
    mDNSPosixGetFDSet(param_1,&local_b8,local_ac,&local_b4);
    iVar2 = select(local_b8,(fd_set *)local_ac,(fd_set *)0x0,(fd_set *)0x0,&local_b4);
    if (iVar2 < 0) {
      piVar3 = __errno_location();
      if (*piVar3 != 4) {
        DAT_0046e820 = '\x01';
      }
    }
    else {
      mDNSPosixProcessFDSet(param_1,local_ac);
    }
  }
  return;
}

[ASK_GPT] 8e03b2e08c83dfd4
