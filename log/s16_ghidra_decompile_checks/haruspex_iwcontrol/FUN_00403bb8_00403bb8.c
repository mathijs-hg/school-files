
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Could not reconcile some variable overlaps */

undefined4 FUN_00403bb8(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  size_t sVar7;
  FILE *pFVar8;
  undefined4 uVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  char **ppcVar13;
  longlong lVar14;
  undefined8 local_a8;
  char *apcStack_a0 [4];
  char **local_90;
  undefined2 local_8c;
  ushort local_8a;
  char *local_80 [16];
  char **local_40;
  char *local_3c;
  undefined8 *local_38;
  undefined *local_34;
  undefined8 local_30;
  
[32m  iVar2 = sockets_open();[0m
  if (iVar2 < 0) {
    perror("socket");
    iVar2 = -1;
  }
  else {
    if (param_1 == 1) {
      FUN_00403adc(iVar2);
    }
    else {
      pcVar10 = *(char **)(param_2 + 4);
      iVar3 = strncmp(pcVar10,"-h",9);
      if ((iVar3 == 0) || (iVar3 = strcmp(pcVar10,"--help"), iVar3 == 0)) {
        FUN_00402830();
      }
      else {
        if (param_1 != 2) {
          param_1 = param_1 + -2;
[32m[32m[32m          strncpy((char *)apcStack_a0,pcVar10,0x10);[0m[0m[0m
          param_2 = param_2 + 8;
          if (param_1 < 1) {
            FUN_00402830();
          }
          iVar3 = 0;
LAB_00405684:
          do {
            while( true ) {
              if (param_1 <= iVar3) {
                uVar9 = 0;
                goto LAB_00405694;
              }
              pcVar11 = *(char **)(param_2 + iVar3 * 4);
              iVar4 = strcasecmp(pcVar11,"nwid");
              if (iVar4 != 0) break;
LAB_00403d58:
              if (param_1 <= iVar3 + 1) {
                FUN_00402830();
              }
              pcVar11 = *(char **)(param_2 + (iVar3 + 1) * 4);
              iVar4 = strcasecmp(pcVar11,"off");
              if (iVar4 == 0) {
LAB_00403dc0:
                local_8c = 1;
              }
              else {
                iVar4 = strcasecmp(pcVar11,"any");
                if (iVar4 == 0) goto LAB_00403dc0;
                iVar4 = strcasecmp(pcVar11,"on");
                if (iVar4 == 0) {
                  iVar4 = ioctl(iVar2,0x8b03,apcStack_a0);
                  pFVar8 = stderr;
                  if (iVar4 < 0) {
                    piVar5 = __errno_location();
                    pcVar10 = strerror(*piVar5);
                    pcVar11 = "SIOCGIWNWID: %s\n";
                    goto LAB_00403f08;
                  }
[32m[32m[32m                  strncpy((char *)apcStack_a0,pcVar10,0x10);[0m[0m[0m
                  local_8c = 0;
                }
                else {
[32m                  iVar4 = sscanf(pcVar11,"%lX",&local_90);[0m
                  if (iVar4 == 1) {
                    local_8c = 0;
                  }
                  else {
                    FUN_00402830();
                  }
                }
              }
              local_8c = CONCAT11(1,(undefined)local_8c);
              iVar4 = ioctl(iVar2,0x8b02,apcStack_a0);
              pFVar8 = stderr;
              iVar3 = iVar3 + 2;
              if (iVar4 < 0) {
                piVar5 = __errno_location();
                pcVar10 = strerror(*piVar5);
                pcVar11 = "SIOCSIWNWID: %s\n";
                goto LAB_00403f08;
              }
            }
            iVar4 = strcasecmp(pcVar11,"domain");
            if (iVar4 == 0) goto LAB_00403d58;
            iVar4 = strncmp(pcVar11,"sens",4);
            if (iVar4 != 0) {
              iVar4 = strncmp(pcVar11,"enc",3);
              if (iVar4 == 0) {
LAB_00404034:
                iVar4 = iVar3 + 1;
                if (param_1 <= iVar4) {
                  FUN_00402830();
                }
                local_40 = (char **)(param_2 + iVar4 * 4);
                pcVar11 = *local_40;
                iVar6 = strcasecmp(pcVar11,"on");
                if (iVar6 == 0) {
                  local_90 = local_80;
                  local_8c = 0;
                  local_8a = 0;
                  iVar3 = ioctl(iVar2,0x8b2b,apcStack_a0);
                  pFVar8 = stderr;
                  if (iVar3 < 0) {
                    piVar5 = __errno_location();
                    pcVar10 = strerror(*piVar5);
                    pcVar11 = "SIOCGIWENCODE: %s\n";
                    goto LAB_00403f08;
                  }
[32m[32m[32m                  strncpy((char *)apcStack_a0,pcVar10,0x10);[0m[0m[0m
                  local_8a = local_8a & 0x7fff;
                }
                else {
                  local_90 = (char **)0x0;
                  local_8a = 0;
                  local_8c = 0;
                  iVar6 = strncmp(pcVar11,"s:",2);
                  if (iVar6 == 0) {
[32m                    sVar7 = strlen(pcVar11 + 2);[0m
                    local_8c = (ushort)(sVar7 & 0xffff);
                    if (0x40 < (sVar7 & 0xffff)) {
                      local_8c = 0x40;
                    }
                    local_30._4_4_ = local_80;
[32m[32m                    strncpy((char *)local_30._4_4_,*local_40 + 2,(uint)local_8c);[0m[0m
                    local_90 = local_30._4_4_;
LAB_00404304:
                    bVar1 = true;
                    iVar4 = iVar3 + 2;
                  }
                  else {
                    sVar7 = strlen(pcVar11);
[32m[32m                    local_3c = (char *)malloc(sVar7 + 1);[0m[0m
                    if (local_3c == (char *)0x0) {
                      fputs("Setting key : Malloc failed (string too long ?)\n",stderr);
                      goto LAB_00403f10;
                    }
                    local_38 = &local_a8;
                    pcVar11 = *local_40;
                    local_40 = (char **)0x0;
[32m[32m                    strcpy(local_3c,pcVar11);[0m[0m
                    local_34 = (undefined *)local_80;
[32m                    pcVar11 = strtok(local_3c,"-:;.,");[0m
                    for (; (pcVar11 != (char *)0x0 && (local_40 != (char **)0x40));
                        local_40 = (char **)((int)local_40 + 1)) {
[32m                      iVar6 = sscanf(pcVar11,"%2X",local_38);[0m
                      if (iVar6 != 1) {
                        bVar1 = false;
                        goto LAB_004042d0;
                      }
                      pcVar12 = pcVar11 + 2;
                      local_34[(int)local_40] = (char)((ulonglong)local_a8 >> 0x20);
                      sVar7 = strlen(pcVar11);
                      if (sVar7 < 3) {
[32m                        pcVar12 = strtok((char *)0x0,"-:;.,");[0m
                      }
                      pcVar11 = pcVar12;
                    }
                    bVar1 = true;
LAB_004042d0:
                    free(local_3c);
                    if (bVar1) {
                      local_90 = local_80;
                      local_8c = (ushort)local_40;
                      goto LAB_00404304;
                    }
                  }
                  if (iVar4 < param_1) {
[32m                    iVar3 = sscanf(*(char **)(param_2 + iVar4 * 4),"[%d]",&local_a8);[0m
                    iVar6 = iVar4 << 2;
                    if (iVar3 == 1) {
                      if (local_a8 < 0x100000000) {
LAB_0040436c:
                        iVar6 = iVar4 << 2;
                        goto LAB_00404370;
                      }
                      iVar6 = iVar4 << 2;
                      if (0xfeffffffff < local_a8) goto LAB_00404370;
                      iVar4 = iVar4 + 1;
                      local_8a = (ushort)((ulonglong)local_a8 >> 0x20) | local_8a;
                      if (iVar4 < param_1) {
                        bVar1 = true;
                        goto LAB_0040436c;
                      }
                    }
                    else {
LAB_00404370:
                      local_30._4_4_ = (char **)(param_2 + iVar6);
                      iVar3 = strcasecmp(*local_30._4_4_,"off");
                      if (iVar3 == 0) {
                        local_8a = local_8a | 0x8000;
                      }
                      iVar3 = strcasecmp(*local_30._4_4_,"open");
                      if (iVar3 == 0) {
                        local_8a = local_8a | 0x2000;
                      }
                      iVar3 = strncasecmp(*local_30._4_4_,"restricted",5);
                      if (iVar3 == 0) {
                        local_8a = local_8a | 0x4000;
                      }
                      if ((local_8a & 0xff00) == 0) goto LAB_00404420;
                      iVar4 = iVar4 + 1;
                    }
                  }
                  else {
LAB_00404420:
                    if (!bVar1) {
                      FUN_00402830();
                    }
                  }
                  iVar4 = iVar4 + -1;
                }
                iVar6 = ioctl(iVar2,0x8b2a,apcStack_a0);
                pFVar8 = stderr;
                iVar3 = iVar4 + 1;
                if (-1 < iVar6) goto LAB_00405684;
                piVar5 = __errno_location();
                local_30._0_4_ = (char *)*piVar5;
                pcVar10 = strerror((int)local_30._0_4_);
                pcVar11 = "SIOCSIWENCODE(%d): %s\n";
              }
              else {
                iVar4 = strcmp(pcVar11,"key");
                if (iVar4 == 0) goto LAB_00404034;
                iVar4 = strcasecmp(pcVar11,"essid");
                if (iVar4 == 0) {
                  iVar4 = iVar3 + 1;
                  if (param_1 <= iVar4) {
                    FUN_00402830();
                  }
                  pcVar11 = *(char **)(param_2 + iVar4 * 4);
                  iVar6 = strcasecmp(pcVar11,"off");
                  if (iVar6 == 0) {
LAB_0040451c:
                    local_8a = 0;
                    local_80[0]._0_1_ = '\0';
                  }
                  else {
                    iVar6 = strcasecmp(pcVar11,"any");
                    if (iVar6 == 0) goto LAB_0040451c;
                    iVar6 = strcasecmp(pcVar11,"on");
                    if (iVar6 == 0) {
                      local_8c = 0;
                      local_8a = 0;
                      local_90 = local_80;
                      iVar3 = ioctl(iVar2,0x8b1b,apcStack_a0);
                      pFVar8 = stderr;
                      if (iVar3 < 0) {
                        piVar5 = __errno_location();
                        pcVar10 = strerror(*piVar5);
                        pcVar11 = "SIOCGIWESSID: %s\n";
                        goto LAB_00403f08;
                      }
[32m[32m[32m                      strncpy((char *)apcStack_a0,pcVar10,0x10);[0m[0m[0m
                      local_a8._0_4_ = (char **)0x1;
                      iVar3 = iVar4;
LAB_00404690:
                      iVar4 = iVar3;
                      local_8a = (ushort)local_a8._0_4_;
                    }
                    else {
                      sVar7 = strlen(pcVar11);
                      if (sVar7 < 0x21) {
                        local_8a = 1;
                        iVar3 = iVar3 + 2;
[32m[32m                        strcpy((char *)local_80,pcVar11);[0m[0m
                        if (iVar3 < param_1) {
[32m                          iVar6 = sscanf(*(char **)(param_2 + iVar3 * 4),"[%d]",&local_a8);[0m
                          if (((iVar6 == 1) && (0xffffffff < local_a8)) && (local_a8 < 0xff00000000)
                             ) goto LAB_00404690;
                        }
                      }
                      else {
                        fprintf(stderr,"ESSID too long (max %d): ``%s\'\'\n",0x20,pcVar11);
                        FUN_00402830();
                      }
                    }
                  }
                  local_90 = local_80;
                  sVar7 = strlen((char *)local_90);
                  local_8c = (short)sVar7 + 1;
                  iVar6 = ioctl(iVar2,0x8b1a,apcStack_a0);
                  pFVar8 = stderr;
                  iVar3 = iVar4 + 1;
                  if (iVar6 < 0) {
                    piVar5 = __errno_location();
                    pcVar10 = strerror(*piVar5);
                    pcVar11 = "SIOCSIWESSID: %s\n";
                    goto LAB_00403f08;
                  }
                  goto LAB_00405684;
                }
                iVar4 = strcasecmp(pcVar11,"ap");
                if (iVar4 == 0) {
                  if (param_1 <= iVar3 + 1) {
                    FUN_00402830();
                  }
                  iVar4 = check_addr_type(iVar2,pcVar10);
                  if (iVar4 < 0) {
                    pcVar11 = "%-8.8s  Interface doesn\'t support MAC & IP addresses\n";
                    pFVar8 = stderr;
                    goto LAB_00403f08;
                  }
                  iVar4 = in_addr(iVar2,pcVar10,*(undefined4 *)(param_2 + (iVar3 + 1) * 4),&local_90
                                 );
                  if (iVar4 < 0) {
                    FUN_00402830();
                  }
                  iVar4 = ioctl(iVar2,0x8b14,apcStack_a0);
                  pFVar8 = stderr;
                  if (iVar4 < 0) {
                    piVar5 = __errno_location();
                    pcVar10 = strerror(*piVar5);
                    pcVar11 = "SIOCSIWAP: %s\n";
                    goto LAB_00403f08;
                  }
                  iVar3 = iVar3 + 3;
                  goto LAB_00405684;
                }
                iVar4 = strncmp(pcVar11,"nick",4);
                if (iVar4 == 0) {
                  if (param_1 <= iVar3 + 1) {
                    FUN_00402830();
                  }
                  ppcVar13 = (char **)(param_2 + (iVar3 + 1) * 4);
                  local_30._0_4_ = *ppcVar13;
                  sVar7 = strlen(local_30._0_4_);
                  if (0x20 < sVar7) {
                    fprintf(stderr,"Name too long (max %d) : ``%s\'\'\n",0x20,local_30._0_4_);
                    FUN_00402830();
                  }
                  local_90 = (char **)*ppcVar13;
                  sVar7 = strlen((char *)local_90);
                  local_8c = (short)sVar7 + 1;
                  iVar4 = ioctl(iVar2,0x8b1c,apcStack_a0);
                  pFVar8 = stderr;
                  iVar3 = iVar3 + 2;
                  if (iVar4 < 0) {
                    piVar5 = __errno_location();
                    pcVar10 = strerror(*piVar5);
                    pcVar11 = "SIOCSIWNICKN: %s\n";
                    goto LAB_00403f08;
                  }
                  goto LAB_00405684;
                }
                iVar4 = strncmp(pcVar11,"bit",3);
                if (iVar4 == 0) {
LAB_0040497c:
                  local_30._0_4_ = (char *)((ulonglong)local_30 >> 0x20);
                  iVar4 = iVar3 + 1;
                  if (param_1 <= iVar4) {
                    FUN_00402830();
                  }
                  ppcVar13 = (char **)(param_2 + iVar4 * 4);
                  local_30._4_4_ = (char **)*ppcVar13;
                  iVar6 = strcasecmp((char *)local_30._4_4_,"auto");
                  if (iVar6 == 0) {
                    local_90 = (char **)0xffffffff;
                    local_8c = local_8c & 0xff;
                  }
                  else {
                    iVar6 = strcasecmp((char *)local_30._4_4_,"fixed");
                    if (iVar6 == 0) {
                      iVar3 = ioctl(iVar2,0x8b21,apcStack_a0);
                      pFVar8 = stderr;
                      if (iVar3 < 0) {
                        piVar5 = __errno_location();
                        pcVar10 = strerror(*piVar5);
                        pcVar11 = "SIOCGIWRATE: %s\n";
                        goto LAB_00403f08;
                      }
[32m[32m[32m                      strncpy((char *)apcStack_a0,pcVar10,0x10);[0m[0m[0m
                      iVar3 = iVar4;
LAB_00404c18:
                      iVar4 = iVar3;
                      local_8c = CONCAT11(1,(undefined)local_8c);
                    }
                    else {
[32m                      iVar6 = sscanf((char *)local_30._4_4_,"%lg",&local_a8);[0m
                      if (iVar6 != 1) {
                        FUN_00402830();
                      }
                      pcVar11 = index(*ppcVar13,0x47);
                      lVar14 = local_a8;
                      if (pcVar11 != (char *)0x0) {
                        lVar14 = __muldf3(local_a8._0_4_,local_a8._4_4_,0x41cdcd65,0);
                      }
                      local_a8 = lVar14;
                      pcVar11 = index(*ppcVar13,0x4d);
                      lVar14 = local_a8;
                      if (pcVar11 != (char *)0x0) {
                        lVar14 = __muldf3(local_a8._0_4_,local_a8._4_4_,0x412e8480,0);
                      }
                      local_a8 = lVar14;
                      pcVar11 = index(*ppcVar13,0x6b);
                      lVar14 = local_a8;
                      if (pcVar11 != (char *)0x0) {
                        lVar14 = __muldf3(local_a8._0_4_,local_a8._4_4_,0x408f4000,0);
                      }
                      local_a8._0_4_ = (char **)((ulonglong)lVar14 >> 0x20);
                      local_a8._4_4_ = (undefined4)lVar14;
                      iVar3 = iVar3 + 2;
                      local_a8 = lVar14;
                      local_90 = (char **)__fixdfsi(local_a8._0_4_,local_a8._4_4_);
                      local_8c = CONCAT11(1,(undefined)local_8c);
                      if (iVar3 < param_1) {
                        iVar6 = strcasecmp(*(char **)(param_2 + iVar3 * 4),"auto");
                        if (iVar6 == 0) {
                          local_8c = local_8c & 0xff;
                          iVar4 = iVar3;
                        }
                      }
                      iVar3 = iVar4 + 1;
                      if (iVar3 < param_1) {
                        iVar6 = strcasecmp(*(char **)(param_2 + iVar3 * 4),"fixed");
                        if (iVar6 == 0) goto LAB_00404c18;
                      }
                    }
                  }
                  iVar6 = ioctl(iVar2,0x8b20,apcStack_a0);
                  pFVar8 = stderr;
                  iVar3 = iVar4 + 1;
                  if (iVar6 < 0) {
                    piVar5 = __errno_location();
                    pcVar10 = strerror(*piVar5);
                    pcVar11 = "SIOCSIWRATE: %s\n";
                    goto LAB_00403f08;
                  }
                  goto LAB_00405684;
                }
                iVar4 = strcmp(pcVar11,"rate");
                if (iVar4 == 0) goto LAB_0040497c;
                iVar4 = strncasecmp(pcVar11,"rts",3);
                if (iVar4 == 0) {
                  if (param_1 <= iVar3 + 1) {
                    FUN_00402830();
                  }
                  local_40 = *(char ***)(param_2 + (iVar3 + 1) * 4);
                  local_90 = (char **)0xffffffff;
                  local_8c = 0x100;
                  iVar4 = strcasecmp((char *)local_40,"off");
                  if (iVar4 == 0) {
                    local_8c = CONCAT11(local_8c._0_1_,1);
                  }
                  else {
                    iVar4 = strcasecmp((char *)local_40,"auto");
                    if (iVar4 == 0) {
                      local_8c = local_8c & 0xff;
                    }
                    else {
                      iVar4 = strcasecmp((char *)local_40,"fixed");
                      if (iVar4 == 0) {
                        local_30._4_4_ = apcStack_a0;
                        iVar4 = ioctl(iVar2,0x8b23,local_30._4_4_);
                        pFVar8 = stderr;
                        if (iVar4 < 0) {
                          piVar5 = __errno_location();
                          pcVar10 = strerror(*piVar5);
                          pcVar11 = "SIOCGIWRTS: %s\n";
                          goto LAB_00403f08;
                        }
[32m[32m[32m                        strncpy((char *)local_30._4_4_,pcVar10,0x10);[0m[0m[0m
                        local_8c = CONCAT11(1,(undefined)local_8c);
                      }
                      else {
[32m                        iVar4 = sscanf((char *)local_40,"%ld",&local_90);[0m
                        if (iVar4 != 1) {
                          FUN_00402830();
                        }
                      }
                    }
                  }
                  iVar4 = ioctl(iVar2,0x8b22,apcStack_a0);
                  pFVar8 = stderr;
                  iVar3 = iVar3 + 2;
                  if (iVar4 < 0) {
                    piVar5 = __errno_location();
                    pcVar10 = strerror(*piVar5);
                    pcVar11 = "SIOCSIWRTS: %s\n";
                    goto LAB_00403f08;
                  }
                  goto LAB_00405684;
                }
                iVar4 = strncmp(pcVar11,"frag",4);
                if (iVar4 == 0) {
                  if (param_1 <= iVar3 + 1) {
                    FUN_00402830();
                  }
                  local_40 = *(char ***)(param_2 + (iVar3 + 1) * 4);
                  local_90 = (char **)0xffffffff;
                  local_8c = 0x100;
                  iVar4 = strcasecmp((char *)local_40,"off");
                  if (iVar4 == 0) {
                    local_8c = CONCAT11(local_8c._0_1_,1);
                  }
                  else {
                    iVar4 = strcasecmp((char *)local_40,"auto");
                    if (iVar4 == 0) {
                      local_8c = local_8c & 0xff;
                    }
                    else {
                      iVar4 = strcasecmp((char *)local_40,"fixed");
                      if (iVar4 == 0) {
                        local_30._4_4_ = apcStack_a0;
                        iVar4 = ioctl(iVar2,0x8b25,local_30._4_4_);
                        pFVar8 = stderr;
                        if (iVar4 < 0) {
                          piVar5 = __errno_location();
                          pcVar10 = strerror(*piVar5);
                          pcVar11 = "SIOCGIWFRAG: %s\n";
                          goto LAB_00403f08;
                        }
[32m[32m[32m                        strncpy((char *)local_30._4_4_,pcVar10,0x10);[0m[0m[0m
                        local_8c = CONCAT11(1,(undefined)local_8c);
                      }
                      else {
[32m                        iVar4 = sscanf((char *)local_40,"%ld",&local_90);[0m
                        if (iVar4 != 1) {
                          FUN_00402830();
                        }
                      }
                    }
                  }
                  iVar4 = ioctl(iVar2,0x8b24,apcStack_a0);
                  pFVar8 = stderr;
                  iVar3 = iVar3 + 2;
                  if (iVar4 < 0) {
                    piVar5 = __errno_location();
                    pcVar10 = strerror(*piVar5);
                    pcVar11 = "SIOCSIWFRAG: %s\n";
                    goto LAB_00403f08;
                  }
                  goto LAB_00405684;
                }
                iVar4 = strcmp(pcVar11,"mode");
                if (iVar4 == 0) {
                  if (param_1 <= iVar3 + 1) {
                    FUN_00402830();
                  }
                  local_40 = (char **)(param_2 + (iVar3 + 1) * 4);
[32m                  iVar4 = sscanf(*local_40,"%d",&local_a8);[0m
                  if (iVar4 != 1) {
                    local_a8._0_4_ = (char **)0x0;
                    do {
                      iVar4 = (int)local_a8._0_4_;
                      if (5 < (int)local_a8._0_4_) break;
                      iVar6 = strncasecmp(*local_40,(&PTR_DAT_00418150)[(int)local_a8._0_4_],3);
                      local_a8._0_4_ = (char **)(iVar4 + 1);
                    } while (iVar6 != 0);
                  }
                  local_a8._0_4_ = (char **)((ulonglong)local_a8 >> 0x20);
                  if (5 < local_a8._0_4_) {
                    FUN_00402830();
                  }
                  local_a8._0_4_ = (char **)((ulonglong)local_a8 >> 0x20);
                  local_90 = local_a8._0_4_;
                  iVar4 = ioctl(iVar2,0x8b06,apcStack_a0);
                  pFVar8 = stderr;
                  iVar3 = iVar3 + 2;
                  if (iVar4 < 0) {
                    piVar5 = __errno_location();
                    pcVar10 = strerror(*piVar5);
                    pcVar11 = "SIOCSIWMODE: %s\n";
                    goto LAB_00403f08;
                  }
                  goto LAB_00405684;
                }
                iVar4 = strncmp(pcVar11,"power",3);
                if (iVar4 != 0) {
                  fprintf(stderr,"Invalid argument : %s\n",pcVar11);
                  FUN_00402830();
                  goto LAB_00403f10;
                }
                iVar4 = iVar3 + 1;
                if (param_1 <= iVar4) {
                  FUN_00402830();
                }
                pcVar11 = *(char **)(param_2 + iVar4 * 4);
                iVar6 = strcasecmp(pcVar11,"off");
                if (iVar6 == 0) {
                  local_8c = CONCAT11(local_8c._0_1_,1);
                }
                else {
                  iVar6 = strcasecmp(pcVar11,"on");
                  if (iVar6 == 0) {
                    iVar3 = ioctl(iVar2,0x8b2d,apcStack_a0);
                    pFVar8 = stderr;
                    if (iVar3 < 0) {
                      piVar5 = __errno_location();
                      pcVar10 = strerror(*piVar5);
                      pcVar11 = "SIOCGIWPOWER: %s\n";
                      goto LAB_00403f08;
                    }
[32m[32m[32m                    strncpy((char *)apcStack_a0,pcVar10,0x10);[0m[0m[0m
                    local_8c = local_8c & 0xff00;
                  }
                  else {
                    local_8a = 0;
                    local_8c = local_8c & 0xff00;
                    iVar6 = strcasecmp(pcVar11,"min");
                    if (iVar6 == 0) {
                      local_8a = 1;
LAB_004052f0:
                      iVar4 = iVar3 + 2;
                      if (param_1 <= iVar4) {
                        FUN_00402830();
                      }
                    }
                    else {
                      iVar6 = strcasecmp(pcVar11,"max");
                      if (iVar6 == 0) {
                        local_8a = 2;
                        goto LAB_004052f0;
                      }
                    }
                    pcVar11 = *(char **)(param_2 + iVar4 * 4);
                    iVar3 = strcasecmp(pcVar11,"period");
                    if (iVar3 == 0) {
                      local_8a = local_8a | 0x1000;
LAB_00405370:
                      iVar4 = iVar4 + 1;
                      if (param_1 <= iVar4) {
                        FUN_00402830();
                      }
                      iVar6 = iVar4 * 4;
                    }
                    else {
                      iVar3 = strcasecmp(pcVar11,"timeout");
                      iVar6 = iVar4 << 2;
                      if (iVar3 == 0) {
                        local_8a = local_8a | 0x2000;
                        goto LAB_00405370;
                      }
                    }
                    ppcVar13 = (char **)(param_2 + iVar6);
                    local_40 = (char **)0x0;
[32m                    iVar3 = sscanf(*ppcVar13,"%lg",&local_a8);[0m
                    if (iVar3 == 1) {
                      lVar14 = __muldf3(local_a8._0_4_,local_a8._4_4_,0x412e8480,0);
                      local_a8 = lVar14;
                      local_30 = lVar14;
                      pcVar11 = index(*ppcVar13,0x75);
                      lVar14 = local_a8;
                      if (pcVar11 != (char *)0x0) {
                        lVar14 = __divdf3(local_30._0_4_,local_30._4_4_,0x412e8480,0);
                      }
                      local_a8 = lVar14;
                      pcVar11 = index(*ppcVar13,0x6d);
                      lVar14 = local_a8;
                      if (pcVar11 != (char *)0x0) {
                        lVar14 = __divdf3(local_a8._0_4_,local_a8._4_4_,0x408f4000,0);
                      }
                      local_a8._0_4_ = (char **)((ulonglong)lVar14 >> 0x20);
                      local_a8._4_4_ = (undefined4)lVar14;
                      local_a8 = lVar14;
                      local_90 = (char **)__fixdfsi(local_a8._0_4_,local_a8._4_4_);
                      if ((local_8a & 0xf000) == 0) {
                        local_8a = local_8a | 0x1000;
                      }
                      iVar4 = iVar4 + 1;
                      local_40 = (char **)0x1;
                    }
                    if (iVar4 < param_1) {
                      ppcVar13 = (char **)(param_2 + iVar4 * 4);
                      iVar3 = strcasecmp(*ppcVar13,"all");
                      if (iVar3 == 0) {
                        local_8a = local_8a | 0x300;
                      }
                      iVar3 = strncasecmp(*ppcVar13,"unicast",4);
                      if (iVar3 == 0) {
                        local_8a = local_8a | 0x100;
                      }
                      iVar3 = strncasecmp(*ppcVar13,"multicast",5);
                      if (iVar3 == 0) {
                        local_8a = local_8a | 0x200;
                      }
                      iVar3 = strncasecmp(*ppcVar13,"force",5);
                      if (iVar3 == 0) {
                        local_8a = local_8a | 0x400;
                      }
                      iVar3 = strcasecmp(*ppcVar13,"repeat");
                      if (iVar3 == 0) {
                        local_8a = local_8a | 0x800;
                      }
                      if ((local_8a & 0xf00) == 0) goto LAB_004055c0;
                      iVar4 = iVar4 + 1;
                    }
                    else {
LAB_004055c0:
                      if (local_40 == (char **)0x0) {
                        FUN_00402830();
                      }
                    }
                    iVar4 = iVar4 + -1;
                  }
                }
                iVar6 = ioctl(iVar2,0x8b2c,apcStack_a0);
                pFVar8 = stderr;
                iVar3 = iVar4 + 1;
                if (-1 < iVar6) goto LAB_00405684;
                piVar5 = __errno_location();
                local_30._0_4_ = (char *)*piVar5;
                pcVar10 = strerror((int)local_30._0_4_);
                pcVar11 = "SIOCSIWPOWER(%d): %s\n";
              }
              fprintf(pFVar8,pcVar11,local_30._0_4_,pcVar10);
              goto LAB_00403f10;
            }
            if (param_1 <= iVar3 + 1) {
              FUN_00402830();
            }
[32m            iVar4 = sscanf(*(char **)(param_2 + (iVar3 + 1) * 4),"%d",&local_90);[0m
            if (iVar4 != 1) {
              FUN_00402830();
            }
            iVar4 = ioctl(iVar2,0x8b08,apcStack_a0);
            pFVar8 = stderr;
            iVar3 = iVar3 + 2;
            if (iVar4 < 0) {
              piVar5 = __errno_location();
              pcVar10 = strerror(*piVar5);
              pcVar11 = "SIOCSIWSENS: %s\n";
LAB_00403f08:
              fprintf(pFVar8,pcVar11,pcVar10);
LAB_00403f10:
              uVar9 = 0xffffffff;
LAB_00405694:
              close(iVar2);
              return uVar9;
            }
          } while( true );
        }
        FUN_00402978(iVar2,pcVar10);
      }
    }
    close(iVar2);
    iVar2 = 0;
  }
                    /* WARNING: Subroutine does not return */
  exit(iVar2);
}

[ASK_GPT] beb39b0c4e551cad
