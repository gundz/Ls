#include <ls.h>
#include <libft.h>
#include <stdlib.h>
#include <dirent.h>

t_dir					*store_files(char **argv)
{
	t_dir				*dir;
	int					i;

	dir = create_dir("");
	i = 1;
	while (argv[i] != '\0')
	{
		if (argv[i][0] != '-')
		{
			if (is_dir(argv[i]) == 0)
			{
				if (ft_strcmp(argv[i], "..") != 0 && argv[i][0] != '.')
					lst_push_back(&dir->files, ft_strdup(argv[i]));
			}
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

	dir = create_dir(path);
	if ((dir_fd = opendir(path)) == NULL)
	{
		show_error(path, -1);
		return (NULL);
	}
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

	if ((dir_fd = opendir(path)) == NULL)
		return (-1);
	while ((file = readdir(dir_fd)) != NULL)
	{
		if (ft_strcmp(file->d_name, "..") != 0 && file->d_name[0] != '.')
		{
			char	*tmp = ft_strcat(path, "/");
			tmp = ft_strcat(tmp, file->d_name);
			if (is_dir(tmp) == 1)
			{
				lst_push_back(rep_list, tmp);
				store_dirs_recursive(tmp, rep_list);
			}
		}
	}
	closedir(dir_fd);
	return (0);
}
