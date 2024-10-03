
/* WARNING: Could not reconcile some variable overlaps */

undefined4 main(int param_1,char **param_2)

{
  int iVar1;
  undefined *puVar2;
  hostent *phVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined auStack_148 [8];
  int local_140;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  undefined4 *local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined auStack_fc [4];
  undefined4 local_f8 [2];
  undefined8 local_f0;
  sockaddr local_e8;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  sockaddr local_cc;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined8 local_68;
  char *local_60;
  undefined4 *local_5c;
  undefined4 *local_58;
  undefined *local_54;
  undefined8 *local_50;
  undefined4 *local_4c;
  undefined4 **local_48;
  char *local_44;
  int local_40;
  undefined4 local_38;
  undefined4 local_34;
  char *local_30;
  char *local_2c;
  
  local_140 = 0;
  local_13c = 0;
  local_138 = 0;
  local_134 = 600;
  local_130 = 0;
  local_12c = 1;
  local_118 = 0;
  local_114 = 2;
  pcVar9 = (char *)0x0;
  local_68._0_4_ = 0;
  local_60 = "initial frequency %d\n";
  while( true ) {
[32m    iVar1 = getopt(param_1,param_2,"c:df:g:h:i:lp:q:rst6");[0m
    if (iVar1 == -1) break;
    uVar7 = (uint)(iVar1 - 0x36U < 0x3f);
    if (uVar7 == 0) {
switchD_00401f0c_caseD_37:
      FUN_0040100c(*param_2);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    puVar2 = (&switchD_00401f0c::switchdataD_004048e0)[iVar1 - 0x36U];
    switch((uint)puVar2 & 0xfffffffe) {
    case 0x401f14:
      local_138 = atoi(optarg);
      break;
    case 0x401f30:
      debug = debug + 1;
      break;
    case 0x401f40:
      iVar1 = atoi(optarg);
      if (debug != 0) {
[32m        printf(local_60,iVar1);[0m
      }
      FUN_00400fa8(iVar1);
      break;
    case 0x401f88:
      local_130 = atoi(optarg);
      break;
    case 0x401fa4:
      pcVar9 = optarg;
      break;
    case 0x401fb0:
      local_134 = atoi(optarg);
      break;
    case 0x401fcc:
      local_140 = local_140 + 1;
      break;
    case 0x401fdc:
      iVar1 = atoi(optarg);
      local_68._0_4_ = (int)(short)iVar1;
      break;
    case 0x402000:
      atof(optarg);
      min_delay._0_4_ = puVar2;
      min_delay._4_4_ = uVar7;
      break;
    case 0x402258:
      uVar11 = 0;
      puVar8 = (undefined4 *)0x0;
      local_60 = (char *)&local_10c;
      local_5c = &local_104;
      local_58 = &local_100;
      local_54 = auStack_fc;
      local_50 = &local_f0;
      local_4c = local_f8;
      local_48 = &local_108;
      local_44 = "%d %f %f %f %lf %f %d";
      local_40 = 0x15180;
      local_30 = "contemplate %u %.1f %.1f %d\n";
      local_34 = 0;
      local_38 = 0x3ef00000;
      local_2c = "fake %f %d \n";
      iVar1 = 0;
      while( true ) {
[32m        pcVar9 = fgets((char *)&local_cc,100,stdin);[0m
        if (pcVar9 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
          exit(0);
        }
        puVar12 = local_58;
        iVar5 = sscanf((char *)&local_cc,local_44,local_60,local_5c,local_58,local_54,local_50,
[32m[32m[32m                       local_4c,local_48);[0m[0m[0m
        if (iVar5 != 7) break;
        fputs((char *)&local_cc,stdout);
        iVar5 = __fixsfsi(local_104);
        iVar5 = iVar5 + local_10c * local_40;
        uVar6 = __addsf3(local_100,local_f8[0]);
        uVar10 = __extendsfdf2(uVar6);
        puVar13 = (undefined4 *)((ulonglong)uVar10 >> 0x20);
        if (debug != 0) {
[32m          printf(local_30,iVar5,local_f0._0_4_,local_f0._4_4_,puVar13,(int)uVar10,local_108);[0m
          puVar12 = puVar13;
        }
        if (iVar1 == 0) {
          puVar8 = local_108;
        }
        uVar10 = __floatunsidf(iVar5 - iVar1);
        local_68 = uVar10;
        uVar10 = __floatsidf((int)local_108 - (int)puVar8);
        uVar10 = __muldf3(local_68._0_4_,local_68._4_4_,(int)((ulonglong)uVar10 >> 0x20),(int)uVar10
                         );
        uVar10 = __muldf3((int)((ulonglong)uVar10 >> 0x20),(int)uVar10,local_38,local_34);
        uVar11 = __adddf3((int)((ulonglong)uVar11 >> 0x20),(int)uVar11,
                          (int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
        if (debug != 0) {
          puVar12 = puVar8;
[32m          printf(local_2c);[0m
        }
        local_f0._0_4_ = (undefined4)((ulonglong)local_f0 >> 0x20);
        uVar10 = __adddf3((int)((ulonglong)uVar11 >> 0x20),(int)uVar11,local_f0._0_4_,local_f0._4_4_
                          ,puVar12);
        local_108 = puVar8;
        local_f0 = uVar10;
        puVar8 = (undefined4 *)contemplate_data(iVar5);
        iVar1 = iVar5;
      }
      fwrite("Replay input error\n",1,0x13,stderr);
                    /* WARNING: Subroutine does not return */
      exit(2);
    case 0x40231c:
      local_13c = local_13c + 1;
      break;
    case 0x40232c:
      local_12c = 0;
      break;
    case 0x402334:
      local_118 = 1;
      break;
    case 0x402340:
      goto switchD_00401f0c_caseD_37;
    }
  }
  if (pcVar9 == (char *)0x0) {
    FUN_0040100c(*param_2);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if ((((local_13c == 0) || (local_140 != 0)) || (local_130 != 0)) || (local_138 != 0)) {
    if ((local_138 != 1) && (local_134 < 0xf)) {
      local_134 = 0xf;
    }
  }
  else {
    local_138 = 1;
  }
  if (debug != 0) {
    printf("Configuration:\n  -c probe_count %d\n  -d (debug)     %d\n  -g goodness    %d\n  -h hostname    %s\n  -i interval    %d\n  -l live        %d\n  -p local_port  %d\n  -q min_delay   %f\n  -s set_clock   %d\n  -x cross_check %d\n  -6 ipv6support %d\n"
           ,local_138,debug,local_130,pcVar9,local_134,local_140,local_68._0_4_,min_delay._0_4_,
           min_delay._4_4_,local_13c,local_12c,local_118);
  }
  if (local_118 == 0) {
    phVar3 = gethostbyname(pcVar9);
    if (phVar3 == (hostent *)0x0) {
      piVar4 = __h_errno_location();
      *piVar4 = 0;
      herror(pcVar9);
      phVar3 = gethostbyname2(pcVar9,10);
      goto LAB_004024dc;
    }
  }
  else {
    phVar3 = gethostbyname2(pcVar9,10);
    if (phVar3 == (hostent *)0x0) {
      phVar3 = gethostbyname(pcVar9);
LAB_004024dc:
      if (phVar3 == (hostent *)0x0) {
        herror(pcVar9);
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
    }
  }
  if (phVar3->h_addrtype == 10) {
    if (phVar3->h_length == 0x10) {
LAB_00402568:
      local_110 = phVar3->h_length;
      local_114 = phVar3->h_addrtype;
[32m      memcpy(&local_128,*phVar3->h_addr_list,phVar3->h_length);[0m
      if (debug != 0) {
        if (local_114 == 10) {
          fwrite("Use IPv6 address: ",1,0x12,stderr);
          puVar8 = &local_128;
          if (local_110 + -2 < 1) {
            iVar1 = 0;
          }
          else {
            iVar1 = 0;
            do {
              fprintf(stderr,"%X%02X:",(uint)*(byte *)puVar8,(uint)*(byte *)((int)puVar8 + 1));
              iVar1 = iVar1 + 2;
              puVar8 = (undefined4 *)((int)puVar8 + 2);
            } while (iVar1 < local_110 + -2);
          }
          fprintf(stderr,"%X%02X\n",(uint)*(byte *)((int)&local_128 + iVar1),
                  (uint)*(byte *)((int)&local_128 + iVar1 + 1));
        }
        else {
          fwrite("Use IPv4 address: ",1,0x12,stderr);
          iVar1 = 0;
          if (0 < local_110 + -1) {
            puVar2 = auStack_148;
            do {
              fprintf(stderr,"%d.",(uint)(byte)puVar2[0x20]);
              iVar1 = iVar1 + 1;
              puVar2 = auStack_148 + iVar1;
            } while (iVar1 < local_110 + -1);
          }
          fprintf(stderr,"%d\n",(uint)*(byte *)((int)&local_128 + iVar1));
        }
      }
      iVar1 = socket(local_114,1,0x11);
      if (iVar1 == -1) {
        perror("socket");
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      if (local_114 == 10) {
        local_e8.sa_data._2_4_ = 0;
        local_e8.sa_data._6_4_ = 0;
        local_e8.sa_data._10_4_ = 0;
        local_d8 = 0;
        local_d4 = 0;
        local_d0 = 0;
        local_e8.sa_family = 10;
        local_e8.sa_data._0_2_ = (short)local_68._0_4_;
        iVar5 = bind(iVar1,&local_e8,0x1c);
      }
      else {
        local_cc.sa_data._2_4_ = 0;
        local_cc.sa_data._6_4_ = 0;
        local_cc.sa_data._10_4_ = 0;
        local_cc.sa_family = 2;
        local_cc.sa_data._0_2_ = (short)local_68._0_4_;
        iVar5 = bind(iVar1,&local_cc,0x10);
      }
      if (iVar5 == -1) {
        perror("bind");
        fprintf(stderr,"could not bind to udp port %d\n",local_68._0_4_);
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      if (local_114 == 10) {
        local_cc.sa_data._2_4_ = 0;
        local_b4 = 0;
        local_cc.sa_family = 10;
        local_cc.sa_data._6_4_ = local_128;
        local_cc.sa_data._10_4_ = local_124;
        local_bc = local_120;
        local_b8 = local_11c;
        local_cc.sa_data._0_2_ = 0x7b;
        iVar5 = connect(iVar1,&local_cc,0x1c);
      }
      else {
        local_cc.sa_data._6_4_ = 0;
        local_cc.sa_data._10_4_ = 0;
        local_cc.sa_family = 2;
        local_cc.sa_data._2_4_ = local_128;
        local_cc.sa_data._0_2_ = 0x7b;
        iVar5 = connect(iVar1,&local_cc,0x10);
      }
      if (iVar5 != -1) {
        uVar6 = FUN_004010e8(iVar1,auStack_148);
        close(iVar1);
        return uVar6;
      }
      perror("connect");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
  }
  else if ((phVar3->h_addrtype != 2) || (phVar3->h_length == 4)) goto LAB_00402568;
  fprintf(stderr,"oops %d\n",phVar3->h_length);
                    /* WARNING: Subroutine does not return */
  exit(1);
}

[ASK_GPT] 199bf9fa07d26e2f
