/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 15:47:40 by mfortin           #+#    #+#             */
/*   Updated: 2016/06/28 20:14:28 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	parse_material(t_scene *scene, t_parser *parser)
{
	parse_material_beg(scene, parser);
	parse_material_core(scene, parser);
	parse_material_fin(parser);
	parser->i = 0;
}

void	parse_material_core(t_scene *scene, t_parser *parser)
{
	int i;

	i = 0;
	while (i < (8 * scene->materials_count) &&
	(parser->ver = (get_next_line(parser->fd, &parser->ln))) > 0)
	{
		i++;
		parser->cnt++;
		if ((i - 1) % 8 == 0 || i % 8 == 0)
			parse_material_1_8(parser, i);
		if ((i - 2) % 8 == 0)
			parse_material2(scene, parser);
		if ((i - 3) % 8 == 0)
			parse_material3(scene, parser);
		if ((i - 4) % 8 == 0)
			parse_material4(scene, parser);
		if ((i - 5) % 8 == 0)
			parse_material5(scene, parser);
		if ((i - 6) % 8 == 0)
			parse_material6(scene, parser);
		if ((i - 7) % 8 == 0)
			parse_material7(scene, parser);
		free(parser->ln);
	}
}

void	parse_material_beg(t_scene *scene, t_parser *parser)
{
	get_next_line(parser->fd, &parser->ln);
	parser->cnt++;
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 4)
		parse_error("wrong materials number parsing", parser->cnt);
	if ((ft_strcmp(parser->tmp[0], "<materials") != 0)
	|| (ft_strcmp(parser->tmp[1], "nb=") != 0)
	|| (ft_strcmp(parser->tmp[3], ">") != 0))
		parse_error("wrong materials number parsing", parser->cnt);
	scene->materials_count = ft_atoi(parser->tmp[2] + 1);
	if (scene->materials_count < 0)
		parse_error("wrong materials number parsing", parser->cnt);
	if (!(scene->materials =
	malloc(sizeof(t_material) * scene->materials_count)))
		parse_error("malloc failed", 0);
	ft_free_line_tab(parser->tmp);
	free(parser->ln);
}

void	parse_material_1_8(t_parser *parser, int i)
{
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 1)
		parse_error("wrong materials syntax parsing", parser->cnt);
	if ((ft_strcmp(parser->tmp[0], "<material>")
	&& (i - 1) % 8 == 0) || ((ft_strcmp(parser->tmp[0], "</material>")
	&& i % 8 == 0)))
		parse_error("wrong materials syntax parsing", parser->cnt);
	ft_free_line_tab(parser->tmp);
}

void	parse_material2(t_scene *scene, t_parser *parser)
{
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 8)
		parse_error("wrong materials colors parsing", parser->cnt);
	if (ft_strcmp(parser->tmp[0], "<color") != 0
	|| ft_strcmp(parser->tmp[1], "r=") != 0
	|| ft_strcmp(parser->tmp[3], "g=") != 0
	|| ft_strcmp(parser->tmp[5], "b=") != 0
	|| ft_strcmp(parser->tmp[7], "/>") != 0)
		parse_error("wrong materials colors parsing", parser->cnt);
	scene->materials[parser->i].diffuse.x = ft_atof(parser->tmp[2] + 1);
	scene->materials[parser->i].diffuse.y = ft_atof(parser->tmp[4] + 1);
	scene->materials[parser->i].diffuse.z = ft_atof(parser->tmp[6] + 1);
	ft_check_vcol(&scene->materials[parser->i].diffuse);
	ft_free_line_tab(parser->tmp);
}
