/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:24:49 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/10 14:19:08 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_heap *ft_heapnew(int number, int init_i);
t_heap *ft_heapadd(int number, int init_i, t_heap *heap);
t_heap *ft_gettail(t_heap *heap);

t_heap *ft_heapnew(int number, int init_i)
{
	t_heap *a;
	
	a = malloc(sizeof(t_heap));
	a->number = number;
	a->initial_index = init_i;
	a->sorted_index = -1;
	a->next = 0;

	return (a);
}

t_heap *ft_heapadd(int number, int init_i, t_heap *heap)
{
	t_heap *new_node;
	t_heap *tail;

	new_node = malloc(sizeof(t_heap));
	tail = ft_gettail(heap);
	new_node->number = number;
	new_node->initial_index = init_i;
	new_node->sorted_index = -1;
	new_node->next = 0;
	
	tail->next = new_node;

	return (heap);
}

t_heap *ft_gettail(t_heap *heap)
{
	while (heap->next)
		heap = heap->next;
	return (heap);
}
