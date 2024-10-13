/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_print_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:02:26 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/13 15:09:56 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_heap_node(t_heap *node)
{
	ft_printf("New node:\n");
	ft_printf("\tValue stored in node:\t%d\n", node->number);
	ft_printf("\tInitial index of the node:\t%d\n", node->initial_index);
}

void	ft_print_heap(t_heap *heap)
{
	while(heap)
	{
		ft_print_heap_node(heap);
		heap = heap->next;
	}
}

void	ft_print_heap_size(t_heap *heap)
{
	int i = ft_get_size(heap);
	ft_printf("The size of my heap is: %d\n", i);
}
