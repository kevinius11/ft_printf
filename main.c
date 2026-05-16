#include "includes/ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*null_str;

	int r_std, r_ft;
	void *p = malloc(1); /* para probar puntero no-NULL */
	printf("\n======= PRUEBAS ft_printf vs printf =======\n\n");
	/* 1) Caracteres */
	printf("-- CHAR --\n");
	r_std = printf("char: '%c'\n", 'A');
	r_ft = ft_printf("char: '%c'\n", 'A');
	printf("returns -> printf=%d, ft_printf=%d\n\n", r_std, r_ft);
	/* 2) Caracter nulo (se imprime como '\0' -- ojo: pantalla no mostrará) */
	printf("-- CHAR NULL (\\0) --\n");
	r_std = printf("char nul: '%c' (puede no visualizarse)\n", '\0');
	r_ft = ft_printf("char nul: '%c' (puede no visualizarse)\n", '\0');
	printf("returns -> printf=%d, ft_printf=%d\n\n", r_std, r_ft);
	/* 3) Strings */
	printf("-- STRINGS --\n");
	r_std = printf("hola mundo\n");
	r_ft = ft_printf("hola mundo\n");
	printf("returns -> printf=%d, ft_printf=%d\n", r_std, r_ft);
	r_std = printf("empty: '%s'\n", "");
	r_ft = ft_printf("empty: '%s'\n", "");
	printf("returns -> printf=%d, ft_printf=%d\n", r_std, r_ft);
	/* NULL string -- comportamiento definido: printf imprime '(null)' en muchas
		implementaciones; la versión provista llama ft_putstr("(null)") si NULL */
	null_str = NULL;
	r_std = printf("[printf] null: '%s'\n", null_str ? null_str : "(null)");
	r_ft = ft_printf("[ft   ] null: '%s'\n", (char *)NULL);
	printf("returns -> printf=%d, ft_printf=%d\n\n", r_std, r_ft);
	/* 4) Enteros (signed) */
	printf("-- ENTEROS (signed) --\n");
	r_std = printf("[0: %d\n", 0);
	r_ft = ft_printf("0: %d\n", 0);
	printf("returns -> printf=%d, ft_printf=%d\n", r_std, r_ft);
	r_std = printf("42: %d\n", 42);
	r_ft = ft_printf("42: %d\n", 42);
	printf("returns -> printf=%d, ft_printf=%d\n", r_std, r_ft);
	r_std = printf("-42: %d\n", -42);
	r_ft = ft_printf("-42: %d\n", -42);
	printf("returns -> printf=%d, ft_printf=%d\n", r_std, r_ft);
	r_std = printf("INT_MAX: %d\n", INT_MAX);
	r_ft = ft_printf("INT_MAX: %d\n", INT_MAX);
	printf("returns -> printf=%d, ft_printf=%d\n", r_std, r_ft);
	/* Caso problemático: INT_MIN en implementaciones que hacen `num =
		-num` puede
		desbordar (porque -INT_MIN no cabe en 'int'). */
	r_std = printf("INT_MIN: %d\n", INT_MIN);
	r_ft = ft_printf("INT_MIN: %d\n", INT_MIN);
	printf("returns -> printf=%d, ft_printf=%d\n\n", r_std, r_ft);
	/* 5) Unsigned */
	printf("-- UNSIGNED --\n");
	r_std = printf("0u: %u\n", 0u);
	r_ft = ft_printf("0u: %u\n", 0u);
	printf("returns -> printf=%d, ft_printf=%d\n", r_std, r_ft);
	r_std = printf("UINT_MAX: %u\n", UINT_MAX);
	r_ft = ft_printf("UINT_MAX: %u\n", UINT_MAX);
	printf("returns -> printf=%d, ft_printf=%d\n\n", r_std, r_ft);
	/* 6) Hex (lower/upper) */
	printf("-- HEX --\n");
	r_std = printf("0x (lower) 255: %x\n", 255);
	r_ft = ft_printf("0x (lower) 255: %x\n", 255);
	printf("returns -> printf=%d, ft_printf=%d\n", r_std, r_ft);
	r_std = printf("0X (upper) 255: %X\n", 255);
	r_ft = ft_printf("0X (upper) 255: %X\n", 255);
	printf("returns -> printf=%d, ft_printf=%d\n", r_std, r_ft);
	r_std = printf("UINT_MAX hex: %x\n", UINT_MAX);
	r_ft = ft_printf("UINT_MAX hex: %x\n", UINT_MAX);
	printf("returns -> printf=%d, ft_printf=%d\n\n", r_std, r_ft);
	/* 7) Punteros */
	printf("-- PUNTEROS --\n");
	r_std = printf("NULL ptr: %p\n", (void *)NULL);
	r_ft = ft_printf("NULL ptr: %p\n", (void *)NULL);
	printf("returns -> printf=%d, ft_printf=%d\n", r_std, r_ft);
	r_std = printf("malloc ptr: %p\n", p);
	r_ft = ft_printf("malloc ptr: %p\n", p);
	printf("returns -> printf=%d, ft_printf=%d\n\n", r_std, r_ft);
	/* 8) Porcentaje literal */
	printf("-- PORCENTAJE %% --\n");
	r_std = printf("literal percent: %%\n");
	r_ft = ft_printf("literal percent: %%\n");
	printf("returns -> printf=%d, ft_printf=%d\n\n", r_std, r_ft);
	/* 9) Mezclas complejas */
	printf("-- MEZCLAS --\n");
	r_std = printf("mix: %s %d %x %c %%\n", "X", 123, 123, 'Z');
	r_ft = ft_printf("mix: %s %d %x %c %%\n", "X", 123, 123, 'Z');
	printf("returns -> printf=%d, ft_printf=%d\n\n", r_std, r_ft);
	/* 10) Especificador desconocido - ver cómo lo maneja ft_printf
		Muchas implementaciones imprimen el carácter tal cual o lo ignoran. */
	printf("-- ESPEC. DESCONOCIDO --\n");
	r_std = printf("unknown %%q with arg: %c\n", 'A');
	/* Para la versión personalizada, probamos con %%q también; según la
		implementación, puede consumir o no argumentos y producir comportamiento
		distinto. */
	r_ft = ft_printf("unknown %%q with arg: %c\n", 'A');
	printf("returns -> printf=%d, ft_printf=%d\n\n", r_std, r_ft);
	/* 11) Casos límite y robustez */
	printf("-- CASOS LÍMITE / ROBUSTEZ --\n");
	/* números grandes (aunque dentro de int/unsigned) */
	r_std = printf("big number: %d %u %x\n", 214748364, 429496729u, 0x7fffffff);
	r_ft = ft_printf("big number: %d %u %x\n", 214748364, 429496729u,
			0x7fffffff);
	printf("returns -> printf=%d, ft_printf=%d\n\n", r_std, r_ft);
	/* 12) Repeticiones y secuencias %%%% */
	printf("-- SECUENCIAS %%%% --\n");
	r_std = printf("4 percents: %%%%\n");
	r_ft = ft_printf("4 percents: %%%%\n");
	printf("returns -> printf=%d, ft_printf=%d\n\n", r_std, r_ft);
	free(p);
	ft_printf("hello %a world");
	printf("======= FIN PRUEBAS =======\n");
	return (0);
}
