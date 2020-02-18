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
int	ft_printf(const char *s, ...)
{
	va_start(arg_list, s);
	counter = 0;
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
			counter++;
			s++;
		}
	}
	va_end(arg_list);
	return (counter);
}
