#include "libftprintf.h"

void	get_flag(void)
{
	if(*g_str == '0')
	{
		g_form.flags.zero = true;
		g_str++;
		router_lvl(1);
	}
	else if (*g_str == '-')
	{
		g_form.flags.minus = true;
		g_str++;
		router_lvl(1);
	}
	else if (*g_str == '+')
	{
		g_form.flags.plus = true;
		g_str++;
		router_lvl(1);
	}
	else if (*g_str == ' ')
	{
		g_form.flags.space = true;
		g_str++;
		router_lvl(1);
	}
	else if (*g_str == '#')
	{
		g_form.flags.hash = true;
		g_str++;
		router_lvl(1);
	}
	return ;
}

void	get_width(void)
{
	if(*g_str == '*')
	{
		g_form.width = va_arg(g_arg_list, int);
		if(g_form.width < 0)
		{
			g_form.width = ABS(g_form.width);
			g_form.flags.minus = true;
		}
		g_str++;
	}
	else
	{
		while (ft_isdigit(*g_str))
		{
			g_form.width *= 10;
			g_form.width += *g_str - 48;
			g_str++;
		}
	}
	router_lvl(3);
	return ;
}

/**
** NOTE: A negative precision means the precision is unspecified.
** If only the period is present the precision is set to zero.
*/
void	get_precision(void)
{
	g_form.precision = 0;
	if(*g_str == '*')
	{
		g_form.precision = va_arg(g_arg_list, int);
		g_str++;
	}
	else
	{
		while (ft_isdigit(*g_str))
		{
			g_form.precision *= 10;
			g_form.precision += *g_str - 48;
			g_str++;
		}
	}
	if (g_form.precision == 0 && g_form.flags.zero == true)
		g_form.precision = false;
	router_lvl(4);
	return ;
}

void	get_length(void)
{
	g_form.length = *g_str;
	g_str++;
	router_lvl(5);
	return ;
}

void	get_specifier(void)
{
	g_form.specifier = *g_str;
	router_specifier();
	return ;
}
