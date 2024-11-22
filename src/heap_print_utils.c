/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_print_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:02:26 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/22 16:26:32 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_heap_node(t_heap *node);
void	ft_print_heap(t_heap *heap);
void	ft_print_heap_size(t_heap *heap);
void	ft_print_ab(t_heap *a, t_heap *b);

void	ft_print_heap_node(t_heap *node)
{
	ft_printf("New node:\n");
	ft_printf("\tValue stored in node:\t%d\n", node->number);
	ft_printf("\tCost of push_b of the node:\t%d\n", node->push_b_cost);
}

void	ft_print_heap(t_heap *heap)
{
	while (heap)
	{
		ft_print_heap_node(heap);
		heap = heap->next;
	}
}

void	ft_print_heap_size(t_heap *heap)
{
	int	i;

	i = ft_get_size(heap);
	ft_printf("The size of my heap is: %d\n", i);
}

void	ft_print_ab(t_heap *a, t_heap *b)
{
	ft_printf("Heap A:\n");
	ft_print_heap(a);
	ft_printf("Heap B:\n");
	ft_print_heap(b);
}
