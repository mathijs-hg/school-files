
void FUN_00448dac(undefined4 param_1,int param_2,undefined *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined auStack_2a0 [64];
  undefined auStack_260 [64];
  undefined auStack_220 [256];
  undefined auStack_120 [256];
  
  iVar3 = 0;
  if (*(char *)(param_2 + 0x770) == '\0') {
    iVar3 = *(int *)(param_2 + 0x74c) + 10;
  }
  puVar1 = *(undefined4 **)(param_2 + 0xc);
  DeconstructServiceName(*(undefined4 *)(param_2 + 0x748),auStack_2a0,auStack_220,auStack_120);
  if (param_3 == (undefined *)0x0) {
    param_3 = auStack_260;
[32m[32m    memcpy(param_3,auStack_2a0,0x40);[0m[0m
    IncrementLabelSuffix(param_3,1);
  }
  SameDomainName(auStack_120,&DAT_0044d544);
  iVar3 = FUN_00448500(param_1,param_2,param_3,auStack_220,auStack_120,iVar3);
  while ((iVar3 == 0 && (puVar1 != (undefined4 *)0x0))) {
    puVar2 = (undefined4 *)*puVar1;
    iVar3 = FUN_00447324(param_1,param_2,puVar1,puVar1[0xb],puVar1[5],0);
    puVar1 = puVar2;
  }
  return;
}

[ASK_GPT] 473329c726a2b09d
