/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/27 19:20:03 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		ret_str[i] = f(s[i]);
		i++;
	}
	return (ret_str);
}
