/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jll32 <jll32@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:05:03 by jll32             #+#    #+#             */
/*   Updated: 2020/10/28 01:05:04 by jll32            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

bool	is_flag(void)
{
	return (*g_str == '-' || *g_str == '0');
}

bool	is_width(void)
{
	return ((*g_str > 48 && *g_str <= 57) || *g_str == '*');
}

bool	is_precision(void)
{
	return (*g_str == '.' && *++g_str);
}

bool	is_length(void)
{
	return (*g_str == 'l' || *g_str == 'h');
}

bool	is_specifier(void)
{
	return (*g_str == 'd'
	|| *g_str == 'i'
	|| *g_str == 'u'
	|| *g_str == 'x'
	|| *g_str == 'X'
	|| *g_str == 'p'
	|| *g_str == 'c'
	|| *g_str == 's'
	|| *g_str == '%');
}
