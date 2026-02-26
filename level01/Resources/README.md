# **ANÁLISIS COMPLETO LINEA POR LINEA - NIVEL level01**

```asm
Dump of assembler code for function main:
   0x080484d0 <+0>:	    push   ebp
   0x080484d1 <+1>:	    mov    ebp,esp
   0x080484d3 <+3>:	    push   edi
   0x080484d4 <+4>:	    push   ebx
   0x080484d5 <+5>:	    and    esp,0xfffffff0
   0x080484d8 <+8>:     sub    esp,0x60
   0x080484db <+11>:	lea    ebx,[esp+0x1c]
   0x080484df <+15>:	mov    eax,0x0
   0x080484e4 <+20>:	mov    edx,0x10
   0x080484e9 <+25>:	mov    edi,ebx
   0x080484eb <+27>:	mov    ecx,edx
   0x080484ed <+29>:	rep stos DWORD PTR es:[edi],eax
   0x080484ef <+31>:	mov    DWORD PTR [esp+0x5c],0x0
   0x080484f7 <+39>:	mov    DWORD PTR [esp],0x80486b8
   0x080484fe <+46>:	call   0x8048380 <puts@plt>
   0x08048503 <+51>:	mov    eax,0x80486df
   0x08048508 <+56>:	mov    DWORD PTR [esp],eax
   0x0804850b <+59>:	call   0x8048360 <printf@plt>
   0x08048510 <+64>:	mov    eax,ds:0x804a020
   0x08048515 <+69>:	mov    DWORD PTR [esp+0x8],eax
   0x08048519 <+73>:	mov    DWORD PTR [esp+0x4],0x100
   0x08048521 <+81>:	mov    DWORD PTR [esp],0x804a040
   0x08048528 <+88>:	call   0x8048370 <fgets@plt>
   0x0804852d <+93>:	call   0x8048464 <verify_user_name>
   0x08048532 <+98>:	mov    DWORD PTR [esp+0x5c],eax
   0x08048536 <+102>:	cmp    DWORD PTR [esp+0x5c],0x0
   0x0804853b <+107>:	je     0x8048550 <main+128>
   0x0804853d <+109>:	mov    DWORD PTR [esp],0x80486f0
   0x08048544 <+116>:	call   0x8048380 <puts@plt>
   0x08048549 <+121>:	mov    eax,0x1
   0x0804854e <+126>:	jmp    0x80485af <main+223>
   0x08048550 <+128>:	mov    DWORD PTR [esp],0x804870d
   0x08048557 <+135>:	call   0x8048380 <puts@plt>
   0x0804855c <+140>:	mov    eax,ds:0x804a020
   0x08048561 <+145>:	mov    DWORD PTR [esp+0x8],eax
   0x08048565 <+149>:	mov    DWORD PTR [esp+0x4],0x64
   0x0804856d <+157>:	lea    eax,[esp+0x1c]
   0x08048571 <+161>:	mov    DWORD PTR [esp],eax
   0x08048574 <+164>:	call   0x8048370 <fgets@plt>
   0x08048579 <+169>:	lea    eax,[esp+0x1c]
   0x0804857d <+173>:	mov    DWORD PTR [esp],eax
   0x08048580 <+176>:	call   0x80484a3 <verify_user_pass>
   0x08048585 <+181>:	mov    DWORD PTR [esp+0x5c],eax
   0x08048589 <+185>:	cmp    DWORD PTR [esp+0x5c],0x0
   0x0804858e <+190>:	je     0x8048597 <main+199>
   0x08048590 <+192>:	cmp    DWORD PTR [esp+0x5c],0x0
   0x08048595 <+197>:	je     0x80485aa <main+218>
   0x08048597 <+199>:	mov    DWORD PTR [esp],0x804871e
   0x0804859e <+206>:	call   0x8048380 <puts@plt>
   0x080485a3 <+211>:	mov    eax,0x1
   0x080485a8 <+216>:	jmp    0x80485af <main+223>
   0x080485aa <+218>:	mov    eax,0x0
   0x080485af <+223>:	lea    esp,[ebp-0x8]
   0x080485b2 <+226>:	pop    ebx
   0x080485b3 <+227>:	pop    edi
   0x080485b4 <+228>:	pop    ebp
   0x080485b5 <+229>:	ret    
End of assembler dump.
```

### **Líneas 0, 1, 3, 4, 5, 8 y 11:**
```asm
0x080484d0 <+0>:    push   ebp
0x080484d1 <+1>:    mov    ebp,esp
0x080484d3 <+3>:    push   edi
0x080484d4 <+4>:    push   ebx
0x080484d5 <+5>:    and    esp,0xfffffff0
0x080484d8 <+8>:    sub    esp,0x60
0x080484db <+11>:   lea    ebx,[esp+0x1c]
```

1. <+0>: Guarda en lo alto del stack el valor de EBP (cpu): `[esp + 0x00]`. El ESP se desplaza 4 bytes hacia abajo
2. <+1>: Asigna el nuevo ESP a EBP para la función `main`
3. <+3>: Guarda en el stack `[esp + 0x04]` el valor de EDI para usarlo mas adelante y desplaza ESP 4 bytes hacia abajo.
4. <+4>: Guarda en el stack `[esp + 0x08]` el valor de EBX y desplaza de nuevo 4 bytes hacia abajo el ESP.
5. <+5>: Alinea el stack a múltiplo de 16 (los últimos 4 bytes se ponene a 0).
6. <+8>: Desplaza (Reserva) 96 bytes (0x60) en el stack de `main()` para que el compilador organice las variables locales y los arguemntos de las funciones que `main()` va a llamar.
7. <+11>: `lea` (Load Effective Address). Calcula la dirección de la variable global `FILE *file` en el stack `[esp+0x1c]` y la copia en EBX que es donde después escribiremos el password.

### **Líneas 15, 20, 25, 27 y 29: (memset())**
```asm
0x080484df <+15>:	mov    eax,0x0
0x080484e4 <+20>:	mov    edx,0x10
0x080484e9 <+25>:	mov    edi,ebx
0x080484eb <+27>:	mov    ecx,edx
0x080484ed <+29>:	rep stos DWORD PTR es:[edi],eax
```

1. <+15>: Pone un 0 en el registro EAX
2. <+20>: Pone en EDX (contador) el número 16 (0x10)
3. <+25>: Copia en EDI `[esp + 0x04]` la dirección de la variable `[esp+0x1c]` (apunta al buffer)
4. <+27>: Copia en ECX el numero 16.
5. <+29>: `rep stos DWORD PTR es:[edi],eax`: 
- `stos` -> Store String. Copia el valor de EAX (que es 0) en la dirección apuntada por EDI.
- Como es `DWORD` escribe 4 bytes  cada vez
- Como EXC es 16, lo hace 16 veces.
**Resultado**: Está poniendo a cero un bloque de 64 bytes (16×4 = 64). Es el equivalente en C a un `memset(file, 0, 64);`.

### **Líneas 31, 39, 46, 51, 56 y 59: (Printea la cabecera)**
```asm
0x080484ef <+31>:	mov    DWORD PTR [esp+0x5c],0x0
0x080484f7 <+39>:	mov    DWORD PTR [esp],0x80486b8
0x080484fe <+46>:	call   0x8048380 <puts@plt>
0x08048503 <+51>:	mov    eax,0x80486df
0x08048508 <+56>:	mov    DWORD PTR [esp],eax
0x0804850b <+59>:	call   0x8048360 <printf@plt>
```

1. <+31>: Pone un 0 en la dirección de memoria almacenada en el stack `[esp+0x5c]`
2. <+39>: Guarda el string que contiene la dirección `0x80486b8` en lo alto del stack como argumento de `puts()`.
```bash
(gdb) x/s 0x80486b8
0x80486b8:	 "********* ADMIN LOGIN PROMPT *********"
```
3. <+46>: Llama a `puts()` y muetra lo almacenado en ESP por el terminal
4. <+51>: Carfa en EAX el valor de la dirección `0x80486df`:
```bash
(gdb) x/s 0x80486df
0x80486df:	 "Enter Username: "
```
5. <+56>: Lo guarda en lo alto del stack como argumento de `printf()`.
6. <+59>: Llama a la función `printf()` y muetsra por pantalla : `"Enter Username: "`

### **Líneas 64, 69, 73, 81, 88 y 93:**
```asm
0x08048510 <+64>:	mov    eax,ds:0x804a020
0x08048515 <+69>:	mov    DWORD PTR [esp+0x8],eax
0x08048519 <+73>:	mov    DWORD PTR [esp+0x4],0x100
0x08048521 <+81>:	mov    DWORD PTR [esp],0x804a040
0x08048528 <+88>:	call   0x8048370 <fgets@plt>
0x0804852d <+93>:	call   0x8048464 <verify_user_name>
```

1. <+64>: `ds` es el prefijo de segmento de datos (valor de una variable global). En este caso el buffer de `stdin()` `(FILE    *file)`;
```bash
(gdb) x/s 0x804a020
0x804a020 <stdin@@GLIBC_2.0>:	 ""
```
2. <+69>: Guardamos la varible global (buffer) como el primer argumento para `fgtes()` en `[esp+0x8]
3. <+73>: El segundo argumento (tamaño) en `[esp+0x4]` 256 (0x100).
4. <+81>: y en lo alto del stack el tercer argumento la dirección `0x804a040` que contiene el string (`a_user_name`) con el nombre del usuario:
```bash
(gdb) x/s 0x804a040
0x804a040 <a_user_name>:	 ""
```
5. <+88>: Llama a la función `fgets()`: `fgets(a_user_name, 256, file)`. Guarda en la variable `a_user_name` el nombre introducido por el teminal.
6. <+93>: Llama a la fución `<verify_user_name>`.

## ANÁLISIS DE LA FUCIÓN `<verify_user_name>`:

```asm
Dump of assembler code for function verify_user_name:
   0x08048464 <+0>:	   push   ebp
   0x08048465 <+1>:	   mov    ebp,esp
   0x08048467 <+3>:	   push   edi
   0x08048468 <+4>:	   push   esi
   0x08048469 <+5>:	   sub    esp,0x10
   0x0804846c <+8>:     mov    DWORD PTR [esp],0x8048690
   0x08048473 <+15>:    call   0x8048380 <puts@plt>
   0x08048478 <+20>:	   mov    edx,0x804a040
   0x0804847d <+25>:	   mov    eax,0x80486a8
   0x08048482 <+30>: 	mov    ecx,0x7
   0x08048487 <+35>:	   mov    esi,edx
   0x08048489 <+37>:	   mov    edi,eax
   0x0804848b <+39>:	   repz cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
   0x0804848d <+41>:	   seta   dl
   0x08048490 <+44>:	   setb   al
   0x08048493 <+47>:	   mov    ecx,edx
   0x08048495 <+49>:	   sub    cl,al
   0x08048497 <+51>:	   mov    eax,ecx
   0x08048499 <+53>:	   movsx  eax,al
   0x0804849c <+56>:	   add    esp,0x10
   0x0804849f <+59>:	   pop    esi
   0x080484a0 <+60>:	   pop    edi
   0x080484a1 <+61>:	   pop    ebp
   0x080484a2 <+62>:	   ret    
End of assembler dump.
```
### **Líneas 0, 1, 3, 4, 5, 8 y 15:**
```asm
0x08048464 <+0>:	 push   ebp
0x08048465 <+1>:	 mov    ebp,esp
0x08048467 <+3>:	 push   edi
0x08048468 <+4>:	 push   esi
0x08048469 <+5>:	 sub    esp,0x10
0x0804846c <+8>:   mov    DWORD PTR [esp],0x8048690
0x08048473 <+15>:  call   0x8048380 <puts@plt>
```

1. <+0>: Guarda en el stack `[esp+0x00]` el valor de EBP `(main())` y ESP se desplaza 4 bytes hacia abajo.
2. <+1>: Copia el nuevo ESP en EBP para la función `verify_user_name()`.
3. <+3>: Guarda en el stack `[esp+0x04]` la dirección de EDI para usarlo más adelante y desplaza hacia abajo 4 bytes ESP.
4. <+4>: Guarda en el stack `[esp+0x08]` la dirección de ESI para usalo más adelante y desplaza ESP hacia abajo 4 bytes más.
5. <+5>: Desplaza (Reserva) 16 bytes (0x10) para el compilador en el stack de `verify_user_name()` organice las variables locales y finciones a las que `verify_user_name()` llamará.
6. <+8>: Guarda en el alto del stack la dirección `0x8048690` que contiene una string como argumento de `puts()`:
```bash
(gdb) x/s 0x8048690
0x8048690:	 "verifying username....\n"
```
7. <+15>: Llama a la función `pust()`.

### **Líneas 20, 25, 30, 35, 37 y 39:**
```asm
0x08048478 <+20>:	mov    edx,0x804a040
0x0804847d <+25>:	mov    eax,0x80486a8
0x08048482 <+30>:	mov    ecx,0x7
0x08048487 <+35>:	mov    esi,edx
0x08048489 <+37>:	mov    edi,eax
0x0804848b <+39>:	repz cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
```

1. <+20>: Carga en EDX la direccion `0x804a040`. La variable global: `<a_user_name>`
2. <+25>: Carga en EAX la dirección `0x80486a8` que contiene el string con el nombre del usuario que el programa espera recibir:
```bash
(gdb) x/s 0x80486a8
0x80486a8:	 "dat_wil"
```
**IMPORTANTE:** - Hemos encontrado una vulnerabilidad (credencial expuesta). Hemos encontrado el nombre del usuario.
3. <+30>: Copia el número 7 en el contador ECX (0x7). Como primer argumento de `strncmp()`
4. <+35>: Copia el `a_user_name` en ESI, como segundo argumento.
5. <+37>: Copia el nombre real `"dat_wil"` guardado en EAX como tercer argumento.
6. <+39>: Compara las dos strings bytes a byte un máximo de 7 bytes. `strncmp("dat_wil", a_user_name, 7)`

### **Líneas 41, 44, 47, 49, 51, 53 y 56:**
```asm
0x0804848d <+41>:	seta   dl
0x08048490 <+44>:	setb   al
0x08048493 <+47>:	mov    ecx,edx
0x08048495 <+49>:	sub    cl,al
0x08048497 <+51>:	mov    eax,ecx
0x08048499 <+53>:	movsx  eax,al
0x0804849c <+56>:	add    esp,0x10
```

1. <+41>: `seta` (Set if Above) pone 1 en DL si `a_user_name > dat_wil`. Pone 0 si no es mayor.
2. <+44>: `setb` (Set if Below) pone 1 en AL si `a_user_name < dat_wil`. Pone 0 si no es menor.
3. <+47>: Copia EDX en ECX.
4. <+49>: Resta AL de CL: `(CL = DL - AL)`. El resultado es el equivalente al valor de retorno de `strncmp()`: *negativo, 0 o positivo*.
5. <+51>: Copia EDX en EAX. Donde devuelve el valor de retorno la función.
6. <+53>: `movsx` extiende con signo AL a EAX completo para que el valor de retorno sea correcto como entero con signo.
7. <+56>: Libera los 16 bytes (0x10) que se reservaron para este función en el paso `<+5>`

### **Lineas :**
```asm
0x0804849f <+59>:	pop    esi
0x080484a0 <+60>:	pop    edi
0x080484a1 <+61>:	pop    ebp
0x080484a2 <+62>:	ret  
```

1. <+59> al <+61>: Quita del stack los registros guardados
2. <+62>: Retonna a `main()`.

## VOLVEMOS A `main()`:

### **Líneas 98, 102, 107, 109, 116, 121 y 126:**
```asm
0x08048532 <+98>:	mov    DWORD PTR [esp+0x5c],eax
0x08048536 <+102>:	cmp    DWORD PTR [esp+0x5c],0x0
0x0804853b <+107>:	je     0x8048550 <main+128>
0x0804853d <+109>:	mov    DWORD PTR [esp],0x80486f0
0x08048544 <+116>:	call   0x8048380 <puts@plt>
0x08048549 <+121>:	mov    eax,0x1
0x0804854e <+126>:	jmp    0x80485af <main+223>
```

1. <+98>: El contenido de EAX (El valor retornado por `strncmp()` se guarda en el stack `[esp+0x5c]`).
2. <+102>: Testea que EAX si el valor es 0,
3. <+107>: `je` Si es 0 salta la línea <+128>. (Usuario es correcto)
4. <+109>: Guarda en lo alto del stack la dirección `0x80486f0` que contiene una string. Como argumento para `puts()`:
```bash
(gdb) x/s 0x80486f0
0x80486f0:	 (gdb) x/s 0x80486f0
0x80486f0:	 "nope, incorrect username...\n"
```
5. <+116>: Llama a `pust("nope, incorrect username...\n")`
6. <+121>: Pone un 1 en EAX
7. <+126>: Salra a la línea <+223> para terminar el programa.

### **Lineas 128, 135 y 140:**
```asm
0x08048550 <+128>:	mov    DWORD PTR [esp],0x804870d
0x08048557 <+135>:	call   0x8048380 <puts@plt>
0x0804855c <+140>:	mov    eax,ds:0x804a020
```

1. <+128>: Guarda en lo alto del stack la dirección `0x804870d` que contiene el string ` "Enter Password: "`:
```bash
(gdb) x/s 0x804870d
0x804870d:	 "Enter Password: "
```
2. <+135>: Llama a la función `puts()` y printea: `"Enter Password: "`
3. <+140>: `ds` (segmento de datos). Valor de una variable global es este caso: `FILE *file` de la función `stdin()`:
```bash
(gdb) x/s 0x804a020
0x804a020 <stdin@@GLIBC_2.0>:	 ""
```

### **Líneas 145, 149, 157, 161, 164, 169, 173 y 176:**
```asm
0x08048561 <+145>:	mov    DWORD PTR [esp+0x8],eax
0x08048565 <+149>:	mov    DWORD PTR [esp+0x4],0x64
0x0804856d <+157>:	lea    eax,[esp+0x1c]
0x08048571 <+161>:	mov    DWORD PTR [esp],eax
0x08048574 <+164>:	call   0x8048370 <fgets@plt>
0x08048579 <+169>:	lea    eax,[esp+0x1c]
0x0804857d <+173>:	mov    DWORD PTR [esp],eax
0x08048580 <+176>:	call   0x80484a3 <verify_user_pass>
```

1. <+145>: Guarda en el stack en `[esp+0x8]` como primer arguento de `fgets()`. Lo leido por `stdin()`.
2. <+149>: Guarda en el stacj en `[esp+0x4]` como segundo algumento el número 100 (0x64)
3. <+157>: Recupera en EAX la dirección de la varible global `a_user_name`.
4. <+161>: Guarda EAX en lo alto del stack como tercer argumento.
5. <+164>: Llama a la función `fgets()`: `fgets(a_user_name, 100, file)`
6. <+169>: Recupera en EAX el puntero del buffer
7. <+173>: Lo guarda en lo alto del stack y lo pasa como argumento a la siguiente función.
8. <+176>: Llama a la función : `<verify_user_pass>`

## ANÁLISIS DE LA FUCIÓN `<verify_user_pass>`:

```asm
Dump of assembler code for function verify_user_pass:
   0x080484a3 <+0>:	push   ebp
   0x080484a4 <+1>:	mov    ebp,esp
   0x080484a6 <+3>:	push   edi
   0x080484a7 <+4>:	push   esi
   0x080484a8 <+5>:	mov    eax,DWORD PTR [ebp+0x8]
   0x080484ab <+8>:	mov    edx,eax
   0x080484ad <+10>:	mov    eax,0x80486b0
   0x080484b2 <+15>:	mov    ecx,0x5
   0x080484b7 <+20>:	mov    esi,edx
   0x080484b9 <+22>:	mov    edi,eax
   0x080484bb <+24>:	repz cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
   0x080484bd <+26>:	seta   dl
   0x080484c0 <+29>:	setb   al
   0x080484c3 <+32>:	mov    ecx,edx
   0x080484c5 <+34>:	sub    cl,al
   0x080484c7 <+36>:	mov    eax,ecx
   0x080484c9 <+38>:	movsx  eax,al
   0x080484cc <+41>:	pop    esi
   0x080484cd <+42>:	pop    edi
   0x080484ce <+43>:	pop    ebp
   0x080484cf <+44>:	ret    
End of assembler dump.
```

### **Líneas 0, 1, 3, 4 y 5:**
```asm
0x080484a3 <+0>:	push   ebp
0x080484a4 <+1>:	mov    ebp,esp
0x080484a6 <+3>:	push   edi
0x080484a7 <+4>:	push   esi
0x080484a8 <+5>:	mov    eax,DWORD PTR [ebp+0x8]
```

1. <+0>: Guarda en el stack `[esp+0x00]` el valor de EBP `(main())` y ESP se desplaza 4 bytes hacia abajo.
2. <+1>: Copia el nuevo ESP en EBP para la función `verify_user_name()`.
3. <+3>: Guarda en el stack `[esp+0x04]` la dirección de EDI para usarlo más adelante y desplaza hacia abajo 4 bytes ESP.
4. <+4>: Guarda en el stack `[esp+0x08]` la dirección de ESI para usalo más adelante y desplaza ESP hacia abajo 4 bytes más.
5. <+5>: Carga en EAX el argumento recibido `[ebp+0x8]` -> String con el password

### **Líneas 8, 10, 15, 20, 22 y 24: Compara el password**
```asm
0x080484ab <+8>:	mov    edx,eax
0x080484ad <+10>:	mov    eax,0x80486b0
0x080484b2 <+15>:	mov    ecx,0x5
0x080484b7 <+20>:	mov    esi,edx
0x080484b9 <+22>:	mov    edi,eax
0x080484bb <+24>:	repz cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
```

1. <+8>: Copia el password escrito por el terminal y lo guarda en EDX. Primer argumento de `strncmp()`.
2. <+10>: Carga en EAX el valor de la dirección `0x80486b0` que contiene un string con la palabra: `"admin"`:
```bash
(gdb) x/s 0x80486b0
0x80486b0:	 "admin"
```
3. <+15>: Guarda el número 5 en ECX (longitud) y primer argumento de `strncmp()`.
4. <+20>: Copia en ESI el registro EDX y segundo argumento de `strncmp()`.
5. <+22>: Copia en EDI el registro EAX (`"admin"`) y tercer argumtno de `strncmp()`.
6. <+24>: Compara las dos strings bytes a byte un máximo de 5 bytes. `strncmp("admin", a_user_name, 5)`

### **Líneas:**
```asm
0x080484bd <+26>:	seta   dl
0x080484c0 <+29>:	setb   al
0x080484c3 <+32>:	mov    ecx,edx
0x080484c5 <+34>:	sub    cl,al
0x080484c7 <+36>:	mov    eax,ecx
0x080484c9 <+38>:	movsx  eax,al
```