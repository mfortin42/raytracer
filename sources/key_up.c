/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 04:50:08 by bkabbas           #+#    #+#             */
/*   Updated: 2016/06/23 22:32:58 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int			internal_key_up_hook(int keycode)
{
	keycode = keycode_converter_key(keycode);
	if (keycode < 1 || keycode > KEYCODES_COUNT)
		return (0);
	key_up(keycode, CMD_SET, TRUE);
	key_down(keycode, CMD_SET, FALSE);
	return (0);
}

t_keycode	get_last_key_up(void)
{
	return (key_up(-1, CMD_GET_LAST, FALSE));
}

t_bool		get_key_up(t_keycode code)
{
	if (code < 1 || code > KEYCODES_COUNT)
		return (FALSE);
	return ((t_bool)key_up(code, CMD_GET, FALSE));
}

t_keycode	key_up(t_keycode code, t_input_cmd cmd, t_bool value)
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
