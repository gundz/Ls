#include <sys/types.h>
#include <dirent.h>

#include <stdio.h>
#include <string.h>

#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>


typedef struct				s_list
{
	struct s_list			*next;
	void				*data;
}					t_list;

typedef struct				s_dir
{
	char				*path;
	t_list				*files;
}					t_dir;

t_list					*create_elem(void *data)
{
	t_list				*lst;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

void					lst_push_back(t_list **lst, void *data)
{
	t_list				*lstwalker;

	if (*lst == NULL)
	{
		*lst = create_elem(data);
		return ;
	}
	lstwalker = *lst;
	while (lstwalker != NULL)
	{
		if (lstwalker->next == NULL)
			break ;
		lstwalker = lstwalker->next;
	}
	lstwalker->next = create_elem(data);
}

t_dir					*store_dir(char *path)
{
	DIR				*dir_fd;
	struct dirent			*file;
	t_dir				*dir;

	if (!(dir = (t_dir *)malloc(sizeof(t_dir))))
		return (NULL);
	dir->files = NULL;
	dir->path = path;
	if ((dir_fd = opendir(path)) == NULL)
		return (NULL);
	while ((file = readdir(dir_fd)) != NULL)
	{
		lst_push_back(&dir->files, strdup(file->d_name));
	}
	closedir(dir_fd);
	return (dir);
}

void					swap_list(t_list *lst1, t_list *lst2)
{
	void				*tmp;

	tmp = lst1->data;
	lst1->data = lst2->data;
	lst2->data = tmp;
}

void					sort_list(t_list **lst)
{
	t_list				*lstwalker;
	t_list				*root;

	lstwalker = *lst;
	while (lstwalker != NULL)
	{
		root = *lst;
		while (root != NULL)
		{
			if (root->next != NULL)
			{
				if (strcmp(root->data, root->next->data) > 0)
					swap_list(root, root->next);
			}
			else
				break ;
			root = root->next;
		}
		if (lstwalker->next == NULL)
			break ;
		lstwalker = lstwalker->next;
	}
}

void					show_dir(t_dir *dir)
{
	t_list				*lstwalker;
	char				*file;

	lstwalker = dir->files;
	while (lstwalker != NULL)
	{
		file = lstwalker->data;
		printf("%s", file);
		if (lstwalker->next == NULL)
			break ;
		printf("\t");
		lstwalker = lstwalker->next;
	}
	printf("\n");
}

int					main(int argc, char **argv)
{
	t_dir				*dir;

	if (argc != 2)
		return (0);
	dir = store_dir(argv[1]);
	if (!dir)
	{
		perror("");
		return (-1);
	}
	sort_list(&dir->files);
	show_dir(dir);
	return (0);
}
