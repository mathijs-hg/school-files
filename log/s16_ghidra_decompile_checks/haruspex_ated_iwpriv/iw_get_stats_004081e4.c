
/* WARNING: Could not reconcile some variable overlaps */

undefined4 iw_get_stats(int param_1,char *param_2,undefined2 *param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  FILE *__stream;
  size_t sVar3;
  char *pcVar4;
  char *pcVar5;
  char *local_128;
  undefined4 local_110;
  char acStack_10c [16];
  undefined2 *local_fc;
  undefined2 local_f8;
  undefined2 local_f6;
  
  if ((param_5 == 0) || (*(byte *)(param_4 + 0x118) < 0xc)) {
[32m    __stream = fopen("/proc/net/wireless","r");[0m
    if (__stream == (FILE *)0x0) {
      uVar2 = 0xffffffff;
    }
    else {
      do {
[32m        pcVar5 = fgets(acStack_10c,0xff,__stream);[0m
        if (pcVar5 == (char *)0x0) {
          fclose(__stream);
          return 0xffffffff;
        }
        local_128 = acStack_10c;
        while ((*local_128 != '\0' && ((*(ushort *)(__ctype_b + *local_128 * 2) & 0x20) != 0))) {
          local_128 = local_128 + 1;
        }
        sVar3 = strlen(param_2);
[32m        iVar1 = strncmp(local_128,param_2,sVar3);[0m
      } while ((iVar1 != 0) || (sVar3 = strlen(param_2), local_128[sVar3] != ':'));
      pcVar5 = strchr(local_128,0x3a);
[32m      pcVar5 = strtok(pcVar5 + 1," ");[0m
[32m[32m      sscanf(pcVar5,"%X",&local_110);[0m[0m
      *param_3 = (short)local_110;
[32m      pcVar5 = strtok((char *)0x0," ");[0m
      pcVar4 = strchr(pcVar5,0x2e);
      if (pcVar4 != (char *)0x0) {
        *(byte *)((int)param_3 + 5) = *(byte *)((int)param_3 + 5) | 1;
      }
[32m[32m      sscanf(pcVar5,"%d",&local_110);[0m[0m
      *(undefined *)(param_3 + 1) = (undefined)local_110;
[32m      pcVar5 = strtok((char *)0x0," ");[0m
      pcVar4 = strchr(pcVar5,0x2e);
      if (pcVar4 != (char *)0x0) {
        *(byte *)((int)param_3 + 5) = *(byte *)((int)param_3 + 5) | 2;
      }
[32m[32m      sscanf(pcVar5,"%d",&local_110);[0m[0m
      *(undefined *)((int)param_3 + 3) = (undefined)local_110;
[32m      pcVar5 = strtok((char *)0x0," ");[0m
      pcVar4 = strchr(pcVar5,0x2e);
      if (pcVar4 != (char *)0x0) {
        *(char *)((int)param_3 + 5) = *(char *)((int)param_3 + 5) + '\x04';
      }
[32m[32m      sscanf(pcVar5,"%d",&local_110);[0m[0m
      *(undefined *)(param_3 + 2) = (undefined)local_110;
[32m      pcVar5 = strtok((char *)0x0," ");[0m
[32m[32m      sscanf(pcVar5,"%d",param_3 + 4);[0m[0m
[32m      pcVar5 = strtok((char *)0x0," ");[0m
[32m[32m      sscanf(pcVar5,"%d",param_3 + 6);[0m[0m
[32m      pcVar5 = strtok((char *)0x0," ");[0m
[32m[32m      sscanf(pcVar5,"%d",param_3 + 0xc);[0m[0m
      fclose(__stream);
      uVar2 = 0;
    }
  }
  else {
    local_f8 = 0x20;
    local_f6 = 1;
    local_fc = param_3;
[32m[32m[32m    strncpy(acStack_10c,param_2,0x10);[0m[0m[0m
[32m[32m[32m    strncpy(acStack_10c,param_2,0x10);[0m[0m[0m
    iVar1 = ioctl(param_1,0x8b0f,acStack_10c);
    if (iVar1 < 0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

[ASK_GPT] e3995c290da9d1d3
