/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:14:13 by mhaddi            #+#    #+#             */
/*   Updated: 2019/11/04 17:46:43 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t len;

	len = ft_strlen(s) + 1;
	while (len)
	{
		if (*s == (char)c)
			return (char *)s;
		s++;
		len--;
	}
	return (NULL);
}
