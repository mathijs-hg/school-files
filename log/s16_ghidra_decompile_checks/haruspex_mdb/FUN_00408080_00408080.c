
void FUN_00408080(char *param_1)

{
  char cVar1;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  sVar2 = strlen(param_1);
  pcVar6 = param_1 + sVar2;
  pcVar5 = param_1;
  if (param_1 < pcVar6) {
    do {
      cVar1 = *param_1;
      *pcVar5 = cVar1;
      if (cVar1 == '%') {
[32m        cVar1 = param_1[2];[0m
        iVar3 = FUN_00408040((int)param_1[1]);
        uVar4 = FUN_00408040((int)cVar1);
        if (((iVar3 < 0x10) && ((int)uVar4 < 0x10)) && (uVar4 = iVar3 << 4 | uVar4, -1 < (int)uVar4)
           ) {
          *pcVar5 = (char)uVar4;
          param_1 = param_1 + 2;
        }
      }
      else if (cVar1 == '+') {
        *pcVar5 = ' ';
      }
      param_1 = param_1 + 1;
      pcVar5 = pcVar5 + 1;
    } while (param_1 < pcVar6);
  }
  *pcVar5 = '\0';
  return;
}

[ASK_GPT] 848ba6866d2ff25d
