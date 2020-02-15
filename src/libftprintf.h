#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

va_list arg_list;
char specifier;
int counter;

int	ft_printf(const char *s, ...);

#endif
