/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2016/05/24 13:52:33 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float		ft_atof(const char *str)
{
	float	value;
	int		sign;
	int		i;

	value = 0;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		value = value * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		i = 1;
		while (ft_isdigit(*str))
		{
			value += (float)(*str - '0') / pow(10, i++);
			str++;
		}
	}
	str += 2;
	return (value * sign);
}
