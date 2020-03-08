// main file for testing purposes

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "libftprintf.h"

enum tests
{
	decimal_with_flag_zero = 1,
	decimal_with_flag_minus,
	decimal_with_flag_minuszero,

};
void test(int tests);

int main()
{
	test(decimal_with_flag_zero);
	return 0;
}

void	test(tests)
{
	switch (tests)
	{
	case decimal_with_flag_zero:
		ft_printf("lmao %05i, %010i, %i, %d|\n", 5, 9, 10, 20);
		printf("lmao %05i, %010i, %i, %d|\n", 5, 9, 10, 20);
		break;

	default:
		break;
	}
}
