/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 18:33:52 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 18:01:54 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <stdio.h>

void		interface_init_show(t_interface *ui,
								t_vector2f p,
								t_ui_hook hooks[4])
{
	t_ui_element	*elem;
	t_vector4f		remap;
	t_vector2f		s;

	remap = m4f_mul_vector(ui->matrix, V4F_INIT(200, 40, 0, 0));
	s = V2F_INIT(remap.x, remap.y);
	hooks[1] = button_hide_interface;
	elem = element_new(ui, 0xFFFFFF, p, s);
	element_bind_hooks(elem, hooks);
	ui->hide_label = label_new_attach(ui, elem, "Hide Interface");
}

void		interface_generate_layout(t_interface *ui, t_vector2f resolution)
{
	t_ui_hook		hooks[4];
	t_vector2f		pit;
	t_vector2f		pos;
	t_vector2f		offset;

	hooks[0] = button_click_down;
	hooks[2] = button_mouse_enter;
	hooks[3] = button_mouse_leave;
	pit = V2F_INIT(resolution.y / 200, resolution.x / 200);
	offset = V2F_INIT(resolution.x / 20, resolution.y / 20);
	pos = V2F_INIT(offset.x, offset.y);
	interface_init_show(ui, pos, hooks);
	pos = V2F_INIT(resolution.x - offset.x, offset.y);
	interface_init_tools(ui, pos, pit.y, hooks);
	pos = V2F_INIT(resolution.x - offset.x, offset.y + (pit.y * 2));
	hooks[1] = button_blurr;
	interface_init_post_effects(ui, pos, pit.y, hooks);
	pos = V2F_INIT(resolution.x - offset.x, resolution.y - offset.y);
	interface_init_rotation_helper(ui, pos);
	pos = V2F_INIT(offset.x, resolution.y - offset.y);
	interface_init_movement_helper(ui, pos);
	pos = V2F_INIT(resolution.x - offset.x, offset.y + (pit.y * 8));
	interface_init_aliasing(ui, pos, pit.y, hooks);
	progress_bar_init(ui, resolution);
}

void		interface_init(t_interface *ui, t_vector2f resolution)
{
	t_vector3f scale_vector;

	if (TTF_Init() == -1)
		exit(0);
	if ((ui->font =
	TTF_OpenFont("resources/font.ttf", resolution.y / 25)) == NULL)
		exit(0);
	ui->elements = list_new();
	ui->labels = list_new();
	ui->hide_ui = 1;
	scale_vector.x = resolution.x / NATIVE_WIDTH;
	scale_vector.y = resolution.y / NATIVE_HEIGHT;
	scale_vector.z = 0;
	ui->matrix = m4f_new();
	m4f_scale(ui->matrix, scale_vector);
	interface_generate_layout(ui, resolution);
}

void		interface_poll_events(t_core *core)
{
	t_ui_element	*iterator;
	t_vector2f		mousepos;

	mousepos = get_mouse_pos();
	list_set_start(core->interface.elements);
	while ((iterator = list_next(core->interface.elements)))
		element_update(iterator, core, mousepos);
}

void		interface_draw(t_interface *ui, SDL_Surface *s)
{
	t_ui_element	*i;
	t_label			*j;

	list_set_start(ui->elements);
	while ((i = list_next(ui->elements)))
		if (i->active)
			SDL_BlitSurface(i->texture->img, NULL, s, (SDL_Rect *)&i->rect);
	list_set_start(ui->labels);
	while ((j = list_next(ui->labels)))
		if (j->active)
			SDL_BlitSurface(j->texture->img, NULL, s, (SDL_Rect *)&j->rect);
}
