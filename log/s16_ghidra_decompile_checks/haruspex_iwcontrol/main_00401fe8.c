
undefined4 main(int param_1,undefined4 *param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  FILE *pFVar6;
  int iVar7;
  int iVar8;
  __pid_t _Var9;
  int iVar10;
  uint uVar11;
  undefined *puVar12;
  char *pcVar13;
  char *__s;
  undefined4 uVar14;
  undefined4 *puVar15;
  int local_70;
  char acStack_6c [20];
  char acStack_58 [32];
  int local_38;
  char *local_34;
  undefined *local_30;
  
[32m  pFVar6 = fopen("/var/run/iwcontrol.pid","r");[0m
  if (pFVar6 != (FILE *)0x0) {
[32m    fgets(acStack_6c,0x14,pFVar6);[0m
[32m    iVar7 = sscanf(acStack_6c,"%d",&local_70);[0m
    if ((iVar7 != 0) && (1 < local_70)) {
      kill(local_70,0xf);
    }
    fclose(pFVar6);
  }
  bVar1 = false;
  setsid();
  puVar15 = param_2;
  for (iVar7 = 1; iVar7 < param_1; iVar7 = iVar7 + 1) {
    pcVar13 = (char *)puVar15[1];
    iVar8 = strncmp("wlan",pcVar13,4);
    if (iVar8 == 0) {
      uVar14 = 10;
      if (9 < DAT_00418310) {
        pcVar13 = "Only  %d Wlan interace is supported\n";
LAB_004021a4:
        printf(pcVar13,uVar14);
        return 0xffffffff;
      }
      printf("Register to %s\n",pcVar13);
[32m[32m      strcpy(&DAT_00418a6c + DAT_00418310 * 0x14,(char *)puVar15[1]);[0m[0m
      DAT_00418310 = DAT_00418310 + 1;
    }
    else {
      iVar8 = strncmp("poll",pcVar13,4);
      bVar1 = true;
      if (iVar8 != 0) {
        uVar14 = *param_2;
        pcVar13 = "Usage: %s [wlan0] [wlan1] ... \n";
        goto LAB_004021a4;
      }
    }
    puVar15 = puVar15 + 1;
  }
  if (DAT_00418310 == 0) {
    pcVar13 = "At least one wlan interface should be binded";
  }
  else {
    iVar7 = FUN_00401210(&DAT_00418324,&DAT_00418b34,&DAT_00418c24);
    if (-1 < iVar7) {
[32m      iVar7 = open("/var/run/iwcontrol.pid",0x101,0x1a4);[0m
      if (iVar7 < 0) {
        printf("Unable to open pidfile %s\n","/var/run/iwcontrol.pid");
      }
      else {
        lockf(iVar7,1,0);
      }
      iVar8 = daemon(0,1);
      if (iVar8 == -1) {
        puts("fork iwcontrol error!");
        iVar7 = 1;
      }
      else {
        if (-1 < iVar7) {
[32m          pFVar6 = fdopen(iVar7,"w");[0m
          if (pFVar6 != (FILE *)0x0) {
            _Var9 = getpid();
            fprintf(pFVar6,"%d\n",_Var9);
            fclose(pFVar6);
          }
          lockf(iVar7,2,0);
          close(iVar7);
        }
        FUN_00401120(&DAT_0041842c);
        if (DAT_00418314 != 0) {
          puVar12 = &DAT_00420000;
          puVar15 = &DAT_00418324;
          for (iVar7 = 0; iVar7 < *(int *)(puVar12 + -0x7cec); iVar7 = iVar7 + 1) {
            local_30 = puVar12;
[32m[32m            sprintf(acStack_58,"/var/auth-%s.fifo",&DAT_00418324 + (iVar7 * 3 + 1) * 2);[0m[0m
            iw_message(0x14,"open auth fifo %s\n",acStack_58);
            puts("auth..");
            FUN_00401174(puVar15,acStack_58);
            puVar12 = local_30;
            puVar15 = puVar15 + 6;
          }
        }
        if (DAT_00418318 != 0) {
          iw_message(0x14,"open iapp fifo %s\n","/var/iapp.fifo");
          FUN_00401174(&DAT_00418414,"/var/iapp.fifo");
        }
        if (DAT_0041831c != 0) {
          puVar15 = &DAT_00418b34;
          for (iVar7 = 0; iVar7 < DAT_0041831c; iVar7 = iVar7 + 1) {
[32m[32m            sprintf(acStack_58,"/var/autoconf-%s.fifo",&DAT_00418b34 + (iVar7 * 3 + 1) * 2);[0m[0m
            iw_message(0x14,"open autoconfig fifo %s\n",acStack_58);
            FUN_00401174(puVar15,acStack_58);
            puVar15 = puVar15 + 6;
          }
        }
        if (DAT_00418320 != 0) {
          puVar15 = &DAT_00418c24;
          for (iVar7 = 0; iVar7 < DAT_00418320; iVar7 = iVar7 + 1) {
[32m[32m            sprintf(acStack_58,"/var/wscd-%s.fifo",&DAT_00418c24 + (iVar7 * 3 + 1) * 2);[0m[0m
            iw_message(0x14,"open wscd fifo %s\n",acStack_58);
            FUN_00401174(puVar15,acStack_58);
            puVar15 = puVar15 + 6;
          }
        }
        DAT_00418328 = FUN_00401f94();
        if (0 < DAT_00418328) {
          if (bVar1) {
            do {
              FUN_00401f2c(0x16);
              sleep(1);
            } while( true );
          }
          local_34 = acStack_6c;
          pcVar13 = &DAT_00418a6c;
          iVar8 = 0;
          bVar3 = false;
          iVar7 = 0;
          do {
            if (DAT_00418310 <= iVar8) {
              do {
                pause();
              } while( true );
            }
            iVar10 = strncmp("wlan0",pcVar13,5);
            bVar2 = bVar1;
            bVar4 = bVar3;
            if (iVar10 == 0) {
              bVar2 = true;
              bVar5 = !bVar1;
              bVar1 = bVar2;
              if (bVar5) {
                iVar7 = 0;
                goto LAB_00402658;
              }
            }
            else {
LAB_00402658:
              iVar10 = strncmp("wlan1",pcVar13,5);
              bVar1 = bVar2;
              if (iVar10 == 0) {
                bVar4 = true;
                if (bVar3) goto LAB_004027d0;
                iVar7 = 1;
              }
[32m              sprintf(local_34,"/dev/wl_chr%d",iVar7);[0m
[32m              DAT_00418d14 = (undefined *)open(local_34,2,0);[0m
              if ((int)DAT_00418d14 < 0) {
                if (iVar7 == 0) {
                  local_38 = RegisterPID(DAT_00418328,"wlan0");
                  __s = "iwcontrol RegisterPID to (wlan0)";
                }
                else {
                  local_38 = RegisterPID(DAT_00418328,"wlan1");
                  __s = "iwcontrol RegisterPID to (wlan1)";
                }
                puts(__s);
                if (local_38 < 1) {
                  printf("Warning: unable to open an wl_chr device and PID registration fail.(wlan%d)(%d %s)\n"
                         ,iVar7,0x2f9,&DAT_00407470);
                }
                else {
[32m                  signal(0x16,FUN_00401f2c);[0m
                }
              }
              else {
[32m                signal(0x16,FUN_00401f2c);[0m
                local_30 = DAT_00418d14;
                _Var9 = getpid();
                fcntl((int)local_30,0x18,_Var9);
                uVar11 = fcntl((int)DAT_00418d14,3);
                fcntl((int)DAT_00418d14,4,uVar11 | 0x1000);
              }
            }
LAB_004027d0:
            bVar3 = bVar4;
            iVar8 = iVar8 + 1;
            pcVar13 = pcVar13 + 0x14;
          } while( true );
        }
        perror("Socket fd return 0");
        iVar7 = 0;
      }
                    /* WARNING: Subroutine does not return */
      exit(iVar7);
    }
    pcVar13 = "parsing pid failed";
  }
  puts(pcVar13);
  return 0xffffffff;
}

[ASK_GPT] a10e8ffc45b59c5a
