/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 15:46:33 by mfortin           #+#    #+#             */
/*   Updated: 2016/06/30 14:22:21 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	parse_camera(t_core *core, t_scene *scene, t_parser *parser)
{
	if (!(scene->camera = malloc(sizeof(t_camera))))
		parse_error("malloc failed", 0);
	scene->camera->viewport = core->screen_size;
	parse_camera_beg_1(scene, parser);
	parse_camera2_fin(scene, parser);
}

void	parse_camera_beg_1(t_scene *scene, t_parser *parser)
{
	get_next_line(parser->fd, &parser->ln);
	parser->cnt++;
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_strcmp(parser->tmp[0], "<camera>") != 0)
		parse_error("wrong camera syntax parsing", parser->cnt);
	ft_free_line_tab(parser->tmp);
	free(parser->ln);
	get_next_line(parser->fd, &parser->ln);
	parser->cnt++;
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 8)
		parse_error("wrong camera positions parsing", parser->cnt);
	if ((ft_strcmp(parser->tmp[0], "<position") != 0)
	|| (ft_strcmp(parser->tmp[1], "x=") != 0)
	|| (ft_strcmp(parser->tmp[3], "y=") != 0)
	|| (ft_strcmp(parser->tmp[5], "z=") != 0)
	|| (ft_strcmp(parser->tmp[7], "/>") != 0))
		parse_error("wrong camera positions parsing", parser->cnt);
	scene->camera->position.x = ft_atof(parser->tmp[2] + 1);
	scene->camera->position.y = ft_atof(parser->tmp[4] + 1);
	scene->camera->position.z = ft_atof(parser->tmp[6] + 1);
	ft_free_line_tab(parser->tmp);
	free(parser->ln);
}

void	parse_camera2_fin(t_scene *scene, t_parser *parser)
{
	get_next_line(parser->fd, &parser->ln);
	parser->cnt++;
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 8)
		parse_error("wrong camera directions parsing", parser->cnt);
	if ((ft_strcmp(parser->tmp[0], "<direction") != 0)
	|| (ft_strcmp(parser->tmp[1], "x=") != 0)
	|| (ft_strcmp(parser->tmp[3], "y=") != 0)
	|| (ft_strcmp(parser->tmp[5], "z=") != 0)
	|| (ft_strcmp(parser->tmp[7], "/>") != 0))
		parse_error("wrong camera directions parsing", parser->cnt);
	scene->camera->rotation.x = ft_atof(parser->tmp[2] + 1);
	scene->camera->rotation.y = ft_atof(parser->tmp[4] + 1);
	scene->camera->rotation.z = ft_atof(parser->tmp[6] + 1);
	scene->camera->sampling = 1;
	ft_free_line_tab(parser->tmp);
	free(parser->ln);
	get_next_line(parser->fd, &parser->ln);
	parser->cnt++;
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_strcmp(parser->tmp[0], "</camera>") != 0)
		parse_error("wrong camera syntax parsing", parser->cnt);
	ft_free_line_tab(parser->tmp);
	free(parser->ln);
}
