/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 03:01:38 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/27 03:03:55 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memswap(void *swpf, void *swps)
{
	char tmp;

	tmp = *(char *)swpf;
	*(char *)swpf = *(char *)swps;
	*(char *)swps = tmp;
}
