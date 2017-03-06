/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/26 22:08:19 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str_new;
	int		start;
	int		end;
	int		length;

	if (s == NULL)
		return (NULL);
	start = 0;
	while (s[start] &&
			(s[start] == '\t' || s[start] == ' ' || s[start] == '\n'))
		start++;
	end = ft_strlen(s) - 1;
	if (start > end)
		return (ft_strnew(0));
	while (s[end] &&
			(s[end] == '\t' || s[end] == ' ' || s[end] == '\n'))
		end--;
	end++;
	length = end - start;
	str_new = ft_strnew(length);
	if (str_new == NULL)
		return (NULL);
	ft_strncpy(str_new, s + start, length);
	return (str_new);
}
