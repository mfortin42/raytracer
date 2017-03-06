/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   releaser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:02:05 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/28 20:43:07 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

void	element_free(t_ui_element *element)
{
	tex_free(element->texture);
	free(element);
}

void	label_free(t_label *label)
{
	tex_free(label->texture);
	free(label);
}

void	tex_free(t_texture *tex)
{
	SDL_FreeSurface(tex->img);
	free(tex);
}

void	scene_free(t_scene *scene)
{
	int i;

	free(scene->camera);
	free(scene->objects);
	free(scene->lights);
	free(scene->materials);
	i = -1;
	while (++i < scene->textures_count)
		SDL_FreeSurface((scene->textures + i)->img);
	free(scene->textures);
	ft_bzero(scene, sizeof(t_scene));
}

void	core_free(t_core *core)
{
	SDL_DestroyWindow(core->win);
	tex_free(core->screen);
	TTF_CloseFont(core->interface.font);
	list_delete_inner(core->interface.elements, (void (*)(void *))element_free);
	list_delete_inner(core->interface.labels, (void (*)(void *))label_free);
	free(core->interface.matrix);
	ft_bzero(&core->interface, sizeof(t_interface));
	scene_free(core->scene);
	core->screen_size = V2F_INIT(0, 0);
}
