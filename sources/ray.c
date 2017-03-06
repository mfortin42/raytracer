/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:06 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 14:08:51 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int				ray_cast(t_ray *ray, t_ray_hit *hit, t_scene *scene)
{
	int			i;
	float		delta;
	float		min_delta;
	t_object	*selected;

	i = -1;
	selected = NULL;
	delta = RAY_LENGTH;
	min_delta = ray->length;
	while (++i < scene->objects_count)
		if ((scene->objects + i)->intersect(ray, scene->objects + i, &delta))
			if (delta < min_delta && ((min_delta = delta) > 0))
				selected = (scene->objects + i);
	if (selected == NULL)
		return (0);
	if (hit != NULL)
	{
		hit->object = selected;
		hit->delta = min_delta;
		hit->point = v3f_add(ray->start, v3f_mul_float(ray->dir, hit->delta));
		return (hit->object->normal(ray, hit));
	}
	return (1);
}

t_ray_hit		*ray_hit_new(t_ray *ray, t_object *obj, float delta)
{
	t_ray_hit	*hit;

	hit = (t_ray_hit *)malloc(sizeof(t_ray_hit));
	hit->object = obj;
	hit->delta = delta;
	hit->point = v3f_add(ray->start, v3f_mul_float(ray->dir, hit->delta));
	hit->object->normal(ray, hit);
	return (hit);
}

t_list			*ray_cast_all(t_ray *ray, t_scene *scene)
{
	int			i;
	float		delta;
	t_object	*obj;
	t_list		*hits;

	i = -1;
	delta = RAY_LENGTH;
	hits = list_new();
	while (++i < scene->objects_count)
	{
		obj = scene->objects + i;
		if (obj->intersect(ray, obj, &delta) && delta < ray->length)
			list_push_back(hits, ray_hit_new(ray, obj, delta));
	}
	if (hits->count <= 0)
		ft_memdel((void **)&hits);
	return (hits);
}

t_vector2f		ray_get_uv(t_ray_hit *hit)
{
	t_vector3f	north;
	t_vector3f	equa;
	t_vector3f	dist;
	float		theta;
	float		phi;

	dist = v3f_normalized(v3f_sub(hit->point, hit->object->position));
	north = v3f_normalized(V3F_INIT(0, hit->object->radius, 0));
	equa = v3f_normalized(V3F_INIT(hit->object->radius, 0, 0));
	phi = acos(-v3f_dot(north, dist));
	theta = (acos(v3f_dot(dist, equa) / sin(phi))) / (2 * PI);
	if (v3f_dot(v3f_cross(north, equa), dist) <= 0)
		theta = 1 - theta;
	phi = phi / PI;
	return (V2F_INIT(theta, phi));
}
