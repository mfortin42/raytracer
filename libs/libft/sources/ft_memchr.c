/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:15:26 by adubois           #+#    #+#             */
/*   Updated: 2016/06/10 01:00:13 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memchr_align(const void **s, unsigned char c, size_t *n)
{
	size_t			size;
	unsigned char	*ptr;

	ptr = (unsigned char *)*s;
	size = (unsigned long)ptr % sizeof(void *);
	if (size > *n)
		size = *n;
	*n -= size;
	while (size--)
	{
		if (*ptr == c)
			return ((void *)ptr);
		++ptr;
	}
	*s = (void *)ptr;
	return (NULL);
}

static void	*ft_memchr_bulk(const void **s, unsigned char c, size_t *n)
{
	unsigned long	chr;
	unsigned long	bytes;
	unsigned long	*ptr;
	unsigned char	*current;
	int				i;

	chr = c | c << 8 | c << 16 | c << 24;
	chr |= chr << 32;
	ptr = (unsigned long *)*s;
	while (*n > 7)
	{
		bytes = *ptr ^ chr;
		if (((bytes - 0x0101010101010101UL) & (~bytes & 0x8080808080808080UL)))
		{
			current = (unsigned char *)ptr;
			i = 0;
			while (i++ < 8)
				if (*(current + i - 1) == c)
					return ((void *)(current + i - 1));
		}
		++ptr;
		*n -= 8;
	}
	*s = (void *)ptr;
	return (NULL);
}

static void	*ft_memchr_terminate(const void *s, unsigned char c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		if (*ptr == c)
			return ((void *)ptr);
		++ptr;
	}
	return (NULL);
}

void		*ft_memchr(const void *s, int c, size_t n)
{
	void	*ptr;

	if (n == 0)
		return (NULL);
	ptr = NULL;
	if ((unsigned long)s % sizeof(void *))
		if ((ptr = ft_memchr_align(&s, (unsigned char)c, &n)))
			return (ptr);
	if (n > 7)
		if ((ptr = ft_memchr_bulk(&s, (unsigned char)c, &n)))
			return (ptr);
	if (n > 0)
		if ((ptr = ft_memchr_terminate(s, (unsigned char)c, n)))
			return (ptr);
	return (ptr);
}
