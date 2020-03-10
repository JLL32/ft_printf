#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "libftprintf.h"

#define DECIMAL_FLAG_ZERO					ft_printf("lmao %05.10d, %010i|\n", 5, 9); \
											printf("lmao %05.10d, %010i|\n", 5, 9);

#define DECIMAL_FLAG_MINUS					ft_printf("lmao %-5i, %-10i, %-i, %d|\n", 5, 9, 10, 20); \
											printf("lmao %-5i, %-10i, %-i, %d|\n", 5, 9, 10, 20);

#define DECIMAL_FLAG_MINUSZERO				ft_printf("lmao %0-5i, %0-10i, %i, %d|\n", 5, 9, 10, 20); \
											printf("lmao %0-5i, %0-10i, %i, %d|\n", 5, 9, 10, 20);
#define DECIMAL_PRECISION					ft_printf("lmao %.5d, %.10i|\n", 5, 9); \
											printf("lmao %.5d, %.10i|\n", 5, 9);
#define DECIMAL_FLAG_ZERO_PRECISION			ft_printf("lmao %0.5d, %0.10i|\n", 5, 9); \
											printf("lmao %0.5d, %0.10i|\n", 5, 9);
#define DECIMAL_FLAG_ZERO_PRECISION_NULL	ft_printf("lmao %0.0d, %0.0i|\n", 5, 9); \
											printf("lmao %0.0d, %0.0i|\n", 5, 9);
#define DECIMAL_FLAG_MINUS_PRECISION		ft_printf("lmao %-.5d, %-.10i|\n", 5, 9); \
											printf("lmao %-.5d, %-.10i|\n", 5, 9);

enum tests
{
	decimal_flag_zero = 1,
	decimal_flag_minus,
	decimal_flag_minuszero,
	decimal_precision,
	decimal_flag_zero_precision,
	decimal_flag_zero_precision_null,
	decimal_flag_minus_precision,
};

void test(int test);
