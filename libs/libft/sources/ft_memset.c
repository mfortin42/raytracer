/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:48:41 by adubois           #+#    #+#             */
/*   Updated: 2016/06/10 01:00:13 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Set the value 'c' to the first 'len' bytes in the memory space pointed by
** 'b'.
*/

static void	ft_memsetblock(unsigned long *ptr, unsigned long cccc, size_t *len)
{
	unsigned long	*p;
	size_t			size;
	size_t			nlen;

	p = (unsigned long *)(*ptr);
	nlen = *len;
	size = 8 * 8;
	while (nlen >= size)
	{
		p[0] = cccc;
		p[1] = cccc;
		p[2] = cccc;
		p[3] = cccc;
		p[4] = cccc;
		p[5] = cccc;
		p[6] = cccc;
		p[7] = cccc;
		p += 8;
		nlen -= size;
	}
	*ptr = (long)p;
	*len = nlen;
}

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned long int	ptr;
	unsigned long int	cccc;

	ptr = (unsigned long int)b;
	cccc = (unsigned char)c;
	cccc |= cccc << 24 | cccc << 16 | cccc << 8;
	cccc |= cccc << 32;
	while (len && ptr % 8 != 0)
	{
		*((unsigned char *)ptr++) = (unsigned char)c;
		--len;
	}
	if (len >= 8 * 8)
		ft_memsetblock(&ptr, cccc, &len);
	while (len >= 8)
	{
		((unsigned long *)ptr)[0] = cccc;
		ptr += 8;
		len -= 8;
	}
	while (len--)
		*((unsigned char *)ptr++) = (unsigned char)c;
	return (b);
}
