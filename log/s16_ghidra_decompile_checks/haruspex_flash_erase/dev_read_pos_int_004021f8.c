
/* WARNING: Could not reconcile some variable overlaps */

int dev_read_pos_int(char *patt,int mtd_num,int *value)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  char *file;
  code *pcVar7;
  uint auStack_38 [2];
  char *apcStack_30 [2];
  undefined *local_28;
  longlong res;
  
  local_28 = &_gp;
  sVar2 = strlen(patt);
[32m  iVar1 = -(sVar2 + 0x40 & 0xfffffff8);[0m
  file = (char *)((int)&local_28 + iVar1);
  (**(code **)(local_28 + -0x7f70))(file,patt,mtd_num);
  iVar3 = read_pos_ll(file,&res);
  iVar5 = -1;
  if (iVar3 == 0) {
    if ((res._4_4_ < 1) && ((res._4_4_ != 0 || ((uint)res < 0x80000000)))) {
      *value = (uint)res;
      iVar5 = 0;
    }
    else {
      pcVar7 = *(code **)(local_28 + -0x7f38);
      uVar6 = **(undefined4 **)(local_28 + -0x7f74);
      *(uint *)((int)auStack_38 + iVar1) = (uint)res;
      *(int *)((int)auStack_38 + iVar1 + 4) = res._4_4_;
      *(char **)((int)apcStack_30 + iVar1) = file;
      (*pcVar7)(uVar6,"%s: error!: value %lld read from file \"%s\" is out of range\n","libmtd");
      puVar4 = (undefined4 *)(**(code **)(local_28 + -0x7f78))();
      *puVar4 = 0x16;
      iVar5 = -1;
    }
  }
  return iVar5;
}

[ASK_GPT] 4cae3acfe5caee07
