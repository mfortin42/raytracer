/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blurr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 12:41:32 by tbalu             #+#    #+#             */
/*   Updated: 2016/06/30 12:08:17 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

static t_vector3f	color_average(int *color_pixels, int blurr)
{
	t_vector3f	color_blurr;
	int			i;

	color_blurr.x = 0.0;
	color_blurr.y = 0.0;
	color_blurr.z = 0.0;
	i = 0;
	while (i < blurr)
	{
		color_blurr.x += (color_pixels[i] >> 16) & 0xFF;
		color_blurr.y += (color_pixels[i] >> 8) & 0xFF;
		color_blurr.z += (color_pixels[i] >> 0) & 0xFF;
		i++;
	}
	color_blurr.x /= blurr;
	color_blurr.y /= blurr;
	color_blurr.z /= blurr;
	return (color_blurr);
}

static t_vector3f	get_color_blurr(t_texture *t, int blurr, int x, int y)
{
	int		i;
	int		j;
	int		color_pixels[POW2(blurr)];

	i = 0;
	while (i < blurr)
	{
		j = 0;
		while (j < blurr)
		{
			if ((x - (blurr / 2) + i) > 0 && (y - (blurr / 2) + j) > 0 &&
				(x - (blurr / 2) + i) < t->width &&
				(y - (blurr / 2) + j) < t->height)
				color_pixels[blurr * i + j] = tex_get_pixel(t,
					x - (blurr / 2) + i, y - (blurr / 2) + j);
			else
				color_pixels[blurr * i + j] = 0;
			j++;
		}
		i++;
	}
	return (color_average(color_pixels, POW2(blurr)));
}

void				post_effects_blurr(t_texture *t)
{
	int			x;
	int			y;
	t_vector3f	color_blurr;
	t_vector3f	color_final;

	y = 0;
	while (y < t->height)
	{
		x = 0;
		while (x < t->width)
		{
			color_blurr = get_color_blurr(t, 9, x, y);
			color_final = v3f_div_float(color_blurr, 255.0f);
			tex_draw_pixel(t, x, y, v3f_to_color(color_final));
			x++;
		}
		y++;
	}
}
