/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_cost_calculation_test.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:33:08 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/13 15:01:13 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_ft_nb_at_head(void);

void	test_ft_nb_at_head(void)
{
	t_heap	*heap;
	int		result;
	ft_printf("\n---------------------Testing ft_nb_at_head---------------------\n");
	heap = 0;
	result = ft_nb_at_head(1, heap);
	if (result != 0)// handle case where the heap is null
		ft_printf("\nTest 1 failed: expected 0, got: %d\n", result);

	heap = ft_heapnew(1);
	result = ft_nb_at_head(1, heap);
	if (result != 0)// handle case where the heap has one element - no rotation required
		ft_printf("\nTest 2 failed: expected 0, got: %d\n", result);

	ft_heapadd(2, &heap);
	result = ft_nb_at_head(2, heap);
	if (result != -1)
		ft_printf("\nTest 3 failed: expected -1, got: %d\n", result);

	ft_heapadd(3, &heap);
	result = ft_nb_at_head(3, heap);
	if (result != -1)
		ft_printf("\nTest 4 failed: expected -1, got: %d\n", result);

	ft_heapadd(4, &heap);
	result = ft_nb_at_head(4, heap);
	if (result != -1)
		ft_printf("\nTest 5 failed: expected -1, got: %d\n", result);

	ft_heapadd(5, &heap);
	result = ft_nb_at_head(4, heap);
	if (result != -2)
		ft_printf("\nTest 6 failed: expected -2, got: %d\n", result);
	ft_heapadd(6, &heap);
	result = ft_nb_at_head(3, heap);
	if (result != 2)
		ft_printf("\nTest 7 failed: expected 2, got: %d\n", result);
	ft_heapadd(33, &heap);
	ft_heapadd(17, &heap);
	ft_heapadd(103, &heap);
	result = ft_nb_at_head(4, heap);
	if (result != 3)
		ft_printf("\nTest 8 failed: expected 3, got: %d\n", result);
	result = ft_nb_at_head(33, heap);
	if (result != -3)
		ft_printf("\nTest 9 failed: expected -3, got: %d\n", result);
	ft_destroyheap(&heap);
}
