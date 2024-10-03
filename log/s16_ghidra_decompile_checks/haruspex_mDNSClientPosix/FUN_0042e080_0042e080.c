
void FUN_0042e080(int param_1,undefined4 *param_2)

{
  short sVar1;
  undefined4 *__ptr;
  undefined4 *puVar2;
  undefined *puVar3;
  
  puVar3 = &_gp;
  while (puVar2 = (undefined4 *)*param_2, puVar2 != (undefined4 *)0x0) {
    *param_2 = *puVar2;
    __ptr = (undefined4 *)puVar2[9];
    if ((__ptr != (undefined4 *)0x0) && (__ptr != puVar2 + 0x1c)) {
      mDNSPlatformMemFree(__ptr);
      puVar2[9] = 0;
    }
    if ((void *)puVar2[8] != (void *)0x0) {
      mDNSPlatformMemFree((void *)puVar2[8]);
      puVar2[8] = 0;
    }
    if (puVar2[7] == 0) {
      *(uint *)(param_1 + 0x2d0) = *(int *)(param_1 + 0x2d0) - (uint)*(ushort *)(puVar2 + 4);
[32m      sVar1 = *(short *)((int)puVar2 + 6);[0m
      if ((((ushort)(sVar1 - 0x2eU) < 3) || (sVar1 == 0x2b)) || (sVar1 == 0x32)) {
        BumpDNSSECStats(param_1,1,0,*(undefined2 *)(puVar2 + 4),puVar3);
      }
    }
    *puVar2 = *(undefined4 *)(param_1 + 0x2dc);
    *(undefined4 **)(param_1 + 0x2dc) = puVar2;
    *(int *)(param_1 + 0x2cc) = *(int *)(param_1 + 0x2cc) + -1;
  }
  return;
}

[ASK_GPT] 8cf1fe991c9e6d1e
