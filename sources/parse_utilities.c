/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:21:49 by mfortin           #+#    #+#             */
/*   Updated: 2016/06/28 20:21:51 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

static int	ft_cntw(char const *s, char c)
{
	unsigned int	i;
	int				cnt;

	i = 0;
	cnt = 0;
	while (s[i] == '\t')
		i++;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cnt++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (cnt);
}

char		**ft_strsplit_xml(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	k = 0;
	i = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_cntw(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (s[i] == '\t')
		i++;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i > j)
			tab[k++] = ft_strndup(s + j, i - j);
	}
	tab[k] = NULL;
	return (tab);
}
