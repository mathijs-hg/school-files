
undefined4 FUN_004078e4(char *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int __fd;
  undefined *puVar1;
  timeval local_1c;
  timeval local_14;
  
  puVar1 = &_gp;
  gettimeofday(&local_1c,(__timezone_ptr_t)0x0);
  while( true ) {
[32m    __fd = open(param_1,2,param_3,param_4,puVar1);[0m
    if (0 < __fd) {
      if (0 < __fd) {
        close(__fd);
      }
      return 0;
    }
    gettimeofday(&local_14,(__timezone_ptr_t)0x0);
    if (param_2 < ((local_14.tv_sec - local_1c.tv_sec) * 1000 + local_14.tv_usec / 1000) -
                  local_1c.tv_usec / 1000) break;
    usleep(10000);
  }
  return 0xffffffff;
}

[ASK_GPT] b559757a2f04267c
