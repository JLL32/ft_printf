#include "libft/libft.h"
#include "libftprintf.h"
#include <stdarg.h>

void parse_signed(void)
{
	long arg;
	char prefix;
	int field_width;
	size_t padding;

// set prefix
// set arg
// set field_width
// set padding
	if (ft_tolower(g_format.length) == 'l')
		arg = va_arg(g_arg_list, long);
	else
		arg = va_arg(g_arg_list, int);
	field_width = g_format.width - numlen(arg);
	if(g_format.precision > (int)numlen(arg))
	{
		field_width = field_width - g_format.precision - numlen(arg);
		padding = g_format.precision - numlen(arg) + (arg < 0);
	}
	prefix = '\0';
	if (arg > 0)
	{
		if (g_format.flags.space)
			prefix = ' ';
		else if (g_format.flags.plus)
			prefix = '+';
		field_width -= (g_format.flags.space || g_format.flags.plus);
	}
	if (field_width > 0)
		if (g_format.flags.minus && g_format.precision < 1)
		{
			ft_putsigned(arg, prefix, 0);
			ft_putnchar(' ', field_width);
		}
		else if (g_format.flags.zero && (g_format.precision > 0))
		{
			ft_putsigned(arg, prefix, field_width);
		}
		else
		{
			ft_putnchar(' ', field_width);
			ft_putsigned(arg, prefix, padding);
		}
	else
		ft_putsigned(arg, prefix, padding);
}

void parse_unsigned(void)
{
	long arg;
	char *prefix;
	int field_width;
	size_t padding;

	if (ft_tolower(g_format.length) == 'l')
		arg = va_arg(g_arg_list, unsigned long);
	else
		arg = va_arg(g_arg_list,unsigned int);

	field_width = g_format.width - unsigned_len(arg);
	/**
	 ** The precision support
	*/
	// if(g_format.precision > (int)numlen(
	// 	(long)arg))
	// 	field_width += g_format.precision - g_format.width;
	if(g_format.precision > (int)unsigned_len(arg))
	{
		field_width = field_width - g_format.precision - numlen(arg);
		padding = g_format.precision - numlen(arg) + (arg < 0);
	}

	/**
	 ** The # flag support
	*/
	prefix = "";
	if(g_format.flags.hash &&
	 (g_format.specifier == 'x' || g_format.specifier == 'X')
	 && arg > 0)
	{
		prefix = (g_format.specifier == 'x' ? "0x" : "0X", 3);
		field_width -= 2;
	}
	if (field_width > 0)
	{
		if (g_format.flags.minus && g_format.precision < 1)
		{
			/* cast_and_putnbr(arg); */
			ft_putnchar(' ', field_width);
		}
		else if (g_format.flags.zero && g_format.precision > 0 || tf_tolower(g_format.specifier) == 'x')
		{
			ft_putsize(arg, g_format.specifier, prefix, field_width);
		}
		else
		{
			ft_putnchar(' ', field_width);
			ft_putsize(arg, g_format.specifier, prefix, padding);
		}

	}
	else
	{
			/* cast_and_putnbr(arg); */
	}
}

void	print_pointer(void)
{
	size_t arg = va_arg(g_arg_list, size_t);
	size_t len = numlen(arg);
	int field_width = g_format.width - len;

	ft_putnstr("0x", 2); // field_width - 2 ?
	if (field_width > 0)
	{
		if (g_format.flags.minus)
		{
			ft_putunsigned(arg);
			ft_putnchar(' ', field_width);
		}
		else
		{
			ft_putnchar(' ', field_width);
			ft_putunsigned(arg);
		}
	}
	else
		ft_putunsigned(arg);
}

/**
 ** NOTE: if the precision is bigger than -1 simply means it exists
 */
void	print_string(void)
{
	/**
	 ** TODO: STR_WIDTH_PRECISION
	 */
	int field_width;
	size_t bytes;
	g_format.arg = va_arg(g_arg_list, char *);
	bytes = g_format.precision >= 0 ? g_format.precision
									: ft_strlen(g_format.arg);
	field_width = g_format.width - bytes;
	if (field_width > 0)
	{
		if (g_format.flags.minus)
		{
			ft_putnstr(g_format.arg, bytes);
			ft_putnchar(' ', field_width);
		}
		else
		{
			ft_putnchar(' ', field_width);
			ft_putnstr(g_format.arg, bytes);
		}
	}
	else
		ft_putnstr(g_format.arg, bytes);
}

void	print_char(void)
{
	int arg = va_arg(g_arg_list, int);
	int field_width = g_format.width - 1;
	if (field_width > 0)
	{
		if (g_format.flags.minus)
		{
			ft_putnchar(arg, 1);
			ft_putnchar(' ', field_width);
		}
		else
	{
			ft_putnchar(' ', field_width);
			ft_putnchar(arg, 1);
		}
	}
	else
		ft_putnchar(arg, 1);
}

void	print_percent(void)
{
	int arg = '%';
	int field_width = g_format.width - 1;
	if (field_width > 0)
	{
		if (g_format.flags.minus)
		{
			ft_putnchar(arg, 1);
			ft_putnchar(' ', field_width);
		}
		else
		{
			ft_putnchar(' ', field_width);
			ft_putnchar(arg, 1);
		}
	}
	else
		ft_putnchar(arg, 1);
}

void	print_shared(void)
{

}

void	ft_putnchar(char c, size_t n)
{
	while (c && n--)
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

void ft_putsigned(long n, char prefix, size_t padding)
{
	size_t i;
	long temp;
	char num[100];

	if (n < 0)
	{
		prefix = '-';
		n = ABS(n);
	}
	ft_putnchar(prefix, 1);
	ft_putnchar('0', padding);
	i = 0;
	while (n)
	{
		temp = 0;
		temp = n % 10;
		if (temp < 10)
			num[i++] = temp + '0';
		else
			num[i++] = temp + 55;
		n = n / 10;
	}
	while (i--)
		ft_putnchar(num[i], 1);
}

void ft_putsize(size_t n, char base, char * prefix, size_t padding)
{
	size_t i;
	size_t temp;
	char num[100];

	i = 0;
	while (*prefix)
	{
		num[i] = *prefix;
		prefix++;
	}
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
	i = 0;
	while (i--)
		ft_putnchar(num[i], 1);
}

void ft_putunsigned(size_t ptr) {
	size_t i;
	size_t temp;
	char num[100];

	i = 0;
	while (ptr)
	{
		temp = 0;
		temp = ptr % 16;
		if (temp < 10)
			num[i++] = temp + '0';
		else
			num[i++] = temp + 55;
		ptr = ptr / 16;
	}
	while(i--)
		ft_putnchar(num[i], 1);
}

size_t unsigned_len(size_t ptr)
{
	size_t count;

	count = 0;
	while (ptr)
	{
		count++;
		ptr /= 16;
	}
	return (count);
}

size_t numlen(long num)
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
		num /= 10;
	}
	return (count);
}
