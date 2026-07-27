/* Ghidra decompilation of libcampan.so (447 functions) */


int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = entry();
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nn_face_quality_process
               (nn_face_quality_t *param_1,ax_yuv_t *param_2,face_box_t *param_3,float *param_4)

{
  nn_face_quality_process(param_1,param_2,param_3,param_4);
  return;
}



void dtbased_tk_change_id(void)

{
  dtbased_tk_change_id();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void kpt_smooth_create(void)

{
  kpt_smooth_create();
  return;
}



void handdet_create(void)

{
  handdet_create();
  return;
}



void handpose_create(void)

{
  handpose_create();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sem_destroy(sem_t *__sem)

{
  int iVar1;
  
  iVar1 = sem_destroy(__sem);
  return iVar1;
}



void campan_face_feature_process
               (nn_face_feature_t *param_1,ax_yuv_t *param_2,nn_campan_face_t *param_3,int param_4)

{
  campan_face_feature_process(param_1,param_2,param_3,param_4);
  return;
}



void dump_campan_cfg(nn_campan_cfg_t *param_1)

{
  dump_campan_cfg(param_1);
  return;
}



void campan_yolov8_humanpose_det_create(void)

{
  campan_yolov8_humanpose_det_create();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(param_1);
  return pvVar1;
}



void nn_hermes_close(void)

{
  nn_hermes_close();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_lock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = pthread_mutex_lock(__mutex);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__detail::_List_node_base::_M_hook(_List_node_base *param_1)

{
  _M_hook(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_init(pthread_mutex_t *__mutex,pthread_mutexattr_t *__mutexattr)

{
  int iVar1;
  
  iVar1 = pthread_mutex_init(__mutex,__mutexattr);
  return iVar1;
}



void campan_reid_process_single
               (campan_reid_t *param_1,nn_campan_person_t *param_2,ax_yuv_t *param_3)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  int iVar6;
  ax_tensor_t *this;
  ax_tensor_t *paVar7;
  undefined4 *puVar8;
  ax_tensor_t *paVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  void *pvVar14;
  void *pvVar15;
  uint uVar16;
  uint uVar17;
  undefined8 uVar18;
  void *pvStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  uint uStack_b8;
  uint uStack_b4;
  int iStack_b0;
  int iStack_ac;
  void *pvStack_a8;
  void *pvStack_a4;
  undefined4 uStack_a0;
  undefined4 *puStack_9c;
  undefined4 *puStack_98;
  undefined4 uStack_94;
  ax_tensor_t aaStack_90 [16];
  void *pvStack_80;
  void *pvStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  void *pvStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_48 = *(undefined4 *)param_3;
  uStack_44 = *(undefined4 *)(param_3 + 4);
  uStack_40 = *(undefined4 *)(param_3 + 8);
  uStack_3c = *(undefined4 *)(param_3 + 0xc);
  uStack_b8 = *(uint *)(param_2 + 0x14);
  uVar16 = *(int *)(param_3 + 0x18) - 1;
  uStack_38 = *(undefined4 *)(param_3 + 0x10);
  uStack_34 = *(undefined4 *)(param_3 + 0x14);
  uStack_30 = *(undefined4 *)(param_3 + 0x18);
  uStack_2c = *(undefined4 *)(param_3 + 0x1c);
  iVar6 = (*(int *)(param_2 + 0x1c) - uStack_b8) + 1;
  uStack_28 = *(undefined4 *)(param_3 + 0x20);
  uVar11 = *(uint *)(param_2 + 0x18);
  pvStack_60 = (void *)0x0;
  uStack_5c = 0;
  uStack_58 = 0;
  pvStack_54 = (void *)0x0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_24 = 0;
  pvStack_c4 = (void *)0x0;
  uStack_c0 = 0;
  uStack_bc = 0;
  iVar2 = (iVar6 * 3) / 2;
  iVar3 = (*(int *)(param_2 + 0x20) - uVar11) + 1;
  uVar4 = (uStack_b8 + iVar6) - 1;
  uStack_b8 = uStack_b8 & ~((int)uStack_b8 >> 0x1f);
  if (iVar2 < iVar3) {
    iVar3 = iVar2;
  }
  uVar17 = *(int *)(param_3 + 0x1c) - 1;
  uStack_b4 = uVar11 & ~((int)uVar11 >> 0x1f);
  uVar11 = (uVar11 + iVar3) - 1;
  uVar4 = uVar4 & ~((int)uVar4 >> 0x1f);
  if ((int)uVar16 <= (int)uStack_b8) {
    uStack_b8 = uVar16;
  }
  if ((int)uVar17 <= (int)uStack_b4) {
    uStack_b4 = uVar17;
  }
  uVar11 = uVar11 & ~((int)uVar11 >> 0x1f);
  if ((int)uVar16 < (int)uVar4) {
    iStack_b0 = uVar16 - uStack_b8;
  }
  else {
    iStack_b0 = uVar4 - uStack_b8;
  }
  if ((int)uVar17 < (int)uVar11) {
    iStack_ac = uVar17 - uStack_b4;
  }
  else {
    iStack_ac = uVar11 - uStack_b4;
  }
  iStack_b0 = iStack_b0 + 1;
  iStack_ac = iStack_ac + 1;
  std::vector<ax_rect_t,std::allocator<ax_rect_t>>::_M_realloc_insert<ax_rect_t_const&>
            ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&pvStack_c4,0,&uStack_b8);
  std::vector<ax_rect_t,std::allocator<ax_rect_t>>::operator=
            ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&pvStack_60,(vector *)&pvStack_c4);
  pvStack_a8 = (void *)0x0;
  pvStack_a4 = (void *)0x0;
  uStack_a0 = 0;
  puStack_9c = (undefined4 *)0x0;
  puStack_98 = (undefined4 *)0x0;
  uStack_94 = 0;
  batch_classify_process
            (*(batch_classify_model_t **)param_1,(classify_in_t *)&pvStack_60,
             (classify_out_t *)&pvStack_a8,1);
  if (puStack_98 != puStack_9c) {
    if ((ax_tensor_t *)puStack_9c[1] != (ax_tensor_t *)*puStack_9c) {
      ax_tensor_t::ax_tensor_t(aaStack_90,(ax_tensor_t *)*puStack_9c);
      memcpy(param_2 + 0x30,pvStack_80,*(size_t *)(param_1 + 4));
      *(undefined4 *)(param_2 + 0x130) = *(undefined4 *)(param_1 + 4);
      uVar18 = ax_tensor_t::norm();
      *(undefined4 *)(param_2 + 0x140) = 1;
      *(undefined8 *)(param_2 + 0x138) = uVar18;
      ax_tensor_t::~ax_tensor_t(aaStack_90);
      puVar8 = puStack_98;
      puVar10 = puStack_98;
      if (puStack_9c != puStack_98) {
        puVar12 = puStack_9c + 3;
        puVar10 = puStack_9c;
        puVar13 = puVar12;
        while( true ) {
          paVar9 = (ax_tensor_t *)puVar10[1];
          this = (ax_tensor_t *)puVar12[-3];
          if ((ax_tensor_t *)puVar12[-3] != paVar9) {
            do {
              paVar7 = this + 0x30;
              ax_tensor_t::~ax_tensor_t(this);
              this = paVar7;
            } while (paVar9 != paVar7);
            paVar9 = (ax_tensor_t *)puVar12[-3];
          }
          if (paVar9 != (ax_tensor_t *)0x0) {
            operator_delete(paVar9);
          }
          puVar12 = puVar12 + 3;
          puVar10 = puStack_9c;
          if (puVar8 == puVar13) break;
          puVar10 = puVar13;
          puVar13 = puVar13 + 3;
        }
      }
      if (puVar10 != (undefined4 *)0x0) {
        operator_delete(puVar10);
      }
      pvVar1 = pvStack_a4;
      pvVar5 = pvStack_a4;
      if (pvStack_a8 != pvStack_a4) {
        pvVar14 = (void *)((int)pvStack_a8 + 0xc);
        pvVar5 = pvStack_a8;
        pvVar15 = pvVar14;
        while( true ) {
          puVar10 = *(undefined4 **)((int)pvVar5 + 4);
          puVar8 = *(undefined4 **)((int)pvVar14 + -0xc);
          if (puVar8 != puVar10) {
            do {
              if ((void *)*puVar8 != (void *)0x0) {
                operator_delete((void *)*puVar8);
              }
              puVar8 = puVar8 + 3;
            } while (puVar10 != puVar8);
            puVar10 = *(undefined4 **)((int)pvVar14 + -0xc);
          }
          if (puVar10 != (undefined4 *)0x0) {
            operator_delete(puVar10);
          }
          pvVar14 = (void *)((int)pvVar14 + 0xc);
          pvVar5 = pvStack_a8;
          if (pvVar1 == pvVar15) break;
          pvVar5 = pvVar15;
          pvVar15 = (void *)((int)pvVar15 + 0xc);
        }
      }
      if (pvVar5 != (void *)0x0) {
        operator_delete(pvVar5);
      }
      if (pvStack_c4 != (void *)0x0) {
        operator_delete(pvStack_c4);
      }
      if (pvStack_54 != (void *)0x0) {
        operator_delete(pvStack_54);
      }
      if (pvStack_60 != (void *)0x0) {
        operator_delete(pvStack_60);
      }
      return;
    }
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0);
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0,0);
}



void campan_set_tracking_person_head
               (campan_feature_match_t *param_1,nn_campan_person_head_t *param_2)

{
  campan_set_tracking_person_head(param_1,param_2);
  return;
}



void AX_MALLOC_INC_TEMP<ax_int_array_t>(ax_int_array_t *param_1,int param_2)

{
  AX_MALLOC_INC_TEMP<ax_int_array_t>(param_1,param_2);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::_Rb_tree_insert_and_rebalance
               (bool param_1,_Rb_tree_node_base *param_2,_Rb_tree_node_base *param_3,
               _Rb_tree_node_base *param_4)

{
  _Rb_tree_insert_and_rebalance(param_1,param_2,param_3,param_4);
  return;
}



void handpose_process_two_cls(handpose_t *param_1,int *param_2,ax_yuv_t *param_3)

{
  handpose_process_two_cls(param_1,param_2,param_3);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  free(__ptr);
  return;
}



void AX_MALLOC_INC_TEMP<nn_campan_persons_t>(nn_campan_persons_t *param_1,int param_2)

{
  AX_MALLOC_INC_TEMP<nn_campan_persons_t>(param_1,param_2);
  return;
}



void campan_human_pose_create(void)

{
  campan_human_pose_create();
  return;
}



retina_head_t * __thiscall retina_head_t::~retina_head_t(retina_head_t *this)

{
  if (*(void **)(this + 0x18) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x18));
  }
  if (*(void **)(this + 0xc) != (void *)0x0) {
    operator_delete(*(void **)(this + 0xc));
  }
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this);
  }
  return this;
}



void __thiscall
std::vector<nn_campan_hand_t,std::allocator<nn_campan_hand_t>>::
_M_realloc_insert<nn_campan_hand_t_const&>(void)

{
  _M_realloc_insert<nn_campan_hand_t_const&>();
  return;
}



void __thiscall
std::vector<ax_track_kpt_t,std::allocator<ax_track_kpt_t>>::_M_realloc_insert<ax_track_kpt_t_const&>
          (void)

{
  _M_realloc_insert<ax_track_kpt_t_const&>();
  return;
}



void campan_register_face_head_track
               (campan_feature_match_t *param_1,nn_campan_register_face_head_track_t *param_2)

{
  int iVar1;
  _List_node_base *p_Var2;
  _List_node_base *p_Var3;
  _List_node_base *p_Var4;
  undefined4 *puVar5;
  undefined4 *****pppppuVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *****pppppuVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  double dVar15;
  int aiStack_2c0 [3];
  undefined4 ****ppppuStack_2b4;
  undefined4 ****ppppuStack_2b0;
  int iStack_2ac;
  undefined4 ****ppppuStack_2a8;
  undefined4 ****ppppuStack_2a4;
  undefined4 uStack_2a0;
  undefined4 auStack_29c [9];
  undefined4 uStack_278;
  undefined4 uStack_274;
  undefined4 ****ppppuStack_270;
  undefined4 ****ppppuStack_26c;
  undefined4 uStack_268;
  undefined4 ****ppppuStack_264;
  undefined4 ****ppppuStack_260;
  undefined4 uStack_25c;
  undefined4 auStack_258 [15];
  undefined4 uStack_21c;
  undefined8 uStack_218;
  undefined8 uStack_210;
  undefined4 uStack_208;
  undefined4 uStack_204;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  undefined4 uStack_1f8;
  undefined4 uStack_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  undefined4 uStack_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  undefined1 auStack_1b0 [96];
  undefined1 auStack_150 [284];
  int iStack_34;
  
  iVar1 = *(int *)(param_1 + 0xabc);
  iStack_2ac = 0;
  iStack_34 = __stack_chk_guard;
  uStack_2a0 = 0;
  puVar12 = &uStack_278;
  puVar5 = auStack_29c;
  do {
    puVar5[2] = 0;
    *puVar5 = puVar5;
    puVar5[1] = puVar5;
    puVar5 = puVar5 + 3;
  } while (puVar12 != puVar5);
  uStack_268 = 0;
  uStack_25c = 0;
  puVar5 = auStack_258;
  do {
    puVar5[2] = 0;
    *puVar5 = puVar5;
    puVar5[1] = puVar5;
    puVar5 = puVar5 + 3;
  } while (puVar5 != &uStack_21c);
  uStack_21c = 0;
  uStack_208 = 0;
  uStack_200 = 0;
  uStack_1f4 = 0;
  aiStack_2c0[2] = 0;
  uStack_1c8 = 0;
  uStack_1c4 = 0;
  uStack_204 = 0xffffffff;
  uStack_278 = 0xffffffff;
  uStack_274 = 0xffffffff;
  uStack_1f8 = 0xffffffff;
  uStack_1bc = 0xffffffff;
  uStack_1b8 = 0xffffffff;
  uStack_1fc = 1;
  ppppuStack_2b4 = &ppppuStack_2b4;
  ppppuStack_2b0 = &ppppuStack_2b4;
  ppppuStack_2a8 = &ppppuStack_2a8;
  ppppuStack_2a4 = &ppppuStack_2a8;
  ppppuStack_270 = &ppppuStack_270;
  ppppuStack_26c = &ppppuStack_270;
  ppppuStack_264 = &ppppuStack_264;
  ppppuStack_260 = &ppppuStack_264;
  dVar15 = (double)get_time_ms();
  memset(auStack_1b0,0,0x178);
  memcpy(auStack_150,param_2,0x118);
  p_Var2 = (_List_node_base *)operator_new(0x180);
  memcpy(p_Var2 + 8,auStack_1b0,0x178);
  std::__detail::_List_node_base::_M_hook(p_Var2);
  aiStack_2c0[0] = *(int *)(param_2 + 0x118);
  iStack_2ac = iStack_2ac + 1;
  aiStack_2c0[1] = 0xffffffff;
  uStack_208 = 1;
  uStack_1bc = 1;
  uStack_218 = dVar15 / 1000.0;
  uStack_210 = dVar15 / 1000.0;
  p_Var2 = (_List_node_base *)operator_new(0x118);
  *(undefined4 *)(p_Var2 + 0x1c) = 0;
  *(int *)(p_Var2 + 8) = aiStack_2c0[0];
  *(int *)(p_Var2 + 0xc) = aiStack_2c0[1];
  *(int *)(p_Var2 + 0x10) = aiStack_2c0[2];
  *(_List_node_base **)(p_Var2 + 0x14) = p_Var2 + 0x14;
  *(_List_node_base **)(p_Var2 + 0x18) = p_Var2 + 0x14;
  pppppuVar6 = (undefined4 *****)ppppuStack_2b4;
  while (pppppuVar6 != &ppppuStack_2b4) {
    p_Var3 = (_List_node_base *)operator_new(0x180);
    memcpy(p_Var3 + 8,pppppuVar6 + 2,0x178);
    std::__detail::_List_node_base::_M_hook(p_Var3);
    pppppuVar6 = (undefined4 *****)*pppppuVar6;
    *(int *)(p_Var2 + 0x1c) = *(int *)(p_Var2 + 0x1c) + 1;
  }
  *(_List_node_base **)(p_Var2 + 0x24) = p_Var2 + 0x20;
  *(undefined4 *)(p_Var2 + 0x28) = 0;
  *(_List_node_base **)(p_Var2 + 0x20) = p_Var2 + 0x20;
  pppppuVar6 = (undefined4 *****)ppppuStack_2a8;
  while (pppppuVar6 != &ppppuStack_2a8) {
    p_Var3 = (_List_node_base *)operator_new(0x180);
    memcpy(p_Var3 + 8,pppppuVar6 + 2,0x178);
    std::__detail::_List_node_base::_M_hook(p_Var3);
    pppppuVar6 = (undefined4 *****)*pppppuVar6;
    *(int *)(p_Var2 + 0x28) = *(int *)(p_Var2 + 0x28) + 1;
  }
  p_Var3 = p_Var2 + 0x2c;
  iVar13 = 2;
  piVar8 = aiStack_2c0;
  while( true ) {
    *(_List_node_base **)p_Var3 = p_Var3;
    *(_List_node_base **)(p_Var3 + 4) = p_Var3;
    piVar7 = (int *)piVar8[9];
    *(undefined4 *)(p_Var3 + 8) = 0;
    while (piVar8 + 9 != piVar7) {
      p_Var4 = (_List_node_base *)operator_new(0x180);
      memcpy(p_Var4 + 8,piVar7 + 2,0x178);
      std::__detail::_List_node_base::_M_hook(p_Var4);
      piVar7 = (int *)*piVar7;
      *(int *)(p_Var3 + 8) = *(int *)(p_Var3 + 8) + 1;
    }
    p_Var3 = p_Var3 + 0xc;
    piVar8 = piVar8 + 3;
    if (iVar13 == 0) break;
    iVar13 = iVar13 + -1;
  }
  *(undefined4 *)(p_Var2 + 0x50) = uStack_278;
  *(undefined4 *)(p_Var2 + 0x54) = uStack_274;
  *(undefined4 *)(p_Var2 + 0x60) = 0;
  *(_List_node_base **)(p_Var2 + 0x58) = p_Var2 + 0x58;
  *(_List_node_base **)(p_Var2 + 0x5c) = p_Var2 + 0x58;
  pppppuVar6 = (undefined4 *****)ppppuStack_270;
  while (pppppuVar6 != &ppppuStack_270) {
    p_Var3 = (_List_node_base *)operator_new(0x2b0);
    memcpy(p_Var3 + 8,pppppuVar6 + 2,0x2a8);
    std::__detail::_List_node_base::_M_hook(p_Var3);
    pppppuVar6 = (undefined4 *****)*pppppuVar6;
    *(int *)(p_Var2 + 0x60) = *(int *)(p_Var2 + 0x60) + 1;
  }
  *(_List_node_base **)(p_Var2 + 0x68) = p_Var2 + 100;
  *(undefined4 *)(p_Var2 + 0x6c) = 0;
  *(_List_node_base **)(p_Var2 + 100) = p_Var2 + 100;
  pppppuVar6 = (undefined4 *****)ppppuStack_264;
  while (pppppuVar6 != &ppppuStack_264) {
    p_Var3 = (_List_node_base *)operator_new(0x2b0);
    memcpy(p_Var3 + 8,pppppuVar6 + 2,0x2a8);
    std::__detail::_List_node_base::_M_hook(p_Var3);
    pppppuVar6 = (undefined4 *****)*pppppuVar6;
    *(int *)(p_Var2 + 0x6c) = *(int *)(p_Var2 + 0x6c) + 1;
  }
  p_Var3 = p_Var2 + 0x70;
  iVar13 = 0x68;
  iVar14 = 4;
  do {
    piVar8 = *(int **)((int)aiStack_2c0 + iVar13);
    *(_List_node_base **)p_Var3 = p_Var3;
    *(_List_node_base **)(p_Var3 + 4) = p_Var3;
    *(undefined4 *)(p_Var3 + 8) = 0;
    while (piVar8 != (int *)((int)aiStack_2c0 + iVar13)) {
      p_Var4 = (_List_node_base *)operator_new(0x2b0);
      memcpy(p_Var4 + 8,piVar8 + 2,0x2a8);
      std::__detail::_List_node_base::_M_hook(p_Var4);
      piVar8 = (int *)*piVar8;
      *(int *)(p_Var3 + 8) = *(int *)(p_Var3 + 8) + 1;
    }
    iVar14 = iVar14 + -1;
    p_Var3 = p_Var3 + 0xc;
    iVar13 = iVar13 + 0xc;
  } while (iVar14 != -1);
  *(undefined4 *)(p_Var2 + 0xac) = uStack_21c;
  *(undefined4 *)(p_Var2 + 0xc0) = uStack_208;
  *(undefined4 *)(p_Var2 + 0xc4) = uStack_204;
  uStack_210._4_4_ = (undefined4)((ulonglong)uStack_210 >> 0x20);
  *(undefined4 *)(p_Var2 + 200) = uStack_200;
  *(undefined4 *)(p_Var2 + 0xcc) = uStack_1fc;
  uStack_218._4_4_ = (undefined4)((ulonglong)uStack_218 >> 0x20);
  *(undefined4 *)(p_Var2 + 0xb8) = (undefined4)uStack_210;
  *(undefined4 *)(p_Var2 + 0xbc) = uStack_210._4_4_;
  *(undefined4 *)(p_Var2 + 0xd0) = uStack_1f8;
  *(undefined4 *)(p_Var2 + 0xd4) = uStack_1f4;
  *(undefined4 *)(p_Var2 + 0xb0) = (undefined4)uStack_218;
  *(undefined4 *)(p_Var2 + 0xb4) = uStack_218._4_4_;
  *(undefined4 *)(p_Var2 + 0xd8) = uStack_1f0;
  *(undefined4 *)(p_Var2 + 0xdc) = uStack_1ec;
  *(undefined4 *)(p_Var2 + 0xe0) = uStack_1e8;
  *(undefined4 *)(p_Var2 + 0xe4) = uStack_1e4;
  puVar5 = &uStack_21c;
  *(undefined4 *)(p_Var2 + 0xe8) = uStack_1e0;
  *(undefined4 *)(p_Var2 + 0xec) = uStack_1dc;
  *(undefined4 *)(p_Var2 + 0xf0) = uStack_1d8;
  *(undefined4 *)(p_Var2 + 0xf4) = uStack_1d4;
  *(undefined4 *)(p_Var2 + 0x108) = uStack_1c0;
  *(undefined4 *)(p_Var2 + 0x10c) = uStack_1bc;
  *(undefined4 *)(p_Var2 + 0xf8) = uStack_1d0;
  *(undefined4 *)(p_Var2 + 0xfc) = uStack_1cc;
  *(undefined4 *)(p_Var2 + 0x100) = uStack_1c8;
  *(undefined4 *)(p_Var2 + 0x104) = uStack_1c4;
  *(undefined4 *)(p_Var2 + 0x110) = uStack_1b8;
  std::__detail::_List_node_base::_M_hook(p_Var2);
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  do {
    puVar5 = puVar5 + -3;
    puVar10 = (undefined4 *)*puVar5;
    while (puVar5 != puVar10) {
      puVar11 = (undefined4 *)*puVar10;
      operator_delete(puVar10);
      puVar10 = puVar11;
    }
    pppppuVar6 = (undefined4 *****)ppppuStack_264;
  } while (puVar5 != auStack_258);
  while (pppppuVar9 = (undefined4 *****)ppppuStack_270, pppppuVar6 != &ppppuStack_264) {
    pppppuVar9 = (undefined4 *****)*pppppuVar6;
    operator_delete(pppppuVar6);
    pppppuVar6 = pppppuVar9;
  }
  while (pppppuVar9 != &ppppuStack_270) {
    pppppuVar6 = (undefined4 *****)*pppppuVar9;
    operator_delete(pppppuVar9);
    pppppuVar9 = pppppuVar6;
  }
  do {
    puVar12 = puVar12 + -3;
    puVar5 = (undefined4 *)*puVar12;
    while (puVar12 != puVar5) {
      puVar10 = (undefined4 *)*puVar5;
      operator_delete(puVar5);
      puVar5 = puVar10;
    }
    pppppuVar6 = (undefined4 *****)ppppuStack_2a8;
  } while (puVar12 != auStack_29c);
  while (pppppuVar9 = (undefined4 *****)ppppuStack_2b4, pppppuVar6 != &ppppuStack_2a8) {
    pppppuVar9 = (undefined4 *****)*pppppuVar6;
    operator_delete(pppppuVar6);
    pppppuVar6 = pppppuVar9;
  }
  while (pppppuVar9 != &ppppuStack_2b4) {
    pppppuVar6 = (undefined4 *****)*pppppuVar9;
    operator_delete(pppppuVar9);
    pppppuVar9 = pppppuVar6;
  }
  if (iStack_34 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



void head_person_match_filter
               (campan_feature_match_t *param_1,nn_campan_persons_t *param_2,
               nn_campan_heads_t *param_3)

{
  head_person_match_filter(param_1,param_2,param_3);
  return;
}



void campan_feature_match_release(campan_feature_match_t *param_1)

{
  campan_feature_match_release(param_1);
  return;
}



void std::
     _Rb_tree<int,std::pair<int_const,match_table_t>,std::_Select1st<std::pair<int_const,match_table_t>>,std::less<int>,std::allocator<std::pair<int_const,match_table_t>>>
     ::_M_emplace_unique<std::pair<int,match_table_t>>(pair_conflict *param_1)

{
  _M_emplace_unique<std::pair<int,match_table_t>>(param_1);
  return;
}



void nn_hermes_cmd(void)

{
  nn_hermes_cmd();
  return;
}



void nn_hermes_cmd(void)

{
  nn_hermes_cmd();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::
     __unguarded_linear_insert<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,__gnu_cxx::__ops::_Val_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
               (void)

{
  __unguarded_linear_insert<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,__gnu_cxx::__ops::_Val_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
            ();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void batch_classify_create(batch_classify_config_t *param_1)

{
  batch_classify_create(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__throw_bad_alloc(void)

{
                    /* WARNING: Subroutine does not return */
  __throw_bad_alloc();
}



void __thiscall std::vector<int,std::allocator<int>>::_M_realloc_insert<int_const&>(void)

{
  _M_realloc_insert<int_const&>();
  return;
}



void nn_face_quality_create(void)

{
  nn_face_quality_create();
  return;
}



void __cxa_begin_catch(void)

{
  __cxa_begin_catch();
  return;
}



void clear_tracking_features_buffer(campan_feature_match_t *param_1)

{
  clear_tracking_features_buffer(param_1);
  return;
}



void campan_face_feature_create(void)

{
  campan_face_feature_create();
  return;
}



vector<retina_head_t,std::allocator<retina_head_t>> * __thiscall
std::vector<retina_head_t,std::allocator<retina_head_t>>::~vector
          (vector<retina_head_t,std::allocator<retina_head_t>> *this)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)this;
  puVar3 = *(undefined4 **)(this + 4);
  if (puVar2 != puVar3) {
    do {
      if ((void *)puVar2[6] != (void *)0x0) {
        operator_delete((void *)puVar2[6]);
      }
      if ((void *)puVar2[3] != (void *)0x0) {
        operator_delete((void *)puVar2[3]);
      }
      pvVar1 = (void *)*puVar2;
      puVar2 = puVar2 + 0xb;
      if (pvVar1 != (void *)0x0) {
        operator_delete(pvVar1);
      }
    } while (puVar3 != puVar2);
    puVar3 = *(undefined4 **)this;
  }
  if (puVar3 != (undefined4 *)0x0) {
    operator_delete(puVar3);
  }
  return this;
}



void __thiscall
std::vector<retina_head_t,std::allocator<retina_head_t>>::_M_realloc_insert<retina_head_t_const&>
          (void)

{
  _M_realloc_insert<retina_head_t_const&>();
  return;
}



void AX_ARRAY_PUSH_BACK<ax_detect_box_array_t,ax_detect_box_t>
               (ax_detect_box_array_t *param_1,ax_detect_box_t *param_2)

{
  void *__src;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  void *__dest;
  int iVar6;
  size_t __n;
  
  iVar4 = *(int *)(param_1 + 4);
  __dest = *(void **)param_1;
  iVar6 = iVar4 + 1;
  if (__dest == (void *)0x0) {
    if (iVar6 * 0x1c < 1) goto LAB_00016fe0;
    __dest = (void *)AX_MALLOC_RECORD(iVar6 * 0x38);
    __src = *(void **)param_1;
    __n = 0;
  }
  else {
    __n = *(size_t *)((int)__dest + -4);
    if ((int)(__n + iVar6 * -0x1c) < 0 == SBORROW4(__n,iVar6 * 0x1c)) goto LAB_00016fe0;
    __dest = (void *)AX_MALLOC_RECORD(iVar6 * 0x38);
    __src = *(void **)param_1;
  }
  if (__src != (void *)0x0) {
    memcpy(__dest,__src,__n);
    AX_FREE_RECORD(*(void **)param_1);
  }
  iVar4 = *(int *)(param_1 + 4);
  *(void **)param_1 = __dest;
LAB_00016fe0:
  puVar5 = (undefined4 *)(iVar4 * 0x1c + (int)__dest);
  uVar1 = *(undefined4 *)(param_2 + 4);
  uVar2 = *(undefined4 *)(param_2 + 8);
  uVar3 = *(undefined4 *)(param_2 + 0xc);
  *puVar5 = *(undefined4 *)param_2;
  puVar5[1] = uVar1;
  puVar5[2] = uVar2;
  puVar5[3] = uVar3;
  uVar1 = *(undefined4 *)(param_2 + 0x14);
  uVar2 = *(undefined4 *)(param_2 + 0x18);
  puVar5[4] = *(undefined4 *)(param_2 + 0x10);
  puVar5[5] = uVar1;
  puVar5[6] = uVar2;
  *(int *)(param_1 + 4) = iVar6;
  return;
}



void __thiscall std::vector<int,std::allocator<int>>::_M_erase(void)

{
  _M_erase();
  return;
}



void get_person_upper_box(nn_campan_person_t *param_1)

{
  get_person_upper_box(param_1);
  return;
}



void __thiscall
std::__cxx11::_List_base<neg_face_head_t,std::allocator<neg_face_head_t>>::_M_clear
          (_List_base<neg_face_head_t,std::allocator<neg_face_head_t>> *this)

{
  _M_clear(this);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__detail::_List_node_base::_M_transfer(_List_node_base *param_1,_List_node_base *param_2)

{
  _M_transfer(param_1,param_2);
  return;
}



void __thiscall
std::vector<int,std::allocator<int>>::emplace_back<int>
          (vector<int,std::allocator<int>> *this,int *param_1)

{
  emplace_back<int>(this,param_1);
  return;
}



void human_pose_create(void)

{
  human_pose_create();
  return;
}



int * std::
      __find_if<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,__gnu_cxx::__ops::_Iter_equals_val<int_const>>
                (int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  iVar1 = (int)param_2 - (int)param_1;
  if (0 < iVar1 >> 4) {
    iVar2 = *param_3;
    if (iVar2 == *param_1) {
      return param_1;
    }
    if (iVar2 == param_1[1]) {
      return param_1 + 1;
    }
    if (iVar2 == param_1[2]) {
      return param_1 + 2;
    }
    if (iVar2 == param_1[3]) {
      return param_1 + 3;
    }
    piVar4 = param_1 + (iVar1 >> 4) * 4;
    while (piVar3 = param_1, param_1 = piVar3 + 4, param_1 != piVar4) {
      if (iVar2 == piVar3[4]) {
        return param_1;
      }
      if (iVar2 == piVar3[5]) {
        return piVar3 + 5;
      }
      if (iVar2 == piVar3[6]) {
        return piVar3 + 6;
      }
      if (iVar2 == piVar3[7]) {
        return piVar3 + 7;
      }
    }
    iVar1 = (int)param_2 - (int)piVar4;
  }
  iVar1 = iVar1 >> 2;
  if (iVar1 == 2) {
    iVar1 = *param_3;
  }
  else {
    if (iVar1 != 3) {
      if (iVar1 != 1) {
        return param_2;
      }
      iVar1 = *param_3;
      goto LAB_0001b59c;
    }
    iVar1 = *param_3;
    if (*param_1 == iVar1) {
      return param_1;
    }
    param_1 = param_1 + 1;
  }
  if (iVar1 == *param_1) {
    return param_1;
  }
  param_1 = param_1 + 1;
LAB_0001b59c:
  if (iVar1 != *param_1) {
    param_1 = param_2;
  }
  return param_1;
}



void __android_log_print(void)

{
  __android_log_print();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__cxx11::string::_M_assign(string *param_1)

{
  _M_assign(param_1);
  return;
}



void __thiscall
std::vector<campan_reid_feature_t,std::allocator<campan_reid_feature_t>>::
_M_realloc_insert<campan_reid_feature_t_const&>(void)

{
  _M_realloc_insert<campan_reid_feature_t_const&>();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nn_get_state(nn_state_t *param_1)

{
  nn_get_state(param_1);
  return;
}



void AX_ARRAY_PUSH_BACK<nn_campan_heads_t,nn_campan_head_t>
               (nn_campan_heads_t *param_1,nn_campan_head_t *param_2)

{
  AX_ARRAY_PUSH_BACK<nn_campan_heads_t,nn_campan_head_t>(param_1,param_2);
  return;
}



void campan_reid_release(campan_reid_t *param_1)

{
  if (param_1 == (campan_reid_t *)0x0) {
    return;
  }
  classify_model_release(*(batch_classify_model_t **)param_1);
  AX_FREE_RECORD(param_1);
  return;
}



void campan_use_humanpose_set_human_head
               (human_pose_t *param_1,nn_campan_cfg_t *param_2,
               nn_campan_use_humanpose_trackid_out_t *param_3)

{
  campan_use_humanpose_set_human_head(param_1,param_2,param_3);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void classify_model_release(batch_classify_model_t *param_1)

{
  classify_model_release(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void softmax(vector *param_1,vector *param_2,int param_3)

{
  softmax(param_1,param_2,param_3);
  return;
}



void face_pose_create(void)

{
  face_pose_create();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void AX_FREE_RECORD(void *param_1)

{
  AX_FREE_RECORD(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void axnn_plg_open(void *param_1)

{
  axnn_plg_open(param_1);
  return;
}



void box_overlap_intersect<ax_box_t>(void)

{
  box_overlap_intersect<ax_box_t>();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::_Rb_tree_rebalance_for_erase(_Rb_tree_node_base *param_1,_Rb_tree_node_base *param_2)

{
  _Rb_tree_rebalance_for_erase(param_1,param_2);
  return;
}



void __thiscall ax_tensor_t::~ax_tensor_t(ax_tensor_t *this)

{
  ~ax_tensor_t(this);
  return;
}



void dtbased_tk_change_ids(void)

{
  dtbased_tk_change_ids();
  return;
}



void std::
     _Rb_tree<int,std::pair<int_const,kpt_smooth_infos_t>,std::_Select1st<std::pair<int_const,kpt_smooth_infos_t>>,std::less<int>,std::allocator<std::pair<int_const,kpt_smooth_infos_t>>>
     ::_M_emplace_unique<std::pair<int,kpt_smooth_infos_t>>(pair_conflict *param_1)

{
  _M_emplace_unique<std::pair<int,kpt_smooth_infos_t>>(param_1);
  return;
}



void campan_human_pose_release(human_pose_t *param_1)

{
  human_pose_release(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int prctl(int __option,...)

{
  int iVar1;
  
  iVar1 = prctl(__option);
  return iVar1;
}



void nn_campan_open_interface(undefined4 param_1)

{
  nn_hermes_open(campan_open,param_1,0x78);
  return;
}



void nn_campan_open_interface(undefined4 param_1)

{
  nn_hermes_open(campan_open,param_1,0x78);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = memset(__s,__c,__n);
  return pvVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::_Rb_tree_increment(_Rb_tree_node_base *param_1)

{
  _Rb_tree_increment(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nnyuv2axyuv(nn_yuv_t *param_1)

{
  nnyuv2axyuv(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::
     __introsort_loop<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,int,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
               (void)

{
  __introsort_loop<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,int,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
            ();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__throw_logic_error(char *param_1)

{
  __throw_logic_error(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nn_set_state(nn_state_t *param_1,int param_2)

{
  nn_set_state(param_1,param_2);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void box_smooth_release(box_smooth_t *param_1)

{
  box_smooth_release(param_1);
  return;
}



void __thiscall retina_model_info_t::~retina_model_info_t(retina_model_info_t *this)

{
  ~retina_model_info_t(this);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
  int iVar1;
  
  iVar1 = close(__fd);
  return iVar1;
}



void campan_face_pose_release(face_pose_t *param_1)

{
  if (param_1 == (face_pose_t *)0x0) {
    return;
  }
  face_pose_release(param_1);
  return;
}



void person_feature_dist(nn_campan_person_feature_t *param_1,nn_campan_person_feature_t *param_2)

{
  person_feature_dist(param_1,param_2);
  return;
}



void campan_set_tracking_person(campan_feature_match_t *param_1,nn_campan_person_t *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  campan_feature_match_t *pcVar5;
  undefined8 uVar7;
  campan_feature_match_t *pcVar6;
  
  __android_log_print(6,"CAMPAN_ATTR","set tracking person ");
  __android_log_print(6,"CAMPAN_ATTR","%d, %d, %d, %d, id %d",*(undefined4 *)(param_2 + 4),
                      *(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc),
                      *(undefined4 *)(param_2 + 0x10),*(undefined4 *)param_2);
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x318));
  memcpy(param_1,param_2,0x2a8);
  uVar2 = *(undefined4 *)param_2;
  *(undefined4 *)(param_1 + 0x304) = 0;
  *(undefined4 *)(param_1 + 0x300) = uVar2;
  uVar7 = get_time_ms();
  *(undefined8 *)(param_1 + 0x310) = uVar7;
  pcVar6 = param_1 + 0x2a8;
  do {
    pcVar5 = pcVar6 + 4;
    puVar3 = *(undefined4 **)pcVar6;
    puVar1 = (undefined4 *)*puVar3;
    while (puVar1 != puVar3) {
      puVar4 = (undefined4 *)*puVar1;
      operator_delete(puVar1);
      puVar1 = puVar4;
    }
    *puVar3 = puVar3;
    puVar3[1] = puVar3;
    puVar3[2] = 0;
    pcVar6 = pcVar5;
  } while (pcVar5 != param_1 + 700);
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x318));
  return;
}



void __thiscall
std::
_Rb_tree<int,std::pair<int_const,kpt_smooth_infos_t>,std::_Select1st<std::pair<int_const,kpt_smooth_infos_t>>,std::less<int>,std::allocator<std::pair<int_const,kpt_smooth_infos_t>>>
::_M_erase(_Rb_tree<int,std::pair<int_const,kpt_smooth_infos_t>,std::_Select1st<std::pair<int_const,kpt_smooth_infos_t>>,std::less<int>,std::allocator<std::pair<int_const,kpt_smooth_infos_t>>>
           *this,_Rb_tree_node *param_1)

{
  _M_erase(this,param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memmove(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = memmove(__dest,__src,__n);
  return pvVar1;
}



float iou<ax_box_t>(void)

{
  float fVar1;
  
  fVar1 = iou<ax_box_t>();
  return fVar1;
}



void __thiscall
std::vector<ax_rect_t,std::allocator<ax_rect_t>>::operator=
          (vector<ax_rect_t,std::allocator<ax_rect_t>> *this,vector *param_1)

{
  operator=(this,param_1);
  return;
}



void campan_human_pose_process
               (human_pose_t *param_1,ax_yuv_t *param_2,nn_campan_persons_t *param_3,float param_4)

{
  campan_human_pose_process(param_1,param_2,param_3,param_4);
  return;
}



void campan_reid_create(void)

{
  campan_reid_create();
  return;
}



void kpt_smooth_release(kpt_smooth_t *param_1)

{
  kpt_smooth_release(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ioctl(int __fd,ulong __request,...)

{
  int iVar1;
  
  iVar1 = ioctl(__fd,__request);
  return iVar1;
}



void __thiscall
std::vector<ez_model_info_t,std::allocator<ez_model_info_t>>::
_M_realloc_insert<ez_model_info_t_const&>(void)

{
  _M_realloc_insert<ez_model_info_t_const&>();
  return;
}



void __thiscall ax_tensor_mem_t::operator=(ax_tensor_mem_t *this,ax_tensor_mem_t *param_1)

{
  operator=(this,param_1);
  return;
}



void retina_create(void)

{
  retina_create();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void operator_delete(void *param_1)

{
  operator_delete(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __assert_fail(char *__assertion,char *__file,uint __line,char *__function)

{
                    /* WARNING: Subroutine does not return */
  __assert_fail(__assertion,__file,__line,__function);
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void get_time_ms(void)

{
  get_time_ms();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void face_feature_process
               (nn_face_feature_t *param_1,ax_yuv_t *param_2,face_box_t *param_3,signed *param_4)

{
  face_feature_process(param_1,param_2,param_3,param_4);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void batch_classify_process
               (batch_classify_model_t *param_1,classify_in_t *param_2,classify_out_t *param_3,
               int param_4)

{
  batch_classify_process(param_1,param_2,param_3,param_4);
  return;
}



void campan_face_pose_create(void)

{
  campan_face_pose_create();
  return;
}



void __thiscall ax_tensor_t::ax_tensor_t(ax_tensor_t *this,ax_tensor_t *param_1)

{
  ax_tensor_t(this,param_1);
  return;
}



void negative_nearest(campan_feature_match_t *param_1,nn_campan_person_t *param_2)

{
  negative_nearest(param_1,param_2);
  return;
}



nn_campan_track_head_t * __thiscall
nn_campan_track_head_t::~nn_campan_track_head_t(nn_campan_track_head_t *this)

{
  nn_campan_track_head_t *pnVar1;
  nn_campan_track_head_t *pnVar2;
  nn_campan_track_head_t *pnVar3;
  
  pnVar3 = this + 0xa4;
  do {
    pnVar3 = pnVar3 + -0xc;
    pnVar2 = *(nn_campan_track_head_t **)pnVar3;
    while (pnVar3 != pnVar2) {
      pnVar1 = *(nn_campan_track_head_t **)pnVar2;
      operator_delete(pnVar2);
      pnVar2 = pnVar1;
    }
  } while (this + 0x68 != pnVar3);
  pnVar3 = *(nn_campan_track_head_t **)(this + 0x5c);
  while (pnVar3 != this + 0x5c) {
    pnVar2 = *(nn_campan_track_head_t **)pnVar3;
    operator_delete(pnVar3);
    pnVar3 = pnVar2;
  }
  pnVar3 = *(nn_campan_track_head_t **)(this + 0x50);
  while (pnVar3 != this + 0x50) {
    pnVar2 = *(nn_campan_track_head_t **)pnVar3;
    operator_delete(pnVar3);
    pnVar3 = pnVar2;
  }
  pnVar3 = this + 0x48;
  do {
    pnVar3 = pnVar3 + -0xc;
    pnVar2 = *(nn_campan_track_head_t **)pnVar3;
    while (pnVar3 != pnVar2) {
      pnVar1 = *(nn_campan_track_head_t **)pnVar2;
      operator_delete(pnVar2);
      pnVar2 = pnVar1;
    }
  } while (this + 0x24 != pnVar3);
  pnVar3 = *(nn_campan_track_head_t **)(this + 0x18);
  while (pnVar3 != this + 0x18) {
    pnVar2 = *(nn_campan_track_head_t **)pnVar3;
    operator_delete(pnVar3);
    pnVar3 = pnVar2;
  }
  pnVar3 = *(nn_campan_track_head_t **)(this + 0xc);
  while (pnVar3 != this + 0xc) {
    pnVar2 = *(nn_campan_track_head_t **)pnVar3;
    operator_delete(pnVar3);
    pnVar3 = pnVar2;
  }
  return this;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = open(__file,__oflag);
  return iVar1;
}



void campan_face_pose_process(face_pose_t *param_1,ax_yuv_t *param_2,nn_campan_faces_t *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  if (*(int *)(param_3 + 4) < 1) {
    return;
  }
  iVar1 = 0;
  do {
    iVar2 = iVar1 * 0x178 + *(int *)param_3;
    iVar1 = iVar1 + 1;
    uStack_38 = *(undefined4 *)(iVar2 + 4);
    uStack_34 = *(undefined4 *)(iVar2 + 8);
    uStack_30 = *(undefined4 *)(iVar2 + 0xc);
    uStack_2c = *(undefined4 *)(iVar2 + 0x10);
    face_pose_process(param_1,param_2,(ax_box_t *)&uStack_38,(float *)(iVar2 + 0x4c));
  } while (iVar1 < *(int *)(param_3 + 4));
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ax_tensor_t::norm(void)

{
  norm();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::_Rb_tree_decrement(_Rb_tree_node_base *param_1)

{
  _Rb_tree_decrement(param_1);
  return;
}



void __thiscall ez_model_info_t::~ez_model_info_t(ez_model_info_t *this)

{
  ~ez_model_info_t(this);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void fps_stat_update(fps_stat_t *param_1)

{
  fps_stat_update(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::
     __adjust_heap<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,int,ax_rect_t,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
               (void)

{
  __adjust_heap<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,int,ax_rect_t,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
            ();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_destroy(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = pthread_mutex_destroy(__mutex);
  return iVar1;
}



void __thiscall
std::vector<ax_rect_t,std::allocator<ax_rect_t>>::_M_realloc_insert<ax_rect_t_const&>(void)

{
  _M_realloc_insert<ax_rect_t_const&>();
  return;
}



void nn_campan_close_interface(void)

{
  undefined4 in_r3;
  
  nn_hermes_close();
  __android_log_print(6,"CAMPAN","campan stopped",in_r3);
  return;
}



void nn_campan_close_interface(void)

{
  undefined4 in_r3;
  
  nn_hermes_close();
  __android_log_print(6,"CAMPAN","campan stopped",in_r3);
  return;
}



void __thiscall
std::vector<retina_head_t,std::allocator<retina_head_t>>::operator=
          (vector<retina_head_t,std::allocator<retina_head_t>> *this,vector *param_1)

{
  operator=(this,param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void batch_classify_config_init(batch_classify_config_t *param_1)

{
  batch_classify_config_init(param_1);
  return;
}



void __stack_chk_fail(void)

{
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



void __cxa_end_cleanup(void)

{
  __cxa_end_cleanup();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void retina_process_humanpose
               (retina_t *param_1,retina_pose_in_t *param_2,retina_pose_out_t *param_3)

{
  retina_process_humanpose(param_1,param_2,param_3);
  return;
}



void __thiscall
std::vector<ax_track_box_t,std::allocator<ax_track_box_t>>::_M_realloc_insert<ax_track_box_t_const&>
          (void)

{
  _M_realloc_insert<ax_track_box_t_const&>();
  return;
}



void dtbased_tk_update(void)

{
  dtbased_tk_update();
  return;
}



void handpose_process_old(handpose_t *param_1,int *param_2,ax_yuv_t *param_3)

{
  handpose_process_old(param_1,param_2,param_3);
  return;
}



void __thiscall
std::vector<ax_box_t,std::allocator<ax_box_t>>::_M_realloc_insert<ax_box_t_const&>
          (vector<ax_box_t,std::allocator<ax_box_t>> *this,void *param_2,undefined4 *param_3)

{
  void *__dest;
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *__dest_00;
  size_t __n;
  void *__src;
  uint uVar5;
  int iVar6;
  void *pvVar7;
  size_t sVar8;
  undefined4 *puVar9;
  
  __src = *(void **)this;
  pvVar7 = *(void **)(this + 4);
  sVar8 = (int)param_2 - (int)__src;
  uVar2 = (int)pvVar7 - (int)__src >> 4;
  if (uVar2 == 0) {
    uVar5 = 1;
LAB_0001a5c0:
    uVar5 = uVar5 << 4;
  }
  else {
    uVar5 = uVar2 * 2;
    if ((uVar2 <= uVar5) && (uVar5 < 0x10000000)) {
      if (uVar5 == 0) {
        iVar6 = 0;
        __dest = (void *)0x0;
        __n = sVar8;
        goto LAB_0001a570;
      }
      goto LAB_0001a5c0;
    }
    uVar5 = 0xfffffff0;
  }
  __dest = operator_new(uVar5);
  __src = *(void **)this;
  iVar6 = uVar5 + (int)__dest;
  pvVar7 = *(void **)(this + 4);
  __n = (int)param_2 - (int)__src;
LAB_0001a570:
  puVar9 = (undefined4 *)((int)__dest + sVar8);
  if (puVar9 != (undefined4 *)0x0) {
    uVar1 = param_3[1];
    uVar3 = param_3[2];
    uVar4 = param_3[3];
    *puVar9 = *param_3;
    puVar9[1] = uVar1;
    puVar9[2] = uVar3;
    puVar9[3] = uVar4;
  }
  if (param_2 != __src) {
    memmove(__dest,__src,__n);
  }
  __dest_00 = (void *)(__n + 0x10 + (int)__dest);
  if (pvVar7 != param_2) {
    __dest_00 = memcpy(__dest_00,param_2,(int)pvVar7 - (int)param_2);
  }
  if (__src != (void *)0x0) {
    operator_delete(__src);
  }
  *(void **)this = __dest;
  *(int *)(this + 4) = (int)__dest_00 + ((int)pvVar7 - (int)param_2);
  *(int *)(this + 8) = iVar6;
  return;
}



void dtbased_tk_create(void)

{
  dtbased_tk_create();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void get_debug_level(char *param_1)

{
  get_debug_level(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nn_sleepms(int param_1)

{
  nn_sleepms(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float sqrtf(float __x)

{
  float fVar1;
  
  fVar1 = sqrtf(__x);
  return fVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sem_init(sem_t *__sem,int __pshared,uint __value)

{
  int iVar1;
  
  iVar1 = sem_init(__sem,__pshared,__value);
  return iVar1;
}



void human_pose_process(human_pose_t *param_1,ax_yuv_t *param_2,ax_box_t *param_3,int *param_4,
                       float param_5)

{
  human_pose_process(param_1,param_2,param_3,param_4,param_5);
  return;
}



void __thiscall
std::vector<int,std::allocator<int>>::operator=
          (vector<int,std::allocator<int>> *this,vector *param_1)

{
  operator=(this,param_1);
  return;
}



classify_in_t * __thiscall classify_in_t::~classify_in_t(classify_in_t *this)

{
  if (*(void **)(this + 0xc) != (void *)0x0) {
    operator_delete(*(void **)(this + 0xc));
  }
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this);
  }
  return this;
}



void __thiscall ax_tensor_t::ax_tensor_t(ax_tensor_t *this)

{
  ax_tensor_t(this);
  return;
}



void kpt_smooth_process(void)

{
  kpt_smooth_process();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::
     __heap_select<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
               (void)

{
  __heap_select<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
            ();
  return;
}



vector<std::vector<std::vector<float,std::allocator<float>>,std::allocator<std::vector<float,std::allocator<float>>>>,std::allocator<std::vector<std::vector<float,std::allocator<float>>,std::allocator<std::vector<float,std::allocator<float>>>>>>
* __thiscall
std::
vector<std::vector<std::vector<float,std::allocator<float>>,std::allocator<std::vector<float,std::allocator<float>>>>,std::allocator<std::vector<std::vector<float,std::allocator<float>>,std::allocator<std::vector<float,std::allocator<float>>>>>>
::~vector(vector<std::vector<std::vector<float,std::allocator<float>>,std::allocator<std::vector<float,std::allocator<float>>>>,std::allocator<std::vector<std::vector<float,std::allocator<float>>,std::allocator<std::vector<float,std::allocator<float>>>>>>
          *this)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *pvVar4;
  void *pvVar5;
  void *pvVar6;
  
  pvVar1 = *(void **)this;
  pvVar6 = *(void **)(this + 4);
  if (pvVar1 != pvVar6) {
    pvVar4 = (void *)((int)pvVar1 + 0xc);
    pvVar5 = pvVar4;
    while( true ) {
      puVar3 = *(undefined4 **)((int)pvVar1 + 4);
      puVar2 = *(undefined4 **)((int)pvVar4 + -0xc);
      if (puVar2 != puVar3) {
        do {
          pvVar1 = (void *)*puVar2;
          puVar2 = puVar2 + 3;
          if (pvVar1 != (void *)0x0) {
            operator_delete(pvVar1);
          }
        } while (puVar3 != puVar2);
        puVar3 = *(undefined4 **)((int)pvVar4 + -0xc);
      }
      if (puVar3 != (undefined4 *)0x0) {
        operator_delete(puVar3);
      }
      pvVar4 = (void *)((int)pvVar4 + 0xc);
      if (pvVar6 == pvVar5) break;
      pvVar1 = pvVar5;
      pvVar5 = (void *)((int)pvVar5 + 0xc);
    }
    pvVar6 = *(void **)this;
  }
  if (pvVar6 != (void *)0x0) {
    operator_delete(pvVar6);
  }
  return this;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::
     __insertion_sort<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
               (void)

{
  __insertion_sort<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
            ();
  return;
}



void __aeabi_idivmod(void)

{
  __aeabi_idivmod();
  return;
}



void campan_face_feature_release(nn_face_feature_t *param_1)

{
  if (param_1 == (nn_face_feature_t *)0x0) {
    return;
  }
  face_feature_release(param_1);
  return;
}



void box_overlap<ax_box_t>(void)

{
  box_overlap<ax_box_t>();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nn_thread_exit(ulong *param_1)

{
  nn_thread_exit(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::
     __adjust_heap<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,int,int,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
               (void)

{
  __adjust_heap<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,int,int,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
            ();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void buffer_pool_release(buffer_pool_t *param_1)

{
  buffer_pool_release(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * calloc(size_t __nmemb,size_t __size)

{
  void *pvVar1;
  
  pvVar1 = calloc(__nmemb,__size);
  return pvVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void flush_model_temp_memory(void)

{
  flush_model_temp_memory();
  return;
}



uint * clip_rect_adaptive<ax_rect_t,ax_size_t>
                 (uint *param_1,uint param_2,uint param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if ((int)param_2 < 0) {
    uVar1 = param_4 - 1;
    param_2 = 0;
  }
  else {
    uVar1 = (param_4 + param_2) - 1;
  }
  uVar6 = param_6 - 1;
  if ((int)param_3 < 0) {
    uVar3 = param_5 - 1;
    param_3 = 0;
  }
  else {
    uVar3 = (param_5 + param_3) - 1;
  }
  uVar5 = param_7 - 1;
  if (param_6 <= (int)uVar1) {
    param_2 = uVar6 - param_4;
    uVar1 = uVar6;
  }
  if (param_7 <= (int)uVar3) {
    param_3 = uVar5 - param_5;
    uVar3 = uVar5;
  }
  param_2 = param_2 & ~((int)param_2 >> 0x1f);
  param_3 = param_3 & ~((int)param_3 >> 0x1f);
  uVar1 = uVar1 & ~((int)uVar1 >> 0x1f);
  if ((int)uVar6 <= (int)param_2) {
    param_2 = uVar6;
  }
  uVar3 = uVar3 & ~((int)uVar3 >> 0x1f);
  if ((int)uVar5 <= (int)param_3) {
    param_3 = uVar5;
  }
  if ((int)uVar6 < (int)uVar1) {
    iVar2 = uVar6 - param_2;
  }
  else {
    iVar2 = uVar1 - param_2;
  }
  if ((int)uVar5 < (int)uVar3) {
    iVar4 = uVar5 - param_3;
  }
  else {
    iVar4 = uVar3 - param_3;
  }
  param_1[2] = iVar2 + 1;
  param_1[3] = iVar4 + 1;
  *param_1 = param_2;
  param_1[1] = param_3;
  return param_1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void box_smooth_create(int param_1)

{
  box_smooth_create(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nn_state_release(nn_state_t *param_1)

{
  nn_state_release(param_1);
  return;
}



void __aeabi_idiv(void)

{
  __aeabi_idiv();
  return;
}



void head_person_match(campan_feature_match_t *param_1,nn_campan_persons_t *param_2,
                      nn_campan_heads_t *param_3)

{
  head_person_match(param_1,param_2,param_3);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sem_post(sem_t *__sem)

{
  int iVar1;
  
  iVar1 = sem_post(__sem);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float expf(float __x)

{
  float fVar1;
  
  fVar1 = expf(__x);
  return fVar1;
}



void clear_tracking_person_buffer(campan_feature_match_t *param_1)

{
  clear_tracking_person_buffer(param_1);
  return;
}



void __cxa_rethrow(void)

{
  __cxa_rethrow();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void AX_MALLOC_RECORD(int param_1)

{
  AX_MALLOC_RECORD(param_1);
  return;
}



void campan_set_second_person_head(campan_feature_match_t *param_1,nn_campan_person_head_t *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  undefined4 *puVar4;
  _List_node_base *p_Var5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  _List_node_base *p_Var9;
  undefined4 *puVar10;
  _List_node_base *p_Var11;
  void *pvVar12;
  int *piVar13;
  _List_node_base *p_Stack_5c;
  _List_node_base *p_Stack_58;
  int iStack_54;
  _List_node_base *p_Stack_50;
  _List_node_base *p_Stack_4c;
  int iStack_48;
  int iStack_44;
  undefined4 uStack_40;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  
  __android_log_print(6,"CAMPAN_ATTR","set second tracking person head");
  FUN_000202a0(param_2);
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x318));
  iStack_44 = *(int *)param_2;
  iStack_48 = 0;
  for (piVar7 = (int *)**(int **)(param_1 + 0x2c8); p_Stack_50 = (_List_node_base *)&p_Stack_50,
      p_Stack_4c = (_List_node_base *)&p_Stack_50, piVar7 != *(int **)(param_1 + 0x2c8);
      piVar7 = (int *)*piVar7) {
    if (iStack_44 == piVar7[5]) {
      p_Var11 = (_List_node_base *)(piVar7 + 2);
      if ((p_Var11 != (_List_node_base *)&p_Stack_50) &&
         (p_Var9 = (_List_node_base *)piVar7[2], p_Var11 != p_Var9)) {
        iStack_54 = 0;
        p_Stack_5c = (_List_node_base *)&p_Stack_5c;
        p_Stack_58 = (_List_node_base *)&p_Stack_5c;
        do {
          p_Var5 = (_List_node_base *)operator_new(0x180);
          memcpy(p_Var5 + 8,p_Var9 + 8,0x178);
          std::__detail::_List_node_base::_M_hook(p_Var5);
          p_Var9 = *(_List_node_base **)p_Var9;
          iStack_54 = iStack_54 + 1;
        } while (p_Var11 != p_Var9);
        if (p_Stack_5c != (_List_node_base *)&p_Stack_5c) {
          std::__detail::_List_node_base::_M_transfer((_List_node_base *)&p_Stack_50,p_Stack_5c);
          iStack_48 = iStack_48 + iStack_54;
          iStack_54 = 0;
          p_Var11 = p_Stack_5c;
          while (p_Var11 != (_List_node_base *)&p_Stack_5c) {
            p_Var9 = *(_List_node_base **)p_Var11;
            operator_delete(p_Var11);
            p_Var11 = p_Var9;
          }
        }
      }
      break;
    }
  }
  piVar13 = *(int **)(param_1 + 0x2cc);
  piVar7 = (int *)*piVar13;
  if (piVar7 != piVar13) {
    bVar3 = false;
    do {
      piVar2 = piVar7 + 5;
      piVar7 = (int *)*piVar7;
      if (*piVar2 == *(int *)param_2) {
        bVar3 = true;
      }
    } while (piVar7 != piVar13);
    if (bVar3) {
      __android_log_print(6,"CAMPAN_ATTR","second head already exist %d");
      goto LAB_00020b24;
    }
  }
  p_Var9 = (_List_node_base *)operator_new(0x30);
  *(undefined4 *)(p_Var9 + 0x10) = 0;
  *(_List_node_base **)(p_Var9 + 8) = p_Var9 + 8;
  *(_List_node_base **)(p_Var9 + 0xc) = p_Var9 + 8;
  p_Var11 = p_Stack_50;
  while (p_Var11 != (_List_node_base *)&p_Stack_50) {
    p_Var5 = (_List_node_base *)operator_new(0x180);
    memcpy(p_Var5 + 8,p_Var11 + 8,0x178);
    std::__detail::_List_node_base::_M_hook(p_Var5);
    p_Var11 = *(_List_node_base **)p_Var11;
    *(int *)(p_Var9 + 0x10) = *(int *)(p_Var9 + 0x10) + 1;
  }
  *(undefined4 *)(p_Var9 + 0x18) = uStack_40;
  *(int *)(p_Var9 + 0x14) = iStack_44;
  *(undefined4 *)(p_Var9 + 0x28) = uStack_30;
  *(undefined4 *)(p_Var9 + 0x20) = uStack_38;
  *(undefined4 *)(p_Var9 + 0x24) = uStack_34;
  std::__detail::_List_node_base::_M_hook(p_Var9);
  iVar6 = piVar13[2];
  uVar8 = iVar6 + 1;
  piVar13[2] = uVar8;
  if (4 < uVar8) {
    pvVar12 = (void *)*piVar13;
    piVar13[2] = iVar6;
    std::__detail::_List_node_base::_M_unhook();
    puVar1 = (undefined4 *)((int)pvVar12 + 8);
    puVar4 = (undefined4 *)*puVar1;
    while (puVar1 != puVar4) {
      puVar10 = (undefined4 *)*puVar4;
      operator_delete(puVar4);
      puVar4 = puVar10;
    }
    operator_delete(pvVar12);
  }
LAB_00020b24:
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x318));
  __android_log_print(6,"CAMPAN_ATTR","set second person finish");
  p_Var11 = p_Stack_50;
  while (p_Var11 != (_List_node_base *)&p_Stack_50) {
    p_Var9 = *(_List_node_base **)p_Var11;
    operator_delete(p_Var11);
    p_Var11 = p_Var9;
  }
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = memcpy(__dest,__src,__n);
  return pvVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void axnn_plg_close(ax_nna_ctx_plg *param_1)

{
  axnn_plg_close(param_1);
  return;
}



void nn_campan_cmd_interface(void)

{
  nn_hermes_cmd();
  return;
}



void nn_campan_cmd_interface(void)

{
  nn_hermes_cmd();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__throw_out_of_range_fmt(char *param_1,...)

{
                    /* WARNING: Subroutine does not return */
  __throw_out_of_range_fmt(param_1);
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = strlen(__s);
  return sVar1;
}



void handpose_release(handpose_t *param_1)

{
  if (param_1 == (handpose_t *)0x0) {
    return;
  }
  classify_model_release(*(batch_classify_model_t **)param_1);
  classify_model_release(*(batch_classify_model_t **)(param_1 + 4));
  classify_model_release(*(batch_classify_model_t **)(param_1 + 8));
  classify_model_release(*(batch_classify_model_t **)(param_1 + 0xc));
  AX_FREE_RECORD(param_1);
  return;
}



void __thiscall std::vector<int,std::allocator<int>>::_M_realloc_insert<int>(void)

{
  _M_realloc_insert<int>();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void retina_process(retina_t *param_1,retina_in_t *param_2,retina_out_t *param_3)

{
  retina_process(param_1,param_2,param_3);
  return;
}



void __thiscall
std::vector<int,std::allocator<int>>::_M_fill_assign
          (vector<int,std::allocator<int>> *this,uint param_1,int *param_2)

{
  _M_fill_assign(this,param_1,param_2);
  return;
}



void __thiscall
std::__cxx11::_List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>>::
_M_clear(_List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>> *this)

{
  _M_clear(this);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
  int iVar1;
  
  iVar1 = sprintf(__s,__format);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void getContext(ax_nna_ctx_plg *param_1,_vx_context **param_2)

{
  getContext(param_1,param_2);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void campan_feature_match_create(void)

{
  campan_feature_match_create();
  return;
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */

void handpose_process_new
               (handpose_t *param_1,nn_campan_hands_t *param_2,ax_yuv_t *param_3,int param_4,
               int param_5,int param_6)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  vector *pvVar6;
  int iVar7;
  int extraout_r1;
  undefined4 uVar8;
  uint uVar9;
  double *pdVar10;
  int *piVar11;
  int *piVar12;
  undefined4 uVar13;
  uint uVar14;
  undefined8 *puVar15;
  float *pfVar16;
  int iVar17;
  void *pvVar18;
  undefined4 uVar19;
  int iVar20;
  int *piVar21;
  ax_tensor_t *paVar22;
  ax_tensor_t *paVar23;
  undefined4 *puVar24;
  size_t __n;
  ax_tensor_t *paVar25;
  undefined4 *puVar26;
  int iVar27;
  int *piVar28;
  void *pvVar29;
  uint uVar30;
  void *pvVar31;
  int *piVar32;
  void *pvVar33;
  int iVar34;
  uint uVar35;
  uint uVar36;
  float fVar37;
  float fVar38;
  double dVar39;
  double dVar40;
  uint uStack_208;
  int iStack_200;
  uint uStack_1ec;
  void *pvStack_1cc;
  uint *puStack_1c8;
  uint *puStack_1c4;
  double *pdStack_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  void *pvStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  double adStack_1a8 [2];
  void *pvStack_198;
  undefined4 *puStack_194;
  undefined4 *puStack_190;
  int iStack_18c;
  int *piStack_188;
  int *piStack_184;
  undefined4 uStack_180;
  void *pvStack_17c;
  void *pvStack_178;
  undefined4 uStack_174;
  int *piStack_170;
  int *piStack_16c;
  undefined4 uStack_168;
  void *pvStack_164;
  void *pvStack_160;
  undefined4 uStack_15c;
  void *pvStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  void *pvStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  void *pvStack_118;
  int iStack_114;
  int iStack_110;
  void *pvStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  int iStack_c0;
  int iStack_bc;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined8 uStack_60;
  
  uStack_208 = *(uint *)(param_2 + 4);
  uStack_140 = *(undefined4 *)param_3;
  uStack_13c = *(undefined4 *)(param_3 + 4);
  uStack_138 = *(undefined4 *)(param_3 + 8);
  uStack_134 = *(undefined4 *)(param_3 + 0xc);
  uStack_130 = *(undefined4 *)(param_3 + 0x10);
  uStack_12c = *(undefined4 *)(param_3 + 0x14);
  uStack_128 = *(undefined4 *)(param_3 + 0x18);
  uStack_124 = *(undefined4 *)(param_3 + 0x1c);
  uStack_120 = *(undefined4 *)(param_3 + 0x20);
  pvStack_158 = (void *)0x0;
  uStack_154 = 0;
  uStack_150 = 0;
  pvStack_14c = (void *)0x0;
  uStack_148 = 0;
  uStack_144 = 0;
  uStack_11c = 0;
  pvStack_1cc = (void *)0x0;
  puStack_1c8 = (uint *)0x0;
  puStack_1c4 = (uint *)0x0;
  if (param_6 != 0) {
    pvStack_198 = (void *)0x0;
    uStack_d8 = uStack_d8 & 0xffffffff00000000;
    puStack_194 = (undefined4 *)0x0;
    puStack_190 = (undefined4 *)0x0;
    piStack_188 = (int *)0x0;
    piStack_184 = (int *)0x0;
    uStack_180 = 0;
    std::vector<int,std::allocator<int>>::_M_fill_assign
              ((vector<int,std::allocator<int>> *)&piStack_188,uStack_208,(int *)&uStack_d8);
    uStack_208 = *(uint *)(param_2 + 4);
    if (1 < (int)uStack_208) {
      if (piStack_188 == piStack_184) {
        uVar9 = 0;
      }
      else {
        uStack_1ec = 0;
        do {
          iVar20 = uStack_1ec * 4;
          uVar9 = uStack_1ec + 1;
          if (*(int *)((int)piStack_188 + iVar20) == 0) {
            iVar7 = *(int *)param_2 + uVar9 * 0x2c + -0x2c;
            piStack_170 = *(int **)(iVar7 + 4);
            piStack_16c = *(int **)(iVar7 + 8);
            uStack_168 = *(undefined4 *)(iVar7 + 0xc);
            pvStack_164 = *(void **)(iVar7 + 0x10);
            if ((int)uVar9 < (int)uStack_208) {
              uVar35 = uVar9;
              iVar5 = iVar20;
              if ((uint)((int)piStack_184 - (int)piStack_188 >> 2) <= uVar9) {
LAB_00025698:
                    /* WARNING: Subroutine does not return */
                std::__throw_out_of_range_fmt
                          ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)"
                           ,uVar35);
              }
              while( true ) {
                iVar5 = iVar5 + 4;
                if (*(int *)((int)piStack_188 + iVar5) == 0) {
                  iVar17 = uVar35 * 0x2c + *(int *)param_2;
                  pvVar31 = *(void **)(iVar17 + 4);
                  iVar27 = *(int *)(iVar17 + 8);
                  iVar34 = *(int *)(iVar17 + 0xc);
                  pvVar33 = *(void **)(iVar17 + 0x10);
                  pvStack_118 = pvVar31;
                  iStack_114 = iVar27;
                  iStack_110 = iVar34;
                  pvStack_10c = pvVar33;
                  fVar38 = iou<ax_box_t>(piStack_170,piStack_16c,uStack_168,pvStack_164,pvVar31,
                                         iVar27,iVar34,pvVar33);
                  if (fVar38 != 0.0 && fVar38 < 0.0 == NAN(fVar38)) {
                    pvVar18 = *(void **)(iVar7 + 4);
                    if ((int)pvVar31 <= (int)*(void **)(iVar7 + 4)) {
                      pvVar18 = pvVar31;
                    }
                    uStack_d8 = CONCAT44(pvVar18,0xffffffff);
                    iStack_c0 = *(int *)(iVar7 + 8);
                    if (iVar27 <= *(int *)(iVar7 + 8)) {
                      iStack_c0 = iVar27;
                    }
                    iStack_bc = *(int *)(iVar7 + 0xc);
                    if (*(int *)(iVar7 + 0xc) < iVar34) {
                      iStack_bc = iVar34;
                    }
                    uStack_d0 = CONCAT44(iStack_bc,iStack_c0);
                    pvVar31 = *(void **)(iVar7 + 0x10);
                    if ((int)*(void **)(iVar7 + 0x10) < (int)pvVar33) {
                      pvVar31 = pvVar33;
                    }
                    uStack_c8 = CONCAT44(pvVar18,pvVar31);
                    uStack_b8 = CONCAT44(uStack_b8._4_4_,pvVar31);
                    if (puStack_194 == puStack_190) {
                      std::vector<nn_campan_hand_t,std::allocator<nn_campan_hand_t>>::
                      _M_realloc_insert<nn_campan_hand_t_const&>
                                ((vector<nn_campan_hand_t,std::allocator<nn_campan_hand_t>> *)
                                 &pvStack_198,puStack_194,&uStack_d8);
                    }
                    else {
                      if (puStack_194 != (undefined4 *)0x0) {
                        *puStack_194 = 0xffffffff;
                        puStack_194[1] = pvVar18;
                        puStack_194[2] = iStack_c0;
                        puStack_194[3] = iStack_bc;
                        puStack_194[4] = pvVar31;
                        puStack_194[5] = pvVar18;
                        puStack_194[6] = iStack_c0;
                        puStack_194[7] = iStack_bc;
                        puStack_194[8] = pvVar31;
                        puStack_194[9] = uStack_b8._4_4_;
                        puStack_194[10] = (undefined4)uStack_b0;
                      }
                      puStack_194 = puStack_194 + 0xb;
                    }
                    uVar4 = (int)piStack_184 - (int)piStack_188 >> 2;
                    if (uVar4 <= uStack_1ec) {
                    /* WARNING: Subroutine does not return */
                      std::__throw_out_of_range_fmt
                                (
                                "vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)"
                                );
                    }
                    *(undefined4 *)((int)piStack_188 + iVar20) = 1;
                    if (uVar4 <= uVar35) {
                    /* WARNING: Subroutine does not return */
                      std::__throw_out_of_range_fmt
                                ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)"
                                 ,uVar35);
                    }
                    *(undefined4 *)((int)piStack_188 + iVar5) = 1;
                    uStack_208 = *(uint *)(param_2 + 4);
                  }
                }
                uVar35 = uVar35 + 1;
                if ((int)uStack_208 <= (int)uVar35) break;
                if ((uint)((int)piStack_184 - (int)piStack_188 >> 2) <= uVar35) goto LAB_00025698;
              }
            }
          }
          if ((int)(uStack_208 + -1) <= (int)uVar9) goto LAB_000255bc;
          uStack_1ec = uVar9;
        } while (uVar9 < (uint)((int)piStack_184 - (int)piStack_188 >> 2));
      }
                    /* WARNING: Subroutine does not return */
      std::__throw_out_of_range_fmt
                ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",uVar9);
    }
LAB_000255bc:
    if (0 < (int)puStack_194 - (int)pvStack_198) {
      pvVar31 = *(void **)param_2;
      iVar20 = uStack_208 + 1;
      iVar7 = iVar20 * 0x2c;
      uVar35 = 0;
      uVar9 = uStack_208;
      uStack_208 = iVar20 * 0x58;
      do {
        puVar24 = (undefined4 *)(uVar35 * 0x2c + (int)pvStack_198);
        if (pvVar31 == (void *)0x0) {
          if (0 < iVar7) {
            __n = 0;
LAB_000255f8:
            pvVar31 = (void *)AX_MALLOC_RECORD(uStack_208);
            if (*(void **)param_2 != (void *)0x0) {
              memcpy(pvVar31,*(void **)param_2,__n);
              AX_FREE_RECORD(*(void **)param_2);
            }
            uVar9 = *(uint *)(param_2 + 4);
            *(void **)param_2 = pvVar31;
          }
        }
        else {
          __n = *(size_t *)((int)pvVar31 + -4);
          if ((int)__n < iVar7) goto LAB_000255f8;
        }
        uVar35 = uVar35 + 1;
        puVar26 = (undefined4 *)(uVar9 * 0x2c + (int)pvVar31);
        uVar8 = puVar24[1];
        uVar13 = puVar24[2];
        uVar19 = puVar24[3];
        *puVar26 = *puVar24;
        puVar26[1] = uVar8;
        puVar26[2] = uVar13;
        puVar26[3] = uVar19;
        uVar8 = puVar24[5];
        uVar13 = puVar24[6];
        uVar19 = puVar24[7];
        puVar26[4] = puVar24[4];
        puVar26[5] = uVar8;
        puVar26[6] = uVar13;
        puVar26[7] = uVar19;
        uVar8 = puVar24[9];
        uVar13 = puVar24[10];
        uVar9 = ((int)puStack_194 - (int)pvStack_198 >> 2) * -0x45d1745d;
        puVar26[8] = puVar24[8];
        puVar26[9] = uVar8;
        puVar26[10] = uVar13;
        *(int *)(param_2 + 4) = iVar20;
        if ((int)uVar9 <= (int)uVar35) break;
        iVar7 = iVar7 + 0x2c;
        uStack_208 = uStack_208 + 0x58;
        if (uVar9 <= uVar35) {
                    /* WARNING: Subroutine does not return */
          std::__throw_out_of_range_fmt
                    ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                     uVar35,uVar9);
        }
        uVar9 = iVar20;
        iVar20 = iVar20 + 1;
      } while( true );
    }
    if (piStack_188 != (int *)0x0) {
      operator_delete(piStack_188);
    }
    if (pvStack_198 != (void *)0x0) {
      operator_delete(pvStack_198);
    }
    uStack_208 = *(uint *)(param_2 + 4);
  }
  if (0 < (int)uStack_208) {
    iVar20 = 0;
    do {
      while( true ) {
        iVar7 = iVar20 * 0x2c + *(int *)param_2;
        uVar36 = *(int *)(param_3 + 0x1c) - 1;
        uVar9 = *(uint *)(iVar7 + 8);
        uVar35 = *(uint *)(iVar7 + 4);
        uVar30 = *(int *)(param_3 + 0x18) - 1;
        uVar14 = (*(int *)(iVar7 + 0xc) - *(int *)(iVar7 + 4)) + uVar35;
        uVar4 = (*(int *)(iVar7 + 0x10) - *(int *)(iVar7 + 8)) + uVar9;
        uVar9 = uVar9 & ~((int)uVar9 >> 0x1f);
        uVar35 = uVar35 & ~((int)uVar35 >> 0x1f);
        if ((int)uVar36 <= (int)uVar9) {
          uVar9 = uVar36;
        }
        if ((int)uVar30 <= (int)uVar35) {
          uVar35 = uVar30;
        }
        uVar14 = uVar14 & ~((int)uVar14 >> 0x1f);
        uVar4 = uVar4 & ~((int)uVar4 >> 0x1f);
        if ((int)uVar30 < (int)uVar14) {
          iVar7 = uVar30 - uVar35;
        }
        else {
          iVar7 = uVar14 - uVar35;
        }
        if ((int)uVar36 < (int)uVar4) {
          iVar5 = uVar36 - uVar9;
        }
        else {
          iVar5 = uVar4 - uVar9;
        }
        uStack_d0 = CONCAT44(iVar5 + 1U,iVar7 + 1U);
        uStack_d8 = CONCAT44(uVar9,uVar35);
        if (puStack_1c8 != puStack_1c4) break;
        std::vector<ax_rect_t,std::allocator<ax_rect_t>>::_M_realloc_insert<ax_rect_t_const&>
                  ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&pvStack_1cc,puStack_1c8,
                   &uStack_d8);
        iVar20 = iVar20 + 1;
        uStack_208 = *(uint *)(param_2 + 4);
        if ((int)uStack_208 <= iVar20) goto LAB_00024ece;
      }
      if (puStack_1c8 != (uint *)0x0) {
        *puStack_1c8 = uVar35;
        puStack_1c8[1] = uVar9;
        puStack_1c8[2] = iVar7 + 1U;
        puStack_1c8[3] = iVar5 + 1U;
      }
      puStack_1c8 = puStack_1c8 + 4;
      iVar20 = iVar20 + 1;
    } while (iVar20 < (int)uStack_208);
  }
LAB_00024ece:
  std::vector<ax_rect_t,std::allocator<ax_rect_t>>::operator=
            ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&pvStack_158,(vector *)&pvStack_1cc);
  piStack_188 = (int *)0x0;
  piStack_184 = (int *)0x0;
  uStack_180 = 0;
  pvStack_17c = (void *)0x0;
  pvStack_178 = (void *)0x0;
  uStack_174 = 0;
  batch_classify_process
            (*(batch_classify_model_t **)param_1,(classify_in_t *)&pvStack_158,
             (classify_out_t *)&piStack_188,0);
  DAT_0003a680 = DAT_0003a680 + 1;
  if (0 < (int)piStack_184 - (int)piStack_188) {
    pvVar6 = (vector *)*piStack_188;
    piVar21 = *(int **)param_2;
    if ((vector *)piStack_188[1] != pvVar6) {
      uVar9 = 0;
      do {
        pdStack_1c0 = (double *)0x0;
        uStack_1bc = 0;
        uStack_1b8 = 0;
        softmax(pvVar6,(vector *)&pdStack_1c0,0xf);
        iVar5 = 1;
        iVar7 = 0;
        dVar40 = *pdStack_1c0;
        iVar20 = extraout_r1;
        pdVar10 = pdStack_1c0;
        do {
          pdVar10 = pdVar10 + 1;
          dVar39 = *pdVar10;
          bVar1 = dVar39 < dVar40;
          bVar2 = dVar39 == dVar40;
          bVar3 = NAN(dVar40);
          if (!bVar2 && bVar1 == (NAN(dVar39) || bVar3)) {
            iVar20 = iVar5;
            dVar40 = dVar39;
          }
          iVar5 = iVar5 + 1;
          if (bVar2 || bVar1 != (NAN(dVar39) || bVar3)) {
            iVar20 = iVar7;
          }
          iVar7 = iVar20;
          iVar20 = iVar7;
        } while (iVar5 != 0xf);
        puVar15 = &uStack_d8;
        do {
          *puVar15 = 0x3fecccccc0000000;
          puVar15 = puVar15 + 1;
        } while (&uStack_60 != puVar15);
        uStack_80 = 0x40000000;
        uStack_7c = 0x3fe33333;
        uStack_d8 = 0x3fe6666660000000;
        uStack_d0 = 0x3fec28f5c0000000;
        uStack_c8 = 0x3fed70a3e0000000;
        uStack_b8 = 0x3fecccccc0000000;
        uStack_b0 = 0x3fecccccc0000000;
        uStack_a0 = 0x3fecccccc0000000;
        uStack_98 = 0x3fecccccc0000000;
        uStack_90 = 0x3fed70a3e0000000;
        uStack_88 = 0x3fecccccc0000000;
        iStack_c0 = -0x60000000;
        iStack_bc = 0x3fe99999;
        uStack_a8 = 0x40000000;
        uStack_a4 = 0x3feb3333;
        if ((int)((uint)((double)(&uStack_d8)[iVar7] < dVar40) << 0x1f) < 0) {
          piVar21[9] = iVar7;
          if (*piVar21 == -1) {
            if (iVar7 != 0xb) {
              piVar21[9] = 0;
            }
          }
          else if (iVar7 == 0xb) {
            if ((int)((uint)(dVar40 < 0.85) << 0x1f) < 0) {
              piVar21[9] = 0;
              goto LAB_0002500a;
            }
          }
          else if ((param_4 != 0) && (iVar7 == 0)) goto LAB_000250c2;
        }
        else {
          piVar21[9] = 0;
          if (*piVar21 == -1) {
            piVar21[9] = 0;
          }
          else {
LAB_0002500a:
            if (param_4 != 0) {
LAB_000250c2:
              iVar20 = handpose_process_old(param_1,piVar21 + 1,param_3);
              piVar21[9] = iVar20;
            }
          }
        }
        if (((param_5 != 0) && (piVar21[9] == 9)) && (*piVar21 != -1)) {
          iVar20 = handpose_process_two_cls(param_1,piVar21 + 1,param_3);
          piVar21[9] = iVar20;
        }
        iVar20 = *(int *)(param_1 + 0xc);
        piVar21[10] = 0;
        if (((iVar20 != 0) && (*piVar21 != -1)) && (piVar21[9] == 1)) {
          pvStack_118 = (void *)0x0;
          iStack_114 = 0;
          iStack_110 = 0;
          uStack_100 = *(undefined4 *)param_3;
          uStack_fc = *(undefined4 *)(param_3 + 4);
          uStack_f8 = *(undefined4 *)(param_3 + 8);
          uStack_f4 = *(undefined4 *)(param_3 + 0xc);
          pvStack_10c = (void *)0x0;
          uStack_108 = 0;
          uStack_104 = 0;
          uStack_f0 = *(undefined4 *)(param_3 + 0x10);
          uStack_ec = *(undefined4 *)(param_3 + 0x14);
          uStack_e8 = *(undefined4 *)(param_3 + 0x18);
          uStack_e4 = *(undefined4 *)(param_3 + 0x1c);
          uStack_dc = 0;
          uStack_e0 = *(undefined4 *)(param_3 + 0x20);
          pvVar31 = (void *)(*(int *)(param_3 + 0x18) - 1);
          pvStack_198 = (void *)(piVar21[1] & ~(piVar21[1] >> 0x1f));
          puStack_194 = (undefined4 *)(piVar21[2] & ~(piVar21[2] >> 0x1f));
          puVar24 = (undefined4 *)(*(int *)(param_3 + 0x1c) + -1);
          pvStack_1b4 = (void *)0x0;
          uStack_1b0 = 0;
          uStack_1ac = 0;
          if ((int)pvVar31 <= (int)pvStack_198) {
            pvStack_198 = pvVar31;
          }
          if ((int)puVar24 <= (int)puStack_194) {
            puStack_194 = puVar24;
          }
          uVar35 = piVar21[3] & ~(piVar21[3] >> 0x1f);
          uVar4 = piVar21[4] & ~(piVar21[4] >> 0x1f);
          if ((int)pvVar31 < (int)uVar35) {
            iVar20 = (int)pvVar31 - (int)pvStack_198;
          }
          else {
            iVar20 = uVar35 - (int)pvStack_198;
          }
          if ((int)puVar24 < (int)uVar4) {
            iStack_18c = (int)puVar24 - (int)puStack_194;
          }
          else {
            iStack_18c = uVar4 - (int)puStack_194;
          }
          puStack_190 = (undefined4 *)(iVar20 + 1);
          iStack_18c = iStack_18c + 1;
          std::vector<ax_rect_t,std::allocator<ax_rect_t>>::_M_realloc_insert<ax_rect_t_const&>
                    ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&pvStack_1b4,0,&pvStack_198);
          std::vector<ax_rect_t,std::allocator<ax_rect_t>>::operator=
                    ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&pvStack_118,
                     (vector *)&pvStack_1b4);
          piStack_170 = (int *)0x0;
          piStack_16c = (int *)0x0;
          uStack_168 = 0;
          pvStack_164 = (void *)0x0;
          pvStack_160 = (void *)0x0;
          uStack_15c = 0;
          batch_classify_process
                    (*(batch_classify_model_t **)(param_1 + 0xc),(classify_in_t *)&pvStack_118,
                     (classify_out_t *)&piStack_170,0);
          if (piStack_16c == piStack_170) {
                    /* WARNING: Subroutine does not return */
            std::__throw_out_of_range_fmt
                      ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0
                       ,0);
          }
          piVar11 = (int *)*piStack_170;
          if ((int *)piStack_170[1] == piVar11) {
                    /* WARNING: Subroutine does not return */
            std::__throw_out_of_range_fmt
                      ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0
                      );
          }
          pfVar16 = (float *)*piVar11;
          if ((uint)(piVar11[1] - (int)pfVar16 >> 2) < 2) {
                    /* WARNING: Subroutine does not return */
            std::__throw_out_of_range_fmt
                      ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",1
                      );
          }
          fVar37 = *pfVar16;
          fVar38 = pfVar16[1];
          bVar1 = fVar38 != fVar37;
          bVar2 = fVar38 < fVar37 == (NAN(fVar38) || NAN(fVar37));
          if (!bVar1 || !bVar2) {
            fVar38 = fVar37;
          }
          uVar35 = (uint)(bVar1 && bVar2);
          fVar38 = expf(-fVar38);
          pvVar31 = pvStack_160;
          adStack_1a8[0] = 0.5;
          adStack_1a8[1] = 0.5;
          dVar39 = adStack_1a8[uVar35];
          dVar40 = (double)(1.0 / (fVar38 + 1.0));
          iStack_200 = 1;
          if (dVar40 != dVar39 && dVar40 < dVar39 == (NAN(dVar40) || NAN(dVar39))) {
            iStack_200 = uVar35 + 1;
          }
          pvVar33 = pvStack_160;
          if (pvStack_164 != pvStack_160) {
            pvVar29 = (void *)((int)pvStack_164 + 0xc);
            pvVar33 = pvStack_164;
            pvVar18 = pvVar29;
            while( true ) {
              paVar25 = *(ax_tensor_t **)((int)pvVar33 + 4);
              paVar22 = *(ax_tensor_t **)((int)pvVar29 + -0xc);
              if (*(ax_tensor_t **)((int)pvVar29 + -0xc) != paVar25) {
                do {
                  paVar23 = paVar22 + 0x30;
                  ax_tensor_t::~ax_tensor_t(paVar22);
                  paVar22 = paVar23;
                } while (paVar25 != paVar23);
                paVar25 = *(ax_tensor_t **)((int)pvVar29 + -0xc);
              }
              if (paVar25 != (ax_tensor_t *)0x0) {
                operator_delete(paVar25);
              }
              pvVar29 = (void *)((int)pvVar29 + 0xc);
              pvVar33 = pvStack_164;
              if (pvVar31 == pvVar18) break;
              pvVar33 = pvVar18;
              pvVar18 = (void *)((int)pvVar18 + 0xc);
            }
          }
          if (pvVar33 != (void *)0x0) {
            operator_delete(pvVar33);
          }
          piVar11 = piStack_16c;
          piVar12 = piStack_16c;
          if (piStack_170 != piStack_16c) {
            piVar32 = piStack_170 + 3;
            piVar12 = piStack_170;
            piVar28 = piVar32;
            while( true ) {
              puVar24 = (undefined4 *)piVar12[1];
              puVar26 = (undefined4 *)piVar32[-3];
              if (puVar26 != puVar24) {
                do {
                  if ((void *)*puVar26 != (void *)0x0) {
                    operator_delete((void *)*puVar26);
                  }
                  puVar26 = puVar26 + 3;
                } while (puVar24 != puVar26);
                puVar24 = (undefined4 *)piVar32[-3];
              }
              if (puVar24 != (undefined4 *)0x0) {
                operator_delete(puVar24);
              }
              piVar32 = piVar32 + 3;
              piVar12 = piStack_170;
              if (piVar11 == piVar28) break;
              piVar12 = piVar28;
              piVar28 = piVar28 + 3;
            }
          }
          if (piVar12 != (int *)0x0) {
            operator_delete(piVar12);
          }
          if (pvStack_1b4 != (void *)0x0) {
            operator_delete(pvStack_1b4);
          }
          if (pvStack_10c != (void *)0x0) {
            operator_delete(pvStack_10c);
          }
          if (pvStack_118 != (void *)0x0) {
            operator_delete(pvStack_118);
          }
          piVar21[10] = iStack_200;
        }
        if (pdStack_1c0 != (double *)0x0) {
          operator_delete(pdStack_1c0);
        }
        uVar9 = uVar9 + 1;
        uVar35 = ((int)piStack_184 - (int)piStack_188 >> 2) * -0x55555555;
        if ((int)uVar35 <= (int)uVar9) goto LAB_0002532a;
        piVar21 = (int *)(uVar9 * 0x2c + *(int *)param_2);
        if (uVar35 <= uVar9) {
                    /* WARNING: Subroutine does not return */
          std::__throw_out_of_range_fmt
                    ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                     uVar9);
        }
        pvVar6 = (vector *)piStack_188[uVar9 * 3];
      } while ((vector *)piStack_188[uVar9 * 3 + 1] != pvVar6);
    }
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0);
  }
LAB_0002532a:
  pvVar31 = pvStack_178;
  pvVar33 = pvStack_178;
  if (pvStack_17c != pvStack_178) {
    pvVar29 = (void *)((int)pvStack_17c + 0xc);
    pvVar33 = pvStack_17c;
    pvVar18 = pvVar29;
    while( true ) {
      paVar25 = *(ax_tensor_t **)((int)pvVar33 + 4);
      paVar22 = *(ax_tensor_t **)((int)pvVar29 + -0xc);
      if (*(ax_tensor_t **)((int)pvVar29 + -0xc) != paVar25) {
        do {
          paVar23 = paVar22 + 0x30;
          ax_tensor_t::~ax_tensor_t(paVar22);
          paVar22 = paVar23;
        } while (paVar25 != paVar23);
        paVar25 = *(ax_tensor_t **)((int)pvVar29 + -0xc);
      }
      if (paVar25 != (ax_tensor_t *)0x0) {
        operator_delete(paVar25);
      }
      pvVar29 = (void *)((int)pvVar29 + 0xc);
      pvVar33 = pvStack_17c;
      if (pvVar31 == pvVar18) break;
      pvVar33 = pvVar18;
      pvVar18 = (void *)((int)pvVar18 + 0xc);
    }
  }
  if (pvVar33 != (void *)0x0) {
    operator_delete(pvVar33);
  }
  piVar21 = piStack_184;
  piVar11 = piStack_184;
  if (piStack_188 != piStack_184) {
    piVar28 = piStack_188 + 3;
    piVar11 = piStack_188;
    piVar12 = piVar28;
    while( true ) {
      puVar26 = (undefined4 *)piVar11[1];
      puVar24 = (undefined4 *)piVar28[-3];
      if (puVar24 != puVar26) {
        do {
          if ((void *)*puVar24 != (void *)0x0) {
            operator_delete((void *)*puVar24);
          }
          puVar24 = puVar24 + 3;
        } while (puVar26 != puVar24);
        puVar26 = (undefined4 *)piVar28[-3];
      }
      if (puVar26 != (undefined4 *)0x0) {
        operator_delete(puVar26);
      }
      piVar28 = piVar28 + 3;
      piVar11 = piStack_188;
      if (piVar21 == piVar12) break;
      piVar11 = piVar12;
      piVar12 = piVar12 + 3;
    }
  }
  if (piVar11 != (int *)0x0) {
    operator_delete(piVar11);
  }
  if (pvStack_1cc != (void *)0x0) {
    operator_delete(pvStack_1cc);
  }
  if (pvStack_14c != (void *)0x0) {
    operator_delete(pvStack_14c);
  }
  if (pvStack_158 != (void *)0x0) {
    operator_delete(pvStack_158);
  }
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__detail::_List_node_base::_M_unhook(void)

{
  _M_unhook();
  return;
}



void __cxa_end_catch(void)

{
  __cxa_end_catch();
  return;
}



void AX_MALLOC_INC_TEMP<box_intersect_array_t>(box_intersect_array_t *param_1,int param_2)

{
  AX_MALLOC_INC_TEMP<box_intersect_array_t>(param_1,param_2);
  return;
}



void __gxx_personality_v0(void)

{
  __gxx_personality_v0();
  return;
}



void campan_yolo_humanpose_det_create(void)

{
  campan_yolo_humanpose_det_create();
  return;
}



void human_pose_release(human_pose_t *param_1)

{
  human_pose_release(param_1);
  return;
}



void human_pose_release(human_pose_t *param_1)

{
  human_pose_release(param_1);
  return;
}



void get_person_upper_box(ax_box_t *param_1)

{
  get_person_upper_box(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::
     __insertion_sort<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
               (undefined4 *param_1,undefined4 *param_2,code *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  size_t __n;
  
  if (param_1 == param_2) {
    return;
  }
  if (param_1 + 4 != param_2) {
    __n = 0x10;
    puVar7 = param_1 + 4;
    do {
      while( true ) {
        iVar2 = (*param_3)(*puVar7,puVar7[1],puVar7[2],puVar7[3],*param_1,param_1[1],param_1[2],
                           param_1[3]);
        puVar6 = (undefined4 *)((int)param_1 + __n);
        if (iVar2 != 0) break;
        puVar6 = puVar7 + 4;
        __unguarded_linear_insert<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,__gnu_cxx::__ops::_Val_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
                  (puVar7,param_3);
        __n = __n + 0x10;
        puVar7 = puVar6;
        if (param_2 == puVar6) {
          return;
        }
      }
      uVar1 = *puVar6;
      uVar3 = puVar6[1];
      uVar4 = puVar6[2];
      uVar5 = puVar6[3];
      if (param_1 != puVar7) {
        memmove((void *)((int)puVar7 + (0x10 - __n)),param_1,__n);
      }
      puVar7 = puVar7 + 4;
      __n = __n + 0x10;
      *param_1 = uVar1;
      param_1[1] = uVar3;
      param_1[2] = uVar4;
      param_1[3] = uVar5;
    } while (param_2 != puVar7);
  }
  return;
}



void retina_campan_human_yolov3_create(void)

{
  retina_campan_human_yolov3_create();
  return;
}



void box_smooth_process(void)

{
  box_smooth_process();
  return;
}



void face_feature_dist(nn_campan_face_feature_t *param_1,nn_campan_face_feature_t *param_2)

{
  face_feature_dist(param_1,param_2);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__cxx11::string::_M_create(uint *param_1,uint param_2)

{
  _M_create(param_1,param_2);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::
     __introsort_loop<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,int,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
               (void)

{
  __introsort_loop<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,int,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
            ();
  return;
}



void face_feature_create(void)

{
  face_feature_create();
  return;
}



void headfacedet_create(void)

{
  headfacedet_create();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nn_state_init(nn_state_t *param_1)

{
  nn_state_init(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nn_thread_init(ulong *param_1,_func_void_ptr_void_ptr *param_2,void *param_3,int param_4,
                   int param_5)

{
  nn_thread_init(param_1,param_2,param_3,param_4,param_5);
  return;
}



void campan_remove_tracking_head(campan_feature_match_t *param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  bool bVar9;
  
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x318));
  puVar1 = *(undefined4 **)(param_1 + 0xac0);
  puVar5 = (undefined4 *)*puVar1;
  if (puVar5 == puVar1) {
LAB_000208a8:
    __android_log_print(6,"CAMPAN_ATTR","cannot remove tracking id %d, not tracking",param_2);
  }
  else {
    iVar3 = puVar5[2];
    while (param_2 != iVar3) {
      puVar5 = (undefined4 *)*puVar5;
      if (puVar5 == puVar1) goto LAB_000208a8;
      iVar3 = puVar5[2];
    }
    __android_log_print(6,"CAMPAN_ATTR","remove tracking id %d",param_2);
    *(int *)(*(int *)(param_1 + 0xac0) + 8) = *(int *)(*(int *)(param_1 + 0xac0) + 8) + -1;
    std::__detail::_List_node_base::_M_unhook();
    operator_delete(puVar5);
    piVar2 = *(int **)(param_1 + 0xab8);
    piVar4 = (int *)*piVar2;
    if (piVar4 != piVar2) {
      do {
        piVar8 = piVar4 + 0x120;
        if (*piVar8 == param_2) {
          piVar4[0x141] = 0;
        }
        piVar4 = (int *)*piVar4;
        if (*piVar8 == param_2) {
          piVar2 = *(int **)(param_1 + 0xab8);
        }
      } while (piVar2 != piVar4);
    }
    piVar2 = *(int **)(param_1 + 0xabc);
    piVar4 = (int *)*piVar2;
    if (piVar4 != piVar2) {
      do {
        bVar9 = piVar4[2] == param_2;
        if (bVar9) {
          piVar4[0x2b] = 0;
        }
        if (bVar9) {
          piVar4[0x42] = 0;
        }
        piVar4 = (int *)*piVar4;
        if (bVar9) {
          piVar2 = *(int **)(param_1 + 0xabc);
        }
      } while (piVar2 != piVar4);
      piVar4 = (int *)*piVar4;
      while (piVar8 = piVar4, piVar2 != piVar8) {
        piVar4 = (int *)*piVar8;
        if (piVar8[0x43] == 1) {
          piVar7 = piVar8 + 0x2b;
          piVar2[2] = piVar2[2] + -1;
          std::__detail::_List_node_base::_M_unhook();
          do {
            piVar7 = piVar7 + -3;
            piVar2 = (int *)*piVar7;
            while (piVar7 != piVar2) {
              piVar6 = (int *)*piVar2;
              operator_delete(piVar2);
              piVar2 = piVar6;
            }
          } while (piVar8 + 0x1c != piVar7);
          piVar2 = (int *)piVar8[0x19];
          while (piVar2 != piVar8 + 0x19) {
            piVar7 = (int *)*piVar2;
            operator_delete(piVar2);
            piVar2 = piVar7;
          }
          piVar2 = (int *)piVar8[0x16];
          while (piVar2 != piVar8 + 0x16) {
            piVar7 = (int *)*piVar2;
            operator_delete(piVar2);
            piVar2 = piVar7;
          }
          piVar2 = piVar8 + 0x14;
          do {
            piVar2 = piVar2 + -3;
            piVar7 = (int *)*piVar2;
            while (piVar2 != piVar7) {
              piVar6 = (int *)*piVar7;
              operator_delete(piVar7);
              piVar7 = piVar6;
            }
          } while (piVar8 + 0xb != piVar2);
          piVar2 = (int *)piVar8[8];
          while (piVar8 + 8 != piVar2) {
            piVar7 = (int *)*piVar2;
            operator_delete(piVar2);
            piVar2 = piVar7;
          }
          piVar2 = (int *)piVar8[5];
          while (piVar2 != piVar8 + 5) {
            piVar7 = (int *)*piVar2;
            operator_delete(piVar2);
            piVar2 = piVar7;
          }
          operator_delete(piVar8);
          piVar2 = *(int **)(param_1 + 0xabc);
        }
      }
    }
  }
  if (*(int *)(*(int *)(param_1 + 0xac0) + 8) == 0) {
    __android_log_print(6,"CAMPAN_ATTR","tracking head empty");
    *(undefined4 *)(param_1 + 0x330) = 0xffffffff;
  }
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x318));
  return;
}



void dtbased_tk_release(void)

{
  dtbased_tk_release();
  return;
}



vector<std::vector<ax_tensor_t,std::allocator<ax_tensor_t>>,std::allocator<std::vector<ax_tensor_t,std::allocator<ax_tensor_t>>>>
* __thiscall
std::
vector<std::vector<ax_tensor_t,std::allocator<ax_tensor_t>>,std::allocator<std::vector<ax_tensor_t,std::allocator<ax_tensor_t>>>>
::~vector(vector<std::vector<ax_tensor_t,std::allocator<ax_tensor_t>>,std::allocator<std::vector<ax_tensor_t,std::allocator<ax_tensor_t>>>>
          *this)

{
  void *pvVar1;
  ax_tensor_t *this_00;
  ax_tensor_t *paVar2;
  ax_tensor_t *paVar3;
  void *pvVar4;
  void *pvVar5;
  void *pvVar6;
  
  pvVar1 = *(void **)this;
  pvVar6 = *(void **)(this + 4);
  if (pvVar1 != pvVar6) {
    pvVar4 = (void *)((int)pvVar1 + 0xc);
    pvVar5 = pvVar4;
    while( true ) {
      paVar3 = *(ax_tensor_t **)((int)pvVar1 + 4);
      this_00 = *(ax_tensor_t **)((int)pvVar4 + -0xc);
      if (*(ax_tensor_t **)((int)pvVar4 + -0xc) != paVar3) {
        do {
          paVar2 = this_00 + 0x30;
          ax_tensor_t::~ax_tensor_t(this_00);
          this_00 = paVar2;
        } while (paVar3 != paVar2);
        paVar3 = *(ax_tensor_t **)((int)pvVar4 + -0xc);
      }
      if (paVar3 != (ax_tensor_t *)0x0) {
        operator_delete(paVar3);
      }
      pvVar4 = (void *)((int)pvVar4 + 0xc);
      if (pvVar6 == pvVar5) break;
      pvVar1 = pvVar5;
      pvVar5 = (void *)((int)pvVar5 + 0xc);
    }
    pvVar6 = *(void **)this;
  }
  if (pvVar6 != (void *)0x0) {
    operator_delete(pvVar6);
  }
  return this;
}



void __thiscall std::vector<float,std::allocator<float>>::_M_realloc_insert<float_const&>(void)

{
  _M_realloc_insert<float_const&>();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void face_pose_process(face_pose_t *param_1,ax_yuv_t *param_2,ax_box_t *param_3,float *param_4)

{
  face_pose_process(param_1,param_2,param_3,param_4);
  return;
}



void person_head_match(campan_feature_match_t *param_1,vector *param_2,vector *param_3,int **param_4
                      ,int **param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  int iStack_b4;
  uint uStack_a4;
  int *piStack_a0;
  void *pvStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  float fStack_38;
  int iStack_34;
  
  iStack_44 = 0;
  pvStack_80 = (void *)0x0;
  uStack_7c = 0;
  uStack_78 = 0;
  std::vector<int,std::allocator<int>>::_M_fill_assign
            ((vector<int,std::allocator<int>> *)&pvStack_80,
             *(int *)(param_3 + 4) - *(int *)param_3 >> 4,&iStack_44);
  iVar8 = (*(int *)(param_3 + 4) - *(int *)param_3 >> 4) *
          (*(int *)(param_2 + 4) - *(int *)param_2 >> 4);
  AX_MALLOC_INC_TEMP<ax_int_array_t>((ax_int_array_t *)(param_1 + 0xb08),iVar8);
  AX_MALLOC_INC_TEMP<ax_int_array_t>
            ((ax_int_array_t *)(param_1 + 0xb10),
             (*(int *)(param_2 + 4) - *(int *)param_2 >> 4) +
             (*(int *)(param_3 + 4) - *(int *)param_3 >> 4));
  iVar3 = *(int *)param_2;
  iVar1 = *(int *)(param_2 + 4);
  iVar11 = *(int *)(param_3 + 4);
  iVar9 = *(int *)param_3;
  iVar4 = iVar1 - iVar3 >> 4;
  piVar5 = *(int **)(param_1 + 0xb08);
  piVar6 = *(int **)(param_1 + 0xb10);
  iVar2 = iVar11 - iVar9 >> 4;
  AX_MALLOC_INC_TEMP<box_intersect_array_t>((box_intersect_array_t *)(param_1 + 0xb38),iVar8);
  if (iVar11 - iVar9 < 1) {
LAB_00023da0:
    iStack_44 = iVar4;
    iStack_40 = iVar2;
    FUN_00022380(param_1 + 0xad8,piVar5,iVar4,iVar2,piVar6);
    if (param_4 != (int **)0x0) {
      *param_4 = piVar6 + iVar2;
    }
    if (param_5 != (int **)0x0) {
      *param_5 = piVar6;
    }
    if (pvStack_80 != (void *)0x0) {
      operator_delete(pvStack_80);
    }
    return;
  }
  iVar8 = *(int *)param_3;
  if (iVar8 == *(int *)(param_3 + 4)) {
    uStack_a4 = 0;
  }
  else {
    iStack_b4 = 0;
    uStack_a4 = 0;
    piStack_a0 = piVar5;
    do {
      puVar7 = (undefined4 *)(iVar8 + uStack_a4 * 0x10);
      uStack_74 = *puVar7;
      uStack_70 = puVar7[1];
      uStack_6c = puVar7[2];
      uStack_68 = puVar7[3];
      if (0 < iVar1 - iVar3) {
        iVar8 = *(int *)param_2;
        if (iVar8 == *(int *)(param_2 + 4)) {
          uVar10 = 0;
LAB_00023dea:
                    /* WARNING: Subroutine does not return */
          std::__throw_out_of_range_fmt
                    ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                     uVar10);
        }
        uVar10 = 0;
        piVar13 = piStack_a0;
        while( true ) {
          puVar7 = (undefined4 *)(iVar8 + uVar10 * 0x10);
          uStack_64 = *puVar7;
          uStack_60 = puVar7[1];
          uStack_5c = puVar7[2];
          uStack_58 = puVar7[3];
          get_person_upper_box((ax_box_t *)&uStack_54);
          box_overlap_intersect<ax_box_t>
                    (uStack_74,uStack_70,uStack_6c,uStack_68,uStack_54,uStack_50,uStack_4c,uStack_48
                     ,&iStack_44);
          iVar8 = iStack_b4 + uVar10;
          uVar10 = uVar10 + 1;
          piVar12 = (int *)(iVar8 * 0x14 + *(int *)(param_1 + 0xb38));
          *piVar12 = iStack_44;
          piVar12[1] = iStack_40;
          piVar12[2] = iStack_3c;
          piVar12[3] = (int)fStack_38;
          piVar12[4] = iStack_34;
          *piVar13 = (int)-(fStack_38 * 1000.0);
          piVar13 = piVar13 + 1;
          if (iVar4 <= (int)uVar10) break;
          iVar8 = *(int *)param_2;
          if ((uint)(*(int *)(param_2 + 4) - iVar8 >> 4) <= uVar10) goto LAB_00023dea;
        }
      }
      uStack_a4 = uStack_a4 + 1;
      if (iVar2 <= (int)uStack_a4) goto LAB_00023da0;
      iVar8 = *(int *)param_3;
      iStack_b4 = iStack_b4 + iVar4;
      piStack_a0 = piStack_a0 + iVar4;
    } while (uStack_a4 < (uint)(*(int *)(param_3 + 4) - iVar8 >> 4));
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",uStack_a4);
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sem_wait(sem_t *__sem)

{
  int iVar1;
  
  iVar1 = sem_wait(__sem);
  return iVar1;
}



void AX_MALLOC_INC_TEMP<nn_campan_faces_t>(nn_campan_faces_t *param_1,int param_2)

{
  AX_MALLOC_INC_TEMP<nn_campan_faces_t>(param_1,param_2);
  return;
}



void __cxa_finalize(void)

{
  __cxa_finalize();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_unlock(pthread_mutex_t *__mutex)

{
  int iVar1;
  
  iVar1 = pthread_mutex_unlock(__mutex);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void retina_release(retina_t *param_1)

{
  retina_release(param_1);
  return;
}



void hung_release(hungarian_t *param_1)

{
  hung_release(param_1);
  return;
}



void __thiscall
std::
_Rb_tree<int,std::pair<int_const,match_table_t>,std::_Select1st<std::pair<int_const,match_table_t>>,std::less<int>,std::allocator<std::pair<int_const,match_table_t>>>
::_M_erase(_Rb_tree<int,std::pair<int_const,match_table_t>,std::_Select1st<std::pair<int_const,match_table_t>>,std::less<int>,std::allocator<std::pair<int_const,match_table_t>>>
           *this,_Rb_tree_node *param_1)

{
  _M_erase(this,param_1);
  return;
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */

void campan_yolo_humanpose_det_process(nn_campan_engine_t *param_1,nn_campan_in_t *param_2)

{
  float *pfVar1;
  size_t __n;
  int *piVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 *puVar5;
  float *pfVar6;
  undefined4 uVar7;
  void *pvVar8;
  float *pfVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int **ppiVar13;
  int iVar14;
  int *piVar15;
  undefined4 uVar16;
  int *piVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  int *piVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  vector<ax_track_box_t,std::allocator<ax_track_box_t>> *pvVar24;
  int *piVar25;
  retina_t *prVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  undefined8 uVar30;
  undefined4 uStack_380;
  undefined4 uStack_37c;
  int iStack_378;
  int *piStack_358;
  int *piStack_348;
  int iStack_344;
  void *pvStack_340;
  void *pvStack_33c;
  undefined4 uStack_338;
  void *pvStack_334;
  undefined4 *puStack_330;
  undefined4 *puStack_32c;
  void *pvStack_328;
  int iStack_324;
  undefined4 uStack_320;
  void *pvStack_31c;
  void *pvStack_318;
  void *pvStack_314;
  void *pvStack_310;
  int iStack_30c;
  undefined4 uStack_308;
  undefined4 uStack_304;
  undefined4 uStack_300;
  undefined4 uStack_2fc;
  int iStack_2f8;
  int iStack_2f4;
  undefined4 uStack_2f0;
  undefined4 uStack_2ec;
  undefined4 uStack_2e8;
  undefined4 uStack_2e4;
  undefined4 uStack_2e0;
  undefined4 uStack_2dc;
  undefined4 uStack_2d8;
  undefined4 uStack_2d4;
  undefined4 uStack_2d0;
  int *piStack_2cc;
  int *apiStack_2c8 [34];
  undefined4 uStack_240;
  undefined4 uStack_23c;
  undefined4 uStack_238;
  undefined4 uStack_234;
  undefined4 uStack_230;
  undefined4 uStack_22c;
  undefined4 uStack_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  
  if (DAT_0003a674 << 0x1a < 0) {
    __android_log_print(6,"CAMPAN","");
  }
  iVar10 = *(int *)(param_1 + 0x108);
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x1cc));
  prVar26 = *(retina_t **)(param_1 + 0xe4);
  puVar18 = *(undefined4 **)(param_1 + 0x14);
  if (*(int *)(param_1 + 0x10) != 0) {
    prVar26 = *(retina_t **)(param_1 + 0xe8);
    puVar18 = *(undefined4 **)(param_1 + 0x24);
  }
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x1cc));
  if ((prVar26 == (retina_t *)0x0) || (*(int *)(param_2 + 0x1c) == 0)) {
    *(undefined4 *)(param_1 + 0x114) = 0;
  }
  else {
    pvStack_340 = (void *)0x0;
    pvStack_33c = (void *)0x0;
    uStack_338 = 0;
    nnyuv2axyuv((nn_yuv_t *)&uStack_2f0);
    uStack_214 = *(undefined4 *)param_2;
    uStack_210 = *(undefined4 *)(param_2 + 4);
    uStack_240 = uStack_2f0;
    uStack_23c = uStack_2ec;
    uStack_238 = uStack_2e8;
    uStack_234 = uStack_2e4;
    uStack_21c = 0;
    uStack_230 = uStack_2e0;
    uStack_22c = uStack_2dc;
    uStack_228 = uStack_2d8;
    uStack_224 = uStack_2d4;
    uStack_220 = uStack_2d0;
    if (*(int *)(prVar26 + 0x44) == 6) {
      uStack_7c = 0x3ee66666;
    }
    else {
      uStack_7c = 0x3f19999a;
    }
    uStack_218 = 0;
    uStack_70 = 0x3eb851ec;
    uStack_20c = 0x3ee66666;
    uStack_74 = 0x3ecccccd;
    uStack_78 = 0x3f800000;
    retina_process_humanpose
              (prVar26,(retina_pose_in_t *)&uStack_240,(retina_pose_out_t *)&pvStack_340);
    __n = (int)pvStack_33c - (int)pvStack_340;
    uVar21 = ((int)__n >> 3) * 0x4f72c235;
    if (uVar21 == 0) {
      iVar22 = 0;
      piStack_358 = (int *)0x0;
    }
    else {
      if (0x11a7b96 < uVar21) {
                    /* WARNING: Subroutine does not return */
        std::__throw_bad_alloc();
      }
      piStack_358 = (int *)operator_new(__n);
      __n = (int)pvStack_33c - (int)pvStack_340;
      iVar22 = ((int)__n >> 3) * 0x4f72c235;
    }
    if (pvStack_33c != pvStack_340) {
      memmove(piStack_358,pvStack_340,__n);
    }
    uVar16 = *(undefined4 *)param_2;
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_2 + 0xc);
    *(undefined4 *)(param_1 + 0x3c) = uVar16;
    uVar16 = *(undefined4 *)(param_2 + 4);
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x8c);
    *(undefined4 *)(param_1 + 0x40) = uVar16;
    FUN_0001624c(param_1 + 0x54,param_1 + 0x58,iVar22);
    if (iVar22 != 0) {
      piVar2 = *(int **)(param_1 + 0x54);
      piVar4 = piStack_358;
      do {
        iVar11 = *piVar4;
        piVar17 = piVar4 + 0x3a;
        iVar28 = piVar4[6];
        *piVar2 = iVar11;
        iVar23 = piVar4[1];
        piVar2[1] = iVar23;
        piVar2[2] = (piVar4[2] - iVar11) + 1;
        iVar11 = piVar4[3];
        piVar2[4] = iVar28;
        piVar2[3] = (iVar11 - iVar23) + 1;
        piVar2 = piVar2 + 5;
        piVar4 = piVar17;
      } while (piStack_358 + iVar22 * 0x3a != piVar17);
    }
    *puVar18 = 0x3e8f5c29;
    uVar16 = *(undefined4 *)(iVar10 + 0x6c);
    puVar18[0xc] = 0x3ecccccd;
    puVar18[6] = uVar16;
    puVar18[8] = 0x3ef5c28f;
    puVar18[1] = 3;
    puVar18[5] = 1;
    puVar18[7] = 1;
    puVar18[10] = 1;
    puVar18[0x12] = 0x3f800000;
    puVar18[0xb] = 0;
    puVar18[9] = 0;
    puVar18[3] = 0x30;
    if (*(int *)(param_1 + 0x278) == 0) {
      puVar18[2] = 0;
    }
    else {
      puVar18[2] = 2;
    }
    dtbased_tk_update(puVar18,param_1 + 0x34,&piStack_348);
    iVar22 = piStack_348[1];
    AX_MALLOC_INC_TEMP<nn_campan_persons_t>((nn_campan_persons_t *)(param_1 + 0x110),iVar22);
    memset(*(void **)(param_1 + 0x110),0,iVar22 * 0x2a8);
    uVar16 = *(undefined4 *)(param_1 + 0x90);
    pvStack_310 = (void *)0x0;
    iStack_30c = 0;
    uStack_308 = 0;
    uVar7 = *(undefined4 *)(param_1 + 0xa0);
    pvStack_334 = (void *)0x0;
    puStack_330 = (undefined4 *)0x0;
    puStack_32c = (undefined4 *)0x0;
    pvStack_328 = (void *)0x0;
    iStack_324 = 0;
    uStack_320 = 0;
    pvStack_31c = (void *)0x0;
    pvStack_318 = (void *)0x0;
    pvStack_314 = (void *)0x0;
    uVar30 = get_time_ms();
    pvVar24 = (vector<ax_track_box_t,std::allocator<ax_track_box_t>> *)&pvStack_31c;
    if (0 < iVar22) {
      iVar11 = 0;
      do {
        iVar28 = *(int *)(param_1 + 0x110);
        iVar29 = *piStack_348;
        iVar12 = iVar11 * 0x2a8;
        iVar27 = iVar29 + iVar11 * 0x20;
        uVar21 = *(uint *)(iVar27 + 0x18);
        iVar23 = iVar28 + iVar12;
        if ((int)uVar21 < 0) {
          uStack_380 = *(undefined4 *)(iVar27 + 4);
          *(undefined4 *)(iVar23 + 4) = uStack_380;
          uStack_37c = *(undefined4 *)(iVar27 + 8);
          puVar18 = (undefined4 *)(iVar23 + 0x264);
          *(undefined4 *)(iVar23 + 8) = uStack_37c;
          iStack_378 = *(int *)(iVar27 + 4) + *(int *)(iVar27 + 0xc) + -1;
          *(int *)(iVar23 + 0xc) = iStack_378;
          iStack_2f4 = *(int *)(iVar27 + 8) + *(int *)(iVar27 + 0x10) + -1;
          *(int *)(iVar23 + 0x10) = iStack_2f4;
          iVar14 = iVar23;
          do {
            *(undefined4 *)(iVar14 + 0x154) = 0;
            *(undefined4 *)(iVar14 + 0x158) = 0;
            iVar14 = iVar14 + 8;
            *puVar18 = 0;
            puVar18 = puVar18 + 1;
          } while ((undefined4 *)(iVar23 + 0x2a8) != puVar18);
        }
        else {
          if ((uint)(((int)pvStack_33c - (int)pvStack_340 >> 3) * 0x4f72c235) <= uVar21) {
                    /* WARNING: Subroutine does not return */
            std::__throw_out_of_range_fmt
                      ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)");
          }
          uStack_380 = *(undefined4 *)((int)pvStack_340 + uVar21 * 0xe8);
          pvVar3 = (void *)((int)pvStack_340 + uVar21 * 0xe8);
          *(undefined4 *)(iVar23 + 4) = uStack_380;
          uStack_37c = *(undefined4 *)((int)pvVar3 + 4);
          *(undefined4 *)(iVar23 + 8) = uStack_37c;
          iStack_378 = *(int *)((int)pvVar3 + 8);
          *(int *)(iVar23 + 0xc) = iStack_378;
          iStack_2f4 = *(int *)((int)pvVar3 + 0xc);
          *(int *)(iVar23 + 0x10) = iStack_2f4;
          puVar18 = (undefined4 *)((int)pvVar3 + 0xa4);
          iVar14 = iVar23;
          pvVar8 = pvVar3;
          puVar19 = (undefined4 *)(iVar23 + 0x264);
          do {
            *(undefined4 *)(iVar14 + 0x154) = *(undefined4 *)((int)pvVar8 + 0x1c);
            *(undefined4 *)(iVar14 + 0x158) = *(undefined4 *)((int)pvVar8 + 0x20);
            puVar5 = puVar18 + 1;
            *puVar19 = *puVar18;
            puVar18 = puVar5;
            iVar14 = iVar14 + 8;
            pvVar8 = (void *)((int)pvVar8 + 8);
            puVar19 = puVar19 + 1;
          } while ((undefined4 *)((int)pvVar3 + 0xe8) != puVar5);
        }
        uStack_304 = *(undefined4 *)(iVar29 + iVar11 * 0x20);
        *(undefined4 *)(iVar28 + iVar12) = uStack_304;
        *(undefined4 *)(iVar23 + 0x24) = *(undefined4 *)(iVar27 + 0x14);
        *(undefined8 *)(iVar23 + 0x28) = uVar30;
        uStack_300 = uStack_380;
        uStack_2fc = uStack_37c;
        iStack_2f8 = iStack_378;
        if (puStack_330 == puStack_32c) {
          std::vector<ax_track_box_t,std::allocator<ax_track_box_t>>::
          _M_realloc_insert<ax_track_box_t_const&>
                    ((vector<ax_track_box_t,std::allocator<ax_track_box_t>> *)&pvStack_334,
                     puStack_330,&uStack_304);
        }
        else {
          if (puStack_330 != (undefined4 *)0x0) {
            *puStack_330 = uStack_304;
            puStack_330[1] = uStack_380;
            puStack_330[2] = uStack_37c;
            puStack_330[3] = iStack_378;
            puStack_330[4] = iStack_2f4;
          }
          puStack_330 = puStack_330 + 5;
        }
        piStack_2cc = *(int **)(iVar28 + iVar12);
        ppiVar13 = &piStack_2cc;
        do {
          ppiVar13[1] = (int *)(float)(longlong)*(int *)(iVar23 + 0x154);
          ppiVar13 = ppiVar13 + 2;
          *ppiVar13 = (int *)(float)(longlong)*(int *)(iVar23 + 0x158);
          iVar23 = iVar23 + 8;
        } while (apiStack_2c8 + 0x21 != ppiVar13);
        if (pvStack_318 == pvStack_314) {
          std::vector<ax_track_kpt_t,std::allocator<ax_track_kpt_t>>::
          _M_realloc_insert<ax_track_kpt_t_const&>
                    ((vector<ax_track_kpt_t,std::allocator<ax_track_kpt_t>> *)&pvStack_31c,
                     pvStack_318,&piStack_2cc);
        }
        else {
          if (pvStack_318 != (void *)0x0) {
            pvStack_318 = memcpy(pvStack_318,&piStack_2cc,0x8c);
          }
          pvStack_318 = (void *)((int)pvStack_318 + 0x8c);
        }
        iVar11 = iVar11 + 1;
        pvVar24 = (vector<ax_track_box_t,std::allocator<ax_track_box_t>> *)&pvStack_334;
      } while (iVar22 != iVar11);
    }
    uStack_304 = *(undefined4 *)param_2;
    uStack_300 = *(undefined4 *)(param_2 + 4);
    box_smooth_process(uVar16,uStack_304,uStack_300,
                       (vector<ax_track_box_t,std::allocator<ax_track_box_t>> *)&pvStack_334,
                       &pvStack_328);
    iVar22 = iStack_324 - (int)pvStack_328;
    if (0 < iVar22) {
      pvVar24 = (vector<ax_track_box_t,std::allocator<ax_track_box_t>> *)0x2a8;
    }
    if (0 < iVar22) {
      iVar23 = *(int *)(param_1 + 0x110);
      iVar11 = 0;
      pvVar8 = pvStack_328;
      while( true ) {
        iVar11 = iVar11 + 1;
        *(undefined4 *)(iVar23 + 0x14) = *(undefined4 *)((int)pvVar8 + 4);
        *(undefined4 *)(iVar23 + 0x18) = *(undefined4 *)((int)pvVar8 + 8);
        *(undefined4 *)(iVar23 + 0x1c) = *(undefined4 *)((int)pvVar8 + 0xc);
        *(undefined4 *)(iVar23 + 0x20) = *(undefined4 *)((int)pvVar8 + 0x10);
        if ((iVar22 >> 2) * -0x33333333 <= iVar11) break;
        pvVar8 = (void *)((int)pvVar8 + 0x14);
        iVar23 = (int)pvVar24 * iVar11 + *(int *)(param_1 + 0x110);
      }
    }
    kpt_smooth_process(uVar7,uStack_304,uStack_300,
                       (vector<ax_track_kpt_t,std::allocator<ax_track_kpt_t>> *)&pvStack_31c,
                       &pvStack_310);
    iVar22 = iStack_30c - (int)pvStack_310 >> 2;
    if (iVar22 * -0x75075075 != 0) {
      pfVar6 = (float *)((int)pvStack_310 + 0x88);
      iVar11 = 0;
      do {
        pfVar9 = pfVar6 + -0x22;
        iVar23 = *(int *)(param_1 + 0x110) + iVar11;
        do {
          pfVar1 = pfVar9 + 1;
          pfVar9 = pfVar9 + 2;
          *(int *)(iVar23 + 0x1dc) = (int)(longlong)(*pfVar1 + 0.5);
          *(int *)(iVar23 + 0x1e0) = (int)(longlong)(*pfVar9 + 0.5);
          iVar23 = iVar23 + 8;
        } while (pfVar6 != pfVar9);
        iVar11 = iVar11 + 0x2a8;
        pfVar6 = pfVar6 + 0x23;
      } while (iVar22 * 0x24924938 - iVar11 != 0);
    }
    if (0 < *(int *)(param_1 + 0x114)) {
      iVar22 = 0;
      do {
        iVar11 = iVar22 * 0x2a8;
        iVar22 = iVar22 + 1;
        *(undefined4 *)(iVar11 + *(int *)(param_1 + 0x110) + 0x140) = 0;
        iVar11 = *(int *)(param_1 + 0x114);
      } while (iVar22 < iVar11);
      if ((0 < iVar11) && (*(int *)(iVar10 + 0x30) != 0)) {
        piStack_2cc = (int *)0x0;
        apiStack_2c8[0] = (int *)0x0;
        apiStack_2c8[1] = (int *)0x0;
        iVar10 = 0;
        do {
          iVar22 = iVar10 * 0x2a8 + *(int *)(param_1 + 0x110);
          iStack_344 = (*(int *)(iVar22 + 0xc) - *(int *)(iVar22 + 4)) *
                       (*(int *)(iVar22 + 0x10) - *(int *)(iVar22 + 8));
          if (apiStack_2c8[0] == apiStack_2c8[1]) {
            std::vector<int,std::allocator<int>>::_M_realloc_insert<int_const&>
                      ((vector<int,std::allocator<int>> *)&piStack_2cc,apiStack_2c8[0],&iStack_344);
            iVar11 = *(int *)(param_1 + 0x114);
          }
          else {
            if (apiStack_2c8[0] != (int *)0x0) {
              *apiStack_2c8[0] = iStack_344;
              iVar11 = *(int *)(param_1 + 0x114);
            }
            apiStack_2c8[0] = apiStack_2c8[0] + 1;
          }
          piVar4 = apiStack_2c8[0];
          piVar2 = piStack_2cc;
          iVar10 = iVar10 + 1;
        } while (iVar10 < iVar11);
        piVar17 = apiStack_2c8[0];
        if (piStack_2cc != apiStack_2c8[0]) {
          iVar10 = (int)apiStack_2c8[0] - (int)piStack_2cc;
          std::
          __introsort_loop<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,int,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
                    (piStack_2cc,apiStack_2c8[0],(0x1f - LZCOUNT(iVar10 >> 2)) * 2,0x15b19);
          if (iVar10 < 0x41) {
            std::
            __insertion_sort<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
                      (piVar2,piVar4,0x15b19);
            iVar11 = *(int *)(param_1 + 0x114);
            piVar17 = piStack_2cc;
          }
          else {
            piVar25 = piVar2 + 0x10;
            std::
            __insertion_sort<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
                      (piVar2,piVar25,0x15b19);
            piVar17 = piStack_2cc;
            if (piVar25 != piVar4) {
              piVar20 = piVar2 + 0xf;
              do {
                piVar20 = piVar20 + 1;
                iVar10 = *piVar20;
                piVar15 = piVar20;
                while( true ) {
                  iVar11 = piVar15[-1];
                  iVar22 = FUN_00015b18(iVar10,iVar11);
                  if (iVar22 == 0) break;
                  *piVar15 = iVar11;
                  piVar15 = piVar15 + -1;
                }
                *piVar15 = iVar10;
              } while ((int *)((int)piVar25 + ((int)piVar4 - (int)(piVar2 + 0x11))) != piVar20);
            }
            iVar11 = *(int *)(param_1 + 0x114);
          }
        }
        if (0 < iVar11) {
          iVar10 = 0;
          do {
            iVar22 = iVar10 * 0x2a8;
            iVar10 = iVar10 + 1;
            *(undefined4 *)(iVar22 + *(int *)(param_1 + 0x110) + 0x140) = 0;
          } while (iVar10 < *(int *)(param_1 + 0x114));
        }
        if (piVar17 != (int *)0x0) {
          operator_delete(piVar17);
        }
      }
    }
    if (pvStack_310 != (void *)0x0) {
      operator_delete(pvStack_310);
    }
    if (pvStack_31c != (void *)0x0) {
      operator_delete(pvStack_31c);
    }
    if (pvStack_328 != (void *)0x0) {
      operator_delete(pvStack_328);
    }
    if (pvStack_334 != (void *)0x0) {
      operator_delete(pvStack_334);
    }
    if (piStack_358 != (int *)0x0) {
      operator_delete(piStack_358);
    }
    if (pvStack_340 != (void *)0x0) {
      operator_delete(pvStack_340);
      return;
    }
  }
  return;
}



void campan_use_new_humanpose_set_human_head
               (nn_campan_cfg_t *param_1,nn_campan_use_humanpose_trackid_out_t *param_2)

{
  campan_use_new_humanpose_set_human_head(param_1,param_2);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nna_setFreq(_vx_context *param_1,int param_2)

{
  nna_setFreq(param_1,param_2);
  return;
}



/* WARNING: Removing unreachable block (ram,0x00015a64) */

void processEntry entry(void)

{
  __gmon_start__();
  return;
}



/* WARNING: Removing unreachable block (ram,0x00015a84) */
/* WARNING: Removing unreachable block (ram,0x00015a8a) */

void FUN_00015a74(void)

{
  return;
}



/* WARNING: Removing unreachable block (ram,0x00015ab8) */
/* WARNING: Removing unreachable block (ram,0x00015abe) */

void FUN_00015aa0(void)

{
  return;
}



void _FINI_0(void)

{
  if (_edata == '\0') {
    __cxa_finalize(DAT_0003a350);
    FUN_00015a74();
    _edata = '\x01';
  }
  return;
}



/* WARNING: Removing unreachable block (ram,0x00015ab8) */
/* WARNING: Removing unreachable block (ram,0x00015abe) */

void _INIT_0(void)

{
  return;
}



bool FUN_00015b18(int param_1,int param_2)

{
  return param_2 < param_1;
}



void FUN_00015b4c(undefined4 *param_1)

{
  __android_log_print(6,"CAMPAN","width %d, height %d, %p, %p",*param_1,param_1[1],param_1[4],
                      param_1[5]);
  __android_log_print(6,"CAMPAN","human_det_en %d",param_1[7]);
  __android_log_print(6,"CAMPAN","face_det_en %d",param_1[8]);
  __android_log_print(6,"CAMPAN","head_det_en %d",param_1[9]);
  __android_log_print(6,"CAMPAN","gesture_det_en %d",param_1[10]);
  __android_log_print(6,"CAMPAN","tracking_id %d",param_1[0xb]);
  return;
}



void FUN_00015bd8(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_50 = *(int *)(param_1 + -0x58);
  local_4c = *(int *)(param_1 + -0x54);
  local_48 = *(int *)(param_1 + -0x48);
  local_44 = *(int *)(param_1 + -0x44);
  local_38 = *(undefined4 *)(param_1 + -0x50);
  uStack_34 = *(undefined4 *)(param_1 + -0x4c);
  local_30 = *(undefined4 *)(param_1 + -8);
  local_40 = *(int *)(param_1 + -0x40);
  local_3c = *(int *)(param_1 + -0x3c);
  iVar5 = *(int *)(param_1 + -0x60);
  if (*(int *)(param_1 + 0xc0) << 0x1b < 0) {
    __android_log_print(6,"CAMPAN","person num %d",local_4c);
    if (0 < local_4c) {
      iVar9 = 0;
      do {
        iVar7 = local_50 + iVar9 * 0x2a8;
        uVar3 = *(undefined4 *)(iVar7 + 0x20);
        uVar4 = *(undefined4 *)(iVar7 + 0x1c);
        __android_log_print(6,"CAMPAN","id %d, %d, %d, %d, %d",
                            *(undefined4 *)(local_50 + iVar9 * 0x2a8),*(undefined4 *)(iVar7 + 0x14),
                            *(undefined4 *)(iVar7 + 0x18),uVar4,uVar3);
        iVar6 = 0;
        do {
          puVar1 = (undefined4 *)(iVar7 + 0x158);
          iVar8 = iVar6 + 1;
          puVar2 = (undefined4 *)(iVar7 + 0x154);
          iVar7 = iVar7 + 8;
          __android_log_print(6,"CAMPAN","pt %d, %d, %d",iVar6,*puVar2,*puVar1,uVar4,uVar3);
          iVar6 = iVar8;
        } while (iVar8 != 0x11);
        iVar9 = iVar9 + 1;
      } while (iVar9 < local_4c);
    }
    __android_log_print(6,"CAMPAN","face num %d",local_44);
    if (0 < local_44) {
      iVar9 = 0;
      do {
        iVar6 = iVar9 * 0x178;
        iVar9 = iVar9 + 1;
        iVar7 = local_48 + iVar6;
        __android_log_print(6,"CAMPAN","id %d, %d, %d, %d, %d",*(undefined4 *)(local_48 + iVar6),
                            *(undefined4 *)(iVar7 + 0x14),*(undefined4 *)(iVar7 + 0x18),
                            *(undefined4 *)(iVar7 + 0x1c),*(undefined4 *)(iVar7 + 0x20));
      } while (iVar9 < local_44);
    }
    __android_log_print(6,"CAMPAN","head num %d",local_3c);
    if (0 < local_3c) {
      iVar9 = 0;
      do {
        iVar6 = iVar9 * 0x3c;
        iVar9 = iVar9 + 1;
        iVar7 = local_40 + iVar6;
        __android_log_print(6,"CAMPAN","id %d, %d, %d, %d, %d",*(undefined4 *)(local_40 + iVar6),
                            *(undefined4 *)(iVar7 + 0x14),*(undefined4 *)(iVar7 + 0x18),
                            *(undefined4 *)(iVar7 + 0x1c),*(undefined4 *)(iVar7 + 0x20));
      } while (iVar9 < local_3c);
    }
  }
  local_2c = param_2;
  if (DAT_0003a674 << 0x1a < 0) {
    __android_log_print(6,"CAMPAN",&DAT_000272ac);
  }
  (**(code **)(iVar5 + 0x10))(0,&local_50);
  if (DAT_0003a674 << 0x1a < 0) {
    __android_log_print(6,"CAMPAN",&DAT_000272b0);
    return;
  }
  return;
}



undefined4 FUN_00016018(float param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  float __x;
  float fVar7;
  
  iVar4 = *param_2;
  __x = (float)(longlong)
               ((param_2[2] - iVar4) * (param_2[2] - iVar4) +
               (param_2[3] - param_2[1]) * (param_2[3] - param_2[1]));
  if ((int)((uint)(__x < 0.0) << 0x1f) < 0) {
    sqrtf(__x);
    iVar4 = *param_2;
  }
  iVar2 = 0;
  uVar1 = 0;
  while( true ) {
    iVar3 = iVar2 << 0x1f;
    bVar6 = iVar3 < 0;
    iVar2 = iVar2 + 1;
    if (bVar6) {
      iVar5 = param_3[1];
      iVar3 = param_3[3];
    }
    else {
      iVar5 = *param_3;
    }
    if (!bVar6) {
      iVar3 = param_3[2];
    }
    if ((int)((uint)(ABS((float)(longlong)(iVar4 - iVar5) / SQRT(__x)) < param_1) << 0x1f) < 0) {
      uVar1 = 1;
    }
    fVar7 = ABS((float)(longlong)(iVar4 - iVar3) / SQRT(__x));
    if (param_1 != fVar7 && param_1 < fVar7 == (NAN(param_1) || NAN(fVar7))) {
      uVar1 = 1;
    }
    if (iVar2 == 4) break;
    param_2 = param_2 + 1;
    iVar4 = *param_2;
  }
  return uVar1;
}



undefined4 FUN_000160c8(float param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  double dVar3;
  float fVar4;
  float fVar5;
  
  piVar2 = (int *)(param_3 + 0xc);
  piVar1 = (int *)*piVar2;
  if (piVar2 == piVar1) {
    if ((int)((uint)(param_1 < 0.45) << 0x1f) < 0) {
      fVar5 = 0.48;
      goto LAB_00016152;
    }
    fVar4 = 0.0;
LAB_00016122:
    dVar3 = (double)param_1;
    fVar5 = (float)(dVar3 + 0.03);
  }
  else {
    fVar4 = 0.0;
    do {
      dVar3 = (double)face_feature_dist((nn_campan_face_feature_t *)(piVar1 + 0x1a),
                                        (nn_campan_face_feature_t *)(param_2 + 0x60));
      piVar1 = (int *)*piVar1;
      if ((int)((uint)((double)fVar4 < dVar3) << 0x1f) < 0) {
        fVar4 = (float)dVar3;
      }
    } while (piVar2 != piVar1);
    if (-1 < (int)((uint)(param_1 < 0.45) << 0x1f)) goto LAB_00016122;
    fVar5 = 0.48;
    dVar3 = 0.44999998807907104;
    param_1 = 0.45;
  }
  if ((int)((uint)(param_1 < fVar4) << 0x1f) < 0) {
    if (DAT_0003a678 == 0) {
      return 1;
    }
    __android_log_print(6,"CAMPAN","rematch face, register_best_dist:%f, register_thresh:%f",
                        DAT_0003a678,(double)fVar4,dVar3);
    return 1;
  }
LAB_00016152:
  fVar4 = 0.0;
  piVar2 = (int *)(param_3 + 0x24);
  do {
    piVar1 = (int *)*piVar2;
    while (piVar2 != piVar1) {
      dVar3 = (double)face_feature_dist((nn_campan_face_feature_t *)(piVar1 + 0x1a),
                                        (nn_campan_face_feature_t *)(param_2 + 0x60));
      piVar1 = (int *)*piVar1;
      if ((int)((uint)((double)fVar4 < dVar3) << 0x1f) < 0) {
        fVar4 = (float)dVar3;
      }
    }
    piVar2 = piVar2 + 3;
  } while ((int *)(param_3 + 0x48) != piVar2);
  if (fVar4 != fVar5 && fVar4 < fVar5 == (NAN(fVar4) || NAN(fVar5))) {
    if (DAT_0003a678 != 0) {
      __android_log_print(6,"CAMPAN","rematch face, process_best_dist:%f, process_thresh:%f",
                          DAT_0003a678,(double)fVar4,(double)fVar5);
    }
    return 1;
  }
  return 0;
}



void FUN_0001624c(int *param_1,int *param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = (void *)*param_1;
  *param_2 = param_3;
  iVar2 = param_3 * 0x14;
  if (pvVar1 == (void *)0x0) {
    if (iVar2 < 1) {
      return;
    }
  }
  else {
    if (*(int *)((int)pvVar1 + -4) + param_3 * -0x14 < 0 ==
        SBORROW4(*(int *)((int)pvVar1 + -4),iVar2)) {
      return;
    }
    AX_FREE_RECORD(pvVar1);
    *param_1 = 0;
  }
  iVar2 = AX_MALLOC_RECORD(iVar2);
  *param_1 = iVar2;
  if (iVar2 != 0) {
    return;
  }
  *param_2 = 0;
  return;
}



/* nn_campan_track_head_t::~nn_campan_track_head_t() */

nn_campan_track_head_t * __thiscall
nn_campan_track_head_t::~nn_campan_track_head_t(nn_campan_track_head_t *this)

{
  nn_campan_track_head_t *pnVar1;
  nn_campan_track_head_t *pnVar2;
  nn_campan_track_head_t *pnVar3;
  
  pnVar3 = this + 0xa4;
  do {
    pnVar3 = pnVar3 + -0xc;
    pnVar2 = *(nn_campan_track_head_t **)pnVar3;
    while (pnVar3 != pnVar2) {
      pnVar1 = *(nn_campan_track_head_t **)pnVar2;
      operator_delete(pnVar2);
      pnVar2 = pnVar1;
    }
  } while (this + 0x68 != pnVar3);
  pnVar3 = *(nn_campan_track_head_t **)(this + 0x5c);
  while (pnVar3 != this + 0x5c) {
    pnVar2 = *(nn_campan_track_head_t **)pnVar3;
    operator_delete(pnVar3);
    pnVar3 = pnVar2;
  }
  pnVar3 = *(nn_campan_track_head_t **)(this + 0x50);
  while (pnVar3 != this + 0x50) {
    pnVar2 = *(nn_campan_track_head_t **)pnVar3;
    operator_delete(pnVar3);
    pnVar3 = pnVar2;
  }
  pnVar3 = this + 0x48;
  do {
    pnVar3 = pnVar3 + -0xc;
    pnVar2 = *(nn_campan_track_head_t **)pnVar3;
    while (pnVar3 != pnVar2) {
      pnVar1 = *(nn_campan_track_head_t **)pnVar2;
      operator_delete(pnVar2);
      pnVar2 = pnVar1;
    }
  } while (this + 0x24 != pnVar3);
  pnVar3 = *(nn_campan_track_head_t **)(this + 0x18);
  while (pnVar3 != this + 0x18) {
    pnVar2 = *(nn_campan_track_head_t **)pnVar3;
    operator_delete(pnVar3);
    pnVar3 = pnVar2;
  }
  pnVar3 = *(nn_campan_track_head_t **)(this + 0xc);
  while (pnVar3 != this + 0xc) {
    pnVar2 = *(nn_campan_track_head_t **)pnVar3;
    operator_delete(pnVar3);
    pnVar3 = pnVar2;
  }
  return this;
}



/* get_middle_person(nn_campan_persons_t*, nn_campan_in_t*) */

int get_middle_person(nn_campan_persons_t *param_1,nn_campan_in_t *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  if (0 < *(int *)(param_1 + 4)) {
    iVar5 = 0;
    iVar8 = 100000;
    iVar9 = -1;
    iVar6 = *(int *)param_1;
    do {
      piVar2 = (int *)(iVar6 + 8);
      piVar4 = (int *)(iVar6 + 0xc);
      piVar3 = (int *)(iVar6 + 4);
      piVar1 = (int *)(iVar6 + 0x10);
      iVar6 = iVar6 + 0x2a8;
      iVar7 = (*piVar3 + *piVar4) / 2 - *(int *)param_2 / 2;
      iVar10 = (*piVar2 + *piVar1) / 2 - *(int *)(param_2 + 4) / 2;
      if (iVar7 < 0) {
        iVar7 = -iVar7;
      }
      if (iVar10 < 0) {
        iVar10 = -iVar10;
      }
      iVar7 = iVar7 + iVar10;
      if (iVar7 < iVar8) {
        iVar9 = iVar5;
      }
      iVar5 = iVar5 + 1;
      if (iVar7 < iVar8) {
        iVar8 = iVar7;
      }
    } while (iVar5 != *(int *)(param_1 + 4));
    if (iVar9 != -1) {
      return iVar9 * 0x2a8 + *(int *)param_1;
    }
  }
  return 0;
}



/* overlap(int*, int*, float*, float*) */

void overlap(int *param_1,int *param_2,float *param_3,float *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar5 = *param_1;
  iVar7 = *param_2;
  iVar8 = param_1[1];
  iVar11 = param_2[1];
  iVar9 = param_1[2];
  iVar6 = iVar5;
  if (iVar5 < iVar7) {
    iVar6 = iVar7;
  }
  iVar4 = param_1[3];
  iVar10 = param_2[2];
  iVar2 = iVar8;
  if (iVar8 < iVar11) {
    iVar2 = iVar11;
  }
  iVar3 = param_2[3];
  if (iVar10 < iVar9) {
    iVar6 = iVar10 - iVar6;
  }
  else {
    iVar6 = iVar9 - iVar6;
  }
  if (iVar3 < iVar4) {
    iVar2 = iVar3 - iVar2;
  }
  else {
    iVar2 = iVar4 - iVar2;
  }
  iVar1 = iVar6;
  if (0 < iVar6) {
    iVar1 = iVar2;
  }
  if (0 < iVar1) {
    iVar8 = (iVar4 - iVar8) * (iVar9 - iVar5);
    iVar7 = (iVar3 - iVar11) * (iVar10 - iVar7);
    iVar5 = iVar8;
    if (0 < iVar8) {
      iVar5 = iVar7;
    }
    if (0 < iVar5) {
      iVar5 = iVar8;
      if (iVar7 <= iVar8) {
        iVar5 = iVar7;
      }
      iVar5 = __aeabi_idiv(iVar2 * iVar6,iVar5);
      if (iVar8 < iVar7) {
        iVar8 = iVar7;
      }
      *param_3 = (float)(longlong)iVar5;
      iVar6 = __aeabi_idiv(iVar2 * iVar6,iVar8);
      *param_4 = (float)(longlong)iVar6;
      return;
    }
  }
  *param_3 = 0.0;
  *param_4 = 0.0;
  return;
}



/* dump_campan_cfg(nn_campan_cfg_t*) */

void dump_campan_cfg(nn_campan_cfg_t *param_1)

{
  double dVar1;
  
  __android_log_print(6,"CAMPAN","%d, %d",*(undefined4 *)param_1,*(undefined4 *)(param_1 + 4));
  __android_log_print(6,"CAMPAN","model_basedir %s",*(undefined4 *)(param_1 + 0xc));
  __android_log_print(6,"CAMPAN","cb_func %p",*(undefined4 *)(param_1 + 0x10));
  __android_log_print(6,"CAMPAN","ax_freq %d",*(undefined4 *)(param_1 + 0x14));
  __android_log_print(6,"CAMPAN","max_track_count %d",*(undefined4 *)(param_1 + 0x18));
  __android_log_print(6,"CAMPAN","human_det_en %d",*(undefined4 *)(param_1 + 0x1c));
  __android_log_print(6,"CAMPAN","human_det_model_type %d",*(undefined4 *)(param_1 + 0x20));
  __android_log_print(6,"CAMPAN","face_det_en %d",*(undefined4 *)(param_1 + 0x24));
  __android_log_print(6,"CAMPAN","head_det_en %d",*(undefined4 *)(param_1 + 0x28));
  __android_log_print(6,"CAMPAN","gesture_det_en %d",*(undefined4 *)(param_1 + 0x2c));
  __android_log_print(6,"CAMPAN","reid_en %d",*(undefined4 *)(param_1 + 0x30));
  __android_log_print(6,"CAMPAN","face_feature_en %d",*(undefined4 *)(param_1 + 0x34));
  __android_log_print(6,"CAMPAN","rotate90 %d",*(undefined4 *)(param_1 + 0x38));
  __android_log_print(6,"CAMPAN","box_smooth_level %d",*(undefined4 *)(param_1 + 0x3c));
  __android_log_print(6,"CAMPAN","max_reid_feature_num %d",*(undefined4 *)(param_1 + 0x40));
  __android_log_print(6,"CAMPAN","gesture_roi_det_en %d",*(undefined4 *)(param_1 + 0x44));
  __android_log_print(6,"CAMPAN","headface_resolution %d",*(undefined4 *)(param_1 + 0x4c));
  __android_log_print(6,"CAMPAN","human_pose_det_en %d",*(undefined4 *)(param_1 + 0x48));
  __android_log_print(6,"CAMPAN","handpose_old_en %d",*(undefined4 *)(param_1 + 0x50));
  __android_log_print(6,"CAMPAN","handpose_two_cls_en %d",*(undefined4 *)(param_1 + 0x54));
  __android_log_print(6,"CAMPAN","handpose_lr_en %d",*(undefined4 *)(param_1 + 0x58));
  __android_log_print(6,"CAMPAN","min_face_feature_pixel %d",*(undefined4 *)(param_1 + 0x5c));
  dVar1 = (double)*(float *)(param_1 + 0x60);
  __android_log_print(6,"CAMPAN","face_match_thresh %.2f");
  __android_log_print(6,"CAMPAN","visual_track_en %d",*(undefined4 *)(param_1 + 100),dVar1);
  __android_log_print(6,"CAMPAN","max_headface_num:%d",*(undefined4 *)(param_1 + 0x68));
  __android_log_print(6,"CAMPAN","max_human_num:%d",*(undefined4 *)(param_1 + 0x6c));
  __android_log_print(6,"CAMPAN","max_hand_num:%d",*(undefined4 *)(param_1 + 0x70));
  __android_log_print(6,"CAMPAN","detect_merge_hand:%d",*(undefined4 *)(param_1 + 0x74));
  return;
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* campan_open(void*) */

void campan_open(void *param_1)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 *__s;
  undefined4 uVar5;
  undefined4 *puVar6;
  ax_nna_ctx_plg *paVar7;
  byte *__ptr;
  undefined4 uVar8;
  ulong *__s_00;
  uint uVar9;
  bool bVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 *puVar14;
  int *piVar15;
  int *piVar16;
  int iVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  bool bVar20;
  undefined4 local_6c;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  char local_40 [13];
  undefined4 local_33;
  undefined3 uStack_2f;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  iVar2 = open("/dev/lombo-misc",2);
  if (iVar2 < 0) {
    __android_log_print(6,"CAMPAN","error:open lombo-misc failed!\n");
    puVar6 = (undefined4 *)0x0;
    goto LAB_0001696e;
  }
  local_6c = 0x61;
  local_68 = 0;
  iVar3 = ioctl(iVar2,0xefe00000,&local_6c);
  if (iVar3 != 0) {
    __android_log_print(6,"CAMPAN","error:ioctl get module len failed! ret %d\n",iVar3);
    puVar6 = (undefined4 *)0x0;
    goto LAB_0001696e;
  }
  sVar1 = (size_t)local_68;
  pvVar4 = calloc((size_t)local_68,1);
  local_68 = CONCAT44(pvVar4,(size_t)local_68);
  if (pvVar4 == (void *)0x0) {
    __android_log_print(6,"CAMPAN","error:malloc failed! len_byte %d\n",sVar1);
    puVar6 = (undefined4 *)0x0;
    goto LAB_0001696e;
  }
  iVar3 = ioctl(iVar2,0xefe00001,&local_6c);
  if (iVar3 != 0) {
    __android_log_print(6,"CAMPAN","error:ioctl read module data failed! ret %d\n",iVar3);
    puVar6 = (undefined4 *)0x0;
    goto LAB_0001696e;
  }
  if ((size_t)local_68 == 0) {
LAB_00016736:
    __ptr = local_68._4_4_;
    if (local_68._4_4_ != (byte *)0x0) goto LAB_000169f2;
  }
  else {
    uVar12 = 0;
    do {
      uVar9 = (uint)local_68._4_4_[uVar12];
      uVar13 = uVar12 + 1;
      __android_log_print(6,"CAMPAN","product_id_buf[%d] = %x\n ",uVar12,uVar9);
      uVar12 = uVar13;
    } while (uVar13 < (size_t)local_68);
    if ((size_t)local_68 != 1) goto LAB_00016736;
    __ptr = local_68._4_4_;
    if (*local_68._4_4_ - 4 < 3) {
      __android_log_print(6,"CAMPAN","product is sa, not sv",*local_68._4_4_ - 4,uVar9);
      if (local_68._4_4_ != (byte *)0x0) {
        free(local_68._4_4_);
        local_68 = local_68 & 0xffffffff;
      }
      close(iVar2);
      puVar6 = (undefined4 *)0x0;
      goto LAB_0001696e;
    }
LAB_000169f2:
    free(__ptr);
    local_68 = local_68 & 0xffffffff;
  }
  if (iVar2 != 0) {
    close(iVar2);
  }
  builtin_strncpy(local_40,"campan V1.01",0xc);
  local_40[0xc] = 0;
  local_33 = 0;
  uStack_2f = 0;
  __android_log_print(6,"CAMPAN","%s, %s, %s, svn 6428+",local_40,"Nov 15 2023","10:17:28");
  __s = (undefined4 *)AX_MALLOC_RECORD(0x280);
  memset(__s,0,0x280);
  pvVar4 = (void *)AX_MALLOC_RECORD(0x78);
  __s[0x42] = pvVar4;
  memcpy(pvVar4,param_1,0x78);
  dump_campan_cfg((nn_campan_cfg_t *)__s[0x42]);
  puVar6 = __s + 5;
  do {
    uVar5 = dtbased_tk_create();
    puVar14 = puVar6 + 1;
    *puVar6 = uVar5;
    if (*(int *)((int)param_1 + 0x38) != 0) {
      uVar5 = dtbased_tk_create();
      puVar6[4] = uVar5;
    }
    puVar6 = puVar14;
  } while (puVar14 != __s + 9);
  uVar5 = campan_feature_match_create();
  __s[0x72] = uVar5;
  puVar6 = (undefined4 *)operator_new(0xc);
  *puVar6 = 0;
  puVar6[1] = 0;
  puVar6[2] = 0;
  __s[0x3d] = puVar6;
  puVar6 = (undefined4 *)operator_new(0xc);
  *puVar6 = 0;
  puVar6[1] = 0;
  puVar6[2] = 0;
  __s[0x3e] = puVar6;
  piVar15 = __s + 0x24;
  do {
    iVar2 = box_smooth_create(10);
    iVar3 = *(int *)((int)param_1 + 0x3c);
    if (iVar3 == 1) {
      *(undefined4 *)(iVar2 + 8) = 0x42200000;
      *(undefined4 *)(iVar2 + 0xc) = 0x3ccccccd;
      *(undefined4 *)(iVar2 + 0x10) = 0x42200000;
      *(undefined4 *)(iVar2 + 0x14) = 0x3d4ccccd;
    }
    else if (iVar3 == 2) {
      *(undefined4 *)(iVar2 + 0xc) = 0x3ccccccd;
      *(undefined4 *)(iVar2 + 0x14) = 0x3d4ccccd;
      *(undefined4 *)(iVar2 + 8) = 0x43c80000;
      *(undefined4 *)(iVar2 + 0x10) = 0x43c80000;
    }
    else if (iVar3 == 0) {
      *(undefined4 *)(iVar2 + 0xc) = 0x3ccccccd;
      *(undefined4 *)(iVar2 + 0x14) = 0x3d4ccccd;
      *(undefined4 *)(iVar2 + 8) = 0x40800000;
      *(undefined4 *)(iVar2 + 0x10) = 0x40800000;
    }
    else {
      __android_log_print(6,"CAMPAN","smooth level: 0-2 , got %d");
    }
    piVar16 = piVar15 + 1;
    *piVar15 = iVar2;
    piVar15 = piVar16;
  } while (__s + 0x28 != piVar16);
  uVar5 = kpt_smooth_create();
  __s[0x28] = uVar5;
                    /* WARNING: Load size is inaccurate */
  uVar5 = *param_1;
  uVar11 = *(undefined4 *)((int)param_1 + 4);
  *__s = uVar5;
  __s[1] = uVar11;
  __s[2] = uVar5;
  __s[3] = uVar11;
  __s[0x9e] = *(undefined4 *)((int)param_1 + 100);
  paVar7 = (ax_nna_ctx_plg *)axnn_plg_open((void *)0x0);
  __s[0x9a] = paVar7;
  getContext(paVar7,(_vx_context **)(__s + 0x40));
  __s[0x41] = (_vx_context *)__s[0x40];
  if (*(int *)((int)param_1 + 0x14) - 100U < 0x259) {
    nna_setFreq((_vx_context *)__s[0x40],*(int *)((int)param_1 + 0x14));
  }
  pthread_mutex_init((pthread_mutex_t *)(__s + 0x73),(pthread_mutexattr_t *)0x0);
  iVar2 = __s[0x42];
  uVar5 = *__s;
  uVar11 = __s[1];
  uVar19 = *(undefined4 *)(iVar2 + 8);
  local_60 = 0;
  local_5c = 0;
  local_50 = 0;
  local_4c = 0;
  uVar18 = __s[0x40];
  local_58 = uVar5;
  local_54 = uVar11;
  local_48 = uVar11;
  local_44 = uVar5;
  if (*(int *)(iVar2 + 0x2c) != 0) {
    uVar8 = handdet_create(uVar18,uVar5,uVar11,0,0,uVar5,uVar11,uVar19,0,
                           *(undefined4 *)(iVar2 + 0xc),0xffffffff,0);
    __s[0x2b] = uVar8;
    if (*(int *)(iVar2 + 0x38) != 0) {
      uVar8 = handdet_create(uVar18,uVar11,uVar5,local_50,local_4c,local_48,local_44,uVar19,0,
                             *(undefined4 *)(iVar2 + 0xc),0xffffffff,0);
      __s[0x2c] = uVar8;
    }
    if (*(int *)(iVar2 + 0x44) != 0) {
      uVar8 = handdet_create(uVar18,uVar5,uVar11,local_60,local_5c,local_58,local_54,uVar19,0,
                             *(undefined4 *)(iVar2 + 0xc),0,0);
      __s[0x2d] = uVar8;
    }
    uVar8 = handpose_create(uVar18,uVar5,uVar11,uVar19,iVar2);
    __s[0x32] = uVar8;
  }
  iVar3 = *(int *)(iVar2 + 0x1c);
  iVar17 = *(int *)(iVar2 + 0x20);
  bVar20 = iVar3 == 0;
  bVar10 = bVar20 || iVar17 != 3;
  if (*(int *)(iVar2 + 0x28) != 0) {
    uVar8 = headfacedet_create(uVar18,uVar5,uVar11,local_60,local_5c,local_58,local_54,uVar19,
                               *(undefined4 *)(iVar2 + 0x4c),*(undefined4 *)(iVar2 + 0xc),0xffffffff
                               ,1,bVar10);
    __s[0x2e] = uVar8;
    if (*(int *)(iVar2 + 0x38) != 0) {
      uVar8 = headfacedet_create(uVar18,uVar11,uVar5,local_50,local_4c,local_48,local_44,uVar19,
                                 *(undefined4 *)(iVar2 + 0x4c),*(undefined4 *)(iVar2 + 0xc),
                                 0xffffffff,1,bVar10);
      __s[0x2f] = uVar8;
    }
    uVar8 = headfacedet_create(uVar18,uVar5,uVar11,local_60,local_5c,local_58,local_54,uVar19,
                               *(undefined4 *)(iVar2 + 0x4c),*(undefined4 *)(iVar2 + 0xc),0,1,1);
    __s[0x30] = uVar8;
    iVar3 = *(int *)(iVar2 + 0x1c);
  }
  if (iVar3 != 0) {
    if (iVar17 == 0) {
      uVar8 = retina_campan_human_yolov3_create
                        (uVar18,uVar5,uVar11,local_60,local_5c,local_58,local_54,uVar19,
                         *(undefined4 *)(iVar2 + 0xc),1);
      __s[0x29] = uVar8;
      if (*(int *)(iVar2 + 0x38) != 0) {
        uVar8 = retina_campan_human_yolov3_create
                          (uVar18,uVar11,uVar5,local_50,local_4c,local_48,local_44,uVar19,
                           *(undefined4 *)(iVar2 + 0xc),1);
        __s[0x2a] = uVar8;
      }
    }
    else {
      if (iVar17 == 2) {
        uVar8 = campan_yolo_humanpose_det_create
                          (uVar18,uVar5,uVar11,local_60,local_5c,local_58,local_54,uVar19,
                           *(undefined4 *)(iVar2 + 0xc),0xffffffff,1);
        __s[0x39] = uVar8;
        if (*(int *)(iVar2 + 0x38) != 0) {
          uVar8 = campan_yolo_humanpose_det_create
                            (uVar18,uVar11,uVar5,local_50,local_4c,local_48,local_44,uVar19,
                             *(undefined4 *)(iVar2 + 0xc),0xffffffff,1);
          __s[0x39] = uVar8;
        }
      }
      else if (iVar17 == 3) {
        uVar8 = campan_yolov8_humanpose_det_create
                          (uVar18,uVar5,uVar11,local_60,local_5c,local_58,local_54,uVar19,
                           *(undefined4 *)(iVar2 + 0xc),0xffffffff,1);
        __s[0x39] = uVar8;
        if (*(int *)(iVar2 + 0x38) != 0) {
          uVar8 = campan_yolov8_humanpose_det_create
                            (uVar18,uVar11,uVar5,local_50,local_4c,local_48,local_44,uVar19,
                             *(undefined4 *)(iVar2 + 0xc),0xffffffff,1);
          __s[0x3a] = uVar8;
        }
      }
      if (!bVar20 && iVar17 == 3) {
        __s[0x98] = 0;
        __s_00 = (ulong *)AX_MALLOC_RECORD(0x9c);
        memset(__s_00,0,0x9c);
        sem_init((sem_t *)(__s_00 + 1),0,0);
        sem_init((sem_t *)(__s_00 + 5),0,0);
        nn_state_init((nn_state_t *)(__s_00 + 0xf));
        __s_00[0x16] = 0x616d7568;
        *(undefined2 *)(__s_00 + 0x18) = 0x74;
        __s_00[0x17] = 0x6564206e;
        pthread_mutex_init((pthread_mutex_t *)(__s_00 + 9),(pthread_mutexattr_t *)0x0);
        nn_thread_init(__s_00,(_func_void_ptr_void_ptr *)&LAB_0001c578_1,__s,0x8000,0x14);
        __s[0x98] = __s_00;
      }
    }
  }
  if (*(int *)(iVar2 + 0x30) != 0) {
    uVar8 = campan_reid_create(uVar18,uVar5,uVar11,uVar19,*(undefined4 *)(iVar2 + 0xc));
    __s[0x33] = uVar8;
  }
  if (*(int *)(iVar2 + 0x34) != 0) {
    uVar8 = campan_face_pose_create(uVar18,*(undefined4 *)(iVar2 + 0xc),uVar5,uVar11,uVar19);
    __s[0x34] = uVar8;
    uVar8 = campan_face_feature_create(uVar18,*(undefined4 *)(iVar2 + 0xc),uVar5,uVar11,uVar19);
    __s[0x3b] = uVar8;
  }
  if (*(int *)(iVar2 + 0x48) != 0) {
    uVar5 = campan_human_pose_create(uVar18,*(undefined4 *)(iVar2 + 0xc),uVar5,uVar11,uVar19);
    __s[0x36] = uVar5;
  }
  flush_model_temp_memory();
  puVar6 = __s + 0x5a;
  __s[0x5b] = &DAT_00015df5;
  __s[0x5c] = 0x15bd9;
  __s[0x5e] = local_40;
  __s[0x5a] = &LAB_0001d160_1;
  __s[0x6f] = 0xffffffff;
  __s[0x70] = 0;
  __s[0x5d] = &LAB_000172c0_1;
  __s[0x71] = 0x34;
LAB_0001696e:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(puVar6);
  }
  return;
}



void nn_campan_open_interface(undefined4 param_1)

{
  nn_hermes_open(campan_open,param_1,0x78);
  return;
}



void nn_campan_cmd_interface(void)

{
  nn_hermes_cmd();
  return;
}



void nn_campan_close_interface(void)

{
  undefined4 in_r3;
  
  nn_hermes_close();
  __android_log_print(6,"CAMPAN","campan stopped",in_r3);
  return;
}



/* void AX_MALLOC_INC_TEMP<nn_campan_persons_t>(nn_campan_persons_t&, int) */

void AX_MALLOC_INC_TEMP<nn_campan_persons_t>(nn_campan_persons_t *param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = *(void **)param_1;
  *(int *)(param_1 + 4) = param_2;
  iVar2 = param_2 * 0x2a8;
  if (pvVar1 == (void *)0x0) {
    if (iVar2 < 1) {
      return;
    }
  }
  else {
    if (*(int *)((int)pvVar1 + -4) + param_2 * -0x2a8 < 0 ==
        SBORROW4(*(int *)((int)pvVar1 + -4),iVar2)) {
      return;
    }
    AX_FREE_RECORD(pvVar1);
    *(undefined4 *)param_1 = 0;
  }
  iVar2 = AX_MALLOC_RECORD(iVar2);
  *(int *)param_1 = iVar2;
  if (iVar2 != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}



/* void AX_ARRAY_PUSH_BACK<nn_campan_heads_t, nn_campan_head_t>(nn_campan_heads_t&,
   nn_campan_head_t&) */

void AX_ARRAY_PUSH_BACK<nn_campan_heads_t,nn_campan_head_t>
               (nn_campan_heads_t *param_1,nn_campan_head_t *param_2)

{
  void *__src;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  void *__dest;
  int iVar6;
  size_t __n;
  
  iVar4 = *(int *)(param_1 + 4);
  __dest = *(void **)param_1;
  iVar6 = iVar4 + 1;
  if (__dest == (void *)0x0) {
    if (iVar6 * 0x3c < 1) goto LAB_00016ec4;
    __dest = (void *)AX_MALLOC_RECORD(iVar6 * 0x78);
    __src = *(void **)param_1;
    __n = 0;
  }
  else {
    __n = *(size_t *)((int)__dest + -4);
    if ((int)(__n + iVar6 * -0x3c) < 0 == SBORROW4(__n,iVar6 * 0x3c)) goto LAB_00016ec4;
    __dest = (void *)AX_MALLOC_RECORD(iVar6 * 0x78);
    __src = *(void **)param_1;
  }
  if (__src != (void *)0x0) {
    memcpy(__dest,__src,__n);
    AX_FREE_RECORD(*(void **)param_1);
  }
  iVar4 = *(int *)(param_1 + 4);
  *(void **)param_1 = __dest;
LAB_00016ec4:
  puVar5 = (undefined4 *)(iVar4 * 0x3c + (int)__dest);
  uVar1 = *(undefined4 *)(param_2 + 4);
  uVar2 = *(undefined4 *)(param_2 + 8);
  uVar3 = *(undefined4 *)(param_2 + 0xc);
  *puVar5 = *(undefined4 *)param_2;
  puVar5[1] = uVar1;
  puVar5[2] = uVar2;
  puVar5[3] = uVar3;
  uVar1 = *(undefined4 *)(param_2 + 0x14);
  uVar2 = *(undefined4 *)(param_2 + 0x18);
  uVar3 = *(undefined4 *)(param_2 + 0x1c);
  puVar5[4] = *(undefined4 *)(param_2 + 0x10);
  puVar5[5] = uVar1;
  puVar5[6] = uVar2;
  puVar5[7] = uVar3;
  uVar1 = *(undefined4 *)(param_2 + 0x24);
  uVar2 = *(undefined4 *)(param_2 + 0x28);
  uVar3 = *(undefined4 *)(param_2 + 0x2c);
  puVar5[8] = *(undefined4 *)(param_2 + 0x20);
  puVar5[9] = uVar1;
  puVar5[10] = uVar2;
  puVar5[0xb] = uVar3;
  uVar1 = *(undefined4 *)(param_2 + 0x34);
  uVar2 = *(undefined4 *)(param_2 + 0x38);
  puVar5[0xc] = *(undefined4 *)(param_2 + 0x30);
  puVar5[0xd] = uVar1;
  puVar5[0xe] = uVar2;
  *(int *)(param_1 + 4) = iVar6;
  return;
}



/* ax_rect_t clip_rect_adaptive<ax_rect_t, ax_size_t>(ax_rect_t, ax_size_t) */

uint * clip_rect_adaptive<ax_rect_t,ax_size_t>
                 (uint *param_1,uint param_2,uint param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if ((int)param_2 < 0) {
    uVar1 = param_4 - 1;
    param_2 = 0;
  }
  else {
    uVar1 = (param_4 + param_2) - 1;
  }
  uVar6 = param_6 - 1;
  if ((int)param_3 < 0) {
    uVar3 = param_5 - 1;
    param_3 = 0;
  }
  else {
    uVar3 = (param_5 + param_3) - 1;
  }
  uVar5 = param_7 - 1;
  if (param_6 <= (int)uVar1) {
    param_2 = uVar6 - param_4;
    uVar1 = uVar6;
  }
  if (param_7 <= (int)uVar3) {
    param_3 = uVar5 - param_5;
    uVar3 = uVar5;
  }
  param_2 = param_2 & ~((int)param_2 >> 0x1f);
  param_3 = param_3 & ~((int)param_3 >> 0x1f);
  uVar1 = uVar1 & ~((int)uVar1 >> 0x1f);
  if ((int)uVar6 <= (int)param_2) {
    param_2 = uVar6;
  }
  uVar3 = uVar3 & ~((int)uVar3 >> 0x1f);
  if ((int)uVar5 <= (int)param_3) {
    param_3 = uVar5;
  }
  if ((int)uVar6 < (int)uVar1) {
    iVar2 = uVar6 - param_2;
  }
  else {
    iVar2 = uVar1 - param_2;
  }
  if ((int)uVar5 < (int)uVar3) {
    iVar4 = uVar5 - param_3;
  }
  else {
    iVar4 = uVar3 - param_3;
  }
  param_1[2] = iVar2 + 1;
  param_1[3] = iVar4 + 1;
  *param_1 = param_2;
  param_1[1] = param_3;
  return param_1;
}



/* void AX_ARRAY_PUSH_BACK<ax_detect_box_array_t, ax_detect_box_t>(ax_detect_box_array_t&,
   ax_detect_box_t&) */

void AX_ARRAY_PUSH_BACK<ax_detect_box_array_t,ax_detect_box_t>
               (ax_detect_box_array_t *param_1,ax_detect_box_t *param_2)

{
  void *__src;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  void *__dest;
  int iVar6;
  size_t __n;
  
  iVar4 = *(int *)(param_1 + 4);
  __dest = *(void **)param_1;
  iVar6 = iVar4 + 1;
  if (__dest == (void *)0x0) {
    if (iVar6 * 0x1c < 1) goto LAB_00016fe0;
    __dest = (void *)AX_MALLOC_RECORD(iVar6 * 0x38);
    __src = *(void **)param_1;
    __n = 0;
  }
  else {
    __n = *(size_t *)((int)__dest + -4);
    if ((int)(__n + iVar6 * -0x1c) < 0 == SBORROW4(__n,iVar6 * 0x1c)) goto LAB_00016fe0;
    __dest = (void *)AX_MALLOC_RECORD(iVar6 * 0x38);
    __src = *(void **)param_1;
  }
  if (__src != (void *)0x0) {
    memcpy(__dest,__src,__n);
    AX_FREE_RECORD(*(void **)param_1);
  }
  iVar4 = *(int *)(param_1 + 4);
  *(void **)param_1 = __dest;
LAB_00016fe0:
  puVar5 = (undefined4 *)(iVar4 * 0x1c + (int)__dest);
  uVar1 = *(undefined4 *)(param_2 + 4);
  uVar2 = *(undefined4 *)(param_2 + 8);
  uVar3 = *(undefined4 *)(param_2 + 0xc);
  *puVar5 = *(undefined4 *)param_2;
  puVar5[1] = uVar1;
  puVar5[2] = uVar2;
  puVar5[3] = uVar3;
  uVar1 = *(undefined4 *)(param_2 + 0x14);
  uVar2 = *(undefined4 *)(param_2 + 0x18);
  puVar5[4] = *(undefined4 *)(param_2 + 0x10);
  puVar5[5] = uVar1;
  puVar5[6] = uVar2;
  *(int *)(param_1 + 4) = iVar6;
  return;
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */

int * FUN_00017014(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6,ax_detect_box_array_t *param_7)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  retina_t *prVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  ax_detect_box_t *paVar13;
  int iVar14;
  int *piVar15;
  float fVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  float fVar23;
  int *local_254;
  undefined4 local_250;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  undefined4 uStack_244;
  undefined4 local_240;
  undefined4 uStack_23c;
  undefined4 uStack_238;
  undefined4 uStack_234;
  undefined4 local_230;
  undefined4 local_228;
  undefined4 uStack_224;
  int iStack_220;
  int iStack_21c;
  undefined4 local_214;
  undefined4 uStack_210;
  undefined8 local_20c;
  undefined4 local_204;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  undefined4 uStack_1f8;
  undefined4 local_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 uStack_1dc;
  int iStack_1d8;
  int iStack_1d4;
  undefined4 local_1d0;
  undefined4 local_40;
  undefined4 local_3c;
  
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x1cc));
  prVar9 = *(retina_t **)(param_1 + 0xb4);
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x1cc));
  if (prVar9 == (retina_t *)0x0) {
    local_254 = (int *)0x0;
  }
  else {
    local_214 = *param_2;
    uStack_210 = param_2[1];
    clip_rect_adaptive<ax_rect_t,ax_size_t>
              (&local_228,param_3,param_4,param_5,param_6,local_214,uStack_210);
    local_20c = 0;
    uVar19 = iStack_220 - 6U;
    if (iStack_220 - 6U < 0x7ca) {
      uVar19 = iStack_21c - 6;
    }
    if (uVar19 < 0x7ca) {
      nnyuv2axyuv((nn_yuv_t *)&local_250);
      local_204 = local_250;
      uStack_200 = uStack_24c;
      uStack_1fc = uStack_248;
      uStack_1f8 = uStack_244;
      local_1f4 = local_240;
      uStack_1f0 = uStack_23c;
      uStack_1ec = uStack_238;
      uStack_1e8 = uStack_234;
      local_1e4 = local_230;
      local_1d0 = 0x3f51eb85;
      local_1e0 = local_228;
      uStack_1dc = uStack_224;
      iStack_1d8 = iStack_220;
      iStack_1d4 = iStack_21c;
      local_40 = 0x3f000000;
      local_3c = 0x3f400000;
      retina_process(prVar9,(retina_in_t *)&local_204,(retina_out_t *)&local_20c);
      piVar1 = local_20c._4_4_;
      local_254 = local_20c._4_4_;
      iVar4 = local_20c._4_4_[1];
      if (0 < iVar4) {
        iVar12 = 0;
        do {
          if (param_7 != (ax_detect_box_array_t *)0x0) {
            paVar13 = (ax_detect_box_t *)(*local_20c._4_4_ + iVar12 * 0x1c);
            if (0 < *(int *)(param_7 + 4)) {
              iVar3 = *(int *)(*local_20c._4_4_ + iVar12 * 0x1c);
              iVar10 = *(int *)(paVar13 + 4);
              iVar14 = *(int *)(paVar13 + 8);
              iVar11 = *(int *)(paVar13 + 0xc);
              piVar8 = *(int **)param_7;
              fVar16 = 0.0;
              piVar15 = piVar8 + *(int *)(param_7 + 4) * 7;
              do {
                iVar7 = *piVar8;
                iVar2 = piVar8[1];
                iVar5 = piVar8[2];
                iVar6 = piVar8[3];
                piVar8 = piVar8 + 7;
                iVar22 = iVar3;
                if (iVar3 <= iVar7) {
                  iVar22 = iVar7;
                }
                iVar20 = iVar10;
                if (iVar10 <= iVar2) {
                  iVar20 = iVar2;
                }
                iVar18 = iVar5;
                if (iVar14 < iVar5) {
                  iVar18 = iVar14;
                }
                iVar17 = iVar6;
                if (iVar11 < iVar6) {
                  iVar17 = iVar11;
                }
                uVar19 = (uint)(((float)(longlong)iVar18 - (float)(longlong)iVar22) + 1.0);
                uVar21 = (uint)(((float)(longlong)iVar17 - (float)(longlong)iVar20) + 1.0);
                if ((int)(uVar19 | uVar21) < 0) {
                  fVar23 = 0.0;
                }
                else {
                  fVar23 = (float)(longlong)(int)uVar19 * (float)(longlong)(int)uVar21;
                }
                fVar23 = fVar23 / (((float)(longlong)(((iVar6 - iVar2) + 1) * ((iVar5 - iVar7) + 1))
                                   + (float)(longlong)
                                            (((iVar11 - iVar10) + 1) * ((iVar14 - iVar3) + 1))) -
                                  fVar23);
                if (fVar23 != fVar16 && fVar23 < fVar16 == (NAN(fVar23) || NAN(fVar16))) {
                  fVar16 = fVar23;
                }
              } while (piVar8 != piVar15);
              if (-1 < (int)((uint)(fVar16 < 0.3) << 0x1f)) goto LAB_00017226;
            }
            AX_ARRAY_PUSH_BACK<ax_detect_box_array_t,ax_detect_box_t>(param_7,paVar13);
          }
LAB_00017226:
          iVar12 = iVar12 + 1;
          if (iVar4 == iVar12) {
            return piVar1;
          }
        } while( true );
      }
    }
    else {
      local_254 = (int *)0x0;
      __android_log_print(6,"CAMPAN","hand roi wrong %d, %d, %d, %d",local_228,uStack_224,iStack_220
                          ,iStack_21c);
    }
  }
  return local_254;
}



/* void AX_MALLOC_INC_TEMP<nn_campan_faces_t>(nn_campan_faces_t&, int) */

void AX_MALLOC_INC_TEMP<nn_campan_faces_t>(nn_campan_faces_t *param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = *(void **)param_1;
  *(int *)(param_1 + 4) = param_2;
  iVar2 = param_2 * 0x178;
  if (pvVar1 == (void *)0x0) {
    if (iVar2 < 1) {
      return;
    }
  }
  else {
    if (*(int *)((int)pvVar1 + -4) + param_2 * -0x178 < 0 ==
        SBORROW4(*(int *)((int)pvVar1 + -4),iVar2)) {
      return;
    }
    AX_FREE_RECORD(pvVar1);
    *(undefined4 *)param_1 = 0;
  }
  iVar2 = AX_MALLOC_RECORD(iVar2);
  *(int *)param_1 = iVar2;
  if (iVar2 != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}



/* void std::vector<ax_track_box_t, std::allocator<ax_track_box_t>
   >::_M_realloc_insert<ax_track_box_t const&>(__gnu_cxx::__normal_iterator<ax_track_box_t*,
   std::vector<ax_track_box_t, std::allocator<ax_track_box_t> > >, ax_track_box_t const&) */

void __thiscall
std::vector<ax_track_box_t,std::allocator<ax_track_box_t>>::_M_realloc_insert<ax_track_box_t_const&>
          (vector<ax_track_box_t,std::allocator<ax_track_box_t>> *this,void *param_2,
          undefined4 *param_3)

{
  void *__dest;
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  size_t sVar7;
  undefined4 *puVar8;
  size_t __n;
  void *__dest_00;
  void *__src;
  void *pvVar9;
  undefined4 uVar10;
  
  __src = *(void **)this;
  pvVar9 = *(void **)(this + 4);
  sVar7 = (int)param_2 - (int)__src;
  iVar1 = (int)pvVar9 - (int)__src >> 2;
  uVar5 = iVar1 * -0x33333333;
  if (uVar5 == 0) {
    uVar2 = 1;
LAB_00017834:
    uVar2 = uVar2 * 0x14;
  }
  else {
    uVar2 = iVar1 * -0x66666666;
    if ((uVar5 < uVar2 || uVar5 == 0) && (uVar2 < 0xccccccd)) {
      if (uVar2 == 0) {
        __dest = (void *)0x0;
        iVar1 = 0;
        __n = sVar7;
        goto LAB_000177dc;
      }
      goto LAB_00017834;
    }
    uVar2 = 0xfffffff0;
  }
  __dest = operator_new(uVar2);
  __src = *(void **)this;
  iVar1 = uVar2 + (int)__dest;
  pvVar9 = *(void **)(this + 4);
  __n = (int)param_2 - (int)__src;
LAB_000177dc:
  puVar8 = (undefined4 *)((int)__dest + sVar7);
  if (puVar8 != (undefined4 *)0x0) {
    uVar3 = param_3[1];
    uVar4 = param_3[2];
    uVar6 = param_3[3];
    uVar10 = param_3[4];
    *puVar8 = *param_3;
    puVar8[1] = uVar3;
    puVar8[2] = uVar4;
    puVar8[3] = uVar6;
    puVar8[4] = uVar10;
  }
  if (param_2 != __src) {
    memmove(__dest,__src,__n);
  }
  __dest_00 = (void *)(__n + 0x14 + (int)__dest);
  if (pvVar9 != param_2) {
    memcpy(__dest_00,param_2,(int)pvVar9 - (int)param_2);
  }
  if (__src != (void *)0x0) {
    operator_delete(__src);
  }
  *(void **)this = __dest;
  *(int *)(this + 4) = (int)__dest_00 + ((int)pvVar9 - (int)param_2);
  *(int *)(this + 8) = iVar1;
  return;
}



/* void std::vector<int, std::allocator<int> >::_M_realloc_insert<int
   const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&)
    */

void __thiscall
std::vector<int,std::allocator<int>>::_M_realloc_insert<int_const&>
          (vector<int,std::allocator<int>> *this,void *param_2,undefined4 *param_3)

{
  void *__dest;
  uint uVar1;
  void *__dest_00;
  size_t __n;
  void *__src;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  size_t sVar5;
  
  __src = *(void **)this;
  pvVar4 = *(void **)(this + 4);
  sVar5 = (int)param_2 - (int)__src;
  uVar1 = (int)pvVar4 - (int)__src >> 2;
  if (uVar1 == 0) {
    uVar2 = 1;
LAB_000178e2:
    uVar2 = uVar2 << 2;
  }
  else {
    uVar2 = uVar1 * 2;
    if ((uVar1 <= uVar2) && (uVar2 < 0x40000000)) {
      if (uVar2 == 0) {
        iVar3 = 0;
        __dest = (void *)0x0;
        __n = sVar5;
        goto LAB_00017894;
      }
      goto LAB_000178e2;
    }
    uVar2 = 0xfffffffc;
  }
  __dest = operator_new(uVar2);
  __src = *(void **)this;
  iVar3 = uVar2 + (int)__dest;
  pvVar4 = *(void **)(this + 4);
  __n = (int)param_2 - (int)__src;
LAB_00017894:
  if ((int)__dest + sVar5 != 0) {
    *(undefined4 *)((int)__dest + sVar5) = *param_3;
  }
  if (param_2 != __src) {
    memmove(__dest,__src,__n);
  }
  __dest_00 = (void *)(__n + 4 + (int)__dest);
  if (pvVar4 != param_2) {
    __dest_00 = memcpy(__dest_00,param_2,(int)pvVar4 - (int)param_2);
  }
  if (__src != (void *)0x0) {
    operator_delete(__src);
  }
  *(void **)this = __dest;
  *(int *)(this + 4) = (int)__dest_00 + ((int)pvVar4 - (int)param_2);
  *(int *)(this + 8) = iVar3;
  return;
}



/* void std::vector<ax_track_kpt_t, std::allocator<ax_track_kpt_t>
   >::_M_realloc_insert<ax_track_kpt_t const&>(__gnu_cxx::__normal_iterator<ax_track_kpt_t*,
   std::vector<ax_track_kpt_t, std::allocator<ax_track_kpt_t> > >, ax_track_kpt_t const&) */

void __thiscall
std::vector<ax_track_kpt_t,std::allocator<ax_track_kpt_t>>::_M_realloc_insert<ax_track_kpt_t_const&>
          (vector<ax_track_kpt_t,std::allocator<ax_track_kpt_t>> *this,void *param_2,void *param_3)

{
  void *__dest;
  void *pvVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  size_t __n;
  void *__src;
  void *pvVar5;
  size_t sVar6;
  
  __src = *(void **)this;
  pvVar5 = *(void **)(this + 4);
  sVar6 = (int)param_2 - (int)__src;
  iVar2 = (int)pvVar5 - (int)__src >> 2;
  uVar4 = iVar2 * -0x75075075;
  if (uVar4 == 0) {
    uVar3 = 1;
LAB_00017990:
    uVar3 = uVar3 * 0x8c;
  }
  else {
    uVar3 = iVar2 * 0x15f15f16;
    if ((uVar4 < uVar3 || uVar4 == 0) && (uVar3 < 0x1d41d42)) {
      if (uVar3 == 0) {
        __dest = (void *)0x0;
        iVar2 = 0;
        __n = sVar6;
        goto LAB_0001793e;
      }
      goto LAB_00017990;
    }
    uVar3 = 0xffffff8c;
  }
  __dest = operator_new(uVar3);
  __src = *(void **)this;
  iVar2 = uVar3 + (int)__dest;
  pvVar5 = *(void **)(this + 4);
  __n = (int)param_2 - (int)__src;
LAB_0001793e:
  pvVar1 = (void *)((int)__dest + sVar6);
  if (pvVar1 != (void *)0x0) {
    memcpy(pvVar1,param_3,0x8c);
  }
  if (param_2 != __src) {
    memmove(__dest,__src,__n);
  }
  pvVar1 = (void *)(__n + 0x8c + (int)__dest);
  if (pvVar5 != param_2) {
    pvVar1 = memcpy(pvVar1,param_2,(int)pvVar5 - (int)param_2);
  }
  if (__src != (void *)0x0) {
    operator_delete(__src);
  }
  *(void **)this = __dest;
  *(int *)(this + 4) = (int)pvVar1 + ((int)pvVar5 - (int)param_2);
  *(int *)(this + 8) = iVar2;
  return;
}



/* std::vector<int, std::allocator<int> >::_M_erase(__gnu_cxx::__normal_iterator<int*,
   std::vector<int, std::allocator<int> > >) */

void * __thiscall
std::vector<int,std::allocator<int>>::_M_erase(vector<int,std::allocator<int>> *this,void *param_2)

{
  void *__src;
  void *pvVar1;
  
  pvVar1 = *(void **)(this + 4);
  __src = (void *)((int)param_2 + 4);
  if (pvVar1 != __src) {
    param_2 = memmove(param_2,__src,(int)pvVar1 - (int)__src);
    pvVar1 = *(void **)(this + 4);
  }
  *(int *)(this + 4) = (int)pvVar1 + -4;
  return param_2;
}



/* void std::vector<float, std::allocator<float> >::_M_realloc_insert<float
   const&>(__gnu_cxx::__normal_iterator<float*, std::vector<float, std::allocator<float> > >, float
   const&) */

void __thiscall
std::vector<float,std::allocator<float>>::_M_realloc_insert<float_const&>
          (vector<float,std::allocator<float>> *this,void *param_2,undefined4 *param_3)

{
  void *__dest;
  uint uVar1;
  void *__dest_00;
  size_t __n;
  void *__src;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  size_t sVar5;
  undefined4 *puVar6;
  
  __src = *(void **)this;
  pvVar4 = *(void **)(this + 4);
  sVar5 = (int)param_2 - (int)__src;
  uVar1 = (int)pvVar4 - (int)__src >> 2;
  if (uVar1 == 0) {
    uVar2 = 1;
LAB_00017a62:
    uVar2 = uVar2 << 2;
  }
  else {
    uVar2 = uVar1 * 2;
    if ((uVar1 <= uVar2) && (uVar2 < 0x40000000)) {
      if (uVar2 == 0) {
        iVar3 = 0;
        __dest = (void *)0x0;
        __n = sVar5;
        goto LAB_00017a14;
      }
      goto LAB_00017a62;
    }
    uVar2 = 0xfffffffc;
  }
  __dest = operator_new(uVar2);
  __src = *(void **)this;
  iVar3 = uVar2 + (int)__dest;
  pvVar4 = *(void **)(this + 4);
  __n = (int)param_2 - (int)__src;
LAB_00017a14:
  puVar6 = (undefined4 *)((int)__dest + sVar5);
  if (puVar6 != (undefined4 *)0x0) {
    *puVar6 = *param_3;
  }
  if (param_2 != __src) {
    memmove(__dest,__src,__n);
  }
  __dest_00 = (void *)(__n + 4 + (int)__dest);
  if (pvVar4 != param_2) {
    __dest_00 = memcpy(__dest_00,param_2,(int)pvVar4 - (int)param_2);
  }
  if (__src != (void *)0x0) {
    operator_delete(__src);
  }
  *(void **)this = __dest;
  *(int *)(this + 4) = (int)__dest_00 + ((int)pvVar4 - (int)param_2);
  *(int *)(this + 8) = iVar3;
  return;
}



/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_00017a78(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  _List_node_base *p_Var4;
  _List_node_base *p_Var5;
  _List_node_base *p_Var6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 *puVar16;
  undefined4 *******pppppppuVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  int iVar20;
  int iVar21;
  int *piVar22;
  void *pvVar23;
  int *piVar24;
  undefined4 *******pppppppuVar25;
  int **ppiVar26;
  undefined4 *puVar27;
  uint uVar28;
  undefined4 *puVar29;
  int iVar30;
  int iVar31;
  int *piVar32;
  int iVar33;
  int *piVar34;
  int iVar35;
  int *piVar36;
  int **ppiVar37;
  int iVar38;
  int iVar39;
  bool bVar40;
  double dVar41;
  double dVar42;
  float fVar43;
  int iVar44;
  uint uVar45;
  int iVar46;
  int iVar47;
  uint uVar48;
  float fVar49;
  float fVar50;
  double dVar51;
  uint local_350;
  int *local_34c;
  void *local_348;
  uint local_344;
  int *local_304;
  int local_2fc;
  float local_2f8;
  void *local_2f4;
  int *local_2f0;
  int *local_2ec;
  int *local_2e8;
  float *local_2e4;
  float *local_2e0;
  undefined4 *******local_2dc;
  undefined4 *******pppppppuStack_2d8;
  undefined4 local_2d4;
  undefined4 *******local_2d0;
  undefined4 *******pppppppuStack_2cc;
  undefined4 local_2c8;
  undefined4 local_2c4 [9];
  undefined4 local_2a0;
  undefined4 local_29c;
  undefined4 *******local_298;
  undefined4 *******pppppppuStack_294;
  undefined4 local_290;
  undefined4 *******local_28c;
  undefined4 *******pppppppuStack_288;
  undefined4 local_284;
  int local_280 [12];
  int local_250 [4];
  double local_240;
  undefined8 local_238;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  undefined4 local_21c;
  undefined4 local_218;
  undefined4 uStack_214;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  undefined4 local_208;
  undefined4 uStack_204;
  undefined4 local_200;
  undefined4 uStack_1fc;
  undefined8 local_1f8;
  undefined4 local_1f0;
  undefined4 uStack_1ec;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined1 auStack_1d8 [4];
  int local_1d4;
  int local_1d0;
  int local_1cc;
  uint local_1c8;
  float local_18c;
  float local_188;
  nn_campan_face_feature_t anStack_178 [284];
  int local_5c;
  
  iVar2 = *(int *)(param_1 + 0x108);
  dVar51 = *(double *)(param_1 + 0x270);
  local_5c = __stack_chk_guard;
  puVar10 = *(undefined4 **)(*(int *)(param_1 + 0x1c8) + 0xabc);
  iVar7 = *(int *)(iVar2 + 0x5c);
  uVar11 = *(undefined4 *)(param_1 + 0x1c);
  if (0 < *(int *)(param_1 + 300)) {
    local_34c = (int *)0x0;
    do {
      iVar12 = *(int *)(param_1 + 0x128);
      iVar8 = (int)local_34c * 0x3c;
      iVar38 = iVar12 + iVar8;
      *(undefined4 *)(iVar38 + 0x2c) = 0;
      *(undefined4 *)(iVar38 + 0x30) = 0;
      *(undefined4 *)(iVar38 + 0x38) = 0;
      puVar16 = (undefined4 *)*puVar10;
      puVar27 = puVar10;
      if (puVar16 != puVar10) {
        iVar14 = puVar16[3];
        while (iVar14 != *(int *)(iVar12 + iVar8)) {
          puVar16 = (undefined4 *)*puVar16;
          puVar27 = puVar16;
          if (puVar16 == puVar10) goto LAB_00017b14;
          iVar14 = puVar16[3];
        }
        puVar27 = puVar16;
        if (puVar16[0x2b] != 0) {
          *(undefined4 *)(iVar38 + 0x30) = puVar16[0x2b];
        }
      }
LAB_00017b14:
      iVar33 = *(int *)(iVar38 + 4);
      iVar39 = *(int *)(iVar38 + 8);
      iVar35 = *(int *)(iVar38 + 0xc);
      iVar14 = *(int *)(iVar38 + 0x10);
      if (*(int *)(param_1 + 0x124) < 1) {
LAB_00018124:
        *(undefined4 *)(iVar38 + 0x34) = 0xffffffff;
        local_348 = (void *)0x0;
        if (puVar27 == puVar10) goto LAB_00018138;
LAB_00017c6a:
        puVar27[0x30] = puVar27[0x30] + 1;
        if (puVar27[7] == 0) {
          *(undefined4 *)(iVar38 + 0x38) = 1;
        }
        else {
          *(undefined4 *)(iVar38 + 0x38) = 2;
          if ((*(int *)(iVar38 + 0x30) != 0) && (puVar27[0x42] == 1)) {
            if (DAT_0003a678 != 0) {
              __android_log_print(6,"CAMPAN","set %d track register done cost %.2f s",puVar27[2],
                                  *(double *)(param_1 + 0x270) - *(double *)(puVar27 + 0x40));
            }
            puVar27[0x42] = 2;
          }
        }
        if ((local_348 != (void *)0x0) && (0 < *(int *)((int)local_348 + 0x170))) {
          piVar24 = puVar27 + 8;
          if (((int)((uint)(ABS(*(float *)((int)local_348 + 0x4c)) < 40.0) << 0x1f) < 0) &&
             ((int)((uint)(ABS(*(float *)((int)local_348 + 0x50)) < 40.0) << 0x1f) < 0)) {
            piVar22 = (int *)puVar27[8];
            if (piVar24 == piVar22) {
              local_344 = puVar27[10];
              if (local_344 < 5) goto LAB_00019312;
            }
            else {
              dVar41 = 0.0;
              do {
                dVar42 = (double)face_feature_dist((nn_campan_face_feature_t *)(piVar22 + 0x1a),
                                                   (nn_campan_face_feature_t *)
                                                   ((int)local_348 + 0x60));
                piVar22 = (int *)*piVar22;
                if (dVar42 != dVar41 && dVar42 < dVar41 == (NAN(dVar42) || NAN(dVar41))) {
                  dVar41 = dVar42;
                }
              } while (piVar24 != piVar22);
              local_344 = puVar27[10];
              if (local_344 < 5) {
LAB_00019312:
                p_Var4 = (_List_node_base *)operator_new(0x180);
                memcpy(p_Var4 + 8,local_348,0x178);
              }
              else {
                if ((dVar41 == 0.0 || dVar41 < 0.0 != NAN(dVar41)) ||
                   (-1 < (int)((uint)(dVar41 < 1.0) << 0x1f))) goto LAB_00019090;
                p_Var4 = (_List_node_base *)operator_new(0x180);
                memcpy(p_Var4 + 8,local_348,0x178);
              }
              std::__detail::_List_node_base::_M_hook(p_Var4);
              local_344 = puVar27[10] + 1;
              puVar27[10] = local_344;
            }
LAB_00019090:
            if (10 < local_344) {
              pvVar23 = (void *)puVar27[9];
              puVar27[10] = local_344 - 1;
              std::__detail::_List_node_base::_M_unhook();
              operator_delete(pvVar23);
              goto LAB_00017cc4;
            }
          }
          else {
LAB_00017cc4:
            local_344 = puVar27[10];
          }
          if (local_344 == 0) {
            fVar43 = 0.0;
LAB_000182ee:
            if ((uint)puVar27[7] < 3) goto LAB_000182fa;
LAB_00018d5c:
            puVar16 = puVar27 + 5;
            puVar29 = (undefined4 *)*puVar16;
            if (puVar16 == puVar29) goto LAB_00017e8c;
            dVar41 = 0.0;
            do {
              dVar42 = (double)face_feature_dist((nn_campan_face_feature_t *)(puVar29 + 0x1a),
                                                 anStack_178);
              puVar29 = (undefined4 *)*puVar29;
              if (dVar42 != dVar41 && dVar42 < dVar41 == (NAN(dVar42) || NAN(dVar41))) {
                dVar41 = dVar42;
              }
            } while (puVar16 != puVar29);
            if ((dVar41 == 0.45 || dVar41 < 0.45 != NAN(dVar41)) ||
               (-1 < (int)((uint)(dVar41 < 0.7) << 0x1f))) goto LAB_00017e8c;
            fVar43 = (float)dVar41;
            for (piVar22 = (int *)puVar27[5]; puVar29 != piVar22; piVar22 = (int *)*piVar22) {
              fVar49 = ABS((float)piVar22[0x15]);
              if ((((fVar49 != 10.0 && fVar49 < 10.0 == NAN(fVar49)) &&
                   (fVar50 = ABS((float)piVar22[0x16]),
                   fVar50 != 10.0 && fVar50 < 10.0 == NAN(fVar50))) &&
                  ((int)((uint)(ABS(local_18c) + ABS(local_188) <
                               (float)(longlong)(int)(fVar49 + fVar50)) << 0x1f) < 0)) &&
                 (fVar43 != 0.5 && fVar43 < 0.5 == NAN(fVar43))) {
                memcpy(piVar22 + 2,auStack_1d8,0x178);
                break;
              }
            }
            iVar38 = *(int *)(param_1 + 0x1c8);
            fVar43 = (float)(longlong)(int)((local_1c8 - local_1d0) * (local_1cc - local_1d4));
            if ((int)((uint)(fVar43 < *(float *)(iVar38 + 0x50c)) << 0x1f) < 0) {
              iVar38 = 0;
            }
            else if ((int)((uint)(fVar43 < *(float *)(iVar38 + 0x510)) << 0x1f) < 0) {
              iVar38 = 1;
            }
            else {
              if (-1 < (int)((uint)(fVar43 < *(float *)(iVar38 + 0x514)) << 0x1f))
              goto LAB_00017e8c;
              iVar38 = 2;
            }
            puVar29 = puVar27 + iVar38 * 3 + 0xb;
            puVar16 = (undefined4 *)puVar27[iVar38 * 3 + 0xb];
            if (puVar29[2] != 0) {
              if (puVar29 != puVar16) {
                dVar41 = 0.0;
                do {
                  dVar42 = (double)face_feature_dist((nn_campan_face_feature_t *)(puVar16 + 0x1a),
                                                     anStack_178);
                  puVar16 = (undefined4 *)*puVar16;
                  if (dVar42 != dVar41 && dVar42 < dVar41 == (NAN(dVar42) || NAN(dVar41))) {
                    dVar41 = dVar42;
                  }
                } while (puVar16 != puVar29);
                if ((dVar41 != 0.5 && dVar41 < 0.5 == NAN(dVar41)) &&
                   ((int)((uint)(dVar41 < 0.699999988079071) << 0x1f) < 0)) goto LAB_00017e30;
              }
              goto LAB_00017e8c;
            }
LAB_00017e30:
            p_Var4 = (_List_node_base *)operator_new(0x180);
            memcpy(p_Var4 + 8,auStack_1d8,0x178);
            std::__detail::_List_node_base::_M_hook(p_Var4);
            iVar38 = puVar29[2];
            uVar45 = iVar38 + 1;
            puVar29[2] = uVar45;
            if (4 < uVar45) {
              pvVar23 = (void *)puVar29[1];
              puVar29[2] = iVar38;
              std::__detail::_List_node_base::_M_unhook();
              operator_delete(pvVar23);
            }
            piVar22 = (int *)puVar27[8];
            while (piVar24 != piVar22) {
              piVar36 = (int *)*piVar22;
              operator_delete(piVar22);
              piVar22 = piVar36;
            }
LAB_00017e82:
            puVar27[8] = piVar24;
            puVar27[9] = piVar24;
            puVar27[10] = 0;
          }
          else {
            piVar22 = (int *)puVar27[8];
            if (local_344 == 1) {
              memcpy(auStack_1d8,piVar22 + 2,0x178);
              fVar43 = 1.0;
              goto LAB_000182ee;
            }
            local_2f4 = (void *)0x0;
            local_2f0 = (int *)0x0;
            local_2ec = (int *)0x0;
            local_2e8 = (int *)0x0;
            local_2e4 = (float *)0x0;
            local_2e0 = (float *)0x0;
            if (piVar24 == piVar22) {
              if (1 < (int)local_344) {
                local_350 = 0;
                uVar45 = 1;
LAB_00019286:
                    /* WARNING: Subroutine does not return */
                std::__throw_out_of_range_fmt
                          ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)"
                           ,uVar45,local_350);
              }
LAB_0001958e:
              uVar28 = 0;
              local_350 = (int)local_2f0 - (int)local_2f4 >> 2;
            }
            else {
              piVar36 = piVar22;
              while( true ) {
                local_2fc = 0;
                local_2f8 = 0.0;
                if (piVar24 != piVar22) {
                  do {
                    if ((piVar22 != piVar36) &&
                       (dVar41 = (double)face_feature_dist((nn_campan_face_feature_t *)
                                                           (piVar36 + 0x1a),
                                                           (nn_campan_face_feature_t *)
                                                           (piVar22 + 0x1a)),
                       dVar41 != 0.5 && dVar41 < 0.5 == NAN(dVar41))) {
                      local_2fc = local_2fc + 1;
                      local_2f8 = (float)((double)local_2f8 + dVar41);
                    }
                    piVar22 = (int *)*piVar22;
                  } while (piVar24 != piVar22);
                  if (0 < local_2fc) {
                    local_2f8 = local_2f8 / (float)(longlong)local_2fc;
                  }
                }
                if (local_2f0 == local_2ec) {
                  std::vector<int,std::allocator<int>>::_M_realloc_insert<int_const&>
                            ((vector<int,std::allocator<int>> *)&local_2f4,local_2f0,&local_2fc);
                }
                else {
                  if (local_2f0 != (int *)0x0) {
                    *local_2f0 = local_2fc;
                  }
                  local_2f0 = local_2f0 + 1;
                }
                if (local_2e4 == local_2e0) {
                  std::vector<float,std::allocator<float>>::_M_realloc_insert<float_const&>
                            ((vector<float,std::allocator<float>> *)&local_2e8,local_2e4,&local_2f8)
                  ;
                  piVar36 = (int *)*piVar36;
                }
                else {
                  if (local_2e4 != (float *)0x0) {
                    *local_2e4 = local_2f8;
                  }
                  piVar36 = (int *)*piVar36;
                  local_2e4 = local_2e4 + 1;
                }
                if (piVar24 == piVar36) break;
                piVar22 = (int *)puVar27[8];
              }
              if ((int)local_344 < 2) {
                if (puVar27[10] == 0) {
LAB_00019544:
                    /* WARNING: Subroutine does not return */
                  __assert_fail("index < L->size()",
                                "/home/mayutao/envs/virgo_smartdevice-linux-v3.0-pre-rel/frameworks/axnn_plugins/src/campan/campan_attr.h"
                                ,0x1ed,
                                "typename ax_list<T1>::iterator index_list(ax_list<T1>*, int) [with T = nn_campan_face_t; typename ax_list<T1>::iterator = std::_List_iterator<nn_campan_face_t>; ax_list<T1> = std::__cxx11::list<nn_campan_face_t, std::allocator<nn_campan_face_t> >]"
                               );
                }
                piVar22 = (int *)puVar27[8];
                if (piVar24 == piVar22) goto LAB_0001958e;
                uVar28 = 0;
LAB_00019004:
                local_350 = (int)local_2f0 - (int)local_2f4 >> 2;
                local_304 = piVar22;
              }
              else {
                local_350 = (int)local_2f0 - (int)local_2f4 >> 2;
                if (local_350 < 2) {
                  uVar45 = 1;
                  goto LAB_00019286;
                }
                piVar22 = (int *)((int)local_2f4 + 4);
                iVar38 = *piVar22;
                uVar28 = 0;
                uVar45 = 1;
                uVar48 = (int)local_2e4 - (int)local_2e8 >> 2;
                while( true ) {
                  iVar14 = *(int *)((int)local_2f4 + uVar28 * 4);
                  uVar1 = uVar45;
                  if ((iVar38 <= iVar14) && (uVar1 = uVar28, iVar14 == iVar38)) {
                    if (uVar48 <= uVar45) {
                    /* WARNING: Subroutine does not return */
                      std::__throw_out_of_range_fmt
                                ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)"
                                 ,uVar45,uVar48);
                    }
                    fVar43 = (float)local_2e8[uVar45];
                    if (uVar48 <= uVar28) {
                    /* WARNING: Subroutine does not return */
                      std::__throw_out_of_range_fmt
                                ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)"
                                 ,uVar28,uVar48);
                    }
                    fVar49 = (float)local_2e8[uVar28];
                    if (fVar43 != fVar49 && fVar43 < fVar49 == (NAN(fVar43) || NAN(fVar49))) {
                      uVar1 = uVar45;
                    }
                  }
                  uVar28 = uVar1;
                  if ((int)local_344 <= (int)(uVar45 + 1)) break;
                  uVar45 = uVar45 + 1;
                  if (uVar45 == local_350) goto LAB_00019286;
                  piVar22 = piVar22 + 1;
                  iVar38 = *piVar22;
                  if (local_350 <= uVar28) {
                    /* WARNING: Subroutine does not return */
                    std::__throw_out_of_range_fmt
                              (
                              "vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)"
                              );
                  }
                }
                if ((uint)puVar27[10] <= uVar28) goto LAB_00019544;
                piVar22 = (int *)puVar27[8];
                if (piVar36 != piVar22) {
                  if (uVar28 != 0) {
                    uVar45 = 0;
                    do {
                      piVar22 = (int *)*piVar22;
                      uVar45 = uVar45 + 1;
                      if (piVar36 == piVar22) goto LAB_00018d14;
                    } while (uVar28 != uVar45);
                  }
                  goto LAB_00019004;
                }
              }
            }
LAB_00018d14:
            pvVar23 = local_2f4;
            memcpy(auStack_1d8,local_304 + 2,0x178);
            if (local_350 <= uVar28) {
                    /* WARNING: Subroutine does not return */
              std::__throw_out_of_range_fmt
                        ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)"
                         ,uVar28,local_350);
            }
            fVar43 = (float)(longlong)*(int *)((int)pvVar23 + uVar28 * 4);
            if (local_2e8 != (int *)0x0) {
              operator_delete(local_2e8);
              pvVar23 = local_2f4;
            }
            if (pvVar23 == (void *)0x0) goto LAB_000182ee;
            operator_delete(pvVar23);
            if (2 < (uint)puVar27[7]) goto LAB_00018d5c;
LAB_000182fa:
            fVar50 = local_188;
            fVar49 = local_18c;
            uVar48 = local_1c8;
            iVar33 = local_1cc;
            iVar14 = local_1d0;
            iVar38 = local_1d4;
            uVar45 = local_1c8;
            if (DAT_0003a678 != 0) {
              uVar45 = 0;
              __android_log_print(6,"CAMPAN","%d, %.2f, %.2f, eval %.2f, buffer size %d",puVar27[2],
                                  (double)local_18c,(double)local_188,(double)fVar43,puVar27[10]);
            }
            if ((fVar43 != 1.0 && fVar43 < 1.0 == NAN(fVar43)) &&
               ((int)((uint)(ABS(fVar49) < 30.0) << 0x1f) < 0)) {
              iVar35 = (uint)(ABS(fVar50) < 30.0) << 0x1f;
              if (iVar35 < 0) {
                uVar45 = 1;
              }
              if (-1 < iVar35) {
                uVar45 = 0;
              }
              if (iVar7 < (int)((uVar48 - iVar14) * (iVar33 - iVar38))) {
                uVar45 = uVar45 & 1;
              }
              else {
                uVar45 = 0;
              }
              if (uVar45 != 0) {
                puVar16 = (undefined4 *)puVar27[5];
                if (puVar27[7] == 0) {
LAB_000183c8:
                  p_Var4 = (_List_node_base *)operator_new(0x180);
                  memcpy(p_Var4 + 8,auStack_1d8,0x178);
                  std::__detail::_List_node_base::_M_hook(p_Var4);
                  puVar27[7] = puVar27[7] + 1;
                  piVar22 = (int *)puVar27[8];
                  while (piVar24 != piVar22) {
                    piVar36 = (int *)*piVar22;
                    operator_delete(piVar22);
                    piVar22 = piVar36;
                  }
                  goto LAB_00017e82;
                }
                if (puVar27 + 5 != puVar16) {
                  dVar41 = 0.0;
                  do {
                    dVar42 = (double)face_feature_dist((nn_campan_face_feature_t *)(puVar16 + 0x1a),
                                                       anStack_178);
                    puVar16 = (undefined4 *)*puVar16;
                    if (dVar42 != dVar41 && dVar42 < dVar41 == (NAN(dVar42) || NAN(dVar41))) {
                      dVar41 = dVar42;
                    }
                  } while (puVar27 + 5 != puVar16);
                  if ((dVar41 != 0.5 && dVar41 < 0.5 == NAN(dVar41)) &&
                     (((int)((uint)(dVar41 < 0.75) << 0x1f) < 0 ||
                      ((((int)((uint)(dVar41 < 0.699999988079071) << 0x1f) < 0 &&
                        ((int)((uint)(ABS(fVar49) < 10.0) << 0x1f) < 0)) &&
                       ((int)((uint)(ABS(fVar50) < 10.0) << 0x1f) < 0)))))) goto LAB_000183c8;
                }
              }
            }
          }
LAB_00017e8c:
          if (((puVar27[4] == 0) &&
              ((int)((uint)(ABS(*(float *)((int)local_348 + 0x4c)) < 60.0) << 0x1f) < 0)) &&
             (iVar38 = FUN_000160c8(*(undefined4 *)(iVar2 + 0x60),local_348,puVar27 + 2),
             iVar38 != 0)) {
            if (DAT_0003a678 != 0) {
              __android_log_print(6,"CAMPAN","%d verified short_term_id %d",puVar27[2],
                                  *(undefined4 *)(iVar12 + iVar8));
            }
            puVar27[4] = 1;
          }
        }
      }
      else {
        iVar31 = -1;
        fVar43 = -1.0;
        iVar20 = *(int *)(param_1 + 0x120);
        iVar30 = 0;
        iVar21 = iVar20;
        do {
          iVar13 = *(int *)(iVar21 + 4);
          iVar9 = *(int *)(iVar21 + 8);
          iVar3 = *(int *)(iVar21 + 0xc);
          iVar15 = *(int *)(iVar21 + 0x10);
          iVar21 = iVar21 + 0x178;
          iVar46 = iVar13;
          if (iVar13 <= iVar33) {
            iVar46 = iVar33;
          }
          iVar13 = iVar3 - iVar13;
          iVar47 = iVar9;
          if (iVar9 <= iVar39) {
            iVar47 = iVar39;
          }
          if (iVar35 <= iVar3) {
            iVar3 = iVar35;
          }
          iVar44 = iVar15;
          if (iVar14 <= iVar15) {
            iVar44 = iVar14;
          }
          uVar45 = (uint)(((float)(longlong)iVar3 - (float)(longlong)iVar46) + 1.0);
          uVar48 = (uint)(((float)(longlong)iVar44 - (float)(longlong)iVar47) + 1.0);
          if ((int)(uVar45 | uVar48) < 0) {
            fVar49 = 0.0;
          }
          else {
            fVar49 = (float)(longlong)(int)uVar48 * (float)(longlong)(int)uVar45;
          }
          fVar49 = fVar49 / (((float)(longlong)(((iVar15 - iVar9) + 1) * (iVar13 + 1)) +
                             (float)(longlong)(((iVar14 - iVar39) + 1) * ((iVar35 - iVar33) + 1))) -
                            fVar49);
          if ((int)((uint)(fVar43 < fVar49) << 0x1f) < 0) {
            iVar31 = iVar30;
            fVar43 = fVar49;
          }
          iVar30 = iVar30 + 1;
        } while (iVar30 != *(int *)(param_1 + 0x124));
        if ((int)((uint)(fVar43 < 0.35) << 0x1f) < 0) goto LAB_00018124;
        if (iVar31 == -1) {
          *(undefined4 *)(iVar38 + 0x34) = 0xffffffff;
          local_348 = (void *)0x0;
        }
        else {
          *(undefined4 *)(iVar38 + 0x34) = 0xffffffff;
          local_348 = (void *)(iVar20 + iVar31 * 0x178);
          if (local_348 != (void *)0x0) {
            iVar20 = *(int *)(iVar20 + iVar31 * 0x178);
          }
          if (local_348 != (void *)0x0) {
            *(int *)(iVar38 + 0x34) = iVar20;
          }
        }
        if (puVar27 != puVar10) goto LAB_00017c6a;
LAB_00018138:
        ppiVar37 = &local_2e8;
        local_2d4 = 0;
        local_2c8 = 0;
        puVar16 = &local_2a0;
        puVar27 = local_2c4;
        do {
          puVar27[2] = 0;
          *puVar27 = puVar27;
          puVar27[1] = puVar27;
          puVar27 = puVar27 + 3;
        } while (puVar16 != puVar27);
        local_290 = 0;
        local_284 = 0;
        piVar24 = local_280;
        do {
          piVar24[2] = 0;
          *piVar24 = (int)piVar24;
          piVar24[1] = (int)piVar24;
          piVar24 = piVar24 + 3;
        } while (local_250 + 3 != piVar24);
        local_1f0 = 0;
        uStack_1ec = 0;
        local_250[3] = 0;
        local_228 = 0;
        local_21c = 0;
        local_2e0 = (float *)0x0;
        local_22c = 0xffffffff;
        local_2a0 = 0xffffffff;
        local_29c = 0xffffffff;
        local_220 = 0xffffffff;
        local_1e4 = 0xffffffff;
        local_1e0 = 0xffffffff;
        local_224 = 1;
        local_2e8 = *(int **)(iVar12 + iVar8);
        local_2e4 = *(float **)(iVar12 + iVar8);
        local_230 = 1;
        local_2dc = &local_2dc;
        pppppppuStack_2d8 = &local_2dc;
        local_2d0 = &local_2d0;
        pppppppuStack_2cc = &local_2d0;
        local_298 = &local_298;
        pppppppuStack_294 = &local_298;
        local_28c = &local_28c;
        pppppppuStack_288 = &local_28c;
        local_240 = dVar51;
        local_238 = dVar51;
        p_Var4 = (_List_node_base *)operator_new(0x118);
        *(int **)(p_Var4 + 8) = local_2e8;
        *(float **)(p_Var4 + 0xc) = local_2e4;
        *(float **)(p_Var4 + 0x10) = local_2e0;
        *(_List_node_base **)(p_Var4 + 0x14) = p_Var4 + 0x14;
        *(undefined4 *)(p_Var4 + 0x1c) = 0;
        *(_List_node_base **)(p_Var4 + 0x18) = p_Var4 + 0x14;
        pppppppuVar25 = local_2dc;
        while ((undefined4 ********)pppppppuVar25 != &local_2dc) {
          p_Var5 = (_List_node_base *)operator_new(0x180);
          memcpy(p_Var5 + 8,pppppppuVar25 + 2,0x178);
          std::__detail::_List_node_base::_M_hook(p_Var5);
          pppppppuVar25 = (undefined4 *******)*pppppppuVar25;
          *(int *)(p_Var4 + 0x1c) = *(int *)(p_Var4 + 0x1c) + 1;
        }
        *(_List_node_base **)(p_Var4 + 0x24) = p_Var4 + 0x20;
        *(undefined4 *)(p_Var4 + 0x28) = 0;
        *(_List_node_base **)(p_Var4 + 0x20) = p_Var4 + 0x20;
        pppppppuVar25 = local_2d0;
        while ((undefined4 ********)pppppppuVar25 != &local_2d0) {
          p_Var5 = (_List_node_base *)operator_new(0x180);
          memcpy(p_Var5 + 8,pppppppuVar25 + 2,0x178);
          std::__detail::_List_node_base::_M_hook(p_Var5);
          pppppppuVar25 = (undefined4 *******)*pppppppuVar25;
          *(int *)(p_Var4 + 0x28) = *(int *)(p_Var4 + 0x28) + 1;
        }
        p_Var5 = p_Var4 + 0x2c;
        iVar8 = 2;
        while( true ) {
          *(_List_node_base **)p_Var5 = p_Var5;
          *(_List_node_base **)(p_Var5 + 4) = p_Var5;
          ppiVar26 = (int **)ppiVar37[9];
          *(undefined4 *)(p_Var5 + 8) = 0;
          while (ppiVar26 != ppiVar37 + 9) {
            p_Var6 = (_List_node_base *)operator_new(0x180);
            memcpy(p_Var6 + 8,ppiVar26 + 2,0x178);
            std::__detail::_List_node_base::_M_hook(p_Var6);
            ppiVar26 = (int **)*ppiVar26;
            *(int *)(p_Var5 + 8) = *(int *)(p_Var5 + 8) + 1;
          }
          p_Var5 = p_Var5 + 0xc;
          ppiVar37 = ppiVar37 + 3;
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
        }
        *(undefined4 *)(p_Var4 + 0x60) = 0;
        *(undefined4 *)(p_Var4 + 0x54) = local_29c;
        *(_List_node_base **)(p_Var4 + 0x58) = p_Var4 + 0x58;
        *(undefined4 *)(p_Var4 + 0x50) = local_2a0;
        *(_List_node_base **)(p_Var4 + 0x5c) = p_Var4 + 0x58;
        pppppppuVar25 = local_298;
        while ((undefined4 ********)pppppppuVar25 != &local_298) {
          p_Var5 = (_List_node_base *)operator_new(0x2b0);
          memcpy(p_Var5 + 8,pppppppuVar25 + 2,0x2a8);
          std::__detail::_List_node_base::_M_hook(p_Var5);
          pppppppuVar25 = (undefined4 *******)*pppppppuVar25;
          *(int *)(p_Var4 + 0x60) = *(int *)(p_Var4 + 0x60) + 1;
        }
        *(_List_node_base **)(p_Var4 + 0x68) = p_Var4 + 100;
        *(undefined4 *)(p_Var4 + 0x6c) = 0;
        *(_List_node_base **)(p_Var4 + 100) = p_Var4 + 100;
        pppppppuVar25 = local_28c;
        while ((undefined4 ********)pppppppuVar25 != &local_28c) {
          p_Var5 = (_List_node_base *)operator_new(0x2b0);
          memcpy(p_Var5 + 8,pppppppuVar25 + 2,0x2a8);
          std::__detail::_List_node_base::_M_hook(p_Var5);
          pppppppuVar25 = (undefined4 *******)*pppppppuVar25;
          *(int *)(p_Var4 + 0x6c) = *(int *)(p_Var4 + 0x6c) + 1;
        }
        p_Var5 = p_Var4 + 0x70;
        iVar8 = 4;
        do {
          piVar24 = (int *)local_250[iVar8 * -3];
          *(_List_node_base **)p_Var5 = p_Var5;
          *(_List_node_base **)(p_Var5 + 4) = p_Var5;
          *(undefined4 *)(p_Var5 + 8) = 0;
          while (piVar24 != local_250 + iVar8 * -3) {
            p_Var6 = (_List_node_base *)operator_new(0x2b0);
            memcpy(p_Var6 + 8,piVar24 + 2,0x2a8);
            std::__detail::_List_node_base::_M_hook(p_Var6);
            piVar24 = (int *)*piVar24;
            *(int *)(p_Var5 + 8) = *(int *)(p_Var5 + 8) + 1;
          }
          iVar8 = iVar8 + -1;
          p_Var5 = p_Var5 + 0xc;
        } while (iVar8 != -1);
        *(int *)(p_Var4 + 0xac) = local_250[3];
        *(undefined4 *)(p_Var4 + 0xc0) = local_230;
        *(undefined4 *)(p_Var4 + 0xc4) = local_22c;
        *(undefined4 *)(p_Var4 + 200) = local_228;
        *(undefined4 *)(p_Var4 + 0xcc) = local_224;
        local_238._4_4_ = (undefined4)((ulonglong)local_238 >> 0x20);
        *(double *)(p_Var4 + 0xb0) = local_240;
        *(undefined4 *)(p_Var4 + 0xd0) = local_220;
        *(undefined4 *)(p_Var4 + 0xd4) = local_21c;
        *(undefined4 *)(p_Var4 + 0xb8) = (undefined4)local_238;
        *(undefined4 *)(p_Var4 + 0xbc) = local_238._4_4_;
        *(undefined4 *)(p_Var4 + 0xd8) = local_218;
        *(undefined4 *)(p_Var4 + 0xdc) = uStack_214;
        *(undefined4 *)(p_Var4 + 0xe0) = uStack_210;
        *(undefined4 *)(p_Var4 + 0xe4) = uStack_20c;
        piVar24 = local_250 + 3;
        *(undefined4 *)(p_Var4 + 0xe8) = local_208;
        *(undefined4 *)(p_Var4 + 0xec) = uStack_204;
        *(undefined4 *)(p_Var4 + 0xf0) = local_200;
        *(undefined4 *)(p_Var4 + 0xf4) = uStack_1fc;
        *(undefined4 *)(p_Var4 + 0x108) = local_1e8;
        *(undefined4 *)(p_Var4 + 0x10c) = local_1e4;
        *(undefined4 *)(p_Var4 + 0x110) = local_1e0;
        *(undefined8 *)(p_Var4 + 0xf8) = local_1f8;
        *(undefined4 *)(p_Var4 + 0x100) = local_1f0;
        *(undefined4 *)(p_Var4 + 0x104) = uStack_1ec;
        std::__detail::_List_node_base::_M_hook(p_Var4);
        puVar10[2] = puVar10[2] + 1;
        do {
          piVar24 = piVar24 + -3;
          piVar22 = (int *)*piVar24;
          while (piVar24 != piVar22) {
            piVar36 = (int *)*piVar22;
            operator_delete(piVar22);
            piVar22 = piVar36;
          }
          pppppppuVar25 = local_28c;
        } while (piVar24 != local_280);
        while (pppppppuVar17 = local_298, (undefined4 ********)pppppppuVar25 != &local_28c) {
          pppppppuVar17 = (undefined4 *******)*pppppppuVar25;
          operator_delete(pppppppuVar25);
          pppppppuVar25 = pppppppuVar17;
        }
        while ((undefined4 ********)pppppppuVar17 != &local_298) {
          pppppppuVar25 = (undefined4 *******)*pppppppuVar17;
          operator_delete(pppppppuVar17);
          pppppppuVar17 = pppppppuVar25;
        }
        do {
          puVar16 = puVar16 + -3;
          puVar27 = (undefined4 *)*puVar16;
          while (puVar16 != puVar27) {
            puVar29 = (undefined4 *)*puVar27;
            operator_delete(puVar27);
            puVar27 = puVar29;
          }
          pppppppuVar25 = local_2d0;
        } while (puVar16 != local_2c4);
        while (pppppppuVar17 = local_2dc, (undefined4 ********)pppppppuVar25 != &local_2d0) {
          pppppppuVar17 = (undefined4 *******)*pppppppuVar25;
          operator_delete(pppppppuVar25);
          pppppppuVar25 = pppppppuVar17;
        }
        while ((undefined4 ********)pppppppuVar17 != &local_2dc) {
          pppppppuVar25 = (undefined4 *******)*pppppppuVar17;
          operator_delete(pppppppuVar17);
          pppppppuVar17 = pppppppuVar25;
        }
      }
      local_34c = (int *)((int)local_34c + 1);
    } while ((int)local_34c < *(int *)(param_1 + 300));
  }
  puVar16 = (undefined4 *)*puVar10;
  if (DAT_0003a678 != 0) {
    if (puVar16 == puVar10) {
      iVar7 = 0;
      iVar8 = 0;
    }
    else {
      iVar7 = 0;
      iVar8 = 0;
      do {
        __android_log_print(6,"CAMPAN",
                            "tracking id %d, tracking %d, short term %d, exist %d, register %d, process %d, %d, %d, person id %d verified %d"
                            ,puVar16[2],puVar16[0x2b],puVar16[3],puVar16[0x33],puVar16[7],
                            puVar16[0xd],puVar16[0x10],puVar16[0x13],puVar16[0x15],puVar16[4]);
        if (puVar16[0x2b] != 0) {
          iVar8 = iVar8 + 1;
        }
        puVar16 = (undefined4 *)*puVar16;
        iVar7 = iVar7 + 1;
      } while (puVar16 != puVar10);
    }
    __android_log_print(6,"CAMPAN","count %d/%d",iVar8,iVar7);
    puVar16 = (undefined4 *)*puVar10;
  }
  for (; puVar10 != puVar16; puVar16 = (undefined4 *)*puVar16) {
    while( true ) {
      if (*(int *)(param_1 + 300) < 1) break;
      iVar7 = puVar16[2];
      piVar24 = *(int **)(param_1 + 0x128);
      if (iVar7 == puVar16[3]) break;
      if (iVar7 != *piVar24) {
        iVar8 = 0;
        do {
          iVar8 = iVar8 + 1;
          if (iVar8 == *(int *)(param_1 + 300)) goto LAB_00017fb0;
          piVar22 = piVar24 + 0xf;
          piVar24 = piVar24 + 0xf;
        } while (iVar7 != *piVar22);
      }
      __android_log_print(6,"CAMPAN","short_term_id != origin id but  origin id exist %d");
      dtbased_tk_change_id(uVar11,*piVar24 + -10000000,0xffffffff);
      iVar7 = piVar24[10];
      *piVar24 = 0x7fffffff;
      if ((iVar7 < 0) || (*(int *)(param_1 + 0x114) < 1)) break;
      piVar24 = *(int **)(param_1 + 0x110);
      if (iVar7 != *piVar24) {
        iVar8 = 0;
        do {
          iVar8 = iVar8 + 1;
          if (iVar8 == *(int *)(param_1 + 0x114)) {
            puVar16 = (undefined4 *)*puVar16;
            goto joined_r0x00018848;
          }
          piVar22 = piVar24 + 0xaa;
          piVar24 = piVar24 + 0xaa;
        } while (iVar7 != *piVar22);
      }
      piVar24[0x52] = 0x7fffffff;
      puVar16 = (undefined4 *)*puVar16;
joined_r0x00018848:
      if (puVar16 == puVar10) goto LAB_00017fb6;
    }
LAB_00017fb0:
  }
LAB_00017fb6:
  local_2f4 = (void *)0x0;
  local_2f0 = (int *)0x0;
  local_2ec = (int *)0x0;
  puVar16 = (undefined4 *)*puVar10;
  if (puVar16 != puVar10) {
LAB_00017fda:
    iVar7 = *(int *)(param_1 + 300);
    if (0 < iVar7) {
      piVar24 = *(int **)(param_1 + 0x128);
      local_34c = piVar24;
      if (puVar16[3] != *piVar24) {
        iVar8 = 0;
        do {
          iVar8 = iVar8 + 1;
          if (iVar8 == iVar7) {
            if (puVar16[0x2b] == 0) goto LAB_000184f0;
            local_34c = (int *)0x0;
            piVar22 = *(int **)(*(int *)(param_1 + 0x1c8) + 0xabc);
            fVar43 = *(float *)(*(int *)(param_1 + 0x108) + 0x60);
            goto LAB_0001802a;
          }
          piVar22 = local_34c + 0xf;
          local_34c = local_34c + 0xf;
        } while (puVar16[3] != *piVar22);
      }
      if (puVar16[0x2b] != 0) {
        if (puVar16[4] == 0) {
          piVar22 = *(int **)(*(int *)(param_1 + 0x1c8) + 0xabc);
          fVar43 = *(float *)(*(int *)(param_1 + 0x108) + 0x60);
LAB_0001802a:
          iVar8 = 0;
          do {
            piVar34 = piVar24 + iVar8 * 0xf;
            for (piVar36 = (int *)*piVar22;
                (piVar36 != piVar22 && (piVar24[iVar8 * 0xf] != piVar36[3]));
                piVar36 = (int *)*piVar36) {
            }
            if (*(int *)(param_1 + 0x124) < 1) {
LAB_00018088:
              if (iVar7 <= iVar8 + 1) goto LAB_000184f0;
            }
            else {
              piVar24 = *(int **)(param_1 + 0x120);
              if (piVar34[0xd] != *piVar24) {
                iVar12 = 0;
                do {
                  iVar12 = iVar12 + 1;
                  if (iVar12 == *(int *)(param_1 + 0x124)) goto LAB_00018088;
                  piVar36 = piVar24 + 0x5e;
                  piVar24 = piVar24 + 0x5e;
                } while (piVar34[0xd] != *piVar36);
              }
              if (((piVar24[0x5c] == 0) ||
                  (-1 < (int)((uint)(ABS((float)piVar24[0x13]) < 50.0) << 0x1f))) ||
                 (-1 < (int)((uint)(ABS((float)piVar24[0x14]) < 40.0) << 0x1f))) goto LAB_00018088;
              puVar27 = puVar16 + 5;
              puVar29 = (undefined4 *)*puVar27;
              if (puVar29 != puVar27) {
                fVar49 = 0.0;
                do {
                  dVar41 = (double)face_feature_dist((nn_campan_face_feature_t *)(puVar29 + 0x1a),
                                                     (nn_campan_face_feature_t *)(piVar24 + 0x18));
                  dVar42 = (double)fVar49;
                  puVar29 = (undefined4 *)*puVar29;
                  if (dVar41 != dVar42 && dVar41 < dVar42 == (NAN(dVar41) || NAN(dVar42))) {
                    fVar49 = (float)dVar41;
                  }
                } while (puVar29 != puVar27);
                if (-1 < (int)((uint)(fVar43 < 0.45) << 0x1f)) goto LAB_000186ec;
                fVar50 = 0.48;
                if (fVar49 == 0.45 || fVar49 < 0.45 != NAN(fVar49)) goto LAB_00018494;
LAB_00018708:
                iVar7 = *piVar34;
                if (DAT_0003a678 != 0) {
                  __android_log_print(6,"CAMPAN",
                                      "track %d, current %d, register_best_dist %.2f process_best_dist %.2f"
                                      ,puVar16[2],iVar7);
                  iVar7 = *piVar34;
                }
                iVar8 = puVar16[0x31];
                bVar40 = iVar8 != iVar7;
                if (bVar40) {
                  puVar16[0x31] = iVar7;
                  iVar8 = 1;
                }
                if (bVar40) {
                  puVar16[0x32] = iVar8;
                }
                else {
                  iVar7 = puVar16[0x32];
                  puVar16[0x32] = iVar7 + 1;
                  if ((1 < iVar7 + 1) && (local_34c != piVar34)) {
                    iVar7 = *piVar34;
                    puVar27 = (undefined4 *)*puVar10;
                    if (puVar27 != puVar10) {
                      iVar8 = puVar27[3];
                      goto joined_r0x0001875a;
                    }
                  }
                }
                goto LAB_000184f0;
              }
              if ((int)((uint)(fVar43 < 0.45) << 0x1f) < 0) {
                fVar50 = 0.48;
              }
              else {
                fVar49 = 0.0;
LAB_000186ec:
                fVar50 = fVar43 + 0.03;
                if (fVar49 != fVar43 && fVar49 < fVar43 == (NAN(fVar49) || NAN(fVar43)))
                goto LAB_00018708;
              }
LAB_00018494:
              fVar49 = 0.0;
              piVar36 = puVar16 + 0xb;
              do {
                piVar32 = (int *)*piVar36;
                while (piVar36 != piVar32) {
                  dVar41 = (double)face_feature_dist((nn_campan_face_feature_t *)(piVar32 + 0x1a),
                                                     (nn_campan_face_feature_t *)(piVar24 + 0x18));
                  dVar42 = (double)fVar49;
                  piVar32 = (int *)*piVar32;
                  if (dVar41 != dVar42 && dVar41 < dVar42 == (NAN(dVar41) || NAN(dVar42))) {
                    fVar49 = (float)dVar41;
                  }
                }
                piVar36 = piVar36 + 3;
              } while (puVar16 + 0x14 != piVar36);
              if (fVar49 != fVar50 && fVar49 < fVar50 == (NAN(fVar49) || NAN(fVar50)))
              goto LAB_00018708;
              iVar7 = *(int *)(param_1 + 300);
              if (iVar7 <= iVar8 + 1) goto LAB_000184f0;
            }
            iVar8 = iVar8 + 1;
            piVar24 = *(int **)(param_1 + 0x128);
          } while( true );
        }
        iVar7 = *(int *)(param_1 + 0x124);
        if (iVar7 < 1) {
          if (DAT_0003a678 != 0) {
            iVar8 = puVar16[0x44];
            goto LAB_000187bc;
          }
        }
        else {
          piVar22 = *(int **)(param_1 + 0x120);
          iVar12 = *piVar22;
          piVar24 = piVar22;
          if (local_34c[0xd] != iVar12) {
            iVar8 = 0;
            do {
              iVar8 = iVar8 + 1;
              if (iVar8 == iVar7) goto LAB_00018670;
              piVar36 = piVar24 + 0x5e;
              piVar24 = piVar24 + 0x5e;
            } while (local_34c[0xd] != *piVar36);
          }
          if ((piVar24[0x5c] == 0) || (-1 < (int)((uint)(ABS((float)piVar24[0x13]) < 60.0) << 0x1f))
             ) {
LAB_00018670:
            iVar8 = puVar16[0x44];
            if (DAT_0003a678 == 0) goto LAB_00018680;
LAB_000187bc:
            __android_log_print(6,"CAMPAN",
                                "heads_hist_iter->not_match_faceid:%d, tracking head id:%d",iVar8,
                                puVar16[2]);
          }
          else {
            iVar7 = FUN_000160c8(*(undefined4 *)(iVar2 + 0x60),piVar24,puVar16 + 2);
            if (iVar7 == 0) {
              iVar8 = *piVar24;
              puVar16[0x44] = iVar8;
            }
            else {
              iVar8 = -1;
              puVar16[0x44] = 0xffffffff;
            }
            if (DAT_0003a678 != 0) goto LAB_000187bc;
          }
          iVar7 = *(int *)(param_1 + 0x124);
          if (0 < iVar7) {
            piVar22 = *(int **)(param_1 + 0x120);
            iVar8 = puVar16[0x44];
            iVar12 = *piVar22;
LAB_00018680:
            piVar24 = piVar22;
            if (iVar8 != iVar12) {
              iVar12 = 0;
              do {
                iVar12 = iVar12 + 1;
                if (iVar7 <= iVar12) goto LAB_000184f0;
                piVar36 = piVar24 + 0x5e;
                piVar24 = piVar24 + 0x5e;
              } while (*piVar36 != iVar8);
            }
            local_2e8 = (int *)0x0;
            local_2e4 = (float *)0x0;
            local_2e0 = (float *)0x0;
            local_2f8 = 0.0;
            do {
              piVar36 = piVar22 + (int)local_2f8 * 0x5e;
              if (((piVar22[(int)local_2f8 * 0x5e] != *piVar24) && (piVar36[0x5c] != 0)) &&
                 ((int)((uint)(ABS((float)piVar36[0x13]) < 60.0) << 0x1f) < 0)) {
                iVar7 = FUN_000160c8(*(undefined4 *)(iVar2 + 0x60),piVar36,puVar16 + 2);
                if (iVar7 != 0) {
                  if (local_2e4 != local_2e0) {
                    if (local_2e4 != (float *)0x0) {
                      *local_2e4 = local_2f8;
                    }
                    iVar7 = *(int *)(param_1 + 0x124);
                    local_2e4 = local_2e4 + 1;
                    goto LAB_000188a0;
                  }
                  std::vector<int,std::allocator<int>>::_M_realloc_insert<int_const&>
                            ((vector<int,std::allocator<int>> *)&local_2e8,local_2e4,&local_2f8);
                }
                iVar7 = *(int *)(param_1 + 0x124);
              }
LAB_000188a0:
              local_2f8 = (float)((int)local_2f8 + 1);
              if (iVar7 <= (int)local_2f8) goto code_r0x000188a8;
              piVar22 = *(int **)(param_1 + 0x120);
            } while( true );
          }
        }
      }
    }
    goto LAB_000184f0;
  }
  goto LAB_00018948;
joined_r0x0001875a:
  if (iVar7 == iVar8) goto LAB_0001912c;
  puVar27 = (undefined4 *)*puVar27;
  if (puVar27 == puVar10) goto LAB_000184f0;
  iVar8 = puVar27[3];
  goto joined_r0x0001875a;
LAB_0001912c:
  if (puVar27[0x2b] == 0) {
    if (local_2f0 == local_2ec) {
      std::vector<int,std::allocator<int>>::_M_realloc_insert<int_const&>
                ((vector<int,std::allocator<int>> *)&local_2f4,local_2f0,piVar34);
    }
    else {
      if (local_2f0 != (int *)0x0) {
        *local_2f0 = iVar7;
      }
      local_2f0 = local_2f0 + 1;
    }
  }
  else {
    if (puVar27[4] != 0) {
      if (DAT_0003a678 != 0) {
        __android_log_print(6,"CAMPAN","match verified head %d, %d",puVar27[2],puVar27[3]);
      }
      goto LAB_000184f0;
    }
    if (local_34c == (int *)0x0) {
LAB_000192f4:
      uVar11 = puVar27[2];
      if (DAT_0003a678 != 0) {
        __android_log_print(6,"CAMPAN","match tracking head %d, short term %d, reset to origin id",
                            uVar11,puVar27[3]);
        goto LAB_0001914e;
      }
    }
    else {
      if (DAT_0003a678 != 0) {
        __android_log_print(6,"CAMPAN","verified change head, %d, current %d(error %d)",puVar16[2],
                            iVar7);
        goto LAB_000192f4;
      }
LAB_0001914e:
      uVar11 = puVar27[2];
    }
    puVar27[3] = uVar11;
    puVar27[4] = 0;
  }
  if (local_34c == (int *)0x0) {
    iVar7 = *piVar34;
    if (DAT_0003a678 != 0) {
      __android_log_print(6,"CAMPAN","refind head, %d, current %d",puVar16[2],iVar7);
      iVar7 = *piVar34;
    }
  }
  else {
    local_34c[0xc] = 0;
    iVar7 = *piVar34;
  }
  puVar16[3] = iVar7;
  puVar16[0x44] = 0xffffffff;
  puVar16[4] = 1;
  puVar16[0x33] = 1;
  puVar16 = (undefined4 *)*puVar16;
joined_r0x000188d2:
  if (puVar16 == puVar10) goto LAB_000184fc;
  goto LAB_00017fda;
code_r0x000188a8:
  iVar7 = (int)local_2e4 - (int)local_2e8;
  if (DAT_0003a678 != 0) {
    __android_log_print(6,"CAMPAN","match_face_idx size:%d",iVar7 >> 2);
    iVar7 = (int)local_2e4 - (int)local_2e8;
  }
  if (iVar7 == 4) {
    iVar7 = *(int *)(*(int *)(param_1 + 0x120) + *local_2e8 * 0x178);
    if (0 < *(int *)(param_1 + 300)) {
      piVar24 = *(int **)(param_1 + 0x128);
      if (iVar7 != piVar24[0xd]) {
        iVar8 = 0;
        piVar22 = piVar24;
        do {
          piVar24 = piVar22 + 0xf;
          iVar8 = iVar8 + 1;
          if (iVar8 == *(int *)(param_1 + 300)) goto LAB_000188c0;
          piVar36 = piVar22 + 0x1c;
          piVar22 = piVar24;
        } while (iVar7 != *piVar36);
      }
      if (piVar24 != (int *)0x0 && local_34c != piVar24) {
        iVar7 = *piVar24;
        if (DAT_0003a678 != 0) {
          __android_log_print(6,"CAMPAN","re refind head id:%d, current head id:%d",iVar7,puVar16[2]
                             );
          iVar7 = *piVar24;
        }
        puVar27 = (undefined4 *)*puVar10;
        if (puVar27 != puVar10) {
          iVar8 = puVar27[3];
          while (iVar7 != iVar8) {
            puVar27 = (undefined4 *)*puVar27;
            if (puVar27 == puVar10) goto LAB_000188c0;
            iVar8 = puVar27[3];
          }
          if ((puVar27[0x2b] == 0) && (puVar27[4] == 1)) {
            if (local_2f0 == local_2ec) {
              std::vector<int,std::allocator<int>>::_M_realloc_insert<int_const&>
                        ((vector<int,std::allocator<int>> *)&local_2f4,local_2f0,piVar24);
            }
            else {
              if (local_2f0 != (int *)0x0) {
                *local_2f0 = iVar7;
              }
              local_2f0 = local_2f0 + 1;
            }
            local_34c[0xc] = 0;
            iVar7 = *piVar24;
            puVar16[0x33] = 1;
            puVar16[3] = iVar7;
            puVar16[4] = 1;
            puVar16[0x44] = 0xffffffff;
          }
        }
      }
    }
  }
LAB_000188c0:
  if (local_2e8 != (int *)0x0) {
    operator_delete(local_2e8);
    puVar16 = (undefined4 *)*puVar16;
    goto joined_r0x000188d2;
  }
LAB_000184f0:
  puVar16 = (undefined4 *)*puVar16;
  goto joined_r0x000188d2;
LAB_0001852c:
  puVar27 = (undefined4 *)*puVar27;
  if (puVar16 == puVar27) goto LAB_0001860e;
  goto LAB_00018532;
LAB_000184fc:
  if (0 < (int)local_2f0 - (int)local_2f4) {
    uVar45 = 0;
    do {
      puVar27 = (undefined4 *)*puVar10;
      if (puVar16 != puVar27) {
LAB_00018532:
        if (*(int *)((int)local_2f4 + uVar45 * 4) != puVar27[2]) goto LAB_0001852c;
        if (DAT_0003a678 != 0) {
          __android_log_print(6,"CAMPAN","erase heads_hist(head) %d");
        }
        puVar29 = puVar27 + 0x2b;
        puVar10[2] = puVar10[2] + -1;
        std::__detail::_List_node_base::_M_unhook();
        do {
          puVar29 = puVar29 + -3;
          puVar19 = (undefined4 *)*puVar29;
          while (puVar29 != puVar19) {
            puVar18 = (undefined4 *)*puVar19;
            operator_delete(puVar19);
            puVar19 = puVar18;
          }
        } while (puVar27 + 0x1c != puVar29);
        puVar29 = (undefined4 *)puVar27[0x19];
        while (puVar27 + 0x19 != puVar29) {
          puVar19 = (undefined4 *)*puVar29;
          operator_delete(puVar29);
          puVar29 = puVar19;
        }
        puVar29 = (undefined4 *)puVar27[0x16];
        while (puVar27 + 0x16 != puVar29) {
          puVar19 = (undefined4 *)*puVar29;
          operator_delete(puVar29);
          puVar29 = puVar19;
        }
        puVar29 = puVar27 + 0x14;
        do {
          puVar29 = puVar29 + -3;
          puVar19 = (undefined4 *)*puVar29;
          while (puVar29 != puVar19) {
            puVar18 = (undefined4 *)*puVar19;
            operator_delete(puVar19);
            puVar19 = puVar18;
          }
        } while (puVar27 + 0xb != puVar29);
        puVar29 = (undefined4 *)puVar27[8];
        while (puVar27 + 8 != puVar29) {
          puVar19 = (undefined4 *)*puVar29;
          operator_delete(puVar29);
          puVar29 = puVar19;
        }
        puVar29 = (undefined4 *)puVar27[5];
        while (puVar27 + 5 != puVar29) {
          puVar19 = (undefined4 *)*puVar29;
          operator_delete(puVar29);
          puVar29 = puVar19;
        }
        operator_delete(puVar27);
        goto LAB_000185f0;
      }
LAB_0001860e:
      if (DAT_0003a678 != 0) {
        __android_log_print(6,"CAMPAN","erase heads_hist not exist %d");
      }
LAB_000185f0:
      uVar45 = uVar45 + 1;
      uVar48 = (int)local_2f0 - (int)local_2f4 >> 2;
      if ((int)uVar48 <= (int)uVar45) break;
      if (uVar48 <= uVar45) {
                    /* WARNING: Subroutine does not return */
        std::__throw_out_of_range_fmt
                  ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                   uVar45);
      }
    } while( true );
  }
  puVar16 = (undefined4 *)*puVar10;
joined_r0x000188e0:
  puVar27 = puVar16;
  if (puVar27 != puVar10) {
    if (0 < *(int *)(param_1 + 300)) {
      piVar24 = *(int **)(param_1 + 0x128);
      if (puVar27[3] != *piVar24) {
        iVar2 = 0;
        do {
          iVar2 = iVar2 + 1;
          if (*(int *)(param_1 + 300) == iVar2) goto LAB_0001891e;
          piVar22 = piVar24 + 0xf;
          piVar24 = piVar24 + 0xf;
        } while (puVar27[3] != *piVar22);
      }
      iVar2 = puVar27[2];
      *(double *)(puVar27 + 0x2e) = dVar51;
      puVar27[0x33] = 0;
      if (*piVar24 != iVar2) {
        if (DAT_0003a678 != 0) {
          __android_log_print(6,"CAMPAN","re project head %d -> %d",*piVar24,iVar2);
          iVar2 = puVar27[2];
        }
        iVar7 = *(int *)(param_1 + 0x114);
        *piVar24 = iVar2;
        piVar24[0xc] = puVar27[0x2b];
        if (0 < iVar7) {
          piVar22 = *(int **)(param_1 + 0x110);
          if (*piVar22 != piVar24[10]) {
            iVar8 = 0;
            do {
              iVar8 = iVar8 + 1;
              if (iVar7 == iVar8) goto LAB_00018c0e;
              piVar36 = piVar22 + 0xaa;
              piVar22 = piVar22 + 0xaa;
            } while (piVar24[10] != *piVar36);
          }
          piVar22[0x52] = iVar2;
          puVar27[0x33] = 1;
          puVar16 = (undefined4 *)*puVar27;
          goto joined_r0x000188e0;
        }
      }
LAB_00018c0e:
      puVar27[0x33] = 1;
      puVar16 = (undefined4 *)*puVar27;
      goto joined_r0x000188e0;
    }
LAB_0001891e:
    puVar27[0x33] = 0;
    puVar16 = (undefined4 *)*puVar27;
    if ((puVar27[0x2b] == 0) &&
       (dVar41 = dVar51 - *(double *)(puVar27 + 0x2e), dVar41 != 5.0 && dVar41 < 5.0 == NAN(dVar41))
       ) {
      puVar29 = puVar27 + 0x2b;
      puVar10[2] = puVar10[2] + -1;
      std::__detail::_List_node_base::_M_unhook();
      do {
        puVar29 = puVar29 + -3;
        puVar19 = (undefined4 *)*puVar29;
        while (puVar29 != puVar19) {
          puVar18 = (undefined4 *)*puVar19;
          operator_delete(puVar19);
          puVar19 = puVar18;
        }
      } while (puVar27 + 0x1c != puVar29);
      puVar29 = (undefined4 *)puVar27[0x19];
      while (puVar27 + 0x19 != puVar29) {
        puVar19 = (undefined4 *)*puVar29;
        operator_delete(puVar29);
        puVar29 = puVar19;
      }
      puVar29 = (undefined4 *)puVar27[0x16];
      while (puVar27 + 0x16 != puVar29) {
        puVar19 = (undefined4 *)*puVar29;
        operator_delete(puVar29);
        puVar29 = puVar19;
      }
      puVar29 = puVar27 + 0x14;
      do {
        puVar29 = puVar29 + -3;
        puVar19 = (undefined4 *)*puVar29;
        while (puVar29 != puVar19) {
          puVar18 = (undefined4 *)*puVar19;
          operator_delete(puVar19);
          puVar19 = puVar18;
        }
      } while (puVar27 + 0xb != puVar29);
      puVar29 = (undefined4 *)puVar27[8];
      while (puVar27 + 8 != puVar29) {
        puVar19 = (undefined4 *)*puVar29;
        operator_delete(puVar29);
        puVar29 = puVar19;
      }
      puVar29 = (undefined4 *)puVar27[5];
      while (puVar27 + 5 != puVar29) {
        puVar19 = (undefined4 *)*puVar29;
        operator_delete(puVar29);
        puVar29 = puVar19;
      }
      operator_delete(puVar27);
    }
    goto joined_r0x000188e0;
  }
LAB_00018948:
  if (local_2f4 != (void *)0x0) {
    operator_delete(local_2f4);
  }
  if (local_5c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



void FUN_00019660(int *param_1,void *param_2,float *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  void *pvVar8;
  int *piVar9;
  int iVar10;
  double dVar11;
  uint local_60;
  int *local_58;
  int local_50;
  float local_4c;
  void *local_48;
  int *local_44;
  int *local_40;
  void *local_3c;
  float *local_38;
  float *pfStack_34;
  
  iVar10 = param_1[2];
  if (iVar10 == 0) {
    *param_3 = 0.0;
    return;
  }
  piVar5 = (int *)*param_1;
  if (iVar10 == 1) {
    memcpy(param_2,piVar5 + 2,0x2a8);
    *param_3 = 1.0;
    return;
  }
  local_48 = (void *)0x0;
  local_44 = (int *)0x0;
  local_40 = (int *)0x0;
  local_3c = (void *)0x0;
  local_38 = (float *)0x0;
  pfStack_34 = (float *)0x0;
  piVar9 = piVar5;
  if (piVar5 == param_1) {
    if (1 < iVar10) {
      local_60 = 0;
      uVar4 = 1;
LAB_000198ac:
                    /* WARNING: Subroutine does not return */
      std::__throw_out_of_range_fmt
                ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",uVar4,
                 local_60);
    }
LAB_000198ca:
    uVar6 = 0;
    local_60 = (int)local_44 - (int)local_48 >> 2;
  }
  else {
    while( true ) {
      local_4c = 0.0;
      local_50 = 0;
      if (piVar5 != param_1) {
        do {
          if ((piVar5 != piVar9) &&
             (dVar11 = (double)person_feature_dist((nn_campan_person_feature_t *)(piVar9 + 0xe),
                                                   (nn_campan_person_feature_t *)(piVar5 + 0xe)),
             (int)((uint)(dVar11 < 0.10000000149011612) << 0x1f) < 0)) {
            local_50 = local_50 + 1;
            local_4c = (float)((double)local_4c + dVar11);
          }
          piVar5 = (int *)*piVar5;
        } while (piVar5 != param_1);
        if (0 < local_50) {
          local_4c = local_4c / (float)(longlong)local_50;
        }
      }
      if (local_44 == local_40) {
        std::vector<int,std::allocator<int>>::_M_realloc_insert<int_const&>
                  ((vector<int,std::allocator<int>> *)&local_48,local_44,&local_50);
      }
      else {
        if (local_44 != (int *)0x0) {
          *local_44 = local_50;
        }
        local_44 = local_44 + 1;
      }
      if (local_38 == pfStack_34) {
        std::vector<float,std::allocator<float>>::_M_realloc_insert<float_const&>
                  ((vector<float,std::allocator<float>> *)&local_3c,local_38,&local_4c);
        piVar9 = (int *)*piVar9;
      }
      else {
        if (local_38 != (float *)0x0) {
          *local_38 = local_4c;
        }
        piVar9 = (int *)*piVar9;
        local_38 = local_38 + 1;
      }
      if (piVar9 == param_1) break;
      piVar5 = (int *)*param_1;
    }
    if (iVar10 < 2) {
      if (piVar9[2] == 0) {
LAB_00019908:
                    /* WARNING: Subroutine does not return */
        __assert_fail("index < L->size()",
                      "/home/mayutao/envs/virgo_smartdevice-linux-v3.0-pre-rel/frameworks/axnn_plugins/src/campan/campan_attr.h"
                      ,0x1ed,
                      "typename ax_list<T1>::iterator index_list(ax_list<T1>*, int) [with T = nn_campan_person_t; typename ax_list<T1>::iterator = std::_List_iterator<nn_campan_person_t>; ax_list<T1> = std::__cxx11::list<nn_campan_person_t, std::allocator<nn_campan_person_t> >]"
                     );
      }
      param_1 = (int *)*piVar9;
      if (param_1 == piVar9) goto LAB_000198ca;
      uVar6 = 0;
    }
    else {
      local_60 = (int)local_44 - (int)local_48 >> 2;
      if (local_60 < 2) {
        uVar4 = 1;
        goto LAB_000198ac;
      }
      piVar5 = (int *)((int)local_48 + 4);
      iVar3 = *piVar5;
      uVar6 = 0;
      uVar4 = 1;
      uVar1 = (int)local_38 - (int)local_3c >> 2;
      while( true ) {
        iVar7 = *(int *)((int)local_48 + uVar6 * 4);
        uVar2 = uVar4;
        if ((iVar3 <= iVar7) && (uVar2 = uVar6, iVar7 == iVar3)) {
          if (uVar1 <= uVar4) {
                    /* WARNING: Subroutine does not return */
            std::__throw_out_of_range_fmt
                      ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                       uVar4,uVar1);
          }
          if (uVar1 <= uVar6) {
                    /* WARNING: Subroutine does not return */
            std::__throw_out_of_range_fmt
                      ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                       uVar6,uVar1);
          }
          if ((int)((uint)(*(float *)((int)local_3c + uVar4 * 4) <
                          *(float *)(uVar6 * 4 + (int)local_3c)) << 0x1f) < 0) {
            uVar2 = uVar4;
          }
        }
        uVar6 = uVar2;
        if (iVar10 <= (int)(uVar4 + 1)) break;
        uVar4 = uVar4 + 1;
        if (uVar4 == local_60) goto LAB_000198ac;
        piVar5 = piVar5 + 1;
        iVar3 = *piVar5;
        if (local_60 <= uVar6) {
                    /* WARNING: Subroutine does not return */
          std::__throw_out_of_range_fmt
                    ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                     uVar6,local_60);
        }
      }
      if ((uint)param_1[2] <= uVar6) goto LAB_00019908;
      param_1 = (int *)*param_1;
      if (piVar9 == param_1) goto LAB_000197e8;
      if (uVar6 != 0) {
        uVar4 = 0;
        do {
          param_1 = (int *)*param_1;
          uVar4 = uVar4 + 1;
          if (piVar9 == param_1) goto LAB_000197e8;
        } while (uVar6 != uVar4);
      }
    }
    local_60 = (int)local_44 - (int)local_48 >> 2;
    local_58 = param_1;
  }
LAB_000197e8:
  pvVar8 = local_48;
  memcpy(param_2,local_58 + 2,0x2a8);
  if (local_60 <= uVar6) {
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",uVar6,
               local_60);
  }
  *param_3 = (float)(longlong)*(int *)((int)pvVar8 + uVar6 * 4);
  if (local_3c != (void *)0x0) {
    operator_delete(local_3c);
    pvVar8 = local_48;
  }
  if (pvVar8 == (void *)0x0) {
    return;
  }
  operator_delete(pvVar8);
  return;
}



void FUN_00019948(int param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  _List_node_base *p_Var4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  float *pfVar14;
  void *pvVar15;
  int iVar16;
  int *piVar17;
  int iVar18;
  int *piVar19;
  int *piVar20;
  int *piVar21;
  uint uVar22;
  int *piVar23;
  uint uVar24;
  int iVar25;
  uint uVar26;
  bool bVar27;
  double dVar28;
  double dVar29;
  int iVar30;
  int iVar31;
  float fVar32;
  float fVar33;
  int iVar34;
  float fVar35;
  undefined1 in_q8 [16];
  undefined8 uVar36;
  uint local_380;
  undefined1 *local_37c;
  int local_374;
  float local_33c;
  void *local_338;
  int *local_334;
  int *local_330;
  undefined8 local_32c;
  undefined8 local_324;
  undefined8 local_31c;
  undefined8 local_314;
  ulonglong local_30c;
  undefined8 local_304;
  undefined4 local_2fc;
  undefined4 uStack_2f8;
  undefined4 uStack_2f4;
  undefined1 auStack_2f0 [4];
  int local_2ec;
  int local_2e8;
  int local_2e4;
  int local_2e0;
  nn_campan_person_feature_t anStack_2c0 [636];
  int local_44;
  
  iVar16 = *(int *)(param_1 + 0x1c8);
  piVar23 = *(int **)(iVar16 + 0xabc);
  piVar19 = (int *)*piVar23;
  local_44 = __stack_chk_guard;
  local_338 = (void *)0x0;
  local_334 = (int *)0x0;
  local_330 = (int *)0x0;
  if (piVar19 != piVar23) {
    do {
      if (piVar19[0x2b] == 0) {
        if (0 < *(int *)(param_1 + 300)) {
          piVar17 = *(int **)(param_1 + 0x128);
          if (piVar19[3] != *piVar17) {
            iVar10 = 0;
            do {
              iVar10 = iVar10 + 1;
              if (iVar10 == *(int *)(param_1 + 300)) goto LAB_00019ad4;
              piVar21 = piVar17 + 0xf;
              piVar17 = piVar17 + 0xf;
            } while (piVar19[3] != *piVar21);
          }
          if (piVar17[10] != -1) {
            piVar19[0x14] = piVar17[10];
            piVar19[0x15] = piVar17[10];
            piVar19 = (int *)*piVar19;
            goto joined_r0x00019d00;
          }
        }
LAB_00019ad4:
        piVar19 = (int *)*piVar19;
      }
      else {
        piVar17 = piVar19 + 0x16;
        if (piVar19[0x33] == 0) {
          iVar10 = piVar19[0x15];
          if (iVar10 != -1) {
            iVar2 = *(int *)(param_1 + 0x114);
            iVar5 = DAT_0003a678;
            if (0 < iVar2) {
              piVar20 = *(int **)(param_1 + 0x110);
              piVar21 = piVar20;
              if (iVar10 != *piVar20) {
                iVar5 = 0;
                do {
                  iVar5 = iVar5 + 1;
                  if (iVar5 == iVar2) {
                    local_380 = 0;
                    goto LAB_00019a06;
                  }
                  piVar11 = piVar21 + 0xaa;
                  piVar21 = piVar21 + 0xaa;
                } while (iVar10 != *piVar11);
              }
LAB_00019d52:
              iVar10 = piVar21[0x52];
              if ((iVar10 != -1) && (0 < *(int *)(param_1 + 300))) {
                piVar17 = *(int **)(param_1 + 0x128);
                iVar5 = *piVar17;
                if (iVar5 != iVar10) {
                  iVar2 = 0;
                  do {
                    iVar2 = iVar2 + 1;
                    if (iVar2 == *(int *)(param_1 + 300)) goto LAB_00019d86;
                    iVar5 = piVar17[0xf];
                    piVar17 = piVar17 + 0xf;
                  } while (iVar10 != iVar5);
                }
                for (piVar20 = (int *)*piVar23; piVar20 != piVar23; piVar20 = (int *)*piVar20) {
                  if (piVar20[2] == iVar5) {
                    if (piVar20[0x2b] == 0) {
                      in_q8._8_8_ = *(double *)(piVar20 + 0x2c);
                      in_q8._0_8_ = *(double *)(piVar19 + 0x2e);
                      if (in_q8._8_8_ == in_q8._0_8_ ||
                          in_q8._8_8_ < in_q8._0_8_ != (NAN(in_q8._8_8_) || NAN(in_q8._0_8_))) {
                        if (DAT_0003a678 != 0) {
                          __android_log_print(6,"CAMPAN",
                                              "person match another head, exist before lost");
                        }
                      }
                      else {
                        if (DAT_0003a678 != 0) {
                          __android_log_print(6,"CAMPAN","use temp person %d match head %d->%d",
                                              piVar19[0x15],iVar5,piVar19[2]);
                        }
                        if (local_334 == local_330) {
                          std::vector<int,std::allocator<int>>::_M_realloc_insert<int_const&>
                                    ((vector<int,std::allocator<int>> *)&local_338,local_334,piVar17
                                    );
                        }
                        else {
                          if (local_334 != (int *)0x0) {
                            *local_334 = *piVar17;
                          }
                          local_334 = local_334 + 1;
                        }
                        iVar10 = *piVar17;
                        piVar19[4] = 0;
                        piVar19[3] = iVar10;
                        *piVar17 = piVar19[2];
                        piVar17[0xc] = piVar19[0x2b];
                        piVar17[0xe] = piVar19[0x42];
                      }
                    }
                    else if (DAT_0003a678 != 0) {
                      __android_log_print(6,"CAMPAN","person match another tracking head ");
                    }
                    goto LAB_00019ad4;
                  }
                }
                __android_log_print(6,"CAMPAN","person %d match head %d, not found",*piVar21,iVar5);
              }
LAB_00019d86:
              iVar5 = DAT_0003a678;
              in_q8 = ZEXT816(0);
              local_2fc = 0;
              uStack_2f8 = 0;
              uStack_2f4 = 0;
              iVar2 = piVar19[2];
              iVar10 = piVar19[0x38] / 2;
              uVar24 = param_2 - 1;
              uVar3 = param_3 - 1;
              uVar8 = (((iVar10 + piVar19[0x36]) - piVar19[0x3a] / 2) +
                      (piVar21[5] + piVar21[7]) / 2) - iVar10;
              uVar6 = piVar21[6] + piVar19[0x37];
              uVar22 = (piVar19[0x38] + uVar8) - 1;
              uVar26 = (piVar19[0x39] + uVar6) - 1;
              uVar6 = uVar6 & ~((int)uVar6 >> 0x1f);
              uVar8 = uVar8 & ~((int)uVar8 >> 0x1f);
              uVar22 = uVar22 & ~((int)uVar22 >> 0x1f);
              if ((int)uVar24 <= (int)uVar8) {
                uVar8 = uVar24;
              }
              uVar26 = uVar26 & ~((int)uVar26 >> 0x1f);
              if ((int)uVar22 <= (int)uVar24) {
                uVar24 = uVar22;
              }
              local_32c = CONCAT44(uVar8,iVar2);
              if ((int)uVar3 <= (int)uVar6) {
                uVar6 = uVar3;
              }
              if ((int)uVar3 <= (int)uVar26) {
                uVar26 = uVar3;
              }
              local_324 = CONCAT44(uVar24,uVar6);
              local_314 = CONCAT44(uVar24,uVar6);
              local_31c = CONCAT44(uVar8,uVar26);
              local_30c = (ulonglong)uVar26;
              local_304 = CONCAT44(1,*piVar21);
              piVar21[0x52] = iVar2;
              if (iVar5 != 0) {
                __android_log_print(6,"CAMPAN",
                                    "use body %d generate relative head %d, %d, %d, %d, %d",
                                    piVar19[0x15],iVar2,uVar8,uVar6,uVar24,uVar26);
              }
              AX_ARRAY_PUSH_BACK<nn_campan_heads_t,nn_campan_head_t>
                        ((nn_campan_heads_t *)(param_1 + 0x128),(nn_campan_head_t *)&local_32c);
              piVar19 = (int *)*piVar19;
              goto joined_r0x00019d00;
            }
LAB_00019ac4:
            if (iVar5 != 0) {
              __android_log_print(6,"CAMPAN","lost body");
            }
          }
          goto LAB_00019ad4;
        }
        if (*(int *)(param_1 + 300) < 1) {
LAB_00019c7a:
                    /* WARNING: Does not return */
          pcVar1 = (code *)software_udf(0xff,0x19c7e);
          (*pcVar1)();
        }
        piVar21 = *(int **)(param_1 + 0x128);
        if (piVar19[2] != *piVar21) {
          iVar10 = 0;
          do {
            iVar10 = iVar10 + 1;
            if (iVar10 == *(int *)(param_1 + 300)) goto LAB_00019c7a;
            piVar20 = piVar21 + 0xf;
            piVar21 = piVar21 + 0xf;
          } while (piVar19[2] != *piVar20);
        }
        iVar10 = piVar21[10];
        if (*(int *)(param_1 + 0x114) < 1) {
LAB_00019ce2:
          if (DAT_0003a678 != 0) {
            __android_log_print(6,"CAMPAN",
                                "head id exist, but head corresponding person id not exist,is -1");
            iVar10 = piVar21[10];
          }
          if (iVar10 != -1) goto LAB_00019ad4;
          if (piVar19[0x15] != -1) {
            piVar19[0x15] = -1;
          }
          piVar19 = (int *)*piVar19;
        }
        else {
          piVar20 = *(int **)(param_1 + 0x110);
          if (iVar10 != *piVar20) {
            iVar5 = 0;
            do {
              iVar5 = iVar5 + 1;
              if (iVar5 == *(int *)(param_1 + 0x114)) goto LAB_00019ce2;
              piVar11 = piVar20 + 0xaa;
              piVar20 = piVar20 + 0xaa;
            } while (iVar10 != *piVar11);
          }
          if ((piVar20[0x50] != 0) && (piVar19[4] != 0)) {
            piVar13 = (int *)piVar19[0x19];
            piVar11 = piVar19 + 0x19;
            if (piVar11 == piVar13) {
              uVar6 = piVar19[0x1b];
              if (uVar6 < 5) {
LAB_0001a3be:
                p_Var4 = (_List_node_base *)operator_new(0x2b0);
                memcpy(p_Var4 + 8,piVar20,0x2a8);
                std::__detail::_List_node_base::_M_hook(p_Var4);
                uVar6 = piVar19[0x1b] + 1;
                piVar19[0x1b] = uVar6;
              }
LAB_0001a39e:
              if (10 < uVar6) {
                pvVar15 = (void *)piVar19[0x1a];
                piVar19[0x1b] = uVar6 - 1;
                std::__detail::_List_node_base::_M_unhook();
                operator_delete(pvVar15);
              }
            }
            else {
              dVar28 = 99.0;
              do {
                dVar29 = (double)person_feature_dist((nn_campan_person_feature_t *)(piVar13 + 0xe),
                                                     (nn_campan_person_feature_t *)(piVar20 + 0xc));
                piVar13 = (int *)*piVar13;
                if ((int)((uint)(dVar29 < dVar28) << 0x1f) < 0) {
                  dVar28 = dVar29;
                }
              } while (piVar11 != piVar13);
              uVar6 = piVar19[0x1b];
              if (4 < uVar6) {
                in_q8._0_8_ = 0.029999999329447746;
                if ((dVar28 != 0.029999999329447746 && dVar28 < 0.029999999329447746 == NAN(dVar28))
                   && (in_q8._0_8_ = 1.0, (int)((uint)(dVar28 < 1.0) << 0x1f) < 0)) {
                  p_Var4 = (_List_node_base *)operator_new(0x2b0);
                  memcpy(p_Var4 + 8,piVar20,0x2a8);
                  std::__detail::_List_node_base::_M_hook(p_Var4);
                  uVar6 = piVar19[0x1b] + 1;
                  piVar19[0x1b] = uVar6;
                }
                goto LAB_0001a39e;
              }
              in_q8._0_8_ = 0.03;
              if (dVar28 != 0.03 && dVar28 < 0.03 == NAN(dVar28)) goto LAB_0001a3be;
            }
            if ((uint)piVar19[0x18] < 3) {
              FUN_00019660(piVar11,auStack_2f0,&local_32c);
              if ((float)local_32c != 2.0 && (float)local_32c < 2.0 == NAN((float)local_32c)) {
                piVar13 = (int *)piVar19[0x16];
                if ((piVar19[0x18] != 0) && (piVar17 != piVar13)) {
                  dVar28 = 99.0;
                  do {
                    dVar29 = (double)person_feature_dist((nn_campan_person_feature_t *)
                                                         (piVar13 + 0xe),anStack_2c0);
                    piVar13 = (int *)*piVar13;
                    if ((int)((uint)(dVar29 < dVar28) << 0x1f) < 0) {
                      dVar28 = dVar29;
                    }
                  } while (piVar17 != piVar13);
                  in_q8._0_8_ = 0.05000000074505806;
                  if (dVar28 == 0.05000000074505806 || dVar28 < 0.05000000074505806 != NAN(dVar28))
                  goto LAB_00019e9c;
                }
                p_Var4 = (_List_node_base *)operator_new(0x2b0);
                memcpy(p_Var4 + 8,auStack_2f0,0x2a8);
                std::__detail::_List_node_base::_M_hook(p_Var4);
                piVar19[0x18] = piVar19[0x18] + 1;
                piVar17 = (int *)piVar19[0x19];
                while (piVar11 != piVar17) {
                  piVar13 = (int *)*piVar17;
                  operator_delete(piVar17);
                  piVar17 = piVar13;
                }
LAB_0001a07e:
                piVar19[0x19] = (int)piVar11;
                piVar19[0x1a] = (int)piVar11;
                piVar19[0x1b] = 0;
              }
            }
            else {
              FUN_00019660(piVar11,auStack_2f0,&local_33c);
              if (local_33c != 2.0 && local_33c < 2.0 == NAN(local_33c)) {
                pfVar14 = (float *)(iVar16 + 0x2d0);
                iVar5 = -1;
                fVar35 = 10000.0;
                iVar2 = 0;
                iVar12 = (local_2e0 - local_2e8) + 2;
                iVar10 = iVar12;
                do {
                  fVar33 = *pfVar14;
                  pfVar14 = pfVar14 + 1;
                  fVar33 = ABS((float)(longlong)((local_2e4 - local_2ec) + 1) /
                               (float)(longlong)iVar12 - fVar33);
                  iVar25 = (uint)(fVar33 < fVar35) << 0x1f;
                  if (iVar25 < 0) {
                    iVar10 = iVar2;
                    fVar35 = fVar33;
                  }
                  iVar2 = iVar2 + 1;
                  if (-1 < iVar25) {
                    iVar10 = iVar5;
                  }
                  iVar5 = iVar10;
                  iVar10 = iVar5;
                } while (iVar2 != 5);
                piVar17 = piVar19 + iVar5 * 3 + 0x1c;
                get_person_upper_box((nn_campan_person_t *)&local_32c);
                if (0 < *(int *)(param_1 + 300)) {
                  local_374 = 0;
                  iVar2 = *(int *)(param_1 + 0x128);
                  in_q8._8_8_ = 0.7;
                  iVar10 = *(int *)(param_1 + 300) * 0x3c + iVar2;
                  fVar35 = (float)(longlong)
                                  ((((int)local_324 - (int)(float)local_32c) + 1) *
                                  ((local_324._4_4_ - local_32c._4_4_) + 1));
                  do {
                    iVar25 = *(int *)(iVar2 + 4);
                    iVar18 = *(int *)(iVar2 + 8);
                    iVar7 = *(int *)(iVar2 + 0xc);
                    iVar9 = *(int *)(iVar2 + 0x10);
                    iVar2 = iVar2 + 0x3c;
                    iVar12 = iVar25;
                    if (iVar25 <= (int)(float)local_32c) {
                      iVar12 = (int)(float)local_32c;
                    }
                    iVar34 = iVar18;
                    if (iVar18 <= local_32c._4_4_) {
                      iVar34 = local_32c._4_4_;
                    }
                    iVar30 = iVar7;
                    if ((int)local_324 <= iVar7) {
                      iVar30 = (int)local_324;
                    }
                    iVar31 = iVar9;
                    if (local_324._4_4_ <= iVar9) {
                      iVar31 = local_324._4_4_;
                    }
                    uVar8 = (uint)(((float)(longlong)iVar30 - (float)(longlong)iVar12) + 1.0);
                    uVar6 = (uint)(((float)(longlong)iVar31 - (float)(longlong)iVar34) + 1.0);
                    if ((int)(uVar8 | uVar6) < 0) {
                      fVar33 = 0.0;
                    }
                    else {
                      fVar33 = (float)(longlong)(int)uVar8 * (float)(longlong)(int)uVar6;
                    }
                    fVar32 = (float)(longlong)(((iVar9 - iVar18) + 1) * ((iVar7 - iVar25) + 1));
                    if (-1 < (int)((uint)(fVar32 < fVar35) << 0x1f)) {
                      fVar32 = fVar35;
                    }
                    in_q8._0_8_ = (double)(fVar33 / fVar32);
                    if (in_q8._0_8_ != in_q8._8_8_ &&
                        in_q8._0_8_ < in_q8._8_8_ == (NAN(in_q8._0_8_) || NAN(in_q8._8_8_))) {
                      local_374 = local_374 + 1;
                    }
                  } while (iVar2 != iVar10);
                  if ((1 < local_374) && (DAT_0003a678 != 0)) {
                    __android_log_print(6,"CAMPAN","find not only one head reject %d",local_374);
                  }
                }
                local_37c = auStack_2f0;
                piVar13 = (int *)piVar19[iVar5 * 3 + 0x1c];
                if ((2 < (uint)piVar17[2]) && (piVar17 != piVar13)) {
                  dVar28 = 99.0;
                  do {
                    dVar29 = (double)person_feature_dist((nn_campan_person_feature_t *)
                                                         (piVar13 + 0xe),anStack_2c0);
                    piVar13 = (int *)*piVar13;
                    if ((int)((uint)(dVar29 < dVar28) << 0x1f) < 0) {
                      dVar28 = dVar29;
                    }
                  } while (piVar17 != piVar13);
                  in_q8._0_8_ = 0.05000000074505806;
                  if (dVar28 == 0.05000000074505806 || dVar28 < 0.05000000074505806 != NAN(dVar28))
                  goto LAB_00019e9c;
                }
                p_Var4 = (_List_node_base *)operator_new(0x2b0);
                memcpy(p_Var4 + 8,local_37c,0x2a8);
                std::__detail::_List_node_base::_M_hook(p_Var4);
                iVar10 = piVar17[2];
                uVar6 = iVar10 + 1;
                piVar17[2] = uVar6;
                if (5 < uVar6) {
                  pvVar15 = (void *)piVar19[iVar5 * 3 + 0x1d];
                  piVar17[2] = iVar10;
                  std::__detail::_List_node_base::_M_unhook();
                  operator_delete(pvVar15);
                }
                piVar17 = (int *)piVar19[0x19];
                while (piVar11 != piVar17) {
                  piVar13 = (int *)*piVar17;
                  operator_delete(piVar17);
                  piVar17 = piVar13;
                }
                goto LAB_0001a07e;
              }
            }
          }
LAB_00019e9c:
          iVar10 = piVar20[5];
          iVar5 = piVar20[6];
          iVar2 = piVar20[8];
          piVar19[0x3a] = (piVar20[7] - iVar10) + 1;
          piVar19[0x3b] = (iVar2 - iVar5) + 1;
          iVar25 = piVar21[5];
          iVar12 = piVar21[6];
          iVar2 = piVar21[8];
          piVar19[0x38] = (piVar21[7] - iVar25) + 1;
          piVar19[0x39] = (iVar2 - iVar12) + 1;
          piVar19[0x36] = iVar25 - iVar10;
          piVar19[0x37] = iVar12 - iVar5;
          piVar19[0x15] = *piVar20;
          piVar19 = (int *)*piVar19;
        }
      }
joined_r0x00019d00:
    } while (piVar19 != piVar23);
    if (0 < (int)local_334 - (int)local_338) {
      local_380 = 0;
      do {
        piVar17 = (int *)*piVar23;
        if (piVar19 != piVar17) {
LAB_00019b14:
          if (*(int *)((int)local_338 + local_380 * 4) != piVar17[2]) goto LAB_00019b0e;
          if (DAT_0003a678 != 0) {
            __android_log_print(6,"CAMPAN","erase heads_hist(head) %d");
          }
          piVar21 = piVar17 + 0x2b;
          piVar23[2] = piVar23[2] + -1;
          std::__detail::_List_node_base::_M_unhook();
          do {
            piVar21 = piVar21 + -3;
            piVar20 = (int *)*piVar21;
            while (piVar21 != piVar20) {
              piVar11 = (int *)*piVar20;
              operator_delete(piVar20);
              piVar20 = piVar11;
            }
          } while (piVar17 + 0x1c != piVar21);
          piVar21 = (int *)piVar17[0x19];
          while (piVar17 + 0x19 != piVar21) {
            piVar20 = (int *)*piVar21;
            operator_delete(piVar21);
            piVar21 = piVar20;
          }
          piVar21 = (int *)piVar17[0x16];
          while (piVar17 + 0x16 != piVar21) {
            piVar20 = (int *)*piVar21;
            operator_delete(piVar21);
            piVar21 = piVar20;
          }
          piVar21 = piVar17 + 0x14;
          do {
            piVar21 = piVar21 + -3;
            piVar20 = (int *)*piVar21;
            while (piVar21 != piVar20) {
              piVar11 = (int *)*piVar20;
              operator_delete(piVar20);
              piVar20 = piVar11;
            }
          } while (piVar17 + 0xb != piVar21);
          piVar21 = (int *)piVar17[8];
          while (piVar21 != piVar17 + 8) {
            piVar20 = (int *)*piVar21;
            operator_delete(piVar21);
            piVar21 = piVar20;
          }
          piVar21 = (int *)piVar17[5];
          while (piVar17 + 5 != piVar21) {
            piVar20 = (int *)*piVar21;
            operator_delete(piVar21);
            piVar21 = piVar20;
          }
          operator_delete(piVar17);
          goto LAB_00019bd4;
        }
LAB_00019bf8:
        if (DAT_0003a678 != 0) {
          __android_log_print(6,"CAMPAN","erase heads_hist not exist %d");
        }
LAB_00019bd4:
        local_380 = local_380 + 1;
        uVar6 = (int)local_334 - (int)local_338 >> 2;
        if ((int)uVar6 <= (int)local_380) break;
        if (uVar6 <= local_380) {
                    /* WARNING: Subroutine does not return */
          std::__throw_out_of_range_fmt
                    ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                     local_380);
        }
      } while( true );
    }
    if (local_338 != (void *)0x0) {
      operator_delete(local_338);
    }
  }
  if (local_44 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_00019a06:
  piVar21 = piVar20 + local_380 * 0xaa;
  if ((piVar21[0x54] == 0) && (piVar21[0x50] == 1)) {
    piVar20 = (int *)piVar19[0x16];
    fVar35 = 99.0;
    if (piVar17 == piVar20) {
LAB_00019a60:
      fVar35 = 99.0;
      piVar20 = piVar19 + 0x1c;
      do {
        piVar11 = (int *)*piVar20;
        while (piVar20 != piVar11) {
          uVar36 = in_q8._8_8_;
          dVar28 = (double)person_feature_dist((nn_campan_person_feature_t *)(piVar11 + 0xe),
                                               (nn_campan_person_feature_t *)(piVar21 + 0xc));
          in_q8._0_8_ = (double)fVar35;
          in_q8._8_8_ = (double)uVar36;
          piVar11 = (int *)*piVar11;
          if ((int)((uint)(dVar28 < in_q8._0_8_) << 0x1f) < 0) {
            fVar35 = (float)dVar28;
          }
        }
        piVar20 = piVar20 + 3;
      } while (piVar19 + 0x2b != piVar20);
      if (-1 < (int)((uint)(fVar35 < 0.05) << 0x1f)) {
        iVar2 = *(int *)(param_1 + 0x114);
        iVar5 = DAT_0003a678;
        if ((int)(local_380 + 1) < iVar2) goto LAB_00019a02;
        goto LAB_00019ac4;
      }
    }
    else {
      do {
        uVar36 = in_q8._8_8_;
        dVar28 = (double)person_feature_dist((nn_campan_person_feature_t *)(piVar20 + 0xe),
                                             (nn_campan_person_feature_t *)(piVar21 + 0xc));
        in_q8._0_8_ = (double)fVar35;
        in_q8._8_8_ = (double)uVar36;
        piVar20 = (int *)*piVar20;
        if ((int)((uint)(dVar28 < in_q8._0_8_) << 0x1f) < 0) {
          fVar35 = (float)dVar28;
        }
      } while (piVar17 != piVar20);
      if (-1 < (int)((uint)(fVar35 < 0.05) << 0x1f)) goto LAB_00019a60;
      fVar35 = 99.0;
    }
    iVar10 = *piVar21;
    if (DAT_0003a678 != 0) {
      in_q8._0_8_ = (double)fVar35;
      __android_log_print(6,"CAMPAN",
                          "person match head track %d, current %d, register_best_dist %.2f process_best_dist %.2f"
                          ,piVar19[2],iVar10);
      iVar10 = *piVar21;
    }
    iVar5 = DAT_0003a678;
    bVar27 = piVar19[0x34] != iVar10;
    if (bVar27) {
      piVar19[0x34] = iVar10;
      iVar10 = 1;
    }
    if (bVar27) {
      piVar19[0x35] = iVar10;
    }
    else {
      iVar10 = piVar19[0x35];
      piVar19[0x35] = iVar10 + 1;
      if ((1 < iVar10 + 1) && (piVar21[0x54] == 0)) {
        iVar10 = *piVar21;
        if (iVar5 != 0) {
          __android_log_print(6,"CAMPAN","refind body person_short_term_id %d -> %d",piVar19[0x15],
                              iVar10);
          iVar10 = *piVar21;
        }
        piVar19[0x15] = iVar10;
        goto LAB_00019d52;
      }
    }
    goto LAB_00019ac4;
  }
  iVar5 = DAT_0003a678;
  if (iVar2 <= (int)(local_380 + 1)) goto LAB_00019ac4;
LAB_00019a02:
  local_380 = local_380 + 1;
  piVar20 = *(int **)(param_1 + 0x110);
  goto LAB_00019a06;
LAB_00019b0e:
  piVar17 = (int *)*piVar17;
  if (piVar19 == piVar17) goto LAB_00019bf8;
  goto LAB_00019b14;
}



/* void std::vector<ax_box_t, std::allocator<ax_box_t> >::_M_realloc_insert<ax_box_t
   const&>(__gnu_cxx::__normal_iterator<ax_box_t*, std::vector<ax_box_t, std::allocator<ax_box_t> >
   >, ax_box_t const&) */

void __thiscall
std::vector<ax_box_t,std::allocator<ax_box_t>>::_M_realloc_insert<ax_box_t_const&>
          (vector<ax_box_t,std::allocator<ax_box_t>> *this,void *param_2,undefined4 *param_3)

{
  void *__dest;
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *__dest_00;
  size_t __n;
  void *__src;
  uint uVar5;
  int iVar6;
  void *pvVar7;
  size_t sVar8;
  undefined4 *puVar9;
  
  __src = *(void **)this;
  pvVar7 = *(void **)(this + 4);
  sVar8 = (int)param_2 - (int)__src;
  uVar2 = (int)pvVar7 - (int)__src >> 4;
  if (uVar2 == 0) {
    uVar5 = 1;
LAB_0001a5c0:
    uVar5 = uVar5 << 4;
  }
  else {
    uVar5 = uVar2 * 2;
    if ((uVar2 <= uVar5) && (uVar5 < 0x10000000)) {
      if (uVar5 == 0) {
        iVar6 = 0;
        __dest = (void *)0x0;
        __n = sVar8;
        goto LAB_0001a570;
      }
      goto LAB_0001a5c0;
    }
    uVar5 = 0xfffffff0;
  }
  __dest = operator_new(uVar5);
  __src = *(void **)this;
  iVar6 = uVar5 + (int)__dest;
  pvVar7 = *(void **)(this + 4);
  __n = (int)param_2 - (int)__src;
LAB_0001a570:
  puVar9 = (undefined4 *)((int)__dest + sVar8);
  if (puVar9 != (undefined4 *)0x0) {
    uVar1 = param_3[1];
    uVar3 = param_3[2];
    uVar4 = param_3[3];
    *puVar9 = *param_3;
    puVar9[1] = uVar1;
    puVar9[2] = uVar3;
    puVar9[3] = uVar4;
  }
  if (param_2 != __src) {
    memmove(__dest,__src,__n);
  }
  __dest_00 = (void *)(__n + 0x10 + (int)__dest);
  if (pvVar7 != param_2) {
    __dest_00 = memcpy(__dest_00,param_2,(int)pvVar7 - (int)param_2);
  }
  if (__src != (void *)0x0) {
    operator_delete(__src);
  }
  *(void **)this = __dest;
  *(int *)(this + 4) = (int)__dest_00 + ((int)pvVar7 - (int)param_2);
  *(int *)(this + 8) = iVar6;
  return;
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_0001a5d8(int param_1,undefined4 *param_2)

{
  ax_detect_box_array_t *paVar1;
  pthread_mutex_t *__mutex;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  void *pvVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  undefined4 uVar16;
  int iVar17;
  int iVar18;
  int *piVar19;
  int *piVar20;
  int *piVar21;
  retina_t *prVar22;
  int iVar23;
  uint uVar24;
  undefined4 *puVar25;
  int iVar26;
  size_t sVar27;
  uint uVar28;
  int *piVar29;
  int iVar30;
  bool bVar31;
  ax_detect_box_t *paVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  undefined4 uVar36;
  int iVar37;
  float fVar38;
  float fVar39;
  int iVar40;
  int iVar41;
  int iVar42;
  float fVar43;
  float fVar44;
  float fVar45;
  int local_508;
  int *local_500;
  retina_in_t *local_4fc;
  uint local_4e8;
  int local_4e4;
  undefined4 *local_4b4;
  undefined4 *local_4b0;
  int *local_4a0;
  int iStack_49c;
  int iStack_498;
  int iStack_494;
  undefined4 local_490;
  undefined4 uStack_48c;
  undefined4 uStack_488;
  undefined4 uStack_484;
  undefined4 local_480;
  undefined4 uStack_47c;
  undefined4 uStack_478;
  undefined4 uStack_474;
  undefined4 local_470;
  uint *local_464;
  undefined8 local_460;
  undefined8 local_458;
  undefined4 local_450;
  undefined4 uStack_44c;
  retina_in_t *local_448;
  undefined4 *local_444;
  undefined4 *local_440;
  void *local_43c;
  undefined4 *local_438;
  undefined4 *local_434;
  void *local_430;
  undefined4 *local_42c;
  undefined4 *local_428;
  void *local_424;
  undefined4 *local_420;
  undefined4 *local_41c;
  int *local_418;
  int local_414;
  int local_410;
  int iStack_40c;
  int *local_408;
  int iStack_404;
  int local_400;
  int iStack_3fc;
  void *local_3f8;
  undefined4 *local_3f4;
  undefined4 *local_3f0;
  undefined4 local_3ec;
  void *local_3e8;
  int local_3e4;
  int local_3e0;
  int iStack_3dc;
  undefined4 local_3d8;
  undefined4 uStack_3d4;
  undefined4 uStack_3d0;
  undefined4 uStack_3cc;
  undefined4 local_3c8;
  undefined4 uStack_3c4;
  undefined4 uStack_3c0;
  undefined4 uStack_3bc;
  undefined4 local_3b8;
  undefined4 local_3b4;
  undefined4 uStack_3b0;
  undefined4 local_3ac;
  undefined4 local_3a8;
  undefined4 local_3a4;
  undefined4 local_3a0;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 uStack_1f8;
  undefined4 local_1ec;
  int *local_1e8;
  int local_1e4;
  int local_1e0;
  int local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_48;
  undefined4 local_44;
  
  if (DAT_0003a674 << 0x1a < 0) {
    __android_log_print(6,"CAMPAN","");
  }
  iVar10 = *(int *)(param_1 + 0x108);
  __mutex = (pthread_mutex_t *)(param_1 + 0x1cc);
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  pthread_mutex_lock(__mutex);
  prVar22 = *(retina_t **)(param_1 + 0xb8);
  local_4b4 = *(undefined4 **)(param_1 + 0x18);
  local_4b0 = *(undefined4 **)(param_1 + 0x1c);
  if (*(int *)(param_1 + 0x10) != 0) {
    prVar22 = *(retina_t **)(param_1 + 0xbc);
    local_4b4 = *(undefined4 **)(param_1 + 0x28);
    local_4b0 = *(undefined4 **)(param_1 + 0x2c);
  }
  pthread_mutex_unlock(__mutex);
  if (((prVar22 == (retina_t *)0x0) || (*(int *)(iVar10 + 0x28) == 0)) || (param_2[9] == 0)) {
    if (*(int *)(param_1 + 0x260) == 0) {
      return;
    }
    sem_wait((sem_t *)(*(int *)(param_1 + 0x260) + 0x14));
    return;
  }
  uVar2 = param_2[1];
  uVar11 = *param_2;
  local_460 = 0;
  nnyuv2axyuv((nn_yuv_t *)&local_490);
  local_3d8 = local_490;
  uStack_3d4 = uStack_48c;
  uStack_3d0 = uStack_488;
  uStack_3cc = uStack_484;
  local_3c8 = local_480;
  uStack_3c4 = uStack_47c;
  uStack_3c0 = uStack_478;
  uStack_3bc = uStack_474;
  local_3b8 = local_470;
  local_210 = 0x3f400000;
  local_3a4 = 0x3f59999a;
  local_3a0 = 0x3f51eb85;
  local_214 = 0x3eb33333;
  local_3b4 = 0;
  uStack_3b0 = 0;
  local_3ac = uVar11;
  local_3a8 = uVar2;
  retina_process(prVar22,(retina_in_t *)&local_3d8,(retina_out_t *)&local_460);
  if (*(int *)(param_1 + 0x260) != 0) {
    sem_wait((sem_t *)(*(int *)(param_1 + 0x260) + 0x14));
  }
  local_440 = (undefined4 *)0x0;
  iVar30 = *(int *)(param_1 + 0x114);
  local_448 = (retina_in_t *)0x0;
  local_444 = (undefined4 *)0x0;
  local_43c = (void *)0x0;
  local_438 = (undefined4 *)0x0;
  local_434 = (undefined4 *)0x0;
  if (0 < iVar30) {
    iVar23 = 0;
    do {
      iVar12 = iVar23 * 0x2a8 + *(int *)(param_1 + 0x110);
      local_20c = *(undefined4 *)(iVar12 + 4);
      local_208 = *(undefined4 *)(iVar12 + 8);
      local_204 = *(undefined4 *)(iVar12 + 0xc);
      local_200 = *(undefined4 *)(iVar12 + 0x10);
      if (local_444 == local_440) {
        std::vector<ax_box_t,std::allocator<ax_box_t>>::_M_realloc_insert<ax_box_t_const&>
                  ((vector<ax_box_t,std::allocator<ax_box_t>> *)&local_448,local_444,&local_20c);
        iVar30 = *(int *)(param_1 + 0x114);
        if (iVar30 <= iVar23 + 1) break;
      }
      else {
        if (local_444 != (undefined4 *)0x0) {
          *local_444 = local_20c;
          local_444[1] = local_208;
          local_444[2] = local_204;
          local_444[3] = local_200;
        }
        local_444 = local_444 + 4;
        if (iVar30 <= iVar23 + 1) break;
      }
      iVar23 = iVar23 + 1;
    } while( true );
  }
  piVar29 = (int *)local_460._4_4_;
  iVar30 = *(int *)((int)local_460._4_4_ + 4);
  if (0 < iVar30) {
    iVar23 = 0;
    do {
      while( true ) {
        iVar12 = *piVar29;
        local_20c = *(undefined4 *)(iVar12 + iVar23 * 0x1c);
        iVar12 = iVar12 + iVar23 * 0x1c;
        local_208 = *(undefined4 *)(iVar12 + 4);
        local_204 = *(undefined4 *)(iVar12 + 8);
        local_200 = *(undefined4 *)(iVar12 + 0xc);
        if (local_438 != local_434) break;
        std::vector<ax_box_t,std::allocator<ax_box_t>>::_M_realloc_insert<ax_box_t_const&>
                  ((vector<ax_box_t,std::allocator<ax_box_t>> *)&local_43c,local_438,&local_20c);
        iVar30 = piVar29[1];
        iVar23 = iVar23 + 1;
        if (iVar30 <= iVar23) goto LAB_0001a7d0;
      }
      if (local_438 != (undefined4 *)0x0) {
        *local_438 = local_20c;
        local_438[1] = local_208;
        local_438[2] = local_204;
        local_438[3] = local_200;
      }
      iVar23 = iVar23 + 1;
      local_438 = local_438 + 4;
    } while (iVar23 < iVar30);
  }
LAB_0001a7d0:
  local_464 = (uint *)0x0;
  person_head_match(*(campan_feature_match_t **)(param_1 + 0x1c8),(vector *)&local_448,
                    (vector *)&local_43c,(int **)&local_464,(int **)0x0);
  uVar24 = 0;
  local_4fc = local_448;
  if ((int)local_444 - (int)local_448 < 1) {
    local_4fc = (retina_in_t *)&local_20c;
  }
  local_430 = (void *)0x0;
  local_42c = (undefined4 *)0x0;
  local_428 = (undefined4 *)0x0;
  local_424 = (void *)0x0;
  local_420 = (undefined4 *)0x0;
  local_41c = (undefined4 *)0x0;
  if (0 < (int)local_444 - (int)local_448) {
    uVar28 = *local_464;
    do {
      local_4fc = local_4fc + uVar24 * 0x10;
      local_20c = *(undefined4 *)local_4fc;
      local_208 = *(undefined4 *)(local_4fc + 4);
      local_204 = *(undefined4 *)(local_4fc + 8);
      local_200 = *(undefined4 *)(local_4fc + 0xc);
      if ((int)uVar28 < 0) {
        if (local_42c != local_428) {
          if (local_42c != (undefined4 *)0x0) {
            *local_42c = local_20c;
            local_42c[1] = local_208;
            local_42c[2] = local_204;
            local_42c[3] = local_200;
          }
          goto LAB_0001a830;
        }
LAB_0001a8c0:
        std::vector<ax_box_t,std::allocator<ax_box_t>>::_M_realloc_insert<ax_box_t_const&>
                  ((vector<ax_box_t,std::allocator<ax_box_t>> *)&local_430,local_42c,
                   (retina_in_t *)&local_20c);
      }
      else {
        if ((uint)((int)local_438 - (int)local_43c >> 4) <= uVar28) {
                    /* WARNING: Subroutine does not return */
          std::__throw_out_of_range_fmt
                    ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                     uVar28);
        }
        iVar30 = uVar28 * 0x10;
        if ((*(int *)((int)local_43c + iVar30 + 0xc) - *(int *)((int)local_43c + iVar30 + 4)) *
            (*(int *)((int)local_43c + iVar30 + 8) - *(int *)((int)local_43c + iVar30)) < 0xe10) {
          if (local_42c == local_428) goto LAB_0001a8c0;
          if (local_42c != (undefined4 *)0x0) {
            *local_42c = local_20c;
            local_42c[1] = local_208;
            local_42c[2] = local_204;
            local_42c[3] = local_200;
          }
LAB_0001a830:
          local_42c = local_42c + 4;
        }
        else if (local_420 == local_41c) {
          std::vector<ax_box_t,std::allocator<ax_box_t>>::_M_realloc_insert<ax_box_t_const&>
                    ((vector<ax_box_t,std::allocator<ax_box_t>> *)&local_424,local_420,
                     (retina_in_t *)&local_20c);
        }
        else {
          if (local_420 != (undefined4 *)0x0) {
            *local_420 = local_20c;
            local_420[1] = local_208;
            local_420[2] = local_204;
            local_420[3] = local_200;
          }
          local_420 = local_420 + 4;
        }
      }
      uVar24 = uVar24 + 1;
      uVar7 = (int)local_444 - (int)local_448 >> 4;
      if ((int)uVar7 <= (int)uVar24) {
        if ((int)local_42c - (int)local_430 < 1) goto LAB_0001a8d8;
        local_4e8 = 0;
        goto LAB_0001abe0;
      }
      uVar28 = local_464[uVar24];
      local_4fc = local_448;
      if (uVar7 <= uVar24) {
                    /* WARNING: Subroutine does not return */
        std::__throw_out_of_range_fmt
                  ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                   uVar24);
      }
    } while( true );
  }
LAB_0001a8e2:
  if (local_430 != (void *)0x0) {
    operator_delete(local_430);
  }
  if (local_43c != (void *)0x0) {
    operator_delete(local_43c);
  }
  if (local_448 != (retina_in_t *)0x0) {
    operator_delete(local_448);
  }
  bVar31 = false;
  piVar29 = (int *)local_460._4_4_;
  iVar23 = *(int *)((int)(int *)local_460 + 4);
  iVar30 = *(int *)((int)local_460._4_4_ + 4);
  do {
    uVar13 = param_2[3];
    if (bVar31) {
      *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x8c);
      *(undefined4 *)(param_1 + 0x38) = uVar13;
      *(undefined4 *)(param_1 + 0x3c) = uVar11;
      *(undefined4 *)(param_1 + 0x40) = uVar2;
      uVar13 = *(undefined4 *)(param_1 + 0x94);
      FUN_0001624c(param_1 + 0x54,param_1 + 0x58,iVar23);
      if (0 < iVar23) {
        piVar3 = (int *)*(int *)local_460;
        piVar29 = piVar3;
        piVar20 = *(int **)(param_1 + 0x54);
        do {
          iVar12 = *piVar29;
          piVar19 = piVar29 + 0xf;
          iVar4 = piVar29[4];
          *piVar20 = iVar12;
          iVar30 = piVar29[1];
          piVar20[1] = iVar30;
          piVar20[2] = (piVar29[2] - iVar12) + 1;
          iVar12 = piVar29[3];
          piVar20[4] = iVar4;
          piVar20[3] = (iVar12 - iVar30) + 1;
          piVar29 = piVar19;
          piVar20 = piVar20 + 5;
        } while (piVar3 + iVar23 * 0xf != piVar19);
      }
      uVar14 = *(undefined4 *)(iVar10 + 0x68);
      iVar10 = 0;
      *local_4b4 = 0x3e8f5c29;
      local_4b4[0xc] = 0x3eb33333;
      local_4b4[0xd] = 0x3eb33333;
      local_4b4[6] = uVar14;
      local_4b4[8] = 0x3f666666;
      local_4b4[1] = 2;
      local_4b4[0x11] = 0x3e800000;
      local_4b4[5] = 1;
      local_4b4[0xb] = 1;
      local_4b4[7] = 1;
      local_4b4[10] = 1;
      local_4b4[0x10] = 3;
      local_4b4[2] = 0;
      local_4b4[9] = 0;
      dtbased_tk_update(local_4b4,param_1 + 0x34,&local_408);
      AX_MALLOC_INC_TEMP<nn_campan_faces_t>((nn_campan_faces_t *)(param_1 + 0x120),local_408[1]);
      memset(*(void **)(param_1 + 0x120),0,local_408[1] * 0x178);
      local_3f8 = (void *)0x0;
      local_3f4 = (undefined4 *)0x0;
      local_3f0 = (undefined4 *)0x0;
      local_3e8 = (void *)0x0;
      local_3e4 = 0;
      local_3e0 = 0;
      if (0 < local_408[1]) {
        do {
          iVar4 = *local_408 + iVar10 * 0x20;
          iVar23 = *(int *)(iVar4 + 0x18);
          iVar30 = *(int *)(param_1 + 0x120);
          iVar12 = *(int *)(*local_408 + iVar10 * 0x20) + 30000000;
          *(int *)(iVar30 + iVar10 * 0x178) = iVar12;
          iVar30 = iVar10 * 0x178 + iVar30;
          if (iVar23 < 0) {
            uVar36 = *(undefined4 *)(iVar4 + 4);
            puVar15 = (undefined4 *)(iVar30 + 0x20);
            *(undefined4 *)(iVar30 + 4) = uVar36;
            uVar14 = *(undefined4 *)(iVar4 + 8);
            *(undefined4 *)(iVar30 + 8) = uVar14;
            iVar26 = *(int *)(iVar4 + 0xc) + *(int *)(iVar4 + 4) + -1;
            *(int *)(iVar30 + 0xc) = iVar26;
            iVar4 = *(int *)(iVar4 + 8) + *(int *)(iVar4 + 0x10) + -1;
            *(int *)(iVar30 + 0x10) = iVar4;
            do {
              puVar15 = puVar15 + 1;
              *puVar15 = 0;
            } while ((undefined4 *)(iVar30 + 0x48) != puVar15);
          }
          else {
            puVar25 = (undefined4 *)(iVar30 + 0x20);
            iVar23 = iVar23 * 0x3c;
            uVar36 = *(undefined4 *)(*(int *)local_460 + iVar23);
            iVar23 = *(int *)local_460 + iVar23;
            *(undefined4 *)(iVar30 + 4) = uVar36;
            puVar15 = (undefined4 *)(iVar23 + 0x10);
            uVar14 = *(undefined4 *)(iVar23 + 4);
            *(undefined4 *)(iVar30 + 8) = uVar14;
            iVar26 = *(int *)(iVar23 + 8);
            *(int *)(iVar30 + 0xc) = iVar26;
            iVar4 = *(int *)(iVar23 + 0xc);
            *(int *)(iVar30 + 0x10) = iVar4;
            do {
              puVar15 = puVar15 + 1;
              puVar25 = puVar25 + 1;
              *puVar25 = *puVar15;
            } while ((undefined4 *)(iVar23 + 0x38) != puVar15);
          }
          *(int *)local_4fc = iVar12;
          *(undefined4 *)(local_4fc + 4) = uVar36;
          *(undefined4 *)(local_4fc + 8) = uVar14;
          *(int *)(local_4fc + 0xc) = iVar26;
          *(int *)(local_4fc + 0x10) = iVar4;
          if (local_3f4 == local_3f0) {
            std::vector<ax_track_box_t,std::allocator<ax_track_box_t>>::
            _M_realloc_insert<ax_track_box_t_const&>
                      ((vector<ax_track_box_t,std::allocator<ax_track_box_t>> *)&local_3f8,local_3f4
                       ,local_4fc);
          }
          else {
            if (local_3f4 != (undefined4 *)0x0) {
              uVar14 = *(undefined4 *)(local_4fc + 4);
              uVar36 = *(undefined4 *)(local_4fc + 8);
              uVar16 = *(undefined4 *)(local_4fc + 0xc);
              *local_3f4 = *(undefined4 *)local_4fc;
              local_3f4[1] = uVar14;
              local_3f4[2] = uVar36;
              local_3f4[3] = uVar16;
              local_3f4[4] = *(undefined4 *)(local_4fc + 0x10);
            }
            local_3f4 = local_3f4 + 5;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < local_408[1]);
      }
      *(undefined4 *)local_4fc = uVar11;
      *(undefined4 *)(local_4fc + 4) = uVar2;
      box_smooth_process(uVar13,*(undefined4 *)local_4fc,*(undefined4 *)(local_4fc + 4),
                         (vector<ax_track_box_t,std::allocator<ax_track_box_t>> *)&local_3f8,
                         &local_3e8);
      if (0 < local_3e4 - (int)local_3e8) {
        iVar10 = 0;
        iVar30 = *(int *)(param_1 + 0x120);
        pvVar8 = local_3e8;
        while( true ) {
          iVar10 = iVar10 + 1;
          *(undefined4 *)(iVar30 + 0x14) = *(undefined4 *)((int)pvVar8 + 4);
          *(undefined4 *)(iVar30 + 0x18) = *(undefined4 *)((int)pvVar8 + 8);
          *(undefined4 *)(iVar30 + 0x1c) = *(undefined4 *)((int)pvVar8 + 0xc);
          *(undefined4 *)(iVar30 + 0x20) = *(undefined4 *)((int)pvVar8 + 0x10);
          if ((local_3e4 - (int)local_3e8 >> 2) * -0x33333333 <= iVar10) break;
          pvVar8 = (void *)((int)pvVar8 + 0x14);
          iVar30 = iVar10 * 0x178 + *(int *)(param_1 + 0x120);
        }
      }
      if (local_3e8 != (void *)0x0) {
        operator_delete(local_3e8);
      }
      if (local_3f8 == (void *)0x0) {
        return;
      }
      operator_delete(local_3f8);
      return;
    }
    *(undefined4 *)(param_1 + 0x38) = uVar13;
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x8c);
    *(undefined4 *)(param_1 + 0x3c) = uVar11;
    *(undefined4 *)(param_1 + 0x40) = uVar2;
    FUN_0001624c(param_1 + 0x54,param_1 + 0x58,iVar30);
    if (0 < iVar30) {
      piVar19 = (int *)*piVar29;
      piVar20 = piVar19;
      piVar3 = *(int **)(param_1 + 0x54);
      do {
        iVar4 = *piVar20;
        piVar21 = piVar20 + 7;
        iVar26 = piVar20[6];
        *piVar3 = iVar4;
        iVar12 = piVar20[1];
        piVar3[1] = iVar12;
        piVar3[2] = (piVar20[2] - iVar4) + 1;
        iVar4 = piVar20[3];
        piVar3[4] = iVar26;
        piVar3[3] = (iVar4 - iVar12) + 1;
        piVar20 = piVar21;
        piVar3 = piVar3 + 5;
      } while (piVar19 + iVar30 * 7 != piVar21);
    }
    uVar13 = *(undefined4 *)(iVar10 + 0x68);
    *local_4b0 = 0x3e8f5c29;
    local_4b0[5] = 1;
    local_4b0[0xb] = 1;
    local_4b0[7] = 1;
    local_4b0[0xc] = 0x3eb33333;
    local_4b0[10] = 1;
    local_4b0[6] = uVar13;
    local_4b0[0xd] = 0x3e99999a;
    local_4b0[1] = 2;
    local_4b0[0xf] = 0x3f666666;
    if (*(int *)(param_1 + 0x278) == 0) {
      local_4b0[2] = 0;
    }
    else {
      local_4b0[2] = 3;
    }
    local_4b0[0x10] = 5;
    local_4b0[8] = 0x3f70a3d7;
    local_4b0[9] = 0;
    local_4b0[0x11] = 0x3e800000;
    dtbased_tk_update(local_4b0,param_1 + 0x34,&local_408);
    pvVar8 = *(void **)(param_1 + 0x128);
    iVar12 = local_408[1];
    *(int *)(param_1 + 300) = iVar12;
    if (pvVar8 == (void *)0x0) {
      sVar27 = iVar12 * 0x3c;
      if (0 < (int)sVar27) goto LAB_0001b3d4;
    }
    else {
      sVar27 = iVar12 * 0x3c;
      if (*(int *)((int)pvVar8 + -4) + iVar12 * -0x3c < 0 !=
          SBORROW4(*(int *)((int)pvVar8 + -4),sVar27)) {
        AX_FREE_RECORD(pvVar8);
        *(undefined4 *)(param_1 + 0x128) = 0;
LAB_0001b3d4:
        pvVar8 = (void *)AX_MALLOC_RECORD(iVar12 * 0x3c);
        *(void **)(param_1 + 0x128) = pvVar8;
        if (pvVar8 == (void *)0x0) {
          *(undefined4 *)(param_1 + 300) = 0;
        }
        sVar27 = local_408[1] * 0x3c;
      }
    }
    memset(pvVar8,0,sVar27);
    local_3f8 = (void *)0x0;
    local_3e8 = (void *)0x0;
    local_3e4 = 0;
    local_3e0 = 0;
    uVar13 = *(undefined4 *)(param_1 + 0x98);
    local_3f4 = (undefined4 *)0x0;
    local_3f0 = (undefined4 *)0x0;
    if (local_408[1] < 1) {
      local_4e4 = 0;
    }
    else {
      local_4e4 = 0;
      do {
        iVar26 = *local_408 + local_4e4 * 0x20;
        iVar4 = *(int *)(iVar26 + 0x18);
        iVar12 = *(int *)(*local_408 + local_4e4 * 0x20) + 10000000;
        iVar33 = *(int *)(param_1 + 0x128) + local_4e4 * 0x3c;
        *(int *)(*(int *)(param_1 + 0x128) + local_4e4 * 0x3c) = iVar12;
        *(undefined4 *)(iVar33 + 0x24) = *(undefined4 *)(iVar26 + 0x14);
        if (iVar4 < 0) {
          iVar4 = *(int *)(iVar26 + 8);
          iVar37 = *(int *)(iVar26 + 4);
          iVar35 = *(int *)(iVar26 + 0x10);
          iVar34 = *(int *)(iVar26 + 0xc) + iVar37 + -1;
          *(int *)(iVar33 + 4) = iVar37;
          iVar26 = iVar35 + iVar4 + -1;
          *(int *)(iVar33 + 0xc) = iVar34;
          *(int *)(iVar33 + 0x10) = iVar26;
          *(int *)(iVar33 + 8) = iVar4;
        }
        else {
          iVar4 = iVar4 * 0x1c;
          iVar26 = *piVar29;
          iVar35 = iVar26 + iVar4;
          iVar37 = *(int *)(iVar26 + iVar4);
          iVar4 = *(int *)(iVar35 + 4);
          iVar34 = *(int *)(iVar35 + 8);
          iVar26 = *(int *)(iVar35 + 0xc);
          *(int *)(iVar33 + 4) = iVar37;
          *(int *)(iVar33 + 8) = iVar4;
          *(int *)(iVar33 + 0xc) = iVar34;
          *(int *)(iVar33 + 0x10) = iVar26;
        }
        *(int *)local_4fc = iVar12;
        *(int *)(local_4fc + 4) = iVar37;
        *(int *)(local_4fc + 8) = iVar4;
        *(int *)(local_4fc + 0xc) = iVar34;
        *(int *)(local_4fc + 0x10) = iVar26;
        if (local_3f4 == local_3f0) {
          std::vector<ax_track_box_t,std::allocator<ax_track_box_t>>::
          _M_realloc_insert<ax_track_box_t_const&>
                    ((vector<ax_track_box_t,std::allocator<ax_track_box_t>> *)&local_3f8,local_3f4,
                     local_4fc);
        }
        else {
          if (local_3f4 != (undefined4 *)0x0) {
            uVar14 = *(undefined4 *)(local_4fc + 4);
            uVar36 = *(undefined4 *)(local_4fc + 8);
            uVar16 = *(undefined4 *)(local_4fc + 0xc);
            *local_3f4 = *(undefined4 *)local_4fc;
            local_3f4[1] = uVar14;
            local_3f4[2] = uVar36;
            local_3f4[3] = uVar16;
            local_3f4[4] = *(undefined4 *)(local_4fc + 0x10);
          }
          local_3f4 = local_3f4 + 5;
        }
        local_4e4 = local_4e4 + 1;
      } while (local_4e4 < local_408[1]);
    }
    *(undefined4 *)local_4fc = uVar11;
    *(undefined4 *)(local_4fc + 4) = uVar2;
    *(int *)(param_1 + 300) = local_4e4;
    box_smooth_process(uVar13,*(undefined4 *)local_4fc,*(undefined4 *)(local_4fc + 4),
                       (vector<ax_track_box_t,std::allocator<ax_track_box_t>> *)&local_3f8,
                       &local_3e8);
    if (0 < local_3e4 - (int)local_3e8) {
      iVar4 = *(int *)(param_1 + 0x128);
      iVar12 = 0;
      pvVar8 = local_3e8;
      while( true ) {
        iVar12 = iVar12 + 1;
        *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)((int)pvVar8 + 4);
        *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)((int)pvVar8 + 8);
        *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)((int)pvVar8 + 0xc);
        *(undefined4 *)(iVar4 + 0x20) = *(undefined4 *)((int)pvVar8 + 0x10);
        if ((local_3e4 - (int)local_3e8 >> 2) * -0x33333333 <= iVar12) break;
        iVar4 = iVar4 + 0x3c;
        pvVar8 = (void *)((int)pvVar8 + 0x14);
      }
    }
    if (local_3e8 != (void *)0x0) {
      operator_delete(local_3e8);
    }
    if (local_3f8 != (void *)0x0) {
      operator_delete(local_3f8);
    }
    bVar31 = true;
  } while( true );
LAB_0001abe0:
  iVar30 = local_4e8 * 0x10;
  iVar12 = *(int *)((int)local_430 + iVar30);
  iVar23 = *(int *)((int)local_430 + iVar30 + 4);
  iVar30 = *(int *)((int)local_430 + iVar30 + 8);
  pthread_mutex_lock(__mutex);
  prVar22 = *(retina_t **)(param_1 + 0xc0);
  if (*(int *)(param_1 + 0x10) != 0) {
    prVar22 = *(retina_t **)(param_1 + 0xc4);
  }
  pthread_mutex_unlock(__mutex);
  if (prVar22 != (retina_t *)0x0) {
    local_458 = 0;
    nnyuv2axyuv((nn_yuv_t *)&local_490);
    local_20c = local_490;
    local_208 = uStack_48c;
    local_204 = uStack_488;
    local_200 = uStack_484;
    local_1fc = local_480;
    uStack_1f8 = uStack_47c;
    local_1ec = local_470;
    local_410 = (int)(longlong)((double)(longlong)(iVar30 - iVar12) * 1.2);
    local_1d8 = 0x3f59999a;
    local_44 = 0x3f400000;
    local_418 = (int *)((iVar30 + iVar12) / 2 - local_410 / 2);
    local_450 = uStack_478;
    uStack_44c = uStack_474;
    local_1d4 = 0x3f59999a;
    local_48 = 0x3eb33333;
    local_414 = (int)(longlong)((double)(longlong)iVar23 + -(double)(longlong)local_410 * 0.1);
    clip_rect_adaptive<ax_rect_t,ax_size_t>
              (&local_4a0,local_418,local_414,local_410,local_410,uStack_478,uStack_474);
    iVar12 = iStack_494;
    iVar23 = iStack_498;
    iVar30 = iStack_49c;
    piVar29 = local_4a0;
    local_418 = local_4a0;
    local_414 = iStack_49c;
    local_410 = iStack_498;
    iStack_40c = iStack_494;
    local_1e8 = local_4a0;
    local_1e4 = iStack_49c;
    local_1e0 = iStack_498;
    local_1dc = iStack_494;
    retina_process(prVar22,(retina_in_t *)&local_20c,(retina_out_t *)&local_458);
    iVar4 = local_458._4_4_[1];
    paVar1 = local_460._4_4_;
    local_400 = (int)piVar29 + iVar23 + -1;
    iVar23 = *(int *)((int)(int *)local_458 + 4);
    iStack_3fc = iVar12 + iVar30 + -1;
    puVar15 = (int *)local_460;
    local_408 = piVar29;
    iStack_404 = iVar30;
    if (0 < iVar4) {
      local_508 = 0;
      do {
        iVar26 = *local_458._4_4_;
        iVar12 = local_508 * 0x1c;
        paVar32 = (ax_detect_box_t *)(iVar26 + iVar12);
        local_3f8 = *(void **)(iVar26 + iVar12);
        local_3f0 = *(undefined4 **)(paVar32 + 8);
        local_3ec = *(undefined4 *)(paVar32 + 0xc);
        local_3f4 = *(undefined4 **)(paVar32 + 4);
        iVar30 = FUN_00016018(0x3d4ccccd,&local_3f8,&local_408);
        if (iVar30 != 1) {
          if (*(int *)(paVar1 + 4) < 1) {
LAB_0001b144:
            AX_ARRAY_PUSH_BACK<ax_detect_box_array_t,ax_detect_box_t>(paVar1,paVar32);
          }
          else {
            iVar26 = *(int *)(iVar26 + iVar12);
            iVar30 = -1;
            iVar33 = *(int *)(paVar32 + 8);
            iVar12 = 0;
            iVar37 = *(int *)(paVar32 + 0xc);
            iVar35 = *(int *)(paVar32 + 4);
            fVar39 = 0.0;
            fVar38 = (float)(longlong)(((iVar37 - iVar35) + 1) * ((iVar33 - iVar26) + 1));
            piVar29 = *(int **)paVar1;
            fVar45 = fVar39;
            do {
              iVar5 = *piVar29;
              iVar6 = piVar29[1];
              iVar9 = piVar29[2];
              iVar17 = piVar29[3];
              piVar29 = piVar29 + 7;
              iVar34 = iVar26;
              if (iVar26 <= iVar5) {
                iVar34 = iVar5;
              }
              iVar18 = iVar35;
              if (iVar35 <= iVar6) {
                iVar18 = iVar6;
              }
              iVar42 = iVar9;
              if (iVar33 < iVar9) {
                iVar42 = iVar33;
              }
              iVar40 = iVar17;
              if (iVar37 < iVar17) {
                iVar40 = iVar37;
              }
              uVar24 = (uint)(((float)(longlong)iVar42 - (float)(longlong)iVar34) + 1.0);
              uVar28 = (uint)(((float)(longlong)iVar40 - (float)(longlong)iVar18) + 1.0);
              if ((int)(uVar24 | uVar28) < 0) {
                fVar44 = 0.0;
              }
              else {
                fVar44 = (float)(longlong)(int)uVar24 * (float)(longlong)(int)uVar28;
              }
              fVar43 = fVar44 / fVar38;
              fVar44 = fVar44 / (((float)(longlong)(((iVar17 - iVar6) + 1) * ((iVar9 - iVar5) + 1))
                                 + fVar38) - fVar44);
              if (fVar44 != fVar39 && fVar44 < fVar39 == (NAN(fVar44) || NAN(fVar39))) {
                iVar30 = iVar12;
                fVar39 = fVar44;
              }
              iVar12 = iVar12 + 1;
              if (fVar43 != fVar45 && fVar43 < fVar45 == (NAN(fVar43) || NAN(fVar45))) {
                fVar45 = fVar43;
              }
            } while (iVar12 != *(int *)(paVar1 + 4));
            if ((int)((uint)(fVar39 < 0.35) << 0x1f) < 0) {
              if ((int)((uint)(fVar45 < 0.5) << 0x1f) < 0) goto LAB_0001b144;
            }
            else if ((iVar30 != -1) &&
                    (piVar29 = *(int **)paVar1 + iVar30 * 7,
                    (int)((uint)((float)piVar29[6] < *(float *)(paVar32 + 0x18)) << 0x1f) < 0)) {
              iVar30 = *(int *)(paVar32 + 4);
              iVar12 = *(int *)(paVar32 + 8);
              iVar26 = *(int *)(paVar32 + 0xc);
              *piVar29 = *(int *)paVar32;
              piVar29[1] = iVar30;
              piVar29[2] = iVar12;
              piVar29[3] = iVar26;
              iVar30 = *(int *)(paVar32 + 0x14);
              iVar12 = *(int *)(paVar32 + 0x18);
              piVar29[4] = *(int *)(paVar32 + 0x10);
              piVar29[5] = iVar30;
              piVar29[6] = iVar12;
            }
          }
        }
        local_508 = local_508 + 1;
        if (iVar4 == local_508) break;
      } while( true );
    }
    if (0 < iVar23) {
      iVar30 = 0;
      do {
        iVar4 = iVar30 * 0x3c;
        iVar26 = *(int *)local_458;
        piVar29 = (int *)(iVar26 + iVar4);
        local_3e8 = *(void **)(iVar26 + iVar4);
        local_3e0 = piVar29[2];
        iStack_3dc = piVar29[3];
        local_3e4 = piVar29[1];
        iVar12 = FUN_00016018(0x3c23d70a,&local_3e8,&local_408);
        if (iVar12 != 1) {
          iVar12 = puVar15[1];
          local_500 = (int *)*puVar15;
          if (0 < iVar12) {
            iVar37 = *(int *)(iVar26 + iVar4);
            iVar4 = -1;
            iVar34 = piVar29[2];
            iVar26 = 0;
            iVar33 = piVar29[1];
            iVar35 = piVar29[3];
            fVar39 = 0.0;
            piVar20 = local_500;
            do {
              iVar6 = *piVar20;
              iVar9 = piVar20[1];
              iVar17 = piVar20[2];
              iVar18 = piVar20[3];
              piVar20 = piVar20 + 0xf;
              iVar5 = iVar37;
              if (iVar37 <= iVar6) {
                iVar5 = iVar6;
              }
              iVar42 = iVar33;
              if (iVar33 <= iVar9) {
                iVar42 = iVar9;
              }
              iVar40 = iVar17;
              if (iVar34 < iVar17) {
                iVar40 = iVar34;
              }
              iVar41 = iVar18;
              if (iVar35 < iVar18) {
                iVar41 = iVar35;
              }
              uVar24 = (uint)(((float)(longlong)iVar40 - (float)(longlong)iVar5) + 1.0);
              uVar28 = (uint)(((float)(longlong)iVar41 - (float)(longlong)iVar42) + 1.0);
              if ((int)(uVar24 | uVar28) < 0) {
                fVar45 = 0.0;
              }
              else {
                fVar45 = (float)(longlong)(int)uVar24 * (float)(longlong)(int)uVar28;
              }
              fVar45 = fVar45 / (((float)(longlong)(((iVar18 - iVar9) + 1) * ((iVar17 - iVar6) + 1))
                                 + (float)(longlong)
                                          (((iVar35 - iVar33) + 1) * ((iVar34 - iVar37) + 1))) -
                                fVar45);
              if ((int)((uint)(fVar39 < fVar45) << 0x1f) < 0) {
                iVar4 = iVar26;
                fVar39 = fVar45;
              }
              iVar26 = iVar26 + 1;
            } while (iVar26 != iVar12);
            if (-1 < (int)((uint)(fVar39 < 0.35) << 0x1f)) {
              if ((iVar4 != -1) &&
                 (local_500 = local_500 + iVar4 * 0xf,
                 (int)((uint)((float)local_500[4] < (float)piVar29[4]) << 0x1f) < 0)) {
                iVar12 = piVar29[1];
                iVar4 = piVar29[2];
                iVar26 = piVar29[3];
                *local_500 = *piVar29;
                local_500[1] = iVar12;
                local_500[2] = iVar4;
                local_500[3] = iVar26;
                iVar12 = piVar29[5];
                iVar4 = piVar29[6];
                iVar26 = piVar29[7];
                local_500[4] = piVar29[4];
                local_500[5] = iVar12;
                local_500[6] = iVar4;
                local_500[7] = iVar26;
                iVar12 = piVar29[9];
                iVar4 = piVar29[10];
                iVar26 = piVar29[0xb];
                local_500[8] = piVar29[8];
                local_500[9] = iVar12;
                local_500[10] = iVar4;
                local_500[0xb] = iVar26;
                iVar12 = piVar29[0xd];
                iVar4 = piVar29[0xe];
                local_500[0xc] = piVar29[0xc];
                local_500[0xd] = iVar12;
                local_500[0xe] = iVar4;
              }
              goto LAB_0001b076;
            }
          }
          iVar4 = iVar12 + 1;
          if (local_500 == (int *)0x0) {
            if (0 < iVar4 * 0x3c) {
              sVar27 = 0;
              goto LAB_0001b0f6;
            }
          }
          else {
            sVar27 = local_500[-1];
            if ((int)(sVar27 + iVar4 * -0x3c) < 0 != SBORROW4(sVar27,iVar4 * 0x3c)) {
LAB_0001b0f6:
              local_500 = (int *)AX_MALLOC_RECORD(iVar4 * 0x78);
              if ((void *)*puVar15 != (void *)0x0) {
                memcpy(local_500,(void *)*puVar15,sVar27);
                AX_FREE_RECORD((void *)*puVar15);
              }
              iVar12 = puVar15[1];
              *puVar15 = local_500;
            }
          }
          local_500 = local_500 + iVar12 * 0xf;
          iVar12 = piVar29[1];
          iVar26 = piVar29[2];
          iVar33 = piVar29[3];
          *local_500 = *piVar29;
          local_500[1] = iVar12;
          local_500[2] = iVar26;
          local_500[3] = iVar33;
          iVar12 = piVar29[5];
          iVar26 = piVar29[6];
          iVar33 = piVar29[7];
          local_500[4] = piVar29[4];
          local_500[5] = iVar12;
          local_500[6] = iVar26;
          local_500[7] = iVar33;
          iVar12 = piVar29[9];
          iVar26 = piVar29[10];
          iVar33 = piVar29[0xb];
          local_500[8] = piVar29[8];
          local_500[9] = iVar12;
          local_500[10] = iVar26;
          local_500[0xb] = iVar33;
          iVar12 = piVar29[0xd];
          iVar26 = piVar29[0xe];
          local_500[0xc] = piVar29[0xc];
          local_500[0xd] = iVar12;
          local_500[0xe] = iVar26;
          puVar15[1] = iVar4;
        }
LAB_0001b076:
        iVar30 = iVar30 + 1;
      } while (iVar23 != iVar30);
    }
  }
  local_4e8 = local_4e8 + 1;
  if (0 < (int)local_4e8) goto LAB_0001a8d8;
  if ((uint)((int)local_42c - (int)local_430 >> 4) <= local_4e8) {
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",local_4e8
              );
  }
  goto LAB_0001abe0;
LAB_0001a8d8:
  local_4fc = (retina_in_t *)&local_20c;
  if (local_424 != (void *)0x0) {
    operator_delete(local_424);
  }
  goto LAB_0001a8e2;
}



/* void std::vector<ax_rect_t, std::allocator<ax_rect_t> >::_M_realloc_insert<ax_rect_t
   const&>(__gnu_cxx::__normal_iterator<ax_rect_t*, std::vector<ax_rect_t, std::allocator<ax_rect_t>
   > >, ax_rect_t const&) */

void __thiscall
std::vector<ax_rect_t,std::allocator<ax_rect_t>>::_M_realloc_insert<ax_rect_t_const&>
          (vector<ax_rect_t,std::allocator<ax_rect_t>> *this,void *param_2,undefined4 *param_3)

{
  void *__dest;
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *__dest_00;
  size_t __n;
  void *__src;
  uint uVar5;
  int iVar6;
  void *pvVar7;
  size_t sVar8;
  undefined4 *puVar9;
  
  __src = *(void **)this;
  pvVar7 = *(void **)(this + 4);
  sVar8 = (int)param_2 - (int)__src;
  uVar2 = (int)pvVar7 - (int)__src >> 4;
  if (uVar2 == 0) {
    uVar5 = 1;
LAB_0001b518:
    uVar5 = uVar5 << 4;
  }
  else {
    uVar5 = uVar2 * 2;
    if ((uVar2 <= uVar5) && (uVar5 < 0x10000000)) {
      if (uVar5 == 0) {
        iVar6 = 0;
        __dest = (void *)0x0;
        __n = sVar8;
        goto LAB_0001b4c8;
      }
      goto LAB_0001b518;
    }
    uVar5 = 0xfffffff0;
  }
  __dest = operator_new(uVar5);
  __src = *(void **)this;
  iVar6 = uVar5 + (int)__dest;
  pvVar7 = *(void **)(this + 4);
  __n = (int)param_2 - (int)__src;
LAB_0001b4c8:
  puVar9 = (undefined4 *)((int)__dest + sVar8);
  if (puVar9 != (undefined4 *)0x0) {
    uVar1 = param_3[1];
    uVar3 = param_3[2];
    uVar4 = param_3[3];
    *puVar9 = *param_3;
    puVar9[1] = uVar1;
    puVar9[2] = uVar3;
    puVar9[3] = uVar4;
  }
  if (param_2 != __src) {
    memmove(__dest,__src,__n);
  }
  __dest_00 = (void *)(__n + 0x10 + (int)__dest);
  if (pvVar7 != param_2) {
    __dest_00 = memcpy(__dest_00,param_2,(int)pvVar7 - (int)param_2);
  }
  if (__src != (void *)0x0) {
    operator_delete(__src);
  }
  *(void **)this = __dest;
  *(int *)(this + 4) = (int)__dest_00 + ((int)pvVar7 - (int)param_2);
  *(int *)(this + 8) = iVar6;
  return;
}



/* __gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >
   std::__find_if<__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >,
   __gnu_cxx::__ops::_Iter_equals_val<int const> >(__gnu_cxx::__normal_iterator<int*,
   std::vector<int, std::allocator<int> > >, __gnu_cxx::__normal_iterator<int*, std::vector<int,
   std::allocator<int> > >, __gnu_cxx::__ops::_Iter_equals_val<int const>,
   std::random_access_iterator_tag) */

int * std::
      __find_if<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,__gnu_cxx::__ops::_Iter_equals_val<int_const>>
                (int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  iVar1 = (int)param_2 - (int)param_1;
  if (0 < iVar1 >> 4) {
    iVar2 = *param_3;
    if (iVar2 == *param_1) {
      return param_1;
    }
    if (iVar2 == param_1[1]) {
      return param_1 + 1;
    }
    if (iVar2 == param_1[2]) {
      return param_1 + 2;
    }
    if (iVar2 == param_1[3]) {
      return param_1 + 3;
    }
    piVar4 = param_1 + (iVar1 >> 4) * 4;
    while (piVar3 = param_1, param_1 = piVar3 + 4, param_1 != piVar4) {
      if (iVar2 == piVar3[4]) {
        return param_1;
      }
      if (iVar2 == piVar3[5]) {
        return piVar3 + 5;
      }
      if (iVar2 == piVar3[6]) {
        return piVar3 + 6;
      }
      if (iVar2 == piVar3[7]) {
        return piVar3 + 7;
      }
    }
    iVar1 = (int)param_2 - (int)piVar4;
  }
  iVar1 = iVar1 >> 2;
  if (iVar1 == 2) {
    iVar1 = *param_3;
  }
  else {
    if (iVar1 != 3) {
      if (iVar1 != 1) {
        return param_2;
      }
      iVar1 = *param_3;
      goto LAB_0001b59c;
    }
    iVar1 = *param_3;
    if (*param_1 == iVar1) {
      return param_1;
    }
    param_1 = param_1 + 1;
  }
  if (iVar1 == *param_1) {
    return param_1;
  }
  param_1 = param_1 + 1;
LAB_0001b59c:
  if (iVar1 != *param_1) {
    param_1 = param_2;
  }
  return param_1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* void std::__insertion_sort<__gnu_cxx::__normal_iterator<int*, std::vector<int,
   std::allocator<int> > >, __gnu_cxx::__ops::_Iter_comp_iter<bool (*)(int, int)>
   >(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >,
   __gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >,
   __gnu_cxx::__ops::_Iter_comp_iter<bool (*)(int, int)>) */

void std::
     __insertion_sort<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
               (undefined4 *param_1,undefined4 *param_2,code *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  if ((param_1 == param_2) || (param_2 == param_1 + 1)) {
    return;
  }
  puVar6 = param_1 + 1;
  do {
    while( true ) {
      puVar4 = puVar6 + 1;
      iVar3 = (*param_3)(*puVar6,*param_1);
      uVar5 = *puVar6;
      if (iVar3 == 0) break;
      if (param_1 != puVar6) {
        memmove((void *)((int)param_1 + (8 - (int)puVar4) + (int)puVar6),param_1,
                (-4 - (int)param_1) + (int)puVar4);
      }
      *param_1 = uVar5;
      puVar6 = puVar4;
      if (param_2 == puVar4) {
        return;
      }
    }
    iVar3 = (*param_3)(uVar5,puVar6[-1]);
    puVar2 = puVar6 + -1;
    while (puVar1 = puVar2, iVar3 != 0) {
      puVar1[1] = *puVar1;
      iVar3 = (*param_3)(uVar5,puVar1[-1]);
      puVar2 = puVar1 + -1;
      puVar6 = puVar1;
    }
    *puVar6 = uVar5;
    puVar6 = puVar4;
  } while (param_2 != puVar4);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* void std::__unguarded_linear_insert<__gnu_cxx::__normal_iterator<ax_rect_t*,
   std::vector<ax_rect_t, std::allocator<ax_rect_t> > >, __gnu_cxx::__ops::_Val_comp_iter<bool
   (*)(ax_rect_t, ax_rect_t)> >(__gnu_cxx::__normal_iterator<ax_rect_t*, std::vector<ax_rect_t,
   std::allocator<ax_rect_t> > >, __gnu_cxx::__ops::_Val_comp_iter<bool (*)(ax_rect_t, ax_rect_t)>)
    */

void std::
     __unguarded_linear_insert<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,__gnu_cxx::__ops::_Val_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
               (undefined4 *param_1,code *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  
  uVar2 = *param_1;
  uVar4 = param_1[1];
  uVar5 = param_1[2];
  uVar6 = param_1[3];
  puVar1 = param_1 + -4;
  while( true ) {
    puVar7 = puVar1;
    iVar3 = (*param_2)(uVar2,uVar4,uVar5,uVar6,*puVar7,puVar7[1],puVar7[2],puVar7[3]);
    if (iVar3 == 0) break;
    puVar7[4] = *puVar7;
    puVar7[5] = puVar7[1];
    puVar7[6] = puVar7[2];
    puVar7[7] = puVar7[3];
    puVar1 = puVar7 + -4;
    param_1 = puVar7;
  }
  *param_1 = uVar2;
  param_1[1] = uVar4;
  param_1[2] = uVar5;
  param_1[3] = uVar6;
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* void std::__insertion_sort<__gnu_cxx::__normal_iterator<ax_rect_t*, std::vector<ax_rect_t,
   std::allocator<ax_rect_t> > >, __gnu_cxx::__ops::_Iter_comp_iter<bool (*)(ax_rect_t, ax_rect_t)>
   >(__gnu_cxx::__normal_iterator<ax_rect_t*, std::vector<ax_rect_t, std::allocator<ax_rect_t> > >,
   __gnu_cxx::__normal_iterator<ax_rect_t*, std::vector<ax_rect_t, std::allocator<ax_rect_t> > >,
   __gnu_cxx::__ops::_Iter_comp_iter<bool (*)(ax_rect_t, ax_rect_t)>) */

void std::
     __insertion_sort<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
               (undefined4 *param_1,undefined4 *param_2,code *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  size_t __n;
  
  if (param_1 == param_2) {
    return;
  }
  if (param_1 + 4 != param_2) {
    __n = 0x10;
    puVar7 = param_1 + 4;
    do {
      while( true ) {
        iVar2 = (*param_3)(*puVar7,puVar7[1],puVar7[2],puVar7[3],*param_1,param_1[1],param_1[2],
                           param_1[3]);
        puVar6 = (undefined4 *)((int)param_1 + __n);
        if (iVar2 != 0) break;
        puVar6 = puVar7 + 4;
        __unguarded_linear_insert<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,__gnu_cxx::__ops::_Val_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
                  (puVar7,param_3);
        __n = __n + 0x10;
        puVar7 = puVar6;
        if (param_2 == puVar6) {
          return;
        }
      }
      uVar1 = *puVar6;
      uVar3 = puVar6[1];
      uVar4 = puVar6[2];
      uVar5 = puVar6[3];
      if (param_1 != puVar7) {
        memmove((void *)((int)puVar7 + (0x10 - __n)),param_1,__n);
      }
      puVar7 = puVar7 + 4;
      __n = __n + 0x10;
      *param_1 = uVar1;
      param_1[1] = uVar3;
      param_1[2] = uVar4;
      param_1[3] = uVar5;
    } while (param_2 != puVar7);
  }
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* void std::__adjust_heap<__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> >
   >, int, int, __gnu_cxx::__ops::_Iter_comp_iter<bool (*)(int, int)>
   >(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int, int, int,
   __gnu_cxx::__ops::_Iter_comp_iter<bool (*)(int, int)>) */

void std::
     __adjust_heap<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,int,int,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
               (int param_1,int param_2,uint param_3,undefined4 param_4,code *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  iVar3 = (int)(param_3 - 1) / 2;
  iVar7 = param_2;
  if (param_2 < iVar3) {
    do {
      iVar4 = iVar7 + 1;
      iVar6 = iVar4 * 2 + -1;
      iVar2 = (*param_5)(*(undefined4 *)(param_1 + iVar4 * 8),*(undefined4 *)(param_1 + iVar6 * 4));
      iVar1 = iVar6 * 4;
      if (iVar2 == 0) {
        iVar1 = iVar4 * 8;
      }
      puVar5 = (undefined4 *)(param_1 + iVar1);
      if (iVar2 == 0) {
        iVar6 = iVar4 * 2;
      }
      *(undefined4 *)(param_1 + iVar7 * 4) = *puVar5;
      iVar7 = iVar6;
    } while (iVar6 < iVar3);
    iVar3 = iVar6;
    if ((param_3 & 1) == 0) goto LAB_0001b792;
  }
  else {
    puVar5 = (undefined4 *)(param_1 + param_2 * 4);
    iVar3 = param_2;
    if ((param_3 & 1) != 0) goto LAB_0001b7fc;
LAB_0001b792:
    if (iVar3 == (int)(param_3 - 2) / 2) {
      iVar6 = iVar3 * 2 + 1;
      puVar5 = (undefined4 *)(param_1 + iVar6 * 4);
      *(undefined4 *)(param_1 + iVar3 * 4) = *(undefined4 *)(param_1 + iVar6 * 4);
    }
    else {
      puVar5 = (undefined4 *)(param_1 + iVar3 * 4);
      iVar6 = iVar3;
    }
  }
  if (param_2 < iVar6) {
    while( true ) {
      iVar7 = (iVar6 + -1) / 2;
      iVar3 = (*param_5)(*(undefined4 *)(param_1 + iVar7 * 4),param_4);
      puVar5 = (undefined4 *)(param_1 + iVar6 * 4);
      if (iVar3 == 0) break;
      *(undefined4 *)(param_1 + iVar6 * 4) = *(undefined4 *)(param_1 + iVar7 * 4);
      iVar6 = iVar7;
      if (iVar7 <= param_2) {
        *(undefined4 *)(param_1 + iVar7 * 4) = param_4;
        return;
      }
    }
  }
LAB_0001b7fc:
  *puVar5 = param_4;
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* void std::__introsort_loop<__gnu_cxx::__normal_iterator<int*, std::vector<int,
   std::allocator<int> > >, int, __gnu_cxx::__ops::_Iter_comp_iter<bool (*)(int, int)>
   >(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >,
   __gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int,
   __gnu_cxx::__ops::_Iter_comp_iter<bool (*)(int, int)>) */

void std::
     __introsort_loop<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,int,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
               (undefined4 *param_1,undefined4 *param_2,int param_3,code *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  iVar2 = (int)param_2 - (int)param_1;
  if (0x40 < iVar2) {
    if (param_3 != 0) {
      puVar3 = param_1 + 1;
      puVar6 = param_2;
LAB_0001b842:
      param_3 = param_3 + -1;
      iVar5 = ((int)puVar6 - (int)param_1 >> 2) - ((int)puVar6 - (int)param_1 >> 0x1f) >> 1;
      iVar2 = (*param_4)(param_1[1],param_1[iVar5]);
      param_2 = puVar3;
      puVar7 = puVar6;
      if (iVar2 == 0) {
        iVar2 = (*param_4)(param_1[1],puVar6[-1]);
        if (iVar2 == 0) {
          iVar2 = (*param_4)(param_1[iVar5],puVar6[-1]);
          uVar4 = *param_1;
          if (iVar2 != 0) goto LAB_0001b878;
          goto LAB_0001b930;
        }
      }
      else {
        iVar2 = (*param_4)(param_1[iVar5]);
        if (iVar2 != 0) {
          uVar4 = *param_1;
LAB_0001b930:
          *param_1 = param_1[iVar5];
          param_1[iVar5] = uVar4;
          uVar1 = *param_1;
          uVar4 = param_1[1];
          goto LAB_0001b88a;
        }
        iVar2 = (*param_4)(param_1[1],puVar6[-1]);
        if (iVar2 != 0) {
          uVar4 = *param_1;
LAB_0001b878:
          *param_1 = puVar6[-1];
          puVar6[-1] = uVar4;
          uVar1 = *param_1;
          uVar4 = param_1[1];
          goto LAB_0001b88a;
        }
      }
      uVar4 = *param_1;
      uVar1 = param_1[1];
      *param_1 = uVar1;
      param_1[1] = uVar4;
LAB_0001b88a:
      do {
        iVar2 = (*param_4)(uVar4,uVar1);
        if (iVar2 == 0) {
          do {
            puVar7 = puVar7 + -1;
            iVar2 = (*param_4)(*param_1,*puVar7);
          } while (iVar2 != 0);
          if (puVar7 <= param_2) goto LAB_0001b8ba;
          uVar4 = *param_2;
          *param_2 = *puVar7;
          *puVar7 = uVar4;
        }
        uVar4 = param_2[1];
        uVar1 = *param_1;
        param_2 = param_2 + 1;
      } while( true );
    }
LAB_0001b8d4:
    iVar5 = (iVar2 >> 2) + -2 >> 1;
    puVar6 = param_1 + iVar5;
    while( true ) {
      __adjust_heap<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,int,int,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
                (param_1,iVar5,iVar2 >> 2,*puVar6,param_4);
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      puVar6 = puVar6 + -1;
    }
    do {
      param_2 = param_2 + -1;
      uVar4 = *param_2;
      *param_2 = *param_1;
      __adjust_heap<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,int,int,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
                (param_1,0,(int)param_2 - (int)param_1 >> 2,uVar4,param_4);
    } while (4 < (int)param_2 - (int)param_1);
  }
  return;
LAB_0001b8ba:
  __introsort_loop<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,int,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
            (param_2,puVar6,param_3,param_4);
  iVar2 = (int)param_2 - (int)param_1;
  if (iVar2 < 0x41) {
    return;
  }
  puVar6 = param_2;
  if (param_3 == 0) goto LAB_0001b8d4;
  goto LAB_0001b842;
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_0001b954(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *piVar10;
  retina_t *prVar11;
  undefined4 uVar12;
  int *piVar13;
  int *piVar14;
  int iVar15;
  int iVar16;
  undefined8 uVar17;
  int *local_264;
  int local_260;
  retina_out_t arStack_25c [4];
  int *local_258;
  undefined4 local_254;
  undefined4 uStack_250;
  void *local_24c;
  undefined4 *local_248;
  undefined4 *local_244;
  void *local_240;
  int local_23c;
  undefined4 local_238;
  int *local_234;
  int *local_230;
  int *local_22c;
  int local_228;
  int local_224;
  undefined4 local_220;
  undefined4 uStack_21c;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined4 local_210;
  undefined4 uStack_20c;
  undefined4 uStack_208;
  undefined4 uStack_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 uStack_1f8;
  undefined4 uStack_1f4;
  undefined4 uStack_1f0;
  undefined4 local_1ec;
  undefined4 uStack_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 uStack_1d4;
  undefined4 local_1d0;
  undefined4 uStack_1cc;
  undefined4 local_1c8;
  undefined4 local_38;
  undefined4 local_34;
  
  if (DAT_0003a674 << 0x1a < 0) {
    __android_log_print(6,"CAMPAN","");
  }
  iVar15 = *(int *)(param_1 + 0x108);
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x1cc));
  prVar11 = *(retina_t **)(param_1 + 0xa4);
  puVar9 = *(undefined4 **)(param_1 + 0x14);
  if (*(int *)(param_1 + 0x10) != 0) {
    prVar11 = *(retina_t **)(param_1 + 0xa8);
    puVar9 = *(undefined4 **)(param_1 + 0x24);
  }
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x1cc));
  if (((prVar11 == (retina_t *)0x0) || (*(int *)(iVar15 + 0x1c) == 0)) || (param_2[7] == 0)) {
    *(undefined4 *)(param_1 + 0x114) = 0;
  }
  else {
    nnyuv2axyuv((nn_yuv_t *)&local_220);
    local_34 = 0x3f800000;
    local_1fc = local_220;
    uStack_1f8 = uStack_21c;
    uStack_1f4 = uStack_218;
    uStack_1f0 = uStack_214;
    local_1ec = local_210;
    uStack_1e8 = uStack_20c;
    uStack_1e4 = uStack_208;
    uStack_1e0 = uStack_204;
    local_1d0 = *param_2;
    uStack_1cc = param_2[1];
    local_1d8 = 0;
    uStack_1d4 = 0;
    local_1dc = local_200;
    local_38 = 0x3ecccccd;
    local_1c8 = 0x3ecccccd;
    get_time_ms();
    retina_process(prVar11,(retina_in_t *)&local_1fc,arStack_25c);
    get_time_ms();
    uVar5 = param_2[3];
    uVar12 = *param_2;
    *(undefined4 *)(param_1 + 0x40) = param_2[1];
    iVar3 = local_258[1];
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x8c);
    *(undefined4 *)(param_1 + 0x38) = uVar5;
    *(undefined4 *)(param_1 + 0x3c) = uVar12;
    FUN_0001624c(param_1 + 0x54,param_1 + 0x58,iVar3);
    iVar3 = local_258[1];
    if (0 < iVar3) {
      local_258 = (int *)*local_258;
      piVar1 = local_258;
      piVar8 = *(int **)(param_1 + 0x54);
      do {
        iVar6 = *piVar1;
        piVar10 = piVar1 + 7;
        iVar16 = piVar1[6];
        *piVar8 = iVar6;
        iVar2 = piVar1[1];
        piVar8[1] = iVar2;
        piVar8[2] = (piVar1[2] - iVar6) + 1;
        iVar6 = piVar1[3];
        piVar8[4] = iVar16;
        piVar8[3] = (iVar6 - iVar2) + 1;
        piVar1 = piVar10;
        piVar8 = piVar8 + 5;
      } while (local_258 + iVar3 * 7 != piVar10);
    }
    *puVar9 = 0x3e8f5c29;
    uVar5 = *(undefined4 *)(iVar15 + 0x18);
    puVar9[1] = 3;
    puVar9[5] = 1;
    puVar9[7] = 1;
    puVar9[10] = 1;
    puVar9[0xb] = 1;
    puVar9[0xc] = 0x3ecccccd;
    puVar9[6] = uVar5;
    puVar9[0xd] = 0x3e99999a;
    puVar9[3] = 0x30;
    iVar3 = *(int *)(param_1 + 0x278);
    puVar9[0x10] = 1;
    puVar9[2] = (uint)(iVar3 != 0);
    puVar9[8] = 0x3ee66666;
    puVar9[0x11] = 0x3e4ccccd;
    puVar9[0x12] = 0x3f800000;
    puVar9[9] = 0;
    dtbased_tk_update(puVar9,param_1 + 0x34,&local_264);
    get_time_ms();
    iVar3 = local_264[1];
    AX_MALLOC_INC_TEMP<nn_campan_persons_t>((nn_campan_persons_t *)(param_1 + 0x110),iVar3);
    memset(*(void **)(param_1 + 0x110),0,iVar3 * 0x2a8);
    uVar5 = *(undefined4 *)(param_1 + 0x90);
    local_24c = (void *)0x0;
    local_248 = (undefined4 *)0x0;
    local_244 = (undefined4 *)0x0;
    local_240 = (void *)0x0;
    local_23c = 0;
    local_238 = 0;
    uVar17 = get_time_ms();
    if (0 < iVar3) {
      iVar2 = 0;
      do {
        while( true ) {
          local_234 = *(int **)(*local_264 + iVar2 * 0x20);
          iVar16 = iVar2 * 0x20 + *local_264;
          iVar6 = *(int *)(param_1 + 0x110);
          *(int **)(iVar6 + iVar2 * 0x2a8) = local_234;
          iVar6 = iVar2 * 0x2a8 + iVar6;
          uVar12 = *(undefined4 *)(iVar16 + 0x14);
          *(undefined8 *)(iVar6 + 0x28) = uVar17;
          *(undefined4 *)(iVar6 + 0x24) = uVar12;
          local_230 = *(int **)(iVar16 + 4);
          *(int **)(iVar6 + 4) = local_230;
          local_22c = *(int **)(iVar16 + 8);
          *(int **)(iVar6 + 8) = local_22c;
          local_228 = *(int *)(iVar16 + 4) + *(int *)(iVar16 + 0xc) + -1;
          *(int *)(iVar6 + 0xc) = local_228;
          local_224 = *(int *)(iVar16 + 8) + *(int *)(iVar16 + 0x10) + -1;
          *(int *)(iVar6 + 0x10) = local_224;
          if (local_248 != local_244) break;
          std::vector<ax_track_box_t,std::allocator<ax_track_box_t>>::
          _M_realloc_insert<ax_track_box_t_const&>
                    ((vector<ax_track_box_t,std::allocator<ax_track_box_t>> *)&local_24c,local_248,
                     &local_234);
          iVar2 = iVar2 + 1;
          if (iVar3 == iVar2) goto LAB_0001bbee;
        }
        if (local_248 != (undefined4 *)0x0) {
          *local_248 = local_234;
          local_248[1] = local_230;
          local_248[2] = local_22c;
          local_248[3] = local_228;
          local_248[4] = local_224;
        }
        local_248 = local_248 + 5;
        iVar2 = iVar2 + 1;
      } while (iVar3 != iVar2);
    }
LAB_0001bbee:
    uStack_250 = param_2[1];
    local_254 = *param_2;
    box_smooth_process(uVar5,local_254,uStack_250,
                       (vector<ax_track_box_t,std::allocator<ax_track_box_t>> *)&local_24c,
                       &local_240);
    if (0 < local_23c - (int)local_240) {
      iVar2 = *(int *)(param_1 + 0x110);
      iVar3 = 0;
      pvVar4 = local_240;
      while( true ) {
        iVar3 = iVar3 + 1;
        *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)((int)pvVar4 + 4);
        *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)((int)pvVar4 + 8);
        *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)((int)pvVar4 + 0xc);
        *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)((int)pvVar4 + 0x10);
        if ((local_23c - (int)local_240 >> 2) * -0x33333333 <= iVar3) break;
        pvVar4 = (void *)((int)pvVar4 + 0x14);
        iVar2 = iVar3 * 0x2a8 + *(int *)(param_1 + 0x110);
      }
    }
    if (0 < *(int *)(param_1 + 0x114)) {
      iVar3 = 0;
      do {
        iVar2 = iVar3 * 0x2a8;
        iVar3 = iVar3 + 1;
        *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x110) + 0x140) = 0;
        iVar2 = *(int *)(param_1 + 0x114);
      } while (iVar3 < iVar2);
      if ((0 < iVar2) && (*(int *)(iVar15 + 0x30) != 0)) {
        local_234 = (int *)0x0;
        local_230 = (int *)0x0;
        local_22c = (int *)0x0;
        iVar15 = 0;
        do {
          iVar3 = iVar15 * 0x2a8 + *(int *)(param_1 + 0x110);
          local_260 = (*(int *)(iVar3 + 0xc) - *(int *)(iVar3 + 4)) *
                      (*(int *)(iVar3 + 0x10) - *(int *)(iVar3 + 8));
          if (local_230 == local_22c) {
            std::vector<int,std::allocator<int>>::_M_realloc_insert<int_const&>
                      ((vector<int,std::allocator<int>> *)&local_234,local_230,&local_260);
            iVar2 = *(int *)(param_1 + 0x114);
          }
          else {
            if (local_230 != (int *)0x0) {
              *local_230 = local_260;
              iVar2 = *(int *)(param_1 + 0x114);
            }
            local_230 = local_230 + 1;
          }
          piVar8 = local_230;
          piVar1 = local_234;
          iVar15 = iVar15 + 1;
        } while (iVar15 < iVar2);
        piVar10 = local_230;
        if (local_234 != local_230) {
          iVar15 = (int)local_230 - (int)local_234;
          std::
          __introsort_loop<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,int,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
                    (local_234,local_230,(0x1f - LZCOUNT(iVar15 >> 2)) * 2,0x15b19);
          if (iVar15 < 0x41) {
            std::
            __insertion_sort<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
                      (piVar1,piVar8,0x15b19);
            iVar2 = *(int *)(param_1 + 0x114);
            piVar10 = local_234;
          }
          else {
            piVar14 = piVar1 + 0x10;
            std::
            __insertion_sort<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
                      (piVar1,piVar14,0x15b19);
            piVar10 = local_234;
            if (piVar14 != piVar8) {
              piVar13 = piVar1 + 0xf;
              do {
                piVar13 = piVar13 + 1;
                iVar15 = *piVar13;
                piVar7 = piVar13;
                while( true ) {
                  iVar2 = piVar7[-1];
                  iVar3 = FUN_00015b18(iVar15,iVar2);
                  if (iVar3 == 0) break;
                  *piVar7 = iVar2;
                  piVar7 = piVar7 + -1;
                }
                *piVar7 = iVar15;
              } while ((int *)((int)piVar14 + ((int)piVar8 - (int)(piVar1 + 0x11))) != piVar13);
            }
            iVar2 = *(int *)(param_1 + 0x114);
          }
        }
        if (0 < iVar2) {
          iVar15 = 0;
          do {
            iVar3 = iVar15 * 0x2a8;
            iVar15 = iVar15 + 1;
            *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x110) + 0x140) = 0;
          } while (iVar15 < *(int *)(param_1 + 0x114));
        }
        if (piVar10 != (int *)0x0) {
          operator_delete(piVar10);
        }
      }
    }
    get_time_ms();
    if (local_240 != (void *)0x0) {
      operator_delete(local_240);
    }
    if (local_24c != (void *)0x0) {
      operator_delete(local_24c);
    }
  }
  return;
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* campan_yolo_humanpose_det_process(nn_campan_engine_t*, nn_campan_in_t*) */

void campan_yolo_humanpose_det_process(nn_campan_engine_t *param_1,nn_campan_in_t *param_2)

{
  float *pfVar1;
  size_t __n;
  int *piVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 *puVar5;
  float *pfVar6;
  undefined4 uVar7;
  void *pvVar8;
  float *pfVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int **ppiVar13;
  int iVar14;
  int *piVar15;
  undefined4 uVar16;
  int *piVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  int *piVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  vector<ax_track_box_t,std::allocator<ax_track_box_t>> *pvVar24;
  int *piVar25;
  retina_t *prVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  undefined8 uVar30;
  undefined4 local_380;
  undefined4 local_37c;
  int local_378;
  int *local_358;
  int *local_348;
  int local_344;
  void *local_340;
  void *local_33c;
  undefined4 local_338;
  void *local_334;
  undefined4 *local_330;
  undefined4 *local_32c;
  void *local_328;
  int local_324;
  undefined4 local_320;
  void *local_31c;
  void *local_318;
  void *local_314;
  void *local_310;
  int local_30c;
  undefined4 local_308;
  undefined4 local_304;
  undefined4 local_300;
  undefined4 local_2fc;
  int local_2f8;
  int local_2f4;
  undefined4 local_2f0;
  undefined4 uStack_2ec;
  undefined4 uStack_2e8;
  undefined4 uStack_2e4;
  undefined4 local_2e0;
  undefined4 uStack_2dc;
  undefined4 uStack_2d8;
  undefined4 uStack_2d4;
  undefined4 local_2d0;
  int *local_2cc;
  int *local_2c8 [34];
  undefined4 local_240;
  undefined4 uStack_23c;
  undefined4 uStack_238;
  undefined4 uStack_234;
  undefined4 local_230;
  undefined4 uStack_22c;
  undefined4 uStack_228;
  undefined4 uStack_224;
  undefined4 local_220;
  undefined4 local_21c;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  
  if (DAT_0003a674 << 0x1a < 0) {
    __android_log_print(6,"CAMPAN","");
  }
  iVar10 = *(int *)(param_1 + 0x108);
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x1cc));
  prVar26 = *(retina_t **)(param_1 + 0xe4);
  puVar18 = *(undefined4 **)(param_1 + 0x14);
  if (*(int *)(param_1 + 0x10) != 0) {
    prVar26 = *(retina_t **)(param_1 + 0xe8);
    puVar18 = *(undefined4 **)(param_1 + 0x24);
  }
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x1cc));
  if ((prVar26 == (retina_t *)0x0) || (*(int *)(param_2 + 0x1c) == 0)) {
    *(undefined4 *)(param_1 + 0x114) = 0;
  }
  else {
    local_340 = (void *)0x0;
    local_33c = (void *)0x0;
    local_338 = 0;
    nnyuv2axyuv((nn_yuv_t *)&local_2f0);
    local_214 = *(undefined4 *)param_2;
    local_210 = *(undefined4 *)(param_2 + 4);
    local_240 = local_2f0;
    uStack_23c = uStack_2ec;
    uStack_238 = uStack_2e8;
    uStack_234 = uStack_2e4;
    local_21c = 0;
    local_230 = local_2e0;
    uStack_22c = uStack_2dc;
    uStack_228 = uStack_2d8;
    uStack_224 = uStack_2d4;
    local_220 = local_2d0;
    if (*(int *)(prVar26 + 0x44) == 6) {
      local_7c = 0x3ee66666;
    }
    else {
      local_7c = 0x3f19999a;
    }
    local_218 = 0;
    local_70 = 0x3eb851ec;
    local_20c = 0x3ee66666;
    local_74 = 0x3ecccccd;
    local_78 = 0x3f800000;
    retina_process_humanpose(prVar26,(retina_pose_in_t *)&local_240,(retina_pose_out_t *)&local_340)
    ;
    __n = (int)local_33c - (int)local_340;
    uVar21 = ((int)__n >> 3) * 0x4f72c235;
    if (uVar21 == 0) {
      iVar22 = 0;
      local_358 = (int *)0x0;
    }
    else {
      if (0x11a7b96 < uVar21) {
                    /* WARNING: Subroutine does not return */
        std::__throw_bad_alloc();
      }
      local_358 = (int *)operator_new(__n);
      __n = (int)local_33c - (int)local_340;
      iVar22 = ((int)__n >> 3) * 0x4f72c235;
    }
    if (local_33c != local_340) {
      memmove(local_358,local_340,__n);
    }
    uVar16 = *(undefined4 *)param_2;
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_2 + 0xc);
    *(undefined4 *)(param_1 + 0x3c) = uVar16;
    uVar16 = *(undefined4 *)(param_2 + 4);
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x8c);
    *(undefined4 *)(param_1 + 0x40) = uVar16;
    FUN_0001624c(param_1 + 0x54,param_1 + 0x58,iVar22);
    if (iVar22 != 0) {
      piVar2 = *(int **)(param_1 + 0x54);
      piVar4 = local_358;
      do {
        iVar11 = *piVar4;
        piVar17 = piVar4 + 0x3a;
        iVar28 = piVar4[6];
        *piVar2 = iVar11;
        iVar23 = piVar4[1];
        piVar2[1] = iVar23;
        piVar2[2] = (piVar4[2] - iVar11) + 1;
        iVar11 = piVar4[3];
        piVar2[4] = iVar28;
        piVar2[3] = (iVar11 - iVar23) + 1;
        piVar2 = piVar2 + 5;
        piVar4 = piVar17;
      } while (local_358 + iVar22 * 0x3a != piVar17);
    }
    *puVar18 = 0x3e8f5c29;
    uVar16 = *(undefined4 *)(iVar10 + 0x6c);
    puVar18[0xc] = 0x3ecccccd;
    puVar18[6] = uVar16;
    puVar18[8] = 0x3ef5c28f;
    puVar18[1] = 3;
    puVar18[5] = 1;
    puVar18[7] = 1;
    puVar18[10] = 1;
    puVar18[0x12] = 0x3f800000;
    puVar18[0xb] = 0;
    puVar18[9] = 0;
    puVar18[3] = 0x30;
    if (*(int *)(param_1 + 0x278) == 0) {
      puVar18[2] = 0;
    }
    else {
      puVar18[2] = 2;
    }
    dtbased_tk_update(puVar18,param_1 + 0x34,&local_348);
    iVar22 = local_348[1];
    AX_MALLOC_INC_TEMP<nn_campan_persons_t>((nn_campan_persons_t *)(param_1 + 0x110),iVar22);
    memset(*(void **)(param_1 + 0x110),0,iVar22 * 0x2a8);
    uVar16 = *(undefined4 *)(param_1 + 0x90);
    local_310 = (void *)0x0;
    local_30c = 0;
    local_308 = 0;
    uVar7 = *(undefined4 *)(param_1 + 0xa0);
    local_334 = (void *)0x0;
    local_330 = (undefined4 *)0x0;
    local_32c = (undefined4 *)0x0;
    local_328 = (void *)0x0;
    local_324 = 0;
    local_320 = 0;
    local_31c = (void *)0x0;
    local_318 = (void *)0x0;
    local_314 = (void *)0x0;
    uVar30 = get_time_ms();
    pvVar24 = (vector<ax_track_box_t,std::allocator<ax_track_box_t>> *)&local_31c;
    if (0 < iVar22) {
      iVar11 = 0;
      do {
        iVar28 = *(int *)(param_1 + 0x110);
        iVar29 = *local_348;
        iVar12 = iVar11 * 0x2a8;
        iVar27 = iVar29 + iVar11 * 0x20;
        uVar21 = *(uint *)(iVar27 + 0x18);
        iVar23 = iVar28 + iVar12;
        if ((int)uVar21 < 0) {
          local_380 = *(undefined4 *)(iVar27 + 4);
          *(undefined4 *)(iVar23 + 4) = local_380;
          local_37c = *(undefined4 *)(iVar27 + 8);
          puVar18 = (undefined4 *)(iVar23 + 0x264);
          *(undefined4 *)(iVar23 + 8) = local_37c;
          local_378 = *(int *)(iVar27 + 4) + *(int *)(iVar27 + 0xc) + -1;
          *(int *)(iVar23 + 0xc) = local_378;
          local_2f4 = *(int *)(iVar27 + 8) + *(int *)(iVar27 + 0x10) + -1;
          *(int *)(iVar23 + 0x10) = local_2f4;
          iVar14 = iVar23;
          do {
            *(undefined4 *)(iVar14 + 0x154) = 0;
            *(undefined4 *)(iVar14 + 0x158) = 0;
            iVar14 = iVar14 + 8;
            *puVar18 = 0;
            puVar18 = puVar18 + 1;
          } while ((undefined4 *)(iVar23 + 0x2a8) != puVar18);
        }
        else {
          if ((uint)(((int)local_33c - (int)local_340 >> 3) * 0x4f72c235) <= uVar21) {
                    /* WARNING: Subroutine does not return */
            std::__throw_out_of_range_fmt
                      ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)");
          }
          local_380 = *(undefined4 *)((int)local_340 + uVar21 * 0xe8);
          pvVar3 = (void *)((int)local_340 + uVar21 * 0xe8);
          *(undefined4 *)(iVar23 + 4) = local_380;
          local_37c = *(undefined4 *)((int)pvVar3 + 4);
          *(undefined4 *)(iVar23 + 8) = local_37c;
          local_378 = *(int *)((int)pvVar3 + 8);
          *(int *)(iVar23 + 0xc) = local_378;
          local_2f4 = *(int *)((int)pvVar3 + 0xc);
          *(int *)(iVar23 + 0x10) = local_2f4;
          puVar18 = (undefined4 *)((int)pvVar3 + 0xa4);
          iVar14 = iVar23;
          pvVar8 = pvVar3;
          puVar19 = (undefined4 *)(iVar23 + 0x264);
          do {
            *(undefined4 *)(iVar14 + 0x154) = *(undefined4 *)((int)pvVar8 + 0x1c);
            *(undefined4 *)(iVar14 + 0x158) = *(undefined4 *)((int)pvVar8 + 0x20);
            puVar5 = puVar18 + 1;
            *puVar19 = *puVar18;
            puVar18 = puVar5;
            iVar14 = iVar14 + 8;
            pvVar8 = (void *)((int)pvVar8 + 8);
            puVar19 = puVar19 + 1;
          } while ((undefined4 *)((int)pvVar3 + 0xe8) != puVar5);
        }
        local_304 = *(undefined4 *)(iVar29 + iVar11 * 0x20);
        *(undefined4 *)(iVar28 + iVar12) = local_304;
        *(undefined4 *)(iVar23 + 0x24) = *(undefined4 *)(iVar27 + 0x14);
        *(undefined8 *)(iVar23 + 0x28) = uVar30;
        local_300 = local_380;
        local_2fc = local_37c;
        local_2f8 = local_378;
        if (local_330 == local_32c) {
          std::vector<ax_track_box_t,std::allocator<ax_track_box_t>>::
          _M_realloc_insert<ax_track_box_t_const&>
                    ((vector<ax_track_box_t,std::allocator<ax_track_box_t>> *)&local_334,local_330,
                     &local_304);
        }
        else {
          if (local_330 != (undefined4 *)0x0) {
            *local_330 = local_304;
            local_330[1] = local_380;
            local_330[2] = local_37c;
            local_330[3] = local_378;
            local_330[4] = local_2f4;
          }
          local_330 = local_330 + 5;
        }
        local_2cc = *(int **)(iVar28 + iVar12);
        ppiVar13 = &local_2cc;
        do {
          ppiVar13[1] = (int *)(float)(longlong)*(int *)(iVar23 + 0x154);
          ppiVar13 = ppiVar13 + 2;
          *ppiVar13 = (int *)(float)(longlong)*(int *)(iVar23 + 0x158);
          iVar23 = iVar23 + 8;
        } while (local_2c8 + 0x21 != ppiVar13);
        if (local_318 == local_314) {
          std::vector<ax_track_kpt_t,std::allocator<ax_track_kpt_t>>::
          _M_realloc_insert<ax_track_kpt_t_const&>
                    ((vector<ax_track_kpt_t,std::allocator<ax_track_kpt_t>> *)&local_31c,local_318,
                     &local_2cc);
        }
        else {
          if (local_318 != (void *)0x0) {
            local_318 = memcpy(local_318,&local_2cc,0x8c);
          }
          local_318 = (void *)((int)local_318 + 0x8c);
        }
        iVar11 = iVar11 + 1;
        pvVar24 = (vector<ax_track_box_t,std::allocator<ax_track_box_t>> *)&local_334;
      } while (iVar22 != iVar11);
    }
    local_304 = *(undefined4 *)param_2;
    local_300 = *(undefined4 *)(param_2 + 4);
    box_smooth_process(uVar16,local_304,local_300,
                       (vector<ax_track_box_t,std::allocator<ax_track_box_t>> *)&local_334,
                       &local_328);
    iVar22 = local_324 - (int)local_328;
    if (0 < iVar22) {
      pvVar24 = (vector<ax_track_box_t,std::allocator<ax_track_box_t>> *)0x2a8;
    }
    if (0 < iVar22) {
      iVar23 = *(int *)(param_1 + 0x110);
      iVar11 = 0;
      pvVar8 = local_328;
      while( true ) {
        iVar11 = iVar11 + 1;
        *(undefined4 *)(iVar23 + 0x14) = *(undefined4 *)((int)pvVar8 + 4);
        *(undefined4 *)(iVar23 + 0x18) = *(undefined4 *)((int)pvVar8 + 8);
        *(undefined4 *)(iVar23 + 0x1c) = *(undefined4 *)((int)pvVar8 + 0xc);
        *(undefined4 *)(iVar23 + 0x20) = *(undefined4 *)((int)pvVar8 + 0x10);
        if ((iVar22 >> 2) * -0x33333333 <= iVar11) break;
        pvVar8 = (void *)((int)pvVar8 + 0x14);
        iVar23 = (int)pvVar24 * iVar11 + *(int *)(param_1 + 0x110);
      }
    }
    kpt_smooth_process(uVar7,local_304,local_300,
                       (vector<ax_track_kpt_t,std::allocator<ax_track_kpt_t>> *)&local_31c,
                       &local_310);
    iVar22 = local_30c - (int)local_310 >> 2;
    if (iVar22 * -0x75075075 != 0) {
      pfVar6 = (float *)((int)local_310 + 0x88);
      iVar11 = 0;
      do {
        pfVar9 = pfVar6 + -0x22;
        iVar23 = *(int *)(param_1 + 0x110) + iVar11;
        do {
          pfVar1 = pfVar9 + 1;
          pfVar9 = pfVar9 + 2;
          *(int *)(iVar23 + 0x1dc) = (int)(longlong)(*pfVar1 + 0.5);
          *(int *)(iVar23 + 0x1e0) = (int)(longlong)(*pfVar9 + 0.5);
          iVar23 = iVar23 + 8;
        } while (pfVar6 != pfVar9);
        iVar11 = iVar11 + 0x2a8;
        pfVar6 = pfVar6 + 0x23;
      } while (iVar22 * 0x24924938 - iVar11 != 0);
    }
    if (0 < *(int *)(param_1 + 0x114)) {
      iVar22 = 0;
      do {
        iVar11 = iVar22 * 0x2a8;
        iVar22 = iVar22 + 1;
        *(undefined4 *)(iVar11 + *(int *)(param_1 + 0x110) + 0x140) = 0;
        iVar11 = *(int *)(param_1 + 0x114);
      } while (iVar22 < iVar11);
      if ((0 < iVar11) && (*(int *)(iVar10 + 0x30) != 0)) {
        local_2cc = (int *)0x0;
        local_2c8[0] = (int *)0x0;
        local_2c8[1] = (int *)0x0;
        iVar10 = 0;
        do {
          iVar22 = iVar10 * 0x2a8 + *(int *)(param_1 + 0x110);
          local_344 = (*(int *)(iVar22 + 0xc) - *(int *)(iVar22 + 4)) *
                      (*(int *)(iVar22 + 0x10) - *(int *)(iVar22 + 8));
          if (local_2c8[0] == local_2c8[1]) {
            std::vector<int,std::allocator<int>>::_M_realloc_insert<int_const&>
                      ((vector<int,std::allocator<int>> *)&local_2cc,local_2c8[0],&local_344);
            iVar11 = *(int *)(param_1 + 0x114);
          }
          else {
            if (local_2c8[0] != (int *)0x0) {
              *local_2c8[0] = local_344;
              iVar11 = *(int *)(param_1 + 0x114);
            }
            local_2c8[0] = local_2c8[0] + 1;
          }
          piVar4 = local_2c8[0];
          piVar2 = local_2cc;
          iVar10 = iVar10 + 1;
        } while (iVar10 < iVar11);
        piVar17 = local_2c8[0];
        if (local_2cc != local_2c8[0]) {
          iVar10 = (int)local_2c8[0] - (int)local_2cc;
          std::
          __introsort_loop<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,int,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
                    (local_2cc,local_2c8[0],(0x1f - LZCOUNT(iVar10 >> 2)) * 2,0x15b19);
          if (iVar10 < 0x41) {
            std::
            __insertion_sort<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
                      (piVar2,piVar4,0x15b19);
            iVar11 = *(int *)(param_1 + 0x114);
            piVar17 = local_2cc;
          }
          else {
            piVar25 = piVar2 + 0x10;
            std::
            __insertion_sort<__gnu_cxx::__normal_iterator<int*,std::vector<int,std::allocator<int>>>,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(int,int)>>
                      (piVar2,piVar25,0x15b19);
            piVar17 = local_2cc;
            if (piVar25 != piVar4) {
              piVar20 = piVar2 + 0xf;
              do {
                piVar20 = piVar20 + 1;
                iVar10 = *piVar20;
                piVar15 = piVar20;
                while( true ) {
                  iVar11 = piVar15[-1];
                  iVar22 = FUN_00015b18(iVar10,iVar11);
                  if (iVar22 == 0) break;
                  *piVar15 = iVar11;
                  piVar15 = piVar15 + -1;
                }
                *piVar15 = iVar10;
              } while ((int *)((int)piVar25 + ((int)piVar4 - (int)(piVar2 + 0x11))) != piVar20);
            }
            iVar11 = *(int *)(param_1 + 0x114);
          }
        }
        if (0 < iVar11) {
          iVar10 = 0;
          do {
            iVar22 = iVar10 * 0x2a8;
            iVar10 = iVar10 + 1;
            *(undefined4 *)(iVar22 + *(int *)(param_1 + 0x110) + 0x140) = 0;
          } while (iVar10 < *(int *)(param_1 + 0x114));
        }
        if (piVar17 != (int *)0x0) {
          operator_delete(piVar17);
        }
      }
    }
    if (local_310 != (void *)0x0) {
      operator_delete(local_310);
    }
    if (local_31c != (void *)0x0) {
      operator_delete(local_31c);
    }
    if (local_328 != (void *)0x0) {
      operator_delete(local_328);
    }
    if (local_334 != (void *)0x0) {
      operator_delete(local_334);
    }
    if (local_358 != (int *)0x0) {
      operator_delete(local_358);
    }
    if (local_340 != (void *)0x0) {
      operator_delete(local_340);
      return;
    }
  }
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* void std::__adjust_heap<__gnu_cxx::__normal_iterator<ax_rect_t*, std::vector<ax_rect_t,
   std::allocator<ax_rect_t> > >, int, ax_rect_t, __gnu_cxx::__ops::_Iter_comp_iter<bool
   (*)(ax_rect_t, ax_rect_t)> >(__gnu_cxx::__normal_iterator<ax_rect_t*, std::vector<ax_rect_t,
   std::allocator<ax_rect_t> > >, int, int, ax_rect_t, __gnu_cxx::__ops::_Iter_comp_iter<bool
   (*)(ax_rect_t, ax_rect_t)>) */

void std::
     __adjust_heap<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,int,ax_rect_t,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
               (int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7,code *param_8)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  
  iVar5 = (int)(param_3 - 1) / 2;
  iVar2 = param_2;
  if (param_2 < iVar5) {
    do {
      iVar10 = (iVar2 + 1) * 2;
      puVar8 = (undefined4 *)(param_1 + (iVar2 + 1) * 0x20);
      iVar9 = iVar10 + -1;
      puVar7 = (undefined4 *)(param_1 + iVar9 * 0x10);
      iVar1 = (*param_8)(*puVar8,puVar8[1],puVar8[2],puVar8[3],*puVar7,puVar7[1],puVar7[2],puVar7[3]
                        );
      if (iVar1 == 0) {
        iVar9 = iVar10;
        puVar7 = puVar8;
      }
      puVar8 = (undefined4 *)(param_1 + iVar2 * 0x10);
      uVar3 = puVar7[1];
      uVar4 = puVar7[2];
      uVar6 = puVar7[3];
      *puVar8 = *puVar7;
      puVar8[1] = uVar3;
      puVar8[2] = uVar4;
      puVar8[3] = uVar6;
      iVar2 = iVar9;
    } while (iVar9 < iVar5);
    if ((param_3 & 1) == 0) goto LAB_0001c662;
  }
  else {
    iVar9 = param_2;
    if ((param_3 & 1) != 0) {
      puVar7 = (undefined4 *)(param_1 + param_2 * 0x10);
      goto LAB_0001c6e4;
    }
LAB_0001c662:
    if (iVar9 == (int)(param_3 - 2) / 2) {
      puVar8 = (undefined4 *)(param_1 + iVar9 * 0x10);
      iVar9 = iVar9 * 2 + 1;
      puVar7 = (undefined4 *)(param_1 + iVar9 * 0x10);
      uVar3 = puVar7[1];
      uVar4 = puVar7[2];
      uVar6 = puVar7[3];
      *puVar8 = *puVar7;
      puVar8[1] = uVar3;
      puVar8[2] = uVar4;
      puVar8[3] = uVar6;
    }
    else {
      puVar7 = (undefined4 *)(param_1 + iVar9 * 0x10);
    }
  }
  while (param_2 < iVar9) {
    iVar5 = (iVar9 + -1) / 2;
    puVar8 = (undefined4 *)(param_1 + iVar5 * 0x10);
    iVar2 = (*param_8)(*puVar8,puVar8[1],puVar8[2],puVar8[3],param_4,param_5,param_6,param_7);
    puVar7 = (undefined4 *)(param_1 + iVar9 * 0x10);
    if (iVar2 == 0) break;
    uVar3 = puVar8[1];
    uVar4 = puVar8[2];
    uVar6 = puVar8[3];
    *puVar7 = *puVar8;
    puVar7[1] = uVar3;
    puVar7[2] = uVar4;
    puVar7[3] = uVar6;
    puVar7 = puVar8;
    iVar9 = iVar5;
  }
LAB_0001c6e4:
  *puVar7 = param_4;
  puVar7[1] = param_5;
  puVar7[2] = param_6;
  puVar7[3] = param_7;
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* void std::__heap_select<__gnu_cxx::__normal_iterator<ax_rect_t*, std::vector<ax_rect_t,
   std::allocator<ax_rect_t> > >, __gnu_cxx::__ops::_Iter_comp_iter<bool (*)(ax_rect_t, ax_rect_t)>
   >(__gnu_cxx::__normal_iterator<ax_rect_t*, std::vector<ax_rect_t, std::allocator<ax_rect_t> > >,
   __gnu_cxx::__normal_iterator<ax_rect_t*, std::vector<ax_rect_t, std::allocator<ax_rect_t> > >,
   __gnu_cxx::__normal_iterator<ax_rect_t*, std::vector<ax_rect_t, std::allocator<ax_rect_t> > >,
   __gnu_cxx::__ops::_Iter_comp_iter<bool (*)(ax_rect_t, ax_rect_t)>) */

void std::
     __heap_select<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
               (undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,code *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  
  iVar1 = (int)param_2 - (int)param_1 >> 4;
  if (0x10 < (int)param_2 - (int)param_1) {
    iVar10 = (iVar1 + -2) / 2;
    puVar9 = param_1 + iVar10 * 4;
    while( true ) {
      uVar2 = *puVar9;
      puVar11 = puVar9 + 1;
      puVar12 = puVar9 + 2;
      puVar13 = puVar9 + 3;
      puVar9 = puVar9 + -4;
      __adjust_heap<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,int,ax_rect_t,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
                (param_1,iVar10,iVar1,uVar2,*puVar11,*puVar12,*puVar13,param_4);
      if (iVar10 == 0) break;
      iVar10 = iVar10 + -1;
    }
  }
  if (param_2 < param_3) {
    do {
      while (iVar10 = (*param_4)(*param_2,param_2[1],param_2[2],param_2[3],*param_1,param_1[1],
                                 param_1[2],param_1[3]), iVar10 != 0) {
        uVar2 = *param_2;
        uVar3 = param_2[1];
        uVar5 = param_2[2];
        uVar7 = param_2[3];
        uVar4 = param_1[1];
        uVar6 = param_1[2];
        uVar8 = param_1[3];
        *param_2 = *param_1;
        param_2[1] = uVar4;
        param_2[2] = uVar6;
        param_2[3] = uVar8;
        param_2 = param_2 + 4;
        __adjust_heap<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,int,ax_rect_t,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
                  (param_1,0,iVar1,uVar2,uVar3,uVar5,uVar7,param_4);
        if (param_3 <= param_2) {
          return;
        }
      }
      param_2 = param_2 + 4;
    } while (param_2 < param_3);
  }
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* void std::__introsort_loop<__gnu_cxx::__normal_iterator<ax_rect_t*, std::vector<ax_rect_t,
   std::allocator<ax_rect_t> > >, int, __gnu_cxx::__ops::_Iter_comp_iter<bool (*)(ax_rect_t,
   ax_rect_t)> >(__gnu_cxx::__normal_iterator<ax_rect_t*, std::vector<ax_rect_t,
   std::allocator<ax_rect_t> > >, __gnu_cxx::__normal_iterator<ax_rect_t*, std::vector<ax_rect_t,
   std::allocator<ax_rect_t> > >, int, __gnu_cxx::__ops::_Iter_comp_iter<bool (*)(ax_rect_t,
   ax_rect_t)>) */

void std::
     __introsort_loop<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,int,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
               (undefined4 *param_1,undefined4 *param_2,int param_3,code *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 *local_48;
  int local_44;
  
  if (0x100 < (int)param_2 - (int)param_1) {
    if (param_3 != 0) {
      puVar6 = param_1 + 4;
      puVar7 = param_1 + 8;
      local_48 = param_2;
      local_44 = param_3;
LAB_0001c7fa:
      local_44 = local_44 + -1;
      puVar11 = param_1 + (((int)local_48 - (int)param_1 >> 4) -
                           ((int)local_48 - (int)param_1 >> 0x1f) >> 1) * 4;
      puVar12 = local_48 + -4;
      iVar1 = (*param_4)(*puVar6,param_1[5],param_1[6],param_1[7],*puVar11,puVar11[1],puVar11[2],
                         puVar11[3]);
      puVar13 = local_48;
      puVar14 = puVar7;
      if (iVar1 == 0) {
        iVar1 = (*param_4)(*puVar6,param_1[5],param_1[6],param_1[7],*puVar12,local_48[-3],
                           local_48[-2],local_48[-1]);
        if (iVar1 == 0) {
          iVar1 = (*param_4)(*puVar11,puVar11[1],puVar11[2],puVar11[3],*puVar12,local_48[-3],
                             local_48[-2],local_48[-1]);
          if (iVar1 != 0) goto LAB_0001c968;
          goto LAB_0001c94e;
        }
      }
      else {
        iVar1 = (*param_4)(*puVar11,puVar11[1],puVar11[2],puVar11[3],*puVar12,local_48[-3],
                           local_48[-2],local_48[-1]);
        if (iVar1 != 0) {
LAB_0001c94e:
          uVar2 = *param_1;
          uVar3 = param_1[1];
          uVar8 = param_1[2];
          uVar9 = param_1[3];
          uVar4 = puVar11[1];
          uVar5 = puVar11[2];
          uVar10 = puVar11[3];
          *param_1 = *puVar11;
          param_1[1] = uVar4;
          param_1[2] = uVar5;
          param_1[3] = uVar10;
          *puVar11 = uVar2;
          puVar11[1] = uVar3;
          puVar11[2] = uVar8;
          puVar11[3] = uVar9;
          goto LAB_0001c870;
        }
        iVar1 = (*param_4)(*puVar6,param_1[5],param_1[6],param_1[7],*puVar12,local_48[-3],
                           local_48[-2],local_48[-1]);
        if (iVar1 != 0) {
LAB_0001c968:
          uVar2 = *param_1;
          uVar3 = param_1[1];
          uVar8 = param_1[2];
          uVar9 = param_1[3];
          uVar4 = local_48[-3];
          uVar5 = local_48[-2];
          uVar10 = local_48[-1];
          *param_1 = *puVar12;
          param_1[1] = uVar4;
          param_1[2] = uVar5;
          param_1[3] = uVar10;
          *puVar12 = uVar2;
          local_48[-3] = uVar3;
          local_48[-2] = uVar8;
          local_48[-1] = uVar9;
          goto LAB_0001c870;
        }
      }
      uVar2 = *param_1;
      uVar3 = param_1[1];
      uVar4 = param_1[2];
      uVar8 = param_1[3];
      *param_1 = *puVar6;
      param_1[1] = param_1[5];
      param_1[2] = param_1[6];
      param_1[3] = param_1[7];
      *puVar6 = uVar2;
      param_1[5] = uVar3;
      param_1[6] = uVar4;
      param_1[7] = uVar8;
LAB_0001c870:
      do {
        param_2 = puVar14 + -4;
        iVar1 = (*param_4)(*param_2,puVar14[-3],puVar14[-2],puVar14[-1],*param_1,param_1[1],
                           param_1[2],param_1[3]);
        if (iVar1 == 0) {
          do {
            puVar11 = puVar13;
            puVar13 = puVar11 + -4;
            iVar1 = (*param_4)(*param_1,param_1[1],param_1[2],param_1[3],*puVar13,puVar11[-3],
                               puVar11[-2],puVar11[-1]);
          } while (iVar1 != 0);
          if (puVar13 <= param_2) goto LAB_0001c8ca;
          uVar2 = *param_2;
          uVar3 = puVar14[-3];
          uVar8 = puVar14[-2];
          uVar9 = puVar14[-1];
          uVar4 = puVar11[-3];
          uVar5 = puVar11[-2];
          uVar10 = puVar11[-1];
          *param_2 = *puVar13;
          puVar14[-3] = uVar4;
          puVar14[-2] = uVar5;
          puVar14[-1] = uVar10;
          *puVar13 = uVar2;
          puVar11[-3] = uVar3;
          puVar11[-2] = uVar8;
          puVar11[-1] = uVar9;
        }
        puVar14 = puVar14 + 4;
      } while( true );
    }
LAB_0001c8e4:
    __heap_select<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
              (param_1,param_2,param_2,param_4);
    do {
      puVar6 = param_2 + -4;
      uVar2 = *puVar6;
      uVar3 = param_2[-3];
      uVar8 = param_2[-2];
      uVar9 = param_2[-1];
      uVar4 = param_1[1];
      uVar5 = param_1[2];
      uVar10 = param_1[3];
      *puVar6 = *param_1;
      param_2[-3] = uVar4;
      param_2[-2] = uVar5;
      param_2[-1] = uVar10;
      __adjust_heap<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,int,ax_rect_t,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
                (param_1,0,(int)puVar6 - (int)param_1 >> 4,uVar2,uVar3,uVar8,uVar9,param_4);
      param_2 = puVar6;
    } while (0x10 < (int)puVar6 - (int)param_1);
  }
  return;
LAB_0001c8ca:
  __introsort_loop<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,int,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
            (param_2,local_48,local_44);
  if ((int)param_2 - (int)param_1 < 0x101) {
    return;
  }
  local_48 = param_2;
  if (local_44 == 0) goto LAB_0001c8e4;
  goto LAB_0001c7fa;
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_0001c990(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int *local_54;
  int *local_50;
  int *local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  
  iVar7 = *(int *)(param_1 + 0x114);
  local_54 = (int *)0x0;
  local_50 = (int *)0x0;
  local_4c = (int *)0x0;
  if (iVar7 < 1) {
    return;
  }
  iVar4 = 0;
  do {
    iVar2 = iVar4 * 0x2a8 + *(int *)(param_1 + 0x110);
    local_48 = *(int *)(iVar2 + 0x14);
    local_44 = *(int *)(iVar2 + 0x18);
    local_40 = (*(int *)(iVar2 + 0x1c) - local_48) + 1;
    local_3c = (*(int *)(iVar2 + 0x20) - local_44) + 1;
    if (local_50 == local_4c) {
      std::vector<ax_rect_t,std::allocator<ax_rect_t>>::_M_realloc_insert<ax_rect_t_const&>
                ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&local_54,local_50,&local_48);
      iVar7 = *(int *)(param_1 + 0x114);
      if (iVar7 <= iVar4 + 1) break;
    }
    else {
      if (local_50 != (int *)0x0) {
        *local_50 = local_48;
        local_50[1] = local_44;
        local_50[2] = local_40;
        local_50[3] = local_3c;
      }
      local_50 = local_50 + 4;
      if (iVar7 <= iVar4 + 1) break;
    }
    iVar4 = iVar4 + 1;
  } while( true );
  piVar3 = local_50;
  piVar1 = local_54;
  iVar7 = (int)local_50 - (int)local_54;
  uVar6 = iVar7 >> 4;
  if (local_54 != local_50) {
    std::
    __introsort_loop<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,int,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
              (local_54,local_50,(0x1f - LZCOUNT(uVar6)) * 2,&LAB_00015b24_1);
    if (iVar7 < 0x101) {
      std::
      __insertion_sort<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
                (piVar1,piVar3,&LAB_00015b24_1);
    }
    else {
      piVar5 = piVar1 + 0x40;
      std::
      __insertion_sort<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,__gnu_cxx::__ops::_Iter_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
                (piVar1,piVar5,&LAB_00015b24_1);
      if (piVar5 != piVar3) {
        do {
          std::
          __unguarded_linear_insert<__gnu_cxx::__normal_iterator<ax_rect_t*,std::vector<ax_rect_t,std::allocator<ax_rect_t>>>,__gnu_cxx::__ops::_Val_comp_iter<bool(*)(ax_rect_t,ax_rect_t)>>
                    (piVar5,&LAB_00015b24_1);
          piVar5 = piVar5 + 4;
        } while (piVar3 != piVar5);
        uVar6 = (int)local_50 - (int)local_54 >> 4;
        piVar3 = local_54;
        goto LAB_0001ca82;
      }
    }
    uVar6 = (int)local_50 - (int)local_54 >> 4;
    piVar3 = local_54;
  }
LAB_0001ca82:
  if ((int)uVar6 <= (int)param_3) {
    param_3 = uVar6;
  }
  if ((int)param_3 < 1) {
LAB_0001cb18:
    if (piVar3 != (int *)0x0) {
      operator_delete(piVar3);
    }
    return;
  }
  if (local_50 == local_54) {
    uVar6 = 0;
  }
  else {
    uVar6 = 0;
    do {
      local_44 = piVar3[uVar6 * 4 + 1];
      local_40 = (int)(longlong)((double)(longlong)piVar3[uVar6 * 4 + 2] * 1.1);
      local_48 = (piVar3[uVar6 * 4] + piVar3[uVar6 * 4 + 2] / 2) - local_40 / 2;
      local_3c = (int)((float)(longlong)local_40 / 0.8);
      FUN_00017014(param_1,param_2,local_48,local_44,local_40,local_3c,param_4);
      uVar6 = uVar6 + 1;
      piVar3 = local_54;
      if (uVar6 == param_3) goto LAB_0001cb18;
    } while (uVar6 < (uint)((int)local_50 - (int)local_54 >> 4));
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",uVar6);
}



void FUN_0001cb80(int param_1,undefined4 *param_2)

{
  int *piVar1;
  void *__s;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  retina_t *prVar12;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  float fVar20;
  int iVar21;
  int iVar22;
  uint uVar23;
  float fVar24;
  int iVar25;
  int iVar26;
  uint uVar27;
  float fVar28;
  int local_254;
  retina_out_t arStack_240 [4];
  retina_t *local_23c;
  undefined4 *local_238;
  int local_234;
  int local_230;
  int local_22c;
  undefined4 local_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined4 local_218;
  undefined4 uStack_214;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  undefined4 uStack_1f8;
  undefined4 local_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 uStack_1dc;
  undefined4 local_1d8;
  undefined4 uStack_1d4;
  undefined4 local_1d0;
  undefined4 local_40;
  undefined4 local_3c;
  
  if (DAT_0003a674 << 0x1a < 0) {
    __android_log_print(6,"CAMPAN","");
  }
  iVar16 = *(int *)(param_1 + 0x108);
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x1cc));
  *(undefined4 *)(param_1 + 0x11c) = 0;
  prVar12 = *(retina_t **)(param_1 + 0xac);
  puVar14 = *(undefined4 **)(param_1 + 0x20);
  if (*(int *)(param_1 + 0x10) != 0) {
    prVar12 = *(retina_t **)(param_1 + 0xb0);
    puVar14 = *(undefined4 **)(param_1 + 0x30);
  }
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x1cc));
  if (prVar12 == (retina_t *)0x0) {
    return;
  }
  if (*(int *)(iVar16 + 0x2c) == 0) {
    return;
  }
  if (param_2[10] == 0) {
    return;
  }
  nnyuv2axyuv((nn_yuv_t *)&local_228);
  local_40 = 0x3e99999a;
  local_204 = local_228;
  uStack_200 = uStack_224;
  uStack_1fc = uStack_220;
  uStack_1f8 = uStack_21c;
  local_3c = 0x3f400000;
  local_1f4 = local_218;
  uStack_1f0 = uStack_214;
  uStack_1ec = uStack_210;
  uStack_1e8 = uStack_20c;
  local_1d8 = *param_2;
  uStack_1d4 = param_2[1];
  local_1e4 = local_208;
  local_1e0 = 0;
  uStack_1dc = 0;
  local_1d0 = 0x3f59999a;
  get_time_ms();
  iVar9 = 0;
  iVar19 = *(int *)(*(int *)(param_1 + 0x1c8) + 0x330);
  if (iVar19 < 0) {
    retina_process(prVar12,(retina_in_t *)&local_204,arStack_240);
    prVar12 = local_23c;
    if (*(int *)(iVar16 + 0x44) == 1) {
      FUN_0001c990(param_1,param_2,5,local_23c);
    }
  }
  else if (*(int *)(param_1 + 300) < 1) {
LAB_0001cc7e:
    if (*(int *)(iVar16 + 0x44) != 1) goto LAB_0001d0fc;
    *(undefined4 *)(prVar12 + 0x54) = 0;
    FUN_0001c990(param_1,param_2,1,prVar12 + 0x50);
    prVar12 = prVar12 + 0x50;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x128);
    iVar7 = *piVar1;
    while (iVar19 != iVar7) {
      iVar9 = iVar9 + 1;
      piVar1 = piVar1 + 0xf;
      if (*(int *)(param_1 + 300) == iVar9) goto LAB_0001cc7e;
      iVar7 = *piVar1;
    }
    if (*(int *)(param_1 + 0x114) < 1) {
LAB_0001d00c:
      local_230 = piVar1[3] - piVar1[1];
      iVar9 = piVar1[4] - piVar1[2];
      if (local_230 < iVar9) {
        local_230 = iVar9;
      }
      local_230 = local_230 * 3;
      local_234 = (piVar1[2] + piVar1[4]) / 2;
      local_238 = (undefined4 *)((piVar1[1] + piVar1[3]) / 2 - local_230 / 2);
      local_22c = (int)((float)(longlong)local_230 / 0.8);
      if (*(int *)(iVar16 + 0x44) == 1) {
        *(undefined4 *)(prVar12 + 0x54) = 0;
LAB_0001d078:
        FUN_00017014(param_1,param_2,local_238,local_234,local_230,local_22c,prVar12 + 0x50);
        prVar12 = prVar12 + 0x50;
        goto LAB_0001cc98;
      }
    }
    else {
      piVar6 = *(int **)(param_1 + 0x110);
      if (piVar1[10] != *piVar6) {
        iVar9 = 0;
        do {
          iVar9 = iVar9 + 1;
          piVar6 = piVar6 + 0xaa;
          if (iVar9 == *(int *)(param_1 + 0x114)) goto LAB_0001d00c;
        } while (piVar1[10] != *piVar6);
      }
      local_234 = piVar6[2];
      iVar9 = (piVar6[3] - piVar6[1]) + 1;
      local_230 = (int)(longlong)((double)(longlong)iVar9 * 1.1);
      local_238 = (undefined4 *)((piVar6[1] + iVar9 / 2) - local_230 / 2);
      local_22c = (int)((float)(longlong)local_230 / 0.8);
      if (*(int *)(iVar16 + 0x44) == 1) {
        *(undefined4 *)(prVar12 + 0x54) = 0;
        goto LAB_0001d078;
      }
    }
LAB_0001d0fc:
    retina_process(prVar12,(retina_in_t *)&local_204,arStack_240);
    prVar12 = local_23c;
  }
LAB_0001cc98:
  if (prVar12 == (retina_t *)0x0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x38) = param_2[3];
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x8c);
  uVar10 = param_2[1];
  *(undefined4 *)(param_1 + 0x3c) = *param_2;
  *(undefined4 *)(param_1 + 0x40) = uVar10;
  FUN_0001624c(param_1 + 0x54,param_1 + 0x58,*(int *)(prVar12 + 4));
  iVar9 = *(int *)(prVar12 + 4);
  if (0 < iVar9) {
    piVar3 = *(int **)prVar12;
    piVar1 = *(int **)(param_1 + 0x54);
    piVar6 = piVar3;
    do {
      iVar19 = *piVar6;
      piVar4 = piVar6 + 7;
      iVar17 = piVar6[6];
      *piVar1 = iVar19;
      iVar7 = piVar6[1];
      piVar1[1] = iVar7;
      piVar1[2] = (piVar6[2] - iVar19) + 1;
      iVar19 = piVar6[3];
      piVar1[4] = iVar17;
      piVar1[3] = (iVar19 - iVar7) + 1;
      piVar1 = piVar1 + 5;
      piVar6 = piVar4;
    } while (piVar3 + iVar9 * 7 != piVar4);
  }
  puVar14[1] = 3;
  uVar10 = *(undefined4 *)(iVar16 + 0x70);
  puVar14[5] = 1;
  puVar14[6] = uVar10;
  puVar14[7] = 1;
  *puVar14 = 0x3e8f5c29;
  puVar14[8] = 0x3f666666;
  puVar14[10] = 0;
  puVar14[2] = 0;
  puVar14[9] = 0;
  get_time_ms();
  dtbased_tk_update(puVar14,param_1 + 0x34,&local_238);
  get_time_ms();
  __s = *(void **)(param_1 + 0x118);
  iVar9 = local_238[1];
  *(int *)(param_1 + 0x11c) = iVar9;
  if (__s == (void *)0x0) {
    if (iVar9 * 0x2c < 1) goto LAB_0001cd9c;
  }
  else {
    if (*(int *)((int)__s + -4) + iVar9 * -0x2c < 0 ==
        SBORROW4(*(int *)((int)__s + -4),iVar9 * 0x2c)) goto LAB_0001cd9c;
    AX_FREE_RECORD(__s);
    *(undefined4 *)(param_1 + 0x118) = 0;
  }
  __s = (void *)AX_MALLOC_RECORD(iVar9 * 0x2c);
  *(void **)(param_1 + 0x118) = __s;
  if (__s == (void *)0x0) {
    *(undefined4 *)(param_1 + 0x11c) = 0;
  }
LAB_0001cd9c:
  memset(__s,0,iVar9 * 0x2c);
  if (0 < iVar9) {
    piVar3 = *(int **)(param_1 + 0x118);
    piVar1 = (int *)*local_238;
    piVar6 = piVar3;
    do {
      piVar4 = piVar6 + 0xb;
      *piVar6 = *piVar1 + 20000000;
      iVar7 = piVar1[1];
      piVar6[1] = iVar7;
      iVar17 = piVar1[2];
      piVar6[2] = iVar17;
      iVar18 = piVar1[3] + iVar7 + -1;
      piVar6[3] = iVar18;
      iVar19 = piVar1[4];
      piVar6[5] = iVar7;
      piVar6[7] = iVar18;
      iVar19 = iVar19 + iVar17 + -1;
      piVar6[6] = iVar17;
      piVar6[4] = iVar19;
      piVar6[8] = iVar19;
      if (piVar1[6] < 0) {
        piVar6[9] = 0;
      }
      else {
        piVar6[9] = *(int *)(piVar1[6] * 0x1c + *(int *)prVar12 + 0x10);
      }
      piVar1 = piVar1 + 8;
      piVar6 = piVar4;
    } while (piVar3 + iVar9 * 0xb != piVar4);
  }
  handpose_process_new
            (*(handpose_t **)(param_1 + 200),(nn_campan_hands_t *)(param_1 + 0x118),
             (ax_yuv_t *)&local_228,*(int *)(iVar16 + 0x50),*(int *)(iVar16 + 0x54),
             *(int *)(iVar16 + 0x74));
  get_time_ms();
  local_254 = *(int *)(param_1 + 0x11c);
  if (0 < local_254) {
    iVar16 = 0;
    do {
      iVar9 = iVar16 * 0x2c + *(int *)(param_1 + 0x118);
      if (*(int *)(iVar9 + 0x24) == 6 || *(int *)(iVar9 + 0x24) == 3) {
        iVar19 = *(int *)(iVar9 + 4);
        iVar17 = *(int *)(iVar9 + 8);
        iVar7 = *(int *)(iVar9 + 0xc);
        iVar18 = *(int *)(iVar9 + 0x10);
        if (0 < *(int *)(param_1 + 300)) {
          iVar15 = 0;
          iVar13 = *(int *)(param_1 + 0x128);
          fVar20 = (float)(longlong)(((iVar18 - iVar17) + 1) * ((iVar7 - iVar19) + 1));
          do {
            iVar2 = *(int *)(iVar13 + 4);
            iVar5 = *(int *)(iVar13 + 8);
            iVar8 = *(int *)(iVar13 + 0xc);
            iVar11 = *(int *)(iVar13 + 0x10);
            iVar25 = iVar19;
            if (iVar19 <= iVar2) {
              iVar25 = iVar2;
            }
            iVar26 = iVar17;
            if (iVar17 <= iVar5) {
              iVar26 = iVar5;
            }
            iVar21 = iVar8;
            if (iVar7 < iVar8) {
              iVar21 = iVar7;
            }
            iVar22 = iVar11;
            if (iVar18 < iVar11) {
              iVar22 = iVar18;
            }
            uVar23 = (uint)(((float)(longlong)iVar21 - (float)(longlong)iVar25) + 1.0);
            uVar27 = (uint)(((float)(longlong)iVar22 - (float)(longlong)iVar26) + 1.0);
            if ((int)(uVar27 | uVar23) < 0) {
              fVar28 = 0.0;
            }
            else {
              fVar28 = (float)(longlong)(int)uVar23 * (float)(longlong)(int)uVar27;
            }
            fVar24 = (float)(longlong)(((iVar11 - iVar5) + 1) * ((iVar8 - iVar2) + 1));
            if ((int)((uint)(fVar20 < fVar24) << 0x1f) < 0) {
              fVar24 = fVar20;
            }
            fVar28 = fVar28 / fVar24;
            if (fVar28 != 0.3 && fVar28 < 0.3 == NAN(fVar28)) {
              __android_log_print(6,"CAMPAN","hand in face, reject");
              local_254 = *(int *)(param_1 + 0x11c);
              *(undefined4 *)(iVar9 + 0x24) = 0;
              break;
            }
            iVar15 = iVar15 + 1;
            iVar13 = iVar13 + 0x3c;
          } while (*(int *)(param_1 + 300) != iVar15);
        }
      }
      iVar16 = iVar16 + 1;
    } while (iVar16 < local_254);
  }
  return;
}



int * FUN_0001da5c(uint *param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  void *pvVar4;
  void *pvVar5;
  uint __n;
  undefined4 *puVar6;
  undefined4 *puVar7;
  void *pvVar8;
  uint local_14;
  
  iVar1 = param_3;
  if (param_3 != 0) {
    iVar1 = 1;
  }
  if (param_2 != (undefined1 *)0x0) {
    iVar1 = 0;
  }
  if (iVar1 != 0) {
    piVar2 = (int *)std::__throw_logic_error("basic_string::_M_construct null not valid");
    puVar6 = (undefined4 *)piVar2[0x14];
    puVar7 = (undefined4 *)piVar2[0x15];
    if (puVar6 != puVar7) {
      do {
        if ((void *)puVar6[6] != (void *)0x0) {
          operator_delete((void *)puVar6[6]);
        }
        if ((void *)puVar6[3] != (void *)0x0) {
          operator_delete((void *)puVar6[3]);
        }
        pvVar4 = (void *)*puVar6;
        puVar6 = puVar6 + 0xb;
        if (pvVar4 != (void *)0x0) {
          operator_delete(pvVar4);
        }
      } while (puVar7 != puVar6);
      puVar7 = (undefined4 *)piVar2[0x14];
    }
    if (puVar7 != (undefined4 *)0x0) {
      operator_delete(puVar7);
    }
    if ((void *)piVar2[0xc] != (void *)0x0) {
      operator_delete((void *)piVar2[0xc]);
    }
    if ((void *)piVar2[9] != (void *)0x0) {
      operator_delete((void *)piVar2[9]);
    }
    if ((void *)piVar2[6] != (void *)0x0) {
      operator_delete((void *)piVar2[6]);
    }
    if ((void *)piVar2[3] != (void *)0x0) {
      operator_delete((void *)piVar2[3]);
    }
    pvVar4 = (void *)*piVar2;
    pvVar8 = (void *)piVar2[1];
    if (pvVar4 != pvVar8) {
      do {
        if (*(void **)((int)pvVar4 + 0x20) != (void *)((int)pvVar4 + 0x28)) {
          operator_delete(*(void **)((int)pvVar4 + 0x20));
        }
        puVar6 = (undefined4 *)((int)pvVar4 + 8);
        pvVar5 = (void *)((int)pvVar4 + 0x10);
        pvVar4 = (void *)((int)pvVar4 + 0x38);
        if ((void *)*puVar6 != pvVar5) {
          operator_delete((void *)*puVar6);
        }
      } while (pvVar8 != pvVar4);
      pvVar8 = (void *)*piVar2;
    }
    if (pvVar8 != (void *)0x0) {
      operator_delete(pvVar8);
    }
    return piVar2;
  }
  __n = param_3 - (int)param_2;
  local_14 = __n;
  if (__n < 0x10) {
    piVar2 = (int *)*param_1;
    if (__n == 1) {
      *(undefined1 *)piVar2 = *param_2;
      piVar3 = (int *)*param_1;
      goto LAB_0001da88;
    }
    piVar3 = piVar2;
    if (__n == 0) goto LAB_0001da88;
  }
  else {
    piVar2 = (int *)std::__cxx11::string::_M_create(param_1,(uint)&local_14);
    *param_1 = (uint)piVar2;
    param_1[2] = local_14;
  }
  piVar2 = (int *)memcpy(piVar2,param_2,__n);
  piVar3 = (int *)*param_1;
LAB_0001da88:
  param_1[1] = local_14;
  *(undefined1 *)((int)piVar3 + local_14) = 0;
  return piVar2;
}



/* retina_model_info_t::~retina_model_info_t() */

retina_model_info_t * __thiscall
retina_model_info_t::~retina_model_info_t(retina_model_info_t *this)

{
  void *pvVar1;
  void *pvVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void *pvVar5;
  
  puVar3 = *(undefined4 **)(this + 0x50);
  puVar4 = *(undefined4 **)(this + 0x54);
  if (puVar3 != puVar4) {
    do {
      if ((void *)puVar3[6] != (void *)0x0) {
        operator_delete((void *)puVar3[6]);
      }
      if ((void *)puVar3[3] != (void *)0x0) {
        operator_delete((void *)puVar3[3]);
      }
      pvVar1 = (void *)*puVar3;
      puVar3 = puVar3 + 0xb;
      if (pvVar1 != (void *)0x0) {
        operator_delete(pvVar1);
      }
    } while (puVar4 != puVar3);
    puVar4 = *(undefined4 **)(this + 0x50);
  }
  if (puVar4 != (undefined4 *)0x0) {
    operator_delete(puVar4);
  }
  if (*(void **)(this + 0x30) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x30));
  }
  if (*(void **)(this + 0x24) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x24));
  }
  if (*(void **)(this + 0x18) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x18));
  }
  if (*(void **)(this + 0xc) != (void *)0x0) {
    operator_delete(*(void **)(this + 0xc));
  }
  pvVar1 = *(void **)this;
  pvVar5 = *(void **)(this + 4);
  if (pvVar1 != pvVar5) {
    do {
      if (*(void **)((int)pvVar1 + 0x20) != (void *)((int)pvVar1 + 0x28)) {
        operator_delete(*(void **)((int)pvVar1 + 0x20));
      }
      puVar3 = (undefined4 *)((int)pvVar1 + 8);
      pvVar2 = (void *)((int)pvVar1 + 0x10);
      pvVar1 = (void *)((int)pvVar1 + 0x38);
      if ((void *)*puVar3 != pvVar2) {
        operator_delete((void *)*puVar3);
      }
    } while (pvVar5 != pvVar1);
    pvVar5 = *(void **)this;
  }
  if (pvVar5 != (void *)0x0) {
    operator_delete(pvVar5);
  }
  return this;
}



/* ez_model_info_t::~ez_model_info_t() */

ez_model_info_t * __thiscall ez_model_info_t::~ez_model_info_t(ez_model_info_t *this)

{
  if (*(ez_model_info_t **)(this + 0x20) != this + 0x28) {
    operator_delete(*(ez_model_info_t **)(this + 0x20));
  }
  if (*(ez_model_info_t **)(this + 8) != this + 0x10) {
    operator_delete(*(ez_model_info_t **)(this + 8));
  }
  return this;
}



/* retina_head_t::~retina_head_t() */

retina_head_t * __thiscall retina_head_t::~retina_head_t(retina_head_t *this)

{
  if (*(void **)(this + 0x18) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x18));
  }
  if (*(void **)(this + 0xc) != (void *)0x0) {
    operator_delete(*(void **)(this + 0xc));
  }
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this);
  }
  return this;
}



/* std::vector<retina_head_t, std::allocator<retina_head_t> >::~vector() */

vector<retina_head_t,std::allocator<retina_head_t>> * __thiscall
std::vector<retina_head_t,std::allocator<retina_head_t>>::~vector
          (vector<retina_head_t,std::allocator<retina_head_t>> *this)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)this;
  puVar3 = *(undefined4 **)(this + 4);
  if (puVar2 != puVar3) {
    do {
      if ((void *)puVar2[6] != (void *)0x0) {
        operator_delete((void *)puVar2[6]);
      }
      if ((void *)puVar2[3] != (void *)0x0) {
        operator_delete((void *)puVar2[3]);
      }
      pvVar1 = (void *)*puVar2;
      puVar2 = puVar2 + 0xb;
      if (pvVar1 != (void *)0x0) {
        operator_delete(pvVar1);
      }
    } while (puVar3 != puVar2);
    puVar3 = *(undefined4 **)this;
  }
  if (puVar3 != (undefined4 *)0x0) {
    operator_delete(puVar3);
  }
  return this;
}



/* std::vector<int, std::allocator<int> >::TEMPNAMEPLACEHOLDERVALUE(std::vector<int,
   std::allocator<int> > const&) */

vector<int,std::allocator<int>> * __thiscall
std::vector<int,std::allocator<int>>::operator=
          (vector<int,std::allocator<int>> *this,vector *param_1)

{
  void *__dest;
  size_t __n;
  void *pvVar1;
  uint __n_00;
  int iVar2;
  void *__dest_00;
  void *__src;
  void *pvVar3;
  
  if (param_1 == (vector *)this) {
    return this;
  }
  __src = *(void **)param_1;
  pvVar3 = *(void **)(param_1 + 4);
  __dest_00 = *(void **)this;
  __n_00 = (int)pvVar3 - (int)__src;
  pvVar1 = (void *)((int)__n_00 >> 2);
  if ((void *)(*(int *)(this + 8) - (int)__dest_00 >> 2) < pvVar1) {
    if (pvVar1 != (void *)0x0) {
      if ((void *)0x3fffffff < pvVar1) {
                    /* WARNING: Subroutine does not return */
        std::__throw_bad_alloc();
      }
      pvVar1 = operator_new(__n_00);
      __dest_00 = *(void **)this;
    }
    if (pvVar3 != __src) {
      memmove(pvVar1,__src,__n_00);
    }
    if (__dest_00 != (void *)0x0) {
      operator_delete(__dest_00);
    }
    iVar2 = __n_00 + (int)pvVar1;
    *(int *)(this + 8) = iVar2;
    *(void **)this = pvVar1;
    goto LAB_0001dc0e;
  }
  __dest = *(void **)(this + 4);
  __n = (int)__dest - (int)__dest_00;
  if ((void *)((int)__n >> 2) < pvVar1) {
    pvVar1 = (void *)((int)__src + __n);
    if (__src == pvVar1) {
      if (pvVar3 != pvVar1) {
LAB_0001dc54:
        memmove(__dest,pvVar1,(int)pvVar3 - (int)pvVar1);
        iVar2 = __n_00 + *(int *)this;
        goto LAB_0001dc0e;
      }
    }
    else {
      memmove(__dest_00,__src,__n);
      __dest_00 = *(void **)this;
      __dest = *(void **)(this + 4);
      pvVar3 = *(void **)(param_1 + 4);
      pvVar1 = (void *)((int)__dest + (*(int *)param_1 - (int)__dest_00));
      if (pvVar3 != pvVar1) goto LAB_0001dc54;
    }
  }
  else if (pvVar3 != __src) {
    memmove(__dest_00,__src,__n_00);
    iVar2 = __n_00 + *(int *)this;
    goto LAB_0001dc0e;
  }
  iVar2 = __n_00 + (int)__dest_00;
LAB_0001dc0e:
  *(int *)(this + 4) = iVar2;
  return this;
}



/* std::vector<retina_head_t, std::allocator<retina_head_t>
   >::TEMPNAMEPLACEHOLDERVALUE(std::vector<retina_head_t, std::allocator<retina_head_t> > const&) */

vector<retina_head_t,std::allocator<retina_head_t>> * __thiscall
std::vector<retina_head_t,std::allocator<retina_head_t>>::operator=
          (vector<retina_head_t,std::allocator<retina_head_t>> *this,vector *param_1)

{
  vector<int,std::allocator<int>> *pvVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  void *pvVar6;
  vector *pvVar7;
  vector *pvVar8;
  vector<int,std::allocator<int>> *pvVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  uint uVar14;
  size_t sVar15;
  vector *pvVar16;
  vector<int,std::allocator<int>> *pvVar17;
  
  if (param_1 == (vector *)this) {
    return this;
  }
  pvVar7 = *(vector **)param_1;
  pvVar16 = *(vector **)(param_1 + 4);
  pvVar9 = *(vector<int,std::allocator<int>> **)this;
  uVar3 = (int)pvVar16 - (int)pvVar7;
  puVar12 = (undefined4 *)(((int)uVar3 >> 2) * -0x45d1745d);
  if ((undefined4 *)((*(int *)(this + 8) - (int)pvVar9 >> 2) * -0x45d1745d) < puVar12) {
    puVar11 = puVar12;
    if (puVar12 != (undefined4 *)0x0) {
      if ((undefined4 *)0x5d1745d < puVar12) {
                    /* WARNING: Subroutine does not return */
        std::__throw_bad_alloc();
      }
      puVar12 = (undefined4 *)operator_new(uVar3);
      puVar11 = puVar12;
    }
    for (; pvVar7 != pvVar16; pvVar7 = pvVar7 + 0x2c) {
      if (puVar12 != (undefined4 *)0x0) {
        iVar13 = *(int *)pvVar7;
        iVar4 = *(int *)(pvVar7 + 4);
        *puVar12 = 0;
        uVar14 = iVar4 - iVar13;
        puVar12[1] = 0;
        puVar12[2] = 0;
        pvVar6 = (void *)((int)uVar14 >> 2);
        if (pvVar6 != (void *)0x0) {
          if ((void *)0x3fffffff < pvVar6) {
                    /* WARNING: Subroutine does not return */
            std::__throw_bad_alloc();
          }
          pvVar6 = operator_new(uVar14);
        }
        puVar12[2] = (int)pvVar6 + uVar14;
        *puVar12 = pvVar6;
        puVar12[1] = pvVar6;
        pvVar2 = *(void **)pvVar7;
        sVar15 = (int)*(void **)(pvVar7 + 4) - (int)pvVar2;
        if (*(void **)(pvVar7 + 4) != pvVar2) {
          pvVar6 = memmove(pvVar6,pvVar2,sVar15);
        }
        puVar12[1] = (int)pvVar6 + sVar15;
        iVar13 = *(int *)(pvVar7 + 0xc);
        iVar4 = *(int *)(pvVar7 + 0x10);
        puVar12[3] = 0;
        uVar14 = iVar4 - iVar13;
        puVar12[4] = 0;
        puVar12[5] = 0;
        pvVar6 = (void *)((int)uVar14 >> 2);
        if (pvVar6 != (void *)0x0) {
          if ((void *)0x3fffffff < pvVar6) {
                    /* WARNING: Subroutine does not return */
            std::__throw_bad_alloc();
          }
          pvVar6 = operator_new(uVar14);
        }
        puVar12[5] = (int)pvVar6 + uVar14;
        puVar12[3] = pvVar6;
        puVar12[4] = pvVar6;
        pvVar2 = *(void **)(pvVar7 + 0xc);
        sVar15 = (int)*(void **)(pvVar7 + 0x10) - (int)pvVar2;
        if (*(void **)(pvVar7 + 0x10) != pvVar2) {
          pvVar6 = memmove(pvVar6,pvVar2,sVar15);
        }
        puVar12[4] = (int)pvVar6 + sVar15;
        iVar13 = *(int *)(pvVar7 + 0x18);
        iVar4 = *(int *)(pvVar7 + 0x1c);
        puVar12[6] = 0;
        uVar14 = iVar4 - iVar13;
        puVar12[7] = 0;
        puVar12[8] = 0;
        pvVar6 = (void *)((int)uVar14 >> 2);
        if (pvVar6 != (void *)0x0) {
          if ((void *)0x3fffffff < pvVar6) {
                    /* WARNING: Subroutine does not return */
            std::__throw_bad_alloc();
          }
          pvVar6 = operator_new(uVar14);
        }
        puVar12[8] = (int)pvVar6 + uVar14;
        puVar12[6] = pvVar6;
        puVar12[7] = pvVar6;
        pvVar2 = *(void **)(pvVar7 + 0x18);
        sVar15 = (int)*(void **)(pvVar7 + 0x1c) - (int)pvVar2;
        if (*(void **)(pvVar7 + 0x1c) != pvVar2) {
          pvVar6 = memmove(pvVar6,pvVar2,sVar15);
        }
        iVar4 = *(int *)(pvVar7 + 0x24);
        iVar13 = *(int *)(pvVar7 + 0x28);
        puVar12[7] = (int)pvVar6 + sVar15;
        puVar12[9] = iVar4;
        puVar12[10] = iVar13;
      }
      puVar12 = puVar12 + 0xb;
    }
    puVar12 = *(undefined4 **)this;
    puVar10 = *(undefined4 **)(this + 4);
    if (puVar12 != puVar10) {
      do {
        if ((void *)puVar12[6] != (void *)0x0) {
          operator_delete((void *)puVar12[6]);
        }
        if ((void *)puVar12[3] != (void *)0x0) {
          operator_delete((void *)puVar12[3]);
        }
        if ((void *)*puVar12 != (void *)0x0) {
          operator_delete((void *)*puVar12);
        }
        puVar12 = puVar12 + 0xb;
      } while (puVar10 != puVar12);
      puVar10 = *(undefined4 **)this;
    }
    if (puVar10 != (undefined4 *)0x0) {
      operator_delete(puVar10);
    }
    *(undefined4 **)this = puVar11;
    pvVar9 = (vector<int,std::allocator<int>> *)(uVar3 + (int)puVar11);
    *(vector<int,std::allocator<int>> **)(this + 8) = pvVar9;
    goto LAB_0001dd48;
  }
  pvVar17 = *(vector<int,std::allocator<int>> **)(this + 4);
  iVar4 = (int)pvVar17 - (int)pvVar9;
  puVar11 = (undefined4 *)((iVar4 >> 2) * -0x45d1745d);
  if (puVar12 < puVar11 || (int)puVar12 + (iVar4 >> 2) * 0x45d1745d == 0) {
    if (0 < (int)uVar3) {
      do {
        vector<int,std::allocator<int>>::operator=(pvVar9,pvVar7);
        vector<int,std::allocator<int>>::operator=(pvVar9 + 0xc,pvVar7 + 0xc);
        vector<int,std::allocator<int>>::operator=(pvVar9 + 0x18,pvVar7 + 0x18);
        pvVar16 = pvVar7 + 0x24;
        uVar5 = *(undefined4 *)(pvVar7 + 0x28);
        puVar12 = (undefined4 *)((int)puVar12 + -1);
        pvVar7 = pvVar7 + 0x2c;
        *(undefined4 *)(pvVar9 + 0x24) = *(undefined4 *)pvVar16;
        *(undefined4 *)(pvVar9 + 0x28) = uVar5;
        pvVar9 = pvVar9 + 0x2c;
      } while (puVar12 != (undefined4 *)0x0);
      pvVar17 = *(vector<int,std::allocator<int>> **)(this + 4);
    }
    for (; pvVar9 != pvVar17; pvVar9 = pvVar9 + 0x2c) {
      if (*(void **)(pvVar9 + 0x18) != (void *)0x0) {
        operator_delete(*(void **)(pvVar9 + 0x18));
      }
      if (*(void **)(pvVar9 + 0xc) != (void *)0x0) {
        operator_delete(*(void **)(pvVar9 + 0xc));
      }
      if (*(void **)pvVar9 != (void *)0x0) {
        operator_delete(*(void **)pvVar9);
      }
    }
LAB_0001dd40:
    pvVar9 = *(vector<int,std::allocator<int>> **)this;
  }
  else {
    if (0 < iVar4) {
      do {
        vector<int,std::allocator<int>>::operator=(pvVar9,pvVar7);
        vector<int,std::allocator<int>>::operator=(pvVar9 + 0xc,pvVar7 + 0xc);
        vector<int,std::allocator<int>>::operator=(pvVar9 + 0x18,pvVar7 + 0x18);
        pvVar16 = pvVar7 + 0x24;
        uVar5 = *(undefined4 *)(pvVar7 + 0x28);
        puVar11 = (undefined4 *)((int)puVar11 + -1);
        pvVar7 = pvVar7 + 0x2c;
        *(undefined4 *)(pvVar9 + 0x24) = *(undefined4 *)pvVar16;
        *(undefined4 *)(pvVar9 + 0x28) = uVar5;
        pvVar9 = pvVar9 + 0x2c;
      } while (puVar11 != (undefined4 *)0x0);
      pvVar9 = *(vector<int,std::allocator<int>> **)this;
      pvVar17 = *(vector<int,std::allocator<int>> **)(this + 4);
      pvVar7 = *(vector **)param_1;
      iVar4 = (int)pvVar17 - (int)pvVar9;
      pvVar16 = *(vector **)(param_1 + 4);
    }
    pvVar8 = pvVar7 + iVar4;
    pvVar1 = pvVar17;
    if (pvVar7 + iVar4 != pvVar16) {
      do {
        pvVar7 = pvVar8 + 0x2c;
        if (pvVar17 != (vector<int,std::allocator<int>> *)0x0) {
          iVar4 = *(int *)pvVar8;
          iVar13 = *(int *)(pvVar8 + 4);
          *(undefined4 *)pvVar1 = 0;
          uVar14 = iVar13 - iVar4;
          *(undefined4 *)(pvVar1 + 4) = 0;
          *(undefined4 *)(pvVar1 + 8) = 0;
          pvVar6 = (void *)((int)uVar14 >> 2);
          if (pvVar6 != (void *)0x0) {
            if ((void *)0x3fffffff < pvVar6) {
                    /* WARNING: Subroutine does not return */
              std::__throw_bad_alloc();
            }
            pvVar6 = operator_new(uVar14);
          }
          *(uint *)(pvVar1 + 8) = uVar14 + (int)pvVar6;
          *(void **)pvVar1 = pvVar6;
          *(void **)(pvVar1 + 4) = pvVar6;
          pvVar2 = *(void **)pvVar8;
          sVar15 = (int)*(void **)(pvVar8 + 4) - (int)pvVar2;
          if (*(void **)(pvVar8 + 4) != pvVar2) {
            pvVar6 = memmove(pvVar6,pvVar2,sVar15);
          }
          *(size_t *)(pvVar1 + 4) = (int)pvVar6 + sVar15;
          iVar4 = *(int *)(pvVar8 + 0xc);
          iVar13 = *(int *)(pvVar8 + 0x10);
          *(undefined4 *)(pvVar1 + 0xc) = 0;
          uVar14 = iVar13 - iVar4;
          *(undefined4 *)(pvVar1 + 0x10) = 0;
          *(undefined4 *)(pvVar1 + 0x14) = 0;
          pvVar6 = (void *)((int)uVar14 >> 2);
          if (pvVar6 != (void *)0x0) {
            if ((void *)0x3fffffff < pvVar6) {
                    /* WARNING: Subroutine does not return */
              std::__throw_bad_alloc();
            }
            pvVar6 = operator_new(uVar14);
          }
          *(uint *)(pvVar1 + 0x14) = uVar14 + (int)pvVar6;
          *(void **)(pvVar1 + 0xc) = pvVar6;
          *(void **)(pvVar1 + 0x10) = pvVar6;
          pvVar2 = *(void **)(pvVar8 + 0xc);
          sVar15 = (int)*(void **)(pvVar8 + 0x10) - (int)pvVar2;
          if (*(void **)(pvVar8 + 0x10) != pvVar2) {
            pvVar6 = memmove(pvVar6,pvVar2,sVar15);
          }
          *(size_t *)(pvVar1 + 0x10) = (int)pvVar6 + sVar15;
          iVar4 = *(int *)(pvVar8 + 0x18);
          iVar13 = *(int *)(pvVar8 + 0x1c);
          *(undefined4 *)(pvVar1 + 0x18) = 0;
          uVar14 = iVar13 - iVar4;
          *(undefined4 *)(pvVar1 + 0x1c) = 0;
          *(undefined4 *)(pvVar1 + 0x20) = 0;
          pvVar6 = (void *)((int)uVar14 >> 2);
          if (pvVar6 != (void *)0x0) {
            if ((void *)0x3fffffff < pvVar6) {
                    /* WARNING: Subroutine does not return */
              std::__throw_bad_alloc();
            }
            pvVar6 = operator_new(uVar14);
          }
          *(uint *)(pvVar1 + 0x20) = uVar14 + (int)pvVar6;
          *(void **)(pvVar1 + 0x18) = pvVar6;
          *(void **)(pvVar1 + 0x1c) = pvVar6;
          pvVar2 = *(void **)(pvVar8 + 0x18);
          sVar15 = (int)*(void **)(pvVar8 + 0x1c) - (int)pvVar2;
          if (*(void **)(pvVar8 + 0x1c) != pvVar2) {
            pvVar6 = memmove(pvVar6,pvVar2,sVar15);
          }
          iVar4 = *(int *)(pvVar8 + 0x24);
          iVar13 = *(int *)(pvVar8 + 0x28);
          *(size_t *)(pvVar1 + 0x1c) = (int)pvVar6 + sVar15;
          *(int *)(pvVar1 + 0x24) = iVar4;
          *(int *)(pvVar1 + 0x28) = iVar13;
        }
        pvVar17 = pvVar17 + 0x2c;
        pvVar8 = pvVar7;
        pvVar1 = pvVar1 + 0x2c;
      } while (pvVar16 != pvVar7);
      goto LAB_0001dd40;
    }
  }
  pvVar9 = pvVar9 + uVar3;
LAB_0001dd48:
  *(vector<int,std::allocator<int>> **)(this + 4) = pvVar9;
  return this;
}



/* void std::vector<ez_model_info_t, std::allocator<ez_model_info_t>
   >::_M_realloc_insert<ez_model_info_t const&>(__gnu_cxx::__normal_iterator<ez_model_info_t*,
   std::vector<ez_model_info_t, std::allocator<ez_model_info_t> > >, ez_model_info_t const&) */

void __thiscall
std::vector<ez_model_info_t,std::allocator<ez_model_info_t>>::
_M_realloc_insert<ez_model_info_t_const&>
          (vector<ez_model_info_t,std::allocator<ez_model_info_t>> *this,void *param_2,
          undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  void *pvVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  uint uVar15;
  
  iVar9 = *(int *)this;
  iVar5 = *(int *)(this + 4) - iVar9 >> 3;
  uVar7 = iVar5 * -0x49249249;
  if (uVar7 == 0) {
    uVar7 = 1;
LAB_0001e2d6:
    uVar15 = uVar7 * 0x38;
  }
  else {
    uVar15 = iVar5 * 0x6db6db6e;
    if (uVar7 < uVar15 || uVar7 == 0) {
      uVar7 = 0x4924924;
      if (uVar15 < 0x4924925) {
        uVar7 = uVar15;
        if (uVar15 == 0) {
          puVar1 = (undefined4 *)0x0;
          goto LAB_0001e0f2;
        }
        goto LAB_0001e2d6;
      }
      uVar15 = 0xffffffe0;
    }
    else {
      uVar15 = 0xffffffe0;
      uVar7 = 0x4924924;
    }
  }
  puVar1 = (undefined4 *)operator_new(uVar15);
  uVar15 = uVar7;
LAB_0001e0f2:
  puVar10 = (undefined4 *)((int)puVar1 + ((int)param_2 - iVar9));
  if (puVar10 != (undefined4 *)0x0) {
    uVar2 = param_3[1];
    iVar9 = param_3[2];
    iVar5 = param_3[3];
    *puVar10 = *param_3;
    puVar10[1] = uVar2;
    puVar10[2] = puVar10 + 4;
    FUN_0001da5c(puVar10 + 2,iVar9,iVar5 + iVar9);
    uVar2 = param_3[8];
    puVar10[8] = puVar10 + 10;
    FUN_0001da5c(puVar10 + 8,uVar2);
  }
  puVar10 = puVar1;
  if (*(void **)this != param_2) {
    iVar5 = (int)*(void **)this + 0x38;
    uVar7 = (int)param_2 - iVar5;
    do {
      if (puVar10 != (undefined4 *)0x0) {
        puVar13 = (undefined4 *)(iVar5 + -0x28);
        uVar2 = *(undefined4 *)(iVar5 + -0x38);
        uVar3 = *(undefined4 *)(iVar5 + -0x34);
        puVar10[2] = puVar10 + 4;
        *puVar10 = uVar2;
        puVar10[1] = uVar3;
        if (*(undefined4 **)(iVar5 + -0x30) == puVar13) {
          uVar14 = *(undefined4 *)(iVar5 + -0x24);
          uVar2 = *(undefined4 *)(iVar5 + -0x20);
          uVar3 = *(undefined4 *)(iVar5 + -0x1c);
          puVar10[4] = *puVar13;
          puVar10[5] = uVar14;
          puVar10[6] = uVar2;
          puVar10[7] = uVar3;
        }
        else {
          puVar10[2] = *(undefined4 **)(iVar5 + -0x30);
          puVar10[4] = *(undefined4 *)(iVar5 + -0x28);
        }
        puVar10[3] = *(undefined4 *)(iVar5 + -0x2c);
        puVar4 = (undefined4 *)(iVar5 + -0x10);
        *(undefined4 **)(iVar5 + -0x30) = puVar13;
        *(undefined4 *)(iVar5 + -0x2c) = 0;
        *(undefined1 *)(iVar5 + -0x28) = 0;
        puVar10[8] = puVar10 + 10;
        if (*(undefined4 **)(iVar5 + -0x18) == puVar4) {
          uVar14 = *(undefined4 *)(iVar5 + -0xc);
          uVar3 = *(undefined4 *)(iVar5 + -8);
          uVar2 = *(undefined4 *)(iVar5 + -4);
          puVar10[10] = *puVar4;
          puVar10[0xb] = uVar14;
          puVar10[0xc] = uVar3;
          puVar10[0xd] = uVar2;
        }
        else {
          puVar10[8] = *(undefined4 **)(iVar5 + -0x18);
          puVar10[10] = *(undefined4 *)(iVar5 + -0x10);
        }
        puVar10[9] = *(undefined4 *)(iVar5 + -0x14);
        *(undefined4 **)(iVar5 + -0x18) = puVar4;
        *(undefined4 *)(iVar5 + -0x14) = 0;
        *(undefined1 *)(iVar5 + -0x10) = 0;
      }
      puVar10 = puVar10 + 0xe;
      iVar5 = iVar5 + 0x38;
    } while (puVar10 != puVar1 + (((uVar7 >> 3) * 0x16db6db7 & 0x1fffffff) + 1) * 0xe);
  }
  puVar13 = puVar10 + 0xe;
  if (*(void **)(this + 4) != param_2) {
    iVar5 = (int)param_2 + 0x38;
    uVar7 = ((uint)((int)*(void **)(this + 4) - iVar5) >> 3) * 0x16db6db7 & 0x1fffffff;
    puVar4 = puVar13;
    do {
      if (puVar4 != (undefined4 *)0x0) {
        puVar11 = *(undefined4 **)(iVar5 + -0x30);
        uVar2 = *(undefined4 *)(iVar5 + -0x38);
        uVar3 = *(undefined4 *)(iVar5 + -0x34);
        puVar4[2] = puVar4 + 4;
        puVar6 = (undefined4 *)(iVar5 + -0x28);
        *puVar4 = uVar2;
        puVar4[1] = uVar3;
        if (puVar11 == puVar6) {
          uVar2 = *(undefined4 *)(iVar5 + -0x24);
          puVar4[4] = *puVar6;
          puVar4[5] = uVar2;
          uVar2 = *(undefined4 *)(iVar5 + -0x1c);
          puVar4[6] = *(undefined4 *)(iVar5 + -0x20);
          puVar4[7] = uVar2;
        }
        else {
          uVar2 = *(undefined4 *)(iVar5 + -0x28);
          puVar4[2] = puVar11;
          puVar4[4] = uVar2;
        }
        puVar12 = *(undefined4 **)(iVar5 + -0x18);
        puVar11 = (undefined4 *)(iVar5 + -0x10);
        *(undefined4 **)(iVar5 + -0x30) = puVar6;
        *(undefined1 *)(iVar5 + -0x28) = 0;
        puVar4[3] = *(undefined4 *)(iVar5 + -0x2c);
        *(undefined4 *)(iVar5 + -0x2c) = 0;
        puVar4[8] = puVar4 + 10;
        if (puVar12 == puVar11) {
          uVar2 = *(undefined4 *)(iVar5 + -0xc);
          puVar4[10] = *puVar11;
          puVar4[0xb] = uVar2;
          uVar2 = *(undefined4 *)(iVar5 + -4);
          puVar4[0xc] = *(undefined4 *)(iVar5 + -8);
          puVar4[0xd] = uVar2;
        }
        else {
          uVar2 = *(undefined4 *)(iVar5 + -0x10);
          puVar4[8] = puVar12;
          puVar4[10] = uVar2;
        }
        *(undefined4 **)(iVar5 + -0x18) = puVar11;
        *(undefined1 *)(iVar5 + -0x10) = 0;
        puVar4[9] = *(undefined4 *)(iVar5 + -0x14);
        *(undefined4 *)(iVar5 + -0x14) = 0;
      }
      puVar4 = puVar4 + 0xe;
      iVar5 = iVar5 + 0x38;
    } while (puVar4 != puVar10 + uVar7 * 0xe + 0x1c);
    param_2 = *(void **)(this + 4);
    puVar13 = puVar13 + (uVar7 + 1) * 0xe;
  }
  pvVar8 = *(void **)this;
  if (pvVar8 != param_2) {
    do {
      if (*(void **)((int)pvVar8 + 0x20) != (void *)((int)pvVar8 + 0x28)) {
        operator_delete(*(void **)((int)pvVar8 + 0x20));
      }
      if (*(void **)((int)pvVar8 + 8) != (void *)((int)pvVar8 + 0x10)) {
        operator_delete(*(void **)((int)pvVar8 + 8));
      }
      pvVar8 = (void *)((int)pvVar8 + 0x38);
    } while (param_2 != pvVar8);
    param_2 = *(void **)this;
  }
  if (param_2 != (void *)0x0) {
    operator_delete(param_2);
  }
  *(undefined4 **)this = puVar1;
  *(undefined4 **)(this + 4) = puVar13;
  *(undefined4 **)(this + 8) = puVar1 + uVar15 * 0xe;
  return;
}



/* void std::vector<retina_head_t, std::allocator<retina_head_t> >::_M_realloc_insert<retina_head_t
   const&>(__gnu_cxx::__normal_iterator<retina_head_t*, std::vector<retina_head_t,
   std::allocator<retina_head_t> > >, retina_head_t const&) */

void __thiscall
std::vector<retina_head_t,std::allocator<retina_head_t>>::_M_realloc_insert<retina_head_t_const&>
          (vector<retina_head_t,std::allocator<retina_head_t>> *this,undefined4 *param_2,
          int *param_3)

{
  undefined4 *puVar1;
  void *pvVar2;
  void *pvVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  undefined4 uVar15;
  int iVar16;
  uint uVar17;
  uint local_34;
  
  iVar16 = (int)param_2 - *(int *)this;
  iVar6 = *(int *)(this + 4) - *(int *)this >> 2;
  uVar8 = iVar6 * -0x45d1745d;
  if (uVar8 == 0) {
    local_34 = 1;
LAB_0001e686:
    uVar8 = local_34 * 0x2c;
LAB_0001e3ce:
    puVar1 = (undefined4 *)operator_new(uVar8);
  }
  else {
    local_34 = iVar6 * 0x745d1746;
    if (local_34 <= uVar8 && uVar8 != 0) {
      uVar8 = 0xfffffffc;
      local_34 = 0x5d1745d;
      goto LAB_0001e3ce;
    }
    if (0x5d1745d < local_34) {
      uVar8 = 0xfffffffc;
      local_34 = 0x5d1745d;
      goto LAB_0001e3ce;
    }
    if (local_34 != 0) goto LAB_0001e686;
    puVar1 = (undefined4 *)0x0;
  }
  puVar11 = (undefined4 *)((int)puVar1 + iVar16);
  if (puVar11 != (undefined4 *)0x0) {
    pvVar5 = (void *)*param_3;
    pvVar2 = (void *)param_3[1];
    *(undefined4 *)((int)puVar1 + iVar16) = 0;
    uVar8 = (int)pvVar2 - (int)pvVar5;
    puVar11[1] = 0;
    puVar11[2] = 0;
    if ((int)uVar8 >> 2 == 0) {
      pvVar3 = (void *)0x0;
      uVar17 = uVar8;
    }
    else {
      if (0x3fffffff < (uint)((int)uVar8 >> 2)) {
                    /* WARNING: Subroutine does not return */
        std::__throw_bad_alloc();
      }
      pvVar3 = operator_new(uVar8);
      pvVar5 = (void *)*param_3;
      pvVar2 = (void *)param_3[1];
      uVar17 = (int)pvVar2 - (int)pvVar5;
    }
    puVar11[2] = (int)pvVar3 + uVar8;
    *puVar11 = pvVar3;
    puVar11[1] = pvVar3;
    if (pvVar5 != pvVar2) {
      pvVar3 = memmove(pvVar3,pvVar5,uVar17);
    }
    pvVar5 = (void *)param_3[3];
    pvVar2 = (void *)param_3[4];
    uVar8 = (int)pvVar2 - (int)pvVar5;
    puVar11[1] = (int)pvVar3 + uVar17;
    puVar11[3] = 0;
    puVar11[4] = 0;
    puVar11[5] = 0;
    if ((int)uVar8 >> 2 == 0) {
      pvVar3 = (void *)0x0;
      uVar17 = uVar8;
    }
    else {
      if (0x3fffffff < (uint)((int)uVar8 >> 2)) {
                    /* WARNING: Subroutine does not return */
        std::__throw_bad_alloc();
      }
      pvVar3 = operator_new(uVar8);
      pvVar5 = (void *)param_3[3];
      pvVar2 = (void *)param_3[4];
      uVar17 = (int)pvVar2 - (int)pvVar5;
    }
    puVar11[5] = (int)pvVar3 + uVar8;
    puVar11[3] = pvVar3;
    puVar11[4] = pvVar3;
    if (pvVar5 != pvVar2) {
      pvVar3 = memmove(pvVar3,pvVar5,uVar17);
    }
    pvVar5 = (void *)param_3[6];
    pvVar2 = (void *)param_3[7];
    uVar8 = (int)pvVar2 - (int)pvVar5;
    puVar11[4] = (int)pvVar3 + uVar17;
    puVar11[6] = 0;
    puVar11[7] = 0;
    puVar11[8] = 0;
    if ((int)uVar8 >> 2 == 0) {
      pvVar3 = (void *)0x0;
      uVar17 = uVar8;
    }
    else {
      if (0x3fffffff < (uint)((int)uVar8 >> 2)) {
                    /* WARNING: Subroutine does not return */
        std::__throw_bad_alloc();
      }
      pvVar3 = operator_new(uVar8);
      pvVar5 = (void *)param_3[6];
      pvVar2 = (void *)param_3[7];
      uVar17 = (int)pvVar2 - (int)pvVar5;
    }
    puVar11[8] = (int)pvVar3 + uVar8;
    puVar11[6] = pvVar3;
    puVar11[7] = pvVar3;
    if (pvVar2 != pvVar5) {
      pvVar3 = memmove(pvVar3,pvVar5,uVar17);
    }
    iVar6 = param_3[9];
    iVar16 = param_3[10];
    puVar11[7] = (int)pvVar3 + uVar17;
    puVar11[9] = iVar6;
    puVar11[10] = iVar16;
  }
  puVar11 = *(undefined4 **)this;
  puVar14 = *(undefined4 **)(this + 4);
  if (puVar11 == param_2) {
    puVar9 = puVar1 + 0xb;
    if (param_2 == puVar14) goto LAB_0001e6ba;
LAB_0001e5e2:
    param_2 = param_2 + 0xb;
    puVar4 = puVar9 + ((((uint)((int)puVar14 - (int)param_2) >> 2) * 0x3a2e8ba3 & 0x3fffffff) + 1) *
                      0xb;
    do {
      if (puVar9 != (undefined4 *)0x0) {
        uVar10 = param_2[-9];
        uVar15 = param_2[-0xb];
        puVar9[1] = param_2[-10];
        puVar9[2] = uVar10;
        uVar10 = param_2[-7];
        uVar13 = param_2[-6];
        *puVar9 = uVar15;
        puVar9[4] = uVar10;
        uVar15 = param_2[-8];
        uVar10 = param_2[-4];
        puVar9[5] = uVar13;
        uVar13 = param_2[-3];
        puVar9[3] = uVar15;
        puVar9[7] = uVar10;
        uVar15 = param_2[-5];
        uVar10 = param_2[-1];
        puVar9[8] = uVar13;
        uVar13 = param_2[-2];
        param_2[-0xb] = 0;
        param_2[-10] = 0;
        param_2[-9] = 0;
        param_2[-8] = 0;
        param_2[-7] = 0;
        param_2[-6] = 0;
        puVar9[6] = uVar15;
        param_2[-5] = 0;
        param_2[-4] = 0;
        param_2[-3] = 0;
        puVar9[9] = uVar13;
        puVar9[10] = uVar10;
      }
      puVar9 = puVar9 + 0xb;
      param_2 = param_2 + 0xb;
    } while (puVar9 != puVar4);
    if (puVar11 == puVar14) goto LAB_0001e6ba;
    puVar12 = puVar11 + 0xb;
  }
  else {
    puVar12 = puVar11 + 0xb;
    uVar8 = ((uint)((int)param_2 - (int)puVar12) >> 2) * 0x3a2e8ba3 & 0x3fffffff;
    puVar4 = puVar1;
    puVar7 = puVar12;
    puVar9 = puVar1;
    do {
      if (puVar4 != (undefined4 *)0x0) {
        *puVar9 = 0;
        puVar9[1] = 0;
        puVar9[2] = 0;
        *puVar9 = puVar7[-0xb];
        puVar7[-0xb] = 0;
        uVar10 = puVar9[1];
        puVar9[1] = puVar7[-10];
        puVar7[-10] = uVar10;
        uVar10 = puVar9[2];
        puVar9[2] = puVar7[-9];
        puVar7[-9] = uVar10;
        puVar9[3] = 0;
        puVar9[4] = 0;
        puVar9[5] = 0;
        puVar9[3] = puVar7[-8];
        puVar7[-8] = 0;
        uVar10 = puVar9[4];
        puVar9[4] = puVar7[-7];
        puVar7[-7] = uVar10;
        uVar10 = puVar9[5];
        puVar9[5] = puVar7[-6];
        puVar7[-6] = uVar10;
        puVar9[6] = 0;
        puVar9[7] = 0;
        puVar9[8] = 0;
        puVar9[6] = puVar7[-5];
        puVar7[-5] = 0;
        uVar10 = puVar9[7];
        puVar9[7] = puVar7[-4];
        puVar7[-4] = uVar10;
        uVar13 = puVar7[-2];
        uVar15 = puVar9[8];
        puVar9[8] = puVar7[-3];
        uVar10 = puVar7[-1];
        puVar7[-3] = uVar15;
        puVar9[9] = uVar13;
        puVar9[10] = uVar10;
      }
      puVar4 = puVar4 + 0xb;
      puVar7 = puVar7 + 0xb;
      puVar9 = puVar9 + 0xb;
    } while (puVar4 != puVar1 + (uVar8 + 1) * 0xb);
    puVar9 = puVar1 + uVar8 * 0xb + 0x16;
    if (param_2 != puVar14) goto LAB_0001e5e2;
  }
  while( true ) {
    puVar4 = puVar12;
    if ((void *)puVar11[6] != (void *)0x0) {
      operator_delete((void *)puVar11[6]);
    }
    if ((void *)puVar11[3] != (void *)0x0) {
      operator_delete((void *)puVar11[3]);
    }
    if ((void *)*puVar11 != (void *)0x0) {
      operator_delete((void *)*puVar11);
    }
    if (puVar4 == puVar14) break;
    puVar12 = puVar4 + 0xb;
    puVar11 = puVar4;
  }
  puVar14 = *(undefined4 **)this;
LAB_0001e6ba:
  if (puVar14 != (undefined4 *)0x0) {
    operator_delete(puVar14);
  }
  *(undefined4 **)this = puVar1;
  *(undefined4 **)(this + 4) = puVar9;
  *(undefined4 **)(this + 8) = puVar1 + local_34 * 0xb;
  return;
}



/* void std::vector<int, std::allocator<int>
   >::_M_realloc_insert<int>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int>
   > >, int&&) */

void __thiscall
std::vector<int,std::allocator<int>>::_M_realloc_insert<int>
          (vector<int,std::allocator<int>> *this,void *param_2,undefined4 *param_3)

{
  void *__dest;
  uint uVar1;
  void *__dest_00;
  size_t __n;
  void *__src;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  size_t sVar5;
  
  __src = *(void **)this;
  pvVar4 = *(void **)(this + 4);
  sVar5 = (int)param_2 - (int)__src;
  uVar1 = (int)pvVar4 - (int)__src >> 2;
  if (uVar1 == 0) {
    uVar2 = 1;
LAB_0001e7d6:
    uVar2 = uVar2 << 2;
  }
  else {
    uVar2 = uVar1 * 2;
    if ((uVar1 <= uVar2) && (uVar2 < 0x40000000)) {
      if (uVar2 == 0) {
        iVar3 = 0;
        __dest = (void *)0x0;
        __n = sVar5;
        goto LAB_0001e788;
      }
      goto LAB_0001e7d6;
    }
    uVar2 = 0xfffffffc;
  }
  __dest = operator_new(uVar2);
  __src = *(void **)this;
  iVar3 = uVar2 + (int)__dest;
  pvVar4 = *(void **)(this + 4);
  __n = (int)param_2 - (int)__src;
LAB_0001e788:
  if ((int)__dest + sVar5 != 0) {
    *(undefined4 *)((int)__dest + sVar5) = *param_3;
  }
  if (param_2 != __src) {
    memmove(__dest,__src,__n);
  }
  __dest_00 = (void *)(__n + 4 + (int)__dest);
  if (pvVar4 != param_2) {
    __dest_00 = memcpy(__dest_00,param_2,(int)pvVar4 - (int)param_2);
  }
  if (__src != (void *)0x0) {
    operator_delete(__src);
  }
  *(void **)this = __dest;
  *(int *)(this + 4) = (int)__dest_00 + ((int)pvVar4 - (int)param_2);
  *(int *)(this + 8) = iVar3;
  return;
}



/* void std::vector<int, std::allocator<int> >::emplace_back<int>(int&&) */

void __thiscall
std::vector<int,std::allocator<int>>::emplace_back<int>
          (vector<int,std::allocator<int>> *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 4);
  if (piVar1 == *(int **)(this + 8)) {
    _M_realloc_insert<int>(this,piVar1,param_1);
    return;
  }
  if (piVar1 != (int *)0x0) {
    *piVar1 = *param_1;
  }
  *(int **)(this + 4) = piVar1 + 1;
  return;
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* handdet_create(_vx_context*, ax_size_t, ax_rect_t, ImageFormat_E, int, char const*, int, int) */

void handdet_create(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,int param_6,int param_7,undefined4 param_8,int param_9,
                   undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  size_t sVar5;
  undefined4 uVar6;
  int iVar7;
  int local_1bc;
  void *local_1b8;
  undefined4 local_1b4;
  undefined4 uStack_1b0;
  void *local_1ac;
  undefined4 local_1a8;
  undefined4 uStack_1a4;
  undefined4 local_1a0 [10];
  undefined4 *local_178;
  undefined4 *local_174;
  undefined4 *local_170;
  void *local_16c;
  undefined4 local_168;
  undefined4 uStack_164;
  void *local_160;
  undefined4 uStack_15c;
  undefined4 local_158;
  void *local_154;
  undefined4 local_150;
  undefined4 uStack_14c;
  void *local_148;
  undefined4 uStack_144;
  undefined4 local_140;
  undefined **local_13c;
  float local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 *local_128;
  undefined4 *puStack_124;
  undefined4 local_120;
  undefined1 *local_11c [2];
  undefined1 auStack_114 [16];
  undefined1 *local_104 [2];
  undefined1 auStack_fc [16];
  undefined4 local_ec;
  undefined4 uStack_e8;
  undefined1 *local_e4;
  int local_e0;
  undefined1 local_dc [16];
  undefined1 *local_cc;
  int local_c8;
  undefined1 local_c4 [16];
  char acStack_b4 [128];
  int local_34;
  
  local_178 = (undefined4 *)0x0;
  local_174 = (undefined4 *)0x0;
  local_170 = (undefined4 *)0x0;
  local_16c = (void *)0x0;
  local_34 = __stack_chk_guard;
  iVar7 = 0;
  local_168 = 0;
  uStack_164 = 0;
  local_160 = (void *)0x0;
  uStack_15c = 0;
  local_158 = 0;
  local_154 = (void *)0x0;
  local_150 = 0;
  uStack_14c = 0;
  local_148 = (void *)0x0;
  uStack_144 = 0;
  local_140 = 0;
  local_128 = (undefined4 *)0x0;
  puStack_124 = (undefined4 *)0x0;
  local_120 = 0;
  local_1a0[0] = 0x100;
  local_1a0[1] = 0x140;
  local_1a0[2] = 0x100;
  local_1a0[3] = 0x160;
  local_1a0[4] = 0x160;
  local_1a0[5] = 0x100;
  local_1a0[6] = 0xe0;
  local_1a0[7] = 0x1a0;
  local_1a0[8] = 0x1a0;
  local_1a0[9] = 0xe0;
  do {
    if (param_9 == 0) {
      sprintf(acStack_b4,"%s/handdet%d.ezb",param_10,iVar7);
    }
    else {
      sprintf(acStack_b4,"%s/handdet1%d.ezb",param_10,iVar7);
    }
    local_11c[0] = auStack_114;
    sVar5 = strlen(acStack_b4);
    FUN_0001da5c(local_11c,acStack_b4,acStack_b4 + sVar5);
    sprintf(acStack_b4,"%s/handdet.bin",param_10);
    local_104[0] = auStack_fc;
    sVar5 = strlen(acStack_b4);
    FUN_0001da5c(local_104,acStack_b4,acStack_b4 + sVar5);
    local_ec = local_1a0[iVar7 * 2];
    uStack_e8 = local_1a0[iVar7 * 2 + 1];
    local_e0 = 0;
    local_dc[0] = 0;
    local_c8 = 0;
    local_c4[0] = 0;
    local_e4 = local_dc;
    local_cc = local_c4;
    std::__cxx11::string::_M_assign((string *)&local_e4);
    std::__cxx11::string::_M_assign((string *)&local_cc);
    puVar1 = local_174;
    if (local_174 == local_170) {
      std::vector<ez_model_info_t,std::allocator<ez_model_info_t>>::
      _M_realloc_insert<ez_model_info_t_const&>
                ((vector<ez_model_info_t,std::allocator<ez_model_info_t>> *)&local_178,local_174,
                 &local_ec);
    }
    else {
      if (local_174 != (undefined4 *)0x0) {
        local_174[2] = local_174 + 4;
        *local_174 = local_ec;
        local_174[1] = uStack_e8;
        FUN_0001da5c(local_174 + 2,local_e4,local_e4 + local_e0);
        puVar1[8] = puVar1 + 10;
        FUN_0001da5c(puVar1 + 8,local_cc,local_cc + local_c8);
      }
      local_174 = local_174 + 0xe;
    }
    if (local_cc != local_c4) {
      operator_delete(local_cc);
    }
    if (local_e4 != local_dc) {
      operator_delete(local_e4);
    }
    if (local_104[0] != auStack_fc) {
      operator_delete(local_104[0]);
    }
    if (local_11c[0] != auStack_114) {
      operator_delete(local_11c[0]);
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 != 5);
  local_1ac = (void *)0xfffffffd;
  local_1b8 = (void *)0x0;
  local_1b4 = 0;
  uStack_1b0 = 0;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1b8,(int *)&local_1ac);
  local_1ac = (void *)0xfffffffa;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1b8,(int *)&local_1ac);
  local_1ac = (void *)0xfffffffe;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1b8,(int *)&local_1ac);
  local_1ac = (void *)0xfffffffb;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1b8,(int *)&local_1ac);
  local_1ac = (void *)0xffffffff;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1b8,(int *)&local_1ac);
  local_1ac = (void *)0xfffffffc;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1b8,(int *)&local_1ac);
  local_1ac = (void *)0x0;
  local_1bc = 0;
  local_1a8 = 0;
  uStack_1a4 = 0;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1ac,&local_1bc);
  local_1bc = 2;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1ac,&local_1bc);
  local_1bc = 4;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1ac,&local_1bc);
  local_13c = &PTR_DAT_0003a524;
  std::vector<int,std::allocator<int>>::operator=
            ((vector<int,std::allocator<int>> *)&local_16c,(vector *)&local_1b8);
  std::vector<int,std::allocator<int>>::operator=
            ((vector<int,std::allocator<int>> *)&local_160,(vector *)&local_1ac);
  local_130 = param_12;
  local_138 = (float)(longlong)param_6 / (float)(longlong)param_7;
  local_134 = 1;
  local_12c = 1;
  uVar6 = retina_create(param_1,param_2,param_3,param_8,
                        (vector<ez_model_info_t,std::allocator<ez_model_info_t>> *)&local_178,
                        param_11);
  if (local_1ac != (void *)0x0) {
    operator_delete(local_1ac);
  }
  puVar1 = local_128;
  puVar2 = puStack_124;
  puVar3 = puStack_124;
  if (local_1b8 != (void *)0x0) {
    operator_delete(local_1b8);
    puVar1 = local_128;
    puVar2 = puStack_124;
    puVar3 = puStack_124;
  }
  for (; puVar4 = puStack_124, puVar1 != puStack_124; puVar1 = puVar1 + 0xb) {
    puStack_124 = puVar3;
    if ((void *)puVar1[6] != (void *)0x0) {
      operator_delete((void *)puVar1[6]);
    }
    if ((void *)puVar1[3] != (void *)0x0) {
      operator_delete((void *)puVar1[3]);
    }
    if ((void *)*puVar1 != (void *)0x0) {
      operator_delete((void *)*puVar1);
    }
    puVar2 = local_128;
    puVar3 = puStack_124;
    puStack_124 = puVar4;
  }
  puStack_124 = puVar3;
  if (puVar2 != (undefined4 *)0x0) {
    operator_delete(puVar2);
  }
  if (local_148 != (void *)0x0) {
    operator_delete(local_148);
  }
  if (local_154 != (void *)0x0) {
    operator_delete(local_154);
  }
  if (local_160 != (void *)0x0) {
    operator_delete(local_160);
  }
  puVar1 = local_178;
  puVar2 = local_174;
  puVar3 = local_174;
  if (local_16c != (void *)0x0) {
    operator_delete(local_16c);
    puVar1 = local_178;
    puVar2 = local_174;
    puVar3 = local_174;
  }
  for (; puVar4 = local_174, puVar1 != local_174; puVar1 = puVar1 + 0xe) {
    local_174 = puVar3;
    if ((undefined4 *)puVar1[8] != puVar1 + 10) {
      operator_delete((undefined4 *)puVar1[8]);
    }
    if ((undefined4 *)puVar1[2] != puVar1 + 4) {
      operator_delete((undefined4 *)puVar1[2]);
    }
    puVar2 = local_178;
    puVar3 = local_174;
    local_174 = puVar4;
  }
  local_174 = puVar3;
  if (puVar2 != (undefined4 *)0x0) {
    operator_delete(puVar2);
  }
  if (local_34 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* retina_campan_human_yolov3_create(_vx_context*, ax_size_t, ax_rect_t, ImageFormat_E, char const*,
   int) */

void retina_campan_human_yolov3_create
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9,
               undefined4 param_10)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  size_t sVar5;
  undefined4 uVar6;
  int iVar7;
  int local_1bc;
  void *local_1b8;
  undefined4 local_1b4;
  undefined4 uStack_1b0;
  void *local_1ac;
  undefined4 local_1a8;
  undefined4 uStack_1a4;
  undefined4 local_1a0 [10];
  undefined4 *local_178;
  undefined4 *local_174;
  undefined4 *puStack_170;
  void *local_16c;
  undefined4 uStack_168;
  undefined4 local_164;
  void *local_160;
  undefined4 local_15c;
  undefined4 uStack_158;
  void *local_154;
  undefined4 uStack_150;
  undefined4 local_14c;
  void *local_148;
  undefined4 local_144;
  undefined4 uStack_140;
  undefined **local_13c;
  float local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 *local_128;
  undefined4 *puStack_124;
  undefined4 local_120;
  undefined1 *local_11c [2];
  undefined1 auStack_114 [16];
  undefined1 *local_104 [2];
  undefined1 auStack_fc [16];
  undefined4 local_ec;
  undefined4 uStack_e8;
  undefined1 *local_e4;
  int local_e0;
  undefined1 local_dc [16];
  undefined1 *local_cc;
  int local_c8;
  undefined1 local_c4 [16];
  char acStack_b4 [128];
  int local_34;
  
  iVar7 = 0;
  local_34 = __stack_chk_guard;
  local_178 = (undefined4 *)0x0;
  local_174 = (undefined4 *)0x0;
  puStack_170 = (undefined4 *)0x0;
  local_16c = (void *)0x0;
  uStack_168 = 0;
  local_164 = 0;
  local_160 = (void *)0x0;
  local_15c = 0;
  uStack_158 = 0;
  local_154 = (void *)0x0;
  uStack_150 = 0;
  local_14c = 0;
  local_148 = (void *)0x0;
  local_144 = 0;
  uStack_140 = 0;
  local_128 = (undefined4 *)0x0;
  puStack_124 = (undefined4 *)0x0;
  local_120 = 0;
  local_1a0[0] = 0x140;
  local_1a0[1] = 0x140;
  local_1a0[2] = 0x100;
  local_1a0[3] = 0x160;
  local_1a0[4] = 0x160;
  local_1a0[5] = 0x100;
  local_1a0[6] = 0xe0;
  local_1a0[7] = 0x1a0;
  local_1a0[8] = 0x1a0;
  local_1a0[9] = 0xe0;
  do {
    sprintf(acStack_b4,"%s/human%d.ezb",param_9,iVar7);
    local_11c[0] = auStack_114;
    sVar5 = strlen(acStack_b4);
    FUN_0001da5c(local_11c,acStack_b4,acStack_b4 + sVar5);
    sprintf(acStack_b4,"%s/human.bin",param_9);
    local_104[0] = auStack_fc;
    sVar5 = strlen(acStack_b4);
    FUN_0001da5c(local_104,acStack_b4,acStack_b4 + sVar5);
    local_ec = local_1a0[iVar7 * 2];
    uStack_e8 = local_1a0[iVar7 * 2 + 1];
    local_e0 = 0;
    local_dc[0] = 0;
    local_c8 = 0;
    local_c4[0] = 0;
    local_e4 = local_dc;
    local_cc = local_c4;
    std::__cxx11::string::_M_assign((string *)&local_e4);
    std::__cxx11::string::_M_assign((string *)&local_cc);
    puVar1 = local_174;
    if (local_174 == puStack_170) {
      std::vector<ez_model_info_t,std::allocator<ez_model_info_t>>::
      _M_realloc_insert<ez_model_info_t_const&>
                ((vector<ez_model_info_t,std::allocator<ez_model_info_t>> *)&local_178,local_174,
                 &local_ec);
    }
    else {
      if (local_174 != (undefined4 *)0x0) {
        local_174[2] = local_174 + 4;
        *local_174 = local_ec;
        local_174[1] = uStack_e8;
        FUN_0001da5c(local_174 + 2,local_e4,local_e4 + local_e0);
        puVar1[8] = puVar1 + 10;
        FUN_0001da5c(puVar1 + 8,local_cc,local_cc + local_c8);
      }
      local_174 = local_174 + 0xe;
    }
    if (local_cc != local_c4) {
      operator_delete(local_cc);
    }
    if (local_e4 != local_dc) {
      operator_delete(local_e4);
    }
    if (local_104[0] != auStack_fc) {
      operator_delete(local_104[0]);
    }
    if (local_11c[0] != auStack_114) {
      operator_delete(local_11c[0]);
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 != 5);
  local_1ac = (void *)0x0;
  local_1b8 = (void *)0x0;
  local_1b4 = 0;
  uStack_1b0 = 0;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1b8,(int *)&local_1ac);
  local_1ac = (void *)0x1;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1b8,(int *)&local_1ac);
  local_1ac = (void *)0x2;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1b8,(int *)&local_1ac);
  local_1ac = (void *)0x0;
  local_1bc = 0;
  local_1a8 = 0;
  uStack_1a4 = 0;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1ac,&local_1bc);
  local_1bc = 1;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1ac,&local_1bc);
  local_1bc = 2;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1ac,&local_1bc);
  local_13c = &PTR_DAT_0003a538;
  std::vector<int,std::allocator<int>>::operator=
            ((vector<int,std::allocator<int>> *)&local_16c,(vector *)&local_1b8);
  std::vector<int,std::allocator<int>>::operator=
            ((vector<int,std::allocator<int>> *)&local_154,(vector *)&local_1ac);
  local_134 = 2;
  local_138 = (float)(longlong)param_6 / (float)(longlong)param_7;
  local_130 = param_10;
  local_12c = 1;
  uVar6 = retina_create(param_1,param_2,param_3,param_8,
                        (vector<ez_model_info_t,std::allocator<ez_model_info_t>> *)&local_178,
                        0xffffffff);
  if (local_1ac != (void *)0x0) {
    operator_delete(local_1ac);
  }
  puVar1 = local_128;
  puVar2 = puStack_124;
  puVar3 = puStack_124;
  if (local_1b8 != (void *)0x0) {
    operator_delete(local_1b8);
    puVar1 = local_128;
    puVar2 = puStack_124;
    puVar3 = puStack_124;
  }
  for (; puVar4 = puStack_124, puVar1 != puStack_124; puVar1 = puVar1 + 0xb) {
    puStack_124 = puVar3;
    if ((void *)puVar1[6] != (void *)0x0) {
      operator_delete((void *)puVar1[6]);
    }
    if ((void *)puVar1[3] != (void *)0x0) {
      operator_delete((void *)puVar1[3]);
    }
    if ((void *)*puVar1 != (void *)0x0) {
      operator_delete((void *)*puVar1);
    }
    puVar2 = local_128;
    puVar3 = puStack_124;
    puStack_124 = puVar4;
  }
  puStack_124 = puVar3;
  if (puVar2 != (undefined4 *)0x0) {
    operator_delete(puVar2);
  }
  if (local_148 != (void *)0x0) {
    operator_delete(local_148);
  }
  if (local_154 != (void *)0x0) {
    operator_delete(local_154);
  }
  if (local_160 != (void *)0x0) {
    operator_delete(local_160);
  }
  puVar1 = local_178;
  puVar2 = local_174;
  puVar3 = local_174;
  if (local_16c != (void *)0x0) {
    operator_delete(local_16c);
    puVar1 = local_178;
    puVar2 = local_174;
    puVar3 = local_174;
  }
  for (; puVar4 = local_174, puVar1 != local_174; puVar1 = puVar1 + 0xe) {
    local_174 = puVar3;
    if ((undefined4 *)puVar1[8] != puVar1 + 10) {
      operator_delete((undefined4 *)puVar1[8]);
    }
    if ((undefined4 *)puVar1[2] != puVar1 + 4) {
      operator_delete((undefined4 *)puVar1[2]);
    }
    puVar2 = local_178;
    puVar3 = local_174;
    local_174 = puVar4;
  }
  local_174 = puVar3;
  if (puVar2 != (undefined4 *)0x0) {
    operator_delete(puVar2);
  }
  if (local_34 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



/* campan_yolo_humanpose_det_create(_vx_context*, ax_size_t, ax_rect_t, ImageFormat_E, char const*,
   int, int) */

void campan_yolo_humanpose_det_create
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9,
               undefined4 param_10,undefined4 param_11)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  size_t sVar5;
  undefined4 uVar6;
  int local_188;
  void *local_184;
  undefined4 local_180;
  undefined4 uStack_17c;
  undefined4 *local_178;
  undefined4 *local_174;
  undefined4 *local_170;
  void *local_16c;
  undefined4 local_168;
  undefined4 uStack_164;
  void *local_160;
  undefined4 uStack_15c;
  undefined4 local_158;
  void *local_154;
  undefined4 local_150;
  undefined4 uStack_14c;
  void *local_148;
  undefined4 uStack_144;
  undefined4 local_140;
  undefined **local_13c;
  float local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 *local_128;
  undefined4 *puStack_124;
  undefined4 local_120;
  undefined1 *local_11c [2];
  undefined1 auStack_114 [16];
  undefined1 *local_104 [2];
  undefined1 auStack_fc [16];
  undefined4 local_ec;
  undefined4 local_e8;
  undefined1 *local_e4;
  int local_e0;
  undefined1 local_dc [16];
  undefined1 *local_cc;
  int local_c8;
  undefined1 local_c4 [16];
  char acStack_b4 [128];
  int local_34;
  
  local_34 = __stack_chk_guard;
  local_178 = (undefined4 *)0x0;
  local_174 = (undefined4 *)0x0;
  local_170 = (undefined4 *)0x0;
  local_16c = (void *)0x0;
  local_168 = 0;
  uStack_164 = 0;
  local_160 = (void *)0x0;
  uStack_15c = 0;
  local_158 = 0;
  local_154 = (void *)0x0;
  local_150 = 0;
  uStack_14c = 0;
  local_148 = (void *)0x0;
  uStack_144 = 0;
  local_140 = 0;
  local_128 = (undefined4 *)0x0;
  puStack_124 = (undefined4 *)0x0;
  local_120 = 0;
  sprintf(acStack_b4,"%s/yolopose.ezb",param_9);
  local_11c[0] = auStack_114;
  sVar5 = strlen(acStack_b4);
  FUN_0001da5c(local_11c,acStack_b4,acStack_b4 + sVar5);
  sprintf(acStack_b4,"%s/yolopose.bin",param_9);
  local_104[0] = auStack_fc;
  sVar5 = strlen(acStack_b4);
  FUN_0001da5c(local_104,acStack_b4,acStack_b4 + sVar5);
  local_e0 = 0;
  local_dc[0] = 0;
  local_c8 = 0;
  local_c4[0] = 0;
  local_ec = 0x1c0;
  local_e8 = 0x100;
  local_e4 = local_dc;
  local_cc = local_c4;
  std::__cxx11::string::_M_assign((string *)&local_e4);
  std::__cxx11::string::_M_assign((string *)&local_cc);
  puVar1 = local_174;
  if (local_174 == local_170) {
    std::vector<ez_model_info_t,std::allocator<ez_model_info_t>>::
    _M_realloc_insert<ez_model_info_t_const&>
              ((vector<ez_model_info_t,std::allocator<ez_model_info_t>> *)&local_178,local_174,
               &local_ec);
  }
  else {
    if (local_174 != (undefined4 *)0x0) {
      local_174[2] = local_174 + 4;
      *local_174 = local_ec;
      local_174[1] = local_e8;
      FUN_0001da5c(local_174 + 2,local_e4,local_e4 + local_e0);
      puVar1[8] = puVar1 + 10;
      FUN_0001da5c(puVar1 + 8,local_cc,local_cc + local_c8);
    }
    local_174 = local_174 + 0xe;
  }
  local_188 = 0;
  local_184 = (void *)0x0;
  local_180 = 0;
  uStack_17c = 0;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_184,&local_188);
  local_188 = 1;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_184,&local_188);
  local_188 = 2;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_184,&local_188);
  local_188 = 3;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_184,&local_188);
  local_13c = &PTR_DAT_0003a54c;
  std::vector<int,std::allocator<int>>::operator=
            ((vector<int,std::allocator<int>> *)&local_16c,(vector *)&local_184);
  local_138 = (float)(longlong)param_6 / (float)(longlong)param_7;
  local_130 = param_11;
  local_134 = 6;
  local_12c = 1;
  uVar6 = retina_create(param_1,param_2,param_3,param_8,
                        (vector<ez_model_info_t,std::allocator<ez_model_info_t>> *)&local_178,
                        param_10);
  if (local_184 != (void *)0x0) {
    operator_delete(local_184);
  }
  if (local_cc != local_c4) {
    operator_delete(local_cc);
  }
  if (local_e4 != local_dc) {
    operator_delete(local_e4);
  }
  if (local_104[0] != auStack_fc) {
    operator_delete(local_104[0]);
  }
  puVar1 = local_128;
  puVar2 = puStack_124;
  puVar3 = puStack_124;
  if (local_11c[0] != auStack_114) {
    operator_delete(local_11c[0]);
    puVar1 = local_128;
    puVar2 = puStack_124;
    puVar3 = puStack_124;
  }
  for (; puVar4 = puStack_124, puVar1 != puStack_124; puVar1 = puVar1 + 0xb) {
    puStack_124 = puVar3;
    if ((void *)puVar1[6] != (void *)0x0) {
      operator_delete((void *)puVar1[6]);
    }
    if ((void *)puVar1[3] != (void *)0x0) {
      operator_delete((void *)puVar1[3]);
    }
    if ((void *)*puVar1 != (void *)0x0) {
      operator_delete((void *)*puVar1);
    }
    puVar2 = local_128;
    puVar3 = puStack_124;
    puStack_124 = puVar4;
  }
  puStack_124 = puVar3;
  if (puVar2 != (undefined4 *)0x0) {
    operator_delete(puVar2);
  }
  if (local_148 != (void *)0x0) {
    operator_delete(local_148);
  }
  if (local_154 != (void *)0x0) {
    operator_delete(local_154);
  }
  if (local_160 != (void *)0x0) {
    operator_delete(local_160);
  }
  puVar1 = local_178;
  puVar2 = local_174;
  puVar3 = local_174;
  if (local_16c != (void *)0x0) {
    operator_delete(local_16c);
    puVar1 = local_178;
    puVar2 = local_174;
    puVar3 = local_174;
  }
  for (; puVar4 = local_174, puVar1 != local_174; puVar1 = puVar1 + 0xe) {
    local_174 = puVar3;
    if ((undefined4 *)puVar1[8] != puVar1 + 10) {
      operator_delete((undefined4 *)puVar1[8]);
    }
    if ((undefined4 *)puVar1[2] != puVar1 + 4) {
      operator_delete((undefined4 *)puVar1[2]);
    }
    puVar2 = local_178;
    puVar3 = local_174;
    local_174 = puVar4;
  }
  local_174 = puVar3;
  if (puVar2 != (undefined4 *)0x0) {
    operator_delete(puVar2);
  }
  if (local_34 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* campan_yolov8_humanpose_det_create(_vx_context*, ax_size_t, ax_rect_t, ImageFormat_E, char
   const*, int, int) */

void campan_yolov8_humanpose_det_create
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9,
               undefined4 param_10,undefined4 param_11)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  size_t sVar5;
  undefined4 uVar6;
  int iVar7;
  int local_198;
  void *local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188 [4];
  undefined4 *local_178;
  undefined4 *local_174;
  undefined4 *local_170;
  void *local_16c;
  undefined4 local_168;
  undefined4 uStack_164;
  void *local_160;
  undefined4 uStack_15c;
  undefined4 local_158;
  void *local_154;
  undefined4 local_150;
  undefined4 uStack_14c;
  void *local_148;
  undefined4 uStack_144;
  undefined4 local_140;
  undefined **local_13c;
  float local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 *local_128;
  undefined4 *puStack_124;
  undefined4 local_120;
  undefined1 *local_11c [2];
  undefined1 auStack_114 [16];
  undefined1 *local_104 [2];
  undefined1 auStack_fc [16];
  undefined4 local_ec;
  undefined4 uStack_e8;
  undefined1 *local_e4;
  int local_e0;
  undefined1 local_dc [16];
  undefined1 *local_cc;
  int local_c8;
  undefined1 local_c4 [16];
  char acStack_b4 [128];
  int local_34;
  
  local_34 = __stack_chk_guard;
  iVar7 = 0;
  local_178 = (undefined4 *)0x0;
  local_174 = (undefined4 *)0x0;
  local_170 = (undefined4 *)0x0;
  local_16c = (void *)0x0;
  local_168 = 0;
  uStack_164 = 0;
  local_160 = (void *)0x0;
  uStack_15c = 0;
  local_158 = 0;
  local_154 = (void *)0x0;
  local_150 = 0;
  uStack_14c = 0;
  local_148 = (void *)0x0;
  uStack_144 = 0;
  local_140 = 0;
  local_128 = (undefined4 *)0x0;
  puStack_124 = (undefined4 *)0x0;
  local_120 = 0;
  local_188[0] = 0x280;
  local_188[1] = 0x160;
  local_188[2] = 0x160;
  local_188[3] = 0x280;
  while( true ) {
    sprintf(acStack_b4,"%s/yolov8pose%d.ezb",param_9,iVar7);
    local_11c[0] = auStack_114;
    sVar5 = strlen(acStack_b4);
    FUN_0001da5c(local_11c,acStack_b4,acStack_b4 + sVar5);
    sprintf(acStack_b4,"%s/yolov8pose.bin",param_9);
    local_104[0] = auStack_fc;
    sVar5 = strlen(acStack_b4);
    FUN_0001da5c(local_104,acStack_b4,acStack_b4 + sVar5);
    local_ec = local_188[iVar7 * 2];
    uStack_e8 = local_188[iVar7 * 2 + 1];
    local_e0 = 0;
    local_dc[0] = 0;
    local_c8 = 0;
    local_c4[0] = 0;
    local_e4 = local_dc;
    local_cc = local_c4;
    std::__cxx11::string::_M_assign((string *)&local_e4);
    std::__cxx11::string::_M_assign((string *)&local_cc);
    puVar1 = local_174;
    if (local_174 == local_170) {
      std::vector<ez_model_info_t,std::allocator<ez_model_info_t>>::
      _M_realloc_insert<ez_model_info_t_const&>
                ((vector<ez_model_info_t,std::allocator<ez_model_info_t>> *)&local_178,local_174,
                 &local_ec);
    }
    else {
      if (local_174 != (undefined4 *)0x0) {
        local_174[2] = local_174 + 4;
        *local_174 = local_ec;
        local_174[1] = uStack_e8;
        FUN_0001da5c(local_174 + 2,local_e4,local_e4 + local_e0);
        puVar1[8] = puVar1 + 10;
        FUN_0001da5c(puVar1 + 8,local_cc,local_cc + local_c8);
      }
      local_174 = local_174 + 0xe;
    }
    if (local_cc != local_c4) {
      operator_delete(local_cc);
    }
    if (local_e4 != local_dc) {
      operator_delete(local_e4);
    }
    if (local_104[0] != auStack_fc) {
      operator_delete(local_104[0]);
    }
    if (local_11c[0] != auStack_114) {
      operator_delete(local_11c[0]);
    }
    if (iVar7 != 0) break;
    iVar7 = 1;
  }
  local_194 = (void *)0x0;
  local_190 = 0;
  local_18c = 0;
  local_198 = 3;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_194,&local_198);
  local_198 = 4;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_194,&local_198);
  local_198 = 0;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_194,&local_198);
  local_198 = 5;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_194,&local_198);
  local_198 = 6;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_194,&local_198);
  local_198 = 1;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_194,&local_198);
  local_198 = 7;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_194,&local_198);
  local_198 = 8;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_194,&local_198);
  local_198 = 2;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_194,&local_198);
  local_13c = &PTR_DAT_0003a560;
  std::vector<int,std::allocator<int>>::operator=
            ((vector<int,std::allocator<int>> *)&local_16c,(vector *)&local_194);
  local_134 = 7;
  local_138 = (float)(longlong)param_6 / (float)(longlong)param_7;
  local_130 = param_11;
  local_12c = 1;
  uVar6 = retina_create(param_1,param_2,param_3,param_8,
                        (vector<ez_model_info_t,std::allocator<ez_model_info_t>> *)&local_178,
                        param_10);
  puVar1 = local_128;
  puVar2 = puStack_124;
  puVar3 = puStack_124;
  if (local_194 != (void *)0x0) {
    operator_delete(local_194);
    puVar1 = local_128;
    puVar2 = puStack_124;
    puVar3 = puStack_124;
  }
  for (; puVar4 = puStack_124, puVar1 != puStack_124; puVar1 = puVar1 + 0xb) {
    puStack_124 = puVar3;
    if ((void *)puVar1[6] != (void *)0x0) {
      operator_delete((void *)puVar1[6]);
    }
    if ((void *)puVar1[3] != (void *)0x0) {
      operator_delete((void *)puVar1[3]);
    }
    if ((void *)*puVar1 != (void *)0x0) {
      operator_delete((void *)*puVar1);
    }
    puVar2 = local_128;
    puVar3 = puStack_124;
    puStack_124 = puVar4;
  }
  puStack_124 = puVar3;
  if (puVar2 != (undefined4 *)0x0) {
    operator_delete(puVar2);
  }
  if (local_148 != (void *)0x0) {
    operator_delete(local_148);
  }
  if (local_154 != (void *)0x0) {
    operator_delete(local_154);
  }
  if (local_160 != (void *)0x0) {
    operator_delete(local_160);
  }
  puVar1 = local_178;
  puVar2 = local_174;
  puVar3 = local_174;
  if (local_16c != (void *)0x0) {
    operator_delete(local_16c);
    puVar1 = local_178;
    puVar2 = local_174;
    puVar3 = local_174;
  }
  for (; puVar4 = local_174, puVar1 != local_174; puVar1 = puVar1 + 0xe) {
    local_174 = puVar3;
    if ((undefined4 *)puVar1[8] != puVar1 + 10) {
      operator_delete((undefined4 *)puVar1[8]);
    }
    if ((undefined4 *)puVar1[2] != puVar1 + 4) {
      operator_delete((undefined4 *)puVar1[2]);
    }
    puVar2 = local_178;
    puVar3 = local_174;
    local_174 = puVar4;
  }
  local_174 = puVar3;
  if (puVar2 != (undefined4 *)0x0) {
    operator_delete(puVar2);
  }
  if (local_34 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* headfacedet_create(_vx_context*, ax_size_t, ax_rect_t, ImageFormat_E, int, char const*, int, int,
   bool) */

void headfacedet_create(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,int param_6,int param_7,undefined4 param_8,int param_9,
                       undefined4 param_10,undefined4 param_11,undefined4 param_12,byte param_13)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  size_t sVar4;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  int local_254;
  void *local_250;
  undefined4 local_24c;
  undefined4 local_248;
  void *local_244;
  void *local_240;
  undefined4 local_23c;
  void *local_238;
  void *local_234;
  undefined4 local_230;
  undefined4 *local_22c;
  undefined4 *local_228;
  undefined4 *local_224;
  undefined4 local_220;
  undefined4 uStack_21c;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined4 local_210;
  undefined4 uStack_20c;
  undefined4 uStack_208;
  undefined4 uStack_204;
  undefined4 local_200;
  undefined4 uStack_1fc;
  undefined4 local_1f8;
  undefined4 uStack_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  undefined4 local_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  undefined4 local_1d8;
  undefined4 uStack_1d4;
  void *local_1d0;
  void *pvStack_1cc;
  undefined4 local_1c8;
  void *local_1c4;
  void *local_1c0;
  undefined4 uStack_1bc;
  void *local_1b8;
  void *pvStack_1b4;
  undefined4 local_1b0;
  undefined **local_1ac;
  undefined4 local_1a8;
  void *local_1a4;
  void *local_1a0;
  undefined4 uStack_19c;
  void *local_198;
  void *pvStack_194;
  undefined4 local_190;
  void *local_18c;
  void *local_188;
  undefined4 uStack_184;
  undefined **local_180;
  undefined4 local_17c;
  undefined4 *local_178;
  undefined4 *local_174;
  undefined4 *puStack_170;
  void *local_16c;
  undefined4 uStack_168;
  undefined4 local_164;
  void *local_160;
  undefined4 local_15c;
  undefined4 uStack_158;
  void *local_154;
  undefined4 uStack_150;
  undefined4 local_14c;
  void *local_148;
  undefined4 local_144;
  undefined4 uStack_140;
  float local_138;
  undefined4 local_130;
  uint local_12c;
  undefined4 *local_128;
  undefined4 *puStack_124;
  undefined4 local_120;
  undefined1 *local_11c [2];
  undefined1 auStack_114 [16];
  undefined1 *local_104 [2];
  undefined1 auStack_fc [16];
  undefined4 local_ec;
  undefined4 uStack_e8;
  undefined1 *local_e4;
  int local_e0;
  undefined1 local_dc [16];
  undefined1 *local_cc;
  int local_c8;
  undefined1 local_c4 [16];
  char acStack_b4 [128];
  int local_34;
  
  puVar7 = &local_1f8;
  iVar8 = 0;
  local_178 = (undefined4 *)0x0;
  local_174 = (undefined4 *)0x0;
  puStack_170 = (undefined4 *)0x0;
  local_16c = (void *)0x0;
  uStack_168 = 0;
  local_164 = 0;
  local_160 = (void *)0x0;
  local_15c = 0;
  uStack_158 = 0;
  local_154 = (void *)0x0;
  uStack_150 = 0;
  local_14c = 0;
  local_148 = (void *)0x0;
  local_144 = 0;
  uStack_140 = 0;
  local_128 = (undefined4 *)0x0;
  puStack_124 = (undefined4 *)0x0;
  local_120 = 0;
  local_34 = __stack_chk_guard;
  if (param_9 == 0) {
    puVar7 = &local_220;
  }
  local_220 = 0x80;
  uStack_21c = 0x80;
  uStack_218 = 0x100;
  uStack_214 = 0x160;
  local_210 = 0x160;
  uStack_20c = 0x100;
  uStack_208 = 0xe0;
  uStack_204 = 0x1a0;
  local_200 = 0x1a0;
  uStack_1fc = 0xe0;
  local_1f8 = 0x80;
  uStack_1f4 = 0x80;
  uStack_1f0 = 0x1a0;
  uStack_1ec = 0x220;
  local_1e8 = 0x220;
  uStack_1e4 = 0x1a0;
  uStack_1e0 = 0x160;
  uStack_1dc = 0x280;
  local_1d8 = 0x280;
  uStack_1d4 = 0x160;
  do {
    if (param_9 == 0) {
      sprintf(acStack_b4,"%s/headfacedet%d.ezb",param_10,iVar8);
    }
    else {
      sprintf(acStack_b4,"%s/headfacedet1%d.ezb",param_10,iVar8);
    }
    local_11c[0] = auStack_114;
    sVar4 = strlen(acStack_b4);
    FUN_0001da5c(local_11c,acStack_b4,acStack_b4 + sVar4);
    sprintf(acStack_b4,"%s/headfacedet.bin",param_10);
    local_104[0] = auStack_fc;
    sVar4 = strlen(acStack_b4);
    FUN_0001da5c(local_104,acStack_b4,acStack_b4 + sVar4);
    local_ec = puVar7[iVar8 * 2];
    uStack_e8 = (puVar7 + iVar8 * 2)[1];
    local_e0 = 0;
    local_dc[0] = 0;
    local_c8 = 0;
    local_c4[0] = 0;
    local_e4 = local_dc;
    local_cc = local_c4;
    std::__cxx11::string::_M_assign((string *)&local_e4);
    std::__cxx11::string::_M_assign((string *)&local_cc);
    puVar1 = local_174;
    if (local_174 == puStack_170) {
      std::vector<ez_model_info_t,std::allocator<ez_model_info_t>>::
      _M_realloc_insert<ez_model_info_t_const&>
                ((vector<ez_model_info_t,std::allocator<ez_model_info_t>> *)&local_178,local_174,
                 &local_ec);
    }
    else {
      if (local_174 != (undefined4 *)0x0) {
        local_174[2] = local_174 + 4;
        *local_174 = local_ec;
        local_174[1] = uStack_e8;
        FUN_0001da5c(local_174 + 2,local_e4,local_e4 + local_e0);
        puVar1[8] = puVar1 + 10;
        FUN_0001da5c(puVar1 + 8,local_cc,local_cc + local_c8);
      }
      local_174 = local_174 + 0xe;
    }
    if (local_cc != local_c4) {
      operator_delete(local_cc);
    }
    if (local_e4 != local_dc) {
      operator_delete(local_e4);
    }
    if (local_104[0] != auStack_fc) {
      operator_delete(local_104[0]);
    }
    if (local_11c[0] != auStack_114) {
      operator_delete(local_11c[0]);
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 != 5);
  local_23c = 0;
  local_250 = (void *)0x0;
  local_24c = 0;
  local_248 = 0;
  local_230 = 0;
  local_1a4 = (void *)0x3;
  local_244 = (void *)0x0;
  local_240 = (void *)0x0;
  local_238 = (void *)0x0;
  local_234 = (void *)0x0;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_250,(int *)&local_1a4);
  local_1a4 = (void *)0x0;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_250,(int *)&local_1a4);
  local_1a4 = (void *)0x4;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_250,(int *)&local_1a4);
  local_1a4 = (void *)0x1;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_250,(int *)&local_1a4);
  local_1a4 = (void *)0x5;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_250,(int *)&local_1a4);
  local_1a4 = (void *)0x2;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_250,(int *)&local_1a4);
  local_1a4 = (void *)0x9;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_250,(int *)&local_1a4);
  local_1a4 = (void *)0x6;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_250,(int *)&local_1a4);
  local_1a4 = (void *)0xc;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_250,(int *)&local_1a4);
  local_1a4 = (void *)0xa;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_250,(int *)&local_1a4);
  local_1a4 = (void *)0x7;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_250,(int *)&local_1a4);
  local_1a4 = (void *)0xd;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_250,(int *)&local_1a4);
  local_1a4 = (void *)0xb;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_250,(int *)&local_1a4);
  local_1a4 = (void *)0x8;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_250,(int *)&local_1a4);
  local_1a4 = (void *)0xe;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_250,(int *)&local_1a4);
  local_240 = local_244;
  local_22c = (undefined4 *)0x0;
  local_228 = (undefined4 *)0x0;
  local_224 = (undefined4 *)0x0;
  local_1d0 = (void *)0x0;
  pvStack_1cc = (void *)0x0;
  local_1c8 = 0;
  local_1c4 = (void *)0x0;
  local_1c0 = (void *)0x0;
  uStack_1bc = 0;
  local_1b8 = (void *)0x0;
  pvStack_1b4 = (void *)0x0;
  local_1b0 = 0;
  local_1a4 = (void *)0x0;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_244,(int *)&local_1a4);
  local_1a4 = (void *)0x2;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_244,(int *)&local_1a4);
  local_1a4 = (void *)0x4;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_244,(int *)&local_1a4);
  local_1a4 = (void *)0x0;
  local_234 = local_238;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_238,(int *)&local_1a4);
  std::vector<int,std::allocator<int>>::operator=
            ((vector<int,std::allocator<int>> *)&local_1d0,(vector *)&local_244);
  std::vector<int,std::allocator<int>>::operator=
            ((vector<int,std::allocator<int>> *)&local_1b8,(vector *)&local_238);
  local_254 = 6;
  local_1ac = &PTR_DAT_0003a574;
  local_1a8 = 1;
  local_1a4 = (void *)0x0;
  local_1a0 = (void *)0x0;
  uStack_19c = 0;
  local_198 = (void *)0x0;
  pvStack_194 = (void *)0x0;
  local_190 = 0;
  local_18c = (void *)0x0;
  local_188 = (void *)0x0;
  uStack_184 = 0;
  local_240 = local_244;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_244,&local_254);
  local_254 = 9;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_244,&local_254);
  local_254 = 0xc;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_244,&local_254);
  local_254 = 1;
  local_234 = local_238;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_238,&local_254);
  std::vector<int,std::allocator<int>>::operator=
            ((vector<int,std::allocator<int>> *)&local_1a4,(vector *)&local_244);
  std::vector<int,std::allocator<int>>::operator=
            ((vector<int,std::allocator<int>> *)&local_18c,(vector *)&local_238);
  puVar7 = local_228;
  local_180 = &PTR_DAT_0003a588;
  local_17c = 0;
  if (local_228 == local_224) {
    std::vector<retina_head_t,std::allocator<retina_head_t>>::
    _M_realloc_insert<retina_head_t_const&>
              ((vector<retina_head_t,std::allocator<retina_head_t>> *)&local_22c,local_228,
               (vector<int,std::allocator<int>> *)&local_1d0);
  }
  else {
    if (local_228 != (undefined4 *)0x0) {
      local_228[2] = 0;
      uVar9 = (int)pvStack_1cc - (int)local_1d0;
      *local_228 = 0;
      local_228[1] = 0;
      pvVar5 = (void *)((int)uVar9 >> 2);
      if (pvVar5 != (void *)0x0) {
        if ((void *)0x3fffffff < pvVar5) {
                    /* WARNING: Subroutine does not return */
          std::__throw_bad_alloc();
        }
        pvVar5 = operator_new(uVar9);
      }
      *puVar7 = pvVar5;
      puVar7[1] = pvVar5;
      puVar7[2] = (int)pvVar5 + uVar9;
      sVar4 = (int)pvStack_1cc - (int)local_1d0;
      if (pvStack_1cc != local_1d0) {
        pvVar5 = memmove(pvVar5,local_1d0,sVar4);
      }
      puVar7[1] = (int)pvVar5 + sVar4;
      puVar7[5] = 0;
      uVar9 = (int)local_1c0 - (int)local_1c4;
      puVar7[4] = 0;
      pvVar5 = (void *)((int)uVar9 >> 2);
      puVar7[3] = 0;
      if (pvVar5 != (void *)0x0) {
        if ((void *)0x3fffffff < pvVar5) {
                    /* WARNING: Subroutine does not return */
          std::__throw_bad_alloc();
        }
        pvVar5 = operator_new(uVar9);
      }
      puVar7[3] = pvVar5;
      puVar7[4] = pvVar5;
      puVar7[5] = (int)pvVar5 + uVar9;
      sVar4 = (int)local_1c0 - (int)local_1c4;
      if (local_1c0 != local_1c4) {
        pvVar5 = memmove(pvVar5,local_1c4,sVar4);
      }
      puVar7[4] = (int)pvVar5 + sVar4;
      puVar7[8] = 0;
      uVar9 = (int)pvStack_1b4 - (int)local_1b8;
      puVar7[7] = 0;
      pvVar5 = (void *)((int)uVar9 >> 2);
      puVar7[6] = 0;
      if (pvVar5 != (void *)0x0) {
        if ((void *)0x3fffffff < pvVar5) {
                    /* WARNING: Subroutine does not return */
          std::__throw_bad_alloc();
        }
        pvVar5 = operator_new(uVar9);
      }
      puVar7[6] = pvVar5;
      puVar7[7] = pvVar5;
      puVar7[8] = (int)pvVar5 + uVar9;
      sVar4 = (int)pvStack_1b4 - (int)local_1b8;
      if (pvStack_1b4 != local_1b8) {
        pvVar5 = memmove(pvVar5,local_1b8,sVar4);
      }
      puVar7[7] = (int)pvVar5 + sVar4;
      puVar7[9] = local_1ac;
      puVar7[10] = local_1a8;
    }
    local_228 = local_228 + 0xb;
  }
  puVar7 = local_228;
  if (local_224 == local_228) {
    std::vector<retina_head_t,std::allocator<retina_head_t>>::
    _M_realloc_insert<retina_head_t_const&>
              ((vector<retina_head_t,std::allocator<retina_head_t>> *)&local_22c,local_224,
               (vector<int,std::allocator<int>> *)&local_1a4);
  }
  else {
    if (local_228 != (undefined4 *)0x0) {
      *local_228 = 0;
      uVar9 = (int)local_1a0 - (int)local_1a4;
      local_228[1] = 0;
      local_228[2] = 0;
      pvVar5 = (void *)((int)uVar9 >> 2);
      if (pvVar5 != (void *)0x0) {
        if ((void *)0x3fffffff < pvVar5) {
                    /* WARNING: Subroutine does not return */
          std::__throw_bad_alloc();
        }
        pvVar5 = operator_new(uVar9);
      }
      puVar7[2] = (int)pvVar5 + uVar9;
      *puVar7 = pvVar5;
      puVar7[1] = pvVar5;
      sVar4 = (int)local_1a0 - (int)local_1a4;
      if (local_1a0 != local_1a4) {
        pvVar5 = memmove(pvVar5,local_1a4,sVar4);
      }
      puVar7[1] = (int)pvVar5 + sVar4;
      puVar7[3] = 0;
      uVar9 = (int)pvStack_194 - (int)local_198;
      puVar7[4] = 0;
      puVar7[5] = 0;
      pvVar5 = (void *)((int)uVar9 >> 2);
      if (pvVar5 != (void *)0x0) {
        if ((void *)0x3fffffff < pvVar5) {
                    /* WARNING: Subroutine does not return */
          std::__throw_bad_alloc();
        }
        pvVar5 = operator_new(uVar9);
      }
      puVar7[5] = (int)pvVar5 + uVar9;
      puVar7[3] = pvVar5;
      puVar7[4] = pvVar5;
      sVar4 = (int)pvStack_194 - (int)local_198;
      if (pvStack_194 != local_198) {
        pvVar5 = memmove(pvVar5,local_198,sVar4);
      }
      puVar7[4] = (int)pvVar5 + sVar4;
      puVar7[6] = 0;
      uVar9 = (int)local_188 - (int)local_18c;
      puVar7[7] = 0;
      puVar7[8] = 0;
      pvVar5 = (void *)((int)uVar9 >> 2);
      if (pvVar5 != (void *)0x0) {
        if ((void *)0x3fffffff < pvVar5) {
                    /* WARNING: Subroutine does not return */
          std::__throw_bad_alloc();
        }
        pvVar5 = operator_new(uVar9);
      }
      puVar7[8] = (int)pvVar5 + uVar9;
      puVar7[6] = pvVar5;
      puVar7[7] = pvVar5;
      sVar4 = (int)local_188 - (int)local_18c;
      if (local_188 != local_18c) {
        pvVar5 = memmove(pvVar5,local_18c,sVar4);
      }
      puVar7[7] = (int)pvVar5 + sVar4;
      puVar7[9] = local_180;
      puVar7[10] = local_17c;
    }
    local_228 = local_228 + 0xb;
  }
  std::vector<retina_head_t,std::allocator<retina_head_t>>::operator=
            ((vector<retina_head_t,std::allocator<retina_head_t>> *)&local_128,(vector *)&local_22c)
  ;
  std::vector<int,std::allocator<int>>::operator=
            ((vector<int,std::allocator<int>> *)&local_16c,(vector *)&local_250);
  local_130 = param_12;
  local_138 = (float)(longlong)param_6 / (float)(longlong)param_7;
  local_12c = (uint)param_13;
  uVar6 = retina_create(param_1,param_2,param_3,param_8,
                        (vector<ez_model_info_t,std::allocator<ez_model_info_t>> *)&local_178,
                        param_11);
  if (local_18c != (void *)0x0) {
    operator_delete(local_18c);
  }
  if (local_198 != (void *)0x0) {
    operator_delete(local_198);
  }
  if (local_1a4 != (void *)0x0) {
    operator_delete(local_1a4);
  }
  if (local_1b8 != (void *)0x0) {
    operator_delete(local_1b8);
  }
  if (local_1c4 != (void *)0x0) {
    operator_delete(local_1c4);
  }
  puVar7 = local_22c;
  puVar1 = local_228;
  puVar2 = local_228;
  if (local_1d0 != (void *)0x0) {
    operator_delete(local_1d0);
    puVar7 = local_22c;
    puVar1 = local_228;
    puVar2 = local_228;
  }
  for (; puVar3 = local_228, puVar7 != local_228; puVar7 = puVar7 + 0xb) {
    local_228 = puVar2;
    if ((void *)puVar7[6] != (void *)0x0) {
      operator_delete((void *)puVar7[6]);
    }
    if ((void *)puVar7[3] != (void *)0x0) {
      operator_delete((void *)puVar7[3]);
    }
    if ((void *)*puVar7 != (void *)0x0) {
      operator_delete((void *)*puVar7);
    }
    puVar1 = local_22c;
    puVar2 = local_228;
    local_228 = puVar3;
  }
  local_228 = puVar2;
  if (puVar1 != (undefined4 *)0x0) {
    operator_delete(puVar1);
  }
  if (local_238 != (void *)0x0) {
    operator_delete(local_238);
  }
  if (local_244 != (void *)0x0) {
    operator_delete(local_244);
  }
  puVar7 = local_128;
  puVar1 = puStack_124;
  puVar2 = puStack_124;
  if (local_250 != (void *)0x0) {
    operator_delete(local_250);
    puVar7 = local_128;
    puVar1 = puStack_124;
    puVar2 = puStack_124;
  }
  for (; puVar3 = puStack_124, puVar7 != puStack_124; puVar7 = puVar7 + 0xb) {
    puStack_124 = puVar2;
    if ((void *)puVar7[6] != (void *)0x0) {
      operator_delete((void *)puVar7[6]);
    }
    if ((void *)puVar7[3] != (void *)0x0) {
      operator_delete((void *)puVar7[3]);
    }
    if ((void *)*puVar7 != (void *)0x0) {
      operator_delete((void *)*puVar7);
    }
    puVar1 = local_128;
    puVar2 = puStack_124;
    puStack_124 = puVar3;
  }
  puStack_124 = puVar2;
  if (puVar1 != (undefined4 *)0x0) {
    operator_delete(puVar1);
  }
  if (local_148 != (void *)0x0) {
    operator_delete(local_148);
  }
  if (local_154 != (void *)0x0) {
    operator_delete(local_154);
  }
  if (local_160 != (void *)0x0) {
    operator_delete(local_160);
  }
  puVar7 = local_178;
  puVar1 = local_174;
  puVar2 = local_174;
  if (local_16c != (void *)0x0) {
    operator_delete(local_16c);
    puVar7 = local_178;
    puVar1 = local_174;
    puVar2 = local_174;
  }
  for (; puVar3 = local_174, puVar7 != local_174; puVar7 = puVar7 + 0xe) {
    local_174 = puVar2;
    if ((undefined4 *)puVar7[8] != puVar7 + 10) {
      operator_delete((undefined4 *)puVar7[8]);
    }
    if ((undefined4 *)puVar7[2] != puVar7 + 4) {
      operator_delete((undefined4 *)puVar7[2]);
    }
    puVar1 = local_178;
    puVar2 = local_174;
    local_174 = puVar3;
  }
  local_174 = puVar2;
  if (puVar1 != (undefined4 *)0x0) {
    operator_delete(puVar1);
  }
  if (local_34 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar6);
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* retina_handdet_yolov8_create(_vx_context*, ax_size_t, ax_rect_t, ImageFormat_E, char const*, int,
   int) */

void retina_handdet_yolov8_create
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9,
               int param_10,undefined4 param_11)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *pvVar4;
  size_t sVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  int local_210;
  void *local_20c;
  undefined4 local_208;
  undefined4 uStack_204;
  undefined4 *local_200;
  undefined4 *local_1fc;
  undefined4 *local_1f8;
  void *local_1f4;
  void *local_1f0;
  undefined4 local_1ec;
  void *local_1e8;
  void *local_1e4;
  undefined4 uStack_1e0;
  void *local_1dc;
  void *pvStack_1d8;
  undefined4 local_1d4;
  undefined **local_1d0;
  undefined4 local_1cc;
  undefined1 auStack_1c8 [80];
  undefined4 *local_178;
  undefined4 *local_174;
  undefined4 *local_170;
  void *local_16c;
  undefined4 uStack_168;
  undefined4 local_164;
  void *local_160;
  undefined4 local_15c;
  undefined4 uStack_158;
  void *local_154;
  undefined4 uStack_150;
  undefined4 local_14c;
  void *local_148;
  undefined4 local_144;
  undefined4 uStack_140;
  float local_138;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 *local_128;
  undefined4 *puStack_124;
  undefined4 local_120;
  undefined1 *local_11c [2];
  undefined1 auStack_114 [16];
  undefined1 *local_104 [2];
  undefined1 auStack_fc [16];
  undefined4 local_ec;
  undefined4 uStack_e8;
  undefined1 *local_e4;
  int local_e0;
  undefined1 local_dc [16];
  undefined1 *local_cc;
  int local_c8;
  undefined1 local_c4 [16];
  char acStack_b4 [128];
  int local_34;
  
  local_34 = __stack_chk_guard;
  iVar8 = 0;
  local_178 = (undefined4 *)0x0;
  local_174 = (undefined4 *)0x0;
  local_170 = (undefined4 *)0x0;
  local_16c = (void *)0x0;
  uStack_168 = 0;
  local_164 = 0;
  local_160 = (void *)0x0;
  local_15c = 0;
  uStack_158 = 0;
  local_154 = (void *)0x0;
  uStack_150 = 0;
  local_14c = 0;
  local_148 = (void *)0x0;
  local_144 = 0;
  uStack_140 = 0;
  local_128 = (undefined4 *)0x0;
  puStack_124 = (undefined4 *)0x0;
  local_120 = 0;
  pvVar4 = memcpy(auStack_1c8,&DAT_00027f18,0x50);
  do {
    if (param_10 == 0) {
      sprintf(acStack_b4,"%s/handdet%d.ezb",param_9,iVar8);
    }
    else {
      sprintf(acStack_b4,"%s/handdet%d%d.ezb",param_9,param_10,iVar8);
    }
    local_11c[0] = auStack_114;
    sVar5 = strlen(acStack_b4);
    FUN_0001da5c(local_11c,acStack_b4,acStack_b4 + sVar5);
    sprintf(acStack_b4,"%s/handdet.bin",param_9);
    local_104[0] = auStack_fc;
    sVar5 = strlen(acStack_b4);
    FUN_0001da5c(local_104,acStack_b4,acStack_b4 + sVar5);
    puVar7 = (undefined4 *)((int)pvVar4 + iVar8 * 8 + param_10 * 0x28);
    local_ec = *puVar7;
    uStack_e8 = puVar7[1];
    local_e0 = 0;
    local_dc[0] = 0;
    local_c8 = 0;
    local_c4[0] = 0;
    local_e4 = local_dc;
    local_cc = local_c4;
    std::__cxx11::string::_M_assign((string *)&local_e4);
    std::__cxx11::string::_M_assign((string *)&local_cc);
    puVar7 = local_174;
    if (local_174 == local_170) {
      std::vector<ez_model_info_t,std::allocator<ez_model_info_t>>::
      _M_realloc_insert<ez_model_info_t_const&>
                ((vector<ez_model_info_t,std::allocator<ez_model_info_t>> *)&local_178,local_174,
                 &local_ec);
    }
    else {
      if (local_174 != (undefined4 *)0x0) {
        local_174[2] = local_174 + 4;
        *local_174 = local_ec;
        local_174[1] = uStack_e8;
        FUN_0001da5c(local_174 + 2,local_e4,local_e4 + local_e0);
        puVar7[8] = puVar7 + 10;
        FUN_0001da5c(puVar7 + 8,local_cc,local_cc + local_c8);
      }
      local_174 = local_174 + 0xe;
    }
    if (local_cc != local_c4) {
      operator_delete(local_cc);
    }
    if (local_e4 != local_dc) {
      operator_delete(local_e4);
    }
    if (local_104[0] != auStack_fc) {
      operator_delete(local_104[0]);
    }
    if (local_11c[0] != auStack_114) {
      operator_delete(local_11c[0]);
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 != 5);
  local_1f4 = (void *)0x0;
  local_20c = (void *)0x0;
  local_208 = 0;
  uStack_204 = 0;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_20c,(int *)&local_1f4);
  local_1f4 = (void *)0x1;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_20c,(int *)&local_1f4);
  local_1f4 = (void *)0x2;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_20c,(int *)&local_1f4);
  local_1f4 = (void *)0x3;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_20c,(int *)&local_1f4);
  local_1f4 = (void *)0x4;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_20c,(int *)&local_1f4);
  local_1f4 = (void *)0x5;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_20c,(int *)&local_1f4);
  local_1d4 = 0;
  local_200 = (undefined4 *)0x0;
  local_1fc = (undefined4 *)0x0;
  local_1f8 = (undefined4 *)0x0;
  local_1f4 = (void *)0x0;
  local_1f0 = (void *)0x0;
  local_1ec = 0;
  local_1e8 = (void *)0x0;
  local_1e4 = (void *)0x0;
  uStack_1e0 = 0;
  local_1dc = (void *)0x0;
  pvStack_1d8 = (void *)0x0;
  local_210 = 0;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1e8,&local_210);
  local_210 = 2;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1e8,&local_210);
  local_210 = 4;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1e8,&local_210);
  local_210 = 1;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1f4,&local_210);
  local_210 = 3;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1f4,&local_210);
  local_210 = 5;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_1f4,&local_210);
  puVar7 = local_1fc;
  local_1cc = 5;
  local_1d0 = &PTR_DAT_0003a59c;
  if (local_1fc == local_1f8) {
    std::vector<retina_head_t,std::allocator<retina_head_t>>::
    _M_realloc_insert<retina_head_t_const&>
              ((vector<retina_head_t,std::allocator<retina_head_t>> *)&local_200,local_1fc,
               (vector<int,std::allocator<int>> *)&local_1f4);
  }
  else {
    if (local_1fc != (undefined4 *)0x0) {
      *local_1fc = 0;
      uVar9 = (int)local_1f0 - (int)local_1f4;
      local_1fc[1] = 0;
      local_1fc[2] = 0;
      pvVar4 = (void *)((int)uVar9 >> 2);
      if (pvVar4 != (void *)0x0) {
        if ((void *)0x3fffffff < pvVar4) {
                    /* WARNING: Subroutine does not return */
          std::__throw_bad_alloc();
        }
        pvVar4 = operator_new(uVar9);
      }
      puVar7[2] = (int)pvVar4 + uVar9;
      *puVar7 = pvVar4;
      puVar7[1] = pvVar4;
      sVar5 = (int)local_1f0 - (int)local_1f4;
      if (local_1f0 != local_1f4) {
        pvVar4 = memmove(pvVar4,local_1f4,sVar5);
      }
      puVar7[1] = (int)pvVar4 + sVar5;
      puVar7[3] = 0;
      uVar9 = (int)local_1e4 - (int)local_1e8;
      puVar7[4] = 0;
      puVar7[5] = 0;
      pvVar4 = (void *)((int)uVar9 >> 2);
      if (pvVar4 != (void *)0x0) {
        if ((void *)0x3fffffff < pvVar4) {
                    /* WARNING: Subroutine does not return */
          std::__throw_bad_alloc();
        }
        pvVar4 = operator_new(uVar9);
      }
      puVar7[5] = (int)pvVar4 + uVar9;
      puVar7[3] = pvVar4;
      puVar7[4] = pvVar4;
      sVar5 = (int)local_1e4 - (int)local_1e8;
      if (local_1e4 != local_1e8) {
        pvVar4 = memmove(pvVar4,local_1e8,sVar5);
      }
      puVar7[4] = (int)pvVar4 + sVar5;
      puVar7[6] = 0;
      uVar9 = (int)pvStack_1d8 - (int)local_1dc;
      puVar7[7] = 0;
      puVar7[8] = 0;
      pvVar4 = (void *)((int)uVar9 >> 2);
      if (pvVar4 != (void *)0x0) {
        if ((void *)0x3fffffff < pvVar4) {
                    /* WARNING: Subroutine does not return */
          std::__throw_bad_alloc();
        }
        pvVar4 = operator_new(uVar9);
      }
      puVar7[8] = (int)pvVar4 + uVar9;
      puVar7[6] = pvVar4;
      puVar7[7] = pvVar4;
      sVar5 = (int)pvStack_1d8 - (int)local_1dc;
      if (pvStack_1d8 != local_1dc) {
        pvVar4 = memmove(pvVar4,local_1dc,sVar5);
      }
      puVar7[7] = (int)pvVar4 + sVar5;
      puVar7[9] = local_1d0;
      puVar7[10] = local_1cc;
    }
    local_1fc = local_1fc + 0xb;
  }
  std::vector<retina_head_t,std::allocator<retina_head_t>>::operator=
            ((vector<retina_head_t,std::allocator<retina_head_t>> *)&local_128,(vector *)&local_200)
  ;
  std::vector<int,std::allocator<int>>::operator=
            ((vector<int,std::allocator<int>> *)&local_16c,(vector *)&local_20c);
  local_130 = 0;
  local_138 = (float)(longlong)param_6 / (float)(longlong)param_7;
  local_12c = 1;
  uVar6 = retina_create(param_1,param_2,param_3,param_8,
                        (vector<ez_model_info_t,std::allocator<ez_model_info_t>> *)&local_178,
                        param_11);
  if (local_1dc != (void *)0x0) {
    operator_delete(local_1dc);
  }
  if (local_1e8 != (void *)0x0) {
    operator_delete(local_1e8);
  }
  puVar7 = local_200;
  puVar1 = local_1fc;
  puVar2 = local_1fc;
  if (local_1f4 != (void *)0x0) {
    operator_delete(local_1f4);
    puVar7 = local_200;
    puVar1 = local_1fc;
    puVar2 = local_1fc;
  }
  for (; puVar3 = local_1fc, puVar7 != local_1fc; puVar7 = puVar7 + 0xb) {
    local_1fc = puVar2;
    if ((void *)puVar7[6] != (void *)0x0) {
      operator_delete((void *)puVar7[6]);
    }
    if ((void *)puVar7[3] != (void *)0x0) {
      operator_delete((void *)puVar7[3]);
    }
    if ((void *)*puVar7 != (void *)0x0) {
      operator_delete((void *)*puVar7);
    }
    puVar1 = local_200;
    puVar2 = local_1fc;
    local_1fc = puVar3;
  }
  local_1fc = puVar2;
  if (puVar1 != (undefined4 *)0x0) {
    operator_delete(puVar1);
  }
  puVar7 = local_128;
  puVar1 = puStack_124;
  puVar2 = puStack_124;
  if (local_20c != (void *)0x0) {
    operator_delete(local_20c);
    puVar7 = local_128;
    puVar1 = puStack_124;
    puVar2 = puStack_124;
  }
  for (; puVar3 = puStack_124, puVar7 != puStack_124; puVar7 = puVar7 + 0xb) {
    puStack_124 = puVar2;
    if ((void *)puVar7[6] != (void *)0x0) {
      operator_delete((void *)puVar7[6]);
    }
    if ((void *)puVar7[3] != (void *)0x0) {
      operator_delete((void *)puVar7[3]);
    }
    if ((void *)*puVar7 != (void *)0x0) {
      operator_delete((void *)*puVar7);
    }
    puVar1 = local_128;
    puVar2 = puStack_124;
    puStack_124 = puVar3;
  }
  puStack_124 = puVar2;
  if (puVar1 != (undefined4 *)0x0) {
    operator_delete(puVar1);
  }
  if (local_148 != (void *)0x0) {
    operator_delete(local_148);
  }
  if (local_154 != (void *)0x0) {
    operator_delete(local_154);
  }
  if (local_160 != (void *)0x0) {
    operator_delete(local_160);
  }
  puVar7 = local_178;
  puVar1 = local_174;
  puVar2 = local_174;
  if (local_16c != (void *)0x0) {
    operator_delete(local_16c);
    puVar7 = local_178;
    puVar1 = local_174;
    puVar2 = local_174;
  }
  for (; puVar3 = local_174, puVar7 != local_174; puVar7 = puVar7 + 0xe) {
    local_174 = puVar2;
    if ((undefined4 *)puVar7[8] != puVar7 + 10) {
      operator_delete((undefined4 *)puVar7[8]);
    }
    if ((undefined4 *)puVar7[2] != puVar7 + 4) {
      operator_delete((undefined4 *)puVar7[2]);
    }
    puVar1 = local_178;
    puVar2 = local_174;
    local_174 = puVar3;
  }
  local_174 = puVar2;
  if (puVar1 != (undefined4 *)0x0) {
    operator_delete(puVar1);
  }
  if (local_34 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



void FUN_000202a0(undefined4 *param_1)

{
  __android_log_print(6,"CAMPAN_ATTR","person %d, %d, %d, %d, id %d",param_1[0x11],param_1[0x12],
                      param_1[0x13],param_1[0x14],param_1[0x10]);
  __android_log_print(6,"CAMPAN_ATTR","head %d, %d, %d, %d, id %d",param_1[1],param_1[2],param_1[3],
                      param_1[4],*param_1);
  return;
}



/* classify_in_t::~classify_in_t() */

classify_in_t * __thiscall classify_in_t::~classify_in_t(classify_in_t *this)

{
  if (*(void **)(this + 0xc) != (void *)0x0) {
    operator_delete(*(void **)(this + 0xc));
  }
  if (*(void **)this != (void *)0x0) {
    operator_delete(*(void **)this);
  }
  return this;
}



/* campan_reid_release(campan_reid_t*) */

void campan_reid_release(campan_reid_t *param_1)

{
  if (param_1 == (campan_reid_t *)0x0) {
    return;
  }
  classify_model_release(*(batch_classify_model_t **)param_1);
  AX_FREE_RECORD(param_1);
  return;
}



/* handpose_release(handpose_t*) */

void handpose_release(handpose_t *param_1)

{
  if (param_1 == (handpose_t *)0x0) {
    return;
  }
  classify_model_release(*(batch_classify_model_t **)param_1);
  classify_model_release(*(batch_classify_model_t **)(param_1 + 4));
  classify_model_release(*(batch_classify_model_t **)(param_1 + 8));
  classify_model_release(*(batch_classify_model_t **)(param_1 + 0xc));
  AX_FREE_RECORD(param_1);
  return;
}



/* person_feature_dist(nn_campan_person_feature_t*, nn_campan_person_feature_t*) */

double person_feature_dist(nn_campan_person_feature_t *param_1,nn_campan_person_feature_t *param_2)

{
  uint uVar1;
  nn_campan_person_feature_t *pnVar2;
  int iVar3;
  uint uVar4;
  nn_campan_person_feature_t *pnVar5;
  undefined8 uVar6;
  undefined8 uVar8;
  undefined1 auVar7 [16];
  undefined1 auVar9 [16];
  
  if ((((*(int *)(param_1 + 0x110) != 0) && (*(int *)(param_2 + 0x110) != 0)) &&
      (*(double *)(param_1 + 0x108) != 0.0)) && (*(double *)(param_2 + 0x108) != 0.0)) {
    uVar4 = *(uint *)(param_1 + 0x100);
    auVar9 = ZEXT816(0);
    uVar1 = uVar4 & 0xfffffff8;
    if ((int)uVar1 < 1) {
      uVar1 = 0;
    }
    else {
      pnVar2 = param_1;
      pnVar5 = param_2;
      do {
        uVar6 = *(undefined8 *)pnVar2;
        pnVar2 = pnVar2 + 8;
        uVar8 = *(undefined8 *)pnVar5;
        pnVar5 = pnVar5 + 8;
        auVar7 = VectorMultiply(uVar6,uVar8,1,0);
        auVar7 = VectorAdd(auVar7._8_8_,auVar7._0_8_,2,0);
        auVar9 = VectorAdd(auVar9,auVar7,4);
      } while (pnVar2 != param_1 + uVar1);
    }
    iVar3 = auVar9._0_4_ + auVar9._4_4_ + auVar9._8_4_ + auVar9._12_4_;
    if ((int)uVar1 < (int)uVar4) {
      pnVar5 = param_2 + (uVar1 - 1);
      pnVar2 = param_1 + (uVar1 - 1);
      do {
        pnVar2 = pnVar2 + 1;
        pnVar5 = pnVar5 + 1;
        iVar3 = (int)(short)(char)*pnVar2 * (int)(short)(char)*pnVar5 + iVar3;
      } while (pnVar2 != param_1 + (uVar4 - 1));
    }
    return 1.0 - (double)(longlong)iVar3 /
                 (*(double *)(param_1 + 0x108) * *(double *)(param_2 + 0x108));
  }
  return 1.0;
}



/* face_feature_dist(nn_campan_face_feature_t*, nn_campan_face_feature_t*) */

double face_feature_dist(nn_campan_face_feature_t *param_1,nn_campan_face_feature_t *param_2)

{
  uint uVar1;
  nn_campan_face_feature_t *pnVar2;
  int iVar3;
  uint uVar4;
  nn_campan_face_feature_t *pnVar5;
  undefined8 uVar6;
  undefined8 uVar8;
  undefined1 auVar7 [16];
  undefined1 auVar9 [16];
  
  if ((((*(int *)(param_1 + 0x110) != 0) && (*(int *)(param_2 + 0x110) != 0)) &&
      (*(double *)(param_1 + 0x108) != 0.0)) && (*(double *)(param_2 + 0x108) != 0.0)) {
    uVar4 = *(uint *)(param_1 + 0x100);
    auVar9 = ZEXT816(0);
    uVar1 = uVar4 & 0xfffffff8;
    if ((int)uVar1 < 1) {
      uVar1 = 0;
    }
    else {
      pnVar2 = param_1;
      pnVar5 = param_2;
      do {
        uVar6 = *(undefined8 *)pnVar2;
        pnVar2 = pnVar2 + 8;
        uVar8 = *(undefined8 *)pnVar5;
        pnVar5 = pnVar5 + 8;
        auVar7 = VectorMultiply(uVar6,uVar8,1,0);
        auVar7 = VectorAdd(auVar7._8_8_,auVar7._0_8_,2,0);
        auVar9 = VectorAdd(auVar9,auVar7,4);
      } while (pnVar2 != param_1 + uVar1);
    }
    iVar3 = auVar9._4_4_ + auVar9._0_4_ + auVar9._8_4_ + auVar9._12_4_;
    if ((int)uVar1 < (int)uVar4) {
      pnVar5 = param_2 + (uVar1 - 1);
      pnVar2 = param_1 + (uVar1 - 1);
      do {
        pnVar2 = pnVar2 + 1;
        pnVar5 = pnVar5 + 1;
        iVar3 = (int)(short)(char)*pnVar2 * (int)(short)(char)*pnVar5 + iVar3;
      } while (pnVar2 != param_1 + (uVar4 - 1));
    }
    return (double)(longlong)iVar3 / (*(double *)(param_1 + 0x108) * *(double *)(param_2 + 0x108));
  }
  return 0.0;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* campan_feature_match_create() */

void * campan_feature_match_create(void)

{
  void *__s;
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  __s = (void *)AX_MALLOC_RECORD(0xb48);
  memset(__s,0,0xb48);
  *(undefined4 *)((int)__s + 0x2d0) = 0x3e99999a;
  *(undefined4 *)((int)__s + 0x2dc) = 0x3f99999a;
  *(undefined4 *)((int)__s + 0x2d8) = 0x3f4ccccd;
  *(undefined4 *)((int)__s + 0x2d4) = 0x3f000000;
  *(undefined4 *)((int)__s + 0x2e4) = 0x3d8f5c29;
  *(undefined4 *)((int)__s + 0x2e0) = 0x3fc00000;
  *(undefined4 *)((int)__s + 0x2e8) = 0x3d8f5c29;
  *(undefined4 *)((int)__s + 0x2ec) = 0x3d8f5c29;
  *(undefined4 *)((int)__s + 0x2f0) = 0x3d8f5c29;
  *(undefined4 *)((int)__s + 0x2f4) = 0x3d8f5c29;
  puVar3 = (undefined4 *)((int)__s + 0x2a8);
  do {
    pvVar1 = operator_new(0xc);
    *(void **)pvVar1 = pvVar1;
    *(void **)((int)pvVar1 + 4) = pvVar1;
    *(undefined4 *)((int)pvVar1 + 8) = 0;
    puVar2 = puVar3 + 1;
    *puVar3 = pvVar1;
    puVar3 = puVar2;
  } while ((undefined4 *)((int)__s + 700) != puVar2);
  pvVar1 = operator_new(0xc);
  *(void **)((int)pvVar1 + 4) = pvVar1;
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(void **)pvVar1 = pvVar1;
  *(void **)((int)__s + 700) = pvVar1;
  pvVar1 = operator_new(0xc);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(void **)pvVar1 = pvVar1;
  *(void **)((int)pvVar1 + 4) = pvVar1;
  *(void **)((int)__s + 0x2c0) = pvVar1;
  pvVar1 = operator_new(0xc);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(void **)pvVar1 = pvVar1;
  *(void **)((int)pvVar1 + 4) = pvVar1;
  *(void **)((int)__s + 0x2c4) = pvVar1;
  pvVar1 = operator_new(0xc);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(void **)pvVar1 = pvVar1;
  *(void **)((int)pvVar1 + 4) = pvVar1;
  *(void **)((int)__s + 0x2c8) = pvVar1;
  pvVar1 = operator_new(0xc);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(void **)pvVar1 = pvVar1;
  *(void **)((int)pvVar1 + 4) = pvVar1;
  *(void **)((int)__s + 0x2cc) = pvVar1;
  pvVar1 = operator_new(0xc);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(void **)pvVar1 = pvVar1;
  *(void **)((int)pvVar1 + 4) = pvVar1;
  *(void **)((int)__s + 0xab8) = pvVar1;
  pvVar1 = operator_new(0xc);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(void **)pvVar1 = pvVar1;
  *(void **)((int)pvVar1 + 4) = pvVar1;
  *(void **)((int)__s + 0xabc) = pvVar1;
  pvVar1 = operator_new(0xc);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(void **)pvVar1 = pvVar1;
  *(void **)((int)pvVar1 + 4) = pvVar1;
  *(undefined4 *)((int)__s + 0x2f8) = 0x3d75c28f;
  *(void **)((int)__s + 0xac0) = pvVar1;
  *(undefined4 *)((int)__s + 0x2fc) = 0x3d23d70a;
  pvVar1 = operator_new(0x18);
  *(undefined4 *)((int)pvVar1 + 4) = 0;
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(undefined4 *)((int)pvVar1 + 0x14) = 0;
  *(int *)((int)pvVar1 + 0xc) = (int)pvVar1 + 4;
  *(int *)((int)pvVar1 + 0x10) = (int)pvVar1 + 4;
  *(void **)((int)__s + 0xb30) = pvVar1;
  pvVar1 = operator_new(0x18);
  *(undefined4 *)((int)pvVar1 + 4) = 0;
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(undefined4 *)((int)pvVar1 + 0x14) = 0;
  *(int *)((int)pvVar1 + 0xc) = (int)pvVar1 + 4;
  *(int *)((int)pvVar1 + 0x10) = (int)pvVar1 + 4;
  *(void **)((int)__s + 0xb34) = pvVar1;
  pthread_mutex_init((pthread_mutex_t *)((int)__s + 0x318),(pthread_mutexattr_t *)0x0);
  *(undefined4 *)((int)__s + 0x300) = 0xffffffff;
  *(undefined4 *)((int)__s + 0x330) = 0xffffffff;
  *(undefined4 *)((int)__s + 0x370) = 0xffffffff;
  *(undefined4 *)((int)__s + 0x518) = 0xffffffff;
  *(undefined4 *)((int)__s + 0x50c) = 0x45800000;
  *(undefined4 *)((int)__s + 0x510) = 0x47800000;
  *(undefined4 *)((int)__s + 0x514) = 0x49800000;
  puVar3 = (undefined4 *)((int)__s + 0x500);
  do {
    pvVar1 = operator_new(0xc);
    *(void **)pvVar1 = pvVar1;
    *(void **)((int)pvVar1 + 4) = pvVar1;
    *(undefined4 *)((int)pvVar1 + 8) = 0;
    puVar2 = puVar3 + 1;
    *puVar3 = pvVar1;
    puVar3 = puVar2;
  } while ((undefined4 *)((int)__s + 0x50c) != puVar2);
  return __s;
}



/* hung_release(hungarian_t*) */

void hung_release(hungarian_t *param_1)

{
  AX_FREE_RECORD(*(void **)param_1);
  AX_FREE_RECORD(*(void **)(param_1 + 8));
  AX_FREE_RECORD(*(void **)(param_1 + 0x10));
  AX_FREE_RECORD(*(void **)(param_1 + 0x18));
  AX_FREE_RECORD(*(void **)(param_1 + 0x20));
  return;
}



/* get_person_upper_box(nn_campan_person_t*) */

void get_person_upper_box(nn_campan_person_t *param_1)

{
  int in_r1;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(in_r1 + 8);
  iVar4 = *(int *)(in_r1 + 0xc);
  iVar1 = *(int *)(in_r1 + 0x10);
  iVar2 = (iVar4 - *(int *)(in_r1 + 4)) + iVar3;
  *(int *)param_1 = *(int *)(in_r1 + 4);
  if (iVar1 <= iVar2) {
    iVar2 = iVar1;
  }
  *(int *)(param_1 + 8) = iVar4;
  *(int *)(param_1 + 0xc) = iVar2;
  *(int *)(param_1 + 4) = iVar3;
  return;
}



/* get_person_upper_box(ax_box_t*) */

void get_person_upper_box(ax_box_t *param_1)

{
  int *in_r1;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = in_r1[1];
  iVar4 = in_r1[2];
  iVar1 = in_r1[3];
  iVar2 = (iVar4 - *in_r1) + iVar3;
  *(int *)param_1 = *in_r1;
  if (iVar1 <= iVar2) {
    iVar2 = iVar1;
  }
  *(int *)(param_1 + 8) = iVar4;
  *(int *)(param_1 + 0xc) = iVar2;
  *(int *)(param_1 + 4) = iVar3;
  return;
}



/* negative_nearest(campan_feature_match_t*, nn_campan_person_t*) */

float negative_nearest(campan_feature_match_t *param_1,nn_campan_person_t *param_2)

{
  int *piVar1;
  int *piVar2;
  double dVar3;
  float fVar4;
  double dVar5;
  
  piVar2 = *(int **)(param_1 + 0x2c4);
  fVar4 = 1000.0;
  piVar1 = (int *)*piVar2;
  if (piVar1 != piVar2) {
    do {
      dVar3 = (double)person_feature_dist((nn_campan_person_feature_t *)(piVar1 + 0xe),
                                          (nn_campan_person_feature_t *)(param_2 + 0x30));
      dVar5 = (double)fVar4;
      piVar1 = (int *)*piVar1;
      if (dVar5 != dVar3 && dVar5 < dVar3 == (NAN(dVar5) || NAN(dVar3))) {
        fVar4 = (float)dVar3;
      }
    } while (piVar1 != piVar2);
  }
  return fVar4;
}



/* campan_set_tracking_person(campan_feature_match_t*, nn_campan_person_t*) */

void campan_set_tracking_person(campan_feature_match_t *param_1,nn_campan_person_t *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  campan_feature_match_t *pcVar5;
  undefined8 uVar7;
  campan_feature_match_t *pcVar6;
  
  __android_log_print(6,"CAMPAN_ATTR","set tracking person ");
  __android_log_print(6,"CAMPAN_ATTR","%d, %d, %d, %d, id %d",*(undefined4 *)(param_2 + 4),
                      *(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc),
                      *(undefined4 *)(param_2 + 0x10),*(undefined4 *)param_2);
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x318));
  memcpy(param_1,param_2,0x2a8);
  uVar2 = *(undefined4 *)param_2;
  *(undefined4 *)(param_1 + 0x304) = 0;
  *(undefined4 *)(param_1 + 0x300) = uVar2;
  uVar7 = get_time_ms();
  *(undefined8 *)(param_1 + 0x310) = uVar7;
  pcVar6 = param_1 + 0x2a8;
  do {
    pcVar5 = pcVar6 + 4;
    puVar3 = *(undefined4 **)pcVar6;
    puVar1 = (undefined4 *)*puVar3;
    while (puVar1 != puVar3) {
      puVar4 = (undefined4 *)*puVar1;
      operator_delete(puVar1);
      puVar1 = puVar4;
    }
    *puVar3 = puVar3;
    puVar3[1] = puVar3;
    puVar3[2] = 0;
    pcVar6 = pcVar5;
  } while (pcVar5 != param_1 + 700);
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x318));
  return;
}



/* clear_tracking_person_buffer(campan_feature_match_t*) */

void clear_tracking_person_buffer(campan_feature_match_t *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  campan_feature_match_t *pcVar4;
  campan_feature_match_t *pcVar5;
  
  puVar1 = *(undefined4 **)(param_1 + 700);
  puVar2 = (undefined4 *)*puVar1;
  while (puVar2 != puVar1) {
    puVar3 = (undefined4 *)*puVar2;
    operator_delete(puVar2);
    puVar2 = puVar3;
  }
  *puVar1 = puVar1;
  puVar1[1] = puVar1;
  puVar1[2] = 0;
  puVar1 = *(undefined4 **)(param_1 + 0x2c0);
  puVar2 = (undefined4 *)*puVar1;
  while (puVar2 != puVar1) {
    puVar3 = (undefined4 *)*puVar2;
    operator_delete(puVar2);
    puVar2 = puVar3;
  }
  *puVar1 = puVar1;
  puVar1[1] = puVar1;
  puVar1[2] = 0;
  puVar1 = *(undefined4 **)(param_1 + 0x2c4);
  puVar2 = (undefined4 *)*puVar1;
  while (puVar2 != puVar1) {
    puVar3 = (undefined4 *)*puVar2;
    operator_delete(puVar2);
    puVar2 = puVar3;
  }
  *puVar1 = puVar1;
  puVar1[1] = puVar1;
  puVar1[2] = 0;
  pcVar5 = param_1 + 0x2a8;
  do {
    pcVar4 = pcVar5 + 4;
    puVar3 = *(undefined4 **)pcVar5;
    puVar2 = puVar3;
    puVar1 = (undefined4 *)*puVar3;
    while (puVar3 != puVar1) {
      puVar2 = (undefined4 *)*puVar1;
      operator_delete(puVar1);
      puVar1 = puVar2;
    }
    *puVar3 = puVar2;
    puVar3[1] = puVar2;
    puVar3[2] = 0;
    pcVar5 = pcVar4;
  } while (pcVar4 != param_1 + 700);
  return;
}



/* campan_remove_tracking_head(campan_feature_match_t*, int) */

void campan_remove_tracking_head(campan_feature_match_t *param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  bool bVar9;
  
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x318));
  puVar1 = *(undefined4 **)(param_1 + 0xac0);
  puVar5 = (undefined4 *)*puVar1;
  if (puVar5 == puVar1) {
LAB_000208a8:
    __android_log_print(6,"CAMPAN_ATTR","cannot remove tracking id %d, not tracking",param_2);
  }
  else {
    iVar3 = puVar5[2];
    while (param_2 != iVar3) {
      puVar5 = (undefined4 *)*puVar5;
      if (puVar5 == puVar1) goto LAB_000208a8;
      iVar3 = puVar5[2];
    }
    __android_log_print(6,"CAMPAN_ATTR","remove tracking id %d",param_2);
    *(int *)(*(int *)(param_1 + 0xac0) + 8) = *(int *)(*(int *)(param_1 + 0xac0) + 8) + -1;
    std::__detail::_List_node_base::_M_unhook();
    operator_delete(puVar5);
    piVar2 = *(int **)(param_1 + 0xab8);
    piVar4 = (int *)*piVar2;
    if (piVar4 != piVar2) {
      do {
        piVar8 = piVar4 + 0x120;
        if (*piVar8 == param_2) {
          piVar4[0x141] = 0;
        }
        piVar4 = (int *)*piVar4;
        if (*piVar8 == param_2) {
          piVar2 = *(int **)(param_1 + 0xab8);
        }
      } while (piVar2 != piVar4);
    }
    piVar2 = *(int **)(param_1 + 0xabc);
    piVar4 = (int *)*piVar2;
    if (piVar4 != piVar2) {
      do {
        bVar9 = piVar4[2] == param_2;
        if (bVar9) {
          piVar4[0x2b] = 0;
        }
        if (bVar9) {
          piVar4[0x42] = 0;
        }
        piVar4 = (int *)*piVar4;
        if (bVar9) {
          piVar2 = *(int **)(param_1 + 0xabc);
        }
      } while (piVar2 != piVar4);
      piVar4 = (int *)*piVar4;
      while (piVar8 = piVar4, piVar2 != piVar8) {
        piVar4 = (int *)*piVar8;
        if (piVar8[0x43] == 1) {
          piVar7 = piVar8 + 0x2b;
          piVar2[2] = piVar2[2] + -1;
          std::__detail::_List_node_base::_M_unhook();
          do {
            piVar7 = piVar7 + -3;
            piVar2 = (int *)*piVar7;
            while (piVar7 != piVar2) {
              piVar6 = (int *)*piVar2;
              operator_delete(piVar2);
              piVar2 = piVar6;
            }
          } while (piVar8 + 0x1c != piVar7);
          piVar2 = (int *)piVar8[0x19];
          while (piVar2 != piVar8 + 0x19) {
            piVar7 = (int *)*piVar2;
            operator_delete(piVar2);
            piVar2 = piVar7;
          }
          piVar2 = (int *)piVar8[0x16];
          while (piVar2 != piVar8 + 0x16) {
            piVar7 = (int *)*piVar2;
            operator_delete(piVar2);
            piVar2 = piVar7;
          }
          piVar2 = piVar8 + 0x14;
          do {
            piVar2 = piVar2 + -3;
            piVar7 = (int *)*piVar2;
            while (piVar2 != piVar7) {
              piVar6 = (int *)*piVar7;
              operator_delete(piVar7);
              piVar7 = piVar6;
            }
          } while (piVar8 + 0xb != piVar2);
          piVar2 = (int *)piVar8[8];
          while (piVar8 + 8 != piVar2) {
            piVar7 = (int *)*piVar2;
            operator_delete(piVar2);
            piVar2 = piVar7;
          }
          piVar2 = (int *)piVar8[5];
          while (piVar2 != piVar8 + 5) {
            piVar7 = (int *)*piVar2;
            operator_delete(piVar2);
            piVar2 = piVar7;
          }
          operator_delete(piVar8);
          piVar2 = *(int **)(param_1 + 0xabc);
        }
      }
    }
  }
  if (*(int *)(*(int *)(param_1 + 0xac0) + 8) == 0) {
    __android_log_print(6,"CAMPAN_ATTR","tracking head empty");
    *(undefined4 *)(param_1 + 0x330) = 0xffffffff;
  }
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x318));
  return;
}



/* campan_set_second_person_head(campan_feature_match_t*, nn_campan_person_head_t*) */

void campan_set_second_person_head(campan_feature_match_t *param_1,nn_campan_person_head_t *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  undefined4 *puVar4;
  _List_node_base *p_Var5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  _List_node_base *p_Var9;
  undefined4 *puVar10;
  _List_node_base *p_Var11;
  void *pvVar12;
  int *piVar13;
  _List_node_base *local_5c;
  _List_node_base *p_Stack_58;
  int local_54;
  _List_node_base *local_50;
  _List_node_base *p_Stack_4c;
  int local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  
  __android_log_print(6,"CAMPAN_ATTR","set second tracking person head");
  FUN_000202a0(param_2);
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x318));
  local_44 = *(int *)param_2;
  local_48 = 0;
  for (piVar7 = (int *)**(int **)(param_1 + 0x2c8); local_50 = (_List_node_base *)&local_50,
      p_Stack_4c = (_List_node_base *)&local_50, piVar7 != *(int **)(param_1 + 0x2c8);
      piVar7 = (int *)*piVar7) {
    if (local_44 == piVar7[5]) {
      p_Var11 = (_List_node_base *)(piVar7 + 2);
      if ((p_Var11 != (_List_node_base *)&local_50) &&
         (p_Var9 = (_List_node_base *)piVar7[2], p_Var11 != p_Var9)) {
        local_54 = 0;
        local_5c = (_List_node_base *)&local_5c;
        p_Stack_58 = (_List_node_base *)&local_5c;
        do {
          p_Var5 = (_List_node_base *)operator_new(0x180);
          memcpy(p_Var5 + 8,p_Var9 + 8,0x178);
          std::__detail::_List_node_base::_M_hook(p_Var5);
          p_Var9 = *(_List_node_base **)p_Var9;
          local_54 = local_54 + 1;
        } while (p_Var11 != p_Var9);
        if (local_5c != (_List_node_base *)&local_5c) {
          std::__detail::_List_node_base::_M_transfer((_List_node_base *)&local_50,local_5c);
          local_48 = local_48 + local_54;
          local_54 = 0;
          p_Var11 = local_5c;
          while (p_Var11 != (_List_node_base *)&local_5c) {
            p_Var9 = *(_List_node_base **)p_Var11;
            operator_delete(p_Var11);
            p_Var11 = p_Var9;
          }
        }
      }
      break;
    }
  }
  piVar13 = *(int **)(param_1 + 0x2cc);
  piVar7 = (int *)*piVar13;
  if (piVar7 != piVar13) {
    bVar3 = false;
    do {
      piVar2 = piVar7 + 5;
      piVar7 = (int *)*piVar7;
      if (*piVar2 == *(int *)param_2) {
        bVar3 = true;
      }
    } while (piVar7 != piVar13);
    if (bVar3) {
      __android_log_print(6,"CAMPAN_ATTR","second head already exist %d");
      goto LAB_00020b24;
    }
  }
  p_Var9 = (_List_node_base *)operator_new(0x30);
  *(undefined4 *)(p_Var9 + 0x10) = 0;
  *(_List_node_base **)(p_Var9 + 8) = p_Var9 + 8;
  *(_List_node_base **)(p_Var9 + 0xc) = p_Var9 + 8;
  p_Var11 = local_50;
  while (p_Var11 != (_List_node_base *)&local_50) {
    p_Var5 = (_List_node_base *)operator_new(0x180);
    memcpy(p_Var5 + 8,p_Var11 + 8,0x178);
    std::__detail::_List_node_base::_M_hook(p_Var5);
    p_Var11 = *(_List_node_base **)p_Var11;
    *(int *)(p_Var9 + 0x10) = *(int *)(p_Var9 + 0x10) + 1;
  }
  *(undefined4 *)(p_Var9 + 0x18) = local_40;
  *(int *)(p_Var9 + 0x14) = local_44;
  *(undefined4 *)(p_Var9 + 0x28) = local_30;
  *(undefined4 *)(p_Var9 + 0x20) = local_38;
  *(undefined4 *)(p_Var9 + 0x24) = uStack_34;
  std::__detail::_List_node_base::_M_hook(p_Var9);
  iVar6 = piVar13[2];
  uVar8 = iVar6 + 1;
  piVar13[2] = uVar8;
  if (4 < uVar8) {
    pvVar12 = (void *)*piVar13;
    piVar13[2] = iVar6;
    std::__detail::_List_node_base::_M_unhook();
    puVar1 = (undefined4 *)((int)pvVar12 + 8);
    puVar4 = (undefined4 *)*puVar1;
    while (puVar1 != puVar4) {
      puVar10 = (undefined4 *)*puVar4;
      operator_delete(puVar4);
      puVar4 = puVar10;
    }
    operator_delete(pvVar12);
  }
LAB_00020b24:
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x318));
  __android_log_print(6,"CAMPAN_ATTR","set second person finish");
  p_Var11 = local_50;
  while (p_Var11 != (_List_node_base *)&local_50) {
    p_Var9 = *(_List_node_base **)p_Var11;
    operator_delete(p_Var11);
    p_Var11 = p_Var9;
  }
  return;
}



/* campan_use_new_humanpose_set_human_head(nn_campan_cfg_t*, nn_campan_use_humanpose_trackid_out_t*)
    */

void campan_use_new_humanpose_set_human_head
               (nn_campan_cfg_t *param_1,nn_campan_use_humanpose_trackid_out_t *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  bool bVar14;
  float fVar15;
  float __x;
  undefined4 uVar16;
  float fVar17;
  float fVar18;
  double dVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  double dVar25;
  double dVar26;
  int local_a0;
  int local_94;
  nn_yuv_t anStack_8c [24];
  int local_74;
  int local_70;
  
  nnyuv2axyuv(anStack_8c);
  *(undefined4 *)(param_2 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_2 + 0x20) = 0xffffffff;
  if (0 < *(int *)(param_2 + 0x14)) {
    fVar22 = 10000.0;
    local_a0 = -1;
    local_94 = 0;
    do {
      iVar1 = local_94 * 0x2c + *(int *)(param_2 + 0x10);
      iVar7 = *(int *)(iVar1 + 8);
      iVar5 = (*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 4)) + 1;
      iVar3 = (*(int *)(iVar1 + 0x10) - iVar7) + 1;
      uVar10 = iVar7 + iVar3;
      dVar19 = (double)(longlong)iVar5;
      dVar25 = (double)(ulonglong)uVar10;
      iVar1 = (int)(longlong)((double)(longlong)*(int *)(iVar1 + 4) + dVar19 * 0.5);
      uVar16 = (undefined4)(longlong)((double)(longlong)iVar7 + (double)(longlong)iVar3 * 0.5);
      dVar26 = (double)CONCAT44(iVar1,uVar16);
      __android_log_print(6,"CAMPAN_ATTR",
                          "ok_hand_box, hand_w:%d, hand_h:%d, hand_center_x:%d, hand_center_y:%d, hand_bottom_line_center_x:%d, hand_bottom_line_center_y:%d"
                          ,iVar5,iVar3,iVar1,uVar16,iVar1,uVar10);
      fVar21 = (float)(dVar19 * 0.8);
      if (0 < *(int *)(param_2 + 4)) {
        iVar5 = 0;
        do {
          iVar4 = iVar5 * 0x2a8;
          iVar7 = *(int *)param_2 + iVar4;
          iVar9 = *(int *)(iVar7 + 0x224);
          iVar8 = *(int *)(iVar7 + 0x228);
          iVar6 = *(int *)(iVar7 + 0x22c);
          iVar11 = *(int *)(iVar7 + 0x230);
          __android_log_print(6,"CAMPAN_ATTR","wrist_value:%d %d %d %d\n",iVar9,iVar8,iVar6,iVar11,
                              (int)((ulonglong)dVar26 >> 0x20),dVar25);
          iVar7 = *(int *)param_2 + iVar4;
          if (iVar9 == 0 && iVar8 == 0) {
            if (iVar6 != 0 || iVar11 != 0) {
              fVar24 = 10000.0;
              fVar18 = 10000.0;
              fVar20 = 10000.0;
              goto LAB_00020e52;
            }
            fVar17 = 10000.0;
            fVar15 = 10000.0;
            fVar23 = 10000.0;
            dVar25 = 0.0;
          }
          else {
            iVar8 = uVar10 - *(int *)(iVar7 + 0x228);
            iVar9 = iVar1 - *(int *)(iVar7 + 0x224);
            if (iVar8 < 0) {
              iVar8 = -iVar8;
            }
            if (iVar9 < 0) {
              iVar9 = -iVar9;
            }
            fVar20 = (float)(longlong)iVar8;
            fVar18 = (float)(longlong)iVar9;
            fVar15 = fVar20 * fVar20 + fVar18 * fVar18;
            fVar24 = SQRT(fVar15);
            if ((int)((uint)(fVar15 < 0.0) << 0x1f) < 0) {
              sqrtf(fVar15);
              iVar7 = *(int *)param_2 + iVar4;
            }
            if (iVar6 == 0 && iVar11 == 0) {
              fVar17 = 10000.0;
              fVar15 = fVar17;
              fVar23 = fVar17;
LAB_00020e2e:
              if (fVar17 == fVar24 || fVar17 < fVar24 != (NAN(fVar17) || NAN(fVar24))) {
LAB_00020eac:
                dVar25 = (double)fVar23;
                goto LAB_00020d42;
              }
            }
            else {
LAB_00020e52:
              iVar4 = uVar10 - *(int *)(iVar7 + 0x230);
              iVar7 = iVar1 - *(int *)(iVar7 + 0x22c);
              if (iVar4 < 0) {
                iVar4 = -iVar4;
              }
              if (iVar7 < 0) {
                iVar7 = -iVar7;
              }
              fVar23 = (float)(longlong)iVar4;
              fVar15 = (float)(longlong)iVar7;
              __x = fVar23 * fVar23 + fVar15 * fVar15;
              fVar17 = SQRT(__x);
              if (-1 < (int)((uint)(__x < 0.0) << 0x1f)) goto LAB_00020e2e;
              sqrtf(__x);
              if (fVar17 == fVar24 || fVar17 < fVar24 != (NAN(fVar17) || NAN(fVar24)))
              goto LAB_00020eac;
            }
            fVar23 = fVar20;
            fVar15 = fVar18;
            dVar25 = (double)fVar23;
            fVar17 = fVar24;
          }
LAB_00020d42:
          if (((fVar15 <= fVar21) && (fVar23 <= (float)((double)(longlong)iVar3 * 0.7))) &&
             (fVar22 != fVar17 && fVar22 < fVar17 == (NAN(fVar22) || NAN(fVar17)))) {
            fVar22 = fVar17;
            local_a0 = iVar5;
          }
          iVar5 = iVar5 + 1;
          dVar26 = (double)fVar21;
          __android_log_print(6,"CAMPAN_ATTR",
                              "min_dst_x_value:%f, dist_thre_x:%f, min_dst_y_value:%f, dist_thre_y:%f, min_wrist_dist_score:%f\n"
                             );
        } while (iVar5 < *(int *)(param_2 + 4));
      }
      if (local_a0 == -1) {
        *(undefined4 *)(param_2 + 0x1c) = 0xffffffff;
        *(undefined4 *)(param_2 + 0x20) = 0xffffffff;
      }
      else {
        iVar1 = *(int *)param_2 + local_a0 * 0x2a8;
        *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(*(int *)param_2 + local_a0 * 0x2a8);
        if (0 < *(int *)(param_2 + 0xc)) {
          puVar13 = *(undefined4 **)(param_2 + 8);
          iVar3 = 0;
          do {
            iVar7 = (int)(longlong)((double)(longlong)(int)(puVar13[3] - puVar13[1]) * 1.2);
            iVar4 = (int)(longlong)((double)(longlong)(int)(puVar13[4] - puVar13[2]) * 1.2);
            iVar5 = (int)(puVar13[1] + puVar13[3]) / 2 - iVar7 / 2;
            bVar14 = iVar5 < 0;
            iVar7 = iVar7 + iVar5;
            if (bVar14) {
              iVar5 = 0;
            }
            iVar6 = (int)(puVar13[2] + puVar13[4]) / 2 - iVar4 / 2;
            iVar4 = iVar4 + iVar6;
            if ((!bVar14) && (local_74 <= iVar5)) {
              iVar5 = local_74 + -1;
            }
            if (iVar6 < 0) {
              iVar6 = 0;
            }
            else if (local_70 <= iVar6) {
              iVar6 = local_70 + -1;
            }
            if (iVar7 < 0) {
              iVar7 = 0;
            }
            else if (local_74 <= iVar7) {
              iVar7 = local_74 + -1;
            }
            if (iVar4 < 0) {
              iVar4 = 0;
            }
            else if (local_70 <= iVar4) {
              iVar4 = local_70 + -1;
            }
            iVar12 = 0;
            iVar11 = 0;
            iVar9 = 0;
            iVar8 = iVar1;
            do {
              iVar2 = *(int *)(iVar8 + 0x1dc);
              if ((iVar2 == 0) && (*(int *)(iVar8 + 0x1e0) == 0)) {
                iVar12 = iVar12 + 1;
              }
              else {
                iVar9 = iVar9 + 1;
                if ((iVar5 <= iVar2) &&
                   (*(int *)(iVar8 + 0x1e0) <= iVar4 &&
                    (iVar6 <= *(int *)(iVar8 + 0x1e0) && iVar2 <= iVar7))) {
                  iVar11 = iVar11 + 1;
                }
              }
              iVar8 = iVar8 + 8;
            } while (iVar1 + 0x28 != iVar8);
            if (iVar12 != 5 && iVar9 == iVar11) {
              *(undefined4 *)(param_2 + 0x20) = *puVar13;
              break;
            }
            iVar3 = iVar3 + 1;
            *(undefined4 *)(param_2 + 0x20) = 0xffffffff;
            puVar13 = puVar13 + 0xf;
          } while (*(int *)(param_2 + 0xc) != iVar3);
        }
      }
      local_94 = local_94 + 1;
    } while (local_94 < *(int *)(param_2 + 0x14));
  }
  return;
}



/* campan_face_pose_create(_vx_context*, char const*, ax_size_t, ImageFormat_E) */

void campan_face_pose_create
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  char acStack_11c [128];
  char acStack_9c [128];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  sprintf(acStack_11c,"%s/headpose.ezb",param_2);
  sprintf(acStack_9c,"%s/headpose.bin",param_2);
  face_pose_create(param_1,acStack_11c,acStack_9c,param_3,param_4,param_5,0x70,0x70);
  if (local_1c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* campan_face_pose_process(face_pose_t*, ax_yuv_t*, nn_campan_faces_t*) */

void campan_face_pose_process(face_pose_t *param_1,ax_yuv_t *param_2,nn_campan_faces_t *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  if (0 < *(int *)(param_3 + 4)) {
    iVar1 = 0;
    do {
      iVar2 = iVar1 * 0x178 + *(int *)param_3;
      iVar1 = iVar1 + 1;
      local_38 = *(undefined4 *)(iVar2 + 4);
      local_34 = *(undefined4 *)(iVar2 + 8);
      local_30 = *(undefined4 *)(iVar2 + 0xc);
      local_2c = *(undefined4 *)(iVar2 + 0x10);
      face_pose_process(param_1,param_2,(ax_box_t *)&local_38,(float *)(iVar2 + 0x4c));
    } while (iVar1 < *(int *)(param_3 + 4));
    return;
  }
  return;
}



/* campan_face_pose_release(face_pose_t*) */

void campan_face_pose_release(face_pose_t *param_1)

{
  if (param_1 == (face_pose_t *)0x0) {
    return;
  }
  face_pose_release(param_1);
  return;
}



/* campan_face_feature_create(_vx_context*, char const*, ax_size_t, ImageFormat_E) */

void campan_face_feature_create
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined8 local_180;
  undefined8 local_178;
  undefined4 local_170;
  undefined4 uStack_16c;
  undefined4 local_168;
  undefined4 uStack_164;
  undefined8 local_160;
  undefined4 local_158;
  undefined4 uStack_154;
  undefined4 local_150;
  undefined4 uStack_14c;
  undefined8 local_148;
  undefined4 local_140;
  undefined4 uStack_13c;
  undefined4 local_138;
  undefined4 uStack_134;
  char acStack_12c [128];
  char acStack_ac [128];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  sprintf(acStack_12c,"%s/face_feature.ezb",param_2);
  sprintf(acStack_ac,"%s/face_feature.bin",param_2);
  local_178 = 0x4049d9205bc01a37;
  local_170 = 0x2de00d2;
  uStack_16c = 0x40526209;
  local_168 = 0xe00d1b71;
  uStack_164 = 0x4049c02d;
  local_160 = 0x404c0339c0ebedfa;
  local_158 = 0x74538ef3;
  uStack_154 = 0x4051ef24;
  local_150 = 0x765fd8ae;
  uStack_14c = 0x4044c64f;
  local_180 = 0x404325b573eab368;
  local_148 = 0x405717645a1cac08;
  local_140 = 0x7ae147ae;
  uStack_13c = 0x4051ae14;
  local_138 = 0xf9724745;
  uStack_134 = 0x40570d0f;
  face_feature_create(param_1,acStack_12c,acStack_ac,param_3,param_4,0x70,0x70,&local_180,param_5);
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* campan_face_feature_process(nn_face_feature_t*, ax_yuv_t*, nn_campan_face_t*, int) */

int campan_face_feature_process
              (nn_face_feature_t *param_1,ax_yuv_t *param_2,nn_campan_face_t *param_3,int param_4)

{
  int iVar1;
  nn_campan_face_t *pnVar2;
  undefined4 *puVar3;
  float __x;
  double dVar4;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48 [9];
  int local_24;
  
  pnVar2 = param_3 + 0x20;
  uStack_54 = *(undefined4 *)(param_3 + 0xc);
  local_5c = *(undefined4 *)(param_3 + 4);
  local_58 = *(undefined4 *)(param_3 + 8);
  puVar3 = &uStack_4c;
  local_50 = *(undefined4 *)(param_3 + 0x10);
  do {
    pnVar2 = pnVar2 + 4;
    puVar3 = puVar3 + 1;
    *puVar3 = *(undefined4 *)pnVar2;
  } while (pnVar2 != param_3 + 0x48);
  if (0 < local_24) {
    iVar1 = face_feature_process(param_1,param_2,(face_box_t *)&local_5c,(signed *)(param_3 + 0x60))
    ;
    if (iVar1 == 0) {
      iVar1 = *(int *)param_1;
      *(int *)(param_3 + 0x160) = iVar1;
      if (iVar1 < 1) {
        dVar4 = 0.0;
      }
      else {
        dVar4 = 0.0;
        pnVar2 = param_3 + 0x5f;
        do {
          pnVar2 = pnVar2 + 1;
          dVar4 = dVar4 + (double)(longlong)((int)(short)(char)*pnVar2 * (int)(short)(char)*pnVar2);
        } while (pnVar2 != param_3 + iVar1 + 0x5f);
        __x = (float)dVar4;
        if ((int)((uint)(__x < 0.0) << 0x1f) < 0) {
          sqrtf(__x);
          dVar4 = (double)SQRT(__x);
        }
        else {
          dVar4 = (double)SQRT(__x);
        }
      }
      *(double *)(param_3 + 0x168) = dVar4;
      *(undefined4 *)(param_3 + 0x170) = 1;
      return 0;
    }
    *(undefined4 *)(param_3 + 0x170) = 0;
    return iVar1;
  }
  *(undefined4 *)(param_3 + 0x170) = 0;
  return 1;
}



/* campan_face_feature_release(nn_face_feature_t*) */

void campan_face_feature_release(nn_face_feature_t *param_1)

{
  if (param_1 == (nn_face_feature_t *)0x0) {
    return;
  }
  face_feature_release(param_1);
  return;
}



/* campan_face_quality_create(_vx_context*, char const*, ax_size_t, ImageFormat_E) */

void campan_face_quality_create
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined8 local_180;
  undefined8 local_178;
  undefined4 local_170;
  undefined4 uStack_16c;
  undefined4 local_168;
  undefined4 uStack_164;
  undefined8 local_160;
  undefined4 local_158;
  undefined4 uStack_154;
  undefined4 local_150;
  undefined4 uStack_14c;
  undefined8 local_148;
  undefined4 local_140;
  undefined4 uStack_13c;
  undefined4 local_138;
  undefined4 uStack_134;
  char acStack_12c [128];
  char acStack_ac [128];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  sprintf(acStack_12c,"%s/face_quality.ezb",param_2);
  sprintf(acStack_ac,"%s/face_quality.bin",param_2);
  local_178 = 0x4049d9205bc01a37;
  local_170 = 0x2de00d2;
  uStack_16c = 0x40506209;
  local_168 = 0xe00d1b71;
  uStack_164 = 0x4046402d;
  local_160 = 0x40480339c0ebedfa;
  local_158 = 0x74538ef3;
  uStack_154 = 0x4051ef24;
  local_150 = 0xecbfb15b;
  uStack_14c = 0x40348c9e;
  local_180 = 0x403e4b6ae7d566cf;
  local_148 = 0x405717645a1cac08;
  local_140 = 0xf5c28f5c;
  uStack_13c = 0x404f5c28;
  local_138 = 0xf9724745;
  uStack_134 = 0x40554d0f;
  nn_face_quality_create
            (param_1,acStack_12c,acStack_ac,param_3,param_4,0x60,0x70,&local_180,param_5);
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* campan_face_quality_process(nn_face_quality_t*, ax_yuv_t*, nn_campan_faces_t*) */

void campan_face_quality_process
               (nn_face_quality_t *param_1,ax_yuv_t *param_2,nn_campan_faces_t *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  float local_68;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 local_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_50 [9];
  int local_2c;
  
  if (*(int *)(param_3 + 4) < 1) {
    return;
  }
  iVar4 = 0;
  do {
    iVar3 = iVar4 * 0x178 + *(int *)param_3;
    local_64 = *(undefined4 *)(iVar3 + 4);
    puVar2 = (undefined4 *)(iVar3 + 0x20);
    uStack_60 = *(undefined4 *)(iVar3 + 8);
    local_5c = *(undefined4 *)(iVar3 + 0xc);
    uStack_58 = *(undefined4 *)(iVar3 + 0x10);
    puVar1 = &uStack_54;
    do {
      puVar2 = puVar2 + 1;
      puVar1 = puVar1 + 1;
      *puVar1 = *puVar2;
    } while (puVar2 != (undefined4 *)(iVar3 + 0x48));
    if (local_2c < 1) {
      *(undefined4 *)(iVar3 + 0x58) = 0;
    }
    else {
      nn_face_quality_process(param_1,param_2,(face_box_t *)&local_64,&local_68);
      *(float *)(iVar3 + 0x58) = local_68;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < *(int *)(param_3 + 4));
  return;
}



/* campan_face_quality_release(nn_face_quality_t*) */

void campan_face_quality_release(nn_face_quality_t *param_1)

{
  if (param_1 == (nn_face_quality_t *)0x0) {
    return;
  }
  nn_face_quality_release(param_1);
  return;
}



/* campan_human_pose_create(_vx_context*, char const*, ax_size_t, ImageFormat_E) */

void campan_human_pose_create
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  char acStack_11c [128];
  char acStack_9c [128];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  sprintf(acStack_11c,"%s/humanpose.ezb",param_2);
  sprintf(acStack_9c,"%s/humanpose.bin",param_2);
  human_pose_create(param_1,acStack_11c,acStack_9c,param_3,param_4,param_5,0xc0,0x100,1);
  if (local_1c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* campan_human_pose_process(human_pose_t*, ax_yuv_t*, nn_campan_persons_t*, float) */

void campan_human_pose_process
               (human_pose_t *param_1,ax_yuv_t *param_2,nn_campan_persons_t *param_3,float param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  if (0 < *(int *)(param_3 + 4)) {
    iVar2 = 0;
    do {
      iVar1 = iVar2 * 0x2a8 + *(int *)param_3;
      iVar2 = iVar2 + 1;
      local_38 = *(undefined4 *)(iVar1 + 4);
      local_34 = *(undefined4 *)(iVar1 + 8);
      local_30 = *(undefined4 *)(iVar1 + 0xc);
      local_2c = *(undefined4 *)(iVar1 + 0x10);
      human_pose_process(param_1,param_2,(ax_box_t *)&local_38,(int *)(iVar1 + 0x154),param_4);
    } while (iVar2 < *(int *)(param_3 + 4));
    return;
  }
  return;
}



/* campan_use_humanpose_set_human_head(human_pose_t*, nn_campan_cfg_t*,
   nn_campan_use_humanpose_trackid_out_t*) */

void campan_use_humanpose_set_human_head
               (human_pose_t *param_1,nn_campan_cfg_t *param_2,
               nn_campan_use_humanpose_trackid_out_t *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  bool bVar12;
  float fVar13;
  float __x;
  float fVar14;
  int iVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  double dVar22;
  double dVar23;
  int local_a0;
  int local_9c;
  int local_98;
  nn_yuv_t anStack_8c [24];
  int local_74;
  int local_70;
  
  nnyuv2axyuv(anStack_8c);
  *(undefined4 *)(param_3 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_3 + 0x20) = 0xffffffff;
  if ((param_1 != (human_pose_t *)0x0) && (*(int *)(param_2 + 0x48) != 0)) {
    campan_human_pose_process(param_1,(ax_yuv_t *)anStack_8c,(nn_campan_persons_t *)param_3,0.5);
    local_9c = *(int *)(param_3 + 0x14);
    if (0 < local_9c) {
      fVar19 = 10000.0;
      iVar8 = *(int *)(param_3 + 4);
      local_98 = -1;
      local_a0 = 0;
      fVar20 = fVar19;
      do {
        iVar1 = local_a0 * 0x2c + *(int *)(param_3 + 0x10);
        dVar23 = (double)(longlong)((*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 4)) + 1);
        dVar22 = (double)(longlong)((*(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8)) + 1);
        iVar15 = (int)(longlong)((double)(longlong)*(int *)(iVar1 + 4) + dVar23 * 0.5);
        iVar1 = (int)(longlong)((double)(longlong)*(int *)(iVar1 + 8) + dVar22 * 0.5);
        if (0 < iVar8) {
          iVar4 = 0;
          do {
            iVar3 = iVar4 * 0x2a8;
            iVar8 = *(int *)param_3 + iVar3;
            iVar9 = *(int *)(iVar8 + 0x19c);
            iVar6 = *(int *)(iVar8 + 0x1a0);
            iVar10 = *(int *)(iVar8 + 0x1a4);
            iVar8 = *(int *)(iVar8 + 0x1a8);
            __android_log_print(6,"CAMPAN_ATTR","wrist_value:%d %d %d %d\n",iVar9,iVar6,iVar10,iVar8
                               );
            if (iVar9 == -1 && iVar6 == -1) {
              if (iVar10 != -1 || iVar8 != -1) {
                fVar16 = 10000.0;
                fVar17 = fVar16;
                fVar18 = fVar16;
                goto LAB_00021898;
              }
              fVar17 = 10000.0;
              fVar18 = 10000.0;
            }
            else {
              iVar6 = iVar1 - *(int *)(*(int *)param_3 + iVar3 + 0x1a0);
              iVar9 = iVar15 - *(int *)(*(int *)param_3 + iVar3 + 0x19c);
              if (iVar6 < 0) {
                iVar6 = -iVar6;
              }
              if (iVar9 < 0) {
                iVar9 = -iVar9;
              }
              fVar18 = (float)(longlong)iVar6;
              fVar17 = (float)(longlong)iVar9;
              fVar13 = fVar18 * fVar18 + fVar17 * fVar17;
              fVar16 = SQRT(fVar13);
              if ((int)((uint)(fVar13 < 0.0) << 0x1f) < 0) {
                sqrtf(fVar13);
              }
              if (iVar10 != -1 || iVar8 != -1) {
LAB_00021898:
                iVar8 = iVar1 - *(int *)(iVar3 + *(int *)param_3 + 0x1a8);
                iVar3 = iVar15 - *(int *)(iVar3 + *(int *)param_3 + 0x1a4);
                if (iVar8 < 0) {
                  iVar8 = -iVar8;
                }
                if (iVar3 < 0) {
                  iVar3 = -iVar3;
                }
                fVar13 = (float)(longlong)iVar8;
                fVar21 = (float)(longlong)iVar3;
                __x = fVar13 * fVar13 + fVar21 * fVar21;
                fVar14 = SQRT(__x);
                if ((int)((uint)(__x < 0.0) << 0x1f) < 0) {
                  sqrtf(__x);
                }
              }
              else {
                fVar14 = 10000.0;
                fVar13 = fVar14;
                fVar21 = fVar14;
              }
              if (fVar14 == fVar16 || fVar14 < fVar16 != (NAN(fVar14) || NAN(fVar16))) {
                fVar17 = fVar21;
                fVar18 = fVar13;
              }
            }
            if ((((fVar17 <= (float)(dVar23 * 0.45)) && (fVar18 <= (float)(dVar22 * 0.7))) &&
                ((int)((uint)(fVar17 < fVar19) << 0x1f) < 0)) &&
               ((int)((uint)(fVar18 < fVar20) << 0x1f) < 0)) {
              fVar19 = fVar17;
              fVar20 = fVar18;
              local_98 = iVar4;
            }
            iVar4 = iVar4 + 1;
            __android_log_print(6,"CAMPAN_ATTR",
                                "min_dst_x_value:%f, dist_thre_x:%f, min_dst_y_value:%f, dist_thre_y:%f\n"
                               );
            iVar8 = *(int *)(param_3 + 4);
          } while (iVar4 < iVar8);
          local_9c = *(int *)(param_3 + 0x14);
        }
        if (local_98 == -1) {
          *(undefined4 *)(param_3 + 0x1c) = 0xffffffff;
          *(undefined4 *)(param_3 + 0x20) = 0xffffffff;
        }
        else {
          iVar1 = *(int *)param_3 + local_98 * 0x2a8;
          *(undefined4 *)(param_3 + 0x1c) = *(undefined4 *)(*(int *)param_3 + local_98 * 0x2a8);
          if (0 < *(int *)(param_3 + 0xc)) {
            iVar15 = 0;
            puVar11 = *(undefined4 **)(param_3 + 8);
            do {
              iVar4 = (int)(longlong)((double)(longlong)(int)(puVar11[3] - puVar11[1]) * 1.2);
              iVar6 = (int)(longlong)((double)(longlong)(int)(puVar11[4] - puVar11[2]) * 1.2);
              iVar3 = (int)(puVar11[3] + puVar11[1]) / 2 - iVar4 / 2;
              bVar12 = iVar3 < 0;
              iVar4 = iVar4 + iVar3;
              if (bVar12) {
                iVar3 = 0;
              }
              iVar9 = (int)(puVar11[2] + puVar11[4]) / 2 - iVar6 / 2;
              iVar6 = iVar6 + iVar9;
              if ((!bVar12) && (local_74 <= iVar3)) {
                iVar3 = local_74 + -1;
              }
              if (iVar9 < 0) {
                iVar9 = 0;
              }
              else if (local_70 <= iVar9) {
                iVar9 = local_70 + -1;
              }
              if (iVar4 < 0) {
                iVar4 = 0;
              }
              else if (local_74 <= iVar4) {
                iVar4 = local_74 + -1;
              }
              if (iVar6 < 0) {
                iVar6 = 0;
              }
              else if (local_70 <= iVar6) {
                iVar6 = local_70 + -1;
              }
              iVar7 = 0;
              iVar5 = 0;
              iVar10 = iVar1;
              do {
                iVar2 = *(int *)(iVar10 + 0x154);
                if (((iVar2 != -1) || (*(int *)(iVar10 + 0x158) != -1)) &&
                   ((iVar5 = iVar5 + 1, iVar3 <= iVar2 &&
                    (*(int *)(iVar10 + 0x158) <= iVar6 &&
                     (iVar9 <= *(int *)(iVar10 + 0x158) && iVar2 <= iVar4))))) {
                  iVar7 = iVar7 + 1;
                }
                iVar10 = iVar10 + 8;
              } while (iVar1 + 0x28 != iVar10);
              if (iVar5 == iVar7) {
                *(undefined4 *)(param_3 + 0x20) = *puVar11;
                break;
              }
              iVar15 = iVar15 + 1;
              *(undefined4 *)(param_3 + 0x20) = 0xffffffff;
              puVar11 = puVar11 + 0xf;
            } while (*(int *)(param_3 + 0xc) != iVar15);
          }
        }
        local_a0 = local_a0 + 1;
        if (local_9c <= local_a0) {
          return;
        }
      } while( true );
    }
  }
  return;
}



/* campan_human_pose_release(human_pose_t*) */

void campan_human_pose_release(human_pose_t *param_1)

{
  human_pose_release(param_1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* kpt_smooth_create() */

undefined4 * kpt_smooth_create(void)

{
  undefined4 *__s;
  undefined8 *puVar1;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  undefined1 auStack_5c [68];
  float fStack_18;
  
  __s = (undefined4 *)AX_MALLOC_RECORD(0x58);
  memset(__s,0,0x58);
  puVar1 = (undefined8 *)operator_new(0x18);
  *puVar1 = 0;
  puVar1[1] = 0;
  *(undefined4 *)((int)puVar1 + 0x14) = 0;
  *(undefined4 *)((int)puVar1 + 4) = 0;
  *(undefined4 *)(puVar1 + 1) = 0;
  *(int *)((int)puVar1 + 0xc) = (int)puVar1 + 4;
  *(int *)(puVar1 + 2) = (int)puVar1 + 4;
  *__s = puVar1;
  __s[1] = 0x3f800000;
  __s[2] = 0x3d4ccccd;
  __s[3] = 0x3c23d70a;
  __s[0x15] = 0x3e99999a;
  pfVar2 = (float *)memcpy(auStack_5c,&DAT_0002808c,0x44);
  pfVar3 = (float *)(__s + 4);
  do {
    fVar4 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    *pfVar3 = fVar4 * 0.3;
    pfVar3 = pfVar3 + 1;
  } while (pfVar2 != &fStack_18);
  return __s;
}



/* campan_register_face_head_track(campan_feature_match_t*, nn_campan_register_face_head_track_t*)
    */

void campan_register_face_head_track
               (campan_feature_match_t *param_1,nn_campan_register_face_head_track_t *param_2)

{
  int iVar1;
  _List_node_base *p_Var2;
  _List_node_base *p_Var3;
  _List_node_base *p_Var4;
  undefined4 *puVar5;
  undefined4 *****pppppuVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *****pppppuVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  double dVar15;
  int local_2c0 [3];
  undefined4 ****local_2b4;
  undefined4 ****local_2b0;
  int local_2ac;
  undefined4 ****local_2a8;
  undefined4 ****ppppuStack_2a4;
  undefined4 local_2a0;
  undefined4 local_29c [9];
  undefined4 local_278;
  undefined4 local_274;
  undefined4 ****local_270;
  undefined4 ****ppppuStack_26c;
  undefined4 local_268;
  undefined4 ****local_264;
  undefined4 ****ppppuStack_260;
  undefined4 local_25c;
  undefined4 local_258 [15];
  undefined4 local_21c;
  undefined8 local_218;
  undefined8 local_210;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  undefined4 uStack_1e4;
  undefined4 local_1e0;
  undefined4 uStack_1dc;
  undefined4 local_1d8;
  undefined4 uStack_1d4;
  undefined4 local_1d0;
  undefined4 uStack_1cc;
  undefined4 local_1c8;
  undefined4 uStack_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined1 auStack_1b0 [96];
  undefined1 auStack_150 [284];
  int local_34;
  
  iVar1 = *(int *)(param_1 + 0xabc);
  local_2ac = 0;
  local_34 = __stack_chk_guard;
  local_2a0 = 0;
  puVar12 = &local_278;
  puVar5 = local_29c;
  do {
    puVar5[2] = 0;
    *puVar5 = puVar5;
    puVar5[1] = puVar5;
    puVar5 = puVar5 + 3;
  } while (puVar12 != puVar5);
  local_268 = 0;
  local_25c = 0;
  puVar5 = local_258;
  do {
    puVar5[2] = 0;
    *puVar5 = puVar5;
    puVar5[1] = puVar5;
    puVar5 = puVar5 + 3;
  } while (puVar5 != &local_21c);
  local_21c = 0;
  local_208 = 0;
  local_200 = 0;
  local_1f4 = 0;
  local_2c0[2] = 0;
  local_1c8 = 0;
  uStack_1c4 = 0;
  local_204 = 0xffffffff;
  local_278 = 0xffffffff;
  local_274 = 0xffffffff;
  local_1f8 = 0xffffffff;
  local_1bc = 0xffffffff;
  local_1b8 = 0xffffffff;
  local_1fc = 1;
  local_2b4 = &local_2b4;
  local_2b0 = &local_2b4;
  local_2a8 = &local_2a8;
  ppppuStack_2a4 = &local_2a8;
  local_270 = &local_270;
  ppppuStack_26c = &local_270;
  local_264 = &local_264;
  ppppuStack_260 = &local_264;
  dVar15 = (double)get_time_ms();
  memset(auStack_1b0,0,0x178);
  memcpy(auStack_150,param_2,0x118);
  p_Var2 = (_List_node_base *)operator_new(0x180);
  memcpy(p_Var2 + 8,auStack_1b0,0x178);
  std::__detail::_List_node_base::_M_hook(p_Var2);
  local_2c0[0] = *(int *)(param_2 + 0x118);
  local_2ac = local_2ac + 1;
  local_2c0[1] = 0xffffffff;
  local_208 = 1;
  local_1bc = 1;
  local_218 = dVar15 / 1000.0;
  local_210 = dVar15 / 1000.0;
  p_Var2 = (_List_node_base *)operator_new(0x118);
  *(undefined4 *)(p_Var2 + 0x1c) = 0;
  *(int *)(p_Var2 + 8) = local_2c0[0];
  *(int *)(p_Var2 + 0xc) = local_2c0[1];
  *(int *)(p_Var2 + 0x10) = local_2c0[2];
  *(_List_node_base **)(p_Var2 + 0x14) = p_Var2 + 0x14;
  *(_List_node_base **)(p_Var2 + 0x18) = p_Var2 + 0x14;
  pppppuVar6 = (undefined4 *****)local_2b4;
  while (pppppuVar6 != &local_2b4) {
    p_Var3 = (_List_node_base *)operator_new(0x180);
    memcpy(p_Var3 + 8,pppppuVar6 + 2,0x178);
    std::__detail::_List_node_base::_M_hook(p_Var3);
    pppppuVar6 = (undefined4 *****)*pppppuVar6;
    *(int *)(p_Var2 + 0x1c) = *(int *)(p_Var2 + 0x1c) + 1;
  }
  *(_List_node_base **)(p_Var2 + 0x24) = p_Var2 + 0x20;
  *(undefined4 *)(p_Var2 + 0x28) = 0;
  *(_List_node_base **)(p_Var2 + 0x20) = p_Var2 + 0x20;
  pppppuVar6 = (undefined4 *****)local_2a8;
  while (pppppuVar6 != &local_2a8) {
    p_Var3 = (_List_node_base *)operator_new(0x180);
    memcpy(p_Var3 + 8,pppppuVar6 + 2,0x178);
    std::__detail::_List_node_base::_M_hook(p_Var3);
    pppppuVar6 = (undefined4 *****)*pppppuVar6;
    *(int *)(p_Var2 + 0x28) = *(int *)(p_Var2 + 0x28) + 1;
  }
  p_Var3 = p_Var2 + 0x2c;
  iVar13 = 2;
  piVar8 = local_2c0;
  while( true ) {
    *(_List_node_base **)p_Var3 = p_Var3;
    *(_List_node_base **)(p_Var3 + 4) = p_Var3;
    piVar7 = (int *)piVar8[9];
    *(undefined4 *)(p_Var3 + 8) = 0;
    while (piVar8 + 9 != piVar7) {
      p_Var4 = (_List_node_base *)operator_new(0x180);
      memcpy(p_Var4 + 8,piVar7 + 2,0x178);
      std::__detail::_List_node_base::_M_hook(p_Var4);
      piVar7 = (int *)*piVar7;
      *(int *)(p_Var3 + 8) = *(int *)(p_Var3 + 8) + 1;
    }
    p_Var3 = p_Var3 + 0xc;
    piVar8 = piVar8 + 3;
    if (iVar13 == 0) break;
    iVar13 = iVar13 + -1;
  }
  *(undefined4 *)(p_Var2 + 0x50) = local_278;
  *(undefined4 *)(p_Var2 + 0x54) = local_274;
  *(undefined4 *)(p_Var2 + 0x60) = 0;
  *(_List_node_base **)(p_Var2 + 0x58) = p_Var2 + 0x58;
  *(_List_node_base **)(p_Var2 + 0x5c) = p_Var2 + 0x58;
  pppppuVar6 = (undefined4 *****)local_270;
  while (pppppuVar6 != &local_270) {
    p_Var3 = (_List_node_base *)operator_new(0x2b0);
    memcpy(p_Var3 + 8,pppppuVar6 + 2,0x2a8);
    std::__detail::_List_node_base::_M_hook(p_Var3);
    pppppuVar6 = (undefined4 *****)*pppppuVar6;
    *(int *)(p_Var2 + 0x60) = *(int *)(p_Var2 + 0x60) + 1;
  }
  *(_List_node_base **)(p_Var2 + 0x68) = p_Var2 + 100;
  *(undefined4 *)(p_Var2 + 0x6c) = 0;
  *(_List_node_base **)(p_Var2 + 100) = p_Var2 + 100;
  pppppuVar6 = (undefined4 *****)local_264;
  while (pppppuVar6 != &local_264) {
    p_Var3 = (_List_node_base *)operator_new(0x2b0);
    memcpy(p_Var3 + 8,pppppuVar6 + 2,0x2a8);
    std::__detail::_List_node_base::_M_hook(p_Var3);
    pppppuVar6 = (undefined4 *****)*pppppuVar6;
    *(int *)(p_Var2 + 0x6c) = *(int *)(p_Var2 + 0x6c) + 1;
  }
  p_Var3 = p_Var2 + 0x70;
  iVar13 = 0x68;
  iVar14 = 4;
  do {
    piVar8 = *(int **)((int)local_2c0 + iVar13);
    *(_List_node_base **)p_Var3 = p_Var3;
    *(_List_node_base **)(p_Var3 + 4) = p_Var3;
    *(undefined4 *)(p_Var3 + 8) = 0;
    while (piVar8 != (int *)((int)local_2c0 + iVar13)) {
      p_Var4 = (_List_node_base *)operator_new(0x2b0);
      memcpy(p_Var4 + 8,piVar8 + 2,0x2a8);
      std::__detail::_List_node_base::_M_hook(p_Var4);
      piVar8 = (int *)*piVar8;
      *(int *)(p_Var3 + 8) = *(int *)(p_Var3 + 8) + 1;
    }
    iVar14 = iVar14 + -1;
    p_Var3 = p_Var3 + 0xc;
    iVar13 = iVar13 + 0xc;
  } while (iVar14 != -1);
  *(undefined4 *)(p_Var2 + 0xac) = local_21c;
  *(undefined4 *)(p_Var2 + 0xc0) = local_208;
  *(undefined4 *)(p_Var2 + 0xc4) = local_204;
  local_210._4_4_ = (undefined4)((ulonglong)local_210 >> 0x20);
  *(undefined4 *)(p_Var2 + 200) = local_200;
  *(undefined4 *)(p_Var2 + 0xcc) = local_1fc;
  local_218._4_4_ = (undefined4)((ulonglong)local_218 >> 0x20);
  *(undefined4 *)(p_Var2 + 0xb8) = (undefined4)local_210;
  *(undefined4 *)(p_Var2 + 0xbc) = local_210._4_4_;
  *(undefined4 *)(p_Var2 + 0xd0) = local_1f8;
  *(undefined4 *)(p_Var2 + 0xd4) = local_1f4;
  *(undefined4 *)(p_Var2 + 0xb0) = (undefined4)local_218;
  *(undefined4 *)(p_Var2 + 0xb4) = local_218._4_4_;
  *(undefined4 *)(p_Var2 + 0xd8) = local_1f0;
  *(undefined4 *)(p_Var2 + 0xdc) = uStack_1ec;
  *(undefined4 *)(p_Var2 + 0xe0) = uStack_1e8;
  *(undefined4 *)(p_Var2 + 0xe4) = uStack_1e4;
  puVar5 = &local_21c;
  *(undefined4 *)(p_Var2 + 0xe8) = local_1e0;
  *(undefined4 *)(p_Var2 + 0xec) = uStack_1dc;
  *(undefined4 *)(p_Var2 + 0xf0) = local_1d8;
  *(undefined4 *)(p_Var2 + 0xf4) = uStack_1d4;
  *(undefined4 *)(p_Var2 + 0x108) = local_1c0;
  *(undefined4 *)(p_Var2 + 0x10c) = local_1bc;
  *(undefined4 *)(p_Var2 + 0xf8) = local_1d0;
  *(undefined4 *)(p_Var2 + 0xfc) = uStack_1cc;
  *(undefined4 *)(p_Var2 + 0x100) = local_1c8;
  *(undefined4 *)(p_Var2 + 0x104) = uStack_1c4;
  *(undefined4 *)(p_Var2 + 0x110) = local_1b8;
  std::__detail::_List_node_base::_M_hook(p_Var2);
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  do {
    puVar5 = puVar5 + -3;
    puVar10 = (undefined4 *)*puVar5;
    while (puVar5 != puVar10) {
      puVar11 = (undefined4 *)*puVar10;
      operator_delete(puVar10);
      puVar10 = puVar11;
    }
    pppppuVar6 = (undefined4 *****)local_264;
  } while (puVar5 != local_258);
  while (pppppuVar9 = (undefined4 *****)local_270, pppppuVar6 != &local_264) {
    pppppuVar9 = (undefined4 *****)*pppppuVar6;
    operator_delete(pppppuVar6);
    pppppuVar6 = pppppuVar9;
  }
  while (pppppuVar9 != &local_270) {
    pppppuVar6 = (undefined4 *****)*pppppuVar9;
    operator_delete(pppppuVar9);
    pppppuVar9 = pppppuVar6;
  }
  do {
    puVar12 = puVar12 + -3;
    puVar5 = (undefined4 *)*puVar12;
    while (puVar12 != puVar5) {
      puVar10 = (undefined4 *)*puVar5;
      operator_delete(puVar5);
      puVar5 = puVar10;
    }
    pppppuVar6 = (undefined4 *****)local_2a8;
  } while (puVar12 != local_29c);
  while (pppppuVar9 = (undefined4 *****)local_2b4, pppppuVar6 != &local_2a8) {
    pppppuVar9 = (undefined4 *****)*pppppuVar6;
    operator_delete(pppppuVar6);
    pppppuVar6 = pppppuVar9;
  }
  while (pppppuVar9 != &local_2b4) {
    pppppuVar6 = (undefined4 *****)*pppppuVar9;
    operator_delete(pppppuVar9);
    pppppuVar9 = pppppuVar6;
  }
  if (local_34 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* std::vector<ax_rect_t, std::allocator<ax_rect_t>
   >::TEMPNAMEPLACEHOLDERVALUE(std::vector<ax_rect_t, std::allocator<ax_rect_t> > const&) */

vector<ax_rect_t,std::allocator<ax_rect_t>> * __thiscall
std::vector<ax_rect_t,std::allocator<ax_rect_t>>::operator=
          (vector<ax_rect_t,std::allocator<ax_rect_t>> *this,vector *param_1)

{
  void *__dest;
  size_t __n;
  void *pvVar1;
  uint __n_00;
  int iVar2;
  void *__dest_00;
  void *__src;
  void *pvVar3;
  
  if (param_1 == (vector *)this) {
    return this;
  }
  __src = *(void **)param_1;
  pvVar3 = *(void **)(param_1 + 4);
  __dest_00 = *(void **)this;
  __n_00 = (int)pvVar3 - (int)__src;
  pvVar1 = (void *)((int)__n_00 >> 4);
  if ((void *)(*(int *)(this + 8) - (int)__dest_00 >> 4) < pvVar1) {
    if (pvVar1 != (void *)0x0) {
      if ((void *)0xfffffff < pvVar1) {
                    /* WARNING: Subroutine does not return */
        std::__throw_bad_alloc();
      }
      pvVar1 = operator_new(__n_00);
      __dest_00 = *(void **)this;
    }
    if (pvVar3 != __src) {
      memmove(pvVar1,__src,__n_00);
    }
    if (__dest_00 != (void *)0x0) {
      operator_delete(__dest_00);
    }
    iVar2 = __n_00 + (int)pvVar1;
    *(int *)(this + 8) = iVar2;
    *(void **)this = pvVar1;
    goto LAB_00022136;
  }
  __dest = *(void **)(this + 4);
  __n = (int)__dest - (int)__dest_00;
  if ((void *)((int)__n >> 4) < pvVar1) {
    pvVar1 = (void *)((int)__src + __n);
    if (__src == pvVar1) {
      if (pvVar3 != pvVar1) {
LAB_0002217c:
        memmove(__dest,pvVar1,(int)pvVar3 - (int)pvVar1);
        iVar2 = __n_00 + *(int *)this;
        goto LAB_00022136;
      }
    }
    else {
      memmove(__dest_00,__src,__n);
      __dest_00 = *(void **)this;
      __dest = *(void **)(this + 4);
      pvVar3 = *(void **)(param_1 + 4);
      pvVar1 = (void *)((int)__dest + (*(int *)param_1 - (int)__dest_00));
      if (pvVar3 != pvVar1) goto LAB_0002217c;
    }
  }
  else if (pvVar3 != __src) {
    memmove(__dest_00,__src,__n_00);
    iVar2 = __n_00 + *(int *)this;
    goto LAB_00022136;
  }
  iVar2 = __n_00 + (int)__dest_00;
LAB_00022136:
  *(int *)(this + 4) = iVar2;
  return this;
}



/* std::vector<std::vector<std::vector<float, std::allocator<float> >,
   std::allocator<std::vector<float, std::allocator<float> > > >,
   std::allocator<std::vector<std::vector<float, std::allocator<float> >,
   std::allocator<std::vector<float, std::allocator<float> > > > > >::~vector() */

vector<std::vector<std::vector<float,std::allocator<float>>,std::allocator<std::vector<float,std::allocator<float>>>>,std::allocator<std::vector<std::vector<float,std::allocator<float>>,std::allocator<std::vector<float,std::allocator<float>>>>>>
* __thiscall
std::
vector<std::vector<std::vector<float,std::allocator<float>>,std::allocator<std::vector<float,std::allocator<float>>>>,std::allocator<std::vector<std::vector<float,std::allocator<float>>,std::allocator<std::vector<float,std::allocator<float>>>>>>
::~vector(vector<std::vector<std::vector<float,std::allocator<float>>,std::allocator<std::vector<float,std::allocator<float>>>>,std::allocator<std::vector<std::vector<float,std::allocator<float>>,std::allocator<std::vector<float,std::allocator<float>>>>>>
          *this)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *pvVar4;
  void *pvVar5;
  void *pvVar6;
  
  pvVar1 = *(void **)this;
  pvVar6 = *(void **)(this + 4);
  if (pvVar1 != pvVar6) {
    pvVar4 = (void *)((int)pvVar1 + 0xc);
    pvVar5 = pvVar4;
    while( true ) {
      puVar3 = *(undefined4 **)((int)pvVar1 + 4);
      puVar2 = *(undefined4 **)((int)pvVar4 + -0xc);
      if (puVar2 != puVar3) {
        do {
          pvVar1 = (void *)*puVar2;
          puVar2 = puVar2 + 3;
          if (pvVar1 != (void *)0x0) {
            operator_delete(pvVar1);
          }
        } while (puVar3 != puVar2);
        puVar3 = *(undefined4 **)((int)pvVar4 + -0xc);
      }
      if (puVar3 != (undefined4 *)0x0) {
        operator_delete(puVar3);
      }
      pvVar4 = (void *)((int)pvVar4 + 0xc);
      if (pvVar6 == pvVar5) break;
      pvVar1 = pvVar5;
      pvVar5 = (void *)((int)pvVar5 + 0xc);
    }
    pvVar6 = *(void **)this;
  }
  if (pvVar6 != (void *)0x0) {
    operator_delete(pvVar6);
  }
  return this;
}



/* std::vector<std::vector<ax_tensor_t, std::allocator<ax_tensor_t> >,
   std::allocator<std::vector<ax_tensor_t, std::allocator<ax_tensor_t> > > >::~vector() */

vector<std::vector<ax_tensor_t,std::allocator<ax_tensor_t>>,std::allocator<std::vector<ax_tensor_t,std::allocator<ax_tensor_t>>>>
* __thiscall
std::
vector<std::vector<ax_tensor_t,std::allocator<ax_tensor_t>>,std::allocator<std::vector<ax_tensor_t,std::allocator<ax_tensor_t>>>>
::~vector(vector<std::vector<ax_tensor_t,std::allocator<ax_tensor_t>>,std::allocator<std::vector<ax_tensor_t,std::allocator<ax_tensor_t>>>>
          *this)

{
  void *pvVar1;
  ax_tensor_t *this_00;
  ax_tensor_t *paVar2;
  ax_tensor_t *paVar3;
  void *pvVar4;
  void *pvVar5;
  void *pvVar6;
  
  pvVar1 = *(void **)this;
  pvVar6 = *(void **)(this + 4);
  if (pvVar1 != pvVar6) {
    pvVar4 = (void *)((int)pvVar1 + 0xc);
    pvVar5 = pvVar4;
    while( true ) {
      paVar3 = *(ax_tensor_t **)((int)pvVar1 + 4);
      this_00 = *(ax_tensor_t **)((int)pvVar4 + -0xc);
      if (*(ax_tensor_t **)((int)pvVar4 + -0xc) != paVar3) {
        do {
          paVar2 = this_00 + 0x30;
          ax_tensor_t::~ax_tensor_t(this_00);
          this_00 = paVar2;
        } while (paVar3 != paVar2);
        paVar3 = *(ax_tensor_t **)((int)pvVar4 + -0xc);
      }
      if (paVar3 != (ax_tensor_t *)0x0) {
        operator_delete(paVar3);
      }
      pvVar4 = (void *)((int)pvVar4 + 0xc);
      if (pvVar6 == pvVar5) break;
      pvVar1 = pvVar5;
      pvVar5 = (void *)((int)pvVar5 + 0xc);
    }
    pvVar6 = *(void **)this;
  }
  if (pvVar6 != (void *)0x0) {
    operator_delete(pvVar6);
  }
  return this;
}



/* float iou<ax_box_t>(ax_box_t, ax_box_t) */

float iou<ax_box_t>(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                   int param_7,int param_8)

{
  uint uVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar4 = param_1;
  if (param_1 <= param_5) {
    iVar4 = param_5;
  }
  iVar5 = param_2;
  if (param_2 <= param_6) {
    iVar5 = param_6;
  }
  iVar6 = param_3;
  if (param_7 <= param_3) {
    iVar6 = param_7;
  }
  iVar3 = param_4;
  if (param_8 <= param_4) {
    iVar3 = param_8;
  }
  uVar7 = (uint)(((float)(longlong)iVar6 - (float)(longlong)iVar4) + 1.0);
  uVar1 = (uint)(((float)(longlong)iVar3 - (float)(longlong)iVar5) + 1.0);
  if ((int)(uVar7 | uVar1) < 0) {
    fVar2 = 0.0;
  }
  else {
    fVar2 = (float)(longlong)(int)uVar7 * (float)(longlong)(int)uVar1;
  }
  return fVar2 / (((float)(longlong)(((param_4 - param_2) + 1) * ((param_3 - param_1) + 1)) +
                  (float)(longlong)(((param_8 - param_6) + 1) * ((param_7 - param_5) + 1))) - fVar2)
  ;
}



/* void AX_MALLOC_INC_TEMP<ax_int_array_t>(ax_int_array_t&, int) */

void AX_MALLOC_INC_TEMP<ax_int_array_t>(ax_int_array_t *param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = *(void **)param_1;
  iVar2 = param_2 * 4;
  *(int *)(param_1 + 4) = param_2;
  if (pvVar1 == (void *)0x0) {
    if (iVar2 < 1) {
      return;
    }
  }
  else {
    if (*(int *)((int)pvVar1 + -4) + param_2 * -4 < 0 == SBORROW4(*(int *)((int)pvVar1 + -4),iVar2))
    {
      return;
    }
    AX_FREE_RECORD(pvVar1);
    *(undefined4 *)param_1 = 0;
  }
  iVar2 = AX_MALLOC_RECORD(iVar2);
  *(int *)param_1 = iVar2;
  if (iVar2 != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}



void FUN_00022380(ax_int_array_t *param_1,int *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int extraout_r1;
  int extraout_r1_00;
  int iVar3;
  int *piVar4;
  size_t __n;
  void *__s;
  int iVar5;
  int *piVar6;
  void *__s_00;
  int iVar7;
  int iVar8;
  void *pvVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  int *piVar14;
  int iVar15;
  size_t __n_00;
  int iVar16;
  int iVar17;
  int local_6c;
  int local_60;
  
  iVar16 = param_3;
  if (param_3 < param_4) {
    iVar16 = param_4;
  }
  iVar15 = iVar16 * iVar16;
  __n = iVar16 * 4;
  AX_MALLOC_INC_TEMP<ax_int_array_t>(param_1,iVar15);
  __n_00 = iVar15 * 4;
  AX_MALLOC_INC_TEMP<ax_int_array_t>(param_1 + 0x18,iVar15);
  AX_MALLOC_INC_TEMP<ax_int_array_t>(param_1 + 0x20,__n);
  AX_MALLOC_INC_TEMP<ax_int_array_t>(param_1 + 8,iVar16);
  AX_MALLOC_INC_TEMP<ax_int_array_t>(param_1 + 0x10,iVar16);
  memset(*(void **)param_1,0,__n_00);
  memset(*(void **)(param_1 + 0x20),0,iVar16 << 4);
  piVar13 = *(int **)param_1;
  if (0 < param_4) {
    iVar15 = 0;
    piVar11 = piVar13;
    do {
      piVar10 = param_2 + param_3;
      piVar12 = piVar11;
      if (0 < param_3) {
        do {
          piVar14 = param_2 + 1;
          *piVar12 = *param_2;
          piVar12 = piVar12 + 1;
          param_2 = piVar14;
        } while (piVar10 != piVar14);
      }
      piVar11 = piVar11 + iVar16;
      iVar15 = iVar15 + 1;
      param_2 = piVar10;
    } while (iVar15 != param_4);
  }
  piVar11 = *(int **)(param_1 + 8);
  __s_00 = *(void **)(param_1 + 0x10);
  __s = *(void **)(param_1 + 0x18);
  if (iVar16 < 1) {
    memset(__s,0,__n_00);
    memset(piVar11,0,__n);
    memset(__s_00,0,__n);
  }
  else {
    iVar15 = 0;
    piVar12 = piVar13 + iVar16;
    piVar10 = piVar13;
    do {
      iVar1 = 0x7fffffff;
      piVar14 = piVar10;
      do {
        piVar6 = piVar14 + 1;
        if (*piVar14 <= iVar1) {
          iVar1 = *piVar14;
        }
        piVar4 = piVar10;
        piVar14 = piVar6;
      } while (piVar12 != piVar6);
      do {
        piVar14 = piVar4 + 1;
        *piVar4 = *piVar4 - iVar1;
        piVar4 = piVar14;
      } while (piVar6 != piVar14);
      piVar10 = piVar10 + iVar16;
      iVar15 = iVar15 + 1;
      piVar12 = piVar12 + iVar16;
      piVar14 = piVar13;
    } while (iVar16 != iVar15);
    do {
      iVar1 = 0x7fffffff;
      iVar5 = 0;
      piVar12 = piVar14;
      do {
        iVar2 = *piVar12;
        iVar5 = iVar5 + 1;
        piVar12 = piVar12 + iVar16;
        if (iVar2 <= iVar1) {
          iVar1 = iVar2;
        }
      } while (iVar15 != iVar5);
      iVar5 = 0;
      piVar12 = piVar14;
      do {
        iVar5 = iVar5 + 1;
        *piVar12 = *piVar12 - iVar1;
        piVar12 = piVar12 + iVar16;
      } while (iVar15 != iVar5);
      piVar14 = piVar14 + 1;
    } while (piVar13 + iVar16 != piVar14);
    memset(__s,0,__n_00);
    memset(piVar11,0,__n);
    memset(__s_00,0,__n);
    piVar13 = piVar13 + -1;
    piVar12 = piVar11;
    pvVar9 = __s;
    do {
      iVar1 = 0;
      piVar10 = piVar13;
      do {
        piVar10 = piVar10 + 1;
        if (((*piVar10 == 0) && (*piVar12 == 0)) && (*(int *)((int)__s_00 + iVar1 * 4) == 0)) {
          *(undefined4 *)((int)pvVar9 + iVar1 * 4) = 1;
          *piVar12 = 1;
          *(undefined4 *)((int)__s_00 + iVar1 * 4) = 1;
        }
        iVar1 = iVar1 + 1;
      } while (iVar15 != iVar1);
      pvVar9 = (void *)((int)pvVar9 + __n);
      piVar12 = piVar12 + 1;
      piVar13 = piVar13 + iVar16;
    } while (piVar11 + iVar16 != piVar12);
  }
  memset(piVar11,0,__n);
  memset(__s_00,0,__n);
  piVar13 = *(int **)(param_1 + 0x10);
  iVar15 = *(int *)(param_1 + 0x18);
  if (iVar16 < 1) {
    return;
  }
  iVar1 = 0;
LAB_0002255a:
  iVar5 = 0;
  iVar2 = 0;
  piVar11 = (int *)(iVar15 + -4);
  piVar12 = piVar13;
  piVar10 = piVar11;
  do {
    do {
      piVar11 = piVar11 + 1;
      if ((*piVar11 == 1) && (*piVar12 == 0)) {
        *piVar12 = 1;
        iVar5 = iVar5 + 1;
      }
      piVar12 = piVar12 + 1;
    } while (piVar13 + iVar16 != piVar12);
    piVar11 = piVar10 + iVar16;
    iVar2 = iVar2 + 1;
    piVar12 = piVar13;
    piVar10 = piVar11;
  } while (iVar16 != iVar2);
  if (iVar5 < iVar16) {
    local_60 = iVar1 + 1;
    if (local_60 != 10000) {
      iVar1 = *(int *)param_1;
      iVar5 = *(int *)(param_1 + 0x18);
      piVar12 = *(int **)(param_1 + 8);
      piVar11 = *(int **)(param_1 + 0x10);
      do {
        iVar2 = 0;
        local_6c = 0;
        while( true ) {
          iVar7 = local_6c * iVar16;
          iVar17 = local_6c;
          iVar8 = iVar2;
          while (((*(int *)(iVar1 + (iVar7 + iVar8) * 4) != 0 || (piVar12[iVar17] != 0)) ||
                 (piVar11[iVar8] != 0))) {
            __aeabi_idivmod(iVar8 + 1,iVar16);
            iVar8 = extraout_r1;
            if (extraout_r1 == iVar2) {
              __aeabi_idivmod(iVar17 + 1,iVar16);
              if (extraout_r1_00 == local_6c) goto LAB_00022686;
              iVar7 = extraout_r1_00 * iVar16;
              iVar17 = extraout_r1_00;
            }
          }
          if (iVar17 < 0) break;
          piVar10 = (int *)(iVar5 + iVar7 * 4);
          piVar10[iVar8] = 2;
          if (iVar16 < 1) {
LAB_0002279e:
            *(int *)(param_1 + 0x28) = iVar17;
            *(int *)(param_1 + 0x2c) = iVar8;
            if (local_60 == 9999) goto LAB_000228a8;
            iVar2 = 0;
            piVar14 = *(int **)(param_1 + 0x20);
            *piVar14 = iVar17;
            iVar1 = *(int *)(param_1 + 0x2c);
            piVar14[1] = iVar1;
            piVar10 = piVar14;
            goto joined_r0x000227d2;
          }
          if (*(int *)(iVar5 + iVar7 * 4) == 1) {
            iVar2 = 0;
            piVar10 = piVar11;
          }
          else {
            iVar2 = 0;
            do {
              iVar2 = iVar2 + 1;
              if (iVar16 == iVar2) goto LAB_0002279e;
              piVar10 = piVar10 + 1;
            } while (*piVar10 != 1);
            piVar10 = piVar11 + iVar2;
          }
          piVar12[iVar17] = 1;
          *piVar10 = 0;
          local_6c = iVar17;
        }
LAB_00022686:
        if (local_60 == 9999) break;
        if (0 < iVar16) {
          iVar17 = 0x7fffffff;
          piVar11 = piVar12;
          iVar2 = iVar1;
          do {
            piVar10 = piVar11 + 1;
            iVar8 = 0;
            do {
              if (((*piVar11 == 0) && (piVar13[iVar8] == 0)) &&
                 (iVar7 = *(int *)(iVar2 + iVar8 * 4), iVar7 <= iVar17)) {
                iVar17 = iVar7;
              }
              iVar8 = iVar8 + 1;
            } while (iVar16 != iVar8);
            iVar2 = iVar2 + __n;
            piVar11 = piVar10;
          } while (piVar12 + iVar16 != piVar10);
          iVar2 = 0;
          iVar7 = 0;
          piVar10 = (int *)(iVar1 + __n);
          piVar11 = piVar12;
          do {
            piVar14 = piVar13;
            piVar6 = piVar10 + -iVar16;
            do {
              iVar3 = iVar2;
              if (*piVar11 == 1) {
                iVar3 = iVar2 + 1;
                *piVar6 = *piVar6 + iVar17;
              }
              iVar2 = iVar3;
              if (*piVar14 == 0) {
                iVar2 = iVar3 + 1;
                *piVar6 = *piVar6 - iVar17;
                if ((*piVar11 == 1) && (*piVar14 == 0)) {
                  iVar2 = iVar3 + -1;
                }
              }
              piVar6 = piVar6 + 1;
              piVar14 = piVar14 + 1;
            } while (piVar10 != piVar6);
            if (iVar2 == 0) {
              __android_log_print(6,"CAMPAN_ATTR","matrix cannnot solve\n");
                    /* WARNING: Subroutine does not return */
              __assert_fail("0",
                            "/home/mayutao/envs/virgo_smartdevice-linux-v3.0-pre-rel/frameworks/axnn_plugins/src/campan/campan_attr.cpp"
                            ,0x4c0,"int hungarian_step6(hungarian_t*, int)");
            }
            piVar10 = piVar10 + -iVar16 + iVar16 * 2;
            iVar7 = iVar7 + 1;
            piVar11 = piVar11 + 1;
          } while (iVar8 != iVar7);
        }
        local_60 = local_60 + 2;
        piVar11 = piVar13;
      } while (local_60 != 10000);
    }
  }
  else if (1 < iVar1 - 0x270eU) {
    if (iVar16 < 1) {
      return;
    }
    iVar15 = 0;
    piVar13 = (int *)((int)__s + -4);
    iVar1 = param_5 + param_4 * 4;
    do {
      piVar11 = piVar13;
      iVar5 = 0;
      do {
        while (piVar11 = piVar11 + 1, *piVar11 != 1) {
LAB_00022646:
          iVar5 = iVar5 + 1;
          if (iVar16 == iVar5) goto LAB_00022678;
        }
        if (param_4 <= iVar15) {
          *(undefined4 *)(iVar1 + iVar5 * 4) = 0xffffffff;
          goto LAB_00022646;
        }
        if (iVar5 < param_3) {
          *(int *)(param_5 + iVar15 * 4) = iVar5;
          *(int *)(iVar1 + iVar5 * 4) = iVar15;
        }
        iVar2 = iVar5 + 1;
        if (param_3 <= iVar5) {
          *(undefined4 *)(param_5 + iVar15 * 4) = 0xffffffff;
        }
        iVar5 = iVar2;
      } while (iVar16 != iVar2);
LAB_00022678:
      piVar13 = piVar13 + iVar16;
      iVar15 = iVar15 + 1;
      if (iVar16 == iVar15) {
        return;
      }
    } while( true );
  }
  goto LAB_000228a8;
joined_r0x000227d2:
  if (iVar16 < 1) goto LAB_00022830;
  piVar6 = (int *)(iVar5 + iVar1 * 4);
  iVar8 = 0;
  iVar17 = -1;
  do {
    iVar1 = *piVar6;
    piVar6 = piVar6 + iVar16;
    if (iVar1 == 1) {
      iVar17 = iVar8;
    }
    iVar8 = iVar8 + 1;
  } while (iVar16 != iVar8);
  if (iVar17 == -1) goto LAB_00022830;
  piVar10[2] = iVar17;
  piVar10[3] = piVar10[1];
  iVar1 = 0;
  piVar6 = (int *)(iVar5 + iVar17 * iVar16 * 4);
  iVar7 = *(int *)(iVar5 + iVar17 * iVar16 * 4);
  while (iVar7 != 2) {
    iVar1 = iVar1 + 1;
    if (iVar8 == iVar1) {
      iVar1 = -1;
      break;
    }
    piVar6 = piVar6 + 1;
    iVar7 = *piVar6;
  }
  piVar10[4] = iVar17;
  piVar10[5] = iVar1;
  iVar2 = iVar2 + 2;
  piVar10 = piVar10 + 4;
  goto joined_r0x000227d2;
LAB_00022830:
  piVar10 = piVar14 + iVar2 * 2 + 2;
  do {
    iVar1 = *piVar14;
    piVar6 = piVar14 + 1;
    piVar14 = piVar14 + 2;
    iVar1 = iVar1 * iVar16 + *piVar6;
    *(uint *)(iVar5 + iVar1 * 4) = (uint)(*(int *)(iVar5 + iVar1 * 4) != 1);
  } while (piVar10 != piVar14);
  iVar1 = local_60 + 2;
  if (iVar16 < 1) {
    if ((iVar1 != 10000) && (1 < local_60 - 0x270cU)) {
      return;
    }
    goto LAB_000228a8;
  }
  piVar11 = piVar11 + -1;
  piVar10 = piVar12;
  do {
    piVar14 = piVar10 + 1;
    *piVar10 = 0;
    piVar11 = piVar11 + 1;
    *piVar11 = 0;
    piVar10 = piVar14;
  } while (piVar12 + iVar16 != piVar14);
  piVar11 = (int *)(iVar5 + -4);
  iVar5 = 0;
  do {
    piVar12 = piVar11 + iVar16;
    do {
      piVar11 = piVar11 + 1;
      if (*piVar11 == 2) {
        *piVar11 = 0;
      }
    } while (piVar12 != piVar11);
    iVar5 = iVar5 + 1;
  } while (iVar16 != iVar5);
  if (iVar1 == 10000) {
LAB_000228a8:
                    /* WARNING: Subroutine does not return */
    __assert_fail("loop < 10000",
                  "/home/mayutao/envs/virgo_smartdevice-linux-v3.0-pre-rel/frameworks/axnn_plugins/src/campan/campan_attr.cpp"
                  ,0x53b,"void linear_assignment(hungarian_t*, int*, ax_size_t, int*)");
  }
  goto LAB_0002255a;
}



/* void AX_MALLOC_INC_TEMP<box_intersect_array_t>(box_intersect_array_t&, int) */

void AX_MALLOC_INC_TEMP<box_intersect_array_t>(box_intersect_array_t *param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = *(void **)param_1;
  *(int *)(param_1 + 4) = param_2;
  iVar2 = param_2 * 0x14;
  if (pvVar1 == (void *)0x0) {
    if (iVar2 < 1) {
      return;
    }
  }
  else {
    if (*(int *)((int)pvVar1 + -4) + param_2 * -0x14 < 0 ==
        SBORROW4(*(int *)((int)pvVar1 + -4),iVar2)) {
      return;
    }
    AX_FREE_RECORD(pvVar1);
    *(undefined4 *)param_1 = 0;
  }
  iVar2 = AX_MALLOC_RECORD(iVar2);
  *(int *)param_1 = iVar2;
  if (iVar2 != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}



/* void box_overlap_intersect<ax_box_t>(ax_box_t, ax_box_t, box_intersect_t*) */

void box_overlap_intersect<ax_box_t>
               (int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
               int param_8,float *param_9)

{
  byte bVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  float fVar12;
  float fVar13;
  
  iVar8 = param_1;
  if (param_1 <= param_5) {
    iVar8 = param_5;
  }
  iVar9 = param_2;
  if (param_2 <= param_6) {
    iVar9 = param_6;
  }
  iVar10 = param_3;
  if (param_7 <= param_3) {
    iVar10 = param_7;
  }
  iVar5 = param_4;
  if (param_8 <= param_4) {
    iVar5 = param_8;
  }
  uVar11 = (uint)(((float)(longlong)iVar10 - (float)(longlong)iVar8) + 1.0);
  uVar6 = (uint)(((float)(longlong)iVar5 - (float)(longlong)iVar9) + 1.0);
  fVar4 = (float)(longlong)(((param_8 - param_6) + 1) * ((param_7 - param_5) + 1));
  if ((int)(uVar11 | uVar6) < 0) {
    fVar7 = 0.0;
  }
  else {
    fVar7 = (float)(longlong)(int)uVar11 * (float)(longlong)(int)uVar6;
  }
  fVar12 = (float)(longlong)(((param_4 - param_2) + 1) * ((param_3 - param_1) + 1));
  bVar1 = (byte)(((uint)(fVar12 == fVar4) << 0x1e) >> 0x18);
  cVar2 = -((char)((byte)(((uint)(fVar12 < fVar4) << 0x1f) >> 0x18) | bVar1) >> 7);
  fVar3 = fVar4;
  if (cVar2 != '\0') {
    fVar3 = fVar12;
  }
  fVar13 = fVar12;
  if ((bool)(bVar1 >> 6) || (bool)cVar2 != (NAN(fVar12) || NAN(fVar4))) {
    fVar13 = fVar4;
  }
  param_9[3] = fVar7 / fVar12;
  param_9[1] = fVar7 / fVar3;
  param_9[2] = fVar7 / fVar13;
  param_9[4] = fVar7 / fVar4;
  *param_9 = fVar7 / ((fVar12 + fVar4) - fVar7);
  return;
}



/* void box_overlap<ax_box_t>(ax_box_t, ax_box_t, float*, float*) */

void box_overlap<ax_box_t>
               (int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
               int param_8,float *param_9,float *param_10)

{
  float in_s11;
  int iVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  float fVar9;
  
  iVar5 = param_1;
  if (param_1 <= param_5) {
    iVar5 = param_5;
  }
  iVar6 = param_2;
  if (param_2 <= param_6) {
    iVar6 = param_6;
  }
  iVar7 = param_3;
  if (param_7 <= param_3) {
    iVar7 = param_7;
  }
  iVar1 = param_4;
  if (param_8 <= param_4) {
    iVar1 = param_8;
  }
  uVar8 = (uint)(((float)(longlong)iVar7 - (float)(longlong)iVar5) + 1.0);
  uVar2 = (uint)(((float)(longlong)iVar1 - (float)(longlong)iVar6) + 1.0);
  if ((int)(uVar8 | uVar2) < 0) {
    fVar3 = 0.0;
  }
  else {
    fVar3 = (float)(longlong)(int)uVar8 * (float)(longlong)(int)uVar2;
  }
  fVar4 = (float)(longlong)(((param_4 - param_2) + 1) * ((param_3 - param_1) + 1));
  fVar9 = (float)(longlong)(((param_8 - param_6) + 1) * ((param_7 - param_5) + 1));
  iVar5 = (uint)(fVar4 < fVar9) << 0x1f;
  if (-1 < iVar5) {
    in_s11 = fVar9;
  }
  if (iVar5 < 0) {
    in_s11 = fVar4;
  }
  if (fVar4 != fVar9 && fVar4 < fVar9 == (NAN(fVar4) || NAN(fVar9))) {
    fVar9 = fVar4;
  }
  *param_9 = fVar3 / in_s11;
  *param_10 = fVar3 / fVar9;
  return;
}



/* campan_reid_process_single(campan_reid_t*, nn_campan_person_t*, ax_yuv_t*) */

void campan_reid_process_single
               (campan_reid_t *param_1,nn_campan_person_t *param_2,ax_yuv_t *param_3)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  int iVar6;
  ax_tensor_t *this;
  ax_tensor_t *paVar7;
  undefined4 *puVar8;
  ax_tensor_t *paVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  void *pvVar14;
  void *pvVar15;
  uint uVar16;
  uint uVar17;
  undefined8 uVar18;
  void *local_c4;
  undefined4 uStack_c0;
  undefined4 local_bc;
  uint local_b8;
  uint local_b4;
  int local_b0;
  int local_ac;
  void *local_a8;
  void *local_a4;
  undefined4 local_a0;
  undefined4 *local_9c;
  undefined4 *local_98;
  undefined4 uStack_94;
  ax_tensor_t aaStack_90 [16];
  void *local_80;
  void *local_60;
  undefined4 local_5c;
  undefined4 local_58;
  void *local_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  local_48 = *(undefined4 *)param_3;
  uStack_44 = *(undefined4 *)(param_3 + 4);
  uStack_40 = *(undefined4 *)(param_3 + 8);
  uStack_3c = *(undefined4 *)(param_3 + 0xc);
  local_b8 = *(uint *)(param_2 + 0x14);
  uVar16 = *(int *)(param_3 + 0x18) - 1;
  local_38 = *(undefined4 *)(param_3 + 0x10);
  uStack_34 = *(undefined4 *)(param_3 + 0x14);
  uStack_30 = *(undefined4 *)(param_3 + 0x18);
  uStack_2c = *(undefined4 *)(param_3 + 0x1c);
  iVar6 = (*(int *)(param_2 + 0x1c) - local_b8) + 1;
  local_28 = *(undefined4 *)(param_3 + 0x20);
  uVar11 = *(uint *)(param_2 + 0x18);
  local_60 = (void *)0x0;
  local_5c = 0;
  local_58 = 0;
  local_54 = (void *)0x0;
  local_50 = 0;
  uStack_4c = 0;
  local_24 = 0;
  local_c4 = (void *)0x0;
  uStack_c0 = 0;
  local_bc = 0;
  iVar2 = (iVar6 * 3) / 2;
  iVar3 = (*(int *)(param_2 + 0x20) - uVar11) + 1;
  uVar4 = (local_b8 + iVar6) - 1;
  local_b8 = local_b8 & ~((int)local_b8 >> 0x1f);
  if (iVar2 < iVar3) {
    iVar3 = iVar2;
  }
  uVar17 = *(int *)(param_3 + 0x1c) - 1;
  local_b4 = uVar11 & ~((int)uVar11 >> 0x1f);
  uVar11 = (uVar11 + iVar3) - 1;
  uVar4 = uVar4 & ~((int)uVar4 >> 0x1f);
  if ((int)uVar16 <= (int)local_b8) {
    local_b8 = uVar16;
  }
  if ((int)uVar17 <= (int)local_b4) {
    local_b4 = uVar17;
  }
  uVar11 = uVar11 & ~((int)uVar11 >> 0x1f);
  if ((int)uVar16 < (int)uVar4) {
    local_b0 = uVar16 - local_b8;
  }
  else {
    local_b0 = uVar4 - local_b8;
  }
  if ((int)uVar17 < (int)uVar11) {
    local_ac = uVar17 - local_b4;
  }
  else {
    local_ac = uVar11 - local_b4;
  }
  local_b0 = local_b0 + 1;
  local_ac = local_ac + 1;
  std::vector<ax_rect_t,std::allocator<ax_rect_t>>::_M_realloc_insert<ax_rect_t_const&>
            ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&local_c4,0,&local_b8);
  std::vector<ax_rect_t,std::allocator<ax_rect_t>>::operator=
            ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&local_60,(vector *)&local_c4);
  local_a8 = (void *)0x0;
  local_a4 = (void *)0x0;
  local_a0 = 0;
  local_9c = (undefined4 *)0x0;
  local_98 = (undefined4 *)0x0;
  uStack_94 = 0;
  batch_classify_process
            (*(batch_classify_model_t **)param_1,(classify_in_t *)&local_60,
             (classify_out_t *)&local_a8,1);
  if (local_98 != local_9c) {
    if ((ax_tensor_t *)local_9c[1] != (ax_tensor_t *)*local_9c) {
      ax_tensor_t::ax_tensor_t(aaStack_90,(ax_tensor_t *)*local_9c);
      memcpy(param_2 + 0x30,local_80,*(size_t *)(param_1 + 4));
      *(undefined4 *)(param_2 + 0x130) = *(undefined4 *)(param_1 + 4);
      uVar18 = ax_tensor_t::norm();
      *(undefined4 *)(param_2 + 0x140) = 1;
      *(undefined8 *)(param_2 + 0x138) = uVar18;
      ax_tensor_t::~ax_tensor_t(aaStack_90);
      puVar8 = local_98;
      puVar10 = local_98;
      if (local_9c != local_98) {
        puVar12 = local_9c + 3;
        puVar10 = local_9c;
        puVar13 = puVar12;
        while( true ) {
          paVar9 = (ax_tensor_t *)puVar10[1];
          this = (ax_tensor_t *)puVar12[-3];
          if ((ax_tensor_t *)puVar12[-3] != paVar9) {
            do {
              paVar7 = this + 0x30;
              ax_tensor_t::~ax_tensor_t(this);
              this = paVar7;
            } while (paVar9 != paVar7);
            paVar9 = (ax_tensor_t *)puVar12[-3];
          }
          if (paVar9 != (ax_tensor_t *)0x0) {
            operator_delete(paVar9);
          }
          puVar12 = puVar12 + 3;
          puVar10 = local_9c;
          if (puVar8 == puVar13) break;
          puVar10 = puVar13;
          puVar13 = puVar13 + 3;
        }
      }
      if (puVar10 != (undefined4 *)0x0) {
        operator_delete(puVar10);
      }
      pvVar1 = local_a4;
      pvVar5 = local_a4;
      if (local_a8 != local_a4) {
        pvVar14 = (void *)((int)local_a8 + 0xc);
        pvVar5 = local_a8;
        pvVar15 = pvVar14;
        while( true ) {
          puVar10 = *(undefined4 **)((int)pvVar5 + 4);
          puVar8 = *(undefined4 **)((int)pvVar14 + -0xc);
          if (puVar8 != puVar10) {
            do {
              if ((void *)*puVar8 != (void *)0x0) {
                operator_delete((void *)*puVar8);
              }
              puVar8 = puVar8 + 3;
            } while (puVar10 != puVar8);
            puVar10 = *(undefined4 **)((int)pvVar14 + -0xc);
          }
          if (puVar10 != (undefined4 *)0x0) {
            operator_delete(puVar10);
          }
          pvVar14 = (void *)((int)pvVar14 + 0xc);
          pvVar5 = local_a8;
          if (pvVar1 == pvVar15) break;
          pvVar5 = pvVar15;
          pvVar15 = (void *)((int)pvVar15 + 0xc);
        }
      }
      if (pvVar5 != (void *)0x0) {
        operator_delete(pvVar5);
      }
      if (local_c4 != (void *)0x0) {
        operator_delete(local_c4);
      }
      if (local_54 != (void *)0x0) {
        operator_delete(local_54);
      }
      if (local_60 != (void *)0x0) {
        operator_delete(local_60);
      }
      return;
    }
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0);
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0,0);
}



/* handpose_process_two_cls(handpose_t*, int*, ax_yuv_t*) */

undefined4 handpose_process_two_cls(handpose_t *param_1,int *param_2,ax_yuv_t *param_3)

{
  undefined4 *puVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  void *pvVar5;
  ax_tensor_t *this;
  ax_tensor_t *paVar6;
  undefined4 *puVar7;
  ax_tensor_t *paVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  void *pvVar12;
  void *pvVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint uVar16;
  double dVar17;
  void *local_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  double *local_94;
  undefined4 local_90;
  undefined4 local_8c;
  uint local_88;
  uint uStack_84;
  int local_80;
  int local_7c;
  undefined4 *local_78;
  undefined4 *local_74;
  undefined4 local_70;
  void *local_6c;
  void *local_68;
  undefined4 uStack_64;
  void *local_60;
  undefined4 local_5c;
  undefined4 local_58;
  void *local_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  local_48 = *(undefined4 *)param_3;
  uStack_44 = *(undefined4 *)(param_3 + 4);
  uStack_40 = *(undefined4 *)(param_3 + 8);
  uStack_3c = *(undefined4 *)(param_3 + 0xc);
  uVar15 = *(int *)(param_3 + 0x1c) - 1;
  uVar16 = *(int *)(param_3 + 0x18) - 1;
  local_38 = *(undefined4 *)(param_3 + 0x10);
  uStack_34 = *(undefined4 *)(param_3 + 0x14);
  uStack_30 = *(undefined4 *)(param_3 + 0x18);
  uStack_2c = *(undefined4 *)(param_3 + 0x1c);
  local_28 = *(undefined4 *)(param_3 + 0x20);
  local_88 = *param_2 & ~(*param_2 >> 0x1f);
  uStack_84 = param_2[1] & ~(param_2[1] >> 0x1f);
  if ((int)uVar16 <= (int)local_88) {
    local_88 = uVar16;
  }
  local_60 = (void *)0x0;
  local_5c = 0;
  local_58 = 0;
  local_54 = (void *)0x0;
  local_50 = 0;
  uStack_4c = 0;
  local_24 = 0;
  local_a0 = (void *)0x0;
  uStack_9c = 0;
  local_98 = 0;
  uVar3 = param_2[2] & ~(param_2[2] >> 0x1f);
  if ((int)uVar15 <= (int)uStack_84) {
    uStack_84 = uVar15;
  }
  uVar4 = param_2[3] & ~(param_2[3] >> 0x1f);
  if ((int)uVar16 < (int)uVar3) {
    local_80 = uVar16 - local_88;
  }
  else {
    local_80 = uVar3 - local_88;
  }
  if ((int)uVar15 < (int)uVar4) {
    local_7c = uVar15 - uStack_84;
  }
  else {
    local_7c = uVar4 - uStack_84;
  }
  local_80 = local_80 + 1;
  local_7c = local_7c + 1;
  std::vector<ax_rect_t,std::allocator<ax_rect_t>>::_M_realloc_insert<ax_rect_t_const&>
            ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&local_a0,0,&local_88);
  std::vector<ax_rect_t,std::allocator<ax_rect_t>>::operator=
            ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&local_60,(vector *)&local_a0);
  local_78 = (undefined4 *)0x0;
  local_74 = (undefined4 *)0x0;
  local_70 = 0;
  local_6c = (void *)0x0;
  local_68 = (void *)0x0;
  uStack_64 = 0;
  batch_classify_process
            (*(batch_classify_model_t **)(param_1 + 8),(classify_in_t *)&local_60,
             (classify_out_t *)&local_78,0);
  if (local_74 != local_78) {
    if ((vector *)local_78[1] != (vector *)*local_78) {
      local_94 = (double *)0x0;
      local_90 = 0;
      local_8c = 0;
      softmax((vector *)*local_78,(vector *)&local_94,2);
      dVar17 = local_94[1];
      if ((int)((uint)(*local_94 < dVar17) << 0x1f) < 0) {
        if (dVar17 == 0.800000011920929 || dVar17 < 0.800000011920929 != NAN(dVar17)) {
          uVar10 = 0;
        }
        else {
          uVar10 = 9;
        }
      }
      else {
        uVar10 = 0;
      }
      operator_delete(local_94);
      pvVar2 = local_68;
      pvVar5 = local_68;
      if (local_6c != local_68) {
        pvVar12 = (void *)((int)local_6c + 0xc);
        pvVar5 = local_6c;
        pvVar13 = pvVar12;
        while( true ) {
          paVar8 = *(ax_tensor_t **)((int)pvVar5 + 4);
          this = *(ax_tensor_t **)((int)pvVar12 + -0xc);
          if (*(ax_tensor_t **)((int)pvVar12 + -0xc) != paVar8) {
            do {
              paVar6 = this + 0x30;
              ax_tensor_t::~ax_tensor_t(this);
              this = paVar6;
            } while (paVar8 != paVar6);
            paVar8 = *(ax_tensor_t **)((int)pvVar12 + -0xc);
          }
          if (paVar8 != (ax_tensor_t *)0x0) {
            operator_delete(paVar8);
          }
          pvVar12 = (void *)((int)pvVar12 + 0xc);
          pvVar5 = local_6c;
          if (pvVar2 == pvVar13) break;
          pvVar5 = pvVar13;
          pvVar13 = (void *)((int)pvVar13 + 0xc);
        }
      }
      if (pvVar5 != (void *)0x0) {
        operator_delete(pvVar5);
      }
      puVar1 = local_74;
      puVar7 = local_74;
      if (local_78 != local_74) {
        puVar11 = local_78 + 3;
        puVar7 = local_78;
        puVar14 = puVar11;
        while( true ) {
          puVar9 = (undefined4 *)puVar7[1];
          puVar7 = (undefined4 *)puVar11[-3];
          if (puVar7 != puVar9) {
            do {
              if ((void *)*puVar7 != (void *)0x0) {
                operator_delete((void *)*puVar7);
              }
              puVar7 = puVar7 + 3;
            } while (puVar9 != puVar7);
            puVar9 = (undefined4 *)puVar11[-3];
          }
          if (puVar9 != (undefined4 *)0x0) {
            operator_delete(puVar9);
          }
          puVar11 = puVar11 + 3;
          puVar7 = local_78;
          if (puVar1 == puVar14) break;
          puVar7 = puVar14;
          puVar14 = puVar14 + 3;
        }
      }
      if (puVar7 != (undefined4 *)0x0) {
        operator_delete(puVar7);
      }
      if (local_a0 != (void *)0x0) {
        operator_delete(local_a0);
      }
      if (local_54 != (void *)0x0) {
        operator_delete(local_54);
      }
      if (local_60 != (void *)0x0) {
        operator_delete(local_60);
      }
      return uVar10;
    }
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0);
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0,0);
}



/* handpose_process_old(handpose_t*, int*, ax_yuv_t*) */

uint handpose_process_old(handpose_t *param_1,int *param_2,ax_yuv_t *param_3)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  float *pfVar6;
  void *pvVar7;
  int *piVar8;
  ax_tensor_t *this;
  ax_tensor_t *paVar9;
  undefined4 *puVar10;
  ax_tensor_t *paVar11;
  undefined4 *puVar12;
  float *pfVar13;
  int *piVar14;
  void *pvVar15;
  void *pvVar16;
  int *piVar17;
  uint uVar18;
  uint uVar19;
  float fVar20;
  float fVar21;
  void *local_dc;
  undefined4 uStack_d8;
  undefined4 local_d4;
  uint local_d0;
  uint uStack_cc;
  int local_c8;
  int local_c4;
  int *local_c0;
  int *local_bc;
  undefined4 local_b8;
  void *local_b4;
  void *local_b0;
  undefined4 uStack_ac;
  void *local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  void *local_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  
  local_90 = *(undefined4 *)param_3;
  uStack_8c = *(undefined4 *)(param_3 + 4);
  uStack_88 = *(undefined4 *)(param_3 + 8);
  uStack_84 = *(undefined4 *)(param_3 + 0xc);
  uVar18 = *(int *)(param_3 + 0x1c) - 1;
  uVar19 = *(int *)(param_3 + 0x18) - 1;
  local_80 = *(undefined4 *)(param_3 + 0x10);
  uStack_7c = *(undefined4 *)(param_3 + 0x14);
  uStack_78 = *(undefined4 *)(param_3 + 0x18);
  uStack_74 = *(undefined4 *)(param_3 + 0x1c);
  local_70 = *(undefined4 *)(param_3 + 0x20);
  local_d0 = *param_2 & ~(*param_2 >> 0x1f);
  uStack_cc = param_2[1] & ~(param_2[1] >> 0x1f);
  local_a8 = (void *)0x0;
  if ((int)uVar19 <= (int)local_d0) {
    local_d0 = uVar19;
  }
  local_a4 = 0;
  local_a0 = 0;
  local_9c = (void *)0x0;
  local_98 = 0;
  uStack_94 = 0;
  local_6c = 0;
  local_dc = (void *)0x0;
  uStack_d8 = 0;
  local_d4 = 0;
  uVar3 = param_2[2] & ~(param_2[2] >> 0x1f);
  if ((int)uVar18 <= (int)uStack_cc) {
    uStack_cc = uVar18;
  }
  uVar4 = param_2[3] & ~(param_2[3] >> 0x1f);
  if ((int)uVar19 < (int)uVar3) {
    local_c8 = uVar19 - local_d0;
  }
  else {
    local_c8 = uVar3 - local_d0;
  }
  if ((int)uVar18 < (int)uVar4) {
    local_c4 = uVar18 - uStack_cc;
  }
  else {
    local_c4 = uVar4 - uStack_cc;
  }
  local_c8 = local_c8 + 1;
  local_c4 = local_c4 + 1;
  std::vector<ax_rect_t,std::allocator<ax_rect_t>>::_M_realloc_insert<ax_rect_t_const&>
            ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&local_dc,0,&local_d0);
  std::vector<ax_rect_t,std::allocator<ax_rect_t>>::operator=
            ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&local_a8,(vector *)&local_dc);
  local_c0 = (int *)0x0;
  local_bc = (int *)0x0;
  local_b8 = 0;
  local_b4 = (void *)0x0;
  local_b0 = (void *)0x0;
  uStack_ac = 0;
  batch_classify_process
            (*(batch_classify_model_t **)(param_1 + 4),(classify_in_t *)&local_a8,
             (classify_out_t *)&local_c0,0);
  if (local_bc != local_c0) {
    piVar5 = (int *)*local_c0;
    if ((int *)local_c0[1] == piVar5) {
                    /* WARNING: Subroutine does not return */
      std::__throw_out_of_range_fmt
                ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0);
    }
    pfVar13 = (float *)*piVar5;
    uVar19 = 1;
    uVar18 = 0;
    uVar3 = piVar5[1] - (int)pfVar13 >> 2;
    pfVar6 = pfVar13;
    while( true ) {
      pfVar6 = pfVar6 + 1;
      if (uVar3 <= uVar19) {
                    /* WARNING: Subroutine does not return */
        std::__throw_out_of_range_fmt
                  ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)");
      }
      fVar20 = *pfVar6;
      if (uVar3 <= uVar18) break;
      fVar21 = pfVar13[uVar18];
      if (fVar20 != fVar21 && fVar20 < fVar21 == (NAN(fVar20) || NAN(fVar21))) {
        uVar18 = uVar19;
      }
      uVar19 = uVar19 + 1;
      if (uVar19 == 9) {
        if (uVar18 < uVar3) {
          fVar20 = expf(-pfVar13[uVar18]);
          pvVar2 = local_b0;
          local_60 = 0xc0000000;
          uStack_5c = 0x3fec28f5;
          local_68 = 0x60000000;
          uStack_64 = 0x3fe66666;
          local_58 = 0xc0000000;
          uStack_54 = 0x3feccccc;
          local_48 = 0xc0000000;
          uStack_44 = 0x3feccccc;
          local_40 = 0xc0000000;
          uStack_3c = 0x3feccccc;
          local_30 = 0xc0000000;
          uStack_2c = 0x3feccccc;
          local_28 = 0xc0000000;
          uStack_24 = 0x3feccccc;
          local_50 = 0xa0000000;
          uStack_4c = 0x3fe99999;
          local_38 = 0xa0000000;
          uStack_34 = 0x3fea3d70;
          iVar1 = (uint)(*(double *)(&local_68 + uVar18 * 2) < (double)(1.0 / (fVar20 + 1.0))) <<
                  0x1f;
          if (-1 < iVar1) {
            uVar18 = 0;
          }
          if ((iVar1 < 0) && (3 < uVar18 - 3)) {
            uVar18 = 0;
          }
          pvVar7 = local_b0;
          if (local_b4 != local_b0) {
            pvVar15 = (void *)((int)local_b4 + 0xc);
            pvVar7 = local_b4;
            pvVar16 = pvVar15;
            while( true ) {
              paVar11 = *(ax_tensor_t **)((int)pvVar7 + 4);
              this = *(ax_tensor_t **)((int)pvVar15 + -0xc);
              if (*(ax_tensor_t **)((int)pvVar15 + -0xc) != paVar11) {
                do {
                  paVar9 = this + 0x30;
                  ax_tensor_t::~ax_tensor_t(this);
                  this = paVar9;
                } while (paVar11 != paVar9);
                paVar11 = *(ax_tensor_t **)((int)pvVar15 + -0xc);
              }
              if (paVar11 != (ax_tensor_t *)0x0) {
                operator_delete(paVar11);
              }
              pvVar15 = (void *)((int)pvVar15 + 0xc);
              pvVar7 = local_b4;
              if (pvVar2 == pvVar16) break;
              pvVar7 = pvVar16;
              pvVar16 = (void *)((int)pvVar16 + 0xc);
            }
          }
          if (pvVar7 != (void *)0x0) {
            operator_delete(pvVar7);
          }
          piVar5 = local_bc;
          piVar8 = local_bc;
          if (local_c0 != local_bc) {
            piVar14 = local_c0 + 3;
            piVar8 = local_c0;
            piVar17 = piVar14;
            while( true ) {
              puVar12 = (undefined4 *)piVar8[1];
              puVar10 = (undefined4 *)piVar14[-3];
              if (puVar10 != puVar12) {
                do {
                  if ((void *)*puVar10 != (void *)0x0) {
                    operator_delete((void *)*puVar10);
                  }
                  puVar10 = puVar10 + 3;
                } while (puVar12 != puVar10);
                puVar12 = (undefined4 *)piVar14[-3];
              }
              if (puVar12 != (undefined4 *)0x0) {
                operator_delete(puVar12);
              }
              piVar14 = piVar14 + 3;
              piVar8 = local_c0;
              if (piVar5 == piVar17) break;
              piVar8 = piVar17;
              piVar17 = piVar17 + 3;
            }
          }
          if (piVar8 != (int *)0x0) {
            operator_delete(piVar8);
          }
          if (local_dc != (void *)0x0) {
            operator_delete(local_dc);
          }
          if (local_9c != (void *)0x0) {
            operator_delete(local_9c);
          }
          if (local_a8 != (void *)0x0) {
            operator_delete(local_a8);
          }
          return uVar18;
        }
                    /* WARNING: Subroutine does not return */
        std::__throw_out_of_range_fmt
                  ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                   uVar18);
      }
    }
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",uVar18);
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0,0);
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* handpose_process(handpose_t*, nn_campan_hands_t*, ax_yuv_t*) */

void handpose_process(handpose_t *param_1,nn_campan_hands_t *param_2,ax_yuv_t *param_3)

{
  void *pvVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  float *pfVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  undefined1 *puVar10;
  void *pvVar11;
  int *piVar12;
  ax_tensor_t *this;
  ax_tensor_t *paVar13;
  undefined4 *puVar14;
  ax_tensor_t *paVar15;
  undefined4 *puVar16;
  int iVar17;
  int *piVar18;
  void *pvVar19;
  void *pvVar20;
  int *piVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  float fVar26;
  float fVar27;
  vector *local_10c;
  void *local_fc;
  uint *local_f8;
  uint *local_f4;
  int *local_f0;
  int *local_ec;
  undefined4 local_e8;
  void *local_e4;
  void *local_e0;
  undefined4 uStack_dc;
  void *local_d8;
  undefined4 local_d4;
  undefined4 uStack_d0;
  void *local_cc;
  undefined4 uStack_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  vector *pvStack_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined8 local_60;
  undefined8 local_58;
  undefined1 auStack_50 [4];
  
  local_c0 = *(undefined4 *)param_3;
  uStack_bc = *(undefined4 *)(param_3 + 4);
  uStack_b8 = *(undefined4 *)(param_3 + 8);
  uStack_b4 = *(undefined4 *)(param_3 + 0xc);
  iVar25 = *(int *)(param_2 + 4);
  local_b0 = *(undefined4 *)(param_3 + 0x10);
  uStack_ac = *(undefined4 *)(param_3 + 0x14);
  uStack_a8 = *(undefined4 *)(param_3 + 0x18);
  pvStack_a4 = *(vector **)(param_3 + 0x1c);
  local_a0 = *(undefined4 *)(param_3 + 0x20);
  iVar17 = 0;
  local_10c = pvStack_a4;
  if (iVar25 < 1) {
    local_10c = (vector *)&local_fc;
  }
  local_d8 = (void *)0x0;
  local_d4 = 0;
  uStack_d0 = 0;
  local_cc = (void *)0x0;
  uStack_c8 = 0;
  local_c4 = 0;
  local_9c = 0;
  local_fc = (void *)0x0;
  local_f8 = (uint *)0x0;
  local_f4 = (uint *)0x0;
  if (0 < iVar25) {
    local_10c = (vector *)&local_fc;
    do {
      uVar24 = *(int *)(param_3 + 0x18) - 1;
      iVar22 = iVar17 * 0x2c + *(int *)param_2;
      uVar23 = *(int *)(param_3 + 0x1c) - 1;
      uVar6 = *(uint *)(iVar22 + 8);
      uVar4 = *(uint *)(iVar22 + 4);
      uVar8 = (*(int *)(iVar22 + 0xc) - *(int *)(iVar22 + 4)) + uVar4;
      uVar3 = (*(int *)(iVar22 + 0x10) - *(int *)(iVar22 + 8)) + uVar6;
      uVar6 = uVar6 & ~((int)uVar6 >> 0x1f);
      uVar4 = uVar4 & ~((int)uVar4 >> 0x1f);
      uVar8 = uVar8 & ~((int)uVar8 >> 0x1f);
      if ((int)uVar23 <= (int)uVar6) {
        uVar6 = uVar23;
      }
      uVar3 = uVar3 & ~((int)uVar3 >> 0x1f);
      if ((int)uVar24 <= (int)uVar4) {
        uVar4 = uVar24;
      }
      if ((int)uVar23 < (int)uVar3) {
        iVar22 = uVar23 - uVar6;
      }
      else {
        iVar22 = uVar3 - uVar6;
      }
      if ((int)uVar24 < (int)uVar8) {
        iVar9 = uVar24 - uVar4;
      }
      else {
        iVar9 = uVar8 - uVar4;
      }
      local_98 = CONCAT44(uVar6,uVar4);
      local_90 = CONCAT44(iVar22 + 1U,iVar9 + 1U);
      if (local_f4 == local_f8) {
        std::vector<ax_rect_t,std::allocator<ax_rect_t>>::_M_realloc_insert<ax_rect_t_const&>
                  ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)local_10c,local_f4,&local_98);
        iVar25 = *(int *)(param_2 + 4);
        if (iVar25 <= iVar17 + 1) break;
      }
      else {
        if (local_f8 != (uint *)0x0) {
          *local_f8 = uVar4;
          local_f8[1] = uVar6;
          local_f8[2] = iVar9 + 1U;
          local_f8[3] = iVar22 + 1U;
        }
        local_f8 = local_f8 + 4;
        if (iVar25 <= iVar17 + 1) break;
      }
      iVar17 = iVar17 + 1;
    } while( true );
  }
  std::vector<ax_rect_t,std::allocator<ax_rect_t>>::operator=
            ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&local_d8,local_10c);
  local_f0 = (int *)0x0;
  local_ec = (int *)0x0;
  local_e8 = 0;
  local_e4 = (void *)0x0;
  local_e0 = (void *)0x0;
  uStack_dc = 0;
  get_time_ms();
  batch_classify_process
            (*(batch_classify_model_t **)param_1,(classify_in_t *)&local_d8,
             (classify_out_t *)&local_f0,0);
  get_time_ms();
  if (0 < (int)local_ec - (int)local_f0) {
    piVar7 = (int *)*local_f0;
    iVar17 = *(int *)param_2;
    if (piVar7 != (int *)local_f0[1]) {
      uVar4 = 0;
      uVar2 = local_98;
      do {
        local_98 = uVar2;
        iVar25 = *piVar7;
        uVar8 = 2;
        uVar6 = 1;
        pfVar5 = (float *)(iVar25 + 8);
        uVar3 = piVar7[1] - iVar25 >> 2;
        do {
          if (uVar3 <= uVar8) {
                    /* WARNING: Subroutine does not return */
            std::__throw_out_of_range_fmt
                      ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                       uVar8);
          }
          fVar26 = *pfVar5;
          pfVar5 = pfVar5 + 1;
          if (uVar3 <= uVar6) {
                    /* WARNING: Subroutine does not return */
            std::__throw_out_of_range_fmt
                      ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                       uVar6);
          }
          fVar27 = *(float *)(iVar25 + uVar6 * 4);
          if (fVar26 != fVar27 && fVar26 < fVar27 == (NAN(fVar26) || NAN(fVar27))) {
            uVar6 = uVar8;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 != 9);
        if (uVar3 <= uVar6) {
                    /* WARNING: Subroutine does not return */
          std::__throw_out_of_range_fmt
                    ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                     uVar6);
        }
        uVar4 = uVar4 + 1;
        fVar26 = expf(-*(float *)(iVar25 + uVar6 * 4));
        puVar10 = auStack_50 + uVar6 * 8;
        local_98 = 0x3fe6666660000000;
        local_90 = 0x3fec28f5c0000000;
        local_88 = 0x3fecccccc0000000;
        local_80 = 0x3fe99999a0000000;
        local_78 = 0x3fecccccc0000000;
        local_70 = 0x3fecccccc0000000;
        local_68 = 0xa0000000;
        uStack_64 = 0x3fea3d70;
        local_60 = 0x3fecccccc0000000;
        local_58 = 0x3fecccccc0000000;
        iVar25 = (uint)((double)(&local_98)[uVar6] < (double)(1.0 / (fVar26 + 1.0))) << 0x1f;
        if (iVar25 < 0) {
          *(uint *)(iVar17 + 0x24) = uVar6;
        }
        if (-1 < iVar25) {
          puVar10 = (undefined1 *)0x0;
        }
        if (-1 < iVar25) {
          *(undefined1 **)(iVar17 + 0x24) = puVar10;
        }
        uVar6 = ((int)local_ec - (int)local_f0 >> 2) * -0x55555555;
        if ((int)uVar6 <= (int)uVar4) goto LAB_0002356c;
        iVar17 = uVar4 * 0x2c + *(int *)param_2;
        if (uVar6 <= uVar4) {
                    /* WARNING: Subroutine does not return */
          std::__throw_out_of_range_fmt
                    ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                     uVar4,uVar6);
        }
        piVar7 = (int *)local_f0[uVar4 * 3];
        uVar2 = 0x3fe6666660000000;
      } while ((int *)local_f0[uVar4 * 3 + 1] != piVar7);
    }
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0);
  }
LAB_0002356c:
  get_time_ms();
  pvVar1 = local_e0;
  pvVar11 = local_e0;
  if (local_e4 != local_e0) {
    pvVar19 = (void *)((int)local_e4 + 0xc);
    pvVar11 = local_e4;
    pvVar20 = pvVar19;
    while( true ) {
      paVar15 = *(ax_tensor_t **)((int)pvVar11 + 4);
      this = *(ax_tensor_t **)((int)pvVar19 + -0xc);
      if (*(ax_tensor_t **)((int)pvVar19 + -0xc) != paVar15) {
        do {
          paVar13 = this + 0x30;
          ax_tensor_t::~ax_tensor_t(this);
          this = paVar13;
        } while (paVar15 != paVar13);
        paVar15 = *(ax_tensor_t **)((int)pvVar19 + -0xc);
      }
      if (paVar15 != (ax_tensor_t *)0x0) {
        operator_delete(paVar15);
      }
      pvVar19 = (void *)((int)pvVar19 + 0xc);
      pvVar11 = local_e4;
      if (pvVar1 == pvVar20) break;
      pvVar11 = pvVar20;
      pvVar20 = (void *)((int)pvVar20 + 0xc);
    }
  }
  if (pvVar11 != (void *)0x0) {
    operator_delete(pvVar11);
  }
  piVar7 = local_ec;
  piVar12 = local_ec;
  if (local_f0 != local_ec) {
    piVar18 = local_f0 + 3;
    piVar12 = local_f0;
    piVar21 = piVar18;
    while( true ) {
      puVar16 = (undefined4 *)piVar12[1];
      puVar14 = (undefined4 *)piVar18[-3];
      if (puVar14 != puVar16) {
        do {
          if ((void *)*puVar14 != (void *)0x0) {
            operator_delete((void *)*puVar14);
          }
          puVar14 = puVar14 + 3;
        } while (puVar16 != puVar14);
        puVar16 = (undefined4 *)piVar18[-3];
      }
      if (puVar16 != (undefined4 *)0x0) {
        operator_delete(puVar16);
      }
      piVar18 = piVar18 + 3;
      piVar12 = local_f0;
      if (piVar7 == piVar21) break;
      piVar12 = piVar21;
      piVar21 = piVar21 + 3;
    }
  }
  if (piVar12 != (int *)0x0) {
    operator_delete(piVar12);
  }
  if (local_fc != (void *)0x0) {
    operator_delete(local_fc);
  }
  if (local_cc != (void *)0x0) {
    operator_delete(local_cc);
  }
  if (local_d8 != (void *)0x0) {
    operator_delete(local_d8);
  }
  return;
}



/* void std::vector<campan_reid_feature_t, std::allocator<campan_reid_feature_t>
   >::_M_realloc_insert<campan_reid_feature_t
   const&>(__gnu_cxx::__normal_iterator<campan_reid_feature_t*, std::vector<campan_reid_feature_t,
   std::allocator<campan_reid_feature_t> > >, campan_reid_feature_t const&) */

void __thiscall
std::vector<campan_reid_feature_t,std::allocator<campan_reid_feature_t>>::
_M_realloc_insert<campan_reid_feature_t_const&>
          (vector<campan_reid_feature_t,std::allocator<campan_reid_feature_t>> *this,
          ax_tensor_t *param_2,ax_tensor_t *param_3)

{
  ax_tensor_t *paVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  ax_tensor_t *paVar6;
  ax_tensor_t *paVar7;
  ax_tensor_t *paVar8;
  uint uVar9;
  
  iVar2 = *(int *)this;
  uVar4 = *(int *)(this + 4) - iVar2 >> 6;
  if (uVar4 == 0) {
    uVar9 = 1;
LAB_00023740:
    uVar4 = uVar9 << 6;
LAB_000236e6:
    paVar1 = (ax_tensor_t *)operator_new(uVar4);
  }
  else {
    uVar9 = uVar4 * 2;
    if ((uVar9 < uVar4) || (0x3ffffff < uVar9)) {
      uVar4 = 0xffffffc0;
      uVar9 = 0x3ffffff;
      goto LAB_000236e6;
    }
    if (uVar9 != 0) goto LAB_00023740;
    paVar1 = (ax_tensor_t *)0x0;
  }
  paVar8 = paVar1 + ((int)param_2 - iVar2);
  if (paVar8 != (ax_tensor_t *)0x0) {
    ax_tensor_t::ax_tensor_t(paVar8,param_3);
    uVar5 = *(undefined4 *)(param_3 + 0x3c);
    uVar3 = *(undefined4 *)(param_3 + 0x30);
    *(undefined4 *)(paVar8 + 0x38) = *(undefined4 *)(param_3 + 0x38);
    *(undefined4 *)(paVar8 + 0x3c) = uVar5;
    *(undefined4 *)(paVar8 + 0x30) = uVar3;
  }
  paVar7 = *(ax_tensor_t **)this;
  paVar8 = paVar1;
  if (paVar7 == param_2) {
    paVar8 = *(ax_tensor_t **)(this + 4);
    paVar6 = paVar1 + 0x40;
    if (param_2 == paVar8) goto LAB_00023786;
LAB_00023752:
    do {
      if (paVar6 != (ax_tensor_t *)0x0) {
        ax_tensor_t::ax_tensor_t(paVar6,param_2);
        uVar5 = *(undefined4 *)(param_2 + 0x3c);
        uVar3 = *(undefined4 *)(param_2 + 0x30);
        *(undefined4 *)(paVar6 + 0x38) = *(undefined4 *)(param_2 + 0x38);
        *(undefined4 *)(paVar6 + 0x3c) = uVar5;
        *(undefined4 *)(paVar6 + 0x30) = uVar3;
      }
      param_2 = param_2 + 0x40;
      paVar6 = paVar6 + 0x40;
    } while (param_2 != paVar8);
    param_2 = *(ax_tensor_t **)(this + 4);
  }
  else {
    do {
      paVar6 = paVar8;
      if (paVar6 != (ax_tensor_t *)0x0) {
        ax_tensor_t::ax_tensor_t(paVar6,paVar7);
        uVar5 = *(undefined4 *)(paVar7 + 0x3c);
        uVar3 = *(undefined4 *)(paVar7 + 0x30);
        *(undefined4 *)(paVar6 + 0x38) = *(undefined4 *)(paVar7 + 0x38);
        *(undefined4 *)(paVar6 + 0x3c) = uVar5;
        *(undefined4 *)(paVar6 + 0x30) = uVar3;
      }
      paVar7 = paVar7 + 0x40;
      paVar8 = paVar6 + 0x40;
    } while (param_2 != paVar7);
    paVar8 = *(ax_tensor_t **)(this + 4);
    paVar6 = paVar6 + 0x80;
    if (paVar8 != param_2) goto LAB_00023752;
  }
  paVar8 = *(ax_tensor_t **)this;
  if (*(ax_tensor_t **)this != param_2) {
    do {
      paVar7 = paVar8 + 0x40;
      ax_tensor_t::~ax_tensor_t(paVar8);
      paVar8 = paVar7;
    } while (paVar7 != param_2);
    param_2 = *(ax_tensor_t **)this;
  }
LAB_00023786:
  if (param_2 != (ax_tensor_t *)0x0) {
    operator_delete(param_2);
  }
  *(ax_tensor_t **)(this + 8) = paVar1 + uVar9 * 0x40;
  *(ax_tensor_t **)this = paVar1;
  *(ax_tensor_t **)(this + 4) = paVar6;
  return;
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* campan_reid_process(campan_reid_t*, nn_campan_persons_t*, ax_yuv_t*,
   std::vector<campan_reid_feature_t, std::allocator<campan_reid_feature_t> >*) */

void campan_reid_process(campan_reid_t *param_1,nn_campan_persons_t *param_2,ax_yuv_t *param_3,
                        vector *param_4)

{
  void *pvVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  ax_tensor_t *paVar7;
  undefined4 *puVar8;
  int iVar9;
  ax_tensor_t *paVar10;
  undefined4 *puVar11;
  ax_tensor_t *paVar12;
  void *pvVar13;
  void *pvVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  double dVar19;
  void *local_cc;
  uint *local_c8;
  uint *local_c4;
  void *local_c0;
  void *local_bc;
  undefined4 local_b8;
  void *local_b4;
  void *local_b0;
  undefined4 uStack_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint uStack_98;
  uint local_94;
  undefined8 local_90;
  ax_tensor_mem_t aaStack_88 [16];
  int local_78;
  undefined8 local_70;
  void *local_68;
  undefined4 local_64;
  undefined4 local_60;
  void *local_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar18 = *(int *)(param_2 + 4);
  local_50 = *(undefined4 *)param_3;
  uStack_4c = *(undefined4 *)(param_3 + 4);
  uStack_48 = *(undefined4 *)(param_3 + 8);
  uStack_44 = *(undefined4 *)(param_3 + 0xc);
  local_40 = *(undefined4 *)(param_3 + 0x10);
  uStack_3c = *(undefined4 *)(param_3 + 0x14);
  uStack_38 = *(undefined4 *)(param_3 + 0x18);
  uStack_34 = *(undefined4 *)(param_3 + 0x1c);
  local_68 = (void *)0x0;
  local_30 = *(undefined4 *)(param_3 + 0x20);
  local_64 = 0;
  local_60 = 0;
  local_5c = (void *)0x0;
  uStack_58 = 0;
  local_54 = 0;
  local_2c = 0;
  local_cc = (void *)0x0;
  local_c8 = (uint *)0x0;
  local_c4 = (uint *)0x0;
  if (0 < iVar18) {
    iVar9 = 0;
    do {
      iVar15 = iVar9 * 0x2a8 + *(int *)param_2;
      uVar16 = *(int *)(param_3 + 0x1c) - 1;
      local_a4 = *(uint *)(iVar15 + 8);
      local_a8 = *(uint *)(iVar15 + 4);
      uVar4 = (*(int *)(iVar15 + 0xc) - *(int *)(iVar15 + 4)) + local_a8;
      uVar17 = *(int *)(param_3 + 0x18) - 1;
      local_a8 = local_a8 & ~((int)local_a8 >> 0x1f);
      uVar2 = (*(int *)(iVar15 + 0x10) - *(int *)(iVar15 + 8)) + local_a4;
      local_a4 = local_a4 & ~((int)local_a4 >> 0x1f);
      uVar4 = uVar4 & ~((int)uVar4 >> 0x1f);
      if ((int)uVar16 <= (int)local_a4) {
        local_a4 = uVar16;
      }
      uVar2 = uVar2 & ~((int)uVar2 >> 0x1f);
      if ((int)uVar17 <= (int)local_a8) {
        local_a8 = uVar17;
      }
      if ((int)uVar16 < (int)uVar2) {
        iVar15 = uVar16 - local_a4;
      }
      else {
        iVar15 = uVar2 - local_a4;
      }
      if ((int)uVar17 < (int)uVar4) {
        iVar5 = uVar17 - local_a8;
      }
      else {
        iVar5 = uVar4 - local_a8;
      }
      local_9c = iVar15 + 1;
      local_a0 = iVar5 + 1;
      if (local_c4 == local_c8) {
        std::vector<ax_rect_t,std::allocator<ax_rect_t>>::_M_realloc_insert<ax_rect_t_const&>
                  ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&local_cc,local_c4,&local_a8);
        iVar18 = *(int *)(param_2 + 4);
        if (iVar18 <= iVar9 + 1) break;
      }
      else {
        if (local_c8 != (uint *)0x0) {
          *local_c8 = local_a8;
          local_c8[1] = local_a4;
          local_c8[2] = local_a0;
          local_c8[3] = local_9c;
        }
        local_c8 = local_c8 + 4;
        if (iVar18 <= iVar9 + 1) break;
      }
      iVar9 = iVar9 + 1;
    } while( true );
  }
  std::vector<ax_rect_t,std::allocator<ax_rect_t>>::operator=
            ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&local_68,(vector *)&local_cc);
  local_c0 = (void *)0x0;
  local_bc = (void *)0x0;
  local_b8 = 0;
  local_b4 = (void *)0x0;
  local_b0 = (void *)0x0;
  uStack_ac = 0;
  batch_classify_process
            (*(batch_classify_model_t **)param_1,(classify_in_t *)&local_68,
             (classify_out_t *)&local_c0,2);
  if (0 < (int)local_b0 - (int)local_b4) {
    uVar2 = 0;
    do {
      ax_tensor_t::ax_tensor_t((ax_tensor_t *)&local_a8);
      if ((uint)(((int)local_b0 - (int)local_b4 >> 2) * -0x55555555) <= uVar2) {
                    /* WARNING: Subroutine does not return */
        std::__throw_out_of_range_fmt
                  ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",uVar2
                  );
      }
      puVar6 = *(uint **)((int)local_b4 + uVar2 * 0xc);
      if (*(uint **)((int)local_b4 + uVar2 * 0xc + 4) == puVar6) {
                    /* WARNING: Subroutine does not return */
        std::__throw_out_of_range_fmt
                  ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0);
      }
      local_a8 = *puVar6;
      uStack_98 = puVar6[4];
      local_a4 = puVar6[1];
      local_90 = *(undefined8 *)(puVar6 + 6);
      local_a0 = puVar6[2];
      local_9c = puVar6[3];
      local_94 = puVar6[5];
      ax_tensor_mem_t::operator=(aaStack_88,(ax_tensor_mem_t *)(puVar6 + 8));
      local_70 = get_time_ms();
      dVar19 = (double)ax_tensor_t::norm();
      local_78 = (int)(longlong)dVar19;
      if (local_78 == 0) {
        __android_log_print(6,"CAMPAN_ATTR","norm zero, set to 1");
        local_78 = 1;
      }
      paVar7 = *(ax_tensor_t **)(param_4 + 4);
      if (paVar7 == *(ax_tensor_t **)(param_4 + 8)) {
        std::vector<campan_reid_feature_t,std::allocator<campan_reid_feature_t>>::
        _M_realloc_insert<campan_reid_feature_t_const&>
                  ((vector<campan_reid_feature_t,std::allocator<campan_reid_feature_t>> *)param_4,
                   paVar7,(ax_tensor_t *)&local_a8);
      }
      else {
        if (paVar7 != (ax_tensor_t *)0x0) {
          ax_tensor_t::ax_tensor_t(paVar7,(ax_tensor_t *)&local_a8);
          *(int *)(paVar7 + 0x30) = local_78;
          *(undefined4 *)(paVar7 + 0x38) = (undefined4)local_70;
          *(undefined4 *)(paVar7 + 0x3c) = local_70._4_4_;
          paVar7 = *(ax_tensor_t **)(param_4 + 4);
        }
        *(ax_tensor_t **)(param_4 + 4) = paVar7 + 0x40;
      }
      uVar2 = uVar2 + 1;
      ax_tensor_t::~ax_tensor_t((ax_tensor_t *)&local_a8);
    } while ((int)uVar2 < ((int)local_b0 - (int)local_b4 >> 2) * -0x55555555);
  }
  pvVar1 = local_b0;
  if (local_b0 != local_b4) {
    pvVar14 = (void *)((int)local_b4 + 0xc);
    pvVar3 = local_b4;
    pvVar13 = pvVar14;
    while( true ) {
      paVar12 = *(ax_tensor_t **)((int)pvVar3 + 4);
      paVar7 = *(ax_tensor_t **)((int)pvVar14 + -0xc);
      if (*(ax_tensor_t **)((int)pvVar14 + -0xc) != paVar12) {
        do {
          paVar10 = paVar7 + 0x30;
          ax_tensor_t::~ax_tensor_t(paVar7);
          paVar7 = paVar10;
        } while (paVar12 != paVar10);
        paVar12 = *(ax_tensor_t **)((int)pvVar14 + -0xc);
      }
      if (paVar12 != (ax_tensor_t *)0x0) {
        operator_delete(paVar12);
      }
      pvVar14 = (void *)((int)pvVar14 + 0xc);
      if (pvVar13 == pvVar1) break;
      pvVar3 = pvVar13;
      pvVar13 = (void *)((int)pvVar13 + 0xc);
    }
  }
  if (local_b4 != (void *)0x0) {
    operator_delete(local_b4);
  }
  pvVar1 = local_bc;
  pvVar3 = local_bc;
  if (local_c0 != local_bc) {
    pvVar14 = (void *)((int)local_c0 + 0xc);
    pvVar3 = local_c0;
    pvVar13 = pvVar14;
    while( true ) {
      puVar11 = *(undefined4 **)((int)pvVar3 + 4);
      puVar8 = *(undefined4 **)((int)pvVar14 + -0xc);
      if (puVar8 != puVar11) {
        do {
          if ((void *)*puVar8 != (void *)0x0) {
            operator_delete((void *)*puVar8);
          }
          puVar8 = puVar8 + 3;
        } while (puVar11 != puVar8);
        puVar11 = *(undefined4 **)((int)pvVar14 + -0xc);
      }
      if (puVar11 != (undefined4 *)0x0) {
        operator_delete(puVar11);
      }
      pvVar14 = (void *)((int)pvVar14 + 0xc);
      pvVar3 = local_c0;
      if (pvVar1 == pvVar13) break;
      pvVar3 = pvVar13;
      pvVar13 = (void *)((int)pvVar13 + 0xc);
    }
  }
  if (pvVar3 != (void *)0x0) {
    operator_delete(pvVar3);
  }
  if (local_cc != (void *)0x0) {
    operator_delete(local_cc);
  }
  if (local_5c != (void *)0x0) {
    operator_delete(local_5c);
  }
  if (local_68 != (void *)0x0) {
    operator_delete(local_68);
  }
  return;
}



/* std::vector<int, std::allocator<int> >::_M_fill_assign(unsigned int, int const&) */

void __thiscall
std::vector<int,std::allocator<int>>::_M_fill_assign
          (vector<int,std::allocator<int>> *this,uint param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  
  piVar3 = *(int **)this;
  if ((uint)(*(int *)(this + 8) - (int)piVar3 >> 2) < param_1) {
    if (param_1 == 0) {
      piVar6 = (int *)0x0;
      piVar7 = (int *)0x0;
    }
    else {
      if (0x3fffffff < param_1) {
                    /* WARNING: Subroutine does not return */
        std::__throw_bad_alloc();
      }
      piVar6 = (int *)operator_new(param_1 * 4);
      piVar7 = piVar6 + param_1;
      iVar1 = *param_2;
      piVar3 = piVar6;
      do {
        *piVar3 = iVar1;
        param_1 = param_1 - 1;
        piVar3 = piVar3 + 1;
      } while (param_1 != 0);
      piVar3 = *(int **)this;
    }
    *(int **)this = piVar6;
    *(int **)(this + 4) = piVar7;
    *(int **)(this + 8) = piVar7;
    if (piVar3 != (int *)0x0) {
      operator_delete(piVar3);
      return;
    }
  }
  else {
    piVar6 = *(int **)(this + 4);
    iVar1 = *param_2;
    uVar2 = (int)piVar6 - (int)piVar3 >> 2;
    if (uVar2 < param_1) {
      if (piVar6 != piVar3) {
        do {
          piVar7 = piVar3 + 1;
          *piVar3 = iVar1;
          piVar3 = piVar7;
        } while (piVar6 != piVar7);
        iVar1 = *param_2;
      }
      iVar5 = param_1 - uVar2;
      piVar3 = piVar6;
      iVar4 = iVar5;
      do {
        *piVar3 = iVar1;
        iVar4 = iVar4 + -1;
        piVar3 = piVar3 + 1;
      } while (iVar4 != 0);
      *(int **)(this + 4) = piVar6 + iVar5;
      return;
    }
    piVar6 = piVar3;
    uVar2 = param_1;
    if (param_1 != 0) {
      do {
        *piVar6 = iVar1;
        uVar2 = uVar2 - 1;
        piVar6 = piVar6 + 1;
      } while (uVar2 != 0);
      piVar3 = piVar3 + param_1;
    }
    *(int **)(this + 4) = piVar3;
  }
  return;
}



/* person_head_match(campan_feature_match_t*, std::vector<ax_box_t, std::allocator<ax_box_t> >*,
   std::vector<ax_box_t, std::allocator<ax_box_t> >*, int**, int**) */

void person_head_match(campan_feature_match_t *param_1,vector *param_2,vector *param_3,int **param_4
                      ,int **param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  int local_b4;
  uint local_a4;
  int *local_a0;
  void *local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  int local_44;
  int local_40;
  int iStack_3c;
  float local_38;
  int local_34;
  
  local_44 = 0;
  local_80 = (void *)0x0;
  local_7c = 0;
  local_78 = 0;
  std::vector<int,std::allocator<int>>::_M_fill_assign
            ((vector<int,std::allocator<int>> *)&local_80,
             *(int *)(param_3 + 4) - *(int *)param_3 >> 4,&local_44);
  iVar8 = (*(int *)(param_3 + 4) - *(int *)param_3 >> 4) *
          (*(int *)(param_2 + 4) - *(int *)param_2 >> 4);
  AX_MALLOC_INC_TEMP<ax_int_array_t>((ax_int_array_t *)(param_1 + 0xb08),iVar8);
  AX_MALLOC_INC_TEMP<ax_int_array_t>
            ((ax_int_array_t *)(param_1 + 0xb10),
             (*(int *)(param_2 + 4) - *(int *)param_2 >> 4) +
             (*(int *)(param_3 + 4) - *(int *)param_3 >> 4));
  iVar3 = *(int *)param_2;
  iVar1 = *(int *)(param_2 + 4);
  iVar11 = *(int *)(param_3 + 4);
  iVar9 = *(int *)param_3;
  iVar4 = iVar1 - iVar3 >> 4;
  piVar5 = *(int **)(param_1 + 0xb08);
  piVar6 = *(int **)(param_1 + 0xb10);
  iVar2 = iVar11 - iVar9 >> 4;
  AX_MALLOC_INC_TEMP<box_intersect_array_t>((box_intersect_array_t *)(param_1 + 0xb38),iVar8);
  if (iVar11 - iVar9 < 1) {
LAB_00023da0:
    local_44 = iVar4;
    local_40 = iVar2;
    FUN_00022380(param_1 + 0xad8,piVar5,iVar4,iVar2,piVar6);
    if (param_4 != (int **)0x0) {
      *param_4 = piVar6 + iVar2;
    }
    if (param_5 != (int **)0x0) {
      *param_5 = piVar6;
    }
    if (local_80 != (void *)0x0) {
      operator_delete(local_80);
    }
    return;
  }
  iVar8 = *(int *)param_3;
  if (iVar8 == *(int *)(param_3 + 4)) {
    local_a4 = 0;
  }
  else {
    local_b4 = 0;
    local_a4 = 0;
    local_a0 = piVar5;
    do {
      puVar7 = (undefined4 *)(iVar8 + local_a4 * 0x10);
      local_74 = *puVar7;
      uStack_70 = puVar7[1];
      uStack_6c = puVar7[2];
      uStack_68 = puVar7[3];
      if (0 < iVar1 - iVar3) {
        iVar8 = *(int *)param_2;
        if (iVar8 == *(int *)(param_2 + 4)) {
          uVar10 = 0;
LAB_00023dea:
                    /* WARNING: Subroutine does not return */
          std::__throw_out_of_range_fmt
                    ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                     uVar10);
        }
        uVar10 = 0;
        piVar13 = local_a0;
        while( true ) {
          puVar7 = (undefined4 *)(iVar8 + uVar10 * 0x10);
          local_64 = *puVar7;
          uStack_60 = puVar7[1];
          uStack_5c = puVar7[2];
          uStack_58 = puVar7[3];
          get_person_upper_box((ax_box_t *)&local_54);
          box_overlap_intersect<ax_box_t>
                    (local_74,uStack_70,uStack_6c,uStack_68,local_54,uStack_50,uStack_4c,uStack_48,
                     &local_44);
          iVar8 = local_b4 + uVar10;
          uVar10 = uVar10 + 1;
          piVar12 = (int *)(iVar8 * 0x14 + *(int *)(param_1 + 0xb38));
          *piVar12 = local_44;
          piVar12[1] = local_40;
          piVar12[2] = iStack_3c;
          piVar12[3] = (int)local_38;
          piVar12[4] = local_34;
          *piVar13 = (int)-(local_38 * 1000.0);
          piVar13 = piVar13 + 1;
          if (iVar4 <= (int)uVar10) break;
          iVar8 = *(int *)param_2;
          if ((uint)(*(int *)(param_2 + 4) - iVar8 >> 4) <= uVar10) goto LAB_00023dea;
        }
      }
      local_a4 = local_a4 + 1;
      if (iVar2 <= (int)local_a4) goto LAB_00023da0;
      iVar8 = *(int *)param_3;
      local_b4 = local_b4 + iVar4;
      local_a0 = local_a0 + iVar4;
    } while (local_a4 < (uint)(*(int *)(param_3 + 4) - iVar8 >> 4));
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",local_a4);
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* head_person_match(campan_feature_match_t*, nn_campan_persons_t*, nn_campan_heads_t*) */

void head_person_match(campan_feature_match_t *param_1,nn_campan_persons_t *param_2,
                      nn_campan_heads_t *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  float fVar13;
  float fVar14;
  int *local_d0;
  int local_c4;
  int local_b0;
  int *local_ac;
  void *local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 uStack_80;
  undefined4 local_7c;
  undefined4 uStack_78;
  undefined4 local_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  int local_64;
  int local_60;
  int local_5c;
  int iStack_58;
  int local_54;
  int local_50;
  int iStack_4c;
  float local_48;
  int local_44;
  
  iVar4 = *(int *)(param_1 + 0xb30);
  local_54 = 0;
  local_90 = (void *)0x0;
  local_8c = 0;
  local_88 = 0;
  std::vector<int,std::allocator<int>>::_M_fill_assign
            ((vector<int,std::allocator<int>> *)&local_90,*(uint *)(param_3 + 4),&local_54);
  iVar5 = *(int *)(param_3 + 4);
  iVar8 = *(int *)(param_2 + 4);
  AX_MALLOC_INC_TEMP<ax_int_array_t>((ax_int_array_t *)(param_1 + 0xb08),iVar8 * iVar5);
  AX_MALLOC_INC_TEMP<ax_int_array_t>
            ((ax_int_array_t *)(param_1 + 0xb10),*(int *)(param_2 + 4) + *(int *)(param_3 + 4));
  uVar1 = *(undefined4 *)(param_1 + 0xb10);
  piVar3 = *(int **)(param_1 + 0xb08);
  iVar9 = *(int *)(param_3 + 4);
  iVar11 = *(int *)(param_2 + 4);
  AX_MALLOC_INC_TEMP<box_intersect_array_t>
            ((box_intersect_array_t *)(param_1 + 0xb38),iVar8 * iVar5);
  if (0 < iVar9) {
    iVar5 = iVar4 + 4;
    local_c4 = 0;
    local_b0 = 0;
    local_ac = piVar3;
    do {
      iVar8 = *(int *)param_3 + local_b0 * 0x3c;
      iVar6 = *(int *)(iVar4 + 8);
      local_84 = *(undefined4 *)(iVar8 + 4);
      uStack_80 = *(undefined4 *)(iVar8 + 8);
      local_7c = *(undefined4 *)(iVar8 + 0xc);
      uStack_78 = *(undefined4 *)(iVar8 + 0x10);
      iVar8 = iVar5;
      if (iVar6 != 0) {
        iVar2 = *(int *)(*(int *)param_3 + local_b0 * 0x3c);
        do {
          if (*(int *)(iVar6 + 0x10) < iVar2) {
            iVar7 = *(int *)(iVar6 + 0xc);
          }
          else {
            iVar7 = *(int *)(iVar6 + 8);
            iVar8 = iVar6;
          }
          iVar6 = iVar7;
        } while (iVar7 != 0);
        if ((iVar8 != iVar5) && (iVar2 < *(int *)(iVar8 + 0x10))) {
          iVar8 = iVar5;
        }
      }
      if (0 < iVar11) {
        iVar6 = 0;
        local_d0 = local_ac;
        do {
          iVar12 = *(int *)param_2;
          iVar7 = iVar12 + iVar6 * 0x2a8;
          get_person_upper_box((nn_campan_person_t *)&local_74);
          local_60 = *(int *)(iVar7 + 8);
          local_5c = (*(int *)(iVar7 + 0xc) + *(int *)(iVar7 + 4)) / 2;
          iVar2 = (int)(longlong)
                       ((double)(longlong)(*(int *)(iVar7 + 0xc) - *(int *)(iVar7 + 4)) * 0.333);
          iStack_58 = iVar2 + local_60;
          iVar2 = iVar2 / 2;
          local_64 = local_5c - iVar2;
          if (*(int *)(iVar7 + 0x10) <= iStack_58) {
            iStack_58 = *(int *)(iVar7 + 0x10);
          }
          local_5c = local_5c + iVar2;
          box_overlap_intersect<ax_box_t>
                    (local_84,uStack_80,local_7c,uStack_78,local_74,uStack_70,uStack_6c,uStack_68,
                     &local_54);
          fVar13 = iou<ax_box_t>(local_84,uStack_80,local_7c,uStack_78,local_64,local_60,local_5c,
                                 iStack_58);
          piVar10 = (int *)((local_c4 + iVar6) * 0x14 + *(int *)(param_1 + 0xb38));
          *piVar10 = local_54;
          piVar10[1] = local_50;
          piVar10[2] = iStack_4c;
          piVar10[3] = (int)local_48;
          piVar10[4] = local_44;
          if (((iVar8 == iVar5) || (*(int *)(iVar8 + 0x14) != *(int *)(iVar12 + iVar6 * 0x2a8))) ||
             (*(int *)(iVar8 + 0x18) < 6)) {
            fVar14 = 0.0;
          }
          else {
            fVar14 = (float)((double)(longlong)*(int *)(iVar8 + 0x18) * 0.1);
            if (fVar14 != 1.0 && fVar14 < 1.0 == NAN(fVar14)) {
              fVar14 = 1.0;
            }
          }
          iVar6 = iVar6 + 1;
          *local_d0 = (int)-((fVar13 + local_48 + fVar14) * 1000.0);
          local_d0 = local_d0 + 1;
        } while (iVar11 != iVar6);
      }
      local_c4 = local_c4 + iVar11;
      local_ac = local_ac + iVar11;
      local_b0 = local_b0 + 1;
    } while (iVar9 != local_b0);
  }
  local_54 = iVar11;
  local_50 = iVar9;
  FUN_00022380(param_1 + 0xad8,piVar3,iVar11,iVar9,uVar1);
  if (local_90 != (void *)0x0) {
    operator_delete(local_90);
  }
  return;
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* campan_feature_match_process(campan_feature_match_t*, nn_campan_persons_t*, nn_campan_heads_t*,
   dtbased_tk*, dtbased_tk*) */

void campan_feature_match_process
               (campan_feature_match_t *param_1,nn_campan_persons_t *param_2,
               nn_campan_heads_t *param_3,dtbased_tk *param_4,dtbased_tk *param_5)

{
  bool bVar1;
  ax_int_array_t *paVar2;
  ax_int_array_t *paVar3;
  void *pvVar4;
  _List_node_base *p_Var5;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  undefined4 *puVar16;
  int iVar17;
  undefined4 *puVar18;
  nn_campan_person_t *pnVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int *piVar25;
  campan_feature_match_t *pcVar26;
  campan_feature_match_t *pcVar27;
  int *piVar28;
  int iVar29;
  campan_feature_match_t *pcVar30;
  int iVar31;
  float fVar32;
  double dVar33;
  float fVar34;
  float fVar35;
  double dVar36;
  int local_c4;
  int local_c0;
  pthread_mutex_t *local_b4;
  float local_90;
  undefined1 auStack_8c [4];
  int local_88;
  int local_84;
  void *local_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  int *local_74;
  int local_70;
  int local_6c;
  int local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int *local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 *puVar19;
  
  local_54 = (int *)0x0;
  local_80 = (void *)0x0;
  uStack_7c = 0;
  local_78 = 0;
  std::vector<int,std::allocator<int>>::_M_fill_assign
            ((vector<int,std::allocator<int>> *)&local_80,*(uint *)(param_2 + 4),(int *)&local_54);
  AX_MALLOC_INC_TEMP<ax_int_array_t>
            ((ax_int_array_t *)(param_1 + 0xb08),*(int *)(param_1 + 0xacc) * *(int *)(param_2 + 4));
  AX_MALLOC_INC_TEMP<ax_int_array_t>
            ((ax_int_array_t *)(param_1 + 0xb10),*(int *)(param_2 + 4) + *(int *)(param_1 + 0xacc));
  iVar9 = *(int *)(param_2 + 4);
  puVar7 = *(undefined4 **)(param_1 + 0xb08);
  iVar10 = iVar9 + -1;
  iVar11 = *(int *)(param_1 + 0xacc);
  piVar8 = *(int **)(param_1 + 0xb10);
  iVar29 = 0;
  if (0 < iVar10) {
    do {
      iVar21 = iVar29 + 1;
      iVar14 = *(int *)param_2;
      iVar15 = iVar29 * 0x2a8;
      piVar28 = (int *)(iVar14 + iVar15);
      iVar22 = iVar21;
      if (iVar21 < iVar9) {
        while( true ) {
          iVar15 = iVar15 + 0x2a8;
          iVar12 = iVar14 + iVar15;
          if (*piVar28 == *(int *)(iVar14 + iVar15)) {
            __android_log_print(6,"CAMPAN_ATTR","input id the same ! id %d");
            __android_log_print(6,"CAMPAN_ATTR","p1 %d, %d, %d, %d, %d",iVar29,piVar28[1],piVar28[2]
                                ,piVar28[3],piVar28[4]);
            __android_log_print(6,"CAMPAN_ATTR","p2 %d, %d, %d, %d, %d",iVar22,
                                *(undefined4 *)(iVar12 + 4),*(undefined4 *)(iVar12 + 8),
                                *(undefined4 *)(iVar12 + 0xc),*(undefined4 *)(iVar12 + 0x10));
          }
          if (iVar9 == iVar22 + 1) break;
          iVar14 = *(int *)param_2;
          iVar22 = iVar22 + 1;
        }
      }
      iVar29 = iVar21;
    } while (iVar21 < iVar10);
  }
  if (0 < iVar9) {
    iVar29 = 0;
    puVar16 = puVar7;
    do {
      iVar22 = *(int *)param_2;
      if (0 < iVar11) {
        iVar14 = 0;
        puVar18 = puVar16;
        do {
          dVar33 = (double)person_feature_dist((nn_campan_person_feature_t *)
                                               (iVar29 * 0x2a8 + iVar22 + 0x30),
                                               (nn_campan_person_feature_t *)
                                               (iVar14 * 0x2a8 + *(int *)(param_1 + 0xac8) + 0x30));
          iVar14 = iVar14 + 1;
          *puVar18 = (int)(longlong)(dVar33 * 1000.0);
          puVar18 = puVar18 + 1;
        } while (iVar11 != iVar14);
      }
      iVar29 = iVar29 + 1;
      puVar16 = puVar16 + iVar11;
    } while (iVar9 != iVar29);
  }
  piVar28 = piVar8;
  local_88 = iVar11;
  local_84 = iVar9;
  FUN_00022380(param_1 + 0xad8,puVar7,iVar11,iVar9,piVar8);
  paVar2 = (ax_int_array_t *)(param_1 + 0xb18);
  AX_MALLOC_INC_TEMP<ax_int_array_t>(paVar2,iVar9);
  paVar3 = (ax_int_array_t *)(param_1 + 0xb20);
  AX_MALLOC_INC_TEMP<ax_int_array_t>(paVar3,iVar9);
  puVar16 = *(undefined4 **)(param_1 + 0xb28);
  *(int *)(param_1 + 0xb2c) = iVar9;
  iVar29 = iVar9 * 4;
  if (puVar16 == (undefined4 *)0x0) {
    if (0 < iVar29) goto LAB_00024a9a;
  }
  else if (puVar16[-1] + iVar9 * -4 < 0 != SBORROW4(puVar16[-1],iVar29)) {
    AX_FREE_RECORD(puVar16);
    *(undefined4 *)(param_1 + 0xb28) = 0;
LAB_00024a9a:
    puVar16 = (undefined4 *)AX_MALLOC_RECORD(iVar29);
    *(undefined4 **)(param_1 + 0xb28) = puVar16;
    if (puVar16 == (undefined4 *)0x0) {
      *(undefined4 *)(param_1 + 0xb2c) = 0;
    }
  }
  iVar29 = *(int *)(param_1 + 0xb18);
  iVar22 = *(int *)(param_1 + 0xb20);
  if (iVar9 < 1) {
    pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x318));
    if (*(int *)(param_1 + 0x300) != -1) {
      *(int *)(param_1 + 0x304) = *(int *)(param_1 + 0x304) + 1;
      goto LAB_00024528;
    }
  }
  else {
    iVar14 = 0;
    iVar15 = 0;
    iVar21 = 0;
    piVar25 = piVar8;
    do {
      while( true ) {
        piVar6 = piVar25 + 1;
        iVar12 = *piVar25;
        iVar23 = *(int *)param_2 + iVar15;
        iVar24 = *(int *)(*(int *)param_2 + iVar15);
        piVar25 = piVar6;
        if (-1 < iVar12) break;
        *(int *)(iVar29 + iVar21 * 4) = iVar24;
LAB_0002432a:
        iVar15 = iVar15 + 0x2a8;
        iVar14 = iVar14 + iVar11;
        *(undefined4 *)(iVar22 + iVar21 * 4) = 0xffffffff;
        puVar16[iVar21] = iVar23;
        iVar21 = iVar21 + 1;
        if (piVar8 + iVar9 == piVar6) goto LAB_0002434a;
      }
      iVar17 = *(int *)(param_1 + 0xac8);
      iVar31 = *(int *)(iVar17 + iVar12 * 0x2a8);
      if ((int)((uint)((double)(longlong)(int)puVar7[iVar14 + iVar12] / 1000.0 < 0.15) << 0x1f) < 0)
      {
        if (iVar31 != iVar24) {
          *(int *)(iVar29 + iVar21 * 4) = iVar24;
          *(undefined4 *)(iVar22 + iVar21 * 4) = *(undefined4 *)(iVar17 + iVar12 * 0x2a8);
          puVar16[iVar21] = iVar23;
          iVar21 = iVar21 + 1;
        }
      }
      else if (iVar31 == iVar24) {
        *(int *)(iVar29 + iVar21 * 4) = iVar31;
        goto LAB_0002432a;
      }
      iVar15 = iVar15 + 0x2a8;
      iVar14 = iVar14 + iVar11;
    } while (piVar8 + iVar9 != piVar6);
LAB_0002434a:
    if (iVar21 != 0) {
      __android_log_print(6,"CAMPAN_ATTR","change 1");
      dtbased_tk_change_ids(param_4,iVar29,iVar22,iVar21);
      puVar7 = (undefined4 *)(iVar22 + -4);
      puVar18 = puVar16;
      do {
        puVar19 = puVar18 + 1;
        puVar7 = puVar7 + 1;
        *(undefined4 *)*puVar18 = *puVar7;
        puVar18 = puVar19;
      } while (puVar16 + iVar21 != puVar19);
    }
    pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x318));
    iVar29 = *(int *)(param_1 + 0x300);
    if (iVar29 != -1) {
      if (iVar29 == **(int **)param_2) {
        iVar14 = 0;
      }
      else {
        iVar22 = 0;
        iVar11 = 0x2a8;
        do {
          iVar14 = iVar11;
          iVar22 = iVar22 + 1;
          if (iVar9 == iVar22) {
            local_c4 = 0;
            *(int *)(param_1 + 0x304) = *(int *)(param_1 + 0x304) + 1;
            goto LAB_000243e4;
          }
          iVar11 = iVar14 + 0x2a8;
        } while (*(int *)((int)*(int **)param_2 + iVar14) != iVar29);
      }
      fVar32 = 10000.0;
      iVar22 = 0;
      *(undefined4 *)(param_1 + 0x304) = 0;
      pcVar27 = param_1 + 0x2d0;
      pvVar4 = (void *)(*(int *)param_2 + iVar14);
      iVar11 = -1;
      fVar34 = (float)(longlong)(*(int *)((int)pvVar4 + 0xc) - *(int *)((int)pvVar4 + 4)) /
               (float)(longlong)(*(int *)((int)pvVar4 + 0x10) - *(int *)((int)pvVar4 + 8));
      iVar29 = *(int *)((int)pvVar4 + 0x10);
      do {
        fVar35 = *(float *)pcVar27;
        pcVar27 = pcVar27 + 4;
        iVar14 = (uint)(ABS(fVar34 - fVar35) < fVar32) << 0x1f;
        if (iVar14 < 0) {
          iVar29 = iVar22;
          fVar32 = ABS(fVar34 - fVar35);
        }
        iVar22 = iVar22 + 1;
        if (-1 < iVar14) {
          iVar29 = iVar11;
        }
        iVar11 = iVar29;
        iVar29 = iVar11;
      } while (iVar22 != 5);
      if ((int)((uint)(fVar34 < 0.25) << 0x1f) < 0) {
        bVar1 = false;
      }
      else {
        bVar1 = fVar34 == 2.0 || fVar34 < 2.0 != NAN(fVar34);
      }
      get_person_upper_box((nn_campan_person_t *)&local_74);
      if (*(int *)(param_3 + 4) < 1) {
LAB_00024b0a:
        if (bVar1) {
          piVar25 = *(int **)(param_1 + (iVar11 + 0xaa) * 4);
          piVar8 = (int *)*piVar25;
          if (piVar8 != piVar25) {
            do {
              dVar33 = (double)person_feature_dist((nn_campan_person_feature_t *)(piVar8 + 0xe),
                                                   (nn_campan_person_feature_t *)
                                                   ((int)pvVar4 + 0x30));
              piVar8 = (int *)*piVar8;
              if ((int)((uint)(dVar33 < 0.04) << 0x1f) < 0) {
                bVar1 = false;
              }
            } while (piVar8 != piVar25);
            if ((!bVar1) && (3 < (uint)piVar8[2])) goto LAB_00024a06;
          }
          p_Var5 = (_List_node_base *)operator_new(0x2b0);
          memcpy(p_Var5 + 8,pvVar4,0x2a8);
          std::__detail::_List_node_base::_M_hook(p_Var5);
          iVar29 = piVar25[2];
          uVar13 = iVar29 + 1;
          piVar25[2] = uVar13;
          if (8 < uVar13) {
            pvVar4 = (void *)*piVar25;
            piVar25[2] = iVar29;
            std::__detail::_List_node_base::_M_unhook();
            operator_delete(pvVar4);
          }
        }
      }
      else {
        iVar29 = 0;
        iVar22 = 0;
        do {
          iVar14 = iVar29 * 0x3c + *(int *)param_3;
          iVar29 = iVar29 + 1;
          local_64 = *(undefined4 *)(iVar14 + 4);
          local_60 = *(undefined4 *)(iVar14 + 8);
          local_5c = *(undefined4 *)(iVar14 + 0xc);
          local_58 = *(undefined4 *)(iVar14 + 0x10);
          piVar28 = local_74;
          box_overlap_intersect<ax_box_t>
                    (local_64,local_60,local_5c,local_58,local_74,local_70,local_6c,local_68,
                     &local_54);
          if (local_50 != 0.7 && local_50 < 0.7 == NAN(local_50)) {
            iVar22 = iVar22 + 1;
          }
        } while (iVar29 < *(int *)(param_3 + 4));
        if (iVar22 < 2) goto LAB_00024b0a;
        __android_log_print(6,"CAMPAN_ATTR","find not only one head reject %d",iVar22);
      }
LAB_00024a06:
      puVar7 = *(undefined4 **)(param_1 + 0x2c4);
      iVar29 = 0;
      do {
        pvVar4 = (void *)(*(int *)param_2 + iVar29 * 0x2a8);
        if (*(int *)(*(int *)param_2 + iVar29 * 0x2a8) != *(int *)(param_1 + 0x300)) {
          pcVar26 = param_1 + 0x2e4;
          bVar1 = false;
          pcVar27 = param_1 + 0x2a8;
          do {
            pcVar30 = pcVar27 + 4;
            piVar25 = *(int **)pcVar27;
            for (piVar8 = (int *)*piVar25; piVar8 != piVar25; piVar8 = (int *)*piVar8) {
              dVar33 = (double)person_feature_dist((nn_campan_person_feature_t *)(piVar8 + 0xe),
                                                   (nn_campan_person_feature_t *)
                                                   ((int)pvVar4 + 0x30));
              dVar36 = (double)*(float *)pcVar26;
              if (dVar36 != dVar33 && dVar36 < dVar33 == (NAN(dVar36) || NAN(dVar33))) {
                bVar1 = true;
                break;
              }
            }
            pcVar26 = pcVar26 + 4;
            pcVar27 = pcVar30;
          } while (param_1 + 700 != pcVar30);
          if (bVar1) {
            p_Var5 = (_List_node_base *)operator_new(0x2b0);
            memcpy(p_Var5 + 8,pvVar4,0x2a8);
            std::__detail::_List_node_base::_M_hook(p_Var5);
            iVar11 = puVar7[2];
            uVar13 = iVar11 + 1;
            puVar7[2] = uVar13;
            if (0xf < uVar13) {
              pvVar4 = (void *)*puVar7;
              puVar7[2] = iVar11;
              std::__detail::_List_node_base::_M_unhook();
              operator_delete(pvVar4);
            }
          }
        }
        iVar29 = iVar29 + 1;
      } while (iVar9 != iVar29);
      goto LAB_00024528;
    }
  }
  goto LAB_00024768;
  while (local_c4 = local_c4 + 1, iVar22 != local_c4) {
LAB_000243e4:
    bVar1 = false;
    pnVar20 = (nn_campan_person_t *)(local_c4 * 0x2a8 + *(int *)param_2);
    pcVar27 = param_1 + 0x2e4;
    pcVar26 = param_1 + 0x2a8;
    do {
      pcVar30 = pcVar26 + 4;
      piVar25 = *(int **)pcVar26;
      for (piVar8 = (int *)*piVar25; piVar8 != piVar25; piVar8 = (int *)*piVar8) {
        dVar33 = (double)person_feature_dist((nn_campan_person_feature_t *)(piVar8 + 0xe),
                                             (nn_campan_person_feature_t *)(pnVar20 + 0x30));
        dVar36 = (double)*(float *)pcVar27;
        if ((dVar36 != dVar33 && dVar36 < dVar33 == (NAN(dVar36) || NAN(dVar33))) &&
           ((int)((uint)(ABS((float)(longlong)(*(int *)(pnVar20 + 0xc) - *(int *)(pnVar20 + 4)) /
                             (float)(longlong)(*(int *)(pnVar20 + 0x10) - *(int *)(pnVar20 + 8)) -
                             (float)(longlong)(piVar8[5] - piVar8[3]) /
                             (float)(longlong)(piVar8[6] - piVar8[4])) < 0.4) << 0x1f) < 0)) {
          bVar1 = true;
          break;
        }
      }
      pcVar27 = pcVar27 + 4;
      pcVar26 = pcVar30;
    } while (param_1 + 700 != pcVar30);
    if (((bVar1) && (3 < *(int *)(param_1 + 0x304))) &&
       (fVar32 = (float)negative_nearest(param_1,pnVar20),
       (int)((uint)(*(float *)(param_1 + 0x2f8) < fVar32) << 0x1f) < 0)) {
      AX_MALLOC_INC_TEMP<ax_int_array_t>(paVar2,1);
      AX_MALLOC_INC_TEMP<ax_int_array_t>(paVar3,1);
      puVar7 = *(undefined4 **)(param_1 + 0xb18);
      puVar16 = *(undefined4 **)(param_1 + 0xb20);
      *puVar7 = *(undefined4 *)pnVar20;
      *puVar16 = *(undefined4 *)(param_1 + 0x300);
      dtbased_tk_change_ids(param_4,puVar7,puVar16,1);
      *(undefined4 *)pnVar20 = *(undefined4 *)(param_1 + 0x300);
      goto LAB_00024528;
    }
  }
  piVar8 = *(int **)(param_1 + 700);
  iVar29 = 0;
  do {
    piVar25 = (int *)*piVar8;
    pnVar20 = (nn_campan_person_t *)(iVar29 * 0x2a8 + *(int *)param_2);
    if (piVar25 != piVar8) {
      do {
        dVar33 = (double)person_feature_dist((nn_campan_person_feature_t *)(piVar25 + 0xe),
                                             (nn_campan_person_feature_t *)(pnVar20 + 0x30));
        dVar36 = (double)*(float *)(param_1 + 0x2fc);
        if (dVar36 != dVar33 && dVar36 < dVar33 == (NAN(dVar36) || NAN(dVar33))) {
          if ((3 < *(int *)(param_1 + 0x304)) &&
             (fVar32 = (float)negative_nearest(param_1,pnVar20),
             (int)((uint)(*(float *)(param_1 + 0x2f8) < fVar32) << 0x1f) < 0)) {
            AX_MALLOC_INC_TEMP<ax_int_array_t>(paVar2,1);
            AX_MALLOC_INC_TEMP<ax_int_array_t>(paVar3,1);
            puVar7 = *(undefined4 **)(param_1 + 0xb18);
            puVar16 = *(undefined4 **)(param_1 + 0xb20);
            *puVar7 = *(undefined4 *)pnVar20;
            *puVar16 = *(undefined4 *)(param_1 + 0x300);
            dtbased_tk_change_ids(param_4,puVar7,puVar16,1);
            *(undefined4 *)pnVar20 = *(undefined4 *)(param_1 + 0x300);
            goto LAB_00024528;
          }
          break;
        }
        piVar25 = (int *)*piVar25;
      } while (piVar25 != piVar8);
    }
    iVar29 = iVar29 + 1;
  } while (iVar22 != iVar29);
LAB_00024528:
  head_person_match(param_1,param_2,param_3);
  if (*(int *)(param_3 + 4) < 1) {
LAB_0002455c:
    if (0 < iVar9) {
      piVar8 = *(int **)param_2;
      if (*piVar8 != *(int *)(param_1 + 0x300)) {
        iVar29 = 0;
        do {
          iVar29 = iVar29 + 1;
          if (iVar9 == iVar29) goto LAB_00024768;
          piVar25 = piVar8 + 0xaa;
          piVar8 = piVar8 + 0xaa;
        } while (*piVar25 != *(int *)(param_1 + 0x300));
      }
      local_68 = piVar8[4];
      piVar25 = (int *)piVar8[1];
      iVar29 = piVar8[2];
      iVar11 = piVar8[3];
      get_person_upper_box((nn_campan_person_t *)&local_64);
      if (0 < *(int *)(param_3 + 4)) {
        iVar22 = 0;
        local_c0 = 0;
        do {
          iVar14 = iVar22 * 0x3c;
          iVar15 = *(int *)param_3 + iVar14;
          local_54 = *(int **)(iVar15 + 4);
          local_50 = *(float *)(iVar15 + 8);
          local_4c = *(undefined4 *)(iVar15 + 0xc);
          local_48 = *(undefined4 *)(iVar15 + 0x10);
          box_overlap<ax_box_t>
                    (local_64,local_60,local_5c,local_58,local_54,local_50,local_4c,local_48,
                     &local_90,auStack_8c);
          if (local_90 != 0.7 && local_90 < 0.7 == NAN(local_90)) {
            local_c0 = local_c0 + 1;
          }
          piVar28 = local_54;
          local_74 = piVar25;
          local_70 = iVar29;
          local_6c = iVar11;
          box_overlap<ax_box_t>
                    (piVar25,iVar29,iVar11,local_68,local_54,local_50,local_4c,local_48,&local_90,
                     auStack_8c);
          if (local_90 != 0.75 && local_90 < 0.75 == NAN(local_90)) {
            iVar21 = (iVar29 + (int)(longlong)((double)(longlong)(iVar11 - (int)piVar25) * 0.4) / 2)
                     - (*(int *)(iVar15 + 0x10) + *(int *)(iVar15 + 8)) / 2;
            iVar15 = ((int)piVar25 + iVar11) / 2 -
                     (*(int *)(iVar15 + 0xc) + *(int *)(iVar15 + 4)) / 2;
            fVar32 = (float)(longlong)(iVar15 * iVar15 + iVar21 * iVar21);
            if ((int)((uint)(fVar32 < 0.0) << 0x1f) < 0) {
              sqrtf(fVar32);
            }
            if ((int)((uint)(SQRT(fVar32) < 1e+08) << 0x1f) < 0) {
              if (local_c0 == 1) {
                iVar11 = *(int *)(param_1 + 0xb30) + 4;
                iVar22 = *(int *)param_3;
                iVar29 = *(int *)(*(int *)(param_1 + 0xb30) + 8);
                if (iVar29 != 0) {
                  iVar15 = iVar11;
                  do {
                    if (*(int *)(iVar29 + 0x10) < *(int *)(iVar22 + iVar14)) {
                      iVar21 = *(int *)(iVar29 + 0xc);
                    }
                    else {
                      iVar21 = *(int *)(iVar29 + 8);
                      iVar15 = iVar29;
                    }
                    iVar29 = iVar21;
                  } while (iVar21 != 0);
                  if ((((iVar11 != iVar15) && (*(int *)(iVar15 + 0x10) <= *(int *)(iVar22 + iVar14))
                       ) && (*(int *)(iVar15 + 0x14) == *(int *)(param_1 + 0x300))) &&
                     (0 < *(int *)(iVar15 + 0x18))) {
                    AX_MALLOC_INC_TEMP<ax_int_array_t>(paVar2,1);
                    AX_MALLOC_INC_TEMP<ax_int_array_t>(paVar3,1);
                    piVar8 = *(int **)(param_1 + 0xb18);
                    piVar25 = *(int **)(param_1 + 0xb20);
                    *piVar8 = *(int *)(iVar22 + iVar14) + -10000000;
                    *piVar25 = *(int *)(param_1 + 0x330) + -10000000;
                    dtbased_tk_change_ids(param_5,piVar8,piVar25,1);
                    *(undefined4 *)(iVar22 + iVar14) = *(undefined4 *)(param_1 + 0x330);
                  }
                }
              }
              break;
            }
          }
          iVar22 = iVar22 + 1;
        } while (iVar22 < *(int *)(param_3 + 4));
      }
    }
  }
  else {
    piVar8 = *(int **)param_3;
    if (*(int *)(param_1 + 0x330) != *piVar8) {
      iVar29 = 0;
      do {
        iVar29 = iVar29 + 1;
        if (iVar29 == *(int *)(param_3 + 4)) goto LAB_0002455c;
        piVar8 = piVar8 + 0xf;
      } while (*piVar8 != *(int *)(param_1 + 0x330));
    }
  }
LAB_00024768:
  local_b4 = (pthread_mutex_t *)(param_1 + 0x318);
  pthread_mutex_unlock(local_b4);
  if (0 < iVar10) {
    iVar29 = 0;
    do {
      iVar22 = *(int *)param_2;
      iVar15 = iVar29 + 1;
      iVar14 = iVar29 * 0x2a8;
      piVar8 = (int *)(iVar22 + iVar14);
      iVar11 = iVar15;
      if (iVar15 < iVar9) {
        while( true ) {
          iVar14 = iVar14 + 0x2a8;
          iVar21 = iVar22 + iVar14;
          if (*piVar8 == *(int *)(iVar22 + iVar14)) {
            __android_log_print(6,"CAMPAN_ATTR","id the same! id %d",*piVar8,piVar28);
            __android_log_print(6,"CAMPAN_ATTR","person1 %d, %d, %d, %d, %d",iVar29,piVar8[1],
                                piVar8[2],piVar8[3],piVar8[4]);
            piVar28 = *(int **)(iVar21 + 4);
            __android_log_print(6,"CAMPAN_ATTR","person2 %d, %d, %d, %d, %d",iVar11,piVar28,
                                *(undefined4 *)(iVar21 + 8),*(undefined4 *)(iVar21 + 0xc),
                                *(undefined4 *)(iVar21 + 0x10));
          }
          if (iVar9 == iVar11 + 1) break;
          iVar22 = *(int *)param_2;
          iVar11 = iVar11 + 1;
        }
      }
      iVar29 = iVar15;
    } while (iVar15 != iVar10);
  }
  iVar29 = *(int *)(param_2 + 4);
  pvVar4 = *(void **)(param_1 + 0xac8);
  *(int *)(param_1 + 0xacc) = iVar29;
  iVar9 = iVar29 * 0x2a8;
  if (pvVar4 == (void *)0x0) {
    if (0 < iVar9) goto LAB_00024abe;
  }
  else if (*(int *)((int)pvVar4 + -4) + iVar29 * -0x2a8 < 0 !=
           SBORROW4(*(int *)((int)pvVar4 + -4),iVar9)) {
    AX_FREE_RECORD(pvVar4);
    *(undefined4 *)(param_1 + 0xac8) = 0;
LAB_00024abe:
    iVar29 = AX_MALLOC_RECORD(iVar9);
    *(int *)(param_1 + 0xac8) = iVar29;
    if (iVar29 == 0) {
      *(undefined4 *)(param_1 + 0xacc) = 0;
    }
  }
  if (0 < *(int *)(param_2 + 4)) {
    memcpy(*(void **)(param_1 + 0xac8),*(void **)param_2,*(int *)(param_2 + 4) * 0x2a8);
  }
  pvVar4 = *(void **)(param_1 + 0xad0);
  iVar29 = *(int *)(param_3 + 4);
  *(int *)(param_1 + 0xad4) = iVar29;
  iVar29 = iVar29 * 0x3c;
  if (pvVar4 == (void *)0x0) {
    if (iVar29 < 1) goto LAB_000248b6;
  }
  else {
    if (iVar29 - *(int *)((int)pvVar4 + -4) == 0 || iVar29 < *(int *)((int)pvVar4 + -4))
    goto LAB_000248b6;
    AX_FREE_RECORD(pvVar4);
    *(undefined4 *)(param_1 + 0xad0) = 0;
  }
  iVar29 = AX_MALLOC_RECORD(iVar29);
  *(int *)(param_1 + 0xad0) = iVar29;
  if (iVar29 == 0) {
    *(undefined4 *)(param_1 + 0xad4) = 0;
  }
LAB_000248b6:
  if (0 < *(int *)(param_3 + 4)) {
    memcpy(*(void **)(param_1 + 0xad0),*(void **)param_3,*(int *)(param_3 + 4) * 0x3c);
  }
  if (local_80 != (void *)0x0) {
    operator_delete(local_80);
  }
  return;
}



/* void std::vector<nn_campan_hand_t, std::allocator<nn_campan_hand_t>
   >::_M_realloc_insert<nn_campan_hand_t const&>(__gnu_cxx::__normal_iterator<nn_campan_hand_t*,
   std::vector<nn_campan_hand_t, std::allocator<nn_campan_hand_t> > >, nn_campan_hand_t const&) */

void __thiscall
std::vector<nn_campan_hand_t,std::allocator<nn_campan_hand_t>>::
_M_realloc_insert<nn_campan_hand_t_const&>
          (vector<nn_campan_hand_t,std::allocator<nn_campan_hand_t>> *this,void *param_2,
          undefined4 *param_3)

{
  void *__dest;
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  size_t sVar7;
  undefined4 *puVar8;
  size_t __n;
  void *__dest_00;
  void *__src;
  void *pvVar9;
  
  __src = *(void **)this;
  pvVar9 = *(void **)(this + 4);
  sVar7 = (int)param_2 - (int)__src;
  iVar1 = (int)pvVar9 - (int)__src >> 2;
  uVar5 = iVar1 * -0x45d1745d;
  if (uVar5 == 0) {
    uVar2 = 1;
LAB_00024d94:
    uVar2 = uVar2 * 0x2c;
  }
  else {
    uVar2 = iVar1 * 0x745d1746;
    if ((uVar5 < uVar2 || uVar5 == 0) && (uVar2 < 0x5d1745e)) {
      if (uVar2 == 0) {
        __dest = (void *)0x0;
        iVar1 = 0;
        __n = sVar7;
        goto LAB_00024d38;
      }
      goto LAB_00024d94;
    }
    uVar2 = 0xfffffffc;
  }
  __dest = operator_new(uVar2);
  __src = *(void **)this;
  iVar1 = uVar2 + (int)__dest;
  pvVar9 = *(void **)(this + 4);
  __n = (int)param_2 - (int)__src;
LAB_00024d38:
  puVar8 = (undefined4 *)((int)__dest + sVar7);
  if (puVar8 != (undefined4 *)0x0) {
    uVar3 = param_3[1];
    uVar4 = param_3[2];
    uVar6 = param_3[3];
    *puVar8 = *param_3;
    puVar8[1] = uVar3;
    puVar8[2] = uVar4;
    puVar8[3] = uVar6;
    uVar3 = param_3[5];
    uVar4 = param_3[6];
    uVar6 = param_3[7];
    puVar8[4] = param_3[4];
    puVar8[5] = uVar3;
    puVar8[6] = uVar4;
    puVar8[7] = uVar6;
    uVar3 = param_3[9];
    uVar4 = param_3[10];
    puVar8[8] = param_3[8];
    puVar8[9] = uVar3;
    puVar8[10] = uVar4;
  }
  if (param_2 != __src) {
    memmove(__dest,__src,__n);
  }
  __dest_00 = (void *)(__n + 0x2c + (int)__dest);
  if (pvVar9 != param_2) {
    memcpy(__dest_00,param_2,(int)pvVar9 - (int)param_2);
  }
  if (__src != (void *)0x0) {
    operator_delete(__src);
  }
  *(void **)this = __dest;
  *(int *)(this + 4) = (int)__dest_00 + ((int)pvVar9 - (int)param_2);
  *(int *)(this + 8) = iVar1;
  return;
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* handpose_process_new(handpose_t*, nn_campan_hands_t*, ax_yuv_t*, int, int, int) */

void handpose_process_new
               (handpose_t *param_1,nn_campan_hands_t *param_2,ax_yuv_t *param_3,int param_4,
               int param_5,int param_6)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  vector *pvVar6;
  int iVar7;
  int extraout_r1;
  undefined4 uVar8;
  uint uVar9;
  double *pdVar10;
  int *piVar11;
  int *piVar12;
  undefined4 uVar13;
  uint uVar14;
  undefined8 *puVar15;
  float *pfVar16;
  int iVar17;
  void *pvVar18;
  undefined4 uVar19;
  int iVar20;
  int *piVar21;
  ax_tensor_t *paVar22;
  ax_tensor_t *paVar23;
  undefined4 *puVar24;
  size_t __n;
  ax_tensor_t *paVar25;
  undefined4 *puVar26;
  int iVar27;
  int *piVar28;
  void *pvVar29;
  uint uVar30;
  void *pvVar31;
  int *piVar32;
  void *pvVar33;
  int iVar34;
  uint uVar35;
  uint uVar36;
  float fVar37;
  float fVar38;
  double dVar39;
  double dVar40;
  uint local_208;
  int local_200;
  uint local_1ec;
  void *local_1cc;
  uint *local_1c8;
  uint *local_1c4;
  double *local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  void *local_1b4;
  undefined4 uStack_1b0;
  undefined4 local_1ac;
  double local_1a8 [2];
  void *local_198;
  undefined4 *local_194;
  undefined4 *local_190;
  int local_18c;
  int *local_188;
  int *local_184;
  undefined4 local_180;
  void *local_17c;
  void *local_178;
  undefined4 uStack_174;
  int *local_170;
  int *local_16c;
  undefined4 local_168;
  void *local_164;
  void *local_160;
  undefined4 uStack_15c;
  void *local_158;
  undefined4 uStack_154;
  undefined4 local_150;
  void *local_14c;
  undefined4 local_148;
  undefined4 uStack_144;
  undefined4 local_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 local_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 local_120;
  undefined4 local_11c;
  void *local_118;
  int local_114;
  int local_110;
  void *local_10c;
  undefined4 uStack_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 local_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  int local_c0;
  int iStack_bc;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined8 uStack_60;
  
  local_208 = *(uint *)(param_2 + 4);
  local_140 = *(undefined4 *)param_3;
  uStack_13c = *(undefined4 *)(param_3 + 4);
  uStack_138 = *(undefined4 *)(param_3 + 8);
  uStack_134 = *(undefined4 *)(param_3 + 0xc);
  local_130 = *(undefined4 *)(param_3 + 0x10);
  uStack_12c = *(undefined4 *)(param_3 + 0x14);
  uStack_128 = *(undefined4 *)(param_3 + 0x18);
  uStack_124 = *(undefined4 *)(param_3 + 0x1c);
  local_120 = *(undefined4 *)(param_3 + 0x20);
  local_158 = (void *)0x0;
  uStack_154 = 0;
  local_150 = 0;
  local_14c = (void *)0x0;
  local_148 = 0;
  uStack_144 = 0;
  local_11c = 0;
  local_1cc = (void *)0x0;
  local_1c8 = (uint *)0x0;
  local_1c4 = (uint *)0x0;
  if (param_6 != 0) {
    local_198 = (void *)0x0;
    local_d8 = local_d8 & 0xffffffff00000000;
    local_194 = (undefined4 *)0x0;
    local_190 = (undefined4 *)0x0;
    local_188 = (int *)0x0;
    local_184 = (int *)0x0;
    local_180 = 0;
    std::vector<int,std::allocator<int>>::_M_fill_assign
              ((vector<int,std::allocator<int>> *)&local_188,local_208,(int *)&local_d8);
    local_208 = *(uint *)(param_2 + 4);
    if (1 < (int)local_208) {
      if (local_188 == local_184) {
        uVar9 = 0;
      }
      else {
        local_1ec = 0;
        do {
          iVar20 = local_1ec * 4;
          uVar9 = local_1ec + 1;
          if (*(int *)((int)local_188 + iVar20) == 0) {
            iVar7 = *(int *)param_2 + uVar9 * 0x2c + -0x2c;
            local_170 = *(int **)(iVar7 + 4);
            local_16c = *(int **)(iVar7 + 8);
            local_168 = *(undefined4 *)(iVar7 + 0xc);
            local_164 = *(void **)(iVar7 + 0x10);
            if ((int)uVar9 < (int)local_208) {
              uVar35 = uVar9;
              iVar5 = iVar20;
              if ((uint)((int)local_184 - (int)local_188 >> 2) <= uVar9) {
LAB_00025698:
                    /* WARNING: Subroutine does not return */
                std::__throw_out_of_range_fmt
                          ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)"
                           ,uVar35);
              }
              while( true ) {
                iVar5 = iVar5 + 4;
                if (*(int *)((int)local_188 + iVar5) == 0) {
                  iVar17 = uVar35 * 0x2c + *(int *)param_2;
                  pvVar31 = *(void **)(iVar17 + 4);
                  iVar27 = *(int *)(iVar17 + 8);
                  iVar34 = *(int *)(iVar17 + 0xc);
                  pvVar33 = *(void **)(iVar17 + 0x10);
                  local_118 = pvVar31;
                  local_114 = iVar27;
                  local_110 = iVar34;
                  local_10c = pvVar33;
                  fVar38 = iou<ax_box_t>(local_170,local_16c,local_168,local_164,pvVar31,iVar27,
                                         iVar34,pvVar33);
                  if (fVar38 != 0.0 && fVar38 < 0.0 == NAN(fVar38)) {
                    pvVar18 = *(void **)(iVar7 + 4);
                    if ((int)pvVar31 <= (int)*(void **)(iVar7 + 4)) {
                      pvVar18 = pvVar31;
                    }
                    local_d8 = CONCAT44(pvVar18,0xffffffff);
                    local_c0 = *(int *)(iVar7 + 8);
                    if (iVar27 <= *(int *)(iVar7 + 8)) {
                      local_c0 = iVar27;
                    }
                    iStack_bc = *(int *)(iVar7 + 0xc);
                    if (*(int *)(iVar7 + 0xc) < iVar34) {
                      iStack_bc = iVar34;
                    }
                    local_d0 = CONCAT44(iStack_bc,local_c0);
                    pvVar31 = *(void **)(iVar7 + 0x10);
                    if ((int)*(void **)(iVar7 + 0x10) < (int)pvVar33) {
                      pvVar31 = pvVar33;
                    }
                    local_c8 = CONCAT44(pvVar18,pvVar31);
                    local_b8 = CONCAT44(local_b8._4_4_,pvVar31);
                    if (local_194 == local_190) {
                      std::vector<nn_campan_hand_t,std::allocator<nn_campan_hand_t>>::
                      _M_realloc_insert<nn_campan_hand_t_const&>
                                ((vector<nn_campan_hand_t,std::allocator<nn_campan_hand_t>> *)
                                 &local_198,local_194,&local_d8);
                    }
                    else {
                      if (local_194 != (undefined4 *)0x0) {
                        *local_194 = 0xffffffff;
                        local_194[1] = pvVar18;
                        local_194[2] = local_c0;
                        local_194[3] = iStack_bc;
                        local_194[4] = pvVar31;
                        local_194[5] = pvVar18;
                        local_194[6] = local_c0;
                        local_194[7] = iStack_bc;
                        local_194[8] = pvVar31;
                        local_194[9] = local_b8._4_4_;
                        local_194[10] = (undefined4)local_b0;
                      }
                      local_194 = local_194 + 0xb;
                    }
                    uVar4 = (int)local_184 - (int)local_188 >> 2;
                    if (uVar4 <= local_1ec) {
                    /* WARNING: Subroutine does not return */
                      std::__throw_out_of_range_fmt
                                (
                                "vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)"
                                );
                    }
                    *(undefined4 *)((int)local_188 + iVar20) = 1;
                    if (uVar4 <= uVar35) {
                    /* WARNING: Subroutine does not return */
                      std::__throw_out_of_range_fmt
                                ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)"
                                 ,uVar35);
                    }
                    *(undefined4 *)((int)local_188 + iVar5) = 1;
                    local_208 = *(uint *)(param_2 + 4);
                  }
                }
                uVar35 = uVar35 + 1;
                if ((int)local_208 <= (int)uVar35) break;
                if ((uint)((int)local_184 - (int)local_188 >> 2) <= uVar35) goto LAB_00025698;
              }
            }
          }
          if ((int)(local_208 + -1) <= (int)uVar9) goto LAB_000255bc;
          local_1ec = uVar9;
        } while (uVar9 < (uint)((int)local_184 - (int)local_188 >> 2));
      }
                    /* WARNING: Subroutine does not return */
      std::__throw_out_of_range_fmt
                ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",uVar9);
    }
LAB_000255bc:
    if (0 < (int)local_194 - (int)local_198) {
      pvVar31 = *(void **)param_2;
      iVar20 = local_208 + 1;
      iVar7 = iVar20 * 0x2c;
      uVar35 = 0;
      uVar9 = local_208;
      local_208 = iVar20 * 0x58;
      do {
        puVar24 = (undefined4 *)(uVar35 * 0x2c + (int)local_198);
        if (pvVar31 == (void *)0x0) {
          if (0 < iVar7) {
            __n = 0;
LAB_000255f8:
            pvVar31 = (void *)AX_MALLOC_RECORD(local_208);
            if (*(void **)param_2 != (void *)0x0) {
              memcpy(pvVar31,*(void **)param_2,__n);
              AX_FREE_RECORD(*(void **)param_2);
            }
            uVar9 = *(uint *)(param_2 + 4);
            *(void **)param_2 = pvVar31;
          }
        }
        else {
          __n = *(size_t *)((int)pvVar31 + -4);
          if ((int)__n < iVar7) goto LAB_000255f8;
        }
        uVar35 = uVar35 + 1;
        puVar26 = (undefined4 *)(uVar9 * 0x2c + (int)pvVar31);
        uVar8 = puVar24[1];
        uVar13 = puVar24[2];
        uVar19 = puVar24[3];
        *puVar26 = *puVar24;
        puVar26[1] = uVar8;
        puVar26[2] = uVar13;
        puVar26[3] = uVar19;
        uVar8 = puVar24[5];
        uVar13 = puVar24[6];
        uVar19 = puVar24[7];
        puVar26[4] = puVar24[4];
        puVar26[5] = uVar8;
        puVar26[6] = uVar13;
        puVar26[7] = uVar19;
        uVar8 = puVar24[9];
        uVar13 = puVar24[10];
        uVar9 = ((int)local_194 - (int)local_198 >> 2) * -0x45d1745d;
        puVar26[8] = puVar24[8];
        puVar26[9] = uVar8;
        puVar26[10] = uVar13;
        *(int *)(param_2 + 4) = iVar20;
        if ((int)uVar9 <= (int)uVar35) break;
        iVar7 = iVar7 + 0x2c;
        local_208 = local_208 + 0x58;
        if (uVar9 <= uVar35) {
                    /* WARNING: Subroutine does not return */
          std::__throw_out_of_range_fmt
                    ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                     uVar35,uVar9);
        }
        uVar9 = iVar20;
        iVar20 = iVar20 + 1;
      } while( true );
    }
    if (local_188 != (int *)0x0) {
      operator_delete(local_188);
    }
    if (local_198 != (void *)0x0) {
      operator_delete(local_198);
    }
    local_208 = *(uint *)(param_2 + 4);
  }
  if (0 < (int)local_208) {
    iVar20 = 0;
    do {
      while( true ) {
        iVar7 = iVar20 * 0x2c + *(int *)param_2;
        uVar36 = *(int *)(param_3 + 0x1c) - 1;
        uVar9 = *(uint *)(iVar7 + 8);
        uVar35 = *(uint *)(iVar7 + 4);
        uVar30 = *(int *)(param_3 + 0x18) - 1;
        uVar14 = (*(int *)(iVar7 + 0xc) - *(int *)(iVar7 + 4)) + uVar35;
        uVar4 = (*(int *)(iVar7 + 0x10) - *(int *)(iVar7 + 8)) + uVar9;
        uVar9 = uVar9 & ~((int)uVar9 >> 0x1f);
        uVar35 = uVar35 & ~((int)uVar35 >> 0x1f);
        if ((int)uVar36 <= (int)uVar9) {
          uVar9 = uVar36;
        }
        if ((int)uVar30 <= (int)uVar35) {
          uVar35 = uVar30;
        }
        uVar14 = uVar14 & ~((int)uVar14 >> 0x1f);
        uVar4 = uVar4 & ~((int)uVar4 >> 0x1f);
        if ((int)uVar30 < (int)uVar14) {
          iVar7 = uVar30 - uVar35;
        }
        else {
          iVar7 = uVar14 - uVar35;
        }
        if ((int)uVar36 < (int)uVar4) {
          iVar5 = uVar36 - uVar9;
        }
        else {
          iVar5 = uVar4 - uVar9;
        }
        local_d0 = CONCAT44(iVar5 + 1U,iVar7 + 1U);
        local_d8 = CONCAT44(uVar9,uVar35);
        if (local_1c8 != local_1c4) break;
        std::vector<ax_rect_t,std::allocator<ax_rect_t>>::_M_realloc_insert<ax_rect_t_const&>
                  ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&local_1cc,local_1c8,&local_d8);
        iVar20 = iVar20 + 1;
        local_208 = *(uint *)(param_2 + 4);
        if ((int)local_208 <= iVar20) goto LAB_00024ece;
      }
      if (local_1c8 != (uint *)0x0) {
        *local_1c8 = uVar35;
        local_1c8[1] = uVar9;
        local_1c8[2] = iVar7 + 1U;
        local_1c8[3] = iVar5 + 1U;
      }
      local_1c8 = local_1c8 + 4;
      iVar20 = iVar20 + 1;
    } while (iVar20 < (int)local_208);
  }
LAB_00024ece:
  std::vector<ax_rect_t,std::allocator<ax_rect_t>>::operator=
            ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&local_158,(vector *)&local_1cc);
  local_188 = (int *)0x0;
  local_184 = (int *)0x0;
  local_180 = 0;
  local_17c = (void *)0x0;
  local_178 = (void *)0x0;
  uStack_174 = 0;
  batch_classify_process
            (*(batch_classify_model_t **)param_1,(classify_in_t *)&local_158,
             (classify_out_t *)&local_188,0);
  DAT_0003a680 = DAT_0003a680 + 1;
  if (0 < (int)local_184 - (int)local_188) {
    pvVar6 = (vector *)*local_188;
    piVar21 = *(int **)param_2;
    if ((vector *)local_188[1] != pvVar6) {
      uVar9 = 0;
      do {
        local_1c0 = (double *)0x0;
        local_1bc = 0;
        local_1b8 = 0;
        softmax(pvVar6,(vector *)&local_1c0,0xf);
        iVar5 = 1;
        iVar7 = 0;
        dVar40 = *local_1c0;
        iVar20 = extraout_r1;
        pdVar10 = local_1c0;
        do {
          pdVar10 = pdVar10 + 1;
          dVar39 = *pdVar10;
          bVar1 = dVar39 < dVar40;
          bVar2 = dVar39 == dVar40;
          bVar3 = NAN(dVar40);
          if (!bVar2 && bVar1 == (NAN(dVar39) || bVar3)) {
            iVar20 = iVar5;
            dVar40 = dVar39;
          }
          iVar5 = iVar5 + 1;
          if (bVar2 || bVar1 != (NAN(dVar39) || bVar3)) {
            iVar20 = iVar7;
          }
          iVar7 = iVar20;
          iVar20 = iVar7;
        } while (iVar5 != 0xf);
        puVar15 = &local_d8;
        do {
          *puVar15 = 0x3fecccccc0000000;
          puVar15 = puVar15 + 1;
        } while (&uStack_60 != puVar15);
        local_80 = 0x40000000;
        uStack_7c = 0x3fe33333;
        local_d8 = 0x3fe6666660000000;
        local_d0 = 0x3fec28f5c0000000;
        local_c8 = 0x3fed70a3e0000000;
        local_b8 = 0x3fecccccc0000000;
        local_b0 = 0x3fecccccc0000000;
        local_a0 = 0x3fecccccc0000000;
        local_98 = 0x3fecccccc0000000;
        local_90 = 0x3fed70a3e0000000;
        local_88 = 0x3fecccccc0000000;
        local_c0 = -0x60000000;
        iStack_bc = 0x3fe99999;
        local_a8 = 0x40000000;
        uStack_a4 = 0x3feb3333;
        if ((int)((uint)((double)(&local_d8)[iVar7] < dVar40) << 0x1f) < 0) {
          piVar21[9] = iVar7;
          if (*piVar21 == -1) {
            if (iVar7 != 0xb) {
              piVar21[9] = 0;
            }
          }
          else if (iVar7 == 0xb) {
            if ((int)((uint)(dVar40 < 0.85) << 0x1f) < 0) {
              piVar21[9] = 0;
              goto LAB_0002500a;
            }
          }
          else if ((param_4 != 0) && (iVar7 == 0)) goto LAB_000250c2;
        }
        else {
          piVar21[9] = 0;
          if (*piVar21 == -1) {
            piVar21[9] = 0;
          }
          else {
LAB_0002500a:
            if (param_4 != 0) {
LAB_000250c2:
              iVar20 = handpose_process_old(param_1,piVar21 + 1,param_3);
              piVar21[9] = iVar20;
            }
          }
        }
        if (((param_5 != 0) && (piVar21[9] == 9)) && (*piVar21 != -1)) {
          iVar20 = handpose_process_two_cls(param_1,piVar21 + 1,param_3);
          piVar21[9] = iVar20;
        }
        iVar20 = *(int *)(param_1 + 0xc);
        piVar21[10] = 0;
        if (((iVar20 != 0) && (*piVar21 != -1)) && (piVar21[9] == 1)) {
          local_118 = (void *)0x0;
          local_114 = 0;
          local_110 = 0;
          local_100 = *(undefined4 *)param_3;
          uStack_fc = *(undefined4 *)(param_3 + 4);
          uStack_f8 = *(undefined4 *)(param_3 + 8);
          uStack_f4 = *(undefined4 *)(param_3 + 0xc);
          local_10c = (void *)0x0;
          uStack_108 = 0;
          local_104 = 0;
          local_f0 = *(undefined4 *)(param_3 + 0x10);
          uStack_ec = *(undefined4 *)(param_3 + 0x14);
          uStack_e8 = *(undefined4 *)(param_3 + 0x18);
          uStack_e4 = *(undefined4 *)(param_3 + 0x1c);
          local_dc = 0;
          local_e0 = *(undefined4 *)(param_3 + 0x20);
          pvVar31 = (void *)(*(int *)(param_3 + 0x18) - 1);
          local_198 = (void *)(piVar21[1] & ~(piVar21[1] >> 0x1f));
          local_194 = (undefined4 *)(piVar21[2] & ~(piVar21[2] >> 0x1f));
          puVar24 = (undefined4 *)(*(int *)(param_3 + 0x1c) + -1);
          local_1b4 = (void *)0x0;
          uStack_1b0 = 0;
          local_1ac = 0;
          if ((int)pvVar31 <= (int)local_198) {
            local_198 = pvVar31;
          }
          if ((int)puVar24 <= (int)local_194) {
            local_194 = puVar24;
          }
          uVar35 = piVar21[3] & ~(piVar21[3] >> 0x1f);
          uVar4 = piVar21[4] & ~(piVar21[4] >> 0x1f);
          if ((int)pvVar31 < (int)uVar35) {
            iVar20 = (int)pvVar31 - (int)local_198;
          }
          else {
            iVar20 = uVar35 - (int)local_198;
          }
          if ((int)puVar24 < (int)uVar4) {
            local_18c = (int)puVar24 - (int)local_194;
          }
          else {
            local_18c = uVar4 - (int)local_194;
          }
          local_190 = (undefined4 *)(iVar20 + 1);
          local_18c = local_18c + 1;
          std::vector<ax_rect_t,std::allocator<ax_rect_t>>::_M_realloc_insert<ax_rect_t_const&>
                    ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&local_1b4,0,&local_198);
          std::vector<ax_rect_t,std::allocator<ax_rect_t>>::operator=
                    ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&local_118,(vector *)&local_1b4)
          ;
          local_170 = (int *)0x0;
          local_16c = (int *)0x0;
          local_168 = 0;
          local_164 = (void *)0x0;
          local_160 = (void *)0x0;
          uStack_15c = 0;
          batch_classify_process
                    (*(batch_classify_model_t **)(param_1 + 0xc),(classify_in_t *)&local_118,
                     (classify_out_t *)&local_170,0);
          if (local_16c == local_170) {
                    /* WARNING: Subroutine does not return */
            std::__throw_out_of_range_fmt
                      ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0
                       ,0);
          }
          piVar11 = (int *)*local_170;
          if ((int *)local_170[1] == piVar11) {
                    /* WARNING: Subroutine does not return */
            std::__throw_out_of_range_fmt
                      ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0
                      );
          }
          pfVar16 = (float *)*piVar11;
          if ((uint)(piVar11[1] - (int)pfVar16 >> 2) < 2) {
                    /* WARNING: Subroutine does not return */
            std::__throw_out_of_range_fmt
                      ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",1
                      );
          }
          fVar37 = *pfVar16;
          fVar38 = pfVar16[1];
          bVar1 = fVar38 != fVar37;
          bVar2 = fVar38 < fVar37 == (NAN(fVar38) || NAN(fVar37));
          if (!bVar1 || !bVar2) {
            fVar38 = fVar37;
          }
          uVar35 = (uint)(bVar1 && bVar2);
          fVar38 = expf(-fVar38);
          pvVar31 = local_160;
          local_1a8[0] = 0.5;
          local_1a8[1] = 0.5;
          dVar39 = local_1a8[uVar35];
          dVar40 = (double)(1.0 / (fVar38 + 1.0));
          local_200 = 1;
          if (dVar40 != dVar39 && dVar40 < dVar39 == (NAN(dVar40) || NAN(dVar39))) {
            local_200 = uVar35 + 1;
          }
          pvVar33 = local_160;
          if (local_164 != local_160) {
            pvVar29 = (void *)((int)local_164 + 0xc);
            pvVar33 = local_164;
            pvVar18 = pvVar29;
            while( true ) {
              paVar25 = *(ax_tensor_t **)((int)pvVar33 + 4);
              paVar22 = *(ax_tensor_t **)((int)pvVar29 + -0xc);
              if (*(ax_tensor_t **)((int)pvVar29 + -0xc) != paVar25) {
                do {
                  paVar23 = paVar22 + 0x30;
                  ax_tensor_t::~ax_tensor_t(paVar22);
                  paVar22 = paVar23;
                } while (paVar25 != paVar23);
                paVar25 = *(ax_tensor_t **)((int)pvVar29 + -0xc);
              }
              if (paVar25 != (ax_tensor_t *)0x0) {
                operator_delete(paVar25);
              }
              pvVar29 = (void *)((int)pvVar29 + 0xc);
              pvVar33 = local_164;
              if (pvVar31 == pvVar18) break;
              pvVar33 = pvVar18;
              pvVar18 = (void *)((int)pvVar18 + 0xc);
            }
          }
          if (pvVar33 != (void *)0x0) {
            operator_delete(pvVar33);
          }
          piVar11 = local_16c;
          piVar12 = local_16c;
          if (local_170 != local_16c) {
            piVar32 = local_170 + 3;
            piVar12 = local_170;
            piVar28 = piVar32;
            while( true ) {
              puVar24 = (undefined4 *)piVar12[1];
              puVar26 = (undefined4 *)piVar32[-3];
              if (puVar26 != puVar24) {
                do {
                  if ((void *)*puVar26 != (void *)0x0) {
                    operator_delete((void *)*puVar26);
                  }
                  puVar26 = puVar26 + 3;
                } while (puVar24 != puVar26);
                puVar24 = (undefined4 *)piVar32[-3];
              }
              if (puVar24 != (undefined4 *)0x0) {
                operator_delete(puVar24);
              }
              piVar32 = piVar32 + 3;
              piVar12 = local_170;
              if (piVar11 == piVar28) break;
              piVar12 = piVar28;
              piVar28 = piVar28 + 3;
            }
          }
          if (piVar12 != (int *)0x0) {
            operator_delete(piVar12);
          }
          if (local_1b4 != (void *)0x0) {
            operator_delete(local_1b4);
          }
          if (local_10c != (void *)0x0) {
            operator_delete(local_10c);
          }
          if (local_118 != (void *)0x0) {
            operator_delete(local_118);
          }
          piVar21[10] = local_200;
        }
        if (local_1c0 != (double *)0x0) {
          operator_delete(local_1c0);
        }
        uVar9 = uVar9 + 1;
        uVar35 = ((int)local_184 - (int)local_188 >> 2) * -0x55555555;
        if ((int)uVar35 <= (int)uVar9) goto LAB_0002532a;
        piVar21 = (int *)(uVar9 * 0x2c + *(int *)param_2);
        if (uVar35 <= uVar9) {
                    /* WARNING: Subroutine does not return */
          std::__throw_out_of_range_fmt
                    ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",
                     uVar9);
        }
        pvVar6 = (vector *)local_188[uVar9 * 3];
      } while ((vector *)local_188[uVar9 * 3 + 1] != pvVar6);
    }
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0);
  }
LAB_0002532a:
  pvVar31 = local_178;
  pvVar33 = local_178;
  if (local_17c != local_178) {
    pvVar29 = (void *)((int)local_17c + 0xc);
    pvVar33 = local_17c;
    pvVar18 = pvVar29;
    while( true ) {
      paVar25 = *(ax_tensor_t **)((int)pvVar33 + 4);
      paVar22 = *(ax_tensor_t **)((int)pvVar29 + -0xc);
      if (*(ax_tensor_t **)((int)pvVar29 + -0xc) != paVar25) {
        do {
          paVar23 = paVar22 + 0x30;
          ax_tensor_t::~ax_tensor_t(paVar22);
          paVar22 = paVar23;
        } while (paVar25 != paVar23);
        paVar25 = *(ax_tensor_t **)((int)pvVar29 + -0xc);
      }
      if (paVar25 != (ax_tensor_t *)0x0) {
        operator_delete(paVar25);
      }
      pvVar29 = (void *)((int)pvVar29 + 0xc);
      pvVar33 = local_17c;
      if (pvVar31 == pvVar18) break;
      pvVar33 = pvVar18;
      pvVar18 = (void *)((int)pvVar18 + 0xc);
    }
  }
  if (pvVar33 != (void *)0x0) {
    operator_delete(pvVar33);
  }
  piVar21 = local_184;
  piVar11 = local_184;
  if (local_188 != local_184) {
    piVar28 = local_188 + 3;
    piVar11 = local_188;
    piVar12 = piVar28;
    while( true ) {
      puVar26 = (undefined4 *)piVar11[1];
      puVar24 = (undefined4 *)piVar28[-3];
      if (puVar24 != puVar26) {
        do {
          if ((void *)*puVar24 != (void *)0x0) {
            operator_delete((void *)*puVar24);
          }
          puVar24 = puVar24 + 3;
        } while (puVar26 != puVar24);
        puVar26 = (undefined4 *)piVar28[-3];
      }
      if (puVar26 != (undefined4 *)0x0) {
        operator_delete(puVar26);
      }
      piVar28 = piVar28 + 3;
      piVar11 = local_188;
      if (piVar21 == piVar12) break;
      piVar11 = piVar12;
      piVar12 = piVar12 + 3;
    }
  }
  if (piVar11 != (int *)0x0) {
    operator_delete(piVar11);
  }
  if (local_1cc != (void *)0x0) {
    operator_delete(local_1cc);
  }
  if (local_14c != (void *)0x0) {
    operator_delete(local_14c);
  }
  if (local_158 != (void *)0x0) {
    operator_delete(local_158);
  }
  return;
}



/* std::_Rb_tree<int, std::pair<int const, match_table_t>, std::_Select1st<std::pair<int const,
   match_table_t> >, std::less<int>, std::allocator<std::pair<int const, match_table_t> >
   >::_M_erase(std::_Rb_tree_node<std::pair<int const, match_table_t> >*) */

void __thiscall
std::
_Rb_tree<int,std::pair<int_const,match_table_t>,std::_Select1st<std::pair<int_const,match_table_t>>,std::less<int>,std::allocator<std::pair<int_const,match_table_t>>>
::_M_erase(_Rb_tree<int,std::pair<int_const,match_table_t>,std::_Select1st<std::pair<int_const,match_table_t>>,std::less<int>,std::allocator<std::pair<int_const,match_table_t>>>
           *this,_Rb_tree_node *param_1)

{
  _Rb_tree_node *p_Var1;
  
  if (param_1 == (_Rb_tree_node *)0x0) {
    return;
  }
  do {
    _M_erase(this,*(_Rb_tree_node **)(param_1 + 0xc));
    p_Var1 = *(_Rb_tree_node **)(param_1 + 8);
    operator_delete(param_1);
    param_1 = p_Var1;
  } while (p_Var1 != (_Rb_tree_node *)0x0);
  return;
}



/* std::__cxx11::_List_base<neg_face_head_t, std::allocator<neg_face_head_t> >::_M_clear() */

void __thiscall
std::__cxx11::_List_base<neg_face_head_t,std::allocator<neg_face_head_t>>::_M_clear
          (_List_base<neg_face_head_t,std::allocator<neg_face_head_t>> *this)

{
  _List_base<neg_face_head_t,std::allocator<neg_face_head_t>> *p_Var1;
  _List_base<neg_face_head_t,std::allocator<neg_face_head_t>> *p_Var2;
  _List_base<neg_face_head_t,std::allocator<neg_face_head_t>> *p_Var3;
  _List_base<neg_face_head_t,std::allocator<neg_face_head_t>> *p_Var4;
  
  p_Var2 = *(_List_base<neg_face_head_t,std::allocator<neg_face_head_t>> **)this;
  while (p_Var2 != this) {
    p_Var4 = *(_List_base<neg_face_head_t,std::allocator<neg_face_head_t>> **)p_Var2;
    p_Var1 = *(_List_base<neg_face_head_t,std::allocator<neg_face_head_t>> **)(p_Var2 + 8);
    while (p_Var1 != p_Var2 + 8) {
      p_Var3 = *(_List_base<neg_face_head_t,std::allocator<neg_face_head_t>> **)p_Var1;
      operator_delete(p_Var1);
      p_Var1 = p_Var3;
    }
    operator_delete(p_Var2);
    p_Var2 = p_Var4;
  }
  return;
}



/* clear_tracking_features_buffer(campan_feature_match_t*) */

void clear_tracking_features_buffer(campan_feature_match_t *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  _List_base<neg_face_head_t,std::allocator<neg_face_head_t>> *this;
  undefined4 *puVar3;
  campan_feature_match_t *pcVar4;
  campan_feature_match_t *pcVar5;
  
  __android_log_print(6,"CAMPAN_ATTR","clear register buffer");
  pcVar5 = param_1 + 0x500;
  do {
    pcVar4 = pcVar5 + 4;
    puVar2 = *(undefined4 **)pcVar5;
    puVar1 = (undefined4 *)*puVar2;
    while (puVar1 != puVar2) {
      puVar3 = (undefined4 *)*puVar1;
      operator_delete(puVar1);
      puVar1 = puVar3;
    }
    *puVar2 = puVar2;
    puVar2[1] = puVar2;
    puVar2[2] = 0;
    pcVar5 = pcVar4;
  } while (param_1 + 0x50c != pcVar4);
  this = *(_List_base<neg_face_head_t,std::allocator<neg_face_head_t>> **)(param_1 + 0x2c8);
  std::__cxx11::_List_base<neg_face_head_t,std::allocator<neg_face_head_t>>::_M_clear(this);
  *(undefined4 *)(this + 8) = 0;
  *(_List_base<neg_face_head_t,std::allocator<neg_face_head_t>> **)this = this;
  *(_List_base<neg_face_head_t,std::allocator<neg_face_head_t>> **)(this + 4) = this;
  return;
}



/* campan_set_tracking_person_head(campan_feature_match_t*, nn_campan_person_head_t*) */

void campan_set_tracking_person_head
               (campan_feature_match_t *param_1,nn_campan_person_head_t *param_2)

{
  int *piVar1;
  _List_node_base *p_Var2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int *piVar8;
  undefined8 uVar9;
  double dVar10;
  
  __android_log_print(6,"CAMPAN_ATTR","set tracking person head");
  FUN_000202a0(param_2);
  pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0x318));
  memcpy(param_1,param_2 + 0x40,0x2a8);
  *(undefined4 *)(param_1 + 0x300) = *(undefined4 *)(param_2 + 0x40);
  *(undefined4 *)(param_1 + 0x304) = 0;
  uVar9 = get_time_ms();
  *(undefined8 *)(param_1 + 0x310) = uVar9;
  uVar3 = *(undefined4 *)(param_2 + 4);
  uVar4 = *(undefined4 *)(param_2 + 8);
  uVar6 = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0x330) = *(undefined4 *)param_2;
  *(undefined4 *)(param_1 + 0x334) = uVar3;
  *(undefined4 *)(param_1 + 0x338) = uVar4;
  *(undefined4 *)(param_1 + 0x33c) = uVar6;
  uVar3 = *(undefined4 *)(param_2 + 0x14);
  uVar4 = *(undefined4 *)(param_2 + 0x18);
  uVar6 = *(undefined4 *)(param_2 + 0x1c);
  *(undefined4 *)(param_1 + 0x340) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(param_1 + 0x344) = uVar3;
  *(undefined4 *)(param_1 + 0x348) = uVar4;
  *(undefined4 *)(param_1 + 0x34c) = uVar6;
  uVar3 = *(undefined4 *)(param_2 + 0x24);
  uVar4 = *(undefined4 *)(param_2 + 0x28);
  uVar6 = *(undefined4 *)(param_2 + 0x2c);
  *(undefined4 *)(param_1 + 0x350) = *(undefined4 *)(param_2 + 0x20);
  *(undefined4 *)(param_1 + 0x354) = uVar3;
  *(undefined4 *)(param_1 + 0x358) = uVar4;
  *(undefined4 *)(param_1 + 0x35c) = uVar6;
  uVar3 = *(undefined4 *)(param_2 + 0x34);
  uVar4 = *(undefined4 *)(param_2 + 0x38);
  *(undefined4 *)(param_1 + 0x360) = *(undefined4 *)(param_2 + 0x30);
  *(undefined4 *)(param_1 + 0x364) = uVar3;
  *(undefined4 *)(param_1 + 0x368) = uVar4;
  *(undefined4 *)(param_1 + 0x370) = 0xffffffff;
  clear_tracking_person_buffer(param_1);
  clear_tracking_features_buffer(param_1);
  piVar7 = *(int **)(param_1 + 0xac0);
  piVar8 = (int *)*piVar7;
  if (piVar8 == piVar7) {
LAB_000258c8:
    p_Var2 = (_List_node_base *)operator_new(0xc);
    *(undefined4 *)(p_Var2 + 8) = *(undefined4 *)param_2;
    std::__detail::_List_node_base::_M_hook(p_Var2);
    piVar7[2] = piVar7[2] + 1;
    piVar8 = *(int **)(param_1 + 0xab8);
    piVar7 = (int *)*piVar8;
    if (piVar7 != piVar8) {
      do {
        piVar1 = piVar7 + 0x120;
        iVar5 = *(int *)param_2;
        if (*piVar1 == iVar5) {
          piVar7[0x141] = 1;
        }
        piVar7 = (int *)*piVar7;
        if (*piVar1 == iVar5) {
          piVar8 = *(int **)(param_1 + 0xab8);
        }
      } while (piVar8 != piVar7);
    }
    piVar8 = *(int **)(param_1 + 0xabc);
    piVar7 = (int *)*piVar8;
    if (piVar7 != piVar8) {
      do {
        while (piVar7[2] != *(int *)param_2) {
          piVar7 = (int *)*piVar7;
          if (piVar8 == piVar7) goto <EXTERNAL>_pthread_mutex_unlock;
        }
        piVar7[0x2b] = 1;
        dVar10 = (double)get_time_ms();
        piVar7[0x42] = 1;
        *(double *)(piVar7 + 0x40) = dVar10 / 1000.0;
        piVar7 = (int *)*piVar7;
        piVar8 = *(int **)(param_1 + 0xabc);
      } while (piVar8 != piVar7);
    }
  }
  else {
    iVar5 = piVar8[2];
    while (*(int *)param_2 != iVar5) {
      piVar8 = (int *)*piVar8;
      if (piVar8 == piVar7) goto LAB_000258c8;
      iVar5 = piVar8[2];
    }
    __android_log_print(6,"CAMPAN_ATTR","id %d already tracking");
  }
<EXTERNAL>_pthread_mutex_unlock:
  pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0x318));
  return;
}



/* std::__cxx11::_List_base<nn_campan_track_person_t, std::allocator<nn_campan_track_person_t>
   >::_M_clear() */

void __thiscall
std::__cxx11::_List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>>::
_M_clear(_List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>> *this)

{
  _List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>> *p_Var1;
  _List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>> *p_Var2;
  _List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>> *p_Var3;
  _List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>> *p_Var4;
  _List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>> *p_Var5;
  
  p_Var1 = *(_List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>> **)this;
  while (p_Var1 != this) {
    p_Var5 = *(_List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>> **)
              p_Var1;
    p_Var4 = p_Var1 + 0x504;
    do {
      p_Var4 = p_Var4 + -0xc;
      p_Var3 = *(_List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>> **)
                p_Var4;
      while (p_Var4 != p_Var3) {
        p_Var2 = *(_List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>> **)
                  p_Var3;
        operator_delete(p_Var3);
        p_Var3 = p_Var2;
      }
    } while (p_Var1 + 0x4c8 != p_Var4);
    p_Var4 = *(_List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>> **)
              (p_Var1 + 0x4bc);
    while (p_Var4 != p_Var1 + 0x4bc) {
      p_Var3 = *(_List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>> **)
                p_Var4;
      operator_delete(p_Var4);
      p_Var4 = p_Var3;
    }
    p_Var4 = *(_List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>> **)
              (p_Var1 + 0x4b0);
    while (p_Var4 != p_Var1 + 0x4b0) {
      p_Var3 = *(_List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>> **)
                p_Var4;
      operator_delete(p_Var4);
      p_Var4 = p_Var3;
    }
    operator_delete(p_Var1);
    p_Var1 = p_Var5;
  }
  return;
}



/* campan_feature_match_release(campan_feature_match_t*) */

void campan_feature_match_release(campan_feature_match_t *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  _List_base<neg_face_head_t,std::allocator<neg_face_head_t>> *p_Var3;
  _List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>> *this;
  undefined4 *puVar4;
  undefined4 *puVar5;
  _Rb_tree<int,std::pair<int_const,match_table_t>,std::_Select1st<std::pair<int_const,match_table_t>>,std::less<int>,std::allocator<std::pair<int_const,match_table_t>>>
  *p_Var6;
  undefined4 *puVar7;
  campan_feature_match_t *pcVar8;
  campan_feature_match_t *pcVar9;
  undefined4 *puVar10;
  
  if (param_1 != (campan_feature_match_t *)0x0) {
    pcVar9 = param_1 + 0x2a8;
    do {
      pcVar8 = pcVar9 + 4;
      puVar2 = *(undefined4 **)pcVar9;
      if (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
        while (puVar1 != puVar2) {
          puVar7 = (undefined4 *)*puVar1;
          operator_delete(puVar1);
          puVar1 = puVar7;
        }
        operator_delete(puVar2);
      }
      pcVar9 = pcVar8;
    } while (param_1 + 700 != pcVar8);
    puVar2 = *(undefined4 **)(param_1 + 700);
    if (puVar2 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*puVar2;
      while (puVar1 != puVar2) {
        puVar7 = (undefined4 *)*puVar1;
        operator_delete(puVar1);
        puVar1 = puVar7;
      }
      operator_delete(puVar2);
    }
    puVar2 = *(undefined4 **)(param_1 + 0x2c0);
    if (puVar2 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*puVar2;
      while (puVar1 != puVar2) {
        puVar7 = (undefined4 *)*puVar1;
        operator_delete(puVar1);
        puVar1 = puVar7;
      }
      operator_delete(puVar2);
    }
    puVar2 = *(undefined4 **)(param_1 + 0x2c4);
    if (puVar2 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*puVar2;
      while (puVar1 != puVar2) {
        puVar7 = (undefined4 *)*puVar1;
        operator_delete(puVar1);
        puVar1 = puVar7;
      }
      operator_delete(puVar2);
    }
    p_Var3 = *(_List_base<neg_face_head_t,std::allocator<neg_face_head_t>> **)(param_1 + 0x2c8);
    if (p_Var3 != (_List_base<neg_face_head_t,std::allocator<neg_face_head_t>> *)0x0) {
      std::__cxx11::_List_base<neg_face_head_t,std::allocator<neg_face_head_t>>::_M_clear(p_Var3);
      operator_delete(p_Var3);
    }
    p_Var3 = *(_List_base<neg_face_head_t,std::allocator<neg_face_head_t>> **)(param_1 + 0x2cc);
    if (p_Var3 != (_List_base<neg_face_head_t,std::allocator<neg_face_head_t>> *)0x0) {
      std::__cxx11::_List_base<neg_face_head_t,std::allocator<neg_face_head_t>>::_M_clear(p_Var3);
      operator_delete(p_Var3);
    }
    this = *(_List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>> **)
            (param_1 + 0xab8);
    if (this != (_List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>> *)0x0
       ) {
      std::__cxx11::_List_base<nn_campan_track_person_t,std::allocator<nn_campan_track_person_t>>::
      _M_clear(this);
      operator_delete(this);
    }
    puVar2 = *(undefined4 **)(param_1 + 0xac0);
    if (puVar2 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*puVar2;
      while (puVar1 != puVar2) {
        puVar7 = (undefined4 *)*puVar1;
        operator_delete(puVar1);
        puVar1 = puVar7;
      }
      operator_delete(puVar2);
    }
    puVar2 = *(undefined4 **)(param_1 + 0xabc);
    if (puVar2 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*puVar2;
      while (puVar2 != puVar1) {
        puVar7 = puVar1 + 0x2b;
        puVar10 = (undefined4 *)*puVar1;
        do {
          puVar7 = puVar7 + -3;
          puVar5 = (undefined4 *)*puVar7;
          while (puVar7 != puVar5) {
            puVar4 = (undefined4 *)*puVar5;
            operator_delete(puVar5);
            puVar5 = puVar4;
          }
        } while (puVar1 + 0x1c != puVar7);
        puVar7 = (undefined4 *)puVar1[0x19];
        while (puVar7 != puVar1 + 0x19) {
          puVar5 = (undefined4 *)*puVar7;
          operator_delete(puVar7);
          puVar7 = puVar5;
        }
        puVar7 = (undefined4 *)puVar1[0x16];
        while (puVar7 != puVar1 + 0x16) {
          puVar5 = (undefined4 *)*puVar7;
          operator_delete(puVar7);
          puVar7 = puVar5;
        }
        puVar7 = puVar1 + 0x14;
        do {
          puVar7 = puVar7 + -3;
          puVar5 = (undefined4 *)*puVar7;
          while (puVar7 != puVar5) {
            puVar4 = (undefined4 *)*puVar5;
            operator_delete(puVar5);
            puVar5 = puVar4;
          }
        } while (puVar1 + 0xb != puVar7);
        puVar7 = (undefined4 *)puVar1[8];
        while (puVar7 != puVar1 + 8) {
          puVar5 = (undefined4 *)*puVar7;
          operator_delete(puVar7);
          puVar7 = puVar5;
        }
        puVar7 = (undefined4 *)puVar1[5];
        while (puVar7 != puVar1 + 5) {
          puVar5 = (undefined4 *)*puVar7;
          operator_delete(puVar7);
          puVar7 = puVar5;
        }
        operator_delete(puVar1);
        puVar1 = puVar10;
      }
      operator_delete(puVar2);
    }
    pcVar9 = param_1 + 0x500;
    do {
      pcVar8 = pcVar9 + 4;
      puVar2 = *(undefined4 **)pcVar9;
      if (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar2;
        while (puVar2 != puVar1) {
          puVar7 = (undefined4 *)*puVar1;
          operator_delete(puVar1);
          puVar1 = puVar7;
        }
        operator_delete(puVar2);
      }
      pcVar9 = pcVar8;
    } while (param_1 + 0x50c != pcVar8);
    pthread_mutex_destroy((pthread_mutex_t *)(param_1 + 0x318));
    hung_release((hungarian_t *)(param_1 + 0xad8));
    AX_FREE_RECORD(*(void **)(param_1 + 0xb08));
    AX_FREE_RECORD(*(void **)(param_1 + 0xb10));
    AX_FREE_RECORD(*(void **)(param_1 + 0xb18));
    AX_FREE_RECORD(*(void **)(param_1 + 0xb20));
    p_Var6 = *(_Rb_tree<int,std::pair<int_const,match_table_t>,std::_Select1st<std::pair<int_const,match_table_t>>,std::less<int>,std::allocator<std::pair<int_const,match_table_t>>>
               **)(param_1 + 0xb30);
    if (p_Var6 != (_Rb_tree<int,std::pair<int_const,match_table_t>,std::_Select1st<std::pair<int_const,match_table_t>>,std::less<int>,std::allocator<std::pair<int_const,match_table_t>>>
                   *)0x0) {
      std::
      _Rb_tree<int,std::pair<int_const,match_table_t>,std::_Select1st<std::pair<int_const,match_table_t>>,std::less<int>,std::allocator<std::pair<int_const,match_table_t>>>
      ::_M_erase(p_Var6,*(_Rb_tree_node **)(p_Var6 + 8));
      operator_delete(p_Var6);
    }
    p_Var6 = *(_Rb_tree<int,std::pair<int_const,match_table_t>,std::_Select1st<std::pair<int_const,match_table_t>>,std::less<int>,std::allocator<std::pair<int_const,match_table_t>>>
               **)(param_1 + 0xb34);
    if (p_Var6 != (_Rb_tree<int,std::pair<int_const,match_table_t>,std::_Select1st<std::pair<int_const,match_table_t>>,std::less<int>,std::allocator<std::pair<int_const,match_table_t>>>
                   *)0x0) {
      std::
      _Rb_tree<int,std::pair<int_const,match_table_t>,std::_Select1st<std::pair<int_const,match_table_t>>,std::less<int>,std::allocator<std::pair<int_const,match_table_t>>>
      ::_M_erase(p_Var6,*(_Rb_tree_node **)(p_Var6 + 8));
      operator_delete(p_Var6);
    }
    AX_FREE_RECORD(*(void **)(param_1 + 0xb38));
    AX_FREE_RECORD(*(void **)(param_1 + 0xac8));
    AX_FREE_RECORD(*(void **)(param_1 + 0xad0));
    AX_FREE_RECORD(param_1);
    return;
  }
  return;
}



/* std::pair<std::_Rb_tree_iterator<std::pair<int const, match_table_t> >, bool> std::_Rb_tree<int,
   std::pair<int const, match_table_t>, std::_Select1st<std::pair<int const, match_table_t> >,
   std::less<int>, std::allocator<std::pair<int const, match_table_t> >
   >::_M_emplace_unique<std::pair<int, match_table_t> >(std::pair<int, match_table_t>&&) */

pair_conflict *
std::
_Rb_tree<int,std::pair<int_const,match_table_t>,std::_Select1st<std::pair<int_const,match_table_t>>,std::less<int>,std::allocator<std::pair<int_const,match_table_t>>>
::_M_emplace_unique<std::pair<int,match_table_t>>(pair_conflict *param_1)

{
  undefined1 uVar1;
  _Rb_tree_node_base *p_Var2;
  int iVar3;
  _Rb_tree_node_base *p_Var4;
  int in_r1;
  int iVar5;
  int *in_r2;
  int iVar6;
  _Rb_tree_node_base *p_Var7;
  _Rb_tree_node_base *p_Var8;
  int iVar9;
  _Rb_tree_node_base *p_Var10;
  
  p_Var2 = (_Rb_tree_node_base *)operator_new(0x20);
  p_Var7 = *(_Rb_tree_node_base **)(in_r1 + 8);
  iVar9 = *in_r2;
  p_Var10 = (_Rb_tree_node_base *)(in_r1 + 4);
  iVar3 = in_r2[1];
  iVar5 = in_r2[2];
  iVar6 = in_r2[3];
  *(int *)(p_Var2 + 0x10) = iVar9;
  *(int *)(p_Var2 + 0x14) = iVar3;
  *(int *)(p_Var2 + 0x18) = iVar5;
  *(int *)(p_Var2 + 0x1c) = iVar6;
  p_Var8 = p_Var10;
  if (p_Var7 == (_Rb_tree_node_base *)0x0) {
LAB_00025c9e:
    p_Var7 = *(_Rb_tree_node_base **)(in_r1 + 0xc);
    if (p_Var7 == p_Var8) goto LAB_00025cb6;
    p_Var4 = (_Rb_tree_node_base *)std::_Rb_tree_decrement(p_Var8);
    iVar3 = *(int *)(p_Var4 + 0x10);
    p_Var7 = p_Var8;
  }
  else {
    do {
      p_Var4 = p_Var7;
      iVar3 = *(int *)(p_Var4 + 0x10);
      if (iVar9 < iVar3) {
        p_Var7 = *(_Rb_tree_node_base **)(p_Var4 + 8);
      }
      else {
        p_Var7 = *(_Rb_tree_node_base **)(p_Var4 + 0xc);
      }
    } while (p_Var7 != (_Rb_tree_node_base *)0x0);
    p_Var8 = p_Var4;
    p_Var7 = p_Var4;
    if (iVar9 < iVar3) goto LAB_00025c9e;
  }
  if (iVar3 < iVar9) {
    if (p_Var7 != (_Rb_tree_node_base *)0x0) {
LAB_00025cb6:
      if (p_Var10 == p_Var7) {
        uVar1 = true;
      }
      else {
        iVar5 = *(int *)(p_Var7 + 0x10);
        iVar3 = iVar5;
        if (iVar5 <= iVar9) {
          iVar3 = 0;
        }
        uVar1 = (undefined1)iVar3;
        if (iVar9 < iVar5) {
          uVar1 = true;
        }
      }
      std::_Rb_tree_insert_and_rebalance((bool)uVar1,p_Var2,p_Var7,p_Var10);
      iVar3 = *(int *)(in_r1 + 0x14);
      *(_Rb_tree_node_base **)param_1 = p_Var2;
      param_1[4] = (pair_conflict)0x1;
      *(int *)(in_r1 + 0x14) = iVar3 + 1;
      return param_1;
    }
    p_Var4 = (_Rb_tree_node_base *)0x0;
  }
  operator_delete(p_Var2);
  *(_Rb_tree_node_base **)param_1 = p_Var4;
  param_1[4] = (pair_conflict)0x0;
  return param_1;
}



/* head_person_match_filter(campan_feature_match_t*, nn_campan_persons_t*, nn_campan_heads_t*) */

void head_person_match_filter
               (campan_feature_match_t *param_1,nn_campan_persons_t *param_2,
               nn_campan_heads_t *param_3)

{
  void *pvVar1;
  _Rb_tree_node_base *p_Var2;
  _Rb_tree_node_base *p_Var3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  _Rb_tree_node_base *p_Var14;
  _Rb_tree_node_base *p_Var15;
  int iVar16;
  _Rb_tree_node_base *p_Var17;
  int iVar18;
  int iVar19;
  float fVar20;
  pair_conflict apStack_48 [8];
  int local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  
  head_person_match(param_1,param_2,param_3);
  iVar8 = *(int *)(param_1 + 0xb30);
  iVar12 = *(int *)(param_3 + 4);
  iVar5 = *(int *)(param_1 + 0xb10);
  p_Var17 = (_Rb_tree_node_base *)(iVar8 + 4);
  p_Var15 = *(_Rb_tree_node_base **)(iVar8 + 0xc);
  iVar6 = *(int *)(param_2 + 4);
  iVar13 = iVar12;
LAB_00025d24:
  p_Var2 = p_Var15;
  if (p_Var15 != p_Var17) {
    do {
      if (0 < iVar13) {
        piVar7 = *(int **)param_3;
        if (*(int *)(p_Var2 + 0x10) == *piVar7) goto LAB_00025f66;
        iVar9 = 0;
        while (iVar9 = iVar9 + 1, iVar9 != iVar13) {
          piVar7 = piVar7 + 0xf;
          if (*piVar7 == *(int *)(p_Var2 + 0x10)) goto LAB_00025f66;
        }
      }
      p_Var15 = (_Rb_tree_node_base *)std::_Rb_tree_increment(p_Var2);
      pvVar1 = (void *)std::_Rb_tree_rebalance_for_erase(p_Var2,p_Var17);
      operator_delete(pvVar1);
      iVar13 = *(int *)(param_3 + 4);
      *(int *)(iVar8 + 0x14) = *(int *)(iVar8 + 0x14) + -1;
      p_Var2 = p_Var15;
      if (p_Var15 == p_Var17) break;
    } while( true );
  }
  if (0 < iVar13) {
    iVar19 = 0;
    p_Var17 = *(_Rb_tree_node_base **)(iVar8 + 8);
    iVar9 = 0;
    piVar7 = (int *)(iVar5 + -4);
    do {
      iVar16 = iVar9 * 0x3c;
      iVar18 = *(int *)param_3;
      *(undefined4 *)(iVar18 + iVar16 + 0x28) = 0xffffffff;
      piVar7 = piVar7 + 1;
      iVar4 = *piVar7;
      iVar10 = *(int *)(iVar18 + iVar16);
      p_Var2 = p_Var15;
      p_Var3 = p_Var17;
      if (p_Var17 == (_Rb_tree_node_base *)0x0) {
LAB_00025f7a:
        if (iVar4 < 0) {
          local_3c = -1;
          iVar4 = local_3c;
        }
        else {
          local_3c = *(int *)(*(int *)param_2 + iVar4 * 0x2a8);
        }
        local_38 = 1;
        local_40 = iVar10;
        local_34 = iVar4;
        std::
        _Rb_tree<int,std::pair<int_const,match_table_t>,std::_Select1st<std::pair<int_const,match_table_t>>,std::less<int>,std::allocator<std::pair<int_const,match_table_t>>>
        ::_M_emplace_unique<std::pair<int,match_table_t>>(apStack_48);
        p_Var17 = *(_Rb_tree_node_base **)(iVar8 + 8);
        if (p_Var17 != (_Rb_tree_node_base *)0x0) {
          p_Var2 = p_Var15;
          p_Var3 = p_Var17;
          do {
            if (*(int *)(p_Var3 + 0x10) < *(int *)(iVar18 + iVar16)) {
              p_Var14 = *(_Rb_tree_node_base **)(p_Var3 + 0xc);
            }
            else {
              p_Var14 = *(_Rb_tree_node_base **)(p_Var3 + 8);
              p_Var2 = p_Var3;
            }
            p_Var3 = p_Var14;
          } while (p_Var14 != (_Rb_tree_node_base *)0x0);
          if ((p_Var15 != p_Var2) && (*(int *)(p_Var2 + 0x10) <= *(int *)(iVar18 + iVar16))) {
            iVar4 = *(int *)(p_Var2 + 0x14);
            iVar13 = *(int *)(param_3 + 4);
            goto LAB_00025e28;
          }
        }
        iVar4 = *(int *)(p_Var15 + 0x14);
        iVar13 = *(int *)(param_3 + 4);
      }
      else {
        do {
          if (*(int *)(p_Var3 + 0x10) < iVar10) {
            p_Var14 = *(_Rb_tree_node_base **)(p_Var3 + 0xc);
          }
          else {
            p_Var14 = *(_Rb_tree_node_base **)(p_Var3 + 8);
            p_Var2 = p_Var3;
          }
          p_Var3 = p_Var14;
        } while (p_Var14 != (_Rb_tree_node_base *)0x0);
        if ((p_Var15 == p_Var2) || (iVar10 < *(int *)(p_Var2 + 0x10))) goto LAB_00025f7a;
        if (iVar4 < 0) {
LAB_00025fd8:
          iVar4 = -1;
          *(undefined4 *)(p_Var2 + 0x14) = 0xffffffff;
          *(undefined4 *)(p_Var2 + 0x18) = 1;
          *(undefined4 *)(p_Var2 + 0x1c) = 0xffffffff;
        }
        else {
          fVar20 = *(float *)((iVar19 + iVar4) * 0x14 + *(int *)(param_1 + 0xb38) + 0xc);
          iVar10 = *(int *)param_2;
          *(int *)(p_Var2 + 0x1c) = iVar4;
          if (fVar20 == 0.7 || fVar20 < 0.7 != NAN(fVar20)) goto LAB_00025fd8;
          iVar4 = *(int *)(iVar10 + iVar4 * 0x2a8);
          if (*(int *)(p_Var2 + 0x14) == iVar4) {
            iVar10 = *(int *)(p_Var2 + 0x18) + 1;
          }
          else {
            *(int *)(p_Var2 + 0x14) = iVar4;
            iVar10 = 1;
          }
          *(int *)(p_Var2 + 0x18) = iVar10;
        }
      }
LAB_00025e28:
      iVar9 = iVar9 + 1;
      *(int *)(iVar18 + iVar16 + 0x28) = iVar4;
      iVar19 = iVar19 + iVar6;
    } while (iVar9 < iVar13);
  }
  iVar13 = *(int *)(param_2 + 4);
  iVar8 = *(int *)(param_1 + 0xb34);
  p_Var15 = *(_Rb_tree_node_base **)(iVar8 + 0xc);
  p_Var17 = (_Rb_tree_node_base *)(iVar8 + 4);
LAB_00025e4a:
  p_Var2 = p_Var15;
  if (p_Var15 != p_Var17) {
    do {
      if (0 < iVar13) {
        piVar7 = *(int **)param_2;
        if (*(int *)(p_Var2 + 0x10) == *piVar7) goto LAB_00025f70;
        iVar9 = 0;
        while( true ) {
          iVar9 = iVar9 + 1;
          piVar7 = piVar7 + 0xaa;
          if (iVar9 == iVar13) break;
          if (*piVar7 == *(int *)(p_Var2 + 0x10)) goto LAB_00025f70;
        }
      }
      p_Var15 = (_Rb_tree_node_base *)std::_Rb_tree_increment(p_Var2);
      pvVar1 = (void *)std::_Rb_tree_rebalance_for_erase(p_Var2,p_Var17);
      operator_delete(pvVar1);
      iVar13 = *(int *)(param_2 + 4);
      *(int *)(iVar8 + 0x14) = *(int *)(iVar8 + 0x14) + -1;
      p_Var2 = p_Var15;
      if (p_Var15 == p_Var17) break;
    } while( true );
  }
  if (iVar13 < 1) {
    return;
  }
  iVar13 = 0;
  piVar7 = (int *)(iVar5 + iVar12 * 4);
  do {
    iVar5 = *(int *)param_2;
    iVar12 = iVar13 * 0x2a8;
    *(undefined4 *)(iVar5 + iVar12 + 0x148) = 0xffffffff;
    local_34 = *piVar7;
    local_40 = *(int *)(iVar5 + iVar12);
    p_Var2 = *(_Rb_tree_node_base **)(iVar8 + 8);
    p_Var17 = p_Var15;
    if (*(_Rb_tree_node_base **)(iVar8 + 8) == (_Rb_tree_node_base *)0x0) {
LAB_00025fea:
      if (local_34 < 0) {
        local_34 = -1;
        local_3c = 0xffffffff;
      }
      else {
        local_3c = *(undefined4 *)(*(int *)param_3 + local_34 * 0x3c);
      }
      local_38 = 1;
      std::
      _Rb_tree<int,std::pair<int_const,match_table_t>,std::_Select1st<std::pair<int_const,match_table_t>>,std::less<int>,std::allocator<std::pair<int_const,match_table_t>>>
      ::_M_emplace_unique<std::pair<int,match_table_t>>(apStack_48);
      if (*(_Rb_tree_node_base **)(iVar8 + 8) != (_Rb_tree_node_base *)0x0) {
        p_Var2 = *(_Rb_tree_node_base **)(iVar8 + 8);
        p_Var17 = p_Var15;
        do {
          if (*(int *)(p_Var2 + 0x10) < *(int *)(iVar5 + iVar12)) {
            p_Var3 = *(_Rb_tree_node_base **)(p_Var2 + 0xc);
          }
          else {
            p_Var3 = *(_Rb_tree_node_base **)(p_Var2 + 8);
            p_Var17 = p_Var2;
          }
          p_Var2 = p_Var3;
        } while (p_Var3 != (_Rb_tree_node_base *)0x0);
        if ((p_Var17 != p_Var15) && (*(int *)(p_Var17 + 0x10) <= *(int *)(iVar5 + iVar12))) {
          iVar9 = *(int *)(p_Var17 + 0x14);
          goto LAB_00025f0a;
        }
      }
      iVar9 = *(int *)(p_Var15 + 0x14);
    }
    else {
      do {
        if (*(int *)(p_Var2 + 0x10) < local_40) {
          p_Var3 = *(_Rb_tree_node_base **)(p_Var2 + 0xc);
        }
        else {
          p_Var3 = *(_Rb_tree_node_base **)(p_Var2 + 8);
          p_Var17 = p_Var2;
        }
        p_Var2 = p_Var3;
      } while (p_Var3 != (_Rb_tree_node_base *)0x0);
      if ((p_Var17 == p_Var15) || (local_40 < *(int *)(p_Var17 + 0x10))) goto LAB_00025fea;
      if (local_34 < 0) {
LAB_00025efa:
        *(undefined4 *)(p_Var17 + 0x14) = 0xffffffff;
        iVar9 = -1;
        *(undefined4 *)(p_Var17 + 0x1c) = 0xffffffff;
        *(undefined4 *)(p_Var17 + 0x18) = 1;
      }
      else {
        iVar9 = *(int *)param_3;
        fVar20 = *(float *)((local_34 * iVar6 + iVar13) * 0x14 + *(int *)(param_1 + 0xb38) + 0xc);
        *(int *)(p_Var17 + 0x1c) = local_34;
        if (fVar20 == 0.7 || fVar20 < 0.7 != NAN(fVar20)) goto LAB_00025efa;
        iVar9 = *(int *)(iVar9 + local_34 * 0x3c);
        if (*(int *)(p_Var17 + 0x14) == iVar9) {
          iVar19 = *(int *)(p_Var17 + 0x18) + 1;
        }
        else {
          *(int *)(p_Var17 + 0x14) = iVar9;
          iVar19 = 1;
        }
        *(int *)(p_Var17 + 0x18) = iVar19;
      }
    }
LAB_00025f0a:
    *(int *)(iVar5 + iVar12 + 0x148) = iVar9;
    iVar13 = iVar13 + 1;
    iVar5 = *(int *)(param_2 + 4);
    piVar7 = piVar7 + 1;
    if (iVar5 <= iVar13) {
      piVar7 = *(int **)(param_1 + 0xab8);
      if (0 < iVar5) {
        iVar13 = 0;
        do {
          for (piVar11 = (int *)*piVar7; piVar7 != piVar11; piVar11 = (int *)*piVar11) {
            if (*(int *)(*(int *)param_2 + iVar13 * 0x2a8) == piVar11[0x11e]) {
              iVar6 = *(int *)(*(int *)param_2 + iVar13 * 0x2a8 + 0x148);
              if (-1 < iVar6) {
                piVar11[0x120] = iVar6;
                iVar5 = *(int *)(param_2 + 4);
              }
              break;
            }
          }
          iVar13 = iVar13 + 1;
        } while (iVar13 < iVar5);
      }
      return;
    }
  } while( true );
LAB_00025f66:
  p_Var15 = (_Rb_tree_node_base *)std::_Rb_tree_increment(p_Var2);
  goto LAB_00025d24;
LAB_00025f70:
  p_Var15 = (_Rb_tree_node_base *)std::_Rb_tree_increment(p_Var2);
  goto LAB_00025e4a;
}



/* std::_Rb_tree<int, std::pair<int const, kpt_smooth_infos_t>, std::_Select1st<std::pair<int const,
   kpt_smooth_infos_t> >, std::less<int>, std::allocator<std::pair<int const, kpt_smooth_infos_t> >
   >::_M_erase(std::_Rb_tree_node<std::pair<int const, kpt_smooth_infos_t> >*) */

void __thiscall
std::
_Rb_tree<int,std::pair<int_const,kpt_smooth_infos_t>,std::_Select1st<std::pair<int_const,kpt_smooth_infos_t>>,std::less<int>,std::allocator<std::pair<int_const,kpt_smooth_infos_t>>>
::_M_erase(_Rb_tree<int,std::pair<int_const,kpt_smooth_infos_t>,std::_Select1st<std::pair<int_const,kpt_smooth_infos_t>>,std::less<int>,std::allocator<std::pair<int_const,kpt_smooth_infos_t>>>
           *this,_Rb_tree_node *param_1)

{
  _Rb_tree_node *p_Var1;
  
  if (param_1 == (_Rb_tree_node *)0x0) {
    return;
  }
  do {
    _M_erase(this,*(_Rb_tree_node **)(param_1 + 0xc));
    p_Var1 = *(_Rb_tree_node **)(param_1 + 8);
    operator_delete(param_1);
    param_1 = p_Var1;
  } while (p_Var1 != (_Rb_tree_node *)0x0);
  return;
}



/* kpt_smooth_release(kpt_smooth_t*) */

void kpt_smooth_release(kpt_smooth_t *param_1)

{
  _Rb_tree<int,std::pair<int_const,kpt_smooth_infos_t>,std::_Select1st<std::pair<int_const,kpt_smooth_infos_t>>,std::less<int>,std::allocator<std::pair<int_const,kpt_smooth_infos_t>>>
  *this;
  
  if (param_1 == (kpt_smooth_t *)0x0) {
    return;
  }
  this = *(_Rb_tree<int,std::pair<int_const,kpt_smooth_infos_t>,std::_Select1st<std::pair<int_const,kpt_smooth_infos_t>>,std::less<int>,std::allocator<std::pair<int_const,kpt_smooth_infos_t>>>
           **)param_1;
  if (this != (_Rb_tree<int,std::pair<int_const,kpt_smooth_infos_t>,std::_Select1st<std::pair<int_const,kpt_smooth_infos_t>>,std::less<int>,std::allocator<std::pair<int_const,kpt_smooth_infos_t>>>
               *)0x0) {
    std::
    _Rb_tree<int,std::pair<int_const,kpt_smooth_infos_t>,std::_Select1st<std::pair<int_const,kpt_smooth_infos_t>>,std::less<int>,std::allocator<std::pair<int_const,kpt_smooth_infos_t>>>
    ::_M_erase(this,*(_Rb_tree_node **)(this + 8));
    operator_delete(this);
  }
  AX_FREE_RECORD(param_1);
  return;
}



/* std::pair<std::_Rb_tree_iterator<std::pair<int const, kpt_smooth_infos_t> >, bool>
   std::_Rb_tree<int, std::pair<int const, kpt_smooth_infos_t>, std::_Select1st<std::pair<int const,
   kpt_smooth_infos_t> >, std::less<int>, std::allocator<std::pair<int const, kpt_smooth_infos_t> >
   >::_M_emplace_unique<std::pair<int, kpt_smooth_infos_t> >(std::pair<int, kpt_smooth_infos_t>&&)
    */

pair_conflict *
std::
_Rb_tree<int,std::pair<int_const,kpt_smooth_infos_t>,std::_Select1st<std::pair<int_const,kpt_smooth_infos_t>>,std::less<int>,std::allocator<std::pair<int_const,kpt_smooth_infos_t>>>
::_M_emplace_unique<std::pair<int,kpt_smooth_infos_t>>(pair_conflict *param_1)

{
  undefined1 uVar1;
  _Rb_tree_node_base *p_Var2;
  _Rb_tree_node_base *p_Var3;
  int iVar4;
  int in_r1;
  int iVar5;
  int *in_r2;
  _Rb_tree_node_base *p_Var6;
  _Rb_tree_node_base *p_Var7;
  int iVar8;
  _Rb_tree_node_base *p_Var9;
  
  p_Var2 = (_Rb_tree_node_base *)operator_new(0x138);
  iVar8 = *in_r2;
  p_Var9 = (_Rb_tree_node_base *)(in_r1 + 4);
  *(int *)(p_Var2 + 0x10) = iVar8;
  memcpy(p_Var2 + 0x18,in_r2 + 2,0x120);
  p_Var6 = *(_Rb_tree_node_base **)(in_r1 + 8);
  p_Var7 = p_Var9;
  if (*(_Rb_tree_node_base **)(in_r1 + 8) == (_Rb_tree_node_base *)0x0) {
LAB_00026158:
    p_Var6 = *(_Rb_tree_node_base **)(in_r1 + 0xc);
    if (p_Var6 == p_Var7) goto LAB_00026170;
    p_Var3 = (_Rb_tree_node_base *)std::_Rb_tree_decrement(p_Var7);
    iVar5 = *(int *)(p_Var3 + 0x10);
    p_Var6 = p_Var7;
  }
  else {
    do {
      p_Var3 = p_Var6;
      iVar5 = *(int *)(p_Var3 + 0x10);
      if (iVar8 < iVar5) {
        p_Var6 = *(_Rb_tree_node_base **)(p_Var3 + 8);
      }
      else {
        p_Var6 = *(_Rb_tree_node_base **)(p_Var3 + 0xc);
      }
    } while (p_Var6 != (_Rb_tree_node_base *)0x0);
    p_Var7 = p_Var3;
    p_Var6 = p_Var3;
    if (iVar8 < iVar5) goto LAB_00026158;
  }
  if (iVar5 < iVar8) {
    if (p_Var6 != (_Rb_tree_node_base *)0x0) {
LAB_00026170:
      if (p_Var9 == p_Var6) {
        uVar1 = true;
      }
      else {
        iVar4 = *(int *)(p_Var6 + 0x10);
        iVar5 = iVar4;
        if (iVar4 <= iVar8) {
          iVar5 = 0;
        }
        uVar1 = (undefined1)iVar5;
        if (iVar8 < iVar4) {
          uVar1 = true;
        }
      }
      std::_Rb_tree_insert_and_rebalance((bool)uVar1,p_Var2,p_Var6,p_Var9);
      iVar8 = *(int *)(in_r1 + 0x14);
      *(_Rb_tree_node_base **)param_1 = p_Var2;
      param_1[4] = (pair_conflict)0x1;
      *(int *)(in_r1 + 0x14) = iVar8 + 1;
      return param_1;
    }
    p_Var3 = (_Rb_tree_node_base *)0x0;
  }
  operator_delete(p_Var2);
  *(_Rb_tree_node_base **)param_1 = p_Var3;
  param_1[4] = (pair_conflict)0x0;
  return param_1;
}



/* kpt_smooth_process(kpt_smooth_t*, ax_size_t, std::vector<ax_track_kpt_t,
   std::allocator<ax_track_kpt_t> >*, std::vector<ax_track_kpt_t, std::allocator<ax_track_kpt_t> >*)
    */

void kpt_smooth_process(int *param_1,int param_2,int param_3,int *param_4,
                       vector<ax_track_kpt_t,std::allocator<ax_track_kpt_t>> *param_5)

{
  double dVar1;
  _Rb_tree_node_base *p_Var2;
  int iVar3;
  int *piVar4;
  _Rb_tree_node_base *p_Var5;
  _Rb_tree_node_base *p_Var6;
  int *piVar7;
  void *pvVar8;
  int iVar9;
  int iVar10;
  void *pvVar11;
  _Rb_tree_node_base *p_Var12;
  float *pfVar13;
  uint uVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  double dVar24;
  double dVar25;
  pair_conflict apStack_2b8 [8];
  int aiStack_2b0 [35];
  int local_224 [35];
  undefined8 local_198;
  int local_190 [2];
  undefined1 local_188 [292];
  
  iVar10 = *param_1;
  *(undefined4 *)(param_5 + 4) = *(undefined4 *)param_5;
  p_Var2 = (_Rb_tree_node_base *)(iVar10 + 4);
  iVar9 = *param_4;
  if (iVar9 != param_4[1]) {
    uVar14 = 0;
    do {
      p_Var5 = *(_Rb_tree_node_base **)(iVar10 + 8);
      pvVar11 = (void *)(iVar9 + uVar14 * 0x8c);
      iVar9 = *(int *)(iVar9 + uVar14 * 0x8c);
      p_Var12 = p_Var2;
      if (p_Var5 == (_Rb_tree_node_base *)0x0) {
LAB_00026228:
        memset(aiStack_2b0,0,0x120);
        local_198 = get_time_ms();
        pvVar8 = pvVar11;
        piVar4 = aiStack_2b0;
        aiStack_2b0[0x22] = iVar9;
        do {
          piVar7 = piVar4 + 2;
          iVar3 = *(int *)((int)pvVar8 + 8);
          piVar4[0x23] = *(int *)((int)pvVar8 + 4);
          piVar4[0x24] = iVar3;
          *piVar4 = 0;
          piVar4[1] = 0;
          pvVar8 = (void *)((int)pvVar8 + 8);
          piVar4 = piVar7;
        } while (aiStack_2b0 + 0x22 != piVar7);
        local_190[0] = iVar9;
        memcpy(local_188,aiStack_2b0,0x120);
        std::
        _Rb_tree<int,std::pair<int_const,kpt_smooth_infos_t>,std::_Select1st<std::pair<int_const,kpt_smooth_infos_t>>,std::less<int>,std::allocator<std::pair<int_const,kpt_smooth_infos_t>>>
        ::_M_emplace_unique<std::pair<int,kpt_smooth_infos_t>>(apStack_2b8);
        pvVar8 = *(void **)(param_5 + 4);
        if (pvVar8 == *(void **)(param_5 + 8)) {
          std::vector<ax_track_kpt_t,std::allocator<ax_track_kpt_t>>::
          _M_realloc_insert<ax_track_kpt_t_const&>(param_5,pvVar8,pvVar11);
        }
        else {
          if (pvVar8 != (void *)0x0) {
            pvVar8 = memcpy(pvVar8,pvVar11,0x8c);
          }
          *(int *)(param_5 + 4) = (int)pvVar8 + 0x8c;
        }
      }
      else {
        do {
          if (*(int *)(p_Var5 + 0x10) < iVar9) {
            p_Var6 = *(_Rb_tree_node_base **)(p_Var5 + 0xc);
          }
          else {
            p_Var6 = *(_Rb_tree_node_base **)(p_Var5 + 8);
            p_Var12 = p_Var5;
          }
          p_Var5 = p_Var6;
        } while (p_Var6 != (_Rb_tree_node_base *)0x0);
        if ((p_Var12 == p_Var2) || (iVar9 < *(int *)(p_Var12 + 0x10))) goto LAB_00026228;
        dVar24 = *(double *)(p_Var12 + 0x130);
        dVar1 = (double)get_time_ms();
        pfVar13 = (float *)(param_1 + 4);
        p_Var6 = p_Var12 + 0x18;
        p_Var5 = p_Var12;
        piVar4 = local_190;
        local_190[0] = iVar9;
        do {
          fVar21 = *(float *)((int)pvVar11 + 8);
          fVar22 = *(float *)((int)pvVar11 + 4);
          fVar23 = *pfVar13;
          pfVar13 = pfVar13 + 1;
          fVar15 = (fVar21 - *(float *)(p_Var5 + 0xa8)) / (float)(longlong)param_3;
          fVar18 = (fVar22 - *(float *)(p_Var5 + 0xa4)) / (float)(longlong)param_2;
          fVar15 = fVar15 * fVar15 + fVar18 * fVar18;
          fVar18 = SQRT(fVar15);
          if ((int)((uint)(fVar15 < 0.0) << 0x1f) < 0) {
            sqrtf(fVar15);
          }
          if (fVar22 == 0.0 && fVar21 == 0.0) {
            if (((*(float *)(p_Var5 + 0xa4) != 0.0) || (*(float *)(p_Var5 + 0xa8) != 0.0)) ||
               (fVar22 != 0.0 || fVar21 != 0.0)) goto LAB_00026426;
            if (fVar23 == fVar18 || fVar23 < fVar18 != (NAN(fVar23) || NAN(fVar18)))
            goto LAB_00026496;
LAB_00026370:
            iVar9 = *(int *)(p_Var5 + 0xa8);
            piVar4[1] = *(int *)(p_Var5 + 0xa4);
            piVar4[2] = iVar9;
          }
          else if (((fVar21 == 0.0 && fVar22 == 0.0) || (*(float *)(p_Var5 + 0xa4) != 0.0)) ||
                  (*(float *)(p_Var5 + 0xa8) != 0.0)) {
            if (fVar23 != fVar18 && fVar23 < fVar18 == (NAN(fVar23) || NAN(fVar18)))
            goto LAB_00026370;
LAB_00026496:
            fVar16 = *(float *)(p_Var5 + 0xa4);
            dVar25 = (dVar1 - dVar24) / 1000.0;
            fVar17 = *(float *)(p_Var5 + 0xa8);
            fVar20 = (float)param_1[2];
            fVar18 = (float)param_1[3];
            fVar15 = (float)((double)(float)param_1[1] * 6.2831852 * dVar25);
            fVar15 = fVar15 / (fVar15 + 1.0);
            fVar23 = (1.0 - fVar15) * *(float *)p_Var6 +
                     fVar15 * (float)((double)(fVar22 - fVar16) / dVar25);
            fVar19 = (1.0 - fVar15) * *(float *)(p_Var6 + 4) +
                     fVar15 * (float)((double)(fVar21 - fVar17) / dVar25);
            *(float *)(p_Var6 + 4) = fVar19;
            *(float *)p_Var6 = fVar23;
            fVar15 = (float)((double)(fVar20 + fVar18 * ABS(fVar23)) * 6.2831852 * dVar25);
            fVar18 = (float)((double)(fVar20 + fVar18 * ABS(fVar19)) * 6.2831852 * dVar25);
            fVar15 = fVar15 / (fVar15 + 1.0);
            fVar18 = fVar18 / (fVar18 + 1.0);
            fVar15 = (1.0 - fVar15) * fVar16 + fVar15 * fVar22;
            *(float *)(p_Var5 + 0xa4) = fVar15;
            fVar18 = (1.0 - fVar18) * fVar17 + fVar18 * fVar21;
            *(float *)(p_Var5 + 0xa8) = fVar18;
            piVar4[1] = (int)fVar15;
            piVar4[2] = (int)fVar18;
          }
          else {
LAB_00026426:
            piVar4[1] = (int)fVar22;
            piVar4[2] = (int)fVar21;
            *(float *)(p_Var5 + 0xa4) = fVar22;
            *(float *)(p_Var5 + 0xa8) = fVar21;
            *(undefined4 *)p_Var6 = 0;
            *(undefined4 *)(p_Var6 + 4) = 0;
          }
          pvVar11 = (void *)((int)pvVar11 + 8);
          p_Var5 = p_Var5 + 8;
          piVar4 = piVar4 + 2;
          p_Var6 = p_Var6 + 8;
        } while ((float *)(param_1 + 0x15) != pfVar13);
        pvVar11 = *(void **)(param_5 + 4);
        if (pvVar11 == *(void **)(param_5 + 8)) {
          std::vector<ax_track_kpt_t,std::allocator<ax_track_kpt_t>>::
          _M_realloc_insert<ax_track_kpt_t_const&>(param_5,pvVar11,local_190);
        }
        else {
          if (pvVar11 != (void *)0x0) {
            memcpy(pvVar11,local_190,0x8c);
          }
          *(int *)(param_5 + 4) = (int)pvVar11 + 0x8c;
        }
        *(double *)(p_Var12 + 0x130) = dVar1;
      }
      uVar14 = uVar14 + 1;
      iVar9 = *param_4;
    } while (uVar14 < (uint)((param_4[1] - iVar9 >> 2) * -0x75075075));
  }
  p_Var12 = *(_Rb_tree_node_base **)(iVar10 + 0xc);
  do {
    while( true ) {
      if (p_Var12 == p_Var2) {
        return;
      }
      piVar4 = (int *)*param_4;
      iVar9 = param_4[1] - (int)piVar4;
      if (piVar4 != (int *)param_4[1]) break;
LAB_00026306:
      iVar9 = *param_1;
      p_Var5 = (_Rb_tree_node_base *)std::_Rb_tree_increment(p_Var12);
      pvVar11 = (void *)std::_Rb_tree_rebalance_for_erase(p_Var12,(_Rb_tree_node_base *)(iVar9 + 4))
      ;
      operator_delete(pvVar11);
      *(int *)(iVar9 + 0x14) = *(int *)(iVar9 + 0x14) + -1;
      p_Var12 = p_Var5;
    }
    if (*(int *)(p_Var12 + 0x10) != *piVar4) {
      iVar10 = 0;
      do {
        iVar10 = iVar10 + 1;
        if (iVar10 == (iVar9 >> 2) * -0x75075075) goto LAB_00026306;
        piVar4 = piVar4 + 0x23;
      } while (*piVar4 != *(int *)(p_Var12 + 0x10));
    }
    p_Var12 = (_Rb_tree_node_base *)std::_Rb_tree_increment(p_Var12);
  } while( true );
}



/* campan_reid_create(_vx_context*, ax_size_t, ImageFormat_E, char const*) */

void campan_reid_create(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  void *local_13c;
  undefined4 local_138;
  undefined4 uStack_134;
  undefined4 local_130;
  char *local_12c;
  char *local_128;
  undefined4 local_124;
  undefined4 uStack_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  void *local_110;
  undefined4 uStack_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined1 local_f8;
  char acStack_f4 [100];
  char acStack_90 [100];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  puVar1 = (undefined8 *)AX_MALLOC_RECORD(0x18);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  sprintf(acStack_f4,"%s/personfeat.ezb",param_5);
  sprintf(acStack_90,"%s/personfeat.bin",param_5);
  *(undefined4 *)((int)puVar1 + 4) = 0x100;
  local_13c = (void *)0x0;
  local_130 = 0xffffffff;
  local_138 = 0;
  uStack_134 = 0;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_13c,(int *)&local_130);
  local_110 = (void *)0x0;
  uStack_10c = 0;
  local_108 = 0;
  batch_classify_config_init((batch_classify_config_t *)&local_130);
  local_11c = 0x40;
  local_118 = 0x80;
  local_130 = param_1;
  local_12c = acStack_f4;
  local_128 = acStack_90;
  local_124 = param_2;
  uStack_120 = param_3;
  local_114 = param_4;
  std::vector<int,std::allocator<int>>::operator=
            ((vector<int,std::allocator<int>> *)&local_110,(vector *)&local_13c);
  local_104 = 0;
  local_f8 = 1;
  uVar2 = batch_classify_create((batch_classify_config_t *)&local_130);
  *(undefined4 *)puVar1 = uVar2;
  if (local_110 != (void *)0x0) {
    operator_delete(local_110);
  }
  if (local_13c != (void *)0x0) {
    operator_delete(local_13c);
  }
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(puVar1);
}



/* handpose_create(_vx_context*, ax_size_t, ImageFormat_E, nn_campan_cfg_t*) */

void handpose_create(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    int param_5)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int local_140;
  void *local_13c;
  void *local_138;
  undefined4 local_134;
  undefined4 local_130;
  char *local_12c;
  char *local_128;
  undefined4 local_124;
  undefined4 uStack_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  void *local_110;
  undefined4 uStack_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined1 local_f8;
  char acStack_f4 [100];
  char acStack_90 [100];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  puVar1 = (undefined8 *)AX_MALLOC_RECORD(0x10);
  *puVar1 = 0;
  puVar1[1] = 0;
  sprintf(acStack_f4,"%s/hand.ezb",*(undefined4 *)(param_5 + 0xc));
  sprintf(acStack_90,"%s/hand.bin",*(undefined4 *)(param_5 + 0xc));
  local_13c = (void *)0x0;
  local_138 = (void *)0x0;
  local_134 = 0;
  local_130 = 0xffffffff;
  std::vector<int,std::allocator<int>>::emplace_back<int>
            ((vector<int,std::allocator<int>> *)&local_13c,(int *)&local_130);
  local_110 = (void *)0x0;
  uStack_10c = 0;
  local_108 = 0;
  batch_classify_config_init((batch_classify_config_t *)&local_130);
  local_11c = 0x70;
  local_118 = 0x70;
  local_130 = param_1;
  local_12c = acStack_f4;
  local_128 = acStack_90;
  local_124 = param_2;
  uStack_120 = param_3;
  local_114 = param_4;
  std::vector<int,std::allocator<int>>::operator=
            ((vector<int,std::allocator<int>> *)&local_110,(vector *)&local_13c);
  local_104 = 0;
  local_f8 = 1;
  uVar2 = batch_classify_create((batch_classify_config_t *)&local_130);
  iVar3 = *(int *)(param_5 + 0x50);
  *(undefined4 *)puVar1 = uVar2;
  if (iVar3 == 0) {
    iVar3 = *(int *)(param_5 + 0x54);
  }
  else {
    sprintf(acStack_f4,"%s/hand_old.ezb",*(undefined4 *)(param_5 + 0xc));
    sprintf(acStack_90,"%s/hand_old.bin",*(undefined4 *)(param_5 + 0xc));
    local_138 = local_13c;
    local_140 = -1;
    std::vector<int,std::allocator<int>>::emplace_back<int>
              ((vector<int,std::allocator<int>> *)&local_13c,&local_140);
    local_11c = 0x70;
    local_118 = 0x70;
    std::vector<int,std::allocator<int>>::operator=
              ((vector<int,std::allocator<int>> *)&local_110,(vector *)&local_13c);
    uVar2 = batch_classify_create((batch_classify_config_t *)&local_130);
    iVar3 = *(int *)(param_5 + 0x54);
    *(undefined4 *)((int)puVar1 + 4) = uVar2;
  }
  if (iVar3 == 0) {
    iVar3 = *(int *)(param_5 + 0x58);
  }
  else {
    sprintf(acStack_f4,"%s/hand_two_cls.ezb",*(undefined4 *)(param_5 + 0xc));
    sprintf(acStack_90,"%s/hand_two_cls.bin",*(undefined4 *)(param_5 + 0xc));
    local_138 = local_13c;
    local_140 = -1;
    std::vector<int,std::allocator<int>>::emplace_back<int>
              ((vector<int,std::allocator<int>> *)&local_13c,&local_140);
    local_11c = 0x70;
    local_118 = 0x70;
    std::vector<int,std::allocator<int>>::operator=
              ((vector<int,std::allocator<int>> *)&local_110,(vector *)&local_13c);
    uVar2 = batch_classify_create((batch_classify_config_t *)&local_130);
    iVar3 = *(int *)(param_5 + 0x58);
    *(undefined4 *)(puVar1 + 1) = uVar2;
  }
  if (iVar3 != 0) {
    sprintf(acStack_f4,"%s/hand_lr.ezb",*(undefined4 *)(param_5 + 0xc));
    sprintf(acStack_90,"%s/hand_lr.bin",*(undefined4 *)(param_5 + 0xc));
    local_138 = local_13c;
    local_140 = -1;
    std::vector<int,std::allocator<int>>::emplace_back<int>
              ((vector<int,std::allocator<int>> *)&local_13c,&local_140);
    local_11c = 0x70;
    local_118 = 0x70;
    std::vector<int,std::allocator<int>>::operator=
              ((vector<int,std::allocator<int>> *)&local_110,(vector *)&local_13c);
    uVar2 = batch_classify_create((batch_classify_config_t *)&local_130);
    *(undefined4 *)((int)puVar1 + 0xc) = uVar2;
  }
  if (local_110 != (void *)0x0) {
    operator_delete(local_110);
  }
  if (local_13c != (void *)0x0) {
    operator_delete(local_13c);
  }
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(puVar1);
}



/* human_pose_release(human_pose_t*) */

void human_pose_release(human_pose_t *param_1)

{
  if (param_1 == (human_pose_t *)0x0) {
    return;
  }
  classify_model_release(*(batch_classify_model_t **)param_1);
  AX_FREE_RECORD(param_1);
  return;
}



/* human_pose_process(human_pose_t*, ax_yuv_t*, ax_box_t*, int*, float) */

void human_pose_process(human_pose_t *param_1,ax_yuv_t *param_2,ax_box_t *param_3,int *param_4,
                       float param_5)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  int iVar10;
  char *pcVar11;
  int iVar12;
  int *piVar13;
  void *pvVar14;
  ax_tensor_t *this;
  ax_tensor_t *paVar15;
  undefined4 *puVar16;
  ax_tensor_t *paVar17;
  undefined4 *puVar18;
  int iVar19;
  int *piVar20;
  int iVar21;
  void *pvVar22;
  void *pvVar23;
  int iVar24;
  int iVar25;
  undefined4 uVar26;
  char *pcVar27;
  char *pcVar28;
  char *pcVar29;
  char local_170;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  void *local_128;
  void *local_124;
  undefined4 local_120;
  int *local_11c;
  int *local_118;
  undefined4 uStack_114;
  int *local_110;
  int *local_10c;
  undefined4 uStack_108;
  void *local_104;
  undefined4 uStack_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  int local_d0 [33];
  char cStack_49;
  char local_48 [20];
  int local_34;
  
  local_134 = *(int *)(param_3 + 4);
  local_138 = *(int *)param_3;
  local_12c = (*(int *)(param_3 + 0xc) - local_134) + 1;
  local_34 = __stack_chk_guard;
  local_130 = (*(int *)(param_3 + 8) - local_138) + 1;
  local_110 = (int *)0x0;
  local_10c = (int *)0x0;
  uStack_108 = 0;
  local_104 = (void *)0x0;
  uStack_100 = 0;
  local_fc = 0;
  std::vector<ax_rect_t,std::allocator<ax_rect_t>>::_M_realloc_insert<ax_rect_t_const&>
            ((vector<ax_rect_t,std::allocator<ax_rect_t>> *)&local_110,0,&local_138);
  local_f8 = *(undefined4 *)param_2;
  uStack_f4 = *(undefined4 *)(param_2 + 4);
  uStack_f0 = *(undefined4 *)(param_2 + 8);
  uStack_ec = *(undefined4 *)(param_2 + 0xc);
  local_e8 = *(undefined4 *)(param_2 + 0x10);
  uStack_e4 = *(undefined4 *)(param_2 + 0x14);
  uStack_e0 = *(undefined4 *)(param_2 + 0x18);
  uStack_dc = *(undefined4 *)(param_2 + 0x1c);
  local_d4 = 0;
  local_d8 = *(undefined4 *)(param_2 + 0x20);
  local_128 = (void *)0x0;
  local_124 = (void *)0x0;
  local_120 = 0;
  local_11c = (int *)0x0;
  local_118 = (int *)0x0;
  uStack_114 = 0;
  batch_classify_process
            (*(batch_classify_model_t **)param_1,(classify_in_t *)&local_110,
             (classify_out_t *)&local_128,1);
  get_time_ms();
  iVar10 = **(int **)(*(int *)param_1 + 0x40);
  if ((*(int **)(*(int *)param_1 + 0x40))[1] == iVar10) {
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0,0);
  }
  local_170 = (char)(int)((float)(longlong)(1 << (*(uint *)(iVar10 + 4) & 0xff)) * param_5);
  memset(local_48,(int)local_170,0x11);
  memset(local_d0,-1,0x88);
  piVar13 = local_10c;
  piVar3 = local_110;
  if (local_118 == local_11c) {
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0);
  }
  iVar10 = *local_11c;
  if (local_11c[1] == iVar10) {
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0);
  }
  iVar7 = *(int *)(iVar10 + 4);
  iVar24 = *(int *)(iVar10 + 8);
  iVar25 = *(int *)(iVar10 + 0xc);
  iVar10 = *(int *)(iVar10 + 0x10);
  if (0 < iVar7) {
    pcVar27 = (char *)(iVar10 + -1);
    iVar21 = 0;
    do {
      if (0 < iVar24) {
        iVar19 = 0;
        pcVar29 = pcVar27;
        piVar8 = local_d0;
        pcVar11 = &cStack_49;
        pcVar28 = pcVar27;
        do {
          do {
            cVar1 = pcVar29[1];
            pcVar11 = pcVar11 + 1;
            if (*pcVar11 < cVar1) {
              *piVar8 = iVar21;
              piVar8[1] = iVar19;
              *pcVar11 = cVar1;
            }
            pcVar29 = pcVar29 + 1;
            piVar8 = piVar8 + 2;
          } while (pcVar11 != local_48 + 0x10);
          pcVar29 = pcVar28 + iVar25;
          iVar19 = iVar19 + 1;
          piVar8 = local_d0;
          pcVar11 = &cStack_49;
          pcVar28 = pcVar29;
        } while (iVar24 != iVar19);
      }
      iVar21 = iVar21 + 1;
      pcVar27 = pcVar27 + iVar25 * iVar24;
    } while (iVar7 != iVar21);
  }
  iVar21 = 0;
  piVar8 = local_d0;
  do {
    iVar19 = local_d0[iVar21 * 2];
    if (0 < iVar19) {
      iVar12 = piVar8[1];
      uVar9 = *(undefined4 *)(param_1 + 0xc);
      iVar4 = __aeabi_idiv(uVar9,iVar7);
      uVar26 = *(undefined4 *)(param_1 + 0x10);
      iVar4 = iVar19 * iVar4;
      iVar5 = __aeabi_idiv(uVar26,iVar24);
      if (iVar19 < iVar7 + -1) {
        iVar6 = iVar24 * (iVar19 + 1);
        iVar6 = (int)*(char *)(iVar10 + iVar21 + iVar25 * (iVar6 + iVar12)) -
                (int)*(char *)(iVar10 + iVar21 + iVar25 * (iVar6 + iVar24 * -2 + iVar12));
        if ((0 < iVar12) && (iVar12 < iVar24 + -1)) goto LAB_00026ab6;
        if (iVar6 == 0) goto LAB_00026b9c;
        if (iVar6 < 1) {
          iVar4 = iVar4 + -1;
        }
        else {
          iVar4 = iVar4 + 1;
        }
        local_d0[iVar21 * 2] = iVar4;
        iVar19 = 0;
        iVar5 = piVar8[1] * iVar5;
      }
      else if ((iVar12 < 1) || (iVar24 + -1 <= iVar12)) {
LAB_00026b9c:
        local_d0[iVar21 * 2] = iVar4;
        iVar19 = 0;
        iVar5 = piVar8[1] * iVar5;
      }
      else {
        iVar6 = 0;
LAB_00026ab6:
        iVar19 = (int)*(char *)(iVar10 + iVar21 + iVar25 * (iVar12 + 1 + iVar19 * iVar24)) -
                 (int)*(char *)(iVar10 + iVar21 + iVar25 * (iVar19 * iVar24 + iVar12 + -1));
        if (iVar6 != 0) {
          if (iVar6 < 1) {
            iVar4 = iVar4 + -1;
          }
          else {
            iVar4 = iVar4 + 1;
          }
        }
        local_d0[iVar21 * 2] = iVar4;
        iVar5 = piVar8[1] * iVar5;
        if (iVar19 != 0) {
          if (iVar19 < 1) {
            iVar19 = -1;
          }
          else {
            iVar19 = 1;
          }
        }
      }
      piVar8[1] = iVar5 + iVar19;
      if (piVar13 == piVar3) {
                    /* WARNING: Subroutine does not return */
        std::__throw_out_of_range_fmt
                  ("vector::_M_range_check: __n (which is %zu) >= this->size() (which is %zu)",0);
      }
      iVar19 = __aeabi_idiv(piVar3[2] * local_d0[iVar21 * 2],uVar9);
      local_d0[iVar21 * 2] = iVar19 + *piVar3;
      iVar19 = __aeabi_idiv(piVar3[3] * piVar8[1],uVar26);
      piVar8[1] = iVar19 + piVar3[1];
    }
    iVar21 = iVar21 + 1;
    piVar8 = piVar8 + 2;
    if (iVar21 == 0x11) {
      memcpy(param_4,local_d0,0x88);
      get_time_ms();
      piVar3 = local_118;
      piVar13 = local_118;
      if (local_11c != local_118) {
        piVar20 = local_11c + 3;
        piVar13 = local_11c;
        piVar8 = piVar20;
        while( true ) {
          paVar17 = (ax_tensor_t *)piVar13[1];
          this = (ax_tensor_t *)piVar20[-3];
          if ((ax_tensor_t *)piVar20[-3] != paVar17) {
            do {
              paVar15 = this + 0x30;
              ax_tensor_t::~ax_tensor_t(this);
              this = paVar15;
            } while (paVar17 != paVar15);
            paVar17 = (ax_tensor_t *)piVar20[-3];
          }
          if (paVar17 != (ax_tensor_t *)0x0) {
            operator_delete(paVar17);
          }
          piVar20 = piVar20 + 3;
          piVar13 = local_11c;
          if (piVar3 == piVar8) break;
          piVar13 = piVar8;
          piVar8 = piVar8 + 3;
        }
      }
      if (piVar13 != (int *)0x0) {
        operator_delete(piVar13);
      }
      pvVar2 = local_124;
      pvVar14 = local_124;
      if (local_128 != local_124) {
        pvVar22 = (void *)((int)local_128 + 0xc);
        pvVar14 = local_128;
        pvVar23 = pvVar22;
        while( true ) {
          puVar18 = *(undefined4 **)((int)pvVar14 + 4);
          puVar16 = *(undefined4 **)((int)pvVar22 + -0xc);
          if (puVar16 != puVar18) {
            do {
              if ((void *)*puVar16 != (void *)0x0) {
                operator_delete((void *)*puVar16);
              }
              puVar16 = puVar16 + 3;
            } while (puVar18 != puVar16);
            puVar18 = *(undefined4 **)((int)pvVar22 + -0xc);
          }
          if (puVar18 != (undefined4 *)0x0) {
            operator_delete(puVar18);
          }
          pvVar22 = (void *)((int)pvVar22 + 0xc);
          pvVar14 = local_128;
          if (pvVar2 == pvVar23) break;
          pvVar14 = pvVar23;
          pvVar23 = (void *)((int)pvVar23 + 0xc);
        }
      }
      if (pvVar14 != (void *)0x0) {
        operator_delete(pvVar14);
      }
      if (local_104 != (void *)0x0) {
        operator_delete(local_104);
      }
      if (local_110 != (int *)0x0) {
        operator_delete(local_110);
      }
      if (local_34 == __stack_chk_guard) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
  } while( true );
}



/* human_pose_create(_vx_context*, char const*, char const*, ax_size_t, ImageFormat_E, ax_size_t,
   int) */

undefined8 *
human_pose_create(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  void *__src;
  void *pvVar1;
  void *pvVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  void *pvVar5;
  uint __n;
  size_t __n_00;
  void *local_78;
  void *local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 local_50;
  void *local_4c;
  void *local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 local_34;
  
  __android_log_print(6,0,"human pose version %s %s","Nov 15 2023","10:13:56");
  puVar3 = (undefined8 *)AX_MALLOC_RECORD(0x14);
  *puVar3 = 0;
  puVar3[1] = 0;
  local_70 = 0;
  *(undefined8 *)((int)puVar3 + 0xc) = 0;
  local_6c = 0;
  local_78 = (void *)0x0;
  local_74 = (void *)0x0;
  std::vector<int,std::allocator<int>>::_M_realloc_insert<int>
            ((vector<int,std::allocator<int>> *)&local_78,0,(batch_classify_config_t *)&local_6c);
  local_4c = (void *)0x0;
  local_48 = (void *)0x0;
  local_44 = 0;
  batch_classify_config_init((batch_classify_config_t *)&local_6c);
  pvVar1 = local_74;
  __src = local_78;
  __n = (int)local_74 - (int)local_78;
  local_50 = param_6;
  uStack_5c = param_5;
  pvVar5 = (void *)((int)__n >> 2);
  local_58 = param_7;
  uStack_54 = param_8;
  local_6c = param_1;
  local_68 = param_2;
  local_64 = param_3;
  local_60 = param_4;
  if ((void *)(local_44 - (int)local_4c >> 2) < pvVar5) {
    if (pvVar5 != (void *)0x0) {
      if ((void *)0x3fffffff < pvVar5) {
                    /* WARNING: Subroutine does not return */
        std::__throw_bad_alloc();
      }
      pvVar5 = operator_new(__n);
    }
    pvVar2 = local_4c;
    if (pvVar1 != __src) {
      memmove(pvVar5,__src,__n);
    }
    if (pvVar2 != (void *)0x0) {
      operator_delete(pvVar2);
    }
    local_48 = (void *)(__n + (int)pvVar5);
    local_4c = pvVar5;
    local_44 = (int)local_48;
    goto LAB_00026e1c;
  }
  __n_00 = (int)local_48 - (int)local_4c;
  if ((void *)((int)__n_00 >> 2) < pvVar5) {
    pvVar5 = (void *)((int)local_78 + __n_00);
    if (local_78 == pvVar5) {
      if (local_74 != pvVar5) {
LAB_00026e72:
        memmove(local_48,pvVar5,(int)local_74 - (int)pvVar5);
      }
    }
    else {
      memmove(local_4c,local_78,__n_00);
      pvVar5 = (void *)((int)local_78 + ((int)local_48 - (int)local_4c));
      if (local_74 != pvVar5) goto LAB_00026e72;
    }
  }
  else if (local_74 != local_78) {
    memmove(local_4c,local_78,__n);
    local_48 = (void *)(__n + (int)local_4c);
    goto LAB_00026e1c;
  }
  local_48 = (void *)(__n + (int)local_4c);
LAB_00026e1c:
  local_40 = param_9;
  local_3c = 0;
  local_38 = 0;
  local_34 = 1;
  *(undefined4 *)((int)puVar3 + 4) = local_60;
  *(undefined4 *)(puVar3 + 1) = uStack_5c;
  *(undefined4 *)((int)puVar3 + 0xc) = local_58;
  *(undefined4 *)(puVar3 + 2) = uStack_54;
  uVar4 = batch_classify_create((batch_classify_config_t *)&local_6c);
  *(undefined4 *)puVar3 = uVar4;
  if (local_4c != (void *)0x0) {
    operator_delete(local_4c);
  }
  if (local_78 != (void *)0x0) {
    operator_delete(local_78);
  }
  return puVar3;
}



void nn_campan_open(undefined4 param_1)

{
  nn_hermes_open(campan_open,param_1,0x78);
  return;
}



void nn_campan_cmd(void)

{
  nn_hermes_cmd();
  return;
}



void nn_campan_close(void)

{
  undefined4 in_r3;
  
  nn_hermes_close();
  __android_log_print(6,"CAMPAN","campan stopped",in_r3);
  return;
}



void _fini(void)

{
  return;
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nn_face_quality_process
               (nn_face_quality_t *param_1,ax_yuv_t *param_2,face_box_t *param_3,float *param_4)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void dtbased_tk_change_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void face_feature_release(nn_face_feature_t *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sem_destroy(sem_t *__sem)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * operator_new(uint param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void nn_hermes_close(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_lock(pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__detail::_List_node_base::_M_hook(_List_node_base *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_init(pthread_mutex_t *__mutex,pthread_mutexattr_t *__mutexattr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::_Rb_tree_insert_and_rebalance
               (bool param_1,_Rb_tree_node_base *param_2,_Rb_tree_node_base *param_3,
               _Rb_tree_node_base *param_4)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void face_pose_release(face_pose_t *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void nn_hermes_cmd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void batch_classify_create(batch_classify_config_t *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__throw_bad_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void nn_face_quality_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __cxa_begin_catch(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nn_face_quality_release(nn_face_quality_t *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__detail::_List_node_base::_M_transfer(_List_node_base *param_1,_List_node_base *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __android_log_print(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__cxx11::string::_M_assign(string *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nn_get_state(nn_state_t *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void classify_model_release(batch_classify_model_t *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void softmax(vector *param_1,vector *param_2,int param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void face_pose_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void AX_FREE_RECORD(void *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void axnn_plg_open(void *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::_Rb_tree_rebalance_for_erase(_Rb_tree_node_base *param_1,_Rb_tree_node_base *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __thiscall ax_tensor_t::~ax_tensor_t(ax_tensor_t *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void dtbased_tk_change_ids(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int prctl(int __option,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::_Rb_tree_increment(_Rb_tree_node_base *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nnyuv2axyuv(nn_yuv_t *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__throw_logic_error(char *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nn_set_state(nn_state_t *param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void box_smooth_release(box_smooth_t *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memmove(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ioctl(int __fd,ulong __request,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __thiscall ax_tensor_mem_t::operator=(ax_tensor_mem_t *this,ax_tensor_mem_t *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void retina_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void operator_delete(void *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __assert_fail(char *__assertion,char *__file,uint __line,char *__function)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void get_time_ms(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void face_feature_process
               (nn_face_feature_t *param_1,ax_yuv_t *param_2,face_box_t *param_3,signed *param_4)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void batch_classify_process
               (batch_classify_model_t *param_1,classify_in_t *param_2,classify_out_t *param_3,
               int param_4)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __thiscall ax_tensor_t::ax_tensor_t(ax_tensor_t *this,ax_tensor_t *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ax_tensor_t::norm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::_Rb_tree_decrement(_Rb_tree_node_base *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void fps_stat_update(fps_stat_t *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_destroy(pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void batch_classify_config_init(batch_classify_config_t *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void nn_hermes_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __cxa_end_cleanup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void retina_process_humanpose
               (retina_t *param_1,retina_pose_in_t *param_2,retina_pose_out_t *param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void dtbased_tk_update(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void dtbased_tk_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void get_debug_level(char *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nn_sleepms(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float sqrtf(float __x)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sem_init(sem_t *__sem,int __pshared,uint __value)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __thiscall ax_tensor_t::ax_tensor_t(ax_tensor_t *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __aeabi_idivmod(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nn_thread_exit(ulong *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void buffer_pool_release(buffer_pool_t *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * calloc(size_t __nmemb,size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void flush_model_temp_memory(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void box_smooth_create(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nn_state_release(nn_state_t *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __aeabi_idiv(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sem_post(sem_t *__sem)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float expf(float __x)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __cxa_rethrow(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void AX_MALLOC_RECORD(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void axnn_plg_close(ax_nna_ctx_plg *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__throw_out_of_range_fmt(char *param_1,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void retina_process(retina_t *param_1,retina_in_t *param_2,retina_out_t *param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void getContext(ax_nna_ctx_plg *param_1,_vx_context **param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __aeabi_unwind_cpp_pr1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__detail::_List_node_base::_M_unhook(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __cxa_end_catch(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __gxx_personality_v0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void box_smooth_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__cxx11::string::_M_create(uint *param_1,uint param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void _ITM_deregisterTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void face_feature_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nn_state_init(nn_state_t *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __aeabi_unwind_cpp_pr0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nn_thread_init(ulong *param_1,_func_void_ptr_void_ptr *param_2,void *param_3,int param_4,
                   int param_5)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void dtbased_tk_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void face_pose_process(face_pose_t *param_1,ax_yuv_t *param_2,ax_box_t *param_3,float *param_4)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __gmon_start__(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sem_wait(sem_t *__sem)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void _ITM_registerTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_unlock(pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void retina_release(retina_t *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nna_setFreq(_vx_context *param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


