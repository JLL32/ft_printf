/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:02:52 by mhaddi            #+#    #+#             */
/*   Updated: 2019/11/04 14:51:08 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_count(int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = (n >= 0) ? n : -n;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int				len;
	char			*a;
	unsigned int	nb;

	len = (n > 0) ? len_count(n) + 1 : len_count(n) + 2;
	if (!(a = malloc(sizeof(char) * len)))
		return (NULL);
	a[--len] = '\0';
	if (n >= 0)
		while (len-- > 0)
		{
			a[len] = n % 10 + '0';
			n /= 10;
		}
	else
	{
		nb = -n;
		while (len-- > 0)
		{
			a[len] = nb % 10 + '0';
			nb /= 10;
		}
		a[0] = '-';
	}
	return (a);
}
