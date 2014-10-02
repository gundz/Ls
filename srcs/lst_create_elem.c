#include <libft.h>
#include <stdlib.h>

t_list					*lst_create_elem(void *data)
{
	t_list				*lst;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lst->data = data;
	lst->next = NULL;
	return (lst);
}
