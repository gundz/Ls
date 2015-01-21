unsigned int					ft_strlen(const char *const str)
{
	unsigned int				len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}
