#ifndef			LS_H
# define		LS_H

# define PROG_NAME "ls"

# include <libft.h>
# include <dirent.h>

typedef struct			s_dir
{
	char				*path;
	t_list				*files;
}						t_dir;

t_dir					*store_files(char **argv, int all);
//t_dir					*store_dir_content(char *path, int all);
int                                     store_dir_content(const char *path, t_dir **dir);
int					store_dirs_recursive(t_dir *dir, t_list **rep_list);

int                                     cmpDir(struct dirent *a, struct dirent *b);
void					sort_all(t_list **lst, int rev);

t_dir					*create_dir(char *path);
int					is_dir(const char *path);

int					options(const int argc, char  **argv, char tab[]);
int					get_option(char tab[], char c);

void					showDir(const t_dir *dir, const int show);
void                                    showDirLst(t_list *lst, const int show);

int						show_error(const char *str, const int n);

#endif
