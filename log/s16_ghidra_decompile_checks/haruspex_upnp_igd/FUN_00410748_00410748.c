
int FUN_00410748(byte *param_1,int param_2,int *param_3)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  byte *pbVar4;
  int iVar5;
  char local_38 [8];
  undefined *local_30;
  
  if ((param_1 == (byte *)0x0) || (pbVar4 = param_1 + param_2, param_2 == 0)) {
    *param_3 = 0;
    return 0;
  }
  param_2 = param_2 * 3;
  if (param_2 < 0) {
    param_2 = param_2 + 3;
  }
[32m[32m[32m  local_30 = (undefined *)malloc((param_2 >> 2) + 4);[0m[0m[0m
  *param_3 = (int)local_30;
LAB_00410874:
  if (pbVar4 < param_1) {
    iVar5 = *param_3;
    *local_30 = 0;
    return (int)local_30 - iVar5;
  }
  iVar5 = 0;
  pcVar3 = local_38;
LAB_004107e0:
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    if ((bVar1 - 0x2b & 0xff) < 0x50) {
      cVar2 = (&DAT_00416d55)[bVar1];
      if (cVar2 != '\0') {
        if (cVar2 == '$') goto LAB_00410818;
[32m        cVar2 = cVar2 + -0x3d;[0m
      }
    }
    else {
LAB_00410818:
      cVar2 = '\0';
    }
    if (pbVar4 < param_1) {
      *pcVar3 = '\0';
    }
    else {
      if (cVar2 == '\0') goto LAB_004107e0;
      iVar5 = iVar5 + 1;
      *pcVar3 = cVar2 + -1;
    }
    if ((pcVar3 == local_38 + 3) || (pcVar3 = pcVar3 + 1, pbVar4 < param_1)) break;
  } while( true );
  if (iVar5 != 0) {
    FUN_004105f0(local_38,local_30);
    local_30 = local_30 + iVar5 + -1;
  }
  goto LAB_00410874;
}

[ASK_GPT] db1cbf735519a81d
