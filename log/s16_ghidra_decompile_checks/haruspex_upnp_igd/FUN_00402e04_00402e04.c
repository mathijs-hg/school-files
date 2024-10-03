
void FUN_00402e04(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,int param_7)

{
  undefined4 uVar1;
  int iVar2;
  size_t sVar3;
  char *__dest;
  char *__s;
  char **ppcVar4;
  
  if (param_6 != 0) {
    uVar1 = ILibCreateEmptyPacket();
    ILibAddHeaderLine(uVar1,"Server",6,"POSIX, UPnP/1.0, xxxxxxxxxxxxxxxxxxxxxxxxx",0x2a);
    for (ppcVar4 = *(char ***)(param_2 + 0x34); ppcVar4 != (char **)0x0;
        ppcVar4 = (char **)ppcVar4[5]) {
      if ((ppcVar4[1] == (char *)0x3) && (iVar2 = strncasecmp(*ppcVar4,"SID",3), iVar2 == 0)) {
[32m[32m[32m        __dest = (char *)malloc((size_t)(ppcVar4[3] + 1));[0m[0m[0m
[32m[32m        strcpy(__dest,ppcVar4[2]);[0m[0m
        ppcVar4 = (char **)ILibGetEntry(*(undefined4 *)(param_7 + 0x48),ppcVar4[2],ppcVar4[3]);
        if (ppcVar4 == (char **)0x0) goto LAB_00402f34;
        ILibSetStatusCode(uVar1,200,&DAT_00415ac4,2);
        __s = *ppcVar4;
        sVar3 = strlen(__s);
        if (0x2e < (int)sVar3) {
          sVar3 = strlen(WAN_Service);
[32m          iVar2 = strncmp(WAN_Service,__s,sVar3);[0m
          if (iVar2 == 0) {
            FUN_00402318(param_3,param_5,ppcVar4);
          }
        }
        goto LAB_00402fdc;
      }
    }
    __dest = (char *)0x0;
LAB_00402f34:
    ILibSetStatusCode(uVar1,0x19c,"Failed",6);
LAB_00402fdc:
    ILibMiniWebServerSend(param_1,uVar1);
    ILibDestructPacket(uVar1);
    ILibMiniWebServerCloseSession(param_1);
    if (__dest != (char *)0x0) {
                    /* WARNING: Treating indirect jump as call */
      free(__dest);
      return;
    }
  }
  return;
}

[ASK_GPT] 0155828b3b34c5b0
