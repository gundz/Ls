#include <ls.h>
#include <libft.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

t_dir					*store_dir(char *path)
{
	DIR					*dir_fd;
	struct dirent		*file;
	t_dir				*dir;

	if (!(dir = (t_dir *)malloc(sizeof(t_dir))))
		return (NULL);
	dir->files = NULL;
	dir->path = path;
	if ((dir_fd = opendir(path)) == NULL)
		return (NULL);
	while ((file = readdir(dir_fd)) != NULL)
	{
		lst_push_back(&dir->files, ft_strdup(file->d_name));
	}
	closedir(dir_fd);
	return (dir);
}
