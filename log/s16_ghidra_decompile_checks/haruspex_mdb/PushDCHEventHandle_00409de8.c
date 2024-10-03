
void PushDCHEventHandle(char *param_1)

{
  char *pcVar1;
  FILE *__s;
  size_t sVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  __fd_mask *p_Var6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uStack_20678;
  uint uStack_20674;
  int iStack_20670;
  size_t sStack_2066c;
  timeval tStack_20668;
  fd_set fStack_20660;
  undefined4 uStack_205e0;
  char acStack_205d8 [1452];
  char acStack_2002c [131080];
  
  uStack_20678 = 0;
  pcVar1 = strstr(param_1,"<PushDCHEvent>");
  if (pcVar1 == (char *)0x0) {
    if (stderr != 0) {
      fwrite("MDB Set Event Fail: Content not valid\n",1,0x26,(FILE *)stderr);
    }
  }
  else {
[32m    unlink("/tmp/.hnap_push_event.xml");[0m
[32m    __s = fopen("/tmp/.hnap_push_event.xml","wb");[0m
    fwrite("<PushDCHEventList>",1,0x12,__s);
    sVar2 = strlen(pcVar1);
    fwrite(pcVar1,1,sVar2,__s);
    fwrite("</PushDCHEventList>",1,0x13,__s);
    fclose(__s);
    iVar3 = ixmlLoadDocument("/tmp/.hnap_push_event.xml");
    if (iVar3 == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_00409d5c(iVar3,"PushDCHEventList");
      iVar9 = 0;
      if (iVar8 == 0) {
        iVar8 = 0;
      }
      else {
        uVar4 = ixmlNode_getFirstChild(iVar3);
        iVar8 = ixmlNode_cloneNode(uVar4,1);
        if (iVar8 == 0) {
          iVar9 = 0;
        }
        else {
          iVar9 = ixmlNodetoString(iVar8);
          if (iVar9 != 0) {
[32m            memset(acStack_2002c,0,0x20000);[0m
            sprintf(acStack_2002c,
                    "<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope %s %s %s><soap:Body>%s</soap:Body></soap:Envelope>"
                    ,"xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"",
                    "xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"",
[32m[32m                    "xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\"",iVar9);[0m[0m
            cfgRead(&DAT_0040b1ac,&DAT_0040b1b4,&uStack_20678);
            uStack_20674 = 0xffffffff;
            iStack_20670 = 0;
[32m            sStack_2066c = 0;[0m
            uStack_205e0._0_1_ = 0;
[32m            memset((void *)((int)&uStack_205e0 + 1),0,0x5b3);[0m
            iVar5 = FUN_004095f0(&uStack_20674,&DAT_0040c070,0x50,acStack_2002c);
            if (iVar5 != -1) {
[32m              memset(&uStack_205e0,0,0x5b4);[0m
              iVar5 = FUN_004098b8(uStack_20674,&uStack_205e0,0x5b4);
              if (iVar5 == 0) {
[32m[32m                sscanf(acStack_205d8,"%d",&iStack_20670);[0m[0m
                if (iStack_20670 == 200) {
                  pcVar1 = strstr((char *)&uStack_205e0,"Content-Length:");
                  if (pcVar1 != (char *)0x0) {
[32m[32m                    sscanf(pcVar1 + 0x10,"%d",&sStack_2066c);[0m[0m
                    if (0x5b3 < sStack_2066c) {
[32m                      sStack_2066c = 3;[0m
                    }
[32m                    sVar2 = sStack_2066c;[0m
                    tStack_20668.tv_sec = 5;
                    tStack_20668.tv_usec = 0;
                    p_Var6 = (__fd_mask *)&fStack_20660;
                    do {
                      *p_Var6 = 0;
                      p_Var6 = p_Var6 + 1;
                    } while (p_Var6 != &uStack_205e0);
                    fStack_20660.fds_bits[uStack_20674 >> 5] =
                         fStack_20660.fds_bits[uStack_20674 >> 5] | 1 << (uStack_20674 & 0x1f);
[32m                    memset(&uStack_205e0,0,0x5b4);[0m
                    iVar5 = 0;
                    if (0 < (int)sVar2) {
                      while( true ) {
                        iVar7 = select(uStack_20674 + 1,&fStack_20660,(fd_set *)0x0,(fd_set *)0x0,
                                       &tStack_20668);
                        if (iVar7 < 0) break;
                        if ((int)sVar2 < 0x5b5) {
[32m[32m                          iVar7 = recv(uStack_20674,(void *)((int)&uStack_205e0 + iVar5),sVar2,0);[0m[0m
                        }
                        else {
[32m[32m                          iVar7 = recv(uStack_20674,(void *)((int)&uStack_205e0 + iVar5),0x5b4,0);[0m[0m
                        }
[32m                        sVar2 = sVar2 - iVar7;[0m
                        if ((iVar7 < 1) || (iVar5 = iVar5 + iVar7, (int)sVar2 < 1)) break;
                      }
                    }
                  }
                }
              }
            }
            if (uStack_20674 != 0xffffffff) {
              close(uStack_20674);
            }
            uStack_20674 = 0xffffffff;
          }
        }
      }
      ixmlDocument_free(iVar3);
      if (iVar9 != 0) {
        ixmlFreeDOMString(iVar9);
      }
    }
    if (iVar8 != 0) {
      ixmlNode_free(iVar8);
    }
[32m    unlink("/tmp/.hnap_push_event.xml");[0m
  }
  return;
}

[ASK_GPT] 9c4608916e0316a4
