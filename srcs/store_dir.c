#include <ls.h>
#include <libft.h>
#include <stdlib.h>
#include <dirent.h>

int                                             store_dir_content(const char *path, t_dir **dir)
{
    DIR                                         *dir_fd;
    struct dirent                               *file;

    if ((dir_fd = opendir(path)) == NULL)
    {
        return (show_error(path, -1));
    }
    if (!(*dir = (t_dir *)malloc(sizeof(t_dir))))
        return (show_error("", -1));
    (*dir)->files = NULL;
    (*dir)->path = ft_strdup(path);
    while ((file = readdir(dir_fd)) != NULL)
    {
        lst_push_back(&(*dir)->files, ft_cpy(file, sizeof(struct dirent)));
    }
    closedir(dir_fd);
    return (0);
}


int						store_dirs_recursive(t_dir *dir, t_list **rep_list)
{
    t_dir                                       *dir_tmp;
    struct dirent                               *file;
    t_list                                      *lstWalker;

    lstWalker = dir->files;
    dir_tmp = NULL;
    while (lstWalker != NULL)
    {
        file = lstWalker->data;
        char                                *tmp = ft_strcat(dir->path, "/");
        tmp = ft_strcat(tmp, file->d_name);
        if (is_dir(tmp) == 1 && ft_strcmp(file->d_name, "..") != 0 && ft_strcmp(file->d_name, ".") != 0)
        {
            store_dir_content(tmp, &dir_tmp);
            lst_push_back(rep_list, dir_tmp);
            store_dirs_recursive(dir_tmp, rep_list);
        }
        if (lstWalker->next == NULL)
            break ;
        lstWalker = lstWalker->next;
    }
    return (0);
}
