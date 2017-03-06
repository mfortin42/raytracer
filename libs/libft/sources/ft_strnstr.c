/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/26 17:45:23 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t length)
{
	const char	*to_finditer;
	const char	*striter;

	if (*to_find == '\0')
		return ((char *)str);
	while (*str != '\0' && length > 0)
	{
		if (*str == *to_find)
		{
			striter = str;
			to_finditer = to_find;
			while (*striter == *to_finditer &&
							length - (to_finditer - to_find) > 0)
			{
				(striter)++;
				(to_finditer)++;
				if (*to_finditer == '\0')
					return ((char *)str);
			}
		}
		(str)++;
		length--;
	}
	return (NULL);
}
