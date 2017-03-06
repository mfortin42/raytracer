/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:49:40 by bkabbas           #+#    #+#             */
/*   Updated: 2016/05/24 13:52:15 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *c1, void *c2, size_t size_c1, size_t size_c2)
{
	void *realloc;

	if (size_c1 + size_c2 == 0)
		return (NULL);
	realloc = malloc(size_c1 + size_c2);
	ft_memcpy(realloc, c1, size_c1);
	ft_memcpy(realloc + size_c1, c2, size_c2);
	return (realloc);
}
