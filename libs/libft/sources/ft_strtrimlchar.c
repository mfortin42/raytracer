/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimlchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:05:17 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/28 02:47:53 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrimlchar(char const *s, int rm)
{
	char		*str_new;
	int			start;
	int			length;

	if (s == NULL)
		return (NULL);
	start = ft_getnextxchar(s, rm, 0, +1);
	length = ft_strlen(s) - start;
	str_new = ft_strnew(length);
	if (str_new == NULL)
		return (NULL);
	ft_strncpy(str_new, s + start, length);
	return (str_new);
}
