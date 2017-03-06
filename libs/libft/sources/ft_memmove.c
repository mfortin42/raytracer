/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 21:00:52 by adubois           #+#    #+#             */
/*   Updated: 2016/06/10 01:00:13 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memmove_align(void **dest, const void **src, size_t *n)
{
	size_t			size;
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char *)*dest + *n;
	source = (unsigned char *)*src + *n;
	size = (unsigned long int)destination % sizeof(void *);
	if (*n < size)
		size = *n;
	*n -= size;
	while (size)
	{
		--destination;
		--source;
		*destination = *source;
		--size;
	}
	*dest = (void *)destination;
	*src = (void *)source;
}

static void	ft_memmove_bulk(void **dest, const void **src, size_t *n)
{
	unsigned char	swap[4096];
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char *)*dest;
	source = (unsigned char *)*src;
	while (*n >= 4096)
	{
		destination -= 4096;
		source -= 4096;
		ft_memcpy(swap, source, 4096);
		ft_memcpy(destination, swap, 4096);
		*n -= 4096;
	}
	*dest = (void *)destination;
	*src = (void *)source;
}

static void	ft_memmove_terminate(void **dest, const void **src, size_t *n)
{
	unsigned char	swap[*n];
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char *)*dest - *n;
	source = (unsigned char *)*src - *n;
	ft_memcpy(swap, source, *n);
	ft_memcpy(destination, swap, *n);
	*n -= 0;
	*dest = (void *)destination;
	*src = (void *)source;
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*orig;

	if (n == 0 || dest == src)
		return (dest);
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	orig = dest;
	ft_memmove_align(&dest, &src, &n);
	if (n >= 4096)
		ft_memmove_bulk(&dest, &src, &n);
	if (n != 0)
		ft_memmove_terminate(&dest, &src, &n);
	return (orig);
}
