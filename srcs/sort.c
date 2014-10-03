#include <libft.h>
#include <ls.h>
#include <stddef.h>

void					sort_all(t_list **lst, int rev)
{
	t_list				*lstwalker;
	t_dir				*tmp;

	if (*lst == NULL)
		return ;
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
