/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/26 23:29:08 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*firstocc;

	firstocc = dst;
	while (n > 0 && *src)
	{
		*dst = *src;
		(dst)++;
		(src)++;
		n--;
	}
	while (n > 0)
	{
		*dst = '\0';
		(dst)++;
		n--;
	}
	return (firstocc);
}
