/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:24 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 12:03:12 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_utils.h"

int		clampi(int val, int min, int max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}

float	clampf(float val, float min, float max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}

float	clampf01(float val)
{
	if (val > 1.0f)
		return (1.0f);
	if (val < 0.0f)
		return (0.0f);
	return (val);
}
