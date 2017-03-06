/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_converters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 02:08:58 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/10 02:09:03 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rcontainers_lists.h>

void	**list_to_array(t_list *list)
{
	int		i;
	void	**ret_array;
	t_node	*node;

	ret_array = malloc(sizeof(void *) * list->count);
	node = list->start;
	i = 0;
	while (node != NULL)
	{
		ret_array[i] = node->data;
		node = node->next;
		i++;
	}
	return (ret_array);
}

void	**list_to_array_range(t_list *list, int start, int end)
{
	void	**ret_array;
	t_node	*node;

	ret_array = malloc(sizeof(void *) * (end - start));
	node = list_get_node_at(list, start);
	while (start < end)
	{
		ret_array[start] = node->data;
		node = node->next;
		start++;
	}
	return (ret_array);
}
