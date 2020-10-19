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
# include <ctype.h>
# include "libft/libft.h"

# define ABS(x) (((x) <  0) ? -(x) : (x))

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
void            parse_signed(void);
void            parse_unsigned(void);
/**
 *  Not final functions
 *  Will be moved later to libft
*/
void			ft_putnchar(char c, size_t n);
void            ft_putsigned(long n, char prefix, size_t padding);
void ft_putsize(size_t n, char base, char * prefix);
void			ft_putnstr(char *str, size_t n);
void			cast_and_putnbr();
void			ft_putptr(size_t n);
size_t			numlen(long num);
size_t          ptrlen(size_t ptr);
/************************************************/

typedef struct
{
	struct
	{
		bool	zero;
		bool	minus;
		bool	plus;
		bool	space;
		bool	hash;
	} flags;
	int width;
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
