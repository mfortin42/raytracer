/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:06 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 12:57:18 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct s_core		t_core;
typedef struct s_scene		t_scene;
typedef struct s_object		t_object;
typedef struct s_material	t_material;
typedef struct s_light		t_light;
typedef struct s_texture	t_texture;
typedef struct s_ray		t_ray;
typedef struct s_ray_hit	t_ray_hit;
typedef struct s_camera		t_camera;
typedef struct s_parser		t_parser;
typedef struct s_rect		t_rect;
typedef struct s_interface	t_interface;
typedef struct s_ui_element	t_ui_element;
typedef struct s_label		t_label;
typedef struct s_filter		t_filter;
typedef void	(*t_ui_hook)	(t_ui_element *, t_core *);
typedef int	(*t_intersect)	(t_ray *, t_object *, float *);
typedef int	(*t_normal)		(t_ray *, t_ray_hit *);
typedef void	(*t_effect)	(t_texture *);

#endif
