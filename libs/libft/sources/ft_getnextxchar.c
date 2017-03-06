/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextxchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/28 03:37:04 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this function search for the next char that is not c, starting by start
** index the move parameter should be valid or undetermined behaviour could
** happen you will probably always want to have -1 or +1 but for control
** purposes i decided to leave the choice, if you want to skip some
** characters the function return the index of the excluded char
*/

#include "libft.h"

int	ft_getnextxchar(const char *s, int c, int start, int move)
{
	if (s == NULL)
		return (-1);
	if (start > (int)ft_strlen(s))
		return (-1);
	while (s[start] == (unsigned char)c && start >= 0)
		start += move;
	return (start);
}
