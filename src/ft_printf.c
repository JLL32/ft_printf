#include "libft/libft.h"
#include "libftprintf.h"

int	isspecifier(char str)
{
	if (str == 'd' || str == 'i' || str == 'u' || str == 'x' || str == 'X'
			|| str == 'c' || str == 's' || str == 'p' || str == '%')
	{
		specifier = str;
		return (1);
	}
	return (0);
}

int num_check(char *str)	// checks the nature of the precision or mfw's values
				// and then converts it to an int
{
	int num;

	if (*str == '*') 	// if the value is an asterisk replace it with next argument
				// and check if the argument itself contains any flags
	{
		num = va_arg(ap, int);
		if (num < 0 && !precisiondot_found)
		{
			num *= -1;
			minusflag_found = 1;
		}
		if (num == 0 && !precisiondot_found)
			zeroflag_found = 1;
	}
	else			// if the value is a normal number,
				// loop through it all and convert it to int
	{
		num = *str - 48;
		while (ft_isdigit(++*str))
			num = (num * 10) + (*str - 48);
	}
	return (num);
}

int	ft_printf(const char *s, ...)
{
	char *str; 	// this will point to the string literal
			// and we'll loop through it

	// all the following variables declared in libftprintf.h
	// they are collecting all the data that exist after the % sign
	// there are two types of this data:
	// boolean: for flags (-; 0; .;) and mfw, and it is either: found (1) or not found (0)
	// value: minimum field width value; precision value
	minusflag_found = 0;
	zeroflag_found = 0;
	precisiondot_found = 0;
	mfwidth_val = 0;
	precision_val = -1;	// if a precision is zero, it doesn't mean that
				// there is no precision, it applies a precision of 0
				// that's why the intialization is set to negative
				// if there was no precision specified it will be set to negative

	counter = 0; 	// this counts the number of characters that will be printed
			// this is the value printf returns

	va_start(ap, s); // makes ap point to the first unnamed argument
	str = (char *)s;
	while (*str)
	{
		counter++;

		/* all of the following code will be in a separate function
		 * containing calls to more separate functions */
		if (*str == '%')	// now we'll check which flags exist and of what value
		{
			str++;
			while (!isspecifier(*str))	// while the conversion specifier
							// is not found, collect all data
			{
				minusflag_found = (*str == '-') ? 1 : minusflag_found;
				zeroflag_found = (*str == '0') ? 1 : zeroflag_found;
				precisiondot_found = (*str == '.') ? 1 : precisiondot_found;
				if (ft_isdigit(*str) || *str == '*')
				{
					if (precisiondot_found)
						precision_val = num_check(str);
					else
						mfwidth_val = num_check(str);
				}
				str++;
			}
			if (precisiondot_found && precision_val < 0)
				precision_val = -1; 	// if the - sign is present in
							// in the precision value,
							// then we cancel the precision

			specifier = *(str++);	// after getting out of the while loop,
						// it means we've found the conversion
						// specifier. we assign it and then
						// increment to the next character.

			/* data management begins here */
				// managing the output for the current % formatting
				// using all the data we got to create
				// the right conditions and shit
				// don't forget to count the final output's characters
			/* data management ends here */
		}
		else
			ft_putchar_fd(*(str++), 1);

		/* reinitialize data here */
	}

	return (counter);
}
