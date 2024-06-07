
int mtd_get_info(libmtd_t desc,mtd_info *info)

{
  FILE *pFVar1;
  DIR *__dirp;
  int *piVar2;
  dirent64 *pdVar3;
  size_t sVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  int local_128;
  char tmp_buf [256];
  
  *(uint *)&info->field_0xc = *(uint *)&info->field_0xc | 1;
                    /* WARNING: Load size is inaccurate */
  __dirp = opendir(*desc);
  if (__dirp == (DIR *)0x0) {
    piVar2 = __errno_location();
    iVar5 = *piVar2;
    if (iVar5 == 2) {
      *piVar2 = 0x13;
      return -1;
    }
                    /* WARNING: Load size is inaccurate */
    uVar7 = *desc;
    pcVar6 = "%s: error!: cannot open \"%s\"\n";
  }
  else {
    info->lowest_mtd_num = 0x7fffffff;
    piVar2 = __errno_location();
    while( true ) {
      *piVar2 = 0;
      pdVar3 = readdir64(__dirp);
      pcVar6 = pdVar3->d_name;
      if (pdVar3 == (dirent64 *)0x0) break;
      sVar4 = strlen(pcVar6);
      if (0xfe < sVar4) {
                    /* WARNING: Load size is inaccurate */
        fprintf(stderr,"%s: error!: invalid entry in %s: \"%s\"\n","libmtd",*desc,pcVar6);
        *piVar2 = 0x16;
        goto out_close;
      }
[32m[32m      iVar5 = sscanf(pcVar6,"mtd%d%s",&local_128,tmp_buf);[0m[0m
      if (iVar5 == 1) {
        info->mtd_dev_cnt = info->mtd_dev_cnt + 1;
        if (info->highest_mtd_num < local_128) {
          info->highest_mtd_num = local_128;
        }
        if (local_128 < info->lowest_mtd_num) {
          info->lowest_mtd_num = local_128;
        }
      }
    }
    iVar5 = *piVar2;
    if (iVar5 != 0) {
                    /* WARNING: Load size is inaccurate */
      fprintf(stderr,"%s: error!: readdir failed on \"%s\"\n","libmtd",*desc);
      pFVar1 = stderr;
      pcVar6 = strerror(iVar5);
      fprintf(pFVar1,"%*serror %d (%s)\n",8,&DAT_0040e38c,iVar5,pcVar6);
out_close:
      closedir(__dirp);
      return -1;
    }
    iVar5 = closedir(__dirp);
    if (iVar5 == 0) {
      if (info->lowest_mtd_num != 0x7fffffff) {
        return 0;
      }
      info->lowest_mtd_num = 0;
      return 0;
    }
                    /* WARNING: Load size is inaccurate */
    uVar7 = *desc;
    iVar5 = *piVar2;
    pcVar6 = "%s: error!: closedir failed on \"%s\"\n";
  }
  fprintf(stderr,pcVar6,"libmtd",uVar7);
  pFVar1 = stderr;
  pcVar6 = strerror(iVar5);
  fprintf(pFVar1,"%*serror %d (%s)\n",8,&DAT_0040e38c,iVar5,pcVar6);
  return -1;
}

[ASK_GPT] 8f071e881737afe4
