/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3f_operators_float.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:25 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/09 23:44:42 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_v3f.h"

t_vector3f	v3f_add_float(t_vector3f v1, float val)
{
	return ((t_vector3f) { v1.x + val, v1.y + val, v1.z + val });
}

t_vector3f	v3f_sub_float(t_vector3f v1, float val)
{
	return ((t_vector3f) { v1.x - val, v1.y - val, v1.z - val });
}

t_vector3f	v3f_mul_float(t_vector3f v1, float val)
{
	return ((t_vector3f) { v1.x * val, v1.y * val, v1.z * val });
}

t_vector3f	v3f_div_float(t_vector3f v1, float val)
{
	return ((t_vector3f) { v1.x / val, v1.y / val, v1.z / val });
}
