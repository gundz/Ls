#include <libft.h>
#include <ls.h>
#include <stdlib.h>
#include <sys/stat.h>


t_dir					*create_dir(char *path)
{
	t_dir				*dir;

	if (!(dir = (t_dir *)malloc(sizeof(t_dir))))
		return (NULL);
	dir->files = NULL;
	dir->path = ft_strdup(path);
	return (dir);
}

int						is_dir(const char *path)
{
	struct stat			stat_buf;

	if (stat(path, &stat_buf) != -1)
	{
		if (S_ISDIR(stat_buf.st_mode))
			return (1);
	}
	else
		return (show_error(path, -1));
	return (0);
}
