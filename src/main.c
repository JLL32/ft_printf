// main file for testing purposes

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "libftprintf.h"

int	main()
{
	//puts("Mine-------\n");
	ft_printf("lmao %05i, %-7i, %i, %d|\n", 5, 9, 10, 20);
	printf("lmao %05i, %-7i, %i, %d|\n", 5, 9, 10, 20);
	//puts("-----------\n");
	//printf("lmao %-20d %20d\n", 5, 9);
	return 0;
}
