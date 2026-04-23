# **ANÁLISIS COMPLETO LINEA POR LINEA - NIVEL level09**

```asm
Dump of assembler code for function main:
   0x0000000000000aa8 <+0>:	    push   rbp
   0x0000000000000aa9 <+1>:	    mov    rbp,rsp
   0x0000000000000aac <+4>:	    lea    rdi,[rip+0x15d]        # 0xc10
   0x0000000000000ab3 <+11>:	call   0x730 <puts@plt>
   0x0000000000000ab8 <+16>:	call   0x8c0 <handle_msg>
   0x0000000000000abd <+21>:	mov    eax,0x0
   0x0000000000000ac2 <+26>:	pop    rbp
   0x0000000000000ac3 <+27>:	ret    
End of assembler dump.
```

### **Líneas 0, 1, 4, 11, 16, 21, 26 y 27:**

1.  <+0>: Guarda en lo alto del stack el valor de `RBP` (cpu) `[rsp + 0x00]`. El `RSP` se desplaza 8 bytes hacia abajo.
2.  <+1>: Asigna el nuevo `RSP` a `RBP` para la función `main`.
3.  <+4>: Calcula la dirección del string del banner relativa a `RIP` y la carga en `RDI` — argumento de `puts()`.
4.  <+11>: Llama a `puts()` — imprime la cabecera del programa.
5.  <+16>: Llama a `handle_msg()` — función principal del programa.
6.  <+21>: Pone `EAX` a 0 — valor de retorno de `main()`.
7.  <+26>: Restaura `RBP`.
8.  <+27>: `ret` — retorna el control al sistema.

# **ANÁLISIS COMPLETO LINEA POR LINEA - function handle_msg**

```asm
Dump of assembler code for function handle_msg:
   0x00000000000008c0 <+0>:     push   rbp
   0x00000000000008c1 <+1>:     mov    rbp,rsp
   0x00000000000008c4 <+4>:     sub    rsp,0xc0
   0x00000000000008cb <+11>:	lea    rax,[rbp-0xc0]
   0x00000000000008d2 <+18>:	add    rax,0x8c
   0x00000000000008d8 <+24>:	mov    QWORD PTR [rax],0x0
   0x00000000000008df <+31>:	mov    QWORD PTR [rax+0x8],0x0
   0x00000000000008e7 <+39>:	mov    QWORD PTR [rax+0x10],0x0
   0x00000000000008ef <+47>:	mov    QWORD PTR [rax+0x18],0x0
   0x00000000000008f7 <+55>:	mov    QWORD PTR [rax+0x20],0x0
   0x00000000000008ff <+63>:	mov    DWORD PTR [rbp-0xc],0x8c
   0x0000000000000906 <+70>:	lea    rax,[rbp-0xc0]
   0x000000000000090d <+77>:	mov    rdi,rax
   0x0000000000000910 <+80>:	call   0x9cd <set_username>
   0x0000000000000915 <+85>:	lea    rax,[rbp-0xc0]
   0x000000000000091c <+92>:	mov    rdi,rax
   0x000000000000091f <+95>:	call   0x932 <set_msg>
   0x0000000000000924 <+100>:	lea    rdi,[rip+0x295]        # 0xbc0
   0x000000000000092b <+107>:	call   0x730 <puts@plt>
   0x0000000000000930 <+112>:	leave  
   0x0000000000000931 <+113>:	ret    
End of assembler dump.
```

### **Líneas 0, 1, 4, 11, 18, 24, 31, 39, 47, 55, 63, 70, 77, 80, 85, 92, 95, 100, 107, 112 y 113:**

1.  <+0>: Guarda en lo alto del stack el valor de `RBP` (cpu) `[rsp + 0x00]`. El `RSP` se desplaza 8 bytes.
2.  <+1>: Asigna el nuevo `RSP` a `RBP` para la función `handle_msg()`.
3.  <+4>: Reserva (desplaza) `192 bytes` (0xc0) en el stack de `handle_msg()` para las variables locales.
4.  <+11>: Calcula la dirección de `[rbp-0xc0]` que es la variable local `msg` (estructura del mensaje) y la carga en `RAX`.
5.  <+18>: Suma `0x8c` (140) a `RAX` — apunta al campo `username` dentro de la estructura `msg`.
6.  <+24>: Escribe `0` en `[rax]` — inicializa los primeros 8 bytes del campo `username`.
7.  <+31>: Escribe `0` en `[rax+0x8]` — inicializa bytes 8-15.
8.  <+39>: Escribe `0` en `[rax+0x10]` — inicializa bytes 16-23.
9.  <+47>: Escribe `0` en `[rax+0x18]` — inicializa bytes 24-31.
10. <+55>: Escribe `0` en `[rax+0x20]` — inicializa bytes 32-39. El campo `username` queda a ceros (40 bytes total).
11. <+63>: Escribe `0x8c` (140) en `[rbp-0xc]` — variable local `len` que indica el tamaño del campo del mensaje.
12. <+70>: Calcula de nuevo la dirección de `msg` en `RAX`.
13. <+77>: Copia `msg` en `RDI` — argumento de `set_username()`.
14. <+80>: Llama a `set_username(msg)` — lee y guarda el username.
15. <+85>: Calcula de nuevo la dirección de `msg` en `RAX`.
16. <+92>: Copia `msg` en `RDI` — argumento de `set_msg()`.
17. <+95>: Llama a `set_msg(msg)` — lee y guarda el mensaje.
18. <+100>: Calcula la dirección del string `">: Msg sent!"` relativa a `RIP` y la carga en `RDI`.
19. <+107>: Llama a `puts(">: Msg sent!")`.
20. <+112>: `leave` — restaura el stack frame.
21. <+113>: `ret` — retorna el control a `main()`.

# **ANÁLISIS COMPLETO LINEA POR LINEA - function set_msg**

```asm
Dump of assembler code for function set_msg:
   0x0000000000000932 <+0>:	    push   rbp
   0x0000000000000933 <+1>:	    mov    rbp,rsp
   0x0000000000000936 <+4>:	    sub    rsp,0x410
   0x000000000000093d <+11>:	mov    QWORD PTR [rbp-0x408],rdi
   0x0000000000000944 <+18>:	lea    rax,[rbp-0x400]
   0x000000000000094b <+25>:	mov    rsi,rax
   0x000000000000094e <+28>:	mov    eax,0x0
   0x0000000000000953 <+33>:	mov    edx,0x80
   0x0000000000000958 <+38>:	mov    rdi,rsi
   0x000000000000095b <+41>:	mov    rcx,rdx
   0x000000000000095e <+44>:	rep stos QWORD PTR es:[rdi],rax
   0x0000000000000961 <+47>:	lea    rdi,[rip+0x265]        # 0xbcd
   0x0000000000000968 <+54>:	call   0x730 <puts@plt>
   0x000000000000096d <+59>:	lea    rax,[rip+0x26b]        # 0xbdf
   0x0000000000000974 <+66>:	mov    rdi,rax
   0x0000000000000977 <+69>:	mov    eax,0x0
   0x000000000000097c <+74>:	call   0x750 <printf@plt>
   0x0000000000000981 <+79>:	mov    rax,QWORD PTR [rip+0x201630]        # 0x201fb8
   0x0000000000000988 <+86>:	mov    rax,QWORD PTR [rax]
   0x000000000000098b <+89>:	mov    rdx,rax
   0x000000000000098e <+92>:	lea    rax,[rbp-0x400]
   0x0000000000000995 <+99>:	mov    esi,0x400
   0x000000000000099a <+104>:	mov    rdi,rax
   0x000000000000099d <+107>:	call   0x770 <fgets@plt>
   0x00000000000009a2 <+112>:	mov    rax,QWORD PTR [rbp-0x408]
   0x00000000000009a9 <+119>:	mov    eax,DWORD PTR [rax+0xb4]
   0x00000000000009af <+125>:	movsxd rdx,eax
   0x00000000000009b2 <+128>:	lea    rcx,[rbp-0x400]
   0x00000000000009b9 <+135>:	mov    rax,QWORD PTR [rbp-0x408]
   0x00000000000009c0 <+142>:	mov    rsi,rcx
   0x00000000000009c3 <+145>:	mov    rdi,rax
   0x00000000000009c6 <+148>:	call   0x720 <strncpy@plt>
   0x00000000000009cb <+153>:	leave  
   0x00000000000009cc <+154>:	ret    
End of assembler dump.
```
### **Líneas 0, 1, 4, 11, 18, 25, 28, 33, 38, 41 y 44:**
```asm
0x0000000000000932 <+0>:	    push   rbp
0x0000000000000933 <+1>:	    mov    rbp,rsp
0x0000000000000936 <+4>:	    sub    rsp,0x410
0x000000000000093d <+11>:	mov    QWORD PTR [rbp-0x408],rdi
0x0000000000000944 <+18>:	lea    rax,[rbp-0x400]
0x000000000000094b <+25>:	mov    rsi,rax
0x000000000000094e <+28>:	mov    eax,0x0
0x0000000000000953 <+33>:	mov    edx,0x80
0x0000000000000958 <+38>:	mov    rdi,rsi
0x000000000000095b <+41>:	mov    rcx,rdx
0x000000000000095e <+44>:	rep stos QWORD PTR es:[rdi],rax
```

1.  <+0>: Guarda en lo alto del stack el valor de `RBP` (función `handle_msg`) `[rsp + 0x00]`. El `RSP` se desplaza 8 bytes.
2.  <+1>: Asigna a `RBP` el nuevo `RSP` para la función `set_msg()`.
3.  <+4>: Reserva (desplaza) `1040 bytes` (0x410) en el stack de `set_msg()`.
4.  <+11>: Guarda el argumento `msg` en `[rbp-0x408]`.
5.  <+18>: Calcula la dirección de `[rbp-0x400]` que es la variable local `buf` y la carga en `RAX`.
6.  <+25>: Copia `buf` en `RSI`.
7.  <+28>: Pone `EAX` a 0.
8.  <+33>: Escribe `128` (0x80) en `EDX` — contador del `rep stos`.
9.  <+38>: Copia `buf` en `RDI` — destino del `rep stos`.
10. <+41>: Copia el contador en `RCX`.
11. <+44>: **Es la versión de 64 bits del `memset`.**
```c
memset(buf, 0, 128 * 8);  // 1024 bytes
```

### **Líneas 47, 54, 59, 66, 69, 74, 79, 86, 89, 92, 99, 104, 107, 112, 119, 125, 128, 135, 142, 145, 148, 153 y 154:**
```asm
0x0000000000000961 <+47>:	lea    rdi,[rip+0x265]        # 0xbcd
0x0000000000000968 <+54>:	call   0x730 <puts@plt>
0x000000000000096d <+59>:	lea    rax,[rip+0x26b]        # 0xbdf
0x0000000000000974 <+66>:	mov    rdi,rax
0x0000000000000977 <+69>:	mov    eax,0x0
0x000000000000097c <+74>:	call   0x750 <printf@plt>
0x0000000000000981 <+79>:	mov    rax,QWORD PTR [rip+0x201630]        # 0x201fb8
0x0000000000000988 <+86>:	mov    rax,QWORD PTR [rax]
0x000000000000098b <+89>:	mov    rdx,rax
0x000000000000098e <+92>:	lea    rax,[rbp-0x400]
0x0000000000000995 <+99>:	mov    esi,0x400
0x000000000000099a <+104>:	mov    rdi,rax
0x000000000000099d <+107>:	call   0x770 <fgets@plt>
0x00000000000009a2 <+112>:	mov    rax,QWORD PTR [rbp-0x408]
0x00000000000009a9 <+119>:	mov    eax,DWORD PTR [rax+0xb4]
0x00000000000009af <+125>:	movsxd rdx,eax
0x00000000000009b2 <+128>:	lea    rcx,[rbp-0x400]
0x00000000000009b9 <+135>:	mov    rax,QWORD PTR [rbp-0x408]
0x00000000000009c0 <+142>:	mov    rsi,rcx
0x00000000000009c3 <+145>:	mov    rdi,rax
0x00000000000009c6 <+148>:	call   0x720 <strncpy@plt>
0x00000000000009cb <+153>:	leave  
0x00000000000009cc <+154>:	ret  
```

1.  <+47>: Calcula la dirección del string `">: Msg @Unix-Dude"` relativa a `RIP` y la carga en `RDI`.
```bash
(gdb) x/s 0xbcd
0xbcd:	 ">: Msg @Unix-Dude"
```
2.  <+54>: Llama a `puts(">: Msg @Unix-Dude")`.
3.  <+59>: Calcula la dirección del string `">>: "` relativa a `RIP` y la carga en `RAX`.
```bash
(gdb) x/s 0xbdf
0xbdf:	 ">>: "

```
4.  <+66>: Copia `">>: "` en `RDI` — argumento de `printf()`.
5.  <+69>: Pone `EAX` a 0.
6.  <+74>: Llama a `printf(">>: ")`.
7.  <+79>: Carga en `RAX` el puntero a `stdin` desde `[rip+0x201630]`.
8.  <+86>: Desreferencia — obtiene el stream `stdin`.
9.  <+89>: Copia `stdin` en `RDX` — tercer argumento de `fgets()`.
10. <+92>: Calcula la dirección de `buf` en `RAX`.
11. <+99>: Carga `0x400` (1024) en `ESI` — segundo argumento de `fgets()`: máximo de bytes a leer.
12. <+104>: Copia `buf` en `RDI` — primer argumento de `fgets()`.
13. <+107>: Llama a `fgets(buf, 1024, stdin)`.
14. <+112>: Carga el puntero `msg` en `RAX`.
15. <+119>: Carga en `EAX` el campo `msg->len` desde `[rax+0xb4]` — el tamaño máximo a copiar.
16. <+125>: Extiende el signo de `len` a 64 bits en `RDX`.
17. <+128>: Calcula la dirección de `buf` en `RCX`.
18. <+135>: Carga el puntero `msg` en `RAX`.
19. <+142>: Copia `buf` en `RSI` — segundo argumento de `strncpy()`.
20. <+145>: Copia `msg` en `RDI` — primer argumento de `strncpy()`.
21. <+148>: Llama a `strncpy(msg, buf, msg->len)` — copia el mensaje en la estructura.
22. <+153>: `leave` — restaura el stack frame.
23. <+154>: `ret` — retorna el control a `handle_msg()`.

# **ANÁLISIS COMPLETO LINEA POR LINEA - function set_username**

```asm
Dump of assembler code for function set_username:
   0x00000000000009cd <+0>:	push   rbp
   0x00000000000009ce <+1>:	mov    rbp,rsp
   0x00000000000009d1 <+4>:	sub    rsp,0xa0
   0x00000000000009d8 <+11>:	mov    QWORD PTR [rbp-0x98],rdi
   0x00000000000009df <+18>:	lea    rax,[rbp-0x90]
   0x00000000000009e6 <+25>:	mov    rsi,rax
   0x00000000000009e9 <+28>:	mov    eax,0x0
   0x00000000000009ee <+33>:	mov    edx,0x10
   0x00000000000009f3 <+38>:	mov    rdi,rsi
   0x00000000000009f6 <+41>:	mov    rcx,rdx
   0x00000000000009f9 <+44>:	rep stos QWORD PTR es:[rdi],rax
   0x00000000000009fc <+47>:	lea    rdi,[rip+0x1e1]        # 0xbe4
   0x0000000000000a03 <+54>:	call   0x730 <puts@plt>
   0x0000000000000a08 <+59>:	lea    rax,[rip+0x1d0]        # 0xbdf
   0x0000000000000a0f <+66>:	mov    rdi,rax
   0x0000000000000a12 <+69>:	mov    eax,0x0
   0x0000000000000a17 <+74>:	call   0x750 <printf@plt>
   0x0000000000000a1c <+79>:	mov    rax,QWORD PTR [rip+0x201595]        # 0x201fb8
   0x0000000000000a23 <+86>:	mov    rax,QWORD PTR [rax]
   0x0000000000000a26 <+89>:	mov    rdx,rax
   0x0000000000000a29 <+92>:	lea    rax,[rbp-0x90]
   0x0000000000000a30 <+99>:	mov    esi,0x80
   0x0000000000000a35 <+104>:	mov    rdi,rax
   0x0000000000000a38 <+107>:	call   0x770 <fgets@plt>
   0x0000000000000a3d <+112>:	mov    DWORD PTR [rbp-0x4],0x0
   0x0000000000000a44 <+119>:	jmp    0xa6a <set_username+157>
   0x0000000000000a46 <+121>:	mov    eax,DWORD PTR [rbp-0x4]
   0x0000000000000a49 <+124>:	cdqe   
   0x0000000000000a4b <+126>:	movzx  ecx,BYTE PTR [rbp+rax*1-0x90]
   0x0000000000000a53 <+134>:	mov    rdx,QWORD PTR [rbp-0x98]
   0x0000000000000a5a <+141>:	mov    eax,DWORD PTR [rbp-0x4]
   0x0000000000000a5d <+144>:	cdqe   
   0x0000000000000a5f <+146>:	mov    BYTE PTR [rdx+rax*1+0x8c],cl
   0x0000000000000a66 <+153>:	add    DWORD PTR [rbp-0x4],0x1
   0x0000000000000a6a <+157>:	cmp    DWORD PTR [rbp-0x4],0x28
   0x0000000000000a6e <+161>:	jg     0xa81 <set_username+180>
   0x0000000000000a70 <+163>:	mov    eax,DWORD PTR [rbp-0x4]
   0x0000000000000a73 <+166>:	cdqe   
   0x0000000000000a75 <+168>:	movzx  eax,BYTE PTR [rbp+rax*1-0x90]
   0x0000000000000a7d <+176>:	test   al,al
   0x0000000000000a7f <+178>:	jne    0xa46 <set_username+121>
   0x0000000000000a81 <+180>:	mov    rax,QWORD PTR [rbp-0x98]
   0x0000000000000a88 <+187>:	lea    rdx,[rax+0x8c]
   0x0000000000000a8f <+194>:	lea    rax,[rip+0x165]        # 0xbfb
   0x0000000000000a96 <+201>:	mov    rsi,rdx
   0x0000000000000a99 <+204>:	mov    rdi,rax
   0x0000000000000a9c <+207>:	mov    eax,0x0
   0x0000000000000aa1 <+212>:	call   0x750 <printf@plt>
   0x0000000000000aa6 <+217>:	leave  
   0x0000000000000aa7 <+218>:	ret    
End of assembler dump.
```

### **Líneas 0, 1, 4, 11, 18, 25, 28, 33, 38, 41 y 44:**
```asm
0x00000000000009cd <+0>:	push   rbp
0x00000000000009ce <+1>:	mov    rbp,rsp
0x00000000000009d1 <+4>:	sub    rsp,0xa0
0x00000000000009d8 <+11>:	mov    QWORD PTR [rbp-0x98],rdi
0x00000000000009df <+18>:	lea    rax,[rbp-0x90]
0x00000000000009e6 <+25>:	mov    rsi,rax
0x00000000000009e9 <+28>:	mov    eax,0x0
0x00000000000009ee <+33>:	mov    edx,0x10
0x00000000000009f3 <+38>:	mov    rdi,rsi
0x00000000000009f6 <+41>:	mov    rcx,rdx
0x00000000000009f9 <+44>:	rep stos QWORD PTR es:[rdi],rax
```

1.  <+0>: Guarda en lo alto del stack el valor de `RBP` (función `handle_msg`) `[rsp + 0x00]`. El `RSP` se desplaza 8 bytes.
2.  <+1>: Asigna a `RBP` el nuevo `RSP` para la función `set_username()`.
3.  <+4>: Reserva (desplaza) `160 bytes` (0xa0) en el stack de `set_username()`.
4.  <+11>: Guarda el argumento `msg` en `[rbp-0x98]`.
5.  <+18>: Calcula la dirección de `[rbp-0x90]` que es la variable local `buf` y la carga en `RAX`.
6.  <+25>: Copia `buf` en `RSI`.
7.  <+28>: Pone `EAX` a 0.
8.  <+33>: Escribe `16` (0x10) en `EDX` — contador del `rep stos`.
9.  <+38>: Copia `buf` en `RDI` — destino del `rep stos`.
10. <+41>: Copia el contador en `RCX`.
11. <+44>: **Es la versión de 64 bits del `memset`.**
```c
memset(buf, 0, 16 * 8);  // 128 bytes
```

### **Líneas 47, 54, 59, 66, 69, 74, 79, 86, 89, 92, 99, 104 y 107:**
```asm
0x00000000000009fc <+47>:	lea    rdi,[rip+0x1e1]        # 0xbe4
0x0000000000000a03 <+54>:	call   0x730 <puts@plt>
0x0000000000000a08 <+59>:	lea    rax,[rip+0x1d0]        # 0xbdf
0x0000000000000a0f <+66>:	mov    rdi,rax
0x0000000000000a12 <+69>:	mov    eax,0x0
0x0000000000000a17 <+74>:	call   0x750 <printf@plt>
0x0000000000000a1c <+79>:	mov    rax,QWORD PTR [rip+0x201595]        # 0x201fb8
0x0000000000000a23 <+86>:	mov    rax,QWORD PTR [rax]
0x0000000000000a26 <+89>:	mov    rdx,rax
0x0000000000000a29 <+92>:	lea    rax,[rbp-0x90]
0x0000000000000a30 <+99>:	mov    esi,0x80
0x0000000000000a35 <+104>:	mov    rdi,rax
0x0000000000000a38 <+107>:	call   0x770 <fgets@plt>
```

1.  <+47>: Calcula la dirección del string `">: Enter your username"` relativa a `RIP` y la carga en `RDI`.
```bash
(gdb) x/s 0xbe4
0xbe4:	 ">: Enter your username"
```
2.  <+54>: Llama a `puts(">: Enter your username")`.
3.  <+59>: Calcula la dirección del string `">>: "` relativa a `RIP` y la carga en `RAX`.
```bash
(gdb) x/s 0xbdf
0xbdf:	 ">>: "
```
4.  <+66>: Copia `">>: "` en `RDI` — argumento de `printf()`.
5.  <+69>: Pone `EAX` a 0.
6.  <+74>: Llama a `printf(">>: ")`.
7.  <+79>: Carga en `RAX` el puntero a `stdin` desde `[rip+0x201595]`.
8.  <+86>: Desreferencia — obtiene el stream `stdin`.
9.  <+89>: Copia `stdin` en `RDX` — tercer argumento de `fgets()`.
10. <+92>: Calcula la dirección de `buf` en `RAX`.
11. <+99>: Carga `0x80` (128) en `ESI` — segundo argumento de `fgets()`: máximo de bytes a leer.
12. <+104>: Copia `buf` en `RDI` — primer argumento de `fgets()`.
13. <+107>: Llama a `fgets(buf, 128, stdin)`.

### **Líneas 112, 119, 121, 124, 126, 134, 141, 144, 146, 153, 157, 161, 163, 166, 168, 176, 178, 180, 187, 194, 201, 204, 207, 212, 217 y 218:**
```asm
0x0000000000000a3d <+112>:	mov    DWORD PTR [rbp-0x4],0x0
0x0000000000000a44 <+119>:	jmp    0xa6a <set_username+157>
0x0000000000000a46 <+121>:	mov    eax,DWORD PTR [rbp-0x4]
0x0000000000000a49 <+124>:	cdqe   
0x0000000000000a4b <+126>:	movzx  ecx,BYTE PTR [rbp+rax*1-0x90]
0x0000000000000a53 <+134>:	mov    rdx,QWORD PTR [rbp-0x98]
0x0000000000000a5a <+141>:	mov    eax,DWORD PTR [rbp-0x4]
0x0000000000000a5d <+144>:	cdqe   
0x0000000000000a5f <+146>:	mov    BYTE PTR [rdx+rax*1+0x8c],cl
0x0000000000000a66 <+153>:	add    DWORD PTR [rbp-0x4],0x1
0x0000000000000a6a <+157>:	cmp    DWORD PTR [rbp-0x4],0x28
0x0000000000000a6e <+161>:	jg     0xa81 <set_username+180>
0x0000000000000a70 <+163>:	mov    eax,DWORD PTR [rbp-0x4]
0x0000000000000a73 <+166>:	cdqe   
0x0000000000000a75 <+168>:	movzx  eax,BYTE PTR [rbp+rax*1-0x90]
0x0000000000000a7d <+176>:	test   al,al
0x0000000000000a7f <+178>:	jne    0xa46 <set_username+121>
0x0000000000000a81 <+180>:	mov    rax,QWORD PTR [rbp-0x98]
0x0000000000000a88 <+187>:	lea    rdx,[rax+0x8c]
0x0000000000000a8f <+194>:	lea    rax,[rip+0x165]        # 0xbfb
0x0000000000000a96 <+201>:	mov    rsi,rdx
0x0000000000000a99 <+204>:	mov    rdi,rax
0x0000000000000a9c <+207>:	mov    eax,0x0
0x0000000000000aa1 <+212>:	call   0x750 <printf@plt>
0x0000000000000aa6 <+217>:	leave  
0x0000000000000aa7 <+218>:	ret  
```

1.  <+112>: Inicializa a 0 la variable local `i` en `[rbp-0x4]` — contador del bucle.
2.  <+119>: `jmp` incondicional a `<+157>` — salta a la condición del bucle.
3.  <+121>: Carga `i` en `EAX`.
4.  <+124>: `cdqe` — extiende el signo de `EAX` a 64 bits en `RAX`.
5.  <+126>: Carga en `ECX` el byte `buf[i]`.
6.  <+134>: Carga el puntero `msg` en `RDX`.
7.  <+141>: Carga `i` en `EAX`.
8.  <+144>: `cdqe` — extiende el signo a 64 bits.
9.  <+146>: Copia `buf[i]` en `msg->username[i]` — `msg + 0x8c + i`. Copia byte a byte el username en la estructura.
10. <+153>: Incrementa `i` en 1.
11. <+157>: Compara `i` con `0x28` (40).
12. <+161>: `jg` — si `i > 40` sale del bucle.
13. <+163>: Carga `i` en `EAX`.
14. <+166>: `cdqe` — extiende el signo.
15. <+168>: Carga en `EAX` el byte `buf[i]`.
16. <+176>: Comprueba si `buf[i]` es `\0`.
17. <+178>: `jne` — si no es `\0` vuelve a `<+121>` para copiar el siguiente byte.
18. <+180>: Carga el puntero `msg` en `RAX`.
19. <+187>: Calcula la dirección de `msg->username` (`msg + 0x8c`) en `RDX`.
20. <+194>: Calcula la dirección del string `">: Welcome, %s"` relativa a `RIP` y la carga en `RAX`.
21. <+201>: Copia `msg->username` en `RSI` — segundo argumento de `printf()`.
22. <+204>: Copia el formato en `RDI` — primer argumento de `printf()`.
23. <+207>: Pone `EAX` a 0.
24. <+212>: Llama a `printf(">: Welcome, %s", msg->username)`.
25. <+217>: `leave` — restaura el stack frame.
26. <+218>: `ret` — retorna el control a `handle_msg()`.

# **ANÁLISIS COMPLETO LINEA POR LINEA - function secret_backdoor**

```asm
Dump of assembler code for function secret_backdoor:
   0x000000000000088c <+0>:	    push   rbp
   0x000000000000088d <+1>:	    mov    rbp,rsp
   0x0000000000000890 <+4>:	    add    rsp,0xffffffffffffff80
   0x0000000000000894 <+8>:	    mov    rax,QWORD PTR [rip+0x20171d]        # 0x201fb8
   0x000000000000089b <+15>:	mov    rax,QWORD PTR [rax]
   0x000000000000089e <+18>:	mov    rdx,rax
   0x00000000000008a1 <+21>:	lea    rax,[rbp-0x80]
   0x00000000000008a5 <+25>:	mov    esi,0x80
   0x00000000000008aa <+30>:	mov    rdi,rax
   0x00000000000008ad <+33>:	call   0x770 <fgets@plt>
   0x00000000000008b2 <+38>:	lea    rax,[rbp-0x80]
   0x00000000000008b6 <+42>:	mov    rdi,rax
   0x00000000000008b9 <+45>:	call   0x740 <system@plt>
   0x00000000000008be <+50>:	leave  
   0x00000000000008bf <+51>:	ret    
End of assembler dump.
```

### **Líneas 0, 1, 4, 8, 15, 18, 21, 25, 30, 33, 38, 42, 45, 50 y 51:**

1.  <+0>: Guarda en lo alto del stack el valor de `RBP` (cpu) `[rsp + 0x00]`. El `RSP` se desplaza 8 bytes.
2.  <+1>: Asigna el nuevo `RSP` a `RBP` para la función `secret_backdoor()`.
3.  <+4>: Reserva `128 bytes` (0x80) en el stack — equivale a `sub rsp, 0x80`.
4.  <+8>: Carga en `RAX` el puntero a `stdin` desde `[rip+0x20171d]`.
5.  <+15>: Desreferencia — obtiene el stream `stdin`.
6.  <+18>: Copia `stdin` en `RDX` — tercer argumento de `fgets()`.
7.  <+21>: Calcula la dirección de `[rbp-0x80]` que es la variable local `cmd` y la carga en `RAX`.
8.  <+25>: Carga `0x80` (128) en `ESI` — segundo argumento de `fgets()`: máximo de bytes a leer.
9.  <+30>: Copia `cmd` en `RDI` — primer argumento de `fgets()`.
10. <+33>: Llama a `fgets(cmd, 128, stdin)` — lee el comando introducido por el usuario.
11. <+38>: Calcula de nuevo la dirección de `cmd` en `RAX`.
12. <+42>: Copia `cmd` en `RDI` — argumento de `system()`.
13. <+45>: Llama a `system(cmd)` — ejecuta el comando como shell.
14. <+50>: `leave` — restaura el stack frame.
15. <+51>: `ret` — retorna el control al caller.

# Resumen del Flujo de Ataque para el Nivel 09

## 1. Lectura:

La vulnerabilidad está en `set_username()` — el bucle de copia no valida correctamente el límite:

```c
for (i = 0; i <= 40 && buf[i]; i++)
    msg->username[i] = buf[i];
```

El bucle itera hasta `i <= 40` — copia **41 bytes** en un campo de 40 bytes.
Este **off-by-one** permite escribir un byte extra más allá de `username`.

---

## 2. Vulnerabilidad:

* `msg->username` ocupa 40 bytes en el offset `0x8c` de la estructura.
* El campo `msg->len` está en el offset `0xb4` — justo después de `username`.
* El off-by-one permite sobrescribir el primer byte de `msg->len`.
* `set_msg()` usa `msg->len` como límite de `strncpy()` — si aumentamos `msg->len` podemos copiar más bytes de los previstos y desbordar `msg->msg` hasta sobrescribir el `RIP` de `handle_msg()`.
* `secret_backdoor()` existe en el binario pero nunca se llama — es nuestro objetivo.
* **PIE está ON** — necesitamos calcular la dirección real de `secret_backdoor()` sumando su offset al base address del binario.

---

## 3. Explotación:

* **Paso 1:** Usamos el off-by-one en `set_username()` para sobrescribir el byte menos significativo de `msg->len` con un valor grande — por ejemplo `\xff` (255) — ampliando el límite de copia de `strncpy()`.
* **Paso 2:** En `set_msg()` introducimos un payload que desborde `msg->msg` hasta sobrescribir el `RIP` de `handle_msg()` con la dirección de `secret_backdoor()`.
* **Paso 3:** Cuando `handle_msg()` ejecute `ret` saltará a `secret_backdoor()` que lee un comando y llama a `system()`.
* **Paso 4:** Introducimos `cat /home/users/end/.pass` como comando.