/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 02:48:02 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/28 03:10:18 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char	*start;
	size_t	length;
	size_t	i;

	if (s == NULL)
		return (NULL);
	start = s;
	length = ft_strlen(s);
	i = 0;
	while (i < length / 2)
	{
		ft_memswap((void *)(s + i), (void *)(s + (length - i - 1)));
		i++;
	}
	return (start);
}
