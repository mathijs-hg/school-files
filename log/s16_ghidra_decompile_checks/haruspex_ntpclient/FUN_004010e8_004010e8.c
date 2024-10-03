
/* WARNING: Could not reconcile some variable overlaps */

bool FUN_004010e8(uint param_1,int *param_2)

{
  bool bVar1;
  sockaddr *psVar2;
  __fd_mask *p_Var3;
  int iVar4;
  int *piVar5;
  ssize_t sVar6;
  char *pcVar7;
  sockaddr *psVar8;
  __fd_mask *p_Var9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  __fd_mask local_1e0 [32];
  undefined local_160 [16];
  socklen_t local_150;
  timeval local_14c;
  uint local_144;
  uint local_140;
  int local_13c;
  uint local_138;
  undefined4 local_134;
  uint local_130;
  int local_12c;
  uint local_128;
  timespec local_124;
  sockaddr *local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  int local_fc;
  int local_f8;
  undefined8 local_a0;
  int *local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  char *local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  char *local_50;
  char *local_4c;
  char *local_48;
  char *local_44;
  char *local_40;
  char *local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int *local_2c;
  
  if (debug != 0) {
    puts("Listening...");
  }
  local_150 = 0x10;
  local_14c.tv_sec = 0;
  local_14c.tv_usec = 0;
  uVar11 = 1 << (param_1 & 0x1f);
  local_98 = param_2;
  iVar12 = 0;
  p_Var9 = local_1e0 + (param_1 >> 5);
  local_5c = 0;
  local_60 = 0x3fe00000;
  local_54 = 0;
  local_58 = 0x402e8480;
  local_50 = "LI==3";
  local_4c = "STRATUM==0";
  local_48 = "abs(DISP)>65536";
  local_44 = "abs(DELAY)>65536";
  local_40 = "XMT==0";
  local_70 = "ORG!=sent";
  local_3c = "MODE!=3";
  local_a0 = CONCAT44(local_a0._0_4_,local_a0._4_4_);
LAB_00401200:
  while( true ) {
    p_Var3 = local_1e0;
    do {
      *p_Var3 = 0;
      p_Var3 = p_Var3 + 1;
    } while (p_Var3 != (__fd_mask *)local_160);
    *p_Var9 = *p_Var9 | uVar11;
    iVar4 = select(param_1 + 1,(fd_set *)local_1e0,(fd_set *)0x0,(fd_set *)0x0,&local_14c);
    if ((iVar4 == 1) && ((uVar11 & *p_Var9) != 0)) break;
    if (iVar4 < 0) {
      piVar5 = __errno_location();
      if (*piVar5 != 4) {
        perror("select");
      }
    }
    else if (local_14c.tv_sec == 0) {
      if ((param_2[4] <= iVar12) && (bVar1 = false, param_2[4] != 0)) goto LAB_00401e08;
      if (debug != 0) {
        fwrite("Sending ...\n",1,0xc,stderr);
      }
      local_118 = 0;
      local_114 = 0;
      local_110 = 0;
      local_10c = 0;
      local_108 = 0;
      local_104 = 0;
      local_100 = 0;
      local_fc = 0;
      local_f8 = 0;
      local_124.tv_sec = 0x1b0004fa;
      local_124.tv_nsec = 0x10000;
      local_11c = (sockaddr *)0x10000;
      FUN_00401048(local_98,param_2 + 1);
      local_fc = *param_2;
      local_f8 = param_2[1];
      send(param_1,&local_124,0x30,0);
      iVar12 = iVar12 + 1;
      local_14c.tv_sec = param_2[5];
      local_14c.tv_usec = 0;
    }
  }
  psVar8 = (sockaddr *)local_160;
[32m[32m  sVar6 = recvfrom(param_1,&DAT_00415194,0x514,0,psVar8,&local_150);[0m[0m
  local_a0._0_4_ = param_2[6];
  if (sVar6 < 0) {
    perror("recvfrom");
    bVar1 = false;
  }
  else if (sVar6 - 1U < 0x513) {
    FUN_00401048(&local_144,&local_140);
    if (debug != 0) {
      printf("packet of length %d received\n",sVar6);
      if (local_160._0_2_ == 2) {
        uVar10 = (uint)local_160._2_2_;
        pcVar7 = inet_ntoa(local_160._4_4_);
        printf("Source: INET Port %d host %s\n",uVar10,pcVar7);
      }
      else {
        printf("Source: Address family %d\n");
      }
    }
    local_a0 = CONCAT44(local_a0._0_4_,local_a0._4_4_);
    if (local_160._2_2_ != 0x7b) goto LAB_00401200;
    local_68 = DAT_00415194 >> 0x1e;
    local_38 = DAT_00415194 >> 0x1b & 7;
    local_34 = DAT_00415194 >> 0x18 & 7;
    local_30 = DAT_00415194 >> 0x10 & 0xff;
    uVar10 = DAT_00415194 & 0xff;
    if ((DAT_00415194 & 0x80) != 0) {
      uVar10 = uVar10 | 0xffffff00;
    }
    local_88._0_4_ = DAT_00415198;
    local_6c = DAT_0041519c;
    local_64 = DAT_0041519c;
    local_80._0_4_ = DAT_004151a4;
    local_a0._0_4_ = DAT_004151a8;
    local_13c = DAT_004151ac;
    local_138 = DAT_004151b0;
    local_134 = DAT_004151b4;
    local_130 = DAT_004151b8;
    local_12c = DAT_004151bc;
    local_128 = DAT_004151c0;
    if (debug != 0) {
      printf("LI=%d  VN=%d  Mode=%d  Stratum=%d  Poll=%d  Precision=%d\n",local_68,local_38,local_34
             ,local_30,DAT_00415194 >> 8 & 0xff,uVar10);
      uVar13 = __floatsidf(local_88._0_4_);
      uVar13 = __muldf3((int)((ulonglong)uVar13 >> 0x20),(int)uVar13,0x402e8480,0);
      local_90 = uVar13;
      uVar13 = __floatsidf(local_64);
      psVar8 = (sockaddr *)__muldf3((int)((ulonglong)uVar13 >> 0x20),(int)uVar13,0x402e8480,0);
      printf("Delay=%.1f  Dispersion=%.1f  Refid=%u.%u.%u.%u\n");
      printf("Reference %u.%.6u\n",local_80._0_4_,
             (local_a0._0_4_ >> 0xc) + ((local_a0._0_4_ >> 10) + 0x8000 >> 0x10) * -0x2f7);
      printf("(sent)    %u.%.6u\n",*param_2,
             ((uint)param_2[1] >> 0xc) + (((uint)param_2[1] >> 10) + 0x8000 >> 0x10) * -0x2f7);
      printf("Originate %u.%.6u\n",local_13c,
             (local_138 >> 0xc) + ((local_138 >> 10) + 0x8000 >> 0x10) * -0x2f7);
      printf("Receive   %u.%.6u\n",local_134,
             (local_130 >> 0xc) + ((local_130 >> 10) + 0x8000 >> 0x10) * -0x2f7);
      printf("Transmit  %u.%.6u\n",local_12c,
             (local_128 >> 0xc) + ((local_128 >> 10) + 0x8000 >> 0x10) * -0x2f7);
      printf("Our recv  %u.%.6u\n",local_144,
             (local_140 >> 0xc) + ((local_140 >> 10) + 0x8000 >> 0x10) * -0x2f7);
    }
    local_78._0_4_ = &local_144;
    local_a0 = FUN_00400eb0(&local_13c,local_78._0_4_);
    local_90._0_4_ = &local_134;
    local_2c = &local_12c;
    local_80 = FUN_00400eb0(local_90._0_4_,local_2c);
    local_90 = FUN_00400eb0(&local_13c,local_90._0_4_);
    local_78 = FUN_00400eb0(local_2c,local_78._0_4_);
    local_124.tv_sec = 0;
    iVar4 = __adjtimex(&local_124);
    psVar2 = local_11c;
    if (iVar4 < 0) {
      perror("adjtimex");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    if (debug != 0) {
      uVar13 = local_80;
      uVar14 = __subdf3(local_a0._0_4_,local_a0._4_4_,local_80._0_4_,local_80._4_4_,local_80);
      printf("Total elapsed: %9.2f\nServer stall:  %9.2f\nSlop:          %9.2f\n");
      uVar13 = __subdf3(local_90._0_4_,local_90._4_4_,local_78._0_4_,local_78._4_4_,uVar13,uVar14);
      __muldf3((int)((ulonglong)uVar13 >> 0x20),(int)uVar13,0x3fe00000,0);
      psVar8 = psVar2;
      printf(
            "Skew:          %9.2f\nFrequency:     %9d\n day   second     elapsed    stall     skew  dispersion  freq\n"
            );
    }
    if (param_2[7] != 0) {
      pcVar7 = local_50;
      if (local_68 != 3) {
        if ((int)local_38 < 3) {
          pcVar7 = "VN<3";
        }
        else {
          pcVar7 = local_3c;
          if (((((local_34 == 4) && (pcVar7 = local_70, local_13c == *param_2)) &&
               (local_138 == param_2[1])) &&
              ((local_12c != 0 || (pcVar7 = local_40, local_128 != 0)))) &&
             ((pcVar7 = local_44, local_88._0_4_ + 0x10000 < 0x20001 &&
              ((pcVar7 = local_48, local_6c + 0x10000 < 0x20001 &&
               (pcVar7 = local_4c, local_30 != 0)))))) goto LAB_00401a18;
        }
      }
      printf("%d %.5d.%.3d  rejected packet: %s\n",local_144 / 0x15180,local_144 % 0x15180,
             local_140 / 0x418937,pcVar7);
      goto LAB_00401200;
    }
LAB_00401a18:
    if (param_2[3] != 0) {
      local_124.tv_sec = local_12c + 0x7c558180;
      local_124.tv_nsec =
           ((local_128 >> 0xc) + ((local_128 >> 10) + 0x8000 >> 0x10) * -0x2f7) * 1000;
      iVar4 = clock_settime(0,&local_124);
      if (iVar4 < 0) {
        perror("clock_settime");
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      if (debug != 0) {
        printf("set time to %lu.%.9lu\n",local_124.tv_sec,local_124.tv_nsec);
      }
    }
    local_78._0_4_ = (uint *)((ulonglong)local_78 >> 0x20);
    local_90._0_4_ = (undefined4 *)((ulonglong)local_90 >> 0x20);
    if (param_2[2] != 0) {
      uVar13 = __subdf3(local_90._0_4_,local_90._4_4_,local_78._0_4_,local_78._4_4_,psVar8);
      local_88 = __muldf3((int)((ulonglong)uVar13 >> 0x20),(int)uVar13,0x3fe00000,0);
      uVar13 = __floatsidf(local_64);
      uVar13 = __muldf3((int)((ulonglong)uVar13 >> 0x20),(int)uVar13,0x402e8480,0);
      __adddf3(local_a0._0_4_,local_a0._4_4_,(int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
      psVar8 = (sockaddr *)contemplate_data(local_144);
      if ((debug == 0) && (psVar8 != psVar2)) {
        FUN_00400fa8(psVar8);
      }
    }
    local_78._0_4_ = (uint *)((ulonglong)local_78 >> 0x20);
    local_90._0_4_ = (undefined4 *)((ulonglong)local_90 >> 0x20);
    local_88._0_4_ = local_144 / 0x15180;
    local_6c = local_144 % 0x15180;
    local_68 = local_140 / 0x418937;
    uVar13 = __subdf3(local_90._0_4_,local_90._4_4_,local_78._0_4_,local_78._4_4_,local_a0,local_80)
    ;
    __muldf3((int)((ulonglong)uVar13 >> 0x20),(int)uVar13,local_60,local_5c);
    uVar13 = __floatsidf(local_64);
    __muldf3((int)((ulonglong)uVar13 >> 0x20),(int)uVar13,local_58,local_54);
    printf("%d %.5d.%.3d  %8.1f %8.1f  %8.1f %8.1f %9d\n",local_88._0_4_,local_6c,local_68);
    fflush(stdout);
    uVar13 = __subdf3(local_a0._0_4_,local_a0._4_4_,local_80._0_4_,local_80._4_4_);
    iVar4 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
    local_a0._0_4_ = iVar4;
    bVar1 = true;
  }
  else {
    printf("Ooops.  pack_len=%d\n",sVar6);
    fflush(stdout);
    bVar1 = false;
  }
  if (((((int)local_a0._0_4_ < param_2[6]) && (param_2[6] != 0)) ||
      ((local_a0 = CONCAT44(local_a0._0_4_,local_a0._4_4_), param_2[4] <= iVar12 &&
       (local_a0 = CONCAT44(local_a0._0_4_,local_a0._4_4_), param_2[4] != 0)))) &&
     (param_2[3] = 0, local_a0 = CONCAT44(local_a0._0_4_,local_a0._4_4_), param_2[2] == 0)) {
LAB_00401e08:
    return !bVar1;
  }
  goto LAB_00401200;
}

[ASK_GPT] 9c8ce5e358d2905f
