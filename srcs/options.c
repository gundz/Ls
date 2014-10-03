#include <stddef.h>

int					options(const int argc, char **argv, char tab[])
{
	int     		i;
	size_t  		j;
	int				nb_options;

	i = 1;	
	nb_options = 0;
	while (i < argc)
	{
		if (argv[i][0] != '-' || argv[i][1] == '-')
			return (nb_options);
		j = 1;
		while (argv[i][j] != '\0')
		{
			tab[(size_t)(unsigned char)argv[i][j]] = 1;
			if (tab[(size_t)(unsigned char)argv[i][j]] == 1)
				++nb_options;
			++j;
		}
		++i;
	}
	return (nb_options);
}

int					get_option(char tab[], char c)
{
	return (tab[(size_t)(unsigned char)c]);
}
