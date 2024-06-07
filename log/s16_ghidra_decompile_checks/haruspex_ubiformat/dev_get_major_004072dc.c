
int dev_get_major(libmtd *lib,int mtd_num,int *major,int *minor)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  char *file;
  char *__s;
  code *pcVar6;
  int iStack_68;
  char *pcStack_64;
  undefined *local_60;
  char buf [50];
  
  __s = lib->mtd_dev;
  local_60 = &_gp;
  sVar2 = strlen(__s);
[32m  iVar1 = -(sVar2 + 0x40 & 0xfffffff8);[0m
  file = (char *)((int)&local_60 + iVar1);
  (**(code **)(local_60 + -0x7ee4))(file,__s,mtd_num);
  iVar3 = read_data(file,buf,0x32);
  if (-1 < iVar3) {
    iVar3 = (**(code **)(local_60 + -0x7ebc))(buf,"%d:%d\n",major,minor);
    if (iVar3 == 2) {
      if ((*major < 0) || (iVar3 = 0, *minor < 0)) {
        puVar4 = (undefined4 *)(**(code **)(local_60 + -0x7ef0))();
        *puVar4 = 0x16;
        iVar3 = *major;
        pcVar6 = *(code **)(local_60 + -0x7e90);
        uVar5 = **(undefined4 **)(local_60 + -0x7ee8);
        *(int *)((int)&iStack_68 + iVar1) = *minor;
        *(char **)((int)&pcStack_64 + iVar1) = file;
        (*pcVar6)(uVar5,"%s: error!: bad major:minor %d:%d in \"%s\"\n","libmtd",iVar3);
        iVar3 = -1;
      }
    }
    else {
      puVar4 = (undefined4 *)(**(code **)(local_60 + -0x7ef0))();
      pcVar6 = *(code **)(local_60 + -0x7e90);
      uVar5 = **(undefined4 **)(local_60 + -0x7ee8);
      *puVar4 = 0x16;
      (*pcVar6)(uVar5,"%s: error!: \"%s\" does not have major:minor format\n","libmtd",file);
      iVar3 = -1;
    }
  }
  return iVar3;
}

[ASK_GPT] 65de28aa204c848b
