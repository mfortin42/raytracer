/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:16:28 by mfortin           #+#    #+#             */
/*   Updated: 2016/06/28 20:14:58 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	parse_object(t_scene *scene, t_parser *parser)
{
	int i;

	i = 0;
	parse_object_beg(scene, parser);
	while (i < (7 * scene->objects_count)
	&& (parser->ver = (get_next_line(parser->fd, &parser->ln))) > 0)
	{
		parser->cnt++;
		i++;
		if (((i - 1) % 7 == 0) || (i % 7 == 0))
			parse_object1_7(parser, i);
		if ((i - 2) % 7 == 0)
			parse_object2(scene, parser);
		if ((i - 3) % 7 == 0)
			parse_object3(scene, parser);
		if ((i - 4) % 7 == 0)
			parse_object4(scene, parser);
		if ((i - 5) % 7 == 0)
			parse_object5(scene, parser);
		if ((i - 6) % 7 == 0)
			parse_object6(scene, parser);
		free(parser->ln);
	}
	parse_object_fin(parser);
	parser->i = 0;
}

void	parse_object_beg(t_scene *scene, t_parser *parser)
{
	get_next_line(parser->fd, &parser->ln);
	parser->cnt++;
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 4)
		parse_error("wrong objects number parsing", parser->cnt);
	if ((ft_strcmp(parser->tmp[0], "<objects") != 0)
	|| (ft_strcmp(parser->tmp[1], "nb=") != 0)
	|| (ft_strcmp(parser->tmp[3], ">") != 0))
		parse_error("wrong objects number parsing", parser->cnt);
	scene->objects_count = ft_atoi(parser->tmp[2] + 1);
	if (scene->objects_count < 0)
		parse_error("wrong objects number parsing", parser->cnt);
	if (!(scene->objects = malloc(sizeof(t_object) * scene->objects_count)))
		parse_error("malloc failed", parser->cnt);
	ft_free_line_tab(parser->tmp);
	free(parser->ln);
}

void	parse_object1_7(t_parser *parser, int i)
{
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 1)
		parse_error("wrong objects syntax parsing", parser->cnt);
	if ((ft_strcmp(parser->tmp[0], "<object>")
	&& (i - 1) % 7 == 0) || (ft_strcmp(parser->tmp[0], "</object>")
	&& i % 7 == 0))
		parse_error("wrong objects syntax parsing", parser->cnt);
	ft_free_line_tab(parser->tmp);
}

void	parse_object2(t_scene *scene, t_parser *parser)
{
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 3)
		parse_error("wrong objects type parsing", parser->cnt);
	else if (ft_strcmp(parser->tmp[1], "sphere") == 0)
		sphere_init(scene->objects + parser->i);
	else if (ft_strcmp(parser->tmp[1], "plane") == 0)
		plane_init(scene->objects + parser->i);
	else if (ft_strcmp(parser->tmp[1], "cone") == 0)
		cone_init(scene->objects + parser->i);
	else if (ft_strcmp(parser->tmp[1], "cylinder") == 0)
		cylinder_init(scene->objects + parser->i);
	else if (ft_strcmp(parser->tmp[1], "disk") == 0)
		disk_init(scene->objects + parser->i);
	else
		parse_error("wrong objects type parsing", parser->cnt);
	ft_free_line_tab(parser->tmp);
}
