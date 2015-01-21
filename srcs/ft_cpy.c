#include <libft.h>
#include <stdlib.h>

void                                            *ft_cpy(void *cpy, size_t size)
{
    void                                        *ret;

    if (!(ret = malloc(size)))
        return (NULL);
    ret = ft_memcpy(ret, cpy, size);
    return (ret);
}
