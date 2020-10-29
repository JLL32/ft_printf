/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jll32 <jll32@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:05:15 by jll32             #+#    #+#             */
/*   Updated: 2020/10/29 17:33:25 by jll32            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

size_t	ft_strlen(const char *s)
{
	const char *str;

	str = s;
	while (*str)
		str++;
	return (str - s);
}

void	ft_putnchar(char c, size_t n)
{
	if (g_form.specifier == 'c' && c == 0)
	{
		g_counter++;
		write(1, &c, 1);
	}
	while (c && n--)
	{
		g_counter++;
		write(1, &c, 1);
	}
}

void	ft_putnstr(char *str, size_t n)
{
	while (*str && n--)
	{
		ft_putnchar(*str, 1);
		str++;
	}
}
