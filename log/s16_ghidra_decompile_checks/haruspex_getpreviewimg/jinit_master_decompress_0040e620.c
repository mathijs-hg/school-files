
void jinit_master_decompress(int *param_1)

{
  code **ppcVar1;
  void *__s;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  bool bVar5;
  int iVar6;
  code *pcVar7;
  
  ppcVar1 = (code **)(**(code **)param_1[1])(param_1,1,0x1c);
  param_1[0x69] = (int)ppcVar1;
  *ppcVar1 = FUN_0040e008;
  ppcVar1[2] = (code *)0x0;
  ppcVar1[1] = FUN_0040e200;
  iVar6 = param_1[0x69];
  jpeg_calc_output_dimensions(param_1);
  __s = (void *)(**(code **)param_1[1])(param_1,1,0x580);
  param_1[0x51] = (int)__s + 0x100;
[32m  memset(__s,0,0x100);[0m
  iVar2 = 0;
  pvVar4 = __s;
  do {
    *(char *)((int)pvVar4 + 0x100) = (char)iVar2;
    iVar2 = iVar2 + 1;
    pvVar4 = (void *)((int)__s + iVar2);
  } while (iVar2 != 0x100);
  pvVar4 = __s;
  do {
    *(undefined *)((int)pvVar4 + 0x200) = 0xff;
    pvVar4 = (void *)((int)pvVar4 + 1);
  } while (pvVar4 != (void *)((int)__s + 0x180));
[32m  memset((void *)((int)__s + 0x380),0,0x180);[0m
[32m[32m  memcpy((void *)((int)__s + 0x500),(void *)param_1[0x51],0x80);[0m[0m
  *(undefined4 *)(iVar6 + 0xc) = 0;
  uVar3 = FUN_0040df30(param_1);
  *(undefined4 *)(iVar6 + 0x10) = uVar3;
  *(undefined4 *)(iVar6 + 0x14) = 0;
  *(undefined4 *)(iVar6 + 0x18) = 0;
  if ((param_1[0x15] == 0) || (param_1[0x10] == 0)) {
    param_1[0x19] = 0;
    param_1[0x1a] = 0;
    param_1[0x1b] = 0;
  }
  if (param_1[0x15] != 0) {
    if (param_1[0x11] != 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x2f;
      (**(code **)*param_1)(param_1);
    }
    if (param_1[0x1e] == 3) {
      if (param_1[0x22] == 0) {
        if (param_1[0x17] == 0) {
          param_1[0x19] = 1;
        }
        else {
          param_1[0x1b] = 1;
        }
      }
      else {
        param_1[0x1a] = 1;
      }
    }
    else {
      param_1[0x19] = 1;
      param_1[0x1a] = 0;
      param_1[0x1b] = 0;
      param_1[0x22] = 0;
    }
    if (param_1[0x19] != 0) {
      jinit_1pass_quantizer(param_1);
      *(int *)(iVar6 + 0x14) = param_1[0x73];
    }
    if ((param_1[0x1b] != 0) || (param_1[0x1a] != 0)) {
      jinit_2pass_quantizer(param_1);
      *(int *)(iVar6 + 0x18) = param_1[0x73];
    }
  }
  if (param_1[0x11] == 0) {
    if (*(int *)(iVar6 + 0x10) == 0) {
      jinit_color_deconverter(param_1);
      pcVar7 = jinit_upsampler;
    }
    else {
      pcVar7 = jinit_merged_upsampler;
    }
    (*pcVar7)(param_1);
    jinit_d_post_controller(param_1,param_1[0x1b]);
  }
  jinit_inverse_dct(param_1);
  if (param_1[0x38] == 0) {
    if (param_1[0x37] == 0) {
      pcVar7 = jinit_huff_decoder;
    }
    else {
      pcVar7 = jinit_phuff_decoder;
    }
    (*pcVar7)(param_1);
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 1;
    (**(code **)*param_1)(param_1);
  }
  bVar5 = true;
  if (*(int *)(param_1[0x6d] + 0x10) == 0) {
    bVar5 = param_1[0x10] != 0;
  }
  jinit_d_coef_controller(param_1,bVar5);
  if (param_1[0x11] == 0) {
    jinit_d_main_controller(param_1,0);
  }
  (**(code **)(param_1[1] + 0x18))(param_1);
  (**(code **)(param_1[0x6d] + 8))(param_1);
  if (((param_1[2] != 0) && (param_1[0x10] == 0)) && (*(int *)(param_1[0x6d] + 0x10) != 0)) {
    iVar2 = param_1[9];
    if (param_1[0x37] != 0) {
      iVar2 = iVar2 * 3 + 2;
    }
    *(undefined4 *)(param_1[2] + 4) = 0;
    uVar3 = 2;
    *(int *)(param_1[2] + 8) = iVar2 * param_1[0x50];
    *(undefined4 *)(param_1[2] + 0xc) = 0;
    if (param_1[0x1b] != 0) {
      uVar3 = 3;
    }
    *(undefined4 *)(param_1[2] + 0x10) = uVar3;
    *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;
  }
  return;
}

[ASK_GPT] c8e535c49cf5f4b0
