
undefined4 iw_extract_event_stream(uint *param_1,undefined4 *param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  void *pvVar6;
  byte *local_30;
  uint local_2c;
  uint local_28;
  ushort *local_24;
  uint local_20;
  
  local_30 = (byte *)0x0;
  local_2c = 0;
  if (*param_1 < param_1[1] + 4) {
    uVar3 = 0;
  }
  else {
    *param_2 = *(undefined4 *)param_1[1];
    if (*(ushort *)param_2 < 5) {
      uVar3 = 0xffffffff;
    }
    else {
      if (*(ushort *)((int)param_2 + 2) < 0x8c00) {
        uVar4 = *(ushort *)((int)param_2 + 2) - 0x8b00;
        if (uVar4 < 0x37) {
          local_30 = standard_ioctl_descr + uVar4 * 0xc;
        }
      }
      else {
        uVar4 = *(ushort *)((int)param_2 + 2) - 0x8c00;
        if (uVar4 < 10) {
          local_30 = standard_event_descr + uVar4 * 0xc;
        }
      }
      if (local_30 != (byte *)0x0) {
        local_2c = (uint)*local_30;
      }
      local_28 = *(uint *)(event_type_size + local_2c * 4);
      if ((param_3 < 0x13) && (local_2c == 8)) {
        local_28 = local_28 + 4;
      }
      if (local_28 < 5) {
        param_1[1] = param_1[1] + (uint)*(ushort *)param_2;
        uVar3 = 2;
      }
      else {
        uVar4 = local_28 - 4;
        if (param_1[2] == 0) {
          local_24 = (ushort *)(param_1[1] + 4);
        }
        else {
          local_24 = (ushort *)param_1[2];
        }
        if (*param_1 < (int)local_24 + uVar4) {
          param_1[1] = param_1[1] + (uint)*(ushort *)param_2;
          uVar3 = 0xfffffffe;
        }
        else {
          if ((param_3 < 0x13) || (local_2c != 8)) {
[32m            memcpy(param_2 + 1,local_24,uVar4);[0m
          }
          else {
[32m            memcpy(param_2 + 2,local_24,uVar4);[0m
          }
          local_24 = (ushort *)((int)local_24 + uVar4);
          if (local_2c == 8) {
            uVar5 = (*(ushort *)param_2 - uVar4) - 4;
            if (*(ushort *)param_2 - uVar4 == 4) {
              param_2[1] = 0;
            }
            else {
              param_2[1] = local_24;
              if (local_30 == (byte *)0x0) {
                param_2[1] = 0;
              }
              else {
                local_20 = (uint)*(ushort *)(param_2 + 2) * (uint)*(ushort *)(local_30 + 2);
                if ((local_20 != uVar5) && (3 < uVar5)) {
                  uVar1 = *local_24;
                  uVar2 = *(ushort *)(local_30 + 2);
                  if ((uint)uVar1 * (uint)uVar2 + 8 == uVar5) {
                    pvVar6 = (void *)((int)local_24 + (4 - uVar4));
[32m                    memcpy(param_2 + 2,pvVar6,uVar4);[0m
                    param_2[1] = (int)pvVar6 + local_28;
                    local_20 = (uint)uVar1 * (uint)uVar2;
                  }
                }
                if (uVar5 < local_20) {
                  param_2[1] = 0;
                }
                if ((*(ushort *)(local_30 + 6) < *(ushort *)(param_2 + 2)) &&
                   ((*(uint *)(local_30 + 8) & 8) == 0)) {
                  param_2[1] = 0;
                }
                if (*(ushort *)(param_2 + 2) < *(ushort *)(local_30 + 4)) {
                  param_2[1] = 0;
                }
              }
            }
            param_1[1] = param_1[1] + (uint)*(ushort *)param_2;
          }
          else {
            if (param_1[2] == 0) {
              if (uVar4 == 0) {
                trap(0x1c00);
              }
              if (((*(ushort *)param_2 - 4) % uVar4 == 4) ||
                 ((*(ushort *)param_2 == 0xc && ((local_2c == 4 || (local_2c == 10)))))) {
                pvVar6 = (void *)((int)local_24 + (4 - uVar4));
[32m                memcpy(param_2 + 1,pvVar6,uVar4);[0m
                local_24 = (ushort *)((int)pvVar6 + uVar4);
              }
            }
            if (param_1[1] + (uint)*(ushort *)param_2 < (int)local_24 + uVar4) {
              param_1[2] = 0;
              param_1[1] = param_1[1] + (uint)*(ushort *)param_2;
            }
            else {
              param_1[2] = (uint)local_24;
            }
          }
          uVar3 = 1;
        }
      }
    }
  }
  return uVar3;
}

[ASK_GPT] b1573f3334ca7404
