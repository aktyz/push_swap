/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:49:44 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/12 22:00:29 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_heap	*ft_gettail(t_heap *heap);
int		ft_get_size(t_heap *heap);

t_heap	*ft_gettail(t_heap *heap)
{
	while (heap->next)
		heap = heap->next;
	return (heap);
}

int	ft_get_size(t_heap *heap)
{
	int	i;

	i = 1;
	while (heap->next)
	{
		i++;
		heap = heap->next;
	}
	return (i);
}
