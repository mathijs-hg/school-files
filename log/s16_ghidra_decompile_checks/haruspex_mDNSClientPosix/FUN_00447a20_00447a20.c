
void FUN_00447a20(int param_1,int param_2,undefined *param_3)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined auStack_50 [68];
  
  if (param_3 == (undefined *)0x0) {
    if (*(code **)(param_1 + 0x1c) != (code *)0x0) {
      (**(code **)(param_1 + 0x1c))(param_1,0);
    }
  }
  else {
    if (param_3 == (undefined *)0xfffefff4) {
[32m[32m      memcpy(auStack_50,(void *)(param_1 + 0x1a98),0x40);[0m[0m
      if (*(code **)(param_1 + 0x1c) != (code *)0x0) {
        (**(code **)(param_1 + 0x1c))(param_1,0xfffefff4);
      }
      iVar3 = param_1 + 0x1a98;
      iVar1 = SameDomainLabel(iVar3,auStack_50);
      if (iVar1 != 0) {
        IncrementLabelSuffix(iVar3,0);
      }
      mDNS_SetFQDN(param_1);
      pcVar2 = "Local Hostname %#s.local already in use; will try %#s.local instead";
      param_3 = auStack_50;
    }
    else {
      if (param_3 == (undefined *)0xfffeff00) {
        return;
      }
      iVar3 = *(int *)(param_2 + 0x20);
      pcVar2 = "mDNS_HostNameCallback: Unknown error %d for registration of record %s";
    }
    LogMsgWithLevel(0,pcVar2,param_3,iVar3);
  }
  return;
}

[ASK_GPT] 869b08b4cf865b36
