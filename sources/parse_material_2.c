/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 19:59:02 by mfortin           #+#    #+#             */
/*   Updated: 2016/06/30 12:31:24 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

void	parse_material3(t_scene *scene, t_parser *parser)
{
	int tmp;

	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 12)
		parse_error("wrong materials texture parsing", parser->cnt);
	if (ft_strcmp(parser->tmp[0], "<texture") != 0
		|| ft_strcmp(parser->tmp[1], "texture=") != 0
		|| ft_strcmp(parser->tmp[3], "offx=") != 0
		|| ft_strcmp(parser->tmp[5], "offy=") != 0
		|| ft_strcmp(parser->tmp[7], "coefx=") != 0
		|| ft_strcmp(parser->tmp[9], "coefy=") != 0
		|| ft_strcmp(parser->tmp[11], "/>") != 0)
		parse_error("wrong materials texture parsing", parser->cnt);
	tmp = ft_atoi(parser->tmp[2] + 1) - 1;
	if (tmp >= scene->textures_count || tmp < -1)
		parse_error("wrong materials texture parsing", parser->cnt);
	if (tmp == -1)
		scene->materials[parser->i].texture = NULL;
	else
		scene->materials[parser->i].texture = scene->textures + tmp;
	parse_material3_bis(scene, parser);
	ft_free_line_tab(parser->tmp);
}

void	parse_material3_bis(t_scene *scene, t_parser *parser)
{
	scene->materials[parser->i].texture_offset.x =
	fabs(ft_atof(parser->tmp[4] + 1));
	scene->materials[parser->i].texture_offset.y =
	fabs(ft_atof(parser->tmp[6] + 1));
	scene->materials[parser->i].texture_coef.x =
	fabs(ft_atof(parser->tmp[8] + 1));
	scene->materials[parser->i].texture_coef.y =
	fabs(ft_atof(parser->tmp[10] + 1));
}

void	parse_material4(t_scene *scene, t_parser *parser)
{
	int bright;

	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 3)
		parse_error("wrong materials brightness parsing", parser->cnt);
	if (ft_strcmp(parser->tmp[0], "<brightness>") != 0
		|| ft_strcmp(parser->tmp[2], "</brightness>") != 0)
		parse_error("wrong materials brightness parsing", parser->cnt);
	bright = ft_atof(parser->tmp[1]);
	scene->materials[parser->i].brightness = bright % 2 ? bright + 1 : bright;
	ft_free_line_tab(parser->tmp);
}

void	parse_material5(t_scene *scene, t_parser *parser)
{
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 3)
		parse_error("wrong materials reflection parsing", parser->cnt);
	if (ft_strcmp(parser->tmp[0], "<reflection>") != 0
		|| ft_strcmp(parser->tmp[2], "</reflection>") != 0)
		parse_error("wrong materials reflection parsing", parser->cnt);
	scene->materials[parser->i].reflection = ft_atof(parser->tmp[1]);
	if (scene->materials[parser->i].reflection > 1)
		scene->materials[parser->i].reflection = 1;
	else if (scene->materials[parser->i].reflection < 0)
		scene->materials[parser->i].reflection = 0;
	ft_free_line_tab(parser->tmp);
}

void	parse_material6(t_scene *scene, t_parser *parser)
{
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 3)
		parse_error("wrong materials refraction parsing", parser->cnt);
	if (ft_strcmp(parser->tmp[0], "<refraction>") != 0
		|| ft_strcmp(parser->tmp[2], "</refraction>") != 0)
		parse_error("wrong materials refraction parsing", parser->cnt);
	scene->materials[parser->i].refraction = ft_atof(parser->tmp[1]);
	if (scene->materials[parser->i].refraction > 1)
		scene->materials[parser->i].refraction = 1;
	else if (scene->materials[parser->i].refraction < 0)
		scene->materials[parser->i].refraction = 0;
	ft_free_line_tab(parser->tmp);
}
