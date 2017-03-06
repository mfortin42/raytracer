/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_element.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 17:47:14 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 14:48:33 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

t_ui_element	*element_new(t_interface *core, int color,
							t_vector2f position, t_vector2f size)
{
	t_ui_element	*ret;

	ret = malloc(sizeof(t_ui_element));
	ret->texture = tex_new(size.x, size.y);
	ret->rect.x = position.x;
	ret->rect.y = position.y;
	ret->rect.w = size.x;
	ret->rect.h = size.y;
	ret->inside = 0;
	ret->active = 1;
	element_set_color(ret, color);
	ret->on_click_down = element_default_click_down;
	ret->on_click_up = element_default_click_up;
	ret->on_mouse_enter = element_default_mouse_enter;
	ret->on_mouse_leave = element_default_mouse_leave;
	list_push_back(core->elements, ret);
	return (ret);
}

void			element_update(t_ui_element *elem, t_core *core, t_vector2f pos)
{
	if (pos.x >= elem->rect.x &&
		pos.y >= elem->rect.y &&
		pos.x < elem->rect.x + elem->rect.w &&
		pos.y < elem->rect.y + elem->rect.h)
	{
		if (!elem->inside)
			elem->on_mouse_enter(elem, core);
		elem->inside = 1;
	}
	else
	{
		if (elem->inside)
			elem->on_mouse_leave(elem, core);
		elem->inside = 0;
	}
	if (get_mouse_button_down(1) && elem->inside)
		elem->on_click_down(elem, core);
	if (get_mouse_button_up(1) && elem->inside)
	{
		elem->inside = 0;
		elem->on_click_up(elem, core);
	}
}

void			element_set_color(t_ui_element *elem, int color)
{
	int				i;
	int				real_size;

	i = -1;
	real_size = elem->texture->size / elem->texture->bytes_per_pixel;
	while (++i < real_size)
		*((unsigned int *)(elem->texture->pixels +
		(i * elem->texture->bytes_per_pixel))) = color;
	elem->color = color;
}

void			element_bind_hooks(t_ui_element *elem, t_ui_hook hooks[4])
{
	elem->on_click_down = hooks[0];
	elem->on_click_up = hooks[1];
	elem->on_mouse_enter = hooks[2];
	elem->on_mouse_leave = hooks[3];
}

void			element_resize(t_ui_element *elem, t_vector2f size)
{
	free(elem->texture);
	elem->texture = tex_new(size.x, size.y);
	element_set_color(elem, elem->color);
	elem->rect.w = size.x;
	elem->rect.h = size.y;
}
