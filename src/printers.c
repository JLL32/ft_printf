#include "libftprintf.h"

void parse_signed(void)
{
	long arg;
	char prefix;
	int field_width;
	size_t padding;
	padding = 0;

	// set prefix
	// set arg
	// set field_width
	// set padding
	if (ft_tolower(g_form.length) == 'l')
		arg = va_arg(g_arg_list, long);
	else
		arg = va_arg(g_arg_list, int);
	field_width = g_form.width - numlen(arg);
	if(g_form.precision > (int)numlen(arg))
	{
		field_width = field_width - g_form.precision - numlen(arg);
		padding = g_form.precision - numlen(arg) + (arg < 0);
	}
	prefix = '\0';
	if (arg > 0)
	{
		if (g_form.flags.space)
			prefix = ' ';
		else if (g_form.flags.plus)
			prefix = '+';
		field_width -= (g_form.flags.space || g_form.flags.plus);
	}
	if (field_width > 0)
		if (g_form.flags.minus && g_form.precision < 1)
		{
			ft_putsigned(arg, prefix, 0);
			ft_putnchar(' ', field_width);
		}
		else if (g_form.flags.zero || (g_form.precision > 0))
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
	size_t arg;
	char *prefix;
	int field_width;
	size_t padding;
	size_t len;
	padding = 0;

	if (ft_tolower(g_form.length) == 'l')
		arg = va_arg(g_arg_list, unsigned long);
	else
		arg = va_arg(g_arg_list,unsigned int);

	len = unsigned_len(arg, g_form.specifier);
	field_width = g_form.width - len;
	/**
	 ** The precision support
	*/
	// if(g_format.precision > (int)numlen(
	// 	(long)arg))
	// 	field_width += g_format.precision - g_format.width;
	if(g_form.precision > (int)len)
	{
		field_width = field_width - g_form.precision - len;
		padding = g_form.precision - len + (arg < 0);
	}

	/**
	 ** The # flag support
	*/
	prefix = "";
	if(g_form.flags.hash && (g_form.specifier == 'x' || g_form.specifier == 'X')
	&& arg > 0)
	{
		prefix = g_form.specifier == 'x' ? "0x" : "0X";
		field_width -= 2;
	}
	if (field_width > 0)
	{
		if (g_form.flags.minus && g_form.precision < 1)
		{
			ft_putsize(arg, g_form.specifier, prefix, 0);
			ft_putnchar(' ', field_width);
		}
		else if (g_form.flags.zero
				|| (g_form.precision > 0)
				|| ft_tolower(g_form.specifier) == 'x')
		{
			ft_putsize(arg, g_form.specifier, prefix, field_width);
		}
		else
		{
			ft_putnchar(' ', field_width);
			ft_putsize(arg, g_form.specifier, prefix, padding);
		}

	}
	else
		ft_putsize(arg, g_form.specifier, prefix, padding);
}

void	parse_ptr(void)
{
	size_t arg = va_arg(g_arg_list, size_t);
	size_t len = numlen(arg);
	int field_width = g_form.width - len;

	ft_putnstr("0x", 2); // field_width - 2 ?
	if (field_width > 0)
	{
		if (g_form.flags.minus)
		{
			ft_putsize(arg, 'x', "", 0);
			ft_putnchar(' ', field_width);
		}
		else
		{
			ft_putnchar(' ', field_width);
			ft_putsize(arg, 'x', "", 0);
		}
	}
	else
		ft_putsize(arg, 'x', "", 0);
}

void	parse_str(void)
{
	int field_width;
	size_t bytes;
	char *arg;
	if ((arg = va_arg(g_arg_list, char *)) == NULL)
		return ;
	bytes = g_form.precision >= 0 ? g_form.precision
								  : ft_strlen(arg);
	field_width = g_form.width - bytes;
	if (field_width > 0)
	{
		if (g_form.flags.minus)
		{
			ft_putnstr(arg, bytes);
			ft_putnchar(' ', field_width);
		}
		else
		{
			ft_putnchar(' ', field_width);
			ft_putnstr(arg, bytes);
		}
	}
	else
		ft_putnstr(arg, bytes);
}

void	parse_char(void)
{
	int arg = va_arg(g_arg_list, int);
	int field_width = g_form.width - 1;
	if (arg == 0) {
		write(1, &arg, 1);
		g_counter++;
		return ;
	}
	if (field_width > 0)
	{
		if (g_form.flags.minus)
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

void	parse_percent(void)
{
	int arg = '%';
	int field_width = g_form.width - 1;
	if (field_width > 0)
	{
		if (g_form.flags.minus)
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
	if (n == 0)
	{
		if (g_form.precision != 0)
			ft_putnchar('0', 1);
		return;
	}
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

	ft_putnstr(prefix, 2);
	ft_putnchar('0', padding);
	if (n == 0)
	{
		if (g_form.precision != 0)
			ft_putnchar('0', 1);
		return ;
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

void ft_putunsigned(size_t ptr) {
	size_t i;
	size_t temp;
	char num[100];

	if (ptr == 0)
	{
		if (g_form.precision != 0)
			ft_putnchar('0', 1);
		return ;
	}
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

size_t unsigned_len(size_t ptr, char base)
{
	size_t count;

	count = 0;
	if (ptr == 0)
		count++;
	while (ptr)
	{
		count++;
		ptr /= ft_tolower(base) == 'x' ? 16 : 10;
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
	if (num == 0)
		count++;
	while (num)
	{
		count++;
		num /= 10;
	}
	return (count);
}

void parse_n(void)
{
	// long *arg;

	// if (g_form.length == 'l')
	// 	arg = va_arg(g_arg_list, long *);
	// else if (g_form.length == 'h')
	// 	arg = va_arg(g_arg_list, short *);
	// else
	// 	arg = va_arg(g_arg_list, int *);
	// *arg = g_counter;
	return;
}
