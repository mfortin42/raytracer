/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_removes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 02:08:58 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/28 20:17:06 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rcontainers_lists.h>

void	list_remove_range(t_list *list, int start, int end)
{
	t_node *start_node;
	t_node *start_node_minus;
	t_node *end_node;
	t_node *iterator;
	t_node *tmp;

	start_node = list_get_node_at(list, start);
	start_node_minus = start_node->prev;
	end_node = list_get_node_at(list, end);
	iterator = start_node;
	while (iterator != end_node)
	{
		tmp = iterator;
		iterator = iterator->next;
		free(tmp);
		list->count--;
	}
	if (start_node_minus != NULL)
		start_node_minus->next = end_node;
	else
		list->start = end_node;
	if (end_node != NULL)
		end_node->prev = start_node_minus;
	else
		list->end = start_node_minus;
}

void	list_remove_value(t_list *list, void *data)
{
	t_node *prev;
	t_node *next;
	t_node *removed;

	removed = list_node_of(list, data);
	prev = removed->prev;
	next = removed->next;
	free(removed);
	if (prev != NULL)
		prev->next = next;
	else
		list->start = next;
	if (next != NULL)
		next->prev = prev;
	else
		list->end = prev;
	list->count--;
}

void	list_remove(t_list *list, int index)
{
	t_node *prev;
	t_node *next;
	t_node *removed;

	removed = list_get_node_at(list, index);
	next = removed->next;
	prev = removed->prev;
	if (prev != NULL)
		prev->next = next;
	else
		list->start = next;
	if (next != NULL)
		next->prev = prev;
	else
		list->end = prev;
	free(removed);
	list->count--;
}

void	list_clear(t_list *list)
{
	t_node	*iterator;
	t_node	*tmp;

	iterator = list->start;
	while (iterator != NULL)
	{
		tmp = iterator->next;
		free(iterator);
		iterator = tmp;
	}
	list->start = NULL;
	list->end = NULL;
	list->iterator = NULL;
	list->count = 0;
	list->current = 0;
}

void	list_delete(t_list *list)
{
	t_node	*iterator;
	t_node	*tmp;

	iterator = list->start;
	while (iterator != NULL)
	{
		tmp = iterator->next;
		free(iterator);
		iterator = tmp;
	}
	free(list);
}
