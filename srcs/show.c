#include <libft.h>
#include <ls.h>
#include <stddef.h>

#include <stdio.h>

void                                            showDir(const t_dir *dir, const int show)
{
    t_list                                      *lstWalker;
    struct dirent                               *file;

    lstWalker = dir->files;
    while (lstWalker != NULL)
    {
        file = lstWalker->data;
        if (!(file->d_name[0] == '.') || show == 1)
            printf("%s\n", file->d_name);
        if (lstWalker->next == NULL)
            break ;
        lstWalker = lstWalker->next;
    }
}

void                                            showDirLst(t_list *lst, const int show)
{
    t_dir                                       *dir;
    unsigned int                                size;
    
    size = lst_count(lst);
    while (lst != NULL)
    {
        dir = lst->data;
        if (size > 1)
            printf("%s:\n", dir->path);
        showDir(lst->data, show);
        if (lst->next == NULL)
            break ;
        printf("\n");
        lst = lst->next;
    }
}
