/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 18:04:38 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 17:17:43 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# define NATIVE_WIDTH 1280
# define NATIVE_HEIGHT 720

void	interface_init(t_interface *ui, t_vector2f screen_size);
void	interface_init_post_effects(t_interface *ui, t_vector2f p,
								float pit, t_ui_hook hooks[4]);
void	interface_init_aliasing(t_interface *ui, t_vector2f p,
								float pit, t_ui_hook hooks[4]);
void	interface_init_tools(t_interface *ui, t_vector2f p,
							float pit, t_ui_hook hooks[4]);
void	interface_init_rotation_helper(t_interface *ui, t_vector2f p);
void	interface_init_movement_helper(t_interface *ui, t_vector2f p);
void	interface_poll_events(t_core *core);
void	interface_draw(t_interface *ui, SDL_Surface *s);

#endif
