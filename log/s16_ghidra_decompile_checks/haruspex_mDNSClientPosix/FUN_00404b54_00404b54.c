
undefined4 FUN_00404b54(undefined4 param_1,__time_t *param_2,void *param_3,undefined *param_4)

{
  int iVar1;
  code **ppcVar2;
  code *pcVar3;
  int local_a8;
  timeval local_a4;
  fd_set fStack_9c;
  
[32m[32m  memcpy(&fStack_9c,&DAT_0046e6c4,0x80);[0m[0m
  local_a4.tv_usec = param_2[1];
  local_a4.tv_sec = *param_2;
  local_a8 = 0;
  mDNSPosixGetFDSet(param_1,&local_a8,&fStack_9c,&local_a4);
  if (local_a8 < DAT_0046e744) {
    local_a8 = DAT_0046e744;
  }
  iVar1 = select(local_a8 + 1,&fStack_9c,(fd_set *)0x0,(fd_set *)0x0,&local_a4);
  if (iVar1 < 1) {
    *param_4 = 0;
  }
  else {
    mDNSPosixProcessFDSet(param_1,&fStack_9c);
    for (ppcVar2 = DAT_0046e748; ppcVar2 != (code **)0x0; ppcVar2 = (code **)ppcVar2[3]) {
      pcVar3 = ppcVar2[2];
      if (((uint)fStack_9c.fds_bits[(uint)pcVar3 >> 5] >> ((uint)pcVar3 & 0x1f) & 1) != 0) {
        (**ppcVar2)(pcVar3,0,ppcVar2[1]);
        break;
      }
    }
    *param_4 = 1;
  }
  sigprocmask(1,(sigset_t *)&DAT_0046e754,(sigset_t *)0x0);
[32m[32m  memcpy(param_3,&DAT_0046e764,0x10);[0m[0m
  sigemptyset((sigset_t *)&DAT_0046e764);
  sigprocmask(2,(sigset_t *)&DAT_0046e754,(sigset_t *)0x0);
  return 0;
}

[ASK_GPT] 3a5344be5c86cfae
