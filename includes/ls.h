#ifndef			LS_H
# define		LS_H

# define PROG_NAME "ls"

# include <libft.h>

typedef struct			s_dir
{
	char				*path;
	t_list				*files;
}						t_dir;

t_dir					*store_files(const int argc, char **argv);
t_dir					*store_dir_content(char *path);
int						store_dirs_recursive(char *path, t_list **rep_list);
void					show_dir(t_list *lst);
int						show_error(char *str, int n);

#endif
