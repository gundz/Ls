#include <stdio.h>

void				options(const int argc, char **argv, char tab[])
{
	int     		i;
	size_t  		j;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-' || argv[i][1] == '-')
			return ;
		j = 1;
		while (argv[i][j] != '\0')
		{
			tab[(size_t)(unsigned char)argv[i][j]] = 1;
			++j;
		}
		++i;
	}
}


int					main(int argc, char **argv)
{
	static char 	tab[256] = {0}; 

	options(argc, argv, tab);
	if (tab[(size_t)(unsigned char)'f'] == 1)
		printf("Option f !");
	if (tab[(size_t)(unsigned char)'r'] == 1)
		printf("Option r !");
	return (0);
}
