/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_utils_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:36:57 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/27 14:02:56 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_push_b(void);

void	test_push_b(void)
{
	t_heap	*a;
	t_heap	*b;

	a = NULL;
	b = NULL;
	ft_printf("\n--------Testing push_b--------\n");
	ft_heapadd(7, &a);
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
	ft_printf("\nAfter push_b from A to exisiting B two stacks are:\n");
	ft_print_ab(a, b);
	ft_print_heap_size(a);
	push_b(&a, &b);
	ft_printf("\nAfter push_b from empty A to exisiting B two stacks are:\n");
	ft_print_ab(a, b);
	ft_print_heap_size(a);
	ft_destroyheap(&a);
	ft_destroyheap(&b);
}
