/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 16:26:39 by bkabbas           #+#    #+#             */
/*   Updated: 2016/06/30 18:03:00 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

void	interface_init_rotation_helper(t_interface *ui,
										t_vector2f p)
{
	t_ui_element	*elem;
	int				ytmp;
	t_vector4f		remap;
	t_vector2f		s;

	remap = m4f_mul_vector(ui->matrix, V4F_INIT(50, 50, 0, 0));
	ytmp = remap.y;
	s = V2F_INIT(remap.x, remap.y);
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x - s.x, p.y - s.y), s);
	label_new_attach(ui, elem, "Bot");
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x - s.x, p.y - s.y * 2), s);
	label_new_attach(ui, elem, "Top");
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x - s.x * 2, p.y - s.y), s);
	label_new_attach(ui, elem, ">");
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x - s.x * 3, p.y - s.y), s);
	label_new_attach(ui, elem, "v");
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x - s.x * 3, p.y - s.y * 2), s);
	label_new_attach(ui, elem, "^");
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x - s.x * 4, p.y - s.y), s);
	label_new_attach(ui, elem, "<");
	remap = m4f_mul_vector(ui->matrix, V4F_INIT(s.x * 4, 40, 0, 0));
	s = V2F_INIT(remap.x, remap.y);
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x - s.x, p.y - ytmp * 3), s);
	label_new_attach(ui, elem, "Rotation");
}

void	interface_init_movement_helper(t_interface *ui,
										t_vector2f p)
{
	t_ui_element	*elem;
	int				ytmp;
	t_vector4f		remap;
	t_vector2f		s;

	remap = m4f_mul_vector(ui->matrix, V4F_INIT(50, 50, 0, 0));
	ytmp = remap.y;
	s = V2F_INIT(remap.x, remap.y);
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x + s.x * 3, p.y - s.y), s);
	label_new_attach(ui, elem, "G");
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x + s.x * 3, p.y - s.y * 2), s);
	label_new_attach(ui, elem, "T");
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x, p.y - s.y), s);
	label_new_attach(ui, elem, "Q");
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x + s.x, p.y - s.y), s);
	label_new_attach(ui, elem, "S");
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x + s.x, p.y - s.y * 2), s);
	label_new_attach(ui, elem, "W");
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x + s.x * 2, p.y - s.y), s);
	label_new_attach(ui, elem, "D");
	remap = m4f_mul_vector(ui->matrix, V4F_INIT(s.x * 4, 40, 0, 0));
	s = V2F_INIT(remap.x, remap.y);
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x, p.y - ytmp * 3), s);
	label_new_attach(ui, elem, "Movements");
}

void	interface_init_tools(t_interface *ui, t_vector2f p,
							float pit, t_ui_hook hooks[4])
{
	t_ui_element	*elem;
	t_vector4f		remap;
	t_vector2f		s;

	remap = m4f_mul_vector(ui->matrix, V4F_INIT(200, 40, 0, 0));
	s = V2F_INIT(remap.x, remap.y);
	hooks[1] = button_reload_scene;
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x - s.x, p.y), s);
	element_bind_hooks(elem, hooks);
	label_new_attach(ui, elem, "Reload");
	hooks[1] = button_screenshot;
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x - s.x, p.y + pit + s.y), s);
	element_bind_hooks(elem, hooks);
	label_new_attach(ui, elem, "Screenshot");
}

void	button_screenshot(t_ui_element *elem, t_core *core)
{
	(void)elem;
	screenshot(core, SCREENSHOT_FILENAME);
}

void	button_reload_scene(t_ui_element *elem, t_core *core)
{
	(void)elem;
	core_free(core);
	parsing(core, core->scene, core->file);
	core_init(core, core->scene);
	interface_init(&core->interface, core->screen_size);
	rasterize_mt(core);
}
