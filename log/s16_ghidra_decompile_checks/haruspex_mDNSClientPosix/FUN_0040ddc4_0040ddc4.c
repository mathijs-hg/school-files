
int FUN_0040ddc4(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_3 + 0xe4) == 3) {
    *(undefined4 *)(param_3 + 0xec) = 0;
    iVar2 = putDeletionRecordWithLimit(param_1 + 0x5cb0,param_2,param_3 + 4);
  }
  else {
    if (*(int *)(param_3 + 0xe4) == 2) {
      *(undefined4 *)(param_3 + 0xe4) = 5;
    }
    if ((*(int *)(param_3 + 0xe4) != 5) && (*(int *)(param_3 + 0xe4) != 7)) {
      *(undefined4 *)(param_3 + 0xe4) = 1;
    }
    if (*(char *)(param_3 + 4) != '\x04') {
      *(undefined *)(param_3 + 0x88) = 1;
    }
    if (((*(short *)(param_3 + 6) == 0x21) && (*(char *)(param_3 + 0x48) == '\x02')) &&
       (*(short *)(param_3 + 0x130) != 0)) {
      *(short *)(*(int *)(param_3 + 0x24) + 8) = *(short *)(param_3 + 0x130);
    }
    if (*(int *)(param_3 + 0xe4) == 7) {
      iVar2 = param_3 + 4;
      SetNewRData(iVar2,*(undefined4 *)(param_3 + 0x16c),*(undefined2 *)(param_3 + 0x164));
      param_2 = putDeletionRecordWithLimit(param_1 + 0x5cb0,param_2,iVar2,param_4);
      if (param_2 == 0) goto LAB_0040dfac;
      SetNewRData(iVar2,*(undefined4 *)(param_3 + 0x170),*(undefined2 *)(param_3 + 0x166));
      uVar3 = *(undefined4 *)(param_3 + 0xc);
    }
    else {
[32m      cVar1 = *(char *)(param_3 + 4);[0m
      if ((cVar1 == ' ') || (cVar1 == '\x10')) {
        param_2 = putDeleteRRSetWithLimit
                            (param_1 + 0x5cb0,param_2,*(undefined4 *)(param_3 + 0x20),
                             *(undefined2 *)(param_3 + 6),param_4);
LAB_0040df74:
        if (param_2 == 0) goto LAB_0040dfac;
      }
      else if (cVar1 != '\b') goto LAB_0040df74;
      uVar3 = *(undefined4 *)(param_3 + 0xc);
    }
    iVar2 = PutResourceRecordTTLWithLimit
                      (param_1 + 0x5cb0,param_2,param_1 + 0x5cb8,param_3 + 4,uVar3,param_4);
  }
  if (iVar2 != 0) {
    return iVar2;
  }
LAB_0040dfac:
  uVar3 = GetRRDisplayString_rdb(param_3 + 4,*(int *)(param_3 + 0x24) + 4,param_1 + 0x2f);
  LogMsgWithLevel(0,"BuildUpdateMessage: Error formatting message for %s",uVar3);
  return 0;
}

[ASK_GPT] fa1758b89e5446ac
