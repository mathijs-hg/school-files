
void FUN_004054d4(void)

{
  int iVar1;
  undefined4 local_a0;
  char local_9c;
  char local_9b [3];
  int local_98;
  int local_94;
  undefined4 local_90;
  char local_8c;
  char acStack_8b [15];
  char local_7c;
  undefined auStack_7b [31];
  char local_5c;
  undefined auStack_5b [31];
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14 [2];
  
  local_a0 = 0;
  local_9c = '\0';
  cfgRead("DATETIME","TimeZone",&local_a0);
  cfgRead("DATETIME","DayLightSaving",&local_9c);
  if (local_9c == '\0') {
    set_timezone(0,local_a0,0,0);
[32m    system("/usr/sbin/msger camsvr 0 ctimeupdate 0 1 2>/dev/null 1>/dev/null");[0m
  }
  else {
    local_9b[0] = '\0';
    cfgRead("DATETIME","DstAuto",local_9b);
    if (local_9b[0] == '\0') {
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_2c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      local_1c = 0;
      local_18 = 0;
      local_14[0] = 0;
      local_8c = '\0';
[32m      memset(acStack_8b,0,0xf);[0m
      local_7c = '\0';
[32m      memset(auStack_7b,0,0x1f);[0m
      local_5c = '\0';
[32m      memset(auStack_5b,0,0x1f);[0m
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      cfgRead("DATETIME","Offset",&local_8c);
      cfgRead("DATETIME","Starttime",&local_7c);
      cfgRead("DATETIME","Stoptime",&local_5c);
[32m      iVar1 = sscanf(acStack_8b,"%d:%d",&local_98,&local_94);[0m
      if (iVar1 == 2) {
        local_3c = local_98 * 0x3c + local_94;
        if (local_8c == '-') {
          local_3c = -local_3c;
        }
        iVar1 = sscanf(&local_7c,"M%d.%d.%d/%d:%d:%d",&local_38,&local_34,&local_30,&local_2c,
[32m                       &local_28,&local_90);[0m
        if (iVar1 == 6) {
          iVar1 = sscanf(&local_5c,"M%d.%d.%d/%d:%d:%d",&local_24,&local_20,&local_1c,&local_18,
[32m                         local_14,&local_90);[0m
          if (iVar1 == 6) {
            set_timezone(0,local_a0,2,&local_3c);
[32m            system("/usr/sbin/msger camsvr 0 ctimeupdate 0 1 2>/dev/null 1>/dev/null");[0m
          }
        }
      }
    }
    else {
      set_timezone(0,local_a0,1,0);
[32m      system("/usr/sbin/msger camsvr 0 ctimeupdate 0 1 2>/dev/null 1>/dev/null");[0m
    }
  }
  return;
}

[ASK_GPT] 787c1303e53257e6
