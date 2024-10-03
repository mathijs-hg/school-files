
char * FUN_00409394(char *param_1,char *param_2,char *param_3,char *param_4)

{
  FILE *__stream;
  size_t sVar1;
  undefined *puVar2;
  int iVar3;
  char *pcVar4;
  char *local_resc;
  
[32m  __stream = fopen(param_1,"rt");[0m
  local_resc = param_4;
  if (__stream != (FILE *)0x0) {
    do {
      do {
        while( true ) {
[32m          pcVar4 = fgets(&DAT_0041c9f0,0x200,__stream);[0m
          local_resc = param_4;
          if (pcVar4 == (char *)0x0) goto LAB_0040954c;
          sVar1 = strlen(&DAT_0041c9f0);
          puVar2 = (undefined *)FUN_00408a60(&DAT_0041c9f0,&DAT_0041c9f0 + sVar1,&LAB_004089e0);
          *puVar2 = 0;
          pcVar4 = (char *)FUN_004089fc(&DAT_0041c9f0,&LAB_004089c4);
          if (*pcVar4 != '[') break;
          if (param_2 == (char *)0x0) goto LAB_0040954c;
          pcVar4 = (char *)FUN_0040913c(pcVar4,0x5b,0x5d);
          iVar3 = strcmp(pcVar4,param_2);
          if (iVar3 == 0) {
            param_2 = (char *)0x0;
          }
        }
      } while ((*pcVar4 == ';') || ((param_2 != (char *)0x0 && (*param_2 != '\0'))));
      local_resc = (char *)FUN_00408be0(pcVar4,0x3d);
      sVar1 = strlen(pcVar4);
      puVar2 = (undefined *)FUN_00408a60(pcVar4,pcVar4 + sVar1,&LAB_004089c4);
      *puVar2 = 0;
      iVar3 = strcmp(param_3,pcVar4);
    } while (iVar3 != 0);
    sVar1 = strlen(local_resc);
    puVar2 = (undefined *)FUN_00408a60(local_resc,local_resc + sVar1,&LAB_004089c4);
    *puVar2 = 0;
LAB_0040954c:
    fclose(__stream);
  }
  return local_resc;
}

[ASK_GPT] d509493f1e559720
