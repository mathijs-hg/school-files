
ssize_t recvfrom_flags(int param_1,void *param_2,size_t param_3,uint *param_4,void *param_5,
                      socklen_t *param_6,undefined2 *param_7,undefined *param_8)

{
  ssize_t sVar1;
  int iVar2;
  cmsghdr *__cmsg;
  iovec local_458;
  msghdr local_450;
  cmsghdr acStack_434 [85];
  msghdr *local_30;
  cmsghdr *local_2c;
  
  local_450.msg_control = acStack_434;
  *param_8 = 0xff;
  local_450.msg_namelen = *param_6;
  local_450.msg_controllen = 0x400;
  local_450.msg_iov = &local_458;
  local_450.msg_name = param_5;
  local_450.msg_iovlen = 1;
  local_450.msg_flags = 0;
  local_458.iov_base = param_2;
  local_458.iov_len = param_3;
  sVar1 = recvmsg(param_1,&local_450,*param_4);
  if (-1 < sVar1) {
    *param_6 = local_450.msg_namelen;
    if (param_7 != (undefined2 *)0x0) {
[32m      memset(param_7,0,0x30);[0m
      *(undefined4 *)(param_7 + 0xe) = 0xffffffff;
    }
    *param_4 = local_450.msg_flags;
    if (((0xb < local_450.msg_controllen) && ((local_450.msg_flags & 8U) == 0)) &&
       (local_30 = &local_450, param_7 != (undefined2 *)0x0)) {
      for (__cmsg = (cmsghdr *)local_450.msg_control; __cmsg != (cmsghdr *)0x0;
          __cmsg = __cmsg_nxthdr(local_30,__cmsg)) {
        if (__cmsg->cmsg_level == 0) {
          iVar2 = __cmsg->cmsg_type;
          if (iVar2 == 8) {
            *param_7 = 2;
            iVar2 = __cmsg[1].cmsg_type;
            param_7[1] = 0;
            *(int *)(param_7 + 2) = iVar2;
            *(size_t *)(param_7 + 0xe) = __cmsg[1].cmsg_len;
          }
          else if (iVar2 == 0xc) {
            *param_8 = *(undefined *)&__cmsg[1].cmsg_len;
          }
          else {
            if (iVar2 != 2) goto LAB_00406fcc;
LAB_00406fc0:
            *param_8 = (char)__cmsg[1].cmsg_len;
          }
        }
        else {
          if (__cmsg->cmsg_level == 0x29) {
            if (__cmsg->cmsg_type == 2) {
              *param_7 = 10;
              local_2c = __cmsg + 1;
[32m[32m              memcpy(param_7 + 4,__cmsg + 1,0x10);[0m[0m
              *(undefined4 *)(param_7 + 2) = 0;
              *(undefined4 *)(param_7 + 0xc) = 0;
              param_7[1] = 0;
              *(int *)(param_7 + 0xe) = local_2c[1].cmsg_level;
              goto LAB_00406ff4;
            }
            if (__cmsg->cmsg_type == 8) goto LAB_00406fc0;
          }
LAB_00406fcc:
          __assert("0","mDNSUNP.c",0x296);
        }
LAB_00406ff4:
      }
    }
  }
  return sVar1;
}

[ASK_GPT] 7bfe3fb483298ee4
