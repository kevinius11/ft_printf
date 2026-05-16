/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:21:16 by kcastro-          #+#    #+#             */
/*   Updated: 2025/11/12 20:17:21 by kcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Esta función recibe un puntero y lo imprime en formato hexadecimal,
precedido por "0x". Si el puntero es NULL, imprime "(nil)". Devuelve el número de caracteres impresos
o -1 en caso de error.
*/
int	ft_putptr(void *ptr)
{
	int					printed; //	 Variable para contar los caracteres impresos
	int					ret; // Variable para almacenar el valor de retorno de las funciones llamadas
	unsigned long long	addr;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	addr = (unsigned long long)ptr; // Convertir el puntero a un valor numérico
	printed = 0; 
	ret = ft_putstr("0x");
	if (ret == -1)
		return (-1);
	printed += ret;
	ret = ft_puthex(addr, 'x'); // Imprimir la dirección en formato hexadecimal
	if (ret == -1)
		return (-1);
	printed += ret; // Sumar el número de caracteres impresos
	return (printed);
}
