/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_checkers_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:25:36 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/13 16:32:34 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_ft_is_sorted(void);

void	test_ft_is_sorted(void)
{
	t_heap	*a;
	int		result;
	
	a = 0;
	result = ft_is_sorted(a);
	if (result != 1)
		ft_printf("\nMy null list is not sorted, expected 1, got: %d\n", result);
	a = ft_heapnew(1, 0);
	result = ft_is_sorted(a);
	if (result != 1)
		ft_printf("\nMy one element list is not sorted, expected 1, got: %d\n", result);
	a = ft_heapadd(2, 0, a);
	result = ft_is_sorted(a);
	if (result != 1)
		ft_printf("\nMy two element list is not sorted, expected 1, got: %d\n", result);
	a = ft_heapadd(-3, 0, a);
	result = ft_is_sorted(a);
	if (result != 0)
		ft_printf("\nMy three element list is sorted, expected 0, got: %d\n", result);
}