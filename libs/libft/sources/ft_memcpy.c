/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 17:49:56 by adubois           #+#    #+#             */
/*   Updated: 2016/06/10 01:00:13 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memcpy_align(void **dest, const void **src, size_t *n)
{
	size_t			size;
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char *)*dest;
	source = (unsigned char *)*src;
	size = (unsigned long int)destination % sizeof(void *);
	if (*n < size)
		size = *n;
	*n -= size;
	while (size)
	{
		*destination = *source;
		++destination;
		++source;
		--size;
	}
	*dest = (void *)destination;
	*src = (void *)source;
}

static void	ft_memcpy_bulk64(void **dest, const void **src, size_t *n)
{
	unsigned long int	*destination;
	unsigned long int	*source;

	destination = (unsigned long int *)*dest;
	source = (unsigned long int *)*src;
	while (*n >= 64)
	{
		*destination = *source;
		*(destination + 1) = *(source + 1);
		*(destination + 2) = *(source + 2);
		*(destination + 3) = *(source + 3);
		*(destination + 4) = *(source + 4);
		*(destination + 5) = *(source + 5);
		*(destination + 6) = *(source + 6);
		*(destination + 7) = *(source + 7);
		destination += 8;
		source += 8;
		*n -= 64;
	}
	*dest = (void *)destination;
	*src = (void *)source;
}

static void	ft_memcpy_bulk8(void **dest, const void **src, size_t *n)
{
	unsigned long int	*destination;
	unsigned long int	*source;

	destination = (unsigned long int *)*dest;
	source = (unsigned long int *)*src;
	while (*n >= 8)
	{
		*destination = *source;
		++destination;
		++source;
		*n -= 8;
	}
	*dest = (void *)destination;
	*src = (void *)source;
}

static void	ft_memcpy_terminate(void **dest, const void **src, size_t *n)
{
	size_t			size;
	unsigned char	*destination;
	unsigned char	*source;

	size = *n;
	destination = (unsigned char *)*dest;
	source = (unsigned char *)*src;
	while (size)
	{
		*destination = *source;
		++destination;
		++source;
		--size;
	}
	*n = 0;
	*dest = (void *)destination;
	*src = (void *)source;
}

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*orig;

	if (n == 0)
		return (dest);
	orig = dest;
	if ((size_t)dest % 8 != 0)
		ft_memcpy_align(&dest, &src, &n);
	if (n >= 64)
		ft_memcpy_bulk64(&dest, &src, &n);
	if (n >= 16)
		ft_memcpy_bulk8(&dest, &src, &n);
	if (n != 0)
		ft_memcpy_terminate(&dest, &src, &n);
	return (orig);
}
