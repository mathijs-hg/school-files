
void FUN_0042a844(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar3;
  uint uVar2;
  undefined uVar4;
  
  if (((*(int *)(param_2 + 0x1c) == 0) && (*(char *)(param_2 + 0x4a) == '\0')) &&
     (iVar1 = IsLocalDomain(*(undefined4 *)(param_2 + 0x20)), iVar1 == 0)) {
    return;
  }
[32m  cVar3 = *(char *)(param_2 + 4);[0m
  if ((cVar3 == '\x10') && (*(int *)(param_2 + 0x38) == 0)) {
    *(undefined *)(param_2 + 4) = 2;
[32m    cVar3 = *(char *)(param_2 + 4);[0m
  }
  if (param_3 < 0) {
    param_3 = 4;
  }
  uVar4 = 3;
  if (cVar3 != '\x02') {
    uVar4 = 0;
  }
  *(undefined *)(param_2 + 0x86) = uVar4;
  if ((int)(uint)*(byte *)(param_2 + 0x87) < param_3) {
    *(char *)(param_2 + 0x87) = (char)param_3;
  }
  if (*(short *)(param_2 + 6) == 10) {
    uVar2 = (uint)**(byte **)(param_2 + 0x20);
    iVar1 = uVar2 + 1;
    if (uVar2 == 0) {
      iVar1 = 0;
    }
    iVar1 = SameDomainLabel(*(byte **)(param_2 + 0x20) + iVar1,"\n_keepalive");
    if (iVar1 != 0) {
      *(undefined *)(param_2 + 0x87) = 0;
      goto LAB_0042a944;
    }
  }
  *(undefined *)(param_2 + 0x87) = 4;
LAB_0042a944:
  *(undefined4 *)(param_2 + 0x8c) = 0;
  FUN_00428828(param_1,param_2);
  return;
}

[ASK_GPT] dc98781da3b9cb11
