
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 FUN_00401210(int param_1,int param_2,int param_3)

{
  DIR *__dirp;
  int iVar1;
  int iVar2;
  dirent *pdVar3;
  char *__s1;
  int iVar4;
  
  __dirp = opendir("/var/run");
  if (__dirp == (DIR *)0x0) {
    printf("Cannot open %s","/var/run");
  }
  else {
    while (pdVar3 = readdir(__dirp), pdVar3 != (dirent *)0x0) {
      __s1 = pdVar3->d_name;
      iw_message(0x14,"iwcontrol:/var/run/%s\n",__s1);
      iVar1 = strncmp(__s1,"auth",4);
      if (iVar1 == 0) {
[32m[32m[32m        sscanf(__s1,"auth-%s.pid",param_1 + DAT_00418314 * 0x18 + 8);[0m[0m[0m
        iVar1 = DAT_00418314;
        iVar2 = 0;
        iVar4 = param_1 + DAT_00418314 * 0x18;
        do {
          iVar2 = iVar2 + 1;
          if (*(char *)(iVar4 + 8) == '.') {
            *(undefined *)(iVar4 + 8) = 0;
          }
          iVar4 = iVar4 + 1;
        } while (iVar2 != 0x10);
        iVar2 = DAT_00418314 * 0x18;
        DAT_00418314 = DAT_00418314 + 1;
        iw_message(0x14,"auth[%d].wlanName=%s\n",iVar1,param_1 + iVar2 + 8);
      }
      iVar1 = strncmp(__s1,"iapp",4);
      if (iVar1 == 0) {
        DAT_00418318 = 1;
        iw_message(0x14,"link_iapp =true\n");
      }
      iVar1 = strncmp(__s1,"autoconf",8);
      if (iVar1 == 0) {
[32m[32m[32m        sscanf(pdVar3->d_name,"autoconf-%s.pid",param_2 + DAT_0041831c * 0x18 + 8);[0m[0m[0m
        iVar1 = DAT_0041831c;
        iVar2 = param_2 + DAT_0041831c * 0x18;
        *(undefined *)(iVar2 + 0xd) = 0;
        DAT_0041831c = DAT_0041831c + 1;
        iw_message(0x14,"autoconf[%d].wlanName=%s\n",iVar1,iVar2 + 8);
      }
      iVar1 = strncmp(__s1,"wscd",4);
      if (iVar1 == 0) {
        iVar1 = strncmp(__s1,"wscd-wlan0-wlan1.pid",0x14);
        if (iVar1 == 0) {
          iw_message(0x14,"next->d_name=%s\n",__s1);
          iVar1 = DAT_00418320 * 0x18;
          DAT_00418320 = DAT_00418320 + 1;
[32m          strcpy((char *)(param_3 + iVar1 + 8),"wlan0");[0m
          iVar1 = DAT_00418320 * 0x18;
          DAT_00418320 = DAT_00418320 + 1;
[32m          strcpy((char *)(param_3 + iVar1 + 8),"wlan1");[0m
        }
        else {
[32m[32m[32m          sscanf(pdVar3->d_name,"wscd-%s.pid",param_3 + DAT_00418320 * 0x18 + 8);[0m[0m[0m
          iVar1 = DAT_00418320;
          iVar2 = 0;
          iVar4 = param_3 + DAT_00418320 * 0x18;
          do {
            iVar2 = iVar2 + 1;
            if (*(char *)(iVar4 + 8) == '.') {
              *(undefined *)(iVar4 + 8) = 0;
            }
            iVar4 = iVar4 + 1;
          } while (iVar2 != 0x10);
          iVar2 = DAT_00418320 * 0x18;
          DAT_00418320 = DAT_00418320 + 1;
          iw_message(0x14,"wscd[%d].wlanName=%s\n",iVar1,param_3 + iVar2 + 8);
        }
        iVar1 = param_3;
        for (iVar2 = 0; iVar2 < DAT_00418320; iVar2 = iVar2 + 1) {
          iw_message(0x14,"wscd[%d].wlanName=%s\n",iVar2,iVar1 + 8);
          iVar1 = iVar1 + 0x18;
        }
      }
    }
  }
  return 0;
}

[ASK_GPT] 3aec6b0cbcb8314a
