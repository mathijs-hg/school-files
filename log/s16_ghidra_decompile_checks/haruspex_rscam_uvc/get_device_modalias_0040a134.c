
undefined4
get_device_modalias(char *param_1,undefined2 *param_2,undefined2 *param_3,undefined2 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  size_t sVar3;
  FILE *__stream;
  undefined auStack_16c [64];
  char acStack_12c [256];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10 [2];
  
[32m  memset(auStack_16c,0,0x40);[0m
[32m  memset(acStack_12c,0,0x100);[0m
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
[32m  memset(&local_2c,0,0x14);[0m
  if (param_1 == (char *)0x0) {
    fwrite("devname is NULL\n",1,0x10,stderr);
    uVar1 = 0xffffffff;
  }
  else {
[32m[32m    iVar2 = access(param_1,0);[0m[0m
    if (iVar2 == 0) {
      sVar3 = strlen(param_1);
      if (sVar3 < 0x46) {
[32m        memset(auStack_16c,0,0x40);[0m
[32m[32m[32m        sscanf(param_1,"/dev/%s",auStack_16c);[0m[0m[0m
        iVar2 = memcmp("video",auStack_16c,5);
        if (iVar2 == 0) {
[32m[32m          snprintf(acStack_12c,0x100,"/sys/class/video4linux/%s/device/modalias",auStack_16c);[0m[0m
          iVar2 = FUN_00407860(acStack_12c);
          if (iVar2 < 0x13) {
            fprintf(stderr,"invalie modalias file of %s\n",auStack_16c);
            uVar1 = 0xffffffff;
          }
          else {
[32m            __stream = fopen(acStack_12c,"rb");[0m
            if (__stream == (FILE *)0x0) {
              fprintf(stderr,"open %s failed\n",acStack_12c);
              uVar1 = 0xffffffff;
            }
            else {
[32m[32m              fread(&local_2c,1,0x13,__stream);[0m[0m
              fclose(__stream);
[32m[32m              sscanf((char *)&local_2c,"usb:v%04xp%04xd%04x",&local_18,&local_14,local_10);[0m[0m
              fprintf(stdout,"vid = 0x%04x, pid = 0x%04x, bcdDevice = %x.%02x\n",local_18,local_14,
                      (int)local_10[0] >> 8,local_10[0] & 0xff);
              if (param_2 != (undefined2 *)0x0) {
                *param_2 = (short)local_18;
              }
              if (param_3 != (undefined2 *)0x0) {
                *param_3 = (short)local_14;
              }
              if (param_4 != (undefined2 *)0x0) {
                *param_4 = (short)local_10[0];
              }
              uVar1 = 0;
            }
          }
        }
        else {
          fprintf(stderr,"invalid device name : %s\n",param_1);
          uVar1 = 0xffffffff;
        }
      }
      else {
        fprintf(stderr,"%s is too long\n",param_1);
        uVar1 = 0xffffffff;
      }
    }
    else {
      fprintf(stderr,"%s is not exist\n",param_1);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

[ASK_GPT] 92d56626f64e2b07
