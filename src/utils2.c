/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jll32 <jll32@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:30:56 by jll32             #+#    #+#             */
/*   Updated: 2020/10/29 18:10:13 by jll32            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(long n, char base, size_t padding)
{
	size_t	i;
	long	temp;
	char	num[100];

	if (n < 0)
		ft_putnchar('-', 1);
	n = n >= 0 ? n : -n;
	ft_putnchar('0', padding);
	if (n == 0)
		if (g_form.precision != 0)
			ft_putnchar('0', 1);
	i = 0;
	while (n)
	{
		temp = 0;
		temp = n % ((base == 'x' || base == 'X') ? 16 : 10);
		if (temp < 10)
			num[i++] = temp + '0';
		else
			num[i++] = temp + (base == 'x' ? 87 : 55);
		n = n / ((base == 'x' || base == 'X') ? 16 : 10);
	}
	while (i--)
		ft_putnchar(num[i], 1);
}

void	ft_putptr(size_t n)
{
	size_t	i;
	long	temp;
	char	num[100];

	ft_putnstr("0x", 2);
	if (n == 0)
		if (g_form.precision != 0)
			ft_putnchar('0', 1);
	i = 0;
	while (n)
	{
		temp = 0;
		temp = n % 16;
		if (temp < 10)
			num[i++] = temp + '0';
		else
			num[i++] = temp + 87;
		n = n / 16;
	}
	while (i--)
		ft_putnchar(num[i], 1);
}

size_t	ptrlen(size_t num)
{
	size_t	count;

	count = 0;
	if (num == 0)
		count++;
	while (num)
	{
		count++;
		num /= 16;
	}
	return (count);
}

size_t	numlen(long num, char base)
{
	size_t	count;

	count = 0;
	if (num < 0)
	{
		count += 1;
		num = num >= 0 ? num : -num;
	}
	if (num == 0)
		count++;
	while (num)
	{
		count++;
		num /= (base == 'x' || base == 'X') ? 16 : 10;
	}
	return (count);
}
