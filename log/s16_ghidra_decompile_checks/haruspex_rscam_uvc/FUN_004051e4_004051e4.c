
int FUN_004051e4(int param_1)

{
  ushort uVar1;
  FILE *pFVar2;
  undefined4 uVar3;
  int local_30;
  timeval local_2c;
  timeval local_24 [2];
  
  if (param_1 == 0) {
    __assert("cmd","/home/ming_qian/repos-home/RsCamLib/tools/uvc_tool/rscam_uvc.c",0x105);
  }
  gettimeofday(&local_2c,(__timezone_ptr_t)0x0);
  switch(*(undefined2 *)(param_1 + 8)) {
  case 1:
    local_30 = download_fw(g_devname,param_1 + 0x18);
    break;
  case 2:
    local_30 = erase_fw(g_devname);
    break;
  case 3:
    local_30 = reset_dev(g_devname,*(undefined2 *)(param_1 + 10));
    break;
  case 4:
    local_30 = print_dev_status(g_devname,*(ushort *)(param_1 + 10) & 0xff);
    break;
  case 5:
    local_30 = read_mem(g_devname,*(uint *)(param_1 + 0xc) & 0xffff,*(undefined2 *)(param_1 + 0x10))
    ;
    break;
  case 6:
    local_30 = write_mem(g_devname,*(uint *)(param_1 + 0xc) & 0xffff,*(undefined2 *)(param_1 + 0x10)
                         ,*(undefined4 *)(param_1 + 0x14));
    break;
  case 7:
    local_30 = read_sensor_reg(g_devname,*(uint *)(param_1 + 0xc) & 0xffff);
    break;
  case 8:
    local_30 = write_sensor_reg(g_devname,*(uint *)(param_1 + 0xc) & 0xffff,
                                *(undefined2 *)(param_1 + 10));
    break;
  case 9:
    local_30 = sf_read_id(g_devname);
    break;
  case 10:
    local_30 = sf_read_sr(g_devname);
    break;
  case 0xb:
    local_30 = sf_write_sr(g_devname,*(undefined2 *)(param_1 + 10));
    break;
  case 0xc:
[32m    local_30 = sf_read(g_devname,*(undefined4 *)(param_1 + 0xc),*(undefined2 *)(param_1 + 0x10));[0m
    break;
  case 0xd:
    local_30 = sf_write(g_devname,*(undefined4 *)(param_1 + 0xc),*(undefined2 *)(param_1 + 0x10),
                        *(undefined4 *)(param_1 + 0x14));
    break;
  case 0xe:
    local_30 = sf_disable_wp(g_devname);
    break;
  case 0xf:
    local_30 = sf_enable_wp(g_devname);
    break;
  case 0x10:
    local_30 = get_fw_version(g_devname);
    break;
  case 0x11:
    local_30 = erase_blk(g_devname,*(undefined4 *)(param_1 + 0xc));
    break;
  case 0x12:
    local_30 = get_device_modalias(g_devname,0,0,0);
    break;
  case 0x13:
    local_30 = rts_dump_fw_uvc(g_devname,*(undefined2 *)(param_1 + 10));
    break;
  case 0x20:
    local_30 = rts_mjpeg_q_set(g_devname,*(ushort *)(param_1 + 10) & 0xff);
    break;
  case 0x21:
    local_30 = rts_mjpeg_q_get(g_devname,0);
    break;
  case 0x22:
    local_30 = rts_crop_start_set(g_devname,*(uint *)(param_1 + 0xc) & 0xffff,
                                  *(undefined2 *)(param_1 + 0x10));
    break;
  case 0x23:
    local_30 = rts_crop_start_get(g_devname,0,0);
  }
  if (local_30 == 0) {
    gettimeofday(local_24,(__timezone_ptr_t)0x0);
    pFVar2 = stdout;
    uVar1 = *(ushort *)(param_1 + 8);
    uVar3 = FUN_00405154(local_2c.tv_sec,local_2c.tv_usec,local_24[0].tv_sec,local_24[0].tv_usec);
    fprintf(pFVar2,"Cmd %d success. Use time:%d\n",(uint)uVar1,uVar3);
  }
  else {
    gettimeofday(local_24,(__timezone_ptr_t)0x0);
    pFVar2 = stderr;
    uVar1 = *(ushort *)(param_1 + 8);
    uVar3 = FUN_00405154(local_2c.tv_sec,local_2c.tv_usec,local_24[0].tv_sec,local_24[0].tv_usec);
    fprintf(pFVar2,"Cmd %d fail. Use time:%d\n",(uint)uVar1,uVar3);
  }
  return local_30;
}

[ASK_GPT] 5fdf81f8d5db918f
