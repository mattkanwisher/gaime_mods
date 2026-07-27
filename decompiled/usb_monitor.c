/* Ghidra decompilation of usb_monitor (68 functions) */


int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = FUN_00010f8c();
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__sighandler_t signal(int __sig,__sighandler_t __handler)

{
  __sighandler_t p_Var1;
  
  p_Var1 = signal(__sig,__handler);
  return p_Var1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int chdir(char *__path)

{
  int iVar1;
  
  iVar1 = chdir(__path);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strcspn(char *__s,char *__reject)

{
  size_t sVar1;
  
  sVar1 = strcspn(__s,__reject);
  return sVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void exit(int __status)

{
                    /* WARNING: Subroutine does not return */
  exit(__status);
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void syslog(int __pri,char *__fmt,...)

{
  syslog(__pri,__fmt);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void closelog(void)

{
  closelog();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
  int iVar1;
  
  iVar1 = close(__fd);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
  FILE *pFVar1;
  
  pFVar1 = fopen(__filename,__modes);
  return pFVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
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



void __stack_chk_fail(void)

{
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t fork(void)

{
  __pid_t _Var1;
  
  _Var1 = fork();
  return _Var1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t setsid(void)

{
  __pid_t _Var1;
  
  _Var1 = setsid();
  return _Var1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint sleep(uint __seconds)

{
  uint uVar1;
  
  uVar1 = sleep(__seconds);
  return uVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = fgets(__s,__n,__stream);
  return pcVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__mode_t umask(__mode_t __mask)

{
  __mode_t _Var1;
  
  _Var1 = umask(__mask);
  return _Var1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fprintf(FILE *__stream,char *__format,...)

{
  int iVar1;
  
  iVar1 = fprintf(__stream,__format);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
  int iVar1;
  
  iVar1 = fclose(__stream);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = strcmp(__s1,__s2);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncpy(char *__dest,char *__src,size_t __n)

{
  char *pcVar1;
  
  pcVar1 = strncpy(__dest,__src,__n);
  return pcVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void openlog(char *__ident,int __option,int __facility)

{
  openlog(__ident,__option,__facility);
  return;
}



void __libc_start_main(void)

{
  __libc_start_main();
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int dup(int __fd)

{
  int iVar1;
  
  iVar1 = dup(__fd);
  return iVar1;
}



void main(void)

{
  int iVar1;
  int iVar2;
  char acStack_64 [64];
  int local_24;
  
  local_24 = __stack_chk_guard;
  openlog("usb_monitor_daemon",3,0x18);
  daemonize();
  syslog(6,"usb_monitor_daemon started.");
  signal(0xf,(__sighandler_t)0x1101d);
  signal(2,(__sighandler_t)0x1101d);
  if (DAT_00022080 != 0) {
    do {
      read_usb_state(acStack_64,0x40);
      iVar1 = strcmp(acStack_64,&DAT_00022088);
      if (iVar1 != 0) {
        syslog(6,"USB state changed from \'%s\' to \'%s\'",&DAT_00022088,acStack_64);
        if (DAT_000220c8 == '\0') {
          iVar1 = strcmp(acStack_64,"configured");
          if (iVar1 == 0) {
            DAT_000220c8 = '\x01';
            syslog(6,"USB first configured state achieved.");
            start_gun_task();
          }
        }
        else {
          iVar1 = strcmp(&DAT_00022088,"configured");
          iVar2 = strcmp(acStack_64,"configured");
          if (iVar1 == 0) {
            if (iVar2 != 0) {
              syslog(6,"USB state changed from \'configured\' to \'%s\'. Preparing to kill gun.",
                     acStack_64);
              kill_gun_task();
            }
          }
          else if (iVar2 == 0) {
            syslog(6,"USB state changed from \'%s\' to \'configured\'. Preparing to reboot.",
                   &DAT_00022088);
            reboot_system();
          }
        }
        strncpy(&DAT_00022088,acStack_64,0x40);
        DAT_000220c7 = 0;
      }
      sleep(1);
    } while (DAT_00022080 != 0);
  }
  syslog(6,"usb_monitor_daemon stopped.");
  closelog();
  if (local_24 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(0);
}



void _start(undefined4 param_1)

{
  undefined4 in_stack_00000000;
  
  __libc_start_main(0x10ded,in_stack_00000000,&stack0x00000004,0x11285,0x112c1,param_1);
                    /* WARNING: Subroutine does not return */
  abort();
}



/* WARNING: Removing unreachable block (ram,0x00010fa0) */

void FUN_00010f8c(void)

{
  __gmon_start__();
  return;
}



/* WARNING: Removing unreachable block (ram,0x00010fc4) */
/* WARNING: Removing unreachable block (ram,0x00010fce) */

void FUN_00010fb0(void)

{
  return;
}



/* WARNING: Removing unreachable block (ram,0x00010ff0) */
/* WARNING: Removing unreachable block (ram,0x00010ffa) */

void FUN_00010fd4(void)

{
  return;
}



void _FINI_0(void)

{
  if (_edata == '\0') {
    FUN_00010fb0();
    _edata = '\x01';
  }
  return;
}



/* WARNING: Removing unreachable block (ram,0x00010ff0) */
/* WARNING: Removing unreachable block (ram,0x00010ffa) */

void _INIT_0(void)

{
  return;
}



void signal_handler(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((param_1 != 2) && (param_1 != 0xf)) {
    return;
  }
  syslog(6,"Received signal %d, shutting down.",param_1,param_4,param_4);
  DAT_00022080 = 0;
  return;
}



void start_gun_task(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = system("/app/bin/gun &");
  if (iVar1 == 0) {
    syslog(6,"\'gun\' process start successfully.",param_3,param_4);
    return;
  }
  return;
}



void kill_gun_task(void)

{
  FILE *__stream;
  int iVar1;
  char *__fmt;
  
  syslog(6,"Attempting to disable PWM and kill \'gun\' process.");
  __stream = fopen("/sys/class/pwm/pwmchip0/pwm5/enable","w");
  if (__stream == (FILE *)0x0) {
    syslog(3,"Failed to open PWM enable file: %s","/sys/class/pwm/pwmchip0/pwm5/enable");
  }
  else {
    iVar1 = fprintf(__stream,"0");
    if (iVar1 < 0) {
      syslog(3,"Failed to write 0 to PWM enable file: %s","/sys/class/pwm/pwmchip0/pwm5/enable");
    }
    else {
      syslog(6,"Successfully disabled PWM by writing 0 to %s","/sys/class/pwm/pwmchip0/pwm5/enable")
      ;
    }
    fclose(__stream);
  }
  iVar1 = system("pkill -9 gun");
  if (iVar1 == 0) {
    iVar1 = 6;
    __fmt = "\'gun\' process killed successfully.";
  }
  else {
    iVar1 = 4;
    __fmt = "Failed to kill \'gun\' process or \'gun\' not found.";
  }
  syslog(iVar1,__fmt);
  return;
}



void reboot_system(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  syslog(6,"System is about to reboot now.");
  iVar1 = system("reboot");
  if (iVar1 == -1) {
    syslog(3,"Failed to execute reboot command.");
  }
  syslog(6,"Reboot command executed.",param_3,param_4);
  return;
}



char * read_usb_state(char *param_1,size_t param_2)

{
  FILE *__stream;
  char *pcVar1;
  size_t sVar2;
  
  __stream = fopen("/sys/class/udc/lb_hdc.0/state","r");
  if (__stream != (FILE *)0x0) {
    pcVar1 = fgets(param_1,param_2,__stream);
    if (pcVar1 == (char *)0x0) {
      syslog(3,"Failed to read USB state from file: %s","/sys/class/udc/lb_hdc.0/state");
      strncpy(param_1,"error",param_2);
      param_1[param_2 - 1] = '\0';
    }
    else {
      sVar2 = strcspn(param_1,"\n");
      param_1[sVar2] = '\0';
    }
    fclose(__stream);
    return param_1;
  }
  syslog(3,"Failed to open USB state file: %s","/sys/class/udc/lb_hdc.0/state");
  strncpy(param_1,"error",param_2);
  param_1[param_2 - 1] = '\0';
  return param_1;
}



void daemonize(void)

{
  __pid_t _Var1;
  int iVar2;
  
  _Var1 = fork();
  if (-1 < _Var1) {
    if (_Var1 != 0) {
LAB_00011208:
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    _Var1 = setsid();
    if (-1 < _Var1) {
      signal(0x11,(__sighandler_t)0x1);
      _Var1 = fork();
      if (-1 < _Var1) {
        if (_Var1 != 0) goto LAB_00011208;
        iVar2 = chdir("/");
        if (-1 < iVar2) {
          umask(0);
          close(0);
          close(1);
          close(2);
          open("/dev/null",2);
          dup(0);
          dup(0);
          return;
        }
        syslog(3,"Failed to change directory to /");
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  exit(1);
}



void __libc_csu_init(EVP_PKEY_CTX *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined **ppuVar2;
  
  _init(param_1);
  iVar1 = 0;
  ppuVar2 = &__DT_INIT_ARRAY;
  do {
    iVar1 = iVar1 + 1;
    (*(code *)*ppuVar2)(param_1,param_2,param_3,*ppuVar2,param_4);
    ppuVar2 = ppuVar2 + 1;
  } while (iVar1 != 1);
  return;
}



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

__sighandler_t signal(int __sig,__sighandler_t __handler)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int chdir(char *__path)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strcspn(char *__s,char *__reject)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void exit(int __status)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void syslog(int __pri,char *__fmt,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void closelog(void)

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

FILE * fopen(char *__filename,char *__modes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int system(char *__command)

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

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t fork(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t setsid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint sleep(uint __seconds)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__mode_t umask(__mode_t __mask)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fprintf(FILE *__stream,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

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

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncpy(char *__dest,char *__src,size_t __n)

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

void openlog(char *__ident,int __option,int __facility)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */

void __libc_start_main(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int dup(int __fd)

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


