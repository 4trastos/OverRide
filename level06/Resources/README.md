# **ANÁLISIS COMPLETO LINEA POR LINEA - NIVEL level06**

```asm
Dump of assembler code for function main:
   0x08048879 <+0>:     push   ebp
   0x0804887a <+1>:	    mov    ebp,esp
   0x0804887c <+3>:	    and    esp,0xfffffff0
   0x0804887f <+6>:	    sub    esp,0x50
   0x08048882 <+9>:	    mov    eax,DWORD PTR [ebp+0xc]
   0x08048885 <+12>:	mov    DWORD PTR [esp+0x1c],eax
   0x08048889 <+16>:	mov    eax,gs:0x14
   0x0804888f <+22>:	mov    DWORD PTR [esp+0x4c],eax
   0x08048893 <+26>:	xor    eax,eax
   0x08048895 <+28>:	push   eax
   0x08048896 <+29>:	xor    eax,eax
   0x08048898 <+31>:	je     0x804889d <main+36>
   0x0804889a <+33>:	add    esp,0x4
   0x0804889d <+36>:	pop    eax
   0x0804889e <+37>:	mov    DWORD PTR [esp],0x8048ad4
   0x080488a5 <+44>:	call   0x8048590 <puts@plt>
   0x080488aa <+49>:	mov    DWORD PTR [esp],0x8048af8
   0x080488b1 <+56>:	call   0x8048590 <puts@plt>
   0x080488b6 <+61>:	mov    DWORD PTR [esp],0x8048ad4
   0x080488bd <+68>:	call   0x8048590 <puts@plt>
   0x080488c2 <+73>:	mov    eax,0x8048b08
   0x080488c7 <+78>:	mov    DWORD PTR [esp],eax
   0x080488ca <+81>:	call   0x8048510 <printf@plt>
   0x080488cf <+86>:	mov    eax,ds:0x804a060
   0x080488d4 <+91>:	mov    DWORD PTR [esp+0x8],eax
   0x080488d8 <+95>:	mov    DWORD PTR [esp+0x4],0x20
   0x080488e0 <+103>:	lea    eax,[esp+0x2c]
   0x080488e4 <+107>:	mov    DWORD PTR [esp],eax
   0x080488e7 <+110>:	call   0x8048550 <fgets@plt>
   0x080488ec <+115>:	mov    DWORD PTR [esp],0x8048ad4
   0x080488f3 <+122>:	call   0x8048590 <puts@plt>
   0x080488f8 <+127>:	mov    DWORD PTR [esp],0x8048b1c
   0x080488ff <+134>:	call   0x8048590 <puts@plt>
   0x08048904 <+139>:	mov    DWORD PTR [esp],0x8048ad4
   0x0804890b <+146>:	call   0x8048590 <puts@plt>
   0x08048910 <+151>:	mov    eax,0x8048b40
   0x08048915 <+156>:	mov    DWORD PTR [esp],eax
   0x08048918 <+159>:	call   0x8048510 <printf@plt>
   0x0804891d <+164>:	mov    eax,0x8048a60
   0x08048922 <+169>:	lea    edx,[esp+0x28]
   0x08048926 <+173>:	mov    DWORD PTR [esp+0x4],edx
   0x0804892a <+177>:	mov    DWORD PTR [esp],eax
   0x0804892d <+180>:	call   0x80485e0 <__isoc99_scanf@plt>
   0x08048932 <+185>:	mov    eax,DWORD PTR [esp+0x28]
   0x08048936 <+189>:	mov    DWORD PTR [esp+0x4],eax
   0x0804893a <+193>:	lea    eax,[esp+0x2c]
   0x0804893e <+197>:	mov    DWORD PTR [esp],eax
   0x08048941 <+200>:	call   0x8048748 <auth>
   0x08048946 <+205>:	test   eax,eax
   0x08048948 <+207>:	jne    0x8048969 <main+240>
   0x0804894a <+209>:	mov    DWORD PTR [esp],0x8048b52
   0x08048951 <+216>:	call   0x8048590 <puts@plt>
   0x08048956 <+221>:	mov    DWORD PTR [esp],0x8048b61
   0x0804895d <+228>:	call   0x80485a0 <system@plt>
   0x08048962 <+233>:	mov    eax,0x0
   0x08048967 <+238>:	jmp    0x804896e <main+245>
   0x08048969 <+240>:	mov    eax,0x1
   0x0804896e <+245>:	mov    edx,DWORD PTR [esp+0x4c]
   0x08048972 <+249>:	xor    edx,DWORD PTR gs:0x14
   0x08048979 <+256>:	je     0x8048980 <main+263>
   0x0804897b <+258>:	call   0x8048580 <__stack_chk_fail@plt>
   0x08048980 <+263>:	leave  
   0x08048981 <+264>:	ret    
End of assembler dump.
```

### **Líneas 0, 1, 3, 6, 9, 12, 16, 22, 26, 28, 29 y 31:**
```asm
0x08048879 <+0>:     push   ebp
0x0804887a <+1>:	    mov    ebp,esp
0x0804887c <+3>:	    and    esp,0xfffffff0
0x0804887f <+6>:	    sub    esp,0x50
0x08048882 <+9>:	    mov    eax,DWORD PTR [ebp+0xc]
0x08048885 <+12>:	mov    DWORD PTR [esp+0x1c],eax
0x08048889 <+16>:	mov    eax,gs:0x14
0x0804888f <+22>:	mov    DWORD PTR [esp+0x4c],eax
0x08048893 <+26>:	xor    eax,eax
0x08048895 <+28>:	push   eax
0x08048896 <+29>:	xor    eax,eax
0x08048898 <+31>:	je     0x804889d <main+36>
```

1. <+0>: Guarda en lo alto del stack el valor de `EBP` (cpu) `[esp + 0x00]`. El `esp` se desplaza 4 bytes hacia abajo.
2. <+1>: Asigna el nuevo `esp` a `ebp` para la función `main`.
3. <+3>: Alinea el stack a múltiplo de 16. (los últimos 4 bytes se ponen a 0).
4. <+6>: Reserva (desplaza) `80 bytes` (0x50) en el stack de `main()` para que el compilador organice las variables locales y los argumentos de las funciones que `main()` va a llamar.
5. <+9>: Carga en `EAX` el segundo argumento de `main()` — `argv` — desde `[ebp+0xc]`.
6. <+12>: Guarda `argv` en `[esp+0x1c]`.
7. <+16>: Carga en `EAX` el valor del **Stack Canary** desde `gs:0x14`.
8. <+22>: Guarda el **Stack Canary** en `[esp+0x4c]` — al final de la función se verificará que sigue intacto.
9. <+26>: Usa `XOR` para poner a 0 el registro `EAX`.
10. <+28>: Guarda `EAX` (0) en el stack — artefacto del compilador.
11. <+29>: Usa `XOR` para poner a 0 `EAX` de nuevo.
12. <+31>: `je` — como `XOR` siempre deja `EAX` a 0 el salto a `<+36>` **siempre** se toma. Las líneas `<+33>` y `<+36>` son código muerto generado por el compilador.

---

### **Líneas 33, 36, 37, 44, 49, 56, 61, 68 y 73:**
```asm
0x0804889a <+33>:	add    esp,0x4
0x0804889d <+36>:	pop    eax
0x0804889e <+37>:	mov    DWORD PTR [esp],0x8048ad4
0x080488a5 <+44>:	call   0x8048590 <puts@plt>
0x080488aa <+49>:	mov    DWORD PTR [esp],0x8048af8
0x080488b1 <+56>:	call   0x8048590 <puts@plt>
0x080488b6 <+61>:	mov    DWORD PTR [esp],0x8048ad4
0x080488bd <+68>:	call   0x8048590 <puts@plt>
0x080488c2 <+73>:	mov    eax,0x8048b08
```

1. <+33>: Código muerto — artefacto del compilador. Nunca se ejecuta.
2. <+36>: Código muerto — artefacto del compilador. Nunca se ejecuta.
3. <+37>: Copia en lo alto del stack el contenido de la dirección `0x8048ad4` como argumento para `puts()`:
```bash
(gdb) x/s 0x8048ad4
0x8048ad4:    '*' <repeats 35 times>
```
4. <+44>: Llama a `puts("***********************************")`.
5. <+49>: Copia en lo alto del stack el contenido de la dirección `0x8048af8` como argumento para `puts()`:
```bash
(gdb) x/s 0x8048af8
0x8048af8:    "*\t\tlevel06\t\t  *"
```
6. <+56>: Llama a `puts("*\t\tlevel06\t\t  *")`.
7. <+61>: Copia en lo alto del stack la dirección `0x8048ad4` de nuevo como argumento para `puts()`.
8. <+68>: Llama a `puts("***********************************")`.
9. <+73>: Carga en `EAX` la dirección `0x8048b08` — será el argumento de `printf()`.

### **Líneas 78, 81, 86, 91, 95, 103, 107 y 110:**
```asm
0x080488c7 <+78>:	mov    DWORD PTR [esp],eax
0x080488ca <+81>:	call   0x8048510 <printf@plt>
0x080488cf <+86>:	mov    eax,ds:0x804a060
0x080488d4 <+91>:	mov    DWORD PTR [esp+0x8],eax
0x080488d8 <+95>:	mov    DWORD PTR [esp+0x4],0x20
0x080488e0 <+103>:	lea    eax,[esp+0x2c]
0x080488e4 <+107>:	mov    DWORD PTR [esp],eax
0x080488e7 <+110>:	call   0x8048550 <fgets@plt>
```

1. <+78>: Copia en lo alto del stack el valor de `EAX` — pasa la dirección de
   `"-> Enter Login: "` como argumento de `printf()`.
2. <+81>: Llama a `printf("-> Enter Login: ")`.
3. <+86>: Carga en `EAX` el puntero al stream `stdin` — será el **tercer
   argumento** de `fgets()`.
4. <+91>: Copia `stdin` en `[esp+0x8]` — el **tercer argumento** de `fgets()`:
   el stream de lectura.
5. <+95>: Escribe `32` (0x20) en `[esp+0x4]` — el **segundo argumento** de
   `fgets()`: número máximo de bytes a leer.
6. <+103>: Calcula la dirección de `[esp+0x2c]` que es la variable local
   `login` y la carga en `EAX`.
7. <+107>: Copia en lo alto del stack la dirección de `login` — el **primer
   argumento** de `fgets()`.
8. <+110>: Llama a `fgets()`:
```c
fgets(login, 32, stdin);
```

### **Líneas 115, 122, 127, 134, 139, 146, 151, 156, 159, 164, 169, 173, 177 y 180:**
```asm
0x080488ec <+115>:	mov    DWORD PTR [esp],0x8048ad4
0x080488f3 <+122>:	call   0x8048590 <puts@plt>
0x080488f8 <+127>:	mov    DWORD PTR [esp],0x8048b1c
0x080488ff <+134>:	call   0x8048590 <puts@plt>
0x08048904 <+139>:	mov    DWORD PTR [esp],0x8048ad4
0x0804890b <+146>:	call   0x8048590 <puts@plt>
0x08048910 <+151>:	mov    eax,0x8048b40
0x08048915 <+156>:	mov    DWORD PTR [esp],eax
0x08048918 <+159>:	call   0x8048510 <printf@plt>
0x0804891d <+164>:	mov    eax,0x8048a60
0x08048922 <+169>:	lea    edx,[esp+0x28]
0x08048926 <+173>:	mov    DWORD PTR [esp+0x4],edx
0x0804892a <+177>:	mov    DWORD PTR [esp],eax
0x0804892d <+180>:	call   0x80485e0 <__isoc99_scanf@plt>
```

1.  <+115>: Copia en lo alto del stack la dirección `0x8048ad4` como argumento para `puts()`.
2.  <+122>: Llama a `puts("***********************************")`.
3.  <+127>: Copia en lo alto del stack el contenido de la dirección `0x8048b1c` como argumento para `puts()`:
```bash
(gdb) x/s 0x8048b1c
0x8048b1c:    "***** NEW ACCOUNT DETECTED ********"
```
4.  <+134>: Llama a `puts("***** NEW ACCOUNT DETECTED ********")`.
5.  <+139>: Copia en lo alto del stack la dirección `0x8048ad4` de nuevo como argumento para `puts()`.
6.  <+146>: Llama a `puts("***********************************")`.
7.  <+151>: Carga en `EAX` la dirección del string `"-> Enter Serial: "` que se encuentra en `0x8048b40`.
8.  <+156>: Copia en lo alto del stack el valor de `EAX` — pasa la dirección de `"-> Enter Serial: "` como argumento de `printf()`.
9.  <+159>: Llama a `printf("-> Enter Serial: ")`.
10. <+164>: Carga en `EAX` la dirección del formato `"%u"` que se encuentra en `0x8048a60` — primer argumento de `scanf()`.
11. <+169>: Calcula la dirección de `[esp+0x28]` que es la variable local `serial` y la carga en `EDX`.
12. <+173>: Copia `serial` en `[esp+0x4]` — el **segundo argumento** de `scanf()`: dónde almacenar el valor leído.
13. <+177>: Copia `"%u"` en lo alto del stack — el **primer argumento** de `scanf()`.
14. <+180>: Llama a `scanf("%u", &serial)` — lee un entero sin signo como serial.

### **Líneas 185, 189, 193, 197, 200, 205 y 207:**
```asm
0x08048932 <+185>:	mov    eax,DWORD PTR [esp+0x28]
0x08048936 <+189>:	mov    DWORD PTR [esp+0x4],eax
0x0804893a <+193>:	lea    eax,[esp+0x2c]
0x0804893e <+197>:	mov    DWORD PTR [esp],eax
0x08048941 <+200>:	call   0x8048748 <auth>
0x08048946 <+205>:	test   eax,eax
0x08048948 <+207>:	jne    0x8048969 <main+240>
```

1. <+185>: Carga en `EAX` el valor de `serial` almacenado en `[esp+0x28]`.
2. <+189>: Copia `serial` en `[esp+0x4]` — el **segundo argumento** de `auth()`.
3. <+193>: Calcula la dirección de `[esp+0x2c]` que es la variable local `login` y la carga en `EAX`.
4. <+197>: Copia la dirección de `login` en lo alto del stack — el **primer argumento** de `auth()`.
5. <+200>: Llama a `auth(login, serial)`.
6. <+205>: Comprueba si el resultado de `auth()` es 0 — si `EAX` es 0 la autenticación fue correcta.
7. <+207>: `jne` — si `auth()` devolvió **distinto de 0** salta a `<+240>` (acceso denegado).

### **Líneas 209, 216, 221, 228, 233, 238, 240, 245, 249, 256, 258, 263 y 264:**
```asm
0x08048948 <+207>:	jne    0x8048969 <main+240>
0x0804894a <+209>:	mov    DWORD PTR [esp],0x8048b52
0x08048951 <+216>:	call   0x8048590 <puts@plt>
0x08048956 <+221>:	mov    DWORD PTR [esp],0x8048b61
0x0804895d <+228>:	call   0x80485a0 <system@plt>
0x08048962 <+233>:	mov    eax,0x0
0x08048967 <+238>:	jmp    0x804896e <main+245>
0x08048969 <+240>:	mov    eax,0x1
0x0804896e <+245>:	mov    edx,DWORD PTR [esp+0x4c]
0x08048972 <+249>:	xor    edx,DWORD PTR gs:0x14
0x08048979 <+256>:	je     0x8048980 <main+263>
0x0804897b <+258>:	call   0x8048580 <__stack_chk_fail@plt>
0x08048980 <+263>:	leave  
0x08048981 <+264>:	ret    
```

1.  <+209>: Carga en lo alto del stack la dirección del string `"Authenticated!"` que se encuentra en `0x8048b52`.
```bash
(gdb) x/s 0x8048b52
0x8048b52:	 "Authenticated!"
```
2.  <+216>: Llama a `puts("Authenticated!")`.
3.  <+221>: Carga en lo alto del stack la dirección del string `"/bin/sh"` que se encuentra en `0x8048b61`.
```bash
(gdb) x/s 0x8048b61
0x8048b61:	 "/bin/sh"
```
4.  <+228>: Llama a `system("/bin/sh")` — lanza una shell.
5.  <+233>: Pone `EAX` a 0 — valor de retorno de `main()`.
6.  <+238>: `jmp` incondicional a `<+245>` — salta al bloque de verificación del canary.
7.  <+240>: Pone `EAX` a 1 — valor de retorno de `main()` en caso de error.
8.  <+245>: Carga en `EDX` el **Stack Canary** guardado en `[esp+0x4c]` al inicio de la función.
9.  <+249>: Aplica `XOR` entre el canary guardado y el canary original de `gs:0x14` — si el stack no fue corrompido el resultado es 0.
10. <+256>: `je` — si el resultado es 0 (canaries coinciden) salta a `<+263>` y termina normalmente.
11. <+258>: Si el canary fue corrompido llama a `__stack_chk_fail@plt` — aborta el programa.
12. <+263>: `leave` — restaura el stack frame: copia `EBP` en `ESP` y hace `pop EBP`.
13. <+264>: `ret` — retorna el control al sistema.


# **ANÁLISIS COMPLETO LINEA POR LINEA - function auth**

```asm
Dump of assembler code for function auth:
0x08048748 <+0>:	push   ebp
0x08048749 <+1>:	mov    ebp,esp
0x0804874b <+3>:	sub    esp,0x28
0x0804874e <+6>:	mov    DWORD PTR [esp+0x4],0x8048a63
0x08048756 <+14>:	mov    eax,DWORD PTR [ebp+0x8]
0x08048759 <+17>:	mov    DWORD PTR [esp],eax
0x0804875c <+20>:	call   0x8048520 <strcspn@plt>
0x08048761 <+25>:	add    eax,DWORD PTR [ebp+0x8]
0x08048764 <+28>:	mov    BYTE PTR [eax],0x0
0x08048767 <+31>:	mov    DWORD PTR [esp+0x4],0x20
0x0804876f <+39>:	mov    eax,DWORD PTR [ebp+0x8]
0x08048772 <+42>:	mov    DWORD PTR [esp],eax
0x08048775 <+45>:	call   0x80485d0 <strnlen@plt>
0x0804877a <+50>:	mov    DWORD PTR [ebp-0xc],eax
0x0804877d <+53>:	push   eax
0x0804877e <+54>:	xor    eax,eax
0x08048780 <+56>:	je     0x8048785 <auth+61>
0x08048782 <+58>:	add    esp,0x4
0x08048785 <+61>:	pop    eax
0x08048786 <+62>:	cmp    DWORD PTR [ebp-0xc],0x5
0x0804878a <+66>:	jg     0x8048796 <auth+78>
0x0804878c <+68>:	mov    eax,0x1
0x08048791 <+73>:	jmp    0x8048877 <auth+303>
0x08048796 <+78>:	mov    DWORD PTR [esp+0xc],0x0
0x0804879e <+86>:	mov    DWORD PTR [esp+0x8],0x1
0x080487a6 <+94>:	mov    DWORD PTR [esp+0x4],0x0
0x080487ae <+102>:	mov    DWORD PTR [esp],0x0
0x080487b5 <+109>:	call   0x80485f0 <ptrace@plt>
0x080487ba <+114>:	cmp    eax,0xffffffff
0x080487bd <+117>:	jne    0x80487ed <auth+165>
0x080487bf <+119>:	mov    DWORD PTR [esp],0x8048a68
0x080487c6 <+126>:	call   0x8048590 <puts@plt>
0x080487cb <+131>:	mov    DWORD PTR [esp],0x8048a8c
0x080487d2 <+138>:	call   0x8048590 <puts@plt>
0x080487d7 <+143>:	mov    DWORD PTR [esp],0x8048ab0
0x080487de <+150>:	call   0x8048590 <puts@plt>
0x080487e3 <+155>:	mov    eax,0x1
0x080487e8 <+160>:	jmp    0x8048877 <auth+303>
0x080487ed <+165>:	mov    eax,DWORD PTR [ebp+0x8]
0x080487f0 <+168>:	add    eax,0x3
0x080487f3 <+171>:	movzx  eax,BYTE PTR [eax]
0x080487f6 <+174>:	movsx  eax,al
0x080487f9 <+177>:	xor    eax,0x1337
0x080487fe <+182>:	add    eax,0x5eeded
0x08048803 <+187>:	mov    DWORD PTR [ebp-0x10],eax
0x08048806 <+190>:	mov    DWORD PTR [ebp-0x14],0x0
0x0804880d <+197>:	jmp    0x804885b <auth+275>
0x0804880f <+199>:	mov    eax,DWORD PTR [ebp-0x14]
0x08048812 <+202>:	add    eax,DWORD PTR [ebp+0x8]
0x08048815 <+205>:	movzx  eax,BYTE PTR [eax]
0x08048818 <+208>:	cmp    al,0x1f
0x0804881a <+210>:	jg     0x8048823 <auth+219>
0x0804881c <+212>:	mov    eax,0x1
0x08048821 <+217>:	jmp    0x8048877 <auth+303>
0x08048823 <+219>:	mov    eax,DWORD PTR [ebp-0x14]
0x08048826 <+222>:	add    eax,DWORD PTR [ebp+0x8]
0x08048829 <+225>:	movzx  eax,BYTE PTR [eax]
0x0804882c <+228>:	movsx  eax,al
0x0804882f <+231>:	mov    ecx,eax
0x08048831 <+233>:	xor    ecx,DWORD PTR [ebp-0x10]
0x08048834 <+236>:	mov    edx,0x88233b2b
0x08048839 <+241>:	mov    eax,ecx
0x0804883b <+243>:	mul    edx
0x0804883d <+245>:	mov    eax,ecx
0x0804883f <+247>:	sub    eax,edx
0x08048841 <+249>:	shr    eax,1
0x08048843 <+251>:	add    eax,edx
0x08048845 <+253>:	shr    eax,0xa
0x08048848 <+256>:	imul   eax,eax,0x539
0x0804884e <+262>:	mov    edx,ecx
0x08048850 <+264>:	sub    edx,eax
0x08048852 <+266>:	mov    eax,edx
0x08048854 <+268>:	add    DWORD PTR [ebp-0x10],eax
0x08048857 <+271>:	add    DWORD PTR [ebp-0x14],0x1
0x0804885b <+275>:	mov    eax,DWORD PTR [ebp-0x14]
0x0804885e <+278>:	cmp    eax,DWORD PTR [ebp-0xc]
0x08048861 <+281>:	jl     0x804880f <auth+199>
0x08048863 <+283>:	mov    eax,DWORD PTR [ebp+0xc]
0x08048866 <+286>:	cmp    eax,DWORD PTR [ebp-0x10]
0x08048869 <+289>:	je     0x8048872 <auth+298>
0x0804886b <+291>:	mov    eax,0x1
0x08048870 <+296>:	jmp    0x8048877 <auth+303>
0x08048872 <+298>:	mov    eax,0x0
0x08048877 <+303>:	leave  
0x08048878 <+304>:	ret 
```

### **Líneas 0, 1, 3, 6, 14, 17, 20, 25, 28, 31, 39, 42, 45 y 50:**
```asm
0x08048748 <+0>:	push   ebp
0x08048749 <+1>:	mov    ebp,esp
0x0804874b <+3>:	sub    esp,0x28
0x0804874e <+6>:	mov    DWORD PTR [esp+0x4],0x8048a63
0x08048756 <+14>:	mov    eax,DWORD PTR [ebp+0x8]
0x08048759 <+17>:	mov    DWORD PTR [esp],eax
0x0804875c <+20>:	call   0x8048520 <strcspn@plt>
0x08048761 <+25>:	add    eax,DWORD PTR [ebp+0x8]
0x08048764 <+28>:	mov    BYTE PTR [eax],0x0
0x08048767 <+31>:	mov    DWORD PTR [esp+0x4],0x20
0x0804876f <+39>:	mov    eax,DWORD PTR [ebp+0x8]
0x08048772 <+42>:	mov    DWORD PTR [esp],eax
0x08048775 <+45>:	call   0x80485d0 <strnlen@plt>
0x0804877a <+50>:	mov    DWORD PTR [ebp-0xc],eax
```

1.  <+0>: Guarda en lo alto del stack el valor de `EBP` (función `main`) `[esp + 0x00]`. El registro `ESP` se desplaza 4 bytes.
2.  <+1>: Asigna a `EBP` el nuevo `ESP` para la función `auth()`.
3.  <+3>: Reserva (desplaza) `40 bytes` (0x28) en el stack de `auth()` para que el compilador organice las variables locales y los argumentos de las funciones que `auth()` va a llamar.
4.  <+6>: Escribe en `[esp+0x4]` la dirección del string `"\n"` — el **segundo argumento** de `strcspn()`: el carácter a buscar.
5.  <+14>: Carga en `EAX` el **primer argumento** de `auth()`: `login`, almacenado en `[ebp+0x8]`.
6.  <+17>: Copia la dirección de `login` en lo alto del stack — el **primer argumento** de `strcspn()`.
7.  <+20>: Llama a `strcspn(login, "\n")` — devuelve en `EAX` el índice del primer `\n` encontrado en `login`.
8.  <+25>: Suma el índice devuelto por `strcspn()` a la dirección base de `login` — obtiene la dirección del `\n`.
9.  <+28>: Escribe `\0` en esa posición — reemplaza el `\n` final del login por un terminador de cadena:
```c
login[strcspn(login, "\n")] = '\0';
```
10. <+31>: Escribe `32` (0x20) en `[esp+0x4]` — el **segundo argumento** de `strnlen()`: longitud máxima a medir.
11. <+39>: Carga en `EAX` la dirección de `login` — el **primer argumento** de `strnlen()`.
12. <+42>: Copia la dirección de `login` en lo alto del stack.
13. <+45>: Llama a `strnlen(login, 32)` — devuelve la longitud de `login` en `EAX`.
14. <+50>: Guarda la longitud de `login` en la variable local `[ebp-0xc]`.

### **Líneas 54, 56, 58, 61, 62, 66, 68, 73, 78, 86, 94, 102, 109 y 114:**
```asm
0x0804877e <+54>:	xor    eax,eax
0x08048780 <+56>:	je     0x8048785 <auth+61>
0x08048782 <+58>:	add    esp,0x4
0x08048785 <+61>:	pop    eax
0x08048786 <+62>:	cmp    DWORD PTR [ebp-0xc],0x5
0x0804878a <+66>:	jg     0x8048796 <auth+78>
0x0804878c <+68>:	mov    eax,0x1
0x08048791 <+73>:	jmp    0x8048877 <auth+303>
0x08048796 <+78>:	mov    DWORD PTR [esp+0xc],0x0
0x0804879e <+86>:	mov    DWORD PTR [esp+0x8],0x1
0x080487a6 <+94>:	mov    DWORD PTR [esp+0x4],0x0
0x080487ae <+102>:	mov    DWORD PTR [esp],0x0
0x080487b5 <+109>:	call   0x80485f0 <ptrace@plt>
0x080487ba <+114>:	cmp    eax,0xffffffff
```

1.  <+54>: Usa `XOR` para poner a 0 `EAX` — artefacto del compilador.
2.  <+56>: `je` — el salto a `<+61>` **siempre** se toma. Código muerto generado por el compilador.
3.  <+58>: Código muerto — artefacto del compilador. Nunca se ejecuta.
4.  <+61>: Código muerto — artefacto del compilador. Nunca se ejecuta.
5.  <+62>: Compara la longitud de `login` en `[ebp-0xc]` con `5`.
6.  <+66>: `jg` — si `len > 5` continúa. Si `len <= 5` salta a `<+68>`.
7.  <+68>: Pone `EAX` a 1 — prepara el valor de retorno de error.
8.  <+73>: `jmp` incondicional a `<+303>` — sale de `auth()` devolviendo 1 (error). El login es demasiado corto.
9.  <+78>: Escribe `0` en `[esp+0xc]` — cuarto argumento de `ptrace()`: `data = 0`.
10. <+86>: Escribe `1` en `[esp+0x8]` — tercer argumento de `ptrace()`: `addr = 1`.
11. <+94>: Escribe `0` en `[esp+0x4]` — segundo argumento de `ptrace()`: `pid = 0`.
12. <+102>: Escribe `0` en `[esp]` — primer argumento de `ptrace()`: `PTRACE_TRACEME`.
13. <+109>: Llama a `ptrace(PTRACE_TRACEME, 0, 1, 0)` — antidebugging: si el proceso ya está siendo trazado por GDB, devuelve `-1`.
14. <+114>: Compara el resultado de `ptrace()` con `0xffffffff` (-1) — si GDB está adjunto la llamada falló.

### **Líneas 117, 119, 126, 131, 138, 143, 150, 155, 160, 165, 168, 171, 174, 177, 182, 187, 190 y 197:**
```asm
0x080487bd <+117>:	jne    0x80487ed <auth+165>
0x080487bf <+119>:	mov    DWORD PTR [esp],0x8048a68
0x080487c6 <+126>:	call   0x8048590 <puts@plt>
0x080487cb <+131>:	mov    DWORD PTR [esp],0x8048a8c
0x080487d2 <+138>:	call   0x8048590 <puts@plt>
0x080487d7 <+143>:	mov    DWORD PTR [esp],0x8048ab0
0x080487de <+150>:	call   0x8048590 <puts@plt>
0x080487e3 <+155>:	mov    eax,0x1
0x080487e8 <+160>:	jmp    0x8048877 <auth+303>
0x080487ed <+165>:	mov    eax,DWORD PTR [ebp+0x8]
0x080487f0 <+168>:	add    eax,0x3
0x080487f3 <+171>:	movzx  eax,BYTE PTR [eax]
0x080487f6 <+174>:	movsx  eax,al
0x080487f9 <+177>:	xor    eax,0x1337
0x080487fe <+182>:	add    eax,0x5eeded
0x08048803 <+187>:	mov    DWORD PTR [ebp-0x10],eax
0x08048806 <+190>:	mov    DWORD PTR [ebp-0x14],0x0
0x0804880d <+197>:	jmp    0x804885b <auth+275>
```

1.  <+117>: `jne` — si `ptrace()` **no** devolvió `-1` (no hay debugger) salta a `<+165>` y continúa normalmente.
2.  <+119>: Carga la dirección del string de la línea decorativa verde:
```bash
(gdb) x/s 0x8048a68
0x8048a68:    "\033[32m.", '-' <repeats 27 times>, "."
```
3.  <+126>: Llama a `puts()` — imprime la línea decorativa superior.
4.  <+131>: Carga la dirección del mensaje de alerta:
```bash
(gdb) x/s 0x8048a8c
0x8048a8c:    "\033[31m| !! TAMPERING DETECTED !!  |"
```
5.  <+138>: Llama a `puts("| !! TAMPERING DETECTED !!  |")`.
6.  <+143>: Carga la dirección del string de la línea decorativa inferior:
```bash
(gdb) x/s 0x8048ab0
0x8048ab0:    "\033[32m'", '-' <repeats 27 times>, "'"
```
7.  <+150>: Llama a `puts()` — imprime la línea decorativa inferior.
8.  <+155>: Pone `EAX` a 1 — prepara el valor de retorno de error.
9.  <+160>: `jmp` incondicional a `<+303>` — sale de `auth()` devolviendo 1 (error).
10. <+165>: Carga en `EAX` la dirección base de `login` desde `[ebp+0x8]`.
11. <+168>: Suma `3` a `EAX` — apunta al cuarto carácter de `login` (`login[3]`).
12. <+171>: Carga el byte en esa posición — `login[3]`.
13. <+174>: Extiende el signo del byte a 32 bits.
14. <+177>: Aplica `XOR 0x1337` a `login[3]`.
15. <+182>: Suma `0x5eeded` al resultado.
16. <+187>: Guarda el resultado en `[ebp-0x10]` — variable local `serial_expected`.
17. <+190>: Inicializa a 0 la variable local `i` en `[ebp-0x14]` — contador del bucle.
18. <+197>: `jmp` incondicional a `<+275>` — salta a la condición del bucle.

### **Líneas 199, 202, 205, 208, 210, 212, 217, 219, 222, 225, 228, 231, 233, 236, 241, 243, 245, 247, 249, 251, 253, 256:**
```asm
0x0804880f <+199>:	mov    eax,DWORD PTR [ebp-0x14]
0x08048812 <+202>:	add    eax,DWORD PTR [ebp+0x8]
0x08048815 <+205>:	movzx  eax,BYTE PTR [eax]
0x08048818 <+208>:	cmp    al,0x1f
0x0804881a <+210>:	jg     0x8048823 <auth+219>
0x0804881c <+212>:	mov    eax,0x1
0x08048821 <+217>:	jmp    0x8048877 <auth+303>
0x08048823 <+219>:	mov    eax,DWORD PTR [ebp-0x14]
0x08048826 <+222>:	add    eax,DWORD PTR [ebp+0x8]
0x08048829 <+225>:	movzx  eax,BYTE PTR [eax]
0x0804882c <+228>:	movsx  eax,al
0x0804882f <+231>:	mov    ecx,eax
0x08048831 <+233>:	xor    ecx,DWORD PTR [ebp-0x10]
0x08048834 <+236>:	mov    edx,0x88233b2b
0x08048839 <+241>:	mov    eax,ecx
0x0804883b <+243>:	mul    edx
0x0804883d <+245>:	mov    eax,ecx
0x0804883f <+247>:	sub    eax,edx
0x08048841 <+249>:	shr    eax,1
0x08048843 <+251>:	add    eax,edx
0x08048845 <+253>:	shr    eax,0xa
0x08048848 <+256>:	imul   eax,eax,0x539
```

1.  <+199>: Carga en `EAX` el contador `i` de `[ebp-0x14]`.
2.  <+202>: Suma `i` a la dirección base de `login` — calcula `login[i]`.
3.  <+205>: Carga el byte `login[i]` en `EAX`.
4.  <+208>: Compara `login[i]` con `0x1f` (31).
5.  <+210>: `jg` — si `login[i] > 0x1f` continúa. Si no salta a `<+212>`.
6.  <+212>: Pone `EAX` a 1 — prepara el valor de retorno de error.
7.  <+217>: `jmp` a `<+303>` — sale de `auth()` devolviendo 1. El carácter no es válido.
8.  <+219>: Carga de nuevo `i` en `EAX`.
9.  <+222>: Suma `i` a la dirección base de `login` — calcula `login[i]` de nuevo.
10. <+225>: Carga el byte `login[i]` en `EAX`.
11. <+228>: Extiende el signo del byte a 32 bits.
12. <+231>: Copia `login[i]` en `ECX`.
13. <+233>: Aplica `XOR` entre `login[i]` y `serial_expected` (`[ebp-0x10]`).
14. <+236>: Carga la constante `0x88233b2b` en `EDX`.
15. <+241>: Copia el resultado del XOR en `EAX`.
16. <+243>: Multiplica `EAX` por `EDX` — operación de mezcla.
17. <+245>: Restaura `EAX` con el valor del XOR.
18. <+247>: Resta `EDX` a `EAX`.
19. <+249>: Desplazamiento lógico derecha 1 bit — divide por 2.
20. <+251>: Suma `EDX` a `EAX`.
21. <+253>: Desplazamiento lógico derecha 10 bits.
22. <+256>: Multiplica `EAX` por `0x539` (1337) — el resultado es la contribución de `login[i]` al serial esperado.

### **Líneas 262, 264, 266, 268, 271, 275, 278, 281, 283, 286, 289, 291, 296, 298, 303 y 304:**
```asm
0x0804884e <+262>:	mov    edx,ecx
0x08048850 <+264>:	sub    edx,eax
0x08048852 <+266>:	mov    eax,edx
0x08048854 <+268>:	add    DWORD PTR [ebp-0x10],eax
0x08048857 <+271>:	add    DWORD PTR [ebp-0x14],0x1
0x0804885b <+275>:	mov    eax,DWORD PTR [ebp-0x14]
0x0804885e <+278>:	cmp    eax,DWORD PTR [ebp-0xc]
0x08048861 <+281>:	jl     0x804880f <auth+199>
0x08048863 <+283>:	mov    eax,DWORD PTR [ebp+0xc]
0x08048866 <+286>:	cmp    eax,DWORD PTR [ebp-0x10]
0x08048869 <+289>:	je     0x8048872 <auth+298>
0x0804886b <+291>:	mov    eax,0x1
0x08048870 <+296>:	jmp    0x8048877 <auth+303>
0x08048872 <+298>:	mov    eax,0x0
0x08048877 <+303>:	leave  
0x08048878 <+304>:	ret 
```

1.  <+262>: Copia `ECX` en `EDX`.
2.  <+264>: Resta `EAX` a `EDX`.
3.  <+266>: Copia `EDX` en `EAX` — resultado final de la operación sobre `login[i]`.
4.  <+268>: Suma el resultado a `serial_expected` en `[ebp-0x10]` — acumula la contribución de cada carácter.
5.  <+271>: Incrementa el contador `i` en 1 — avanza al siguiente carácter.
6.  <+275>: Carga el valor actualizado de `i` en `EAX`.
7.  <+278>: Compara `i` con `len` en `[ebp-0xc]`.
8.  <+281>: `jl` — si `i < len` vuelve a `<+199>` para continuar el bucle.
9.  <+283>: Carga en `EAX` el **segundo argumento** de `auth()`: `serial` introducido por el usuario, desde `[ebp+0xc]`.
10. <+286>: Compara `serial` del usuario con `serial_expected` calculado en `[ebp-0x10]`.
11. <+289>: `je` — si son iguales salta a `<+298>` (autenticación correcta).
12. <+291>: Pone `EAX` a 1 — serial incorrecto.
13. <+296>: `jmp` a `<+303>` — sale de `auth()` devolviendo 1 (error).
14. <+298>: Pone `EAX` a 0 — serial correcto, autenticación exitosa.
15. <+303>: `leave` — restaura el stack frame.
16. <+304>: `ret` — retorna el control a `main()`.

# Resumen del Flujo de Ataque para el Nivel 06

## 1. Lectura:

No hay explotación de memoria, es ingeniería inversa pura.

La vulnerabilidad está en la función `auth()` — la lógica de validación del
serial es completamente reversible a partir del login:

```c
serial_expected = (login[3] ^ 0x1337) + 0x5eeded;
for (i = 0; i < len; i++)
    serial_expected += (login[i] ^ serial_expected) * 0x539;
if (serial == serial_expected)
    return (0);
```

---

## 2. Vulnerabilidad:

* `auth()` usa `ptrace(PTRACE_TRACEME)` como antidebugging — no podemos
  analizarlo directamente con GDB.
* El serial esperado se **calcula a partir del login** — si conocemos el
  algoritmo podemos calcular el serial correcto para cualquier login válido.
* El login debe tener más de 5 caracteres y ninguno puede ser `<= 0x1f`.

---

## 3. Explotación:

* **Paso 1:** Elegimos un login válido de más de 5 caracteres, por ejemplo `usuario`.
* **Paso 2:** Replicamos el algoritmo de `auth()` en Python para calcular el
  serial esperado:

```python
login = "usuario"
serial = (ord(login[3]) ^ 0x1337) + 0x5eeded
for c in login:
    serial += (ord(c) ^ serial) * 0x539
    serial &= 0xffffffff
print serial
```

* **Paso 3:** Introducimos el login y el serial calculado:

```bash
level06@OverRide:~$ ./level06
-> Enter Login: usuario
-> Enter Serial: <serial calculado>
Authenticated!
$
```