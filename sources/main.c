/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:06 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 14:20:30 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	parse_special_args(t_core *core, char **av)
{
	if (!ft_strequ("-screenshot_headless", av[2]))
		parse_error("Wrongs special args", 0);
	core->headless_mode = 1;
	core->screenshot_path = av[3];
}

int		main(int ac, char **av)
{
	t_core		core;
	t_scene		scene;

	core.headless_mode = 0;
	if (ac < 2 || SDL_Init(SDL_INIT_VIDEO) != 0)
		parse_error("Wrongs args", 0);
	if (ac == 3)
		parse_error("Wrongs special args", 0);
	else if (ac == 4)
		parse_special_args(&core, av);
	core.file = av[1];
	parsing(&core, &scene, av[1]);
	core_init(&core, &scene);
	if (!core.headless_mode)
		interface_init(&core.interface, core.screen_size);
	rasterize_mt(&core);
	if (!core.headless_mode)
		while (42)
			update(&core);
	return (0);
}
