
void FUN_00414b34(undefined4 param_1)

{
[32m[32m  sprintf(WAN_Service,"urn:schemas-upnp-org:service:WAN%sConnection:1",param_1);[0m[0m
  printf("Use service:%s\n",WAN_Service);
  UPnPEventCallback_WANConnection_PossibleConnectionTypes = &LAB_00414abc;
  UPnPEventCallback_WANConnection_PortMappingNumberOfEntries = &LAB_00414b0c;
  UPnPEventCallback_WANConnection_ExternalIPAddress = &LAB_00414a94;
  UPnPEventCallback_WANConnection_ConnectionStatus = &LAB_00414ae4;
  return;
}

[ASK_GPT] defa48612d9f7026
