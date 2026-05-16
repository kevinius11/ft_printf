/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:24:43 by kcastro-          #+#    #+#             */
/*   Updated: 2025/11/12 20:12:06 by kcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Esta función recibe un carácter que representa un especificador de formato
y una lista de argumentos variables. Dependiendo del especificador, llama a la
función correspondiente para manejar ese tipo de dato y devuelve el número de
caracteres impresos.
*/
int	dispatch_format(int c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	/*
	else if (c == 'a')
		return (ft_putstr("42 Cursus"));
	*/
	else
		return (handle_unknown_format(c, ap));
}
