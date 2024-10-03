
undefined4 main(void)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  __pid_t _Var4;
  size_t __n;
  undefined4 local_30;
  ushort local_2c;
  undefined local_2a;
  char local_29;
  int local_28;
  undefined4 local_24;
  itimerval local_20;
  
  local_30 = 0x123456;
  local_2c = 0x7890;
  local_2a = 0;
  g_State = 0x80;
  HWMIB_getRegion(&local_2a);
  iVar1 = FUN_004018a4(&local_28);
  if ((iVar1 < 0) || (local_28 == 0)) {
    HWMIB_getMAC(&local_30);
  }
  else {
    local_2c = local_2c & 0xff00 | (ushort)(byte)local_28;
  }
  iVar1 = brctlAddBr(&DAT_00404718);
  if (iVar1 < 0) {
    piVar2 = __errno_location();
    if (*piVar2 != 0x11) {
      pcVar3 = strerror(*piVar2);
      printf("[%s] brctlAddBr error!! %s\n","netmgr",pcVar3);
      return 0xffffffff;
    }
    printf("[%s] %s is exist\n","netmgr",&DAT_00404718);
  }
  local_24 = 0;
  iVar1 = InitialMsg(&local_24);
  if (iVar1 < 0) {
    printf("[%s] create message queue fail!\n","netmgr");
  }
  else {
    brctlSetSTP(&DAT_00404718,0);
    brctlSetForwardDelay(&DAT_00404718,1);
    net_up(&DAT_00404718);
    net_set_hwaddr(&DAT_00404778,&local_30);
    net_set_ifaddr(&DAT_00404778,0);
    net_up(&DAT_00404778);
    iVar1 = WExist();
    if (iVar1 != 0) {
      net_set_hwaddr("wlan0",&local_30);
      SetCountryRegion("wlan0",local_2a);
      net_set_ifaddr("wlan0",0);
      net_set_hwaddr("wlan0-vxd",&local_30);
      SetCountryRegion("wlan0-vxd",local_2a);
      net_set_ifaddr("wlan0-vxd",0);
    }
    WSCGenPin();
[32m    _Var4 = fork();[0m
    if (_Var4 < 0) {
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    if (0 < _Var4) {
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
[32m    signal(2,FUN_00401854);[0m
[32m    signal(0xf,FUN_00401854);[0m
[32m    signal(3,FUN_00401854);[0m
[32m    iVar1 = open("/var/run/netmgr.pid",0x501,0x284);[0m
    if (iVar1 < 0) {
      piVar2 = __errno_location();
      if (*piVar2 == 0x11) {
        puts("it may be in running");
        return 0xffffffff;
      }
    }
    else {
      _Var4 = getpid();
[32m      sprintf((char *)&local_20,"%d",_Var4);[0m
      __n = strlen((char *)&local_20);
      write(iVar1,&local_20,__n);
      close(iVar1);
      local_29 = '\0';
      cfgRead("WIRELESS_AP","Enable",&local_29);
      g_State = g_State & 0xcf | (local_29 != '\0') << 4 | (local_29 != '\0') << 5;
[32m      signal(0xe,FUN_00401700);[0m
      local_20.it_value.tv_sec = 0;
      local_20.it_value.tv_usec = 100000;
      local_20.it_interval.tv_sec = 0;
      local_20.it_interval.tv_usec = 100000;
      iVar1 = setitimer(ITIMER_REAL,&local_20,(itimerval *)0x0);
      if (iVar1 == 0) {
        MsgManager(local_24);
[32m        unlink("/var/run/netmgr.pid");[0m
        return 0;
      }
    }
  }
  return 0xffffffff;
}

[ASK_GPT] 42877ad5eaa696d6
