/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:53:38 by kcastro-          #+#    #+#             */
/*   Updated: 2025/11/12 20:21:06 by kcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_helper(long num)
{
	int	ret;
	int	count;

	count = 0;
	if (num >= 10)
	{
		ret = ft_putnbr_helper(num / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar((num % 10) + '0');
	if (ret == -1)
		return (-1);
	return (count + ret);
}

int	ft_putnbr(int n)
{
	long	num;
	int		ret;

	num = n;
	if (num < 0)
	{
		ret = ft_putchar('-');
		if (ret == -1)
			return (-1);
		ret = ft_putnbr_helper(-num);
		if (ret == -1)
			return (-1);
		return (1 + ret);
	}
	return (ft_putnbr_helper(num));
}
