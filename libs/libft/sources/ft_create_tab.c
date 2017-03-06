/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:34:10 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 02:42:24 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_create_tab(int width, int height, size_t element_size)
{
	void	**ret;
	int		i;

	if ((ret = (void **)malloc(width * sizeof(void *))) == NULL)
		return (NULL);
	i = 0;
	while (i < width)
	{
		if ((ret[i] = (void *)malloc(height * element_size)) == NULL)
			return (NULL);
		i++;
	}
	return (ret);
}
