
undefined4 RequestIndication(int param_1,char *param_2,void *param_3,uint *param_4)

{
  undefined *__ptr;
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined *local_28;
  ushort local_24;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
[32m[32m[32m  strncpy((char *)&local_38,param_2,0x10);[0m[0m[0m
[32m[32m[32m  __ptr = (undefined *)malloc(0x618);[0m[0m[0m
  *__ptr = 2;
  local_24 = 1;
  local_28 = __ptr;
  iVar1 = ioctl(param_1,0x89ff,&local_38);
  if (iVar1 < 0) {
    free(__ptr);
    piVar2 = __errno_location();
    strerror(*piVar2);
    uVar3 = 0xffffffff;
  }
  else {
[32m[32m    memcpy(param_3,local_28,(uint)local_24);[0m[0m
    *param_4 = (uint)local_24;
    free(__ptr);
    uVar3 = 1;
  }
  return uVar3;
}

[ASK_GPT] 70a572faf8819af3
