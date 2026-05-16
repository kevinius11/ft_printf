/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:15:20 by kcastro-          #+#    #+#             */
/*   Updated: 2025/11/12 20:11:17 by kcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
ESta función maneja los especificadores de formato desconocidos.
*/

int	handle_unknown_format(char specifier, va_list ap)
{
	(void)ap;
	return (ft_putchar('%') + ft_putchar(specifier));
}

/*
Esta es la función principal ft_printf que formatea e imprime una cadena.
*/

int	ft_printf(const char *format, ...)
{
	va_list	ap; // Lista de argumentos variables
	int		pc; // Contador de caracteres impresos
	int		i;

	pc = 0;
	i = 0;
	va_start(ap, format); // Inicializar la lista de argumentos variables
	while (format && format[i]) // Recorrer la cadena de formato
	{
		if (format[i] == '%' && format[i + 1]) // Encontrar un especificador de formato
		{
			i++; // Mover al carácter del especificador
			pc += dispatch_format(format[i], ap); // Llamar a la función de despacho
			i++; // Mover al siguiente carácter después del especificador
			continue ; // Continuar con el siguiente ciclo
		}
		pc += ft_putchar(format[i]); // Imprimir el carácter normal
		i++;
	}
	va_end(ap);
	return (pc);
}
