
int ubi_get_info(libubi_t desc,ubi_info *info)

{
  FILE *pFVar1;
  int iVar2;
  DIR *__dirp;
  int *piVar3;
  dirent64 *pdVar4;
  size_t sVar5;
  char *pcVar6;
  int dev_num;
  char tmp_buf [256];
  
[32m  memset(info,0,0x18);[0m
  iVar2 = read_major(*(char **)((int)desc + 8),&info->ctrl_major,&info->ctrl_minor);
  if (iVar2 != 0) {
    info->ctrl_minor = -1;
    info->ctrl_major = -1;
  }
  __dirp = opendir(*(char **)((int)desc + 0xc));
  iVar2 = -1;
  if (__dirp != (DIR *)0x0) {
    info->lowest_dev_num = 0x7fffffff;
    piVar3 = __errno_location();
    while( true ) {
      *piVar3 = 0;
      pdVar4 = readdir64(__dirp);
      pcVar6 = pdVar4->d_name;
      if (pdVar4 == (dirent64 *)0x0) break;
      sVar5 = strlen(pcVar6);
      if (0xfe < sVar5) {
        fprintf(stderr,"%s: error!: invalid entry in %s: \"%s\"\n","libubi",
                *(undefined4 *)((int)desc + 0xc),pcVar6);
        *piVar3 = 0x16;
        goto out_close;
      }
[32m[32m      iVar2 = sscanf(pcVar6,"ubi%d%s",&dev_num,tmp_buf);[0m[0m
      if (iVar2 == 1) {
        info->dev_count = info->dev_count + 1;
        if (info->highest_dev_num < dev_num) {
          info->highest_dev_num = dev_num;
        }
        if (dev_num < info->lowest_dev_num) {
          info->lowest_dev_num = dev_num;
        }
      }
    }
    iVar2 = *piVar3;
    if (iVar2 == 0) {
      iVar2 = closedir(__dirp);
      if (iVar2 == 0) {
        if (info->lowest_dev_num == 0x7fffffff) {
          info->lowest_dev_num = 0;
        }
        iVar2 = read_positive_int(*(char **)((int)desc + 0x14),&info->version);
        iVar2 = (iVar2 == 0) - 1;
      }
      else {
        iVar2 = *piVar3;
        fprintf(stderr,"%s: error!: closedir failed on \"%s\"\n","libubi",
                *(undefined4 *)((int)desc + 0xc));
        pFVar1 = stderr;
        pcVar6 = strerror(iVar2);
        fprintf(pFVar1,"%*serror %d (%s)\n",8,&DAT_0040e38c,iVar2,pcVar6);
        iVar2 = -1;
      }
    }
    else {
      fprintf(stderr,"%s: error!: readdir failed on \"%s\"\n","libubi",
              *(undefined4 *)((int)desc + 0xc));
      pFVar1 = stderr;
      pcVar6 = strerror(iVar2);
      fprintf(pFVar1,"%*serror %d (%s)\n",8,&DAT_0040e38c,iVar2,pcVar6);
out_close:
      closedir(__dirp);
      iVar2 = -1;
    }
  }
  return iVar2;
}

[ASK_GPT] 6b796bcdbcae8af1
