/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_operations_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:06:28 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/14 15:49:58 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_push_b(void);
void	test_swap(void);
void	test_reverse_rotate(void);

void	test_push_b(void)
{
	t_heap *a;
	t_heap *b;

	a = 0;
	b = 0;

	a = ft_heapnew(7);
	ft_heapadd(33, &a);
	ft_printf("\n\nStack A before changes:\n");
	ft_print_heap(a);
	push_b(&a, &b);
	ft_printf("\nAfter push_b to empty B two stacks are:\n");
	ft_print_ab(a, b);
	ft_heapadd(56, &a);
	ft_printf("\n\nStack A before changes:\n");
	ft_print_heap(a);
	push_b(&a, &b);
	ft_printf("\nAfter push_b to exisiting B two stacks are:\n");
	ft_print_ab(a, b);
	push_b(&a, &b);
	ft_printf("\nAfter push_b of last element of A to exisiting B two stacks are:\n");
	ft_print_ab(a, b);
	ft_print_heap_size(a);
	push_b(&a, &b);
	ft_printf("\nAfter push_b from empty A to exisiting B two stacks are:\n");
	ft_print_ab(a, b);
	ft_print_heap_size(a);
	ft_destroyheap(&a);
	ft_destroyheap(&b);
}

void	test_swap(void)
{
	t_heap	*a;

	a = 0;
	swap_a(&a);
	a = ft_heapnew(33);
	ft_printf("Heap before swap:\n");
	ft_print_heap(a);
	swap_a(&a);
	ft_printf("Heap after swap:\n");
	ft_print_heap(a);
	ft_printf("\n\n");
	ft_heapadd(7, &a);
	ft_printf("Heap before swap:\n");
	ft_print_heap(a);
	swap_a(&a);
	ft_printf("Heap after swap:\n");
	ft_print_heap(a);
	ft_printf("\n\n");
	ft_heapadd(5879348, &a);
	ft_printf("Heap before swap:\n");
	ft_print_heap(a);
	swap_a(&a);
	ft_printf("Heap after swap:\n");
	ft_print_heap(a);
	ft_destroyheap(&a);
}

void	test_reverse_rotate(void)
{
	t_heap	*a;

	a = 0;
	reverse_rotate_a(&a);
	a = ft_heapnew(45);
	ft_printf("Heap before reverse rotation:\n");
	ft_print_heap(a);
	reverse_rotate_a(&a);
	ft_printf("Heap after reverse rotation:\n");
	ft_print_heap(a);
	ft_printf("\n\n");
	ft_heapadd(9, &a);
	ft_printf("Heap before reverse rotation:\n");
	ft_print_heap(a);
	reverse_rotate_a(&a);
	ft_printf("Heap after reverse rotation:\n");
	ft_print_heap(a);
	ft_printf("\n\n");
	ft_heapadd(27, &a);
	ft_printf("Heap before reverse rotation:\n");
	ft_print_heap(a);
	reverse_rotate_a(&a);
	ft_printf("Heap after reverse rotation:\n");
	ft_print_heap(a);
	ft_destroyheap(&a);
}
