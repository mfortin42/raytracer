/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmath_v4f.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:24 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 12:02:42 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RMATH_V4F_H
# define RMATH_V4F_H

# include <math.h>
# include <stdlib.h>
# include "rmath_utils.h"
# include "rmath_typedefs.h"
# include "rmath_structs.h"

/*
** Commons t_vector4f initializations
*/
# define V4F_INIT(x, y, z, w)	(t_vector4f) { x, y, z, w }
# define V4F_ZERO				(t_vector4f) { +0, +0, +0, +0 }
# define V4F_ONE				(t_vector4f) { +1, +1, +1, +1 }
# define V4F_FORWARD			(t_vector4f) { +0, +0, +1, +1 }
# define V4F_BACK				(t_vector4f) { +0, +0, -1, +1 }
# define V4F_UP					(t_vector4f) { +0, +1, +0, +1 }
# define V4F_DOWN				(t_vector4f) { +0, -1, +0, +1 }
# define V4F_RIGHT				(t_vector4f) { +1, +0, +0, +1 }
# define V4F_LEFT				(t_vector4f) { -1, +0, +0, +1 }

/*
**	Return the length of "vector"
*/
float			v4f_length(t_vector4f vector);

/*
**	Return the result of the dot product between "v1" and "v2"
*/
float			v4f_dot(t_vector4f v1, t_vector4f v2);

/*
**	Return the normalized version of "vector"
*/
t_vector4f		v4f_normalized(t_vector4f vector);

/*
**	Return the rotated version of "vector" by "angle"
*/
t_vector4f		v4f_rotate(t_vector4f vector, float angle);

/*
**	Return the result of the addition between "v1" with "v2" (operator +)
*/
t_vector4f		v4f_add(t_vector4f v1, t_vector4f v2);

/*
**	Return the result of the subtraction between "v1" with "v2" (operator -)
*/
t_vector4f		v4f_sub(t_vector4f v1, t_vector4f v2);

/*
**	Return the result of the multiplication between "v1" with "v2" (operator *)
*/
t_vector4f		v4f_mul(t_vector4f v1, t_vector4f v2);

/*
**	Return the result of the division between "v1" with "v2" (operator /)
*/
t_vector4f		v4f_div(t_vector4f v1, t_vector4f v2);

/*
**	Return the result of the addition between components from "v1" with "val"
*/
t_vector4f		v4f_add_float(t_vector4f v1, float val);

/*
**	Return the result of the subtraction between components from "v1" with "val"
*/
t_vector4f		v4f_sub_float(t_vector4f v1, float val);

/*
**	Return the result of the multiplication from "v1" and "val"
*/
t_vector4f		v4f_mul_float(t_vector4f v1, float val);

/*
**	Return the result of the division between components from "v1" with "val"
*/
t_vector4f		v4f_div_float(t_vector4f v1, float val);

/*
**	Return a lerped vector from "v1 to "v2" by "lerp_factor"
*/
t_vector4f		v4f_lerp(t_vector4f v1, t_vector4f v2, float lerp_factor);

/*
**	Return the opposite version of "v"
*/
t_vector4f		v4f_opposite(t_vector4f v);

/*
**	Return the cross product of "v1" and "v2"
*/
t_vector4f		v4f_cross(t_vector4f v1, t_vector4f v2);

/*
**	Return a dynamically allocated t_vector4f using "x" "y" "z" "w" values
*/
t_vector4f		*v4f_new(float x, float y, float z, float w);

/*
**	Return a color (as an int) based "v"
**	Components of "v" are clamped from 0 to 1 and represent A,R,G,B
*/
int				v4f_to_color(t_vector4f color);

#endif
