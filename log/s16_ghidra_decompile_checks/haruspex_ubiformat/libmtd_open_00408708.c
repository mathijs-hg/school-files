
libmtd_t libmtd_open(void)

{
  FILE *__stream;
  libmtd *lib;
  char *pcVar1;
  int iVar2;
  int *piVar3;
  
[32m[32m  lib = (libmtd *)calloc(1,0x34);[0m[0m
  if (lib == (libmtd *)0x0) {
    piVar3 = __errno_location();
    iVar2 = *piVar3;
    fprintf(stderr,"%s: error!: out of memory\n","libmtd");
    __stream = stderr;
    pcVar1 = strerror(iVar2);
    fprintf(__stream,"%*serror %d (%s)\n",8,&DAT_0040e38c,iVar2,pcVar1);
                    /* WARNING: Subroutine does not return */
    exit(-1);
  }
  *(uint *)&lib->field_0x30 = *(uint *)&lib->field_0x30 & 0xfffffff9;
  pcVar1 = mkpath("/sys","class/mtd");
  lib->sysfs_mtd = pcVar1;
  if (pcVar1 != (char *)0x0) {
    pcVar1 = mkpath(pcVar1,"mtd%d");
    lib->mtd = pcVar1;
    if (pcVar1 != (char *)0x0) {
      pcVar1 = mkpath(pcVar1,"name");
      lib->mtd_name = pcVar1;
      if (pcVar1 != (char *)0x0) {
        iVar2 = sysfs_is_supported(lib);
        if (iVar2 == 0) {
          free(lib->mtd);
          free(lib->sysfs_mtd);
          free(lib->mtd_name);
          lib->sysfs_mtd = (char *)0x0;
          lib->mtd = (char *)0x0;
          lib->mtd_name = (char *)0x0;
          return lib;
        }
        pcVar1 = mkpath(lib->mtd,"dev");
        lib->mtd_dev = pcVar1;
        if (pcVar1 != (char *)0x0) {
          pcVar1 = mkpath(lib->mtd,"type");
          lib->mtd_type = pcVar1;
          if (pcVar1 != (char *)0x0) {
            pcVar1 = mkpath(lib->mtd,"erasesize");
            lib->mtd_eb_size = pcVar1;
            if (pcVar1 != (char *)0x0) {
              pcVar1 = mkpath(lib->mtd,"size");
              lib->mtd_size = pcVar1;
              if (pcVar1 != (char *)0x0) {
                pcVar1 = mkpath(lib->mtd,"writesize");
                lib->mtd_min_io_size = pcVar1;
                if (pcVar1 != (char *)0x0) {
                  pcVar1 = mkpath(lib->mtd,"subpagesize");
                  lib->mtd_subpage_size = pcVar1;
                  if (pcVar1 != (char *)0x0) {
                    pcVar1 = mkpath(lib->mtd,"oobsize");
                    lib->mtd_oob_size = pcVar1;
                    if (pcVar1 != (char *)0x0) {
                      pcVar1 = mkpath(lib->mtd,"numeraseregions");
                      lib->mtd_region_cnt = pcVar1;
                      if (pcVar1 != (char *)0x0) {
                        pcVar1 = mkpath(lib->mtd,"flags");
                        lib->mtd_flags = pcVar1;
                        if (pcVar1 != (char *)0x0) {
                          *(uint *)&lib->field_0x30 = *(uint *)&lib->field_0x30 | 1;
                          return lib;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  libmtd_close(lib);
  return (libmtd_t)0x0;
}

[ASK_GPT] b0d835f87fd7e9c9
