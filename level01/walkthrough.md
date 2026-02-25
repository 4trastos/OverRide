# 1. Buscar Binario:

Listamos los archivos para que muetre el biarnio del `level01` y sus permisos:

```bash
level01@OverRide:~$ ls -la
total 17
dr-xr-x---+ 1 level01 level01   80 Sep 13  2016 .
dr-x--x--x  1 root    root     260 Oct  2  2016 ..
-rw-r--r--  1 level01 level01  220 Sep 10  2016 .bash_logout
lrwxrwxrwx  1 root    root       7 Sep 13  2016 .bash_profile -> .bashrc
-rw-r--r--  1 level01 level01 3533 Sep 10  2016 .bashrc
-rwsr-s---+ 1 level02 users   7360 Sep 10  2016 level01
-rw-r--r--+ 1 level01 level01   41 Oct 19  2016 .pass
-rw-r--r--  1 level01 level01  675 Sep 10  2016 .profile
```

> **Nota:** El bit `s` en los permisos indica que es un binairo **SUID**. Se ejecuta con los privilegios del propietario (`level01`).

# 2. Analizamos las protecciones de la RAM
```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Partial RELRO   No canary found   NX disabled   No PIE          No RPATH   No RUNPATH   /home/users/level01/level01
```

### a). PIE:
```bash
level01@OverRide:~$ file ./level01 
./level01: setuid setgid ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=0x923fd646950abba3d31df70cad30a6a5ab5760e8, not stripped
```

## b). ASLR:
```bash
level01@OverRide:~$ cat /proc/sys/kernel/randomize_va_space 
0
```

### c). NX y RELRO:
```bash
level01@OverRide:~$ readelf -l ./level01 | grep -E "STACK|RELRO"
  GNU_STACK      0x000000 0x00000000 0x00000000 0x00000 0x00000 RWE 0x4
  GNU_RELRO      0x000f14 0x08049f14 0x08049f14 0x000ec 0x000ec R   0x1
```

### d). STACK CANARY:
```bash
level01@OverRide:~$ nm ./level01 
08049f28 d _DYNAMIC
08049ff4 d _GLOBAL_OFFSET_TABLE_
0804868c R _IO_stdin_used
         w _Jv_RegisterClasses
08049f18 d __CTOR_END__
08049f14 d __CTOR_LIST__
08049f20 D __DTOR_END__
08049f1c d __DTOR_LIST__
08048898 r __FRAME_END__
08049f24 d __JCR_END__
08049f24 d __JCR_LIST__
0804a01c A __bss_start
0804a014 D __data_start
08048640 t __do_global_ctors_aux
080483e0 t __do_global_dtors_aux
0804a018 D __dso_handle
         w __gmon_start__
08048632 T __i686.get_pc_thunk.bx
08049f14 d __init_array_end
08049f14 d __init_array_start
08048630 T __libc_csu_fini
080485c0 T __libc_csu_init
         U __libc_start_main@@GLIBC_2.0
0804a01c A _edata
0804a0a4 A _end
0804866c T _fini
08048688 R _fp_hw
08048318 T _init
080483b0 T _start
0804a040 B a_user_name
0804a024 b completed.6159
0804a014 W data_start
0804a028 b dtor_idx.6161
         U fgets@@GLIBC_2.0
08048440 t frame_dummy
080484d0 T main
         U printf@@GLIBC_2.0
         U puts@@GLIBC_2.0
0804a020 B stdin@@GLIBC_2.0
08048464 T verify_user_name
080484a3 T verify_user_pass
```

### e). `.got` y `.plt`:
```bash
level01@OverRide:~$ readelf -S ./level01 | grep -E ".got|.plt"
  [10] .rel.plt          REL             080482f0 0002f0 000028 08   A  5  12  4
  [12] .plt              PROGBITS        08048350 000350 000060 04  AX  0   0 16
  [22] .got              PROGBITS        08049ff0 000ff0 000004 04  WA  0   0  4
  [23] .got.plt          PROGBITS        08049ff4 000ff4 000020 04  WA  0   0  4
```

# 3. Resumen del análisis:

| Protección | Estado | Evidencia | Consecuencias |
| --- | --- | --- | --- |
| **PIE** | **OFF** | `executable` | El binario siempre carga en `0x08048000`. |
| **ASLR** | **OFF** | `0` | El Heap y el Stack no se mueven; las direcciones son fijas. |
| **NX** | **OFF** | `RWE` | El Heap  y el Stack SI permiten ejecución.  Podemos meter y correr Shellcode allí. |
| **RELRO** | **PARTIAL** | `R` | La sección `.got.plt` sigue siendo escribible `(WA)`. Podríamos hacer un `GOT Hijack` si fuera necesario. |
| **CANARY** | **NO**  | `No canary found` | No hay "centinela" al final del stack. Podemos desbordar el EIP sin que el programa lo detecte. |
| **.got.plt** | **WA**  | `WA` | Confirma sección `.got.plt` en escritura |

# 4. Fuzzing:

