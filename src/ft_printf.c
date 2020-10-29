/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jll32 <jll32@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 08:35:53 by ael-hach          #+#    #+#             */
/*   Updated: 2020/10/29 18:59:50 by jll32            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *s, ...)
{
	va_start(g_arg_list, s);
	g_counter = 0;
	g_str = (char *)s;
	while (*g_str)
	{
		if (*g_str == '%')
		{
			init_form();
			g_str++;
			router_lvl(1);
		}
		else
		{
			write(1, g_str, 1);
			g_counter++;
		}
		g_str++;
	}
	va_end(g_arg_list);
	return (g_counter);
}

void	init_form(void)
{
	g_form.flags.zero = false;
	g_form.flags.minus = false;
	g_form.width = 0;
	g_form.precision = -1;
	g_form.specifier = '\0';
	return ;
}
