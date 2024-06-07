
int sysfs_is_supported(libmtd *lib)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  code *pcVar15;
  int aiStack_138 [2];
  undefined *local_130;
  int local_128;
  char tmp_buf [256];
  
  local_130 = &_gp;
  sVar2 = strlen(lib->mtd_name);
[32m  iVar1 = -(sVar2 + 0x18 & 0xfffffff8);[0m
  iVar3 = (**(code **)(local_130 + -0x7f68))(lib->sysfs_mtd);
  pcVar10 = (char *)((int)&local_130 + iVar1);
  if (iVar3 == 0) {
    piVar6 = (int *)(**(code **)(local_130 + -0x7f78))();
    iVar3 = *piVar6;
    if (iVar3 == 2) {
      *piVar6 = 0;
      return 0;
    }
    puVar7 = *(undefined4 **)(local_130 + -0x7f74);
    (**(code **)(local_130 + -0x7f38))
              (*puVar7,"%s: error!: cannot open \"%s\"\n","libmtd",lib->sysfs_mtd);
    uVar12 = *puVar7;
    uVar8 = (**(code **)(local_130 + -0x7f0c))(iVar3);
    pcVar15 = *(code **)(local_130 + -0x7f38);
    *(int *)((int)aiStack_138 + iVar1) = iVar3;
    *(undefined4 *)((int)aiStack_138 + iVar1 + 4) = uVar8;
    (*pcVar15)(uVar12,"%*serror %d (%s)\n",8,"");
    return -1;
  }
  do {
    iVar4 = (**(code **)(local_130 + -0x7f4c))(iVar3);
    iVar11 = iVar4 + 0x13;
    if (iVar4 == 0) {
      local_128 = -1;
      break;
    }
    uVar5 = (**(code **)(local_130 + -0x7f80))(iVar11);
    if (0xfe < uVar5) {
      pcVar10 = lib->sysfs_mtd;
      pcVar15 = *(code **)(local_130 + -0x7f38);
      uVar8 = **(undefined4 **)(local_130 + -0x7f74);
      *(int *)((int)aiStack_138 + iVar1) = iVar11;
      (*pcVar15)(uVar8,"%s: error!: invalid entry in %s: \"%s\"\n","libmtd",pcVar10);
      puVar7 = (undefined4 *)(**(code **)(local_130 + -0x7f78))();
      *puVar7 = 0x16;
      (**(code **)(local_130 + -0x7f88))(iVar3);
      return -1;
    }
    iVar4 = (**(code **)(local_130 + -0x7f54))(iVar11,"mtd%d%s",&local_128,tmp_buf);
  } while (iVar4 != 1);
  iVar3 = (**(code **)(local_130 + -0x7f88))(iVar3);
  if (iVar3 == 0) {
    if (local_128 == -1) {
      return 0;
    }
    (**(code **)(local_130 + -0x7f70))(pcVar10,lib->mtd_name,local_128);
    iVar3 = (**(code **)(local_130 + -0x7f64))(pcVar10,0x80000);
    if (iVar3 == -1) {
      return 0;
    }
    iVar3 = (**(code **)(local_130 + -0x7f94))(iVar3);
    if (iVar3 == 0) {
      return 1;
    }
    puVar13 = *(undefined4 **)(local_130 + -0x7f74);
    puVar7 = (undefined4 *)(**(code **)(local_130 + -0x7f78))();
    uVar8 = *puVar13;
    uVar12 = *puVar7;
    pcVar15 = *(code **)(local_130 + -0x7f38);
    pcVar9 = "%s: error!: close failed on \"%s\"\n";
  }
  else {
    puVar13 = *(undefined4 **)(local_130 + -0x7f74);
    puVar7 = (undefined4 *)(**(code **)(local_130 + -0x7f78))();
    pcVar10 = lib->sysfs_mtd;
    uVar8 = *puVar13;
    pcVar15 = *(code **)(local_130 + -0x7f38);
    uVar12 = *puVar7;
    pcVar9 = "%s: error!: closedir failed on \"%s\"\n";
  }
  (*pcVar15)(uVar8,pcVar9,"libmtd",pcVar10);
  uVar14 = *puVar13;
  uVar8 = (**(code **)(local_130 + -0x7f0c))(uVar12);
  pcVar15 = *(code **)(local_130 + -0x7f38);
  *(undefined4 *)((int)aiStack_138 + iVar1) = uVar12;
  *(undefined4 *)((int)aiStack_138 + iVar1 + 4) = uVar8;
  (*pcVar15)(uVar14,"%*serror %d (%s)\n",8,"");
  return -1;
}

[ASK_GPT] 9d3ce0da7627ad26
