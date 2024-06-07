
undefined4 iw_print_version_info(int param_1)

{
  int __fd;
  undefined4 uVar1;
  int iVar2;
  
[32m  __fd = iw_sockets_open();[0m
  if (__fd < 0) {
    perror("socket");
    uVar1 = 0xffffffff;
  }
  else {
    if (param_1 != 0) {
      printf("%-8.16s  Wireless-Tools version %d\n",param_1,0x1d);
    }
    printf("          Compatible with Wireless Extension v11 to v%d.\n\n",0x16);
    iVar2 = iw_get_kernel_we_version();
    if (0xf < iVar2) {
      printf("Kernel    Currently compiled with Wireless Extension v%d.\n\n",iVar2);
    }
    iw_enum_devices(__fd,print_iface_version_info,0,0);
    close(__fd);
    uVar1 = 0;
  }
  return uVar1;
}

[ASK_GPT] e1bb710984c9f354
