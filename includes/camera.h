/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:05 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 12:49:18 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# define ALIASING_MIN 1
# define ALIASING_MAX 8
# define ZOOM 0.52056705055

t_camera	*camera_new(t_vector3f p, t_vector3f r, t_vector2f view);
t_vector3f	camera_direction(t_camera *c, t_vector2f pos);
int			camera_rotate(t_camera *cam);
int			camera_move(t_camera *cam);
int			camera_sampling(t_camera *cam);

#endif
