
#ifndef		LIBFT_H
# define	LIBFT_H

typedef struct				s_list
{
	struct s_list			*next;
	void					*data;
}							t_list;

t_list						*lst_create_elem(void *data);
void						lst_push_back(t_list **lst, void *data);
void						lst_sort(t_list **lst, int (*cmp)(), const int rev);

void						ft_putstr(const char *const str);
char						*ft_strdup(const char *const str);
int							ft_strcmp(const char *s1, const char *s2);
char						*ft_strcat(const char *const str, const char *const str2);

#endif
