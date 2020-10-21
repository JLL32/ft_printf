/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hach <ael-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:33:42 by ael-hach          #+#    #+#             */
/*   Updated: 2020/02/17 16:02:32 by ael-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	router_lvl(int lvl)
{
	if (is_flag() && lvl <= 1)
		get_flag();
	else if(is_width() && lvl <= 2)
		get_width();
	else if (is_precision() && lvl <= 3)
		get_precision();
	else if (is_length() && lvl <= 4)
		get_length();
	else if (is_specifier() && lvl <= 5)
		get_specifier();
	return;
}

void	router_specifier(void)
{
	if (g_form.specifier == 'd'
	|| g_form.specifier == 'i'
	|| g_form.specifier == 'x'
	|| g_form.specifier == 'X'
	|| g_form.specifier == 'u')
		parse_signed();
	else if (g_form.specifier == 'u'
		|| g_form.specifier == 'x'
		|| g_form.specifier == 'X')
		parse_unsigned();
	else if (g_form.specifier == 'p')
		parse_ptr();
	else if (g_form.specifier == 's')
		parse_str();
	else if (g_form.specifier == 'c')
		parse_char();
	else if (g_form.specifier == '%')
		parse_percent();
	return;
}
