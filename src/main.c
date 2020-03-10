/**********************************
 * main file for testing purposes *
 **********************************/

#include "test.h"
#define label(label) puts(#label)

int main()
{
	label(decimal_flag_zero);
	test(decimal_flag_zero);
	printf("%d\n", g_format.precision);
	return 0;
}

void test(tests)
{
	switch (tests)
	{
	case decimal_flag_zero:
		ft_printf("lmao %05.10d, %010i|\n", 5, 9);
		printf("lmao %05.10d, %010i|\n", 5, 9);
		break;
	case decimal_flag_minus:
		DECIMAL_FLAG_MINUS
		break;
	default:
		break;
	}
}
