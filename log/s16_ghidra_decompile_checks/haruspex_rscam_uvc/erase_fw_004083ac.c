
int erase_fw(undefined4 param_1)

{
  int __fd;
  int iVar1;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined auStack_28 [32];
  
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  __fd = uvc_open_device(param_1);
  if (__fd < 1) {
    fwrite("Open Device Fail\n",1,0x11,stderr);
  }
  else {
    iVar1 = uvc_spi_sf_disable_wp(__fd);
    if (iVar1 == 0) {
      iVar1 = uvc_spi_sf_erase_chip(__fd);
      if (iVar1 == 0) {
[32m        iVar1 = uvc_spi_sf_read(__fd,0,0x20,&local_48);[0m
        if (iVar1 < 0) {
          fwrite("usb_vc_spi_sf_read fail\n",1,0x18,stderr);
        }
        else {
[32m          memset(auStack_28,0xff,0x20);[0m
          FUN_0040895c(&local_48,0x20);
          iVar1 = memcmp(auStack_28,&local_48,0x20);
          if (iVar1 != 0) {
            fwrite("Erase flash fail, compare fail\n",1,0x1f,stderr);
          }
        }
      }
      else {
        fwrite("Erase flash fail\n",1,0x11,stderr);
      }
    }
    else {
      fwrite("Disabe write protect fail\n",1,0x1a,stderr);
    }
  }
  iVar1 = uvc_spi_sf_enable_wp(__fd);
  if (iVar1 != 0) {
    fwrite("Enable write protect fail\n",1,0x1a,stderr);
  }
  if (0 < __fd) {
    close(__fd);
  }
  return iVar1;
}

[ASK_GPT] 0ceabdc9d89a0b8a
