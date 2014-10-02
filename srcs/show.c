#include <libft.h>
#include <ls.h>
#include <stddef.h>

#include <stdio.h>
void					show_dir(t_list *lst)
{
	t_list				*lstwalker;
	t_list				*lstwalker2;
	t_dir				*tmp;

	lstwalker = lst;
	while (lstwalker != NULL)
	{
		tmp = lstwalker->data;
		lstwalker2 = tmp->files;
		if (tmp->path[0] != '\0')
			printf("%s :\n", tmp->path);
		while (lstwalker2 != NULL)
		{
			printf("%s", lstwalker2->data);
			if (lstwalker2->next == NULL)
				break ;
			lstwalker2 = lstwalker2->next;
			printf("\n");
		}
		if (lstwalker->next == NULL)
			break ;
		lstwalker = lstwalker->next;
		printf("\n\n");
	}
	printf("\n");
}
