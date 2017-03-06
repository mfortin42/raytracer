/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:05 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 12:52:28 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RASTERIZER_H
# define RASTERIZER_H

void		rasterize(t_core *core);
int			calculate_pixel(t_scene *scene, t_camera *cam, int x, int y);
t_vector3f	calculate_sub_pixel(t_scene *scene, t_camera *cam, t_vector2f pos,
			float coef);
t_vector3f	calculate_lighting(t_scene *scene, t_ray *ray, t_ray_hit *hit,
			float coef);
t_vector3f	calculate_texture_color(t_ray_hit *hit);

#endif
