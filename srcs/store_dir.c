#include <ls.h>
#include <libft.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <string.h>

t_dir					*store_files(const int argc, char **argv)
{
	t_dir				*dir;
	struct stat			stat_buf;
	int					i;

	if (!(dir = (t_dir *)malloc(sizeof(t_dir))))
		return (NULL);
	dir->files = NULL;
	dir->path = ft_strdup("");
	i = 1;
	while (argv[i] != '\0')
	{
		if (argv[i][0] != '-')
		{
			if (stat(argv[i], &stat_buf) != -1)
			{
				if (!(S_ISDIR(stat_buf.st_mode)))
				{
						if (ft_strcmp(argv[i], "..") != 0 && argv[i][0] != '.')
					lst_push_back(&dir->files, ft_strdup(argv[i]));
				}
			}
			else
				show_error(argv[i], -1);
		}
		++i;
	}
	return (dir);
}

t_dir					*store_dir_content(char *path)
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
		if (ft_strcmp(file->d_name, "..") != 0 && file->d_name[0] != '.')
			lst_push_back(&dir->files, ft_strdup(file->d_name));
	}
	closedir(dir_fd);
	return (dir);
}

int						store_dirs_recursive(char *path, t_list **rep_list)
{
	DIR					*dir_fd;
	struct dirent		*file;
	struct stat			stat_buf;

	if ((dir_fd = opendir(path)) == NULL)
		return (-1);
	while ((file = readdir(dir_fd)) != NULL)
	{
		if (ft_strcmp(file->d_name, "..") != 0 && file->d_name[0] != '.')
		{
			char	*tmp = ft_strcat(path, "/");
			tmp = ft_strcat(tmp, file->d_name);
			if (stat(tmp, &stat_buf) != -1)
			{
				if (S_ISDIR(stat_buf.st_mode))
				{
					lst_push_back(rep_list, tmp);
					store_dirs_recursive(tmp, rep_list);
				}
			}
		}
	}
	closedir(dir_fd);
	return (0);
}
