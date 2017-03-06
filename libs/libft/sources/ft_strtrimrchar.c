/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimrchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:10:37 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/28 02:48:11 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrimrchar(char const *s, int rm)
{
	char		*str_new;
	int			end;

	if (s == NULL)
		return (NULL);
	end = ft_getnextxchar(s, rm, ft_strlen(s) - 1, -1) + 1;
	str_new = ft_strnew(end);
	if (str_new == NULL)
		return (NULL);
	ft_strncpy(str_new, s, end);
	return (str_new);
}
