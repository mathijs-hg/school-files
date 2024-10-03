
undefined4 FUN_00400a6c(undefined4 param_1)

{
  int iVar1;
  int local_128;
  char local_124;
  undefined auStack_123 [263];
  
  local_124 = '\0';
  local_128 = 0;
[32m  memset(auStack_123,0,0xff);[0m
  FUN_004009ec(&local_128);
  iVar1 = local_128;
  fprintf(stderr,"[%s][%s][%s][%d]\nupdate state = %d\n","fw_upgrade","firmware_upgrade.c",
          "safeReboot",0xa4,local_128);
  if (local_128 != 1) {
[32m    sprintf(&local_124,"/var/reboot -d %d 2>/dev/null 1>/dev/null&",param_1);[0m
[32m[32m    system(&local_124);[0m[0m
    fprintf(stderr,"[%s][%s][%s][%d]\nStart reboot....\n","fw_upgrade","firmware_upgrade.c",
            "safeReboot",0xaa,iVar1);
    return 0;
  }
  return 0xffffffff;
}

[ASK_GPT] c7a920073a87d902
