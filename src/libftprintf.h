#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
#define IS_SPECIFIER(c) (c) == 'd' || (c) == 'i' || (c) == 'x ' || (c) == 'X' || (c) == 'u';
va_list arg_list;
char	specifier;
int		counter;

int		ft_printf(const char *s, ...);
void	router(char **str, void *arg);


typedef struct s_format
{
	/* data */
} t_format;

#endif
