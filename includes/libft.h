
#ifndef		LIBFT_H
# define	LIBFT_H

# include <stddef.h>
# include <stdarg.h>

typedef struct				s_list
{
	struct s_list			*next;
	void					*data;
}							t_list;

t_list						*lst_create_elem(void *data);
void						lst_push_back(t_list **lst, void *data);
void						lst_sort(t_list **lst, int (*cmp)(), const int rev);
unsigned int				lst_count(t_list *lst);

void						ft_putstr(const char *const str);
void                                            *ft_memcpy(void *dest, const void *src, size_t n);
void                                            *ft_cpy(void *cpy, size_t size);
char						*ft_strdup(const char *const str);
unsigned int                                    ft_strlen(const char *const str);
int						ft_strcmp(const char *s1, const char *s2);
char                                            *ft_strijoin(unsigned int n, ...);

#endif
