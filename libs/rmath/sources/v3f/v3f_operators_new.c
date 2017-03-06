/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3f_operators_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:25 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/09 23:44:20 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_v3f.h"

t_vector3f	*v3f_new(float x, float y, float z)
{
	t_vector3f	*ret;

	ret = (t_vector3f *)malloc(sizeof(t_vector3f));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}
