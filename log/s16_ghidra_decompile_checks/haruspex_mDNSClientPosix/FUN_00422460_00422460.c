
undefined4
FUN_00422460(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = AlgCreate(2,param_5);
  if (iVar1 == 0) {
    LogMsgWithLevel(0,"baseEncode: AlgCreate failed\n");
    uVar3 = 0;
  }
  else {
    uVar3 = 0;
    AlgAdd(iVar1,param_3,param_4);
    iVar2 = AlgEncode(iVar1);
    if (iVar2 != 0) {
[32m      uVar3 = mDNS_snprintf(param_1,param_2,"%s",iVar2);[0m
    }
    AlgDestroy(iVar1);
  }
  return uVar3;
}

[ASK_GPT] ccb30db6a20ba6da
