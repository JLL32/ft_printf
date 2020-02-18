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

/*
** TODO: Finish the macro IS_SPECIFIER
** TODO: Create the macro IS_FLAG
** TODO: Create the macro IS_WIDTH
** TODO: Create the macro IS_PRECISION
** TODO: Create the macro IS_LENGTH
*/
va_list			g_arg_list;
int				g_counter;
int				ft_printf(const char *s, ...);
void			router(char **str, void *arg);
typedef struct	s_format
{
	char	*str;
	char	flag;
	int		width;
	int		precision;
	char	length;
	char	specifier;
	int		counter;
	void	*arg;
}				t_format;
char		*g_str;
t_format	g_format;
#endif
