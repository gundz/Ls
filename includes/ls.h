#ifndef			LS_H
# define		LS_H

# include <libft.h>

typedef struct			s_dir
{
	char				*path;
	t_list				*files;
}						t_dir;

t_dir					*store_dir(char *path);
int						store_dir_recursive(char *path, t_list **rep_list);
void					show_dir(t_dir *dir);

#endif
