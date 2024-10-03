
void DoActionHandle(char *param_1)

{
  char *pcVar1;
  int iVar2;
  __fd_mask *p_Var3;
  int iVar4;
  size_t __n;
  undefined4 uStack_20668;
  uint uStack_20664;
  int iStack_20660;
  size_t sStack_2065c;
  timeval tStack_20658;
  fd_set fStack_20650;
  undefined4 uStack_205d0;
  char acStack_205c8 [1452];
  char acStack_2001c [131076];
  
  uStack_20668 = 0;
  pcVar1 = strstr(param_1,"<DoAction");
  if (pcVar1 == (char *)0x0) {
    if (stderr != 0) {
      fwrite("MDB Set Policy Fail: Content not valid\n",1,0x27,(FILE *)stderr);
    }
  }
  else {
[32m    memset(acStack_2001c,0,0x20000);[0m
    sprintf(acStack_2001c,
            "<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope %s %s %s><soap:Body>%s</soap:Body></soap:Envelope>"
            ,"xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"",
            "xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"",
[32m[32m            "xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\"",pcVar1);[0m[0m
    cfgRead(&DAT_0040b1ac,&DAT_0040b1b4,&uStack_20668);
    uStack_20664 = 0xffffffff;
    iStack_20660 = 0;
[32m    sStack_2065c = 0;[0m
    uStack_205d0._0_1_ = 0;
[32m    memset((void *)((int)&uStack_205d0 + 1),0,0x5b3);[0m
    iVar2 = FUN_004095f0(&uStack_20664,&DAT_0040c070,0x50,acStack_2001c);
    if (iVar2 != -1) {
[32m      memset(&uStack_205d0,0,0x5b4);[0m
      iVar2 = FUN_004098b8(uStack_20664,&uStack_205d0,0x5b4);
      if (iVar2 == 0) {
[32m[32m        sscanf(acStack_205c8,"%d",&iStack_20660);[0m[0m
        if (iStack_20660 == 200) {
          pcVar1 = strstr((char *)&uStack_205d0,"Content-Length:");
          if (pcVar1 != (char *)0x0) {
[32m[32m            sscanf(pcVar1 + 0x10,"%d",&sStack_2065c);[0m[0m
            if (0x5b3 < sStack_2065c) {
[32m              sStack_2065c = 3;[0m
            }
[32m            __n = sStack_2065c;[0m
            tStack_20658.tv_sec = 5;
            tStack_20658.tv_usec = 0;
            p_Var3 = (__fd_mask *)&fStack_20650;
            do {
              *p_Var3 = 0;
              p_Var3 = p_Var3 + 1;
            } while (p_Var3 != &uStack_205d0);
            fStack_20650.fds_bits[uStack_20664 >> 5] =
                 fStack_20650.fds_bits[uStack_20664 >> 5] | 1 << (uStack_20664 & 0x1f);
[32m            memset(&uStack_205d0,0,0x5b4);[0m
            iVar2 = 0;
            if (0 < (int)__n) {
              while( true ) {
                iVar4 = select(uStack_20664 + 1,&fStack_20650,(fd_set *)0x0,(fd_set *)0x0,
                               &tStack_20658);
                if (iVar4 < 0) break;
                if ((int)__n < 0x5b5) {
[32m[32m                  iVar4 = recv(uStack_20664,(void *)((int)&uStack_205d0 + iVar2),__n,0);[0m[0m
                }
                else {
[32m[32m                  iVar4 = recv(uStack_20664,(void *)((int)&uStack_205d0 + iVar2),0x5b4,0);[0m[0m
                }
[32m                __n = __n - iVar4;[0m
                if ((iVar4 < 1) || (iVar2 = iVar2 + iVar4, (int)__n < 1)) break;
              }
            }
          }
        }
      }
    }
    if (uStack_20664 != 0xffffffff) {
      close(uStack_20664);
    }
  }
  return;
}

[ASK_GPT] 9e34c4ad5971bb9a
