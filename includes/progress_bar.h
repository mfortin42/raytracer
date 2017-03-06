/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_bar.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 18:36:39 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/28 02:00:53 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRESS_BAR_H
# define PROGRESS_BAR_H

void	progress_bar_init(t_interface *ui, t_vector2f resolution);
void	progress_bar_show(t_interface *ui, int val);
void	progress_bar_update(t_interface *ui, int y, int y_max);

#endif
