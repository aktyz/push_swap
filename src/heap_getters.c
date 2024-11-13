/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:49:44 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/13 14:37:03 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_heap	*ft_get_tail(t_heap *heap);
int		ft_get_size(t_heap *heap);
int		ft_get_min(t_heap *heap);
int		ft_get_nb_pos(int nb, t_heap *heap);

t_heap	*ft_get_tail(t_heap *heap)
{
	while (heap->next)
		heap = heap->next;
	return (heap);
}

/**
 * Returns number of nodes in the heap.
 *
*/
int	ft_get_size(t_heap *heap)
{
	int	i;

	if (!heap)
		return (0);
	i = 1;
	while (heap->next)
	{
		i++;
		heap = heap->next;
	}
	return (i);
}

int		ft_get_min(t_heap *heap)
{
	int	min;

	min = heap->number;
	while (heap)
	{
		if (heap->number < min)
			min = heap->number;
		heap = heap->next;
	}
	return (min);
}
/**
 * Function assigns the current posiotion number of the node
 * in the heap.
 * 
 * Needed to calculate the required heap rotations to get this number
 * to the head.
 * 
 */
int		ft_get_nb_pos(int nb, t_heap *heap)
{
	int	pos;

	pos = 0;
	while (heap && nb != heap->number)
	{
		pos++;
		heap = heap->next;
	}
	if (!heap)
		return (-1);
	return (pos);
}
