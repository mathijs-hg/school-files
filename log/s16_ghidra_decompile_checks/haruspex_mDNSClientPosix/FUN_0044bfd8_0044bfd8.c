
void FUN_0044bfd8(undefined4 param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  size_t sVar6;
  int iVar7;
  uint __n;
  char local_220;
  undefined auStack_21f [3];
  char local_21c [252];
  char local_120;
  undefined auStack_11f [259];
  
  if ((param_2 != 0) && (*(int *)(*(int *)(param_2 + 0xa48) + 0x104) == 4)) {
    local_220 = '\0';
[32m    memset(auStack_21f,0,0xff);[0m
    iVar4 = *(int *)(param_2 + 0xa48);
    iVar7 = 0;
    fprintf(stderr,"IPaddr: %d.%d.%d.%d\n",(uint)*(byte *)(iVar4 + 0x108),
            (uint)*(byte *)(iVar4 + 0x109),(uint)*(byte *)(iVar4 + 0x10a),
            (uint)*(byte *)(iVar4 + 0x10b));
    fprintf(stderr,"Port: %d\n",(uint)*(ushort *)(*(int *)(param_2 + 0xa48) + 0x118));
    do {
      __n = (uint)*(byte *)(*(int *)(param_2 + 0xa48) + iVar7 + 0x11c);
[32m      memset(&local_220,0,0x100);[0m
      iVar4 = *(int *)(param_2 + 0xa48) + iVar7;
      iVar7 = iVar7 + __n + 1;
[32m[32m      strncpy(&local_220,(char *)(iVar4 + 0x11d),__n);[0m[0m
      pcVar5 = strstr(&local_220,"mac=");
      if (pcVar5 != (char *)0x0) {
        pcVar5 = local_21c;
        fprintf(stderr,"Mac Address is %s\n",pcVar5);
        if (DAT_0046e830 != (FILE *)0x0) {
          local_120 = '\0';
[32m          memset(auStack_11f,0,0xff);[0m
          sVar6 = strlen(pcVar5);
          iVar4 = 0;
          while (bVar3 = iVar4 < (int)sVar6, iVar4 = iVar4 + 1, bVar3) {
            *pcVar5 = (char)*(undefined2 *)(__ctype_toupper + *pcVar5 * 2);
            pcVar5 = pcVar5 + 1;
          }
          iVar4 = *(int *)(param_2 + 0xa48);
          if (DAT_0046e83c == 0) {
            uVar2 = *(ushort *)(iVar4 + 0x118);
            bVar1 = *(byte *)(iVar4 + 0x108);
            pcVar5 = "<device>\n<mac>%s</mac>\n<ip>%d.%d.%d.%d</ip>\n<port>%d</port>\n</device>\n";
          }
          else {
            uVar2 = *(ushort *)(iVar4 + 0x118);
            pcVar5 = "[%s]\nip=%d.%d.%d.%d\nport=%d\n\n";
            bVar1 = *(byte *)(iVar4 + 0x108);
          }
          sprintf(&local_120,pcVar5,local_21c,(uint)bVar1,(uint)*(byte *)(iVar4 + 0x109),
[32m[32m                  (uint)*(byte *)(iVar4 + 0x10a),(uint)*(byte *)(iVar4 + 0x10b),(uint)uVar2);[0m[0m
          sVar6 = strlen(&local_120);
          fwrite(&local_120,1,sVar6,DAT_0046e830);
        }
        break;
      }
    } while (iVar7 <= (int)(*(ushort *)(*(int *)(param_2 + 0xa48) + 0x11a) - 1));
  }
  mDNS_StopResolveService(param_1,param_2);
  return;
}

[ASK_GPT] 5b3ce910b4ce7bb4
