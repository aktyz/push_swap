/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:07:25 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/27 13:24:12 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_ft_sort_three(void);

void	test_ft_sort_three(void)
{
	t_heap	*a;

	ft_printf("\n--------Testing ft_sort_three--------\n");
	ft_heapadd(9, &a);
	ft_heapadd(7, &a);
	ft_heapadd(5, &a);
	ft_print_heap(a);
	ft_sort_three(&a);
	ft_print_heap(a);
	ft_destroyheap(&a);
	ft_printf("\n\n");
	ft_heapadd(7, &a);
	ft_heapadd(5, &a);
	ft_heapadd(9, &a);
	ft_print_heap(a);
	ft_sort_three(&a);
	ft_print_heap(a);
	ft_destroyheap(&a);
	ft_printf("\n\n");
	ft_heapadd(5, &a);
	ft_heapadd(7, &a);
	ft_heapadd(9, &a);
	ft_print_heap(a);
	ft_sort_three(&a);
	ft_print_heap(a);
	ft_destroyheap(&a);
}
