
int mtd_get_dev_info1(libmtd_t desc,int mtd_num,mtd_dev_info *mtd)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  char *buf;
  uint uVar6;
  DItype DVar7;
  undefined *puVar8;
  undefined4 in_stack_ffffffdc;
  undefined4 in_stack_ffffffe4;
  
  puVar8 = &_gp;
[32m  memset(mtd,0,0x100);[0m
  mtd->mtd_num = mtd_num;
  iVar1 = mtd_dev_present(desc,mtd_num);
  if (iVar1 == 0) {
    iVar1 = -1;
    puVar5 = (undefined4 *)(**(code **)(puVar8 + -0x7ef0))();
    *puVar5 = 0x13;
  }
  else {
    if ((*(uint *)((int)desc + 0x30) & 1) == 0) {
      iVar1 = legacy_get_dev_info1(mtd_num,mtd);
      return iVar1;
    }
    iVar2 = dev_get_major((libmtd *)desc,mtd_num,&mtd->major,&mtd->minor);
    iVar1 = -1;
    if (iVar2 == 0) {
      iVar2 = dev_read_data(*(char **)((int)desc + 0xc),mtd_num,mtd->name,0x80);
      if (-1 < iVar2) {
        mtd->type_str[iVar2 + 0x40] = '\0';
        buf = mtd->type_str;
        uVar3 = dev_read_data(*(char **)((int)desc + 0x10),mtd_num,buf,0x41);
        if (-1 < (int)uVar3) {
          mtd->type_str[uVar3 - 1] = '\0';
          iVar2 = dev_read_pos_int(*(char **)((int)desc + 0x14),mtd_num,&mtd->eb_size);
          if ((((iVar2 == 0) &&
               (iVar2 = dev_read_pos_ll(*(char **)((int)desc + 0x18),mtd_num,&mtd->size), iVar2 == 0
               )) && (iVar2 = dev_read_pos_int(*(char **)((int)desc + 0x1c),mtd_num,
                                               &mtd->min_io_size), iVar2 == 0)) &&
             (((iVar2 = dev_read_pos_int(*(char **)((int)desc + 0x20),mtd_num,&mtd->subpage_size),
               iVar2 == 0 &&
               (iVar2 = dev_read_pos_int(*(char **)((int)desc + 0x24),mtd_num,&mtd->oob_size),
               iVar2 == 0)) &&
              ((iVar2 = dev_read_pos_int(*(char **)((int)desc + 0x28),mtd_num,&mtd->region_cnt),
               iVar2 == 0 &&
               (iVar2 = dev_read_hex_int(*(char **)((int)desc + 0x2c),mtd_num,
                                         (int *)&stack0xffffffe0), iVar2 == 0)))))) {
            uVar6 = *(uint *)&mtd->field_0xf8;
            uVar4 = uVar3 >> 10 & 1;
            *(uint *)&mtd->field_0xf8 = uVar6 & 0xfffffffe | uVar4;
            DVar7 = __divdi3(CONCAT44(in_stack_ffffffdc,puVar8),CONCAT44(in_stack_ffffffe4,uVar3));
            mtd->eb_cnt = (int)DVar7;
            iVar1 = (**(code **)(puVar8 + -0x7edc))(buf,"nand");
            if (iVar1 == 0) {
              mtd->type = 4;
              iVar1 = 1;
            }
            else {
              iVar1 = (**(code **)(puVar8 + -0x7edc))(buf,"mlc-nand");
              if (iVar1 == 0) {
                mtd->type = 8;
                iVar1 = 1;
              }
              else {
                iVar1 = (**(code **)(puVar8 + -0x7edc))(buf,&DAT_00410170);
                uVar3 = 3;
                if (iVar1 != 0) {
                  iVar1 = (**(code **)(puVar8 + -0x7edc))(buf,&DAT_00410174);
                  uVar3 = 2;
                  if (iVar1 != 0) {
                    iVar1 = (**(code **)(puVar8 + -0x7edc))(buf,"absent");
                    uVar3 = 0;
                    if (iVar1 != 0) {
                      iVar1 = (**(code **)(puVar8 + -0x7edc))(buf,"dataflash");
                      uVar3 = 6;
                      if (iVar1 != 0) {
                        iVar1 = (**(code **)(puVar8 + -0x7edc))(buf,&DAT_0041018c);
                        uVar3 = 1;
                        if (iVar1 != 0) {
                          iVar1 = (**(code **)(puVar8 + -0x7edc))(buf,&DAT_00410190);
                          uVar3 = -(uint)(iVar1 != 0) | 7;
                        }
                      }
                    }
                  }
                }
                mtd->type = uVar3;
                iVar1 = 0;
              }
            }
            *(uint *)&mtd->field_0xf8 = uVar6 & 0xfffffffc | uVar4 | iVar1 << 1;
            iVar1 = 0;
          }
        }
      }
    }
  }
  return iVar1;
}

[ASK_GPT] ac33a0312db512d1
