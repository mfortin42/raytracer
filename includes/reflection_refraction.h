/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_refraction.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:00:07 by tbalu             #+#    #+#             */
/*   Updated: 2016/06/23 13:25:20 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFLECTION_REFRACTION_H
# define REFLECTION_REFRACTION_H

void	reflection(t_ray *ray, t_ray_hit *hit, float *coef);
void	refraction(t_ray *ray, t_ray_hit *hit, float *coef);

#endif
