/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:01:38 by mfortin           #+#    #+#             */
/*   Updated: 2016/06/30 14:23:29 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

void	parse_object3(t_scene *scene, t_parser *parser)
{
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 8)
		parse_error("wrong objects positions parsing", parser->cnt);
	if ((ft_strcmp(parser->tmp[0], "<position") != 0)
	|| (ft_strcmp(parser->tmp[1], "x=") != 0)
	|| (ft_strcmp(parser->tmp[3], "y=") != 0)
	|| (ft_strcmp(parser->tmp[5], "z=") != 0)
	|| (ft_strcmp(parser->tmp[7], "/>") != 0))
		parse_error("wrong objects positions parsing", parser->cnt);
	scene->objects[parser->i].position.x = ft_atof(parser->tmp[2] + 1);
	scene->objects[parser->i].position.y = ft_atof(parser->tmp[4] + 1);
	scene->objects[parser->i].position.z = ft_atof(parser->tmp[6] + 1);
	ft_free_line_tab(parser->tmp);
}

void	parse_object4(t_scene *scene, t_parser *parser)
{
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 8)
		parse_error("wrong objects directions parsing", parser->cnt);
	if ((ft_strcmp(parser->tmp[0], "<direction") != 0)
	|| (ft_strcmp(parser->tmp[1], "x=") != 0)
	|| (ft_strcmp(parser->tmp[3], "y=") != 0)
	|| (ft_strcmp(parser->tmp[5], "z=") != 0)
	|| (ft_strcmp(parser->tmp[7], "/>") != 0))
		parse_error("wrong objects directions parsing", parser->cnt);
	scene->objects[parser->i].rotation.x = ft_atof(parser->tmp[2] + 1);
	scene->objects[parser->i].rotation.y = ft_atof(parser->tmp[4] + 1);
	scene->objects[parser->i].rotation.z = ft_atof(parser->tmp[6] + 1);
	scene->objects[parser->i].rotation =
	v3f_normalized(scene->objects[parser->i].rotation);
	ft_free_line_tab(parser->tmp);
}

void	parse_object5(t_scene *scene, t_parser *parser)
{
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 3)
		parse_error("wrong objects size parsing", parser->cnt);
	if (ft_strcmp(parser->tmp[0], "<size>") != 0
		|| ft_strcmp(parser->tmp[2], "</size>") != 0)
		parse_error("wrong objects size parsing", parser->cnt);
	scene->objects[parser->i].radius = ft_atof(parser->tmp[1]);
	if (scene->objects[parser->i].radius <= 0)
		parse_error("wrong objects size parsing", parser->cnt);
	ft_free_line_tab(parser->tmp);
}

void	parse_object6(t_scene *scene, t_parser *parser)
{
	int material;

	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 3)
		parse_error("wrong objects material parsing", parser->cnt);
	if (ft_strcmp(parser->tmp[0], "<material>") != 0
	|| ft_strcmp(parser->tmp[2], "</material>") != 0)
		parse_error("wrong objects material parsing", parser->cnt);
	material = ft_atoi(parser->tmp[1]) - 1;
	if (material >= scene->materials_count || material < 0)
		parse_error("wrong objects material parsing", parser->cnt);
	scene->objects[parser->i].mat = (scene->materials + material);
	ft_free_line_tab(parser->tmp);
	parser->i++;
}

void	parse_object_fin(t_parser *parser)
{
	get_next_line(parser->fd, &parser->ln);
	parser->cnt++;
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 1)
		parse_error("wrong objects syntax parsing", parser->cnt);
	if (ft_strcmp(parser->tmp[0], "</objects>") != 0)
		parse_error("wrong objects syntax parsing", parser->cnt);
	ft_free_line_tab(parser->tmp);
	free(parser->ln);
}
