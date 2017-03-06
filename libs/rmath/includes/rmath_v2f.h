/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmath_v2f.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:24 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 11:59:11 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RMATH_V2F_H
# define RMATH_V2F_H

# include <math.h>
# include <stdlib.h>
# include "rmath_utils.h"
# include "rmath_typedefs.h"
# include "rmath_structs.h"

/*
** Commons t_vector2f initializations
*/
# define V2F_INIT(x, y)		(t_vector2f) { x, y }
# define V2F_ZERO			(t_vector2f) { +0, +0 }
# define V2F_ONE			(t_vector2f) { +1, +1 }
# define V2F_UP				(t_vector2f) { +0, +1 }
# define V2F_DOWN			(t_vector2f) { +0, -1 }
# define V2F_RIGHT			(t_vector2f) { +1, +0 }
# define V2F_LEFT			(t_vector2f) { -1, +0 }

/*
**	Return the length of "vector"
*/
float			v2f_length(t_vector2f vector);

/*
**	Return the result of the dot product between "v1" and "v2"
*/
float			v2f_dot(t_vector2f v1, t_vector2f v2);

/*
**	Return the normalized version of "vector"
*/
t_vector2f		v2f_normalized(t_vector2f vector);

/*
**	Return the rotated version of "vector" by "angle"
*/
t_vector2f		v2f_rotate(t_vector2f vector, float angle);

/*
**	Return the result of the addition between "v1" with "v2" (operator +)
*/
t_vector2f		v2f_add(t_vector2f v1, t_vector2f v2);

/*
**	Return the result of the subtraction between "v1" with "v2" (operator -)
*/
t_vector2f		v2f_sub(t_vector2f v1, t_vector2f v2);

/*
**	Return the result of the multiplication between "v1" with "v2" (operator *)
*/
t_vector2f		v2f_mul(t_vector2f v1, t_vector2f v2);

/*
**	Return the result of the division between "v1" with "v2" (operator /)
*/
t_vector2f		v2f_div(t_vector2f v1, t_vector2f v2);

/*
**	Return the result of the addition between components from "v1" with "val"
*/
t_vector2f		v2f_add_float(t_vector2f v1, float val);

/*
**	Return the result of the subtraction between components from "v1" with "val"
*/
t_vector2f		v2f_sub_float(t_vector2f v1, float val);

/*
**	Return the result of the multiplication between "v1" and "val"
*/
t_vector2f		v2f_mul_float(t_vector2f v1, float val);

/*
**	Return the result of the division between components from "v1" with "val"
*/
t_vector2f		v2f_div_float(t_vector2f v1, float val);

/*
**	Return a lerped vector from "v1 to "v2" by "lerp_factor"
*/
t_vector2f		v2f_lerp(t_vector2f v1, t_vector2f v2, float lerp_factor);

/*
**	Return the opposite version of "v"
*/
t_vector2f		v2f_opposite(t_vector2f v);

/*
**	Return a dynamically allocated t_vector2f using "x" "y" values
*/
t_vector2f		*v2f_new(float x, float y);

#endif
