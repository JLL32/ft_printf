#include "libftprintf.h"

void	print_integer(void)
{
	/**
	 * TODO: Implement the flag
	*/
	return;
}

void	print_pointer(void)
{
	return;
}

void	print_string(void)
{
	return;
}

void	print_char(void)
{

	write(1,(char *)g_format.arg,1);
	g_counter++;
	return;
}
