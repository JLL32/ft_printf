/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:46:50 by mhaddi            #+#    #+#             */
/*   Updated: 2019/11/04 22:30:12 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			len_count(int n)
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
	return (n == 0) ? 1 : i;
}

static unsigned int	power(int len)
{
	unsigned int	n;

	n = 1;
	while (--len > 0)
		n = n * 10;
	return (n);
}

void				ft_putnbr_fd(int n, int fd)
{
	char			s;
	int				len;
	unsigned int	nb;

	nb = (n >= 0) ? n : -n;
	len = len_count(nb);
	if (n < 0)
		write(fd, "-", 1);
	while (len > 0)
	{
		s = (nb / power(len)) % 10 + '0';
		write(fd, &s, 1);
		len--;
	}
}
