
undefined4 main(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  itimerval local_20;
  
  if (param_1 == 2) {
    fprintf(stderr,"[%s] invalid arguments\n","wanip_detect");
    FUN_004009a4();
    return 0xffffffff;
  }
  if (param_1 < 3) {
    local_20.it_interval.tv_sec = 600;
  }
  else {
    iVar1 = strcmp(*(char **)(param_2 + 4),"-i");
    if ((iVar1 != 0) ||
       (local_20.it_interval.tv_sec = atoi(*(char **)(param_2 + 8)), local_20.it_interval.tv_sec < 1
       )) {
      fprintf(stderr,"[%s] invalid arguments\n","wanip_detect");
      FUN_004009a4();
      return 0xffffffff;
    }
  }
[32m  signal(2,FUN_00400960);[0m
[32m  signal(0xf,FUN_00400960);[0m
[32m  signal(3,FUN_00400960);[0m
[32m  system("/usr/sbin/ddns checkip");[0m
  SIReadBin(5,&old_addr,4);
  pcVar2 = inet_ntoa(old_addr);
  printf("[%s] WAN IP: %s, interval: %d sec(s).\n","wanip_detect",pcVar2,local_20.it_interval.tv_sec
        );
[32m  signal(0xe,FUN_00400c2c);[0m
  local_20.it_value.tv_usec = 0;
  local_20.it_interval.tv_usec = 0;
  local_20.it_value.tv_sec = local_20.it_interval.tv_sec;
  iVar1 = setitimer(ITIMER_REAL,&local_20,(itimerval *)0x0);
  if (iVar1 == 0) {
    if (DAT_00411060 == 0) {
      uVar3 = 0;
    }
    else {
      do {
        sleep(1);
        uVar3 = 0;
      } while (DAT_00411060 != 0);
    }
  }
  else {
    fprintf(stderr,"%s: Failed to create thread: timer_handle\n","wanip_detect");
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

[ASK_GPT] 7e07614ec56ffdfe
