
int uvc_download_fm(undefined4 param_1,void *param_2,size_t param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint local_5c;
  uint local_58;
  void *local_54;
  
  local_54 = (void *)0x0;
  iVar1 = uvc_spi_sf_disable_wp(param_1);
  if (iVar1 == 0) {
    uvc_spi_sf_erase_chip(param_1);
    iVar1 = check_erase_result(param_1,0,5000);
    if (iVar1 == 0) {
[32m      local_54 = malloc(param_3);[0m
      if (local_54 == (void *)0x0) {
        fwrite("Alloc memory fail\n",1,0x12,stderr);
      }
      else {
        fwrite("----:Write  Firmware    \n",1,0x19,stdout);
        fflush(stdout);
        local_58 = 0;
        local_5c = 0x1000;
        while (local_58 < param_3) {
          uVar2 = local_5c;
          if (param_3 - local_58 < 0x1001) {
            uVar2 = param_3 - local_58;
          }
          iVar1 = uvc_spi_sf_write(param_1,local_58,uVar2 & 0xffff,(int)param_2 + local_58);
          if (iVar1 != 0) {
            fwrite("Write Firmware        [fail!]\n",1,0x1e,stdout);
            fflush(stdout);
            goto LAB_004071cc;
          }
          local_58 = local_58 + uVar2;
          uVar2 = (uint)DAT_00429530;
          DAT_00429530 = DAT_00429530 + 1;
          uVar3 = (local_58 * 100) / param_3;
          if (param_3 == 0) {
            trap(0x1c00);
          }
          fprintf(stdout,"\r%s%s%c  %3d","----:","Write  Firmware    ",
                  (int)(char)(&DAT_004291e0)[uVar2 & 3],uVar3);
          fflush(stdout);
          if (param_3 == 0) {
            trap(0x1c00);
          }
          if ((local_58 * 100) / param_3 == 100) {
            if (param_3 == 0) {
              trap(0x1c00);
            }
            fprintf(stdout,"\r%s%s  %3d","----:","Write  Firmware    ",(local_58 * 100) / param_3,
                    uVar3);
            fflush(stdout);
            fprintf(stdout,"\r%s%s   SUCCESS\n","----:","Write  Firmware    ");
            fflush(stdout);
          }
        }
        fwrite("----:Verify Frimware    \n",1,0x19,stdout);
        fflush(stdout);
        memset(local_54,0,param_3);
        local_58 = 0;
        local_5c = 0x1000;
        while (local_58 < param_3) {
          uVar2 = local_5c;
          if (param_3 - local_58 < 0x1001) {
            uVar2 = param_3 - local_58;
          }
[32m          iVar1 = uvc_spi_sf_read(param_1,local_58,uVar2 & 0xffff,(int)local_54 + local_58);[0m
          if (iVar1 != 0) goto LAB_004071cc;
          local_58 = local_58 + uVar2;
          uVar2 = (uint)DAT_00429530;
          DAT_00429530 = DAT_00429530 + 1;
          uVar3 = (local_58 * 100) / param_3;
          if (param_3 == 0) {
            trap(0x1c00);
          }
          fprintf(stdout,"\r%s%s%c  %3d","----:","Read Frimware    ",
                  (int)(char)(&DAT_004291e0)[uVar2 & 3],uVar3);
          fflush(stdout);
          if (param_3 == 0) {
            trap(0x1c00);
          }
          if ((local_58 * 100) / param_3 == 100) {
            if (param_3 == 0) {
              trap(0x1c00);
            }
            fprintf(stdout,"\r%s%s  %3d","----:","Read Frimware    ",(local_58 * 100) / param_3,
                    uVar3);
            fflush(stdout);
            fprintf(stdout,"\r%s%s   SUCCESS\n","----:","Read Frimware    ");
            fflush(stdout);
          }
        }
[32m        iVar1 = memcmp(param_2,local_54,param_3);[0m
        if (iVar1 == 0) {
          fprintf(stdout,"\r%s%s   SUCCESS\n","----:","Verify Frimware    ");
          fflush(stdout);
          iVar1 = uvc_write_spi_sf_tag(param_1);
          if (iVar1 != 0) {
            fwrite("Write flash tag fail\n",1,0x15,stderr);
          }
        }
        else {
          fwrite("Verify Firmware       [Compare fail!]!\n",1,0x27,stdout);
          fflush(stdout);
        }
      }
    }
    else {
      fwrite("Erase fail\n",1,0xb,stderr);
    }
  }
  else {
    fwrite("Disabe write protect fail\n",1,0x1a,stderr);
  }
LAB_004071cc:
  iVar1 = uvc_spi_sf_enable_wp(param_1);
  if (iVar1 != 0) {
    fwrite("Enable write protect fail\n",1,0x1a,stderr);
  }
  if (local_54 != (void *)0x0) {
    free(local_54);
  }
  return iVar1;
}

[ASK_GPT] fda6eb322532a3a2
