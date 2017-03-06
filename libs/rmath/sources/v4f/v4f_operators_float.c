/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4f_operators_float.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:25 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/09 23:43:35 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_v4f.h"

t_vector4f	v4f_add_float(t_vector4f v1, float val)
{
	return ((t_vector4f) { v1.x + val, v1.y + val, v1.z + val, v1.w + val });
}

t_vector4f	v4f_sub_float(t_vector4f v1, float val)
{
	return ((t_vector4f) { v1.x - val, v1.y - val, v1.z - val, v1.w - val });
}

t_vector4f	v4f_mul_float(t_vector4f v1, float val)
{
	return ((t_vector4f) { v1.x * val, v1.y * val, v1.z * val, v1.w * val });
}

t_vector4f	v4f_div_float(t_vector4f v1, float val)
{
	return ((t_vector4f) { v1.x / val, v1.y / val, v1.z / val, v1.w / val });
}
