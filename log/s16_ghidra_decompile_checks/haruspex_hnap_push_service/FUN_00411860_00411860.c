
undefined4 FUN_00411860(int *param_1,int param_2,int param_3,char *param_4)

{
  undefined4 uVar1;
  int iVar2;
  size_t sVar3;
  size_t sVar4;
  ssize_t sVar5;
  char local_5d0;
  undefined auStack_5cf [1463];
  
  local_5d0 = '\0';
[32m  memset(auStack_5cf,0,0x5b3);[0m
  if ((((param_1 == (int *)0x0) || (param_2 == 0)) || (param_3 < 0)) ||
     ((0xffff < param_3 || (param_4 == (char *)0x0)))) {
    fprintf(stderr,"[hnap_push_service][%s] invalid parameters\n","postHTTPRequest");
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = FUN_0041161c(param_1,param_2,param_3);
    if (iVar2 == 0) {
      *param_1 = -1;
      fprintf(stderr,"[hnap_push_service][%s] doConnect failed\n","postHTTPRequest");
      uVar1 = 0xffffffff;
    }
    else {
      sVar3 = strlen(param_4);
      if (param_3 == 0x50) {
        sprintf(&local_5d0,
                "POST /HNAP1/ HTTP/1.1\r\nHost: %s\r\nContent-Type: text/xml; charset=utf-8\r\nContent-Length: %d\r\nSOAPAction: \"http://%s/HNAP1/PushDCHEvent\"\r\n\r\n"
[32m[32m                ,param_2,sVar3,param_2);[0m[0m
      }
      else {
        sprintf(&local_5d0,
                "POST /HNAP1/ HTTP/1.1\r\nHost: %s:%d\r\nContent-Type: text/xml; charset=utf-8\r\nContent-Length: %d\r\nSOAPAction: \"http://%s/HNAP1/PushDCHEvent\"\r\n\r\n"
[32m[32m                ,param_2,param_3,sVar3,param_2);[0m[0m
      }
      sVar4 = strlen(&local_5d0);
      sVar5 = send(*param_1,&local_5d0,sVar4,0);
      if (sVar5 < 0) {
        close(*param_1);
        *param_1 = -1;
        fprintf(stderr,"[hnap_push_service][%s] send HTTP request failed\n","postHTTPRequest");
        uVar1 = 0xffffffff;
      }
      else if (sVar3 == 0) {
        uVar1 = 0;
      }
      else {
        do {
[32m          sVar4 = 0x5b4;[0m
          if ((int)sVar3 < 0x5b5) {
            sVar4 = sVar3;
          }
          sVar5 = send(*param_1,param_4,sVar4,0);
          sVar3 = sVar3 - sVar5;
          if (sVar5 < 0) {
            close(*param_1);
            *param_1 = -1;
            fprintf(stderr,"[hnap_push_service][%s] send request content failed\n","postHTTPRequest"
                   );
            return 0xffffffff;
          }
          param_4 = param_4 + sVar5;
        } while (sVar3 != 0);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

[ASK_GPT] a5d0847c7e99b2fd
