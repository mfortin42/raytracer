/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 22:44:45 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 12:16:26 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

t_label		*label_new(t_interface *ui, t_rect rect, char *text)
{
	t_label		*ret;

	ret = (t_label *)malloc(sizeof(t_label));
	ret->texture = NULL;
	ret->attached = NULL;
	ret->font = ui->font;
	ret->rect = rect;
	ret->active = 1;
	label_update_text(ret, text, V3F_INIT(0.0, 0.0, 0.0));
	list_push_back(ui->labels, ret);
	return (ret);
}

t_label		*label_new_attach(t_interface *ui, t_ui_element *e, char *text)
{
	t_label *ret;

	ret = (t_label *)malloc(sizeof(t_label));
	ret->texture = NULL;
	ret->attached = e;
	ret->font = ui->font;
	ret->active = 1;
	label_update_text(ret, text, V3F_INIT(0.0, 0.0, 0.0));
	list_push_back(ui->labels, ret);
	return (ret);
}

void		label_update_text(t_label *label, char *text, t_vector3f color)
{
	SDL_Color sdl_color;

	if (label->texture)
	{
		SDL_FreeSurface(label->texture->img);
		free(label->texture);
	}
	sdl_color = (SDL_Color) { color.x * 255, color.y * 255, color.z * 255, 0 };
	label->texture =
	tex_new_surface(TTF_RenderUTF8_Blended(label->font, text, sdl_color));
	if (label->attached)
	{
		label->rect.x = label->attached->rect.x +
						label->attached->rect.w / 2 -
						label->texture->width / 2;
		label->rect.y = label->attached->rect.y +
						label->attached->rect.h / 2 -
						label->texture->height / 2;
	}
}
