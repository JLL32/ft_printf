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

void			print_integer(void);
void			print_pointer(void);
void			print_string(void);
void			print_char(void);
void			print_shared(void);
void			print_percent(void);
/**
 *  Not final function
 *  Will be moved later to libft
*/
void			ft_putnchar(char c, size_t n);
void			ft_putnstr(char *str, size_t n);
void			ft_putnbr_base(long n, char base);
size_t			numlen(long long num, char base);
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

va_list			g_arg_list;
int				g_counter;
char			*g_str;
t_format		g_format;
#endif
