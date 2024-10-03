
int uvc_write_to_flash(undefined4 param_1,int param_2,void *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint local_18;
  uint local_14;
  void *local_10;
  
  local_10 = (void *)0x0;
  iVar1 = uvc_spi_sf_disable_wp(param_1);
  if (iVar1 == 0) {
    uvc_spi_sf_erase_blk(param_1,param_2);
    iVar1 = check_erase_result(param_1,param_2,5000);
    if (iVar1 == 0) {
[32m      local_10 = malloc(param_4);[0m
      if (local_10 == (void *)0x0) {
        fwrite("Alloc memory fail\n",1,0x12,stderr);
      }
      else {
        fwrite("---Write Flash\n",1,0xf,stdout);
        fflush(stdout);
        local_18 = 0x1000;
        for (local_14 = 0; local_14 < param_4; local_14 = local_14 + uVar2) {
          uVar2 = local_18;
          if (param_4 - local_14 < 0x1001) {
            uVar2 = param_4 - local_14;
          }
          iVar1 = uvc_spi_sf_write(param_1,local_14 + param_2,uVar2 & 0xffff,(int)param_3 + local_14
                                  );
          if (iVar1 != 0) {
            fwrite("+++Write Flash        [fail!]\n",1,0x1e,stdout);
            fflush(stdout);
            goto LAB_004077c0;
          }
        }
        fwrite("---Write Flash   SUCCESS\n",1,0x19,stdout);
        fflush(stdout);
        fwrite("---Verify Flash\n",1,0x10,stdout);
        fflush(stdout);
        memset(local_10,0,param_4);
        local_18 = 0x1000;
        for (local_14 = 0; local_14 < param_4; local_14 = local_14 + uVar2) {
          uVar2 = local_18;
          if (param_4 - local_14 < 0x1001) {
            uVar2 = param_4 - local_14;
          }
          iVar1 = uvc_spi_sf_read(param_1,local_14 + param_2,uVar2 & 0xffff,(int)local_10 + local_14
[32m                                 );[0m
          if (iVar1 != 0) goto LAB_004077c0;
        }
        iVar1 = memcmp(param_3,local_10,param_4);
        if (iVar1 == 0) {
          fwrite("---Verify Flash   SUCCESS\n",1,0x1a,stdout);
          fflush(stdout);
        }
        else {
          fwrite("+++Verify Flash       [Compare fail!]!\n",1,0x27,stdout);
          fflush(stdout);
        }
      }
    }
    else {
      fwrite("Erase blk fail\n",1,0xf,stderr);
    }
  }
  else {
    fwrite("Disabe write protect fail\n",1,0x1a,stderr);
  }
LAB_004077c0:
  iVar1 = uvc_spi_sf_enable_wp(param_1);
  if (iVar1 != 0) {
    fwrite("Enable write protect fail\n",1,0x1a,stderr);
  }
  if (local_10 != (void *)0x0) {
    free(local_10);
  }
  return iVar1;
}

[ASK_GPT] 056c87484a959061
