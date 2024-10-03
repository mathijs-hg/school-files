
/* WARNING: Could not reconcile some variable overlaps */

void FUN_00402978(int param_1,char *param_2)

{
  int iVar1;
  FILE *__stream;
  size_t __n;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined4 local_8e0;
  char acStack_8dc [16];
  undefined *local_8cc;
  uint local_8c8;
  char local_8bc [256];
  char acStack_7bc [16];
  int local_7ac;
  undefined *local_7a8;
  undefined4 local_7a4;
  int local_7a0;
  undefined4 local_79c;
  int local_798;
  undefined *local_794;
  undefined4 local_790;
  int local_78c;
  undefined auStack_788 [64];
  uint local_748;
  uint local_744;
  int local_740;
  uint local_73c;
  undefined auStack_738 [36];
  int local_714;
  undefined auStack_710 [36];
  int local_6ec;
  undefined auStack_6e8 [2];
  undefined auStack_6e6 [14];
  int local_6d8;
  undefined *local_6d4;
  uint local_6d0;
  int local_6cc;
  undefined *local_6c8;
  undefined4 local_6c4;
  int local_6c0;
  undefined *local_6bc;
  undefined4 local_6b8;
  int local_6b4;
  undefined *local_6b0;
  int local_6ac;
  undefined *local_6a8;
  undefined4 local_6a4;
  undefined4 local_6a0;
  undefined *local_69c;
  uint local_698;
  int local_694;
  undefined *local_690;
  undefined4 local_68c;
  undefined2 local_280;
  undefined local_27e;
  undefined local_27d;
  undefined local_27c;
  byte local_27b;
  undefined4 local_278;
  undefined4 local_274 [3];
  undefined4 local_268 [2];
  int local_260;
  undefined auStack_25c [40];
  undefined4 local_234;
  int local_24;
  
[32m  memset(acStack_7bc,0,0x79c);[0m
[32m[32m[32m  strncpy(acStack_8dc,param_2,0x10);[0m[0m[0m
  iVar1 = ioctl(param_1,0x8b01,acStack_8dc);
  if (iVar1 < 0) {
    fprintf(stderr,"%-8.8s  no wireless extensions.\n\n",param_2);
    return;
  }
[32m[32m  strcpy(acStack_7bc,(char *)&local_8cc);[0m[0m
  iVar1 = get_range_info(param_1,param_2,auStack_25c);
  if (-1 < iVar1) {
    local_24 = 1;
  }
[32m[32m[32m  strncpy(acStack_8dc,param_2,0x10);[0m[0m[0m
  iVar1 = ioctl(param_1,0x8b03,acStack_8dc);
  if (-1 < iVar1) {
    local_7ac = 1;
    local_7a8 = local_8cc;
    local_7a4 = local_8c8;
  }
[32m[32m[32m  strncpy(acStack_8dc,param_2,0x10);[0m[0m[0m
  iVar1 = ioctl(param_1,0x8b09,acStack_8dc);
  if (-1 < iVar1) {
    local_798 = 1;
    local_794 = local_8cc;
    local_790 = local_8c8;
  }
[32m[32m[32m  strncpy(acStack_8dc,param_2,0x10);[0m[0m[0m
  local_8cc = auStack_788;
  local_8c8 = 0;
  iVar1 = ioctl(param_1,0x8b2b,acStack_8dc);
  if (-1 < iVar1) {
    local_748 = local_8c8 >> 0x10;
    local_744 = local_8c8 & 0xffff;
    local_78c = 1;
  }
[32m[32m[32m  strncpy(acStack_8dc,param_2,0x10);[0m[0m[0m
  local_8cc = auStack_738;
  local_8c8 = 0;
  iVar1 = ioctl(param_1,0x8b1b,acStack_8dc);
  if (-1 < iVar1) {
    local_73c = local_8c8 & 0xffff;
    local_740 = 1;
  }
[32m[32m[32m  strncpy(acStack_8dc,param_2,0x10);[0m[0m[0m
  iVar1 = ioctl(param_1,0x8b15,acStack_8dc);
  if (-1 < iVar1) {
    local_6ec = 1;
[32m[32m    memcpy(auStack_6e8,&local_8cc,0x10);[0m[0m
  }
[32m[32m[32m  strncpy(acStack_8dc,param_2,0x10);[0m[0m[0m
  local_8cc = auStack_710;
  local_8c8 = 0;
  iVar1 = ioctl(param_1,0x8b1d,acStack_8dc);
  if ((-1 < iVar1) && (1 < local_8c8._0_2_)) {
    local_714 = 1;
  }
[32m[32m[32m  strncpy(acStack_8dc,param_2,0x10);[0m[0m[0m
  iVar1 = ioctl(param_1,0x8b21,acStack_8dc);
  if (-1 < iVar1) {
    local_6d8 = 1;
    local_6d4 = local_8cc;
    local_6d0 = local_8c8;
  }
[32m[32m[32m  strncpy(acStack_8dc,param_2,0x10);[0m[0m[0m
  iVar1 = ioctl(param_1,0x8b23,acStack_8dc);
  if (-1 < iVar1) {
    local_6cc = 1;
    local_6c8 = local_8cc;
    local_6c4 = local_8c8;
  }
[32m[32m[32m  strncpy(acStack_8dc,param_2,0x10);[0m[0m[0m
  iVar1 = ioctl(param_1,0x8b25,acStack_8dc);
  if (-1 < iVar1) {
    local_6c0 = 1;
    local_6bc = local_8cc;
    local_6b8 = local_8c8;
  }
[32m[32m[32m  strncpy(acStack_8dc,param_2,0x10);[0m[0m[0m
  iVar1 = ioctl(param_1,0x8b07,acStack_8dc);
  if (-1 < iVar1) {
    if (local_8cc < (undefined *)0x6) {
      local_6b4 = 1;
    }
    local_6b0 = local_8cc;
  }
[32m[32m[32m  strncpy(acStack_8dc,param_2,0x10);[0m[0m[0m
  local_8c8 = local_8c8 & 0xffff0000;
  iVar1 = ioctl(param_1,0x8b2d,acStack_8dc);
  if (-1 < iVar1) {
    local_6ac = 1;
    local_6a8 = local_8cc;
    local_6a4 = local_8c8;
  }
[32m[32m[32m  strncpy(acStack_8dc,param_2,0x10);[0m[0m[0m
  iVar1 = ioctl(param_1,0x8b27,acStack_8dc);
  if (-1 < iVar1) {
    local_6a0 = 1;
    local_69c = local_8cc;
    local_698 = local_8c8;
  }
[32m[32m[32m  strncpy(acStack_8dc,param_2,0x10);[0m[0m[0m
  iVar1 = ioctl(param_1,0x8b29,acStack_8dc);
  if (-1 < iVar1) {
    local_694 = 1;
    local_690 = local_8cc;
    local_68c = local_8c8;
  }
[32m  __stream = fopen("/proc/net/wireless","r");[0m
  if (__stream != (FILE *)0x0) {
    do {
[32m      pcVar5 = fgets(local_8bc,0xff,__stream);[0m
      pcVar4 = local_8bc;
      if (pcVar5 == (char *)0x0) {
        fclose(__stream);
        goto LAB_00403aac;
      }
      do {
        pcVar5 = pcVar4;
        if (*pcVar5 == 0) break;
        pcVar4 = pcVar5 + 1;
      } while ((*(ushort *)(__ctype_b + *pcVar5 * 2) & 0x20) != 0);
      __n = strlen(param_2);
[32m      iVar1 = strncmp(pcVar5,param_2,__n);[0m
    } while ((iVar1 != 0) || (pcVar5[__n] != ':'));
    pcVar4 = strchr(pcVar5,0x3a);
[32m    pcVar4 = strtok(pcVar4 + 1," ");[0m
[32m[32m    sscanf(pcVar4,"%X",&local_8e0);[0m[0m
    local_280 = (undefined2)local_8e0;
[32m    pcVar4 = strtok((char *)0x0," ");[0m
    pcVar5 = strchr(pcVar4,0x2e);
    if (pcVar5 != (char *)0x0) {
      local_27b = local_27b | 1;
    }
[32m[32m    sscanf(pcVar4,"%d",&local_8e0);[0m[0m
    local_27e = (undefined)local_8e0;
[32m    pcVar4 = strtok((char *)0x0," ");[0m
    pcVar5 = strchr(pcVar4,0x2e);
    if (pcVar5 != (char *)0x0) {
      local_27b = local_27b | 2;
    }
[32m[32m    sscanf(pcVar4,"%d",&local_8e0);[0m[0m
    local_27d = (undefined)local_8e0;
[32m    pcVar4 = strtok((char *)0x0," ");[0m
    pcVar5 = strchr(pcVar4,0x2e);
    if (pcVar5 != (char *)0x0) {
      local_27b = local_27b + 4;
    }
[32m[32m    sscanf(pcVar4,"%d",&local_8e0);[0m[0m
    local_27c = (undefined)local_8e0;
[32m    pcVar4 = strtok((char *)0x0," ");[0m
[32m[32m    sscanf(pcVar4,"%d",&local_278);[0m[0m
[32m    pcVar4 = strtok((char *)0x0," ");[0m
[32m[32m    sscanf(pcVar4,"%d",local_274);[0m[0m
[32m    pcVar4 = strtok((char *)0x0," ");[0m
[32m[32m    sscanf(pcVar4,"%d",local_268);[0m[0m
    fclose(__stream);
    local_260 = 1;
  }
LAB_00403aac:
  printf("%-8.8s  %s  ",param_2,acStack_7bc);
  if (local_740 != 0) {
    if (local_73c == 0) {
      printf("ESSID:off  ");
    }
    else if ((local_73c & 0xff) < 2) {
      printf("ESSID:\"%s\"  ",auStack_738);
    }
    else {
      printf("ESSID:\"%s\" [%d]  ",auStack_738);
    }
  }
  if (local_714 != 0) {
    printf("Nickname:\"%s\"",auStack_710);
  }
  if ((local_740 != 0) || (uVar6 = 3, local_714 != 0)) {
    uVar6 = 0;
    printf("\n          ");
  }
  if (local_7ac != 0) {
    if (local_7a4._1_1_ == '\0') {
      printf("NWID:%X  ",local_7a8);
    }
    else {
      printf("NWID:off/any  ");
    }
    uVar6 = uVar6 + 2;
  }
  if (local_6b4 != 0) {
    uVar6 = uVar6 + 3;
    printf("Mode:%s  ",(&PTR_DAT_00418150)[(int)local_6b0]);
  }
  if (local_7a0 != 0) {
    iVar1 = __ltsf2(local_79c,0x447a0000);
    if (iVar1 < 0) {
      __extendsfdf2(local_79c);
      pcVar4 = "Channel:%g  ";
    }
    else {
      iVar1 = __gesf2(local_79c,0x4e6e6b28);
      if (iVar1 < 0) {
        iVar1 = __gesf2(local_79c,0x49742400);
        if (iVar1 < 0) {
          uVar7 = __extendsfdf2(local_79c);
          __divdf3((int)((ulonglong)uVar7 >> 0x20),(int)uVar7,0x408f4000,0);
          pcVar4 = "Frequency:%gkHz  ";
        }
        else {
          uVar7 = __extendsfdf2(local_79c);
          __divdf3((int)((ulonglong)uVar7 >> 0x20),(int)uVar7,0x412e8480,0);
          pcVar4 = "Frequency:%gMHz  ";
        }
      }
      else {
        uVar7 = __extendsfdf2(local_79c);
        __divdf3((int)((ulonglong)uVar7 >> 0x20),(int)uVar7,0x41cdcd65,0);
        pcVar4 = "Frequency:%gGHz  ";
      }
    }
    uVar6 = uVar6 + 4;
    printf(pcVar4);
  }
  if (local_6ec != 0) {
    if (8 < uVar6) {
      uVar6 = 0;
      printf("\n          ");
    }
    if ((local_6b4 == 0) || (local_6b0 != (undefined *)0x1)) {
      pcVar4 = "Access Point:";
    }
    else {
      pcVar4 = "Cell:";
    }
    uVar6 = uVar6 + 6;
    printf(pcVar4);
    uVar2 = pr_ether(auStack_6e6);
    printf(" %s",uVar2);
  }
  if (local_6d8 != 0) {
    if (0xb < uVar6) {
      uVar6 = 0;
      printf("\n          ");
    }
    if (local_6d0._0_1_ == '\0') {
      pcVar4 = "Bit Rate:";
    }
    else {
      pcVar4 = "Bit Rate=";
    }
    printf(pcVar4);
    uVar7 = __floatsidf(local_6d4);
    uVar2 = (undefined4)((ulonglong)uVar7 >> 0x20);
    uVar3 = (undefined4)uVar7;
    iVar1 = __gedf2(uVar2,uVar3,0x41cdcd65,0);
    if (iVar1 < 0) {
      iVar1 = __gedf2(uVar2,uVar3,0x412e8480,0);
      if (iVar1 < 0) {
        __divdf3(uVar2,uVar3,0x408f4000,0);
        pcVar4 = "%gkb/s";
      }
      else {
        __divdf3(uVar2,uVar3,0x412e8480,0);
        pcVar4 = "%gMb/s";
      }
    }
    else {
      __divdf3(uVar2,uVar3,0x41cdcd65,0);
      pcVar4 = "%gGb/s";
    }
    uVar6 = uVar6 + 3;
    printf(pcVar4);
    printf("   ");
  }
  if (local_798 != 0) {
    if (10 < uVar6) {
      printf("\n          ");
    }
    if (local_790._0_1_ == '\0') {
      pcVar4 = "Sensitivity:";
    }
    else {
      pcVar4 = "Sensitivity=";
    }
    printf(pcVar4);
    if (local_24 == 0) {
      pcVar4 = "%d  ";
    }
    else {
      if (-1 < (int)local_794) {
        printf("%d/%d  ",local_794,local_234);
        goto LAB_004036bc;
      }
      pcVar4 = "%d dBm  ";
    }
    printf(pcVar4);
  }
LAB_004036bc:
  uVar6 = 0;
  pcVar4 = "\n          ";
  printf("\n          ");
  if (local_694 == 0) goto LAB_00403770;
  printf("Retry");
  if (local_68c._1_1_ == '\0') {
    if ((local_68c & 0xf000) != 0) {
      print_retry_value(stdout,local_690);
    }
    if (local_68c._2_2_ == 0) {
      pcVar5 = ":on";
      goto LAB_0040374c;
    }
  }
  else {
    pcVar5 = ":off";
LAB_0040374c:
    printf(pcVar5);
  }
  uVar6 = 5;
  printf("   ");
LAB_00403770:
  if (local_6cc != 0) {
    if (local_6c4._1_1_ == '\0') {
      if (local_6c4._0_1_ == '\0') {
        pcVar5 = "RTS thr:";
      }
      else {
        pcVar5 = "RTS thr=";
      }
      printf(pcVar5);
      printf("%d B   ",local_6c8);
    }
    else {
      printf("RTS thr:off   ");
    }
    uVar6 = uVar6 + 3;
  }
  if (local_6c0 != 0) {
    if (10 < uVar6) {
      uVar6 = 0;
      printf("\n          ");
    }
    uVar6 = uVar6 + 4;
    if (local_6b8._1_1_ == '\0') {
      if (local_6b8._0_1_ == '\0') {
        pcVar5 = "Fragment thr:";
      }
      else {
        pcVar5 = "Fragment thr=";
      }
      printf(pcVar5);
      printf("%d B   ",local_6bc);
    }
    else {
      printf("Fragment thr:off");
    }
  }
  if (uVar6 != 0) {
    printf("\n          ");
  }
  if (local_78c != 0) {
    printf("Encryption key:");
    if (((local_744 & 0x8000) == 0) && (local_748 != 0)) {
      print_key(stdout,auStack_788);
      if (1 < (local_744 & 0xff)) {
        printf(" [%d]");
      }
      if ((local_744 & 0x4000) != 0) {
        printf("   Encryption mode:restricted");
      }
      pcVar5 = pcVar4;
      if ((local_744 & 0x2000) != 0) {
        printf("   Encryption mode:open");
      }
    }
    else {
      pcVar5 = "off\n          ";
    }
    printf(pcVar5);
  }
  if (local_6ac != 0) {
    printf("Power Management");
    if (local_6a4._1_1_ == '\0') {
      if ((local_6a4 & 0xf000) != 0) {
        print_pm_value(stdout,local_6a8);
      }
      print_pm_mode(stdout,local_6a4 & 0xffff);
      if (local_6a4._2_2_ == 0) {
        printf(":on");
      }
    }
    else {
      pcVar4 = ":off\n          ";
    }
    printf(pcVar4);
  }
  if (local_260 != 0) {
    local_27b = 0;
    printf("Link ");
    print_stats(stdout,&local_27e,auStack_25c,local_24);
    printf("          Rx invalid nwid:%d  invalid crypt:%d  invalid misc:%d\n",local_278,
           local_274[0],local_268[0]);
  }
  putchar(10);
  return;
}

[ASK_GPT] 2a1916b11d5adc39
