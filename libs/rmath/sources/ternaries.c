/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternaries.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:24 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/09 23:43:34 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_utils.h"

float	minf(float a, float b)
{
	return (a < b ? a : b);
}

int		mini(int a, int b)
{
	return (a > b ? a : b);
}

float	maxf(float a, float b)
{
	return (a > b ? a : b);
}

int		maxi(int a, int b)
{
	return (a < b ? a : b);
}
