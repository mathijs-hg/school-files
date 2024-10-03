
undefined4 *
ILibCreateSSDPClientModule
          (undefined4 param_1,void *param_2,size_t param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  char *__s;
  size_t __n;
  int iVar6;
  undefined local_68 [4];
  undefined4 local_64;
  undefined4 local_60;
  in_addr_t local_5c;
  undefined4 local_58;
  sockaddr local_54;
  sockaddr local_44;
  undefined4 local_30;
  
  local_30 = param_4;
[32m[32m[32m  puVar1 = (undefined4 *)malloc(0x30);[0m[0m[0m
  local_68[0] = 4;
  local_64 = 1;
  local_60 = 0;
  local_54._0_4_ = 0;
  local_54.sa_data._2_4_ = 0;
  local_54.sa_data._6_4_ = 0;
  local_54.sa_data._10_4_ = 0;
  local_44.sa_family = 2;
  local_44.sa_data._2_4_ = inet_addr("239.255.255.250");
  puVar1[2] = FUN_0040fbe4;
  *puVar1 = &LAB_0040f580;
  puVar1[1] = FUN_004102f4;
  local_44.sa_data._0_2_ = 0x76c;
  puVar1[3] = local_30;
  local_54._0_4_ = 0x2076c;
  puVar1[0xb] = param_5;
  local_54.sa_data._2_4_ = 0;
  puVar1[10] = 0;
[32m[32m[32m  pvVar2 = malloc(param_3 + 1);[0m[0m[0m
  puVar1[4] = pvVar2;
[32m  memcpy(pvVar2,param_2,param_3);[0m
  *(undefined *)(puVar1[4] + param_3) = 0;
  puVar1[5] = param_3;
  uVar3 = ILibGetLocalIPAddressList(puVar1 + 6);
  puVar1[7] = uVar3;
  iVar4 = socket(2,1,0);
  puVar1[8] = iVar4;
  ILibGetDGramSocket(0,puVar1 + 9);
  setsockopt(puVar1[9],0,0x21,local_68,1);
  iVar4 = setsockopt(puVar1[8],0xffff,4,&local_64,4);
  if (-1 < iVar4) {
    iVar4 = bind(puVar1[8],&local_54,0x10);
    if (-1 < iVar4) {
      uVar5 = fcntl(puVar1[8],3,0);
      fcntl(puVar1[8],4,uVar5 | 0x80);
      fcntl(puVar1[9],4,uVar5 | 0x80);
      for (iVar4 = 0; iVar4 < (int)puVar1[7]; iVar4 = iVar4 + 1) {
        local_5c = inet_addr("239.255.255.250");
        local_58 = *(undefined4 *)(puVar1[6] + iVar4 * 4);
        iVar6 = setsockopt(puVar1[8],0,0x23,&local_5c,8);
        if (iVar6 < 0) {
          printf("SSDPListenSocket setsockopt mreq");
        }
      }
      ILibAddToChain(param_1,puVar1);
[32m[32m[32m      pvVar2 = malloc(param_3 + 1);[0m[0m[0m
[32m      memcpy(pvVar2,param_2,param_3);[0m
      *(undefined *)((int)pvVar2 + param_3) = 0;
[32m[32m[32m      __s = (char *)malloc(param_3 + 0x69);[0m[0m[0m
      __n = sprintf(__s,
                    "M-SEARCH * HTTP/1.1\r\nMX: 3\r\nST: %s\r\nHOST: 239.255.255.250:1900\r\nMAN: \"ssdp:discover\"\r\n\r\n"
[32m[32m                    ,pvVar2);[0m[0m
      for (iVar4 = 0; iVar4 < (int)puVar1[7]; iVar4 = iVar4 + 1) {
        local_60 = *(undefined4 *)(puVar1[6] + iVar4 * 4);
        iVar6 = setsockopt(puVar1[9],0,0x20,&local_60,4);
        if (iVar6 == 0) {
          sendto(puVar1[9],__s,__n,0,&local_44,0x10);
        }
      }
      free(pvVar2);
      free(__s);
      return puVar1;
    }
    printf("SSDPListenSocket bind");
  }
                    /* WARNING: Subroutine does not return */
  exit(1);
}

[ASK_GPT] 3c7dffcfd513e318
