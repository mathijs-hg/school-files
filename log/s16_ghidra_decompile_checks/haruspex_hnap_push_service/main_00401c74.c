
undefined4 main(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  char local_50;
  char local_4f [7];
  char *local_48;
  char *local_44;
  int local_40;
  int local_3c;
  char *local_38;
  undefined *local_34;
  char *local_30;
  
  local_50 = '\0';
  local_4f[0] = '\0';
[32m  signal(2,FUN_00401ae0);[0m
[32m  signal(0xf,FUN_00401ae0);[0m
[32m  signal(3,FUN_00401ae0);[0m
[32m  signal(0xd,(__sighandler_t)0x1);[0m
[32m  signal(0xb,(__sighandler_t)&DAT_004022ac);[0m
  iVar1 = create_hnap_login_info();
  if (iVar1 == -1) {
    fprintf(stderr,"[hnap_push_service][%s] create login file fail!\n",&DAT_00414ae0);
    uVar3 = 0xffffffff;
  }
  else {
    iVar1 = msgInitial(0xa55a00c);
    if (iVar1 == 0) {
      fprintf(stderr,"[hnap_push_service][%s] create message queue fail!\n",&DAT_00414ae0);
      uVar3 = 0xffffffff;
    }
    else {
[32m[32m      g_pPushThread = malloc(0x52b16);[0m[0m
      if (g_pPushThread == (void *)0x0) {
        fprintf(stderr,"[hnap_push_service][%s] allocate thread fail!\n",&DAT_00414ae0);
        uVar3 = 0xffffffff;
      }
      else {
        g_loadDeviceListThread._0_4_ = 0;
        g_loadDeviceListThread._4_2_ = 0;
        load_device_start();
        ReviewPolicyFromFile();
        FUN_00401b2c(0);
        FUN_00401bd0(0);
        local_40 = 1;
        local_3c = 1;
        local_48 = &local_50;
        local_44 = local_4f;
        local_38 = "225810";
        local_34 = &LAB_004022ec;
        local_30 = "230010";
        while (DAT_00427400 == 0) {
          iVar4 = msgWaitSys(iVar1,0,1);
          if (-1 < iVar4) {
            if (DAT_00427400 != 0) {
              uVar3 = 0;
              goto LAB_00402250;
            }
            if (*(int *)(iVar1 + 0x10) == 2000) {
              iVar4 = *(int *)(iVar1 + 0x14);
              if (iVar4 == 0x65) {
                local_50 = '\0';
                local_4f[0] = '\0';
                cfgRead("PRIVACY_MODE","Enable",local_48);
                cfgRead("PRIVACY_MODE","Manual",local_44);
                if (((local_50 == '\0') || (local_4f[0] == '\0')) &&
                   ((uVar2 = FUN_00401bd0(1), 30000 < uVar2 || (local_40 != 0)))) {
                  iVar4 = atoi(local_38);
                  PushDCHEventNotifyCheck(iVar4,local_34,*(undefined4 *)(iVar1 + 0x20));
                  iVar4 = atoi(local_38);
                  NotifierSettingsCheck(iVar4,*(undefined4 *)(iVar1 + 0x20));
                  FUN_00401bd0(0);
                  local_40 = 0;
                }
              }
              else if (iVar4 == 0x66) {
                ReviewPolicyFromFile();
              }
              else if (iVar4 == 100) {
                local_50 = '\0';
                local_4f[0] = '\0';
                cfgRead("PRIVACY_MODE","Enable",local_48);
                cfgRead("PRIVACY_MODE","Manual",local_44);
                if (((local_50 == '\0') || (local_4f[0] == '\0')) &&
                   ((uVar2 = FUN_00401b2c(1), 30000 < uVar2 || (local_3c != 0)))) {
                  iVar4 = atoi(local_30);
                  PushDCHEventNotifyCheck(iVar4,local_34,*(undefined4 *)(iVar1 + 0x20));
                  iVar4 = atoi(local_30);
                  NotifierSettingsCheck(iVar4,*(undefined4 *)(iVar1 + 0x20));
                  FUN_00401b2c(0);
                  local_3c = 0;
                }
              }
            }
          }
        }
        uVar3 = 0;
      }
LAB_00402250:
      msgClean(iVar1,0);
      msgRelease(iVar1);
    }
  }
  fprintf(stderr,"[hnap_push_service][%s] set load device list thread stop!\n",&DAT_00414ae0);
  load_device_stop(&g_loadDeviceListThread);
  while ((char)g_loadDeviceListThread != '\0') {
    load_device_stop(&g_loadDeviceListThread);
    usleep(50000);
  }
  fprintf(stderr,"[hnap_push_service][%s] set push dch event thread stop!\n",&DAT_00414ae0);
  iVar1 = 0;
  if (g_pPushThread != (void *)0x0) {
    do {
      push_dchevent_stop((int)g_pPushThread + iVar1);
      iVar1 = iVar1 + 0x844f;
    } while (iVar1 != 0x52b16);
    do {
      iVar1 = 0;
      iVar4 = 0;
      while (push_dchevent_stop((int)g_pPushThread + iVar4),
            *(char *)((int)g_pPushThread + iVar4 + 5) == '\0') {
        iVar1 = iVar1 + 1;
        iVar4 = iVar1 * 0x844f;
        if (9 < iVar1) {
          usleep(50000);
          free(g_pPushThread);
          g_pPushThread = (void *)0x0;
          goto LAB_00402200;
        }
      }
      usleep(50000);
    } while( true );
  }
LAB_00402200:
  printf("[hnap_push_service][%s] exit!\n",&DAT_00414ae0);
  return uVar3;
}

[ASK_GPT] 749744d183edb10a
