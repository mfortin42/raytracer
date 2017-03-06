/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rakiah <bkabbas@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 02:08:58 by Rakiah            #+#    #+#             */
/*   Updated: 2016/06/29 14:53:35 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rcontainers_lists.h>

t_list	*list_new(void)
{
	t_list *ret;

	ret = (t_list *)malloc(sizeof(t_list));
	ret->start = NULL;
	ret->end = NULL;
	ret->iterator = NULL;
	ret->count = 0;
	ret->current = 0;
	return (ret);
}

t_node	*list_push_back(t_list *list, void *data)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	node->prev = list->end;
	node->next = NULL;
	if (list->end != NULL)
		list->end->next = node;
	list->end = node;
	list->count++;
	if (list->start == NULL)
	{
		list->start = node;
		list->iterator = node;
	}
	return (node);
}

t_node	*list_push_front(t_list *list, void *data)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	node->next = list->start;
	node->prev = NULL;
	if (list->start != NULL)
		list->start->prev = node;
	list->start = node;
	list->count++;
	if (list->end == NULL)
	{
		list->end = node;
		list->iterator = node;
	}
	return (node);
}
