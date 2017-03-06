/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:05 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/23 16:13:01 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# define RAY_LENGTH 20000.0f
# define MAX_RAY_REFLECTIONS 5
# define MAX_RAY_REFRACTION 5
# define RAY_INIT(pos, dir, length) (t_ray) { pos, dir, length, 0, 0};

int				ray_cast(t_ray *ray, t_ray_hit *hit, t_scene *scene);
t_list			*ray_cast_all(t_ray *ray, t_scene *scene);
t_ray_hit		*ray_hit_new(t_ray *ray, t_object *obj, float delta);
t_vector2f		ray_get_uv(t_ray_hit *hit);

#endif
