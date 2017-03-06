/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_effects.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 16:41:52 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/28 19:06:11 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POST_EFFECTS_H
# define POST_EFFECTS_H

void	post_effects_init(t_core *core);
void	post_effects_grayscale(t_texture *t);
void	post_effects_sepia(t_texture *t);
void	post_effects_blurr(t_texture *t);
void	post_effects_inverse(t_texture *t);

#endif
