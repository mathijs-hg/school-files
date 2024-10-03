
uint FUN_00412f7c(char *param_1,int param_2)

{
  size_t sVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  char local_20;
  char local_1f;
  undefined local_1e;
  
  sVar1 = strlen(param_1);
  if ((sVar1 & 1) == 0) {
    uVar2 = sVar1 >> 1;
    if (sVar1 != 0) {
      uVar2 = (uint)*param_1;
      if ((((0x2f < (int)uVar2) && (6 < ((uVar2 & 0xff) - 0x3a & 0xff))) &&
          (0x19 < ((uVar2 & 0xff) - 0x47 & 0xff))) && ((int)uVar2 < 0x67)) {
        uVar2 = 1;
        do {
          if (sVar1 <= uVar2) {
            uVar2 = 0;
            do {
              local_20 = *param_1;
[32m              local_1f = param_1[1];[0m
              local_1e = 0;
              lVar3 = strtol(&local_20,(char **)0x0,0x10);
              *(char *)(param_2 + (uVar2 >> 1)) = (char)lVar3;
              uVar2 = uVar2 + 2;
              param_1 = param_1 + 2;
            } while (uVar2 < sVar1);
            return sVar1 >> 1;
          }
          uVar4 = (uint)param_1[uVar2];
        } while (((0x2f < (int)uVar4) && (6 < ((uVar4 & 0xff) - 0x3a & 0xff))) &&
                ((0x19 < ((uVar4 & 0xff) - 0x47 & 0xff) && (uVar2 = uVar2 + 1, (int)uVar4 < 0x67))))
        ;
      }
      fprintf(stderr,"[ERROR] %s:%u: input string error: %s\n","aes.c",0xca,param_1);
      uVar2 = 0;
    }
  }
  else {
    fprintf(stderr,"[ERROR] %s:%u: input length error:%u\n","aes.c",0xbe,sVar1);
    uVar2 = 0;
  }
  return uVar2;
}

[ASK_GPT] 023d0b013750e658
