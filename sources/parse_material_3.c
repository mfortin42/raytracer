/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:00:17 by mfortin           #+#    #+#             */
/*   Updated: 2016/06/30 14:23:15 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

void	parse_material7(t_scene *scene, t_parser *parser)
{
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 3)
		parse_error("wrong materials transparency parsing", parser->cnt);
	if (ft_strcmp(parser->tmp[0], "<transparency>") != 0
		|| ft_strcmp(parser->tmp[2], "</transparency>") != 0)
		parse_error("wrong materials transparency parsing", parser->cnt);
	scene->materials[parser->i].transparency = ft_atof(parser->tmp[1]);
	if (scene->materials[parser->i].transparency > 1)
		scene->materials[parser->i].transparency = 1;
	else if (scene->materials[parser->i].transparency < 0)
		scene->materials[parser->i].transparency = 0;
	ft_free_line_tab(parser->tmp);
	parser->i++;
}

void	parse_material_fin(t_parser *parser)
{
	get_next_line(parser->fd, &parser->ln);
	parser->cnt++;
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 1)
		parse_error("wrong materials syntax parsing", parser->cnt);
	if (ft_strcmp(parser->tmp[0], "</materials>") != 0)
		parse_error("wrong materials syntax parsing", parser->cnt);
	ft_free_line_tab(parser->tmp);
	free(parser->ln);
}
