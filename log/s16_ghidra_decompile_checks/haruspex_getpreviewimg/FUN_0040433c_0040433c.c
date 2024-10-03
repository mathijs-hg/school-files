
void FUN_0040433c(int *param_1)

{
  size_t sVar1;
  int iVar2;
  size_t __n;
  
  iVar2 = param_1[6];
[32m  __n = 0x1000 - *(int *)(iVar2 + 4);[0m
  if (__n != 0) {
[32m    sVar1 = fwrite(*(void **)(iVar2 + 0x18),1,__n,*(FILE **)(iVar2 + 0x14));[0m
    if (sVar1 != __n) {
      *(undefined4 *)(*param_1 + 0x14) = 0x25;
      (**(code **)*param_1)(param_1);
    }
  }
  fflush(*(FILE **)(iVar2 + 0x14));
  iVar2 = ferror(*(FILE **)(iVar2 + 0x14));
  if (iVar2 != 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x25;
                    /* WARNING: Could not recover jumptable at 0x0040440c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)*param_1)(param_1);
    return;
  }
  return;
}

[ASK_GPT] 4cc77be875b80032
