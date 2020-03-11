#include "libftprintf.h"

void	print_integer(void)
{
	int field_width = g_format.width - numlen((int)g_format.arg, g_format.specifier);
	if(g_format.precision > (int)numlen((int)g_format.arg, g_format.specifier))
		field_width += g_format.precision - g_format.width;
		if (field_width > 0)
		{
			if (g_format.flags.minus && g_format.precision < 1)
			{
				ft_putnbr_base((int)g_format.arg, g_format.specifier);
				ft_putnchar(' ', field_width);
			}
			else
			{
				ft_putnchar((g_format.flags.zero != (g_format.precision == 0)) || g_format.precision ? '0' : ' ', field_width);
				ft_putnbr_base((int)g_format.arg, g_format.specifier);
			}
		}
		else
			ft_putnbr_base((int)g_format.arg, g_format.specifier);
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

	while(n--)
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

void ft_putnbr_base(long n, char base)
{
	size_t i;
	long temp;
	char hexaDeciNum[100];
	if (n < 0)
	{
			ft_putnchar('-', 1);
			n = -n;
	}
    i = 0;
    while(n)
    {
        temp  = 0;
        temp =  n % ((base == 'x' || base == 'X') ? 16 : 10);
        if(temp < 10)
            hexaDeciNum[i++] = temp + '0';
        else
            hexaDeciNum[i++] = temp + (base == 'x' ?  87 : 55);
        n = n/((base == 'x' || base == 'X') ? 16 : 10);
    }
	while (i--)
        ft_putnchar(hexaDeciNum[i], 1);
}

size_t numlen(long long num, char base)
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
		num /= (base == 'X' || base == 'x' ? 16 : 10);
	}
	return (count);
}
