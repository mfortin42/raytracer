/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 03:18:39 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/28 03:26:06 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char *s)
{
	char *start;

	if (s == NULL)
		return (NULL);
	start = s;
	while (*s)
	{
		if (ft_islower((int)*s))
			(*s) -= ('a' - 'A');
		(s)++;
	}
	return (start);
}
