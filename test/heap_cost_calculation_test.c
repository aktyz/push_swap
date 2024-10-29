/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_heap_cost_calculation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:33:08 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/29 16:33:52 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_ft_nb_at_head(void);

void	test_ft_nb_at_head(void)
{
	t_heap	*heap;
	int		result;

	heap = 0;
	result = ft_nb_at_head(1, heap);
	if (result != 0)
		ft_printf("\nTest 1 failed: expected 0, got: %d\n", result);

	heap = ft_heapnew(1);
	result = ft_nb_at_head(1, heap);
	if (result != 0)
		ft_printf("\nTest 2 failed: expected 0, got: %d\n", result);

	ft_heapadd(2, &heap);
	result = ft_nb_at_head(2, heap);
	if (result != 1)
		ft_printf("\nTest 3 failed: expected 1, got: %d\n", result);

	ft_heapadd(3, &heap);
	result = ft_nb_at_head(3, heap);
	if (result != 2)
		ft_printf("\nTest 4 failed: expected 2, got: %d\n", result);

	ft_heapadd(4, &heap);
	result = ft_nb_at_head(4, heap);
	if (result != -1)
		ft_printf("\nTest 5 failed: expected -1, got: %d\n", result);

	ft_heapadd(5, &heap);
	result = ft_nb_at_head(5, heap);
	if (result != -2)
		ft_printf("\nTest 6 failed: expected -2, got: %d\n", result);
}
