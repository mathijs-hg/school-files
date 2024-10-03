
void FUN_00412afc(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 != 0) {
    uVar2 = 0;
    do {
[32m[32m      iVar1 = rand();[0m[0m
      *(char *)(param_1 + uVar2) = (char)iVar1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  return;
}

[ASK_GPT] e33c10c7830ff357
