/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_refraction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 17:12:09 by tbalu             #+#    #+#             */
/*   Updated: 2016/06/30 12:39:16 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

void	reflection(t_ray *ray, t_ray_hit *hit, float *coef)
{
	float reflection;

	*coef *= hit->object->mat->reflection;
	reflection = 2.0f * v3f_dot(ray->dir, hit->normal);
	ray->start = hit->point;
	ray->dir = v3f_sub(ray->dir, v3f_mul_float(hit->normal, reflection));
	ray->level_reflection++;
}

void	refraction(t_ray *ray, t_ray_hit *hit, float *coef)
{
	float	refraction;
	float	cos1;
	float	cos2;
	float	n;

	n = 1 / hit->object->mat->refraction;
	*coef *= (hit->object->mat->transparency);
	ray->start = hit->point;
	cos1 = v3f_dot(hit->normal, v3f_mul_float(ray->dir, -1));
	cos2 = sqrtf(1 - POW2(n) * (1 - POW2(cos1)));
	if (cos1 > 0)
		refraction = (n * cos1 - cos2);
	else
		refraction = (n * cos1 + cos2);
	ray->dir = v3f_add(v3f_mul_float(ray->dir, n),
	v3f_mul_float(hit->normal, refraction));
	ray->level_refraction++;
}
