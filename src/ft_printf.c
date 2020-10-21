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
** NOTE: be careful with the conversion specifier 'e'
** NOTE: be careful with the French version of the correction instructions
** NOTE: dont't forget about the wide character
** TODO: Move the args logic from parsers to specifiers router or create functions to set args
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

void	init_format(void)
{
	g_form.flags.zero = false;
	g_form.flags.minus = false;
	g_form.flags.plus = false;
	g_form.flags.space = false;
	g_form.flags.hash = false;
	g_form.width = 0;
	g_form.precision = -1;
	g_form.length = '\0';
	g_form.specifier = '\0';
	g_form.arg = NULL;
	return ;
}
