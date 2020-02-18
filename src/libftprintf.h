/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:46:25 by ael-hach          #+#    #+#             */
/*   Updated: 2020/02/18 10:46:28 by ael-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

va_list			g_arg_list;
int				g_counter;
int				ft_printf(const char *s, ...);
int				init_struct();
void			router_lvl1();
typedef struct	s_format
{
	char	flag;
	int		width;
	int		precision;
	char	length;
	char	specifier;
	void	*arg;
}				t_format;
char			*g_str;
t_format		g_format;
#endif
