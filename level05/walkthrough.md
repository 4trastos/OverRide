# 1. Buscar Binario:

Listamos los archivos para que muestre el biarnio del `level05` y sus permisos:

```bash
level05@OverRide:~$ ls -la
total 17
dr-xr-x---+ 1 level05 level05   80 Sep 13  2016 .
dr-x--x--x  1 root    root     260 Oct  2  2016 ..
-rw-r--r--  1 level05 level05  220 Sep 10  2016 .bash_logout
lrwxrwxrwx  1 root    root       7 Sep 13  2016 .bash_profile -> .bashrc
-rw-r--r--  1 level05 level05 3533 Sep 10  2016 .bashrc
-rwsr-s---+ 1 level06 users   5176 Sep 10  2016 level05
-rw-r--r--+ 1 level05 level05   41 Oct 19  2016 .pass
-rw-r--r--  1 level05 level05  675 Sep 10  2016 .profile
```

> **Nota:** El bit `s` en los permisos indica que es un binairo **SUID**. Se ejecuta con los privilegios del propietario (`level06`).

# 2. Analizamos las protecciones de la RAM
```bash
ELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
No RELRO        No canary found   NX disabled   No PIE          No RPATH   No RUNPATH   /home/users/level05/level05
```

### a). PIE:
```bash
level05@OverRide:~$ file ./level05 
./level05: setuid setgid ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=0x1a9c02d3aeffff53ee0aa8c7730cbcb1ab34270e, not stripped
```

## b). ASLR:
```bash
level05OverRide:~$ cat /proc/sys/kernel/randomize_va_space 
0
```

### c). NX y RELRO:
```bash
level05@OverRide:~$ readelf -l ./level05 | grep -E "RELRO|STACK"
GNU_STACK      0x000000 0x00000000 0x00000000 0x00000 0x00000 RWE 0x4
```

### d). STACK CANARY:
```bash
level05@OverRide:~$ nm ./level05 
080496fc d _DYNAMIC
080497c8 d _GLOBAL_OFFSET_TABLE_
080485ec R _IO_stdin_used
         w _Jv_RegisterClasses
080496ec d __CTOR_END__
080496e8 d __CTOR_LIST__
080496f4 D __DTOR_END__
080496f0 d __DTOR_LIST__
080486e4 r __FRAME_END__
080496f8 d __JCR_END__
080496f8 d __JCR_LIST__
080497f0 A __bss_start
080497e8 D __data_start
080485a0 t __do_global_ctors_aux
080483c0 t __do_global_dtors_aux
080497ec D __dso_handle
         w __gmon_start__
08048592 T __i686.get_pc_thunk.bx
080496e8 d __init_array_end
080496e8 d __init_array_start
08048590 T __libc_csu_fini
08048520 T __libc_csu_init
         U __libc_start_main@@GLIBC_2.0
080497f0 A _edata
080497fc A _end
080485cc T _fini
080485e8 R _fp_hw
080482f8 T _init
08048390 T _start
080497f4 b completed.6159
080497e8 W data_start
080497f8 b dtor_idx.6161
         U exit@@GLIBC_2.0
         U fgets@@GLIBC_2.0
08048420 t frame_dummy
08048444 T main
         U printf@@GLIBC_2.0
080497f0 B stdin@@GLIBC_2.0
```

### e). `.got` y `.plt`:
```bash
level05@OverRide:~$ readelf -S ./level05 | grep -E ".got|.plt"
  [10] .rel.plt          REL             080482d0 0002d0 000028 08   A  5  12  4
  [12] .plt              PROGBITS        08048330 000330 000060 04  AX  0   0 16
  [22] .got              PROGBITS        080497c4 0007c4 000004 04  WA  0   0  4
  [23] .got.plt          PROGBITS        080497c8 0007c8 000020 04  WA  0   0  4
```

---

# 3. Resumen del análisis:

**IMPORTANTE**:
Estamos ante un Binario de `32 bits` tal y como nos muestra `file ./level05`

| Protección | Estado | Evidencia | Consecuencias |
| --- | --- | --- | --- |
| **PIE** | **OFF** | `executable` | El binario siempre carga en `0x08048000`. |
| **ASLR** | **OFF** | `0` | El Heap y el Stack no se mueven; las direcciones son fijas. |
| **NX** | **OFF** | `RWE` | El Stack **SÍ** permite ejecución. Podemos meter y correr Shellcode allí. |
| **RELRO** | **OFF** | `ausencia` | La sección `.got.plt` sigue siendo escribible `(WA)`. Podríamos hacer un `GOT Hijack` si fuera necesario. |
| **CANARY** | **NO** | `ausencia` | No hay "centinela" al final del stack. Podemos desbordar el buffer y el programa NO lo detectará. |
| **.got.plt** | **WA** | `WA` | Confirma sección `.got.plt` en escritura. |

---

# 4. Fuzzing:

Al ejecutar el binario el prorama nos deja abierta la terminal para poder escribir. Intentamos provocar un `segtfault` y nos damos cuenta que lo que hace el programa es convertor mayúsculas en minúsculas. Tambien intentamos comprobar si `printf` está volcando valores del stack. 

```bash
level05@OverRide:~$ ./level05 
asdsad
asdsad
level05@OverRide:~$ ./level05 
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaalevel05@OverRide:~$ 
level05@OverRide:~$ ./level05 


level05@OverRide:~$ ./level05 
AAAA %p %p %p %p %p %p %p %p 
aaaa 0x64 0xf7fcfac0 0xf7ec3af9 0xffffd6df 0xffffd6de (nil) 0xffffffff 0xffffd764 
level05@OverRide:~$ ./level05 
aAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
level05@OverRide:~$ 
```

**1. El programa convierte mayúsculas a minúsculas:**
```bash
AAAA %p %p... → aaaa 0x64 0xf7fcfac0...
```
Esto significa que si queremos meter direcciones de memoria en el payload, las que contengan bytes entre `0x41-0x5A` (A-Z) serán modificadas. Hay que tener en cuenta qué bytes tienen las direcciones de `system()` y de la `.got.plt` al construir el exploit.

**2. La vulnerabilidad Format String está confirmada:**
```bash
AAAA %p %p %p %p %p %p %p %p
aaaa 0x64 0xf7fcfac0 0xf7ec3af9 0xffffd6df...
```
`printf` está volcando valores del stack (igual que en el level02).

**3. El buffer tiene límite:**
Con muchas `a` el programa trunca la salida. `fgets` sí controla el tamaño, así que no hay Stack Buffer Overflow clásico. El único vector es **Format String**.

**4. La posición de nuestro input en el stack:**
En la posición **4** vemos `0xffffd6df`. Esa dirección apunta al propio input. Esto es clave para el **GOT Hijack** porque significa que podemos meter una dirección en el input y referenciarla con `%4$n`.

---

# 5. Reverse Engineering (Target Identification):

El comando `nm` nos muestra funciones importantes:

```bash
U fgets@@GLIBC_2.0    ⟸
U printf@@GLIBC_2.0   ⟸
U exit@@GLIBC_2.0     ⟸
```

* `fgets()`: Lee input del usuario. Posible vector de ataque si el buffer es pequeño.
* `printf()`: Si recibe input del usuario directamente como formato sin sanitizar. Vector de **Format String**, igual que en el level02.
* `exit()`: El programa termina con `exit()` en lugar de `ret`. No hay dirección de retorno que pisar en el stack.

**Importante:** 

* No hay `system()` en el binario. No podemos hacer Ret2Libc directamente.
* La combinación de `printf()` sin sanitizar y `.got.plt` escribible apunta a un **GOT Hijack**:
- usar Format String para sobrescribir la entrada de `exit()` en la `.got.plt` con la dirección de `system()` en la libc.

Para ver con detalle el análisis consulta el archivo
[asm_analysis.md](https://github.com/4trastos/OverRide/blob/main/level05/Resources/README.md)
en conjunto con el programa de demostración
[source.c](https://github.com/4trastos/OverRide/blob/main/level05/source.c).

---

# 6. Solución: