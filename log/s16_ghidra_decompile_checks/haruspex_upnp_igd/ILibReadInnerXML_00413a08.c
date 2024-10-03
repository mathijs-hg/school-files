
int ILibReadInnerXML(void **param_1,void **param_2)

{
  void *pvVar1;
  void **ppvVar2;
  int iVar3;
  void *pvVar4;
  void **ppvVar5;
  undefined4 local_20 [3];
  
  local_20[0] = 0;
  ppvVar5 = param_1;
  do {
    pvVar1 = ppvVar5[4];
    do {
      if (pvVar1 != (void *)0x0) {
        FUN_00410dc0(local_20,ppvVar5);
      }
      ppvVar5 = (void **)ppvVar5[8];
      pvVar1 = ppvVar5[4];
    } while (pvVar1 != (void *)0x0);
    ppvVar2 = (void **)FUN_00411668(local_20);
  } while (((param_1 != ppvVar2) || (ppvVar5[1] != param_1[1])) ||
[32m          (iVar3 = memcmp(*ppvVar5,*param_1,(size_t)ppvVar5[1]), iVar3 != 0));[0m
  pvVar1 = ppvVar5[6];
  pvVar4 = param_1[6];
  *param_2 = pvVar4;
  iVar3 = (int)pvVar1 + (-1 - (int)pvVar4);
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  return iVar3;
}

[ASK_GPT] cf1119d453e0930f
