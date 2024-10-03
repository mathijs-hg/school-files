
void FUN_00434158(int param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = *(int *)(param_2 + 0x28c);
[32m  sVar1 = *(short *)(*(int *)(param_3 + 0x20) + 8);[0m
[32m  sVar2 = *(short *)(*(int *)(iVar7 + 0xa48) + 0x118);[0m
  if ((param_4 != 0) && (*(short *)(param_3 + 2) == 0x21)) {
    *(short *)(*(int *)(iVar7 + 0xa48) + 0x118) = sVar1;
    if (*(char *)(iVar7 + 0xa40) == '\0') {
      *(undefined *)(iVar7 + 0xa40) = 1;
      *(undefined4 *)(iVar7 + 0x654) = *(undefined4 *)(param_3 + 0x18);
      uVar4 = DomainNameLengthLimit(*(int *)(param_3 + 0x20) + 10,*(int *)(param_3 + 0x20) + 0x10a);
      if (uVar4 < 0x101) {
        mDNSPlatformMemCopy((void *)(iVar7 + 0x674),(void *)(*(int *)(param_3 + 0x20) + 10),uVar4);
      }
      else {
        *(undefined *)(iVar7 + 0x674) = 0;
      }
      *(undefined4 *)(iVar7 + 0x8e4) = *(undefined4 *)(param_3 + 0x18);
      uVar4 = DomainNameLengthLimit(*(int *)(param_3 + 0x20) + 10,*(int *)(param_3 + 0x20) + 0x10a);
      if (uVar4 < 0x101) {
        mDNSPlatformMemCopy((void *)(iVar7 + 0x904),(void *)(*(int *)(param_3 + 0x20) + 10),uVar4);
      }
      else {
        *(undefined *)(iVar7 + 0x904) = 0;
      }
      mDNS_StartQuery(param_1,iVar7 + 0x520);
      for (puVar5 = *(undefined4 **)(param_1 + 0x2174); puVar5 != (undefined4 *)0x0;
          puVar5 = (undefined4 *)*puVar5) {
        if (puVar5[0x549] == 6) goto LAB_00434418;
      }
    }
    else {
      bVar3 = sVar2 != sVar1;
      if (((*(int *)(iVar7 + 0x654) == *(int *)(iVar7 + 0x134)) ||
          (*(int *)(iVar7 + 0x654) == *(int *)(param_3 + 0x18))) &&
         (iVar6 = SameDomainName(iVar7 + 0x674,*(int *)(param_3 + 0x20) + 10), iVar6 != 0)) {
        if (((*(code **)(iVar7 + 0xa4c) != (code *)0x0) && (*(char *)(iVar7 + 0xa42) != '\0')) &&
           ((*(char *)(iVar7 + 0xa41) != '\0' && (bVar3)))) {
          *(int *)(iVar7 + 0xa44) = *(int *)(iVar7 + 0xa44) + 1;
                    /* WARNING: Could not recover jumptable at 0x00434490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (**(code **)(iVar7 + 0xa4c))(param_1,iVar7);
          return;
        }
      }
      else {
        mDNS_StopQuery(param_1,iVar7 + 0x520);
        if (-1 < *(int *)(iVar7 + 0x7c0)) {
          mDNS_StopQuery(param_1,iVar7 + 0x7b0);
        }
        iVar6 = SameDomainName(iVar7 + 0x674,*(int *)(param_3 + 0x20) + 10);
        if ((iVar6 == 0) || (bVar3)) {
          *(undefined4 *)(iVar7 + 0x654) = *(undefined4 *)(param_3 + 0x18);
          uVar4 = DomainNameLengthLimit
                            (*(int *)(param_3 + 0x20) + 10,*(int *)(param_3 + 0x20) + 0x10a);
          if (uVar4 < 0x101) {
            mDNSPlatformMemCopy((void *)(iVar7 + 0x674),(void *)(*(int *)(param_3 + 0x20) + 10),
                                uVar4);
          }
          else {
            *(undefined *)(iVar7 + 0x674) = 0;
          }
          *(undefined4 *)(iVar7 + 0x8e4) = *(undefined4 *)(param_3 + 0x18);
          uVar4 = DomainNameLengthLimit
                            (*(int *)(param_3 + 0x20) + 10,*(int *)(param_3 + 0x20) + 0x10a);
          if (uVar4 < 0x101) {
            mDNSPlatformMemCopy((void *)(iVar7 + 0x904),(void *)(*(int *)(param_3 + 0x20) + 10),
                                uVar4);
          }
          else {
            *(undefined *)(iVar7 + 0x904) = 0;
          }
        }
        else {
          *(undefined4 *)(iVar7 + 0x8e4) = *(undefined4 *)(iVar7 + 0x134);
          *(undefined4 *)(iVar7 + 0x654) = *(undefined4 *)(iVar7 + 0x134);
        }
        mDNS_StartQuery(param_1,iVar7 + 0x520);
        for (puVar5 = *(undefined4 **)(param_1 + 0x2174); puVar5 != (undefined4 *)0x0;
            puVar5 = (undefined4 *)*puVar5) {
          if (puVar5[0x549] == 6) {
LAB_00434418:
            mDNS_StartQuery(param_1,iVar7 + 0x7b0);
            return;
          }
        }
      }
    }
  }
  return;
}

[ASK_GPT] ac80d5690c2fc89d
