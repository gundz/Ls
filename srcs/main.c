#include <libft.h>
#include <ls.h>
#include <stddef.h>

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
}
