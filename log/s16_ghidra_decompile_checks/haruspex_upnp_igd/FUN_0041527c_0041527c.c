
/* WARNING: Switch with 1 destination removed at 0x00415430 */
/* WARNING: Could not reconcile some variable overlaps */

void FUN_0041527c(int param_1)

{
  ushort uVar1;
  char *__ptr;
  size_t sVar2;
  char *__s;
  size_t sVar3;
  size_t sVar4;
  char *__s_00;
  int iVar5;
  undefined4 uVar6;
  char **ppcVar7;
  int *piVar8;
  int iVar9;
  code *pcVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  code *pcVar13;
  ushort auStack_50 [2];
  char *pcStack_4c;
  char *pcStack_48;
  undefined4 uStack_44;
  uint local_40;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined *local_20;
  
  local_20 = &_gp;
  for (iVar5 = param_1; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x58)) {
    for (iVar9 = *(int *)(iVar5 + 0x54); iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x24)) {
    }
  }
[32m[32m  strcpy(ServiceType,WAN_Service);[0m[0m
  uVar6 = (**(code **)(local_20 + -0x7f98))(*(undefined4 *)(local_20 + -0x7ea4));
  ppcVar7 = (char **)(**(code **)(local_20 + -0x7de8))
                               (param_1,*(undefined4 *)(local_20 + -0x7ea4),uVar6);
  iVar5 = DAT_004276a4;
  if (DAT_004276a4 == 1) {
    puVar12 = *(undefined4 **)(local_20 + -0x7f54);
    puVar11 = *(undefined4 **)(local_20 + -0x7f24);
    local_40 = *puVar12;
    local_3c = *puVar11;
    (**(code **)(local_20 + -0x7df0))
              ("addportmap: service:[%s] ip:[%s] pro:[%s] extport:%d intport:%d\n",
               *(undefined4 *)(local_20 + -0x7f90),*(undefined4 *)(local_20 + -0x7dec),
               *(undefined4 *)(local_20 + -0x7dd0));
    local_38 = (uint)*(ushort *)((int)puVar11 + 2);
    local_40 = (uint)*(ushort *)((int)puVar12 + 2);
    local_34 = *(undefined4 *)(local_20 + -0x7dec);
    local_3c = *(undefined4 *)(local_20 + -0x7dd0);
    local_2c = *(undefined4 *)(local_20 + -0x7f90);
    local_30 = iVar5;
    local_28 = 0;
    (**(code **)(local_20 + -0x7e0c))(ppcVar7,FUN_00415228,0,"");
  }
  else {
    if (DAT_004276a4 < 2) {
      if (DAT_004276a4 != 0) {
        return;
      }
      uVar1 = *(ushort *)(*(int *)(local_20 + -0x7f54) + 2);
      pcVar13 = *(code **)(local_20 + -0x7ef4);
      pcVar10 = FUN_00415140;
    }
    else {
      if (DAT_004276a4 == 2) {
[32m[32m[32m        __ptr = (char *)malloc(0xc);[0m[0m[0m
        if (ppcVar7 != (char **)0x0) {
          sVar2 = strlen(*ppcVar7);
[32m[32m[32m          __s = (char *)malloc(sVar2 + 0x110);[0m[0m[0m
          iVar5 = sprintf(__s,"%sGetExternalIPAddress xmlns:u=\"%s\"></u:GetExternalIPAddress%s",
                          "<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\" xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\"><s:Body><u:"
[32m[32m                          ,*ppcVar7,"></s:Body></s:Envelope>");[0m[0m
          FUN_00405000(ppcVar7[8]);
          ILibParseUri(ppcVar7[2],&pcStack_4c,auStack_50,&pcStack_48);
          sVar2 = strlen(pcStack_48);
          sVar3 = strlen(pcStack_4c);
          sVar4 = strlen(*ppcVar7);
[32m[32m[32m          __s_00 = (char *)malloc(sVar2 + sVar3 + 0xad + sVar4);[0m[0m[0m
          local_30 = sprintf(__s_00,
                             "POST %s HTTP/1.0\r\nHost: %s:%d\r\nUser-Agent: POSIX, UPnP/1.0, Intel MicroStack/1.0.1423\r\nSOAPACTION: \"%s#%s\"\r\nContent-Type: text/xml\r\nContent-Length: %d\r\n\r\n"
                             ,pcStack_48,pcStack_4c,(uint)auStack_50[0],*ppcVar7,
[32m[32m                             "GetExternalIPAddress",iVar5);[0m[0m
          local_40 = 0;
          local_3c = 0;
          local_38 = 0;
          uStack_44._2_2_ = 0;
          uStack_44._0_2_ = 2;
          local_40 = inet_addr(pcStack_4c);
          piVar8 = (int *)ppcVar7[8];
          *(code **)(__ptr + 4) = FUN_00415480;
          uStack_44 = CONCAT22(uStack_44._0_2_,auStack_50[0]);
          *(undefined4 *)(__ptr + 8) = 0;
          ILibAddRequest_DirectEx
                    (*(undefined4 *)(*piVar8 + 0x2c),__s_00,local_30,__s,iVar5,&uStack_44,
                     FUN_0040b6fc,ppcVar7,__ptr);
          free(pcStack_4c);
          __ptr = pcStack_48;
        }
        free(__ptr);
        return;
      }
      if (DAT_004276a4 != 3) {
        return;
      }
      pcVar13 = *(code **)(local_20 + -0x7f20);
      pcVar10 = FUN_004151d4;
      uVar1 = *(ushort *)(*(int *)(local_20 + -0x7f54) + 2);
    }
    local_40 = (uint)uVar1;
    local_3c = *(undefined4 *)(local_20 + -0x7dd0);
    (*pcVar13)(ppcVar7,pcVar10,0,"");
  }
  return;
}

[ASK_GPT] 4af2f828555e5993
