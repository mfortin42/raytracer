/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2f_operators_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:25 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/09 23:43:34 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_v2f.h"

t_vector2f	*v2f_new(float x, float y)
{
	t_vector2f	*ret;

	ret = (t_vector2f *)malloc(sizeof(t_vector2f));
	ret->x = x;
	ret->y = y;
	return (ret);
}
