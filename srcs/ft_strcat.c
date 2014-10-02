#include <stdlib.h>

unsigned int					ft_strlen(const char *const str)
{
	unsigned int				len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

char							*ft_strcat(const char *const str,
		const char *const str2)
{
	unsigned int				len1;
	unsigned int				len2;
	char						*ret;

	len1 = ft_strlen(str);
	len2 = ft_strlen(str2);
	if (!(ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	len1 = 0;
	while (str[len1] != '\0')
	{
		ret[len1] = str[len1];
		++len1;
	}
	len2 = 0;
	while (str2[len2] != '\0')
	{
		ret[len1] = str2[len2];
		++len1;
		++len2;
	}
	ret[len1] = '\0';
	return (ret);
}
