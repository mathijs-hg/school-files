
int sf_read(undefined4 param_1,undefined4 param_2,ushort param_3)

{
  int __fd;
  void *local_18;
  int local_10;
  
  __fd = uvc_open_device(param_1);
  if (__fd < 0) {
    fwrite("Open Device Fail\n",1,0x11,stderr);
    local_10 = __fd;
  }
  else {
[32m    local_18 = malloc((uint)param_3);[0m
    if (local_18 == (void *)0x0) {
      fwrite("Malloc Memory Fail\n",1,0x13,stderr);
      local_10 = -1;
    }
    else {
[32m      local_10 = uvc_spi_sf_read(__fd,param_2,param_3,local_18);[0m
      if (local_10 == 0) {
        FUN_0040895c(local_18,param_3);
      }
      else {
        fprintf(stderr,"uvc_spi_sf_read fail.ret = %d\n",local_10);
      }
    }
  }
  if (0 < __fd) {
    close(__fd);
  }
  if (local_18 != (void *)0x0) {
    free(local_18);
  }
  return local_10;
}

[ASK_GPT] 593b377b55af73fb
