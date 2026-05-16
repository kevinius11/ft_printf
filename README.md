# ft_printf 🖨️ - Reimplementación de la Función de Formateo de C

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" alt="C" />
  <img src="https://img.shields.io/badge/School-42_Network-black.svg" alt="42" />
  <img src="https://img.shields.io/badge/Score-100%2F100-success.svg" alt="Score" />
</p>

## 📋 Descripción del Proyecto
El objetivo de este proyecto es recrear el comportamiento de la famosa función estándar `printf` de la librería `<stdio.h>`. Es un excelente ejercicio para aprender a utilizar **funciones variádicas** en C y dominar el formateo de datos, la gestión de buffers y la conversión de sistemas numéricos (decimal, sutiles binarios y hexadecimales) sin depender de las funciones del sistema.

A diferencia del `printf` original, esta versión se enfoca en la robustez y optimización del código, imitando con precisión los valores de retorno y el manejo de errores.

---

## 🛠️ Habilidades Técnicas Demostradas
* **Funciones Variádicas:** Uso avanzado de las macros de la librería `<stdarg.h>` (`va_start`, `va_arg`, `va_copy` y `va_end`) para procesar un número indefinido de argumentos de diferentes tipos.
* **Parsing en Tiempo Real:** Diseño de un algoritmo capaz de recorrer una cadena de formato, identificar los especificadores de conversión `%` y extraer los datos correspondientes limpiamente.
* **Aritmética de Punteros y Conversión de Bases:** Implementación de algoritmos propios para convertir números enteros a formatos hexadecimales (para punteros y valores `X` / `x`) y strings de forma eficiente.
* **Optimización de Entrada/Salida (I/O):** Minimización de llamadas al sistema mediante el uso controlado del descriptor de archivo estándar (`stdout`) a través de funciones de escritura básicas.

---

## 🗂️ Especificadores Soportados

Esta implementación gestiona correctamente los siguientes tipos de conversiones esenciales:

| Especificador | Descripción |
| :---: | :--- |
| `%c` | Imprime un único carácter. |
| `%s` | Imprime una cadena de caracteres (string). |
| `%p` | Imprime la dirección de un puntero en formato hexadecimal de minúsculas. |
| `%d` | Imprime un número entero en base 10 (con signo). |
| `%i` | Imprime un entero en base 10 (con signo). |
| `%u` | Imprime un número entero decimal sin signo. |
| `%x` | Imprime un número hexadecimal en minúsculas (base 16). |
| `%X` | Imprime un número hexadecimal en mayúsculas (base 16). |
| `%%` | Imprime el símbolo del porcentaje de forma literal. |

---

## 🚀 Cómo Compilar e Integrar

### Compilación
Para generar la librería estática compilada (`libftprintf.a`), clona el repositorio y ejecuta en la raíz del proyecto:
```bash
make
```

Las reglas del Makefile incluyen la gestión limpia habitual: clean, fclean y re.


### Cómo usarla en tus proyectos
1. Incluye el archivo de cabecera en tu código fuente:

```C
#include "ft_printf.h"
```
2. Al compilar tu programa principal, enlaza la librería generada:

```Bash
gcc mi_programa.c -L. -lftprintf -o mi_programa
```

## 🛡️ Estándar de Calidad

Al igual que todos mis desarrollos en el ecosistema 42, este código cumple estrictamente con las reglas de la Norminette y ha sido testeado frente a escenarios extremos de desbordamiento, punteros NULL y entradas inesperadas para garantizar que no existan comportamientos indefinidos ni fugas de memoria.
