/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jll32 <jll32@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:04:40 by jll32             #+#    #+#             */
/*   Updated: 2020/11/04 19:05:24 by jll32            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	parse_signed(long arg, int field_width, size_t padding, size_t len)
{
	len = numlen(arg, g_form.specifier);
	field_width = g_form.width - len + (!g_form.precision && !arg);
	if (g_form.precision > (int)len)
	{
		field_width = field_width - (g_form.precision - len) - (arg < 0);
		padding = g_form.precision - len + (arg < 0);
	}
	if (field_width > 0)
		if (g_form.flags.minus)
		{
			ft_putnbr(arg, g_form.specifier, padding);
			ft_putnchar(' ', field_width);
		}
		else if (g_form.flags.zero)
		{
			ft_putnbr(arg, g_form.specifier, field_width);
		}
		else
		{
			ft_putnchar(' ', field_width);
			ft_putnbr(arg, g_form.specifier, padding);
		}
	else
		ft_putnbr(arg, g_form.specifier, padding);
}

void	parse_ptr(size_t arg)
{
	size_t	len;
	int		field_width;

	len = ptrlen(arg);
	field_width = g_form.width - len - 2 + (!arg && !g_form.precision);
	if (field_width > 0)
	{
		if (g_form.flags.minus)
		{
			ft_putptr(arg);
			ft_putnchar(' ', field_width);
		}
		else
		{
			ft_putnchar(' ', field_width);
			ft_putptr(arg);
		}
	}
	else
		ft_putptr(arg);
}

void	parse_str(char *arg)
{
	int		field_width;
	size_t	bytes;

	if (arg == NULL)
		arg = "(null)";
	bytes = ft_strlen(arg);
	if (g_form.precision >= 0)
		bytes = (int)ft_strlen(arg) < g_form.precision
		? ft_strlen(arg) : g_form.precision;
	field_width = g_form.width - bytes;
	if (field_width > 0)
		if (g_form.flags.minus)
		{
			ft_putnstr(arg, bytes);
			ft_putnchar(' ', field_width);
		}
		else
		{
			ft_putnchar(' ', field_width);
			ft_putnstr(arg, bytes);
		}
	else
		ft_putnstr(arg, bytes);
}

void	parse_char(int arg)
{
	int		field_width;

	field_width = g_form.width - 1;
	if (field_width > 0)
	{
		if (g_form.flags.minus)
		{
			ft_putnchar(arg, 1);
			ft_putnchar(' ', field_width);
		}
		else if (g_form.flags.zero && g_form.specifier == '%')
		{
			ft_putnchar('0', field_width);
			ft_putnchar(arg, 1);
		}
		else
		{
			ft_putnchar(' ', field_width);
			ft_putnchar(arg, 1);
		}
	}
	else
		ft_putnchar(arg, 1);
}
