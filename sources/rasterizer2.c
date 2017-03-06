/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterizer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:06 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 14:47:51 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void				rasterize_mt(t_core *core)
{
	int				i;
	t_thread		*t;
	pthread_t		*list[4];

	i = -1;
	t = get_ts();
	t->current_p = 0;
	if (!core->headless_mode)
		progress_bar_show(&core->interface, 1);
	while (++i < 4)
		list[i] = new_thread(&doctrine, core);
	main_doctrine(core);
	i = -1;
	while (++i < 4)
		pthread_join(*list[i], NULL);
	rasterize_done(core);
	i = -1;
	while (++i < 4)
		free(list[i]);
}

void				rasterize_done(t_core *core)
{
	int				i;

	i = -1;
	if (!core->headless_mode)
	{
		while (++i < POST_EFFECTS_COUNT)
			if (core->filters[i].activated)
				core->filters[i].effect(core->screen);
		progress_bar_show(&core->interface, 0);
		swap_buffer(core);
	}
	else
	{
		if (screenshot(core, core->screenshot_path))
		{
			ft_putendl(ft_strjoin("correctly rendered image : ",
			core->screenshot_path));
		}
		else
		{
			ft_putendl(ft_strjoin("render failed, probably due to path : ",
			core->screenshot_path));
		}
		exit(1);
	}
}
