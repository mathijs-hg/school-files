
int ubiutils_srand(void)

{
  int iVar1;
  __pid_t _Var2;
  int iVar3;
  timezone tz;
  timeval tv;
  
  iVar1 = gettimeofday((timeval *)&tv,(__timezone_ptr_t)&tz);
  iVar3 = -1;
  if (iVar1 == 0) {
    _Var2 = getpid();
[32m[32m    srand((uint)(_Var2 * (tv.tv_sec + tv.tv_usec)) % 0x7fffffff);[0m[0m
    iVar3 = 0;
  }
  return iVar3;
}

[ASK_GPT] 67a21e7a5457fc53
