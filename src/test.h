#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "libftprintf.h"

#define DECIMAL_FLAG_ZERO		ft_printf("lmao %05.10d, %010i|\n", 5, 9); \
								printf("lmao %05.10d, %010i|\n", 5, 9);

#define DECIMAL_FLAG_MINUS		ft_printf("lmao %-5i, %-10i, %-i, %d|\n", 5, 9, 10, 20); \
								printf("lmao %-5i, %-10i, %-i, %d|\n", 5, 9, 10, 20);

#define DECIMAL_FLAG_MINUSZERO	ft_printf("lmao %05i, %010i, %i, %d|\n", 5, 9, 10, 20); \
								printf("lmao %05i, %010i, %i, %d|\n", 5, 9, 10, 20);
enum tests
{
	decimal_flag_zero = 1,
	decimal_flag_minus,
	decimal_flag_minuszero,

};

void test(int test);
