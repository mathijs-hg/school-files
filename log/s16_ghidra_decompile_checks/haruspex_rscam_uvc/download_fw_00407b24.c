
int download_fw(undefined4 param_1,char *param_2)

{
  FILE *pFVar1;
  undefined4 uVar2;
  size_t __size;
  int iVar3;
  FILE *local_28;
  void *local_24;
  int local_1c;
  int local_18;
  
  pFVar1 = stdout;
  local_18 = -1;
  local_24 = (void *)0x0;
  local_28 = (FILE *)0x0;
  uVar2 = get_cur_time();
  fprintf(pFVar1,"----:%s : Download firmware begin!\n",uVar2);
  fflush(stdout);
  local_1c = uvc_open_device(param_1);
  if (local_1c < 0) {
    fprintf(stderr,"Open Device:%s Fail.\n",param_1);
    local_18 = local_1c;
  }
  else {
    __size = FUN_00407860(param_2);
    if ((int)__size < 1) {
      fwrite("Please specify firmware file!\n",1,0x1e,stderr);
      local_18 = -1;
    }
    else {
[32m      local_24 = malloc(__size);[0m
[32m      if ((local_24 != (void *)0x0) && (local_28 = fopen(param_2,"rb"), local_28 != (FILE *)0x0)) {[0m
[32m[32m        fread(local_24,1,__size,local_28);[0m[0m
        local_18 = FUN_004061e4(local_1c);
        if (local_18 == 0) {
          local_18 = uvc_reset_device(local_1c,1);
          if (local_18 == 0) {
            uvc_close_device(local_1c);
            local_1c = -1;
            sleep(2);
            iVar3 = FUN_004078e4(param_1,3000);
            if (iVar3 == 0) {
              local_1c = uvc_open_device(param_1);
              if (local_1c < 0) {
                fwrite("Open Device Fail\n",1,0x11,stderr);
                local_18 = local_1c;
              }
              else {
[32m                local_18 = uvc_download_fm(local_1c,local_24,__size);[0m
              }
            }
            else {
              fwrite("Timeout\n",1,8,stderr);
              local_18 = -1;
            }
          }
          else {
            fwrite("++++:reset 2 updatefw mode fail\n",1,0x20,stdout);
            fflush(stdout);
          }
        }
        else {
          fwrite("++++:rts_reset_preset fail\n",1,0x1b,stdout);
          fflush(stdout);
        }
      }
    }
  }
  pFVar1 = stdout;
  if (local_18 == 0) {
    uVar2 = get_cur_time();
    fprintf(pFVar1,"----:%s : Download firmware Success!\n",uVar2);
    fflush(stdout);
    print_success();
  }
  else {
    uVar2 = get_cur_time();
    fprintf(pFVar1,"++++:%s : Download firmware fail!\n",uVar2);
    fflush(stdout);
    print_fail();
  }
  if ((0 < local_1c) && (iVar3 = uvc_reset_device(local_1c,3), iVar3 != 0)) {
    fwrite("Reset device Fail\n",1,0x12,stderr);
  }
  if (0 < local_1c) {
    uvc_close_device(local_1c);
  }
  if (local_28 != (FILE *)0x0) {
    fclose(local_28);
  }
  if (local_24 != (void *)0x0) {
    free(local_24);
  }
  return local_18;
}

[ASK_GPT] 2d4d15c5047d20be
