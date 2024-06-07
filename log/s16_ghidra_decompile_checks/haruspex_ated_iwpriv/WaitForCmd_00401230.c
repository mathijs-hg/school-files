
undefined4 WaitForCmd(int param_1)

{
  int iVar1;
  int *piVar2;
  ssize_t sVar3;
  uint local_658;
  timeval local_648;
  fd_set fStack_640;
  undefined auStack_5c0 [1464];
  
LAB_00401258:
  do {
    iVar1 = listen(param_1,5);
    if (iVar1 < 0) {
      perror("socket listen error\n");
      return 0xffffffff;
    }
    l_connSock = accept(param_1,(sockaddr *)0x0,(socklen_t *)0x0);
    if ((int)l_connSock < 0) {
      perror("socket accept error\n");
      return 0xffffffff;
    }
    while( true ) {
      while( true ) {
        for (local_658 = 0; local_658 < 0x20; local_658 = local_658 + 1) {
          fStack_640.fds_bits[local_658] = 0;
        }
        fStack_640.fds_bits[l_connSock >> 5] =
             fStack_640.fds_bits[l_connSock >> 5] | 1 << (l_connSock & 0x1f);
        local_648.tv_sec = 0x3c;
        local_648.tv_usec = 0;
        iVar1 = select(l_connSock + 1,&fStack_640,(fd_set *)0x0,(fd_set *)0x0,&local_648);
        if (-1 < iVar1) break;
        piVar2 = __errno_location();
        if (*piVar2 != 4) {
          perror("socket select error\n");
          return 0xffffffff;
        }
      }
      if (iVar1 == 0) {
        perror("socket timeout, return to listen\n");
        close(l_connSock);
        goto LAB_00401258;
      }
[32m      memset(auStack_5c0,0,0x5b4);[0m
[32m[32m      sVar3 = recvfrom(l_connSock,auStack_5c0,0x5b4,0,(sockaddr *)0x0,(socklen_t *)0x0);[0m[0m
      if (sVar3 < 1) break;
      ProcessCmd(l_connSock,auStack_5c0,sVar3);
    }
    if (sVar3 != 0) {
      perror("socket recv error\n");
      return 0xffffffff;
    }
    puts("socket close, return to listen");
    close(l_connSock);
  } while( true );
}

[ASK_GPT] a22864e7aacdabdd
