#include <stdio.h>
#include <errno.h>
#include <libft.h>
#include <ls.h>

int						main_ls(int argc, char **argv)
{
	t_dir				*dir;

	if (argc != 2)
		dir = store_dir("./");
	else
		dir = store_dir(argv[1]);
	if (!dir)
	{
		perror("");
		return (-1);
	}
	lst_sort(&dir->files, ft_strcmp, 0);
	show_dir(dir);
	return (0);
}

int						main(int argc, char **argv)
{
	t_list				*rep_list;
	char				*dir;

	rep_list = NULL;
	if (argc < 2)
	{
		if (store_dir_recursive(".", &rep_list) == -1)
		{
			perror("");
			return (-1);
		}
	}
	else
	{
		if (store_dir_recursive(argv[1], &rep_list) == -1)
		{
			perror("");
			return (-1);
		}
	}
	return (0);
}
