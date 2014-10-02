#include <libft.h>
#include <ls.h>
#include <stddef.h>

void					show_dir(t_dir *dir)
{
	t_list				*lstwalker;
	char				*file;

	lstwalker = dir->files;
	while (lstwalker != NULL)
	{
		file = lstwalker->data;
		ft_putstr(file);
		if (lstwalker->next == NULL)
			break ;
		ft_putstr("\t");
		lstwalker = lstwalker->next;
	}
	ft_putstr("\n");
}
