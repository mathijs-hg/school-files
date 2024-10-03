
void FUN_00403ca0(int *param_1,void **param_2,void *param_3,void *param_4)

{
  void *pvVar1;
  int iVar2;
  byte *pbVar3;
  size_t __n;
  
  if (*param_2 == (void *)0x0) {
    pvVar1 = (void *)jpeg_alloc_huff_table();
    *param_2 = pvVar1;
  }
[32m  __n = 0;[0m
[32m[32m  memcpy(*param_2,param_3,0x11);[0m[0m
  iVar2 = 1;
  do {
    pbVar3 = (byte *)((int)param_3 + iVar2);
    iVar2 = iVar2 + 1;
[32m    __n = __n + *pbVar3;[0m
  } while (iVar2 != 0x11);
  if (0xff < __n - 1) {
    *(undefined4 *)(*param_1 + 0x14) = 8;
    (**(code **)*param_1)(param_1);
  }
[32m  memcpy((void *)((int)*param_2 + 0x11),param_4,__n);[0m
  *(undefined4 *)((int)*param_2 + 0x114) = 0;
  return;
}

[ASK_GPT] 2b0303525c17c032
