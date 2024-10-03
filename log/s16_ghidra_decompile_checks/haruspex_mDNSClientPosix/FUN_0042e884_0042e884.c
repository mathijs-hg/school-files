
void FUN_0042e884(int param_1,int *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int local_48;
  int *local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  local_44 = &local_48;
  local_48 = 0;
  for (puVar8 = *(undefined4 **)(param_1 + 0x2174);
      (puVar8 != (undefined4 *)0x0 && (puVar8[0x548] != param_3)); puVar8 = (undefined4 *)*puVar8) {
  }
  local_3c = param_1 + 0x2f;
  puVar7 = *(undefined4 **)(param_1 + 0x2160);
  do {
    local_38 = param_1 + 0x5cbc;
    if (puVar7 == (undefined4 *)0x0) {
      iVar9 = param_1 + 0x5cb0;
      FUN_0042a238(param_1,local_48,&local_44,param_3);
      local_2c = param_1 + 0x5cb6;
      local_30 = param_1 + 0x5cb8;
      local_34 = param_1 + 0x5cba;
      local_40 = 0;
      do {
        iVar5 = local_38;
        if (local_48 == 0) {
          return;
        }
        InitializeDNSMessage(iVar9,0,0x84000000);
        while ((iVar2 = local_48, local_48 != 0 && (*(int *)(local_48 + 0xb4) != 0))) {
          iVar4 = *(int *)(local_48 + 0x2c);
          if (iVar4 != 0) {
            uVar1 = *(ushort *)(*(int *)(iVar4 + 0xc) + 0xc);
            *(undefined4 *)(iVar4 + 0x10) = 0xffffffff;
            local_40 = local_40 + uVar1 + 0xc;
          }
          if ((*(byte *)(local_48 + 4) & 0x32) != 0) {
            *(ushort *)(local_48 + 8) = *(ushort *)(local_48 + 8) | 0x8000;
          }
          iVar4 = 0x5a0;
          if ((*(short *)(param_1 + 0x5cb6) == 0) &&
             (iVar4 = 0x22ec, *(int *)(param_1 + 0x5cb8) != 0)) {
            iVar4 = 0x5a0;
          }
          iVar4 = PutResourceRecordTTLWithLimit
                            (iVar9,iVar5,local_2c,local_48 + 4,*(undefined4 *)(local_48 + 0xc),
                             param_1 + (iVar4 - local_40) + 0x5cbc);
          *(ushort *)(iVar2 + 8) = *(ushort *)(iVar2 + 8) & 0x7fff;
          if ((iVar4 == 0) && (iVar4 = iVar5, *(short *)(param_1 + 0x5cb6) != 0)) break;
          local_48 = *(int *)(iVar2 + 0xb0);
          *(undefined *)(iVar2 + 0x88) = 1;
          *(undefined4 *)(iVar2 + 0xb0) = 0;
          *(undefined4 *)(iVar2 + 0xb4) = 0;
          *(undefined4 *)(iVar2 + 0xb8) = 0;
          iVar5 = iVar4;
        }
        for (puVar7 = *(undefined4 **)(param_1 + 0x2160); puVar7 != (undefined4 *)0x0;
            puVar7 = (undefined4 *)*puVar7) {
          iVar4 = puVar7[0xb];
          iVar2 = iVar5;
          if ((iVar4 != 0) && (*(int *)(iVar4 + 0x10) == -1)) {
            iVar4 = *(int *)(iVar4 + 0xc);
            iVar2 = 0x5a0;
            if ((*(short *)(param_1 + 0x5cb6) == 0) &&
               (iVar2 = 0x22ec, *(int *)(param_1 + 0x5cb8) != 0)) {
              iVar2 = 0x5a0;
            }
            iVar2 = PutResourceRecordTTLWithLimit
                              (iVar9,iVar5,local_30,iVar4,*(undefined4 *)(iVar4 + 8),
                               param_1 + iVar2 + 0x5cbc);
            if (iVar2 == 0) {
              uVar3 = GetRRDisplayString_rdb(iVar4,*(int *)(iVar4 + 0x20) + 4,local_3c);
              LogMsgWithLevel(0,
                              "SendDelayedUnicastResponse: ERROR!! Cannot Add NSEC3 Record %s on %p"
                              ,uVar3,puVar8[0x548]);
              iVar2 = iVar5;
            }
            *(undefined4 *)(puVar7[0xb] + 0x10) = 0;
          }
          iVar5 = iVar2;
        }
        while ((iVar2 = local_48, local_48 != 0 && (*(int *)(local_48 + 0xb4) == 0))) {
          if ((*(byte *)(local_48 + 4) & 0x32) != 0) {
            *(ushort *)(local_48 + 8) = *(ushort *)(local_48 + 8) | 0x8000;
          }
          iVar4 = 0x5a0;
          if ((*(short *)(param_1 + 0x5cb6) == 0) &&
             (iVar4 = 0x22ec, *(int *)(param_1 + 0x5cb8) != 0)) {
            iVar4 = 0x5a0;
          }
          iVar4 = PutResourceRecordTTLWithLimit
                            (iVar9,iVar5,local_34,local_48 + 4,*(undefined4 *)(local_48 + 0xc),
                             param_1 + iVar4 + 0x5cbc);
          *(ushort *)(iVar2 + 8) = *(ushort *)(iVar2 + 8) & 0x7fff;
          if ((iVar4 == 0) || (iVar5 = iVar4, *(short *)(param_1 + 0x5cb6) == 0)) {
            iVar4 = iVar5;
            if ((*(byte *)(iVar2 + 4) & 0x32) != 0) {
              *(undefined4 *)(iVar2 + 0x90) = 0xffffffff;
            }
          }
          else {
            *(undefined *)(iVar2 + 0x88) = 1;
          }
          local_48 = *(int *)(iVar2 + 0xb0);
          *(undefined4 *)(iVar2 + 0xb8) = 0;
          *(undefined4 *)(iVar2 + 0xb0) = 0;
          *(undefined4 *)(iVar2 + 0xb4) = 0;
          iVar5 = iVar4;
        }
        if (*(short *)(param_1 + 0x5cb6) != 0) {
          mDNSSendDNSMessage(param_1,iVar9,iVar5,param_3,0,param_2);
        }
      } while( true );
    }
    if (((puVar7[0x24] == -1) || (puVar7[0x27] == -1)) ||
       ((puVar7[0x28] == -1 &&
        (((puVar7[0x29] == -1 && (puVar7[0x2a] == -1)) && (puVar7[0x2b] == -1)))))) {
      *(undefined *)((int)puVar7 + 0x8b) = 0;
    }
    if ((*(char *)((int)puVar7 + 0x8b) != '\0') && (puVar7[0x24] == param_3)) {
      if (*param_2 == 4) {
        iVar5 = puVar7[0x27];
        iVar9 = param_2[1];
      }
      else {
        if (((*param_2 != 6) || (puVar7[0x28] != param_2[1])) ||
           ((puVar7[0x29] != param_2[2] || (puVar7[0x2a] != param_2[3])))) goto LAB_0042eadc;
        iVar5 = puVar7[0x2b];
        iVar9 = param_2[4];
      }
      if (iVar5 == iVar9) {
        puVar7[0x27] = 0;
        puVar7[0x24] = 0;
        *(undefined *)((int)puVar7 + 0x8b) = 0;
[32m[32m        memcpy(puVar7 + 0x28,zerov6Addr,0x10);[0m[0m
        if ((puVar8 == (undefined4 *)0x0) ||
           (iVar9 = mDNSPlatformValidRecordForInterface(puVar7,puVar8), iVar9 != 0)) {
          if ((puVar7[0x2c] == 0) && (local_44 != puVar7 + 0x2c)) {
            puVar7[0x2d] = 0xffffffff;
            *local_44 = (int)puVar7;
            local_44 = puVar7 + 0x2c;
          }
        }
        else if (mDNS_LoggingEnabled != 0) {
          uVar3 = GetRRDisplayString_rdb(puVar7 + 1,puVar7[9] + 4,local_3c);
          for (puVar6 = *(undefined4 **)(param_1 + 0x2174); puVar6 != (undefined4 *)0x0;
              puVar6 = (undefined4 *)*puVar6) {
            if (puVar6[0x548] == param_3) {
              iVar9 = (int)puVar6 + 0x1552;
              goto LAB_0042ea90;
            }
          }
          iVar9 = 0;
LAB_0042ea90:
          LogMsgWithLevel(3,"SendDelayedUnicastResponse: Not sending %s, on %s",uVar3,iVar9);
        }
      }
    }
LAB_0042eadc:
    puVar7 = (undefined4 *)*puVar7;
  } while( true );
}

[ASK_GPT] 6d7abb91ff7fdaf3
