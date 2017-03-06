/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2f_operators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:25 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/09 23:43:34 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_v2f.h"

t_vector2f	v2f_add(t_vector2f v1, t_vector2f v2)
{
	return ((t_vector2f) { v1.x + v2.x, v1.y + v2.y });
}

t_vector2f	v2f_sub(t_vector2f v1, t_vector2f v2)
{
	return ((t_vector2f) { v1.x - v2.x, v1.y - v2.y });
}

t_vector2f	v2f_mul(t_vector2f v1, t_vector2f v2)
{
	return ((t_vector2f) { v1.x * v2.x, v1.y * v2.y });
}

t_vector2f	v2f_div(t_vector2f v1, t_vector2f v2)
{
	return ((t_vector2f) { v1.x / v2.x, v1.y / v2.y });
}
