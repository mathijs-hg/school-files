
void FUN_00402198(undefined4 param_1)

{
  char acStack_88 [128];
  
[32m[32m  sprintf(acStack_88,"/var/run/ipfind-%s.pid",param_1);[0m[0m
  FUN_004013d0("IPFind terminated!\n");
[32m  unlink(acStack_88);[0m
  close(server_sockfd);
  return;
}

[ASK_GPT] 1276b832cd1d69e8
