/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmath_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:24 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/10 00:21:48 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RMATH_STRUCTS_H
# define RMATH_STRUCTS_H

struct					s_vector2f
{
	float				x;
	float				y;
};

struct					s_vector3f
{
	float				x;
	float				y;
	float				z;
};

struct					s_vector4f
{
	float				x;
	float				y;
	float				z;
	float				w;
};

struct					s_matrix4f
{
	float				m[4][4];
};

#endif
