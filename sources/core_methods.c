/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:40:09 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 14:18:35 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

void	swap_buffer(t_core *core)
{
	SDL_Surface		*s;

	s = SDL_GetWindowSurface(core->win);
	SDL_BlitSurface(core->screen->img, NULL, s, NULL);
	interface_draw(&core->interface, s);
	SDL_UpdateWindowSurface(core->win);
}

void	poll_events(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			exit(0);
		else if (event.type == SDL_KEYDOWN)
			internal_key_down_hook(event.key.keysym.sym);
		else if (event.type == SDL_KEYUP)
			internal_key_up_hook(event.key.keysym.sym);
		else if (event.type == SDL_MOUSEMOTION)
			internal_mouse_pos_hook(event.motion.x, event.motion.y);
		else if (event.type == SDL_MOUSEBUTTONDOWN)
			internal_mouse_down_hook(event.button.button,
								event.button.x, event.button.y);
		else if (event.type == SDL_MOUSEBUTTONUP)
			internal_mouse_up_hook(event.button.button,
								event.button.x, event.button.y);
		else if (event.type == SDL_WINDOWEVENT)
			if (event.window.event == SDL_WINDOWEVENT_CLOSE)
				exit(0);
	}
}

void	update(t_core *core)
{
	poll_events();
	if (camera_move(core->scene->camera) || camera_rotate(core->scene->camera))
		rasterize_mt(core);
	interface_poll_events(core);
	key_up(-1, CMD_SET_ALL, FALSE);
	mouse_up(-1, CMD_SET_ALL, FALSE);
}

void	core_init(t_core *core, t_scene *scene)
{
	if (!core->headless_mode)
	{
		if ((core->win = SDL_CreateWindow("Raytracer",
											SDL_WINDOWPOS_CENTERED,
											SDL_WINDOWPOS_CENTERED,
											core->screen_size.x,
											core->screen_size.y,
											SDL_WINDOW_SHOWN)) == NULL)
			exit(0);
	}
	if ((core->screen = tex_new(core->screen_size.x,
								core->screen_size.y)) == NULL)
		exit(0);
	core->scene = scene;
	post_effects_init(core);
}
