
void iw_print_stats(FLO_type param_1,FLO_type param_2,char *param_3,size_t param_4,byte *param_5_00,
                   int param_6,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  char *local_res0;
  size_t local_res4;
  uint local_28;
  uint local_24;
  
  if ((param_5 == 0) || ((param_5_00[1] == 0 && ((param_5_00[3] & 0x88) == 0)))) {
    snprintf(param_3,param_4,"Quality:%d  Signal level:%d  Noise level:%d",(uint)*param_5_00,
[32m             (uint)param_5_00[1],(uint)param_5_00[2]);[0m
  }
  else {
    local_res0 = param_3;
    local_res4 = param_4;
    if ((param_5_00[3] & 0x10) == 0) {
      if ((param_5_00[3] & 1) == 0) {
        uVar1 = 0x3a;
      }
      else {
        uVar1 = 0x3d;
      }
      iVar2 = snprintf(param_3,param_4,"Quality%c%d/%d  ",uVar1,(uint)*param_5_00,
[32m[32m[32m                       (uint)*(byte *)(param_6 + 0x2c));[0m[0m[0m
      local_res0 = param_3 + iVar2;
[32m      local_res4 = param_4 - iVar2;[0m
    }
    if ((char)param_5_00[3] < '\0') {
      if ((param_5_00[3] & 0x20) == 0) {
        uVar3 = (uint)param_5_00[1];
        pcVar4 = __floatsidf;
        __floatsidf(uVar3);
        __divdf3(param_1,param_2);
        __subdf3(param_1,param_2);
        if ((param_5_00[3] & 2) == 0) {
          uVar1 = 0x3a;
        }
        else {
          uVar1 = 0x3d;
        }
[32m[32m[32m        iVar2 = snprintf(local_res0,local_res4,"Signal level%c%g dBm  ",uVar1,pcVar4,uVar3);[0m[0m[0m
        local_res0 = local_res0 + iVar2;
[32m        local_res4 = local_res4 - iVar2;[0m
      }
      if ((param_5_00[3] & 0x40) == 0) {
        uVar3 = (uint)param_5_00[2];
        pcVar4 = __floatsidf;
        __floatsidf(uVar3);
        __divdf3(param_1,param_2);
        __subdf3(param_1,param_2);
        if ((param_5_00[3] & 4) == 0) {
          uVar1 = 0x3a;
        }
        else {
          uVar1 = 0x3d;
        }
[32m        snprintf(local_res0,local_res4,"Noise level%c%g dBm",uVar1,pcVar4,uVar3);[0m
      }
    }
    else if (((param_5_00[3] & 8) == 0) && (param_5_00[1] <= *(byte *)(param_6 + 0x2d))) {
      if ((param_5_00[3] & 0x20) == 0) {
        if ((param_5_00[3] & 2) == 0) {
          uVar1 = 0x3a;
        }
        else {
          uVar1 = 0x3d;
        }
        iVar2 = snprintf(local_res0,local_res4,"Signal level%c%d/%d  ",uVar1,(uint)param_5_00[1],
[32m[32m[32m                         (uint)*(byte *)(param_6 + 0x2d));[0m[0m[0m
        local_res0 = local_res0 + iVar2;
[32m        local_res4 = local_res4 - iVar2;[0m
      }
      if ((param_5_00[3] & 0x40) == 0) {
        if ((param_5_00[3] & 4) == 0) {
          uVar1 = 0x3a;
        }
        else {
          uVar1 = 0x3d;
        }
        snprintf(local_res0,local_res4,"Noise level%c%d/%d",uVar1,(uint)param_5_00[2],
[32m                 (uint)*(byte *)(param_6 + 0x2e));[0m
      }
    }
    else {
      if ((param_5_00[3] & 0x20) == 0) {
        local_28 = (uint)param_5_00[1];
        if (0x3f < param_5_00[1]) {
          local_28 = local_28 - 0x100;
        }
        if ((param_5_00[3] & 2) == 0) {
          uVar1 = 0x3a;
        }
        else {
          uVar1 = 0x3d;
        }
[32m[32m[32m        iVar2 = snprintf(local_res0,local_res4,"Signal level%c%d dBm  ",uVar1,local_28);[0m[0m[0m
        local_res0 = local_res0 + iVar2;
[32m        local_res4 = local_res4 - iVar2;[0m
      }
      if ((param_5_00[3] & 0x40) == 0) {
        local_24 = (uint)param_5_00[2];
        if (0x3f < param_5_00[2]) {
          local_24 = local_24 - 0x100;
        }
        if ((param_5_00[3] & 4) == 0) {
          uVar1 = 0x3a;
        }
        else {
          uVar1 = 0x3d;
        }
[32m        snprintf(local_res0,local_res4,"Noise level%c%d dBm",uVar1,local_24);[0m
      }
    }
  }
  return;
}

[ASK_GPT] 61f38e32e3d80130
