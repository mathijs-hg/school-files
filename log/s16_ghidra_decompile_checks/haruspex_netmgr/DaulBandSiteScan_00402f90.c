
void DaulBandSiteScan(void)

{
  char *__src;
  int iVar1;
  
[32m[32m  __src = (char *)malloc(0x5554);[0m[0m
  if (__src == (char *)0x0) {
    fwrite("\n=== malloc szBuf fail===\n",1,0x1a,stderr);
  }
  else {
[32m    memset(__src,0,0x5554);[0m
    iVar1 = SiteSurvey("wlan0",__src,0x5554);
    if (iVar1 == 0) {
      iVar1 = SiteListLockAttach();
      if (iVar1 == 0) {
        free(__src);
        return;
      }
[32m[32m      strcpy((char *)(iVar1 + 8),__src);[0m[0m
      *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
      SiteListUnlockDetach(iVar1);
    }
    free(__src);
  }
  return;
}

[ASK_GPT] 148505fbf9a7d31d
