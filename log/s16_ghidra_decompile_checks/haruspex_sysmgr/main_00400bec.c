
undefined4 main(void)

{
  int iVar1;
  int *piVar2;
  __pid_t _Var3;
  size_t __n;
  undefined4 local_28;
  char acStack_24 [24];
  
  local_28 = 0;
  fprintf(stderr,"[%s][%s][%d]Start\n","sysmgr",&DAT_00401750,0x43);
[32m  signal(2,FUN_00400b90);[0m
[32m  signal(0xf,FUN_00400b90);[0m
[32m  signal(3,FUN_00400b90);[0m
[32m  signal(0xd,(__sighandler_t)0x1);[0m
[32m  signal(0xb,FUN_00400ebc);[0m
[32m  iVar1 = open("/var/run/sysmgr.pid",0x501,0x284);[0m
  if (iVar1 < 0) {
    piVar2 = __errno_location();
    if (*piVar2 == 0x11) {
      fprintf(stderr,"[%s][%s][%d]Is already running\n","sysmgr","MkSysmagPIDFile",0x30);
    }
  }
  else {
    _Var3 = getpid();
[32m    sprintf(acStack_24,"%d",_Var3);[0m
    __n = strlen(acStack_24);
    write(iVar1,acStack_24,__n);
    close(iVar1);
    iVar1 = sysmsg_InitialMsg(&local_28);
    if (iVar1 < 0) {
      fprintf(stderr,"[%s][%s][%d]Create message queue fail!\n","sysmgr",&DAT_00401750,0x50);
    }
    else {
      iVar1 = sysfun_init();
      if (iVar1 < 0) {
        fprintf(stderr,"[%s][%s][%d]Init fail!\n","sysmgr",&DAT_00401750,0x56);
      }
      else {
        sysmsg_MsgManager(local_28);
      }
    }
  }
  sysfun_uninit();
  sysmsg_UninitialMsg(&local_28);
[32m  unlink("/var/run/sysmgr.pid");[0m
  fprintf(stderr,"[%s][%s][%d]Exit\n","sysmgr",&DAT_00401750,0x61);
  return 0;
}

[ASK_GPT] 1490ca5246e36ac9
