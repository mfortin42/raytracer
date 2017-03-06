/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelencl <fdelencl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:05 by fdelencl          #+#    #+#             */
/*   Updated: 2016/06/30 12:32:44 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int					rasterize_one(t_core *core)
{
	int				x;
	int				y;
	int				pixel;
	t_thread		*t;

	t = get_ts();
	pixel = t->current_p;
	t->current_p = pixel + 1;
	if (pixel < core->screen_size.x * core->screen_size.y - 1)
	{
		y = pixel / core->screen_size.x;
		x = pixel - y * core->screen_size.x;
		pixel = calculate_pixel(core->scene, core->scene->camera, x, y);
		tex_draw_pixel(core->screen, x, y, pixel);
		return (1);
	}
	return (0);
}

pthread_t			*new_thread(void *(*f)(void *), void *arg)
{
	pthread_t		*thread;
	t_thread		*status;

	status = get_ts();
	status->thread_amount++;
	thread = malloc(sizeof(pthread_t));
	if (!(pthread_create(thread, NULL, f, arg)))
		return (thread);
	return (NULL);
}

t_thread			*get_ts(void)
{
	static t_thread	*t = NULL;

	if (t == NULL)
	{
		t = malloc(sizeof(t_thread));
		t->thread_amount = 0;
		t->current_p = 0;
	}
	return (t);
}

void				*doctrine(void *core)
{
	t_thread		*t;

	t = get_ts();
	while (rasterize_one((t_core *)core))
		;
	t->thread_amount--;
	return (NULL);
}

void				main_doctrine(t_core *core)
{
	t_thread		*t;
	int				y;

	y = 0;
	t = get_ts();
	while (rasterize_one(core))
	{
		if (t->current_p / core->screen_size.x > y)
		{
			y = t->current_p / core->screen_size.x;
			if (!core->headless_mode)
			{
				progress_bar_update(&core->interface, y, core->screen_size.y);
				swap_buffer(core);
			}
		}
	}
}
