#include <unistd.h>

void					ft_putstr(const char *const str)
{
	unsigned int		len;

	len = 0;
	while (str[len] != '\0')
		len++;
	write(1, str, len);
}
