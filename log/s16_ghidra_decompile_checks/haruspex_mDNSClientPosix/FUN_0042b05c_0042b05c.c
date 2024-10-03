
bool FUN_0042b05c(int param_1)

{
  uint uVar1;
  int iVar2;
  short local_58 [2];
  short local_54;
  undefined2 local_52;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_44;
  ushort local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  if (*(short *)(param_1 + 6) == 10) {
    uVar1 = (uint)**(byte **)(param_1 + 0x20);
    iVar2 = uVar1 + 1;
    if (uVar1 == 0) {
      iVar2 = 0;
    }
    iVar2 = SameDomainLabel(*(byte **)(param_1 + 0x20) + iVar2,"\n_keepalive");
    if (iVar2 == 0) {
      return false;
    }
    local_48 = 0;
    local_4c = 0;
    local_50 = 0;
    local_52 = 0;
[32m[32m    memcpy(&local_28,zeroAddr,0x14);[0m[0m
[32m[32m    memcpy(&local_3c,&local_28,0x14);[0m[0m
    local_58[0] = 0;
[32m    local_54 = local_58[0];[0m
    FUN_0042ac48(param_1,&local_50,&local_3c,&local_28,&local_44,&local_4c,&local_48,local_58,
                 &local_54,&local_52);
    if (((local_3c == 4) ||
        ((((local_3c == 6 && (local_34 == 0)) && (local_38 == 0)) &&
         (local_38 = local_2c, local_30 == 0)))) && (local_38 == 0)) {
      return false;
    }
    if (local_58[0] != 0) {
      if (((local_28 == 4) ||
          (((local_28 == 6 && (local_20 == 0)) &&
           ((local_24 == 0 && (local_24 = local_18, local_1c == 0)))))) && (local_24 == 0)) {
        return false;
      }
      if (local_54 != 0) {
        return (local_44 & 0xffff | local_44 >> 0x10 | (uint)local_40) != 0;
      }
    }
  }
  return false;
}

[ASK_GPT] 2b3cc23b81fd7c08
