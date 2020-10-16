#ifndef TEST_H
# define TEST_H
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include "libftprintf.h"

# define BLUE "\x1b[34m"
# define GREEN "\x1b[32m"
# define MAGENTA "\x1b[35m"
# define RESET "\x1b[0m"
# define COLOR1 GREEN
# define COLOR2 BLUE
# define COLOR3 MAGENTA

# define TEST(param)                                     \
 	{                                                    \
 		int a, b;                                        \
 		puts("\t~~~" COLOR3 #param RESET "~~~");         \
 		ft_printf(COLOR2 "Result:" RESET " \t[" COLOR2); \
 		a = ft_printf(param);                            \
 		ft_printf(RESET "]\n");                          \
 		printf(COLOR1 "Expected:" RESET " \t[" COLOR1);  \
 		b = printf(param);                               \
 		printf(RESET "]\n");                             \
 		puts(a == b ? "Length: OK" : "Length: Error");   \
 		sleep(0);                                        \
 	}

/**
 ** Format specifier: %d %i
 */
# define DECIMAL_FLAG_ZERO					"Elpsycongroo %05.10d, %010i", 5, 9

# define DECIMAL_FLAG_MINUS					"El psy congroo! %-5i, %-10i, %-i, %d", 5, 9, 10, 20

# define DECIMAL_FLAG_MINUSZERO				"El psy congroo! %0-5i, %0-10i, %i, %d", 5, 9, 10, 20

# define DECIMAL_PRECISION					"El psy congroo! %.5d, %.10i", 5, 9

# define DECIMAL_PRECISION_NULL             "%5.d", 10

# define DECIMAL_FLAG_ZERO_PRECISION		"El psy congroo! %0.5d, %0.10i", 5, 9

# define DECIMAL_FLAG_ZERO_PRECISION_NULL	"El psy congroo! %0.0d, %0.0i", 5, 9

# define DECIMAL_WIDTH_ASTERISK				"El psy congroo! %*.d", 5, 9

# define DECIMAL_FLAG_MINUS_PRECISION		"El psy congroo! %-.5d, %-.10i", 5, 9


/**
 ** Format specifier: %x %X
 */
# define HEXA_FLAG_MINUS_PRECISION			"El psy %-.5x, %-.10X congroo!", 255, 1228

# define HEXA_PRECISION						"El psy %.5X, %.10x congroo!", 214, 1228

# define HEXA_FLAG_HASH_PRECISION			"El psy %#.5X, %#.10x congroo!", 214, 1228

# define HEXA_FLAG_MINUS_HASH_PRECISION		"El psy %-#.5x, %-#.10X congroo!", 255, 1228

/**
 ** Format specifier: %s
 */
# define STR_WIDTH_LESS "%4s", "Hello"
# define STR_WIDTH_MORE "%10s", "Hello"
# define STR_FLAG_MINUS "%-10s", "Hello"
# define STR_PRECISION_LESS "%.2s", "Hello"
# define STR_PRECISION_MORE "%.10s", "Hello"
# define STR_PRECISION_NULL "%.s", "Hello"
# define STR_PRECISION_ZERO "%.0s", "Hello"
# define STR_WIDTH_PRECISION "%10.2s", "Hello"

/**
** Format specifier: %c
*/
# define C_WIDTH_MORE "%5c", 'H'
# define C_FLAG_MINUS "%-5c", 'H'
#endif // !TEST_H

/*!
** TODO: t_printf ("%x",0)
*/
