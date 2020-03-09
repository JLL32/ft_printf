#define DECIMAL_FLAG_ZERO	ft_printf("lmao %05i, %010i, %i, %d|\n", 5, 9, 10, 20); \
							printf("lmao %05i, %010i, %i, %d|\n", 5, 9, 10, 20);
enum tests
{
	decimal_flag_zero = 1,
	decimal_flag_minus,
	decimal_flag_minuszero,

};
void test(tests);
