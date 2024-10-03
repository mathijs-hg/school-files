
undefined4 get_xu_id(int param_1)

{
  int iVar1;
  int local_48;
  undefined4 local_40;
  undefined4 auStack_3c [10];
  undefined4 local_14;
  undefined4 local_10;
  
  local_40 = 4;
[32m[32m  memcpy(auStack_3c,&DAT_00418918,0x28);[0m[0m
  local_14 = 0;
  local_10 = 0;
  iVar1 = ioctl(param_1,0xc0045670,&local_40);
  if ((iVar1 != 0) ||
     (iVar1 = uvc_exec_vendor_cmd_safe(param_1,0xcd,0,&local_14,8,0,local_40), iVar1 != 0)) {
    local_48 = 0;
    while ((local_48 < 10 &&
           (iVar1 = uvc_exec_vendor_cmd_safe(param_1,0xcd,0,&local_14,8,0,auStack_3c[local_48]),
           iVar1 != 0))) {
      local_48 = local_48 + 1;
    }
    if (local_48 < 10) {
      local_40 = auStack_3c[local_48];
    }
  }
  return local_40;
}

[ASK_GPT] a9b23236721b750f
