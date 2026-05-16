/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:13:04 by kcastro-          #+#    #+#             */
/*   Updated: 2025/11/12 20:16:14 by kcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Esta función recibe un entero sin signo y lo imprime en formato decimal.
Devuelve el número de caracteres impresos o -1 en caso de error.
*/

int	ft_putunsigned(unsigned int n)
{
	int	len;
	int	ret;

	len = 0;
	if (n >= 10)
	{
		ret = ft_putunsigned(n / 10); // Llamada recursiva para imprimir los dígitos más significativos
		if (ret == -1)
			return (-1);
		len += ret;
		ret = ft_putunsigned(n % 10);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	else
	{
		ret = ft_putchar(n + '0');
		if (ret == -1)
			return (-1);
		len += ret;
	}
	return (len);
}
