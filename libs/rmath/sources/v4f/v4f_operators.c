/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4f_operators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:25 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/09 23:58:15 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_v4f.h"

t_vector4f	v4f_add(t_vector4f v1, t_vector4f v2)
{
	return ((t_vector4f){ v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w });
}

t_vector4f	v4f_sub(t_vector4f v1, t_vector4f v2)
{
	return ((t_vector4f){ v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w });
}

t_vector4f	v4f_mul(t_vector4f v1, t_vector4f v2)
{
	return ((t_vector4f){ v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w });
}

t_vector4f	v4f_div(t_vector4f v1, t_vector4f v2)
{
	return ((t_vector4f){ v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w });
}
