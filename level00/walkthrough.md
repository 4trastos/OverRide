# 1. Burcar Binario:

Listamos los archivos para que muestre el binario del `level00` y sus permisos:

```bash
level00@OverRide:~$ ls -la
total 13
dr-xr-x---+ 1 level01 level01   60 Sep 13  2016 .
dr-x--x--x  1 root    root     260 Oct  2  2016 ..
-rw-r--r--  1 level01 level01  220 Sep 10  2016 .bash_logout
lrwxrwxrwx  1 root    root       7 Sep 13  2016 .bash_profile -> .bashrc
-rw-r--r--  1 level00 level00 3533 Sep 10  2016 .bashrc
-rwsr-s---+ 1 level01 users   7280 Sep 10  2016 level00
-rw-r--r--  1 level01 level01  675 Sep 10  2016 .profile
```

> **Nota:** El bit `s` en los permisos indica que es un binairo **SUID**. Se ejecuta con los privilegios del propietario (`level01`).

---

# 2. Analizamos las protecciones de la RAM
```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Partial RELRO   No canary found   NX enabled    No PIE          No RPATH   No RUNPATH   /home/users/level01/level00
```

### a). PIE:
```bash
file ./level00 
./level00: setuid setgid ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=0x20352633f776024748e9f8a5ebab6686df488bcf, not stripped
```

## b). ASLR:
```bash
level00@OverRide:~$ cat /proc/sys/kernel/randomize_va_space 
0
```

### c). NX y RELRO:
```bash
level00@OverRide:~$ readelf -l ./level00 | grep -E "STACK|RELRO"
  GNU_STACK      0x000000 0x00000000 0x00000000 0x00000 0x00000 RW  0x4
  GNU_RELRO      0x000f14 0x08049f14 0x08049f14 0x000ec 0x000ec R   0x1
```

### d). STACK CANARY:
```bash
level00@OverRide:~$ nm ./level00
08049f28 d _DYNAMIC
08049ff4 d _GLOBAL_OFFSET_TABLE_
080485ec R _IO_stdin_used
         w _Jv_RegisterClasses
08049f18 d __CTOR_END__
08049f14 d __CTOR_LIST__
08049f20 D __DTOR_END__
08049f1c d __DTOR_LIST__
08048758 r __FRAME_END__
08049f24 d __JCR_END__
08049f24 d __JCR_LIST__
0804a020 A __bss_start
0804a018 D __data_start
080485a0 t __do_global_ctors_aux
08048410 t __do_global_dtors_aux
0804a01c D __dso_handle
         w __gmon_start__
08048592 T __i686.get_pc_thunk.bx
08049f14 d __init_array_end
08049f14 d __init_array_start
         U __isoc99_scanf@@GLIBC_2.7
08048590 T __libc_csu_fini
08048520 T __libc_csu_init
         U __libc_start_main@@GLIBC_2.0
0804a020 A _edata
0804a028 A _end
080485cc T _fini
080485e8 R _fp_hw
08048338 T _init
080483e0 T _start
0804a020 b completed.6159
0804a018 W data_start
0804a024 b dtor_idx.6161
08048470 t frame_dummy
08048494 T main
         U printf@@GLIBC_2.0
         U puts@@GLIBC_2.0
         U system@@GLIBC_2.0
```

### e). `.got` y `.plt`:
```bash
level00@OverRide:~$ readelf -S ./level00 | grep -E ".got|.plt"
  [10] .rel.plt          REL             08048308 000308 000030 08   A  5  12  4
  [12] .plt              PROGBITS        08048370 000370 000070 04  AX  0   0 16
  [22] .got              PROGBITS        08049ff0 000ff0 000004 04  WA  0   0  4
  [23] .got.plt          PROGBITS        08049ff4 000ff4 000024 04  WA  0   0  4
```


# 3. Resumen del análisis:

| Protección | Estado | Evidencia | Consecuencias |
| --- | --- | --- | --- |
| **PIE** | **OFF** | `executable` | El binario siempre carga en `0x08048000`. |
| **ASLR** | **OFF** | `0` | El Heap y el Stack no se mueven; las direcciones son fijas. |
| **NX** | **ON** | `RW` | El Heap  y el Stack NO permiten ejecución. NO podemos meter y correr Shellcode allí. |
| **RELRO** | **PARTIAL** | `R` | La sección `.got.plt` sigue siendo escribible `(WA)`. Podríamos hacer un `GOT Hijack` si fuera necesario. |
| **CANARY** | **NO**  | `No canary found` | No hay "centinela" al final del stack. Podemos desbordar el EIP sin que el programa lo detecte. |
| **.got.plt** | **WA**  | `WA` | Confirma sección `.got.plt` en escritura |

---

# 4. Fuzzing:

Al ejecutar el binairo nos pide una contraseña y probamos si somos capaces de generar un `segfault`, algo que no logramos hacer, pero sie vemos que podemos dejar una shell abierta si introducios argumentos :
```bash
level00@OverRide:~$ ./level00
***********************************
* 	     -Level00 -		  *
***********************************
Password:asd

Invalid Password!
level00@OverRide:~$
level00@OverRide:~$ ./level00 $(/bin/sh);
whoami 
cd ..
cat /home/users/level01/.pass
cat: /home/users/level01/.pass: Permission denied
exit
***********************************
* 	     -Level00 -		  *
***********************************
Password:exit

Invalid Password!
level00@OverRide:~$
```

---

# 5. Reverse Engineering (Target Identification):

1. El comando `nm` nos muestra las herramientas de las que disponibles dentro del binario. Vemos que hay 4 que son importantes:
```bash
level00@OverRide:~$ nm ./level00
...
         U __isoc99_scanf@@GLIBC_2.7        ⟸ 
...
         U printf@@GLIBC_2.0                ⟸
         U puts@@GLIBC_2.0                  ⟸
         U system@@GLIBC_2.0                ⟸
```
- `__isoc99_scanf`: Es una entrada de datos `scanf`.
- `printf()` y `puts()`: Que nos muestran por el terminal datos.
- `system()`: El binairo ya importa `system()`, por lo que no tenemos que buscar la dirección de memoria. Ya tenemos una entrada .got.plt para saltar directamente a ella.

2. Al desensamblar encontramos una opración de comparación. En la línea <+83> comprueba si el password que hemos introducido es igual al número `5276` (0x149c):
```asm
0x080484e3 <+79>:	mov    eax,DWORD PTR [esp+0x1c]
0x080484e7 <+83>:	cmp    eax,0x149c
0x080484ec <+88>:	jne    0x804850d <main+121>
```

3. Por lo tanto tan solo tendremos que escribir el número `5276` cuando el programa nos lo pida.

Para ver con detalle el analisis consuta el archivo  [asm_analysis.md](https://github.com/4trastos/OverRide/blob/main/level00/Resources/README.md) en conjunto con el programa de demostración  [source.c](https://github.com/4trastos/OverRide/blob/main/level00/source.c).


### **Ejecución:**

Usamos la contraseña que hemos encontrado guardada en el binairo para obtener los permisos de lectura del `level01`:

```bash
level00@OverRide:~$ ./level00 
***********************************
* 	     -Level00 -		  *
***********************************
Password:5276

Authenticated!
$ pwd
/home/users/level00
$ cat /home/users/level01/.pass
uSq2ehEGT6c9S24zbshexZQBXUGrncxn5sD5QfGL
$ 
level00@OverRide:~$ su level01
Password: 
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Partial RELRO   No canary found   NX disabled   No PIE          No RPATH   No RUNPATH   /home/users/level01/level01
level01@OverRide:~$ 
```

# 7. Conclusión:

El nivel 00 de OverRide nos introduce en el análisis de flujo de control. A diferencia de Rainfall, donde la vulnerabilidad solía ser técnica (memoria), aquí es lógica: una `puerta trasera` (backdoor) integrada en el código mediante una comparación fija de una contraseña numérica `(5276)`.