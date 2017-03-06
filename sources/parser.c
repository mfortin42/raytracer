/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 15:46:47 by mfortin           #+#    #+#             */
/*   Updated: 2016/06/29 17:51:30 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

static void	parser_init(t_parser *parser)
{
	parser->fd = 0;
	parser->ln = NULL;
	parser->ver = 0;
	parser->cnt = 0;
	parser->i = 0;
}

void		parsing(t_core *core, t_scene *scene, char *file)
{
	int			i;
	t_parser	parser;

	i = 0;
	parser_init(&parser);
	if ((parser.fd = open(file, O_RDONLY)) < 0)
		parse_error(ft_strjoin("failed to open : ", file), 0);
	while ((parser.ver = (get_next_line(parser.fd, &parser.ln))) > 0)
	{
		parser.cnt++;
		i++;
		if (i == 2 && (ft_strcmp(parser.ln, "<scene>")) != 0)
			parse_error("wrong scene parsing", parser.cnt);
		if (i == 3)
			parse_all(core, scene, &parser);
		if (i <= 2)
			free(parser.ln);
	}
	if (parser.ver == 0 && (i == 0 || i == 1))
		parse_error("wrong parsing", 0);
	if (parser.ver == -1)
		parse_error("didnt read a file", 0);
	close(parser.fd);
}

void		parse_all(t_core *core, t_scene *scene, t_parser *parser)
{
	parse_resolution(core, parser);
	parse_ambient_light(scene, parser);
	parse_camera(core, scene, parser);
	parse_texture(scene, parser);
	parse_material(scene, parser);
	parse_object(scene, parser);
	parse_light(scene, parser);
}

void		parse_resolution(t_core *core, t_parser *parser)
{
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 6)
		parse_error("wrong resolution parsing", parser->cnt);
	if (ft_strcmp(parser->tmp[0], "<resolution") != 0
	|| ft_strcmp(parser->tmp[1], "width=") != 0
	|| ft_strcmp(parser->tmp[3], "height=") != 0
	|| ft_strcmp(parser->tmp[5], "/>") != 0)
		parse_error("wrong resolution parsing", parser->cnt);
	core->screen_size.x = ft_atoi(parser->tmp[2] + 1);
	core->screen_size.y = ft_atoi(parser->tmp[4] + 1);
	if (core->screen_size.x <= 0 || core->screen_size.y <= 0)
		parse_error("wrong resolution parsing", parser->cnt);
	ft_free_line_tab(parser->tmp);
}

void		parse_ambient_light(t_scene *scene, t_parser *parser)
{
	get_next_line(parser->fd, &parser->ln);
	parser->cnt++;
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 8)
		parse_error("wrong ambient-light parsing", parser->cnt);
	if (ft_strcmp(parser->tmp[0], "<ambient-light") != 0
	|| ft_strcmp(parser->tmp[1], "r=") != 0
	|| ft_strcmp(parser->tmp[3], "g=") != 0
	|| ft_strcmp(parser->tmp[5], "b=") != 0
	|| ft_strcmp(parser->tmp[7], "/>") != 0)
		parse_error("wrong ambient-light parsing", parser->cnt);
	scene->ambient_light.x = ft_atof(parser->tmp[2] + 1);
	scene->ambient_light.y = ft_atof(parser->tmp[4] + 1);
	scene->ambient_light.z = ft_atof(parser->tmp[6] + 1);
	ft_check_vcol(&scene->ambient_light);
	ft_free_line_tab(parser->tmp);
}
