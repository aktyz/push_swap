/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_swap_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:37:27 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/11 19:37:27 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_swap(void);

void	test_swap(void)
{
	t_heap	*a;
	ft_printf("\n---------------------Testing swap---------------------\n");
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
