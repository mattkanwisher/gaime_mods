/* Ghidra decompilation of fw_ab_upgrade (127 functions) */


int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = FUN_00012768();
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fsync(int __fd)

{
  int iVar1;
  
  iVar1 = fsync(__fd);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long strtol(char *__nptr,char **__endptr,int __base)

{
  long lVar1;
  
  lVar1 = strtol(__nptr,__endptr,__base);
  return lVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  free(__ptr);
  return;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
  int iVar1;
  
  iVar1 = strncmp(__s1,__s2,__n);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = printf(__format);
  return iVar1;
}



void __android_log_print(void)

{
  __android_log_print();
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

int unlink(char *__name)

{
  int iVar1;
  
  iVar1 = unlink(__name);
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

char * strcpy(char *__dest,char *__src)

{
  char *pcVar1;
  
  pcVar1 = strcpy(__dest,__src);
  return pcVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __assert_fail(char *__assertion,char *__file,uint __line,char *__function)

{
                    /* WARNING: Subroutine does not return */
  __assert_fail(__assertion,__file,__line,__function);
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getopt(int ___argc,char **___argv,char *__shortopts)

{
  int iVar1;
  
  iVar1 = getopt(___argc,___argv,__shortopts);
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

int access(char *__name,int __type)

{
  int iVar1;
  
  iVar1 = access(__name,__type);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
  char *pcVar1;
  
  pcVar1 = strstr(__haystack,__needle);
  return pcVar1;
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

size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s)

{
  size_t sVar1;
  
  sVar1 = fwrite(__ptr,__size,__n,__s);
  return sVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = memcpy(__dest,__src,__n);
  return pvVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = malloc(__size);
  return pvVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = strlen(__s);
  return sVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fprintf(FILE *__stream,char *__format,...)

{
  int iVar1;
  
  iVar1 = fprintf(__stream,__format);
  return iVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
  ssize_t sVar1;
  
  sVar1 = write(__fd,__buf,__n);
  return sVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
  int iVar1;
  
  iVar1 = sprintf(__s,__format);
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



void __libc_start_main(void)

{
  __libc_start_main();
  return;
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */

void main(int param_1,char **param_2)

{
  int iVar1;
  char *pcVar2;
  ssize_t sVar3;
  char *pcVar4;
  size_t sVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  void *__buf;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  uint *puVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined *puVar16;
  int *piVar17;
  int *piVar18;
  char *__name;
  void *pvVar19;
  uint uVar20;
  int iVar21;
  uint *puVar22;
  uint *puVar23;
  uint *puVar24;
  int iVar25;
  bool bVar26;
  undefined4 *local_548;
  undefined1 auStack_520 [4];
  undefined4 local_51c;
  undefined1 auStack_518 [4];
  __off_t local_514;
  uint local_510;
  uint local_50c;
  uint local_508;
  uint local_504;
  int local_500;
  int local_4fc;
  undefined4 local_4f8;
  undefined4 uStack_4f4;
  undefined4 local_4f0;
  int local_4ec;
  uint local_4e8;
  undefined4 uStack_4e4;
  undefined4 uStack_4e0;
  undefined4 uStack_4dc;
  undefined4 local_4d8;
  int local_4d4;
  undefined4 uStack_4d0;
  undefined4 uStack_4cc;
  undefined4 local_4c8;
  undefined4 uStack_4c4;
  undefined4 uStack_4c0;
  undefined4 uStack_4bc;
  uint *local_4b8;
  char local_4b4 [64];
  uint local_474 [4];
  undefined4 uStack_464;
  int local_460;
  uint local_45c [4];
  undefined4 local_44c;
  undefined4 uStack_448;
  undefined4 uStack_444;
  undefined4 uStack_440;
  undefined4 local_43c;
  undefined4 uStack_438;
  undefined4 uStack_434;
  undefined4 uStack_430;
  undefined1 uStack_42c;
  char acStack_42b [12];
  char acStack_41f [1011];
  int local_2c;
  
  iVar21 = 0;
  bVar26 = false;
  local_2c = __stack_chk_guard;
  __android_log_print(3,"FW_AB_UPGRADE","fw_ab_upgrade start...");
  __name = "/media/package.efw";
  while (iVar1 = getopt(param_1,param_2,"dhrp:"), iVar1 != -1) {
    switch(iVar1) {
    case 100:
      bVar26 = true;
      break;
    default:
      iVar21 = -0x16;
      FUN_00012950(*param_2);
      goto LAB_000113f2;
    case 0x68:
      iVar21 = 0;
      FUN_00012950(*param_2);
      goto LAB_000113f2;
    case 0x70:
      __name = optarg;
      break;
    case 0x72:
      iVar21 = 1;
    }
  }
  __android_log_print(4,"FW_AB_UPGRADE","package path is %s",__name);
  memset(&local_4fc,0,0x48);
  memset(local_474,0,0x448);
  local_500 = iVar1;
  iVar1 = open("/proc/cmdline",0);
  if (iVar1 < 0) {
    __android_log_print(6,"FW_AB_UPGRADE","failed to open %s","/proc/cmdline");
LAB_000115a4:
    __android_log_print(6,"FW_AB_UPGRADE","failed to get device boot param");
  }
  else {
    pcVar2 = (char *)calloc(0x1000,1);
    if (pcVar2 == (char *)0x0) {
      __android_log_print(6,"FW_AB_UPGRADE","failed to malloc, size:%u",0x1000);
LAB_0001159e:
      close(iVar1);
      goto LAB_000115a4;
    }
    lseek(iVar1,0,0);
    sVar3 = read(iVar1,pcVar2,0x1000);
    if (sVar3 < 1) {
      __android_log_print(6,"FW_AB_UPGRADE","failed to read %s","/proc/cmdline");
LAB_00011598:
      free(pcVar2);
      goto LAB_0001159e;
    }
    pcVar4 = strstr(pcVar2,"boot=");
    if (pcVar4 == (char *)0x0) {
      __android_log_print(6,"FW_AB_UPGRADE","failed to get boot storage from command line");
      goto LAB_00011598;
    }
    local_474[0] = strtol(pcVar4 + 5,(char **)0x0,10);
    if (1 < local_474[0]) {
      __android_log_print(6,"FW_AB_UPGRADE","invalid boot storage %d",local_474[0]);
      goto LAB_00011598;
    }
    pcVar4 = strstr(pcVar2,"lombo_select=");
    if (pcVar4 == (char *)0x0) {
      __android_log_print(6,"FW_AB_UPGRADE","failed to get boot zone from command line");
      goto LAB_00011598;
    }
    if (pcVar4[0xd] == 'a') {
      local_474[1] = 1;
    }
    else {
      if (pcVar4[0xd] != 'b') {
        __android_log_print(6,"FW_AB_UPGRADE","invalid boot zone %c");
        goto LAB_00011598;
      }
      local_474[1] = 2;
    }
    free(pcVar2);
    close(iVar1);
    if (((-1 < local_500) || (local_4fc != 0)) || (__name == (char *)0x0)) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("pkg && pkg->fd < 0 && !pkg->handle && dev && path",
                    "apps/verified-test/fw_ab_upgrade/fw_ab_upgrade.c",0x1bb,"package_create");
    }
    iVar1 = access(__name,0);
    if (iVar1 == 0) {
      iVar1 = open(__name,0);
      local_500 = iVar1;
      if (iVar1 < 0) {
        __android_log_print(6,"FW_AB_UPGRADE","failed to open package file %s",__name);
        pvVar19 = (void *)0x0;
        goto LAB_0001152c;
      }
      pvVar19 = calloc(0x1000,1);
      if (pvVar19 == (void *)0x0) {
        __android_log_print(6,"FW_AB_UPGRADE","failed to malloc, size:%u",0x1000);
        goto LAB_0001152c;
      }
      lseek(iVar1,0,0);
      sVar3 = read(local_500,pvVar19,0x1000);
      if (sVar3 < 1) {
        __android_log_print(6,"FW_AB_UPGRADE","failed to read package file %s",__name);
        goto LAB_0001152c;
      }
      local_4fc = unpack_init(pvVar19,1);
      if (local_4fc == 0) {
        __android_log_print(6,"FW_AB_UPGRADE","failed to unpack package file %s",__name);
        goto LAB_0001152c;
      }
      if (local_4b8 != (uint *)0x0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("pkg && !pkg->item_list","apps/verified-test/fw_ab_upgrade/fw_ab_upgrade.c",
                      0x157,"package_create_item_list");
      }
      if (1 < local_474[1] - 1) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("(zone == 1) || (zone == 2)",
                      "apps/verified-test/fw_ab_upgrade/fw_ab_upgrade.c",0x158,
                      "package_create_item_list");
      }
      if (local_474[1] == 1) {
        puVar14 = &DAT_000260a4;
      }
      else {
        puVar14 = &DAT_000260c0;
      }
      puVar22 = &local_504;
      local_548 = puVar14;
      do {
        iVar1 = local_4fc;
        pcVar2 = (char *)*local_548;
        puVar15 = local_548 + 1;
        if ((local_4fc == 0) || (pcVar2 == (char *)0x0)) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("pkg && pkg->handle && name",
                        "apps/verified-test/fw_ab_upgrade/fw_ab_upgrade.c",0x109,
                        "package_append_item");
        }
        sVar5 = strlen(pcVar2);
        if (10 < sVar5) {
          __android_log_print(6,"FW_AB_UPGRADE","item name %s is too long",pcVar2);
LAB_00012386:
          __android_log_print(6,"FW_AB_UPGRADE","failed to append item %s to item list",*local_548);
          FUN_000129e4(&local_500);
          __android_log_print(6,"FW_AB_UPGRADE","failed to create item list of package");
          goto LAB_0001152c;
        }
        puVar23 = &local_508;
        iVar1 = FUN_000127f8(iVar1,pcVar2,&local_510,&local_50c,puVar23,puVar22);
        if (iVar1 != 0) {
          __android_log_print(6,"FW_AB_UPGRADE","failed to get info of item %s",pcVar2);
          goto LAB_00012386;
        }
        puVar6 = (uint *)malloc(0x20);
        if (puVar6 == (uint *)0x0) {
          __android_log_print(6,"FW_AB_UPGRADE","failed to malloc, size:%u",0x20);
          goto LAB_00012386;
        }
        puVar6[0] = 0;
        puVar6[1] = 0;
        puVar6[1] = 0;
        puVar6[2] = 0;
        strncpy((char *)puVar6,pcVar2,10);
        puVar6[7] = 0;
        puVar6[3] = local_510;
        puVar6[4] = local_50c;
        puVar6[5] = local_508;
        puVar6[6] = local_504;
        puVar24 = local_4b8;
        if (local_4b8 != (uint *)0x0) {
          do {
            puVar12 = puVar24;
            puVar24 = (uint *)puVar12[7];
          } while (puVar24 != (uint *)0x0);
          puVar12[7] = (uint)puVar6;
          puVar6 = local_4b8;
        }
        local_4b8 = puVar6;
        local_548 = puVar15;
      } while (puVar14 + 7 != puVar15);
      if ((local_500 < 1) || (local_4fc == 0)) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("pkg && pkg->fd > 0 && pkg->handle && name",
                      "apps/verified-test/fw_ab_upgrade/fw_ab_upgrade.c",0xd7,"package_fetch_item");
      }
      iVar1 = FUN_000127f8(local_4fc,&DAT_00013f64,&local_510,&local_50c,puVar23,puVar22);
      uVar7 = local_508;
      if (iVar1 != 0) {
        __android_log_print(6,"FW_AB_UPGRADE","failed to get info of item %s",&DAT_00013f64);
LAB_000117a0:
        __android_log_print(6,"FW_AB_UPGRADE","failed to fetch item misc from package");
LAB_000117b2:
        __android_log_print(6,"FW_AB_UPGRADE","failed to get misc of package");
        goto LAB_0001152c;
      }
      if (0x1000 < local_508) {
        __android_log_print(6,"FW_AB_UPGRADE","failed to fetch item %s, length:%u",&DAT_00013f64,
                            local_508);
        goto LAB_000117a0;
      }
      puVar14 = (undefined4 *)calloc(local_508,1);
      if (puVar14 == (undefined4 *)0x0) {
        __android_log_print(6,"FW_AB_UPGRADE","failed to malloc, size:%u",uVar7);
        goto LAB_000117a0;
      }
      lseek(local_500,local_504,0);
      uVar7 = read(local_500,puVar14,local_508);
      if (uVar7 < local_508) {
        __android_log_print(6,"FW_AB_UPGRADE","failed to read data of item %s, size:%u",
                            &DAT_00013f64,local_508);
        free(puVar14);
        goto LAB_000117a0;
      }
      decode(puVar14,local_508,local_50c);
      iVar1 = FUN_00012a90(puVar14);
      if (iVar1 != 0) {
        __android_log_print(6,"FW_AB_UPGRADE","misc data verify error");
        free(puVar14);
        goto LAB_000117b2;
      }
      local_4f8 = *puVar14;
      uStack_4f4 = puVar14[1];
      local_4f0 = puVar14[2];
      local_4ec = puVar14[3];
      local_4e8 = puVar14[4];
      uStack_4e4 = puVar14[5];
      uStack_4e0 = puVar14[6];
      uStack_4dc = puVar14[7];
      local_4d8 = puVar14[8];
      local_4d4 = puVar14[9];
      uStack_4d0 = puVar14[10];
      uStack_4cc = puVar14[0xb];
      local_4c8 = puVar14[0xc];
      uStack_4c4 = puVar14[0xd];
      uStack_4c0 = puVar14[0xe];
      uStack_4bc = puVar14[0xf];
      free(puVar14);
      free(pvVar19);
      if ((local_500 < 1) || (local_4fc == 0)) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("pkg && pkg->fd > 0 && pkg->handle && dev",
                      "apps/verified-test/fw_ab_upgrade/fw_ab_upgrade.c",0x26e,"device_get_imbr");
      }
      if (1 < local_474[0]) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("(dev->boot_storage == 0) || (dev->boot_storage == 1)",
                      "apps/verified-test/fw_ab_upgrade/fw_ab_upgrade.c",0x270,"device_get_imbr");
      }
      puVar16 = (&PTR_s_imbr_mmc_00025ee0)[local_474[0]];
      iVar1 = FUN_000127f8(local_4fc,"leaver_item",auStack_520,&local_51c,auStack_518,&local_514);
      if (iVar1 == 0) {
        pvVar19 = calloc(0x1000,1);
        if (pvVar19 == (void *)0x0) {
          __android_log_print(6,"FW_AB_UPGRADE","failed to malloc, size:%u",0x1000);
          goto LAB_00011934;
        }
        lseek(local_500,local_514,0);
        sVar3 = read(local_500,pvVar19,0x1000);
        if (sVar3 < 1) {
          __android_log_print(6,"FW_AB_UPGRADE","failed to read data of item %s, size:%u",
                              "leaver_item",0x1000);
LAB_000119e4:
          free(pvVar19);
          goto LAB_00011934;
        }
        decode(pvVar19,0x1000,local_51c);
        iVar1 = unpack_init(pvVar19,1);
        if (iVar1 == 0) {
          __android_log_print(6,"FW_AB_UPGRADE","failed to unpack item %s","leaver_item");
          goto LAB_000119e4;
        }
        iVar8 = FUN_000127f8(iVar1,puVar16,&local_510,&local_50c,puVar23,puVar22);
        if (iVar8 != 0) {
          __android_log_print(6,"FW_AB_UPGRADE","failed to get info of item %s",puVar16);
LAB_000119de:
          unpack_uninit(iVar1);
          goto LAB_000119e4;
        }
        if (local_508 < 0x400) {
          __android_log_print(6,"FW_AB_UPGRADE","invalid imbr size(%u bytes) of %s",local_508,
                              puVar16);
          goto LAB_000119de;
        }
        __buf = calloc(0x400,1);
        if (__buf == (void *)0x0) {
          __android_log_print(6,"FW_AB_UPGRADE","failed to malloc, size:%u",0x400);
          goto LAB_000119de;
        }
        lseek(local_500,local_514 + local_504,0);
        sVar3 = read(local_500,__buf,0x400);
        if (sVar3 != 0x400) {
          __android_log_print(6,"FW_AB_UPGRADE","failed to read data of item %s, size:%u",puVar16,
                              0x400);
          free(__buf);
          goto LAB_000119de;
        }
        decode(__buf,0x400,local_51c);
        memcpy(&uStack_42c,__buf,0x400);
        free(__buf);
        unpack_uninit(iVar1);
        free(pvVar19);
        iVar1 = access("/dev/block/misc",0);
        if (iVar1 != 0) {
          __android_log_print(6,"FW_AB_UPGRADE","block device %s is not exist","/dev/block/misc");
LAB_00011ade:
          __android_log_print(6,"FW_AB_UPGRADE","failed to get misc of device");
          goto LAB_00011946;
        }
        iVar1 = open("/dev/block/misc",0);
        if (iVar1 < 0) {
          __android_log_print(6,"FW_AB_UPGRADE","failed to open %s","/dev/block/misc");
          goto LAB_00011ade;
        }
        puVar14 = (undefined4 *)malloc(0x40);
        if (puVar14 == (undefined4 *)0x0) {
          __android_log_print(6,"FW_AB_UPGRADE","failed to malloc, size:%u",0x40);
LAB_00011b40:
          close(iVar1);
          goto LAB_00011ade;
        }
        lseek(iVar1,0,0);
        sVar3 = read(iVar1,puVar14,0x40);
        if (sVar3 != 0x40) {
          __android_log_print(6,"FW_AB_UPGRADE","failed to read %s","/dev/block/misc");
LAB_00011b3a:
          free(puVar14);
          goto LAB_00011b40;
        }
        iVar8 = FUN_00012a90(puVar14);
        if (iVar8 != 0) {
          __android_log_print(6,"FW_AB_UPGRADE","misc data verify error");
          goto LAB_00011b3a;
        }
        local_474[2] = *puVar14;
        local_474[3] = puVar14[1];
        uStack_464 = puVar14[2];
        local_460 = puVar14[3];
        local_45c[0] = puVar14[4];
        local_45c[1] = puVar14[5];
        local_45c[2] = puVar14[6];
        local_45c[3] = puVar14[7];
        local_44c = puVar14[8];
        uStack_448 = puVar14[9];
        uStack_444 = puVar14[10];
        uStack_440 = puVar14[0xb];
        local_43c = puVar14[0xc];
        uStack_438 = puVar14[0xd];
        uStack_434 = puVar14[0xe];
        uStack_430 = puVar14[0xf];
        free(puVar14);
        close(iVar1);
        if (local_4ec == local_460) {
          puVar6 = local_4b8;
          if (local_4e8 < local_45c[0]) {
            __android_log_print(6,"FW_AB_UPGRADE",
                                "board version of package %u less than the one of device %u",
                                local_4e8,local_45c[0]);
            goto LAB_00012350;
          }
          for (; iVar1 = local_500, puVar24 = local_4b8, puVar6 != (uint *)0x0;
              puVar6 = (uint *)puVar6[7]) {
            if (local_500 == 0) {
                    /* WARNING: Subroutine does not return */
              __assert_fail("pkg && pkg->fd && item",
                            "apps/verified-test/fw_ab_upgrade/fw_ab_upgrade.c",0x37b,"item_check");
            }
            piVar9 = (int *)malloc(0x1000);
            if (piVar9 == (int *)0x0) {
              __android_log_print(6,"FW_AB_UPGRADE","failed to malloc, size:%u",0x1000);
LAB_00011c54:
              __android_log_print(6,"FW_AB_UPGRADE","item %s check error",puVar6,puVar23,puVar22);
              __android_log_print(6,"FW_AB_UPGRADE","package check error");
              goto LAB_0001155e;
            }
            puVar24 = (uint *)0x0;
            lseek(iVar1,puVar6[6],0);
            for (uVar7 = puVar6[5]; uVar7 != 0; uVar7 = uVar7 - uVar20) {
              uVar20 = uVar7;
              if (0xfff < uVar7) {
                uVar20 = 0x1000;
              }
              uVar10 = read(local_500,piVar9,uVar20);
              if (uVar10 != uVar20) {
                __android_log_print(6,"FW_AB_UPGRADE","failed to read data of item %s",puVar6);
                puVar12 = puVar22;
                goto LAB_00011c9e;
              }
              uVar10 = uVar20 >> 2;
              if (uVar10 != 0) {
                piVar11 = piVar9 + uVar10;
                uVar10 = 0;
                piVar18 = piVar9;
                do {
                  piVar17 = piVar18 + 1;
                  uVar10 = uVar10 + *piVar18;
                  piVar18 = piVar17;
                } while (piVar11 != piVar17);
              }
              puVar24 = (uint *)((int)puVar24 + uVar10);
            }
            puVar12 = (uint *)puVar6[3];
            if (puVar24 != puVar12) {
              puVar23 = puVar6;
              __android_log_print(6,"FW_AB_UPGRADE",
                                  "calculated sum %u of item %s not equals to the hash %u",puVar24,
                                  puVar6,puVar12);
LAB_00011c9e:
              free(piVar9);
              puVar22 = puVar12;
              goto LAB_00011c54;
            }
            free(piVar9);
          }
          for (; puVar24 != (uint *)0x0; puVar24 = (uint *)puVar24[7]) {
            sVar5 = strlen((char *)puVar24);
            if (0xf < sVar5) {
              __android_log_print(6,"FW_AB_UPGRADE","%s is too long for a partition name",puVar24);
LAB_00011db2:
              __android_log_print(6,"FW_AB_UPGRADE","failed to found partition %s in imbr",puVar24);
LAB_00011dc2:
              __android_log_print(6,"FW_AB_UPGRADE","device check error");
              goto LAB_0001155e;
            }
            iVar1 = 0;
            do {
              iVar8 = strncmp((char *)puVar24,acStack_41f + iVar1,10);
              if (iVar8 == 0) {
                iVar1 = iVar1 + 0x54;
                goto LAB_00011d1a;
              }
              iVar1 = iVar1 + 0x20;
            } while (iVar1 != 0x1e0);
            iVar1 = 0x200;
            while (iVar8 = strncmp((char *)puVar24,acStack_42b + iVar1,10), iVar8 != 0) {
              iVar1 = iVar1 + 0x20;
              if (iVar1 == 0x400) goto LAB_00011db2;
            }
            iVar1 = iVar1 + 0x48;
LAB_00011d1a:
            if (*(char *)(iVar1 + (int)local_474) == '\0') {
              __android_log_print(6,"FW_AB_UPGRADE","boot index of partition %s is 0",puVar24);
              goto LAB_00011dc2;
            }
            uVar7 = *(int *)((int)local_45c + iVar1) * 0x200;
            if (uVar7 < puVar24[5]) {
              __android_log_print(6,"FW_AB_UPGRADE",
                                  "size of item %s (%u) large than corresponding partition (%u)",
                                  puVar24,puVar24[5],uVar7);
              goto LAB_00011dc2;
            }
            local_4b4[0] = '\0';
            local_4b4[1] = '\0';
            local_4b4[2] = '\0';
            local_4b4[3] = '\0';
            local_4b4[4] = '\0';
            local_4b4[5] = '\0';
            local_4b4[6] = '\0';
            local_4b4[7] = '\0';
            local_4b4[8] = '\0';
            local_4b4[9] = '\0';
            local_4b4[10] = '\0';
            local_4b4[0xb] = '\0';
            local_4b4[0xc] = '\0';
            local_4b4[0xd] = '\0';
            local_4b4[0xe] = '\0';
            local_4b4[0xf] = '\0';
            local_4b4[0x10] = '\0';
            local_4b4[0x11] = '\0';
            local_4b4[0x12] = '\0';
            local_4b4[0x13] = '\0';
            local_4b4[0x14] = '\0';
            local_4b4[0x15] = '\0';
            local_4b4[0x16] = '\0';
            local_4b4[0x17] = '\0';
            local_4b4[0x18] = '\0';
            local_4b4[0x19] = '\0';
            local_4b4[0x1a] = '\0';
            local_4b4[0x1b] = '\0';
            local_4b4[0x1c] = '\0';
            local_4b4[0x1d] = '\0';
            local_4b4[0x1e] = '\0';
            local_4b4[0x1f] = '\0';
            local_4b4[0x20] = '\0';
            local_4b4[0x21] = '\0';
            local_4b4[0x22] = '\0';
            local_4b4[0x23] = '\0';
            local_4b4[0x24] = '\0';
            local_4b4[0x25] = '\0';
            local_4b4[0x26] = '\0';
            local_4b4[0x27] = '\0';
            local_4b4[0x28] = '\0';
            local_4b4[0x29] = '\0';
            local_4b4[0x2a] = '\0';
            local_4b4[0x2b] = '\0';
            local_4b4[0x2c] = '\0';
            local_4b4[0x2d] = '\0';
            local_4b4[0x2e] = '\0';
            local_4b4[0x2f] = '\0';
            local_4b4[0x30] = '\0';
            local_4b4[0x31] = '\0';
            local_4b4[0x32] = '\0';
            local_4b4[0x33] = '\0';
            local_4b4[0x34] = '\0';
            local_4b4[0x35] = '\0';
            local_4b4[0x36] = '\0';
            local_4b4[0x37] = '\0';
            local_4b4[0x38] = '\0';
            local_4b4[0x39] = '\0';
            local_4b4[0x3a] = '\0';
            local_4b4[0x3b] = '\0';
            local_4b4[0x3c] = '\0';
            local_4b4[0x3d] = '\0';
            local_4b4[0x3e] = '\0';
            local_4b4[0x3f] = '\0';
            sprintf(local_4b4,"/dev/block/%s",puVar24);
            iVar1 = open(local_4b4,0);
            if (iVar1 < 0) {
              __android_log_print(6,"FW_AB_UPGRADE","failed to open %s",local_4b4);
              goto LAB_00011dc2;
            }
            uVar20 = lseek(iVar1,0,2);
            close(iVar1);
            if (uVar7 != uVar20) {
              __android_log_print(6,"FW_AB_UPGRADE",
                                  "size of block device %s (%u) not equals to corresponding partition (%u)"
                                  ,local_4b4,uVar20,uVar7);
              goto LAB_00011dc2;
            }
          }
          puVar22 = (uint *)0x0;
          puVar23 = local_4b8;
          while (iVar1 = local_4d4, puVar23 != (uint *)0x0) {
            iVar1 = strcmp((char *)puVar23,"misc");
            if (iVar1 == 0) {
              puVar22 = puVar23;
              puVar23 = (uint *)puVar23[7];
            }
            else {
              iVar1 = FUN_00012b58(&local_500,puVar23);
              if (iVar1 != 0) {
                __android_log_print(6,"FW_AB_UPGRADE","failed to write block device %s",puVar23);
                goto LAB_00012302;
              }
              puVar23 = (uint *)puVar23[7];
            }
          }
          if (puVar22 == (uint *)0x0) {
            __android_log_print(6,"FW_AB_UPGRADE","not misc item in the update list");
          }
          else {
            if (local_4d4 == local_474[1]) {
              iVar8 = FUN_00012d28(&local_4f8,puVar22[4]);
              puVar22[3] = puVar22[3] - iVar8;
              if (1 < local_4d4 - 1U) {
                    /* WARNING: Subroutine does not return */
                __assert_fail("(pkg->misc.select == 1) || (pkg->misc.select == 2)",
                              "apps/verified-test/fw_ab_upgrade/fw_ab_upgrade.c",0x465,
                              "misc_calibrate_write");
              }
              if (1 < iVar1 - 1U) {
                    /* WARNING: Subroutine does not return */
                __assert_fail("(dev->boot_zone == 1) || (dev->boot_zone == 2)",
                              "apps/verified-test/fw_ab_upgrade/fw_ab_upgrade.c",0x466,
                              "misc_calibrate_write");
              }
              if (iVar1 != local_4d4) {
                    /* WARNING: Subroutine does not return */
                __assert_fail("pkg->misc.select == dev->boot_zone",
                              "apps/verified-test/fw_ab_upgrade/fw_ab_upgrade.c",0x467,
                              "misc_calibrate_write");
              }
              if (iVar1 == 1) {
                local_4d4 = 2;
              }
              else {
                local_4d4 = 1;
              }
              local_4f0 = FUN_00012a28(&local_4f8);
              pvVar19 = malloc(0x1000);
              if (pvVar19 == (void *)0x0) {
                __android_log_print(6,"FW_AB_UPGRADE","failed to malloc, size:%u",0x1000);
              }
              else {
                iVar1 = open("/dev/block/misc",0x101001);
                if (iVar1 < 0) {
                  __android_log_print(6,"FW_AB_UPGRADE","failed to open %s","/dev/block/misc");
                }
                else {
                  uVar7 = puVar22[5];
                  if (uVar7 < 0x40) {
                    /* WARNING: Subroutine does not return */
                    __assert_fail("total_len >= sizeof(misc_t)",
                                  "apps/verified-test/fw_ab_upgrade/fw_ab_upgrade.c",0x47a,
                                  "misc_calibrate_write");
                  }
                  lseek(iVar1,0,0);
                  sVar3 = write(iVar1,&local_4f8,0x40);
                  if (sVar3 == 0x40) {
                    lseek(local_500,puVar22[6] + 0x40,0);
                    for (uVar7 = uVar7 - 0x40; uVar7 != 0; uVar7 = uVar7 - uVar20) {
                      uVar20 = uVar7;
                      if (0xfff < uVar7) {
                        uVar20 = 0x1000;
                      }
                      sVar5 = read(local_500,pvVar19,uVar20);
                      if (uVar20 != sVar5) {
                        __android_log_print(6,"FW_AB_UPGRADE",
                                            "failed to read data of item %s, size:%d",puVar22,uVar20
                                           );
                        goto LAB_000122e8;
                      }
                      decode(pvVar19,uVar20,puVar22[4]);
                      sVar5 = write(iVar1,pvVar19,uVar20);
                      if (uVar20 != sVar5) {
                        __android_log_print(6,"FW_AB_UPGRADE","failed to write to %s, size:%d",
                                            "/dev/block/misc",uVar20);
                        goto LAB_000122e8;
                      }
                    }
                    fsync(iVar1);
                    close(iVar1);
                    free(pvVar19);
                    iVar1 = FUN_00012d28(&local_4f8,puVar22[4]);
                    puVar22[3] = puVar22[3] + iVar1;
                    goto LAB_00011e40;
                  }
                  __android_log_print(6,"FW_AB_UPGRADE","failed to write to %s, size:%d",
                                      "/dev/block/misc",0x40);
LAB_000122e8:
                  close(iVar1);
                }
                free(pvVar19);
              }
            }
            else {
              iVar1 = FUN_00012b58(&local_500,&DAT_00013f64);
              if (iVar1 == 0) {
LAB_00011e40:
                for (puVar22 = local_4b8; puVar22 != (uint *)0x0; puVar22 = (uint *)puVar22[7]) {
                  iVar1 = FUN_00012b38(&local_500,puVar22);
                  if (iVar1 == 0) {
                    __android_log_print(6,"FW_AB_UPGRADE",
                                        "failed to get item %s from item list of package",puVar22);
LAB_00011f16:
                    __android_log_print(6,"FW_AB_UPGRADE","block device %s verify error",puVar22);
                    __android_log_print(6,"FW_AB_UPGRADE","upgrade verify error");
                    goto LAB_0001155e;
                  }
                  piVar9 = (int *)malloc(0x1000);
                  if (piVar9 == (int *)0x0) {
                    __android_log_print(6,"FW_AB_UPGRADE","failed to malloc, size:%u",0x1000);
                    goto LAB_00011f16;
                  }
                  local_4b4[0] = '\0';
                  local_4b4[1] = '\0';
                  local_4b4[2] = '\0';
                  local_4b4[3] = '\0';
                  local_4b4[4] = '\0';
                  local_4b4[5] = '\0';
                  local_4b4[6] = '\0';
                  local_4b4[7] = '\0';
                  local_4b4[8] = '\0';
                  local_4b4[9] = '\0';
                  local_4b4[10] = '\0';
                  local_4b4[0xb] = '\0';
                  local_4b4[0xc] = '\0';
                  local_4b4[0xd] = '\0';
                  local_4b4[0xe] = '\0';
                  local_4b4[0xf] = '\0';
                  local_4b4[0x10] = '\0';
                  local_4b4[0x11] = '\0';
                  local_4b4[0x12] = '\0';
                  local_4b4[0x13] = '\0';
                  local_4b4[0x14] = '\0';
                  local_4b4[0x15] = '\0';
                  local_4b4[0x16] = '\0';
                  local_4b4[0x17] = '\0';
                  local_4b4[0x18] = '\0';
                  local_4b4[0x19] = '\0';
                  local_4b4[0x1a] = '\0';
                  local_4b4[0x1b] = '\0';
                  local_4b4[0x1c] = '\0';
                  local_4b4[0x1d] = '\0';
                  local_4b4[0x1e] = '\0';
                  local_4b4[0x1f] = '\0';
                  local_4b4[0x20] = '\0';
                  local_4b4[0x21] = '\0';
                  local_4b4[0x22] = '\0';
                  local_4b4[0x23] = '\0';
                  local_4b4[0x24] = '\0';
                  local_4b4[0x25] = '\0';
                  local_4b4[0x26] = '\0';
                  local_4b4[0x27] = '\0';
                  local_4b4[0x28] = '\0';
                  local_4b4[0x29] = '\0';
                  local_4b4[0x2a] = '\0';
                  local_4b4[0x2b] = '\0';
                  local_4b4[0x2c] = '\0';
                  local_4b4[0x2d] = '\0';
                  local_4b4[0x2e] = '\0';
                  local_4b4[0x2f] = '\0';
                  local_4b4[0x30] = '\0';
                  local_4b4[0x31] = '\0';
                  local_4b4[0x32] = '\0';
                  local_4b4[0x33] = '\0';
                  local_4b4[0x34] = '\0';
                  local_4b4[0x35] = '\0';
                  local_4b4[0x36] = '\0';
                  local_4b4[0x37] = '\0';
                  local_4b4[0x38] = '\0';
                  local_4b4[0x39] = '\0';
                  local_4b4[0x3a] = '\0';
                  local_4b4[0x3b] = '\0';
                  local_4b4[0x3c] = '\0';
                  local_4b4[0x3d] = '\0';
                  local_4b4[0x3e] = '\0';
                  local_4b4[0x3f] = '\0';
                  sprintf(local_4b4,"/dev/block/%s",puVar22);
                  iVar8 = open(local_4b4,0);
                  if (iVar8 < 0) {
                    __android_log_print(6,"FW_AB_UPGRADE","failed to open %s",local_4b4);
LAB_00011f4a:
                    free(piVar9);
                    goto LAB_00011f16;
                  }
                  iVar25 = 0;
                  lseek(iVar8,0,0);
                  for (uVar7 = *(uint *)(iVar1 + 0x14); uVar7 != 0; uVar7 = uVar7 - uVar20) {
                    uVar20 = uVar7;
                    if (0xfff < uVar7) {
                      uVar20 = 0x1000;
                    }
                    uVar10 = read(iVar8,piVar9,uVar20);
                    if (uVar20 != uVar10) {
                      __android_log_print(6,"FW_AB_UPGRADE","failed to read %s",local_4b4);
                      goto LAB_00011f9e;
                    }
                    encode(piVar9,uVar20,*(undefined4 *)(iVar1 + 0x10));
                    iVar13 = 0;
                    for (piVar18 = piVar9; piVar18 != (int *)((uVar20 & 0xfffffffc) + (int)piVar9);
                        piVar18 = piVar18 + 1) {
                      iVar13 = iVar13 + *piVar18;
                    }
                    iVar25 = iVar25 + iVar13;
                  }
                  if (iVar25 != *(int *)(iVar1 + 0xc)) {
                    __android_log_print(6,"FW_AB_UPGRADE",
                                        "calculated sum %u of %s not equals to the hash %u",iVar25,
                                        local_4b4,*(int *)(iVar1 + 0xc));
LAB_00011f9e:
                    close(iVar8);
                    goto LAB_00011f4a;
                  }
                  close(iVar8);
                  free(piVar9);
                }
                FUN_00012a00(&local_500);
                if (bVar26) {
                  unlink(__name);
                }
                __android_log_print(3,"FW_AB_UPGRADE","fw_ab_upgrade success...");
                if (iVar21 != 0) {
                  iVar21 = 0;
                  system("reboot");
                }
                goto LAB_000113f2;
              }
            }
            __android_log_print(6,"FW_AB_UPGRADE","failed to write block device misc");
          }
LAB_00012302:
          __android_log_print(6,"FW_AB_UPGRADE","upgrade write error");
        }
        else {
          __android_log_print(6,"FW_AB_UPGRADE",
                              "board flag of package %u not equals to the one of device %u",
                              local_4ec,local_460);
LAB_00012350:
          __android_log_print(6,"FW_AB_UPGRADE","board check error");
        }
      }
      else {
        __android_log_print(6,"FW_AB_UPGRADE","failed to get info of item %s","leaver_item");
LAB_00011934:
        __android_log_print(6,"FW_AB_UPGRADE","failed to get imbr of device");
LAB_00011946:
        __android_log_print(6,"FW_AB_UPGRADE","failed to create device info");
      }
    }
    else {
      pvVar19 = (void *)0x0;
      __android_log_print(6,"FW_AB_UPGRADE","package file %s is not exist",__name);
LAB_0001152c:
      FUN_000129e4(&local_500);
      if (local_4fc != 0) {
        unpack_uninit();
        local_4fc = 0;
      }
      if (-1 < local_500) {
        close(local_500);
        local_500 = -1;
      }
      if (pvVar19 != (void *)0x0) {
        free(pvVar19);
      }
      __android_log_print(6,"FW_AB_UPGRADE","failed to create package info");
    }
  }
LAB_0001155e:
  iVar21 = -1;
  FUN_00012a00(&local_500);
  __android_log_print(6,"FW_AB_UPGRADE","fw_ab_upgrade failed...");
LAB_000113f2:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar21);
}



void _start(undefined4 param_1)

{
  undefined4 in_stack_00000000;
  
  __libc_start_main(0x11371,in_stack_00000000,&stack0x00000004,0x13ca9,0x13ce5,param_1);
                    /* WARNING: Subroutine does not return */
  abort();
}



/* WARNING: Removing unreachable block (ram,0x0001277c) */

void FUN_00012768(void)

{
  __gmon_start__();
  return;
}



/* WARNING: Removing unreachable block (ram,0x000127a0) */
/* WARNING: Removing unreachable block (ram,0x000127aa) */

void FUN_0001278c(void)

{
  return;
}



/* WARNING: Removing unreachable block (ram,0x000127cc) */
/* WARNING: Removing unreachable block (ram,0x000127d6) */

void FUN_000127b0(void)

{
  return;
}



void _FINI_0(void)

{
  if (_edata == '\0') {
    FUN_0001278c();
    _edata = '\x01';
  }
  return;
}



/* WARNING: Removing unreachable block (ram,0x000127cc) */
/* WARNING: Removing unreachable block (ram,0x000127d6) */

void _INIT_0(void)

{
  return;
}



undefined4
FUN_000127f8(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5,
            undefined4 *param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined1 auStack_28 [4];
  undefined4 local_24;
  undefined1 auStack_20 [4];
  undefined4 local_1c;
  
  if (param_1 != 0 && param_2 != 0) {
    iVar1 = unpack_isvalid();
    if (iVar1 == 0) {
      iVar1 = unpack_get_item_byname(param_1,1,param_2);
      if (iVar1 == 0) {
        __android_log_print(6,"FW_AB_UPGRADE","failed to get item %s",param_2);
        uVar3 = 0xffffffff;
      }
      else {
        iVar2 = unpack_get_item_hash(param_1,iVar1,&local_30);
        if (iVar2 == 0) {
          iVar2 = unpack_get_item_attr(param_1,iVar1,&uStack_2c);
          if (iVar2 == 0) {
            iVar2 = unpack_get_item_itemlen(param_1,iVar1,&local_24,auStack_28);
            if (iVar2 == 0) {
              iVar1 = unpack_get_data_offset(param_1,iVar1,auStack_20,&local_1c);
              if (iVar1 == 0) {
                *param_3 = local_30;
                *param_4 = uStack_2c;
                *param_5 = local_24;
                *param_6 = local_1c;
                uVar3 = 0;
              }
              else {
                __android_log_print(6,"FW_AB_UPGRADE","failed to get offset of item %s",param_2);
                uVar3 = 0xffffffff;
              }
            }
            else {
              __android_log_print(6,"FW_AB_UPGRADE","failed to get length of item %s",param_2);
              uVar3 = 0xffffffff;
            }
          }
          else {
            __android_log_print(6,"FW_AB_UPGRADE","failed to get attr of item %s",param_2);
            uVar3 = 0xffffffff;
          }
        }
        else {
          __android_log_print(6,"FW_AB_UPGRADE","failed to get hash of item %s",param_2);
          uVar3 = 0xffffffff;
        }
      }
    }
    else {
      __android_log_print(6,"FW_AB_UPGRADE","invalid unpack handle");
      uVar3 = 0xffffffff;
    }
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("handle && name && hash && attr && length && offset",
                "apps/verified-test/fw_ab_upgrade/fw_ab_upgrade.c",99,"get_item_info");
}



void FUN_00012950(int param_1)

{
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("argv0","apps/verified-test/fw_ab_upgrade/fw_ab_upgrade.c",0x56e,"usage");
  }
  fprintf(stderr,"Usage: %s [options]\n",param_1);
  fwrite(" -p path\tPath of package file\n",1,0x1e,stderr);
  fwrite(" -d\t\tDelete package\n",1,0x14,stderr);
  fwrite(" -r\t\tReboot system\n",1,0x13,stderr);
  fwrite(&UNK_00013f58,1,10,stderr);
  return;
}



void FUN_000129e4(int param_1)

{
  void *__ptr;
  void *pvVar1;
  
  __ptr = *(void **)(param_1 + 0x48);
  *(undefined4 *)(param_1 + 0x48) = 0;
  if (__ptr == (void *)0x0) {
    return;
  }
  do {
    pvVar1 = *(void **)((int)__ptr + 0x1c);
    free(__ptr);
    __ptr = pvVar1;
  } while (pvVar1 != (void *)0x0);
  return;
}



void FUN_00012a00(int *param_1)

{
  FUN_000129e4();
  if (param_1[1] != 0) {
    unpack_uninit();
    param_1[1] = 0;
  }
  if (-1 < *param_1) {
    close(*param_1);
    *param_1 = -1;
  }
  return;
}



int FUN_00012a28(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int local_58 [16];
  int iStack_18;
  int *piVar6;
  
  puVar7 = param_1;
  piVar5 = local_58;
  if (param_1 != (undefined4 *)0x0) {
    do {
      puVar8 = puVar7 + 4;
      uVar2 = puVar7[1];
      uVar3 = puVar7[2];
      uVar4 = puVar7[3];
      *piVar5 = *puVar7;
      piVar5[1] = uVar2;
      piVar5[2] = uVar3;
      piVar5[3] = uVar4;
      puVar7 = puVar8;
      piVar5 = piVar5 + 4;
    } while (puVar8 != param_1 + 0x10);
    local_58[2] = 0x12345678;
    iVar1 = 0;
    piVar5 = local_58;
    do {
      piVar6 = piVar5 + 1;
      iVar1 = iVar1 + *piVar5;
      piVar5 = piVar6;
    } while (piVar6 != &iStack_18);
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("misc","apps/verified-test/fw_ab_upgrade/fw_ab_upgrade.c",0x9d,"misc_check_code");
}



undefined4 FUN_00012a90(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("misc","apps/verified-test/fw_ab_upgrade/fw_ab_upgrade.c",0xae,"misc_data_check");
  }
  if (*param_1 == 0x20545055) {
    if (param_1[9] - 1U < 2) {
      iVar1 = FUN_00012a28();
      if (param_1[2] == iVar1) {
        uVar2 = 0;
      }
      else {
        __android_log_print(6,"FW_AB_UPGRADE","misc get bad check code 0x%08x (0x%08x)",param_1[2],
                            iVar1);
        uVar2 = 0xffffffff;
      }
    }
    else {
      __android_log_print(6,"FW_AB_UPGRADE","misc get bad select %u");
      uVar2 = 0xffffffff;
    }
  }
  else {
    __android_log_print(6,"FW_AB_UPGRADE","misc get bad magic 0x%08x");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



char * FUN_00012b38(int param_1,char *param_2)

{
  int iVar1;
  char *__s1;
  
  __s1 = *(char **)(param_1 + 0x48);
  while ((__s1 != (char *)0x0 && (iVar1 = strcmp(__s1,param_2), iVar1 != 0))) {
    __s1 = *(char **)(__s1 + 0x1c);
  }
  return __s1;
}



void FUN_00012b58(int *param_1,undefined4 param_2)

{
  int iVar1;
  void *__buf;
  int __fd;
  size_t sVar2;
  size_t __n;
  undefined4 uVar3;
  uint uVar4;
  uint __nbytes;
  undefined8 local_6c;
  undefined8 uStack_64;
  undefined8 local_5c;
  undefined8 local_54;
  undefined8 local_4c;
  undefined8 local_44;
  undefined8 local_3c;
  undefined8 local_34;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (*param_1 < 1) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("pkg && pkg->fd > 0 && name","apps/verified-test/fw_ab_upgrade/fw_ab_upgrade.c",
                  0x416,"block_dev_write");
  }
  iVar1 = FUN_00012b38();
  if (iVar1 == 0) {
    __android_log_print(6,"FW_AB_UPGRADE","failed to get item %s from item list of package",param_2)
    ;
    uVar3 = 0xffffffff;
  }
  else {
    __buf = malloc(0x1000);
    if (__buf == (void *)0x0) {
      __android_log_print(6,"FW_AB_UPGRADE","failed to malloc, size:%u",0x1000);
      uVar3 = 0xffffffff;
    }
    else {
      local_6c = 0;
      uStack_64 = 0;
      local_5c = 0;
      local_54 = 0;
      local_4c = 0;
      local_44 = 0;
      local_3c = 0;
      local_34 = 0;
      sprintf((char *)&local_6c,"/dev/block/%s",param_2);
      __fd = open((char *)&local_6c,0x101001);
      if (__fd < 0) {
        __android_log_print(6,"FW_AB_UPGRADE","failed to open %s",&local_6c);
LAB_00012c96:
        free(__buf);
        uVar3 = 0xffffffff;
      }
      else {
        lseek(*param_1,*(__off_t *)(iVar1 + 0x18),0);
        lseek(__fd,0,0);
        for (uVar4 = *(uint *)(iVar1 + 0x14); uVar4 != 0; uVar4 = uVar4 - sVar2) {
          __nbytes = uVar4;
          if (0xfff < uVar4) {
            __nbytes = 0x1000;
          }
          __n = read(*param_1,__buf,__nbytes);
          if (__n != __nbytes) {
            __android_log_print(6,"FW_AB_UPGRADE","failed to read data of item %s, size:%d",param_2,
                                __nbytes);
LAB_00012c42:
            close(__fd);
            goto LAB_00012c96;
          }
          decode(__buf,__n,*(undefined4 *)(iVar1 + 0x10));
          sVar2 = write(__fd,__buf,__n);
          if (sVar2 != __n) {
            __android_log_print(6,"FW_AB_UPGRADE","failed to write to %s, size:%d",&local_6c,__n);
            goto LAB_00012c42;
          }
        }
        fsync(__fd);
        close(__fd);
        free(__buf);
        uVar3 = 0;
      }
    }
  }
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar3);
}



int FUN_00012d28(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int local_50 [16];
  int *piVar3;
  
  local_50[0] = *param_1;
  local_50[1] = param_1[1];
  local_50[2] = param_1[2];
  local_50[3] = param_1[3];
  local_50[4] = param_1[4];
  local_50[5] = param_1[5];
  local_50[6] = param_1[6];
  local_50[7] = param_1[7];
  local_50[8] = param_1[8];
  local_50[9] = param_1[9];
  local_50[10] = param_1[10];
  local_50[0xb] = param_1[0xb];
  local_50[0xc] = param_1[0xc];
  local_50[0xd] = param_1[0xd];
  local_50[0xe] = param_1[0xe];
  local_50[0xf] = param_1[0xf];
  encode(local_50,param_2,0x40);
  iVar1 = 0;
  piVar2 = local_50;
  do {
    piVar3 = piVar2 + 1;
    iVar1 = iVar1 + *piVar2;
    piVar2 = piVar3;
  } while (piVar3 != (int *)&stack0xfffffff0);
  return iVar1;
}



uint data_left(int param_1,int param_2,uint param_3)

{
  return (param_1 >> (param_2 - param_3 & 0xff) | param_1 << (param_3 & 0xff)) & 0xffff;
}



uint data_right(int param_1,int param_2,uint param_3)

{
  return (param_1 << (param_2 - param_3 & 0xff) | param_1 >> (param_3 & 0xff)) & 0xffff;
}



undefined4 encode(short *param_1,uint param_2,undefined1 param_3)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  
  if (param_2 >> 1 != 0) {
    psVar2 = param_1;
    do {
      psVar3 = psVar2 + 1;
      if (*psVar2 != 0) {
        sVar1 = data_left(*psVar2,0x10,param_3);
        *psVar2 = sVar1;
      }
      psVar2 = psVar3;
    } while (psVar3 != param_1 + (param_2 >> 1));
    return 0;
  }
  return 0;
}



undefined4 decode(short *param_1,uint param_2,undefined1 param_3)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  
  if (param_2 >> 1 != 0) {
    psVar2 = param_1;
    do {
      psVar3 = psVar2 + 1;
      if (*psVar2 != 0) {
        sVar1 = data_right(*psVar2,0x10,param_3);
        *psVar2 = sVar1;
      }
      psVar2 = psVar3;
    } while (psVar3 != param_1 + (param_2 >> 1));
    return 0;
  }
  return 0;
}



undefined4
unpack_buf_read(int param_1,void *param_2,int param_3,undefined4 param_4,size_t param_5,
               size_t param_6,size_t *param_7)

{
  memcpy(param_2,(void *)(param_3 + param_1),param_5);
  *param_7 = param_5;
  param_7[1] = param_6;
  return 0;
}



undefined4 unpack_blk_read(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("NULL != handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x87,
                  "unpack_blk_read");
  }
  if (*(int *)(param_1 + 0x108) != 1) {
    return 0;
  }
  uVar1 = unpack_buf_read(*(undefined4 *)(param_1 + 0x10c));
  return uVar1;
}



void * unpack_init(undefined4 param_1,int param_2)

{
  void *__ptr;
  int iVar1;
  void *pvVar2;
  int iVar3;
  void *__ptr_00;
  int iVar4;
  size_t sVar5;
  undefined8 local_30;
  
  local_30 = 0;
  __ptr = calloc(0x1c0,1);
  if (__ptr == (void *)0x0) {
LAB_00012f86:
    if (*(void **)((int)__ptr + 0x1ac) == (void *)0x0) {
LAB_00012fd0:
      if (*(int *)((int)__ptr + 0x1a4) != 0) {
        strtab_uninit();
      }
      goto LAB_00012fae;
    }
    pvVar2 = (void *)0x0;
    free(*(void **)((int)__ptr + 0x1ac));
    *(undefined4 *)((int)__ptr + 0x1ac) = 0;
    if (*(int *)((int)__ptr + 0x1a4) == 0) goto LAB_00012fae;
LAB_00012f9c:
    strtab_uninit();
    *(undefined4 *)((int)__ptr + 0x1a4) = 0;
    if (pvVar2 == (void *)0x0) goto LAB_00012fae;
  }
  else {
    *(int *)((int)__ptr + 0x108) = param_2;
    if (param_2 == 1) {
      *(undefined4 *)((int)__ptr + 0x10c) = param_1;
    }
    iVar1 = unpack_blk_read(__ptr,(int)__ptr + 0x114,0,0,0x20,0,&local_30);
    if ((((iVar1 != 0) || (*(int *)((int)__ptr + 0x114) != 0x204b5020)) ||
        (iVar1 = unpack_blk_read(__ptr,(int)__ptr + 0x134,0x20,0,0x40,0,&local_30), iVar1 != 0)) ||
       (iVar1 = unpack_blk_read(__ptr,(int)__ptr + 0x174,0x60,0,0x30,0,&local_30), iVar1 != 0))
    goto LAB_00012f86;
    sVar5 = *(size_t *)((int)__ptr + 0x18c);
    pvVar2 = calloc(sVar5,1);
    if (pvVar2 == (void *)0x0) goto LAB_00012f86;
    iVar1 = unpack_blk_read(__ptr,pvVar2,*(undefined4 *)((int)__ptr + 0x194),
                            *(undefined4 *)((int)__ptr + 0x198),sVar5,0,&local_30);
    if (iVar1 == 0) {
      iVar1 = strtab_init(0x800,0x10);
      *(int *)((int)__ptr + 0x1a4) = iVar1;
      if (iVar1 == 0) {
        __ptr_00 = *(void **)((int)__ptr + 0x1ac);
        if (__ptr_00 != (void *)0x0) goto LAB_00012fe4;
        goto LAB_00012fa8;
      }
      strtab_set_strbuf(iVar1,pvVar2,sVar5);
      free(pvVar2);
      if (*(int *)((int)__ptr + 0x1a4) == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("NULL != handle->hstab","apps/verified-test/fw_ab_upgrade/unpack.c",0x136,
                      "dump_string_table");
      }
      iVar3 = strtab_get_cnt();
      iVar1 = 0;
      if (iVar3 != 0) {
        do {
          iVar4 = iVar1 + 1;
          strtab_get_str_byIndex(*(undefined4 *)((int)__ptr + 0x1a4),iVar1);
          iVar1 = iVar4;
        } while (iVar3 != iVar4);
      }
      sVar5 = *(int *)((int)__ptr + 0x178) * 0x50;
      pvVar2 = calloc(sVar5,1);
      *(void **)((int)__ptr + 0x1ac) = pvVar2;
      if (pvVar2 != (void *)0x0) {
        iVar1 = unpack_blk_read(__ptr,pvVar2,*(undefined4 *)((int)__ptr + 0x17c),
                                *(undefined4 *)((int)__ptr + 0x180),sVar5,0,&local_30);
        if (iVar1 == 0) {
          return __ptr;
        }
        goto LAB_00012f86;
      }
      goto LAB_00012fd0;
    }
    __ptr_00 = *(void **)((int)__ptr + 0x1ac);
    if (__ptr_00 == (void *)0x0) {
      iVar1 = *(int *)((int)__ptr + 0x1a4);
    }
    else {
LAB_00012fe4:
      free(__ptr_00);
      iVar1 = *(int *)((int)__ptr + 0x1a4);
      *(undefined4 *)((int)__ptr + 0x1ac) = 0;
    }
    if (iVar1 != 0) goto LAB_00012f9c;
  }
LAB_00012fa8:
  free(pvVar2);
LAB_00012fae:
  free(__ptr);
  printf("err: %s %d failed to read pkg.\n","unpack_init",0x128);
  return (void *)0x0;
}



undefined4 unpack_uninit(void *param_1)

{
  if (param_1 != (void *)0x0) {
    if (*(int *)((int)param_1 + 0x1a4) != 0) {
      strtab_uninit();
      *(undefined4 *)((int)param_1 + 0x1a4) = 0;
    }
    if (*(int *)((int)param_1 + 0x104) != 0) {
      *(undefined4 *)((int)param_1 + 0x104) = 0;
    }
    if (*(void **)((int)param_1 + 0x1ac) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x1ac));
    }
    free(param_1);
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("NULL != handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x14d,"unpack_uninit");
}



undefined4 unpack_isvalid(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("NULL != handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x16e,
                  "unpack_isvalid");
  }
  iVar1 = strcmp((char *)(param_1 + 0x114)," PK ");
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x178) + 1 == *(int *)(param_1 + 400)) {
      return 0;
    }
    printf("Err:%s %d item_cnt=%d str_cnt=%d \n","apps/verified-test/fw_ab_upgrade/unpack.c",0x179,
           *(int *)(param_1 + 0x178),*(int *)(param_1 + 400));
    return 0x17a;
  }
  printf("Err:%s %d magic error \n","apps/verified-test/fw_ab_upgrade/unpack.c",0x172);
  return 0x173;
}



undefined4 unpack_get_ver(int param_1,undefined4 *param_2)

{
  if (param_1 != 0) {
    *param_2 = *(undefined4 *)(param_1 + 0x11c);
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("NULL != handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x189,"unpack_get_ver")
  ;
}



void unpack_get_sztype(int param_1,undefined4 *param_2)

{
  if (param_1 != 0) {
    *param_2 = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("NULL != handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x197,
                "unpack_get_sztype");
}



undefined4 unpack_get_align(int param_1,undefined4 *param_2)

{
  if (param_1 != 0) {
    *param_2 = 0x10;
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("NULL != handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x1a5,
                "unpack_get_align");
}



undefined4 unpack_get_ID(int param_1)

{
  if (param_1 != 0) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("NULL != handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x1b3,"unpack_get_ID");
}



undefined4 unpack_get_info(int param_1,char *param_2)

{
  if (param_1 != 0) {
    strcpy(param_2,(char *)(param_1 + 0x13c));
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("NULL != handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x1c1,"unpack_get_info"
               );
}



undefined4 unpack_get_dir(int param_1,char *param_2)

{
  char *__src;
  
  if (param_1 != 0) {
    __src = (char *)strtab_get_str_byOffset
                              (*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x160));
    strcpy(param_2,__src);
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("NULL != handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x1d0,"unpack_get_dir")
  ;
}



undefined4 unpack_get_data_offset(int param_1,int param_2,int *param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("NULL != item_handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x1e1,
                  "unpack_get_data_offset");
  }
  if (param_1 != 0) {
    uVar1 = *(uint *)(param_1 + 0x184);
    uVar2 = *(uint *)(*(int *)(param_2 + 4) + 0x40);
    *param_3 = *(int *)(*(int *)(param_2 + 4) + 0x44) +
               *(int *)(param_1 + 0x188) + (uint)CARRY4(uVar2,uVar1);
    *param_4 = uVar2 + uVar1;
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("NULL != handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x1e4,
                "unpack_get_data_offset");
}



undefined4 unpack_get_item_cnt(int param_1,undefined4 *param_2)

{
  if (param_1 != 0) {
    *param_2 = *(undefined4 *)(param_1 + 0x178);
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("NULL != handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x1fa,
                "unpack_get_item_cnt");
}



int unpack_get_item_byindex(int param_1,uint param_2)

{
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("NULL != handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x209,
                  "unpack_get_item_byindex");
  }
  if (param_2 < *(uint *)(param_1 + 0x178)) {
    *(uint *)(param_1 + 0x1b0) = param_2;
    *(undefined4 *)(param_1 + 0x1b8) = 0;
    *(uint *)(param_1 + 0x1b4) = param_2 * 0x50 + *(int *)(param_1 + 0x1ac);
    *(undefined4 *)(param_1 + 0x1bc) = 0;
    return param_1 + 0x1b0;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("index < handle->BlockInfo.section_cnt","apps/verified-test/fw_ab_upgrade/unpack.c",
                0x20a,"unpack_get_item_byindex");
}



undefined4 unpack_get_item_byname(int param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  undefined4 uVar2;
  char *__s1;
  int iVar3;
  int iVar4;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("NULL != handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x21d,
                  "unpack_get_item_byname");
  }
  iVar4 = *(int *)(param_1 + 0x178);
  if (iVar4 != 0) {
    iVar3 = 0;
    __s1 = (char *)(*(int *)(param_1 + 0x1ac) + 0x10);
    do {
      iVar1 = strcmp(__s1,param_3);
      if (iVar1 == 0) {
        uVar2 = unpack_get_item_byindex(param_1,iVar3);
        return uVar2;
      }
      iVar3 = iVar3 + 1;
      __s1 = __s1 + 0x50;
    } while (iVar3 != iVar4);
  }
  return 0;
}



undefined4 unpack_get_item_attr(undefined4 param_1,int param_2,undefined4 *param_3)

{
  if (param_2 != 0) {
    *param_3 = *(undefined4 *)(*(int *)(param_2 + 4) + 0x28);
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("NULL != item_handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x235,
                "unpack_get_item_attr");
}



undefined4 unpack_get_item_hash(undefined4 param_1,int param_2,undefined4 *param_3)

{
  if (param_2 != 0) {
    *param_3 = *(undefined4 *)(*(int *)(param_2 + 4) + 0x2c);
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("NULL != item_handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x244,
                "unpack_get_item_hash");
}



undefined4
unpack_get_item_filelen(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = *(int *)(param_2 + 4);
    *param_3 = *(undefined4 *)(iVar1 + 0x30);
    *param_4 = *(undefined4 *)(iVar1 + 0x34);
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("NULL != item_handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x253,
                "unpack_get_item_filelen");
}



undefined4
unpack_get_item_itemlen(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = *(int *)(param_2 + 4);
    *param_3 = *(undefined4 *)(iVar1 + 0x38);
    *param_4 = *(undefined4 *)(iVar1 + 0x3c);
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("NULL != item_handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x262,
                "unpack_get_item_itemlen");
}



undefined4 unpack_get_item_filename(int param_1,int param_2,char *param_3)

{
  char *__src;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("NULL != handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x272,
                  "unpack_get_item_filename");
  }
  if (param_2 != 0) {
    __src = (char *)strtab_get_str_byOffset
                              (*(undefined4 *)(param_1 + 0x1a4),
                               *(undefined4 *)(*(int *)(param_2 + 4) + 0x48));
    strcpy(param_3,__src);
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("NULL != item_handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x276,
                "unpack_get_item_filename");
}



int unpack_get_item_data
              (int param_1,int param_2,undefined4 param_3,undefined4 param_4,uint param_5,
              uint param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  undefined8 uVar6;
  undefined8 local_30;
  
  local_30 = 0;
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("NULL != handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x288,
                  "unpack_get_item_data");
  }
  if (param_2 != 0) {
    if ((param_5 & 0xf) != 0) {
      printf("Err:%s %d offset(%llx) not align\n","unpack_get_item_data",0x295,param_5 & 0xf,param_5
             ,param_6);
      return 0x296;
    }
    iVar1 = *(int *)(param_2 + 4);
    uVar3 = *(uint *)(iVar1 + 0x3c);
    uVar2 = *(uint *)(iVar1 + 0x38);
    bVar5 = uVar3 <= param_6;
    if (param_6 == uVar3) {
      bVar5 = uVar2 <= param_5;
    }
    if (!bVar5) {
      uVar6 = VectorShiftRight(CONCAT44(param_4,param_4),0x20);
      uVar4 = (int)((ulonglong)uVar6 >> 0x20) + param_6 + CARRY4((uint)uVar6,param_5);
      bVar5 = uVar4 <= uVar3;
      if (uVar3 == uVar4) {
        bVar5 = (uint)uVar6 + param_5 <= uVar2;
      }
      if (bVar5) {
        uVar2 = *(uint *)(param_1 + 0x184) + param_5;
        iVar1 = unpack_blk_read(param_1,param_3,uVar2 + *(uint *)(iVar1 + 0x40),
                                *(int *)(param_1 + 0x188) +
                                param_6 + CARRY4(*(uint *)(param_1 + 0x184),param_5) +
                                *(int *)(iVar1 + 0x44) + (uint)CARRY4(uVar2,*(uint *)(iVar1 + 0x40))
                                ,uVar6,&local_30);
        if (iVar1 == 0) {
          return 0;
        }
        printf("Err: %s %d \n","unpack_get_item_data",0x2a1);
        return iVar1;
      }
    }
    printf("Err:%s %d offset_lo(%x) not valid value=%x buflen=%x\n","unpack_get_item_data",0x2a7,
           param_5 >> 9 | param_6 << 0x17,uVar2 >> 9 | uVar3 << 0x17,param_4);
    return 0x2a8;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("NULL != item_handle","apps/verified-test/fw_ab_upgrade/unpack.c",0x28c,
                "unpack_get_item_data");
}



undefined4 * strtab_init(size_t param_1,undefined4 param_2)

{
  undefined4 *__ptr;
  void *__ptr_00;
  void *pvVar1;
  
  __ptr = (undefined4 *)malloc(0x24);
  if (__ptr == (undefined4 *)0x0) {
    printf("Err: %s %d","strtab_init",0x17);
  }
  else {
    __ptr[2] = param_2;
    __ptr[1] = param_1;
    *(undefined8 *)(__ptr + 6) = 0;
    *__ptr = 0;
    *(undefined8 *)(__ptr + 7) = 0;
    __ptr[3] = 0;
    __ptr[4] = 0;
    __ptr_00 = calloc(param_1,1);
    __ptr[5] = __ptr_00;
    if (__ptr_00 == (void *)0x0) {
      free(__ptr);
      printf("Err: %s %d","strtab_init",0x2e);
      __ptr = (undefined4 *)0x0;
    }
    else {
      __ptr[7] = param_1 >> 1;
      pvVar1 = calloc((param_1 >> 1) << 2,1);
      __ptr[8] = pvVar1;
      if (pvVar1 == (void *)0x0) {
        free(__ptr_00);
        free(__ptr);
        printf("Err: %s %d","strtab_init",0x48);
        __ptr = (undefined4 *)0x0;
      }
    }
  }
  return __ptr;
}



void dump_unsign_data(int param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  
  printf("------------------------------------------------------------");
  printf("len=%d",param_2);
  if (param_2 != 0) {
    pbVar1 = (byte *)(param_1 + -1);
    iVar2 = 0;
    do {
      pbVar1 = pbVar1 + 1;
      printf("[%d]=%02X",iVar2,(uint)*pbVar1);
      iVar2 = iVar2 + 1;
    } while (pbVar1 != (byte *)(param_2 + param_1 + -1));
  }
  printf("------------------------------------------------------------");
  return;
}



int unsign_strlen(char *param_1)

{
  int iVar1;
  
  if (*param_1 != '\0') {
    iVar1 = 0;
    do {
      param_1 = param_1 + 1;
      iVar1 = iVar1 + 1;
    } while (*param_1 != '\0');
    return iVar1;
  }
  return 0;
}



undefined4 strtab_set_strbuf(int *param_1,void *param_2,uint param_3,undefined4 param_4)

{
  size_t sVar1;
  byte *__s;
  undefined4 uVar2;
  int iVar3;
  char *__dest;
  void *pvVar4;
  char *__s_00;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  int *piVar9;
  uint *puVar10;
  uint uVar11;
  
  if (param_1 == (int *)0x0) {
    printf("Err: %s %d","strtab_set_strbuf",0x87,param_4,param_4);
    uVar2 = 0x88;
  }
  else if (param_2 == (void *)0x0) {
    printf("Err: %s %d","strtab_set_strbuf",0x8d,param_4,param_4);
    uVar2 = 0x8e;
  }
  else if (param_3 < (uint)param_1[1]) {
    memset((void *)param_1[5],0,param_1[1]);
    memset((void *)param_1[8],0,param_1[7] << 2);
    memcpy((void *)param_1[5],param_2,param_3);
    pbVar8 = (byte *)param_1[5];
    uVar6 = (uint)*pbVar8;
    uVar11 = uVar6;
    if (uVar6 != 0) {
      uVar6 = 0;
      uVar11 = 0;
      puVar10 = (uint *)(param_1[8] + -4);
      __s = pbVar8;
      do {
        puVar10 = puVar10 + 1;
        *puVar10 = uVar6;
        uVar11 = uVar11 + 1;
        sVar1 = strlen((char *)__s);
        uVar6 = uVar6 + sVar1 + 1;
        __s = pbVar8 + uVar6;
      } while (pbVar8[uVar6] != 0);
    }
    param_1[3] = uVar11;
    uVar2 = 0;
    param_1[4] = uVar6;
  }
  else {
    free((void *)param_1[5]);
    free((void *)param_1[8]);
    iVar7 = param_1[2];
    param_1[8] = 0;
    iVar3 = __aeabi_uidiv((param_3 - 1) + iVar7,iVar7);
    iVar5 = *param_1;
    uVar11 = param_1[1];
    do {
      uVar6 = uVar11;
      iVar5 = iVar5 + 1;
      uVar11 = uVar6 << 1;
    } while (uVar11 < (uint)(iVar7 * iVar3));
    *param_1 = iVar5;
    iVar3 = 0;
    param_1[1] = uVar11;
    param_1[3] = 0;
    param_1[4] = 0;
    __dest = (char *)calloc(uVar11,1);
    param_1[5] = (int)__dest;
    if (__dest == (char *)0x0) {
      printf("Err: %s %d","strtab_set_strbuf",199);
      uVar2 = 200;
    }
    else {
      uVar6 = uVar6 & 0x7fffffff;
      param_1[7] = uVar6;
      pvVar4 = calloc(uVar6 << 2,1);
      param_1[8] = (int)pvVar4;
      if (pvVar4 != (void *)0x0) {
        memcpy(__dest,param_2,param_3);
        if (*__dest == '\0') {
          iVar3 = 0;
          iVar5 = 0;
        }
        else {
          piVar9 = (int *)((int)pvVar4 + -4);
          iVar5 = 0;
          __s_00 = __dest;
          do {
            piVar9 = piVar9 + 1;
            *piVar9 = iVar3;
            iVar5 = iVar5 + 1;
            sVar1 = strlen(__s_00);
            iVar3 = iVar3 + sVar1 + 1;
            __s_00 = __dest + iVar3;
          } while (__dest[iVar3] != '\0');
        }
        param_1[3] = iVar5;
        param_1[4] = iVar3;
        return 0;
      }
      printf("Err: %s %d","strtab_set_strbuf",0xd3);
      uVar2 = 0xd4;
    }
  }
  return uVar2;
}



size_t strtab_add_string(int *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  void *pvVar2;
  int iVar3;
  size_t __nmemb;
  size_t __n;
  void *pvVar4;
  
  if (param_1 == (int *)0x0) {
    __n = 0xffffffff;
    printf("Err: %s %d","strtab_add_string",0x100,param_4,param_4);
  }
  else if (param_2 == (char *)0x0) {
    __n = 0xffffffff;
    printf("Err: %s %d","strtab_add_string",0x106,param_4,param_4);
  }
  else {
    sVar1 = strlen(param_2);
    if (sVar1 == 0) {
      printf("Err: %s %d","strtab_add_string",0x110);
      return 0xffffffff;
    }
    __nmemb = param_1[1];
    __n = param_1[4];
    if (sVar1 < __nmemb - __n) {
      memcpy((void *)(param_1[5] + __n),param_2,sVar1 + 1);
    }
    else {
      iVar3 = *param_1;
      do {
        iVar3 = iVar3 + 1;
        __nmemb = __nmemb * 2;
      } while (__nmemb - __n <= sVar1);
      *param_1 = iVar3;
      param_1[1] = __nmemb;
      pvVar2 = calloc(__nmemb,1);
      if (pvVar2 == (void *)0x0) {
        printf("Err: %s %d","strtab_add_string",0x12e);
        return 0xffffffff;
      }
      pvVar4 = (void *)param_1[5];
      memcpy(pvVar2,pvVar4,__n);
      free(pvVar4);
      param_1[5] = (int)pvVar2;
      param_1[7] = (uint)param_1[1] >> 1;
      pvVar2 = calloc(((uint)param_1[1] >> 1) << 2,1);
      if (pvVar2 == (void *)0x0) {
        printf("Err: %s %d","strtab_add_string",0x141);
        return 0xffffffff;
      }
      pvVar4 = (void *)param_1[8];
      memcpy(pvVar2,pvVar4,param_1[3] << 2);
      free(pvVar4);
      __n = param_1[4];
      param_1[8] = (int)pvVar2;
      strcpy((char *)(param_1[5] + __n),param_2);
    }
    param_1[4] = sVar1 + param_1[4] + 1;
    *(size_t *)(param_1[8] + param_1[3] * 4) = __n;
    param_1[3] = param_1[3] + 1;
  }
  return __n;
}



undefined4 strtab_get_cnt(int param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0xc);
  }
  printf("Err: %s %d","strtab_get_cnt",0x163);
  return 0;
}



undefined4 strtab_get_len(int param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x10);
  }
  printf("Err: %s %d","strtab_get_len",0x176);
  return 0;
}



undefined4 strtab_get_max_len(int param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 4);
  }
  printf("Err: %s %d","strtab_get_max_len",0x189);
  return 0;
}



undefined4 strtab_get_align(int param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 8);
  }
  printf("Err: %s %d","strtab_get_align",0x19c);
  return 0;
}



int strtab_get_align_size(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 8);
    iVar1 = __aeabi_uidiv(*(int *)(param_1 + 0x10) + iVar2 + -1,iVar2);
    return iVar2 * iVar1;
  }
  printf("Err: %s %d","strtab_get_align_size",0x1af,param_4,param_4);
  return 0;
}



undefined4 strtab_get_str(int param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x14);
  }
  printf("Err: %s %d","strtab_get_str",0x1c2);
  return 0;
}



int strtab_get_str_byIndex(int param_1,uint param_2)

{
  if (param_1 == 0) {
    printf("Err: %s %d","strtab_get_str_byIndex",0x1d7);
    return 0;
  }
  if (param_2 < *(uint *)(param_1 + 0xc)) {
    return *(int *)(param_1 + 0x14) + *(int *)(*(int *)(param_1 + 0x20) + param_2 * 4);
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("i < handle->str_tab.cnt","apps/verified-test/fw_ab_upgrade/string_table.c",0x1dc,
                "strtab_get_str_byIndex");
}



int strtab_get_str_byOffset(int param_1,int param_2)

{
  if (param_1 != 0) {
    return *(int *)(param_1 + 0x14) + param_2;
  }
  printf("Err: %s %d","strtab_get_str_byOffset",0x1ec);
  return 0;
}



undefined4 strtab_get_offset_byIndex(int param_1,uint param_2)

{
  if (param_1 == 0) {
    printf("Err: %s %d","strtab_get_offset_byIndex",0x201);
    return 0;
  }
  if (param_2 < *(uint *)(param_1 + 0xc)) {
    return *(undefined4 *)(*(int *)(param_1 + 0x20) + param_2 * 4);
  }
  printf("Err: %s %d i{%d} >= handle->str_tab.cnt{%d}","strtab_get_offset_byIndex",0x20c,param_2,
         *(uint *)(param_1 + 0xc));
  return 0;
}



undefined4 strtab_uninit(void *param_1)

{
  if (param_1 != (void *)0x0) {
    if (*(void **)((int)param_1 + 0x14) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x14));
      *(undefined4 *)((int)param_1 + 0x14) = 0;
    }
    if (*(void **)((int)param_1 + 0x20) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x20));
    }
    free(param_1);
    return 0;
  }
  printf("Err: %s %d","strtab_uninit",0x21e);
  return 0x21f;
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

int fsync(int __fd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long strtol(char *__nptr,char **__endptr,int __base)

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

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

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

void * memset(void *__s,int __c,size_t __n)

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

ssize_t read(int __fd,void *__buf,size_t __nbytes)

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

int unlink(char *__name)

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

char * strcpy(char *__dest,char *__src)

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

int getopt(int ___argc,char **___argv,char *__shortopts)

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

int access(char *__name,int __type)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__off_t lseek(int __fd,__off_t __offset,int __whence)

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

void __aeabi_uidiv(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s)

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

void * malloc(size_t __size)

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

int fprintf(FILE *__stream,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

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

void __libc_start_main(void)

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


