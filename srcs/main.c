#include <stdio.h>
#include <errno.h>
#include <libft.h>
#include <ls.h>

int						main_ls2(int argc, char **argv)
{
	t_dir				*dir;

	if (argc != 2)
		dir = store_dir_content("./");
	else
		dir = store_dir_content(argv[1]);
	if (!dir)
	{
		perror("");
		return (-1);
	}
	lst_sort(&dir->files, ft_strcmp, 0);
//	show_dir(dir);
	return (0);
}

int						main_ls_rec(int argc, char **argv)
{
	t_list				*rep_list;
	char				*dir;

	rep_list = NULL;
	if (argc < 2)
	{
		if (store_dirs_recursive(".", &rep_list) == -1)
		{
			perror("");
			return (-1);
		}
	}
	else
	{
		if (store_dirs_recursive(argv[1], &rep_list) == -1)
		{
			perror("");
			return (-1);
		}
		lst_sort(&rep_list, ft_strcmp, 0);
		while (rep_list != NULL)
		{
			printf("%s\n", rep_list->data);
			if (rep_list->next == NULL)
				break ;
			rep_list = rep_list->next;
		}
	}
	return (0);
}

#include <sys/types.h>
#include <sys/stat.h>

void					sort_all(t_list **lst, int rev)
{
	t_list				*lstwalker;
	t_dir				*tmp;

	lst_sort(lst, ft_strcmp, rev);
	lstwalker = *lst;
	while (lstwalker != NULL)
	{
		tmp = lstwalker->data;
		lst_sort(&tmp->files, ft_strcmp, rev);
		if (lstwalker->next == NULL)
			break ;
		lstwalker = lstwalker->next;
	}
}

int						main(int argc, char **argv)
{
	t_list				*lst;
	int					i;
	struct stat			stat_buf;

	if (argc > 1)
	{
		lst = NULL;
		lst_push_back(&lst, store_files(argc, argv));
		i = 1;
		while (argv[i] != '\0')
		{
			if (argv[i][0] != '-')
			{
				if (stat(argv[i], &stat_buf) != -1)
				{
					if (S_ISDIR(stat_buf.st_mode))
						lst_push_back(&lst, store_dir_content(argv[i]));
				}
				++i;
			}
		}
		sort_all(&lst, 0);
		show_dir(lst);
	}
}
