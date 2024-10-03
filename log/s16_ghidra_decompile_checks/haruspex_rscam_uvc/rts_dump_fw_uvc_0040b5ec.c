
int rts_dump_fw_uvc(undefined4 param_1,uint param_2)

{
  void *__s;
  int __fd;
  int iVar1;
  FILE *local_48;
  int local_3c;
  uint local_38;
  int local_34;
  char acStack_2c [36];
  
  local_34 = -1;
  local_48 = (FILE *)0x0;
  local_38 = 0x40;
  while (local_38 < param_2) {
    local_38 = local_38 << 1;
    fprintf(stdout,"file_size = %dk\n",local_38);
  }
[32m[32m  __s = malloc(local_38 * 0x400);[0m[0m
  if (__s == (void *)0x0) {
    local_34 = -1;
  }
  else {
    memset(__s,0xff,local_38 * 0x400);
[32m[32m    memcpy(acStack_2c,"rscam_fw.bin",0xd);[0m[0m
    __fd = uvc_open_device(param_1);
    if (__fd < 0) {
      fwrite("Open Device Fail\n",1,0x11,stderr);
      local_34 = __fd;
    }
    else {
      fprintf(stdout,"dump device(%s)\'s fw to %s\n",param_1,acStack_2c);
[32m      local_48 = fopen(acStack_2c,"wb");[0m
      for (local_3c = 0; local_3c < (int)local_38; local_3c = local_3c + 1) {
        iVar1 = local_3c * 0x400;
[32m        local_34 = uvc_spi_sf_read(__fd,iVar1,0x400,(void *)((int)__s + iVar1));[0m
        if (local_34 < 0) {
          fprintf(stderr,"read sf:addr =0x%x; len = %d failed : %d\n",iVar1,0x400,local_34);
          goto LAB_0040b904;
        }
      }
      fwrite(__s,1,local_38 * 0x400,local_48);
    }
LAB_0040b904:
    fclose(local_48);
    if (__s != (void *)0x0) {
      free(__s);
    }
    if (0 < __fd) {
      close(__fd);
    }
  }
  return local_34;
}

[ASK_GPT] 3d47e33269b09b11
