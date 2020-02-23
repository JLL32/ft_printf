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
	return;
}

void	print_shared()
{

}

void	ft_putchar(char c)
{
	/**
	 * TODO: Move it later to libft
	*/
	g_counter++;
	write(1, &c,1);
	return ;
}
