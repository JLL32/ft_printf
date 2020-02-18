#include "libftprintf.h"

bool is_flag()
{
	return (*g_str == '+' || *g_str == '-' || *g_str == '#' || *g_str == '*' || *g_str == '0' ? true : false);
}

bool is_width()
{
	return (*g_str > 48 && *g_str <= 57 ? true : false);
}

bool is_precision()
{
	return (*g_str == '.' ? true : false);
}

bool is_length()
{
	return (*g_str == 'l' || *g_str == 'h' ? true : false);
}

bool is_specifier()
{
	return (*g_str == 'd' || *g_str == 'i' || *g_str == 'u' || *g_str == 'x' || *g_str == 'X' );
}
