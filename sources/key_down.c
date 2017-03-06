/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_down.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 04:52:29 by bkabbas           #+#    #+#             */
/*   Updated: 2016/06/23 22:27:53 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int			internal_key_down_hook(int keycode)
{
	keycode = keycode_converter_key(keycode);
	if (keycode < 1 || keycode > KEYCODES_COUNT)
		return (0);
	key_down(keycode, CMD_SET, TRUE);
	return (0);
}

t_keycode	get_last_key_down(void)
{
	return (key_down(-1, CMD_GET_LAST, FALSE));
}

t_bool		get_key_down(t_keycode code)
{
	if (code < 1 || code > KEYCODES_COUNT)
		return (FALSE);
	return ((t_bool)key_down(code, CMD_GET, FALSE));
}

t_keycode	key_down(t_keycode code, t_input_cmd cmd, t_bool value)
{
	static t_bool		keys[KEYCODES_COUNT] = { 0 };
	static t_keycode	last_key = NONE;

	if (cmd == CMD_SET_ALL)
	{
		code = 1;
		while (code < KEYCODES_COUNT)
			keys[code++] = value;
		last_key = NONE;
	}
	else if (cmd == CMD_SET)
	{
		last_key = code;
		keys[code] = value;
	}
	else if (cmd == CMD_GET)
	{
		if (code == KEYCODES_COUNT && last_key != NONE)
			return (TRUE);
		return (keys[code]);
	}
	return (last_key);
}
