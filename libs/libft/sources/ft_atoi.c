/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/28 04:32:09 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		is_negative;
	int		result;

	while (ft_isspace((int)*str))
		(str)++;
	result = 0;
	is_negative = 0;
	if (*str == '-')
	{
		is_negative = 1;
		(str)++;
	}
	else if (*str == '+')
		(str)++;
	while (ft_isdigit((int)*str))
	{
		result = ((result * 10) + (*str - '0'));
		(str)++;
	}
	result *= (is_negative == 1 ? -1 : 1);
	return (result);
}
