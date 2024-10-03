
undefined4 FUN_00404c1c(void)

{
  char cVar1;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  undefined local_2a8;
  undefined auStack_2a7 [63];
  char local_268 [64];
  char local_228;
  undefined auStack_227 [255];
  char local_128 [256];
  
  local_2a8 = 0;
[32m  memset(auStack_2a7,0,0x3f);[0m
  local_268[0] = '\0';
[32m  memset(local_268 + 1,0,0x3f);[0m
  local_228 = '\0';
[32m  memset(auStack_227,0,0xff);[0m
  local_128[0] = '\0';
[32m  memset(local_128 + 1,0,0xff);[0m
  cfgRead("USER_ADMIN","Username1",&local_2a8);
  cfgRead("USER_ADMIN","Password1",local_268);
  uVar4 = 0;
  iVar3 = 0;
  while( true ) {
    sVar2 = strlen(local_268);
    if (sVar2 <= uVar4) break;
    cVar1 = local_268[uVar4];
    if ((((cVar1 == '\"') || (cVar1 == '`')) || (cVar1 == '\\')) || (cVar1 == '$')) {
      local_128[iVar3] = '\\';
      iVar3 = iVar3 + 1;
    }
    local_128[iVar3] = cVar1;
    iVar3 = iVar3 + 1;
    uVar4 = uVar4 + 1;
  }
  sprintf(&local_228,"/usr/sbin/set_passwd -u \"%s\" -p \"%s\"  2>/dev/null 1>/dev/null",&local_2a8,
[32m[32m          local_128);[0m[0m
[32m[32m  system(&local_228);[0m[0m
[32m  signal(0x10,(__sighandler_t)0x1);[0m
[32m  system("/etc/init.d/rtmpd-0 stop 2>/dev/null 1>/dev/null");[0m
[32m  system("/etc/init.d/rtspd-0 stop 2>/dev/null 1>/dev/null");[0m
[32m  system("/etc/init.d/httpd-0 reload 2>/dev/null 1>/dev/null");[0m
[32m  system("/etc/init.d/https-0 reload 2>/dev/null 1>/dev/null");[0m
[32m  system("/etc/init.d/rtspd-0 start 2>/dev/null 1>/dev/null");[0m
[32m  system("/etc/init.d/rtmpd-0 start 2>/dev/null 1>/dev/null");[0m
  return 0;
}

[ASK_GPT] 2a5892a57442cac7
