/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/28 04:14:19 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrimchar(char const *s, int rm)
{
	char		*str_new;
	int			start;
	int			end;
	int			length;

	if (s == NULL)
		return (NULL);
	start = ft_getnextxchar(s, rm, 0, +1);
	end = ft_getnextxchar(s, rm, ft_strlen(s) - 1, -1);
	if (start > end)
		return (ft_strnew(0));
	length = end - start;
	str_new = ft_strnew(length);
	if (str_new == NULL)
		return (NULL);
	ft_strncpy(str_new, s + start, length + 1);
	return (str_new);
}
