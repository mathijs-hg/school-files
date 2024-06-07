
int dev_read_hex_int(char *patt,int mtd_num,int *value)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int iVar10;
  code *pcVar11;
  uint auStack_70 [4];
  undefined *local_60;
  uint local_58;
  int local_54;
  char buf [50];
  
  local_60 = &_gp;
  sVar2 = strlen(patt);
[32m  iVar1 = -(sVar2 + 0x40 & 0xfffffff8);[0m
  iVar10 = (int)&local_60 + iVar1;
  (**(code **)(local_60 + -0x7f70))(iVar10,patt,mtd_num);
  iVar3 = (**(code **)(local_60 + -0x7f64))(iVar10,0x80000);
  if (iVar3 != -1) {
    iVar4 = (**(code **)(local_60 + -0x7f48))(iVar3,buf,0x32);
    if (iVar4 == -1) {
      puVar8 = *(undefined4 **)(local_60 + -0x7f74);
      puVar5 = (undefined4 *)(**(code **)(local_60 + -0x7f78))();
      uVar7 = *puVar5;
      (**(code **)(local_60 + -0x7f38))(*puVar8,"%s: error!: cannot read \"%s\"\n","libmtd",iVar10);
      uVar9 = *puVar8;
      uVar6 = (**(code **)(local_60 + -0x7f0c))(uVar7);
      pcVar11 = *(code **)(local_60 + -0x7f38);
      *(undefined4 *)((int)auStack_70 + iVar1) = uVar7;
      *(undefined4 *)((int)auStack_70 + iVar1 + 4) = uVar6;
      (*pcVar11)(uVar9,"%*serror %d (%s)\n",8,"");
    }
    else {
      if (iVar4 == 0x32) {
        (**(code **)(local_60 + -0x7f38))
                  (**(undefined4 **)(local_60 + -0x7f74),
                   "%s: error!: contents of \"%s\" is too long\n","libmtd",iVar10);
      }
      else {
        pcVar11 = *(code **)(local_60 + -0x7f54);
        buf[iVar4] = '\0';
        iVar4 = (*pcVar11)(buf,"%llx\n",&local_58);
        if (iVar4 == 1) {
          if (-1 < local_54) {
            iVar3 = (**(code **)(local_60 + -0x7f94))(iVar3);
            if (iVar3 != 0) {
              puVar8 = *(undefined4 **)(local_60 + -0x7f74);
              puVar5 = (undefined4 *)(**(code **)(local_60 + -0x7f78))();
              uVar7 = *puVar5;
              (**(code **)(local_60 + -0x7f38))
                        (*puVar8,"%s: error!: close failed on \"%s\"\n","libmtd",iVar10);
              uVar9 = *puVar8;
              uVar6 = (**(code **)(local_60 + -0x7f0c))(uVar7);
              pcVar11 = *(code **)(local_60 + -0x7f38);
              *(undefined4 *)((int)auStack_70 + iVar1) = uVar7;
              *(undefined4 *)((int)auStack_70 + iVar1 + 4) = uVar6;
              (*pcVar11)(uVar9,"%*serror %d (%s)\n",8,"");
              return -1;
            }
            if ((uint)(local_58 + 0x80000000 < local_58) + local_54 == 0) {
              *value = local_58;
              return 0;
            }
            pcVar11 = *(code **)(local_60 + -0x7f38);
            uVar6 = **(undefined4 **)(local_60 + -0x7f74);
            *(uint *)((int)auStack_70 + iVar1) = local_58;
            *(int *)((int)auStack_70 + iVar1 + 4) = local_54;
            *(int *)((int)auStack_70 + iVar1 + 8) = iVar10;
            (*pcVar11)(uVar6,"%s: error!: value %lld read from file \"%s\" is out of range\n",
                       "libmtd");
            puVar5 = (undefined4 *)(**(code **)(local_60 + -0x7f78))();
            *puVar5 = 0x16;
            return -1;
          }
          pcVar11 = *(code **)(local_60 + -0x7f38);
          uVar6 = **(undefined4 **)(local_60 + -0x7f74);
          *(uint *)((int)auStack_70 + iVar1) = local_58;
          *(int *)((int)auStack_70 + iVar1 + 4) = local_54;
          *(int *)((int)auStack_70 + iVar1 + 8) = iVar10;
          (*pcVar11)(uVar6,"%s: error!: negative value %lld in \"%s\"\n","libmtd");
        }
        else {
          (**(code **)(local_60 + -0x7f38))
                    (**(undefined4 **)(local_60 + -0x7f74),
                     "%s: error!: cannot read integer from \"%s\"\n\n","libmtd",iVar10);
        }
      }
      puVar5 = (undefined4 *)(**(code **)(local_60 + -0x7f78))();
      *puVar5 = 0x16;
    }
    (**(code **)(local_60 + -0x7f94))(iVar3);
  }
  return -1;
}

[ASK_GPT] c6b326b1333f01af
