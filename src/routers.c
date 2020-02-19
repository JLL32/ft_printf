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
#include "validators.c"

void	router_lvl1()
{
	if (*g_str == '%')
	{
		write(1, g_str,1);
		g_counter++;
	}
	else if (is_flag())
		get_flag();
	else if(is_width())
		get_width();
	else if (is_precision())
		get_precision();
	else if (is_length())
		get_length();
	else if (is_specifier())
		get_specifier();
}

void	router_lvl2()
{
	if (is_flag())
		get_flag();
	else if (is_width())
		get_width();
	else if (is_precision())
		get_precision();
	else if (is_length())
		get_length();
	else if (is_specifier())
		get_specifier();
}

void	router_lvl3()
{
	if (is_precision())
		get_precision();
	else if (is_length())
		get_length();
	else if (is_specifier())
		get_specifier();
}

void	router_lvl4()
{
	if (is_length())
		get_length();
	else if (is_specifier())
		get_specifier();
}
void	router_lvl5()
{
	if (is_length())
		get_length();
	else if (is_specifier())
		get_specifier();
}
