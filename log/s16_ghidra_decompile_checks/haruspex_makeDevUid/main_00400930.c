
/* WARNING: Could not reconcile some variable overlaps */

undefined4 main(void)

{
  uint uVar1;
  FILE *pFVar2;
  uint uVar3;
  int iVar4;
  undefined uVar5;
  undefined *puVar6;
  timeval tStack_38;
  undefined local_30 [16];
  undefined local_20 [4];
  uint local_1c;
  undefined2 local_18;
  
[32m  pFVar2 = fopen("/mnt/flash/device/dev_unique.ini","r");[0m
  if (pFVar2 == (FILE *)0x0) {
[32m    system("mkdir -p /mnt/flash/device/ 2 > /dev/null 1 > /dev/null");[0m
[32m    pFVar2 = fopen("/mnt/flash/device/dev_unique.ini","w");[0m
    if (pFVar2 == (FILE *)0x0) {
      fwrite("create dev_unique.ini failed\n",1,0x1d,stderr);
    }
    else {
      fclose(pFVar2);
      fwrite("generate device unique id\n",1,0x1a,stderr);
      local_1c = 0;
      local_18 = 0;
      HWMIB_getMAC();
      uVar1 = local_1c >> 8;
      uVar3 = local_1c & 0xff;
      gettimeofday(&tStack_38,(__timezone_ptr_t)0x0);
      srand(uVar1 << 0x18 | uVar3 << 0x10 | (uint)(byte)local_18 | (uint)local_18._0_1_ << 8 |
[32m[32m            tStack_38.tv_usec << 0xc);[0m[0m
      puVar6 = local_30;
      do {
[32m[32m        iVar4 = rand();[0m[0m
        iVar4 = iVar4 % 0x3e;
        if (iVar4 < 0x24) {
          if (iVar4 < 10) {
            uVar5 = (undefined)((uint)((iVar4 + 0x30) * 0x1000000) >> 0x18);
          }
          else {
            uVar5 = (undefined)((uint)((iVar4 + 0x57) * 0x1000000) >> 0x18);
          }
        }
        else {
          uVar5 = (undefined)((uint)((iVar4 + 0x1d) * 0x1000000) >> 0x18);
        }
        *puVar6 = uVar5;
        puVar6 = puVar6 + 1;
      } while (puVar6 != local_20);
      local_20[0] = 0;
      CfgSetField("/mnt/flash/device/dev_unique.ini",&DAT_00400de8,"unique_id",local_30);
      fprintf(stderr,"device unique id: [%s]\n",local_30);
    }
  }
  else {
    fclose(pFVar2);
    fwrite("don\'t need generate device unique id\n",1,0x25,stderr);
  }
  return 0;
}

[ASK_GPT] 4d7564dd0fae55df
