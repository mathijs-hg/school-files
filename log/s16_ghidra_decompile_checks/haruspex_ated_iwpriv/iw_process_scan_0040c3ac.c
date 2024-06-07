
/* WARNING: Could not reconcile some variable overlaps */

undefined4 iw_process_scan(int param_1,char *param_2,int param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  void *__ptr;
  undefined8 uVar3;
  void *local_88;
  uint local_84;
  void **local_80;
  void **local_50;
  char acStack_48 [16];
  void *local_38;
  ushort local_34;
  undefined2 local_32;
  undefined auStack_28 [2];
  ushort uStack_26;
  void *pvStack_24;
  undefined4 uStack_20;
  void *pvStack_1c;
  void *pvStack_18;
  undefined auStack_14 [12];
  
  local_88 = (void *)0x0;
  local_84 = 0x1000;
  param_4[1] = param_4[1] + 1;
  if (0x96 < param_4[1]) {
    piVar1 = __errno_location();
    *piVar1 = 0x3e;
    return 0xffffffff;
  }
  if (param_4[1] == 1) {
    local_38 = (void *)0x0;
    local_32 = 0;
    local_34 = 0;
[32m[32m[32m    strncpy(acStack_48,param_2,0x10);[0m[0m[0m
    iVar2 = ioctl(param_1,0x8b18,acStack_48);
    if ((iVar2 < 0) && (piVar1 = __errno_location(), *piVar1 != 1)) {
      return 0xffffffff;
    }
    return 0xfa;
  }
  while( true ) {
[32m    __ptr = realloc(local_88,local_84);[0m
    if (__ptr == (void *)0x0) {
      if (local_88 != (void *)0x0) {
        free(local_88);
      }
      piVar1 = __errno_location();
      *piVar1 = 0xc;
      return 0xffffffff;
    }
    local_32 = 0;
    local_34 = (ushort)local_84;
    local_38 = __ptr;
[32m[32m[32m    strncpy(acStack_48,param_2,0x10);[0m[0m[0m
    iVar2 = ioctl(param_1,0x8b19,acStack_48);
    if (-1 < iVar2) break;
    piVar1 = __errno_location();
    if ((*piVar1 != 7) || (param_3 < 0x11)) {
      piVar1 = __errno_location();
      if (*piVar1 == 0xb) {
        free(__ptr);
        return 100;
      }
      free(__ptr);
      return 0xffffffff;
    }
    local_88 = __ptr;
    if ((int)local_84 < (int)(uint)local_34) {
      local_84 = (uint)local_34;
    }
    else {
      local_84 = local_84 << 1;
    }
  }
  if (local_34 != 0) {
    local_80 = (void **)0x0;
    iw_init_event_stream(auStack_14,__ptr,local_34);
    *param_4 = 0;
    do {
      iVar2 = iw_extract_event_stream(auStack_14,auStack_28,param_3);
      if (0 < iVar2) {
        local_50 = local_80;
        if (uStack_26 == 0x8b15) {
[32m[32m          local_50 = (void **)malloc(0x100);[0m[0m
          if (local_50 != (void **)0x0) {
            if (local_80 != (void **)0x0) {
              *local_80 = local_50;
            }
[32m            memset(local_50,0,0x100);[0m
            local_50[1] = (void *)0x1;
            local_50[2] = pvStack_24;
            local_50[3] = uStack_20;
            local_50[4] = pvStack_1c;
            local_50[5] = pvStack_18;
          }
        }
        else if (uStack_26 < 0x8b16) {
          if (uStack_26 == 0x8b05) {
            local_80[0xe] = (void *)0x1;
            uVar3 = iw_freq2float(&pvStack_24);
            *(undefined8 *)(local_80 + 0x10) = uVar3;
            local_80[0x12] = (void *)((uint)uStack_20 >> 0x18);
          }
          else if (uStack_26 == 0x8b07) {
            local_80[0x32] = pvStack_24;
            if (((int)local_80[0x32] < 7) && (-1 < (int)local_80[0x32])) {
              local_80[0x31] = (void *)0x1;
            }
          }
          else if (uStack_26 == 0x8b03) {
            local_80[0xb] = (void *)0x1;
            local_80[0xc] = pvStack_24;
            local_80[0xd] = uStack_20;
          }
        }
        else if (uStack_26 == 0x8b21) {
          if ((local_80[0x3f] == (void *)0x0) || ((int)local_80[0x3d] < (int)pvStack_24)) {
            local_80[0x3f] = (void *)0x1;
            local_80[0x3d] = pvStack_24;
            local_80[0x3e] = uStack_20;
          }
        }
        else if (uStack_26 < 0x8b22) {
          if (uStack_26 == 0x8b1b) {
            local_80[0x26] = (void *)0x1;
            local_80[0x27] = (void *)(uint)uStack_20._2_2_;
[32m            memset(local_80 + 0x28,0,0x21);[0m
            if ((pvStack_24 != (void *)0x0) && ((short)uStack_20 != 0)) {
[32m              memcpy(local_80 + 0x28,pvStack_24,(uint)uStack_20 & 0xffff);[0m
            }
          }
        }
        else if (uStack_26 == 0x8b2b) {
          local_80[0x13] = (void *)0x1;
          local_80[0x24] = (void *)((uint)uStack_20 & 0xffff);
          local_80[0x25] = (void *)(uint)uStack_20._2_2_;
          if (pvStack_24 == (void *)0x0) {
            local_80[0x25] = (void *)((uint)local_80[0x25] | 0x800);
          }
          else {
[32m            memcpy(local_80 + 0x14,pvStack_24,(uint)uStack_20 & 0xffff);[0m
          }
        }
        else if (uStack_26 == 0x8c01) {
          local_80[0x3c] = (void *)0x1;
          *(void **)((int)local_80 + 0xd2) = pvStack_24;
        }
        if (local_50 == (void **)0x0) {
          free(__ptr);
          piVar1 = __errno_location();
          *piVar1 = 0xc;
          return 0xffffffff;
        }
        local_80 = local_50;
        if (*param_4 == 0) {
          *param_4 = (int)local_50;
        }
      }
    } while (0 < iVar2);
  }
  free(__ptr);
  return 0;
}

[ASK_GPT] 36ee8ae4d05a63f6
