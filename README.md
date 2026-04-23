# OverRide

## Descripción

Este proyecto sigue al proyecto RainFall. Su objetivo es aprender a explotar binarios ELF en un sistema i386/x86-64, enfrentando protecciones de memoria progresivamente más complejas.

---

## Estructura del repositorio

```bash
OverRide/
├── level00/
│   ├── flag
│   ├── source.c
│   ├── walkthrough.md
│   └── Resources/
│       └── README.md
├── level01/
│   ├── flag
│   ├── source.c
│   ├── walkthrough.md
│   └── Resources/
│       └── README.md
├── ...
└── level09/          ← bonus
    ├── flag
    ├── source.c
    ├── walkthrough.md
    └── Resources/
        └── README.md
```

Cada nivel contiene:
- **flag**: el password del siguiente nivel.
- **source.c**: reconstrucción del binario explotado a partir del desensamblado.
- **walkthrough.md**: los pasos seguidos para resolver el nivel.
- **Resources/**: análisis detallado del desensamblado línea a línea.

---

## Niveles y técnicas

| Nivel | Técnica |
| --- | --- |
| **level00** | Análisis básico — password hardcodeado |
| **level01** | Stack Buffer Overflow + Ret2Libc (32 bits) |
| **level02** | Format String Read — lectura del stack |
| **level03** | Ingeniería inversa de algoritmo XOR |
| **level04** | Ret2Libc con fork/ptrace antidebugging |
| **level05** | GOT Hijack + shellcode en variable de entorno |
| **level06** | Ingeniería inversa de algoritmo de validación |
| **level07** | Array Out of Bounds + Ret2Libc |
| **level08** | Path Traversal |
| **level09** | Off-by-one + Stack Buffer Overflow con PIE *(bonus)* |

---

## Protecciones analizadas

En cada nivel se analiza el estado de las siguientes protecciones:

- **PIE** (Position Independent Executable)
- **ASLR** (Address Space Layout Randomization)
- **NX** (No eXecute)
- **RELRO** (Relocation Read-Only)
- **Stack Canary**

---

## Parte obligatoria

Completar los niveles del **level00** al **level08**.

## Parte bonus

Completar el **level09** — el último usuario es `end`.

> **Nota:** Convertirse en `root` no es un bonus — se considera trampa.

---

## Requisitos

- Máquina virtual de 64 bits con la ISO del proyecto.
- Conexión SSH al puerto 4242:

```bash
ssh level00@<IP> -p 4242
```

- Contraseña inicial: `level00`

---

## Advertencias

- El repositorio **no debe contener ningún binario**.
- El uso de herramientas de automatización se considera trampa (-42).
- Cada solución debe poder ser explicada y justificada durante la evaluación.
- Los archivos del proyecto no deben incluirse en el repositorio bajo ninguna
  circunstancia — deben descargarse durante la evaluación si es necesario.
