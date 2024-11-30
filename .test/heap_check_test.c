/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_check_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:33:51 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/28 14:44:24 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_ft_is_sorted(void);

void	test_ft_is_sorted(void)
{
	t_heap	*a;
	int		result;

	ft_printf("\n--------Testing ft_is_sorted--------\n");
	a = NULL;
	result = ft_is_sorted(a);
	if (result != 1)
		ft_printf("\nMy null list is sorted, expected 1, got: %d\n",
			result);
	ft_heapadd(1, &a);
	result = ft_is_sorted(a);
	if (result != 1)
		ft_printf("\nMy one element list is sorted, expected 1, got: %d\n",
			result);
	ft_heapadd(2, &a);
	result = ft_is_sorted(a);
	if (result != 1)
		ft_printf("\nMy two element list is sorted, expected 1, got: %d\n",
			result);
	ft_heapadd(-3, &a);
	result = ft_is_sorted(a);
	if (result != 1)
		ft_printf("\nMy three element list is sorted, expected 1, got: %d\n",
			result);
	ft_destroyheap(&a);
	parse_string_arg(&a, "67 4 9");
	result = ft_is_sorted(a);
	if (result != 1)
		ft_printf("\nMy rotated list is sorted, expected 1, got: %d\n",
			result);
	ft_destroyheap(&a);
	parse_string_arg(&a, "4 67 9 107");
	result = ft_is_sorted(a);
	if (result != 0)
		ft_printf("\nMy list is NOT sorted, expected 0, got: %d\n",
			result);
	ft_destroyheap(&a);
}
