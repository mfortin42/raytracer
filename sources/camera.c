/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:06 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 14:17:25 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_camera	*camera_new(t_vector3f pos, t_vector3f rotation, t_vector2f size)
{
	t_camera	*ret;

	ret = malloc(sizeof(t_camera));
	ret->viewport = size;
	ret->position = pos;
	ret->rotation = rotation;
	return (ret);
}

t_vector3f	camera_direction(t_camera *cam, t_vector2f pos)
{
	t_vector3f	dir;
	float		ratio;

	ratio = cam->viewport.x / cam->viewport.y;
	pos.x = (2 * (pos.x / cam->viewport.x) - 1) * ratio * ZOOM;
	pos.y = (1 - 2 * (pos.y / cam->viewport.y)) * ZOOM;
	dir.x = pos.x * cos(cam->rotation.y) * cos(cam->rotation.x) +
			pos.y * (cos(cam->rotation.y) * sin(cam->rotation.x) *
			sin(cam->rotation.z) - sin(cam->rotation.y) *
			cos(cam->rotation.z)) + cos(cam->rotation.y) *
			sin(cam->rotation.x) * cos(cam->rotation.z) +
			sin(cam->rotation.y) * sin(cam->rotation.z);
	dir.y = pos.x * sin(cam->rotation.y) * cos(cam->rotation.x) +
			pos.y * (sin(cam->rotation.y) * sin(cam->rotation.x) *
			sin(cam->rotation.z) + cos(cam->rotation.y) *
			cos(cam->rotation.z)) + sin(cam->rotation.y) *
			sin(cam->rotation.x) * cos(cam->rotation.z) -
			cos(cam->rotation.y) * sin(cam->rotation.z);
	dir.z = pos.x * -sin(cam->rotation.x) + pos.y * cos(cam->rotation.x) *
			sin(cam->rotation.z) + cos(cam->rotation.x) * cos(cam->rotation.z);
	return (v3f_normalized(dir));
}

int			camera_move(t_camera *cam)
{
	int ret;

	ret = 0;
	if (get_key_down(Q) && (ret = 1))
		cam->position.x -= 50;
	if (get_key_down(D) && (ret = 1))
		cam->position.x += 50;
	if (get_key_down(S) && (ret = 1))
		cam->position.y -= 50;
	if (get_key_down(W) && (ret = 1))
		cam->position.y += 50;
	if (get_key_down(G) && (ret = 1))
		cam->position.z -= 50;
	if (get_key_down(T) && (ret = 1))
		cam->position.z += 50;
	return (ret);
}

int			camera_rotate(t_camera *cam)
{
	int ret;

	ret = 0;
	if (get_key_down(RIGHT_ARROW) && (ret = 1))
		cam->rotation.x -= 50;
	if (get_key_down(LEFT_ARROW) && (ret = 1))
		cam->rotation.x += 50;
	if (get_key_down(DOWN_ARROW) && (ret = 1))
		cam->rotation.z -= 50;
	if (get_key_down(UP_ARROW) && (ret = 1))
		cam->rotation.z += 50;
	if (get_key_down(PAGE_DOWN) && (ret = 1))
		cam->rotation.y += 50;
	if (get_key_down(PAGE_UP) && (ret = 1))
		cam->rotation.y -= 50;
	return (ret);
}
