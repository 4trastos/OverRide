# 1. Buscar Binario:

Listamos los archivos para que muestre el biarnio del `level06` y sus permisos:

```bash
level06@OverRide:~$ ls -la
total 17
dr-xr-x---+ 1 level06 level06   80 Sep 13  2016 .
dr-x--x--x  1 root    root     260 Oct  2  2016 ..
-rw-r--r--  1 level06 level06  220 Sep 10  2016 .bash_logout
lrwxrwxrwx  1 root    root       7 Sep 13  2016 .bash_profile -> .bashrc
-rw-r--r--  1 level06 level06 3533 Sep 10  2016 .bashrc
-rwsr-s---+ 1 level07 users   7907 Sep 10  2016 level06
-rw-r--r--+ 1 level06 level06   41 Oct 19  2016 .pass
-rw-r--r--  1 level06 level06  675 Sep 10  2016 .profile
```

> **Nota:** El bit `s` en los permisos indica que es un binairo **SUID**. Se ejecuta con los privilegios del propietario (`level07`).

# 2. Analizamos las protecciones de la RAM
```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Partial RELRO   Canary found      NX enabled    No PIE          No RPATH   No RUNPATH   /home/users/level06/level06
```

### a). PIE:
```bash
level06@OverRide:~$ file ./level06 
./level06: setuid setgid ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=0x459bcb819bfdde7ecfa5612c8445e7dd0831cc48, not stripped
```

## b). ASLR:
```bash
level05OverRide:~$ cat /proc/sys/kernel/randomize_va_space 
0
```

### c). NX y RELRO:
```bash
level06@OverRide:~$  readelf -l ./level06 | grep -E "RELRO|STACK"
  GNU_STACK      0x000000 0x00000000 0x00000000 0x00000 0x00000 RW  0x4
  GNU_RELRO      0x000f00 0x08049f00 0x08049f00 0x00100 0x00100 R   0x1
```

### d). STACK CANARY:
```bash
level06@OverRide:~$ nm ./level06 
08049f18 d _DYNAMIC
08049ff4 d _GLOBAL_OFFSET_TABLE_
08048a5c R _IO_stdin_used
         w _Jv_RegisterClasses
08049f08 d __CTOR_END__
08049f04 d __CTOR_LIST__
08049f10 D __DTOR_END__
08049f0c d __DTOR_LIST__
08048d28 r __FRAME_END__
08049f14 d __JCR_END__
08049f14 d __JCR_LIST__
0804a044 A __bss_start
0804a03c D __data_start
08048a10 t __do_global_ctors_aux
08048630 t __do_global_dtors_aux
0804a040 D __dso_handle
         w __gmon_start__
08048a02 T __i686.get_pc_thunk.bx
08049f04 t __init_array_end
08049f00 t __init_array_start
         U __isoc99_scanf@@GLIBC_2.7
08048a00 T __libc_csu_fini
08048990 T __libc_csu_init
         U __libc_start_main@@GLIBC_2.0
         U __stack_chk_fail@@GLIBC_2.4              ⟸
0804a044 A _edata
0804a08c A _end
08048a3c T _fini
08048a58 R _fp_hw
080484d0 T _init
08048600 T _start
         U alarm@@GLIBC_2.0
08048748 T auth
080486b4 T clear_stdin
0804a084 b completed.6159
0804a03c W data_start
0804a088 b dtor_idx.6161
08048720 T enable_timeout_cons
         U fflush@@GLIBC_2.0
         U fgets@@GLIBC_2.0
08048690 t frame_dummy
080486d7 T get_unum
         U getchar@@GLIBC_2.0
08048879 T main
         U printf@@GLIBC_2.0
0804870f T prog_timeout
         U ptrace@@GLIBC_2.0
         U puts@@GLIBC_2.0
         U signal@@GLIBC_2.0
0804a060 B stdin@@GLIBC_2.0
0804a080 B stdout@@GLIBC_2.0
         U strcspn@@GLIBC_2.0
         U strnlen@@GLIBC_2.0
         U system@@GLIBC_2.0
```

### e). `.got` y `.plt`:
```bash
level06@OverRide:~$ readelf -S ./level06 | grep -E ".got|.plt"
  [10] .rel.plt          REL             08048458 000458 000078 08   A  5  12  4
  [12] .plt              PROGBITS        08048500 000500 000100 04  AX  0   0 16
  [23] .got              PROGBITS        08049ff0 000ff0 000004 04  WA  0   0  4
  [24] .got.plt          PROGBITS        08049ff4 000ff4 000048 04  WA  0   0  4
```

---

# 3. Resumen del análisis:

**IMPORTANTE**:
Estamos ante un Binario de `32 bits` tal y como nos muestra `file ./level06`

| Protección | Estado | Evidencia | Consecuencias |
| --- | --- | --- | --- |
| **PIE** | **OFF** | `executable` | El binario siempre carga en `0x08048000`. |
| **ASLR** | **OFF** | `0` | El Heap y el Stack no se mueven; las direcciones son fijas. |
| **NX** | **ON** | `RW` | El Stack **NO** permite ejecución. No podemos meter ni correr Shellcode allí. |
| **RELRO** | **PARTIAL** | `R` | La sección `.got.plt` sigue siendo escribible `(WA)`. |
| **CANARY** | **SÍ** | `__stack_chk_fail@@GLIBC_2.4` ⟸ | Hay "centinela" al final del stack. Si desbordamos el buffer el programa lo detectará y abortará. |
| **.got.plt** | **WA** | `WA` | Confirma sección `.got.plt` en escritura. |

---

# 4. Fuzzing:

Al ejecutar el binario el prorama nos muestra un mensaje y nos pide que nos logueemos. y acto seguido nos introducamo el `Serial` (password):

```bash
level06@OverRide:~$ ./level06 
***********************************
*		level06		  *
***********************************
-> Enter Login: 
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: 
asdas
level06@OverRide:~$ 
```

En un principio no es necesario poner el login puesto que acepta un string vacío.

Pero si ponemos un login demasiado largo, el programa no espera el serial y sale directamente — el buffer del login tiene un límite.

Si ponemos un login corto, el programa acepta el serial pero lo valida y sale sin error ni segfault — el **Stack Canary** impide el desbordamiento clásico.

```bash
level06@OverRide:~$ ./level06 
***********************************
*		level06		  *
***********************************
-> Enter Login: dasssssssssssssssssssssssssssssssssssssss
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: 
level06@OverRide:~$ 
```

---

# 5. Reverse Engineering (Target Identification):

El comando `nm` nos muestra funciones importantes:

```bash
08048748 T auth                       ⟸
         U ptrace@@GLIBC_2.0          ⟸
         U system@@GLIBC_2.0          ⟸
         U __stack_chk_fail@@GLIBC_2.4 ⟸
```

* `auth()`: Función propia del binario — contiene la lógica de validación del login y el serial.
* `ptrace()`: Igual que en el level04 — técnica antidebugging que detecta si el binario está siendo analizado con GDB.
* `system()`: El binario ya importa `system()`, por lo que no tenemos que buscar la dirección de memoria.
* `__stack_chk_fail()`: Hay Stack Canary — no podemos desbordar el buffer directamente.

Para ver con detalle el análisis consulta el archivo [asm_analysis.md](https://github.com/4trastos/OverRide/blob/main/level06/Resources/README.md) en conjunto con el programa de demostración [source.c](https://github.com/4trastos/OverRide/blob/main/level06/source.c).

---

# 6. Solución:

Para resolver este nivel necesitamos entender el algoritmo de validación de `auth()` y replicarlo en Python para calcular el serial correcto para cualquier login válido.

---

## 1. Entender la lógica:

`auth()` calcula el serial esperado a partir del login con este algoritmo:

```c
serial_expected = (login[3] ^ 0x1337) + 0x5eeded;
for (i = 0; i < len; i++)
{
    temp = login[i] ^ serial_expected;
    serial_expected += temp - (temp / 1337) * 1337;
}
if (serial == serial_expected)
    return (0);
```

El login debe tener más de 5 caracteres y ningún carácter puede ser `<= 0x1f`.

---

## 2. Restricciones:

* `ptrace(PTRACE_TRACEME)` actúa como antidebugging — si el proceso está siendo trazado por GDB devuelve `-1` y el programa imprime `"!! TAMPERING DETECTED !!"` y sale.
* No podemos usar GDB directamente para depurar `auth()`.
* La solución es replicar el algoritmo fuera del binario.

---

## 3. Calcular el serial:

Replicamos el algoritmo en Python:

```bash
level06@OverRide:~$ python -c "
login = 'aaaaaa'
serial = (ord(login[3]) ^ 0x1337) + 0x5eeded
for c in login:
    temp = ord(c) ^ serial
    serial += temp - (temp / 1337) * 1337
    serial &= 0xffffffff
print serial
"
6231562
```

---

## 4. Ejecución:

```bash
level06@OverRide:~$ ./level06
***********************************
*       level06         *
***********************************
-> Enter Login: aaaaaa
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: 6231562
Authenticated!
$ whoami
level07
$ cat /home/users/level07/.pass
GbcPDRgsFK77LNnnuh7QyFYA2942Gp8yKj9KrWD8
$
```

---

# 7. Conclusión:

El nivel 06 no requiere explotar ninguna vulnerabilidad de memoria — el vector de ataque es la **ingeniería inversa del algoritmo de validación**. El programa usa `ptrace(PTRACE_TRACEME)` como antidebugging para impedir el análisis con GDB, pero el algoritmo es completamente determinista y reversible.

Analizando el desensamblado de `auth()` identificamos que el serial se calcula aplicando una serie de operaciones sobre cada carácter del login. Replicando ese algoritmo en Python obtenemos el serial correcto para cualquier login válido de más de 5 caracteres.