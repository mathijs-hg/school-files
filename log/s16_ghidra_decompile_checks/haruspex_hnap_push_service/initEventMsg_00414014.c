
undefined4 * initEventMsg(void)

{
  undefined4 *__s;
  
[32m[32m  __s = (undefined4 *)malloc(0x10010);[0m[0m
  if (__s == (undefined4 *)0x0) {
    fprintf(stderr,"[hnap_push_service][%s] Create Event Message failed\n","initEventMsg");
  }
  else {
[32m    memset(__s,0,0x10010);[0m
    *__s = 0x8571688;
    *(undefined *)(__s + 1) = 0x81;
    *(undefined *)((int)__s + 5) = 0x10;
    *(undefined *)((int)__s + 6) = 0;
    *(undefined *)((int)__s + 7) = 0;
    net_get_hwaddr(&DAT_00414bc0,__s + 2);
    *(undefined *)((int)__s + 0xe) = 0;
    *(undefined *)((int)__s + 0xf) = 0;
  }
  return __s;
}

[ASK_GPT] 64b6a21762ff4de1
