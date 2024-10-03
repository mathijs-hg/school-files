
void FUN_00439fcc(int param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  *(undefined4 *)(param_1 + 0x216c) = param_2;
  while( true ) {
    puVar4 = *(undefined4 **)(param_1 + 0x216c);
    if (puVar4 == (undefined4 *)0x0) break;
    if (mDNS_LoggingEnabled != 0) {
[32m      cVar1 = *(char *)(puVar4 + 1);[0m
      pcVar2 = "Accelerating";
      if (cVar1 != '\x01') {
        pcVar2 = "Initiating  ";
      }
      uVar3 = GetRRDisplayString_rdb(puVar4 + 1,puVar4[9] + 4,param_1 + 0x2f);
      LogMsgWithLevel(3,"DeregLoop: %s deregistration for %p %02X %s",pcVar2,puVar4,cVar1,uVar3);
    }
    if (*(char *)(puVar4 + 1) == '\x01') {
      if (1 < *(byte *)((int)puVar4 + 0x87)) {
        *(undefined *)((int)puVar4 + 0x87) = 1;
        puVar4[0x30] = *(int *)(param_1 + 0x234) - puVar4[0x2f];
      }
    }
    else {
      mDNS_Deregister_internal(param_1,puVar4,1);
    }
    if (*(undefined4 **)(param_1 + 0x216c) == puVar4) {
      *(undefined4 *)(param_1 + 0x216c) = *puVar4;
    }
  }
  return;
}

[ASK_GPT] 82cd3bc7289e9126
