/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 18:25:00 by adubois           #+#    #+#             */
/*   Updated: 2016/06/10 01:00:13 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	size;
	char	*source;

	if (n == 0)
		return (NULL);
	source = (char *)src;
	size = 0;
	while (source[size] != (char)c)
	{
		++size;
		if (size == n)
		{
			ft_memcpy(dest, src, n);
			return (NULL);
		}
	}
	ft_memcpy(dest, src, size);
	return ((void *)((char *)dest + size));
}
