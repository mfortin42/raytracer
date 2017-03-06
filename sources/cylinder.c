/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:06 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/08 20:16:29 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int			cylinder_intersect(t_ray *ray, t_object *obj, float *t)
{
	float		abc[3];
	float		tmp[2];
	float		discr;
	t_vector3f	dist;

	dist = v3f_sub(ray->start, obj->position);
	tmp[0] = v3f_dot(ray->dir, obj->rotation);
	tmp[1] = v3f_dot(dist, obj->rotation);
	abc[0] = v3f_dot(ray->dir, ray->dir) - POW2(tmp[0]);
	abc[1] = 2 * (v3f_dot(ray->dir, dist) - (tmp[0] * tmp[1]));
	abc[2] = v3f_dot(dist, dist) - POW2(tmp[1]) - POW2(obj->radius);
	discr = abc[1] * abc[1] - (4 * abc[0] * abc[2]);
	if (discr < 0)
		return (-1);
	else
		return (resolve_quadratic(discr, abc[0], abc[1], t));
}

int			cylinder_calculate_normal(t_ray *r, t_ray_hit *h)
{
	float		m;
	t_vector3f	dist;
	t_vector3f	tmp;

	dist = v3f_sub(r->start, h->object->position);
	m = v3f_dot(r->dir, h->object->rotation) *
		h->delta + v3f_dot(dist, h->object->rotation);
	h->normal = v3f_mul_float(r->dir, h->delta);
	h->normal = v3f_add(h->normal, dist);
	tmp = v3f_mul_float(h->object->rotation, m);
	h->normal = v3f_sub(h->normal, tmp);
	h->normal = v3f_normalized(h->normal);
	return (1);
}

void		cylinder_init(t_object *obj)
{
	obj->intersect = cylinder_intersect;
	obj->normal = cylinder_calculate_normal;
}
