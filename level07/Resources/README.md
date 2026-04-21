# **ANÁLISIS COMPLETO LINEA POR LINEA - NIVEL level07**

```asm
Dump of assembler code for function main:
   0x08048723 <+0>:	push   ebp
   0x08048724 <+1>:	mov    ebp,esp
   0x08048726 <+3>:	push   edi
   0x08048727 <+4>:	push   esi
   0x08048728 <+5>:	push   ebx
   0x08048729 <+6>:	and    esp,0xfffffff0
   0x0804872c <+9>:	sub    esp,0x1d0
   0x08048732 <+15>:	mov    eax,DWORD PTR [ebp+0xc]
   0x08048735 <+18>:	mov    DWORD PTR [esp+0x1c],eax
   0x08048739 <+22>:	mov    eax,DWORD PTR [ebp+0x10]
   0x0804873c <+25>:	mov    DWORD PTR [esp+0x18],eax
   0x08048740 <+29>:	mov    eax,gs:0x14
   0x08048746 <+35>:	mov    DWORD PTR [esp+0x1cc],eax
   0x0804874d <+42>:	xor    eax,eax
   0x0804874f <+44>:	mov    DWORD PTR [esp+0x1b4],0x0
   0x0804875a <+55>:	mov    DWORD PTR [esp+0x1b8],0x0
   0x08048765 <+66>:	mov    DWORD PTR [esp+0x1bc],0x0
   0x08048770 <+77>:	mov    DWORD PTR [esp+0x1c0],0x0
   0x0804877b <+88>:	mov    DWORD PTR [esp+0x1c4],0x0
   0x08048786 <+99>:	mov    DWORD PTR [esp+0x1c8],0x0
   0x08048791 <+110>:	lea    ebx,[esp+0x24]
   0x08048795 <+114>:	mov    eax,0x0
   0x0804879a <+119>:	mov    edx,0x64
   0x0804879f <+124>:	mov    edi,ebx
   0x080487a1 <+126>:	mov    ecx,edx
   0x080487a3 <+128>:	rep stos DWORD PTR es:[edi],eax
   0x080487a5 <+130>:	jmp    0x80487ea <main+199>
   0x080487a7 <+132>:	mov    eax,DWORD PTR [esp+0x1c]
   0x080487ab <+136>:	mov    eax,DWORD PTR [eax]
   0x080487ad <+138>:	mov    DWORD PTR [esp+0x14],0xffffffff
   0x080487b5 <+146>:	mov    edx,eax
   0x080487b7 <+148>:	mov    eax,0x0
   0x080487bc <+153>:	mov    ecx,DWORD PTR [esp+0x14]
   0x080487c0 <+157>:	mov    edi,edx
   0x080487c2 <+159>:	repnz scas al,BYTE PTR es:[edi]
   0x080487c4 <+161>:	mov    eax,ecx
   0x080487c6 <+163>:	not    eax
   0x080487c8 <+165>:	lea    edx,[eax-0x1]
   0x080487cb <+168>:	mov    eax,DWORD PTR [esp+0x1c]
   0x080487cf <+172>:	mov    eax,DWORD PTR [eax]
   0x080487d1 <+174>:	mov    DWORD PTR [esp+0x8],edx
   0x080487d5 <+178>:	mov    DWORD PTR [esp+0x4],0x0
   0x080487dd <+186>:	mov    DWORD PTR [esp],eax
   0x080487e0 <+189>:	call   0x80484f0 <memset@plt>
   0x080487e5 <+194>:	add    DWORD PTR [esp+0x1c],0x4
   0x080487ea <+199>:	mov    eax,DWORD PTR [esp+0x1c]
   0x080487ee <+203>:	mov    eax,DWORD PTR [eax]
   0x080487f0 <+205>:	test   eax,eax
   0x080487f2 <+207>:	jne    0x80487a7 <main+132>
   0x080487f4 <+209>:	jmp    0x8048839 <main+278>
   0x080487f6 <+211>:	mov    eax,DWORD PTR [esp+0x18]
   0x080487fa <+215>:	mov    eax,DWORD PTR [eax]
   0x080487fc <+217>:	mov    DWORD PTR [esp+0x14],0xffffffff
   0x08048804 <+225>:	mov    edx,eax
   0x08048806 <+227>:	mov    eax,0x0
   0x0804880b <+232>:	mov    ecx,DWORD PTR [esp+0x14]
   0x0804880f <+236>:	mov    edi,edx
   0x08048811 <+238>:	repnz scas al,BYTE PTR es:[edi]
   0x08048813 <+240>:	mov    eax,ecx
   0x08048815 <+242>:	not    eax
   0x08048817 <+244>:	lea    edx,[eax-0x1]
   0x0804881a <+247>:	mov    eax,DWORD PTR [esp+0x18]
   0x0804881e <+251>:	mov    eax,DWORD PTR [eax]
   0x08048820 <+253>:	mov    DWORD PTR [esp+0x8],edx
   0x08048824 <+257>:	mov    DWORD PTR [esp+0x4],0x0
   0x0804882c <+265>:	mov    DWORD PTR [esp],eax
   0x0804882f <+268>:	call   0x80484f0 <memset@plt>
   0x08048834 <+273>:	add    DWORD PTR [esp+0x18],0x4
   0x08048839 <+278>:	mov    eax,DWORD PTR [esp+0x18]
   0x0804883d <+282>:	mov    eax,DWORD PTR [eax]
   0x0804883f <+284>:	test   eax,eax
   0x08048841 <+286>:	jne    0x80487f6 <main+211>
   0x08048843 <+288>:	mov    DWORD PTR [esp],0x8048b38
   0x0804884a <+295>:	call   0x80484c0 <puts@plt>
   0x0804884f <+300>:	mov    eax,0x8048d4b
   0x08048854 <+305>:	mov    DWORD PTR [esp],eax
   0x08048857 <+308>:	call   0x8048470 <printf@plt>
   0x0804885c <+313>:	mov    DWORD PTR [esp+0x1b4],0x1
   0x08048867 <+324>:	mov    eax,ds:0x804a040
   0x0804886c <+329>:	mov    DWORD PTR [esp+0x8],eax
   0x08048870 <+333>:	mov    DWORD PTR [esp+0x4],0x14
   0x08048878 <+341>:	lea    eax,[esp+0x1b8]
   0x0804887f <+348>:	mov    DWORD PTR [esp],eax
   0x08048882 <+351>:	call   0x80484a0 <fgets@plt>
   0x08048887 <+356>:	lea    eax,[esp+0x1b8]
   0x0804888e <+363>:	mov    DWORD PTR [esp+0x14],0xffffffff
   0x08048896 <+371>:	mov    edx,eax
   0x08048898 <+373>:	mov    eax,0x0
   0x0804889d <+378>:	mov    ecx,DWORD PTR [esp+0x14]
   0x080488a1 <+382>:	mov    edi,edx
   0x080488a3 <+384>:	repnz scas al,BYTE PTR es:[edi]
   0x080488a5 <+386>:	mov    eax,ecx
   0x080488a7 <+388>:	not    eax
   0x080488a9 <+390>:	sub    eax,0x1
   0x080488ac <+393>:	sub    eax,0x1
   0x080488af <+396>:	mov    BYTE PTR [esp+eax*1+0x1b8],0x0
   0x080488b7 <+404>:	lea    eax,[esp+0x1b8]
   0x080488be <+411>:	mov    edx,eax
   0x080488c0 <+413>:	mov    eax,0x8048d5b
   0x080488c5 <+418>:	mov    ecx,0x5
   0x080488ca <+423>:	mov    esi,edx
   0x080488cc <+425>:	mov    edi,eax
   0x080488ce <+427>:	repz cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
   0x080488d0 <+429>:	seta   dl
   0x080488d3 <+432>:	setb   al
   0x080488d6 <+435>:	mov    ecx,edx
   0x080488d8 <+437>:	sub    cl,al
   0x080488da <+439>:	mov    eax,ecx
   0x080488dc <+441>:	movsx  eax,al
   0x080488df <+444>:	test   eax,eax
   0x080488e1 <+446>:	jne    0x80488f8 <main+469>
   0x080488e3 <+448>:	lea    eax,[esp+0x24]
   0x080488e7 <+452>:	mov    DWORD PTR [esp],eax
   0x080488ea <+455>:	call   0x8048630 <store_number>
   0x080488ef <+460>:	mov    DWORD PTR [esp+0x1b4],eax
   0x080488f6 <+467>:	jmp    0x8048965 <main+578>
   0x080488f8 <+469>:	lea    eax,[esp+0x1b8]
   0x080488ff <+476>:	mov    edx,eax
   0x08048901 <+478>:	mov    eax,0x8048d61
   0x08048906 <+483>:	mov    ecx,0x4
   0x0804890b <+488>:	mov    esi,edx
   0x0804890d <+490>:	mov    edi,eax
   0x0804890f <+492>:	repz cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
   0x08048911 <+494>:	seta   dl
   0x08048914 <+497>:	setb   al
   0x08048917 <+500>:	mov    ecx,edx
   0x08048919 <+502>:	sub    cl,al
   0x0804891b <+504>:	mov    eax,ecx
   0x0804891d <+506>:	movsx  eax,al
   0x08048920 <+509>:	test   eax,eax
   0x08048922 <+511>:	jne    0x8048939 <main+534>
   0x08048924 <+513>:	lea    eax,[esp+0x24]
   0x08048928 <+517>:	mov    DWORD PTR [esp],eax
   0x0804892b <+520>:	call   0x80486d7 <read_number>
   0x08048930 <+525>:	mov    DWORD PTR [esp+0x1b4],eax
   0x08048937 <+532>:	jmp    0x8048965 <main+578>
   0x08048939 <+534>:	lea    eax,[esp+0x1b8]
   0x08048940 <+541>:	mov    edx,eax
   0x08048942 <+543>:	mov    eax,0x8048d66
   0x08048947 <+548>:	mov    ecx,0x4
   0x0804894c <+553>:	mov    esi,edx
   0x0804894e <+555>:	mov    edi,eax
   0x08048950 <+557>:	repz cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
   0x08048952 <+559>:	seta   dl
   0x08048955 <+562>:	setb   al
   0x08048958 <+565>:	mov    ecx,edx
   0x0804895a <+567>:	sub    cl,al
   0x0804895c <+569>:	mov    eax,ecx
   0x0804895e <+571>:	movsx  eax,al
   0x08048961 <+574>:	test   eax,eax
   0x08048963 <+576>:	je     0x80489cf <main+684>
   0x08048965 <+578>:	cmp    DWORD PTR [esp+0x1b4],0x0
   0x0804896d <+586>:	je     0x8048989 <main+614>
   0x0804896f <+588>:	mov    eax,0x8048d6b
   0x08048974 <+593>:	lea    edx,[esp+0x1b8]
   0x0804897b <+600>:	mov    DWORD PTR [esp+0x4],edx
   0x0804897f <+604>:	mov    DWORD PTR [esp],eax
   0x08048982 <+607>:	call   0x8048470 <printf@plt>
   0x08048987 <+612>:	jmp    0x80489a1 <main+638>
   0x08048989 <+614>:	mov    eax,0x8048d88
   0x0804898e <+619>:	lea    edx,[esp+0x1b8]
   0x08048995 <+626>:	mov    DWORD PTR [esp+0x4],edx
   0x08048999 <+630>:	mov    DWORD PTR [esp],eax
   0x0804899c <+633>:	call   0x8048470 <printf@plt>
   0x080489a1 <+638>:	lea    eax,[esp+0x1b8]
   0x080489a8 <+645>:	mov    DWORD PTR [eax],0x0
   0x080489ae <+651>:	mov    DWORD PTR [eax+0x4],0x0
   0x080489b5 <+658>:	mov    DWORD PTR [eax+0x8],0x0
   0x080489bc <+665>:	mov    DWORD PTR [eax+0xc],0x0
   0x080489c3 <+672>:	mov    DWORD PTR [eax+0x10],0x0
   0x080489ca <+679>:	jmp    0x804884f <main+300>
   0x080489cf <+684>:	nop
   0x080489d0 <+685>:	mov    eax,0x0
   0x080489d5 <+690>:	mov    esi,DWORD PTR [esp+0x1cc]
   0x080489dc <+697>:	xor    esi,DWORD PTR gs:0x14
   0x080489e3 <+704>:	je     0x80489ea <main+711>
   0x080489e5 <+706>:	call   0x80484b0 <__stack_chk_fail@plt>
   0x080489ea <+711>:	lea    esp,[ebp-0xc]
   0x080489ed <+714>:	pop    ebx
   0x080489ee <+715>:	pop    esi
   0x080489ef <+716>:	pop    edi
   0x080489f0 <+717>:	pop    ebp
   0x080489f1 <+718>:	ret    
End of assembler dump.

```

### **Líneas 0 - 130:**
```asm
0x08048723 <+0>:	push   ebp
0x08048724 <+1>:	mov    ebp,esp
0x08048726 <+3>:	push   edi
0x08048727 <+4>:	push   esi
0x08048728 <+5>:	push   ebx
0x08048729 <+6>:	and    esp,0xfffffff0
0x0804872c <+9>:	sub    esp,0x1d0
0x08048732 <+15>:	mov    eax,DWORD PTR [ebp+0xc]
0x08048735 <+18>:	mov    DWORD PTR [esp+0x1c],eax
0x08048739 <+22>:	mov    eax,DWORD PTR [ebp+0x10]
0x0804873c <+25>:	mov    DWORD PTR [esp+0x18],eax
0x08048740 <+29>:	mov    eax,gs:0x14
0x08048746 <+35>:	mov    DWORD PTR [esp+0x1cc],eax
0x0804874d <+42>:	xor    eax,eax
0x0804874f <+44>:	mov    DWORD PTR [esp+0x1b4],0x0
0x0804875a <+55>:	mov    DWORD PTR [esp+0x1b8],0x0
0x08048765 <+66>:	mov    DWORD PTR [esp+0x1bc],0x0
0x08048770 <+77>:	mov    DWORD PTR [esp+0x1c0],0x0
0x0804877b <+88>:	mov    DWORD PTR [esp+0x1c4],0x0
0x08048786 <+99>:	mov    DWORD PTR [esp+0x1c8],0x0
0x08048791 <+110>:	lea    ebx,[esp+0x24]
0x08048795 <+114>:	mov    eax,0x0
0x0804879a <+119>:	mov    edx,0x64
0x0804879f <+124>:	mov    edi,ebx
0x080487a1 <+126>:	mov    ecx,edx
0x080487a3 <+128>:	rep stos DWORD PTR es:[edi],eax
0x080487a5 <+130>:	jmp    0x80487ea <main+199>
```

1.  <+0>: Guarda en lo alto del stack el valor de `EBP` (cpu) `[esp + 0x00]`. El `esp` se desplaza 4 bytes hacia abajo.
2.  <+1>: Asigna el nuevo `esp` a `ebp` para la función `main`.
3.  <+3>: Guarda en el stack el registro `EDI` — el compilador lo preserva porque lo usará internamente en `main()`.
4.  <+4>: Guarda en el stack el registro `ESI` — ídem.
5.  <+5>: Guarda en el stack el registro `EBX` — ídem.
6.  <+6>: Alinea el stack a múltiplo de 16. (los últimos 4 bytes se ponen a 0).
7.  <+9>: Reserva (desplaza) `464 bytes` (0x1d0) en el stack de `main()` para que el compilador organice las variables locales y los argumentos de las funciones que `main()` va a llamar.
8.  <+15>: Carga en `EAX` el segundo argumento de `main()` — `argv` — desde `[ebp+0xc]`.
9.  <+18>: Guarda `argv` en `[esp+0x1c]`.
10. <+22>: Carga en `EAX` el tercer argumento de `main()` — `envp` — desde `[ebp+0x10]`.
11. <+25>: Guarda `envp` en `[esp+0x18]`.
12. <+29>: Carga en `EAX` el valor del **Stack Canary** desde `gs:0x14`.
13. <+35>: Guarda el **Stack Canary** en `[esp+0x1cc]` — al final de la función se verificará que sigue intacto.
14. <+42>: Usa `XOR` para poner a 0 `EAX`.
15. <+44>: Inicializa a 0 la variable local en `[esp+0x1b4]`.
16. <+55>: Inicializa a 0 la variable local en `[esp+0x1b8]`.
17. <+66>: Inicializa a 0 la variable local en `[esp+0x1bc]`.
18. <+77>: Inicializa a 0 la variable local en `[esp+0x1c0]`.
19. <+88>: Inicializa a 0 la variable local en `[esp+0x1c4]`.
20. <+99>: Inicializa a 0 la variable local en `[esp+0x1c8]`.
21. <+110>: Calcula la dirección de `[esp+0x24]` que es el array `data` y la carga en `EBX`.
22. <+114>: Pone `EAX` a 0.
23. <+119>: Escribe `100` (0x64) en `EDX` — contador del `rep stos`.
24. <+124>: Copia la dirección de `data` en `EDI` — destino del `rep stos`.
25. <+126>: Copia el contador en `ECX`.
26. <+128>: **Es la versión de 32 bits del `memset`.**
```c
memset(data, 0, 100);
```
- `rep stos DWORD`: Escribe 4 bytes por iteración, 100 veces = `400 bytes` de ceros.
27. <+130>: `jmp` incondicional a `<+199>` — salta al bucle principal del programa.

### **Líneas 132 - 209:**
```asm
0x080487a7 <+132>:	mov    eax,DWORD PTR [esp+0x1c]
0x080487ab <+136>:	mov    eax,DWORD PTR [eax]
0x080487ad <+138>:	mov    DWORD PTR [esp+0x14],0xffffffff
0x080487b5 <+146>:	mov    edx,eax
0x080487b7 <+148>:	mov    eax,0x0
0x080487bc <+153>:	mov    ecx,DWORD PTR [esp+0x14]
0x080487c0 <+157>:	mov    edi,edx
0x080487c2 <+159>:	repnz scas al,BYTE PTR es:[edi]
0x080487c4 <+161>:	mov    eax,ecx
0x080487c6 <+163>:	not    eax
0x080487c8 <+165>:	lea    edx,[eax-0x1]
0x080487cb <+168>:	mov    eax,DWORD PTR [esp+0x1c]
0x080487cf <+172>:	mov    eax,DWORD PTR [eax]
0x080487d1 <+174>:	mov    DWORD PTR [esp+0x8],edx
0x080487d5 <+178>:	mov    DWORD PTR [esp+0x4],0x0
0x080487dd <+186>:	mov    DWORD PTR [esp],eax
0x080487e0 <+189>:	call   0x80484f0 <memset@plt>
0x080487e5 <+194>:	add    DWORD PTR [esp+0x1c],0x4
0x080487ea <+199>:	mov    eax,DWORD PTR [esp+0x1c]
0x080487ee <+203>:	mov    eax,DWORD PTR [eax]
0x080487f0 <+205>:	test   eax,eax
0x080487f2 <+207>:	jne    0x80487a7 <main+132>
0x080487f4 <+209>:	jmp    0x8048839 <main+278>
```

1.  <+132>: Carga en `EAX` el puntero `argv` almacenado en `[esp+0x1c]`.
2.  <+136>: Desreferencia — carga en `EAX` el valor de `argv[0]` (el nombre del programa).
3.  <+138>: Escribe `0xffffffff` en `[esp+0x14]` — inicializa el contador de `repnz scas` a -1.
4.  <+146>: Copia `argv[0]` en `EDX`.
5.  <+148>: Pone `EAX` a 0 — byte que buscará `repnz scas` (el terminador `\0`).
6.  <+153>: Carga `0xffffffff` en `ECX` — contador del bucle `repnz scas`.
7.  <+157>: Copia la dirección de `argv[0]` en `EDI` — destino de `repnz scas`.
8.  <+159>: `repnz scas` — recorre `argv[0]` byte a byte hasta encontrar el `\0`. Es el equivalente ensamblador de `strlen(argv[0])`.
9.  <+161>: Copia el resultado de `ECX` en `EAX`.
10. <+163>: Aplica `NOT EAX` — invierte todos los bits.
11. <+165>: `lea edx, [eax-1]` — obtiene la longitud real de `argv[0]` en `EDX`.
12. <+168>: Carga de nuevo `argv` en `EAX`.
13. <+172>: Desreferencia — carga `argv[0]` en `EAX`.
14. <+174>: Copia la longitud de `argv[0]` en `[esp+0x8]` — el **tercer argumento** de `memset()`.
15. <+178>: Escribe `0` en `[esp+0x4]` — el **segundo argumento** de `memset()`: el byte de relleno.
16. <+186>: Copia la dirección de `argv[0]` en `[esp]` — el **primer argumento** de `memset()`.
17. <+189>: Llama a `memset(argv[0], 0, strlen(argv[0]))` — borra `argv[0]` de la memoria.
18. <+194>: Avanza `argv` al siguiente puntero sumando 4 bytes — `argv++`.
19. <+199>: Carga en `EAX` el puntero `argv` actualizado.
20. <+203>: Desreferencia — carga el siguiente argumento.
21. <+205>: Comprueba si el argumento es NULL.
22. <+207>: `jne` — si no es NULL vuelve a `<+132>` para borrar el siguiente argumento.
23. <+209>: `jmp` incondicional a `<+278>` — todos los argumentos han sido borrados, continúa el programa.

### **Líneas 211 - 286:**
```asm
 0x080487f6 <+211>:	mov    eax,DWORD PTR [esp+0x18]
0x080487fa <+215>:	mov    eax,DWORD PTR [eax]
0x080487fc <+217>:	mov    DWORD PTR [esp+0x14],0xffffffff
0x08048804 <+225>:	mov    edx,eax
0x08048806 <+227>:	mov    eax,0x0
0x0804880b <+232>:	mov    ecx,DWORD PTR [esp+0x14]
0x0804880f <+236>:	mov    edi,edx
0x08048811 <+238>:	repnz scas al,BYTE PTR es:[edi]
0x08048813 <+240>:	mov    eax,ecx
0x08048815 <+242>:	not    eax
0x08048817 <+244>:	lea    edx,[eax-0x1]
0x0804881a <+247>:	mov    eax,DWORD PTR [esp+0x18]
0x0804881e <+251>:	mov    eax,DWORD PTR [eax]
0x08048820 <+253>:	mov    DWORD PTR [esp+0x8],edx
0x08048824 <+257>:	mov    DWORD PTR [esp+0x4],0x0
0x0804882c <+265>:	mov    DWORD PTR [esp],eax
0x0804882f <+268>:	call   0x80484f0 <memset@plt>
0x08048834 <+273>:	add    DWORD PTR [esp+0x18],0x4
0x08048839 <+278>:	mov    eax,DWORD PTR [esp+0x18]
0x0804883d <+282>:	mov    eax,DWORD PTR [eax]
0x0804883f <+284>:	test   eax,eax
0x08048841 <+286>:	jne    0x80487f6 <main+211>
```

1.  <+211>: Carga en `EAX` el puntero `envp` almacenado en `[esp+0x18]`.
2.  <+215>: Desreferencia — carga en `EAX` el valor de `envp[0]` (primera variable de entorno).
3.  <+217>: Escribe `0xffffffff` en `[esp+0x14]` — inicializa el contador de `repnz scas` a -1.
4.  <+225>: Copia `envp[0]` en `EDX`.
5.  <+227>: Pone `EAX` a 0 — byte que buscará `repnz scas` (el terminador `\0`).
6.  <+232>: Carga `0xffffffff` en `ECX` — contador del bucle `repnz scas`.
7.  <+236>: Copia la dirección de `envp[0]` en `EDI` — destino de `repnz scas`.
8.  <+238>: `repnz scas` — recorre `envp[0]` byte a byte hasta encontrar el `\0`. Es el equivalente ensamblador de `strlen(envp[0])`.
9.  <+240>: Copia el resultado de `ECX` en `EAX`.
10. <+242>: Aplica `NOT EAX` — invierte todos los bits.
11. <+244>: `lea edx, [eax-1]` — obtiene la longitud real de `envp[0]` en `EDX`.
12. <+247>: Carga de nuevo `envp` en `EAX`.
13. <+251>: Desreferencia — carga `envp[0]` en `EAX`.
14. <+253>: Copia la longitud de `envp[0]` en `[esp+0x8]` — el **tercer argumento** de `memset()`.
15. <+257>: Escribe `0` en `[esp+0x4]` — el **segundo argumento** de `memset()`: el byte de relleno.
16. <+265>: Copia la dirección de `envp[0]` en `[esp]` — el **primer argumento** de `memset()`.
17. <+268>: Llama a `memset(*envp, 0, strlen(*envp))` — borra la variable de entorno actual.
18. <+273>: Avanza `envp` al siguiente puntero sumando 4 bytes — `envp++`.
19. <+278>: Carga en `EAX` el puntero `envp` actualizado.
20. <+282>: Desreferencia — carga la siguiente variable de entorno.
21. <+284>: Comprueba si es NULL.
22. <+286>: `jne` — si no es NULL vuelve a `<+211>` para borrar la siguiente variable de entorno.

### **Líneas 288, 295, 300, 305, 308, 313, 324, 329, 333, 341, 348 y 351:**
```asm
0x08048843 <+288>:	mov    DWORD PTR [esp],0x8048b38
0x0804884a <+295>:	call   0x80484c0 <puts@plt>
0x0804884f <+300>:	mov    eax,0x8048d4b
0x08048854 <+305>:	mov    DWORD PTR [esp],eax
0x08048857 <+308>:	call   0x8048470 <printf@plt>
0x0804885c <+313>:	mov    DWORD PTR [esp+0x1b4],0x1
0x08048867 <+324>:	mov    eax,ds:0x804a040
0x0804886c <+329>:	mov    DWORD PTR [esp+0x8],eax
0x08048870 <+333>:	mov    DWORD PTR [esp+0x4],0x14
0x08048878 <+341>:	lea    eax,[esp+0x1b8]
0x0804887f <+348>:	mov    DWORD PTR [esp],eax
0x08048882 <+351>:	call   0x80484a0 <fgets@plt>
```

1.  <+288>: Copia en lo alto del stack la dirección `0x8048b38` como argumento para `puts()`:
```bash
(gdb) x/s 0x8048b38
0x8048b38:    '-' <repeats 52 times>, "\n  Welcome to wil's crappy number storage service!..."
```
2.  <+295>: Llama a `puts()` — imprime la cabecera del programa.
3.  <+300>: Carga en `EAX` la dirección del string `"Input command: "` que se encuentra en `0x8048d4b`.
4.  <+305>: Copia en lo alto del stack la dirección de `"Input command: "` — argumento de `printf()`.
```bash
(gdb) x/s 0x8048d4b
0x8048d4b:	 "Input command: "
```
5.  <+308>: Llama a `printf("Input command: ")`.
6.  <+313>: Escribe `1` en `[esp+0x1b4]` — inicializa el contador del bucle principal a 1.
7.  <+324>: Carga en `EAX` el puntero al stream `stdin` — será el **tercer argumento** de `fgets()`.
8.  <+329>: Copia `stdin` en `[esp+0x8]` — el **tercer argumento** de `fgets()`: el stream de lectura.
9.  <+333>: Escribe `20` (0x14) en `[esp+0x4]` — el **segundo argumento** de `fgets()`: número máximo de bytes a leer.
10. <+341>: Calcula la dirección de `[esp+0x1b8]` que es la variable local `cmd` y la carga en `EAX`.
11. <+348>: Copia la dirección de `cmd` en lo alto del stack — el **primer argumento** de `fgets()`.
12. <+351>: Llama a `fgets(cmd, 20, stdin)` — lee el comando introducido por el usuario.

### **Líneas 356 - 446:**
```asm
0x08048887 <+356>:	lea    eax,[esp+0x1b8]
0x0804888e <+363>:	mov    DWORD PTR [esp+0x14],0xffffffff
0x08048896 <+371>:	mov    edx,eax
0x08048898 <+373>:	mov    eax,0x0
0x0804889d <+378>:	mov    ecx,DWORD PTR [esp+0x14]
0x080488a1 <+382>:	mov    edi,edx
0x080488a3 <+384>:	repnz scas al,BYTE PTR es:[edi]
0x080488a5 <+386>:	mov    eax,ecx
0x080488a7 <+388>:	not    eax
0x080488a9 <+390>:	sub    eax,0x1
0x080488ac <+393>:	sub    eax,0x1
0x080488af <+396>:	mov    BYTE PTR [esp+eax*1+0x1b8],0x0
0x080488b7 <+404>:	lea    eax,[esp+0x1b8]
0x080488be <+411>:	mov    edx,eax
0x080488c0 <+413>:	mov    eax,0x8048d5b
0x080488c5 <+418>:	mov    ecx,0x5
0x080488ca <+423>:	mov    esi,edx
0x080488cc <+425>:	mov    edi,eax
0x080488ce <+427>:	repz cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
0x080488d0 <+429>:	seta   dl
0x080488d3 <+432>:	setb   al
0x080488d6 <+435>:	mov    ecx,edx
0x080488d8 <+437>:	sub    cl,al
0x080488da <+439>:	mov    eax,ecx
0x080488dc <+441>:	movsx  eax,al
0x080488df <+444>:	test   eax,eax
0x080488e1 <+446>:	jne    0x80488f8 <main+469>
```

1.  <+356>: Calcula la dirección de `[esp+0x1b8]` que es la variable local `cmd` y la carga en `EAX`.
2.  <+363>: Escribe `0xffffffff` en `[esp+0x14]` — inicializa el contador de `repnz scas` a -1.
3.  <+371>: Copia la dirección de `cmd` en `EDX`.
4.  <+373>: Pone `EAX` a 0 — byte que buscará `repnz scas` (el terminador `\0`).
5.  <+378>: Carga `0xffffffff` en `ECX` — contador del bucle `repnz scas`.
6.  <+382>: Copia la dirección de `cmd` en `EDI` — destino de `repnz scas`.
7.  <+384>: `repnz scas` — recorre `cmd` byte a byte hasta encontrar el `\0`. Es el equivalente ensamblador de `strlen(cmd)`.
8.  <+386>: Copia el resultado de `ECX` en `EAX`.
9.  <+388>: Aplica `NOT EAX` — invierte todos los bits.
10. <+390>: Resta 1 a `EAX`.
11. <+393>: Resta 1 a `EAX` de nuevo — obtiene `strlen(cmd) - 2` para apuntar al `\n`.
12. <+396>: Escribe `\0` en `cmd[strlen(cmd)-2]` — elimina el `\n` final del comando:
```c
cmd[strlen(cmd) - 1] = '\0';
```
13. <+404>: Calcula de nuevo la dirección de `cmd` y la carga en `EAX`.
14. <+411>: Copia `cmd` en `EDX`.
15. <+413>: Carga en `EAX` la dirección del string `"store"` que se encuentra en `0x8048d5b`.
```bash
(gdb) x/s 0x8048d5b
0x8048d5b:	 "store"
```
16. <+418>: Carga `5` en `ECX` — número de bytes a comparar.
17. <+423>: Copia `cmd` en `ESI` — primer argumento de `repz cmps`.
18. <+425>: Copia `"store"` en `EDI` — segundo argumento de `repz cmps`.
19. <+427>: `repz cmps` — compara `cmd` con `"store"` durante 5 bytes. Es el equivalente ensamblador de `strncmp(cmd, "store", 5)`.
20. <+429>: `seta dl` — pone `DL` a 1 si `cmd > "store"`.
21. <+432>: `setb al` — pone `AL` a 1 si `cmd < "store"`.
22. <+435>: Copia `DL` en `ECX`.
23. <+437>: Resta `AL` a `CL` — obtiene el resultado de la comparación.
24. <+439>: Copia el resultado en `EAX`.
25. <+441>: Extiende el signo a 32 bits.
26. <+444>: Comprueba si el resultado es 0.
27. <+446>: `jne` — si `cmd != "store"` salta a `<+469>` para comprobar el siguiente comando.

### **Líneas 448 - 511:**
```asm
0x080488e3 <+448>:	lea    eax,[esp+0x24]
0x080488e7 <+452>:	mov    DWORD PTR [esp],eax
0x080488ea <+455>:	call   0x8048630 <store_number>
0x080488ef <+460>:	mov    DWORD PTR [esp+0x1b4],eax
0x080488f6 <+467>:	jmp    0x8048965 <main+578>
0x080488f8 <+469>:	lea    eax,[esp+0x1b8]
0x080488ff <+476>:	mov    edx,eax
0x08048901 <+478>:	mov    eax,0x8048d61
0x08048906 <+483>:	mov    ecx,0x4
0x0804890b <+488>:	mov    esi,edx
0x0804890d <+490>:	mov    edi,eax
0x0804890f <+492>:	repz cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
0x08048911 <+494>:	seta   dl
0x08048914 <+497>:	setb   al
0x08048917 <+500>:	mov    ecx,edx
0x08048919 <+502>:	sub    cl,al
0x0804891b <+504>:	mov    eax,ecx
0x0804891d <+506>:	movsx  eax,al
0x08048920 <+509>:	test   eax,eax
0x08048922 <+511>:	jne    0x8048939 <main+534>
```

1.  <+448>: Calcula la dirección de `[esp+0x24]` que es el array `data` y la carga en `EAX`.
2.  <+452>: Copia la dirección de `data` en lo alto del stack — único argumento de `store_number()`.
3.  <+455>: Llama a `store_number(data)`.
4.  <+460>: Guarda el valor de retorno de `store_number()` en `running` `[esp+0x1b4]`.
5.  <+467>: `jmp` incondicional a `<+578>` — salta al final del bucle.
6.  <+469>: Calcula de nuevo la dirección de `cmd` y la carga en `EAX`.
7.  <+476>: Copia `cmd` en `EDX`.
8.  <+478>: Carga en `EAX` la dirección del string `"read"` que se encuentra en `0x8048d61`.
```bash
(gdb) x/s 0x8048d61
0x8048d61:	 "read"
```
9.  <+483>: Carga `4` en `ECX` — número de bytes a comparar.
10. <+488>: Copia `cmd` en `ESI` — primer argumento de `repz cmps`.
11. <+490>: Copia `"read"` en `EDI` — segundo argumento de `repz cmps`.
12. <+492>: `repz cmps` — compara `cmd` con `"read"` durante 4 bytes. Es el equivalente ensamblador de `strncmp(cmd, "read", 4)`.
13. <+494>: `seta dl` — pone `DL` a 1 si `cmd > "read"`.
14. <+497>: `setb al` — pone `AL` a 1 si `cmd < "read"`.
15. <+500>: Copia `DL` en `ECX`.
16. <+502>: Resta `AL` a `CL` — obtiene el resultado de la comparación.
17. <+504>: Copia el resultado en `EAX`.
18. <+506>: Extiende el signo a 32 bits.
19. <+509>: Comprueba si el resultado es 0.
20. <+511>: `jne` — si `cmd != "read"` salta a `<+534>` para comprobar el siguiente comando.

### **Líneas 513 - 576:**
```asm
0x08048924 <+513>:	lea    eax,[esp+0x24]
0x08048928 <+517>:	mov    DWORD PTR [esp],eax
0x0804892b <+520>:	call   0x80486d7 <read_number>
0x08048930 <+525>:	mov    DWORD PTR [esp+0x1b4],eax
0x08048937 <+532>:	jmp    0x8048965 <main+578>
0x08048939 <+534>:	lea    eax,[esp+0x1b8]
0x08048940 <+541>:	mov    edx,eax
0x08048942 <+543>:	mov    eax,0x8048d66
0x08048947 <+548>:	mov    ecx,0x4
0x0804894c <+553>:	mov    esi,edx
0x0804894e <+555>:	mov    edi,eax
0x08048950 <+557>:	repz cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
0x08048952 <+559>:	seta   dl
0x08048955 <+562>:	setb   al
0x08048958 <+565>:	mov    ecx,edx
0x0804895a <+567>:	sub    cl,al
0x0804895c <+569>:	mov    eax,ecx
0x0804895e <+571>:	movsx  eax,al
0x08048961 <+574>:	test   eax,eax
0x08048963 <+576>:	je     0x80489cf <main+684>
```

1.  <+513>: Calcula la dirección de `[esp+0x24]` que es el array `data` y la carga en `EAX`.
2.  <+517>: Copia la dirección de `data` en lo alto del stack — único argumento de `read_number()`.
3.  <+520>: Llama a `read_number(data)`.
4.  <+525>: Guarda el valor de retorno de `read_number()` en `running` `[esp+0x1b4]`.
5.  <+532>: `jmp` incondicional a `<+578>` — salta al final del bucle.
6.  <+534>: Calcula de nuevo la dirección de `cmd` y la carga en `EAX`.
7.  <+541>: Copia `cmd` en `EDX`.
8.  <+543>: Carga en `EAX` la dirección del string `"quit"` que se encuentra en `0x8048d66`.
```bash
(gdb) x/s 0x8048d66
0x8048d66:	 "quit"
```
9.  <+548>: Carga `4` en `ECX` — número de bytes a comparar.
10. <+553>: Copia `cmd` en `ESI` — primer argumento de `repz cmps`.
11. <+555>: Copia `"quit"` en `EDI` — segundo argumento de `repz cmps`.
12. <+557>: `repz cmps` — compara `cmd` con `"quit"` durante 4 bytes. Es el equivalente ensamblador de `strncmp(cmd, "quit", 4)`.
13. <+559>: `seta dl` — pone `DL` a 1 si `cmd > "quit"`.
14. <+562>: `setb al` — pone `AL` a 1 si `cmd < "quit"`.
15. <+565>: Copia `DL` en `ECX`.
16. <+567>: Resta `AL` a `CL` — obtiene el resultado de la comparación.
17. <+569>: Copia el resultado en `EAX`.
18. <+571>: Extiende el signo a 32 bits.
19. <+574>: Comprueba si el resultado es 0.
20. <+576>: `je` — si `cmd == "quit"` salta a `<+684>` (bloque de salida).

### **Líneas 578, 586, 588, 593, 600, 604, 607, 612, 614, 619, 626, 630, 633, 638, 645, 651, 658, 665, 672 y 679:**
```asm
0x08048965 <+578>:	cmp    DWORD PTR [esp+0x1b4],0x0
0x0804896d <+586>:	je     0x8048989 <main+614>
0x0804896f <+588>:	mov    eax,0x8048d6b
0x08048974 <+593>:	lea    edx,[esp+0x1b8]
0x0804897b <+600>:	mov    DWORD PTR [esp+0x4],edx
0x0804897f <+604>:	mov    DWORD PTR [esp],eax
0x08048982 <+607>:	call   0x8048470 <printf@plt>
0x08048987 <+612>:	jmp    0x80489a1 <main+638>
0x08048989 <+614>:	mov    eax,0x8048d88
0x0804898e <+619>:	lea    edx,[esp+0x1b8]
0x08048995 <+626>:	mov    DWORD PTR [esp+0x4],edx
0x08048999 <+630>:	mov    DWORD PTR [esp],eax
0x0804899c <+633>:	call   0x8048470 <printf@plt>
0x080489a1 <+638>:	lea    eax,[esp+0x1b8]
0x080489a8 <+645>:	mov    DWORD PTR [eax],0x0
0x080489ae <+651>:	mov    DWORD PTR [eax+0x4],0x0
0x080489b5 <+658>:	mov    DWORD PTR [eax+0x8],0x0
0x080489bc <+665>:	mov    DWORD PTR [eax+0xc],0x0
0x080489c3 <+672>:	mov    DWORD PTR [eax+0x10],0x0
0x080489ca <+679>:	jmp    0x804884f <main+300>
```

1.  <+578>: Compara `running` en `[esp+0x1b4]` con 0.
2.  <+586>: `je` — si `running == 0` (comando ejecutado con éxito) salta a `<+614>`.
3.  <+588>: Carga en `EAX` la dirección del string `" Failed to do %s command\n"` en `0x8048d6b`.
```bash
(gdb) x/s 0x8048d6b
0x8048d6b:	 " Failed to do %s command\n"
```
4.  <+593>: Calcula la dirección de `cmd` en `[esp+0x1b8]` y la carga en `EDX`.
5.  <+600>: Copia `cmd` en `[esp+0x4]` — el **segundo argumento** de `printf()`.
6.  <+604>: Copia el formato en lo alto del stack — el **primer argumento** de `printf()`.
7.  <+607>: Llama a `printf(" Failed to do %s command\n", cmd)`.
8.  <+612>: `jmp` incondicional a `<+638>` — salta al reset del comando.
9.  <+614>: Carga en `EAX` la dirección del string `" Completed %s command successfully\n"` en `0x8048d88`.
```bash
(gdb) x/s 0x8048d88
0x8048d88:	 " Completed %s command successfully\n"
```
10. <+619>: Calcula la dirección de `cmd` y la carga en `EDX`.
11. <+626>: Copia `cmd` en `[esp+0x4]` — el **segundo argumento** de `printf()`.
12. <+630>: Copia el formato en lo alto del stack — el **primer argumento** de `printf()`.
13. <+633>: Llama a `printf(" Completed %s command successfully\n", cmd)`.
14. <+638>: Calcula la dirección de `cmd` en `[esp+0x1b8]` y la carga en `EAX`.
15. <+645>: Escribe `0` en `cmd[0..3]` — borra los primeros 4 bytes de `cmd`.
16. <+651>: Escribe `0` en `cmd[4..7]`.
17. <+658>: Escribe `0` en `cmd[8..11]`.
18. <+665>: Escribe `0` en `cmd[12..15]`.
19. <+672>: Escribe `0` en `cmd[16..19]` — `cmd` queda completamente a ceros.
20. <+679>: `jmp` incondicional a `<+300>` — vuelve al inicio del bucle para leer el siguiente comando.

### **Líneas 684, 685, 690, 697, 704, 706, 711, 714, 715, 716, 717 y 718:**
```asm
0x080489cf <+684>:	nop
0x080489d0 <+685>:	mov    eax,0x0
0x080489d5 <+690>:	mov    esi,DWORD PTR [esp+0x1cc]
0x080489dc <+697>:	xor    esi,DWORD PTR gs:0x14
0x080489e3 <+704>:	je     0x80489ea <main+711>
0x080489e5 <+706>:	call   0x80484b0 <__stack_chk_fail@plt>
0x080489ea <+711>:	lea    esp,[ebp-0xc]
0x080489ed <+714>:	pop    ebx
0x080489ee <+715>:	pop    esi
0x080489ef <+716>:	pop    edi
0x080489f0 <+717>:	pop    ebp
0x080489f1 <+718>:	ret    
```

1.  <+684>: `nop` — instrucción vacía. Artefacto del compilador.
2.  <+685>: Pone `EAX` a 0 — valor de retorno de `main()`.
3.  <+690>: Carga en `ESI` el **Stack Canary** guardado en `[esp+0x1cc]` al inicio de la función.
4.  <+697>: Aplica `XOR` entre el canary guardado y el canary original de `gs:0x14` — si el stack no fue corrompido el resultado es 0.
5.  <+704>: `je` — si el resultado es 0 (canaries coinciden) salta a `<+711>` y termina normalmente.
6.  <+706>: Si el canary fue corrompido llama a `__stack_chk_fail@plt` — aborta el programa.
7.  <+711>: Restaura `ESP` desde `[ebp-0xc]` — libera el stack frame.
8.  <+714>: Restaura el registro `EBX`.
9.  <+715>: Restaura el registro `ESI`.
10. <+716>: Restaura el registro `EDI`.
11. <+717>: Restaura el `EBP` del caller.
12. <+718>: `ret` — retorna el control al sistema.

# **ANÁLISIS COMPLETO LÍNEA POR LÍNEA - función read_number**

```asm
Dump of assembler code for function read_number:
   0x080486d7 <+0>:	push   ebp
   0x080486d8 <+1>:	mov    ebp,esp
   0x080486da <+3>:	sub    esp,0x28
   0x080486dd <+6>:	mov    DWORD PTR [ebp-0xc],0x0
   0x080486e4 <+13>:	mov    eax,0x8048add
   0x080486e9 <+18>:	mov    DWORD PTR [esp],eax
   0x080486ec <+21>:	call   0x8048470 <printf@plt>
   0x080486f1 <+26>:	call   0x80485e7 <get_unum>
   0x080486f6 <+31>:	mov    DWORD PTR [ebp-0xc],eax
   0x080486f9 <+34>:	mov    eax,DWORD PTR [ebp-0xc]
   0x080486fc <+37>:	shl    eax,0x2
   0x080486ff <+40>:	add    eax,DWORD PTR [ebp+0x8]
   0x08048702 <+43>:	mov    edx,DWORD PTR [eax]
   0x08048704 <+45>:	mov    eax,0x8048b1b
   0x08048709 <+50>:	mov    DWORD PTR [esp+0x8],edx
   0x0804870d <+54>:	mov    edx,DWORD PTR [ebp-0xc]
   0x08048710 <+57>:	mov    DWORD PTR [esp+0x4],edx
   0x08048714 <+61>:	mov    DWORD PTR [esp],eax
   0x08048717 <+64>:	call   0x8048470 <printf@plt>
   0x0804871c <+69>:	mov    eax,0x0
   0x08048721 <+74>:	leave  
   0x08048722 <+75>:	ret    
End of assembler dump.
```

### **Líneas 0, 1, 3, 6, 13, 18, 21, 26, 31, 34, 37, 40, 43, 45, 50, 54, 57, 61, 64, 69, 74 y 75:**

1.  <+0>: Guarda en lo alto del stack el valor de `EBP` (función `main`) `[esp + 0x00]`. El registro `ESP` se desplaza 4 bytes.
2.  <+1>: Asigna a `EBP` el nuevo `ESP` para la función `read_number()`.
3.  <+3>: Reserva (desplaza) `40 bytes` (0x28) en el stack de `read_number()`.
4.  <+6>: Inicializa a 0 la variable local `index` en `[ebp-0xc]`.
5.  <+13>: Carga en `EAX` la dirección del string `" Index: "` que se encuentra en `0x8048add`.
```bash
(gdb) x/s 0x8048add
0x8048add:	 " Index: "
```
6.  <+18>: Copia en lo alto del stack la dirección de `" Index: "` — argumento de `printf()`.
7.  <+21>: Llama a `printf(" Index: ")`.
8.  <+26>: Llama a `get_unum()` — lee un número sin signo introducido por el usuario y lo devuelve en `EAX`.
9.  <+31>: Guarda el índice devuelto por `get_unum()` en `index` `[ebp-0xc]`.
10. <+34>: Carga `index` en `EAX`.
11. <+37>: `shl eax, 0x2` — multiplica `index` por 4 (`index * 4`). Cada elemento del array ocupa 4 bytes.
12. <+40>: Suma la dirección base de `data` (`[ebp+0x8]`) — calcula `&data[index]`.
13. <+43>: Carga en `EDX` el valor almacenado en `data[index]`.
14. <+45>: Carga en `EAX` la dirección del formato `" Number at data[%u] is %u\n"` en `0x8048b1b`.
```bash
(gdb) x/s 0x8048b1b
0x8048b1b:	 " Number at data[%u] is %u\n"
```
15. <+50>: Copia el valor de `data[index]` en `[esp+0x8]` — el **tercer argumento** de `printf()`.
16. <+54>: Carga `index` en `EDX`.
17. <+57>: Copia `index` en `[esp+0x4]` — el **segundo argumento** de `printf()`.
18. <+61>: Copia el formato en lo alto del stack — el **primer argumento** de `printf()`.
19. <+64>: Llama a `printf(" Number at data[%u] is %u\n", index, data[index])`.
20. <+69>: Pone `EAX` a 0 — valor de retorno: éxito.
21. <+74>: `leave` — restaura el stack frame.
22. <+75>: `ret` — retorna el control a `main()`.


# **ANÁLISIS COMPLETO LÍNEA POR LÍNEA - función store_number**

```asm
Dump of assembler code for function store_number:
   0x08048630 <+0>:	push   ebp
   0x08048631 <+1>:	mov    ebp,esp
   0x08048633 <+3>:	sub    esp,0x28
   0x08048636 <+6>:	mov    DWORD PTR [ebp-0x10],0x0
   0x0804863d <+13>:	mov    DWORD PTR [ebp-0xc],0x0
   0x08048644 <+20>:	mov    eax,0x8048ad3
   0x08048649 <+25>:	mov    DWORD PTR [esp],eax
   0x0804864c <+28>:	call   0x8048470 <printf@plt>
   0x08048651 <+33>:	call   0x80485e7 <get_unum>
   0x08048656 <+38>:	mov    DWORD PTR [ebp-0x10],eax
   0x08048659 <+41>:	mov    eax,0x8048add
   0x0804865e <+46>:	mov    DWORD PTR [esp],eax
   0x08048661 <+49>:	call   0x8048470 <printf@plt>
   0x08048666 <+54>:	call   0x80485e7 <get_unum>
   0x0804866b <+59>:	mov    DWORD PTR [ebp-0xc],eax
   0x0804866e <+62>:	mov    ecx,DWORD PTR [ebp-0xc]
   0x08048671 <+65>:	mov    edx,0xaaaaaaab
   0x08048676 <+70>:	mov    eax,ecx
   0x08048678 <+72>:	mul    edx
   0x0804867a <+74>:	shr    edx,1
   0x0804867c <+76>:	mov    eax,edx
   0x0804867e <+78>:	add    eax,eax
   0x08048680 <+80>:	add    eax,edx
   0x08048682 <+82>:	mov    edx,ecx
   0x08048684 <+84>:	sub    edx,eax
   0x08048686 <+86>:	test   edx,edx
   0x08048688 <+88>:	je     0x8048697 <store_number+103>
   0x0804868a <+90>:	mov    eax,DWORD PTR [ebp-0x10]
   0x0804868d <+93>:	shr    eax,0x18
   0x08048690 <+96>:	cmp    eax,0xb7
   0x08048695 <+101>:	jne    0x80486c2 <store_number+146>
   0x08048697 <+103>:	mov    DWORD PTR [esp],0x8048ae6
   0x0804869e <+110>:	call   0x80484c0 <puts@plt>
   0x080486a3 <+115>:	mov    DWORD PTR [esp],0x8048af8
   0x080486aa <+122>:	call   0x80484c0 <puts@plt>
   0x080486af <+127>:	mov    DWORD PTR [esp],0x8048ae6
   0x080486b6 <+134>:	call   0x80484c0 <puts@plt>
   0x080486bb <+139>:	mov    eax,0x1
   0x080486c0 <+144>:	jmp    0x80486d5 <store_number+165>
   0x080486c2 <+146>:	mov    eax,DWORD PTR [ebp-0xc]
   0x080486c5 <+149>:	shl    eax,0x2
   0x080486c8 <+152>:	add    eax,DWORD PTR [ebp+0x8]
   0x080486cb <+155>:	mov    edx,DWORD PTR [ebp-0x10]
   0x080486ce <+158>:	mov    DWORD PTR [eax],edx
   0x080486d0 <+160>:	mov    eax,0x0
   0x080486d5 <+165>:	leave  
   0x080486d6 <+166>:	ret    
End of assembler dump.
```

### **Líneas 0, 1, 3, 6, 13, 20, 25, 28, 33, 38, 41, 46, 49, 54, 59:**
```asm
0x08048630 <+0>:	push   ebp
0x08048631 <+1>:	mov    ebp,esp
0x08048633 <+3>:	sub    esp,0x28
0x08048636 <+6>:	mov    DWORD PTR [ebp-0x10],0x0
0x0804863d <+13>:	mov    DWORD PTR [ebp-0xc],0x0
0x08048644 <+20>:	mov    eax,0x8048ad3
0x08048649 <+25>:	mov    DWORD PTR [esp],eax
0x0804864c <+28>:	call   0x8048470 <printf@plt>
0x08048651 <+33>:	call   0x80485e7 <get_unum>
0x08048656 <+38>:	mov    DWORD PTR [ebp-0x10],eax
0x08048659 <+41>:	mov    eax,0x8048add
0x0804865e <+46>:	mov    DWORD PTR [esp],eax
0x08048661 <+49>:	call   0x8048470 <printf@plt>
0x08048666 <+54>:	call   0x80485e7 <get_unum>
0x0804866b <+59>:	mov    DWORD PTR [ebp-0xc],eax
```

1.  <+0>: Guarda en lo alto del stack el valor de `EBP` (función `main`) `[esp + 0x00]`. El registro `ESP` se desplaza 4 bytes.
2.  <+1>: Asigna a `EBP` el nuevo `ESP` para la función `store_number()`.
3.  <+3>: Reserva (desplaza) `40 bytes` (0x28) en el stack de `store_number()`.
4.  <+6>: Inicializa a 0 la variable local `number` en `[ebp-0x10]`.
5.  <+13>: Inicializa a 0 la variable local `index` en `[ebp-0xc]`.
6.  <+20>: Carga en `EAX` la dirección del string `" Number: "` en `0x8048ad3`.
```bash
(gdb) x/s 0x8048ad3
0x8048ad3:	 " Number: "
```
7.  <+25>: Copia en lo alto del stack — argumento de `printf()`.
8.  <+28>: Llama a `printf(" Number: ")`.
9.  <+33>: Llama a `get_unum()` — lee el número introducido por el usuario.
10. <+38>: Guarda el número en `number` `[ebp-0x10]`.
11. <+41>: Carga en `EAX` la dirección del string `" Index: "` en `0x8048add`.
```bash
(gdb) x/s 0x8048add
0x8048add:	 " Index: "
```
12. <+46>: Copia en lo alto del stack — argumento de `printf()`.
13. <+49>: Llama a `printf(" Index: ")`.
14. <+54>: Llama a `get_unum()` — lee el índice introducido por el usuario.
15. <+59>: Guarda el índice en `index` `[ebp-0xc]`.

### **Líneas 62, 65, 70, 72, 74, 76, 78, 80, 82, 84, 86 y 88:**
```asm
0x0804866e <+62>:	mov    ecx,DWORD PTR [ebp-0xc]
0x08048671 <+65>:	mov    edx,0xaaaaaaab
0x08048676 <+70>:	mov    eax,ecx
0x08048678 <+72>:	mul    edx
0x0804867a <+74>:	shr    edx,1
0x0804867c <+76>:	mov    eax,edx
0x0804867e <+78>:	add    eax,eax
0x08048680 <+80>:	add    eax,edx
0x08048682 <+82>:	mov    edx,ecx
0x08048684 <+84>:	sub    edx,eax
0x08048686 <+86>:	test   edx,edx
0x08048688 <+88>:	je     0x8048697 <store_number+103>
```

1.  <+62>: Carga `index` en `ECX`.
2.  <+65>: Carga la constante `0xaaaaaaab` en `EDX` — constante de la división entera por 3.
3.  <+70>: Copia `index` en `EAX`.
4.  <+72>: Multiplica `EAX` por `EDX` — parte de la operación `index % 3`.
5.  <+74>: `shr edx, 1` — desplazamiento derecha 1 bit.
6.  <+76>: Copia `EDX` en `EAX`.
7.  <+78>: `add eax, eax` — multiplica por 2.
8.  <+80>: Suma `EDX` a `EAX` — `eax = index / 3 * 3`.
9.  <+82>: Copia `index` en `EDX`.
10. <+84>: Resta `EAX` a `EDX` — obtiene `index % 3`.
11. <+86>: Comprueba si `index % 3 == 0`.
12. <+88>: `je` — si `index % 3 == 0` salta a `<+103>` (índice reservado).

### **Líneas 90, 93, 96 y 101:**
```asm
0x0804868a <+90>:	mov    eax,DWORD PTR [ebp-0x10]
0x0804868d <+93>:	shr    eax,0x18
0x08048690 <+96>:	cmp    eax,0xb7
0x08048695 <+101>:	jne    0x80486c2 <store_number+146>
```

1.  <+90>: Carga `number` en `EAX`.
2.  <+93>: `shr eax, 0x18` — desplazamiento derecha 24 bits — obtiene el byte más significativo de `number`.
3.  <+96>: Compara el byte más significativo con `0xb7`.
4.  <+101>: `jne` — si el byte más significativo **no es** `0xb7` salta a `<+146>` y almacena el número.

### **Líneas 103, 110, 115, 122, 127, 134, 139 y 144:**
```asm
0x08048697 <+103>:	mov    DWORD PTR [esp],0x8048ae6
0x0804869e <+110>:	call   0x80484c0 <puts@plt>
0x080486a3 <+115>:	mov    DWORD PTR [esp],0x8048af8
0x080486aa <+122>:	call   0x80484c0 <puts@plt>
0x080486af <+127>:	mov    DWORD PTR [esp],0x8048ae6
0x080486b6 <+134>:	call   0x80484c0 <puts@plt>
0x080486bb <+139>:	mov    eax,0x1
0x080486c0 <+144>:	jmp    0x80486d5 <store_number+165>
```

1.  <+103>: Carga en lo alto del stack la dirección de `" *** ERROR! ***"` en `0x8048ae6`.
```bash
(gdb) x/s 0x8048ae6
0x8048ae6:	 " *** ERROR! ***"
```
2.  <+110>: Llama a `puts(" *** ERROR! ***")`.
3.  <+115>: Carga en lo alto del stack la dirección de `"   This index is reserved for wil!"` en `0x8048af8`.
```bash
(gdb) x/s 0x8048af8
0x8048af8:	 "   This index is reserved for wil!"
```
4.  <+122>: Llama a `puts("   This index is reserved for wil!")`.
5.  <+127>: Carga en lo alto del stack la dirección de `" *** ERROR! ***"` de nuevo.
6.  <+134>: Llama a `puts(" *** ERROR! ***")`.
7.  <+139>: Pone `EAX` a 1 — valor de retorno: error.
8.  <+144>: `jmp` incondicional a `<+165>` — sale de la función devolviendo 1.

### **Líneas 146, 149, 152, 155, 158, 160, 165 y 166:**
```asm
0x080486c2 <+146>:	mov    eax,DWORD PTR [ebp-0xc]
0x080486c5 <+149>:	shl    eax,0x2
0x080486c8 <+152>:	add    eax,DWORD PTR [ebp+0x8]
0x080486cb <+155>:	mov    edx,DWORD PTR [ebp-0x10]
0x080486ce <+158>:	mov    DWORD PTR [eax],edx
0x080486d0 <+160>:	mov    eax,0x0
0x080486d5 <+165>:	leave  
0x080486d6 <+166>:	ret  
```

1.  <+146>: Carga `index` en `EAX`.
2.  <+149>: `shl eax, 0x2` — multiplica `index` por 4. Cada elemento del array ocupa 4 bytes.
3.  <+152>: Suma la dirección base de `data` (`[ebp+0x8]`) — calcula `&data[index]`.
4.  <+155>: Carga `number` en `EDX`.
5.  <+158>: Escribe `number` en `data[index]`.
6.  <+160>: Pone `EAX` a 0 — valor de retorno: éxito.
7.  <+165>: `leave` — restaura el stack frame.
8.  <+166>: `ret` — retorna el control a `main()`.

---

# Resumen del Flujo de Ataque para el Nivel 07

## 1. Lectura:

La vulnerabilidad está en `store_number()` — no hay validación del límite
superior del índice:

```c
data[index] = number;
```

Podemos escribir en cualquier dirección de memoria calculando el offset
correcto desde `data`.

---

## 2. Vulnerabilidad:

* `data` es un array de 100 enteros sin signo en el stack — `[esp+0x24]`.
* `store_number()` solo bloquea índices donde `index % 3 == 0` o el byte más significativo de `number` es `0xb7`.
* No hay validación del límite superior — podemos escribir fuera del array.
* El programa borra `argv` y `envp` al inicio — no podemos usar variables de entorno para shellcode.
* **NX está OFF** — el stack permite ejecución de shellcode.
* **Stack Canary presente** — no podemos desbordar el buffer directamente.

---

## 3. Explotación:

* **Paso 1:** Localizamos la dirección de retorno de `main()` en el stack calculando su offset desde `data`.
* **Paso 2:** Verificamos que el índice calculado no sea múltiplo de 3 ni que el shellcode tenga el byte `0xb7` en la posición más significativa.
* **Paso 3:** Almacenamos el shellcode en `data` usando `store_number()`.
* **Paso 4:** Sobrescribimos la dirección de retorno de `main()` con la dirección de `data` donde está el shellcode.
* **Paso 5:** Cuando el programa ejecute `quit` y `main()` haga `ret`, saltará al shellcode.