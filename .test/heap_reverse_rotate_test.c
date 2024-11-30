/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_reverse_rotate_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:35:48 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/11 19:35:48 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_reverse_rotate(void);

void	test_reverse_rotate(void)
{
	t_heap	*a;

	ft_printf("\n--------Testing reverse_rotate--------\n");
	a = NULL;
	reverse_rotate_a(&a);
	ft_heapadd(45, &a);
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
