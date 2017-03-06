/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 21:23:12 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 18:03:01 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

void	button_mouse_enter(t_ui_element *elem, t_core *core)
{
	element_set_color(elem, 0xCCCCCC);
	swap_buffer(core);
}

void	button_mouse_leave(t_ui_element *elem, t_core *core)
{
	element_set_color(elem, 0xFFFFFF);
	swap_buffer(core);
}

void	button_click_down(t_ui_element *elem, t_core *core)
{
	element_set_color(elem, 0x777777);
	swap_buffer(core);
}

void	button_hide_interface(t_ui_element *elem, t_core *core)
{
	t_ui_element	*it_elem;
	t_label			*it_label;

	core->interface.hide_ui = !core->interface.hide_ui;
	list_set_start(core->interface.elements);
	while ((it_elem = list_next(core->interface.elements)))
		if (it_elem != elem)
			it_elem->active = core->interface.hide_ui;
	list_set_start(core->interface.labels);
	while ((it_label = list_next(core->interface.labels)))
		if (it_label != core->interface.hide_label)
			it_label->active = core->interface.hide_ui;
	if (core->interface.hide_ui)
	{
		label_update_text(core->interface.hide_label, "Hide Interface",
		V3F_INIT(0, 0, 0));
	}
	else
	{
		label_update_text(core->interface.hide_label, "Show Interface",
		V3F_INIT(0, 0, 0));
	}
	progress_bar_show(&core->interface, 0);
	swap_buffer(core);
}
