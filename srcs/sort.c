#include <libft.h>
#include <ls.h>
#include <stddef.h>
#include <dirent.h>

int                                     cmpDir(struct dirent *a, struct dirent *b)
{
   return (ft_strcmp(a->d_name, b->d_name));
}

int                                     cmpDirLst(t_dir *a, t_dir *b)
{
    return (ft_strcmp(a->path, b->path));
}

void					sort_all(t_list **lst, int rev)
{
	t_list				*lstwalker;
	t_dir				*tmp;

	if (*lst == NULL)
		return ;
	lst_sort(lst, cmpDirLst, rev);
	lstwalker = *lst;
	while (lstwalker != NULL)
	{
		tmp = lstwalker->data;
		lst_sort(&tmp->files, cmpDir, rev);
		if (lstwalker->next == NULL)
			break ;
		lstwalker = lstwalker->next;
	}
}
