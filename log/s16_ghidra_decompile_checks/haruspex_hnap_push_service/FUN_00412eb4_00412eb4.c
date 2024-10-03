
undefined4 FUN_00412eb4(byte *param_1,char *param_2,uint param_3)

{
  byte *pbVar1;
  uint uVar2;
  char local_28;
  char local_27;
  undefined local_26;
  
  *param_2 = '\0';
  if (param_3 != 0) {
    uVar2 = 0;
    pbVar1 = param_1;
    do {
[32m      local_28 = "0123456789abcdefpMsgInfo->stHeader.uPayloadLen: [%d]\n"[*pbVar1 >> 4];[0m
[32m      local_27 = "0123456789abcdefpMsgInfo->stHeader.uPayloadLen: [%d]\n"[*pbVar1 & 0xf];[0m
      local_26 = 0;
[32m[32m      strcat(param_2,&local_28);[0m[0m
      uVar2 = uVar2 + 1;
      pbVar1 = param_1 + uVar2;
    } while (uVar2 < param_3);
  }
  return 0;
}

[ASK_GPT] 22a5fc1c51f3fe99
