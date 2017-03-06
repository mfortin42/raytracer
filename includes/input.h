/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 21:27:52 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 12:56:39 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

typedef int	t_bool;
typedef enum e_keycode	t_keycode;
typedef enum e_input_cmd	t_input_cmd;

# define TRUE 1
# define FALSE 0
# define KEYCODES_COUNT 18
# define MOUSEBUTTON_COUNT 6

int				internal_key_down_hook(int code);
int				internal_key_up_hook(int code);
int				internal_mouse_down_hook(int code, int x, int y);
int				internal_mouse_up_hook(int code, int x, int y);
int				internal_mouse_pos_hook(int x, int y);
int				internal_mouse_motion_hook(int x, int y);

t_bool			get_mouse_button_up(int code);
t_bool			get_mouse_button_down(int code);
t_bool			get_key_up(t_keycode code);
t_bool			get_key_down(t_keycode code);
t_vector2f		get_mouse_pos(void);
t_vector2f		get_mouse_motion(void);

t_keycode		get_last_key_down(void);
t_keycode		get_last_key_up(void);
int				get_last_mouse_up(void);
int				get_last_mouse_down(void);

t_keycode		key_up(t_keycode code, t_input_cmd cmd, t_bool value);
t_keycode		key_down(t_keycode code, t_input_cmd cmd, t_bool value);
int				mouse_up(int code, t_input_cmd cmd, t_bool value);
int				mouse_down(int mousebutton, t_input_cmd cmd, t_bool value);
t_vector2f		mouse_pos(int x, int y, t_input_cmd cmd);
t_vector2f		mouse_motion(int x, int y, t_input_cmd cmd);

t_keycode		keycode_converter_key(int keycode);
int				keycode_converter_mbutton(int keycode);

enum	e_keycode
{
	NONE,
	UP_ARROW,
	DOWN_ARROW,
	RIGHT_ARROW,
	LEFT_ARROW,
	PAGE_UP,
	PAGE_DOWN,
	ALPHA1,
	ALPHA2,
	ALPHA3,
	D,
	G,
	Q,
	S,
	W,
	T,
	ESCAPE,
	ANY
};

enum	e_input_cmd
{
	CMD_GET,
	CMD_SET,
	CMD_SET_ALL,
	CMD_GET_LAST
};

#endif
