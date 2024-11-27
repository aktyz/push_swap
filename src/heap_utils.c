/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:24:49 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/27 15:02:01 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// HEAP construct & desctruct
void	ft_heapadd(int number, t_heap **heap);
void	ft_destroyheap(t_heap **heap);

// HEAPS operations
void	push_a(t_heap **a, t_heap **b);
void	push_b(t_heap **a, t_heap **b);

void	ft_heapadd(int number, t_heap **heap)
{
	t_heap	*new_node;
	t_heap	*tail;
	
	new_node = malloc(sizeof(t_heap));
	new_node->number = number;
	new_node->push_b_cost = 0;
	new_node->distance_from_head = 0;
	new_node->next = 0;
	if (!*heap)
		*heap = new_node;
	else
	{
		tail = ft_get_tail(*heap);
		tail->next = new_node;
	}	
}

void	ft_destroyheap(t_heap **heap)
{
	t_heap	*temp;

	while (*heap)
	{
		temp = *heap;
		*heap = (*heap)->next;
		free(temp);
	}
	*heap = NULL;
}

/**
 * Functions takes b heap head and move it to the
 * head of heap a
 *
 */
void	push_a(t_heap **a, t_heap **b)
{
	t_heap	*temp;

	if (!(*b))
		return ;
	temp = *b;
	*b = temp->next;
	temp->next = NULL;
	if (ft_get_size(*a) == 0)
		ft_heapadd(temp->number, a);
	else
	{
		temp->next = *a;
		*a = temp;
	}
	ft_printf("pa\n");
}

/**
 * Function takes a heap head and move it to the
 * head of heap b
 *
 */
void	push_b(t_heap **a, t_heap **b)
{
	t_heap	*temp;

	if (!(*a))
		return ;
	temp = *a;
	*a = temp->next;
	temp->next = NULL;
	if (ft_get_size(*b) == 0)
		ft_heapadd(temp->number, b);
	else
	{
		temp->next = *b;
		*b = temp;
	}
	ft_printf("pb\n");
}
