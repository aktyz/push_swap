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
	t_heap	*min;
	int		size;

	size = ft_get_size(heap) - 1;
	if (size <= 1)
		return (1);
	min = ft_get_nb_node(ft_get_min(heap), heap);
	tmp_nb = min->number;
	if (min->next)
		min = min->next;
	else
		min = heap;
	while (size--)
	{
		if (tmp_nb < min->number)
		{
			tmp_nb = min->number;
			if (min->next)
				min = min->next;
			else
				min = heap;
		}
		else
		{
			return (0);
			min = NULL;
		}
	}
	min = NULL;
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