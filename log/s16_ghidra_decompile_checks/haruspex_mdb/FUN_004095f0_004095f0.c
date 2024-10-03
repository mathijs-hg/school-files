
undefined4 FUN_004095f0(int *param_1,char *param_2,int param_3,char *param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  size_t sVar4;
  size_t sVar5;
  ssize_t sVar6;
  int iVar7;
  char local_5e8;
  undefined auStack_5e7 [1459];
  sockaddr local_34;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
  if (param_2 == (char *)0x0) {
    return 0xffffffff;
  }
  if (param_3 < 0) {
    return 0xffffffff;
  }
  if (0xffff < param_3) {
    return 0xffffffff;
  }
  if (param_4 == (char *)0x0) {
    return 0xffffffff;
  }
  local_5e8 = '\0';
[32m  memset(auStack_5e7,0,0x5b3);[0m
  iVar2 = socket(2,2,0);
  *param_1 = iVar2;
  if (-1 < iVar2) {
    local_34.sa_family = 2;
    local_34.sa_data._2_4_ = inet_addr(param_2);
    local_34.sa_data._0_2_ = (undefined2)param_3;
    uVar3 = fcntl(*param_1,3,0);
    if ((int)uVar3 < 0) {
      close(*param_1);
    }
    else {
      iVar2 = fcntl(*param_1,4,uVar3 | 0x80);
      iVar7 = 5;
      if (iVar2 < 0) {
        close(*param_1);
      }
      else {
        do {
          iVar2 = connect(*param_1,&local_34,0x10);
          if (-1 < iVar2) {
            sVar4 = strlen(param_4);
            sprintf(&local_5e8,
                    "POST /HNAP1/ HTTP/1.1\r\nHost: %s:%d\r\nContent-Type: text/xml; charset=utf-8\r\nContent-Length: %d\r\nSOAPAction: \"http://%s/HNAP1/PushDCHEvent\"\r\n\r\n"
[32m[32m                    ,param_2,param_3,sVar4,param_2);[0m[0m
            sVar5 = strlen(&local_5e8);
            sVar6 = send(*param_1,&local_5e8,sVar5,0);
            if (sVar6 < 0) {
              close(*param_1);
              *param_1 = -1;
              return 0xffffffff;
            }
            if (sVar4 == 0) {
              return 0;
            }
            while( true ) {
[32m              sVar5 = 0x5b4;[0m
              if ((int)sVar4 < 0x5b5) {
                sVar5 = sVar4;
              }
              sVar6 = send(*param_1,param_4,sVar5,0);
              sVar4 = sVar4 - sVar6;
              if (sVar6 < 0) break;
              param_4 = param_4 + sVar6;
              if (sVar4 == 0) {
                return 0;
              }
            }
            close(*param_1);
            *param_1 = -1;
            return 0xffffffff;
          }
          sleep(1);
          bVar1 = iVar7 != 1;
          iVar7 = iVar7 + -1;
        } while (bVar1);
        close(*param_1);
      }
    }
  }
  *param_1 = -1;
  return 0xffffffff;
}

[ASK_GPT] 3614bdc29f8a34b5
