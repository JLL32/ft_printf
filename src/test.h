#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "libftprintf.h"

#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define MAGENTA "\x1b[35m"
#define RESET "\x1b[0m"
#define COLOR1 GREEN
#define COLOR2 BLUE
#define COLOR3 MAGENTA

#define TEST(param)                                  \
	puts("~~~~"COLOR3 #param RESET"~~~~");              \
	ft_printf(COLOR2 "Result:" RESET " \t[" COLOR2); \
	ft_printf(param);                                \
	ft_printf(RESET "]\n");                          \
	printf(COLOR1 "Expected:" RESET " \t["COLOR1);          \
	printf(param);                                   \
	printf(RESET "]\n");

#define DECIMAL_FLAG_ZERO					"Elpsycongroo %05.10d, %010i", 5, 9

#define DECIMAL_FLAG_MINUS					"El psy congroo! %-5i, %-10i, %-i, %d", 5, 9, 10, 20

#define DECIMAL_FLAG_MINUSZERO				"El psy congroo! %0-5i, %0-10i, %i, %d", 5, 9, 10, 20

#define DECIMAL_PRECISION					"El psy congroo! %.5d, %.10i", 5, 9

#define DECIMAL_FLAG_ZERO_PRECISION			"El psy congroo! %0.5d, %0.10i", 5, 9

#define DECIMAL_FLAG_ZERO_PRECISION_NULL	"El psy congroo! %0.0d, %0.0i", 5, 9

#define DECIMAL_FLAG_MINUS_PRECISION		"El psy congroo! %-.5d, %-.10i", 5, 9

#define HEXA_FLAG_MINUS_PRECISION			"El psy congroo! %-.5x, %-.10X", 5, 9

#define HEXA_PRECISION						"El psy congroo! %.5X, %.10x", 255, 1028

