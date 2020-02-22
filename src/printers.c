#include "libftprintf.h"

void	print_integer()
{
	/**
	 * TODO: Implement the flag
	*/
	return;
}

void	print_pointer()
{
	return;
}

void	print_string()
{
	return;
}

void	print_char()
{

	write(1,(char *)g_format.arg,1);
	g_counter++;
	return;
}
