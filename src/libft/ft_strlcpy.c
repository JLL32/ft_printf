/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:47:15 by mhaddi            #+#    #+#             */
/*   Updated: 2019/11/07 23:00:09 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dst && !size)
		return (srclen);
	while (size > 1)
	{
		if (*src == '\0')
			break ;
		*(dst++) = *(src++);
		size--;
	}
	if (size)
		*dst = '\0';
	return (srclen);
}
