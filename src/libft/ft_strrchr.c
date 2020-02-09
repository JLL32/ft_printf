/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:44:12 by mhaddi            #+#    #+#             */
/*   Updated: 2019/11/05 01:56:13 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t len;

	len = ft_strlen(s) + 1;
	s += len - 1;
	while (len)
	{
		if (*s == (char)c)
			return (char *)s;
		len--;
		if (len)
			s--;
	}
	return (NULL);
}
