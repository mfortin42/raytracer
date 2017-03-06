/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 15:12:00 by mfortin           #+#    #+#             */
/*   Updated: 2016/06/28 20:13:31 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	parse_light(t_scene *scene, t_parser *parser)
{
	int i;

	i = 0;
	parse_light_beg(scene, parser);
	while (i < (4 * scene->lights_count)
	&& (parser->ver = (get_next_line(parser->fd, &parser->ln))) > 0)
	{
		parser->cnt++;
		i++;
		if ((i - 1) % 4 == 0 || i % 4 == 0)
			parse_light_1_4(parser, i);
		if ((i - 2) % 4 == 0)
			parse_light2(scene, parser);
		if ((i - 3) % 4 == 0)
			parse_light3(scene, parser);
		free(parser->ln);
	}
	parse_light_fin(parser);
	parser->i = 0;
}

void	parse_light_beg(t_scene *scene, t_parser *parser)
{
	get_next_line(parser->fd, &parser->ln);
	parser->cnt++;
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 4)
		parse_error("wrong lights number parsing", parser->cnt);
	if ((ft_strcmp(parser->tmp[0], "<lights") != 0)
	|| (ft_strcmp(parser->tmp[1], "nb=") != 0)
	|| (ft_strcmp(parser->tmp[3], ">") != 0))
		parse_error("wrong lights number parsing", parser->cnt);
	scene->lights_count = ft_atoi(parser->tmp[2] + 1);
	if (scene->lights_count < 0)
		parse_error("wrong lights number parsing", parser->cnt);
	if (!(scene->lights = malloc(sizeof(t_light) * scene->lights_count)))
		parse_error("malloc failed", 0);
	ft_free_line_tab(parser->tmp);
	free(parser->ln);
}

void	parse_light_1_4(t_parser *parser, int i)
{
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 1)
		parse_error("wrong lights syntax parsing", parser->cnt);
	if ((ft_strcmp(parser->tmp[0], "<light>")
	&& (i - 1) % 4 == 0) || ((ft_strcmp(parser->tmp[0], "</light>")
	&& i % 4 == 0)))
		parse_error("wrong lights syntax parsing", parser->cnt);
	ft_free_line_tab(parser->tmp);
}

void	parse_light2(t_scene *scene, t_parser *parser)
{
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 8)
		parse_error("wrong lights positions parsing", parser->cnt);
	if (ft_strcmp(parser->tmp[0], "<position") != 0
	|| ft_strcmp(parser->tmp[1], "x=") != 0
	|| ft_strcmp(parser->tmp[3], "y=") != 0
	|| ft_strcmp(parser->tmp[5], "z=") != 0
	|| ft_strcmp(parser->tmp[7], "/>") != 0)
		parse_error("wrong lights positions parsing", parser->cnt);
	scene->lights[parser->i].position.x = ft_atof(parser->tmp[2] + 1);
	scene->lights[parser->i].position.y = ft_atof(parser->tmp[4] + 1);
	scene->lights[parser->i].position.z = ft_atof(parser->tmp[6] + 1);
	ft_free_line_tab(parser->tmp);
}

void	parse_light3(t_scene *scene, t_parser *parser)
{
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 8)
		parse_error("wrong lights colors parsing", parser->cnt);
	if (ft_strcmp(parser->tmp[0], "<color") != 0
	|| ft_strcmp(parser->tmp[1], "r=") != 0
	|| ft_strcmp(parser->tmp[3], "g=") != 0
	|| ft_strcmp(parser->tmp[5], "b=") != 0
	|| ft_strcmp(parser->tmp[7], "/>") != 0)
		parse_error("wrong lights colors parsing", parser->cnt);
	scene->lights[parser->i].intensity.x = ft_atof(parser->tmp[2] + 1);
	scene->lights[parser->i].intensity.y = ft_atof(parser->tmp[4] + 1);
	scene->lights[parser->i].intensity.z = ft_atof(parser->tmp[6] + 1);
	ft_check_vcol(&scene->lights[parser->i].intensity);
	ft_free_line_tab(parser->tmp);
	parser->i++;
}
