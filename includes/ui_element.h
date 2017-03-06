/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_element.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 20:23:43 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/25 17:55:58 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_ELEMENT_H
# define UI_ELEMENT_H

t_ui_element	*element_new(t_interface *core, int color,
							t_vector2f position, t_vector2f size);
t_ui_element	*element_new_texture(t_interface *core, t_texture *tex,
									t_vector2f position, t_vector2f size);
void			element_update(t_ui_element *e, t_core *c, t_vector2f p);
void			element_bind_hooks(t_ui_element *elem, t_ui_hook hooks[4]);
void			element_set_color(t_ui_element *elem, int color);
void			element_resize(t_ui_element *elem, t_vector2f size);

#endif
