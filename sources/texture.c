/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:06 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 12:45:32 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_texture		*tex_new(int width, int height)
{
	SDL_Surface	*s;

	if ((s = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0)) == NULL)
		return (NULL);
	return (tex_new_surface(s));
}

t_texture		*tex_new_bmp(char *file)
{
	SDL_Surface	*s;

	if ((s = SDL_LoadBMP(file)) == NULL)
		return (NULL);
	return (tex_new_surface(s));
}

t_texture		*tex_new_surface(SDL_Surface *s)
{
	t_texture	*ret;

	ret = (t_texture *)malloc(sizeof(t_texture));
	ret->img = s;
	ret->pixels = s->pixels;
	ret->width = s->w;
	ret->height = s->h;
	ret->bytes_per_pixel = s->format->BytesPerPixel;
	ret->l_size = s->pitch;
	ret->size = ret->height * ret->l_size;
	return (ret);
}

void			tex_draw_pixel(t_texture *tex, int x, int y, int pixel)
{
	*((unsigned int *)(tex->pixels +
	((y * tex->l_size) +
	(x * tex->bytes_per_pixel)))) = pixel;
}

int				tex_get_pixel(t_texture *tex, int x, int y)
{
	return (*((unsigned int *)(tex->pixels +
			((y * tex->l_size) +
			(x * tex->bytes_per_pixel)))));
}
