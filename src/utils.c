#include "utils.h"

int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

int	ft_tolower(int c)
{
	return((c >= 'A' && c <= 'Z') || (c >= 0xC0 && c <= 0xDD) ? c + 32 : c);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}
