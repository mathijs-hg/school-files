
int mtd_dev_present(libmtd_t desc,int mtd_num)

{
  size_t sVar1;
  int iVar2;
  char *__s;
  undefined *local_c0;
  stat st;
  
  local_c0 = &_gp;
  if ((*(uint *)((int)desc + 0x30) & 1) != 0) {
    __s = *(char **)((int)desc + 4);
    sVar1 = strlen(__s);
[32m    iVar2 = (int)&local_c0 - (sVar1 + 0x18 & 0xfffffff8);[0m
    (**(code **)(local_c0 + -0x7f70))(iVar2,__s,mtd_num);
    iVar2 = (**(code **)(local_c0 + -0x7f10))(iVar2,&st);
    return (uint)(iVar2 == 0);
  }
  iVar2 = legacy_dev_present(mtd_num);
  return (uint)(iVar2 == 1);
}

[ASK_GPT] 1e80953a3436c8a0
