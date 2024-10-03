
void ILibSSDP_IPAddressListChanged(int param_1)

{
  bool bVar1;
  char *__s;
  size_t __n;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_48;
  in_addr_t local_44;
  undefined4 local_40;
  sockaddr local_3c;
  
  local_3c.sa_family = 2;
  local_3c.sa_data._2_4_ = inet_addr("239.255.255.250");
  local_3c.sa_data._0_2_ = 0x76c;
  for (iVar4 = 0; iVar4 < *(int *)(param_1 + 0x1c); iVar4 = iVar4 + 1) {
    local_44 = inet_addr("239.255.255.250");
    local_40 = *(undefined4 *)(*(int *)(param_1 + 0x18) + iVar4 * 4);
    setsockopt(*(int *)(param_1 + 0x20),0,0x23,&local_44,8);
  }
  iVar4 = 0;
[32m[32m[32m  __s = (char *)malloc(*(int *)(param_1 + 0x14) + 0x69);[0m[0m[0m
  __n = sprintf(__s,
                "M-SEARCH * HTTP/1.1\r\nMX: 3\r\nST: %s\r\nHOST: 239.255.255.250:1900\r\nMAN: \"ssdp:discover\"\r\n\r\n"
[32m[32m[32m                ,*(undefined4 *)(param_1 + 0x10));[0m[0m[0m
  free(*(void **)(param_1 + 0x18));
  uVar2 = ILibGetLocalIPAddressList(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  while( true ) {
    iVar3 = iVar4 * 4;
    bVar1 = *(int *)(param_1 + 0x1c) <= iVar4;
    iVar4 = iVar4 + 1;
    if (bVar1) break;
    local_48 = *(undefined4 *)(*(int *)(param_1 + 0x18) + iVar3);
    iVar3 = setsockopt(*(int *)(param_1 + 0x24),0,0x20,&local_48,4);
    if (iVar3 == 0) {
      sendto(*(int *)(param_1 + 0x24),__s,__n,0,&local_3c,0x10);
    }
  }
  free(__s);
  return;
}

[ASK_GPT] 1fbf2c9f2786405f
