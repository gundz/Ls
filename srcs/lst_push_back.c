#include <libft.h>
#include <stddef.h>

void					lst_push_back(t_list **lst, void *data)
{
	t_list				*lstwalker;

	if (*lst == NULL)
	{
		*lst = lst_create_elem(data);
		return ;
	}
	lstwalker = *lst;
	while (lstwalker != NULL)
	{
		if (lstwalker->next == NULL)
			break ;
		lstwalker = lstwalker->next;
	}
	lstwalker->next = lst_create_elem(data);
}
