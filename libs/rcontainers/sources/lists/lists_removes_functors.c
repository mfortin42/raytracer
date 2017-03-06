/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_removes_functors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 02:08:58 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/28 20:16:38 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rcontainers_lists.h>

void	list_remove_range_inner(t_list *list,
								int start,
								int end,
								void (*f)(void *))
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
	while (iterator != end_node && (tmp = iterator))
	{
		iterator = iterator->next;
		f(tmp->data);
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

void	list_remove_value_inner(t_list *list, void *data, void (*f)(void *))
{
	t_node *prev;
	t_node *next;
	t_node *removed;

	removed = list_node_of(list, data);
	prev = removed->prev;
	next = removed->next;
	if (prev != NULL)
		prev->next = next;
	else
		list->start = next;
	if (next != NULL)
		next->prev = prev;
	else
		list->end = prev;
	f(removed->data);
	free(removed);
	list->count--;
}

void	list_remove_inner(t_list *list, int index, void (*f)(void *))
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
	f(removed->data);
	free(removed);
	list->count--;
}

void	list_clear_inner(t_list *list, void (*f)(void *))
{
	t_node	*iterator;
	t_node	*tmp;

	iterator = list->start;
	while (iterator != NULL)
	{
		tmp = iterator->next;
		f(iterator->data);
		free(iterator);
		iterator = tmp;
	}
	list->start = NULL;
	list->end = NULL;
	list->iterator = NULL;
	list->count = 0;
	list->current = 0;
}

void	list_delete_inner(t_list *list, void (*f)(void *))
{
	t_node	*iterator;
	t_node	*tmp;

	iterator = list->start;
	while (iterator != NULL)
	{
		tmp = iterator->next;
		f(iterator->data);
		free(iterator);
		iterator = tmp;
	}
	free(list);
}
