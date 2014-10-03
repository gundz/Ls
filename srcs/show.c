#include <libft.h>
#include <ls.h>
#include <stddef.h>

#include <stdio.h>
void					show_dir2(t_list *lst)
{
	t_list				*lstwalker;

	lstwalker = lst;
	while (lstwalker != NULL)
	{
		ft_putstr(lstwalker->data);
		ft_putstr("\n");
		if (lstwalker->next == NULL)
			break ;
		lstwalker = lstwalker->next;
	}

}

void					show_dir(t_list *lst)
{
	t_list				*lstwalker;
	unsigned int		show_d_name;
	t_dir				*tmp;

	show_d_name = lst_count(lst);
	lstwalker = lst;
	while (lstwalker != NULL)
	{
		tmp = lstwalker->data;
		if (show_d_name > 0 && tmp->path[0] != '\0')
		{
			ft_putstr(tmp->path);
			ft_putstr(" :\n");
		}
		show_dir2(tmp->files);
		if (lstwalker->next == NULL)
			break ;
		lstwalker = lstwalker->next;
		ft_putstr("\n");
	}
}
