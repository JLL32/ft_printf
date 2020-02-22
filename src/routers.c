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
	if (*g_str == '%' && lvl <= 1)
	{
		write(1, g_str,1);
		g_counter++;
	}
	else if (is_flag() && lvl <= 2)
		get_flag();
	else if(is_width() && lvl <= 3)
		get_width();
	else if (is_precision() && lvl <= 4)
		get_precision();
	else if (is_length() && lvl <= 5)
		get_length();
	else if (is_specifier() && lvl <= 6)
		get_specifier();
	return;
}

void	router_specifier()
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
	return;
}
