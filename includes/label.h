/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 23:06:08 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 12:49:31 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_H
# define LABEL_H

t_label		*label_new(t_interface *ui, t_rect rect, char *text);
t_label		*label_new_attach(t_interface *ui, t_ui_element *e, char *text);
void		label_update_text(t_label *label, char *text, t_vector3f color);

#endif
