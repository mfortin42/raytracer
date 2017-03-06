/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_hooks.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 21:31:59 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/28 22:17:15 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_HOOKS_H
# define BUTTON_HOOKS_H

void	button_mouse_enter(t_ui_element *elem, t_core *core);
void	button_mouse_leave(t_ui_element *elem, t_core *core);
void	button_click_down(t_ui_element *elem, t_core *core);
void	button_aliasing_up(t_ui_element *elem, t_core *core);
void	button_aliasing_down(t_ui_element *elem, t_core *core);
void	button_screenshot(t_ui_element *elem, t_core *core);
void	button_reload_scene(t_ui_element *elem, t_core *core);
void	button_blurr(t_ui_element *elem, t_core *core);
void	button_grayscale(t_ui_element *elem, t_core *core);
void	button_sepia(t_ui_element *elem, t_core *core);
void	button_inverse(t_ui_element *elem, t_core *core);
void	button_hide_interface(t_ui_element *ele, t_core *core);

#endif
