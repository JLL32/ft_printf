/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:24:02 by mhaddi            #+#    #+#             */
/*   Updated: 2019/11/04 15:09:58 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t len;

	if ((!dst && !src) || (!dst && !n))
		return (NULL);
	if (!src && !n)
		return (dst);
	if (!ft_memcmp(dst, src, n))
		return (dst);
	len = n;
	while (len)
	{
		*(char *)(dst++) = *(char *)(src++);
		len--;
	}
	return (dst - n);
}
