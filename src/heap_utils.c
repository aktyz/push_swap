/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:24:49 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/07 15:29:20 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_heap *ft_heapnew(int number, int init_i);

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
