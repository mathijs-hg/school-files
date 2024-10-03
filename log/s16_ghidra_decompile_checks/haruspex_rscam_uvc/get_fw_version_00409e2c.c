
int get_fw_version(undefined4 param_1)

{
  int __fd;
  uint local_a8;
  int local_a0;
  undefined auStack_9c [64];
  byte local_5c;
  byte local_59;
  byte local_58;
  byte local_57;
  byte local_56;
  byte local_55;
  byte local_54;
  byte local_51;
  byte local_50;
  byte local_4f;
  byte local_4e;
  byte local_4d;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_a0 = 0;
[32m  memset(auStack_9c,0,0x80);[0m
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  __fd = uvc_open_device(param_1);
  if (__fd < 0) {
    fwrite("Open Device Fail\n",1,0x11,stderr);
    local_a0 = __fd;
  }
  else {
    for (local_a8 = 0; (int)local_a8 < 0x10; local_a8 = local_a8 + 1) {
      local_a0 = uvc_get_dev_status(__fd,auStack_9c + local_a8 * 8,local_a8 & 0xff);
      if (local_a0 != 0) {
        fwrite("Get Dev Status Failed\n",1,0x16,stderr);
        goto LAB_0040a0f4;
      }
    }
    if ((((local_5c & 0xf) == 0) && ((local_54 & 0xf) != 0)) && ((local_54 & 0xf) != 0xb)) {
      snprintf((char *)&local_1c,0x10,"0x%02x-%02x%02x-%02x%02x",(uint)local_51,(uint)local_50,
[32m[32m               (uint)local_4f,(uint)local_4e,(uint)local_4d);[0m[0m
    }
    else {
      snprintf((char *)&local_1c,0x10,"0x%02x-%02x%02x-%02x%02x",(uint)local_59,(uint)local_58,
[32m[32m               (uint)local_57,(uint)local_56,(uint)local_55);[0m[0m
    }
    fprintf(stdout,"%s\n",&local_1c);
  }
LAB_0040a0f4:
  if (0 < __fd) {
    close(__fd);
  }
  return local_a0;
}

[ASK_GPT] 6a560aedf81d7398
