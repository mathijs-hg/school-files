
undefined4 FUN_00401120(undefined4 param_1)

{
  int __fd;
  int *piVar1;
  undefined4 uVar2;
  __pid_t _Var3;
  size_t __n;
  char acStack_90 [132];
  
[32m[32m  sprintf(acStack_90,"/var/run/ipfind-%s.pid",param_1);[0m[0m
[32m  __fd = open(acStack_90,0x501,0x284);[0m
  if (__fd < 0) {
    piVar1 = __errno_location();
    if (*piVar1 == 0x11) {
      fprintf(stderr,"Error!! ipfind(%s) may be in running\n",param_1);
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  else {
    _Var3 = getpid();
[32m    sprintf(acStack_90,"%d",_Var3);[0m
    __n = strlen(acStack_90);
    write(__fd,acStack_90,__n);
    close(__fd);
    uVar2 = 0;
  }
  return uVar2;
}

[ASK_GPT] e0757da78802db90
