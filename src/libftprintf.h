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
# include "libft/libft.h"

va_list			g_arg_list;
int				g_counter;
int				ft_printf(const char *s, ...);
void			init_format(void);
void			router_lvl(int lvl);
void			router_specifier(void);
bool			is_flag(void);
bool			is_width(void);
bool			is_precision(void);
bool			is_length(void);
bool			is_specifier(void);
void			get_flag(void);
void			get_width(void);
void			get_precision(void);
void			get_length(void);
void			get_specifier(void);

/**
 *  Not final function
*/
void			ft_putchar(char c);
/************************************************/

typedef struct s_flags
{
	bool	zero;
	bool	minus;
	bool	plus;
	bool	space;
	bool	hash;
}				t_flags;

typedef struct s_format
{
	t_flags	flags;
	int		width;
	int		precision;
	char	length;
	char	specifier;
	void	*arg;
}				t_format;
char			*g_str;
t_format		g_format;
#endif
