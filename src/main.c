/**********************************
 * main file for testing purposes *
 **********************************/

#include "test.h"
#define label(label) puts(#label)

int main()
{
	label(decimal_flag_zero_precision);
	test(decimal_flag_zero_precision);
	return 0;
}

void test(tests)
{
	switch (tests)
	{
	case decimal_flag_zero:
		DECIMAL_FLAG_ZERO
		break;
	case decimal_flag_minus:
		DECIMAL_FLAG_MINUS
		break;
	case decimal_precision:
		DECIMAL_PRECISION
		break;
	case decimal_flag_zero_precision:
		DECIMAL_FLAG_ZERO_PRECISION
		break;
	case decimal_flag_zero_precision_null:
		DECIMAL_FLAG_ZERO_PRECISION_NULL
		break;
	case decimal_flag_minus_precision:
		DECIMAL_FLAG_MINUS_PRECISION
		break;
	default:
		break;
	}
}
