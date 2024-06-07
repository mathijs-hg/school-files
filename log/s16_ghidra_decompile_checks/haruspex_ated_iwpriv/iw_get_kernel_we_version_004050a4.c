
undefined4 iw_get_kernel_we_version(void)

{
  FILE *__stream;
  char *pcVar1;
  int iVar2;
  char acStack_410 [1024];
  undefined4 local_10 [2];
  
[32m  __stream = fopen("/proc/net/wireless","r");[0m
  if (__stream == (FILE *)0x0) {
    fwrite("Cannot read /proc/net/wireless\n",1,0x1f,stderr);
    local_10[0] = 0xffffffff;
  }
  else {
[32m    fgets(acStack_410,0x400,__stream);[0m
    pcVar1 = strstr(acStack_410,"| WE");
    if (pcVar1 == (char *)0x0) {
      pcVar1 = strstr(acStack_410,"| Missed");
      if (pcVar1 == (char *)0x0) {
        local_10[0] = 0xb;
      }
      else {
        local_10[0] = 0xf;
      }
      fclose(__stream);
    }
    else {
[32m      fgets(acStack_410,0x400,__stream);[0m
      pcVar1 = strrchr(acStack_410,0x7c);
[32m      if ((pcVar1 != (char *)0x0) && (iVar2 = sscanf(pcVar1 + 1,"%d",local_10), iVar2 == 1)) {[0m
        fclose(__stream);
        return local_10[0];
      }
      fwrite("Cannot parse /proc/net/wireless\n",1,0x20,stderr);
      fclose(__stream);
      local_10[0] = 0xffffffff;
    }
  }
  return local_10[0];
}

[ASK_GPT] 082a028e69619dc5
