
int mDNS_StartResolveService
              (undefined4 param_1,int param_2,void *param_3,undefined4 param_4,undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  
  mDNS_Lock_(param_1,"mDNS_StartResolveService");
  *(undefined4 *)(param_2 + 0x10) = 0xffffffff;
  *(undefined4 *)(param_2 + 0x134) = *(undefined4 *)((int)param_3 + 0x100);
  *(undefined4 *)(param_2 + 0x138) = 0;
[32m[32m  memcpy((void *)(param_2 + 0x13c),zeroAddr,0x14);[0m[0m
  uVar1 = DomainNameLengthLimit(param_3,(int)param_3 + 0x100);
  if (uVar1 < 0x101) {
    mDNSPlatformMemCopy((void *)(param_2 + 0x154),param_3,uVar1);
  }
  else {
    *(undefined *)(param_2 + 0x154) = 0;
  }
  *(undefined2 *)(param_2 + 0x254) = 0x21;
  *(code **)(param_2 + 0x288) = FUN_00434158;
  *(undefined4 *)(param_2 + 0x2a0) = 0xffffffff;
  *(undefined *)(param_2 + 0x259) = 1;
  *(undefined2 *)(param_2 + 0x256) = 1;
  *(undefined *)(param_2 + 600) = 0;
  *(undefined *)(param_2 + 0x25a) = 0;
  *(undefined *)(param_2 + 0x25b) = 0;
  *(undefined *)(param_2 + 0x25c) = 0;
  *(undefined *)(param_2 + 0x25d) = 0;
  *(undefined *)(param_2 + 0x25e) = 0;
  *(undefined *)(param_2 + 0x263) = 0;
  *(undefined *)(param_2 + 0x264) = 0;
  *(undefined *)(param_2 + 0x25f) = 0;
  *(undefined *)(param_2 + 0x260) = 0;
  *(undefined *)(param_2 + 0x261) = 0;
  *(undefined *)(param_2 + 0x262) = 0;
  *(undefined *)(param_2 + 0x266) = 0;
  *(undefined *)(param_2 + 0xcc) = 0;
  *(undefined *)(param_2 + 0x267) = 0;
  *(undefined4 *)(param_2 + 0x284) = 0;
  *(undefined4 *)(param_2 + 0x44) = 0;
  *(int *)(param_2 + 0x28c) = param_2;
  *(undefined4 *)(param_2 + 0x3c4) = *(undefined4 *)((int)param_3 + 0x100);
  *(undefined4 *)(param_2 + 0x3c8) = 0;
[32m[32m  memcpy((void *)(param_2 + 0x3cc),zeroAddr,0x14);[0m[0m
  uVar1 = DomainNameLengthLimit(param_3,(int)param_3 + 0x100);
  if (uVar1 < 0x101) {
    mDNSPlatformMemCopy((void *)(param_2 + 0x3e4),param_3,uVar1);
  }
  else {
    *(undefined *)(param_2 + 0x3e4) = 0;
  }
  *(undefined2 *)(param_2 + 0x4e4) = 0x10;
  *(undefined **)(param_2 + 0x518) = &LAB_00427c68;
  *(undefined2 *)(param_2 + 0x4e6) = 1;
  *(undefined *)(param_2 + 0x4e8) = 0;
  *(undefined *)(param_2 + 0x4e9) = 1;
  *(undefined *)(param_2 + 0x4ea) = 0;
  *(undefined *)(param_2 + 0x4eb) = 0;
  *(undefined *)(param_2 + 0x4ec) = 0;
  *(undefined *)(param_2 + 0x4ed) = 0;
  *(undefined *)(param_2 + 0x4ee) = 0;
  *(undefined *)(param_2 + 0x4f3) = 0;
  *(undefined *)(param_2 + 0x4f4) = 0;
  *(undefined *)(param_2 + 0x4ef) = 0;
  *(undefined *)(param_2 + 0x4f0) = 0;
  *(undefined *)(param_2 + 0x4f1) = 0;
  *(undefined *)(param_2 + 0x4f2) = 0;
  *(undefined *)(param_2 + 0x4f6) = 0;
  *(undefined *)(param_2 + 0x35c) = 0;
  *(undefined *)(param_2 + 0x4f7) = 0;
  *(undefined4 *)(param_2 + 0x514) = 0;
  *(undefined4 *)(param_2 + 0x2d4) = 0;
  *(int *)(param_2 + 0x51c) = param_2;
  *(undefined4 *)(param_2 + 0x530) = 0xffffffff;
  *(undefined4 *)(param_2 + 0x654) = *(undefined4 *)((int)param_3 + 0x100);
  *(undefined4 *)(param_2 + 0x658) = 0;
[32m[32m  memcpy((void *)(param_2 + 0x65c),zeroAddr,0x14);[0m[0m
  *(undefined4 *)(param_2 + 0x7c0) = 0xffffffff;
  *(undefined *)(param_2 + 0x674) = 0;
  *(undefined2 *)(param_2 + 0x774) = 1;
  *(undefined2 *)(param_2 + 0x776) = 1;
  *(undefined *)(param_2 + 0x778) = 0;
  *(undefined *)(param_2 + 0x779) = 1;
  *(undefined *)(param_2 + 0x77a) = 0;
  *(undefined *)(param_2 + 0x77b) = 0;
  *(undefined *)(param_2 + 0x77c) = 0;
  *(undefined *)(param_2 + 0x77d) = 0;
  *(undefined *)(param_2 + 0x77e) = 0;
  *(undefined *)(param_2 + 0x783) = 0;
  *(undefined *)(param_2 + 0x784) = 0;
  *(undefined *)(param_2 + 0x77f) = 0;
  *(undefined *)(param_2 + 0x780) = 0;
  *(undefined *)(param_2 + 0x781) = 0;
  *(undefined *)(param_2 + 0x782) = 0;
  *(undefined *)(param_2 + 0x786) = 0;
  *(undefined *)(param_2 + 0x5ec) = 0;
  *(undefined *)(param_2 + 0x787) = 0;
  *(undefined4 *)(param_2 + 0x7a4) = 0;
  *(undefined4 *)(param_2 + 0x564) = 0;
  *(code **)(param_2 + 0x7a8) = FUN_00426808;
  *(int *)(param_2 + 0x7ac) = param_2;
  *(undefined4 *)(param_2 + 0x8e4) = *(undefined4 *)((int)param_3 + 0x100);
  *(undefined4 *)(param_2 + 0x8e8) = 0;
[32m[32m  memcpy((void *)(param_2 + 0x8ec),zeroAddr,0x14);[0m[0m
  *(undefined2 *)(param_2 + 0xa04) = 0x1c;
  *(undefined *)(param_2 + 0xa09) = 1;
  *(code **)(param_2 + 0xa38) = FUN_00426808;
  *(undefined4 *)(param_2 + 0xa4c) = param_4;
  *(undefined4 *)(param_2 + 0xa50) = param_5;
  *(undefined *)(param_2 + 0x904) = 0;
  *(undefined2 *)(param_2 + 0xa06) = 1;
  *(undefined *)(param_2 + 0xa08) = 0;
  *(undefined *)(param_2 + 0xa0a) = 0;
  *(undefined *)(param_2 + 0xa0b) = 0;
  *(undefined *)(param_2 + 0xa0c) = 0;
  *(undefined *)(param_2 + 0xa0d) = 0;
  *(undefined *)(param_2 + 0xa0e) = 0;
  *(undefined *)(param_2 + 0xa13) = 0;
  *(undefined *)(param_2 + 0xa14) = 0;
  *(undefined *)(param_2 + 0xa0f) = 0;
  *(undefined *)(param_2 + 0xa10) = 0;
  *(undefined *)(param_2 + 0xa12) = 0;
  *(undefined *)(param_2 + 0xa16) = 0;
  *(undefined *)(param_2 + 0x87c) = 0;
  *(undefined *)(param_2 + 0xa17) = 0;
  *(undefined4 *)(param_2 + 0xa34) = 0;
  *(undefined4 *)(param_2 + 0x7f4) = 0;
  *(int *)(param_2 + 0xa3c) = param_2;
  *(undefined *)(param_2 + 0xa40) = 0;
  *(undefined *)(param_2 + 0xa41) = 0;
  *(undefined *)(param_2 + 0xa42) = 0;
  *(undefined4 *)(param_2 + 0xa44) = 0;
  *(void **)(param_2 + 0xa48) = param_3;
[32m[32m  memcpy((void *)((int)param_3 + 0x104),zeroAddr,0x14);[0m[0m
  *(undefined2 *)((int)param_3 + 0x11a) = 0;
  *(undefined2 *)((int)param_3 + 0x118) = 0;
  iVar2 = mDNS_StartQuery_internal(param_1,param_2);
  if ((iVar2 != 0) || (iVar2 = mDNS_StartQuery_internal(param_1,param_2 + 0x290), iVar2 != 0)) {
    mDNS_StopResolveService(param_1,param_2);
  }
  mDNS_Unlock_(param_1,"mDNS_StartResolveService");
  return iVar2;
}

[ASK_GPT] f59039d98169d494
