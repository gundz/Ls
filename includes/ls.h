#ifndef			LS_H
# define		LS_H

# define PROG_NAME "ls"

# include <libft.h>

typedef struct			s_dir
{
	char				*path;
	t_list				*files;
}						t_dir;

t_dir					*store_files(char **argv, int all);
t_dir					*store_dir_content(char *path, int all);
int						store_dirs_recursive(char *path, t_list **rep_list);

void					sort_all(t_list **lst, int rev);

t_dir					*create_dir(char *path);
int						is_dir(char *path);

int						options(const int argc, char  **argv, char tab[]);
int						get_option(char tab[], char c);

void					show_dir(t_list *lst);
int						show_error(char *str, int n);

#endif
