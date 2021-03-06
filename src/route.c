/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jll32 <jll32@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:33:42 by ael-hach          #+#    #+#             */
/*   Updated: 2020/10/29 18:29:05 by jll32            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	router_lvl(int lvl)
{
	if (is_flag() && lvl <= 1)
		get_flag();
	else if (is_width() && lvl <= 2)
		get_width();
	else if (is_precision() && lvl <= 3)
		get_precision();
	else if (is_specifier() && lvl <= 4)
		get_specifier();
	else if (*g_str == ' ')
	{
		g_str++;
		router_lvl(4);
	}
	return ;
}

void	router_specifier(void)
{
	if (g_form.specifier == 'd' || g_form.specifier == 'i')
		parse_signed(va_arg(g_arg_list, int), 0, 0, 0);
	else if (g_form.specifier == 'u'
			|| g_form.specifier == 'x'
			|| g_form.specifier == 'X')
		parse_signed(va_arg(g_arg_list, unsigned int), 0, 0, 0);
	else if (g_form.specifier == 'p')
		parse_ptr(va_arg(g_arg_list, size_t));
	else if (g_form.specifier == 's')
		parse_str(va_arg(g_arg_list, char *));
	else if (g_form.specifier == 'c')
		parse_char(va_arg(g_arg_list, int));
	else if (g_form.specifier == '%')
		parse_char('%');
	return ;
}
