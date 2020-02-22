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

#include "libft/libft.h"
#include "libftprintf.h"
#include "routers.c"

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
	init_struct();
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			router_lvl1();
		}
		else
		{
			write(1, s, 1);
			g_counter++;
			s++;
		}
	}
	va_end(g_arg_list);
	return (g_counter);
}

void	init_struct()
{
	g_format.flags[0] = 0;
	g_format.flags[1] = 0;
	g_format.flags[2] = 0;
	g_format.flags[3] = 0;
	g_format.width = 0;
	g_format.precision = 0;
	g_format.length = '\0';
	g_format.specifier = '\0';
	g_format.arg = NULL;
	return;
}
