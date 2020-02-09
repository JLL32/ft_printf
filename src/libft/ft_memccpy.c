/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:12:24 by mhaddi            #+#    #+#             */
/*   Updated: 2019/11/04 15:07:23 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n)
	{
		*(unsigned char *)(dst) = *(unsigned char *)(src);
		if (*(unsigned char *)dst == (unsigned char)c)
			return (dst + 1);
		dst++;
		src++;
		n--;
	}
	return (NULL);
}
