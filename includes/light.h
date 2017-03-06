/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:05 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/08 20:16:28 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

t_light		*light_new(t_vector3f pos, t_vector3f color);
t_vector3f	light_get_ambiant(t_light *l, t_ray_hit *h, float c);
t_vector3f	light_get_diffuse(t_light *l, t_ray *p, t_ray_hit *h);
t_vector3f	light_get_specular(t_light *l, t_ray *r, t_ray *p, t_ray_hit *h);
int			light_is_eligible(t_light *l, t_ray_hit *h, float *t);

#endif
