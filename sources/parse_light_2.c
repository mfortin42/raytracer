/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:03:21 by mfortin           #+#    #+#             */
/*   Updated: 2016/06/28 20:05:38 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>

void	parse_light_fin(t_parser *parser)
{
	get_next_line(parser->fd, &parser->ln);
	parser->cnt++;
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 1)
		parse_error("wrong lights syntax parsing", parser->cnt);
	if (ft_strcmp(parser->tmp[0], "</lights>") != 0)
		parse_error("wrong lights syntax parsing", parser->cnt);
	ft_free_line_tab(parser->tmp);
	free(parser->ln);
	get_next_line(parser->fd, &parser->ln);
	parser->cnt++;
	parser->tmp = ft_strsplit_xml(parser->ln, ' ');
	if (ft_size_tab(parser->tmp) != 1)
		parse_error("wrong scene syntax parsing", parser->cnt);
	if (ft_strcmp(parser->tmp[0], "</scene>") != 0)
		parse_error("wrong scene syntax parsing", parser->cnt);
	ft_free_line_tab(parser->tmp);
	free(parser->ln);
}
