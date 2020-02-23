#include "libftprintf.h"
#include "routers.c"
#include "libft/libft.h"

void	get_flag(void)
{
	//int i;

	//i = 0;
	if(*g_str == '0')
	{
		g_format.flags.zero = true;
		g_str++;
		router_lvl(1);
	}
	else if (*g_str == '-')
	{
		g_format.flags.minus = true;
		g_str++;
		router_lvl(1);
	}
	else if (*g_str == '+')
	{
		g_format.flags.plus = true;
		g_str++;
		router_lvl(1);
	}
	else if (*g_str == ' ')
	{
		g_format.flags.space = true;
		g_str++;
		router_lvl(1);
	}
	else if (*g_str == '#')
	{
		g_format.flags.hash = true;
		g_str++;
		router_lvl(1);
	}
	router_lvl(2);
	return ;
}

void	get_width(void)
{
	while (ft_isdigit(*g_str) || *g_str == '*')
	{
		if(*g_str == '*')
		{
			g_format.width = -42;
			break ;
		}
		else
		{
			g_format.width *= 10;
			g_format.width += *g_str - 48;
		}
		g_str++;
	}
	router_lvl(3);
	return ;
}

void	get_precision(void)
{
	g_str++;
	while (ft_isdigit(*g_str))
	{
		g_format.precision *= 10;
		g_format.precision += *g_str - 48;
		g_str++;
	}
	router_lvl(4);
	return ;
}

void	get_length(void)
{
	g_format.length = *g_str;
	g_str++;
	router_lvl(5);
	return ;
}

void	get_specifier(void)
{
	g_format.specifier = *g_str;
	g_str++;
	router_specifier();
	return ;
}
