#include "libftprintf.h"

void	print_integer(void)
{
	g_format.arg = va_arg(g_arg_list, void *);

	int field_width = g_format.width -numlen((long)g_format.arg,
	g_format.specifier);
	/**
	 ** The precision support
	*/
	if(g_format.precision > (int)numlen(
		(long)g_format.arg, g_format.specifier))
		field_width += g_format.precision - g_format.width;
	/**
	 ** The # flag support
	*/
	if(g_format.flags.hash
	&& (g_format.specifier == 'x' || g_format.specifier == 'X'))
		ft_putnstr( g_format.specifier == 'x' ? "0x" : "0X", 3);
	/**
	 ** The + flag support
	 */
	if((g_format.specifier == 'd' || g_format.specifier == 'i')
	&& g_format.flags.plus && (long)g_format.arg > 0)
		ft_putnchar('+', 1);
	/**
	 ** The space flag (The + flag overrides the space flag)
	 */
	else if((g_format.specifier == 'd' || g_format.specifier == 'i')
	&& g_format.flags.space && (long)g_format.arg > 0)
		ft_putnchar(' ', 1);
	if (field_width > 0)
	{
		if (g_format.flags.minus && g_format.precision < 1)
		{
			cast_and_putnbr();
			ft_putnchar(' ', field_width);
		}
		else
		{
			ft_putnchar( (g_format.flags.zero != (g_format.precision == 0))
				|| (g_format.precision > 0)
				|| (g_format.specifier == 'X' || g_format.specifier == 'x')
				? '0' : ' ', field_width);
			cast_and_putnbr();
		}
	}
	else
		cast_and_putnbr();
}

void	print_pointer(void)
{

}

void	print_string(void)
{

}

void	print_char(void)
{

}

void	print_percent(void)
{

}

void	print_shared(void)
{

}

void	ft_putnchar(char c, size_t n)
{
	while (n--)
	{
		g_counter++;
		write(1, &c, 1);
	}
}

void	ft_putnstr(char *str, size_t n)
{
	while (*str && n--)
	{
		ft_putnchar(*str, 1);
		str++;
	}
}

void	cast_and_putnbr()
{
	if (g_format.length)
	{
		if (g_format.length == 'l')
			ft_putnbr_base((long)g_format.arg, g_format.specifier);
		else if(g_format.length == 'h'
		|| g_format.specifier == 'd'
		|| g_format.specifier == 'i')
			ft_putnbr_base((short)g_format.arg, g_format.specifier);
		else if(g_format.length == 'h' || g_format.specifier == 'u')
			ft_putnbr_base((unsigned short)g_format.arg, g_format.specifier);
	}
	else
	{
		 if (g_format.specifier == 'd' || g_format.specifier == 'i')
			ft_putnbr_base((int)g_format.arg, g_format.specifier);
		else if (g_format.specifier == 'u' || g_format.specifier == 'x'
		|| g_format.specifier == 'X')
			ft_putnbr_base((unsigned int)g_format.arg, g_format.specifier);
	}
}

/**
 ** NOTE: An integer overflow will occur when passing unsigned long
*/
void ft_putnbr_base(long n, char base)
{
	size_t i;
	long temp;
	char num[100];

	if (n < 0)
	{
		ft_putnchar('-' , 1);
		n = ABS(n);
	}
	i = 0;
	while (n)
	{
		temp = 0;
		temp = n % ((base == 'x' || base == 'X') ? 16 : 10);
		if (temp < 10)
			num[i++] = temp + '0';
		else
			num[i++] = temp + (base == 'x' ? 87 : 55);
		n = n / ((base == 'x' || base == 'X') ? 16 : 10);
	}
	while (i--)
		ft_putnchar(num[i], 1);
}

size_t numlen(long num, char base)
{
	size_t count;

	count = 0;
	if (num < 0)
	{
		count += 1;
		num = ABS(num);
	}
	while (num)
	{
		count++;
		num /= (base == 'X' || base == 'x' ? 16 : 10);
	}
	return (count);
}
