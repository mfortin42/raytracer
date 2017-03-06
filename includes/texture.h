/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:06 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/23 20:53:54 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

t_texture	*tex_new(int width, int height);
t_texture	*tex_new_bmp(char *file);
t_texture	*tex_new_surface(SDL_Surface *s);
void		tex_draw_pixel(t_texture *tex, int x, int y, int pixel);
int			tex_get_pixel(t_texture *tex, int x, int y);

#endif
