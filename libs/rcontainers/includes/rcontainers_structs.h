/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcontainers_structs.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 12:11:32 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/30 12:11:43 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RCONTAINERS_STRUCTS_H
# define RCONTAINERS_STRUCTS_H

struct		s_node
{
	void	*data;
	t_node	*next;
	t_node	*prev;
};

struct		s_list
{
	t_node	*start;
	t_node	*end;
	t_node	*iterator;
	size_t	count;
	int		current;
};

struct		s_array
{
	void	*b;
};

#endif
