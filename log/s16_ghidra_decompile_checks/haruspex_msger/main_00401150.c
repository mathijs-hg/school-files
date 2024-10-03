
undefined4 main(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  size_t sVar5;
  int iVar6;
  int iVar7;
  char *__nptr;
  long *plVar8;
  int iVar9;
  int iVar10;
  undefined4 local_130;
  int local_12c [65];
  
  local_130 = 0;
  if (param_1 < 4) {
    FUN_00400a60("msger");
    return 0xffffffff;
  }
  uVar1 = atoi(*(char **)(param_2 + 8));
  iVar10 = 0;
  do {
    iVar2 = strcmp(*(char **)(param_2 + 4),"sinfo" + iVar10 * 0x1c);
    iVar6 = iVar10 + 1;
    if (iVar2 == 0) {
      iVar10 = (&DAT_00402920)[iVar10 * 7];
      if (-1 < iVar10) {
        if (1 < uVar1) {
          FUN_00400a60("msger");
          return 0xffffffff;
        }
        if (uVar1 == 0) {
          if (param_1 < 6) {
            puts("msger: inform message specify uncorrect arguments!");
            FUN_00400a60("msger");
            return 0xffffffff;
          }
        }
        else if ((uVar1 == 1) && (param_1 != 5)) {
          puts("msger: query message only accept 4 arguments!");
          FUN_00400a60("msger");
          return 0xffffffff;
        }
        __nptr = *(char **)(param_2 + 0xc);
        iVar2 = atoi(__nptr);
        if (iVar2 != 0) goto LAB_00401374;
        iVar2 = 0;
        goto LAB_00401310;
      }
      break;
    }
    iVar10 = iVar6;
  } while (iVar6 != 10);
  printf("msger: unknow message server name: %s!\n",*(char **)(param_2 + 4));
  FUN_00400a60("msger");
  return 0xffffffff;
LAB_00401310:
  iVar6 = strcmp(__nptr,"cstop" + iVar2 * 0x1c);
  iVar7 = iVar2 + 1;
  if (iVar6 == 0) {
    iVar2 = (&DAT_00402a38)[iVar2 * 7];
LAB_00401374:
    if (-1 < iVar2) {
      iVar6 = 0;
      if ((iVar10 == 0xa55a001) || (iVar6 = msgInitial(iVar10), iVar6 != 0)) {
        if (uVar1 == 0) {
          iVar7 = atoi(*(char **)(param_2 + 0x10));
          if (iVar7 == 0) {
            if (5 < param_1) {
              plVar8 = local_12c;
              iVar9 = 5;
              do {
                lVar4 = strtol(*(char **)(param_2 + 0x14),(char **)0x0,0);
                *plVar8 = lVar4;
                iVar9 = iVar9 + 1;
                param_2 = param_2 + 4;
                plVar8 = plVar8 + 1;
              } while (iVar9 < param_1);
            }
            iVar9 = (param_1 + -5) * 4;
          }
          else {
[32m[32m            strcpy((char *)local_12c,*(char **)(param_2 + 0x14));[0m[0m
[32m            sVar5 = strlen(*(char **)(param_2 + 0x14));[0m
[32m            iVar9 = sVar5 + 1;[0m
          }
          if (iVar10 == 0xa55a001) {
            puts("msger: Set ShareInfo...");
            SIWriteInt(iVar2,local_12c[0]);
          }
          else {
            puts("msger: Send Inform...");
            if (((iVar10 == 0xa55a200) && (0x79 < iVar2)) && (iVar2 < 0x83)) {
              if (iVar7 == 0) {
                msgInformEvent(iVar6,iVar2,local_12c[0]);
              }
              else {
                msgInformEventStr(iVar6,iVar2,local_12c);
              }
            }
            else {
              msgInformParam(iVar6,iVar2,iVar7,iVar9,local_12c);
            }
          }
        }
        else if (uVar1 == 1) {
          local_12c[0] = atoi(*(char **)(param_2 + 0x10));
          if (iVar10 == 0xa55a001) {
            SIReadInt(iVar2,&local_130);
            printf("%d\n",local_130);
          }
          else {
            msgQueryParam(iVar6,iVar2,4,local_12c);
            iVar10 = msgWaitAnswer(iVar6,1);
            if (iVar10 < 0) {
              puts("msger: Something wrong can\'t get answer!");
            }
            else if (*(int *)(iVar6 + 0x18) == 0) {
              printf("%d\n",*(undefined4 *)(iVar6 + 0x20));
            }
            else {
              puts((char *)(iVar6 + 0x20));
            }
          }
        }
        msgDetach(iVar6);
        uVar3 = 0;
      }
      else {
        puts("msger: message manager not ready!");
        uVar3 = 0xffffffff;
      }
      return uVar3;
    }
LAB_0040137c:
    puts("msger: invalid command!");
    FUN_00400a60("msger");
    return 0xffffffff;
  }
  iVar2 = iVar7;
  if (iVar7 == 0xb9) goto LAB_0040137c;
  goto LAB_00401310;
}

[ASK_GPT] 16e06504eeb1b368
