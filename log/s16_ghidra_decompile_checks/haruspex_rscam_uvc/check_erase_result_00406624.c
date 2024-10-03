
undefined4 check_erase_result(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 local_11c;
  undefined auStack_118 [128];
  undefined auStack_98 [128];
  timeval local_18;
  timeval local_10;
  
  local_11c = 0xffffffff;
[32m  memset(auStack_118,0,0x80);[0m
[32m  memset(auStack_98,0,0x80);[0m
  gettimeofday(&local_18,(__timezone_ptr_t)0x0);
[32m  memset(auStack_98,0xff,0x80);[0m
  do {
[32m    iVar1 = uvc_spi_sf_read(param_1,param_2,0x80,auStack_118);[0m
    if (iVar1 == 0) {
      iVar1 = memcmp(auStack_118,auStack_98,0x80);
      if (iVar1 == 0) {
        local_11c = 0;
LAB_0040682c:
        printf("checkEraseResult : %d\n",local_11c);
        return local_11c;
      }
    }
    gettimeofday(&local_10,(__timezone_ptr_t)0x0);
    if (param_3 < ((local_10.tv_sec - local_18.tv_sec) * 1000 + local_10.tv_usec / 1000) -
                  local_18.tv_usec / 1000) goto LAB_0040682c;
    usleep(10000);
  } while( true );
}

[ASK_GPT] 7ddef1520ee310f1
