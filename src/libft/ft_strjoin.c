/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:55:48 by mhaddi            #+#    #+#             */
/*   Updated: 2019/11/13 22:03:09 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	strjoin = malloc((sizeof(char) * len) + sizeof(char));
	if (!strjoin)
		return (NULL);
	while (*s1)
		strjoin[i++] = *(s1++);
	while (*s2)
		strjoin[i++] = *(s2++);
	strjoin[i] = '\0';
	return (strjoin);
}
