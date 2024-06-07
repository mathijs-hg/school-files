
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffc74 : 0x004058b0 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 iw_get_range_info(int param_1,char *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_4c4 [16];
  undefined4 *local_4b4;
  ushort local_4b0;
  undefined2 local_4ae;
  undefined4 local_4a4;
  undefined4 local_4a0;
  undefined4 local_49c;
  undefined auStack_498 [132];
  undefined4 local_414;
  undefined4 local_410;
  undefined auStack_40c [36];
  undefined auStack_3e8 [56];
  undefined4 local_3b0;
  undefined auStack_3ac [32];
  byte bStack_38c;
  undefined4 local_374;
  
[32m  memset(&local_4a4,0,0x498);[0m
  local_4b4 = &local_4a4;
  local_4b0 = 0x498;
  local_4ae = 0;
[32m[32m[32m  strncpy(acStack_4c4,param_2,0x10);[0m[0m[0m
  iVar1 = ioctl(param_1,0x8b0b,acStack_4c4);
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    if (local_4b0 < 300) {
      bStack_38c = 9;
    }
    if (bStack_38c < 0x10) {
[32m      memset(param_3,0,0x24c);[0m
      *param_3 = local_4a4;
      param_3[1] = local_4a0;
      param_3[2] = local_49c;
[32m[32m      memcpy(param_3 + 0x4c,auStack_498,0x84);[0m[0m
      param_3[10] = local_414;
      param_3[0xb] = local_410;
[32m[32m      memcpy(param_3 + 0xd,auStack_40c,0x24);[0m[0m
[32m[32m      memcpy(param_3 + 0x2e,auStack_3e8,0x38);[0m[0m
      *(undefined4 *)((int)param_3 + 0xf2) = local_3b0;
[32m[32m      memcpy(param_3 + 0x3e,auStack_3ac,0x38);[0m[0m
      param_3[0xc] = local_374;
    }
    else {
[32m[32m      memcpy(param_3,&local_4a4,0x24c);[0m[0m
    }
    if (iw_ignore_version == 0) {
      if (*(byte *)(param_3 + 0x46) < 0xb) {
        fprintf(stderr,"Warning: Driver for device %s has been compiled with an ancient version\n",
                param_2);
        fwrite("of Wireless Extension, while this program support version 11 and later.\n",1,0x48,
               stderr);
        fwrite("Some things may be broken...\n\n",1,0x1e,stderr);
      }
      if (0x16 < *(byte *)(param_3 + 0x46)) {
        fprintf(stderr,"Warning: Driver for device %s has been compiled with version %d\n",param_2,
                (uint)*(byte *)(param_3 + 0x46));
        fprintf(stderr,"of Wireless Extension, while this program supports up to version %d.\n",0x16
               );
        fwrite("Some things may be broken...\n\n",1,0x1e,stderr);
      }
      if ((10 < *(byte *)(param_3 + 0x46)) &&
         (*(byte *)(param_3 + 0x46) < *(byte *)((int)param_3 + 0x119))) {
        fprintf(stderr,"Warning: Driver for device %s recommend version %d of Wireless Extension,\n"
                ,param_2,(uint)*(byte *)((int)param_3 + 0x119));
        fprintf(stderr,"but has been compiled with version %d, therefore some driver features\n",
                (uint)*(byte *)(param_3 + 0x46));
        fwrite("may not be available...\n\n",1,0x19,stderr);
      }
    }
    iw_ignore_version = 1;
    uVar2 = 0;
  }
  return uVar2;
}

[ASK_GPT] 682fdd40ecb930f9
