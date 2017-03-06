/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 16:59:20 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**alloc_char_array(char *src,
									int bounds[5],
									int *size,
									char c)
{
	char	**ret;
	int		length;
	int		i;
	int		next_start;

	if ((ret = (char **)ft_memalloc((bounds[3] + 1) * sizeof(char **))) == NULL)
		return (NULL);
	i = 0;
	if (size != NULL)
		(*size) = bounds[3];
	next_start = bounds[0];
	while (i < bounds[3])
	{
		length = ft_strchrnul(src + next_start, (int)c) - (src + next_start);
		if (length <= 0)
			break ;
		if ((ret[i] = ft_strsub(src, next_start, length)) == NULL)
			return (NULL);
		next_start = ft_getnextxchar(src, (int)c, next_start + length, +1);
		i++;
	}
	return (ret);
}

char			**ft_strsplit(char const *s, char c, int *size)
{
	int			bounds[5];
	char		**ret;

	bounds[2] = ft_strlen(s);
	bounds[0] = ft_getnextxchar(s, (int)c, 0, +1);
	bounds[1] = ft_getnextxchar(s, (int)c, bounds[2] - 1, -1);
	if (bounds[0] > bounds[1])
	{
		ret = (char **)ft_memalloc((1) * sizeof(char **));
		if (size != NULL)
			*size = 0;
		return (ret);
	}
	bounds[3] = 1;
	bounds[4] = bounds[0];
	while (bounds[4] < bounds[1])
	{
		if (s[bounds[4]] == c)
		{
			bounds[3]++;
			bounds[4] = ft_getnextxchar(s, (int)c, bounds[4], +1);
		}
		bounds[4]++;
	}
	return (alloc_char_array((char *)s, bounds, size, c));
}
