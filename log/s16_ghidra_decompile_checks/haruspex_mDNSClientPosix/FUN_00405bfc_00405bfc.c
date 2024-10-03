
int FUN_00405bfc(int param_1,short *param_2,int param_3,char *param_4,void *param_5)

{
  void **ppvVar1;
  char *pcVar2;
  int iVar3;
  void **ppvVar4;
  int iVar5;
  void **ppvVar6;
  
  if (param_1 == 0) {
    __assert("m != ((void *)0)","mDNSPosix.c",0x361);
  }
  if (param_2 == (short *)0x0) {
    __assert("intfAddr != ((void *)0)","mDNSPosix.c",0x362);
  }
  if (param_4 == (char *)0x0) {
    __assert("intfName != ((void *)0)","mDNSPosix.c",0x363);
  }
  if (param_3 == 0) {
    __assert("intfMask != ((void *)0)","mDNSPosix.c",0x364);
  }
[32m[32m  ppvVar1 = (void **)calloc(1,0x15b4);[0m[0m
  if (ppvVar1 == (void **)0x0) {
    iVar3 = 0x368;
  }
  else {
    pcVar2 = strdup(param_4);
    ppvVar1[0x568] = pcVar2;
    if (pcVar2 != (char *)0x0) {
      FUN_00403f00(param_2,ppvVar1 + 0x549,0);
      FUN_00403f00(param_3,ppvVar1 + 0x54e,0);
[32m[32m[32m      strncpy((char *)((int)ppvVar1 + 0x1552),param_4,0x40);[0m[0m[0m
      *(undefined *)((int)ppvVar1 + 0x1592) = *(undefined *)(param_1 + 9);
      *(undefined *)((int)ppvVar1 + 0x1593) = 1;
      *(undefined *)((int)ppvVar1 + 0x1591) = 0;
      if (ppvVar1[0x568] == (void *)0x0) {
        __assert("intf->intfName != ((void *)0)","mDNSPosix.c",0x37e);
      }
      pcVar2 = (char *)ppvVar1[0x568];
      ppvVar1[0x56a] = param_5;
      ppvVar1[0x56c] = (void *)0xffffffff;
      ppvVar1[0x56b] = (void *)0xffffffff;
      if (pcVar2 == (char *)0x0) {
        __assert("intfName != ((void *)0)","mDNSPosix.c",0x212);
      }
      ppvVar6 = *(void ***)(param_1 + 0x2174);
      while ((ppvVar4 = ppvVar1, ppvVar6 != (void **)0x0 &&
             (iVar3 = strcmp((char *)ppvVar6[0x568],pcVar2), ppvVar4 = ppvVar6, iVar3 != 0))) {
        ppvVar6 = (void **)*ppvVar6;
      }
      ppvVar1[0x548] = ppvVar4;
      if ((ppvVar4[0x56b] == (void *)0xffffffff) && (*param_2 == 2)) {
        ppvVar4 = ppvVar4 + 0x56b;
      }
      else {
        if ((ppvVar4[0x56c] != (void *)0xffffffff) || (*param_2 != 10)) {
          iVar5 = 0;
          goto LAB_00405e8c;
        }
        ppvVar4 = ppvVar4 + 0x56c;
      }
      iVar5 = FUN_004052b4(param_2,0x14e90000,ppvVar1[0x56a],ppvVar4);
      goto LAB_00405e8c;
    }
    iVar3 = 0x36e;
  }
  iVar5 = 0xc;
  __assert("0","mDNSPosix.c",iVar3);
LAB_00405e8c:
  *(undefined *)((int)ppvVar1 + 0x1599) = 1;
  *(undefined *)(ppvVar1 + 0x566) = 0;
  if ((iVar5 == 0) && (iVar5 = mDNS_RegisterInterface(param_1,ppvVar1,0), iVar5 == 0)) {
    DAT_0046e6bc = DAT_0046e6bc + 1;
    ppvVar6 = ppvVar1;
    if (0 < gMDNSPlatformPosixVerboseLevel) {
      fprintf(stderr,"Registered interface %s\n",ppvVar1[0x568]);
    }
  }
  else {
    ppvVar6 = (void **)0x0;
    FUN_00404f88(ppvVar1);
  }
  if ((ppvVar6 != (void **)0x0) != (iVar5 == 0)) {
    __assert("(err == 0) == (intf != ((void *)0))","mDNSPosix.c",0x3b3);
  }
  return iVar5;
}

[ASK_GPT] bdf988181048f0d0
