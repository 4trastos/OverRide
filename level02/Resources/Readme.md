# **ANÁLISIS COMPLETO LINEA POR LINEA - NIVEL level02**

```asm
Dump of assembler code for function main:
   0x0000000000400814 <+0>:	    push   rbp
   0x0000000000400815 <+1>:	    mov    rbp,rsp
   0x0000000000400818 <+4>:	    sub    rsp,0x120
   0x000000000040081f <+11>:	mov    DWORD PTR [rbp-0x114],edi
   0x0000000000400825 <+17>:	mov    QWORD PTR [rbp-0x120],rsi
   0x000000000040082c <+24>:	lea    rdx,[rbp-0x70]
   0x0000000000400830 <+28>:	mov    eax,0x0
   0x0000000000400835 <+33>:	mov    ecx,0xc
   0x000000000040083a <+38>:	mov    rdi,rdx
   0x000000000040083d <+41>:	rep stos QWORD PTR es:[rdi],rax
   0x0000000000400840 <+44>:	mov    rdx,rdi
   0x0000000000400843 <+47>:	mov    DWORD PTR [rdx],eax
   0x0000000000400845 <+49>:	add    rdx,0x4
   0x0000000000400849 <+53>:	lea    rdx,[rbp-0xa0]
   0x0000000000400850 <+60>:	mov    eax,0x0
   0x0000000000400855 <+65>:	mov    ecx,0x5
   0x000000000040085a <+70>:	mov    rdi,rdx
   0x000000000040085d <+73>:	rep stos QWORD PTR es:[rdi],rax
   0x0000000000400860 <+76>:	mov    rdx,rdi
   0x0000000000400863 <+79>:	mov    BYTE PTR [rdx],al
   0x0000000000400865 <+81>:	add    rdx,0x1
   0x0000000000400869 <+85>:	lea    rdx,[rbp-0x110]
   0x0000000000400870 <+92>:	mov    eax,0x0
   0x0000000000400875 <+97>:	mov    ecx,0xc
   0x000000000040087a <+102>:	mov    rdi,rdx
   0x000000000040087d <+105>:	rep stos QWORD PTR es:[rdi],rax
   0x0000000000400880 <+108>:	mov    rdx,rdi
   0x0000000000400883 <+111>:	mov    DWORD PTR [rdx],eax
   0x0000000000400885 <+113>:	add    rdx,0x4
   0x0000000000400889 <+117>:	mov    QWORD PTR [rbp-0x8],0x0
   0x0000000000400891 <+125>:	mov    DWORD PTR [rbp-0xc],0x0
   0x0000000000400898 <+132>:	mov    edx,0x400bb0
   0x000000000040089d <+137>:	mov    eax,0x400bb2
   0x00000000004008a2 <+142>:	mov    rsi,rdx
   0x00000000004008a5 <+145>:	mov    rdi,rax
   0x00000000004008a8 <+148>:	call   0x400700 <fopen@plt>
   0x00000000004008ad <+153>:	mov    QWORD PTR [rbp-0x8],rax
   0x00000000004008b1 <+157>:	cmp    QWORD PTR [rbp-0x8],0x0
   0x00000000004008b6 <+162>:	jne    0x4008e6 <main+210>
   0x00000000004008b8 <+164>:	mov    rax,QWORD PTR [rip+0x200991]        # 0x601250 <stderr@@GLIBC_2.2.5>
   0x00000000004008bf <+171>:	mov    rdx,rax
   0x00000000004008c2 <+174>:	mov    eax,0x400bd0
   0x00000000004008c7 <+179>:	mov    rcx,rdx
   0x00000000004008ca <+182>:	mov    edx,0x24
   0x00000000004008cf <+187>:	mov    esi,0x1
   0x00000000004008d4 <+192>:	mov    rdi,rax
   0x00000000004008d7 <+195>:	call   0x400720 <fwrite@plt>
   0x00000000004008dc <+200>:	mov    edi,0x1
   0x00000000004008e1 <+205>:	call   0x400710 <exit@plt>
   0x00000000004008e6 <+210>:	lea    rax,[rbp-0xa0]
   0x00000000004008ed <+217>:	mov    rdx,QWORD PTR [rbp-0x8]
   0x00000000004008f1 <+221>:	mov    rcx,rdx
   0x00000000004008f4 <+224>:	mov    edx,0x29
   0x00000000004008f9 <+229>:	mov    esi,0x1
   0x00000000004008fe <+234>:	mov    rdi,rax
   0x0000000000400901 <+237>:	call   0x400690 <fread@plt>
   0x0000000000400906 <+242>:	mov    DWORD PTR [rbp-0xc],eax
   0x0000000000400909 <+245>:	lea    rax,[rbp-0xa0]
   0x0000000000400910 <+252>:	mov    esi,0x400bf5
   0x0000000000400915 <+257>:	mov    rdi,rax
   0x0000000000400918 <+260>:	call   0x4006d0 <strcspn@plt>
   0x000000000040091d <+265>:	mov    BYTE PTR [rbp+rax*1-0xa0],0x0
   0x0000000000400925 <+273>:	cmp    DWORD PTR [rbp-0xc],0x29
   0x0000000000400929 <+277>:	je     0x40097d <main+361>
   0x000000000040092b <+279>:	mov    rax,QWORD PTR [rip+0x20091e]        # 0x601250 <stderr@@GLIBC_2.2.5>
   0x0000000000400932 <+286>:	mov    rdx,rax
   0x0000000000400935 <+289>:	mov    eax,0x400bf8
   0x000000000040093a <+294>:	mov    rcx,rdx
   0x000000000040093d <+297>:	mov    edx,0x24
   0x0000000000400942 <+302>:	mov    esi,0x1
   0x0000000000400947 <+307>:	mov    rdi,rax
   0x000000000040094a <+310>:	call   0x400720 <fwrite@plt>
   0x000000000040094f <+315>:	mov    rax,QWORD PTR [rip+0x2008fa]        # 0x601250 <stderr@@GLIBC_2.2.5>
   0x0000000000400956 <+322>:	mov    rdx,rax
   0x0000000000400959 <+325>:	mov    eax,0x400bf8
   0x000000000040095e <+330>:	mov    rcx,rdx
   0x0000000000400961 <+333>:	mov    edx,0x24
   0x0000000000400966 <+338>:	mov    esi,0x1
   0x000000000040096b <+343>:	mov    rdi,rax
   0x000000000040096e <+346>:	call   0x400720 <fwrite@plt>
   0x0000000000400973 <+351>:	mov    edi,0x1
   0x0000000000400978 <+356>:	call   0x400710 <exit@plt>
   0x000000000040097d <+361>:	mov    rax,QWORD PTR [rbp-0x8]
   0x0000000000400981 <+365>:	mov    rdi,rax
   0x0000000000400984 <+368>:	call   0x4006a0 <fclose@plt>
   0x0000000000400989 <+373>:	mov    edi,0x400c20
   0x000000000040098e <+378>:	call   0x400680 <puts@plt>
   0x0000000000400993 <+383>:	mov    edi,0x400c50
   0x0000000000400998 <+388>:	call   0x400680 <puts@plt>
   0x000000000040099d <+393>:	mov    edi,0x400c80
   0x00000000004009a2 <+398>:	call   0x400680 <puts@plt>
   0x00000000004009a7 <+403>:	mov    edi,0x400cb0
   0x00000000004009ac <+408>:	call   0x400680 <puts@plt>
   0x00000000004009b1 <+413>:	mov    eax,0x400cd9
   0x00000000004009b6 <+418>:	mov    rdi,rax
   0x00000000004009b9 <+421>:	mov    eax,0x0
   0x00000000004009be <+426>:	call   0x4006c0 <printf@plt>
   0x00000000004009c3 <+431>:	mov    rax,QWORD PTR [rip+0x20087e]        # 0x601248 <stdin@@GLIBC_2.2.5>
   0x00000000004009ca <+438>:	mov    rdx,rax
   0x00000000004009cd <+441>:	lea    rax,[rbp-0x70]
   0x00000000004009d1 <+445>:	mov    esi,0x64
   0x00000000004009d6 <+450>:	mov    rdi,rax
   0x00000000004009d9 <+453>:	call   0x4006f0 <fgets@plt>
   0x00000000004009de <+458>:	lea    rax,[rbp-0x70]
   0x00000000004009e2 <+462>:	mov    esi,0x400bf5
   0x00000000004009e7 <+467>:	mov    rdi,rax
   0x00000000004009ea <+470>:	call   0x4006d0 <strcspn@plt>
   0x00000000004009ef <+475>:	mov    BYTE PTR [rbp+rax*1-0x70],0x0
   0x00000000004009f4 <+480>:	mov    eax,0x400ce8
   0x00000000004009f9 <+485>:	mov    rdi,rax
   0x00000000004009fc <+488>:	mov    eax,0x0
   0x0000000000400a01 <+493>:	call   0x4006c0 <printf@plt>
   0x0000000000400a06 <+498>:	mov    rax,QWORD PTR [rip+0x20083b]        # 0x601248 <stdin@@GLIBC_2.2.5>
   0x0000000000400a0d <+505>:	mov    rdx,rax
   0x0000000000400a10 <+508>:	lea    rax,[rbp-0x110]
   0x0000000000400a17 <+515>:	mov    esi,0x64
   0x0000000000400a1c <+520>:	mov    rdi,rax
   0x0000000000400a1f <+523>:	call   0x4006f0 <fgets@plt>
   0x0000000000400a24 <+528>:	lea    rax,[rbp-0x110]
   0x0000000000400a2b <+535>:	mov    esi,0x400bf5
   0x0000000000400a30 <+540>:	mov    rdi,rax
   0x0000000000400a33 <+543>:	call   0x4006d0 <strcspn@plt>
   0x0000000000400a38 <+548>:	mov    BYTE PTR [rbp+rax*1-0x110],0x0
   0x0000000000400a40 <+556>:	mov    edi,0x400cf8
   0x0000000000400a45 <+561>:	call   0x400680 <puts@plt>
   0x0000000000400a4a <+566>:	lea    rcx,[rbp-0x110]
   0x0000000000400a51 <+573>:	lea    rax,[rbp-0xa0]
   0x0000000000400a58 <+580>:	mov    edx,0x29
   0x0000000000400a5d <+585>:	mov    rsi,rcx
   0x0000000000400a60 <+588>:	mov    rdi,rax
   0x0000000000400a63 <+591>:	call   0x400670 <strncmp@plt>
   0x0000000000400a68 <+596>:	test   eax,eax
   0x0000000000400a6a <+598>:	jne    0x400a96 <main+642>
   0x0000000000400a6c <+600>:	mov    eax,0x400d22
   0x0000000000400a71 <+605>:	lea    rdx,[rbp-0x70]
   0x0000000000400a75 <+609>:	mov    rsi,rdx
   0x0000000000400a78 <+612>:	mov    rdi,rax
   0x0000000000400a7b <+615>:	mov    eax,0x0
   0x0000000000400a80 <+620>:	call   0x4006c0 <printf@plt>
   0x0000000000400a85 <+625>:	mov    edi,0x400d32
   0x0000000000400a8a <+630>:	call   0x4006b0 <system@plt>
   0x0000000000400a8f <+635>:	mov    eax,0x0
   0x0000000000400a94 <+640>:	leave  
   0x0000000000400a95 <+641>:	ret    
   0x0000000000400a96 <+642>:	lea    rax,[rbp-0x70]
   0x0000000000400a9a <+646>:	mov    rdi,rax
   0x0000000000400a9d <+649>:	mov    eax,0x0
   0x0000000000400aa2 <+654>:	call   0x4006c0 <printf@plt>
   0x0000000000400aa7 <+659>:	mov    edi,0x400d3a
   0x0000000000400aac <+664>:	call   0x400680 <puts@plt>
   0x0000000000400ab1 <+669>:	mov    edi,0x1
   0x0000000000400ab6 <+674>:	call   0x400710 <exit@plt>
End of assembler dump.
```

### **Líneas 0, 1, 4, 11, 17, 24, 28, 33, 38 y 41:**
```asm
0x0000000000400814 <+0>:	push   rbp
0x0000000000400815 <+1>:	mov    rbp,rsp
0x0000000000400818 <+4>:	sub    rsp,0x120
0x000000000040081f <+11>:	mov    DWORD PTR [rbp-0x114],edi
0x0000000000400825 <+17>:	mov    QWORD PTR [rbp-0x120],rsi
0x000000000040082c <+24>:	lea    rdx,[rbp-0x70]
0x0000000000400830 <+28>:	mov    eax,0x0
0x0000000000400835 <+33>:	mov    ecx,0xc
0x000000000040083a <+38>:	mov    rdi,rdx
0x000000000040083d <+41>:	rep stos QWORD PTR es:[rdi],rax
```

1. <+0>: Guarda en en lo alto del stack el valor de RBP (cpu) `[rsp + 0x00]`. El RSP se desplaza 8 bytes hacia abajo.
2. <+1>: Asigna el nuevo RSP a RBP para la función `main`
3. <+4>: Reserva (desplaza) `288 bytes` (0x120) en el stack de `main()` para que el compilador organice las variables locales y los argumentos de las funciones que `main()` va a llamar.
4. <+11>: Guarda la dirección `[rbp-0x114]` el argumento `argc` de la función `main` en EDI.
4. <+17>:  Guarda la dirección `[rbp-0x120]` el argumento `argv` de la función `main` en RSI.
5. <+24>: Calcula la dirección de `[rbp-0x70]` que es la varibale local de `buffer_username` y la carga en RDX.
6. <+28>: Carga el valor 0 en EAX.
7. <+33>: Añade el valor 12 (0xc) en ECX que es el contador.
8. <+38>: RDI toma la dirección que  se calculó en la línea <+24> `(rbp-0x70)`. (destino de `memset()`)
9. <+41>: **Es la versión de 64 bits del `memset`.** 
```c
memset(buffer_username, 0, 96);
```
- `rep` Repite la instrcucción siguiente (`stos QWORD`) tantas veces como indique ECX (12).
- `stos QWORD`: "Store String". Copia el valor del registro `RAX` (0) en la dirección apuntada por RDI.
- **Tamaño**: Al ser `QWORD` escribe 8 bytes en cada repetición.
- **Resultado**: Está llenando de ceros un bloque de memoria de `96 bytes` (12 × 8 = 96). Este bloque empieza en `[rbp-0x70]`

### **Líneas 44, 47, 49, 53, 60, 65, 70 y 73:**
```asm
0x0000000000400840 <+44>:	mov    rdx,rdi
0x0000000000400843 <+47>:	mov    DWORD PTR [rdx],eax
0x0000000000400845 <+49>:	add    rdx,0x4
0x0000000000400849 <+53>:	lea    rdx,[rbp-0xa0]
0x0000000000400850 <+60>:	mov    eax,0x0
0x0000000000400855 <+65>:	mov    ecx,0x5
0x000000000040085a <+70>:	mov    rdi,rdx
0x000000000040085d <+73>:	rep stos QWORD PTR es:[rdi],rax
```

1. <+44>: Copia en RDX la dirección final donde se quedó el puntero RDI tras el `rep stos` anterior.
2. <+47>: Escribe el valor de EAX (que es 0) en los siguientes 4 bytes (DWORD) de la memoria apuntada por RDX.
3. <+49>: Suma 4 bytes al registro RDX para alinear el registro de memoria (96 + 4 bytes = 100 bytes)
4. <+53>: Calcula la dirección de `[rbp-0xa0]` que es la varibale local de `buffer_file` y la carga en RDX.
5. <+60>: Asegura que EAX (RAX) sean 0.
6. <+65>: Carga en número 5 en el contador ECX
7. <+70>: Copia la dirección del nuevo buffer `buffer_file` en RDI.
8. <+73>: **Es la versión de 64 bits del `memset`.** 
```c
memset(buffer_file, 0, 40);
```
- `rep`: Repite la instrucción siguiente: (`stos QWORD`) tantas veces como indique ECX (5).
- `stos QWORD`: "Store String". Copia el valor del registro `RAX` (0) en la dirección apuntada por RDI.
- **Tamaño**: Al ser `QWORD` escirbe 8 bytes en cada repetición.
- **Resultado**: Está llenado de ceros un bloque de memoria de `40 bytes` (5 x 8 = 40). Este bloque empieza en `[rbp-0xa0]`

### **Líneas 76, 79, 81, 85, 92, 97, 102 y 105:**
```asm
0x0000000000400860 <+76>:	mov    rdx,rdi
0x0000000000400863 <+79>:	mov    BYTE PTR [rdx],al
0x0000000000400865 <+81>:	add    rdx,0x1
0x0000000000400869 <+85>:	lea    rdx,[rbp-0x110]
0x0000000000400870 <+92>:	mov    eax,0x0
0x0000000000400875 <+97>:	mov    ecx,0xc
0x000000000040087a <+102>:	mov    rdi,rdx
0x000000000040087d <+105>:	rep stos QWORD PTR es:[rdi],rax
```

1. <+76>: Copia en RDX la dirección final donde se quedó el puntero RDI tras en `rep stos` anterior.
2. <+79>: Como `RAX` vale 0, `al` también vale 0. Así que `mov BYTE PTR [rdx],al` escribe un solo byte 0 en la dirección apuntada por RDX. `al` es el 1 byte (8 bits) del registro `RAX`.
3. <+81>: sumamos un byte al registro RDX para alinear el registro de la memoria. (avanza el puntero).
4. <+85>: Calcula la dirección `[rbp-0x110]` que es la variable local `buffer_password` (el buffer donde se leerá el contenido del archivo `.pass`) y la carga en RDX.
5. <+92>: Asegura que EAX (RAX) sean 0.
6. <+97>: Carga el número 12 (0xc) en el contador ECX.
7. <+102>: Copia la dirección del nuevo buffer `buffer_password` en RDI.
8. <+105>: **Es la versión de 64 bits del `memset`.**
```c
memset(buffer_password, 0, 96);
```
- `rep`: Repite la instrucción siguiente (`stos QWORD`) tantas veces como indique ECX (12).
- `stos QWORD`: "Store String". Copia el valor del registro `RAX` (0) en la dirección apuntada por RDI.
- **Tamaño**: Al ser `QWORD` escribe 8 bytes en cada repetición.
- **Resultado**: Está llenando de ceros un bloque de memoria de `96 bytes` (12 × 8 = 96). Este bloque empieza en `[rbp-0x110]`.

### **Líneas 108, 111, 113, 117, 125, 132, 137, 142, 145, 148, 153, 157 y 162:**
```asm
0x0000000000400880 <+108>:	mov    rdx,rdi
0x0000000000400883 <+111>:	mov    DWORD PTR [rdx],eax
0x0000000000400885 <+113>:	add    rdx,0x4
0x0000000000400889 <+117>:	mov    QWORD PTR [rbp-0x8],0x0
0x0000000000400891 <+125>:	mov    DWORD PTR [rbp-0xc],0x0
0x0000000000400898 <+132>:	mov    edx,0x400bb0
0x000000000040089d <+137>:	mov    eax,0x400bb2
0x00000000004008a2 <+142>:	mov    rsi,rdx
0x00000000004008a5 <+145>:	mov    rdi,rax
0x00000000004008a8 <+148>:	call   0x400700 <fopen@plt>
0x00000000004008ad <+153>:	mov    QWORD PTR [rbp-0x8],rax
0x00000000004008b1 <+157>:	cmp    QWORD PTR [rbp-0x8],0x0
0x00000000004008b6 <+162>:	jne    0x4008e6 <main+210>
0x00000000004008b8 <+164>:	mov    rax,QWORD PTR [rip+0x200991]        # 0x601250 <stderr@@GLIBC_2.2.5>
```

1. <+108>: Copia en `RDX` la dirección final donde se quedó el puntero `RDI` tras el último `rep stos`
2. <+11>: Escribe el valor de EAX (que es 0) en los siguientes 4 bytes (DWORD) de la memoria apuntada por RDX.
3. <+113>: Avanzamos el puntero 4 bytes. (para alinear la memoria).
4. <+117>:  Inicializa con 0 la variable `FILE *fp` que se encuentra en [rbp-0x8] — el puntero que recibirá el resultado de `fopen()`.
5. <+125>: Inicializa con un  0 la varible `int bytes_read` que se encuentra en: `[rbp-0xc]`
6. <+132>: Copia en el registro `EDX` la variable `r` que se encuentra en la dirección: `0x400bb0`
y que almacena lo leido.
```bash
(gdb) x/s 0x400bb0
0x400bb0:	 "r"
```
7. <+137>: Copia en `EAX` la dirección de memoria de la ruta donde se encuentra el password: `.pass`
```bash
(gdb) x/s 0x400bb2
0x400bb2:	 "/home/users/level03/.pass"
```
8. <+142>: Carga en `RSI` el valor de `RDX` el segundo argumento de `fopen()` -> `"r"` lectura.
9. <+145>: CArga en `RDI` el valor de `RAX` el primer argumeto de `fopen()`-> `la ruta /home/users/level03/.pass.`
10. <+148>: Llama a `fopen()`.
11. <+153>: Guarda en `[rbp-0x8]` (FILE *fp) el puntero devuelto por `fopen()`.
12. <+157>: Compara con un 0 si hay algo en el `fd`.
13. <+162>: `jne` Si no es 0 (si no está vacio) salta a la línea `<+210>`
14. <+164>: Si `fp` es `NULL` (fopen falló), carga en `RAX` la dirección de `stderr` para usarla como destino del mensaje de error con `fwrite()`.

## Salida del programa si fp es NULL:

### **Líneas 171, 174, 179, 182, 187, 192, 195, 200 y 205:**
```asm
0x00000000004008bf <+171>:	mov    rdx,rax
0x00000000004008c2 <+174>:	mov    eax,0x400bd0
0x00000000004008c7 <+179>:	mov    rcx,rdx
0x00000000004008ca <+182>:	mov    edx,0x24
0x00000000004008cf <+187>:	mov    esi,0x1
0x00000000004008d4 <+192>:	mov    rdi,rax
0x00000000004008d7 <+195>:	call   0x400720 <fwrite@plt>
0x00000000004008dc <+200>:	mov    edi,0x1
0x00000000004008e1 <+205>:	call   0x400710 <exit@plt>
```

1. <+171>: Carga en `rdx` la dirección de `stderr` almacena en `RAX`
2. <+174>: Carga en `eax` el mensaje de error que se encuentra en la dirección: `0x400bd0`. Como primer argumento del `fwrite()`
```bash
(gdb) x/s 0x400bd0
0x400bd0:	 "ERROR: failed to open password file\n"
```
3. <+179>: Copia la dirección de `stderr` en el regitro `RCX`
4. <+182>: Escribe 36 bytes `(0x24)` en el registro `EDX`, el número de elementos como tercer argumento de `fwrite@plt`
5. <+187>: Escibe 1 byte en el registro `ESI` (tamaño de cada elemento) como segundo argumento del `fwrite()`
6. <+192>: Mueve a `RDI` la dirección del mensaje de error (primer argumento de fwrite()).
7. <+195>: Llama a  `fwrite@plt`
8. <+200>: Carga el valor 1 en `EDI` — el código de salida que recibirá `exit()`.
```bash
exit(1);
```
9. <+205>: Llama a `exit@plt` y termina el programa.

### **Líneas 210, 217, 221, 224, 229, 234 y 237:**
```asm
0x00000000004008e6 <+210>:	lea    rax,[rbp-0xa0]
0x00000000004008ed <+217>:	mov    rdx,QWORD PTR [rbp-0x8]
0x00000000004008f1 <+221>:	mov    rcx,rdx
0x00000000004008f4 <+224>:	mov    edx,0x29
0x00000000004008f9 <+229>:	mov    esi,0x1
0x00000000004008fe <+234>:	mov    rdi,rax
0x0000000000400901 <+237>:	call   0x400690 <fread@plt>
```

1. <+210>: Calcula la dirección de [rbp-0xa0] que es la variable local `buffer_file` y la carga en `RAX`.
2. <+217>: Guarda en `RDX` el puntero FILE *fp de `[rbp-0x8]` devuelto por fopen() — será el cuarto argumento de `fread()`: el stream desde donde leer.
3. <+221>: El registro `RDX` lo copia en `RCX`
4. <+224>: Escibre 41 bytes `0x29` en `EDX`, el número de elementos como tercer argumento de `fread@plt`
5. <+229>: Escibe 1 byte en el registro `ESI` (tamaño de cada elemento) como segundo argumento del `fread()`
6. <+234>: Mueve a `RDI` la dirección del `buffer_password`(primer argumento de fread()).
7. <+237>: Llama a `<fread@plt>`

### **Líneas 242, 245, 252, 257, 260, 265, 273, 277 y 279:**
```asm
0x0000000000400906 <+242>:	mov    DWORD PTR [rbp-0xc],eax
0x0000000000400909 <+245>:	lea    rax,[rbp-0xa0]
0x0000000000400910 <+252>:	mov    esi,0x400bf5
0x0000000000400915 <+257>:	mov    rdi,rax
0x0000000000400918 <+260>:	call   0x4006d0 <strcspn@plt>
0x000000000040091d <+265>:	mov    BYTE PTR [rbp+rax*1-0xa0],0x0
0x0000000000400925 <+273>:	cmp    DWORD PTR [rbp-0xc],0x29
0x0000000000400929 <+277>:	je     0x40097d <main+361>
0x000000000040092b <+279>:	mov    rax,QWORD PTR [rip+0x20091e]        # 0x601250 <stderr@@GLIBC_2.2.5>
```

1. <+242>: Copia el resultato en la direcciñón de `bytes_read` (actualiza la variable)
2. <+245>: Calcula la dirección de `[rbp-0xa0]` que es la variable `buffer_file` y la carga en `RAX`.
3. <+252>: Carga un salto de línea en el registro `ESI` como segundo argumento de `strcspn()`:
```bash
(gdb) x/s 0x400bf5
0x400bf5:	 "\n"
```
4. <+257>: Copia la dirección de `buffer_file` en `RDI` para pasarlo como primer argumento a `strcspn()`, que buscará la posición del "\n" dentro del buffer.
5. <+260>: Llama a `strcspn()`. Devuelve en `RAX` el índice del primer \n encontrado en `buffer_file`.:
```bash
strcspn(buffer_file, "\n");
```
6. <+265>: Escribe \0 en la posición buffer_file[rax] — reemplaza el \n final del password por un terminador de cadena. Equivale a:
```bash
buffer_file[strcspn(buffer_file, "\n")] = '\0';
```
7. <+273>: Compara `bytes_read` con 41 `(0x29)` — verifica que `fread()` leyó exactamente los bytes esperados del archivo `.pass`.
8. <+277>: Si `bytes_read == 41` salta a `<main+361>` (continúa el programa normalmente).
9. <+270>: si no coincide lanza el mensaje de error y sale.

### **Líneas 286, 289, 294, 297, 302, 307, 310 y 315:**
```asm
0x0000000000400932 <+286>:	mov    rdx,rax
0x0000000000400935 <+289>:	mov    eax,0x400bf8
0x000000000040093a <+294>:	mov    rcx,rdx
0x000000000040093d <+297>:	mov    edx,0x24
0x0000000000400942 <+302>:	mov    esi,0x1
0x0000000000400947 <+307>:	mov    rdi,rax
0x000000000040094a <+310>:	call   0x400720 <fwrite@plt>
0x000000000040094f <+315>:	mov    rax,QWORD PTR [rip+0x2008fa]        # 0x601250 <stderr@@GLIBC_2.2.5>
```

1. <+286>: Carga en `RDX` la dirección de `stderr` almacenada en `RAX`.
2. <+289>: Carga en `EAX` la dirección del mensaje de error que se encuentra en `0x400bf8`:
```bash
(gdb) x/s 0x400bf8
0x400bf8:	 "ERROR: failed to read password file\n"
```
3. <+294>: Copia la dirección de `stderr` en `RCX` — el **cuarto argumento** de `fwrite()`: el stream de destino.
4. <+297>: Escribe `0x24` (36) en `EDX` — el **tercer argumento** de `fwrite()`: número de elementos a escribir.
5. <+302>: Escribe 1 en `ESI` — el **segundo argumento** de `fwrite()`: tamaño de cada elemento en bytes.
6. <+307>: Mueve a `RDI` la dirección del mensaje de error — el **primer argumento** de `fwrite()`: el buffer a escribir.
7. <+310>: Llama a `fwrite@plt`.
8. <+315>: Carga en `RAX` la dirección de `stderr` para el segundo `fwrite()` que viene a continuación.

### **Líneas 322, 325, 330, 333, 343, 346, 351 y 356:**
```asm
0x0000000000400956 <+322>:	mov    rdx,rax
0x0000000000400959 <+325>:	mov    eax,0x400bf8
0x000000000040095e <+330>:	mov    rcx,rdx
0x0000000000400961 <+333>:	mov    edx,0x24
0x0000000000400966 <+338>:	mov    esi,0x1
0x000000000040096b <+343>:	mov    rdi,rax
0x000000000040096e <+346>:	call   0x400720 <fwrite@plt>
0x0000000000400973 <+351>:	mov    edi,0x1
0x0000000000400978 <+356>:	call   0x400710 <exit@plt>
```

1. <+322>: Carga en `RDX` la dirección de `stderr` almacenada en `RAX`.
2. <+325>: Carga en `EAX` la dirección del mensaje de error que se encuentra en `0x400bf8`:
```bash
(gdb) x/s 0x400bf8
0x400bf8:	 "ERROR: failed to read password file\n"
```
3. <+330>: Copia la dirección de `stderr` en `RCX` — el **cuarto argumento** de `fwrite()`: el stream de destino.
4. <+333>: Escribe `0x24` (36) en `EDX` — el **tercer argumento** de `fwrite()`: número de elementos a escribir.
5. <+338>: Escribe 1 en `ESI` — el **segundo argumento** de `fwrite()`: tamaño de cada elemento en bytes.
6. <+343>: Mueve a `RDI` la dirección del mensaje de error — el **primer argumento** de `fwrite()`: el buffer a escribir.
7. <+346>: Llama a `fwrite@plt` — segunda llamada con el mismo mensaje de error.
8. <+351>: Carga el valor `1` en `EDI` — el código de salida que recibirá `exit()`.
9. <+356>: Llama a `exit@plt` y termina el programa.

### **Líneas 361, 365, 368, 373, 378, 383, 388, 393, 398, 403, 408, 413, 418, 421 y 426:**
```asm
0x000000000040097d <+361>:	mov    rax,QWORD PTR [rbp-0x8]
0x0000000000400981 <+365>:	mov    rdi,rax
0x0000000000400984 <+368>:	call   0x4006a0 <fclose@plt>
0x0000000000400989 <+373>:	mov    edi,0x400c20
0x000000000040098e <+378>:	call   0x400680 <puts@plt>
0x0000000000400993 <+383>:	mov    edi,0x400c50
0x0000000000400998 <+388>:	call   0x400680 <puts@plt>
0x000000000040099d <+393>:	mov    edi,0x400c80
0x00000000004009a2 <+398>:	call   0x400680 <puts@plt>
0x00000000004009a7 <+403>:	mov    edi,0x400cb0
0x00000000004009ac <+408>:	call   0x400680 <puts@plt>
0x00000000004009b1 <+413>:	mov    eax,0x400cd9
0x00000000004009b6 <+418>:	mov    rdi,rax
0x00000000004009b9 <+421>:	mov    eax,0x0
0x00000000004009be <+426>:	call   0x4006c0 <printf@plt>
```

1. <+361>: Carga en `RAX` el puntero de `fp` del `fopen()`
2. <+365>: Lo guarda en `RDI`
3. <+368>: Llama a `fclose()` y cierra el file descriptor `(fp)`
4. <+373>: Copia en `EDI` el string "===== [ Secure Access System v1.0 ] =====" como argumento para la función `puts()`:
```bash
(gdb) x/s 0x400c20
0x400c20:	 "===== [ Secure Access System v1.0 ] ====="
```
5. <+378>: Llama a `puts()`:
```bash
puts("===== [ Secure Access System v1.0 ] =====");
```
6. <+383>: Copia en `EDI` el contendo de la direccion `0x400c50` como argumento para la función `puts()`:
```bash
(gdb) x/s 0x400c50
0x400c50:	 "/", '*' <repeats 39 times>, "\\"
```
7. <+388>: Llama a `puts()`
8. <+393>: Copia en `EDI` el contendo de la direccion `0x400c80` como argumento para la función `puts()`:
```bash
(gdb) x/s 0x400c80
0x400c80:	 "| You must login to access this system. |"
```
9. <+398>: Llama a `puts()`.
10. <+403>: Copia en `EDI` el contendo de la direccion `0x400cb0` como argumento para la función `puts()`:
```bash
(gdb) x/s 0x400cb0
0x400cb0:	 "\\", '*' <repeats 38 times>, "/"
```
11. <+408>: Llama a `puts()`.
12. <+413>: Carga en `EAX` el contenido de la dirección `0x400cd9`:
```bash
(gdb) x/s 0x400cd9
0x400cd9:	 "--[ Username: "
```
13. <+418>: Copia en `RDI` el registro `RAX`
14. <+421>: Pone `EAX` a 0 — convención x86-64 que indica a `printf()` que no se usan registros vectoriales (SSE/AVX).
15. <+426>: llama a `printf()`:
```bash
printf("--[ Username: ");
```

### **Líneas 431, 438, 441, 445, 450, 453 y 458:**
```asm
0x00000000004009c3 <+431>:	mov    rax,QWORD PTR [rip+0x20087e]        # 0x601248 <stdin@@GLIBC_2.2.5>
0x00000000004009ca <+438>:	mov    rdx,rax
0x00000000004009cd <+441>:	lea    rax,[rbp-0x70]
0x00000000004009d1 <+445>:	mov    esi,0x64
0x00000000004009d6 <+450>:	mov    rdi,rax
0x00000000004009d9 <+453>:	call   0x4006f0 <fgets@plt>
0x00000000004009de <+458>:	lea    rax,[rbp-0x70]
```

1. <+431>: Carga en `RAX` el puntero al stream `stdin` — será el tercer argumento de `fgets()`.
2. <+438>: Copia `RAX` en `RDX` para no perder el registro.
3. <+441>: Calcula la dirección de `[rbp-0x70]` que es la variable `buffer_username` y la carga en `RAX`.
4. <+445>: Pone 100 `(0x64)` en `ESI` — el segundo argumento de `fgets()`: número máximo de bytes a leer.
5. <+450>: Copia `RAX` en `RDI` para pasarlo como argumento de `fgest()`
6. <+453>: Llama a `fgets()`
```bash
fgets(buffer_username, 100, stdin);
```
7. <+458>: Calcula la dirección de `[rbp-0x70]` que es la variable `buffer_username` y la carga en `RAX`.

### **Líneas: 462, 467, 470, 475, 480, 485, 488 y 493**
```asm
0x00000000004009e2 <+462>:	mov    esi,0x400bf5
0x00000000004009e7 <+467>:	mov    rdi,rax
0x00000000004009ea <+470>:	call   0x4006d0 <strcspn@plt>
0x00000000004009ef <+475>:	mov    BYTE PTR [rbp+rax*1-0x70],0x0
0x00000000004009f4 <+480>:	mov    eax,0x400ce8
0x00000000004009f9 <+485>:	mov    rdi,rax
0x00000000004009fc <+488>:	mov    eax,0x0
0x0000000000400a01 <+493>:	call   0x4006c0 <printf@plt>
```

1. <+462>:  Carga un salto de línea en el registro `ESI` como segundo argumento de `strcspn()`:
```bash
(gdb) x/s 0x400bf5
0x400bf5:	 "\n"
```
2. <+467>: Copia la dirección de `buffer_username` en `RDI` para pasarlo como primer argumento a `strcspn()`, que buscará la posición del "\n" dentro del buffer.
3. <+470>: Llama a `strcspn()`. Devuelve en `RAX` el índice del primer \n encontrado en `buffer_username`.:
```bash
strcspn(buffer_username, "\n");
```
4. <+475>: Escribe \0 en la posición `buffer_username[rax]` — reemplaza el \n final del `username` por un terminador de cadena. Equivale a:
```bash
buffer_username[strcspn(buffer_username, "\n")] = '\0';
```
5. <+480>: Copia en `EAX` el valor de la dirección `0x400ce8`
```bash
(gdb) x/s 0x400ce8
0x400ce8:	 "--[ Password: "
```
6. <+485>: Copia en `RDI` el valor de `RAX` — primer argumento de printf(): la cadena "--[ Password: ".
7. <+488>: Pone `EAX` a 0 — convención x86-64 que indica a `printf()` que no se usan registros vectoriales (SSE/AVX).
8. <+493>: llama a `printf()`:
```bash
printf("--[ Password: ");
```

### **Líeas 498 a 561:**
```asm
0x0000000000400a06 <+498>:	mov    rax,QWORD PTR [rip+0x20083b]        # 0x601248 <stdin@@GLIBC_2.2.5>
0x0000000000400a0d <+505>:	mov    rdx,rax
0x0000000000400a10 <+508>:	lea    rax,[rbp-0x110]
0x0000000000400a17 <+515>:	mov    esi,0x64
0x0000000000400a1c <+520>:	mov    rdi,rax
0x0000000000400a1f <+523>:	call   0x4006f0 <fgets@plt>
0x0000000000400a24 <+528>:	lea    rax,[rbp-0x110]
0x0000000000400a2b <+535>:	mov    esi,0x400bf5
0x0000000000400a30 <+540>:	mov    rdi,rax
0x0000000000400a33 <+543>:	call   0x4006d0 <strcspn@plt>
0x0000000000400a38 <+548>:	mov    BYTE PTR [rbp+rax*1-0x110],0x0
0x0000000000400a40 <+556>:	mov    edi,0x400cf8
0x0000000000400a45 <+561>:	call   0x400680 <puts@plt>
```

1. <+498>: Carga en `RAX` el puntero al stream `stdin` — será el **tercer argumento** de `fgets()`.
2. <+505>: Copia `RAX` en `RDX` para no perder el registro.
3. <+508>: Calcula la dirección de `[rbp-0x110]` que es la variable `buffer_password` y la carga en `RAX`.
4. <+515>: Pone `100` (0x64) en `ESI` — el **segundo argumento** de `fgets()`: número máximo de bytes a leer.
5. <+520>: Copia `RAX` en `RDI` para pasarlo como primer argumento de `fgets()`.
6. <+523>: Llama a `fgets()`:
```bash
fgets(buffer_password, 100, stdin);
```
7. <+528>: Calcula la dirección de `[rbp-0x110]` que es la variable `buffer_password` y la carga en `RAX`.
8. <+535>: Carga un salto de línea en el registro `ESI` como segundo argumento de `strcspn()`:
```bash
(gdb) x/s 0x400bf5
0x400bf5:    "\n"
```
9. <+540>: Copia la dirección de `buffer_password` en `RDI` para pasarlo como primer argumento a `strcspn()`, que buscará la posición del `\n` dentro del buffer.
10. <+543>: Llama a `strcspn()`. Devuelve en `RAX` el índice del primer `\n` encontrado en `buffer_password`:
```bash
strcspn(buffer_password, "\n");
```
11. <+548>: Escribe `\0` en la posición `buffer_password[rax]` — reemplaza el `\n` final del password por un terminador de cadena. Equivale a:
```bash
buffer_password[strcspn(buffer_password, "\n")] = '\0';
```
12. <+556>: Copia en `EDI` el contenido de la dirección `0x400cf8` como argumento para `puts()`:
```bash
(gdb) x/s 0x400cf8
0x400cf8:    '*' <repeats 41 times>
```
13. <+561>: Llama a `puts()`:
```bash
puts("*****************************************");
```

### **Líneas 566, 573, 580, 585, 588, 591, 596 y 596:**
```asm
0x0000000000400a4a <+566>:	lea    rcx,[rbp-0x110]
0x0000000000400a51 <+573>:	lea    rax,[rbp-0xa0]
0x0000000000400a58 <+580>:	mov    edx,0x29
0x0000000000400a5d <+585>:	mov    rsi,rcx
0x0000000000400a60 <+588>:	mov    rdi,rax
0x0000000000400a63 <+591>:	call   0x400670 <strncmp@plt>
0x0000000000400a68 <+596>:	test   eax,eax
0x0000000000400a6a <+598>:	jne    0x400a96 <main+642>
```

1. <+566>: Calcula la dirección de `[rbp-0x110]` que es la variable `buffer_password` y la carga en `RCX`.
2. <+573>: Calcula la dirección de `[rbp-0xa0]` que es la variable `buffer_file` y la carga en `RAX`.
3. <+580>: Escribe `41` (0x29) en `EDX` — el **tercer argumento** de `strncmp()`: número de bytes a comparar.
4. <+585>: Copia `RCX` en `RSI` — el **segundo argumento** de `strncmp()`: `buffer_password` (lo que introdujo el usuario).
5. <+588>: Copia `RAX` en `RDI` — el **primer argumento** de `strncmp()`: `buffer_file` (el password real leído del `.pass`).
6. <+591>: Llama a `strncmp()` — compara los primeros 41 bytes de `buffer_file` con `buffer_password`:
```bash
strncmp(buffer_file, buffer_password, 41);
```
7. <+596>: Comprueba si el resultado de `strncmp()` es 0 — si ambos strings son iguales `EAX` será 0.
8. <+598>: `jne` — si **no son iguales** (EAX != 0) salta a `<main+642>` (bloque de acceso denegado).

### **Líneas 600 a 641:**
```asm
0x0000000000400a6c <+600>:	mov    eax,0x400d22
0x0000000000400a71 <+605>:	lea    rdx,[rbp-0x70]
0x0000000000400a75 <+609>:	mov    rsi,rdx
0x0000000000400a78 <+612>:	mov    rdi,rax
0x0000000000400a7b <+615>:	mov    eax,0x0
0x0000000000400a80 <+620>:	call   0x4006c0 <printf@plt>
0x0000000000400a85 <+625>:	mov    edi,0x400d32
0x0000000000400a8a <+630>:	call   0x4006b0 <system@plt>
0x0000000000400a8f <+635>:	mov    eax,0x0
0x0000000000400a94 <+640>:	leave  
0x0000000000400a95 <+641>:	ret
```

1. <+600>: Carga en `EAX` la dirección del string `"Greetings, %s!\n"` que se encuentra en `0x400d22`.
2. <+605>: Calcula la dirección de `[rbp-0x70]` que es la variable `buffer_username` y la carga en `RDX`.
3. <+609>: Copia `RDX` en `RSI` — el **segundo argumento** de `printf()`: el valor que sustituirá al `%s`.
4. <+612>: Copia `RAX` en `RDI` — el **primer argumento** de `printf()`: el formato `"Greetings, %s!\n"`.
5. <+615>: Pone `EAX` a 0 — convención x86-64 que indica a `printf()` que no se usan registros vectoriales (SSE/AVX).
6. <+620>: Llama a `printf()`:
```bash
printf("Greetings, %s!\n", buffer_username);
```
7. <+625>: Carga en `EDI` la dirección del string `"/bin/sh"` que se encuentra en `0x400d32` — único argumento de `system()`.
8. <+630>: Llama a `system()` — lanza una shell:
```bash
system("/bin/sh");
```
9. <+635>: Pone `EAX` a 0 — valor de retorno de `main()`.
10. <+640>: `leave` — restaura el stack frame: copia `RBP` en `RSP` y hace `pop RBP`.
11. <+641>: `ret` — retorna al caller devolviendo el control.

### **Líeas 642, 646, 649, 654, 659, 664, 669 y674:**
```asm
0x0000000000400a96 <+642>:	lea    rax,[rbp-0x70]
0x0000000000400a9a <+646>:	mov    rdi,rax
0x0000000000400a9d <+649>:	mov    eax,0x0
0x0000000000400aa2 <+654>:	call   0x4006c0 <printf@plt>
0x0000000000400aa7 <+659>:	mov    edi,0x400d3a
0x0000000000400aac <+664>:	call   0x400680 <puts@plt>
0x0000000000400ab1 <+669>:	mov    edi,0x1
0x0000000000400ab6 <+674>:	call   0x400710 <exit@plt>
```

1. <+642>: Calcula la dirección de `[rbp-0x70]` que es la variable `buffer_username` y la carga en `RAX`.
2. <+646>: Copia `RAX` en `RDI` — único argumento de `printf()`: el nombre de usuario introducido.
3. <+649>: Pone `EAX` a 0 — convención x86-64 que indica a `printf()` que no se usan registros vectoriales (SSE/AVX).
4. <+654>: Llama a `printf()` — imprime el nombre de usuario sin formato:
```bash
printf(buffer_username);
```
5. <+659>: Carga en `EDI` la dirección del string `" does not have access!"` que se encuentra en `0x400d3a` — argumento de `puts()`.
6. <+664>: Llama a `puts()`:
```bash
puts(" does not have access!");
```
7. <+669>: Carga el valor `1` en `EDI` — el código de salida que recibirá `exit()`.
8. <+674>: Llama a `exit@plt` y termina el programa.