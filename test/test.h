/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jll32 <jll32@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:05:20 by jll32             #+#    #+#             */
/*   Updated: 2020/11/04 18:53:55 by jll32            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include "../src/libftprintf.h"

# define BLUE "\x1b[34m"
# define GREEN "\x1b[32m"
# define MAGENTA "\x1b[35m"
# define RESET "\x1b[0m"
# define COLOR1 GREEN
# define COLOR2 BLUE
# define COLOR3 MAGENTA

# define TEST(param)                                     \
 	{                                                    \
 		int a, b;                                        \
 		puts("\t~~~" COLOR3 #param RESET "~~~");         \
 		ft_printf(COLOR2 "Result:" RESET " \t[" COLOR2); \
 		a = ft_printf(param);                            \
 		ft_printf(RESET "]\n");                          \
 		printf(COLOR1 "Expected:" RESET " \t[" COLOR1);  \
 		b = printf(param);                               \
 		printf(RESET "]\n");                             \
 		puts(a == b ? "Length: OK" : "Length: Error");   \
 		sleep(0);                                        \
 	}

/**
 ** Format specifier: %d %i
 */
# define DECIMAL_FLAG_ZERO					"Elpsycongroo %05.10d, %010i", 5, 9
# define DECIMAL_FLAG_MINUS					"El psy congroo! %-5i, %-10i, %-i, %d", 5, 9, 10, 20
# define DECIMAL_FLAG_MINUSZERO				"El psy congroo! %0-5i, %0-10i, %i, %d", 5, 9, 10, 20

/* # define DECIMAL_PRECISION					"El psy congroo! %.5d, %.10i", 5, 9 */

# define DECIMAL_PRECISION_NULL				"%5.d", 10
# define DECIMAL_FLAG_ZERO_PRECISION		"El psy congroo! %0.5d, %0.10i", 5, 9
# define DECIMAL_FLAG_ZERO_PRECISION_NULL	"El psy congroo! %0.0d, %0.0i", 5, 9
# define DECIMAL_WIDTH_ASTERISK				"El psy congroo! %*.d", 5, 9
# define DECIMAL_FLAG_MINUS_PRECISION		"El psy congroo! %-.5d, %-.10i", 5, 9

# define DECIMAL_WIDTH						"%8d|%8d", 123, -123
# define DECIMAL_MINUS						"%-8d|%-8d", 123, -123
# define DECIMAL_PLUS						"%+8d|%+8d", 123, -123
# define DECIMAL_SPACE						"% 8d|% 8d", 123, -123
# define DECIMAL_ZERO						"%08d|%08d", 123, -123
# define DECIMAL_MINUS_PLUS					"%-+8d|%-+8d", 123, -123
# define DECIMAL_MINUS_SPACE				"%- 8d|%- 8d", 123, -123
# define DECIMAL_PLUS_ZERO					"%+08d|%+08d", 123, -123
# define DECIMAL_SPACE_ZERO					"% 08d|% 08d", 123, -123
# define DECIMAL_PRECISION					"%.8d|%.8d", 123, -123
# define DECIMAL_WIDTH_PRECISION_ZERO		"%4.d|%4.d", 123, -123
# define DECIMAL_MINUS_PRECISION			"%-4.8d|%-4.8d", 123, -123


/**
 ** Format specifier: %x %X
 */
# define HEXA_FLAG_MINUS_PRECISION			"El psy %-.5x, %-.10X congroo!", 255, 1228

# define HEXA_PRECISION						"El psy %.5X, %.10x congroo!", 214, 1228

# define HEXA_FLAG_HASH_PRECISION			"El psy %#.5X, %#.10x congroo!", 214, 1228

# define HEXA_FLAG_MINUS_HASH_PRECISION		"El psy %-#.5x, %-#.10X congroo!", 255, 1228

/**
 ** Format specifier: %u
*/
# define U_WIDTH							"%8u", 123
# define U_MINUS							"%-8u", 123
# define U_SPACE							"% 8u", 123
# define U_ZERO								"%08u", 123
# define U_MINUS_SPACE						"%- 8u", 123
# define U_SPACE_ZERO						"% 08u", 123
# define U_PRECISION						"%.8u", 123
# define U_WIDTH_PRECISION_ZERO				"%4.u", 123
# define U_MINUS_PRECISION					"%-4.8u", 123

/**
 ** Format specifier: %s
 */
# define STR_WIDTH_LESS						"%4s", "Hello"
# define STR_WIDTH_MORE						"%10s", "Hello"
# define STR_FLAG_MINUS						"%-10s", "Hello"
# define STR_PRECISION_LESS					"%.2s", "Hello"
# define STR_PRECISION_MORE					"%.10s", "Hello"
# define STR_PRECISION_NULL					"%.s", "Hello"
# define STR_PRECISION_ZERO					"%.0s", "Hello"
# define STR_WIDTH_PRECISION				"%10.2s", "Hello"
# define S_WIDTH							"%6s|%6s", "bogus", "buzzword"
# define S_MINUS_WIDTH						"%-6s|%-6s", "bogus", "buzzword"
# define S_PRECISION						"%.4s|%.4s", "bogus", "buzzword"
# define S_WIDTH_PRECISION					"%6.4s|%6.4s", "bogus", "buzzword"
# define S_MINUS_WIDTH_PRECISION			"%-6.4s|%-6.4s", "bogus", "buzzword"


/**
** Format specifier: %c
*/
# define C_WIDTH_MORE						"%5c", 'H'
# define C_FLAG_MINUS						"%-5c", 'H'

/**
** Format specifier: %p
*/
int leet = 1337;
void *ptr = &leet;
# define P_WIDTH							"%20p", ptr
# define P_FLAG_MINUS						"%-20p", ptr

# define TEST_1 "Bla bla %d", 0
# define TEST_2 "Bla bla %c", 0
# define TEST_3 "Bla bla %s", 0
# define TEST_4 "Bla bla %%"
# define TEST_5 "Bla bla %.d", 0
# define TEST_6 "Bla bla %3c", 0
# define TEST_7 "Bla bla %3x", 0
# define TEST_8 "Bla bla %3x", 123
# define TEST_9 "Bla bla %*p", 3, 0
# define TEST_10 "Bla bla %*p", 10, (void*)-1
# define TEST_11 "Bla bla %*.d", 3, 0
# define TEST_12 "Bla bla %*.3d", 10, 0
# define TEST_13 "Bla bla %*.3d", -15, 0
# define TEST_14 "Bla bla %*.10d", -15, -123
# define TEST_15 "Bla bla %*.3s", 10, ""
# define TEST_16 "Bla bla %03u", 0
# define TEST_17 "Bla bla %*.u", 3, 0
# define TEST_18 "Bla bla %*.3u", 10, 0
# define TEST_19 "this is just a %040.20d\n" ,0
# define TEST_20 "this is just a %040d\n", 0
# define TEST_21 "this is just a %020.1d\n",0
# define TEST_22 "%.0s", (void *)22
# define TEST_23 "%p", NULL
#endif // !TEST_H



/*!
** TODO: t_printf ("%x",0)
*/
