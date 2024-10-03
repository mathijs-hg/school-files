
undefined4 setWlanDrv(int *param_1,char *param_2,int param_3)

{
  int iVar1;
  size_t sVar2;
  uint uVar3;
  uint uVar4;
  
  if (-1 < param_3) {
    SetWMode(param_2,param_3);
  }
  SetRadio(param_2,*param_1 != 0);
  SetESSID(param_2,param_1 + 2);
  if (param_1[0xb] != 0) {
    SetChannel(param_2);
  }
  SetInfraMode(param_2,param_1[1]);
  SetStaNum(param_2,param_1[0xc]);
  uVar3 = param_1[0xd];
  if (uVar3 == 0) {
    uVar4 = 0;
    if (param_1[0xe] == 0) {
      SetAuth(param_2,0);
      SetEnc(param_2,0);
      iVar1 = strcmp(param_2,"wlan0-vxd");
      if (iVar1 == 0) {
        SetWpaPsk(param_2,&DAT_00404c90);
      }
      goto LAB_004033b4;
    }
LAB_004031e4:
    if (param_1[0xe] == 1) {
      if (3 < (uint)param_1[0x11]) {
        return 0xffffffff;
      }
      uVar4 = param_1[0xf];
      if (1 < uVar4) {
        return 0xffffffff;
      }
      iVar1 = param_1[0x10];
      if (iVar1 < 0) {
        return 0xffffffff;
      }
      if (1 < (int)uVar4) {
        return 0xffffffff;
      }
[32m      sVar2 = strlen((char *)((int)param_1 + param_1[0x11] * 0x41 + 0x48));[0m
      if (sVar2 != (iVar1 * 8 + 5) * (uVar4 + 1)) {
        return 0xffffffff;
      }
      if (uVar3 == 0) {
        SetAuth(param_2,0);
      }
      else if (uVar3 == 1) {
        SetAuth(param_2,1);
      }
      else {
        SetAuth(param_2,6);
      }
      SetEnc(param_2,1);
      SetDefaultID(param_2,param_1[0x11]);
      SetWepKey(param_2,param_1[0x11],(int)param_1 + param_1[0x11] * 0x41 + 0x48);
      goto LAB_004033b4;
    }
  }
  else {
    uVar4 = uVar3;
    if (uVar3 < 2) goto LAB_004031e4;
  }
  if (2 < uVar4 - 2) {
    return 0xffffffff;
  }
  if ((param_1[0xe] < 2) || (4 < param_1[0xe])) {
    return 0xffffffff;
  }
  if (uVar3 == 2) {
    SetAuth(param_2,2);
  }
  else if (uVar3 == 3) {
    SetAuth(param_2,5);
  }
  else {
    SetAuth(param_2,7);
  }
  SetEnc(param_2,param_1[0xe]);
  SetWpaPsk(param_2,param_1 + 0x53);
LAB_004033b4:
  StartJoin(param_2);
  return 0;
}

[ASK_GPT] 48cde3c4ff932780
