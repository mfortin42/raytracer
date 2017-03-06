/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 03:18:39 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/28 03:25:48 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *s)
{
	char *start;

	if (s == NULL)
		return (NULL);
	start = s;
	while (*s)
	{
		if (ft_isupper((int)*s))
			(*s) += 'a' - 'A';
		(s)++;
	}
	return (start);
}
