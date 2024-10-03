
undefined4 ILibProcessXMLNodeList(void **param_1)

{
  void *pvVar1;
  void **ppvVar2;
  int iVar3;
  undefined4 uVar4;
  void **local_18 [2];
  
  local_18[0] = (void **)0x0;
  do {
    uVar4 = 0;
    if (param_1 == (void **)0x0) {
LAB_00413d00:
      if (local_18[0] != (void **)0x0) {
        FUN_004116b8(local_18);
        uVar4 = 0xfffffffd;
      }
      return uVar4;
    }
    if (param_1[4] == (void *)0x0) {
      ppvVar2 = (void **)FUN_00411668(local_18);
      if (ppvVar2 == (void **)0x0) {
        uVar4 = 0xffffffff;
        goto LAB_00413d00;
      }
      uVar4 = 0xfffffffe;
      if (ppvVar2[1] != param_1[1]) goto LAB_00413d00;
[32m      iVar3 = memcmp(*ppvVar2,*param_1,(size_t)ppvVar2[1]);[0m
      uVar4 = 0xfffffffe;
      if (iVar3 != 0) goto LAB_00413d00;
      pvVar1 = param_1[8];
      if ((pvVar1 != (void *)0x0) && (*(int *)((int)pvVar1 + 0x10) != 0)) {
        ppvVar2[10] = pvVar1;
      }
      ppvVar2[0xb] = param_1;
      param_1[0xc] = ppvVar2;
    }
    else {
      pvVar1 = (void *)0x0;
      if (local_18[0] != (void **)0x0) {
        pvVar1 = *local_18[0];
      }
      param_1[9] = pvVar1;
      FUN_00410dc0(local_18,param_1);
    }
    param_1 = (void **)param_1[8];
  } while( true );
}

[ASK_GPT] ce36aa4cfe01c3b9
