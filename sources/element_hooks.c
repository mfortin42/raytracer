/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_default_hooks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 20:20:00 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/25 00:26:55 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

void		element_default_mouse_enter(t_ui_element *elem, t_core *core)
{
	(void)core;
	(void)elem;
}

void		element_default_mouse_leave(t_ui_element *elem, t_core *core)
{
	(void)core;
	(void)elem;
}

void		element_default_click_down(t_ui_element *elem, t_core *core)
{
	(void)core;
	(void)elem;
}

void		element_default_click_up(t_ui_element *elem, t_core *core)
{
	(void)core;
	(void)elem;
}
