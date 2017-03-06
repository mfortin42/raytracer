/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmath_m4f.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:24 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/10 00:18:46 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RMATH_M4F_H
# define RMATH_M4F_H

# include <math.h>
# include <stdlib.h>
# include "rmath_utils.h"
# include "rmath_typedefs.h"
# include "rmath_structs.h"

/*
**	Initialize "m" to indentity matrix
*/
void			m4f_identity(t_matrix4f *matrix);

/*
**	Initialize "m" to translation matrix with "t"
*/
void			m4f_translate(t_matrix4f *matrix, t_vector3f t);

/*
**	Initialize "m" to rotation matrix with "r"
*/
void			m4f_rotate(t_matrix4f *matrix, t_vector3f r);

/*
**	Initialize "m" to scale matrix with "s"
*/
void			m4f_scale(t_matrix4f *matrix, t_vector3f s);

/*
**	Initialize "m" to screen space matrix by width and height
*/
void			m4f_screen_space(t_matrix4f *m, float width, float height);

/*
**	Initialize "m" to perspective matrix with defined parameters:
**	"degfov" Field of view of the perspective in degree
**	"screen" screen size (width and height)
**	"frustum" frustum of the perspective
*/
void			m4f_perspective(t_matrix4f *m, float degfov,
								t_vector2f screen, t_vector2f frustum);

/*
**	Return the determinant of "m"
*/
float			m4f_get_determinant(t_matrix4f *m);

/*
**	Adjugate "m"
*/
void			m4f_adjugate(t_matrix4f *m);

/*
**	Invert "m"
*/
void			m4f_invert(t_matrix4f *m);

/*
**	Return "dst", copied from src
*/
t_matrix4f		*m4f_cpy(t_matrix4f *dst, t_matrix4f *src);

/*
**	Return "dst", multiplied by "src"
*/
t_matrix4f		*m4f_mul(t_matrix4f *m1, t_matrix4f *m2);

/*
**	Return the multiplication of "m1" and "m2" in an allocated t_matrix4f
*/
t_matrix4f		*m4f_mul_new(t_matrix4f *m1, t_matrix4f *m2);

/*
**	Return a dynamically allocated t_matrix4f
*/
t_matrix4f		*m4f_new();

/*
**	Return the result of the multiplication of "m" with "v"
*/
t_vector4f		m4f_mul_vector(t_matrix4f *m, t_vector4f v);

#endif
