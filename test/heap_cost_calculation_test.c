/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_cost_calculation_test.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:33:08 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/22 16:31:57 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_ft_nb_at_head(void);
void	test_ft_get_b_rot(void);

void	test_ft_nb_at_head(void)
{
	t_heap	*heap;
	int		result;

	ft_printf("\n--------Testing ft_nb_at_head--------\n");
	heap = 0;
	result = ft_nb_at_head(1, heap);
	if (result != 0)
		ft_printf("\nTest 1 failed: expected 0, got: %d\n", result);
	heap = ft_heapnew(1);
	result = ft_nb_at_head(1, heap);
	if (result != 0)
		- no rotation required
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
	heap = ft_heapnew(1);
	ft_heapadd(7, &heap);
	ft_heapadd(5, &heap);
	ft_heapadd(2, &heap);
	result = ft_nb_at_head(7, heap);
	if (result != 1)
		ft_printf("\nTest 10 failed: expected 1, got: %d\n", result);
	ft_destroyheap(&heap);
}

void	test_ft_get_b_rot(void)
{
	t_heap	*b;
	t_heap	*a;
	int		b_rot;

	ft_printf("\n--------Testing ft_get_b_rot--------\n");
	b = 0;
	b_rot = ft_get_b_rot(3, b);
	if (b_rot != 0)
		ft_printf("Test case 0 failed: expected 0, got %d\n", b_rot);
	else
		ft_printf("\n\n");
	b = ft_heapnew(7);
	ft_heapadd(5, &b);
	ft_heapadd(2, &b);
	ft_printf("\n\nHeap before test case 1:\n");
	ft_print_heap(b);
	b_rot = ft_get_b_rot(1, b);
	if (b_rot != 0)
		ft_printf("Test case 1 failed: expected 0, got %d\n", b_rot);
	else
		ft_printf("\n\n");
	a = ft_heapnew(1);
	push_b(&a, &b);
	ft_printf("\n\nHeap before test case 2:\n");
	ft_print_heap(b);
	b_rot = ft_get_b_rot(6, b);
	if (b_rot != -2)
		ft_printf("Test case 2 failed: expected -2, got %d\n", b_rot);
	else
		ft_printf("\n\n");
	reverse_rotate_b(&b);
	reverse_rotate_b(&b);
	ft_printf("\n\nHeap before test case 3:\n");
	ft_print_heap(b);
	b_rot = ft_get_b_rot(4, b);
	if (b_rot != 1)
		ft_printf("Test case 3 failed: expected 1, got %d\n", b_rot);
	else
		ft_printf("\n\n");
}
