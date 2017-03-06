/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/06/23 23:19:07 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_keycode	move_keycode(int keycode)
{
	if (keycode == SDLK_d)
		return (D);
	if (keycode == SDLK_a)
		return (Q);
	if (keycode == SDLK_w)
		return (W);
	if (keycode == SDLK_s)
		return (S);
	if (keycode == SDLK_t)
		return (T);
	if (keycode == SDLK_g)
		return (G);
	return (0);
}

t_keycode	rotate_keycode(int keycode)
{
	if (keycode == SDLK_RIGHT)
		return (RIGHT_ARROW);
	if (keycode == SDLK_LEFT)
		return (LEFT_ARROW);
	if (keycode == SDLK_UP)
		return (UP_ARROW);
	if (keycode == SDLK_DOWN)
		return (DOWN_ARROW);
	if (keycode == SDLK_PAGEUP)
		return (PAGE_UP);
	if (keycode == SDLK_PAGEDOWN)
		return (PAGE_DOWN);
	return (0);
}

t_keycode	settings_keycode(int keycode)
{
	if (keycode == 27)
		return (ESCAPE);
	if (keycode == 49)
		return (ALPHA1);
	if (keycode == 50)
		return (ALPHA2);
	if (keycode == 51)
		return (ALPHA3);
	return (0);
}

t_keycode	keycode_converter_key(int keycode)
{
	enum e_keycode ret;

	if ((ret = move_keycode(keycode)) ||
		(ret = rotate_keycode(keycode)) ||
		(ret = settings_keycode(keycode)))
		return (ret);
	return (0);
}

int			keycode_converter_mbutton(int keycode)
{
	return (keycode);
}
