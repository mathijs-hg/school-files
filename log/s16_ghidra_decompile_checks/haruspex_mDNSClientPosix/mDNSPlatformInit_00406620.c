
undefined4 mDNSPlatformInit(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  __pid_t _Var8;
  undefined2 local_40 [8];
  sockaddr local_30;
  int local_20;
  FILE *local_1c;
  
  if (param_1 == (int *)0x0) {
    __assert("m != ((void *)0)","mDNSPosix.c",0x4f9);
  }
  iVar2 = socket(2,1,0x11);
  local_30.sa_family = 2;
  local_30.sa_data._0_2_ = 0x14e9;
  local_30.sa_data._2_4_ = 0;
  iVar3 = bind(iVar2,&local_30,0x10);
  close(iVar2);
  if (iVar3 == 0) {
    *(undefined *)(param_1 + 2) = 1;
  }
  *(undefined *)(param_1 + 0x696) = 0;
  gethostname((char *)((int)param_1 + 0x1a59),0x3f);
  uVar5 = 0;
  do {
    uVar4 = uVar5 + 1;
[32m    cVar1 = *(char *)((int)param_1 + uVar5 + 0x1a59);[0m
    if ((cVar1 == '\0') || (cVar1 == '.')) break;
    uVar5 = uVar4;
  } while (uVar4 != 0x3f);
  *(char *)(param_1 + 0x696) = (char)(uVar5 & 0xff);
  if ((uVar5 & 0xff) == 0) {
    MakeDomainLabelFromLiteralString(param_1 + 0x696,"Computer");
  }
  if (*(char *)(param_1 + 0x6b6) == '\0') {
    *(undefined *)(param_1 + 0x6a6) = 0;
    gethostname((char *)((int)param_1 + 0x1a99),0x3f);
    iVar2 = 0;
    do {
      iVar3 = iVar2 + 1;
[32m      cVar1 = *(char *)((int)param_1 + iVar2 + 0x1a99);[0m
      if ((cVar1 == '\0') || (cVar1 == '.')) break;
      iVar2 = iVar3;
    } while (iVar3 != 0x3f);
    *(char *)(param_1 + 0x6a6) = (char)iVar2;
  }
  if (*(char *)(param_1 + 0x6a6) == '\0') {
    MakeDomainLabelFromLiteralString(param_1 + 0x6a6,"Computer");
  }
  mDNS_SetFQDN(param_1);
  local_40[0] = 2;
  *(undefined4 *)*param_1 = 0xffffffff;
  iVar2 = FUN_004052b4(local_40,0,0,*param_1);
  local_40[0] = 10;
  *(undefined4 *)(*param_1 + 4) = 0xffffffff;
  if ((iVar2 == 0) && (iVar2 = FUN_004052b4(local_40,0,0,*param_1 + 4), iVar2 == 0)) {
    iVar2 = FUN_00405fc4(param_1);
  }
  mDNS_Lock_(param_1,"mDNSPlatformInit");
  if (iVar2 == 0) {
    FUN_00406464(param_1,"/etc/resolv.conf");
  }
  mDNS_Unlock_(param_1,"mDNSPlatformInit");
  if (iVar2 != 0) {
    return 0xfffeffff;
  }
[32m[32m  piVar6 = (int *)malloc(8);[0m[0m
  if (piVar6 == (int *)0x0) {
    iVar2 = -0x10003;
  }
  else {
    piVar6[1] = (int)param_1;
    iVar2 = socket(0x10,3,0);
    if (iVar2 < 0) {
LAB_00406960:
      piVar7 = __errno_location();
      iVar2 = *piVar7;
      if (iVar2 != 0) goto LAB_0040699c;
    }
    else {
      fcntl(iVar2,4,0x80);
      mDNSPlatformMemZero(&local_30,0xc);
      local_30.sa_family = 0x10;
      local_30.sa_data._6_4_ = 0x11;
      iVar3 = bind(iVar2,&local_30,0xc);
      if (iVar3 != 0) goto LAB_00406960;
      *piVar6 = iVar2;
    }
    iVar2 = FUN_0040423c(*piVar6,FUN_00406380,piVar6);
    if (iVar2 == 0) goto LAB_00406a10;
  }
LAB_0040699c:
  local_1c = stderr;
  local_20 = iVar2;
  _Var8 = getpid();
  fprintf(local_1c,"mDNS(%d) WARNING: Unable to detect interface changes (%d).\n",_Var8,local_20);
LAB_00406a10:
  mDNSCoreInitComplete(param_1,0);
  return 0;
}

[ASK_GPT] f3ee282ce3b240dd
