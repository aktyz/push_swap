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

/**
 * Functions run through heap to check if the nb is already added there
 *
 */
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

/** Function checks if a heap is sorted, returning:
 * - 0 if heap is NOT sorted
 * - 1 if heap is sorted
 *
 */
int	ft_is_sorted(t_heap *heap)
{
	int		tmp_nb;

	if (ft_get_size(heap) < 2)
		return (1);
	tmp_nb = heap->number;
	heap = heap->next;
	while (heap)
	{
		if (tmp_nb < heap->number)
		{
			tmp_nb = heap->number;
			heap = heap->next;
		}
		else
			return (0);
	}
	return (1);
}
