
libubi_t libubi_open(void)

{
  FILE *__stream;
  void *desc;
  char *pcVar1;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  int version;
  
[32m[32m  desc = calloc(1,0x68);[0m[0m
  pvVar4 = desc;
  if (desc != (void *)0x0) {
    pcVar1 = mkpath("/sys","class/misc/ubi_ctrl/");
    *(char **)((int)desc + 4) = pcVar1;
    if (pcVar1 != (char *)0x0) {
      pcVar1 = mkpath(pcVar1,"dev");
      *(char **)((int)desc + 8) = pcVar1;
      if (pcVar1 != (char *)0x0) {
        pcVar1 = mkpath("/sys","class/ubi");
        *(char **)((int)desc + 0xc) = pcVar1;
        if (pcVar1 != (char *)0x0) {
[32m          iVar2 = open64(pcVar1,0);[0m
          if (iVar2 == -1) {
            piVar3 = __errno_location();
            *piVar3 = 0;
          }
          else {
            iVar2 = close(iVar2);
            if (iVar2 == 0) {
              pcVar1 = mkpath(*(char **)((int)desc + 0xc),"ubi%d");
              *(char **)((int)desc + 0x10) = pcVar1;
              if (pcVar1 != (char *)0x0) {
                pcVar1 = mkpath(*(char **)((int)desc + 0xc),"version");
                *(char **)((int)desc + 0x14) = pcVar1;
                if (pcVar1 != (char *)0x0) {
                  pcVar1 = mkpath(*(char **)((int)desc + 0x10),"dev");
                  *(char **)((int)desc + 0x18) = pcVar1;
                  if (pcVar1 != (char *)0x0) {
                    pcVar1 = mkpath(*(char **)((int)desc + 0x10),"avail_eraseblocks");
                    *(char **)((int)desc + 0x1c) = pcVar1;
                    if (pcVar1 != (char *)0x0) {
                      pcVar1 = mkpath(*(char **)((int)desc + 0x10),"total_eraseblocks");
                      *(char **)((int)desc + 0x20) = pcVar1;
                      if (pcVar1 != (char *)0x0) {
                        pcVar1 = mkpath(*(char **)((int)desc + 0x10),"bad_peb_count");
                        *(char **)((int)desc + 0x24) = pcVar1;
                        if (pcVar1 != (char *)0x0) {
                          pcVar1 = mkpath(*(char **)((int)desc + 0x10),"eraseblock_size");
                          *(char **)((int)desc + 0x28) = pcVar1;
                          if (pcVar1 != (char *)0x0) {
                            pcVar1 = mkpath(*(char **)((int)desc + 0x10),"max_ec");
                            *(char **)((int)desc + 0x2c) = pcVar1;
                            if (pcVar1 != (char *)0x0) {
                              pcVar1 = mkpath(*(char **)((int)desc + 0x10),"reserved_for_bad");
                              *(char **)((int)desc + 0x30) = pcVar1;
                              if (pcVar1 != (char *)0x0) {
                                pcVar1 = mkpath(*(char **)((int)desc + 0x10),"max_vol_count");
                                *(char **)((int)desc + 0x34) = pcVar1;
                                if (pcVar1 != (char *)0x0) {
                                  pcVar1 = mkpath(*(char **)((int)desc + 0x10),"min_io_size");
                                  *(char **)((int)desc + 0x38) = pcVar1;
                                  if (pcVar1 != (char *)0x0) {
                                    pcVar1 = mkpath(*(char **)((int)desc + 0x10),"mtd_num");
                                    *(char **)((int)desc + 0x3c) = pcVar1;
                                    if (pcVar1 != (char *)0x0) {
                                      pcVar1 = mkpath(*(char **)((int)desc + 0xc),"ubi%d_%d");
                                      *(char **)((int)desc + 0x40) = pcVar1;
                                      if (pcVar1 != (char *)0x0) {
                                        pcVar1 = mkpath(pcVar1,"type");
                                        *(char **)((int)desc + 0x44) = pcVar1;
                                        if (pcVar1 != (char *)0x0) {
                                          pcVar1 = mkpath(*(char **)((int)desc + 0x40),"dev");
                                          *(char **)((int)desc + 0x48) = pcVar1;
                                          if (pcVar1 != (char *)0x0) {
                                            pcVar1 = mkpath(*(char **)((int)desc + 0x40),"alignment"
                                                           );
                                            *(char **)((int)desc + 0x4c) = pcVar1;
                                            if (pcVar1 != (char *)0x0) {
                                              pcVar1 = mkpath(*(char **)((int)desc + 0x40),
                                                              "data_bytes");
                                              *(char **)((int)desc + 0x50) = pcVar1;
                                              if (pcVar1 != (char *)0x0) {
                                                pcVar1 = mkpath(*(char **)((int)desc + 0x40),
                                                                "reserved_ebs");
                                                *(char **)((int)desc + 0x54) = pcVar1;
                                                if (pcVar1 != (char *)0x0) {
                                                  pcVar1 = mkpath(*(char **)((int)desc + 0x40),
                                                                  "usable_eb_size");
                                                  *(char **)((int)desc + 0x58) = pcVar1;
                                                  if (pcVar1 != (char *)0x0) {
                                                    pcVar1 = mkpath(*(char **)((int)desc + 0x40),
                                                                    "corrupted");
                                                    *(char **)((int)desc + 0x5c) = pcVar1;
                                                    if (pcVar1 != (char *)0x0) {
                                                      pcVar1 = mkpath(*(char **)((int)desc + 0x40),
                                                                      "name");
                                                      *(char **)((int)desc + 0x60) = pcVar1;
                                                      if ((pcVar1 != (char *)0x0) &&
                                                         (iVar2 = read_positive_int(*(char **)((int)
                                                  desc + 0x14),&version), iVar2 == 0)) {
                                                    if (version == 1) {
                                                      return desc;
                                                    }
                                                    fprintf(stderr,
                                                  "%s: error!: this library was made for UBI version %d, but UBI version %d is detected\n\n"
                                                  ,"libubi",1,version);
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
            else {
              piVar3 = __errno_location();
              iVar2 = *piVar3;
              fprintf(stderr,"%s: error!: close failed on \"%s\"\n","libubi",
                      *(undefined4 *)((int)desc + 0xc));
              __stream = stderr;
              pcVar1 = strerror(iVar2);
              fprintf(__stream,"%*serror %d (%s)\n",8,&DAT_0040e38c,iVar2,pcVar1);
            }
          }
        }
      }
    }
    pvVar4 = (void *)0x0;
    libubi_close(desc);
  }
  return pvVar4;
}

[ASK_GPT] 767f98a1bebd2ac0
