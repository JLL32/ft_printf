/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 00:04:54 by mhaddi            #+#    #+#             */
/*   Updated: 2019/11/14 03:27:24 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	slen;

	slen = ft_strlen(s1);
	ptr = malloc((sizeof(*ptr) * slen) + sizeof(*ptr));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, slen + 1);
	return (ptr);
}
