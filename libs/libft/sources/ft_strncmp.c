/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/26 19:21:55 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t length)
{
	if (length == 0)
		return (0);
	while (*s1 == *s2 && --length > 0)
	{
		if (*s1 == '\0')
			return (0);
		(s1)++;
		(s2)++;
	}
	return (*(unsigned char *)s1) - (*(unsigned char *)s2);
}
