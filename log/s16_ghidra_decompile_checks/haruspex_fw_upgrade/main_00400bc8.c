
int main(int param_1,int param_2)

{
  int iVar1;
  FILE *__stream;
  void *__ptr;
  size_t sVar2;
  undefined4 uVar3;
  char *pcVar4;
  size_t __n;
  void *__ptr_00;
  undefined4 uVar5;
  int local_c8 [2];
  stat sStack_c0;
  
  local_c8[0] = 0;
[32m  signal(2,(__sighandler_t)&LAB_00400a08);[0m
[32m  signal(0xf,(__sighandler_t)&LAB_00400a08);[0m
[32m  signal(3,(__sighandler_t)&LAB_00400a08);[0m
[32m  signal(0xb,(__sighandler_t)&LAB_00400a08);[0m
[32m  signal(0x10,(__sighandler_t)&LAB_00400a08);[0m
[32m  signal(0x11,(__sighandler_t)&LAB_00400a08);[0m
[32m  signal(0xd,(__sighandler_t)&LAB_00400a08);[0m
[32m  signal(0x12,(__sighandler_t)&LAB_00400a08);[0m
  if (param_1 != 2) {
    pcVar4 = "[%s][%s][%s][%d]\n[Error] No input file\n";
    uVar5 = 0x3a;
LAB_004010c8:
    fprintf(stderr,pcVar4,"fw_upgrade","firmware_upgrade.c",&DAT_00401a2c,uVar5);
    return -1;
  }
  FUN_004009ec(local_c8);
  if (local_c8[0] == 1) {
    pcVar4 = "[%s][%s][%s][%d]\n[Error] firmware is upgrading\n";
    uVar5 = 0x41;
    goto LAB_004010c8;
  }
[32m[32m  iVar1 = stat(*(char **)(param_2 + 4),&sStack_c0);[0m[0m
  if (iVar1 < 0) {
    pcVar4 = "[%s][%s][%s][%d]\n[Error] Can\'t get size of %s\n";
    uVar5 = *(undefined4 *)(param_2 + 4);
    uVar3 = 0x46;
LAB_0040121c:
    fprintf(stderr,pcVar4,"fw_upgrade","firmware_upgrade.c",&DAT_00401a2c,uVar3,uVar5);
    return -1;
  }
[32m  __stream = fopen(*(char **)(param_2 + 4),"r");[0m
  if (__stream == (FILE *)0x0) {
    uVar5 = *(undefined4 *)(param_2 + 4);
    pcVar4 = "[%s][%s][%s][%d]\n[Error] Can\'t open %s\n";
    uVar3 = 0x4c;
    goto LAB_0040121c;
  }
  FUN_004009d0(1);
  fprintf(stderr,"[%s][%s][%s][%d]\nstop damemons before firmware upgrading\n","fw_upgrade",
          "firmware_upgrade.c",&DAT_00401a2c,0x52);
[32m  system("/etc/init.d/stop_daemon_when_fwup.sh 2>/dev/null 1>/dev/null");[0m
  sleep(1);
  fprintf(stderr,"[%s][%s][%s][%d]\nget firmware size %d\n","fw_upgrade","firmware_upgrade.c",
          &DAT_00401a2c,0x56,sStack_c0.st_blocks);
[32m  __ptr = malloc(sStack_c0.st_blocks);[0m
  if (__ptr == (void *)0x0) {
    fprintf(stderr,"[%s][%s][%s][%d]\n[Error] Can\'t allocate %ld bytes\n","fw_upgrade",
            "firmware_upgrade.c",&DAT_00401a2c,0x59,sStack_c0.st_blocks);
LAB_00400e64:
    iVar1 = -1;
    fclose(__stream);
    FUN_004009d0(3);
    goto LAB_00400e7c;
  }
  __n = sStack_c0.st_blocks;
  __ptr_00 = __ptr;
  if (sStack_c0.st_blocks == 0) {
[32m    sVar2 = 0;[0m
  }
  else {
    do {
[32m[32m[32m      sVar2 = fread(__ptr_00,1,__n,__stream);[0m[0m[0m
      __n = __n - sVar2;
[32m      if ((int)sVar2 < 0) {[0m
        fprintf(stderr,"[%s][%s][%s][%d]\n[Error] Can\'t read %ld bytes from %s\n","fw_upgrade",
                "firmware_upgrade.c",&DAT_00401a2c,0x65,sStack_c0.st_blocks,
                *(undefined4 *)(param_2 + 4));
        free(__ptr);
        goto LAB_00400e64;
      }
      __ptr_00 = (void *)((int)__ptr_00 + sVar2);
    } while (__n != 0);
  }
  fprintf(stderr,"[%s][%s][%s][%d]\nread firmware size %d\n","fw_upgrade","firmware_upgrade.c",
          &DAT_00401a2c,0x6f,sVar2);
  fclose(__stream);
  iVar1 = VerifyFWCode(__ptr,sStack_c0.st_blocks);
  if (iVar1 != 0) {
    iVar1 = -1;
    fprintf(stderr,"[%s][%s][%s][%d]\n[Error] VerifyFWCode failed\n","fw_upgrade",
            "firmware_upgrade.c",&DAT_00401a2c,0x73,sVar2);
    free(__ptr);
    FUN_004009d0(3);
    goto LAB_00400e7c;
  }
[32m  system("/usr/sbin/twinkling 2>/dev/null 1>/dev/null&");[0m
  fprintf(stderr,"[%s][%s][%s][%d]\nbackup restore file\n","fw_upgrade","firmware_upgrade.c",
          &DAT_00401a2c,0x7d,sVar2);
[32m  system("/usr/sbin/userconfig -backup /mnt/flash/config/restore.ini 2>/dev/null 1>/dev/null");[0m
  fprintf(stderr,"[%s][%s][%s][%d]\nstart firmware upgrading\n","fw_upgrade","firmware_upgrade.c",
          &DAT_00401a2c,0x7f);
  iVar1 = UpgradeFWCode(__ptr,sStack_c0.st_blocks);
  fprintf(stderr,"[%s][%s][%s][%d]\nfirmware upgrade done\n","fw_upgrade","firmware_upgrade.c",
          &DAT_00401a2c,0x81);
  if (iVar1 == -2) {
    pcVar4 = "[%s][%s][%s][%d]\ninvalid signature\n";
    uVar5 = 0x8c;
LAB_0040102c:
    fprintf(stderr,pcVar4,"fw_upgrade","firmware_upgrade.c",&DAT_00401a2c,uVar5);
    FUN_004009d0(3);
  }
  else {
    if (iVar1 < -1) {
      if (iVar1 == -3) {
        pcVar4 = "[%s][%s][%s][%d]\nwritting fw failed\n";
        uVar5 = 0x90;
      }
      else {
LAB_0040100c:
        pcVar4 = "[%s][%s][%s][%d]\nI don\'t know\n";
        uVar5 = 0x94;
      }
      goto LAB_0040102c;
    }
    if (iVar1 == -1) {
      pcVar4 = "[%s][%s][%s][%d]\ninvalid file length\n";
      uVar5 = 0x88;
      goto LAB_0040102c;
    }
    if (iVar1 != 0) goto LAB_0040100c;
    fprintf(stderr,"[%s][%s][%s][%d]\nsuccess\n","fw_upgrade","firmware_upgrade.c",&DAT_00401a2c,
            0x84);
    FUN_004009d0(2);
  }
  free(__ptr);
LAB_00400e7c:
  FUN_00400a6c(5);
  return iVar1;
}

[ASK_GPT] 568ed772b0faf66b
