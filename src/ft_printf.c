/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hach <ael-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 08:35:53 by ael-hach          #+#    #+#             */
/*   Updated: 2020/02/17 15:54:00 by ael-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/**
** int ft_printf(const char *s, ...)
** @brief prints a formatted text in the standard output
** @param s takes a string to format later
** @param ... takes a list of arguments to imbed
** @return returns the length of the printed text
** TODO: Find a better way the implement the body of printf
*/
int		ft_printf(const char *s, ...)
{
	va_start(g_arg_list, s);
	g_counter = 0;
	g_str = (char *)s;
	while (*g_str)
	{
		if (*g_str == '%')
		{
			init_format();
			g_str++;
			g_format.arg = va_arg(g_arg_list, void *);
			router_lvl(1);
		}
		else
		{
			write(1, s, 1);
			g_counter++;
		}
		g_str++;
	}
	va_end(g_arg_list);
	return (g_counter);
}

void	init_format(void)
{
	g_format.flags.zero = false;
	g_format.flags.minus = false;
	g_format.flags.plus = false;
	g_format.flags.space = false;
	g_format.flags.hash = false;
	g_format.width = 0;
	g_format.precision = 0;
	g_format.length = '\0';
	g_format.specifier = '\0';
	g_format.arg = NULL;
	return ;
}
