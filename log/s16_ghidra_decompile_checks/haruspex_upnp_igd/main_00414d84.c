
undefined4 main(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  in_addr local_20 [3];
  
[32m  signal(2,FUN_00415084);[0m
[32m  signal(9,FUN_00415084);[0m
[32m  signal(0xf,FUN_00415084);[0m
  puts("UPnP ControlPoint 1.0 for IGD\r");
[32m  IFaceName = strdup("br0");[0m
  if (((1 < param_1 - 2U) && (param_1 != 5)) && (param_1 != 7)) goto LAB_00414ef0;
  pcVar2 = *(char **)(param_2 + 4);
  iVar1 = strcasecmp(pcVar2,"ppp");
  if ((iVar1 != 0) && (iVar1 = strcasecmp(pcVar2,"ip"), iVar1 != 0)) goto LAB_00414ef0;
  FUN_00414b34(pcVar2);
[32m[32m  sscanf(*(char **)(param_2 + 8),"%d",&DAT_004276a4);[0m[0m
  if (DAT_004276a4 == 2) {
    if (param_1 != 3) goto LAB_00414ef0;
    goto LAB_00414f7c;
  }
  if (DAT_004276a4 == 0) {
    iVar1 = 5;
LAB_00414ee8:
    if (param_1 != iVar1) {
LAB_00414ef0:
      FUN_00414948();
      return ReturnCode;
    }
  }
  else {
    iVar1 = 7;
    if (DAT_004276a4 == 1) goto LAB_00414ee8;
  }
[32m[32m  sscanf(*(char **)(param_2 + 0xc),"%d",&Ext_Port);[0m[0m
[32m[32m  strcpy(Protocol,*(char **)(param_2 + 0x10));[0m[0m
  if (DAT_004276a4 == 1) {
[32m[32m    strcpy(Service,*(char **)(param_2 + 0x14));[0m[0m
[32m[32m    sscanf(*(char **)(param_2 + 0x18),"%d",&Int_Port);[0m[0m
  }
LAB_00414f7c:
  FUN_00414bc8(RouteIP);
  puts(RouteIP);
  iVar1 = net_get_ifaddr(&DAT_004171a8,local_20);
  if (iVar1 < 0) {
    return ReturnCode;
  }
  pcVar2 = inet_ntoa(local_20[0]);
[32m[32m  strcpy(LocalIP,pcVar2);[0m[0m
[32m  strcpy(DeviceType,"urn:schemas-upnp-org:device:WANConnectionDevice:1");[0m
  UPnP_CP_chain = ILibCreateChain();
  UPnP_CP = UPnPCreateControlPoint(UPnP_CP_chain,FUN_0041527c,&LAB_00414940);
  ILibStartChain(UPnP_CP_chain);
  printf("Return Code = %u\n",ReturnCode);
  return ReturnCode;
}

[ASK_GPT] 901758d319ee86c9
