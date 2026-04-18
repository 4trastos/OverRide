# **ANÁLISIS COMPLETO LINEA POR LINEA - NIVEL level03**

```asm
Dump of assembler code for function main:
0x0804885a <+0>:	push   ebp
0x0804885b <+1>:	mov    ebp,esp
0x0804885d <+3>:	and    esp,0xfffffff0
0x08048860 <+6>:	sub    esp,0x20
0x08048863 <+9>:	push   eax
0x08048864 <+10>:	xor    eax,eax
0x08048866 <+12>:	je     0x804886b <main+17>
0x08048868 <+14>:	add    esp,0x4
0x0804886b <+17>:	pop    eax
0x0804886c <+18>:	mov    DWORD PTR [esp],0x0
0x08048873 <+25>:	call   0x80484b0 <time@plt>
0x08048878 <+30>:	mov    DWORD PTR [esp],eax
0x0804887b <+33>:	call   0x8048500 <srand@plt>
0x08048880 <+38>:	mov    DWORD PTR [esp],0x8048a48
0x08048887 <+45>:	call   0x80484d0 <puts@plt>
0x0804888c <+50>:	mov    DWORD PTR [esp],0x8048a6c
0x08048893 <+57>:	call   0x80484d0 <puts@plt>
0x08048898 <+62>:	mov    DWORD PTR [esp],0x8048a48
0x0804889f <+69>:	call   0x80484d0 <puts@plt>
0x080488a4 <+74>:	mov    eax,0x8048a7b
0x080488a9 <+79>:	mov    DWORD PTR [esp],eax
0x080488ac <+82>:	call   0x8048480 <printf@plt>
0x080488b1 <+87>:	mov    eax,0x8048a85
0x080488b6 <+92>:	lea    edx,[esp+0x1c]
0x080488ba <+96>:	mov    DWORD PTR [esp+0x4],edx
0x080488be <+100>:	mov    DWORD PTR [esp],eax
0x080488c1 <+103>:	call   0x8048530 <__isoc99_scanf@plt>
0x080488c6 <+108>:	mov    eax,DWORD PTR [esp+0x1c]
0x080488ca <+112>:	mov    DWORD PTR [esp+0x4],0x1337d00d
0x080488d2 <+120>:	mov    DWORD PTR [esp],eax
0x080488d5 <+123>:	call   0x8048747 <test>
0x080488da <+128>:	mov    eax,0x0
0x080488df <+133>:	leave  
0x080488e0 <+134>:	ret    
End of assembler dump.
```

### **Línas 0, 1, 3, 6, 9, 10 y 12:**
```asm
0x0804885a <+0>:	push   ebp
0x0804885b <+1>:	mov    ebp,esp
0x0804885d <+3>:	and    esp,0xfffffff0
0x08048860 <+6>:	sub    esp,0x20
0x08048863 <+9>:	push   eax
0x08048864 <+10>:	xor    eax,eax
0x08048866 <+12>:	je     0x804886b <main+17>
```

1. <+0>: Guarda en lo alto del stack el valor de `EBP` (cpu) `[esp + 0x00]`. El `esp` se desplaza 4 bytes hacia abajo.
2. <+1>: Asigna en nuevo `esp` a `ebp` para la función `main`
3. <+3>: Alinea el stack a múltiplo de 16. (los últimos 4 bytes se ponene a 0).
4. <+6>: Reserva (desplaza) `32 bytes` (0x20) en el stack de `main` para que el compilador organice las varibles locales y los argumentos de las funciones que `main` va a llamar.
5. <+9>: Guarda en el stack el registro `eax`
6. <+10>: Usa la puerta lógica `XOR` para poner a 0 el registro `eax` que será el registro donde guardará lo leido por el terminal.
7. <+12>:`je` — como XOR siempre deja EAX a 0, el flag `ZF` siempre está activo y el salto a <+17> siempre se toma.


### **Líneas 14, 17, 18, 25, 30 y 33:**
```asm
0x08048868 <+14>:	add    esp,0x4
0x0804886b <+17>:	pop    eax
0x0804886c <+18>:	mov    DWORD PTR [esp],0x0
0x08048873 <+25>:	call   0x80484b0 <time@plt>
0x08048878 <+30>:	mov    DWORD PTR [esp],eax
0x0804887b <+33>:	call   0x8048500 <srand@plt>
```

1. <+14>: Suma (desplaza) 4 bytes el `esp` (stack pointer).
2. <+17>: Saca del stack el registro `eax`.
3. <+18>: POne con un 0 el `esp` para inicilizar a NULL la siguiente función.
4. <+25>: Llama a `time()`
```bash
time(NULL);
```
5. <+30>: Copia `eax` al inicio del stack.
6. <+33>: Llama a `srand(time(NULL))` — inicializa el generador de números aleatorios usando el tiempo actual como semilla.

### **Líneas: 38, 34, 50, 57, 62, 69, 74, 79 y 82** (Printea el head del programa)
```asm
0x08048880 <+38>:	mov    DWORD PTR [esp],0x8048a48
0x08048887 <+45>:	call   0x80484d0 <puts@plt>
0x0804888c <+50>:	mov    DWORD PTR [esp],0x8048a6c
0x08048893 <+57>:	call   0x80484d0 <puts@plt>
0x08048898 <+62>:	mov    DWORD PTR [esp],0x8048a48
0x0804889f <+69>:	call   0x80484d0 <puts@plt>
0x080488a4 <+74>:	mov    eax,0x8048a7b
0x080488a9 <+79>:	mov    DWORD PTR [esp],eax
0x080488ac <+82>:	call   0x8048480 <printf@plt>
```

1. <+38>: Copia en el stack el contenido de la dirección `0x8048a48` y lo pasa como argumento a `puts()`:
```bash
(gdb) x/s 0x8048a48
0x8048a48:	 '*' <repeats 35 times>
```
2. <+45>: Llama a `puts()`
3. <+50>: Copia en el stack el contenido de la dirección `0x8048a6c` y lo pasa como argumento a `puts()`:
```bash
(gdb) x/s 0x8048a6c
0x8048a6c:	 "*\t\tlevel03\t\t**"
```
4. <+57>: Llama a `puts()`
5. <+62>:  Copia en el stack el contenido de la dirección `0x8048a48` y lo pasa como argumento a `puts()`:
```bash
(gdb) x/s 0x8048a48
0x8048a48:	 '*' <repeats 35 times>
```
6. <+69>: Llama a `puts()`
7. <+74>: Carga en `eax` el contenido de la dirección `0x8048a7b`:
```bash
(gdb) x/s 0x8048a7b 
0x8048a7b:	 "Password:"
```
8. <+79>: Copia en `esp` el valor de `eax`. Pasa la dirección de `"Password:"` como argumento de `printf()`.
9. <+82>: Llama a `printf()`:
```bash
printf("Password:");
```

### **Líeas 87, 92, 96, 100 y 103:**
```asm
0x080488b1 <+87>:	mov    eax,0x8048a85
0x080488b6 <+92>:	lea    edx,[esp+0x1c]
0x080488ba <+96>:	mov    DWORD PTR [esp+0x4],edx
0x080488be <+100>:	mov    DWORD PTR [esp],eax
0x080488c1 <+103>:	call   0x8048530 <__isoc99_scanf@plt>
```

1. <+87>: Carga en `eax` el contenido de la dirección `0x8048a85`.
```bash
(gdb) x/s 0x8048a85
0x8048a85:	 "%d"
```
2. <+92>: Calcula la dirección de `[esp+0x1c]` que es la dirección de la varibale local `user_input` y la carga en `edx`
3. <+96>: Escribe en `[esp+0x4]` la dirección de `user_input`. Segundo argumento de `scanf()`: dónde almacenar el valor leído.
4. <+100>: Copia `%d` que esta en el registro `eax` a lo alto del stack para pasarlo como primer argumento de `scanf()`
5. <+103>: Llama a `scanf()` 

### **Líneas 108, 112, 120 y 123:**
```asm
0x080488c6 <+108>:	mov    eax,DWORD PTR [esp+0x1c]
0x080488ca <+112>:	mov    DWORD PTR [esp+0x4],0x1337d00d
0x080488d2 <+120>:	mov    DWORD PTR [esp],eax
0x080488d5 <+123>:	call   0x8048747 <test>
```

1. <+108>: Carga en `eax` el valor de `user_input` almacenado en `[esp+0x1c]`
2. <+112>: Escribe en `[esp+0x4]` el valor constante `0x1337d00d` (322109453 en decimal) como segundo argumento de test().
```bash
(gdb) x/s 0x1337d00d
0x1337d00d:	 <Address 0x1337d00d out of bounds>
```
3. <+120>: Copia en el stack la varible `user_input` y lo pasa como primer argumento
4. Llama a la función `test()`:
```bash
test(user_input, 0x1337d00d);
```

## **Análisis del desensambllado de la función - test()**
```asm
Dump of assembler code for function test:
0x08048747 <+0>:	push   ebp
0x08048748 <+1>:	mov    ebp,esp
0x0804874a <+3>:	sub    esp,0x28
0x0804874d <+6>:	mov    eax,DWORD PTR [ebp+0x8]
0x08048750 <+9>:	mov    edx,DWORD PTR [ebp+0xc]
0x08048753 <+12>:	mov    ecx,edx
0x08048755 <+14>:	sub    ecx,eax
0x08048757 <+16>:	mov    eax,ecx
0x08048759 <+18>:	mov    DWORD PTR [ebp-0xc],eax
0x0804875c <+21>:	cmp    DWORD PTR [ebp-0xc],0x15
0x08048760 <+25>:	ja     0x804884a <test+259>
0x08048766 <+31>:	mov    eax,DWORD PTR [ebp-0xc]
0x08048769 <+34>:	shl    eax,0x2
0x0804876c <+37>:	add    eax,0x80489f0
0x08048771 <+42>:	mov    eax,DWORD PTR [eax]
0x08048773 <+44>:	jmp    eax
0x08048775 <+46>:	mov    eax,DWORD PTR [ebp-0xc]
0x08048778 <+49>:	mov    DWORD PTR [esp],eax
0x0804877b <+52>:	call   0x8048660 <decrypt>
0x08048780 <+57>:	jmp    0x8048858 <test+273>
0x08048785 <+62>:	mov    eax,DWORD PTR [ebp-0xc]
0x08048788 <+65>:	mov    DWORD PTR [esp],eax
0x0804878b <+68>:	call   0x8048660 <decrypt>
0x08048790 <+73>:	jmp    0x8048858 <test+273>
0x08048795 <+78>:	mov    eax,DWORD PTR [ebp-0xc]
0x08048798 <+81>:	mov    DWORD PTR [esp],eax
0x0804879b <+84>:	call   0x8048660 <decrypt>
0x080487a0 <+89>:	jmp    0x8048858 <test+273>
0x080487a5 <+94>:	mov    eax,DWORD PTR [ebp-0xc]
0x080487a8 <+97>:	mov    DWORD PTR [esp],eax
0x080487ab <+100>:	call   0x8048660 <decrypt>
0x080487b0 <+105>:	jmp    0x8048858 <test+273>
0x080487b5 <+110>:	mov    eax,DWORD PTR [ebp-0xc]
0x080487b8 <+113>:	mov    DWORD PTR [esp],eax
0x080487bb <+116>:	call   0x8048660 <decrypt>
0x080487c0 <+121>:	jmp    0x8048858 <test+273>
0x080487c5 <+126>:	mov    eax,DWORD PTR [ebp-0xc]
0x080487c8 <+129>:	mov    DWORD PTR [esp],eax
0x080487cb <+132>:	call   0x8048660 <decrypt>
0x080487d0 <+137>:	jmp    0x8048858 <test+273>
0x080487d5 <+142>:	mov    eax,DWORD PTR [ebp-0xc]
0x080487d8 <+145>:	mov    DWORD PTR [esp],eax
0x080487db <+148>:	call   0x8048660 <decrypt>
0x080487e0 <+153>:	jmp    0x8048858 <test+273>
0x080487e2 <+155>:	mov    eax,DWORD PTR [ebp-0xc]
0x080487e5 <+158>:	mov    DWORD PTR [esp],eax
0x080487e8 <+161>:	call   0x8048660 <decrypt>
0x080487ed <+166>:	jmp    0x8048858 <test+273>
0x080487ef <+168>:	mov    eax,DWORD PTR [ebp-0xc]
0x080487f2 <+171>:	mov    DWORD PTR [esp],eax
0x080487f5 <+174>:	call   0x8048660 <decrypt>
0x080487fa <+179>:	jmp    0x8048858 <test+273>
0x080487fc <+181>:	mov    eax,DWORD PTR [ebp-0xc]
0x080487ff <+184>:	mov    DWORD PTR [esp],eax
0x08048802 <+187>:	call   0x8048660 <decrypt>
0x08048807 <+192>:	jmp    0x8048858 <test+273>
0x08048809 <+194>:	mov    eax,DWORD PTR [ebp-0xc]
0x0804880c <+197>:	mov    DWORD PTR [esp],eax
0x0804880f <+200>:	call   0x8048660 <decrypt>
0x08048814 <+205>:	jmp    0x8048858 <test+273>
0x08048816 <+207>:	mov    eax,DWORD PTR [ebp-0xc]
0x08048819 <+210>:	mov    DWORD PTR [esp],eax
0x0804881c <+213>:	call   0x8048660 <decrypt>
0x08048821 <+218>:	jmp    0x8048858 <test+273>
0x08048823 <+220>:	mov    eax,DWORD PTR [ebp-0xc]
0x08048826 <+223>:	mov    DWORD PTR [esp],eax
0x08048829 <+226>:	call   0x8048660 <decrypt>
0x0804882e <+231>:	jmp    0x8048858 <test+273>
0x08048830 <+233>:	mov    eax,DWORD PTR [ebp-0xc]
0x08048833 <+236>:	mov    DWORD PTR [esp],eax
0x08048836 <+239>:	call   0x8048660 <decrypt>
0x0804883b <+244>:	jmp    0x8048858 <test+273>
0x0804883d <+246>:	mov    eax,DWORD PTR [ebp-0xc]
0x08048840 <+249>:	mov    DWORD PTR [esp],eax
0x08048843 <+252>:	call   0x8048660 <decrypt>
0x08048848 <+257>:	jmp    0x8048858 <test+273>
0x0804884a <+259>:	call   0x8048520 <rand@plt>
0x0804884f <+264>:	mov    DWORD PTR [esp],eax
0x08048852 <+267>:	call   0x8048660 <decrypt>
0x08048857 <+272>:	nop
0x08048858 <+273>:	leave  
0x08048859 <+274>:	ret    
End of assembler dump.
```

### **Líneas 0, 1, 3, 6 y 9:**
```asm
0x08048747 <+0>:	push   ebp
0x08048748 <+1>:	mov    ebp,esp
0x0804874a <+3>:	sub    esp,0x28
0x0804874d <+6>:	mov    eax,DWORD PTR [ebp+0x8]
0x08048750 <+9>:	mov    edx,DWORD PTR [ebp+0xc]
```

1. <+0>: Guarda en lo alto del stack el valor de `ebp` (función main)`[esp + 0x00]`. El registro `esp` se desplaza 4 bytes.
2. <+1>: Asigna a `ebp` el nuevo `esp`para la función `test()`.
3. <+3>: Reserva (desplaza) 40 bytes `(0x28)` en el stack de `test()` para que el compilador organize las variables locales y los argumentos de las funciones que `test()` va a llamar.
4. <+6>: Carga en `eax` el primer argumento que recibe `test(): user_input`, almacenado en `[ebp+0x8]`.
5. <+9>: Carga en `edx` el segundo argumento que recibe `test(): param (0x1337d00d)`, almacenado en `[ebp+0xc]`.

### **Líneas 12, 14, 16, 18, 21 y 25:**
```asm
0x08048753 <+12>:	mov    ecx,edx
0x08048755 <+14>:	sub    ecx,eax
0x08048757 <+16>:	mov    eax,ecx
0x08048759 <+18>:	mov    DWORD PTR [ebp-0xc],eax
0x0804875c <+21>:	cmp    DWORD PTR [ebp-0xc],0x15
0x08048760 <+25>:	ja     0x804884a <test+259>
```

1. <+12>: Copia `param` en `ecx`
2. <+14>: Resta `inset_input` a `param`
3. <+16>: Carga el resultado en `eax`
4. <+18>: Guarda el resultado de la resta en la variable local `diff` que se encuentra en `[ebp-0xc]`.
5. <+21>: compara el valor de `diff` con el número `0x15 `(21 en decimal).
6. <+25>: Si `diff` es mayor que 0x15 salta a `<test+259>` (bloque rand).

### **Líneas 31, 34, 37, 42 y 44:**
```asm
0x08048766 <+31>:	mov    eax,DWORD PTR [ebp-0xc]
0x08048769 <+34>:	shl    eax,0x2
0x0804876c <+37>:	add    eax,0x80489f0
0x08048771 <+42>:	mov    eax,DWORD PTR [eax]
0x08048773 <+44>:	jmp    eax
```

1. <+31>: Carga en `eax` el valor de `diff` que se encuentra en `[ebp-0xc]`.
2. <+34>: Multiplica `diff` por 4 (`shl eax, 0x2` = desplazamiento de 2 bits a la izquierda).
   Cada entrada de la tabla de saltos ocupa 4 bytes — esto calcula el offset correcto.
3. <+37>: Suma la dirección base de la tabla de saltos `0x80489f0` y obtiene la dirección
   de la entrada correspondiente a `diff` dentro de la tabla.:
```bash
gdb) x/s 0x80489f0
0x80489f0:	 "J\210\004\bu\207\004\b\205\207\004\b\225\207\004\b\245\207\004\b\265\207\004\bŇ\004\bՇ\004\b\342\207\004\b\357\207\004\bJ\210\004\bJ\210\004\bJ\210\004\bJ\210\004\bJ\210\004\bJ\210\004\b\374\207\004\b\t\210\004\b\026\210\004\b#\210\004\b0\210\004\b=\210\004\b", '*' <repeats 35 times>
```
4. <+42>: Lee el valor almacenado en esa dirección y obtiene la dirección de destino del salto.
5. <+44>: Salta a la dirección obtenida. Este es el mecanismo interno de un `switch(diff)`.
   Cada caso del switch llama a `decrypt(diff)`.

### **Líneas 46 a 257 — Cuerpo del switch:**

Este bloque contiene **21 casos idénticos en estructura** (cases 0 a 20), uno por cada
valor posible de `diff` cuando es `<= 0x15`. Cada caso sigue el mismo patrón de 4 líneas:

```asm
mov    eax, DWORD PTR [ebp-0xc]    ; carga diff en eax
mov    DWORD PTR [esp], eax        ; lo pasa como argumento
call   0x8048660 <decrypt>         ; llama a decrypt(diff)
jmp    0x8048858 <test+273>        ; salta al final de test()
```

El compilador genera un bloque separado por cada caso en lugar de reutilizar el mismo
código. Es el comportamiento estándar de un `switch` sin optimización.

En C equivale a:

```c
switch(diff)
{
    case 0:  decrypt(diff); break;
    case 1:  decrypt(diff); break;
    case 2:  decrypt(diff); break;
    // ... hasta case 20 (0x14)
    case 20: decrypt(diff); break;
}
```

## **Análisis del desensambllado de la función - decrypt()**
```asm
Dump of assembler code for function decrypt:
0x08048660 <+0>:	push   ebp
0x08048661 <+1>:	mov    ebp,esp
0x08048663 <+3>:	push   edi
0x08048664 <+4>:	push   esi
0x08048665 <+5>:	sub    esp,0x40
0x08048668 <+8>:	mov    eax,gs:0x14
0x0804866e <+14>:	mov    DWORD PTR [ebp-0xc],eax
0x08048671 <+17>:	xor    eax,eax
0x08048673 <+19>:	mov    DWORD PTR [ebp-0x1d],0x757c7d51
0x0804867a <+26>:	mov    DWORD PTR [ebp-0x19],0x67667360
0x08048681 <+33>:	mov    DWORD PTR [ebp-0x15],0x7b66737e
0x08048688 <+40>:	mov    DWORD PTR [ebp-0x11],0x33617c7d
0x0804868f <+47>:	mov    BYTE PTR [ebp-0xd],0x0
0x08048693 <+51>:	push   eax
0x08048694 <+52>:	xor    eax,eax
0x08048696 <+54>:	je     0x804869b <decrypt+59>
0x08048698 <+56>:	add    esp,0x4
0x0804869b <+59>:	pop    eax
0x0804869c <+60>:	lea    eax,[ebp-0x1d]
0x0804869f <+63>:	mov    DWORD PTR [ebp-0x2c],0xffffffff
0x080486a6 <+70>:	mov    edx,eax
0x080486a8 <+72>:	mov    eax,0x0
0x080486ad <+77>:	mov    ecx,DWORD PTR [ebp-0x2c]
0x080486b0 <+80>:	mov    edi,edx
0x080486b2 <+82>:	repnz scas al,BYTE PTR es:[edi]
0x080486b4 <+84>:	mov    eax,ecx
0x080486b6 <+86>:	not    eax
0x080486b8 <+88>:	sub    eax,0x1
0x080486bb <+91>:	mov    DWORD PTR [ebp-0x24],eax
0x080486be <+94>:	mov    DWORD PTR [ebp-0x28],0x0
0x080486c5 <+101>:	jmp    0x80486e5 <decrypt+133>
0x080486c7 <+103>:	lea    eax,[ebp-0x1d]
0x080486ca <+106>:	add    eax,DWORD PTR [ebp-0x28]
0x080486cd <+109>:	movzx  eax,BYTE PTR [eax]
0x080486d0 <+112>:	mov    edx,eax
0x080486d2 <+114>:	mov    eax,DWORD PTR [ebp+0x8]
0x080486d5 <+117>:	xor    eax,edx
0x080486d7 <+119>:	mov    edx,eax
0x080486d9 <+121>:	lea    eax,[ebp-0x1d]
0x080486dc <+124>:	add    eax,DWORD PTR [ebp-0x28]
0x080486df <+127>:	mov    BYTE PTR [eax],dl
0x080486e1 <+129>:	add    DWORD PTR [ebp-0x28],0x1
0x080486e5 <+133>:	mov    eax,DWORD PTR [ebp-0x28]
0x080486e8 <+136>:	cmp    eax,DWORD PTR [ebp-0x24]
0x080486eb <+139>:	jb     0x80486c7 <decrypt+103>
0x080486ed <+141>:	lea    eax,[ebp-0x1d]
0x080486f0 <+144>:	mov    edx,eax
0x080486f2 <+146>:	mov    eax,0x80489c3
0x080486f7 <+151>:	mov    ecx,0x11
0x080486fc <+156>:	mov    esi,edx
0x080486fe <+158>:	mov    edi,eax
0x08048700 <+160>:	repz cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
0x08048702 <+162>:	seta   dl
0x08048705 <+165>:	setb   al
0x08048708 <+168>:	mov    ecx,edx
0x0804870a <+170>:	sub    cl,al
0x0804870c <+172>:	mov    eax,ecx
0x0804870e <+174>:	movsx  eax,al
0x08048711 <+177>:	test   eax,eax
0x08048713 <+179>:	jne    0x8048723 <decrypt+195>
0x08048715 <+181>:	mov    DWORD PTR [esp],0x80489d4
0x0804871c <+188>:	call   0x80484e0 <system@plt>
0x08048721 <+193>:	jmp    0x804872f <decrypt+207>
0x08048723 <+195>:	mov    DWORD PTR [esp],0x80489dc
0x0804872a <+202>:	call   0x80484d0 <puts@plt>
0x0804872f <+207>:	mov    esi,DWORD PTR [ebp-0xc]
0x08048732 <+210>:	xor    esi,DWORD PTR gs:0x14
0x08048739 <+217>:	je     0x8048740 <decrypt+224>
0x0804873b <+219>:	call   0x80484c0 <__stack_chk_fail@plt>
0x08048740 <+224>:	add    esp,0x40
0x08048743 <+227>:	pop    esi
0x08048744 <+228>:	pop    edi
0x08048745 <+229>:	pop    ebp
0x08048746 <+230>:	ret    
End of assembler dump.
```

### **Lineas 0, 1, 3, 4, 5, 8, 14 y 17:**
```asm
0x08048660 <+0>:	push   ebp
0x08048661 <+1>:	mov    ebp,esp
0x08048663 <+3>:	push   edi
0x08048664 <+4>:	push   esi
0x08048665 <+5>:	sub    esp,0x40
0x08048668 <+8>:	mov    eax,gs:0x14
0x0804866e <+14>:	mov    DWORD PTR [ebp-0xc],eax
0x08048671 <+17>:	xor    eax,eax
```

1. <+0>: Guarda en lo alto del stack el valor de `ebp` (función test)`[esp + 0x00]`. El registro `esp` se desplaza 4 bytes.
2. <+1>: Asigna a `ebp` el nuevo `esp`para la función `decrypt()`.
3. <+3>: Guarda en el stack el registro `edi` que más tarde lo usarán internamente `decrypt()`.
4. <+4>: Guarda en el satck el registo `esi`que más tarde lo usarán internamente `decrypt()`.
5. <+5>: Reserva (desplaza) 64 bytes `(0x40)` en el stack de `decryt()` para que el compilador organize las variables locales y los argumentos de las funciones que `decrypt()` va a llamar.
6. <+8>: Carga en `eax` el valor del `Stack Canary` desde gs:0x14. Es un valor aleatorio generado por el sistema para detectar desbordamientos de stack.
7. <+14>: Guarda el `Stack Canary` en `[ebp-0xc]`. Al final de la función se verificará que sigue intacto.
8. <+17>: Usa la puerta lógica `XOR` para poner a 0 el registro `eax`

### **Líneas 19 a 202 — Inicialización, bucle XOR y comparación:**

#### **Inicialización del string cifrado (líneas 19-47):**

El compilador escribe directamente en el stack 16 bytes cifrados más un terminador `\0`:

```asm
mov DWORD PTR [ebp-0x1d], 0x757c7d51
mov DWORD PTR [ebp-0x19], 0x67667360
mov DWORD PTR [ebp-0x15], 0x7b66737e
mov DWORD PTR [ebp-0x11], 0x33617c7d
mov BYTE PTR  [ebp-0xd],  0x0
```

En C equivale a:
```c
char encrypted[] = {
    0x51, 0x7d, 0x7c, 0x75,
    0x60, 0x73, 0x66, 0x67,
    0x7e, 0x73, 0x66, 0x7b,
    0x7d, 0x7c, 0x61, 0x33,
    0x00
};
```

#### **Artefacto del compilador (líneas 51-59):**

Mismo patrón que ya vimos en `main` — `push eax / xor eax,eax / je / pop eax`.
El salto siempre se toma. Código muerto generado por el compilador.

#### **Cálculo de la longitud del string (líneas 60-91):**

`repnz scas` es el equivalente ensamblador de `strlen()` — recorre el string
byte a byte hasta encontrar el `\0` y devuelve la longitud en `EAX`.
El resultado se guarda en [ebp-0x24] como longitud del string que será el límite del bucle XOR.

#### **Bucle XOR (líneas 94-139):**

Itera sobre cada byte de `encrypted[]` y le aplica XOR con el valor de `diff`:

```c
for (int i = 0; i < strlen(encrypted); i++)
    encrypted[i] ^= diff;
```

El contador `i` se guarda en `[ebp-0x28]`. El bucle salta a `<+133>` para comprobar la condición antes de ejecutar el cuerpo. Es un `for` compilado con la condición al final.

#### **Comparación con el string esperado (líneas 141-179):**

`repz cmps` compara byte a byte `encrypted[]` con el string en `0x80489c3`
durante `0x11` (17) bytes — es el equivalente ensamblador de `strncmp()`.

```bash
(gdb) x/s 0x80489c3
0x80489c3:	 "Congratulations!"
```
#### **Resultado (líneas 181-202):**

```asm
; si coinciden:
mov DWORD PTR [esp], 0x80489d4
call system@plt

; si no coinciden:
mov DWORD PTR [esp], 0x80489dc
call puts@plt
```

```bash
(gdb) x/s 0x80489d4
0x80489d4:    "/bin/sh"
(gdb) x/s 0x80489dc
0x80489dc:    "\nInvalid Password"
```

Si `encrypted[] XOR diff` coincide con `"Congratulations!"`, el programa llama
a `system("/bin/sh")` — lanza una shell. Si no coincide, imprime `"Invalid Password"`.

### **Líneas 207 a la 230:**
```asm
0x0804872f <+207>:	mov    esi,DWORD PTR [ebp-0xc]
0x08048732 <+210>:	xor    esi,DWORD PTR gs:0x14
0x08048739 <+217>:	je     0x8048740 <decrypt+224>
0x0804873b <+219>:	call   0x80484c0 <__stack_chk_fail@plt>
0x08048740 <+224>:	add    esp,0x40
0x08048743 <+227>:	pop    esi
0x08048744 <+228>:	pop    edi
0x08048745 <+229>:	pop    ebp
0x08048746 <+230>:	ret    
```

1. <+207>: Carga en `esi` el valor del **Stack Canary** guardado en `[ebp-0xc]` al inicio de la función.
2. <+210>: Aplica `xor` entre el canary guardado y el canary original de `gs:0x14`. Si el stack no fue corrompido el resultado es `0`.
3. <+217>: `je` — si el resultado es `0` (canaries coinciden) salta a `<+224>` y termina normalmente.
4. <+219>: Si el canary fue corrompido llama a `__stack_chk_fail@plt` — aborta el programa con un error de seguridad.
5. <+224>: Libera los 64 bytes `(0x40)` reservados en el stack de `decrypt()`.
6. <+227>: Restaura el registro `ESI`.
7. <+228>: Restaura el registro `EDI`.
8. <+229>: Restaura el `EBP` de la función `test()`.
9. <+230>: `ret` — retorna el control a la función `test()`.

## **Continuación análisis test():**

### **Líneas 257, 259, 264,267, 272, 273 y 274**
```asm
0x08048848 <+257>:	jmp    0x8048858 <test+273>
0x0804884a <+259>:	call   0x8048520 <rand@plt>
0x0804884f <+264>:	mov    DWORD PTR [esp],eax
0x08048852 <+267>:	call   0x8048660 <decrypt>
0x08048857 <+272>:	nop
0x08048858 <+273>:	leave  
0x08048859 <+274>:	ret  
```

1. <+257>: Último `jmp` del switch — salta a `<test+273>` para terminar la función.
2. <+259>: Si `diff > 0x15` — llama a `rand()` que devuelve un número aleatorio en `EAX`.
3. <+264>: Copia el valor aleatorio devuelto por `rand()` al stack como argumento de `decrypt()`.
4. <+267>: Llama a `decrypt()` con el valor aleatorio — la desencriptación fallará y mostrará `"Invalid Password"`.
5. <+272>: `nop` — instrucción vacía, no hace nada. Artefacto del compilador.
6. <+273>: `leave` — restaura el stack frame: copia `EBP` en `ESP` y hace `pop EBP`.
7. <+274>: `ret` — retorna el control a `main()`.

## **Continuación análisis de main():**

### **Líneas: 128, 133 y 134**
```asm
0x080488da <+128>:	mov    eax,0x0
0x080488df <+133>:	leave  
0x080488e0 <+134>:	ret   
```

1. <+128>: Pone `EAX` a 0 — valor de retorno de `main()`.
2. <+133>: `leave` — restaura el stack frame: copia `EBP` en `ESP` y hace `pop EBP`.
3. <+134>: `ret` — retorna el control al sistema. 

Esto es un proyecto académico de 42 Madrid. Aquí tienes el resumen adaptado al level03:

---

# Resumen del Flujo de Ataque para el Nivel 03

## 1. Lectura:

La vulnerabilidad está en la función `decrypt()` — específicamente en la lógica
de `test()` que controla con qué valor se llama a `decrypt()`:

```c
diff = param - user_input;   // param = 0x1337d00d
if (diff > 0x15)
    decrypt(rand());          // valor aleatorio → siempre falla
else
    decrypt(diff);            // valor controlado → puede funcionar
```

---

## 2. Vulnerabilidad:

* `param` siempre vale `0x1337d00d` (322424845 en decimal).
* `diff = param - user_input` — controlamos `diff` controlando `user_input`.
* `decrypt(diff)` aplica `XOR` con `diff` sobre el string cifrado y lo compara
  con `"Congratulations!"`.
* Necesitamos encontrar el valor de `diff` que descifra el string correctamente.

---

## 3. Explotación:

* **Paso 1:** Verificamos con Python que todos los bytes del string cifrado hacen
  `XOR` con el mismo valor — `diff = 0x12` (18 en decimal).
* **Paso 2:** Como `diff = 0x1337d00d - user_input`, despejamos `user_input`:
```c
user_input = 0x1337d00d - 0x12 = 322424827
```
* **Paso 3:** Introducimos ese valor como password:

```bash
level03@OverRide:~$ ./level03
***********************************
*       level03     **
***********************************
Password:322424827
$ whoami
level04
$ cat /home/users/level04/.pass
kgv3tkEb9h2mLkRsPkXRfc2mHbjMxQzvb2FrgKkf
$
```
---
