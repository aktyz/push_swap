/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_check_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:33:51 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/13 14:10:42 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_ft_is_sorted(void);

void	test_ft_is_sorted(void)
{
	t_heap	*a;
	int		result;
	ft_printf("\n---------------------Testing ft_is_sorted---------------------\n");
	a = 0;
	result = ft_is_sorted(a);
	if (result != 1)
		ft_printf("\nMy null list is not sorted, expected 1, got: %d\n",
			result);
	a = ft_heapnew(1);
	result = ft_is_sorted(a);
	if (result != 1)
		ft_printf("\nMy one element list is not sorted, expected 1, got: %d\n",
			result);
	ft_heapadd(2, &a);
	result = ft_is_sorted(a);
	if (result != 1)
		ft_printf("\nMy two element list is not sorted, expected 1, got: %d\n",
			result);
	ft_heapadd(-3, &a);
	result = ft_is_sorted(a);
	if (result != 0)
		ft_printf("\nMy three element list is sorted, expected 0, got: %d\n",
			result);
}
