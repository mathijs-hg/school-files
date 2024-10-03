
void FUN_0043c740(int param_1)

{
  int iVar1;
  byte local_290;
  undefined auStack_28f [63];
  byte local_250;
  undefined auStack_24f [63];
  undefined auStack_210 [256];
  undefined auStack_110 [260];
  
  if (*(char *)(param_1 + 0x2aa1) == '\x01') {
    DeconstructServiceName(*(undefined4 *)(param_1 + 0x31f4),&local_290,auStack_210,auStack_110);
    local_250 = mDNS_snprintf(auStack_24f,0x3e,"%d-%d-%d-%d.%d %#s",*(undefined *)(param_1 + 0x2a9c)
                              ,*(undefined *)(param_1 + 0x2a9d),*(undefined *)(param_1 + 0x2a9e),
                              *(undefined *)(param_1 + 0x2a9f),*(undefined *)(param_1 + 0x2aa0),
[32m                              param_1 + 0x1a58);[0m
    if (local_290 == local_250) {
      iVar1 = mDNSPlatformMemSame(auStack_28f,auStack_24f);
      if (iVar1 != 0) goto LAB_0043c844;
    }
    if (mDNS_LoggingEnabled != 0) {
      LogMsgWithLevel(2,&DAT_00459ce8,&local_290,&local_250);
    }
    *(undefined *)(param_1 + 0x2aa1) = 2;
    FUN_0043c5a8(param_1,param_1 + 0x2aac,1);
  }
LAB_0043c844:
  if (*(code **)(param_1 + 0x1c) != (code *)0x0) {
    (**(code **)(param_1 + 0x1c))(param_1,0xfffeff01);
  }
  return;
}

[ASK_GPT] 56a7de7a367d0c8b
