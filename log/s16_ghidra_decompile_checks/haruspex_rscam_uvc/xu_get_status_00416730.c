
/* WARNING: Could not reconcile some variable overlaps */

int xu_get_status(undefined4 param_1,ushort *param_2,undefined param_3)

{
  int iVar1;
  undefined local_1c;
  undefined local_1b;
  undefined local_1a;
  undefined2 local_18;
  uint *local_14;
  uint local_10;
  undefined4 local_c;
  
  local_10 = 0;
  local_c = 0;
[32m  memset(&local_1c,0,0xc);[0m
  local_1b = 10;
  local_18 = 8;
  local_14 = &local_10;
  local_1a = 0x81;
  local_1c = param_3;
  iVar1 = query_xu_ctrl(param_1,&local_1c);
  if (iVar1 == 0) {
    if (param_2 != (ushort *)0x0) {
      *param_2 = (ushort)local_10._0_1_ | (ushort)(((local_10 >> 0x10) << 0x18) >> 0x10);
    }
    iVar1 = 0;
  }
  return iVar1;
}

[ASK_GPT] 69ca92ad387fc0a3
