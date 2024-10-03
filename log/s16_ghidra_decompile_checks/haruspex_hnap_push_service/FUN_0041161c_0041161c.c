
undefined4 FUN_0041161c(int *param_1,undefined4 param_2,undefined2 param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  sockaddr local_78;
  char local_68;
  undefined auStack_67 [83];
  
  local_68 = '\0';
[32m  memset(auStack_67,0,0x4f);[0m
  iVar2 = socket(2,2,0);
  *param_1 = iVar2;
  if (iVar2 < 0) {
    fprintf(stderr,"[hnap_push_service][%s] create socket failed\n","doConnect");
  }
  else {
    iVar2 = FUN_00411588(param_2,&local_68);
    if (iVar2 < 0) {
      fprintf(stderr,"[hnap_push_service][%s] gethostnameip failed\n","doConnect");
    }
    else {
      local_78.sa_family = 2;
      local_78.sa_data._2_4_ = inet_addr(&local_68);
      local_78.sa_data._0_2_ = param_3;
      uVar3 = fcntl(*param_1,3,0);
      if ((int)uVar3 < 0) {
        close(*param_1);
        fprintf(stderr,"[hnap_push_service][%s] get socket parameters failed\n","doConnect");
      }
      else {
        iVar2 = fcntl(*param_1,4,uVar3 | 0x80);
        iVar4 = 5;
        if (iVar2 < 0) {
          fprintf(stderr,"[hnap_push_service][%s] set non-blocking failed\n","doConnect");
          close(*param_1);
        }
        else {
          do {
            iVar2 = connect(*param_1,&local_78,0x10);
            if (-1 < iVar2) {
              return 1;
            }
            sleep(1);
            bVar1 = iVar4 != 1;
            iVar4 = iVar4 + -1;
          } while (bVar1);
          close(*param_1);
          fprintf(stderr,"[hnap_push_service][%s] do socket connect failed\n","doConnect");
        }
      }
    }
  }
  return 0;
}

[ASK_GPT] 9dc4df9227545584
