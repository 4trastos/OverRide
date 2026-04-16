# 1. Buscar Binario:

Listamos los archivos para que muetre el biarnio del `level03` y sus permisos:

```bash
level03@OverRide:~$ ls -la
total 17
dr-xr-x---+ 1 level03 level03   80 Sep 13  2016 .
dr-x--x--x  1 root    root     260 Oct  2  2016 ..
-rw-r--r--  1 level03 level03  220 Sep 10  2016 .bash_logout
lrwxrwxrwx  1 root    root       7 Sep 13  2016 .bash_profile -> .bashrc
-rw-r--r--  1 level03 level03 3533 Sep 10  2016 .bashrc
-rwsr-s---+ 1 level04 users   7677 Sep 10  2016 level03
-rw-r--r--+ 1 level03 level03   41 Oct 19  2016 .pass
-rw-r--r--  1 level03 level03  675 Sep 10  2016 .profile
```

> **Nota:** El bit `s` en los permisos indica que es un binairo **SUID**. Se ejecuta con los privilegios del propietario (`level03`).

# 2. Analizamos las protecciones de la RAM
```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Partial RELRO   Canary found      NX enabled    No PIE          No RPATH   No RUNPATH   /home/users/level03/level03
```

### a). PIE:
```bash
level02@OverRide:~$ file ./level02 
./level02: setuid setgid ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=0xf639d5c443e6ff1c50a0f8393461c0befc329e71, not stripped
```

## b). ASLR:
```bash
level02@OverRide:~$ cat /proc/sys/kernel/randomize_va_space 
0
```

### c). NX y RELRO:
```bash
level02@OverRide:~$ readelf -l ./level02 | grep -E "STACK|RELRO"
  GNU_STACK      0x0000000000000000 0x0000000000000000 0x0000000000000000
```

### d). STACK CANARY:
```bash
level02@OverRide:~$ nm ./level02 
0000000000601028 d _DYNAMIC
00000000006011c0 d _GLOBAL_OFFSET_TABLE_
0000000000400ba8 R _IO_stdin_used
                 w _Jv_RegisterClasses
0000000000601008 d __CTOR_END__
0000000000601000 d __CTOR_LIST__
0000000000601018 D __DTOR_END__
0000000000601010 d __DTOR_LIST__
0000000000400e28 r __FRAME_END__
0000000000601020 d __JCR_END__
0000000000601020 d __JCR_LIST__
0000000000601248 A __bss_start
0000000000601238 D __data_start
0000000000400b60 t __do_global_ctors_aux
0000000000400780 t __do_global_dtors_aux
0000000000601240 D __dso_handle
                 w __gmon_start__
0000000000601000 d __init_array_end
0000000000601000 d __init_array_start
0000000000400b50 T __libc_csu_fini
0000000000400ac0 T __libc_csu_init
                 U __libc_start_main@@GLIBC_2.2.5
0000000000601248 A _edata
0000000000601268 A _end
0000000000400b98 T _fini
0000000000400640 T _init
0000000000400730 T _start
000000000040075c t call_gmon_start
0000000000601258 b completed.6531
0000000000601238 W data_start
0000000000601260 b dtor_idx.6533
                 U exit@@GLIBC_2.2.5
                 U fclose@@GLIBC_2.2.5
                 U fgets@@GLIBC_2.2.5
                 U fopen@@GLIBC_2.2.5
00000000004007f0 t frame_dummy
                 U fread@@GLIBC_2.2.5
                 U fwrite@@GLIBC_2.2.5
0000000000400814 T main
                 U printf@@GLIBC_2.2.5
                 U puts@@GLIBC_2.2.5
0000000000601250 B stderr@@GLIBC_2.2.5
0000000000601248 B stdin@@GLIBC_2.2.5
                 U strcspn@@GLIBC_2.2.5
                 U strncmp@@GLIBC_2.2.5
                 U system@@GLIBC_2.2.5
```

### e). `.got` y `.plt`:
```bash
level02@OverRide:~$ readelf -S ./level02 | grep -E ".got|.plt"
  [10] .rela.plt         RELA             0000000000400520  00000520
  [12] .plt              PROGBITS         0000000000400660  00000660
  [22] .got              PROGBITS         00000000006011b8  000011b8
  [23] .got.plt          PROGBITS         00000000006011c0  000011c0
```

# 3. Resumen del análisis:

**IMPORTANTE**:
Estamos ante un Binario de `64 bits` tal y como nos muestra `file ./level02`

| Protección | Estado | Evidencia | Consecuencias |
| --- | --- | --- | --- |
| **PIE** | **OFF** | `executable` | El binario siempre carga en `0x08048000`. |
| **ASLR** | **OFF** | `0` | El Heap y el Stack no se mueven; las direcciones son fijas. |
| **NX** | **OFF** | `RWE` | El Heap  y el Stack SI permiten ejecución.  Podemos meter y correr Shellcode allí. |
| **RELRO** | **OFF** | `ausencia` | La sección `.got.plt` sigue siendo escribible `(WA)`. Podríamos hacer un `GOT Hijack` si fuera necesario. |
| **CANARY** | **NO**  | `No canary found` | No hay "centinela" al final del stack. Podemos desbordar el EIP sin que el programa lo detecte. |
| **.got.plt** | **WA**  | `WA` | Confirma sección `.got.plt` en escritura |

---

# 4. Fuzzing:

Al ejecutar el binario, el programa nos pide un usuario y a continuación una contraseña. Parece que tanto el usuario y la contraseña las testea una vez completados los dos campos. 

```bash
level02@OverRide:~$ ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: a
--[ Password: a
*****************************************
a does not have access!
```

Pero al intentar probocar un `segfault`, nos damos cuenta que podemos llenar de bytes el `buffer` del usuario y este sobreescribirá el buffer destinado al password:

```bash
level02@OverRide:~$ ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
--[ Password: *****************************************
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa does not have access!
level02@OverRide:~$ ./level02 
```
---

# 5. Reverse Engineering (Target Identification):