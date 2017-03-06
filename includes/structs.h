/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:16:05 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 16:15:15 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define POST_EFFECTS_COUNT 4

struct			s_scene
{
	t_vector3f	ambient_light;
	t_camera	*camera;
	t_object	*objects;
	t_light		*lights;
	t_material	*materials;
	t_texture	*textures;
	int			objects_count;
	int			lights_count;
	int			materials_count;
	int			textures_count;
};

struct			s_camera
{
	t_vector3f	position;
	t_vector3f	rotation;
	t_vector2f	viewport;
	int			sampling;
};

struct			s_object
{
	t_vector3f	position;
	t_vector3f	rotation;
	t_material	*mat;
	t_intersect	intersect;
	t_normal	normal;
	float		radius;
};

struct			s_material
{
	float		brightness;
	float		reflection;
	float		refraction;
	float		transparency;
	t_vector3f	diffuse;
	t_texture	*texture;
	t_vector2f	texture_offset;
	t_vector2f	texture_coef;
};

struct			s_light
{
	t_vector3f	position;
	t_vector3f	intensity;
};

struct			s_ray
{
	t_vector3f	start;
	t_vector3f	dir;
	float		length;
	int			level_reflection;
	int			level_refraction;
};

struct			s_ray_hit
{
	t_object	*object;
	t_vector3f	point;
	t_vector3f	normal;
	float		delta;
};

struct			s_texture
{
	SDL_Surface	*img;
	char		*pixels;
	int			bytes_per_pixel;
	int			l_size;
	int			size;
	int			width;
	int			height;
	int			endian;
};

struct			s_interface
{
	TTF_Font		*font;
	t_list			*elements;
	t_list			*labels;
	t_label			*aliasing;
	t_ui_element	*bar_bounding;
	t_ui_element	*bar_dynamic;
	t_label			*bar_value;
	t_vector2f		bar_dynamic_size;
	t_label			*blurr;
	t_label			*sepia;
	t_label			*grayscale;
	t_label			*inverse;
	t_label			*hide_label;
	t_matrix4f		*matrix;
	int				hide_ui;
};

struct			s_filter
{
	int			activated;
	t_effect	effect;
};

struct			s_core
{
	int			headless_mode;
	char		*screenshot_path;
	char		*file;
	SDL_Window	*win;
	t_scene		*scene;
	t_texture	*screen;
	t_interface	interface;
	t_vector2f	screen_size;
	t_filter	filters[POST_EFFECTS_COUNT];
};

struct			s_parser
{
	int			i;
	int			cnt;
	int			ver;
	int			fd;
	char		*ln;
	char		**tmp;
};

struct			s_rect
{
	int x;
	int y;
	int w;
	int h;
};

struct			s_ui_element
{
	t_texture	*texture;
	t_ui_hook	on_click_down;
	t_ui_hook	on_click_up;
	t_ui_hook	on_mouse_enter;
	t_ui_hook	on_mouse_leave;
	t_rect		rect;
	int			color;
	int			inside;
	int			active;
};

struct			s_label
{
	TTF_Font		*font;
	t_texture		*texture;
	t_ui_element	*attached;
	t_rect			rect;
	int				active;
};

#endif
