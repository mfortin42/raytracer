/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:06 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 14:19:54 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vector3f	light_get_diffuse(t_light *light, t_ray *photon, t_ray_hit *hit)
{
	t_vector3f	color;
	float		lambert;

	color = v3f_mul(hit->object->mat->diffuse, calculate_texture_color(hit));
	lambert = v3f_dot(photon->dir, hit->normal);
	return (v3f_mul_float(v3f_mul(color, light->intensity), lambert));
}

t_vector3f	light_get_specular(t_light *light, t_ray *ray,
								t_ray *photon, t_ray_hit *hit)
{
	t_vector3f	dir;
	float		factor;

	dir = v3f_mul_float(hit->normal, 2 * v3f_dot(hit->normal, photon->dir));
	dir = v3f_sub(dir, photon->dir);
	factor = pow(v3f_dot(dir, ray->dir), hit->object->mat->brightness);
	return (v3f_mul_float(light->intensity, factor));
}

int			light_is_eligible(t_light *light, t_ray_hit *hit, float *t)
{
	t_vector3f dist;

	dist = v3f_sub(light->position, hit->point);
	if (v3f_dot(hit->normal, dist) <= 0.01f ||
		(*t = sqrt(v3f_dot(dist, dist))) <= 0.01f)
		return (0);
	return (1);
}
