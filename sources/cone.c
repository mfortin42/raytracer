/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:06 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 14:17:50 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int			cone_intersect(t_ray *r, t_object *o, float *t)
{
	float		abc[3];
	float		det;
	t_vector3f	dist;
	float		tmp[2];
	float		tangle;

	tangle = tan(o->radius / 2.00f);
	dist = v3f_sub(r->start, o->position);
	tmp[0] = v3f_dot(r->dir, o->rotation);
	tmp[1] = v3f_dot(dist, o->rotation);
	abc[0] = v3f_dot(r->dir, r->dir) - ((1 + POW2(tangle)) * POW2(tmp[0]));
	abc[1] = 2 * (v3f_dot(r->dir, dist)
	- ((1 + POW2(tangle)) * tmp[0] * tmp[1]));
	abc[2] = v3f_dot(dist, dist) - ((1 + POW2(tangle)) * POW2(tmp[1]));
	det = abc[1] * abc[1] - (4 * abc[0] * abc[2]);
	if (det < 0.00001f)
		return (-1);
	else
		return (resolve_quadratic(det, abc[0], abc[1], t));
}

int			cone_calculate_normal(t_ray *r, t_ray_hit *h)
{
	t_vector3f	dist;
	t_vector3f	tmp;
	float		m;

	dist = v3f_sub(r->start, h->object->position);
	m = v3f_dot(r->dir, h->object->rotation)
	* h->delta + v3f_dot(dist, h->object->rotation);
	h->normal = v3f_mul_float(r->dir, h->delta);
	h->normal = v3f_add(h->normal, dist);
	tmp = v3f_mul_float(h->object->rotation, m *
						(1 + POW2(tan(h->object->radius / 2))));
	h->normal = v3f_sub(h->normal, tmp);
	h->normal = v3f_normalized(h->normal);
	return (1);
}

void		cone_init(t_object *o)
{
	o->intersect = &cone_intersect;
	o->normal = &cone_calculate_normal;
}
