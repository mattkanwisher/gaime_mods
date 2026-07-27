/* Ghidra decompilation of fw_upgrade (42 functions) */


int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = call_weak_fn();
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  free(__ptr);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = printf(__format);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = puts(__s);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
  int iVar1;
  
  iVar1 = close(__fd);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  ssize_t sVar1;
  
  sVar1 = read(__fd,__buf,__nbytes);
  return sVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ioctl(int __fd,ulong __request,...)

{
  int iVar1;
  
  iVar1 = ioctl(__fd,__request);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int system(char *__command)

{
  int iVar1;
  
  iVar1 = system(__command);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = open(__file,__oflag);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__off_t lseek(int __fd,__off_t __offset,int __whence)

{
  __off_t _Var1;
  
  _Var1 = lseek(__fd,__offset,__whence);
  return _Var1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * calloc(size_t __nmemb,size_t __size)

{
  void *pvVar1;
  
  pvVar1 = calloc(__nmemb,__size);
  return pvVar1;
}



void __aeabi_uidiv(void)

{
  __aeabi_uidiv();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
  ssize_t sVar1;
  
  sVar1 = write(__fd,__buf,__n);
  return sVar1;
}



void __libc_start_main(void)

{
  __libc_start_main();
  return;
}



int main(void)

{
  int __fd;
  int iVar1;
  ssize_t sVar2;
  int iVar3;
  undefined4 *puVar4;
  size_t sVar5;
  ulonglong local_c8;
  undefined8 local_c0;
  ulonglong uStack_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  int iStack_50;
  int local_4c;
  undefined4 uStack_48;
  undefined8 local_44;
  undefined8 local_3c;
  undefined8 local_34;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  local_60 = 0x20545055;
  local_2c = 0;
  local_54 = 0;
  iStack_50 = 0;
  local_4c = 0;
  uStack_48 = 0;
  local_c8 = 0;
  local_44 = 0;
  local_3c = 0;
  local_34 = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  local_58 = 0x12345678;
  local_c0 = 0;
  uStack_b8 = 0;
  local_b0 = 0;
  local_a8 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = 0;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_5c = 1;
  __fd = open("/dev/char/misc",0x101002);
  if (__fd < 0) {
    puts("open /dev/char/misc failed! try to open /dev/block/misc");
    __fd = open("/dev/block/misc",2);
    if (-1 < __fd) {
      read(__fd,&local_a0,0x40);
      iStack_50 = (int)local_90;
      local_54 = uStack_98._4_4_;
      if ((uStack_98._4_4_ == -1) && ((int)local_90 == -1)) {
        iStack_50 = 0;
        uStack_98 = uStack_98 & 0xffffffff;
        local_90 = local_90 & 0xffffffff00000000;
        local_54 = iStack_50;
      }
      local_4c = local_90._4_4_;
      if (local_90._4_4_ == -1) {
        local_4c = 0;
        local_90 = local_90 & 0xffffffff;
      }
      local_58 = check_sum(&local_60,0x40);
      sVar5 = (local_90._4_4_ + 0x10) * 4;
      puVar4 = (undefined4 *)calloc(sVar5,1);
      lseek(__fd,0,0);
      read(__fd,puVar4,sVar5);
      *puVar4 = local_60;
      puVar4[1] = local_5c;
      puVar4[2] = local_58;
      puVar4[3] = local_54;
      puVar4[4] = iStack_50;
      puVar4[5] = local_4c;
      puVar4[6] = uStack_48;
      puVar4[7] = (undefined4)local_44;
      puVar4[8] = local_44._4_4_;
      puVar4[9] = (undefined4)local_3c;
      puVar4[10] = local_3c._4_4_;
      puVar4[0xb] = (undefined4)local_34;
      puVar4[0xc] = local_34._4_4_;
      puVar4[0xd] = local_2c;
      puVar4[0xe] = uStack_28;
      puVar4[0xf] = uStack_24;
      lseek(__fd,0,0);
      write(__fd,puVar4,sVar5);
      close(__fd);
      system("reboot");
      return 0;
    }
    iVar1 = 0xe4;
    puts("open /dev/block/misc failed! exit");
  }
  else {
    iVar1 = ioctl(__fd,0x80204d01,&local_c0);
    if (iVar1 == 0) {
      sVar2 = read(__fd,&local_a0,0x40);
      if (sVar2 < 0) {
        iVar1 = 0x95;
        printf("read err ret:%d\n");
      }
      else {
        iStack_50 = (int)local_90;
        local_54 = uStack_98._4_4_;
        if ((uStack_98._4_4_ == -1) && ((int)local_90 == -1)) {
          uStack_98 = uStack_98 & 0xffffffff;
          local_90 = local_90 & 0xffffffff00000000;
          iStack_50 = 0;
          local_54 = 0;
        }
        local_4c = local_90._4_4_;
        if (local_90._4_4_ == -1) {
          local_4c = 0;
          local_90 = local_90 & 0xffffffff;
        }
        local_58 = check_sum(&local_60,0x40);
        iVar1 = (int)local_b0;
        iVar3 = __aeabi_uidiv((int)local_b0 + local_90._4_4_ * 4 + 0x3f,(int)local_b0);
        sVar5 = iVar1 * iVar3;
        puVar4 = (undefined4 *)calloc(sVar5,1);
        if (puVar4 == (undefined4 *)0x0) {
          iVar1 = 0xb2;
          printf("%s:%d malloc buf_write failed!\n",&__FUNCTION___7671,0xb1);
        }
        else {
          lseek(__fd,0,0);
          sVar2 = read(__fd,puVar4,sVar5);
          if (sVar2 < 0) {
            iVar1 = 0xbd;
            printf("read err ret:%d\n");
          }
          else {
            *puVar4 = local_60;
            puVar4[1] = local_5c;
            puVar4[2] = local_58;
            puVar4[3] = local_54;
            puVar4[4] = iStack_50;
            puVar4[5] = local_4c;
            puVar4[6] = uStack_48;
            puVar4[7] = (undefined4)local_44;
            puVar4[8] = local_44._4_4_;
            puVar4[9] = (undefined4)local_3c;
            puVar4[10] = local_3c._4_4_;
            puVar4[0xb] = (undefined4)local_34;
            puVar4[0xc] = local_34._4_4_;
            puVar4[0xd] = local_2c;
            puVar4[0xe] = uStack_28;
            puVar4[0xf] = uStack_24;
            lseek(__fd,0,0);
            local_c8 = uStack_b8 & 0xffffffff00000000;
            iVar3 = ioctl(__fd,0x40084d02,&local_c8);
            if (iVar3 == 0) {
              lseek(__fd,0,0);
              sVar2 = write(__fd,puVar4,sVar5);
              if (-1 < sVar2) {
                free(puVar4);
                close(__fd);
                system("reboot");
                return 0;
              }
              iVar1 = 0xd5;
              printf("write err ret:%d\n");
            }
            else {
              iVar1 = 0xca;
              printf("%s:%d erase flash failed! ret %d\n",&__FUNCTION___7671,0xc9,iVar3);
            }
          }
          free(puVar4);
        }
      }
    }
    else {
      printf("%s:%d ioctl failed! ret %d\n",&__FUNCTION___7671,0x82,iVar1);
    }
    if (__fd == 0) {
      return iVar1;
    }
  }
  close(__fd);
  return iVar1;
}



void _start(undefined4 param_1)

{
  undefined4 in_stack_00000000;
  
  __libc_start_main(0x10895,in_stack_00000000,&stack0x00000004,0x10c95,0x10cd1,param_1);
                    /* WARNING: Subroutine does not return */
  abort();
}



/* WARNING: Removing unreachable block (ram,0x00010bdc) */

void call_weak_fn(void)

{
  __gmon_start__();
  return;
}



/* WARNING: Removing unreachable block (ram,0x00010c00) */
/* WARNING: Removing unreachable block (ram,0x00010c0a) */

void deregister_tm_clones(void)

{
  return;
}



/* WARNING: Removing unreachable block (ram,0x00010c2c) */
/* WARNING: Removing unreachable block (ram,0x00010c36) */

void register_tm_clones(void)

{
  return;
}



void __do_global_dtors_aux(void)

{
  if (completed_10541 == '\0') {
    deregister_tm_clones();
    completed_10541 = '\x01';
  }
  return;
}



/* WARNING: Removing unreachable block (ram,0x00010c2c) */
/* WARNING: Removing unreachable block (ram,0x00010c36) */

void frame_dummy(void)

{
  return;
}



int check_sum(int *param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_1 == (int *)0x0) {
    printf("Err: %s %d","check_sum",0x5a);
    return 0;
  }
  if (param_2 >> 2 != 0) {
    iVar1 = 0;
    piVar2 = param_1;
    do {
      piVar3 = piVar2 + 1;
      iVar1 = iVar1 + *piVar2;
      piVar2 = piVar3;
    } while (piVar3 != param_1 + (param_2 >> 2));
    return iVar1;
  }
  return 0;
}



/* WARNING: Unknown calling convention */

void __libc_csu_init(int argc,char **argv,char **envp)

{
  int iVar1;
  undefined **ppuVar2;
  
  _init((EVP_PKEY_CTX *)argc);
  iVar1 = 0;
  ppuVar2 = &__frame_dummy_init_array_entry;
  do {
    iVar1 = iVar1 + 1;
    (*(code *)*ppuVar2)(argc,argv,envp);
    ppuVar2 = ppuVar2 + 1;
  } while (iVar1 != 1);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __libc_csu_fini(void)

{
  return;
}



void _fini(void)

{
  return;
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* free@@GLIBC_2.4 */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* printf@@GLIBC_2.4 */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* puts@@GLIBC_2.4 */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* close@@GLIBC_2.4 */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* read@@GLIBC_2.4 */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* abort@@GLIBC_2.4 */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ioctl(int __fd,ulong __request,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* ioctl@@GLIBC_2.4 */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int system(char *__command)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* system@@GLIBC_2.4 */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* open@@GLIBC_2.4 */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__off_t lseek(int __fd,__off_t __offset,int __whence)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* lseek@@GLIBC_2.4 */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * calloc(size_t __nmemb,size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* calloc@@GLIBC_2.4 */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __aeabi_uidiv(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __aeabi_uidiv@@GCC_3.5 */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* write@@GLIBC_2.4 */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __aeabi_unwind_cpp_pr0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __aeabi_unwind_cpp_pr0@@GCC_3.5 */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __libc_start_main(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __libc_start_main@@GLIBC_2.4 */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __gmon_start__(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


