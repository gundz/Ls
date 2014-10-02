#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

void					store_dir(char *path)
{
	DIR					*dir_fd;
	struct dirent		*file;

	if ((dir_fd = opendir(path)) == NULL)
	{
		perror(path);
		return ;
	}
	while ((file = readdir(dir_fd)) != NULL)
	{
		printf("%s\n", file->d_name);
	}
	closedir(dir_fd);

}

int					main(int argc, char **argv)
{
	if (argc > 1)
	{
		int i = 0;
		while (argv[i] != '\0')
		{
			printf("%s\n", argv[i++]);
			//store_dir(argv[i++]);
		}
	}
	return (0);
}
