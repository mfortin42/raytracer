/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/28 04:31:18 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size_int(int n)
{
	size_t			size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char			*str_new;
	int				size_alloc;
	int				i;
	long long		nb;
	int				is_neg;

	size_alloc = size_int(n);
	is_neg = n < 0 ? 1 : 0;
	str_new = ft_strnew(size_alloc + is_neg);
	if (str_new == 0)
		return (0);
	if (n == 0)
		str_new[0] = '0';
	else if (is_neg)
		str_new[0] = '-';
	i = size_alloc + is_neg - 1;
	nb = n;
	while (nb != 0)
	{
		str_new[i] = ((is_neg ? -nb : nb) % 10) + '0';
		nb /= 10;
		i--;
	}
	str_new[size_alloc + is_neg] = 0;
	return (str_new);
}
