
undefined4 main(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  tm *ptVar3;
  size_t sVar4;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined auStack_a0 [132];
  
  if (param_1 < 4) {
    FUN_00401c30();
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_004026cc("/tmp/mysnapshot.jpg");
    uVar1 = 0xffffffff;
    if (-1 < iVar2) {
      local_a8 = atoi(*(char **)(param_2 + 8));
      iVar2 = atoi(*(char **)(param_2 + 0xc));
      ptVar3 = localtime(&local_a8);
[32m[32m      strcpy((char *)&uStack_a4,*(char **)(param_2 + 4));[0m[0m
      sVar4 = strlen((char *)&uStack_a4);
      if (*(char *)((int)&uStack_a4 + (sVar4 - 1)) != '/') {
        sVar4 = strlen((char *)&uStack_a4);
        *(char *)((int)&uStack_a4 + sVar4) = '/';
        *(undefined *)((int)&uStack_a4 + sVar4 + 1) = 0;
      }
      if ((param_1 == 5) && (**(char **)(param_2 + 0x10) != '\0')) {
[32m[32m        strcat((char *)&uStack_a4,*(char **)(param_2 + 0x10));[0m[0m
      }
      sVar4 = strlen((char *)&uStack_a4);
      sprintf((char *)((int)&uStack_a4 + sVar4),"%04d%02d%02d_%02d%02d%02d",ptVar3->tm_year + 0x76c,
[32m              ptVar3->tm_mon + 1,ptVar3->tm_mday,ptVar3->tm_hour,ptVar3->tm_min,ptVar3->tm_sec);[0m
      if (iVar2 != 0) {
        sVar4 = strlen((char *)&uStack_a4);
        *(char *)((int)&uStack_a4 + sVar4) = 'D';
        *(undefined *)((int)&uStack_a4 + sVar4 + 1) = 0;
      }
      sVar4 = strlen((char *)&uStack_a4);
      *(undefined4 *)((int)&uStack_a4 + sVar4) = 0x2e6a7067;
      *(undefined *)((int)&uStack_a4 + sVar4 + 4) = 0;
      FUN_00401cb0("/tmp/mysnapshot.jpg",&uStack_a4);
[32m[32m      sprintf((char *)&uStack_a4,"rm -f %s","/tmp/mysnapshot.jpg");[0m[0m
[32m[32m      system((char *)&uStack_a4);[0m[0m
      uVar1 = 0;
    }
  }
  return uVar1;
}

[ASK_GPT] 4563d770418cb67e
