/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jll32 <jll32@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:46:25 by ael-hach          #+#    #+#             */
/*   Updated: 2020/10/29 18:29:55 by jll32            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <ctype.h>

int				ft_printf(const char *s, ...);
void			init_form(void);
void			router_lvl(int lvl);
void			router_specifier(void);
bool			is_flag(void);
bool			is_width(void);
bool			is_precision(void);
bool			is_specifier(void);
void			get_flag(void);
void			get_width(void);
void			get_precision(void);
void			get_specifier(void);
void			parse_signed(long arg
, int field_width
, size_t padding
, size_t len);
void			parse_ptr(size_t arg);
void			parse_str(char *arg);
void			parse_char(int arg);
size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
void			ft_putnchar(char c, size_t n);
void			ft_putnstr(char *str, size_t n);
void			ft_putnbr(long n, char base, size_t padding);
void			ft_putptr(size_t num);
size_t			numlen(long num, char base);
size_t			ptrlen(size_t num);

typedef struct
{
	struct
	{
		bool	zero;
		bool	minus;
	}		flags;
	int		width;
	int		precision;
	char	length;
	char	specifier;
}		t_form;

va_list			g_arg_list;
int				g_counter;
char			*g_str;
t_form			g_form;
#endif
