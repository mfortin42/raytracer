/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/28 00:21:30 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	diff;
	size_t	dlen;

	s = (char *)src;
	d = dest;
	diff = size;
	while (diff-- != 0 && *d != '\0')
		d++;
	dlen = d - dest;
	diff = size - dlen;
	if (diff == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (diff != 1)
		{
			*d++ = *s;
			diff--;
		}
		s++;
	}
	*d = 0;
	return (dlen + (s - src));
}
