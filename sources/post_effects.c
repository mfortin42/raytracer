/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_effects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 18:05:36 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 14:24:36 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

void		post_effects_inverse(t_texture *t)
{
	int			i;
	int			pixel;
	t_vector3f	color;
	t_vector3f	inversed;

	i = -1;
	while (++i < t->size / t->bytes_per_pixel)
	{
		pixel = *((unsigned int *)(t->pixels + (i * t->bytes_per_pixel)));
		color.x = ((pixel >> 16) & 0xFF) / 255.0f;
		color.y = ((pixel >> 8) & 0xFF) / 255.0f;
		color.z = ((pixel >> 0) & 0xFF) / 255.0f;
		inversed.x = fabs(1.0f - color.x);
		inversed.y = fabs(1.0f - color.y);
		inversed.z = fabs(1.0f - color.z);
		*((unsigned int *)(t->pixels + (i * t->bytes_per_pixel))) =
		v3f_to_color(inversed);
	}
}

void		post_effects_sepia(t_texture *t)
{
	int			i;
	int			pixel;
	int			color[3];
	t_vector3f	sepia;

	i = -1;
	while (++i < t->size / t->bytes_per_pixel)
	{
		pixel = *((unsigned int *)(t->pixels + (i * t->bytes_per_pixel)));
		color[0] = ((pixel >> 16) & 0xFF);
		color[1] = ((pixel >> 8) & 0xFF);
		color[2] = ((pixel >> 0) & 0xFF);
		sepia.x =
		(color[0] * 0.393f) + (color[1] * 0.769f) + (color[2] * 0.189f);
		sepia.y =
		(color[0] * 0.349f) + (color[1] * 0.686f) + (color[2] * 0.168f);
		sepia.z =
		(color[0] * 0.272f) + (color[1] * 0.534f) + (color[2] * 0.131f);
		*((unsigned int *)(t->pixels + (i * t->bytes_per_pixel))) =
		v3f_to_color(v3f_div_float(sepia, 255.0f));
	}
}

void		post_effects_grayscale(t_texture *t)
{
	int			i;
	int			pixel;
	int			gray;
	int			color[3];

	i = -1;
	while (++i < t->size / t->bytes_per_pixel)
	{
		pixel = *((unsigned int *)(t->pixels + (i * t->bytes_per_pixel)));
		color[0] = ((pixel >> 16) & 0xFF);
		color[1] = ((pixel >> 8) & 0xFF);
		color[2] = ((pixel >> 0) & 0xFF);
		gray = (color[0] + color[1] + color[2]) / 3;
		*((unsigned int *)(t->pixels + (i * t->bytes_per_pixel))) =
		v3f_to_color(V3F_INIT(gray / 255.0f, gray / 255.0f, gray / 255.0f));
	}
}

void		post_effects_init(t_core *core)
{
	core->filters[0].effect = post_effects_blurr;
	core->filters[0].activated = 0;
	core->filters[1].effect = post_effects_grayscale;
	core->filters[1].activated = 0;
	core->filters[2].effect = post_effects_sepia;
	core->filters[2].activated = 0;
	core->filters[3].effect = post_effects_inverse;
	core->filters[3].activated = 0;
}
