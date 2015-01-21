#include <libft.h>
#include <ls.h>
#include <stddef.h>
/*
void				main_ls(t_list **lst, char **argv, int all)
{
	int				i;

	lst_push_back(lst, store_files(argv, all));
	i = 1;
	while (argv[i] != '\0')
	{
		if (argv[i][0] != '-')
		{
			if (is_dir(argv[i]) == 1)
				lst_push_back(lst, store_dir_content(argv[i], all));
		}	
		++i;
	}
}

int					main(int argc, char **argv)
{
	static char		tab[256] = {0};
	int				nb_options;
	t_list			*lst;

	nb_options = options(argc, argv, tab);
	lst = NULL;
	if (nb_options == (argc - 1))
		lst_push_back(&lst, store_dir_content("./", get_option(tab, 'a')));
	else 
		main_ls(&lst, argv, get_option(tab, 'a'));
	sort_all(&lst, get_option(tab, 'r'));
	show_dir(lst);
	return (0);
}*/
#include <stdio.h>
#include <dirent.h>

int                                             main2(void)
{
    t_list                                      *lst = NULL;
    t_dir                                       *dir = NULL;

    if (store_dir_content("testd", &dir) == 0)
    {
        lst_push_back(&lst, dir);
        store_dirs_recursive(dir, &lst);
    }
    sort_all(&lst, 0);
    showDirLst(lst, 0);
    return (0);
}

int                                             main(int argc, char **argv)
{
    t_dir                                       *dir;
    t_list                                      *lst;
    int                                         i = 1;

    lst = NULL;
    if (argc > 1)
    {
        while (argv[i] != NULL)
        {
            if (store_dir_content(argv[i], &dir) == 0)
            {
                lst_push_back(&lst, dir);
            }
            i++;
        }
    }
    else
    {
        store_dir_content("./", &dir);
        lst_push_back(&lst, dir);
    }
    sort_all(&lst, 0);
    showDirLst(lst, 0);
}
