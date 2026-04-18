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
level03@OverRide:~$ file ./level03 
./level03: setuid setgid ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=0x9e834af52f4b2400d5bd38b3dac04d1a5faa1729, not stripped
```

## b). ASLR:
```bash
level03@OverRide:~$ cat /proc/sys/kernel/randomize_va_space 
0
```

### c). NX y RELRO:
```bash
level03@OverRide:~$ readelf -l ./level03 | grep -E "STACK|RELRO"
GNU_STACK      0x000000 0x00000000 0x00000000 0x00000 0x00000 RW  0x4
GNU_RELRO      0x000f14 0x08049f14 0x08049f14 0x000ec 0x000ec R   0x1
```

### d). STACK CANARY:
```bash
level03@OverRide:~$ nm ./level03 
08049f28 d _DYNAMIC
08049ff4 d _GLOBAL_OFFSET_TABLE_
080489bc R _IO_stdin_used
         w _Jv_RegisterClasses
08049f18 d __CTOR_END__
08049f14 d __CTOR_LIST__
08049f20 D __DTOR_END__
08049f1c d __DTOR_LIST__
08048c50 r __FRAME_END__
08049f24 d __JCR_END__
08049f24 d __JCR_LIST__
0804a038 A __bss_start
0804a030 D __data_start
08048970 t __do_global_ctors_aux
08048570 t __do_global_dtors_aux
0804a034 D __dso_handle
         w __gmon_start__
08048962 T __i686.get_pc_thunk.bx
08049f14 d __init_array_end
08049f14 d __init_array_start
         U __isoc99_scanf@@GLIBC_2.7
08048960 T __libc_csu_fini
080488f0 T __libc_csu_init
         U __libc_start_main@@GLIBC_2.0
         U __stack_chk_fail@@GLIBC_2.4      ⟸
0804a038 A _edata
0804a04c A _end
0804899c T _fini
080489b8 R _fp_hw
0804843c T _init
08048540 T _start
080485f4 T clear_stdin
0804a044 b completed.6159
0804a030 W data_start
08048660 T decrypt
0804a048 b dtor_idx.6161
         U fflush@@GLIBC_2.0
080485d0 t frame_dummy
08048617 T get_unum
         U getchar@@GLIBC_2.0
0804885a T main
         U printf@@GLIBC_2.0
0804864f T prog_timeout
         U puts@@GLIBC_2.0
         U rand@@GLIBC_2.0
         U srand@@GLIBC_2.0
0804a040 B stdout@@GLIBC_2.0
         U system@@GLIBC_2.0
08048747 T test
         U time@@GLIBC_2.0
```

### e). `.got` y `.plt`:
```bash
level03@OverRide:~$ readelf -S ./level03 | grep -E ".got|.plt"
  [10] .rel.plt          REL             080483dc 0003dc 000060 08   A  5  12  4
  [12] .plt              PROGBITS        08048470 000470 0000d0 04  AX  0   0 16
  [22] .got              PROGBITS        08049ff0 000ff0 000004 04  WA  0   0  4
  [23] .got.plt          PROGBITS        08049ff4 000ff4 00003c 04  WA  0   0  4
```

# 3. Resumen del análisis:

**IMPORTANTE**:
Estamos ante un Binario de `32 bits` tal y como nos muestra `file ./level03`

| Protección | Estado | Evidencia | Consecuencias |
| --- | --- | --- | --- |
| **PIE** | **OFF** | `executable` | El binario siempre carga en `0x08048000`. |
| **ASLR** | **OFF** | `0` | El Heap y el Stack no se mueven; las direcciones son fijas. |
| **NX** | **ON** | `RW` | El Stack **NO** permite ejecución. No podemos meter ni correr Shellcode allí. |
| **RELRO** | **PARTIAL** | `R` | La sección `.got.plt` sigue siendo escribible `(WA)`. Podríamos hacer un `GOT Hijack` si fuera necesario. |
| **CANARY** | **SÍ** | `__stack_chk_fail@@GLIBC_2.4` ⟸ | Hay "centinela" al final del stack. Si desbordamos el buffer el programa lo detectará y abortará. |
| **.got.plt** | **WA** | `WA` | Confirma sección `.got.plt` en escritura. |

---

# 4. Fuzzing:

Al ejecutar el binario, el programa nos pide una contraseña. Parece que hasta que se no completa el campo no testea la contraseña. Si no coincide el programa termina. 

```bash
level03@OverRide:~$ ./level03
***********************************
*		level03		**
***********************************
Password:asddasdasdasd

Invalid Password
level03@OverRide:~$ 
```

NO logramos provocar un `segfault` al llenar de bytes el `buffer` de la contraseña.
Esto se debe al **Stack Canary** detectado en el análisis — el programa aborta
controladamente antes de llegar al `ret`.

```bash
level03@OverRide:~$ ./level03
***********************************
*		level03		**
***********************************
Password:qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq

Invalid Password
level03@OverRide:~$ ./level03
```
---

# 5. Reverse Engineering (Target Identification):

El comando `nm` nos muestra funciones importantes:

```bash
08048660 T decrypt                    ⟸
08048747 T test                       ⟸
         U rand@@GLIBC_2.0            ⟸
         U srand@@GLIBC_2.0           ⟸
         U time@@GLIBC_2.0            ⟸
         U system@@GLIBC_2.0          ⟸
```

* `decrypt()` y `test()`: Funciones propias del binario que contienen la lógica del programa.
* `rand()`, `srand()` y `time()`: El binario genera un número aleatorio — la contraseña probablemente depende de él.
* `system()`: El binario ya importa `system()`, por lo que no tenemos que buscar la dirección de memoria.


Para ver con detalle el analisis consuta el archivo  [asm_analysis.md](https://github.com/4trastos/OverRide/blob/main/level03/Resources/README.md) en conjunto con el programa de demostración  [source.c](https://github.com/4trastos/OverRide/blob/main/level03/source.c).

---

# 6. Solución:

Para resolver este nivel necesitamos encontrar el valor exacto que al aplicar `XOR`
sobre el string cifrado produce `"Congratulations!"` — que es la condición que hace
que `decrypt()` llame a `system("/bin/sh")`.

---

## 1. Entender la lógica:

`test()` calcula `diff = 0x1337d00d - user_input` y llama a `decrypt(diff)`.
`decrypt()` aplica `XOR` byte a byte sobre el string cifrado con `diff` y compara
el resultado con `"Congratulations!"`.

Necesitamos que:
```c
encrypted[i] XOR diff == "Congratulations!"
```

---

## 2. Calcular `diff`:

Verificamos que todos los bytes del string cifrado hacen `XOR` con el mismo valor:

```bash
level03@OverRide:~$ python -c "
encrypted = [0x51,0x7d,0x7c,0x75,0x60,0x73,0x66,0x67,0x7e,0x73,0x66,0x7b,0x7d,0x7c,0x61,0x33]
target    = [ord(c) for c in 'Congratulations!']
for i in range(len(encrypted)):
    print(hex(encrypted[i] ^ target[i]))
"
0x12
0x12
...  (16 veces)
```

Todos los bytes producen `0x12` — por lo tanto `diff = 0x12` (18 en decimal).

---

## 3. Calcular `user_input`:

Como `diff = 0x1337d00d - user_input`, despejamos:

```bash
level03@OverRide:~$ python -c "print(0x1337d00d - 0x12)"
322424827
```

---

## 4. Ejecución:

```bash
level03@OverRide:~$ ./level03
***********************************
*       level03     **
***********************************
Password:322424827
$ whoami
level04
$ cat /home/users/level04/.pass
kgv3tkEb9h2mLkRsPkXRfc2mHbjMxQzvb2FrgKkf
$
```

---

# 7. Conclusión:

El nivel 03 introduce una vulnerabilidad diferente a los niveles anteriores. El programa
usa `NX` y `Stack Canary` — no podemos desbordar el buffer ni ejecutar shellcode en el
stack. Sin embargo, la lógica del programa tiene un fallo de diseño: el valor con el que
se llama a `decrypt()` depende directamente de la entrada del usuario.

Analizando el string cifrado hardcodeado en `decrypt()` y el valor constante `0x1337d00d`,
podemos calcular el valor exacto de `diff` que descifra `"Congratulations!"` y derivar
el `user_input` correcto — sin necesidad de explotar ninguna protección de memoria.