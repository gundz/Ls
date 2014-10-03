#include <libft.h>
#include <ls.h>
#include <stddef.h>

void					main_ls(t_list **lst, char **argv)
{
	int					i;

	lst_push_back(lst, store_files(argv));
	i = 1;
	while (argv[i] != '\0')
	{
		if (argv[i][0] != '-')
		{
			if (is_dir(argv[i]) == 1)
				lst_push_back(lst, store_dir_content(argv[i]));
			++i;
		}
	}
}

int						main(int argc, char **argv)
{
	t_list				*lst;

	lst = NULL;
	if (argc > 1)
		main_ls(&lst, argv);
	else
		lst_push_back(&lst, store_dir_content("./"));
	sort_all(&lst, 0);
	show_dir(lst);
	return (0);
}
