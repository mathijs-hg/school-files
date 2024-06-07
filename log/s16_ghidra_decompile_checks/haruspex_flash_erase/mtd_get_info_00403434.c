
int mtd_get_info(libmtd_t desc,mtd_info *info)

{
  int iVar1;
  
[32m  memset(info,0,0x10);[0m
  if ((*(uint *)((int)desc + 0x30) & 1) != 0) {
    iVar1 = mtd_get_info(desc,info);
    return iVar1;
  }
  iVar1 = legacy_mtd_get_info(info);
  return iVar1;
}

[ASK_GPT] 7bc31326c341d521
