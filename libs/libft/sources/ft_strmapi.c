/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/27 19:08:54 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret_str;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	ret_str = ft_strnew(ft_strlen(s) + 1);
	if (ret_str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret_str[i] = f(i, s[i]);
		i++;
	}
	return (ret_str);
}
