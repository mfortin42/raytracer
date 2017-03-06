/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2f_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:25 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/09 23:43:34 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_v2f.h"

t_vector2f	v2f_lerp(t_vector2f v1, t_vector2f v2, float l)
{
	t_vector2f tmp;

	tmp = v2f_sub(v2, v1);
	tmp.x *= l;
	tmp.y *= l;
	tmp = v2f_add(tmp, v1);
	return (tmp);
}

t_vector2f	v2f_opposite(t_vector2f v)
{
	return ((t_vector2f) { -v.x, -v.y });
}
