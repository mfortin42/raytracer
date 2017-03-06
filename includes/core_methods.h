/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_methods.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:40:53 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 12:49:04 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_METHODS_H
# define CORE_METHODS_H

void	swap_buffer(t_core *core);
void	poll_events();
void	update(t_core *core);
void	core_init(t_core *core, t_scene *scene);

#endif
