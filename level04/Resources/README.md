# **ANÁLISIS COMPLETO LINEA POR LINEA - NIVEL level04**

```asm
Dump of assembler code for function main:
   0x080486c8 <+0>:	    push   ebp
   0x080486c9 <+1>:	    mov    ebp,esp
   0x080486cb <+3>:	    push   edi
   0x080486cc <+4>:	    push   ebx
   0x080486cd <+5>:	    and    esp,0xfffffff0
   0x080486d0 <+8>:	    sub    esp,0xb0
   0x080486d6 <+14>:	call   0x8048550 <fork@plt>
   0x080486db <+19>:	mov    DWORD PTR [esp+0xac],eax
   0x080486e2 <+26>:	lea    ebx,[esp+0x20]
   0x080486e6 <+30>:	mov    eax,0x0
   0x080486eb <+35>:	mov    edx,0x20
   0x080486f0 <+40>:	mov    edi,ebx
   0x080486f2 <+42>:	mov    ecx,edx
   0x080486f4 <+44>:	rep stos DWORD PTR es:[edi],eax
   0x080486f6 <+46>:	mov    DWORD PTR [esp+0xa8],0x0
   0x08048701 <+57>:	mov    DWORD PTR [esp+0x1c],0x0
   0x08048709 <+65>:	cmp    DWORD PTR [esp+0xac],0x0
   0x08048711 <+73>:	jne    0x8048769 <main+161>
   0x08048713 <+75>:	mov    DWORD PTR [esp+0x4],0x1
   0x0804871b <+83>:	mov    DWORD PTR [esp],0x1
   0x08048722 <+90>:	call   0x8048540 <prctl@plt>
   0x08048727 <+95>:	mov    DWORD PTR [esp+0xc],0x0
   0x0804872f <+103>:	mov    DWORD PTR [esp+0x8],0x0
   0x08048737 <+111>:	mov    DWORD PTR [esp+0x4],0x0
   0x0804873f <+119>:	mov    DWORD PTR [esp],0x0
   0x08048746 <+126>:	call   0x8048570 <ptrace@plt>
   0x0804874b <+131>:	mov    DWORD PTR [esp],0x8048903
   0x08048752 <+138>:	call   0x8048500 <puts@plt>
   0x08048757 <+143>:	lea    eax,[esp+0x20]
   0x0804875b <+147>:	mov    DWORD PTR [esp],eax
   0x0804875e <+150>:	call   0x80484b0 <gets@plt>
   0x08048763 <+155>:	jmp    0x804881a <main+338>
   0x08048768 <+160>:	nop
   0x08048769 <+161>:	lea    eax,[esp+0x1c]
   0x0804876d <+165>:	mov    DWORD PTR [esp],eax
   0x08048770 <+168>:	call   0x80484f0 <wait@plt>
   0x08048775 <+173>:	mov    eax,DWORD PTR [esp+0x1c]
   0x08048779 <+177>:	mov    DWORD PTR [esp+0xa0],eax
   0x08048780 <+184>:	mov    eax,DWORD PTR [esp+0xa0]
   0x08048787 <+191>:	and    eax,0x7f
   0x0804878a <+194>:	test   eax,eax
   0x0804878c <+196>:	je     0x80487ac <main+228>
   0x0804878e <+198>:	mov    eax,DWORD PTR [esp+0x1c]
   0x08048792 <+202>:	mov    DWORD PTR [esp+0xa4],eax
   0x08048799 <+209>:	mov    eax,DWORD PTR [esp+0xa4]
   0x080487a0 <+216>:	and    eax,0x7f
   0x080487a3 <+219>:	add    eax,0x1
   0x080487a6 <+222>:	sar    al,1
   0x080487a8 <+224>:	test   al,al
   0x080487aa <+226>:	jle    0x80487ba <main+242>
   0x080487ac <+228>:	mov    DWORD PTR [esp],0x804891d
   0x080487b3 <+235>:	call   0x8048500 <puts@plt>
   0x080487b8 <+240>:	jmp    0x804881a <main+338>
   0x080487ba <+242>:	mov    DWORD PTR [esp+0xc],0x0
   0x080487c2 <+250>:	mov    DWORD PTR [esp+0x8],0x2c
   0x080487ca <+258>:	mov    eax,DWORD PTR [esp+0xac]
   0x080487d1 <+265>:	mov    DWORD PTR [esp+0x4],eax
   0x080487d5 <+269>:	mov    DWORD PTR [esp],0x3
   0x080487dc <+276>:	call   0x8048570 <ptrace@plt>
   0x080487e1 <+281>:	mov    DWORD PTR [esp+0xa8],eax
   0x080487e8 <+288>:	cmp    DWORD PTR [esp+0xa8],0xb
   0x080487f0 <+296>:	jne    0x8048768 <main+160>
   0x080487f6 <+302>:	mov    DWORD PTR [esp],0x8048931
   0x080487fd <+309>:	call   0x8048500 <puts@plt>
   0x08048802 <+314>:	mov    DWORD PTR [esp+0x4],0x9
   0x0804880a <+322>:	mov    eax,DWORD PTR [esp+0xac]
   0x08048811 <+329>:	mov    DWORD PTR [esp],eax
   0x08048814 <+332>:	call   0x8048520 <kill@plt>
   0x08048819 <+337>:	nop
   0x0804881a <+338>:	mov    eax,0x0
   0x0804881f <+343>:	lea    esp,[ebp-0x8]
   0x08048822 <+346>:	pop    ebx
   0x08048823 <+347>:	pop    edi
   0x08048824 <+348>:	pop    ebp
   0x08048825 <+349>:	ret    
End of assembler dump.
```

### **Líneas 0, 1, 3, 4, 5, 8 y 14:**
```asm
0x080486c8 <+0>:	    push   ebp
0x080486c9 <+1>:	    mov    ebp,esp
0x080486cb <+3>:	    push   edi
0x080486cc <+4>:	    push   ebx
0x080486cd <+5>:	    and    esp,0xfffffff0
0x080486d0 <+8>:	    sub    esp,0xb0
0x080486d6 <+14>:	call   0x8048550 <fork@plt>
```

1. <+0>: Guarda en lo alto del stack el valor de `EBP` (cpu) `[esp + 0x00]`. El `esp` se desplaza 4 bytes hacia abajo.
2. <+1>: Asigna en nuevo `esp` a `ebp` para la función `main`
3. <+3>: Guarda en el stack de `main()` el registro `edi` para usarlo más adelante
4. <+4>: Guarda en el stack de `main()` el registro `ebx` para usarlo más adelante
5. <+5>: Alinea el stack a múltiplo de 16. (los últimos 4 bytes se ponene a 0).
6. <+8>: Reserva (desplaza) `176 bytes` (0xb0) en el stack de `main()` para que el compilador organice las varibles locales y los argumentos de las funciones que `main()` va a llamar.
7. <+14>: Llama a `fork()`.

### **Líneas 19, 26, 30, 35, 40, 42 y 44:**
```asm
0x080486db <+19>:	mov    DWORD PTR [esp+0xac],eax
0x080486e2 <+26>:	lea    ebx,[esp+0x20]
0x080486e6 <+30>:	mov    eax,0x0
0x080486eb <+35>:	mov    edx,0x20
0x080486f0 <+40>:	mov    edi,ebx
0x080486f2 <+42>:	mov    ecx,edx
0x080486f4 <+44>:	rep stos DWORD PTR es:[edi],eax
```

1. <+19>: Copia el resultado del fork() en la variable `id` que se encuntra en esta dirección del stack `[esp+0xac]`.
2. <+26>: Calcula la direcciñon de la variable `user_input` que se encuantra en `[esp+0x20]` y la carga en `ebx`
3. <+30>: Pone a 0 `eax`
4. <+35>: Escirbe el númeoro `32` en decimal (0x20) en el `edx` que hará como contador.
5. <+40>: Copia la variable `user_input` en el registro `edi` para pasarlo como arguemnto en el bucle.
6. <+42>: Copia en contador en `ecx` como otro argumento.
7. <+44>: Es la versión de 32 bits del `memset()`.
```c
memset(user_input, 0, 32);
```
- `rep`: Repite la instrucción siguiente (`stos DWORD`) tantas veces como indique `ECX` (32).
- `stos DWORD`: Copia el valor de `EAX` (0) en la dirección apuntada por `EDI`.
- **Tamaño**: Al ser `DWORD` escribe 4 bytes en cada repetición.
- **Resultado**: Está llenando de ceros un bloque de memoria de `128 bytes` (32 × 4 = 128). Este bloque empieza en `[esp+0x20]`

### **Líneas 46, 57, 65 y 73:**
```asm
0x080486f6 <+46>:	mov    DWORD PTR [esp+0xa8],0x0
0x08048701 <+57>:	mov    DWORD PTR [esp+0x1c],0x0
0x08048709 <+65>:	cmp    DWORD PTR [esp+0xac],0x0
0x08048711 <+73>:	jne    0x8048769 <main+161>
```

1. <+46>: Pone a 0 la variable que se encuentra en `[esp+0xa8]`
2. <+57>: Pone a 0 la varable `status`.
3. <+65>: Compara la variable `pid` con un 0
4. <+73>: `jne`. Si `pid != 0`  estamos en el proceso padre y salta a <main+161>. Si `pid == 0` estamos en el proceso hijo y continúa.

### **Líneas 75, 83, 90, 95, 103, 111, 119 y 126:**
```asm
0x08048713 <+75>:	mov    DWORD PTR [esp+0x4],0x1
0x0804871b <+83>:	mov    DWORD PTR [esp],0x1
0x08048722 <+90>:	call   0x8048540 <prctl@plt>
0x08048727 <+95>:	mov    DWORD PTR [esp+0xc],0x0
0x0804872f <+103>:	mov    DWORD PTR [esp+0x8],0x0
0x08048737 <+111>:	mov    DWORD PTR [esp+0x4],0x0
0x0804873f <+119>:	mov    DWORD PTR [esp],0x0
0x08048746 <+126>:	call   0x8048570 <ptrace@plt>
```

1. <+75>: Escribe `1` en `[esp+0x4]` — segundo argumento de `prctl()`: la señal `SIGHUP`.
2. <+83>: Escribe `1` en `[esp]` — primer argumento de `prctl()`: `PR_SET_PDEATHSIG`.
3. <+90>: Llama a `prctl(PR_SET_PDEATHSIG, 1)` — hace que el hijo reciba `SIGHUP`
   y muera si el proceso padre es eliminado.
4. <+95>: Escribe `0` en `[esp+0xc]` — cuarto argumento de `ptrace()`: `data = 0`.
5. <+103>: Escribe `0` en `[esp+0x8]` — tercer argumento de `ptrace()`: `addr = 0`.
6. <+111>: Escribe `0` en `[esp+0x4]` — segundo argumento de `ptrace()`: `pid = 0`.
7. <+119>: Escribe `0` en `[esp]` — primer argumento de `ptrace()`: `PTRACE_TRACEME`.
8. <+126>: Llama a `ptrace(PTRACE_TRACEME, 0, 0, 0)` — el hijo le indica al kernel
   que el padre puede monitorizarlo. También actúa como **antidebugging**: si el
   proceso ya está siendo trazado por GDB, esta llamada fallará.

### **Líneas 131, 138, 143, 147, 150, 155 y 160:**
```asm
0x0804874b <+131>:	mov    DWORD PTR [esp],0x8048903
0x08048752 <+138>:	call   0x8048500 <puts@plt>
0x08048757 <+143>:	lea    eax,[esp+0x20]
0x0804875b <+147>:	mov    DWORD PTR [esp],eax
0x0804875e <+150>:	call   0x80484b0 <gets@plt>
0x08048763 <+155>:	jmp    0x804881a <main+338>
0x08048768 <+160>:	nop
```

1. <+131>: Copia el contenido de la dirección `0x8048903` en el registro `esp` como argumneto para `puts()`:
```bash
(gdb) x/s 0x8048903
0x8048903:	 "Give me some shellcode, k"
```
2. <+138>: Llama a `puts()`
3. <+143>: Calcula la dirección de la variable `user_input` que se encuentra en `[esp+0x20]` y la carga en `eax`
4. <+147>: La copia en lo alto del stack como argumento de  `gets()`
5. <+150>: Llama a `gets()`.
6. <+155>: `jmp` incondicional a `<main+338>`. El hijo termina después de leer el input.
7. <+160>: No hace nada

### **Líneas 161, 165 y 168:**
```asm
0x08048769 <+161>:	lea    eax,[esp+0x1c]
0x0804876d <+165>:	mov    DWORD PTR [esp],eax
0x08048770 <+168>:	call   0x80484f0 <wait@plt>
```

1. <+161>:  Calcula la dirección de la variable `status` que se encuentra en `[esp+0x1c]` y la carga en `aex`. Será el argumento de `wait()`.
2. <+165>: La copia al stack
3. <+168>: Llama a `wait()`

### **Líneas 173 a 240:**
```asm
0x08048775 <+173>:	mov    eax,DWORD PTR [esp+0x1c]
0x08048779 <+177>:	mov    DWORD PTR [esp+0xa0],eax
0x08048780 <+184>:	mov    eax,DWORD PTR [esp+0xa0]
0x08048787 <+191>:	and    eax,0x7f
0x0804878a <+194>:	test   eax,eax
0x0804878c <+196>:	je     0x80487ac <main+228>
0x0804878e <+198>:	mov    eax,DWORD PTR [esp+0x1c]
0x08048792 <+202>:	mov    DWORD PTR [esp+0xa4],eax
0x08048799 <+209>:	mov    eax,DWORD PTR [esp+0xa4]
0x080487a0 <+216>:	and    eax,0x7f
0x080487a3 <+219>:	add    eax,0x1
0x080487a6 <+222>:	sar    al,1
0x080487a8 <+224>:	test   al,al
0x080487aa <+226>:	jle    0x80487ba <main+242>
0x080487ac <+228>:	mov    DWORD PTR [esp],0x804891d
0x080487b3 <+235>:	call   0x8048500 <puts@plt>
0x080487b8 <+240>:	jmp    0x804881a <main+338>
```

1.  <+173>: Carga la variable `status` en `eax`.
2.  <+177>: Guarda `status` en `[esp+0xa0]`. Primera copia
3.  <+184>: Carga la copia de `status` en `eax`.
4.  <+191>: Aplica máscara `AND 0x7f`. Extrae los 7 bits bajos del status. (código de señal si el proceso fue terminado por señal).
5.  <+194>: Comprueba si el resultado es 0.
6.  <+196>: `je` si es 0 el hijo terminó normalmente, salta a `<+228>` para imprimir `"child is exiting..."`.
7.  <+198>: Carga `status` en `eax` de nuevo.
8.  <+202>: Guarda en `[esp+0xa4]`. Segunda copia
9.  <+209>: Carga la segunda copia en `eax`.
10. <+216>: Aplica máscara `AND 0x7f` de nuevo.
11. <+219>: Suma 1 al resultado.
12. <+222>: `sar al, 1`. Desplazamiento aritmético derecha 1 bit (divide por 2).
13. <+224>: Comprueba si el resultado es 0.
14. <+226>: `jle` Si es <= 0 el hijo fue detenido por una señal y salta a `<+242>` (bloque ptrace).
15. <+228>: Carga en `[esp]` la dirección `0x804891d` del string `"child is exiting..."`.
```bash
(gdb) x/s 0x804891d
0x804891d:	 "child is exiting..."
```
16. <+235>: Llama a `puts()`.
17. <+240>: `jmp` incondicional a `<main+338>`. Termina el programa.

### **Líneas 242, 250, 258, 265, 269 y 276:**

1. <+242>: Escribe `0` en `[esp+0xc]` — cuarto argumento de `ptrace()`: `data = 0`.
2. <+250>: Escribe `0x2c` (44) en `[esp+0x8]` — tercer argumento de `ptrace()`: offset del registro `EAX` dentro de la estructura `user` del kernel.
3. <+258>: Carga en `EAX` el `pid` del hijo almacenado en `[esp+0xac]`.
4. <+265>: Copia `pid` en `[esp+0x4]` — segundo argumento de `ptrace()`.
5. <+269>: Escribe `3` en `[esp]` — primer argumento de `ptrace()`: `PTRACE_PEEKUSER`.
6. <+276>: Llama a `ptrace(PTRACE_PEEKUSER, pid, 44, 0)` — lee el valor del registro `EAX` del proceso hijo para ver qué syscall está ejecutando.

### **Líneas 281, 288, 296, 302, 309, 314, 322, 329 y 332:**

1. <+281>: Guarda el resultado de `ptrace()` en `wait_pid` `[esp+0xa8]` —
   contiene el número de la syscall que está ejecutando el hijo.
2. <+288>: Compara `wait_pid` con `0xb` (11) — el número de la syscall `execve()`.
3. <+296>: `jne` — si el hijo **no** está llamando a `execve()` vuelve a `<+160>` para seguir monitorizando.
4. <+302>: Carga en `[esp]` la dirección del string `"no exec() for you"`.
```bash
(gdb) x/s 0x8048931
0x8048931:	 "no exec() for you"
```
5. <+309>: Llama a `puts("no exec() for you")` — avisa que detectó `execve()`.
6. <+314>: Escribe `9` en `[esp+0x4]` — segundo argumento de `kill()`: señal `SIGKILL`.
7. <+322>: Carga en `EAX` el `pid` del hijo almacenado en `[esp+0xac]`.
8. <+329>: Copia `pid` en `[esp]` — primer argumento de `kill()`.
9. <+332>: Llama a `kill(pid, SIGKILL)` — elimina el hijo si intenta ejecutar `execve()`.


### **Líneas 337, 338, 343, 346, 347, 348 y 349:**

1. <+337>: `nop` NO hace nada.
2. <+338>: Pone `EAX` a 0 — valor de retorno de `main()`.
3. <+343>: Restaura `ESP` desde `[ebp-0x8]` — libera el stack frame.
4. <+346>: Restaura el registro `EBX`.
5. <+347>: Restaura el registro `EDI`.
6. <+348>: Restaura el `EBP` del caller.
7. <+349>: `ret` — retorna el control al sistema.


# Resumen del Flujo de Ataque para el Nivel 04

## 1. Lectura:

La vulnerabilidad está en la línea `<+150>` de `main` — en el proceso hijo:

```asm
0x0804875e <+150>: call   0x80484b0 <gets@plt>
```
```c
gets(user_input);
```
`gets()` no controla el tamaño del buffer — permite desbordar `user_input[128]`
y sobrescribir el `EIP`.

---

## 2. Vulnerabilidad:

* `user_input` se inicializa en `[esp+0x20]` con 128 bytes.
* `gets()` lee sin límite — podemos desbordar el buffer y pisar el `EIP`.
* El padre monitoriza al hijo con `ptrace(PTRACE_PEEKUSER)` y bloquea
  cualquier llamada a `execve()` (syscall `0xb`).
* No hay **Stack Canary** — el desbordamiento no será detectado.
* **NX está OFF** — el stack permite ejecución de shellcode.

---

## 3. Explotación:

* **Paso 1:** Calculamos el offset hasta el `EIP` con un patrón cíclico en GDB.
* **Paso 2:** Como `execve()` está bloqueada no podemos usar shellcode estándar.
  Usamos **Ret2Libc** — saltamos a `system()` dentro de la libc con `"/bin/sh"`
  como argumento, igual que en el level01.
* **Paso 3:** Localizamos las direcciones de `system()` y `"/bin/sh"` en la libc
  con GDB.
* **Paso 4:** Construimos el payload:

```
python -c 'print "A"*offset + addr_system + "AAAA" + addr_binsh'
```