
undefined4 main(void)

{
  char cVar1;
  int iVar2;
  size_t sVar3;
  uint uVar4;
  int local_ad8;
  int local_ad4;
  char local_ad0 [512];
  char local_8d0 [1024];
  char local_4d0;
  undefined auStack_4cf [1151];
  int local_50;
  int local_4c;
  int local_48;
  char *local_44;
  char *local_40;
  int local_3c;
  char *local_38;
  char *local_34;
  int *local_30;
  
  local_ad8 = 0;
  local_ad4 = 0;
  local_ad0[0] = '\0';
[32m  memset(local_ad0 + 1,0,0x1ff);[0m
  local_8d0[0] = '\0';
[32m  memset(local_8d0 + 1,0,0x3ff);[0m
  local_4d0 = '\0';
[32m  memset(auStack_4cf,0,0x47f);[0m
  CfgEnumSec("/mnt/flash/config/bundle.ini",&local_ad8,0);
  local_3c = local_ad8;
  if (local_ad8 != 0) {
    local_30 = &local_ad4;
    local_38 = "Restore Bundle config: [%s] [%s] = [%s]\n";
    local_34 = "/usr/sbin/userconfig -write \"%s\" \"%s\" \"%s\" 2>/dev/null 1>/dev/null";
    local_44 = local_8d0;
    local_40 = &local_4d0;
    do {
      local_4c = local_3c;
      CfgEnumField("/mnt/flash/config/bundle.ini",local_3c,local_30);
      local_50 = local_ad4;
      if (local_ad4 != 0) {
        do {
[32m          memset(local_ad0,0,0x200);[0m
          local_48 = local_50;
          iVar2 = CfgGetField("/mnt/flash/config/bundle.ini",local_4c,local_50,1,local_ad0,0x200);
          if (iVar2 == 0) {
[32m            memset(local_44,0,0x400);[0m
            iVar2 = 0;
            for (uVar4 = 0; sVar3 = strlen(local_ad0), uVar4 < sVar3; uVar4 = uVar4 + 1) {
              cVar1 = local_ad0[uVar4];
              if (((cVar1 == '\"') || (cVar1 == '`')) || (cVar1 == '\\')) {
                local_8d0[iVar2] = '\\';
                iVar2 = iVar2 + 1;
              }
              local_8d0[iVar2] = cVar1;
              iVar2 = iVar2 + 1;
            }
[32m            fprintf(stderr,local_38,local_4c,local_48,local_ad0);[0m
[32m[32m[32m            sprintf(local_40,local_34,local_4c,local_48,local_44);[0m[0m[0m
[32m[32m            system(local_40);[0m[0m
          }
          local_50 = *(int *)(local_50 + 0x100);
        } while (local_50 != 0);
        if (local_ad4 != 0) {
          ListFree();
          local_ad4 = 0;
        }
      }
      local_3c = *(int *)(local_3c + 0x100);
    } while (local_3c != 0);
  }
  ListFree(local_ad8);
  ListFree(0);
  return 0;
}

[ASK_GPT] 40f34b5f63762d88
