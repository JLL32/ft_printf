/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:43:31 by mhaddi            #+#    #+#             */
/*   Updated: 2019/11/03 16:49:13 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sign(int c)
{
	return (c == '+' || c == '-') ? 1 : 0;
}

int			ft_atoi(const char *str)
{
	unsigned long long	n;
	int					negative;

	n = 0;
	negative = 0;
	while (*str)
	{
		if (*str == '-' && ft_isdigit(*(str + 1)))
			negative = 1;
		else if (sign(*str) && !ft_isdigit(*(str + 1)))
			return (0);
		else if (!ft_isdigit(*str) && !ft_iswhitespace(*str) && !sign(*str))
			return (0);
		else if (ft_isdigit(*str))
		{
			n = n * 10 + (*str - 48);
			if (!ft_isdigit(*(str + 1)))
				break ;
		}
		str++;
	}
	if (n > 9223372036854775807)
		return (negative) ? 0 : -1;
	else
		return (negative) ? (n * -1) : (n);
}
