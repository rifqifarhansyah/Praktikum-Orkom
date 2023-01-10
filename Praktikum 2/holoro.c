void Holoro(undefined4 param_1)

{
  uint uVar1;
  int in_GS_OFFSET;
  int aiStack_2c [7];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  read_six_numbers(param_1,aiStack_2c + 1);
  if (aiStack_2c[1] != 1) {
    illegal_move();
  }
  uVar1 = 1;
  do {
    if ((uVar1 & 1) == 0) {
      if (aiStack_2c[uVar1 + 1] != uVar1 * aiStack_2c[uVar1]) goto LAB_0001172e;
    }
    else if (aiStack_2c[uVar1 + 1] != uVar1 + aiStack_2c[uVar1]) {
        LAB_0001172e:
        illegal_move();
    }
    uVar1 = uVar1 + 1;
    if (uVar1 == 6) {
      if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail_local();
      }
      return;
    }
  } while( true );
}