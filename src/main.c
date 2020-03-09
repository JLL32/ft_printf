/**********************************
 * main file for testing purposes *
 **********************************/

#include "test.h"
#define label(label) puts(#label)

int main()
{
	label(decimal_flag_zero);
	test(decimal_flag_zero);
	return 0;
}

void	test(tests)
{
	switch (tests)
	{
	case decimal_flag_zero:
	DECIMAL_FLAG_ZERO
	break;
	case decimal_flag_minus:
	DECIMAL_FLAG_MINUS
	break;
	default:
		break;
	}
}
