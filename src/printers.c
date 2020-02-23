#include "libftprintf.h"

void	print_integer(void)
{
	int field_width = g_format.width - numlen(g_format.width);
	if (field_width > 0)
	{
		if (g_format.flags.zero || !g_format.flags.minus)
		{
			while(field_width--)
				ft_putchar('0');
		}
	}
	ft_putnbr((int)g_format.arg);
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

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

size_t numlen(long long num)
{
	/**
	 * TODO: Move it later to libft
	*/
	size_t count;

	count = 0;
	if (num < 0)
	{
		count += 1;
		num *= -1;
	}
	while (num)
	{
		count++;
		num /= 10;
	}
	return (count);
}
