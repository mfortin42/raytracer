/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3f_operators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:25 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/09 23:43:34 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_v3f.h"

t_vector3f	v3f_add(t_vector3f v1, t_vector3f v2)
{
	return ((t_vector3f) { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z });
}

t_vector3f	v3f_sub(t_vector3f v1, t_vector3f v2)
{
	return ((t_vector3f) { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z });
}

t_vector3f	v3f_mul(t_vector3f v1, t_vector3f v2)
{
	return ((t_vector3f) { v1.x * v2.x, v1.y * v2.y, v1.z * v2.z });
}

t_vector3f	v3f_div(t_vector3f v1, t_vector3f v2)
{
	return ((t_vector3f) { v1.x / v2.x, v1.y / v2.y, v1.z / v2.z });
}
