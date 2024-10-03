
bool DomainEnumQuery(byte *param_1)

{
  int iVar1;
  bool bVar2;
  int *__dest;
  int local_28 [7];
  
  __dest = local_28;
[32m[32m  memcpy(__dest,&PTR_DAT_0046e060,0x18);[0m[0m
  iVar1 = CountLabels(param_1);
  bVar2 = false;
  if (3 < iVar1) {
    do {
      iVar1 = *__dest;
      __dest = __dest + 1;
      if (iVar1 == 0) {
        return false;
      }
      iVar1 = SameDomainLabel(iVar1,param_1);
    } while (iVar1 == 0);
    param_1 = param_1 + *param_1 + 1;
    iVar1 = SameDomainLabel(param_1,&DAT_00455744);
    if (iVar1 == 0) {
      bVar2 = false;
    }
    else {
      iVar1 = SameDomainLabel(param_1 + *param_1 + 1,&DAT_0045c8c8);
      bVar2 = iVar1 != 0;
    }
  }
  return bVar2;
}

[ASK_GPT] d9d5d2b75520e793
