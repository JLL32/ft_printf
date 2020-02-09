/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:16:02 by mhaddi            #+#    #+#             */
/*   Updated: 2019/11/04 15:01:04 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if ((!dst && !src) || (!dst && !len))
		return (NULL);
	if (!src && !len)
		return (dst);
	if (!ft_memcmp(dst, src, len))
		return (dst);
	if (dst > src)
	{
		while (len)
		{
			len--;
			((char *)dst)[len] = ((char *)src)[len];
		}
	}
	else
		dst = ft_memcpy(dst, src, len);
	return (dst);
}
