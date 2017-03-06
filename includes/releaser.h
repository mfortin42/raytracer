/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   releaser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:38:06 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/28 20:38:47 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RELEASER_H
# define RELEASER_H

void	element_free(t_ui_element *element);
void	label_free(t_label *label);
void	tex_free(t_texture *tex);
void	scene_free(t_scene *scene);
void	core_free(t_core *core);

#endif
