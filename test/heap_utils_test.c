/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_utils_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:36:57 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/11 19:38:09 by zslowian         ###   ########.fr       */
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
