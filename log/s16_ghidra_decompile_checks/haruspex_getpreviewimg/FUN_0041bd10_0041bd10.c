
void FUN_0041bd10(int *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char **ppcVar4;
  char *pcVar5;
  char *__format;
  
  iVar2 = *param_1;
  iVar3 = *(int *)(iVar2 + 0x14);
  if ((iVar3 < 1) || (*(int *)(iVar2 + 0x74) < iVar3)) {
    if ((*(int *)(iVar2 + 0x78) != 0) &&
       ((*(int *)(iVar2 + 0x7c) <= iVar3 && (iVar3 <= *(int *)(iVar2 + 0x80))))) {
      ppcVar4 = (char **)(*(int *)(iVar2 + 0x78) + (iVar3 - *(int *)(iVar2 + 0x7c)) * 4);
      goto LAB_0041bd88;
    }
  }
  else {
    ppcVar4 = (char **)(iVar3 * 4 + *(int *)(iVar2 + 0x70));
LAB_0041bd88:
    pcVar5 = *ppcVar4;
    __format = pcVar5;
    if (pcVar5 != (char *)0x0) goto LAB_0041bdcc;
  }
  *(int *)(iVar2 + 0x18) = iVar3;
  pcVar5 = **(char ***)(iVar2 + 0x70);
  __format = pcVar5;
LAB_0041bdcc:
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    if (cVar1 == '\0') goto LAB_0041bdf0;
  } while (cVar1 != '%');
  if (*pcVar5 == 's') {
    (*(code *)(undefined *)0x0)(param_2,__format,iVar2 + 0x18);
    (*(code *)(undefined *)0x0)();
    (*(code *)(undefined *)0x0)();
    (*(code *)(undefined *)0x0)();
    (*(code *)(undefined *)0x0)();
    (*(code *)(undefined *)0x0)();
    (*(code *)(undefined *)0x0)();
    FUN_00401af0();
    return;
  }
LAB_0041bdf0:
  sprintf(param_2,__format,*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x1c),
          *(undefined4 *)(iVar2 + 0x20),*(undefined4 *)(iVar2 + 0x24),*(undefined4 *)(iVar2 + 0x28),
          *(undefined4 *)(iVar2 + 0x2c),*(undefined4 *)(iVar2 + 0x30),*(undefined4 *)(iVar2 + 0x34),
[32m[32m[32m          &_gp);[0m[0m[0m
  return;
}

[ASK_GPT] a41151b895be646a
