#include <stddef.h>

void                    options(const int argc, const char **argv, char tab[])
{
    int                 i;
    size_t              j;

    i = 1;
    while (i < argc)
    {
        if (argv[i][0] != '-' || argv[i][1] == '-')
            return ;
        j = 1;
        while (argv[i][j] != '\0')
        {
            tab[(size_t)(unsigned char)argv[i][j]] = 1;
            j++;
        }
        i++;
    }
}
