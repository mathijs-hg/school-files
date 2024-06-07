
void iw_print_pm_mode(undefined4 *param_1,size_t param_2,uint param_3,undefined4 param_4)

{
  if ((int)param_2 < 0x1c) {
[32m    snprintf((char *)param_1,param_2,"<too big>",param_4,&_gp);[0m
  }
  else {
    param_3 = param_3 & 0xf00;
    if (param_3 == 0x300) {
      *param_1 = 0x65646f6d;
      param_1[1] = 0x6c6c413a;
      param_1[2] = 0x63617020;
      param_1[3] = 0x7374656b;
      param_1[4] = 0x63657220;
      param_1[5] = 0x65766965;
      *(char *)(param_1 + 6) = 'd';
      *(char *)((int)param_1 + 0x19) = '\0';
    }
    else {
      if (param_3 < 0x301) {
        if (param_3 == 0x100) {
          *param_1 = 0x65646f6d;
          param_1[1] = 0x696e553a;
          param_1[2] = 0x74736163;
          param_1[3] = 0x6c6e6f20;
          param_1[4] = 0x65722079;
          param_1[5] = 0x76696563;
          *(char *)(param_1 + 6) = 'e';
          *(char *)((int)param_1 + 0x19) = 'd';
          *(char *)((int)param_1 + 0x1a) = '\0';
          return;
        }
        if (param_3 == 0x200) {
          *param_1 = 0x65646f6d;
          param_1[1] = 0x6c754d3a;
          param_1[2] = 0x61636974;
          param_1[3] = 0x6f207473;
          param_1[4] = 0x20796c6e;
          param_1[5] = 0x65636572;
          param_1[6] = 0x64657669;
          *(char *)(param_1 + 7) = '\0';
          return;
        }
      }
      else {
        if (param_3 == 0x400) {
          *param_1 = 0x65646f6d;
          param_1[1] = 0x726f463a;
          param_1[2] = 0x73206563;
          param_1[3] = 0x69646e65;
          *(char *)(param_1 + 4) = 'n';
          *(char *)((int)param_1 + 0x11) = 'g';
          *(char *)((int)param_1 + 0x12) = '\0';
          return;
        }
        if (param_3 == 0x800) {
          *param_1 = 0x65646f6d;
          param_1[1] = 0x7065523a;
          param_1[2] = 0x20746165;
          param_1[3] = 0x746c756d;
          param_1[4] = 0x73616369;
          *(char *)(param_1 + 5) = 't';
          *(char *)((int)param_1 + 0x15) = 's';
          *(char *)((int)param_1 + 0x16) = '\0';
          return;
        }
      }
      *(undefined *)param_1 = 0;
    }
  }
  return;
}

[ASK_GPT] 60656311ddc6e25f
