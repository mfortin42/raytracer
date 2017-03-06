/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays_inits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <bkabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 22:50:00 by bkabbas           #+#    #+#             */
/*   Updated: 2016/06/10 02:09:21 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rcontainers_arrays.h>

t_array	*array_new(size_t elem_size)
{
	t_array *ret;

	(void)elem_size;
	ret = (t_array *)malloc(sizeof(t_array));
	return (ret);
}
