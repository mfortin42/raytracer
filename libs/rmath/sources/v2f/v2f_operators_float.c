/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2f_operators_float.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:25 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/09 23:43:34 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_v2f.h"

t_vector2f	v2f_add_float(t_vector2f v1, float val)
{
	return ((t_vector2f) { v1.x + val, v1.y + val });
}

t_vector2f	v2f_sub_float(t_vector2f v1, float val)
{
	return ((t_vector2f) { v1.x - val, v1.y - val });
}

t_vector2f	v2f_mul_float(t_vector2f v1, float val)
{
	return ((t_vector2f) { v1.x * val, v1.y * val });
}

t_vector2f	v2f_div_float(t_vector2f v1, float val)
{
	return ((t_vector2f) { v1.x / val, v1.y / val });
}
