
void FUN_00448f3c(int param_1,int param_2,int param_3)

{
  bool bVar1;
  char *pcVar2;
  uint uVar3;
  undefined local_50;
  undefined auStack_4f [67];
  
  if (param_3 == -0x1000c) {
    FUN_00448dac(param_1,param_2,0);
  }
  else if (param_3 == -0x10100) {
    if (*(char *)(param_1 + 0x275) == '\0') {
      bVar1 = *(int *)(param_1 + 0x2aa8) != 0;
      *(bool *)(param_1 + 0x2aa1) = bVar1;
      if (bVar1) {
        uVar3 = (uint)*(byte *)(param_1 + 0x2a9f);
        local_50 = mDNS_snprintf(auStack_4f,0x3e,"%d-%d-%d-%d.%d %#s",
                                 *(undefined *)(param_1 + 0x2a9c),*(undefined *)(param_1 + 0x2a9d),
                                 *(undefined *)(param_1 + 0x2a9e),uVar3,
[32m                                 *(undefined *)(param_1 + 0x2aa0),param_1 + 0x1a58);[0m
        FUN_00448500(param_1,param_2,&local_50,&DAT_00457b8c,&DAT_0044d544,0,
                     uVar3 & 0xffff | (uint)**(ushort **)(param_1 + 0x2aa8) << 0x10,"",1,0,0,0,
                     FUN_00448f3c,0,0);
      }
      if (mDNS_LoggingEnabled != 0) {
        if (*(char *)(param_1 + 0x2aa1) == '\0') {
          pcVar2 = "stopped";
        }
        else {
          pcVar2 = "started";
        }
        LogMsgWithLevel(2,"Sleep Proxy Server %#s %s",*(undefined4 *)(param_2 + 0x748),pcVar2);
      }
    }
    else {
      *(undefined *)(param_1 + 0x2aa1) = 3;
    }
  }
  return;
}

[ASK_GPT] d4e896a408777431
