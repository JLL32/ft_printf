/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:32:52 by mhaddi            #+#    #+#             */
/*   Updated: 2019/11/14 00:09:16 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	columns_counter(char const *s, char c)
{
	size_t	clmns;
	size_t	j;

	clmns = 0;
	j = 0;
	if (s[0] != c && s[0] != '\0')
		clmns = 1;
	while (s[j])
	{
		if (s[j] == c && s[j + 1] != c)
		{
			if (s[j + 1] == '\0')
				break ;
			clmns++;
		}
		j++;
	}
	return (clmns);
}

static void		storers(char const *s, char c, size_t *indxs, size_t *row_len)
{
	size_t	len_calc;
	size_t	i;
	size_t	j;

	len_calc = 0;
	i = 0;
	if (s[0] != c)
		indxs[i++] = 0 + len_calc++;
	j = 0;
	while (s[j])
	{
		if (s[j] == c && s[j + 1] != c)
		{
			if (s[j + 1] == '\0')
				break ;
			indxs[i] = j + 1;
			if (i > 0)
				row_len[i - 1] = len_calc + 1;
			len_calc = 1;
			i++;
		}
		len_calc = (s[j] != c && s[j + 1] != c) ? len_calc + 1 : len_calc;
		j++;
	}
	row_len[i - 1] = (!s[j]) ? len_calc : len_calc + 1;
}

static char		**arrays_filler(char const *s, size_t *indxs,
		size_t *row_len, size_t clmns)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**arr;

	i = 0;
	if (!(arr = malloc(sizeof(char *) * (clmns + 1))))
		return (NULL);
	while (i < clmns)
	{
		j = 0;
		if (!(arr[i] = malloc(sizeof(char) * row_len[i])))
		{
			while (j < i)
				free(arr[j++]);
			free(arr);
			return (NULL);
		}
		k = indxs[i];
		while (j < row_len[i] - 1)
			arr[i][j++] = s[k++];
		arr[i++][j] = '\0';
	}
	arr[clmns] = NULL;
	return (arr);
}

static char		**edgecases(char const *s, char c)
{
	char	**empty_arr;

	if (!c && *s)
	{
		if (!(empty_arr = malloc(sizeof(char *) * 2)))
			return (NULL);
		empty_arr[1] = NULL;
		if (!(empty_arr[0] = ft_strdup(s)))
		{
			free(empty_arr);
			return (NULL);
		}
		return (empty_arr);
	}
	if (!(empty_arr = malloc(sizeof(char *))))
		return (NULL);
	empty_arr[0] = NULL;
	return (empty_arr);
}

char			**ft_split(char const *s, char c)
{
	size_t	clmns;
	size_t	*indxs;
	size_t	*row_len;
	char	**arr;

	if (!s)
		return (NULL);
	if (!c || !(clmns = columns_counter(s, c)))
		return (edgecases(s, c));
	if (!(row_len = malloc(sizeof(size_t) * clmns)))
		return (NULL);
	if (!(indxs = malloc(sizeof(size_t) * clmns)))
	{
		free(row_len);
		return (NULL);
	}
	storers(s, c, indxs, row_len);
	arr = arrays_filler(s, indxs, row_len, clmns);
	free(indxs);
	free(row_len);
	if (!arr)
		return (NULL);
	return (arr);
}
