/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcontainers_lists.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <bkabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 22:50:00 by bkabbas           #+#    #+#             */
/*   Updated: 2016/06/29 15:00:05 by Rakiah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RCONTAINERS_LISTS_H
# define RCONTAINERS_LISTS_H

# include <stdlib.h>
# include <rcontainers_typedefs.h>
# include <rcontainers_structs.h>

/*
** create the list and return it, the elem_size is purely informational
** and can be set to 0 without affecting how the list work
*/
t_list	*list_new(void);
/*
** create a node at the end of the list and return it
*/
t_node	*list_push_back(t_list *list, void *data);
/*
** create a node at the start of the list and return it
*/
t_node	*list_push_front(t_list *list, void *data);
/*
** return the node corresponding to the data work on address equality
*/
t_node	*list_node_of(t_list *list, void *data);
/*
** return the index of the data you passed, work on address equality
*/
int		list_index_of(t_list *list, void *data);
/*
** return the node corresponding to the index
*/
t_node	*list_get_node_at(t_list *list, int index);
/*
** return the data of the node corresponding to the index
*/
void	*list_get_data_at(t_list *list, int index);
/*
** return the data of the current node and iterate
** the list by one step from the start to the end
*/
void	*list_next(t_list *list);
/*
** return the data of the current node and iterate
** the list by one step from the end to the start
*/
void	*list_prev(t_list *list);
/*
** return an array containing data pointers of every node in the list
*/
void	**list_to_array(t_list *list);
/*
** return an array containing data pointers of every node from start to end
*/
void	**list_to_array_range(t_list *list, int start, int end);

/*
** IMPLEMENTATION OF THE METHODS FOR REMOVING NODES
** INNER VERSIONS PASS TO FUNCTOR F BEFORE FREEING NODE
*/

/*
** start inclusive, end exclusive ex list_remove_range(list, 0, list->count))
** would kind of result as a clear, but always remember that you should
** reset the iterator after you do a remove_range (list_set_/start/end())
** or reset it by yourself if you know what you're doing
*/
void	list_remove_range(t_list *list, int start, int end);
void	list_remove_range_inner(t_list *l, int st, int ed, void (*f)(void *));
/*
** remove on an adress equality means it will not work (and can't) if you try to
** remove some nodes that have the same value, but different memory adress
*/
void	list_remove_value(t_list *list, void *data);
void	list_remove_value_inner(t_list *list, void *data, void (*f)(void *));
/*
** remove at the given index (first node is 0, last node is list->count)
*/
void	list_remove(t_list *list, int index);
void	list_remove_inner(t_list *list, int index, void (*f)(void *));
/*
** clear the whole list, and delete every node, this method is more optimized
** that doing a remove range from 0 to count
*/
void	list_clear(t_list *list);
void	list_clear_inner(t_list *list, void (*f)(void *));
/*
** clear the whole list, delete every node, and free list
*/
void	list_delete(t_list *list);
void	list_delete_inner(t_list *list, void (*f)(void *));
/*
** default functor for inner removing method, just free the data inside the node
*/
void	list_default_remove_functor(void *n);

/*
** list processor, send data inside the functor
*/
void	list_process_inner(t_list *list, void (*f)(void *));
/*
** list processor, send a specific range of data inside the functor
*/
void	list_process_range_inner(t_list *l, int st, int ed, void (*f)(void *));
/*
** list processor, send a specific data from index inside the functor
*/
void	list_process_at_inner(t_list *list, int index, void (*f)(void *));
/*
** setup list->current at 0 and the iterator at start
*/
void	list_set_end(t_list *list);
/*
** setup list->current at list->count - 1 and the iterator at end
*/
void	list_set_start(t_list *list);
/*
** setup list->current at index and the iterator at index node
*/
void	list_set_index(t_list *list, int index);

#endif
