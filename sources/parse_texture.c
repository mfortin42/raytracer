/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 13:03:56 by mfortin           #+#    #+#             */
/*   Updated: 2016/06/28 20:12:33 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

void	parse_texture(t_scene *scene, t_parser *parser)
{
	int i;

	i = 0;
	parse_texture_beg(scene, parser);
	while ((i < scene->textures_count)
	&& (parser->ver = (get_next_line(parser->fd, &parser->ln))) > 0)
	{
		parser->cnt++;
		i++;
		parse_texture1(scene, parser);
		parser->i++;
		free(parser->ln);
	}
	parse_texture_fin(parser);
	parser->i = 0;
}

void	parse_texture_beg(t_scene *scene, t_parser *parser)
{
	get_next_line(parser->fd, &parser->ln);
	parser->cnt++;
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 4)
		parse_error("wrong texture number parsing", parser->cnt);
	if ((ft_strcmp(parser->tmp[0], "<textures") != 0)
	|| (ft_strcmp(parser->tmp[1], "nb=") != 0)
	|| (ft_strcmp(parser->tmp[3], ">") != 0))
		parse_error("wrong texture number parsing", parser->cnt);
	scene->textures_count = ft_atoi(parser->tmp[2] + 1);
	if (scene->textures_count < 0)
		parse_error("wrong texture number parsing", parser->cnt);
	if (!(scene->textures = malloc(sizeof(t_texture) * scene->textures_count)))
		parse_error("malloc failed", 0);
	ft_free_line_tab(parser->tmp);
	free(parser->ln);
}

void	parse_texture1(t_scene *scene, t_parser *parser)
{
	char *file;

	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 4)
		parse_error("wrong texture file parsing", parser->cnt);
	if ((ft_strcmp(parser->tmp[0], "<texture") != 0)
	|| (ft_strcmp(parser->tmp[1], "file=") != 0)
	|| (ft_strcmp(parser->tmp[3], "/>") != 0))
		parse_error("wrong texture file parsing", parser->cnt);
	file = ft_strndup(parser->tmp[2] + 1, ft_strlen(parser->tmp[2]) - 2);
	if ((tex_new_bmp(file)) == NULL)
		parse_error("wrong texture file parsing", parser->cnt);
	scene->textures[parser->i] = *tex_new_bmp(file);
	ft_free_line_tab(parser->tmp);
}

void	parse_texture_fin(t_parser *parser)
{
	get_next_line(parser->fd, &parser->ln);
	parser->cnt++;
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 1)
		parse_error("wrong texture syntax parsing", parser->cnt);
	if (ft_strcmp(parser->tmp[0], "</textures>") != 0)
		parse_error("wrong texture syntax parsing", parser->cnt);
	ft_free_line_tab(parser->tmp);
	free(parser->ln);
}
