/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgundlac <fgundlac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:32:08 by fgundlac          #+#    #+#             */
/*   Updated: 2014/03/14 02:20:43 by fgundlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*tmp;
	char		*tmp2;

	if (dest == NULL || src == NULL)
		return (NULL);
	if (n > 0)
	{
		i = 0;
		tmp = dest;
		tmp2 = (char *)src;
		while (i < n)
		{
			tmp[i] = tmp2[i];
			i++;
		}
	}
	return (dest);
}
