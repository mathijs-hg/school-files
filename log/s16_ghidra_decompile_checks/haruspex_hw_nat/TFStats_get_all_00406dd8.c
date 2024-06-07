
undefined4 TFStats_get_all(void *param_1)

{
  int __fd;
  undefined4 uVar1;
  int iVar2;
  byte *pbVar3;
  int local_18;
  
[32m  __fd = open("/dev/hwnat0",0);[0m
  if (__fd < 0) {
    printf("Open %s pseudo device failed\n","/dev/hwnat0");
    free(param_1);
    uVar1 = 1;
  }
  else {
    iVar2 = ioctl(__fd,0x2b,param_1);
    if (iVar2 < 0) {
      puts("HW_NAT_API: ioctl error");
      close(__fd);
      free(param_1);
      uVar1 = 1;
    }
    else {
      close(__fd);
      printf("tf_opt->array_length=%d\n",(uint)*(ushort *)((int)param_1 + 0x50));
      if (*(short *)((int)param_1 + 0x50) != 0) {
        for (local_18 = 0; local_18 < (int)(uint)*(ushort *)((int)param_1 + 0x50);
            local_18 = local_18 + 1) {
          pbVar3 = (byte *)((int)param_1 + local_18 * 0x38 + 0x58);
          printf("mac:%02x:%02x:%02x:%02x:%02x:%02x\n",(uint)*pbVar3,(uint)pbVar3[1],(uint)pbVar3[2]
                 ,(uint)pbVar3[3],(uint)pbVar3[4],(uint)pbVar3[5]);
          printf("total upload %lld bytes, ");
          printf("total download %lld bytes\n");
          printf("upload speed %lld bytes/s, ");
          printf("download speed %lld bytes/s\n ");
          printf("total_pkts is %lld,");
          printf("recent_pkts is %lld\n");
        }
      }
      puts("sta info:");
      printf("rx: %lld bytes, %lld bytes/s, %lld pkts, %lld pkts/s\n",
             *(undefined4 *)((int)param_1 + 0x44),*(undefined4 *)((int)param_1 + 0x10),
             *(undefined4 *)((int)param_1 + 0x14),*(undefined4 *)((int)param_1 + 0x20),
             *(undefined4 *)((int)param_1 + 0x24),*(undefined4 *)((int)param_1 + 0x30),
             *(undefined4 *)((int)param_1 + 0x34),*(undefined4 *)((int)param_1 + 0x40),
             *(undefined4 *)((int)param_1 + 0x44));
      printf("tx: %lld bytes, %lld bytes/s, %lld pkts, %lld pkts/s\n",
             *(undefined4 *)((int)param_1 + 0x4c),*(undefined4 *)((int)param_1 + 0x18),
             *(undefined4 *)((int)param_1 + 0x1c),*(undefined4 *)((int)param_1 + 0x28),
             *(undefined4 *)((int)param_1 + 0x2c),*(undefined4 *)((int)param_1 + 0x38),
             *(undefined4 *)((int)param_1 + 0x3c),*(undefined4 *)((int)param_1 + 0x48),
             *(undefined4 *)((int)param_1 + 0x4c));
      free(param_1);
      uVar1 = 0;
    }
  }
  return uVar1;
}

[ASK_GPT] 9db7bb56a6edec45
