
undefined * FUN_00411f08(byte *param_1,undefined4 param_2,int param_3)

{
  undefined *puVar1;
  undefined *__dest;
  byte *pbVar2;
  uint __n;
  undefined *__dest_00;
  
[32m[32m[32m[32m  puVar1 = (undefined *)malloc(param_3 + 1);[0m[0m[0m[0m
  __dest_00 = puVar1;
  do {
[32m    memcpy(__dest_00,param_1 + 1,(uint)*param_1);[0m
    __dest = __dest_00 + *param_1;
    pbVar2 = param_1 + *param_1 + 1;
    param_1 = pbVar2 + 2;
    __n = *pbVar2 & 0x3f;
    __dest_00 = __dest + __n;
[32m    memcpy(__dest,__dest + -((uint)pbVar2[1] * 4 + (uint)(*pbVar2 >> 6)),__n);[0m
  } while (__dest_00 < puVar1 + param_3);
  puVar1[param_3] = 0;
  return puVar1;
}

[ASK_GPT] e1ace80b5aed5e66
