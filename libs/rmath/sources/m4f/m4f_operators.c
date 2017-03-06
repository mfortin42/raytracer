/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4f_operators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:25 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/09 23:43:34 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rmath_m4f.h"

t_matrix4f	*m4f_new(void)
{
	t_matrix4f *ret;

	ret = (t_matrix4f *)malloc(sizeof(t_matrix4f));
	return (ret);
}

t_matrix4f	*m4f_mul(t_matrix4f *m1, t_matrix4f *m2)
{
	t_matrix4f	tmp;
	int			x;
	int			y;

	if (m1 == NULL)
		return (m2);
	m4f_cpy(&tmp, m1);
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			m1->m[x][y] = tmp.m[x][0] * m2->m[0][y] +
							tmp.m[x][1] * m2->m[1][y] +
							tmp.m[x][2] * m2->m[2][y] +
							tmp.m[x][3] * m2->m[3][y];
			y++;
		}
		x++;
	}
	return (m1);
}

t_vector4f	m4f_mul_vector(t_matrix4f *m, t_vector4f v)
{
	t_vector4f ret;

	ret.x = m->m[0][0] * v.x + m->m[0][1] * v.y +
			m->m[0][2] * v.z + m->m[0][3] * v.w;
	ret.y = m->m[1][0] * v.x + m->m[1][1] * v.y +
			m->m[1][2] * v.z + m->m[1][3] * v.w;
	ret.z = m->m[2][0] * v.x + m->m[2][1] * v.y +
			m->m[2][2] * v.z + m->m[2][3] * v.w;
	ret.w = m->m[3][0] * v.x + m->m[3][1] * v.y +
			m->m[3][2] * v.z + m->m[3][3] * v.w;
	return (ret);
}

t_matrix4f	*m4f_cpy(t_matrix4f *dst, t_matrix4f *src)
{
	dst->m[0][0] = src->m[0][0];
	dst->m[1][0] = src->m[1][0];
	dst->m[2][0] = src->m[1][0];
	dst->m[3][0] = src->m[3][0];
	dst->m[0][1] = src->m[0][1];
	dst->m[1][1] = src->m[1][1];
	dst->m[2][1] = src->m[2][1];
	dst->m[3][1] = src->m[3][1];
	dst->m[0][2] = src->m[0][2];
	dst->m[1][2] = src->m[1][2];
	dst->m[2][2] = src->m[2][2];
	dst->m[3][2] = src->m[3][2];
	dst->m[0][3] = src->m[0][3];
	dst->m[1][3] = src->m[1][3];
	dst->m[2][3] = src->m[2][3];
	dst->m[3][3] = src->m[3][3];
	return (dst);
}

t_matrix4f	*m4f_mul_new(t_matrix4f *m1, t_matrix4f *m2)
{
	t_matrix4f	*new;
	int			x;
	int			y;

	x = 0;
	y = 0;
	new = m4f_new();
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			new->m[x][y] = m1->m[x][0] * m2->m[0][y] +
							m1->m[x][1] * m2->m[1][y] +
							m1->m[x][2] * m2->m[2][y] +
							m1->m[x][3] * m2->m[3][y];
			y++;
		}
		x++;
	}
	return (new);
}
