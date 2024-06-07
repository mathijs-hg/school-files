
int legacy_get_dev_info1(int mtd_num,mtd_dev_info *mtd)

{
  int iVar1;
  undefined4 in_a3;
  char node [31];
  
[32m  sprintf(node,"/dev/mtd%d",mtd_num,in_a3,&_gp);[0m
  iVar1 = legacy_get_dev_info(node,mtd);
  return iVar1;
}

[ASK_GPT] a283ba01f13720a4
