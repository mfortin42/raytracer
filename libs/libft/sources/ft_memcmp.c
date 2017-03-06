/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubois <adubois@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 18:27:27 by adubois           #+#    #+#             */
/*   Updated: 2016/06/10 01:00:13 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_memcmp_align(const void **s1, const void **s2, size_t *n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			size;

	str1 = (unsigned char *)*s1;
	str2 = (unsigned char *)*s2;
	size = (unsigned long)str1 % sizeof(void *);
	if (size > *n)
		size = *n;
	*n -= size;
	while (size--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		++str1;
		++str2;
	}
	*s1 = (void*)str1;
	*s2 = (void*)str2;
	return (0);
}

static int	ft_memcmp_bulk(const void **s1, const void **s2, size_t *n)
{
	unsigned long	*str1;
	unsigned long	*str2;
	int				i;

	str1 = (unsigned long *)*s1;
	str2 = (unsigned long *)*s2;
	while (*n > 7)
	{
		if (str1 != str2)
		{
			i = 8;
			while (--i >= 0)
				if (*((unsigned char *)str1 + i) !=
					*((unsigned char *)str2 + i))
					return (*((unsigned char *)str1 + i) -
							*((unsigned char *)str2 + i));
		}
		++str1;
		++str2;
		*n -= 8;
	}
	*s1 = (void*)str1;
	*s2 = (void*)str2;
	return (0);
}

static int	ft_memcmp_terminate(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		++str1;
		++str2;
	}
	return (0);
}

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		result;

	if (n == 0)
		return (0);
	result = 0;
	if ((unsigned long)s1 % sizeof(void *))
		if ((result = ft_memcmp_align(&s1, &s2, &n)))
			return (result);
	if (n > 7)
		if ((result = ft_memcmp_bulk(&s1, &s2, &n)))
			return (result);
	if (n > 0)
		if ((result = ft_memcmp_terminate(s1, s2, n)))
			return (result);
	return (result);
}
