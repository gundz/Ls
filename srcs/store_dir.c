#include <ls.h>
#include <libft.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>
#include <string.h>
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

int						store_dir_recursive(char *path, t_list **rep_list)
{
	DIR					*dir_fd;
	struct dirent		*file;
	struct stat			stat_buf;

	printf("%s\n", path);
	if ((dir_fd = opendir(path)) == NULL)
		return (-1);
	while ((file = readdir(dir_fd)) != NULL)
	{
		if (ft_strcmp(file->d_name, "..") != 0 && ft_strcmp(file->d_name, ".") != 0)
		{
			char	*tmp = ft_strcat(path, "/");
			tmp = ft_strcat(tmp, file->d_name);
			if (stat(tmp, &stat_buf) == -1)
				return (-1);
			if (S_ISDIR(stat_buf.st_mode))
			{
				lst_push_back(rep_list, tmp);
				store_dir_recursive(tmp, rep_list);
			}
		}
	}
	closedir(dir_fd);
	return (0);
}
