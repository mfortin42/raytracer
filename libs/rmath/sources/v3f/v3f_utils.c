/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3f_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:25 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/22 20:09:07 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_v3f.h"

t_vector3f	v3f_lerp(t_vector3f v1, t_vector3f v2, float lerp_factor)
{
	return (v3f_add(v3f_mul_float(v3f_sub(v2, v1), lerp_factor), v1));
}

t_vector3f	v3f_opposite(t_vector3f v)
{
	return ((t_vector3f) { -v.x, -v.y, -v.z });
}

float		v3f_distance(t_vector3f v1, t_vector3f v2)
{
	return (sqrtf(POW2(v2.x - v1.x) + POW2(v2.y - v1.y) + POW2(v2.z - v1.z)));
}

int			v3f_to_color(t_vector3f color)
{
	return ((0 << 24) |
			((unsigned char)(minf(color.x, 1.0f) * 255.0f) << 16) |
			((unsigned char)(minf(color.y, 1.0f) * 255.0f) << 8) |
			((unsigned char)(minf(color.z, 1.0f) * 255.0f)));
}
