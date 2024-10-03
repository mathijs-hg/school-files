
undefined4 checkSetPolicyType(char *param_1)

{
  FILE *__s;
  size_t __n;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
[32m  unlink("/tmp/.hnap_set_policy_check.xml");[0m
[32m  __s = fopen("/tmp/.hnap_set_policy_check.xml","wb");[0m
  __n = strlen(param_1);
  fwrite(param_1,1,__n,__s);
  fclose(__s);
  iVar1 = ixmlLoadDocument("/tmp/.hnap_set_policy_check.xml");
  if (iVar1 == 0) {
    uVar5 = 0xffffffff;
  }
  else {
    iVar2 = FUN_00409d5c(iVar1,"SetNotifierSettings");
    iVar3 = FUN_00409d5c(iVar1,"DoAction");
    iVar4 = FUN_00409d5c(iVar1,"SetDCHPolicy");
    uVar5 = 0;
    if (iVar2 == 0) {
      if (iVar3 == 0) {
        uVar5 = 2;
        if (iVar4 == 0) {
          uVar5 = 0xffffffff;
        }
      }
      else {
        uVar5 = 1;
      }
    }
    ixmlDocument_free(iVar1);
  }
[32m  unlink("/tmp/.hnap_set_policy_check.xml");[0m
  return uVar5;
}

[ASK_GPT] 3a4771c893078a65
