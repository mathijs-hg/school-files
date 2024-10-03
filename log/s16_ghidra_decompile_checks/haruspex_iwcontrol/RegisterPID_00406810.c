
undefined4 RegisterPID(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined *puVar4;
  __pid_t local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  __pid_t *local_24;
  undefined2 local_20;
  
  puVar4 = &_gp;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
[32m[32m[32m  strncpy((char *)&local_34,param_2,0x10);[0m[0m[0m
  local_38 = getpid();
  local_24 = &local_38;
  local_20 = 4;
  iVar1 = ioctl(param_1,0x8b3e,&local_34,param_4,puVar4);
  uVar3 = 1;
  if (iVar1 < 0) {
    piVar2 = __errno_location();
    strerror(*piVar2);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

[ASK_GPT] fc761e9fb430f03e
