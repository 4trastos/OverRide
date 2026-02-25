# **ANÁLISIS COMPLETO LINEA POR LINEA - NIVEL level00**

```asm
Dump of assembler code for function main:
   0x08048494 <+0>:     push   ebp
   0x08048495 <+1>:	    mov    ebp,esp
   0x08048497 <+3>:	    and    esp,0xfffffff0
   0x0804849a <+6>:	    sub    esp,0x20
   0x0804849d <+9>:	    mov    DWORD PTR [esp],0x80485f0
   0x080484a4 <+16>:	call   0x8048390 <puts@plt>
   0x080484a9 <+21>:	mov    DWORD PTR [esp],0x8048614
   0x080484b0 <+28>:	call   0x8048390 <puts@plt>
   0x080484b5 <+33>:	mov    DWORD PTR [esp],0x80485f0
   0x080484bc <+40>:	call   0x8048390 <puts@plt>
   0x080484c1 <+45>:	mov    eax,0x804862c
   0x080484c6 <+50>:	mov    DWORD PTR [esp],eax
   0x080484c9 <+53>:	call   0x8048380 <printf@plt>
   0x080484ce <+58>:	mov    eax,0x8048636
   0x080484d3 <+63>:	lea    edx,[esp+0x1c]
   0x080484d7 <+67>:	mov    DWORD PTR [esp+0x4],edx
   0x080484db <+71>:	mov    DWORD PTR [esp],eax
   0x080484de <+74>:	call   0x80483d0 <__isoc99_scanf@plt>
   0x080484e3 <+79>:	mov    eax,DWORD PTR [esp+0x1c]
   0x080484e7 <+83>:	cmp    eax,0x149c
   0x080484ec <+88>:	jne    0x804850d <main+121>
   0x080484ee <+90>:	mov    DWORD PTR [esp],0x8048639
   0x080484f5 <+97>:	call   0x8048390 <puts@plt>
   0x080484fa <+102>:	mov    DWORD PTR [esp],0x8048649
   0x08048501 <+109>:	call   0x80483a0 <system@plt>
   0x08048506 <+114>:	mov    eax,0x0
   0x0804850b <+119>:	jmp    0x804851e <main+138>
   0x0804850d <+121>:	mov    DWORD PTR [esp],0x8048651
   0x08048514 <+128>:	call   0x8048390 <puts@plt>
   0x08048519 <+133>:	mov    eax,0x1
   0x0804851e <+138>:	leave  
   0x0804851f <+139>:	ret    
End of assembler dump.
```

### **Líneas 0, 1, 3 y 6:**
```asm
0x08048494 <+0>:    push   ebp
0x08048495 <+1>:	mov    ebp,esp
0x08048497 <+3>:	and    esp,0xfffffff0
0x0804849a <+6>:    sub    esp,0x20
```

1. <+0>: Guarda en el stack en valor de EBP (cpu): [esp + 0x00] y ESP se desplaza 8 bytes hacia abajo.
2. <+1>: Copia en  EBP en nuevo ESP para la función `main`
3. <+3>: Alinea el stack a multiplo de 8. (los últimos 4 bytes se ponene a 0).
4. <+6>: Desplaza (Reserva) 32 bytes (0x20) de espacio para que el compilador en el stack de `main()`, organice las varibles locales y los argumentos de las funciones que `main()` va a llamar.

### **Línas 9, 16, 21, 28, 33 y 40: (Printea enunciado por termial)**
```asm
0x0804849d <+9>:	mov    DWORD PTR [esp],0x80485f0
0x080484a4 <+16>:	call   0x8048390 <puts@plt>
0x080484a9 <+21>:	mov    DWORD PTR [esp],0x8048614
0x080484b0 <+28>:	call   0x8048390 <puts@plt>
0x080484b5 <+33>:	mov    DWORD PTR [esp],0x80485f0
0x080484bc <+40>:	call   0x8048390 <puts@plt>
```

1. <+9>: Guarda en los alto del stack la dirección `0x80485f0` que contiene la primera línea de asteriscos `*`
```bash
(gdb) x/s 0x80485f0
0x80485f0:	 '*' <repeats 35 times>
```
2. <+16>: Llama la función `puts()` y muestra por pantalla 35 veces un `*`: `***********************************`
3. <+21> y <+28>: Actualiza lo alto del stack con la siguiente dirección `0x8048614` que contiene el nombre del nivel y lo muestra por pantalla:
```bash
(gdb) x/s 0x8048614
0x8048614:	 "* \t     -Level00 -\t\t  *"
```
4. <+33> y <+40>: Realiza la misma opración que en las ejecuciones <+9> y <+16>: `***********************************`

### **Líneas 15, 50, 53, 58 y 63:**
```asm
0x080484c1 <+45>:	mov    eax,0x804862c
0x080484c6 <+50>:	mov    DWORD PTR [esp],eax
0x080484c9 <+53>:	call   0x8048380 <printf@plt>
0x080484ce <+58>:	mov    eax,0x8048636
0x080484d3 <+63>:	lea    edx,[esp+0x1c]
```

1. <+45>: Carga en EAX el valor de la dirección `0x804862c` que contine la string `"Password:"`
```bash
(gdb) x/s 0x804862c
0x804862c:	 "Password:"
```
2. <+50>: Guarda EAX en lo alto del stack
3. <+53>: llama a la función `printf()` que muestra por pantalla el string almacenado en el `stack`: `"Password:"` 
4. <+58>: Carga e EAX el contenido de la dirección `0x8048636` que contiene: `"%d"` - (segundo argumento de `int scanf(const char *restrict format, ...)`)
```bash
(gdb) x/s 0x8048636
0x8048636:	 "%d"
```
5. <+63>: Calcula donde se encuentra la dirección que contiene `[esp+0x1c]` y lo copia en EDX. Es el buffer `stdin()` que contine el password que hemos escrito en la termninal.

### **Líneas 67, 71 y 74:**
```asm
0x080484d7 <+67>:	mov    DWORD PTR [esp+0x4],edx
0x080484db <+71>:	mov    DWORD PTR [esp],eax
0x080484de <+74>:	call   0x80483d0 <__isoc99_scanf@plt>
```

1. <+67>: Avanza 4 bytes en el stack y guarda el buffer leido (primer argumento de `int scanf(const char *restrict format, ...)`).
2. <+71>: Guarda en los alto del stack el segundo argumeto de la función `scanf()` almacenado en EAX (`"%d"`).
3. <+74>: Llama a la finción `scanf()`: `int scanf(const char *buffer, "%d");` y transforma el string del buffer en un número entero.

### **Líneas 79, 83 y 88:**
```asm
0x080484e3 <+79>:	mov    eax,DWORD PTR [esp+0x1c]
0x080484e7 <+83>:	cmp    eax,0x149c
0x080484ec <+88>:	jne    0x804850d <main+121>
```

1. <+79>: Carga en EAX el resultado de lo transformado por `scanf()`
2. <+83>: Compara el número: `5276` (0x149c) con lo que hemos escrito por el terminal.
3. <+74>: `JNE` (jump no exactly). Si no es igual salta a la línea <+121> y muestra el string de Password erroneo:
```bash
(gdb) x/s 0x8048651
0x8048651:	 "\nInvalid Password!"
```

### **Líneas 90, 97, 102 y 109:**
```asm
0x080484ee <+90>:	mov    DWORD PTR [esp],0x8048639
0x080484f5 <+97>:	call   0x8048390 <puts@plt>
0x080484fa <+102>:	mov    DWORD PTR [esp],0x8048649
0x08048501 <+109>:	call   0x80483a0 <system@plt>
```

1. <+90>: Guarda en lo alto del stack la dirección `0x8048639` que contiene el string `"\nAuthenticated!"`:
```bash
(gdb) x/s 0x8048639
0x8048639:	 "\nAuthenticated!"
```
2. <+97>: Llama a la función `printf()` y muestra por pantalla :` Authenticated!`
3. <+102>: Guarda en lo alto del stack la dirección `0x8048649` que contiene el comando : `/bin/sh`
```bash
(gdb) x/s 0x8048649
0x8048649:	 "/bin/sh"
```
4. <+109>: Llama a la función `system()`, ejecuta `system(/bin/sh)` y nos da los permisos de ejecución del level01.

### **Líneas:**
```asm
0x08048506 <+114>:	mov    eax,0x0
0x0804850b <+119>:	jmp    0x804851e <main+138>
0x0804850d <+121>:	mov    DWORD PTR [esp],0x8048651
0x08048514 <+128>:	call   0x8048390 <puts@plt>
0x08048519 <+133>:	mov    eax,0x1
0x0804851e <+138>:	leave  
0x0804851f <+139>:	ret    
```

1. <+114>: Pone a 0 el registro EAX
2. <+119>: Salta a al línea <+138> donde borra y sale del programa
3. <+121>: Guarda en lo alto del stack la dirección de memoria `0x8048651` que contiee la string: `Invalid Password!`
```bash
(gdb) x/s 0x8048651
0x8048651:	 "\nInvalid Password!"
```
4. <+128>: Llama a la fución `puts()` y muestra por el terminal la string guarda en el `stack`
5. <+133> a <+130>: Sale del programa.

### **Resumen del Flujo de Ataque para el Nivel 00**

1. **Lectura:** El programa deja abierta la terminal donde nos pide que escribamos el password. Si el password es correcto, llama a la fucnión `system(/bin/sh)` y nos concede permisos de level01 para poder leer el password del siguiente nivel.

2. **Vulnerabilidad:** En el código se han dejado escrito el Password que ejecuta el comando de permisos de usuario.

* En la línea `<+83>` El programa compara el número: `5276` (0x149c) con lo que hemos escrito por el terminal.

3. **Explotación:**

* **Paso 1:** Una vez encontrado el password, escribirlo y leer el password del `level01`
