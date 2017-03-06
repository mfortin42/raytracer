/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmath_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:43:24 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/22 20:08:45 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RMATH_UTILS_H
# define RMATH_UTILS_H

# include <stdlib.h>
# include "rmath_typedefs.h"
# include "rmath_structs.h"
# define PI 3.14159265358979323846
# define POW2(x) (x) * (x)

/*
**		Return the minimum value between "a" and "b"
*/
float	minf(float a, float b);
int		mini(int a, int b);

/*
**		Return the maximum value between "a" and "b"
*/
float	maxf(float a, float b);
int		maxi(int a, int b);

/*
**		Return the clamped version of "val" from "min" to "max"
*/
float	clampf(float val, float min, float max);
int		clampi(int val, int min, int max);

/*
**		Return the clamped version of "val" from "0" to "1"
*/
float	clampf01(float val);

#endif
