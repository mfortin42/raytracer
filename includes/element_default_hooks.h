/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_default_hooks.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 20:22:33 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/24 20:27:45 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_DEFAULT_HOOKS_H
# define ELEMENT_DEFAULT_HOOKS_H

void		element_default_mouse_enter(t_ui_element *elem, t_core *core);
void		element_default_mouse_leave(t_ui_element *elem, t_core *core);
void		element_default_click_down(t_ui_element *elem, t_core *core);
void		element_default_click_up(t_ui_element *elem, t_core *core);

#endif
