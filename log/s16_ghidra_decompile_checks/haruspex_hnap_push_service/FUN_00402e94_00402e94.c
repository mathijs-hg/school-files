
undefined4 FUN_00402e94(char *param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined4 local_50;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  char local_30;
  undefined auStack_2f [35];
  
  puVar2 = &_gp;
  if (param_1 != (char *)0x0) {
    local_30 = '\0';
[32m    memset(auStack_2f,0,0x1f);[0m
    local_50 = local_50 & 0xffffff;
[32m    memset((void *)((int)&local_50 + 1),0,0x1f);[0m
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    net_get_hwaddr(&DAT_00414bc0,&local_50);
    sprintf(&local_30,"%02X:%02X:%02X:%02X:%02X:%02X",local_50 >> 0x18,local_50 >> 0x10 & 0xff,
[32m            local_50 >> 8 & 0xff,local_50 & 0xff,local_4c >> 0x18,local_4c >> 0x10 & 0xff,puVar2);[0m
    iVar1 = strcasecmp(&local_30,param_1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 0xffffffff;
}

[ASK_GPT] 36da4dba01ffdfec
