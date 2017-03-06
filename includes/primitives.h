/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:05 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 12:52:04 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMITIVES_H
# define PRIMITIVES_H

int		sphere_intersect(t_ray *ray, t_object *obj, float *delta);
int		plane_intersect(t_ray *ray, t_object *obj, float *delta);
int		cylinder_intersect(t_ray *ray, t_object *obj, float *delta);
int		cone_intersect(t_ray *ray, t_object *obj, float *delta);
int		disk_intersect(t_ray *ray, t_object *obj, float *delta);

int		sphere_calculate_normal(t_ray *r, t_ray_hit *h);
int		plane_calculate_normal(t_ray *r, t_ray_hit *h);
int		cylinder_calculate_normal(t_ray *r, t_ray_hit *h);
int		cone_calculate_normal(t_ray *r, t_ray_hit *h);

void	sphere_init(t_object *obj);
void	plane_init(t_object *obj);
void	cylinder_init(t_object *obj);
void	cone_init(t_object *obj);
void	disk_init(t_object *obj);

int		resolve_quadratic(float det, float a, float b, float *t);

#endif
