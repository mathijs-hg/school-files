
undefined4 FUN_004040ec(int param_1,int param_2)

{
  undefined2 uVar1;
  void *pvVar2;
  long lVar3;
  void *pvVar4;
  uint uVar5;
  int iVar6;
  int local_1c;
  
[32m[32m  snprintf(g_devname,0x100,"/dev/video0");[0m[0m
LAB_004050f4:
  while( true ) {
[32m    iVar6 = getopt_long(param_1,param_2,&DAT_004173e0,longopts,0);[0m
    if (iVar6 == -1) {
      return 0;
    }
    uVar1 = (undefined2)iVar6;
    if (0xf < iVar6) break;
    if (iVar6 < 0xe) {
      if (iVar6 == 7) {
[32m[32m[32m        pvVar2 = malloc(0x118);[0m[0m[0m
[32m        memset(pvVar2,0,0x118);[0m
        *(undefined2 *)((int)pvVar2 + 8) = uVar1;
        uVar5 = strtol(optarg,(char **)0x0,0);
        *(uint *)((int)pvVar2 + 0xc) = uVar5 & 0xffff;
        FUN_00403dcc(pvVar2,&m_cmd_list);
      }
      else if (iVar6 < 8) {
        if (iVar6 == 3) {
[32m[32m[32m          pvVar2 = malloc(0x118);[0m[0m[0m
[32m          memset(pvVar2,0,0x118);[0m
          *(undefined2 *)((int)pvVar2 + 8) = uVar1;
          iVar6 = strcasecmp(optarg,"RST_2_UPDATEFW");
          if (iVar6 == 0) {
            *(undefined2 *)((int)pvVar2 + 10) = 1;
          }
          else {
            iVar6 = strcasecmp(optarg,"RST_2_NEWCODE");
            if (iVar6 == 0) {
              *(undefined2 *)((int)pvVar2 + 10) = 2;
            }
            else {
              iVar6 = strcasecmp(optarg,"RST_2_ROM");
              if (iVar6 == 0) {
                *(undefined2 *)((int)pvVar2 + 10) = 3;
              }
            }
          }
          FUN_00403dcc(pvVar2,&m_cmd_list);
        }
        else if (iVar6 < 4) {
          if (iVar6 == 1) {
[32m[32m[32m            pvVar2 = malloc(0x118);[0m[0m[0m
[32m            memset(pvVar2,0,0x118);[0m
            *(undefined2 *)((int)pvVar2 + 8) = uVar1;
[32m[32m            snprintf((char *)((int)pvVar2 + 0x18),0x100,"%s",optarg);[0m[0m
            FUN_00403dcc(pvVar2,&m_cmd_list);
          }
          else {
            if (iVar6 != 2) goto LAB_004050d0;
[32m[32m[32m            pvVar2 = malloc(0x118);[0m[0m[0m
[32m            memset(pvVar2,0,0x118);[0m
            *(undefined2 *)((int)pvVar2 + 8) = uVar1;
            FUN_00403dcc(pvVar2,&m_cmd_list);
          }
        }
        else {
          if (iVar6 != 5) {
            if (iVar6 < 6) goto LAB_004045b8;
            goto LAB_004047b8;
          }
LAB_00404664:
          if (param_1 < optind + 1) {
            fwrite("need more argument.\n",1,0x14,stderr);
                    /* WARNING: Subroutine does not return */
            exit(1);
          }
[32m[32m[32m          pvVar2 = malloc(0x118);[0m[0m[0m
[32m          memset(pvVar2,0,0x118);[0m
          *(undefined2 *)((int)pvVar2 + 8) = uVar1;
          lVar3 = strtol(optarg,(char **)0x0,0);
          *(long *)((int)pvVar2 + 0xc) = lVar3;
          lVar3 = strtol(*(char **)(param_2 + optind * 4),(char **)0x0,0);
          *(short *)((int)pvVar2 + 0x10) = (short)lVar3;
          FUN_00403dcc(pvVar2,&m_cmd_list);
        }
      }
      else if (iVar6 < 0xb) {
        if (8 < iVar6) goto LAB_00404cd0;
        if (param_1 < optind + 1) {
          fwrite("need more argument.\n",1,0x14,stderr);
                    /* WARNING: Subroutine does not return */
          exit(1);
        }
[32m[32m[32m        pvVar2 = malloc(0x118);[0m[0m[0m
[32m        memset(pvVar2,0,0x118);[0m
        *(undefined2 *)((int)pvVar2 + 8) = uVar1;
        uVar5 = strtol(optarg,(char **)0x0,0);
        *(uint *)((int)pvVar2 + 0xc) = uVar5 & 0xffff;
        lVar3 = strtol(*(char **)(param_2 + optind * 4),(char **)0x0,0);
        *(short *)((int)pvVar2 + 10) = (short)lVar3;
        FUN_00403dcc(pvVar2,&m_cmd_list);
      }
      else {
        if (iVar6 == 0xc) goto LAB_00404664;
        if (iVar6 < 0xd) {
[32m[32m[32m          pvVar2 = malloc(0x118);[0m[0m[0m
[32m          memset(pvVar2,0,0x118);[0m
          *(undefined2 *)((int)pvVar2 + 8) = uVar1;
          lVar3 = strtol(optarg,(char **)0x0,0);
          *(ushort *)((int)pvVar2 + 10) = (ushort)lVar3 & 0xff;
          FUN_00403dcc(pvVar2,&m_cmd_list);
        }
        else {
LAB_004047b8:
          if (param_1 < optind + 1) {
            fwrite("need more argument.\n",1,0x14,stderr);
                    /* WARNING: Subroutine does not return */
            exit(1);
          }
[32m[32m          pvVar2 = malloc(0x118);[0m[0m
[32m          memset(pvVar2,0,0x118);[0m
          *(undefined2 *)((int)pvVar2 + 8) = uVar1;
          lVar3 = strtol(optarg,(char **)0x0,0);
          *(long *)((int)pvVar2 + 0xc) = lVar3;
          lVar3 = strtol(*(char **)(param_2 + optind * 4),(char **)0x0,0);
          *(short *)((int)pvVar2 + 0x10) = (short)lVar3;
          if (param_1 < (int)(optind + 1 + (uint)*(ushort *)((int)pvVar2 + 0x10))) {
            fwrite("data is not enough.\n",1,0x14,stderr);
            free(pvVar2);
                    /* WARNING: Subroutine does not return */
            exit(1);
          }
[32m[32m[32m          pvVar4 = malloc((uint)*(ushort *)((int)pvVar2 + 0x10));[0m[0m[0m
          *(void **)((int)pvVar2 + 0x14) = pvVar4;
          if (*(int *)((int)pvVar2 + 0x14) == 0) {
            fwrite("malloc memory fail.\n",1,0x14,stderr);
            free(pvVar2);
                    /* WARNING: Subroutine does not return */
            exit(1);
          }
          for (local_1c = 0; local_1c < (int)(uint)*(ushort *)((int)pvVar2 + 0x10);
              local_1c = local_1c + 1) {
            iVar6 = *(int *)((int)pvVar2 + 0x14);
            lVar3 = strtol(*(char **)(param_2 + (optind + 1 + local_1c) * 4),(char **)0x0,0);
            *(char *)(iVar6 + local_1c) = (char)lVar3;
          }
          FUN_00403dcc(pvVar2,&m_cmd_list);
        }
      }
    }
    else {
LAB_00404cd0:
[32m[32m[32m      pvVar2 = malloc(0x118);[0m[0m[0m
[32m      memset(pvVar2,0,0x118);[0m
      *(undefined2 *)((int)pvVar2 + 8) = uVar1;
      FUN_00403dcc(pvVar2,&m_cmd_list);
    }
  }
  if (iVar6 == 0x22) goto LAB_00404664;
  if (iVar6 < 0x23) {
    if (iVar6 == 0x12) {
[32m[32m[32m      pvVar2 = malloc(0x118);[0m[0m[0m
[32m      memset(pvVar2,0,0x118);[0m
      *(undefined2 *)((int)pvVar2 + 8) = uVar1;
      FUN_00403dcc(pvVar2,&m_cmd_list);
      goto LAB_004050f4;
    }
    if (iVar6 < 0x13) {
      if (iVar6 == 0x10) {
[32m[32m[32m        pvVar2 = malloc(0x118);[0m[0m[0m
[32m        memset(pvVar2,0,0x118);[0m
        *(undefined2 *)((int)pvVar2 + 8) = uVar1;
        FUN_00403dcc(pvVar2,&m_cmd_list);
        goto LAB_004050f4;
      }
      if (iVar6 == 0x11) {
[32m[32m[32m        pvVar2 = malloc(0x118);[0m[0m[0m
[32m        memset(pvVar2,0,0x118);[0m
        *(undefined2 *)((int)pvVar2 + 8) = uVar1;
        lVar3 = strtol(optarg,(char **)0x0,0);
        *(long *)((int)pvVar2 + 0xc) = lVar3;
        FUN_00403dcc(pvVar2,&m_cmd_list);
        goto LAB_004050f4;
      }
    }
    else {
      if (iVar6 == 0x20) {
LAB_004045b8:
[32m[32m[32m        pvVar2 = malloc(0x118);[0m[0m[0m
[32m        memset(pvVar2,0,0x118);[0m
        *(undefined2 *)((int)pvVar2 + 8) = uVar1;
        lVar3 = strtol(optarg,(char **)0x0,0);
        *(short *)((int)pvVar2 + 10) = (short)lVar3;
        FUN_00403dcc(pvVar2,&m_cmd_list);
        goto LAB_004050f4;
      }
      if (0x20 < iVar6) goto LAB_00404cd0;
      if (iVar6 == 0x13) {
[32m[32m[32m        pvVar2 = malloc(0x118);[0m[0m[0m
[32m        memset(pvVar2,0,0x118);[0m
        *(undefined2 *)((int)pvVar2 + 8) = uVar1;
        lVar3 = strtol(optarg,(char **)0x0,0);
        *(short *)((int)pvVar2 + 10) = (short)lVar3;
        FUN_00403dcc(pvVar2,&m_cmd_list);
        goto LAB_004050f4;
      }
    }
  }
  else {
    if (iVar6 == 0x3f) {
      fprintf(stderr,"invalid param: -%c\n",optopt);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    if (iVar6 < 0x40) {
      if (iVar6 == 0x23) goto LAB_00404cd0;
      if (iVar6 == 0x3a) {
        fprintf(stderr,"requires argument: -%c\n",optopt);
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
    }
    else {
      if (iVar6 == 0x68) {
        FUN_00403ef4();
        goto LAB_004050f4;
      }
      if (iVar6 == 0x1000) goto LAB_004050f4;
      if (iVar6 == 100) {
[32m[32m        snprintf(g_devname,0x100,"%s",optarg);[0m[0m
        goto LAB_004050f4;
      }
    }
  }
LAB_004050d0:
  FUN_00403ef4();
  goto LAB_004050f4;
}

[ASK_GPT] dddc822e294e1bf1
