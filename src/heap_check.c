/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:23:21 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/11 19:23:21 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_dup(t_heap *heap, int nb);
int		ft_is_sorted(t_heap *heap);
t_heap	*ft_get_nb_node(int nb, t_heap *heap);

/**
 * Functions run through heap to check if the nb is already added there
 *
 */
int	ft_is_dup(t_heap *heap, int nb)
{
	if (!heap)
		return (OK);
	while (heap)
	{
		if (heap->number == nb)
			return (DUPLICATION_ERROR);
		heap = heap->next;
	}
	return (OK);
}

/** Function checks if a heap is sorted, returning:
 * - 0 if heap is NOT sorted
 * - 1 if heap is sorted
 *
 */
int	ft_is_sorted(t_heap *heap)
{
	t_heap	*min;
	t_heap	*next;
	int		size;

	size = ft_get_size(heap) - 1;
	if (size <= 1)
		return (1);
	min = ft_get_nb_node(ft_get_min(heap), heap);
	while (size--)
	{
		if (min->next)
			next = min->next;
		else
			next = heap;
		if (next->number > min->number)
			min = next;
		else
			return (0);
	}
	return (1);
}

/**
 * Function returns a pointer to the node containing nb
 *
 */
t_heap	*ft_get_nb_node(int nb, t_heap *heap)
{
	if (!heap)
		return (NULL);
	while (heap->next && heap->number != nb)
		heap = heap->next;
	return (heap);
}
