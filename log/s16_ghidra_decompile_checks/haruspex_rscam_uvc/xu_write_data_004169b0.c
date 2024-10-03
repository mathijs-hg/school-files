
int xu_write_data(undefined4 param_1,void *param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  size_t __n;
  int iVar2;
  void *local_20;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_20 = param_2;
  while( true ) {
    uVar1 = param_3;
    if ((int)param_3 < 0) {
      uVar1 = param_3 + 7;
    }
    if ((int)uVar1 >> 3 <= local_18) break;
    iVar2 = xu_set_data(param_1,local_20,param_4);
    if (iVar2 != 0) {
      return iVar2;
    }
    local_20 = (void *)((int)local_20 + 8);
    local_18 = local_18 + 1;
  }
  if ((param_3 & 7) != 0) {
    local_14 = 0;
    local_10 = 0;
[32m    __n = param_3 & 0x80000007;[0m
[32m    if ((int)__n < 0) {[0m
[32m      __n = (__n - 1 | 0xfffffff8) + 1;[0m
    }
[32m    memcpy(&local_14,local_20,__n);[0m
    iVar2 = xu_set_data(param_1,&local_14,param_4);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  return 0;
}

[ASK_GPT] 42e00580df9be78e
