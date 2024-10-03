
/* WARNING: Type propagation algorithm not settling */

void FUN_00400e00(void)

{
  int iVar1;
  FILE *__stream;
  char *pcVar2;
  char *pcVar3;
  undefined4 *__haystack;
  stat sStack_1f0;
  undefined4 local_158;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40 [2];
  char *local_38;
  char *local_34;
  char *local_30;
  char *local_2c;
  
  local_158._0_1_ = '\0';
[32m  memset((char *)((int)&local_158 + 1),0,0xff);[0m
  local_58 = local_58 & 0xffffff;
[32m  memset((void *)((int)&local_58 + 1),0,0x13);[0m
  local_44 = 0;
[32m[32m  iVar1 = stat("/tmp/sys_env",&sStack_1f0);[0m[0m
  if (-1 < iVar1) {
[32m    unlink("/tmp/sys_env");[0m
  }
[32m  system("/bin/dd if=/dev/mtdblock1 of=/tmp/sys_env 1>/dev/null 2>/dev/null");[0m
[32m  __stream = fopen("/tmp/sys_env","rb");[0m
  if (__stream != (FILE *)0x0) {
    fseek(__stream,0,1);
[32m[32m    fread(&local_158,1,0x100,__stream);[0m[0m
    fclose(__stream);
  }
  __haystack = &local_158;
  if (local_158._0_1_ != '\0') {
    local_38 = "userconfig: restore mac addr to userconfig\n";
    local_34 = "HW_NIC0_ADDR";
    local_30 = "HW_NIC1_ADDR";
    local_2c = "HW_WLAN0_WLAN_ADDR";
    while( true ) {
      pcVar2 = strstr((char *)__haystack,"eth=");
      if (pcVar2 != (char *)0x0) {
        local_58 = 0;
        local_54 = 0;
        local_50 = 0;
        local_4c = 0;
        local_48 = 0;
        pcVar2 = pcVar2 + 4;
        pcVar3 = strchr(pcVar2,10);
[32m[32m[32m        memcpy(&local_58,pcVar2,(int)pcVar3 - (int)pcVar2);[0m[0m[0m
        fwrite(local_38,1,0x2b,stderr);
        cfgWrite("System",local_34,&local_58,1);
        cfgWrite("System",local_30,&local_58,1);
        cfgWrite("System",local_2c,&local_58,1);
      }
      pcVar2 = strstr((char *)__haystack,"region=");
      if (pcVar2 != (char *)0x0) break;
      __haystack = (undefined4 *)((int)__haystack + 1);
      if (local_158._0_1_ == '\0') {
        return;
      }
      if (__haystack == &local_58) {
        return;
      }
    }
    local_40[0] = 0;
    local_44 = 0;
    pcVar2 = pcVar2 + 7;
    pcVar3 = strchr(pcVar2,10);
[32m[32m[32m    memcpy(&local_44,pcVar2,(int)pcVar3 - (int)pcVar2);[0m[0m[0m
    fwrite("userconfig: restore wifi region to userconfig\n",1,0x2e,stderr);
    local_40[0] = atoi((char *)&local_44);
    cfgWrite("WIRELESS","Region",local_40,1);
  }
  return;
}

[ASK_GPT] 4773d954f08b723c
