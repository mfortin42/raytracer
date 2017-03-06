/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:06 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/08 20:16:29 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int			sphere_intersect(t_ray *ray, t_object *obj, float *t)
{
	float		a;
	float		b;
	float		c;
	float		det;
	t_vector3f	dist;

	dist = v3f_sub(ray->start, obj->position);
	a = v3f_dot(ray->dir, ray->dir);
	b = 2 * v3f_dot(dist, ray->dir);
	c = v3f_dot(dist, dist) - (obj->radius * obj->radius);
	det = (b * b) - (4 * a * c);
	if (det < 0)
		return (0);
	else
		return (resolve_quadratic(det, a, b, t));
}

int			sphere_calculate_normal(t_ray *r, t_ray_hit *h)
{
	float		tmp;
	t_vector3f	dist;

	(void)r;
	dist = v3f_sub(h->point, h->object->position);
	tmp = v3f_dot(dist, dist);
	if (tmp == 0.0f)
		return (0);
	tmp = 1.0f / sqrt(tmp);
	h->normal = v3f_mul_float(dist, tmp);
	return (1);
}

void		sphere_init(t_object *obj)
{
	obj->intersect = &sphere_intersect;
	obj->normal = &sphere_calculate_normal;
}
