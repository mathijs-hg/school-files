
void SetNewRData(int param_1,int param_2,undefined2 param_3)

{
  short sVar1;
  undefined2 uVar3;
  undefined4 uVar2;
  int iVar4;
  
  if (param_2 != 0) {
    *(int *)(param_1 + 0x20) = param_2;
    *(undefined2 *)(param_1 + 0xc) = param_3;
  }
[32m  sVar1 = *(short *)(param_1 + 2);[0m
  if ((((sVar1 == 2) || (sVar1 == 5)) || (sVar1 == 0xc)) || (sVar1 == 0x27)) {
    iVar4 = *(int *)(param_1 + 0x20) + 4;
  }
  else if (((sVar1 == 0xf) || (sVar1 == 0x12)) || ((sVar1 == 0x15 || (sVar1 == 0x24)))) {
    iVar4 = *(int *)(param_1 + 0x20) + 6;
  }
  else {
    iVar4 = 0;
    if (sVar1 == 0x21) {
      iVar4 = *(int *)(param_1 + 0x20) + 10;
    }
  }
  uVar3 = GetRDLength(param_1,0);
  *(undefined2 *)(param_1 + 0xc) = uVar3;
  uVar3 = GetRDLength(param_1,1);
  *(undefined2 *)(param_1 + 0xe) = uVar3;
  if (iVar4 == 0) {
    uVar2 = RDataHashValue(param_1);
    *(undefined4 *)(param_1 + 0x14) = uVar2;
  }
  else {
    uVar2 = DomainNameHashValue(iVar4);
    *(undefined4 *)(param_1 + 0x14) = uVar2;
  }
  return;
}

[ASK_GPT] 71c748da01cf542b
