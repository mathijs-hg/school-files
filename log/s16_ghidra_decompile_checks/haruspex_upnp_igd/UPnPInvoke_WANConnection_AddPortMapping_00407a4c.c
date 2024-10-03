
/* WARNING: Could not reconcile some variable overlaps */

void UPnPInvoke_WANConnection_AddPortMapping
               (char **param_1,undefined4 param_2,undefined4 param_3,char *param_4,ushort param_5,
               char *param_6,ushort param_7,char *param_8,undefined4 param_9,char *param_10,
               undefined4 param_11)

{
  char *__ptr;
  size_t sVar1;
  size_t sVar2;
  char *__s;
  int iVar3;
  size_t sVar4;
  char *__s_00;
  int *piVar5;
  ushort local_60 [2];
  char *local_5c;
  char *local_58;
  undefined4 local_54;
  in_addr_t local_50;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_40;
  uint local_3c;
  size_t local_38;
  size_t local_34;
  size_t local_30;
  
  local_40 = (uint)param_5;
  local_3c = (uint)param_7;
[32m[32m[32m  __ptr = (char *)malloc(0xc);[0m[0m[0m
  if (param_1 != (char **)0x0) {
    local_30 = strlen(*param_1);
    local_34 = strlen(param_4);
    local_38 = strlen(param_6);
    sVar1 = strlen(param_8);
    sVar2 = strlen(param_10);
[32m[32m[32m    __s = (char *)malloc(local_30 + local_34 + 0x239 + local_38 + sVar1 + sVar2);[0m[0m[0m
    iVar3 = sprintf(__s,
                    "%sAddPortMapping xmlns:u=\"%s\"><NewRemoteHost>%s</NewRemoteHost><NewExternalPort>%u</NewExternalPort><NewProtocol>%s</NewProtocol><NewInternalPort>%u</NewInternalPort><NewInternalClient>%s</NewInternalClient><NewEnabled>%d</NewEnabled><NewPortMappingDescription>%s</NewPortMappingDescription><NewLeaseDuration>%u</NewLeaseDuration></u:AddPortMapping%s"
                    ,
                    "<?xml version=\"1.0\" encoding=\"utf-8\"?><s:Envelope s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\" xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\"><s:Body><u:"
                    ,*param_1,param_4,local_40,param_6,local_3c,param_8,param_9,param_10,param_11,
[32m[32m                    "></s:Body></s:Envelope>");[0m[0m
    FUN_00405000(param_1[8]);
    ILibParseUri(param_1[2],&local_5c,local_60,&local_58);
    sVar1 = strlen(local_58);
    sVar2 = strlen(local_5c);
    sVar4 = strlen(*param_1);
[32m[32m[32m    __s_00 = (char *)malloc(sVar1 + sVar2 + 0xa7 + sVar4);[0m[0m[0m
    local_30 = sprintf(__s_00,
                       "POST %s HTTP/1.0\r\nHost: %s:%d\r\nUser-Agent: POSIX, UPnP/1.0, Intel MicroStack/1.0.1423\r\nSOAPACTION: \"%s#%s\"\r\nContent-Type: text/xml\r\nContent-Length: %d\r\n\r\n"
[32m[32m[32m                       ,local_58,local_5c,(uint)local_60[0],*param_1,"AddPortMapping",iVar3);[0m[0m[0m
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    local_54._2_2_ = 0;
    local_54._0_2_ = 2;
    local_50 = inet_addr(local_5c);
    piVar5 = (int *)param_1[8];
    *(undefined4 *)(__ptr + 4) = param_2;
    local_54 = CONCAT22(local_54._0_2_,local_60[0]);
    *(undefined4 *)(__ptr + 8) = param_3;
    ILibAddRequest_DirectEx
              (*(undefined4 *)(*piVar5 + 0x2c),__s_00,local_30,__s,iVar3,&local_54,FUN_0040b438,
               param_1,__ptr);
    free(local_5c);
    __ptr = local_58;
  }
  free(__ptr);
  return;
}

[ASK_GPT] 2a720098fe2d04d0
