
int process_iwpriv_cmd(char *param_1,char *param_2,size_t param_3)

{
  int __fd;
  int iVar1;
  int local_70;
  char *local_5c [2];
  undefined auStack_54 [4];
  char *local_50;
  
[32m  __fd = iw_sockets_open();[0m
  if (__fd < 0) {
    perror("socket");
    local_70 = -1;
  }
  else {
    memset(param_2,0,param_3);
[32m[32m    strncpy(param_2,param_1,param_3 - 1);[0m[0m
    iVar1 = SplitString(param_2,local_5c,0x50,&DAT_0040eab4);
    iVar1 = strncmp(local_5c[iVar1 + -1],"&",2);
    if (iVar1 == 0) {
[32m[32m      local_70 = system(param_1);[0m[0m
    }
    else {
      iVar1 = strcmp(local_5c[0],"iwpriv");
      if ((iVar1 == 0) && (iVar1 = strncmp(local_5c[1],"ra",2), iVar1 == 0)) {
        if (Calibrated == 0) {
          iVar1 = SplitString(param_1,local_5c,0x50,&DAT_0040eab4);
[32m          local_70 = set_private(__fd,auStack_54,iVar1 + -2,local_5c[1],param_2,param_3);[0m
          iVar1 = strncmp(local_50,"bufferWriteBack",0xf);
          if (iVar1 == 0) {
            Calibrated = 1;
            printf("[%s]Calibrated = %d\n","process_iwpriv_cmd",1);
          }
        }
        else {
          printf("[%s]Invalid commond! DUT has been calibrated.\n","process_iwpriv_cmd");
          local_70 = -1;
        }
      }
      else {
[32m        local_70 = getCmdResults(param_1,0,param_2,param_3);[0m
      }
    }
  }
  if (0 < __fd) {
    close(__fd);
  }
  return local_70;
}

[ASK_GPT] f8959b2af127558d
