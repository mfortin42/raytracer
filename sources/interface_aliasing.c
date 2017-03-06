/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_aliasing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 15:33:01 by bkabbas           #+#    #+#             */
/*   Updated: 2016/06/30 17:58:06 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

void	interface_init_aliasing(t_interface *ui,
								t_vector2f p,
								float pit,
								t_ui_hook hooks[4])
{
	t_ui_element	*elem;
	t_vector4f		remap;
	t_vector2f		s;
	float			h;

	remap = m4f_mul_vector(ui->matrix, V4F_INIT(66, 40, 0, 0));
	s = V2F_INIT(remap.x, remap.y);
	h = p.y + (s.y + pit) * 8;
	hooks[1] = button_aliasing_down;
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x - s.x * 3, h), s);
	element_bind_hooks(elem, hooks);
	label_new_attach(ui, elem, "-");
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x - s.x * 2, h), s);
	ui->aliasing = label_new_attach(ui, elem, "1");
	hooks[1] = button_aliasing_up;
	elem = element_new(ui, 0xFFFFFF, V2F_INIT(p.x - s.x, h), s);
	element_bind_hooks(elem, hooks);
	label_new_attach(ui, elem, "+");
	remap = m4f_mul_vector(ui->matrix, V4F_INIT(198, 40, 0, 0));
	elem = element_new(ui, 0xFFFFFF,
						V2F_INIT(p.x - remap.x, p.y + (s.y * 8)),
						V2F_INIT(remap.x, remap.y));
	label_new_attach(ui, elem, "Aliasing");
}

void	button_aliasing_up(t_ui_element *elem, t_core *core)
{
	t_camera	*cam;
	t_vector3f	color;
	char		*aliasing_str;
	int			old_sampling;

	element_set_color(elem, 0xFFFFFF);
	cam = core->scene->camera;
	old_sampling = cam->sampling;
	cam->sampling = clampi(cam->sampling * 2, ALIASING_MIN, ALIASING_MAX);
	color = V3F_INIT(0, 0, 0);
	if (cam->sampling != old_sampling)
	{
		aliasing_str = ft_itoa(cam->sampling);
		if (cam->sampling == ALIASING_MAX)
			color = V3F_INIT(1.0f, 0.0f, 0.0f);
		label_update_text(core->interface.aliasing, aliasing_str, color);
		free(aliasing_str);
		rasterize_mt(core);
	}
}

void	button_aliasing_down(t_ui_element *elem, t_core *core)
{
	t_camera	*cam;
	t_vector3f	color;
	char		*aliasing_str;
	int			old_sampling;

	element_set_color(elem, 0xFFFFFF);
	cam = core->scene->camera;
	old_sampling = cam->sampling;
	color = V3F_INIT(0, 0, 0);
	cam->sampling = clampi(cam->sampling / 2, ALIASING_MIN, ALIASING_MAX);
	if (cam->sampling != old_sampling)
	{
		if (cam->sampling == ALIASING_MIN)
			color = V3F_INIT(0.0f, 1.0f, 0.0f);
		aliasing_str = ft_itoa(cam->sampling);
		label_update_text(core->interface.aliasing, aliasing_str, color);
		free(aliasing_str);
		rasterize_mt(core);
	}
}
