/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_operations_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:06:28 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/13 16:11:03 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_push_b(void);

void	test_push_b(void)
{
	t_heap *a;
	t_heap *b;

	a = 0;
	b = 0;

	a = ft_heapnew(7, 0);
	a = ft_heapadd(33, 1, a);
	ft_printf("\n\nStack A before changes:\n");
	ft_print_heap(a);
	push_b(&a, &b);
	ft_printf("\nAfter push_b to empty B two stacks are:\n");
	ft_printf("Heap A:\n");
	ft_print_heap(a);
	ft_printf("Heap B:\n");
	ft_print_heap(b);
	a = ft_heapadd(56, 2, a);
	ft_printf("\n\nStack A before changes:\n");
	ft_print_heap(a);
	push_b(&a, &b);
	ft_printf("\nAfter push_b to exisiting B two stacks are:\n");
	ft_printf("Heap A:\n");
	ft_print_heap(a);
	ft_printf("Heap B:\n");
	ft_print_heap(b);
	push_b(&a, &b);
	ft_printf("\nAfter push_b of last element of A to exisiting B two stacks are:\n");
	ft_printf("Heap A:\n");
	ft_print_heap(a);
	ft_printf("Heap B:\n");
	ft_print_heap(b);
	ft_print_heap_size(a);
	push_b(&a, &b);
	ft_printf("\nAfter push_b from empty A to exisiting B two stacks are:\n");
	ft_printf("Heap A:\n");
	ft_print_heap(a);
	ft_printf("Heap B:\n");
	ft_print_heap(b);
	ft_print_heap_size(a);
}