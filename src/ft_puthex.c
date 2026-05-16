/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:16:42 by kcastro-          #+#    #+#             */
/*   Updated: 2025/11/12 20:24:01 by kcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_get_hex_char(int digit, char format)
{
	if (digit < 10)
		return (digit + '0');
	if (format == 'x')
		return (digit - 10 + 'a');
	return (digit - 10 + 'A');
}

static int	ft_puthex_helper(unsigned long long n, char format)
{
	int	ret;

	if (n >= 16)
	{
		ret = ft_puthex_helper(n / 16, format);
		if (ret == -1)
			return (-1);
	}
	else
		ret = 0;
	if (ft_putchar(ft_get_hex_char(n % 16, format)) == -1)
		return (-1);
	return (ret + 1);
}

int	ft_puthex(unsigned long long n, char format)
{
	if (format != 'x' && format != 'X')
		return (-1);
	return (ft_puthex_helper(n, format));
}
