
uint FUN_004262ac(void *param_1,void *param_2,undefined param_3,ushort *param_4,int param_5)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  ushort **ppuVar4;
  ushort *local_40 [4];
  undefined auStack_30 [16];
  undefined local_20;
  undefined local_1f;
  undefined local_1e;
  undefined local_1d;
  undefined local_1c;
  undefined local_1b;
  undefined local_1a;
  undefined local_19;
  ushort *local_18 [2];
  
  local_18[0] = param_4;
[32m[32m  memcpy(local_40,param_1,0x10);[0m[0m
[32m[32m  memcpy(auStack_30,param_2,0x10);[0m[0m
  uVar2 = 0;
  local_20 = (char)((uint)param_5 >> 0x18);
  local_1f = (char)((uint)param_5 >> 0x10);
  local_1e = (char)((uint)param_5 >> 8);
  local_19 = param_3;
  local_1d = (char)param_5;
  local_1c = 0;
  local_1b = 0;
  local_1a = 0;
  for (; 0 < param_5; param_5 = param_5 + -2) {
    uVar1 = *local_18[0];
    local_18[0] = local_18[0] + 1;
    uVar2 = uVar2 + uVar1;
  }
  ppuVar4 = local_40;
  uVar2 = (uVar2 >> 0x10) + (uVar2 & 0xffff);
  uVar3 = (uVar2 >> 0x10) + (uVar2 & 0xffff);
  uVar2 = uVar3 & 0xffff;
  if (uVar3 == 0xffff) {
    uVar2 = 0;
  }
  do {
    uVar1 = *(ushort *)ppuVar4;
    ppuVar4 = (ushort **)((int)ppuVar4 + 2);
    uVar2 = uVar2 + uVar1;
  } while (ppuVar4 != local_18);
  uVar2 = (uVar2 >> 0x10) + (uVar2 & 0xffff);
  uVar2 = (uVar2 >> 0x10) + (uVar2 & 0xffff);
  uVar3 = uVar2 & 0xffff;
  if (uVar2 == 0xffff) {
    uVar3 = 0;
  }
  return uVar3;
}

[ASK_GPT] d0fb912504630c52
