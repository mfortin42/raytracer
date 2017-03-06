/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmath_v3f.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:24 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 14:11:41 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RMATH_V3F_H
# define RMATH_V3F_H

# include <math.h>
# include <stdlib.h>
# include "rmath_utils.h"
# include "rmath_typedefs.h"
# include "rmath_structs.h"

/*
** Commons t_vector3f initializations
*/
# define V3F_INIT(x, y, z)	(t_vector3f) { x, y, z }
# define V3F_ZERO			(t_vector3f) { +0, +0, +0 }
# define V3F_ONE			(t_vector3f) { +1, +1, +1 }
# define V3F_FORWARD		(t_vector3f) { +0, +0, +1 }
# define V3F_BACK			(t_vector3f) { +0, +0, -1 }
# define V3F_UP				(t_vector3f) { +0, +1, +0 }
# define V3F_DOWN			(t_vector3f) { +0, -1, +0 }
# define V3F_RIGHT			(t_vector3f) { +1, +0, +0 }
# define V3F_LEFT			(t_vector3f) { -1, +0, +0 }

/*
**	Return the length of "vector"
*/
float			v3f_length(t_vector3f vector);

/*
**	Return the result of the dot product between "v1" and "v2"
*/
float			v3f_dot(t_vector3f v1, t_vector3f v2);

/*
**	Return the distance between "v1" and "v2"
*/
float			v3f_distance(t_vector3f v1, t_vector3f v2);

/*
**	Return the normalized version of "vector"
*/
t_vector3f		v3f_normalized(t_vector3f vector);

/*
**	Return the rotated version of "vector" by "angle"
*/
t_vector3f		v3f_rotate(t_vector3f vector, float angle);

/*
**	Return the result of the addition between "v1" with "v2" (operator +)
*/
t_vector3f		v3f_add(t_vector3f v1, t_vector3f v2);

/*
**	Return the result of the subtraction between "v1" with "v2" (operator -)
*/
t_vector3f		v3f_sub(t_vector3f v1, t_vector3f v2);

/*
**	Return the result of the multiplication between "v1" with "v2" (operator *)
*/
t_vector3f		v3f_mul(t_vector3f v1, t_vector3f v2);

/*
**	Return the result of the division between "v1" with "v2" (operator /)
*/
t_vector3f		v3f_div(t_vector3f v1, t_vector3f v2);

/*
**	Return the result of the addition between components from "v1" with "val"
*/
t_vector3f		v3f_add_float(t_vector3f v1, float val);

/*
**	Return the result of the subtraction between components from "v1" with "val"
*/
t_vector3f		v3f_sub_float(t_vector3f v1, float val);

/*
**	Return the result of the multiplication from "v1" and "val"
*/
t_vector3f		v3f_mul_float(t_vector3f v1, float val);

/*
**	Return the result of the division between components from "v1" with "val"
*/
t_vector3f		v3f_div_float(t_vector3f v1, float val);

/*
**	Return a lerped vector from "v1 to "v2" by "lerp_factor"
*/
t_vector3f		v3f_lerp(t_vector3f v1, t_vector3f v2, float lerp_factor);

/*
**	Return the opposite version of "v"
*/
t_vector3f		v3f_opposite(t_vector3f v);

/*
**	Return the cross product of "v1" and "v2"
*/
t_vector3f		v3f_cross(t_vector3f v1, t_vector3f v2);

/*
**	Return a dynamically allocated t_vector2f using "x" "y" "z" values
*/
t_vector3f		*v3f_new(float x, float y, float z);

/*
**	Return a color (as an int) based "v"
**	Components of "v" are clamped from 0 to 1 and represent R,G,B values
*/
int				v3f_to_color(t_vector3f v);

#endif
