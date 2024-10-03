
/* WARNING: Heritage AFTER dead removal. Example location: r0x00415190 : 0x00403018 */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int contemplate_data(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6,int param_7)

{
  bool bVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int iVar17;
  int iVar18;
  undefined4 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined4 uVar23;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 *local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 *local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 *local_5c;
  undefined8 local_58;
  char *local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 *local_44;
  char *local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  uint local_30;
  char *local_2c;
  
  if (debug != 0) {
    printf("xontemplate %u %.1f %.1f %d\n",param_1,param_3,param_4,param_5,param_6,param_7);
  }
  uVar3 = DAT_004156b4;
  iVar18 = DAT_004156b4 * 0x30;
  *(int *)(&DAT_004156b8 + iVar18) = param_1;
  iVar11 = (uVar3 * 6 + 1) * 8;
  *(undefined4 *)(&DAT_004156bc + iVar11) = param_4;
  *(undefined4 *)(&DAT_004156b8 + iVar11) = param_3;
  uVar20 = __subdf3(param_5,param_6,min_delay._0_4_,min_delay._4_4_);
  *(undefined8 *)(&DAT_004156b8 + (uVar3 * 3 + 1) * 0x10) = uVar20;
  *(int *)(&DAT_004156d0 + iVar18) = param_7;
  if (DAT_004156b0 < 0x10) {
    DAT_004156b0 = DAT_004156b0 + 1;
  }
  if (DAT_004156b0 != 0x10) goto LAB_00403f28;
  if (debug != 0) {
    putchar(10);
  }
  uVar20 = 0;
  local_40 = "hist %d %d %f %f %f\n";
  local_4c = 0;
  local_50 = (char *)0x3ef00000;
  uVar3 = DAT_004156b4;
  while( true ) {
    uVar15 = (undefined4)((ulonglong)uVar20 >> 0x20);
    uVar16 = (undefined4)uVar20;
    iVar18 = uVar3 * 0x30;
    iVar17 = (uVar3 * 6 + 1) * 8;
    uVar20 = __subdf3(*(undefined4 *)(&DAT_004156b8 + iVar17),
                      *(undefined4 *)(&DAT_004156bc + iVar17),uVar15,uVar16);
    iVar11 = (uVar3 * 3 + 1) * 0x10;
    uVar20 = __adddf3((int)((ulonglong)uVar20 >> 0x20),(int)uVar20,
                      *(undefined4 *)(&DAT_004156b8 + iVar11),
                      *(undefined4 *)(&DAT_004156bc + iVar11));
    *(undefined8 *)(&DAT_004156e0 + iVar18) = uVar20;
    uVar20 = __subdf3(*(undefined4 *)(&DAT_004156b8 + iVar17),
                      *(undefined4 *)(&DAT_004156bc + iVar17),uVar15,uVar16);
    uVar20 = __subdf3((int)((ulonglong)uVar20 >> 0x20),(int)uVar20,
                      *(undefined4 *)(&DAT_004156b8 + iVar11),
                      *(undefined4 *)(&DAT_004156bc + iVar11));
    uVar23 = (undefined4)((ulonglong)uVar20 >> 0x20);
    *(undefined8 *)(&DAT_004156d8 + iVar18) = uVar20;
    if (debug != 0) {
      printf(local_40,uVar3,*(int *)(&DAT_004156b8 + iVar18) - param_1,uVar23,uVar15,uVar16,uVar23,
             (int)uVar20,*(undefined4 *)(&DAT_004156e0 + iVar18),
[32m             *(undefined4 *)(&DAT_004156e4 + iVar18));[0m
    }
    uVar14 = uVar3 - 1;
    if ((int)uVar14 < 0) {
      uVar14 = 0xf;
    }
    if (DAT_004156b4 == uVar14) break;
    uVar20 = __floatunsidf(*(int *)(&DAT_004156b8 + uVar3 * 0x30) -
                           *(int *)(&DAT_004156b8 + uVar14 * 0x30));
    local_58 = uVar20;
    uVar20 = __floatsidf(*(int *)(&DAT_004156d0 + uVar3 * 0x30) - param_7);
    uVar20 = __muldf3(local_58._0_4_,local_58._4_4_,(int)((ulonglong)uVar20 >> 0x20),(int)uVar20);
    uVar20 = __muldf3((int)((ulonglong)uVar20 >> 0x20),(int)uVar20,local_50,local_4c);
    uVar20 = __adddf3(uVar15,uVar16,(int)((ulonglong)uVar20 >> 0x20),(int)uVar20);
    uVar3 = uVar14;
  }
  iVar18 = 1;
  uVar3 = FUN_00402920();
  puVar4 = &DAT_004159c8;
  local_48 = &DAT_004159c8;
  local_58._4_4_ = (undefined4 *)0x0;
  local_58._0_4_ = 0xc07f4000;
  local_30 = 1;
  local_50 = "maxseg[%d] = %f *x+ %f\n";
  do {
    uVar14 = FUN_00402934(DAT_004156b4,uVar3,1,1,0,puVar4);
    FUN_00402934(DAT_004156b4,uVar3,0,1,1,&local_88);
    uVar15 = local_84;
    uVar23 = local_88;
    iVar11 = __ltdf2(local_88,local_84,*puVar4,puVar4[1]);
    if (((iVar11 < 0) && (iVar11 = __ltdf2(local_58._0_4_,local_58._4_4_,uVar23,uVar15), iVar11 < 0)
        ) && ((local_30 != 0 || (iVar11 = __ltdf2(uVar23,uVar15,local_78,local_74), iVar11 < 0)))) {
      local_78 = local_88;
      local_74 = local_84;
      local_70 = local_80;
      local_6c = local_7c;
      local_30 = 0;
    }
    if (debug != 0) {
      printf(local_50,iVar18,*puVar4,puVar4[1],puVar4[2],puVar4[3]);
    }
    local_58._4_4_ = (undefined4 *)puVar4[1];
    local_58._0_4_ = *puVar4;
    iVar18 = iVar18 + 1;
    puVar4 = puVar4 + 4;
    uVar3 = uVar14;
  } while (uVar14 != DAT_004156b4);
  if ((debug != 0) && (local_30 == 0)) {
    printf("mincross %f *x+ %f\n",0,local_78,local_74,local_70,local_6c);
  }
  iVar11 = 1;
  uVar3 = FUN_00402920(DAT_004156b4);
  puVar4 = &DAT_00415ad8;
  local_40 = (char *)&DAT_00415ad8;
  local_4c = 0;
  local_50 = (char *)0x407f4000;
  local_38 = 1;
  local_2c = "minseg[%d] = %f *x+ %f\n";
  do {
    uVar14 = FUN_00402934(DAT_004156b4,uVar3,0,0,1,puVar4);
    uVar23 = 0;
    puVar8 = &local_88;
    FUN_00402934(DAT_004156b4,uVar3,1,0,0,&local_88);
    local_58._4_4_ = (undefined4 *)local_84;
    local_58._0_4_ = local_88;
    iVar17 = __gtdf2(local_88,local_84,*puVar4,puVar4[1]);
    if (((0 < iVar17) &&
        (iVar17 = __gtdf2(local_50,local_4c,local_58._0_4_,local_58._4_4_), 0 < iVar17)) &&
       ((local_38 != 0 ||
        (iVar17 = __ltdf2(local_58._0_4_,local_58._4_4_,local_68,local_64), iVar17 < 0)))) {
      local_68 = local_88;
      local_64 = local_84;
      local_60 = local_80;
      local_5c = local_7c;
      local_38 = 0;
    }
    if (debug != 0) {
      puVar8 = (undefined4 *)puVar4[3];
      uVar23 = puVar4[2];
      printf(local_2c,iVar11,*puVar4,puVar4[1],uVar23,puVar8);
    }
    local_4c = puVar4[1];
    local_50 = (char *)*puVar4;
    iVar11 = iVar11 + 1;
    puVar4 = puVar4 + 4;
    uVar3 = uVar14;
  } while (uVar14 != DAT_004156b4);
  iVar17 = 1;
  if (local_38 == 0) {
    iVar17 = local_30;
  }
  if ((debug != 0) && (local_38 == 0)) {
    uVar23 = local_60;
    puVar8 = local_5c;
    printf("maxcross %f *x+ %f\n",0,local_68,local_64,local_60,local_5c);
  }
  if (iVar17 == 0) {
    DAT_00415bdc = 0;
    DAT_00415bd8 = 0x40340000;
    DAT_00415be4 = 0;
    DAT_00415be0 = 0x40340000;
    FUN_00402d2c(&local_78);
    bVar1 = true;
    if (iVar18 < 2) {
      iVar13 = 1;
LAB_00403748:
      if (debug == 0) {
        iVar17 = 1;
      }
      else {
        puts("found maxseg vs. save_min inconsistency");
        iVar17 = 1;
      }
    }
    else {
      iVar13 = 1;
      do {
        if ((bVar1) && (iVar5 = __gtdf2(*local_48,local_48[1],local_78,local_74), 0 < iVar5)) {
          local_48[-4] = local_78;
          local_48[-3] = local_74;
          local_48[-2] = local_70;
          local_48[-1] = local_6c;
          bVar1 = false;
        }
        iVar5 = __gtdf2(*local_48,local_48[1],local_68,local_64);
        if (0 < iVar5) break;
        if (!bVar1) {
          FUN_00402d2c(local_48);
        }
        iVar13 = iVar13 + 1;
        local_48 = local_48 + 4;
      } while (iVar13 < iVar18);
      if (bVar1) goto LAB_00403748;
    }
    (&DAT_004159b8)[iVar13 * 4] = local_68;
    (&DAT_004159bc)[iVar13 * 4] = local_64;
    (&DAT_004159c0)[iVar13 * 4] = local_60;
    (&DAT_004159c4)[iVar13 * 4] = local_5c;
    FUN_00402d2c(&local_68);
    bVar1 = true;
    if (iVar11 < 2) {
      iVar18 = 1;
LAB_00403884:
      if (debug == 0) {
        iVar17 = 1;
      }
      else {
        puts("found minseg vs. save_max inconsistency");
        iVar17 = 1;
      }
    }
    else {
      iVar18 = 1;
      do {
        if ((bVar1) &&
           (iVar13 = __ltdf2(*(undefined4 *)local_40,*(undefined4 *)((int)local_40 + 4),local_68,
                             local_64), iVar13 < 0)) {
          DAT_00415ac8 = local_68;
          DAT_00415acc = local_64;
          DAT_00415ad0 = local_60;
          DAT_00415ad4 = local_5c;
          bVar1 = false;
        }
        iVar13 = __ltdf2(*(undefined4 *)local_40,*(undefined4 *)((int)local_40 + 4),local_78,
                         local_74);
        if (iVar13 < 0) break;
        if (!bVar1) {
          FUN_00402d2c(local_40);
        }
        iVar18 = iVar18 + 1;
        local_40 = (char *)((int)local_40 + 0x10);
      } while (iVar18 < iVar11);
      if (bVar1) goto LAB_00403884;
    }
    (&DAT_00415ac8)[iVar18 * 4] = local_68;
    (&DAT_00415acc)[iVar18 * 4] = local_64;
    (&DAT_00415ad0)[iVar18 * 4] = local_60;
    (&DAT_00415ad4)[iVar18 * 4] = local_5c;
    if (debug != 0) {
      FUN_00402d2c(&local_78);
    }
    uVar15 = DAT_00415bdc;
    uVar3 = DAT_00415bd8;
    if (iVar17 == 0) {
      iVar18 = __eqdf2(DAT_00415bd8,DAT_00415bdc,0,0);
      uVar16 = DAT_00415be4;
      uVar14 = DAT_00415be0;
      if (iVar18 == 0) {
        iVar18 = __eqdf2(DAT_00415be0,DAT_00415be4,0,0);
        if (iVar18 == 0) {
          local_30 = 0;
          uVar3 = 0;
          uVar15 = 0;
        }
        else {
          uVar3 = uVar14 ^ 0x80000000;
          local_30 = 0;
          uVar15 = uVar16;
        }
      }
      else {
        iVar18 = __eqdf2(DAT_00415be0,DAT_00415be4,0,0);
        local_30 = (uint)(iVar18 != 0);
        if (iVar18 != 0) {
          uVar3 = 0;
          uVar15 = 0;
        }
      }
      if (debug != 0) {
        printf("find_df() = %e\n");
      }
      local_3c = local_64;
      local_40 = (char *)local_68;
      local_34 = local_74;
      local_38 = local_78;
      uVar20 = __adddf3(local_68,local_64,local_78,local_74);
      uVar20 = __muldf3((int)((ulonglong)uVar20 >> 0x20),(int)uVar20,0x3fe00000,0);
      uVar20 = __adddf3(uVar3,uVar15,(int)((ulonglong)uVar20 >> 0x20),(int)uVar20);
      uVar16 = (undefined4)((ulonglong)uVar20 >> 0x20);
      local_58._4_4_ = local_5c;
      local_58._0_4_ = local_60;
      local_44 = local_6c;
      local_48 = (undefined4 *)local_70;
      uVar21 = __adddf3(local_60,local_5c,local_70,local_6c);
      uVar21 = __muldf3((int)((ulonglong)uVar21 >> 0x20),(int)uVar21,0x3fe00000,0);
      uVar6 = (undefined4)((ulonglong)uVar21 >> 0x20);
      uVar9 = (undefined4)uVar21;
      uVar21 = __divdf3(uVar6,uVar9,0xc082c000,0);
      uVar21 = __subdf3((int)((ulonglong)uVar21 >> 0x20),(int)uVar21,uVar16,(int)uVar20);
      uVar7 = (undefined4)((ulonglong)uVar21 >> 0x20);
      local_50 = (char *)uVar21;
      uVar21 = __divdf3(uVar6,uVar9,0xc09c2000,0);
      uVar20 = __subdf3((int)((ulonglong)uVar21 >> 0x20),(int)uVar21,uVar16,(int)uVar20);
      uVar16 = (undefined4)((ulonglong)uVar20 >> 0x20);
      uVar10 = (undefined4)uVar20;
      iVar18 = __ltdf2(uVar6,uVar9,0,0);
      if (iVar18 < 0) {
        iVar18 = __gtdf2(uVar16,uVar10,0,0);
        uVar12 = 0;
        if (0 < iVar18) {
          uVar12 = uVar16;
        }
        uVar19 = 0;
        if (0 < iVar18) {
          uVar19 = uVar10;
        }
        iVar18 = __ltdf2(uVar7,local_50,0,0);
        if (iVar18 < 0) {
          uVar12 = uVar7;
          uVar19 = local_50;
        }
      }
      else {
        uVar12 = 0;
        uVar19 = 0;
      }
      iVar18 = __gedf2(uVar6,uVar9,0,0);
      uVar21 = CONCAT44(uVar12,uVar19);
      if (-1 < iVar18) {
        iVar18 = __gtdf2(uVar7,local_50,0,0);
        if (0 < iVar18) {
          uVar19 = local_50;
          uVar12 = uVar7;
        }
        iVar18 = __ltdf2(uVar16,uVar10,0,0);
        uVar21 = CONCAT44(uVar12,uVar19);
        if (iVar18 < 0) {
          uVar21 = uVar20;
        }
      }
      iVar18 = __ltdf2(local_58._0_4_,local_58._4_4_,0xc08f4000,0);
      if ((iVar18 < 0) || (iVar18 = __gtdf2(local_48,local_44,0x408f4000,0), 0 < iVar18)) {
        uVar20 = 0;
      }
      else {
        uVar20 = __subdf3(local_58._0_4_,local_58._4_4_,local_48,local_44);
        uVar20 = __adddf3((int)((ulonglong)uVar20 >> 0x20),(int)uVar20,0x408f4000,0);
        uVar22 = __subdf3(local_40,local_3c,local_38,local_34);
        uVar22 = __muldf3((int)((ulonglong)uVar22 >> 0x20),(int)uVar22,0x4092c000,0);
        uVar20 = __adddf3((int)((ulonglong)uVar20 >> 0x20),(int)uVar20,
                          (int)((ulonglong)uVar22 >> 0x20),(int)uVar22);
        uVar22 = __divdf3(0x408f4000,0,(int)((ulonglong)uVar20 >> 0x20),(int)uVar20);
        uVar2 = (ulonglong)uVar22 >> 0x20;
        uVar16 = (undefined4)uVar22;
        uVar20 = CONCAT44(uVar23,puVar8);
        if (debug != 0) {
          printf("find_df_center %f %f\n");
          uVar20 = uVar22;
        }
        uVar20 = __muldf3((int)uVar2,uVar16,(int)((ulonglong)uVar21 >> 0x20),(int)uVar21,uVar20);
      }
      uVar20 = __adddf3(uVar3,uVar15,(int)((ulonglong)uVar20 >> 0x20),(int)uVar20);
      uVar23 = (undefined4)((ulonglong)uVar20 >> 0x20);
      uVar21 = __muldf3(uVar23,(int)uVar20,0x40f00000,0);
      uVar21 = __adddf3((int)((ulonglong)uVar21 >> 0x20),(int)uVar21,0x3fe00000,0);
      iVar18 = __fixdfsi((int)((ulonglong)uVar21 >> 0x20),(int)uVar21);
      if (debug != 0) {
        printf("delta_f %f  delta_freq %d  bsn %d\n",local_30,uVar23,(int)uVar20,iVar18,local_30);
      }
      iVar18 = param_7 - iVar18;
      printf("# box [( %.3f , %.1f ) ");
      printf(" ( %.3f , %.1f )] ");
      printf(" delta_f %.3f  computed_freq %d\n");
      param_7 = -0xfa0000;
      if (-0xfa0001 < iVar18) {
        param_7 = iVar18;
      }
      if (0xfa0000 < param_7) {
        param_7 = 0xfa0000;
      }
      goto LAB_00403f28;
    }
  }
  puts("# inconsistent");
LAB_00403f28:
  DAT_004156b4 = DAT_004156b4 + 1 & 0x8000000f;
  if ((int)DAT_004156b4 < 0) {
    DAT_004156b4 = (DAT_004156b4 - 1 | 0xfffffff0) + 1;
  }
  return param_7;
}

[ASK_GPT] 72dd9987fa2e4dcf
