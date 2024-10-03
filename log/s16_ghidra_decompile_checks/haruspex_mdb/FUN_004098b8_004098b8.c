
undefined4 FUN_004098b8(uint param_1,void *param_2,int param_3)

{
  fd_set *pfVar1;
  int iVar2;
  ssize_t sVar3;
  int iVar4;
  void *__buf;
  fd_set local_b0;
  timeval local_30;
  
  if (((param_1 != 0xffffffff) && (param_2 != (void *)0x0)) && (0 < param_3)) {
    pfVar1 = &local_b0;
    do {
      pfVar1->fds_bits[0] = 0;
      pfVar1 = (fd_set *)pfVar1->fds_bits;
    } while ((timeval *)pfVar1 != &local_30);
    local_30.tv_sec = 5;
    local_30.tv_usec = 0;
    local_b0.fds_bits[param_1 >> 5] = local_b0.fds_bits[param_1 >> 5] | 1 << (param_1 & 0x1f);
    iVar4 = 0;
    __buf = param_2;
    do {
      while( true ) {
        iVar2 = select(param_1 + 1,&local_b0,(fd_set *)0x0,(fd_set *)0x0,&local_30);
        if (iVar2 < 0) {
          return 0xffffffff;
        }
[32m[32m        sVar3 = recv(param_1,__buf,1,0);[0m[0m
        iVar4 = iVar4 + sVar3;
        if (sVar3 < 1) {
          return 0xffffffff;
        }
        __buf = (void *)((int)param_2 + iVar4);
        if (iVar4 < 4) break;
        if (param_3 <= iVar4) {
          return 0xffffffff;
        }
        iVar2 = strncmp((char *)((int)__buf + -4),"\r\n\r\n",4);
        if (iVar2 == 0) {
          return 0;
        }
      }
    } while (iVar4 < param_3);
  }
  return 0xffffffff;
}

[ASK_GPT] 0bf62b9ed926cef3
