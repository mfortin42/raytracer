/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_post_effects.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 14:49:37 by bkabbas           #+#    #+#             */
/*   Updated: 2016/06/30 18:02:20 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

void	interface_init_post_effects(t_interface *ui,
									t_vector2f p,
									float pit,
									t_ui_hook hooks[4])
{
	t_ui_element	*elem;
	t_vector4f		remap;
	t_vector2f		s;
	float			h;

	remap = m4f_mul_vector(ui->matrix, V4F_INIT(200, 40, 0, 0));
	s = V2F_INIT(remap.x, remap.y);
	h = pit + s.y;
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x - s.x, p.y + h * 2), s);
	label_new_attach(ui, elem, "Post Effects");
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x - s.x, p.y + h * 3), s);
	ui->blurr = label_new_attach(ui, elem, "Blurr : Off");
	element_bind_hooks(elem, hooks);
	hooks[1] = button_grayscale;
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x - s.x, p.y + h * 4), s);
	ui->grayscale = label_new_attach(ui, elem, "Grayscale : Off");
	element_bind_hooks(elem, hooks);
	hooks[1] = button_sepia;
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x - s.x, p.y + h * 5), s);
	ui->sepia = label_new_attach(ui, elem, "Sepia : Off");
	element_bind_hooks(elem, hooks);
	hooks[1] = button_inverse;
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x - s.x, p.y + h * 6), s);
	ui->inverse = label_new_attach(ui, elem, "Inverse : Off");
	element_bind_hooks(elem, hooks);
}

void	button_blurr(t_ui_element *elem, t_core *core)
{
	element_set_color(elem, 0xFFFFFF);
	core->filters[0].activated = !core->filters[0].activated;
	if (core->filters[0].activated)
	{
		label_update_text(core->interface.blurr, "Blurr : On",
		V3F_INIT(0, 0, 0));
		post_effects_blurr(core->screen);
		swap_buffer(core);
	}
	else
	{
		label_update_text(core->interface.blurr, "Blurr : Off",
		V3F_INIT(0, 0, 0));
		rasterize_mt(core);
	}
}

void	button_grayscale(t_ui_element *elem, t_core *core)
{
	element_set_color(elem, 0xFFFFFF);
	core->filters[1].activated = !core->filters[1].activated;
	if (core->filters[1].activated)
	{
		label_update_text(core->interface.grayscale, "Grayscale : On",
		V3F_INIT(0, 0, 0));
		post_effects_grayscale(core->screen);
		swap_buffer(core);
	}
	else
	{
		label_update_text(core->interface.grayscale, "Grayscale : Off",
		V3F_INIT(0, 0, 0));
		rasterize_mt(core);
	}
}

void	button_sepia(t_ui_element *elem, t_core *core)
{
	element_set_color(elem, 0xFFFFFF);
	core->filters[2].activated = !core->filters[2].activated;
	if (core->filters[2].activated)
	{
		label_update_text(core->interface.sepia, "Sepia : On",
		V3F_INIT(0, 0, 0));
		post_effects_sepia(core->screen);
		swap_buffer(core);
	}
	else
	{
		label_update_text(core->interface.sepia, "Sepia : Off",
		V3F_INIT(0, 0, 0));
		rasterize_mt(core);
	}
}

void	button_inverse(t_ui_element *elem, t_core *core)
{
	element_set_color(elem, 0xFFFFFF);
	core->filters[3].activated = !core->filters[3].activated;
	if (core->filters[3].activated)
	{
		label_update_text(core->interface.inverse, "Inverse : On",
		V3F_INIT(0, 0, 0));
		post_effects_inverse(core->screen);
		swap_buffer(core);
	}
	else
	{
		label_update_text(core->interface.inverse, "Inverse : Off",
		V3F_INIT(0, 0, 0));
		rasterize_mt(core);
	}
}
