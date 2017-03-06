/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:05 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/28 20:23:27 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include <get_next_line.h>

void	parsing(t_core *core, t_scene *scene, char *file);
void	parse_all(t_core *core, t_scene *scene, t_parser *parser);

void	parse_resolution(t_core *core, t_parser *parser);
void	parse_ambient_light(t_scene *scene, t_parser *parser);

void	parse_camera(t_core *core, t_scene *scene, t_parser *parser);
void	parse_camera_beg_1(t_scene *scene, t_parser *parser);
void	parse_camera2_fin(t_scene *scene, t_parser *parser);

void	parse_texture(t_scene *scene, t_parser *parser);
void	parse_texture_beg(t_scene *scene, t_parser *parser);
void	parse_texture1(t_scene *scene, t_parser *parser);
void	parse_texture_fin(t_parser *parser);

void	parse_material(t_scene *scene, t_parser *parser);
void	parse_material_core(t_scene *scene, t_parser *parser);
void	parse_material_beg(t_scene *scene, t_parser *parser);
void	parse_material_1_8(t_parser *parser, int i);
void	parse_material2(t_scene *scene, t_parser *parser);
void	parse_material3(t_scene *scene, t_parser *parser);
void	parse_material3_bis(t_scene *scene, t_parser *parser);
void	parse_material4(t_scene *scene, t_parser *parser);
void	parse_material5(t_scene *scene, t_parser *parser);
void	parse_material6(t_scene *scene, t_parser *parser);
void	parse_material7(t_scene *scene, t_parser *parser);
void	parse_material_fin(t_parser *parser);

void	parse_object(t_scene *scene, t_parser *parser);
void	parse_object_beg(t_scene *scene, t_parser *parser);
void	parse_object1_7(t_parser *parser, int i);
void	parse_object2(t_scene *scene, t_parser *parser);
void	parse_object3(t_scene *scene, t_parser *parser);
void	parse_object4(t_scene *scene, t_parser *parser);
void	parse_object5(t_scene *scene, t_parser *parser);
void	parse_object6(t_scene *scene, t_parser *parser);
void	parse_object_fin(t_parser *parser);

void	parse_light(t_scene *scene, t_parser *parser);
void	parse_light_beg(t_scene *scene, t_parser *parser);
void	parse_light_1_4(t_parser *parser, int i);
void	parse_light2(t_scene *scene, t_parser *parser);
void	parse_light3(t_scene *scene, t_parser *parser);
void	parse_light_fin(t_parser *parser);

void	parse_error(char *str, int i);
void	ft_free_line_tab(char **str);
void	ft_check_vcol(t_vector3f *col);
int		ft_size_tab(char **str);
char	**ft_strsplit_xml(char const *s, char c);
char	*get_valid_filename(char *file);

#endif
