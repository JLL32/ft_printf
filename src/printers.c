#include "libftprintf.h"

void	print_integer(void)
{
	int field_width = g_format.width - numlen((int)g_format.arg);
	if(g_format.precision > (int)numlen((int)g_format.arg))
		field_width += g_format.precision - g_format.width;
	if(g_format.specifier == 'd' || g_format.specifier == 'i')
	{
		if (field_width > 0)
		{
			if(g_format.flags.minus && g_format.precision < 1)
			{
				ft_putnbr((int)g_format.arg);
				ft_putnchar(' ', field_width);
			}
			else
			{
				ft_putnchar((g_format.flags.zero != (g_format.precision == 0)) || g_format.precision ? '0' : ' ', field_width);
				ft_putnbr((int)g_format.arg);
			}
		}
		else
			ft_putnbr((int)g_format.arg);
	}
	return ;
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

void	print_percent(void)
{

}

void	print_shared(void)
{

}

void	ft_putnchar(char c, size_t n)
{

	while(n--)
	{
		g_counter++;
		write(1, &c, 1);
	}
	return ;
}

void	ft_putnstr(char *str, size_t n)
{
	while (*str && n--)
	{
		ft_putnchar(*str, 1);
		str++;
	}
	return ;
}

void	ft_putnbr(long n)
{
		if (n < 0)
		{
			ft_putnchar('-', 1);
			ft_putnbr(-n);
		}
		else if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putnchar(n % 10 + '0', 1);
		}
		else
			ft_putnchar(n + '0', 1);
	return ;
}

size_t numlen(long long num)
{
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
