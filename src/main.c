/**********************************
 * main file for testing purposes *
 **********************************/

#include "test.h"
#define label(label) puts(#label)

int main()
{
	TEST(DECIMAL_FLAG_ZERO);
	TEST(DECIMAL_FLAG_MINUS);
	// TEST(DECIMAL_FLAG_MINUSZERO);
	TEST(DECIMAL_PRECISION);
	TEST(DECIMAL_FLAG_ZERO_PRECISION);
	TEST(DECIMAL_FLAG_ZERO_PRECISION_NULL);
	TEST(DECIMAL_FLAG_MINUS_PRECISION);
	TEST(HEXA_PRECISION);
	TEST(HEXA_FLAG_MINUS_PRECISION);
	TEST(DECIMAL_WIDTH_ASTERISK);

	return 0;
}
