
void FUN_00400950(void)

{
  FILE *__stream;
  undefined4 in_a3;
  undefined *puVar1;
  char local_210;
  undefined auStack_20f [255];
  undefined local_110;
  undefined auStack_10f [255];
  undefined4 local_10 [2];
  
  puVar1 = &_gp;
  local_210 = '\0';
[32m  memset(auStack_20f,0,0xff);[0m
  local_110 = 0;
[32m  memset(auStack_10f,0,0xff);[0m
  local_10[0] = 0;
  cfgRead(&DAT_00401230,"ModelNumber",&local_110,in_a3,puVar1);
  cfgRead("Bonjour",&DAT_0040124c,&local_210);
  cfgRead(&DAT_00401254,&DAT_0040125c,local_10);
[32m  __stream = fopen("/var/bonjour-http_service.txt","w");[0m
  if (__stream != (FILE *)0x0) {
    if (local_210 == '\0') {
      fprintf(__stream,"D-Link %s Configuration Utility\n",&local_110);
    }
    else {
      fprintf(__stream,"%s\n",&local_210);
    }
    fprintf(__stream,"%s\n","_http._tcp.");
    fprintf(__stream,"%d\n",local_10[0]);
    fclose(__stream);
  }
  return;
}

[ASK_GPT] e677499f972b50c6
