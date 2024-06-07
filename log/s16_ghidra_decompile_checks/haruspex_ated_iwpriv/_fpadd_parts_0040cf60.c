
fp_number_type * _fpadd_parts(fp_number_type *a,fp_number_type *b,fp_number_type *tmp)

{
  bool bVar1;
  fp_class_type fVar2;
  uint uVar3;
  halffractype hVar4;
  fp_class_type fVar5;
  int iVar6;
  uint uVar7;
  uint b_00;
  uint uVar8;
  uint b_01;
  uint uVar9;
  fp_number_type *pfVar10;
  int iVar11;
  int iVar12;
  DItype DVar13;
  DItype DVar14;
  undefined *puVar15;
  undefined4 in_stack_ffffffcc;
  
  fVar2 = a->class;
  puVar15 = &_gp;
  pfVar10 = a;
  if ((CLASS_QNAN < fVar2) && (fVar5 = b->class, pfVar10 = b, CLASS_QNAN < fVar5)) {
    if (fVar2 == CLASS_INFINITY) {
      pfVar10 = a;
      if ((fVar5 == CLASS_INFINITY) && (a->sign != b->sign)) {
        pfVar10 = &__thenan_df;
      }
    }
    else {
      pfVar10 = b;
      if (fVar5 != CLASS_INFINITY) {
        if (fVar5 == CLASS_ZERO) {
          pfVar10 = a;
          if (fVar2 == CLASS_ZERO) {
[32m[32m            memcpy(tmp,a,0x18);[0m[0m
            tmp->sign = b->sign & a->sign;
            pfVar10 = tmp;
          }
        }
        else {
          pfVar10 = b;
          if (fVar2 != CLASS_ZERO) {
            iVar11 = a->normal_exp;
            iVar6 = b->normal_exp;
            b_00 = (a->fraction).l[0];
            uVar8 = (a->fraction).l[1];
            uVar3 = iVar11 - iVar6;
            iVar12 = ((int)uVar3 >> 0x1f ^ uVar3) - ((int)uVar3 >> 0x1f);
            b_01 = (b->fraction).l[0];
            uVar9 = (b->fraction).l[1];
            if (iVar12 < 0x40) {
              if ((int)uVar3 < 1) {
                iVar6 = iVar11;
                if (uVar3 != 0) {
                  DVar13 = __lshrdi3(CONCAT44(in_stack_ffffffcc,0x418190),b_00);
                  DVar14 = __ashldi3(CONCAT44(in_stack_ffffffcc,puVar15),1);
                  b_00 = (uint)(((int)DVar14 - 1U & b_00 |
                                (int)((ulonglong)DVar14 >> 0x20) - (uint)((int)DVar14 == 0) & uVar8)
                               != 0) | (uint)DVar13;
                  uVar8 = (uint)((ulonglong)DVar13 >> 0x20);
                  iVar6 = iVar11 + iVar12;
                }
              }
              else {
                DVar13 = __lshrdi3(CONCAT44(in_stack_ffffffcc,0x418190),b_01);
                DVar14 = __ashldi3(CONCAT44(in_stack_ffffffcc,puVar15),1);
                b_01 = (uint)(((int)DVar14 - 1U & b_01 |
                              (int)((ulonglong)DVar14 >> 0x20) - (uint)((int)DVar14 == 0) & uVar9)
                             != 0) | (uint)DVar13;
                uVar9 = (uint)((ulonglong)DVar13 >> 0x20);
                iVar6 = iVar11;
              }
            }
            else if (iVar6 < iVar11) {
              b_01 = 0;
              uVar9 = 0;
              iVar6 = iVar11;
            }
            else {
              b_00 = 0;
              uVar8 = 0;
            }
            uVar3 = a->sign;
            if (uVar3 == b->sign) {
              tmp->sign = uVar3;
              tmp->normal_exp = iVar6;
              (tmp->fraction).l[0] = b_01 + b_00;
              (tmp->fraction).l[1] = (uint)(b_01 + b_00 < b_01) + uVar9 + uVar8;
            }
            else {
              uVar7 = b_01 - b_00;
              if (uVar3 == 0) {
                uVar7 = b_00 - b_01;
                bVar1 = b_00 < uVar7;
                iVar11 = uVar8 - uVar9;
              }
              else {
                bVar1 = b_01 < uVar7;
                iVar11 = uVar9 - uVar8;
              }
              hVar4 = iVar11 - (uint)bVar1;
              if ((int)hVar4 < 0) {
                uVar7 = -uVar7;
                tmp->sign = 1;
                tmp->normal_exp = iVar6;
                hVar4 = -(uint)(uVar7 != 0) - hVar4;
              }
              else {
                tmp->sign = 0;
                tmp->normal_exp = iVar6;
              }
              (tmp->fraction).l[0] = uVar7;
              (tmp->fraction).l[1] = hVar4;
              while( true ) {
                uVar8 = (tmp->fraction).l[0];
                hVar4 = (tmp->fraction).l[1];
                uVar9 = (uint)(uVar8 - 1 < uVar8) + (hVar4 - 1);
                if ((0xfffffff < uVar9) || ((uVar9 == 0xfffffff && (uVar8 - 1 == 0xffffffff))))
                break;
                (tmp->fraction).l[0] = uVar8 << 1;
                iVar6 = tmp->normal_exp;
                (tmp->fraction).l[1] = hVar4 << 1 | uVar8 >> 0x1f;
                tmp->normal_exp = iVar6 + -1;
              }
            }
            uVar8 = (tmp->fraction).l[1];
            tmp->class = CLASS_NUMBER;
            pfVar10 = tmp;
            if (0x1fffffff < uVar8) {
              (tmp->fraction).l[0] =
                   (tmp->fraction).l[0] & 1 | uVar8 << 0x1f | (tmp->fraction).l[0] >> 1;
              iVar6 = tmp->normal_exp;
              (tmp->fraction).l[1] = uVar8 >> 1;
              tmp->normal_exp = iVar6 + 1;
            }
          }
        }
      }
    }
  }
  return pfVar10;
}

[ASK_GPT] 41848adb9f36f6b9
