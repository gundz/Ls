#include <libft.h>
#include <ls.h>
#include <stdio.h>

int					show_error(char *str, int n)
{
	ft_putstr(PROG_NAME);
	ft_putstr(": ");
	perror(str);
	return (n);
}
