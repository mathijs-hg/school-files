
undefined4 *
FUN_0041447c(undefined4 param_1,void *param_2,int param_3,uint param_4,void *param_5,
            undefined4 param_6,char *param_7,int param_8,undefined4 param_9)

{
  undefined4 *__ptr;
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined uVar4;
  undefined2 local_38 [4];
  uint local_30;
  
  uVar4 = 0;
  local_38[0] = 0;
  if (param_8 != 0) {
    uVar4 = *(undefined *)(param_8 + 0x262);
  }
  if (((param_4 & 1) == 0) || ((param_7 != (char *)0x0 && (*param_7 != '\0')))) {
    local_30 = param_4;
    __ptr = (undefined4 *)mDNSPlatformMemAllocate(0x2334);
    puVar3 = __ptr;
    if (__ptr == (undefined4 *)0x0) {
      LogMsgWithLevel(0,"ERROR: MakeTCP - memallocate failed");
    }
    else {
      mDNSPlatformMemZero(__ptr,0x2334);
      *__ptr = param_1;
      uVar1 = mDNSPlatformTCPSocket(param_1,local_30,local_38,uVar4);
      __ptr[1] = uVar1;
      __ptr[0x8c2] = param_9;
      __ptr[0x8c0] = 0;
      __ptr[0x8c1] = param_8;
[32m[32m      memcpy(__ptr + 0x8c3,param_5,0x14);[0m[0m
      *(ushort *)(__ptr + 0x8c8) = param_6._0_2_;
      __ptr[0x8c9] = 0;
      *(undefined2 *)(__ptr + 0x8ca) = 0;
      __ptr[0x8cb] = 0;
      __ptr[0x8cc] = 0;
      *(undefined2 *)((int)__ptr + 0x2322) = local_38[0];
      if (param_2 != (void *)0x0) {
        __ptr[0x8c0] = param_3 - (int)param_2;
        mDNSPlatformMemCopy(__ptr + 2,param_2,param_3 - (int)param_2);
      }
      if (__ptr[1] == 0) {
        LogMsgWithLevel(0,"MakeTCPConn: unable to create TCP socket");
        mDNSPlatformMemFree(__ptr);
        puVar3 = (undefined4 *)0x0;
      }
      else {
        uVar1 = 0;
        if (param_8 != 0) {
          uVar1 = *(undefined4 *)(param_8 + 0x134);
        }
        iVar2 = mDNSPlatformTCPConnect
                          (__ptr[1],param_5,(uint)param_6._0_2_ << 0x10,param_7,uVar1,FUN_00413aec,
                           __ptr);
        if (iVar2 == -0x100fd) {
          FUN_00413aec(__ptr[1],__ptr,1,0);
        }
        else if (iVar2 != -0x100fb) {
          if (mDNS_LoggingEnabled != 0) {
            LogMsgWithLevel(3,"MakeTCPConn: connection failed");
          }
          puVar3 = (undefined4 *)0x0;
          DisposeTCPConn(__ptr);
        }
      }
    }
  }
  else {
    LogMsgWithLevel(0,"MakeTCPConn: TLS connection being setup with NULL hostname");
    puVar3 = (undefined4 *)0x0;
  }
  return puVar3;
}

[ASK_GPT] ed3935dd8215e366
