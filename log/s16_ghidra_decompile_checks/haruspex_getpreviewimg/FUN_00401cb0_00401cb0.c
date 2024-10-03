
undefined4 FUN_00401cb0(char *param_1,char *param_2)

{
  uint *puVar1;
  void **__ptr;
  void *pvVar2;
  int *piVar3;
  undefined **ppuVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  void *__src;
  undefined *puVar13;
  size_t __n;
  undefined4 local_500 [11];
  undefined4 local_4d4;
  undefined4 local_4bc;
  undefined4 local_4b4;
  uint local_490;
  undefined **local_48c;
  int local_3c8;
  int local_330;
  code **local_32c;
  undefined4 local_314;
  uint local_310;
  undefined4 local_30c;
  undefined4 local_308;
  undefined4 local_2f0;
  int local_2ec;
  undefined4 local_280;
  uint local_250;
  int local_244;
  undefined auStack_1b8 [132];
  undefined auStack_134 [132];
  undefined *local_b0;
  int *local_ac;
  int *local_a8;
  int local_a4 [9];
  void *local_80;
  void *local_7c;
  void *local_78;
  uint local_70;
  undefined **local_6c;
  int *local_68;
  int *local_64;
  undefined **local_60;
  FILE *local_5c;
  uint *local_58;
  int local_54;
  undefined *local_50;
  int *local_4c;
  void *local_48;
  int *local_44;
  void *local_40;
  void **local_3c;
  uint *local_38;
  FILE *local_34;
  void *local_30;
  undefined4 *local_2c;
  
[32m  local_34 = fopen(param_1,"rb");[0m
  if (local_34 == (FILE *)0x0) {
    printf("getpreviewing: Error opening jpeg file %s\n!",param_1);
  }
  else {
    local_500[0] = jpeg_std_error(auStack_1b8);
    jpeg_CreateDecompress(local_500,0x3e,0x1d0);
    jpeg_stdio_src(local_500,local_34);
    jpeg_read_header(local_500,1);
    local_4d4 = 3;
    local_4bc = 1;
    local_4b4 = 0;
    jpeg_start_decompress(local_500);
    local_6c = (undefined **)(local_3c8 << 3);
[32m    puVar1 = (uint *)malloc((int)local_48c << 2);[0m
    local_38 = puVar1;
[32m    __ptr = (void **)malloc(local_490 << 2);[0m
[32m[32m[32m    pvVar2 = malloc(0x500);[0m[0m[0m
[32m[32m[32m    piVar3 = (int *)malloc(0x500);[0m[0m[0m
    local_60 = local_6c;
[32m[32m[32m    local_30 = malloc(local_490 * 3 * (int)local_6c);[0m[0m[0m
    local_54 = local_3c8 * 0x20;
[32m[32m[32m    local_48 = malloc((int)local_6c * 0x10 + local_3c8 * -0x20);[0m[0m[0m
[32m[32m[32m    local_50 = (undefined *)malloc(0x38400);[0m[0m[0m
    local_80 = local_48;
    local_7c = (void *)((int)local_48 + local_54);
    local_78 = (void *)((int)local_48 + local_3c8 * 0x40);
    if (0 < (int)local_6c) {
      iVar8 = (int)local_60 << 1;
      ppuVar4 = (undefined **)0x0;
      do {
        iVar6 = (int)ppuVar4 * 4;
        *(void **)((int)local_48 + iVar6) = (void *)((int)local_30 + (int)ppuVar4 * local_490);
        *(void **)((int)local_7c + iVar6) =
             (void *)((int)local_30 + ((int)ppuVar4 + (int)local_60) * local_490);
        *(void **)((int)local_78 + iVar6) = (void *)((int)local_30 + iVar8 * local_490);
        ppuVar4 = (undefined **)((int)ppuVar4 + 1);
        iVar8 = iVar8 + 1;
      } while (ppuVar4 != local_6c);
    }
    *__ptr = (void *)0x0;
    *local_38 = 0;
    uVar7 = 0xf0;
    if ((undefined **)0x1 < local_48c) {
      ppuVar4 = (undefined **)0x1;
      do {
        if (local_48c == (undefined **)0x0) {
          trap(0x1c00);
        }
        if (local_38[(int)ppuVar4 - 1] == uVar7 / (uint)local_48c) {
          local_38[(int)ppuVar4 - 1] = 0xffffffff;
        }
        local_38[(int)ppuVar4] = uVar7 / (uint)local_48c;
        ppuVar4 = (undefined **)((int)ppuVar4 + 1);
        uVar7 = uVar7 + 0xf0;
      } while (ppuVar4 < local_48c);
    }
    uVar7 = 0x140;
    if (1 < local_490) {
      uVar9 = 1;
      do {
        if (local_490 == 0) {
          trap(0x1c00);
        }
        if (__ptr[uVar9 - 1] == (void *)(uVar7 / local_490)) {
          __ptr[uVar9 - 1] = (void *)0xffffffff;
        }
        __ptr[uVar9] = (void *)(uVar7 / local_490);
        uVar9 = uVar9 + 1;
        uVar7 = uVar7 + 0x140;
      } while (uVar9 < local_490);
    }
    local_44 = (int *)(local_50 + 0x12c00);
    local_4c = (int *)(local_50 + 96000);
[32m    memset(pvVar2,0,0x500);[0m
[32m    memset(piVar3,0,0x500);[0m
    if (local_48c != (undefined **)0x0) {
      local_5c = (FILE *)local_60;
      local_68 = local_4c;
      local_64 = local_44;
      local_3c = &local_80;
      local_2c = local_500;
      local_70 = 0;
      puVar13 = local_50;
      ppuVar4 = (undefined **)local_5c;
      local_58 = puVar1;
      do {
        local_5c = (FILE *)ppuVar4;
        jpeg_read_raw_data(local_2c,local_3c,local_60);
        if (0 < (int)local_6c) {
          iVar8 = 0;
          puVar1 = local_58;
          do {
            if (-1 < (int)*puVar1) {
              if (local_490 != 0) {
                iVar6 = (iVar8 / 2) * 4;
                uVar7 = local_70;
                do {
                  if (-1 < (int)__ptr[uVar7]) {
                    *puVar13 = *(undefined *)(*(int *)((int)local_80 + iVar8 * 4) + uVar7);
                    puVar13 = puVar13 + 1;
                    iVar10 = (int)__ptr[uVar7] / 2;
                    piVar11 = (int *)((int)pvVar2 + iVar10 * 4);
                    *piVar11 = *piVar11 +
                               (uint)*(byte *)(*(int *)((int)local_7c + iVar6) + (int)uVar7 / 2);
                    piVar3[iVar10] =
                         piVar3[iVar10] +
                         (uint)*(byte *)(*(int *)((int)local_78 + iVar6) + (int)uVar7 / 2);
                  }
                  uVar7 = uVar7 + 1;
                } while (uVar7 < local_490);
              }
              uVar7 = local_70;
              piVar11 = local_64;
              piVar12 = local_68;
              if ((*puVar1 & 1) != 0) {
                do {
                  iVar6 = *(int *)((int)pvVar2 + uVar7);
                  if (iVar6 < 0) {
                    iVar6 = iVar6 + 3;
                  }
                  *(char *)piVar11 = (char)(iVar6 >> 2);
                  iVar6 = *(int *)((int)piVar3 + uVar7);
                  if (iVar6 < 0) {
                    iVar6 = iVar6 + 3;
                  }
                  *(char *)piVar12 = (char)(iVar6 >> 2);
                  uVar7 = uVar7 + 4;
                  piVar11 = (int *)((int)piVar11 + 1);
                  piVar12 = (int *)((int)piVar12 + 1);
                } while (uVar7 != 0x280);
                local_64 = local_64 + 0x28;
                local_68 = local_68 + 0x28;
[32m                memset(pvVar2,local_70,0x500);[0m
[32m                memset(piVar3,local_70,0x500);[0m
              }
            }
            iVar8 = iVar8 + 1;
            puVar1 = puVar1 + 1;
          } while (iVar8 < (int)local_6c);
        }
        local_58 = (uint *)((int)local_58 + local_54);
        ppuVar4 = (undefined **)((int)local_60 + (int)local_5c);
      } while (local_5c < local_48c);
    }
    local_330 = jpeg_std_error(auStack_134);
    jpeg_CreateCompress(&local_330,0x3e,0x178);
[32m    local_5c = fopen(param_2,"wb");[0m
    if (local_5c != (FILE *)0x0) {
      jpeg_stdio_dest(&local_330,local_5c);
      local_314 = 0x140;
      local_310 = 0xf0;
      local_30c = 3;
      local_308 = 2;
      jpeg_set_defaults(&local_330);
      jpeg_set_quality(&local_330,0x3c,1);
      local_280 = 1;
      local_2f0 = 3;
      *(undefined4 *)(local_2ec + 8) = 2;
      *(undefined4 *)(local_2ec + 0xc) = 2;
      jpeg_start_compress(&local_330,1);
      local_70 = (**local_32c)(&local_330,1,0xc);
      iVar8 = 0;
      iVar6 = 0;
      local_54 = local_70;
      do {
        *(int *)((int)local_a4 + iVar8) = *(int *)(local_2ec + iVar6 + 0x1c) << 3;
        *(int *)((int)local_a4 + iVar8 + 0xc) = *(int *)(local_2ec + iVar6 + 0xc) << 3;
        uVar5 = (*local_32c[2])(&local_330,1);
        *(undefined4 *)(local_70 + iVar8) = uVar5;
        iVar6 = iVar6 + 0x54;
        iVar8 = iVar8 + 4;
      } while (iVar6 != 0xfc);
      local_b0 = local_50;
      local_ac = local_44;
      local_a8 = local_4c;
      piVar11 = local_a4 + 6;
      iVar8 = 1;
      do {
        if (iVar8 == 1) {
          *piVar11 = 0x140;
        }
        else {
          *piVar11 = 0xa0;
          if (2 < iVar8) {
            local_58 = (uint *)(local_244 << 3);
            iVar8 = 0;
            if (local_250 < local_310) {
              local_6c = &local_b0;
              local_68 = local_a4 + 3;
              local_64 = local_a4;
              local_60 = (undefined **)0x0;
              local_4c = &local_330;
              local_44 = piVar3;
              local_40 = pvVar2;
              local_3c = __ptr;
              do {
                iVar6 = 0;
                do {
                  pvVar2 = **(void ***)(local_70 + iVar6);
                  iVar10 = *(int *)((int)local_68 + iVar6);
[32m                  __n = *(size_t *)((int)local_a4 + iVar6 + 0x18);[0m
                  if (0 < iVar10) {
                    __src = (void *)(*(int *)((int)local_6c + iVar6) + __n * iVar10 * iVar8);
                    piVar3 = (int *)((int)local_64 + iVar6);
                    ppuVar4 = local_60;
                    do {
[32m                      memcpy(pvVar2,__src,__n);[0m
                      pvVar2 = (void *)((int)pvVar2 + *piVar3);
                      ppuVar4 = (undefined **)((int)ppuVar4 + 1);
                      __src = (void *)((int)__src + __n);
                    } while ((int)ppuVar4 < iVar10);
                  }
                  iVar6 = iVar6 + 4;
                } while (iVar6 != 0xc);
                jpeg_write_raw_data(local_4c,local_54,local_58);
                iVar8 = iVar8 + 1;
                __ptr = local_3c;
                pvVar2 = local_40;
                piVar3 = local_44;
              } while (local_250 < local_310);
            }
            free(pvVar2);
            free(piVar3);
            free(local_38);
            free(__ptr);
            free(local_30);
            free(local_48);
            free(local_50);
            jpeg_finish_decompress(local_500);
            jpeg_destroy_decompress(local_500);
            fclose(local_34);
            jpeg_finish_compress(&local_330);
            jpeg_destroy_compress(&local_330);
            fclose(local_5c);
            return 1;
          }
        }
        iVar8 = iVar8 + 1;
        piVar11 = piVar11 + 1;
      } while( true );
    }
    printf("getpreviewimg: Error opening file %s\n",param_2);
  }
  return 0xffffffff;
}

[ASK_GPT] fe42bd718fdfa4d5
