/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:21:14 by mhaddi            #+#    #+#             */
/*   Updated: 2019/11/09 03:37:47 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	str[--len] = '\0';
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
