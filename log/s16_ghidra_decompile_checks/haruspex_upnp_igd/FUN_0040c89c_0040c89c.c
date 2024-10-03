
/* WARNING: Could not reconcile some variable overlaps */

void FUN_0040c89c(undefined4 param_1,undefined4 param_2,int param_3,char *param_4,int param_5,
                 int param_6)

{
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  ushort local_40 [2];
  char *local_3c;
  void *local_38;
  undefined4 local_34;
  in_addr_t local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_20;
  
  if (param_3 == 0) {
    iVar1 = FUN_00404b4c(param_6);
    if (iVar1 != 0) {
      ILibLifeTime_Remove(*(undefined4 *)(param_6 + 0x28),iVar1);
      FUN_0040c730(param_6,*(undefined4 *)(iVar1 + 0xc));
      iVar6 = 0;
      while( true ) {
        iVar8 = iVar6 + 1;
        iVar6 = FUN_00402cd4(iVar1,iVar6);
        if (iVar6 == 0) break;
        local_20 = iVar6;
        FUN_00403074(iVar6);
        iVar6 = iVar8;
        if (*(code **)(param_6 + 0x10) != (code *)0x0) {
          (**(code **)(param_6 + 0x10))(local_20);
        }
      }
      do {
        iVar6 = iVar1;
        iVar1 = *(int *)(iVar6 + 0x4c);
      } while (*(int *)(iVar6 + 0x4c) != 0);
      for (iVar1 = *(int *)(iVar6 + 0x3c); iVar1 != 0; iVar1 = iVar1 + -1) {
        FUN_0040917c(iVar6);
      }
      FUN_0040917c(iVar6);
      FUN_0040c730(param_6,param_2);
    }
  }
  else if (param_5 != 0) {
    iVar1 = FUN_004049e0(param_6,param_4);
    if (iVar1 == 0) {
      FUN_00404c30(param_6,param_4);
      iVar1 = FUN_004049e0(param_6,param_2);
      if (iVar1 == 0) {
        FUN_00404c30(param_6,param_2);
        ILibParseUri(param_4,&local_3c,local_40,&local_38);
        pcVar4 = local_3c;
        iVar1 = strcmp(local_3c,RouteIP);
        if (iVar1 == 0) {
          printf("IP: %s Port: %d Path: %s\r\n",pcVar4,(uint)local_40[0],local_38);
          uVar2 = FUN_00401c38(local_3c,local_40[0],local_38,&DAT_004159f4);
          local_30 = 0;
          local_34._2_2_ = 0;
          local_34._0_2_ = 2;
          local_2c = 0;
          local_28 = 0;
          local_30 = inet_addr(local_3c);
          local_34 = CONCAT22(local_34._0_2_,local_40[0]);
          sVar3 = strlen(param_4);
[32m[32m[32m          pcVar4 = (char *)malloc(sVar3 + 1);[0m[0m[0m
[32m[32m          strcpy(pcVar4,param_4);[0m[0m
[32m[32m[32m          piVar5 = (int *)malloc(8);[0m[0m[0m
          uVar7 = *(undefined4 *)(param_6 + 0x2c);
          *piVar5 = param_5;
          piVar5[1] = (int)pcVar4;
          ILibAddRequest(uVar7,uVar2,&local_34,FUN_0040c67c,piVar5,param_6);
          pcVar4 = local_3c;
        }
        free(pcVar4);
        free(local_38);
      }
    }
    else {
      iVar1 = FUN_004049e0(param_6,param_2);
      if (((iVar1 != 0) && (iVar1 = FUN_00404a94(param_6,param_2), iVar1 != 0)) &&
         (iVar1 = FUN_00404b4c(param_6,iVar1), iVar1 != 0)) {
        ILibLifeTime_Remove(*(undefined4 *)(param_6 + 0x28),iVar1);
        ILibLifeTime_AddEx(*(undefined4 *)(param_6 + 0x28),iVar1,param_5 * 1000,FUN_0040cbd8,0);
        FUN_0040917c(iVar1);
      }
    }
  }
  return;
}

[ASK_GPT] e224a03ce821f19e
