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
	if (g_format.specifier == 'd'
	|| g_format.specifier == 'i'
	|| g_format.specifier == 'x'
	|| g_format.specifier == 'X'
	|| g_format.specifier == 'u')
		print_integer();
	else if (g_format.specifier == 'p')
		print_pointer();
	else if (g_format.specifier == 's')
		print_string();
	else if (g_format.specifier == 'c')
		print_char();
	else if (g_format.specifier == '%')
		print_percent();
	return;
}
