
uint FUN_00400f50(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  char acStack_350 [256];
  char acStack_250 [256];
  char acStack_150 [256];
  char local_50;
  undefined auStack_4f [67];
  
  local_50 = '\0';
[32m  memset(auStack_4f,0,0x3f);[0m
  Base64decs(param_1,acStack_350);
  Base64decs(param_2,acStack_250);
  cfgRead("USER_ADMIN","Username1",&local_50);
  usrInit(0);
  iVar1 = usrGetGroup(acStack_350);
  uVar2 = usrGetPass(acStack_350,acStack_150,0x100);
  if (uVar2 == 1) {
    if (iVar1 == 0) {
      iVar1 = strcmp(&local_50,acStack_350);
      if (iVar1 == 0) {
        iVar1 = strcmp(acStack_250,acStack_150);
        uVar2 = (uint)(iVar1 != 0);
      }
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  usrFree();
  return uVar2;
}

[ASK_GPT] 31ed96247ec588e5
