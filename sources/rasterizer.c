/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:06 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 14:47:51 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int			calculate_pixel(t_scene *scene, t_camera *cam, int x, int y)
{
	t_vector3f	color;
	t_vector2f	sub;
	float		sampling;
	float		increment;

	sub.x = x;
	color = V3F_ZERO;
	increment = (1.0f / cam->sampling);
	sampling = (1.0f / (cam->sampling * cam->sampling));
	while (sub.x < x + 1)
	{
		sub.y = y;
		while (sub.y < y + 1)
		{
			color =
			v3f_add(color, calculate_sub_pixel(scene, cam, sub, sampling));
			sub.y += increment;
		}
		sub.x += increment;
	}
	return (v3f_to_color(color));
}

t_vector3f	calculate_sub_pixel(t_scene *scene, t_camera *cam,
								t_vector2f pos, float coef)
{
	t_ray_hit	hit;
	t_ray		ray;
	t_vector3f	color;

	color = V3F_ZERO;
	ray = RAY_INIT(cam->position, camera_direction(cam, pos), RAY_LENGTH);
	while (42)
	{
		if (!ray_cast(&ray, &hit, scene))
			break ;
		color = v3f_add(color, calculate_lighting(scene, &ray, &hit, coef));
		if (hit.object->mat->reflection != 0 &&
		ray.level_reflection < MAX_RAY_REFLECTIONS)
			reflection(&ray, &hit, &coef);
		else if (hit.object->mat->transparency != 0 &&
		ray.level_refraction < MAX_RAY_REFRACTION)
			refraction(&ray, &hit, &coef);
		else
			break ;
	}
	return (color);
}

float		calculate_shadow_coef(t_ray *ray, t_scene *scene)
{
	t_list		*hits;
	t_ray_hit	*iterator;
	float		transparency;

	transparency = 1.0f;
	hits = ray_cast_all(ray, scene);
	if (hits == NULL)
		return (1);
	list_set_start(hits);
	while ((iterator = list_next(hits)))
		transparency *= iterator->object->mat->transparency;
	list_clear_inner(hits, list_default_remove_functor);
	free(hits);
	return (transparency);
}

t_vector3f	calculate_lighting(t_scene *scene,
								t_ray *ray,
								t_ray_hit *hit,
								float coef)
{
	t_vector3f	color;
	t_ray		photon;
	int			i;
	float		t;
	float		transparency;

	i = -1;
	color = v3f_mul_float(v3f_mul(v3f_mul(hit->object->mat->diffuse,
		calculate_texture_color(hit)), scene->ambient_light), coef);
	while (++i < scene->lights_count)
	{
		if (!light_is_eligible(scene->lights + i, hit, &t))
			continue ;
		photon.start = hit->point;
		photon.dir = v3f_mul_float(
			v3f_sub(scene->lights[i].position, hit->point), 1 / t);
		photon.length = v3f_distance(scene->lights[i].position, hit->point);
		if ((transparency = calculate_shadow_coef(&photon, scene)))
			color = v3f_mul_float(v3f_add(color, v3f_add(
				light_get_specular(scene->lights + i, ray, &photon, hit),
				light_get_diffuse(scene->lights + i, &photon, hit))),
									coef * transparency);
	}
	return (color);
}

t_vector3f	calculate_texture_color(t_ray_hit *hit)
{
	t_vector2f	uv;
	t_vector3f	color;
	int			pixel;

	color = V3F_ONE;
	pixel = 0;
	if (hit->object->mat->texture != NULL)
	{
		uv = ray_get_uv(hit);
		uv.x *= hit->object->mat->texture->width *
				hit->object->mat->texture_coef.x;
		uv.y *= hit->object->mat->texture->height *
				hit->object->mat->texture_coef.y;
		uv.x = (int)(uv.x + hit->object->mat->texture_offset.x) %
							hit->object->mat->texture->width;
		uv.y = (int)(uv.y + hit->object->mat->texture_offset.y) %
							hit->object->mat->texture->height;
		pixel = tex_get_pixel(hit->object->mat->texture, uv.x, uv.y);
		color = V3F_INIT(((pixel >> 16) & 0xFF) / 255.0f,
						((pixel >> 8) & 0xFF) / 255.0f,
						((pixel >> 0) & 0xFF) / 255.0f);
	}
	return (color);
}
