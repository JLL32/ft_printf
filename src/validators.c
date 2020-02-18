#include "libftprintf.h"

bool is_flag()
{
	return (*g_str == '+' || *g_str == '-' || *g_str == '#' || *g_str == '0');
}

bool is_width()
{
	return ((*g_str > 48 && *g_str <= 57) || *g_str == '*');
}

bool is_precision()
{
	return (*g_str == '.');
}

bool is_length()
{
	return (*g_str == 'l' || *g_str == 'h');
}

bool is_specifier()
{
	return (*g_str == 'd' || *g_str == 'i' || *g_str == 'u' || *g_str == 'x'
	|| *g_str == 'X' || *g_str == 'p' || *g_str == 'c' || *g_str == 's');
}
