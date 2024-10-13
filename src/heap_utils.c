/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:24:49 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/13 16:14:45 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// HEAP construct & desctruct
t_heap	*ft_heapnew(int number, int init_i);
t_heap	*ft_heapadd(int number, int init_i, t_heap *heap);
void	ft_destroyheap(t_heap **heap);

// HEAPS operations
void	push_b(t_heap **a, t_heap **b);

// HEAP checks
int		ft_is_dup(t_heap *heap, int nb);

t_heap *ft_heapnew(int number, int init_i)
{
	t_heap *a;
	
	a = malloc(sizeof(t_heap));
	a->number = number;
	a->initial_index = init_i;
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
	new_node->next = 0;
	
	tail->next = new_node;

	return (heap);
}

int	ft_is_dup(t_heap *heap, int nb)
{
	while (heap->next)
	{
		if (heap->number == nb)
			return (DUPLICATION_ERROR);
		heap = heap->next;
	}
	return (OK);
}

void	ft_destroyheap(t_heap **heap)
{
	t_heap *temp;
	
	while (*heap)
	{
		temp = *heap;
		*heap = (*heap)->next;
		free(temp);
	}
	heap = 0;
}

void	push_b(t_heap **a, t_heap **b)
{
	t_heap *temp;
	
	if (!(*a))
		return ;
	temp = *a;
	*a = temp->next;
	if (ft_get_size(*b) == 0)
		*b = ft_heapnew(temp->number, 0);
	else
	{
		temp->next = *b;
		*b = temp;
	}
	ft_printf("pb\n");
}
