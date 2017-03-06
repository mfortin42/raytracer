/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/26 17:47:06 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	destlength;
	unsigned int	diff;
	unsigned int	i;

	destlength = ft_strlen(dest);
	diff = size - destlength - 1;
	i = 0;
	while (src[i] && diff > 0)
	{
		dest[i] = src[i];
		diff--;
		i++;
	}
	dest[destlength + i] = '\0';
	return (i);
}
