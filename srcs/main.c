#include <stdio.h>
#include <errno.h>
#include <libft.h>
#include <ls.h>

int						main(int argc, char **argv)
{
	t_dir				*dir;

	if (argc != 2)
		return (0);
	dir = store_dir(argv[1]);
	if (!dir)
	{
		perror("");
		return (-1);
	}
	lst_sort(&dir->files, ft_strcmp, 1);
	show_dir(dir);
	return (0);
}
