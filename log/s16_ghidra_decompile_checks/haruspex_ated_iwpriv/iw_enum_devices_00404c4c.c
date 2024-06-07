
void iw_enum_devices(int param_1,code *param_2,undefined4 param_3,undefined4 param_4)

{
  FILE *pFVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  char *local_450;
  uint local_44c;
  char *local_438;
  char local_430;
  char local_42f;
  uint local_30;
  char *local_2c;
  undefined auStack_28 [24];
  
[32m  pFVar1 = fopen("/proc/net/dev","r");[0m
  if (pFVar1 == (FILE *)0x0) {
    local_30 = 0x400;
    local_2c = &local_430;
    iVar3 = ioctl(param_1,0x8912,&local_30);
    pFVar1 = stderr;
    if (iVar3 < 0) {
      piVar4 = __errno_location();
      pcVar2 = strerror(*piVar4);
      fprintf(pFVar1,"SIOCGIFCONF: %s\n",pcVar2);
    }
    else {
      local_450 = local_2c;
      local_44c = local_30 >> 5;
      while (local_44c = local_44c - 1, -1 < (int)local_44c) {
        (*param_2)(param_1,local_450,param_3,param_4);
        local_450 = local_450 + 0x20;
      }
    }
  }
  else {
[32m    fgets(&local_430,0x400,pFVar1);[0m
[32m    fgets(&local_430,0x400,pFVar1);[0m
    while( true ) {
[32m      pcVar2 = fgets(&local_430,0x400,pFVar1);[0m
      if (pcVar2 == (char *)0x0) break;
      if ((local_430 != '\0') && (local_42f != '\0')) {
        local_438 = &local_430;
        while ((*(ushort *)(__ctype_b + *local_438 * 2) & 0x20) != 0) {
          local_438 = local_438 + 1;
        }
        pcVar2 = strrchr(local_438,0x3a);
        if ((pcVar2 == (char *)0x0) || (0x11 < (int)(pcVar2 + (1 - (int)local_438)))) {
          pcVar2 = (char *)0x0;
        }
        else {
[32m[32m[32m          memcpy(auStack_28,local_438,(int)pcVar2 - (int)local_438);[0m[0m[0m
[32m          auStack_28[(int)pcVar2 - (int)local_438] = 0;[0m
        }
        if (pcVar2 == (char *)0x0) {
          fwrite("Cannot parse /proc/net/dev\n",1,0x1b,stderr);
        }
        else {
          (*param_2)(param_1,auStack_28,param_3,param_4);
        }
      }
    }
    fclose(pFVar1);
  }
  return;
}

[ASK_GPT] 816c7c566bd7d90d
