#include "libftprintf.h"

bool is_flag(void)
{
	return (*g_str == '+' || *g_str == '-' || *g_str == '#' || *g_str == '0' || *g_str == ' ');
}

bool is_width(void)
{
	return ((*g_str > 48 && *g_str <= 57) || *g_str == '*');
}

bool is_precision(void)
{
	/* return (*g_str == '.' && ft_isdigit(*(++g_str))); */
	return (*g_str == '.' && *++g_str);
}

bool is_length(void)
{
	return (*g_str == 'l' || *g_str == 'h');
}

bool is_specifier(void)
{
	return (*g_str == 'd' || *g_str == 'i' || *g_str == 'u' || *g_str == 'x'
	|| *g_str == 'X' || *g_str == 'p' || *g_str == 'c' || *g_str == 's');
}
