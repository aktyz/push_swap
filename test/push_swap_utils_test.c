/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:07:25 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/13 19:29:48 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_ft_sort_three(void);

void	test_ft_sort_three(void)
{
	t_heap *a;

	a = ft_heapnew(9, 0);
	a = ft_heapadd(7, 1, a);
	a = ft_heapadd(5, 2, a);
	ft_print_heap(a);
	ft_sort_three(&a);
	ft_print_heap(a);
	ft_destroyheap(&a);
	ft_printf("\n\n");
	a = ft_heapnew(7, 0);
	a = ft_heapadd(5, 1, a);
	a = ft_heapadd(9, 2, a);
	ft_print_heap(a);
	ft_sort_three(&a);
	ft_print_heap(a);
	ft_destroyheap(&a);
	ft_printf("\n\n");
	a = ft_heapnew(5, 0);
	a = ft_heapadd(7, 1, a);
	a = ft_heapadd(9, 2, a);
	ft_print_heap(a);
	ft_sort_three(&a);
	ft_print_heap(a);
	ft_destroyheap(&a);
}
